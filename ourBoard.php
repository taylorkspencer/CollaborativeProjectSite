<?php
  // Include shared functions and variables
  include_once('defines.inc');
  include_once('printDB.inc');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
    <title>Appalachian Women's Museum - Our Board</title>
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
        <div class="heading">Our Board</div>
        <hr/>
        <?php
          // Dynamically generate the entries from the database
          printExcerts('localhost', '14FAUSMXHCIDB1', '14FAUSMXHCIDB1', 'n1c0c5q0', 'Members', 'members.php');
        ?>
        <div class="entry">
          <div class="heading">Board Documents</div>
          <hr/>
          <?php
            // This is password-protected content; include the authentication form
            include('auth.inc');
          ?>
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
