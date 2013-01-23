<?php
class game_stats_views_handler_field_end_time extends views_handler_field_date {
	function query() {
		$query = "(SELECT MAX(end_time) as end_time
          			FROM games_play_session
					WHERE gsid = games_game_session_games_game_session_users.gsid)";
		
		$this->ensure_my_table();
		$this->field_alias = $this->query->add_field(NULL, $query, ($this->table_alias.'_'.$this->real_field));
		$this->add_additional_fields();
	}
}