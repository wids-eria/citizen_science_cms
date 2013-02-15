<?php
/**
 * @file
 * Views integration for Game Stats module.
 */

/**
 * Implementation of hook_views_data()
 */
function game_stats_views_data() {
  $data['games_play_session'] = array(
    'table' => array(
      'group' => t('Game Stats'),
      'base' => array(
        'field' => 'psid',
        'title' => t('Game Play Sessions'),
        'help' => t('Sessions of play')
      ),
    ),
    'psid' => array(
      'title' => t('Play Session:Play Session ID'),
      'help' => t('The id of the play session.'),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric'
      ),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
    ),
    'game_id' => array(
      'title' => 'Play Session:Game ID',
      'help' => t('The ID of the game played in the game session.'),
      'relationship' => array(
        'base' => 'games_game_id',
        'base field' => 'game_id',
        'label' => 'Game'
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric'
      ),
    ),
    'gsid' => array(
      'title' => 'Play Session:Game Session ID',
      'help' => t('The ID of the game session.'),
      'relationship' => array(
        'base' => 'games_game_session',
        'base field' => 'gsid',
        'label' => 'Game session'
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric'
      ),
    ),
    'start_time' => array(
      'title' => t('Play Session:Start Time'),
      'help' => t('The start time of the game session.'),
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
    ),
    'end_time' =>array(
      'title' => t('Play Session:End Time'),
      'help' => t('The end time of the game session.'),
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
    ),
    'date_filter'=>array(
      'title' => t('Play Session:Date'),
      'help' => t('Play session dates'),
      'filter' => array(
        'handler' => 'game_stats_date_api_filter_handler',
        'base' => 'games_play_session',
        'empty field name' => t('Undated'),
      )
    ),
    'uid' => array(
      'title' => t('Play Session:Player'),
      'help' => t('The ID of the user that played in the game session.'),
      'field' => array(
        'handler' => 'views_handler_field_user'
      ),
      'sort' => array(
        'handler' => 'views_handler_sort'
      ),
      'relationship' => array(
        'base' => 'users',
        'base field' => 'uid',
        'label' => 'User'
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
    ),
    'version' => array(
      'title' => t('Play Session:Version'),
      'help' => t('Version of the game.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric'
      ),
      'sort' => array(
        'handler' => 'views_handler_sort'
      ),
    ),
  );
        
  //TODO: construct differently to handle a 'games_game_session_users' table
  $data['games_game_session_users'] = array(
      'table' => array(
          'group' => t('Game Stats'),
          'base' => array(
              'field' => 'gsid',
              'title' => t('Game Session Users'),
              'help' => t('Game playthrough users')
          ),
      ),
      'gsid' => array(
          'title' => t('Game Session:Game Session ID'),
          'help' => t('The session ID of the game played in the game session.'),
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => TRUE,
          ),
          'filter' => array(
              'handler' => 'views_handler_filter_numeric',
          ),
          'argument' => array(
              'handler' => 'views_handler_argument_numeric'
          ),
          'relationship' => array(
              'base' => 'games_game_session',
              'base field' => 'gsid',
              'label' => 'Game Session'
          ),
      ),
      'uid' => array(
          'title' => t('Game Session:Player'),
          'help' => t('The ID of the user that played in the game session.'),
          'field' => array(
              'handler' => 'views_handler_field_user'
          ),
          'sort' => array(
              'handler' => 'views_handler_sort'
          ),
          'relationship' => array(
              'base' => 'users',
              'base field' => 'uid',
              'label' => 'User'
          ),
      ),
      'score' => array(
          'title' => t('Game Session:Score'),
          'help' => t('The score of the game session.'),
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => TRUE,
          ),
          'sort' => array(
              'handler' => 'views_handler_sort'
          ),
          'filter' => array(
              'handler' => 'views_handler_filter_numeric',
          ),
      ),
      'count_stat' => array(
          'title' => t('Count Stats'),
          'help' => 'Stat values for the session',
          'group' => 'Game Stats',
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_count_stat',
              'base field' => 'gsid',
              'relationship field' => 'gsid',
              'label' => 'Count Stat'
          )
      ),
      'label_stat' => array(
          'title' => t('Label Stats'),
          'help' => 'Stat values for the session',
          'group' => 'Game Stats',
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_label_stat',
              'base field' => 'gsid',
              'relationship field' => 'gsid',
              'label' => 'Label Stat'
          )
      ),
      'enum_stat' => array(
          'title' => t('Enum Stats'),
          'help' => 'Stat values for the session',
          'group' => 'Game Stats',
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_enum_stat',
              'base field' => 'gsid',
              'relationship field' => 'gsid',
              'label' => 'Enum Stat'
          )
      ),
      'serializable_stat' => array(
          'title' => t('Serializable Stats'),
          'help' => 'Stat values for the session',
          'group' => 'Game Stats',
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_serializable_stat',
              'base field' => 'gsid',
              'relationship field' => 'gsid',
              'label' => 'Serializable Stat'
          )
      ),
  );
        
  $data['games_game_session'] = array(
      'table' => array(
          'group' => t('Game Stats'),
          'base' => array(
              'field' => 'gsid',
              'title' => t('Game Sessions'),
              'help' => t('Game playthroughs')
          ),
      ),
      'gsid' => array(
          'title' => t('Game Session:Game Session ID'),
          'help' => t('The session ID of the game played in the game session.'),
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => TRUE,
          ),
          'filter' => array(
              'handler' => 'views_handler_filter_numeric',
          ),
          'argument' => array(
              'handler' => 'views_handler_argument_numeric'
          ),
          'relationship' => array(
              'base' => 'games_game_session_users',
              'base field' => 'gsid',
              'label' => 'Game Session Users'
          ),
      ),
      'game_id' => array(
          'title' => t('Game Session:Game ID'),
          'help' => t('The ID of the game played in the game session.'),
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => TRUE,
          ),
          'filter' => array(
              'handler' => 'views_handler_filter_numeric',
          ),
          'argument' => array(
              'handler' => 'views_handler_argument_numeric'
          ),
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_game_id',
              'base field' => 'game_id',
              'relationship field' => 'game_id',
              'label' => 'Game ID'
          ),
      ),
