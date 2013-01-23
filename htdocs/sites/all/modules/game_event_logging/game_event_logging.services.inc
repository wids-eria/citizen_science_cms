<?php
function _game_event_logging_svc_register_event_types($events) {
  try {
    return _game_event_logging_register_event_types($events);
  } catch (Exception $e) {
    return services_error($e->getMessage(), 500);
  }
}

function _game_event_logging_svc_log_events($psid, $event_args) {
  try {
    _game_event_logging_log_events($psid, $event_args);
  } catch (Exception $e) {
    return services_error($e->getMessage(), 500);
  }
}