<?php
// $Id: game_event_views_handler_field_admin_link.inc
/**
 * Field handler to present a link to user edit.
 */
class game_event_views_handler_field_admin_links extends views_handler_field {
	// An example of field level access control.
	function access() {
		return user_access('admin game event logging');
	}

	function query() {
		$this->ensure_my_table();
		$this->add_additional_fields();
	}
	
	function render($values) {
		$edit_text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
		$delete_text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
		$etid = $values->etid;
		if (user_access('admin game event logging')) {
			$edit_link = l($edit_text, "admin/build/game-events/type/$etid", array('query' => drupal_get_destination()));
			$delete_link = l($delete_text, "admin/build/game-events/type/$etid/delete", array('query' => drupal_get_destination()));
			$output = "<div><span>$edit_link</span>  |  <span>$delete_link</span></div>";
			return $output;
		}
	}
}