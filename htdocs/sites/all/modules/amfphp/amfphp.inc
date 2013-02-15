<?php

/**
 * Execute AMFPHP request
 */
function amfphp_server_exec() {
  $path = drupal_get_path('module', 'amfphp');
  
  define("PRODUCTION_SERVER", !variable_get('services_debug', FALSE));
	
	require_once $path . "/amfphp/globals.php";
	require_once $path . "/overrides/AmfphpGateway.php";

	$gateway = new AmfphpGateway();
	$gateway->setClassPath($servicesPath);
	$gateway->setClassMappingsPath($voPath); 
	$gateway->setCharsetHandler(variable_get('charset_method','utf8_decode'), variable_get('charset_php','ISO-8859-1'), variable_get('charset_sql','ISO-8859-1'));
	$gateway->setErrorHandling(variable_get('amfphp_exception_handler', E_ALL ^ E_NOTICE));
	
	if (PRODUCTION_SERVER) {
		$gateway->disableDebug();
		//$gateway->disableStandalonePlayer();
	}

	$gateway->enableGzipCompression(25*1024);
	$gateway->service();
}

/*
 * ugly! ugly! ugly!
 * we need to use a method call wrapper here to convert all 'uid' values in the result
 * to 'userid'.  this is because flex uses the property 'uid' in objects and will overwrite
 * anything we send with its own value.
 */
function amfphp_method_call($method_name, $args) {
  // convert all userid to uid
  amfphp_fix_uid($args, 0);
  
  $result = services_method_call($method_name, $args);
  
  // convert all uid to userid
  amfphp_fix_uid($result);
  
  return $result;
}

function amfphp_fix_uid(&$data, $direction = 1) {
  if(is_object($data) || is_array($data)) {
    if($direction == 1) {
      if(is_object($data) && isset($data->uid)) {
        $data->userid = $data->uid;
        unset($data->uid);
      } else if(is_array($data) && isset($data['uid'])) {
        $data['userid'] = $data['uid'];
        unset($data['uid']);
      }
    } else if(is_object($data) && isset($data->userid)) {
      $data->uid = $data->userid; 
      unset($data->userid);
    } else if(is_array($data) && isset($data['userid'])) {
      $data['uid'] = $data['userid'];
      unset($data['userid']);      
    }    
    
    foreach($data as &$value) {
      amfphp_fix_uid($value, $direction);
    }
  }
}

/*
 * Implementation of hook_server_error()
 */
function amfphp_server_error($message) {
  // log error to watchdog
  watchdog('amfphp server', $message, NULL, WATCHDOG_ERROR);
  
  // we must throw an error here as it is caught by AMFPHP to send faults back
  // to the client
  trigger_error($message, E_USER_ERROR);
}