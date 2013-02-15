<?php
/**
 * Start the game.  Bundles all the startup process together.
 * @param int $game_id
 * @param string $version
 * @param int $time
 * @param boolean $use_old_gsid
 * @param boolean $create_new_psid
 * @return array(settings)
 */
function game_stats_start_game($game_id, $version, $time = NULL, $use_old_gsid = FALSE, $create_new_psid = TRUE, $uid = NULL) {
  global $user;
  if(is_null($uid))
    $uid = $user->uid;

  if($create_new_psid)
    _game_stats_close_play_sessions($game_id, $uid);

  $stored_time = _game_stats_time_diff_check($time);
  if($use_old_gsid) {
    $result = db_query('SELECT gsu.gsid FROM {games_game_session_users} gsu LEFT JOIN {games_game_session} gs ON gs.gsid = gsu.gsid WHERE uid = %d AND game_id = %d ORDER BY start_time DESC;', $uid, $game_id);
    $gsid = db_result($result);
  } else {
    $data = _game_stats_enter_session_data($game_id, $stored_time, 0, FALSE, 0, FALSE);
    $gsid = $data['gsid'];
    _game_stats_enter_session_user_data($gsid, $uid, 0, FALSE);
  }

  $psid = _game_stats_last_psid($gsid, $uid);
  if($create_new_psid || $psid === FALSE)
    $psid = _game_stats_start_play_session($game_id, $gsid, $version, $uid, $time);
  
  //Interval for the heartbeat.  Based on seconds.
  $heartbeatSec = 10;
  $stats_enabled = user_access('use game stats');
  
  $game_settings = array(
      'psid' => (int)$psid,
      'heartbeatSec' => (int)$heartbeatSec,
      'stats_enabled' => (bool)$stats_enabled,
  );
  $game_settings = array_merge($game_settings, module_invoke_all('game_stats_start_game_settings', $game_id));
  
  module_invoke_all('game_stats_start_game', $game_id);
  return $game_settings;
}

/**
 * Complete the game.  Bundles all the cleanup process together.
 * @param $psid
 * @param $score
 * @param $stats
 * @param $time
 */
function game_stats_complete_game($psid, $score, $stats = NULL, $time = NULL, $uid = NULL) {
  global $user;
  if(is_null($uid))
    $uid = $user->uid;

  game_stats_psid_is_open_check($psid);

  $gsid = _game_stats_get_game_session_by_psid($psid);
  if($gsid === FALSE)
    throw new Error(t("No gsid found for psid !psid.", array('!psid' => $psid)));

  //TODO:add user id to the mix
  $game_id = db_result(db_query("SELECT game_id FROM {games_game_session} WHERE gsid = %d", $gsid));
  $stored_time = _game_stats_time_diff_check($time);

  _game_stats_enter_session_data($game_id, 0, $gsid, TRUE, $stored_time, TRUE);
  _game_stats_enter_session_user_data($gsid, $uid, $score, TRUE);
  drupal_alter('game_stats_pre_complete_save', $stats, $game_id, $score);
  
  if(is_array($stats) && user_access('save stats')) {
    foreach($stats as $stat) {
      game_stats_save_stat($psid, $stat['sid'], $stat['value']);
    }
  } else if(is_array($stats) && !user_access('save stats')) {
    throw new Exception('Stats were posted without the user having permissions to save stats.');
  }
  
  _game_stats_close_play_sessions($game_id, $uid);
  module_invoke_all('game_stats_complete_game', $game_id, $gsid, $score);
}

function game_stats_register_stats($stats, $game_id) {
	$stat_return = array();
    
	drupal_alter('game_stats_pre_register_stats', $stats, $game_id);
	
	foreach($stats as $stat) {
		$name = $stat['adminName'];
		$type = $stat['statType'];
		$allowed_types = array('count', 'serializable', 'label', 'enum');
		if(empty($stat['adminName']) || empty($type) || !in_array($type, $allowed_types)) {
			throw new Exception("Invalid stat definition");
		}
		
		$result = db_fetch_array(db_query("SELECT stat_type, sid, admin_name FROM {games_stats} WHERE admin_name = '%s' and game_id = %d", $name, $game_id));
		if($result === FALSE) {
			$settings = array();
			$stat_data = game_stats_stat_create($game_id, $settings, $name, $type);
			$stat_return[$name] = (int)$stat_data['sid'];
		} else if($result['stat_type'] !== $type) {
			throw new Exception("Stat $name type doesn't match");
		} else if($result['admin_name'] !== $name) {
			throw new Exception("Stat $name case doesn't match");
		} else {
			$stat_return[$name] = (int)$result['sid'];
		}
	}
	return $stat_return;
}


