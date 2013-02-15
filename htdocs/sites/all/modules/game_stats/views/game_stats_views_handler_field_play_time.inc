<?php
class game_stats_views_handler_field_play_time extends views_handler_field_numeric {
	function query() {
		$query = "(SELECT ROUND((SUM(gpssub.end_time) - SUM(gpssub.start_time))/60) as play_time
					FROM games_play_session gpssub
					WHERE gpssub.gsid = games_game_session_games_game_session_users.gsid)";
		
		$this->ensure_my_table();
		$this->field_alias = $this->query->add_field(NULL, $query, ($this->table_alias.'_'.$this->real_field));
		$this->add_additional_fields();
	}
}