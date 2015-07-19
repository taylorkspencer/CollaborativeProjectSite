<?php
  // Include shared functions and variables
  include_once('defines.inc');
  include_once('printDB.inc');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
    <title>Appalachian Women's Museum - Events</title>
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
        <div class="heading">Events</div>
        <hr/>
        <?php
          //TODO: Dynamically generate the entries from the database
          
        ?>
        <div class="entry">
          <div class="heading">November 2014</div>
          <hr/>
          <ul class="events">
            <ul>
              <li>Event 1</li>
              <li>November 15, 2014</li>
            </ul>
          </ul>
        </div>
        <div class="entry">
          <div class="heading">December 2014</div>
          <hr/>
          <ul class="events">
            <ul>
              <li>Event 2</li>
              <li>December 10, 2014</li>
            </ul>
          </ul>
        </div>
        <div class="entry">
          <div class="heading">January 2015</div>
          <hr/>
          <ul class="events">
            <ul>
              <li>Event 3</li>
              <li>January 4, 2015</li>
            </ul>
          </ul>
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
