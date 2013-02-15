<?php
// $Id: game_event_views_handler_field_log_message.inc
/**
 * Field handler to display the formated logged message.
 */
class game_event_views_handler_field_log_message extends views_handler_field {
	function query() {
		$this->ensure_my_table();
		$this->add_additional_fields();
	}
	
	function render($values) {
		$eid = $values->eid;
		$output = game_event_logging_event_message($eid);
		return $output;
	}
}