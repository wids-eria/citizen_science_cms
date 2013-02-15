Drupal.game = new Object();

Drupal.clamp = function(value, min, max) {
	return Math.max(min, Math.min(value, max));
};

Drupal.game.popout = function(game, url) {
	var max_width = parseInt(game.attr('width'));
	var max_height = parseInt(game.attr('height'));
	var width = Drupal.clamp(max_width, 0, screen.width);
	var height = Drupal.clamp(max_height, 0, screen.height);
	var popup = window.open(url, "", 'dialog=yes,height=' + height + ',width=' + width + ',directories=no,menubar=no,location=no,resizable=yes,scrollbars=no,status=no');
	$('.swftools-wrapper').html('');	
};

Drupal.behaviors.game = function(context) {
//	$('ul.links .popout a').each(function() {
//		var url = $(this).attr('href');
//
//		$(this).click(function() {
//			Drupal.game.popout($('.swftools-wrapper object'), url);
//		});
//
//		$(this).attr('href', '#');
//	});
};

