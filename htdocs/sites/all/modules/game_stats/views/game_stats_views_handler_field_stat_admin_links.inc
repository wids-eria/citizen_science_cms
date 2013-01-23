<?php
// $Id: views_handler_field_user_link_edit.inc,v 1.1.4.1 2010/03/19 22:59:10 merlinofchaos Exp $
/**
 * Field handler to present a link to user edit.
 */
class game_stats_views_handler_field_stat_admin_links extends views_handler_field {
	// An example of field level access control.
	function access() {
		return user_access('admin game stats');
	}

	function query() {
		$this->ensure_my_table();
		$this->add_additional_fields();
	}
	
	function render($values) {
		$edit_text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
		$delete_text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
		$sid = $values->sid;
		if (user_access('admin game stats')) {
			$edit_link = l($edit_text, 'admin/build/game_stats/stat/'.$sid.'/edit', array('query' => drupal_get_destination()));
			$delete_link = l($delete_text, 'admin/build/game_stats/stat/'.$sid.'/delete', array('query' => drupal_get_destination()));
			$output = "<div><span>$edit_link</span>  |  <span>$delete_link</span></div>";
			return $output;
		}
	}
}