<?php
class game_stats_views_handler_filter_game_title extends views_handler_filter_many_to_one {
  function get_value_options() {
  	$query = db_query("SELECT title FROM {services_keys} WHERE title <> 'Site'");
  	while (($item = db_fetch_array($query)) !== FALSE) {
  		$titles[$item['title']] = $item['title'];
  	}
    $this->value_options = $titles;
  }
}