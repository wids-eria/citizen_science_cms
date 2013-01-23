<?php
/**
 * Implementation of hook_views_default_views().
 */
function game_stats_views_default_views() {
  /*
   * View 'game_stats_admin'
   */
  $view = new view;
  $view->name = 'game_stats_admin';
  $view->description = 'A list of stats created by games.';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'games_stats';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'game_name' => array(
      'label' => 'Game Key ID',
      'required' => 1,
      'id' => 'game_name',
      'table' => 'games_stats',
      'field' => 'game_name',
      'relationship' => 'none',
    ),
    'kid' => array(
      'label' => 'Game Name',
      'required' => 1,
      'id' => 'kid',
      'table' => 'games_game_id',
      'field' => 'kid',
      'relationship' => 'game_name',
    ),
  ));
  $handler->override_option('fields', array(
    'admin_name' => array(
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
      'id' => 'admin_name',
      'table' => 'games_stats',
      'field' => 'admin_name',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'name' => array(
      'label' => 'Name',
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
      'empty' => '<em>No name provided.</em>',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'games_stats',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'stat_type' => array(
      'label' => 'Stat Type',
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
      'id' => 'stat_type',
      'table' => 'games_stats',
      'field' => 'stat_type',
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
      'table' => 'games_stats',
      'field' => 'description',
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
      'hide_empty' => 1,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'admin_links',
      'table' => 'games_stats',
      'field' => 'admin_links',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'sid' => array(
      'label' => 'Stat ID',
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
      'exclude' => 1,
      'id' => 'sid',
      'table' => 'games_stats',
      'field' => 'sid',
      'relationship' => 'none',
    ),
    'weight' => array(
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
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'weight',
      'table' => 'games_stats',
      'field' => 'weight',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'weight' => array(
      'order' => 'ASC',
      'id' => 'weight',
      'table' => 'games_stats',
      'field' => 'weight',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'game_id' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'game_id',
      'table' => 'games_stats',
      'field' => 'game_id',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '5' => 0,
        '7' => 0,
        '6' => 0,
        '3' => 0,
        '11' => 0,
        '4' => 0,
        '8' => 0,
        '12' => 0,
        '9' => 0,
        '10' => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'advpoll_binary' => 0,
        'advpoll_ranking' => 0,
        'achievement' => 0,
        'flash_game' => 0,
        'product' => 0,
        'weblinks' => 0,
        'forum' => 0,
        'assignment' => 0,
        'web_quest' => 0,
        'class' => 0,
        'class_announcement' => 0,
        'curriculum_unit' => 0,
        'justice_profile' => 0,
        'lesson_plan' => 0,
        'page' => 0,
        'profile' => 0,
        'public_user_info' => 0,
        'simplenews' => 0,
        'story' => 0,
        'subject_page' => 0,
        'talk_to_justice' => 0,
        'teacher_subject_page' => 0,
        'tribal_government' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_is_member' => 'OG_VIEWS_DO_NOT_VALIDATE_MEMBERSHIP',
      'validate_argument_group_node_type' => array(
        'class' => 0,
      ),
      'validate_argument_vocabulary' => array(
        '1' => 0,
        '14' => 0,
        '15' => 0,
        '12' => 0,
        '17' => 0,
        '19' => 0,
        '4' => 0,
        '16' => 0,
        '5' => 0,
        '18' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'admin game stats',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Game Stats');
  $handler->override_option('empty', 'No stats.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'draggabletable');
  $handler->override_option('style_options', array(
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'admin_name' => 'admin_name',
      'name' => 'name',
      'stat_type' => 'stat_type',
      'description' => 'description',
      'admin_links' => 'admin_links',
      'sid' => 'sid',
      'weight' => 'weight',
    ),
    'info' => array(
      'admin_name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'stat_type' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'description' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'admin_links' => array(
        'separator' => '',
      ),
      'sid' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'weight' => array(
        'separator' => '',
      ),
    ),
    'default' => -1,
    'tabledrag_order' => array(
      'field' => 'weight',
      'handler' => 'game_stats',
    ),
    'tabledrag_order_visible' => array(
      'visible' => 0,
    ),
    'tabledrag_hierarchy' => array(
      'field' => 'none',
      'handler' => 'native',
    ),
    'tabledrag_hierarchy_visible' => array(
      'visible' => 0,
    ),
    'draggableviews_depth_limit' => '0',
    'draggableviews_repair' => array(
      'repair' => 'repair',
    ),
    'tabledrag_types_add' => 'Add type',
    'tabledrag_expand' => array(
      'expand_links' => 0,
      'collapsed' => 0,
      'by_uid' => 0,
    ),
    'draggableviews_extensions' => array(
      'extension_top' => '3',
      'extension_bottom' => '3',
    ),
    'tabledrag_lock' => array(
      'lock' => 0,
    ),
    'draggableviews_default_on_top' => '1',
    'draggableviews_button_text' => 'Save order',
    'draggableviews_arguments' => array(
      'use_args' => 0,
    ),
  ));
  $handler = $view->new_display('page', 'Games Stats Admin Page', 'page_1');
  $handler->override_option('path', 'admin/build/game_stats/%');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => 'Game stats list',
    'description' => '',
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
$view->name = 'game_sessions';
$view->description = 'Game sessions';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'games_game_session';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('relationships', array(
  'game_id' => array(
    'label' => 'Game ID',
    'required' => 1,
    'id' => 'game_id',
    'table' => 'games_game_session',
    'field' => 'game_id',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
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
  'gsid' => array(
    'label' => 'Game Session Users',
    'required' => 1,
    'id' => 'gsid',
    'table' => 'games_game_session',
    'field' => 'gsid',
    'relationship' => 'none',
  ),
  'uid' => array(
    'label' => 'User',
    'required' => 1,
    'id' => 'uid',
    'table' => 'games_game_session_users',
    'field' => 'uid',
    'relationship' => 'gsid',
  ),
));
$handler->override_option('fields', array(
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
  'start_time' => array(
    'label' => 'Start Time',
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
    'date_format' => 'small',
    'custom_date_format' => '',
    'exclude' => 0,
    'id' => 'start_time',
    'table' => 'games_game_session',
    'field' => 'start_time',
    'relationship' => 'none',
  ),
  'complete' => array(
    'label' => 'Completed',
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
    'type' => 'yes-no',
    'not' => 0,
    'exclude' => 0,
    'id' => 'complete',
    'table' => 'games_game_session',
    'field' => 'complete',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Override',
    ),
  ),
  'score' => array(
    'label' => 'Score',
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
    'separator' => ',',
    'prefix' => '',
    'suffix' => '',
    'exclude' => 0,
    'id' => 'score',
    'table' => 'games_game_session_users',
    'field' => 'score',
    'relationship' => 'gsid',
  ),
  'name' => array(
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
    'id' => 'name',
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
    'override' => array(
      'button' => 'Override',
    ),
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
  'complete' => array(
    'operator' => '=',
    'value' => 'All',
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'operator' => '',
      'identifier' => 'complete',
      'label' => 'Complete',
      'optional' => 1,
      'remember' => 0,
    ),
    'id' => 'complete',
    'table' => 'games_game_session',
    'field' => 'complete',
    'relationship' => 'none',
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
$handler->override_option('title', 'Game sessions');
$handler->override_option('empty', 'No sessions.');
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
    'name' => 'name',
    'title' => 'title',
    'start_time' => 'start_time',
    'complete' => 'complete',
    'score' => 'score',
    'title_1' => 'title_1',
    'uid' => 'uid',
  ),
  'info' => array(
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'title' => array(
      'separator' => '',
    ),
    'start_time' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'complete' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'score' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'title_1' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'uid' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  ),
  'default' => 'start_time',
));
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('path', 'admin/reports/game/game-sessions');
$handler->override_option('menu', array(
  'type' => 'tab',
  'title' => 'Sessions',
  'description' => '',
  'weight' => '0',
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler = $view->new_display('feed', 'Feed', 'feed_1');
$handler->override_option('items_per_page', 0);
$handler->override_option('style_plugin', 'views_csv');
$handler->override_option('style_options', array(
  'mission_description' => FALSE,
  'description' => '',
  'attach_text' => 'CSV',
  'provide_file' => 1,
  'filename' => 'view-%view.csv',
  'parent_sort' => 0,
  'seperator' => ',',
  'quote' => 1,
  'trim' => 0,
  'header' => 1,
));
$handler->override_option('row_plugin', '');
$handler->override_option('path', 'admin/reports/game/game-sessions/csv');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('displays', array(
  'default' => 'default',
  'page_1' => 'page_1',
));
$handler->override_option('sitename_title', FALSE);
  $views[$view->name] = $view;  
  return $views;
}