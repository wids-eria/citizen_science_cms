<?php
class game_stats_date_api_filter_handler extends date_api_filter_handler {
	function date_filter($prefix, $query_field, $operator) {
		$field = $query_field['field'];
		
		//Check what querys we want run through this that aren't actual base tables.
		//$names = array('games_play_session_games_game_session_end_time');
		//if(in_array($field['query_name'],$names))
			//$field['fullname'] = $this->relationship.'.'.$field['field_name'];
		
		$field['fullname'] = 'games_play_session_games_game_session.end_time';
		
		// Handle the simple operators first.
		if ($operator == 'empty') {
			$this->add_date_field($field);
			return $field['fullname'] .' IS NULL';
		}
		elseif ($operator == 'not empty') {
			$this->add_date_field($field);
			return $field['fullname'] .' IS NOT NULL';
		}

		// Views treats the default values as though they are submitted
		// so we when it is really not submitted we have to adjust the
		// query to match what should have been the default.
		$value_parts = !is_array($this->value[$prefix]) ? array($this->value[$prefix]) : $this->value[$prefix];
		foreach ($value_parts as $part) {
			$default = $this->default_value($prefix);
			if (!empty($this->force_value) && !empty($default)) {
				$this->value[$prefix] = $default;
			}
			else {
				if (empty($part)) {
					return '';
				}
			}
		}
	    
		$this->add_date_field($field);
		$granularity = $this->options['granularity'];
		$date_handler = $query_field['date_handler'];
		$this->format = $date_handler->views_formats($granularity, 'sql');
		$complete_date = date_fuzzy_datetime($this->value[$prefix]);
		$date = date_make_date($complete_date);
		$value = date_format($date, $this->format);
		$range = $this->date_handler->arg_range($value);
		$year_range = date_range_years($this->options['year_range']);
		if ($this->operator != 'not between') {
			switch ($operator) {
				case '>':
				case '>=':
					$range[1] = date_make_date(date_pad($year_range[1], 4) .'-12-31 23:59:59');  
					if ($operator == '>') {
						date_modify($range[0], '+1 second');
					}
					break;
				case '<':
				case '<=':
					$range[0] = date_make_date(date_pad($year_range[0], 4) .'-01-01 00:00:00');
					if ($operator == '<') {
						date_modify($range[1], '-1 second');
					}
					break;
			}
		}
	    
		$min_date = $range[0];
		$max_date = $range[1];
        
	    $this->min_date = $min_date;
	    $this->max_date = $max_date;
	    $this->year = date_format($date, 'Y');
	    $this->month = date_format($date, 'n');
	    $this->day = date_format($date, 'j');
	    $this->week = date_week(date_format($date, DATE_FORMAT_DATE));
	    $this->date_handler = $date_handler;
	        
	    if ($this->date_handler->granularity == 'week') {
			$this->format = DATE_FORMAT_DATETIME;
	    }
	    switch ($prefix) {
			case 'min':
				$value = date_format($min_date, $this->format);
				break;
			case 'max':
				$value = date_format($max_date, $this->format);
				break;
			default:
				$value = date_format($date, $this->format);
				break;
	    }
	    if ($this->date_handler->granularity != 'week') {
			$sql = $date_handler->sql_where_format($this->format, $field['fullname'], $operator, $value);
	    }
	    else {
			$sql = $date_handler->sql_where_date('DATE', $field['fullname'], $operator, $value);
	    }
	    return $sql;
	  }
}