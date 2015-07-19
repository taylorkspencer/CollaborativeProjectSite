<?php
  // Include shared functions and variables
  include_once('defines.inc');
  include_once('printDB.inc');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
    <title>Appalachian Women's Museum - Board Documents</title>
    <link rel="stylesheet" type="text/css" href="style.css"/>
    <script type="text/javascript" src="script.js"></script>
  </head>
  <body>
    <?php
      // Include the header from an external file
      include_once('header.inc');
    ?>
    <div id="mainContents">
      <?php
        //TODO: Authenticate the user over POST before showing them the contents
        
      ?>
      <div class="entries">
        <div class="heading">Board Documents</div>
        <hr/>
        <div class="entry">
          <div class="heading"></div>
          <hr/>
          <div class="paragraph"></div>
        </div>
      </div>
      <?php
        // Include the donate pane from an external file
        include_once('donatePane.inc');
      ?>
    </div>
    <?php
      // Include the footer from an external file
      include_once('footer.inc');
    ?>
  </body>
</html>