/**
 * Close(set end time)the play session
 * @param $game_id
 * @param $time
 */
function game_stats_end_play_session($psid) {
	db_query("UPDATE {games_play_session} SET closed = 1 WHERE closed = 0 AND psid = %d", $psid);
}

/**
 * Store Player stats (Types: count, label, enum, serializable)
 * @param int $psid
 * @param int $sid
 * @param $value
 * 
 * returns false if $psid is already closed
 */
function game_stats_save_stat($psid, $sid, $value, $uid = NULL) {
  global $user;
  if(is_null($uid))
    $uid = $user->uid;
  
  game_stats_psid_is_open_check($psid);

  $type = db_result(db_query("SELECT stat_type FROM {games_stats} WHERE sid = %d", $sid));
  if($type === FALSE)
    throw new Exception("Stat not found.  psid: $psid sid: $sid value: $value");
  
  $gsid = _game_stats_get_game_session_by_psid($psid);
  if(isset($gsid))
    game_stats_value_create($sid, $gsid, $type, $value, $uid);
  else
    throw new Exception('The gsid for a stat is not set at the proper time.');

  module_invoke_all('game_stat_save', $sid, $gsid, $psid, $value, $uid);
}

function game_stats_get_stat_id_by_name($name) {
  return db_result(db_query('SELECT sid FROM {games_stats} WHERE admin_name = "%s"', $name));
}

/**
 * Get stat value by play session id and stat id
 * @param $psid
 * @param $sid
 * @param $type
 */
function game_stats_get_stat_value($psid, $sid, $type, $uid = FALSE) {
  $gsid = _game_stats_get_game_session_by_psid($psid);
  $table = 'games_'.$type.'_stat';

  if($use_uid)
    $value = db_result(db_query('SELECT value FROM {'.$table.'} WHERE gsid = %d AND sid = %d AND uid = %d', $gsid, $sid, $uid));
  else
    $value = db_result(db_query('SELECT value FROM {'.$table.'} WHERE gsid = %d AND sid = %d', $gsid, $sid));
  
  return $value;
}

