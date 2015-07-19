<?php
  // Include shared functions and variables
  include_once('defines.inc');
  include_once('printDB.inc');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
    <title>Appalachian Women's Museum - Videos</title>
    <link rel="stylesheet" type="text/css" href="style.css"/>
    <script type="text/javascript" src="script.js"></script>
  </head>
  <body>
    <?php
      // Include the header from an external file
      include('header.inc');
    ?>
    <div id="mainContents">
      <div class="entries">
        <div class="heading">Videos</div>
        <hr/>
        <div class="entry">
          <div class="heading">Monteith Farmstead</div>
          <hr/>
          <iframe class="videoContainer" src="http://player.vimeo.com/video/89424262?byline=0&portrait=0" height="360" width="640" allowfullscreen></iframe>
        </div>
        <div class="entry">
          <div class="heading">Canning Stories</div>
          <hr/>
          <iframe class="videoContainer" src="http://player.vimeo.com/video/101321804?byline=0&portrait=0" height="360" width="640" allowfullscreen></iframe>
        </div>
      </div>
      <?php
        // Include the donate pane from an external file
        include('donatePane.inc');
      ?>
    </div>
    <?php
      // Include the footer from an external file
      include('footer.inc');
    ?>
  </body>
</html>
