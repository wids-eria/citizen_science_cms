<?php
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <?php print $head ?>
    <title><?php print $head_title ?></title>
    <?php print $styles ?>
    <?php print $scripts ?>
    <!--[if lt IE 7]>
      <?php print phptemplate_get_ie_styles(); ?>
    <![endif]-->
  </head>
  
  
  
  <body<?php print phptemplate_body_class($left, $right); ?>>

<!-- Layout -->

  <div class="page_wrap">
    
      <div class="header">
        
        <div class="logo">
          <!-- FIXME 1/22/2013 (kevin) find a cleaner way -->
          <a href="<?php echo url(); ?>"><img src="<?php echo $base_path.path_to_theme().'/images/cs_logo.png';?>"/></a>
        </div>
        
        <div class="navigation">
            
            <ul class="nav_buttons">
                <li><?php echo l('HOME', ''); ?></li>
                <li><?php echo l('PLAY GAME', 'node/1'); ?></li>
                
                <li>                    
                    <div id="centeredmenu">                
                        <ul>
                           <li><a href="#">RESOURCES</a> 
                                <ul>
                                   <!-- FIXME 1/22/2013 (kevin) use drupal menus at some point -->
                                   <li><?php echo l('Curriculum', 'node/5'); ?></li>
                                   <li><a href="#">Research</a></li>
                                   <li><?php echo l('Science Info', 'node/4'); ?></li>
                                </ul>
                             </li>                   
                        </ul>                
                    </div>                    
                </li>                
                
            </ul>
            
        </div>
        
      </div>
      
  </div>

      <div class="middle_section_container">                                          <!-- middle section container -->

    <div class="middle_middle">
        
        <!--
            <div class="middle_left">             
                
                <div style="display:none">
                    <ul id="imageList">
                         <li>images/images_for_random/boy_1.png</li>
                         <li>images/images_for_random/boy_2.png</li>
                         <li>images/images_for_random/farmer_1.png</li>
                        <li>images/images_for_random/farmer_2.png</li>
                         <li>images/images_for_random/girl_1.png</li>
                         <li>images/images_for_random/guy_1.png</li>
                         <li>images/images_for_random/guy_2.png</li>
                        <li>images/images_for_random/lake_spirit.png</li>
                    </ul>
                </div>
                
                <div id="imageHolder" class="image"></div>            
                
            </div>
        -->
        
        <?php if ($right): ?>
        <div class="post_container_short">            
         <?php else : ?>
         <div class="post_container">
          <?php endif;?>

            <div id="center"><div id="squeeze"><div class="right-corner"><div class="left-corner">
               
                
                <?php if ($mission): print '<div id="mission">'. $mission .'</div>'; endif; ?>
                <?php if ($tabs): print '<div id="tabs-wrapper" class="clear-block">'; endif; ?>
                <?php if ($title): print '<h2'. ($tabs ? ' class="with-tabs"' : '') .'>'. $title .'</h2>'; endif; ?>
                <?php if ($tabs): print '<ul class="tabs primary">'. $tabs .'</ul></div>'; endif; ?>
                <?php if ($tabs2): print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; endif; ?>
                <?php if ($show_messages && $messages): print $messages; endif; ?>
                <?php print $help; ?>
                <div class="clear-block">
                  
                  <?php print $content ?>
                  
                  <?php if ($left): ?>
                  <div id="sidebar-left" class="sidebar">
                    <?php if ($search_box): ?><div class="block block-theme"><?php print $search_box ?></div><?php endif; ?>
                    <?php print $left ?>
                  </div>
                <?php endif; ?>
                           
                </div>
                <?php print $feed_icons ?>
                
            </div></div></div></div> <!-- /.left-corner, /.right-corner, /#squeeze, /#center -->
      
            
            
            <div class="title_divider"></div>        
            
        </div>
        
        
        
        <?php if ($right): ?>                
        
        <div class="sidebar_container">     
            
              <div id="sidebar-right" class="sidebar">
                <?php print $right ?>                
              </div>            
            
        </div>
        
        <?php endif; ?>
        
    </div>

</div>
    
    
    <!--<div class="bottom_container">
    
    <div class="screens">
        
        <div class="orangeheader">
            <h2><a href="">Post 2 Title</a></h2>
        </div>
        
        <img src="images/img4.png"/>
        
        <p>Donec ullamcorper nulla non metus auctor fringilla. Sed posue
            re consectetur est at lobortis. <a href="">Cras justo odio</a>, dapibus ac fac
            ilisis in, egestas eget quam. Morbi leo risus, porta ac consecte
            tur ac, vestibulum at eros. Praesent commodo cursus magna, vel s
        </p>
        
        <div class="read_full_article">
            <a class="blue_link small_link" href="">Click here to view the full article.</a>
        </div>
        
    </div>
    
    
    
    <div class="screens">
        
        <div class="orangeheader">
            <h2><a href="">Post 3 Title</a></h2>
        </div>
        
        <img src="images/img4.png"/>

        <p>Donec ullamcorper nulla non metus auctor fringilla. Sed posue
            re consectetur est at lobortis. <a href="">Cras justo odio</a>, dapibus ac fac
            ilisis in, egestas eget quam. Morbi leo risus, porta ac consecte
            tur ac, vestibulum at eros. Praesent commodo cursus magna, vel s
        </p>
        
        <div class="read_full_article">
            <a class="blue_link small_link" href="">Click here to view the full article.</a>
        </div>
        
    </div>
    
    
    
    <div class="screen_right">
        
        <div class="orangeheader">
            <h2><a href="">Post 4 Title</a></h2>
        </div>
        
        <img src="images/img4.png"/>
        
        <p>Donec ullamcorper nulla non metus auctor fringilla. Sed posue
            re consectetur est at lobortis. <a href="">Cras justo odio</a>, dapibus ac fac
            ilisis in, egestas eget quam. Morbi leo risus, porta ac consecte
            tur ac, vestibulum at eros. Praesent commodo cursus magna, vel s
        </p>
        
        <div class="read_full_article">
            <a class="blue_link small_link" href="">Click here to view the full article.</a>
        </div>
        
    </div>
    
    
    </div>-->
    
                
    <div class="footer">    
        <div class="footer_content">        
        <?php print $footer ?>
        
        <p>
          The thoughts and views expressed here are the researchers' and do not
          represent the formal positions <br /> and policies of the researchers' supporting institutions.
        </p>
        <br />
        <p>
            Citizen Science has been made possible through support from the
            <a href="http://www.nsf.gov/" target="_blank">National Science Foundation</a>, the
            <a href="http://www.wisc.edu" target="_blank">University of Wisconsin - Madison</a>, the
            <a href="http://www.gameslearningsociety.org/" target="_blank">Games+Learning+Society</a> group, the
            <a href="http://discovery.wisc.edu" target="_blank">Wisconsin Institutes for Discovery/Morgridge Institute for Research </a> and
            <a href="http://www.filamentgames.com/" target="_blank">Filament Games</a>.
            
            
        </p>
        </div>
    </div>

    
    
<div class="clear">
</div>

<!-- /layout -->

  <?php print $closure ?>
  </body>
</html>