function game_stats_get_user_high_score($game_id, $uid, $excluded_gsid = NULL) {
  if(is_null($excluded_gsid)) {
    $high_score = db_result(db_query('SELECT MAX(score) FROM {games_game_session} ggs
      INNER JOIN {games_game_session_users} ggsu ON ggsu.gsid = ggs.gsid
      WHERE uid = %d AND game_id = %d;', $uid, $game_id));
  } else {
    $high_score = db_result(db_query('SELECT MAX(score) FROM {games_game_session} ggs
      INNER JOIN {games_game_session_users} ggsu ON ggsu.gsid = ggs.gsid
      WHERE uid = %d AND game_id = %d AND ggs.gsid <> %d;', $uid, $game_id, $excluded_gsid));
  }
  return $high_score;
}

function game_stats_get_game_id_by_sid($sid) {
  return db_result(db_query('SELECT game_id FROM {games_stats} WHERE sid = %d', $sid));
}

/**
 * Checks to see if user has a game session created
 * @param $uid
 */
function game_stats_has_game_session($uid) {
  return db_result(db_query("SELECT COUNT(ggs.gsid) FROM {games_game_session} ggs 
    INNER JOIN {games_game_session_users} ggsu ON ggsu.gsid = ggs.gsid
    WHERE uid = %d", $uid));
}

function game_stats_get_game_session_user($gsid) {
  $result = db_query("SELECT * FROM {games_game_session_user} su
    LEFT JOIN {games_game_session} gs ON su.gsid = gs.gsid
    WHERE gs.complete <> 1 AND gsid = %d", $gsid);
  return db_fetch_array($result);
}

/**
 * Creates the json data that can be read into the game for stat tracking
 * @param $api_version
 * @param $tracing
 * @param $permit_offline
 * @param $permit_nonymous
 * @param $use_cookie
 */
function game_stats_add_js($game_id, $api_version = '6.x-2.x', $tracing = FALSE, $permit_offline = TRUE, $permit_anonymous = TRUE, $use_cookie = TRUE, $display_login = FALSE, $display_errors = TRUE) {
  global $base_url;
  $game_services_info = db_fetch_array(db_query("SELECT ggi.kid, sk.domain
    FROM {games_game_id} ggi
    LEFT JOIN {services_keys} sk ON sk.kid = ggi.kid
    WHERE ggi.game_id = %d", $game_id));
  $domain = $game_services_info['domain'];
  $api_key = $game_services_info['kid'];
  $enabled = user_access('use game stats');
  $query = isset($_GET['XDEBUG_PROFILE']) ? '?XDEBUG_PROFILE' : '';
  //dpr($query);
  $options = array(
    'tracing' => $tracing,
    'domain' => $domain,
    'apiKey' => $api_key,
    'apiVersion' => $api_version,
    'url' => $base_url.'/services/amfphp' . $query,
    'permitOffline' => $permit_offline,
    'permitAnonymous' => $permit_anonymous,
    'useCookie' => $use_cookie,
    'enabled' => $enabled,
    'displayLogin' => $display_login,
    'displayErrors' => $display_errors
  );
  
  $module_dir = drupal_get_path('module', 'game_stats');

  $options = array_merge($options, module_invoke_all('game_stats_add_js', $game_id));
  
  drupal_add_js($module_dir.'/js/game_stats.js');
  drupal_add_js(array('game_stats' => $options), 'setting');
}

function game_stats_psid_is_open($psid) {
  $psid_check = db_result(db_query("SELECT psid FROM {games_play_session} WHERE closed = 0 AND psid = %d", $psid));
  if($psid_check == FALSE)
    $return = FALSE;
  else
    $return = TRUE;

  return $return;
}

/**
 * Generate an options field list of game ids
 */
function game_stats_game_id_options() {
    module_load_include('inc', 'services_keyauth', 'services_keyauth');
	foreach(services_keyauth_get_keys() as $key) {
		$game_id = db_result(db_query("SELECT game_id FROM {games_game_id} WHERE kid = '%s'",$key->kid));
		$options[$game_id] = $key->title;
	}
	return $options;
}

/**
 * Gets the possible enum values for a give stat id
 * @param $sid
 * @return array
 */
function game_stats_get_enum_values($sid) {
  $query = db_query('SELECT value FROM games_enum WHERE sid = %d', $sid);
  while($row = db_fetch_array($query)) {
    $enum_values[] = $row['value'];
  }
  return $enum_values;
}

function game_stats_get_enum_value($eid) {
  $query = db_query('SELECT value FROM games_enum WHERE eid = %d', $eid);
  return db_result($query);
}

function game_stats_update_by_session_id($session_id, $uid) {
  $query = db_query('SELECT psid FROM {games_play_session} WHERE session_id = %d', $session_id);
  while($row = db_fetch_array($query)) {
    $gsid = _game_stats_get_game_session_by_psid($row['psid']);
    $data = array(
    	'gsid' => $gsid,
    	'uid' => $uid,
    );
    drupal_write_record('games_game_session', $data, 'gsid');
  }
}

/**
 * Gets the game_id by the games name stored in the service keys admin
 * @param $name
 */
function game_stats_game_id_by_name($name) {
  $game_id_list = game_stats_game_id_options();
  $game_id = array_keys($game_id_list, $name);
  return $game_id[0];
}

/**
 * Gets the node id by using the game_id
 * @param $game_id
 * @param $field - field to be returned
 */
function game_stats_get_nid_by_game_id($game_id, $field = NULL) {
  switch($field) {
    case 'nid':
    case 'vid':
      $field = 'n.'.$field;
      break;
  }
  
  if(is_null($field)) {
    $field = 'n.nid';
  }
  
  $query = db_query('SELECT %s FROM {node} n
					LEFT JOIN {content_type_flash_game} fg ON fg.vid = n.vid AND fg.nid = n.nid
					WHERE n.type = "flash_game" AND fg.field_service_key_value = %d', $field, $game_id);
  $field_value = db_result($query);
  return $field_value;
}

function game_stats_psid_is_open_check($psid) {
  $open = game_stats_psid_is_open($psid);
  if(!$open)
    throw new Exception('Play session '.$psid.' is already closed or not created.');
}

function game_stats_get_game_name($game_id) {
  $query = db_query("SELECT sk.title
    FROM {services_keys} sk
    INNER JOIN {games_game_id} ggi ON ggi.kid = sk.kid
    WHERE ggi.game_id = %d", $game_id);
  return db_result($query);
}

function game_stats_get_all_games() {
  $query = db_query('SELECT * FROM {services_keys} sk
    LEFT JOIN {games_game_id} ggi ON ggi.kid = sk.kid
    LEFT JOIN {content_type_flash_game} fg ON fg.field_service_key_value = ggi.game_id
    LEFT JOIN {node} n ON n.vid = fg.vid
    WHERE sk.domain NOT IN ("site","avatar_editor")');
  while($game = db_fetch_array($query)) {
    $games[] = $game;
  }
  return $games;
}