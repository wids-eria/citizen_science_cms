<?php
function games_event_insert_test_data() {
	//Create an event type with params
	$event_type_data = array(
		'name' => 'test_event',
	);
	$event_type = drupal_write_record('game_event_type', $event_type_data);
	
	$event_type_param_data1 = array(
		'etid' => $event_type['etid'],
		'idx' => 0,
		'name' => 'test_1'
	);
	drupal_write_record('game_event_type_param', $event_type_param_data1);
	$event_type_param_data2 = array(
		'etid' => $event_type['etid'],
		'idx' => 1,
		'name' => 'test_2'
	);
	drupal_write_record('game_event_type_param', $event_type_param_data2);
	
	//Create events with two seperate psids 1 and 2
	$event_data1 = array(
		'psid' => 1,
		'timestamp' => time(),
	);
	drupal_write_record('game_event', $event_data1);
	$event_data2 = array(
		'psid' => 2,
		'timestamp' => time(),
	);
	drupal_write_record('game_event', $event_data2);
	
	//Create event arg data (FAILS!!!!)
	$arg_data1 = array(
		'eid' => $event_data1['eid'],
		'idx' => $event_type_param_data1['idx'],
		'value' => 'test 1'
	);
	drupal_write_record('game_event_arg', $arg_data1);
	$arg_data2 = array(
		'eid' => $event_data1['eid'],
		'idx' => $event_type_param_data2['idx'],
		'value' => 'test 2'
	);
	drupal_write_record('game_event_arg', $arg_data2);
	$arg_data3 = array(
		'eid' => $event_data2['eid'],
		'idx' => $event_type_param_data1['idx'],
		'value' => 'test 3'
	);
	drupal_write_record('game_event_arg', $arg_data3);
	$arg_data4 = array(
		'eid' => $event_data2['eid'],
		'idx' => $event_type_param_data2['idx'],
		'value' => 'test 4'
	);
	drupal_write_record('game_event_arg', $arg_data4);
	
	return "Test data inserted.";
}

function games_event_delete_test_data() {
	db_query('DELETE FROM {game_event_type}');
	db_query('DELETE FROM {game_event_type_param}');
	db_query('DELETE FROM {game_event_arg}');
	db_query('DELETE FROM {game_event}');
	return "Test data deleted.";
}