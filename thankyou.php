<?php
// Include shared functions and variables
include_once('defines.inc');
include_once('printDB.inc');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
        <title>Appalachian Women's Museum - Thank You</title>
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
                <div class="entry">
                    <div class="heading">Thank You</div>
                    <hr/>
                    <div class="paragraph">Donation was successful.</div>
                </div>
            </div>
        </div>
    </body>
</html>

<script>
    setInterval(function() {
        window.location.href = 'index.php';
    }, 5000);
</script>