<?php
// $Id: draggableviews_handler_game_stats.inc,v 1.1.2.13 2009/10/15 21:39:49 sevi Exp $

/**
 * @file
 * The default implementation of draggableviews handlers.
 */

/*
 * Default Implementation: storage done by draggableviews
 */
class draggableviews_handler_game_stats extends draggableviews_handler {
	function save($sid, $value) {
		db_query('UPDATE {games_stats} SET weight = %d WHERE sid = %d', $value, $sid);
	}
}