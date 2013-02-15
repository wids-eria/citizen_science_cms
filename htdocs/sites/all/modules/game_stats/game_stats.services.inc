<?php
function _game_stats_svc_start_game($version, $time = NULL){
  try {
    $game_id = _game_stats_get_game_id();
    return game_stats_start_game($game_id, $version, $time);
  } catch (Exception $e) {
    return services_error($e->getMessage(), 500);
  }
}

function _game_stats_svc_complete_game($psid, $score, $stats = FALSE, $time = NULL){
  try {
    game_stats_complete_game($psid, $score, $stats, $time);
  } catch (Exception $e) {
    return services_error($e->getMessage(), 500);
  }
}

function _game_stats_svc_save_stat($psid, $stats, $uid = NULL){
  try {
    foreach($stats as $stat){
      game_stats_save_stat($psid, $stat['sid'], $stat['value'], $uid);
    }
  } catch (Exception $e) {
    return services_error($e->getMessage(), 500);
  }
}

function _game_stats_svc_register_stats($stats) {
  try {
    $game_id = _game_stats_get_game_id();
    return game_stats_register_stats($stats, $game_id);
  } catch (Exception $e) {
    return services_error($e->getMessage(), 500);
  }
}

function _game_stats_svc_heartbeat($psid, $time = NULL) {
  try {
    _game_stats_set_heartbeat_time($psid, $time);
  } catch(Exception $e) {
    return services_error($e->getMessage(), 500);
  }
}