//      'uid' => array(
//          'title'			=> t('Game Session:Player'),
//          'help'			=> t('The ID of the user that played in the game session.'),
//          'field' => array(
//              'handler' => 'views_handler_field_user'
//          ),
//          'sort' => array(
//              'handler' => 'views_handler_sort'
//          ),
//          'relationship' 	=> array(
//              'base' 	=> 'users',
//              'base field' => 'uid',
//              'label' => 'User'
//          ),
//      ),
      'complete' => array(
          'title' => t('Game Session:Completed'),
          'help' 	=> t('Sees if the game session was completed or not.'),
          'field' => array(
              'handler' => 'views_handler_field_boolean',
              'click sortable' => TRUE,
          ),
          'filter'=> array(
              'handler' => 'views_handler_filter_boolean_operator',
          ),
      ),
//      'score' => array(
//          'title'	=> t('Game Session:Score'),
//          'help'	=> t('The score of the game session.'),
//          'field' => array(
//              'handler' => 'views_handler_field_numeric',
//              'click sortable' => TRUE,
//          ),
//          'sort' => array(
//              'handler' => 'views_handler_sort'
//          ),
//          'filter'=> array(
//              'handler' => 'views_handler_filter_numeric',
//          ),
//      ),
      'start_time' => array(
          'title' => t('Game Session:Start Time'),
          'help' => t('The start time of the game session.'),
          'field' => array(
              'handler' => 'views_handler_field_date',
              'click sortable' => TRUE,
          ),
          'filter'=> array(
              'handler' => 'views_handler_filter_date',
          ),
      ),
      'end_time' => array(
          'title' => t('Game Session:End Time'),
          'help' => t('The end time of the game session.'),
          'field' => array(
              'handler' => 'views_handler_field_date',
              'click sortable' => TRUE,
          ),
          'filter'=> array(
              'handler' => 'views_handler_filter_date',
          ),
      ),
      'count_stat' => array(
          'title' => t('Count Stats'),
          'help' => 'Stat values for the session',
          'group' => 'Game Stats',
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_count_stat',
              'base field' => 'gsid',
              'relationship field' => 'gsid',
              'label' => 'Count Stat'
          )
      ),
      'label_stat' => array(
          'title' => t('Label Stats'),
          'help' => 'Stat values for the session',
          'group' => 'Game Stats',
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_label_stat',
              'base field' => 'gsid',
              'relationship field' => 'gsid',
              'label' => 'Label Stat'
          )
      ),
      'enum_stat' => array(
          'title' => t('Enum Stats'),
          'help' => 'Stat values for the session',
          'group' => 'Game Stats',
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_enum_stat',
              'base field' => 'gsid',
              'relationship field' => 'gsid',
              'label' => 'Enum Stat'
          )
      ),
      'serializable_stat' => array(
          'title' => t('Serializable Stats'),
          'help' => 'Stat values for the session',
          'group' => 'Game Stats',
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_serializable_stat',
              'base field' => 'gsid',
              'relationship field' => 'gsid',
              'label' => 'Serializable Stat'
          )
      ),
      'game_play_session' => array(
          'title' => t('Play Session'),
          'help' => 'The game sessions play sessions',
          'group' => 'Game Stats',
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_play_session',
              'base field' => 'gsid',
              'relationship field' => 'gsid',
              'label' => 'Game Play Session'
          ),
      ),
      'play_time' => array(
          'title' => t('Play Time'),
          'help' => t('The total play time for one game session.'),
          'group' => 'Game Stats',
          'field' => array(
              'handler' => 'game_stats_views_handler_field_play_time',
              'click sortable' => TRUE,
          ),
      ),
      'game_end_time' => array(
          'title' => t('End Time'),
          'help' => t('The end time based off of the play session.'),
          'group' => 'Game Stats',
          'field' => array(
              'handler' => 'game_stats_views_handler_field_end_time',
              'click sortable' => TRUE,
          ),
      )
  );

  $data['games_stats'] = array(
      'table' => array(
          'group' => t('Game Stats'),
          'base' => array(
              'field' => 'sid',
              'title' => t('Game Stats'),
              'help' => t('Stats that have been created by games.'),
          ),
      ),
      'sid' => array(
          'title'	=> 'Stat:Stat ID',
          'help'	=> t('The ID of the stat.'),
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => TRUE,
          ),
      ),
      'admin_name' => array(
          'title'	=> 'Stat:Admin Name',
          'help'	=> t('The administrative name of the stat.'),
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => TRUE,
          ),
          'sort' => array(
              'handler' => 'views_handler_sort'
          ),
      ),
      'name' => array(
          'title'	=> 'Stat:Name',
          'help'	=> t('The name of the stat.'),
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => TRUE,
          ),
          'sort' => array(
              'handler' => 'views_handler_sort'
          ),
      ),
      'description' => array(
          'title'	=> 'Stat:Description',
          'help'	=> t('The description of the stat.'),
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => TRUE,
          ),
      ),
      'game_id' => array(
          'title'	=> 'Stat:Game ID',
          'help'	=> t('The ID of the game played in the game session.'),
          'field' => array(
              'handler' => 'views_handler_field_numeric',
              'click sortable' => TRUE,
          ),
          'argument' => array(
              'handler' => 'views_handler_argument_numeric'
          ),
      ),
      'stat_type' => array(
          'title'	=> 'Stat:Stat Type',
          'help'	=> t('The type of stat it is.'),
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => TRUE,
          ),
      ),
      'game_name' => array(
          'title' => t('Game Key ID'),
          'help' => 'Name of the game',
          'group' => 'Game Stats',
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_game_id',
              'base field' => 'game_id',
              'relationship field' => 'game_id',
              'label' => 'Game Key ID'
          ),
      ),
      'admin_links' => array(
          'title' => t('Stat Admin Links'),
          'help' => t('Link to edit the stat name and description and a link to delete the stat.'),
          'group' => 'Game Stats',
          'field' => array(
              'handler' => 'game_stats_views_handler_field_stat_admin_links',
          ),
      ),
      'weight' => array(
          'title' => t('Stat Weight'),
          'help' => t('Weight of the stat.'),
          'group' => 'Game Stats',
          'field' => array(
              'handler' => 'views_handler_field_numeric'
          ),
          'sort' => array(
              'handler' => 'views_handler_sort'
          ),
      ),
      'hidden' => array(
          'title' => t('Stat Hidden'),
          'help' => t('Hidden state of the stat'),
          'group' => 'Game Stats',
          'field' => array(
              'handler' => 'views_handler_field_numeric'
          ),
      ),
  );

  //TODO:add new views data to handle the games_game_session_users table
  $data['games_enum'] =array(
      'table' => array(
          'group' => t('Game Stats'),
      ),
      'value' => array(
          'title' => t('Enumerator:Enum Stat'),
          'help'	=> t('The enum value for a stats.'),
          'field' => array(
              'handler' => 'views_handler_field',
              'click sortable' => TRUE,
          ),
      ),
  );
  
  $data['games_count_stat'] = array(
      'table' => array(
          'group' => t('Game Stats'),
      ),
      'sid' => array(
          'title' => t('Count Stat ID'),
          'help' => t('The ID of a specific stat'),
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_stats',
              'base field' => 'sid',
              'relationship field' => 'sid',
              'label' => 'Count Stat ID',
          ),
          'field' => array(
              'handler' => 'views_handler_field_numeric'
          )
      ),
      'value' => array(
          'title' => t('Count Stat Value'),
          'help'	=> t('The  value for a single count stat.'),
          'field' => array(
              'handler' => 'views_handler_field_numeric'
          ),
      ),
  );
  
  $data['games_label_stat'] = array(
      'table' => array(
          'group' => t('Game Stats'),
      ),
      'sid' => array(
          'title' => t('Label Stat ID'),
          'help' => t('The ID of a specific stat'),
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_stats',
              'base field' => 'sid',
              'relationship field' => 'sid',
              'label' => 'Label Stat ID',
          ),
          'field' => array(
              'handler' => 'views_handler_field_numeric'
          )
      ),
      'value' => array(
          'title' => t('Label Stat Value'),
          'help'	=> t('The  value for a single label stat.'),
          'field' => array(
              'handler' => 'views_handler_field'
          ),
      ),
  );
  
  $data['games_serializable_stat'] = array(
      'table' => array(
          'group' => t('Game Stats'),
      ),
      'sid' => array(
          'title' => t('Serializable Stat ID'),
          'help' => t('The ID of a specific stat'),
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_stats',
              'base field' => 'sid',
              'relationship field' => 'sid',
              'label' => 'Enum Serializable ID',
          ),
          'field' => array(
              'handler' => 'views_handler_field_numeric'
          )
      ),
      'value' => array(
          'title' => t('Serializable Stat Value'),
          'help'	=> t('The  value for a single serializable stat.'),
          'field' => array(
              'handler' => 'views_handler_field'
          ),
      ),
  );
  
  $data['games_enum_stat'] = array(
      'table' => array(
          'group' => t('Game Stats'),
      ),
      'sid' => array(
          'title' => t('Enum Stat ID'),
          'help' => t('The ID of a specific stat'),
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_stats',
              'base field' => 'sid',
              'relationship field' => 'sid',
              'label' => 'Enum Stat ID',
          ),
          'field' => array(
              'handler' => 'views_handler_field_numeric'
          )
      ),
      'value' => array(
          'title' => t('Enum Stat Value'),
          'help'	=> t('The value for a single enum stat.'),
          'field' => array(
              'handler' => 'views_handler_field_numeric'
          ),
          'relationship' => array(
              'handler' => 'views_handler_relationship',
              'base' => 'games_enum',
              'base field' => 'eid',
              'label' => 'Enum Stat Value',
          )
      ),
  );
	
	$data['games_game_id'] = array(
		'table' => array(
			'group' => t('Game Stats'),
		),
		'kid' => array(
			'title' => t('Services Key'),
			'help' => t('The domain name of the key to link to the games name'),
			'relationship' => array(
				'handler' => 'views_handler_relationship',
				'base' => 'services_keys',
				'base field' => 'kid',
				'relationship field' => 'kid',
				'label' => 'Services Key',
			),
		),
	);
	
	$data['services_keys'] = array(
		'table' => array(
			'group' => t('Game Stats'),
		),
		'title' => array(
			'title' => t('Game Name'),
			'help' => t('The game name'),
			'field' => array(
				'handler' => 'views_handler_field'
			),
			'filter' => array(
				'handler' => 'game_stats_views_handler_filter_game_title',
			)
		),
	);
		
	return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function game_stats_views_handlers() {
	return array(
		'info' => array(
			'path' => drupal_get_path('module', 'game_stats') .'/views',
		),
		'handlers' => array(
			'game_stats_date_api_filter_handler' => array(
				'parent' => 'date_api_filter_handler',
			),
			'game_stats_views_handler_filter_game_title' => array(
				'parent' => 'views_handler_filter_many_to_one',
			),
			'game_stats_views_handler_field_play_time' => array(
				'parent' => 'views_handler_field_numeric',
			),
			'game_stats_views_handler_field_stat_admin_links' => array(
				'parent' => 'views_handler_field',
			),
			'game_stats_views_handler_field_end_time' => array(
				'parent' => 'views_handler_field_date',
			),
		),
	);
}
