<?php
/**
 * Implementation of hook_views_default_views().
 */
function game_event_logging_views_default_views() {
  /*
   * View 'game_event_type_admin'
   */
  $view = new view;
  $view->name = 'game_event_type_admin';
  $view->description = 'A list of event types created by games.';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'game_event_type';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'name' => array(
      'label' => 'Admin Name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'game_event_type',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '<em>No title provided.</em>',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'game_event_type',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'description' => array(
      'label' => 'Description',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '<em>No description provided.</em>',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'description',
      'table' => 'game_event_type',
      'field' => 'description',
      'relationship' => 'none',
    ),
    'format' => array(
      'label' => 'Format',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '<em>No format provided.</em>',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'format',
      'table' => 'game_event_type',
      'field' => 'format',
      'relationship' => 'none',
    ),
    'admin_links' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'admin_links',
      'table' => 'game_event_type',
      'field' => 'admin_links',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Game Events Admin');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'name' => 'name',
      'title' => 'title',
      'description' => 'description',
      'format' => 'format',
      'admin_links' => 'admin_links',
    ),
    'info' => array(
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'description' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'format' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'admin_links' => array(
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Game events', 'page_1');
	$handler->override_option('path', 'admin/build/game-events/types');
	$handler->override_option('menu', array(
	  'type' => 'tab',
	  'title' => 'Types',
	  'description' => 'Game event types',
	  'weight' => '0',
	  'name' => 'admin',
	));
	$handler->override_option('tab_options', array(
	  'type' => 'none',
	  'title' => '',
	  'description' => '',
	  'weight' => 0,
	  'name' => 'navigation',
	));
	  
  $views[$view->name] = $view;
$view = new view;
$view->name = 'game_events';
$view->description = 'Game events';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'game_event';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('relationships', array(
  'psid' => array(
    'label' => 'Play session',
    'required' => 1,
    'id' => 'psid',
    'table' => 'game_event',
    'field' => 'psid',
    'relationship' => 'none',
  ),
  'gsid' => array(
    'label' => 'Game session',
    'required' => 1,
    'id' => 'gsid',
    'table' => 'games_play_session',
    'field' => 'gsid',
    'relationship' => 'psid',
  ),
  'etid' => array(
    'label' => 'Event Type',
    'required' => 1,
    'id' => 'etid',
    'table' => 'game_event',
    'field' => 'etid',
    'relationship' => 'none',
  ),
  'game_id' => array(
    'label' => 'Game',
    'required' => 1,
    'id' => 'game_id',
    'table' => 'games_play_session',
    'field' => 'game_id',
    'relationship' => 'psid',
    'override' => array(
      'button' => 'Override',
    ),
  ),
  'kid' => array(
    'label' => 'Services Key',
    'required' => 1,
    'id' => 'kid',
    'table' => 'games_game_id',
    'field' => 'kid',
    'relationship' => 'game_id',
    'override' => array(
      'button' => 'Override',
    ),
  ),
  'uid' => array(
    'label' => 'User',
    'required' => 1,
    'id' => 'uid',
    'table' => 'games_play_session',
    'field' => 'uid',
    'relationship' => 'psid',
  ),
));
$handler->override_option('fields', array(
  'timestamp' => array(
    'label' => 'Timestamp',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'date_format' => 'custom',
    'custom_date_format' => 'd M Y g:i:s a',
    'exclude' => 0,
    'id' => 'timestamp',
    'table' => 'game_event',
    'field' => 'timestamp',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Override',
    ),
  ),
  'gsid' => array(
    'label' => 'Game Session ID',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'set_precision' => FALSE,
    'precision' => 0,
    'decimal' => '.',
    'separator' => '',
    'prefix' => '',
    'suffix' => '',
    'exclude' => 0,
    'id' => 'gsid',
    'table' => 'games_game_session',
    'field' => 'gsid',
    'relationship' => 'gsid',
    'override' => array(
      'button' => 'Override',
    ),
  ),
  'title' => array(
    'label' => 'Game',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'services_keys',
    'field' => 'title',
    'relationship' => 'kid',
    'override' => array(
      'button' => 'Override',
    ),
  ),
  'name' => array(
    'label' => 'Type',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'name',
    'table' => 'game_event_type',
    'field' => 'name',
    'relationship' => 'etid',
  ),
  'log_message' => array(
    'label' => 'Message',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'log_message',
    'table' => 'game_event',
    'field' => 'log_message',
    'relationship' => 'none',
  ),
  'name_1' => array(
    'label' => 'Account',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_user' => 1,
    'overwrite_anonymous' => 0,
    'anonymous_text' => '',
    'exclude' => 0,
    'id' => 'name_1',
    'table' => 'users',
    'field' => 'name',
    'relationship' => 'uid',
  ),
));
$handler->override_option('filters', array(
  'uid' => array(
    'operator' => 'in',
    'value' => '',
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'uid_op',
      'identifier' => 'uid',
      'label' => 'Username',
      'optional' => 1,
      'remember' => 0,
      'reduce' => 0,
    ),
    'id' => 'uid',
    'table' => 'users',
    'field' => 'uid',
    'relationship' => 'uid',
  ),
  'title' => array(
    'operator' => 'or',
    'value' => array(),
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'title_op',
      'identifier' => 'title',
      'label' => 'Game',
      'optional' => 1,
      'single' => 0,
      'remember' => 0,
      'reduce' => 0,
    ),
    'id' => 'title',
    'table' => 'services_keys',
    'field' => 'title',
    'relationship' => 'kid',
    'override' => array(
      'button' => 'Override',
    ),
    'reduce_duplicates' => 0,
  ),
  'gsid' => array(
    'operator' => '=',
    'value' => array(
      'value' => '',
      'min' => '',
      'max' => '',
    ),
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'gsid_op',
      'identifier' => 'gsid',
      'label' => 'Game Session ID',
      'optional' => 1,
      'remember' => 0,
    ),
    'id' => 'gsid',
    'table' => 'games_game_session',
    'field' => 'gsid',
    'relationship' => 'gsid',
    'override' => array(
      'button' => 'Override',
    ),
  ),
));
$handler->override_option('access', array(
  'type' => 'perm',
  'perm' => 'access site reports',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('title', 'Game events');
$handler->override_option('empty', 'No events.');
$handler->override_option('empty_format', '1');
$handler->override_option('use_ajax', TRUE);
$handler->override_option('items_per_page', 20);
$handler->override_option('use_pager', '1');
$handler->override_option('style_plugin', 'table');
$handler->override_option('style_options', array(
  'grouping' => '',
  'override' => 1,
  'sticky' => 0,
  'order' => 'desc',
  'columns' => array(
    'timestamp' => 'timestamp',
    'gsid' => 'gsid',
    'name_1' => 'name_1',
    'title' => 'title',
    'name' => 'name',
    'log_message' => 'log_message',
  ),
  'info' => array(
    'timestamp' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'gsid' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'name_1' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'title' => array(
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'log_message' => array(
      'separator' => '',
    ),
  ),
  'default' => 'timestamp',
));
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('path', 'admin/reports/game/events');
$handler->override_option('menu', array(
  'type' => 'default tab',
  'title' => 'Events',
  'description' => '',
  'weight' => '0',
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'normal',
  'title' => 'Games',
  'description' => '',
  'weight' => '0',
  'name' => 'admin',
));

$views[$view->name] = $view;  

  return $views;
}