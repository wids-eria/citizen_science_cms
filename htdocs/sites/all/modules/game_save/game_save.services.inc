<?php
function _game_save_svc_save($psid, $game_state, $format, $save_time = NULL) {
  try {
    $gsid = _game_stats_get_game_session_by_psid($psid);
    if($gsid === FALSE)
      throw new Exception("No gsid found.  psid:".$psid);
    _game_save($gsid, $game_state, $format, $save_time);
  } catch (Exception $e) {
    return services_error($e->getMessage(), 500);
  }
}

function _game_save_svc_resume($gsid, $version, $time = NULL, $uid = NULL) {
  try {
    return _game_save_resume_game($gsid, $version, $time, $uid);
  } catch (Exception $e) {
    return services_error($e->getMessage(), 500);
  }
}

function _game_save_svc_list_saves($uid = NULL) {
  try {
    $game_id = _game_stats_get_game_id();
    return _game_save_list($game_id, $uid);
  } catch (Exception $e) {
    return services_error($e->getMessage(), 500);
  }
}