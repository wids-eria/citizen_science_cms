<?php
/**
 * @file
 * Views integration for Game Event Logging module.
 */

/**
 * Implementation of hook_views_data()
 */
function game_event_logging_views_data() {	
	$data['game_event_type'] = array(
		'table' => array(
			'group' => t('Game Event'),
			'base' => array(
				'field' => 'etid',
				'title' => t('Game Event Types'),
				'help' => t('Event types that have been created by games.'),
			),
		),
		'etid' => array(
			'title'	=> t('Event Type:ID'),
			'help'	=> t('The event type ID.'),
			'field'	=> array(
				'handler' => 'views_handler_field_numeric',
				'click sortable' => TRUE,
			),
			'filter'=> array(
				'handler' => 'views_handler_filter_numeric',
			),
			'argument' => array(
				'handler' => 'views_handler_argument_numeric'
			)
		),
		'name' => array(
			'title'	=> t('Event Type:Admin Name'),
			'help'	=> t('The admin name of the event type created by the game.'),
			'field' => array(
				'handler' => 'views_handler_field',
				'click sortable' => TRUE,
			),
			'sort' => array(
				'handler' => 'views_handler_sort'
			),
		),
		'title' => array(
			'title'	=> t('Event Type:Title'),
			'help'	=> t('The title of the event type created by the user.'),
			'field' => array(
				'handler' => 'views_handler_field',
				'click sortable' => TRUE,
			),
			'sort' => array(
				'handler' => 'views_handler_sort'
			),
		),
		'description' => array(
			'title'	=> 'Event Type:Description',
			'help'	=> t('The description of the stat.'),
			'field' => array(
				'handler' => 'views_handler_field',
				'click sortable' => TRUE,
			),
		),
		'format' => array(
			'title'	=> 'Event Type:Format',
			'help'	=> t('The format of the event type output when the event is displayed.'),
			'field' => array(
				'handler' => 'views_handler_field',
				'click sortable' => TRUE,
			),
		),
		'admin_links' => array(
			'title' => t('Event Type:Admin Links'),
			'help' 	=> t('Link to edit the event type name, description, format, and a link to delete the stat.'),
			'field' => array(
				'handler' => 'game_event_views_handler_field_admin_links',
			),
		),
	);
	$data['game_event'] = array(
		'table' => array(
			'group' => t('Game Event'),
			'base' => array(
				'field' => 'eid',
				'title' => t('Game Events'),
				'help' => t('Events created by games.'),
			),
		),
		'eid' => array(
			'title' 	=> t('Event:Event ID'),
			'help' 		=> t('The event id.'),
			'filter'	=> array(
				'handler' => 'views_handler_filter_numeric',
			),
			'argument' 	=> array(
				'handler' => 'views_handler_argument_numeric'
			)
		),
		'psid' => array(
			'title' 	=> t('Event:Play Session ID'),
			'help' 		=> t('The id play session when the event happened.'),
			'filter'	=> array(
				'handler' => 'views_handler_filter_numeric',
			),			
			'argument' 	=> array(
				'handler' => 'views_handler_argument_numeric'
			),
			'relationship' => array(
				'base' => 'games_play_session',
				'base field' => 'psid',
				'relationship field' => 'psid',
				'label' => 'Play session'
			)
		),
		'timestamp' => array(
			'title' => t('Event:Timestamp'),
			'help' 	=> t('Time the event happened.'),
			'filter'	=> array(
				'handler' => 'views_handler_filter_date',
			),			
			'argument' 	=> array(
				'handler' => 'views_handler_argument_date'
			),
			'field' => array(
		    	'handler' 		=> 'views_handler_field_date',
				'click sortable'=> TRUE,
			),
		),
		'etid' => array(
			'title' => t('Event:Event Type'),
			'help'	=> t('The type of event that is being displayed.'),
			'relationship' => array(
				'handler' 			=> 'views_handler_relationship',
				'base' 				=> 'game_event_type',
				'base field'		=> 'etid',
				'relationship field'=> 'etid',
				'label'				=> 'Event Type'
			)
		),
		'log_message' => array(
			'title' => t('Event:Log Message'),
			'help' 	=> t('Message that is logged for the event.'),
			'field' => array(
		    	'handler' => 'game_event_views_handler_field_log_message',
			),
		),
	);
	return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function game_event_logging_views_handlers() {
	return array(
		'info' => array(
			'path' => drupal_get_path('module', 'game_event_logging') .'/views',
		),
		'handlers' => array(
			'game_event_views_handler_field_admin_links' => array(
				'parent' => 'views_handler_field',
			),
			'game_event_views_handler_field_log_message' => array(
				'parent' => 'views_handler_field',
			),
		),
	);
}