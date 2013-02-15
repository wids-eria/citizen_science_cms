<?php
function games_stats_insert_test_data() {
//	$today = time();
//	
//	$gs = 1;
//	while ($gs <= 150000) {
//		$game_session_values = array(
//			'game_id' => ($gs <= 75000) ? 5 : 6,
//			'uid' => $gs,
//			'score' => ($gs*2),
//			'complete' => 1,
//			'start_time' => ($today - ($gs*2)),
//			'end_time' => ($today - ($gs*2)) + 400,
//		);
//		drupal_write_record('games_game_session', $game_session_values);
//		$gs++;
//	}
//	
//	$s = 1;
//	while ($s <= 8) {
//		$settings1 = array();
//		$stats_values = array(
//			'game_id' => ($s <= 4) ? 5 : 6,
//			'settings' => $settings,
//			'stat_type' => "count",
//			'name' => "Stat $s",
//			'admin_name' => "stat_$s",
//			'description' => "This is test stat number $s",
//		);
//		drupal_write_record('games_stats', $stats_values);
//		$s++;
//	}
//
//	$se = 1;
//	while ($se <= 3) {
//		$settings2 = array();
//		$stats_values = array(
//			'game_id' => 1,
//			'settings' => $settings2,
//			'stat_type' => "serialized",
//			'name' => "Serialized Stat $se",
//			'admin_name' => "serialized_stat_$se",
//			'description' => "This is test serialized stat number $se",
//		);
//		drupal_write_record('games_stats', $stats_values);
//		$se++;
//	}
}

function games_stats_insert_test_count_data() {
//	$query = db_query('SELECT ggs.gsid, gs.sid FROM {games_game_session} ggs
//						LEFT JOIN {games_stats} gs ON gs.game_id = ggs.game_id
//						WHERE ggs.gsid > 13 AND gs.sid > 12');
//	$c = 1;
//	while(($row = db_fetch_array($query)) !== FALSE) {
//		$data = array(
//			'gsid' => $row['gsid'],
//			'sid' => $row['sid'],
//			'value' => $c,
//		);
//		drupal_write_record('games_count_stat', $data);
//		$c++;
//	}
}

function games_stats_insert_test_serialized_data() {
//	$query = db_query('SELECT ggs.gsid, gs.sid FROM {games_game_session} ggs
//						LEFT JOIN {games_stats} gs ON gs.game_id = ggs.game_id
//						WHERE gs.sid IN (21, 22, 23)');
//	$c = 1;
//	
//	while(($row = db_fetch_array($query)) !== FALSE) {
//		switch($c) {
//			case 1:
//				$serialized_data = array('Apple', 'Orange', 'Plum', 'Peach', 'Grape');
//				break;
//			case 2:
//				$serialized_data = array(
//					'first_choice' => 'Apple', 
//					'second_choice' => 'Orange', 
//					'third_choice' => 'Plum', 
//					'fourth_choice' => 'Peach', 
//					'fifth_choice' => 'Grape'
//				);
//				break;
//			case 3:
//				$serialized_data = array(
//					'Fruit' => array(
//						'first_fruit' => 'Apple', 
//						'second_fruit' => 'Orange',
//					),
//					'Grain' => array(
//						'first_grain' => 'Bread',
//						'second_grain' => 'Bagel',
//					)
//				);
//				break;
//		}
//		$data = array(
//			'gsid' => $row['gsid'],
//			'sid' => $row['sid'],
//			'value' => $serialized_data,
//		);
//		drupal_write_record('games_serializable_stat', $data);
//		$c++;
//	}
}