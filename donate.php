<?php
// Include shared functions and variables
include_once('defines.inc');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
        <title>Appalachian Women's Museum - Donate</title>
        <link rel="stylesheet" type="text/css" href="style.css"/>
        <script type="text/javascript" src="script.js"></script>
        <script>
            function form_check() {
                var first_name = document.getElementById('first_name').value;
                var last_name = document.getElementById('last_name').value;
                var address = document.getElementById('address').value;
                var city = document.getElementById('city').value;
                var state = document.getElementById('state').value;
                var zip = document.getElementById('zip').value;
                var credit_card = document.getElementById('credit_card').value;
                var date_for_expiration = document.getElementById('date_for_expiration').value;
                var cvv = document.getElementById('cvv').value;
                var email_address = document.getElementById('email_address').value;

                if (first_name.length > 0 && last_name.length > 0 && address.length > 0 &&
                    city.length > 0 && state.length > 0 && zip.length > 0 &&
                    credit_card.length > 0 && date_for_expiration.length > 0 && cvv.length > 0 &&
                    email_address.length > 0) {
                
                    document.getElementById('error_ul').style.display = 'none';
                    return true;
                }

                document.getElementById('error_ul').style.display = 'block';
                return false;
            }
        </script>
    </head>
    <body>
        <?php
        // Include the header from an external file
        include_once('header.inc');
        ?>
        <div id="mainContents">
            <!-- TODO: Start dynamically generating the entries -->
            <div class="entries">
                <div class="heading">Donate</div>
                <hr/>
                <div class="entry">
                    <div class="heading"></div>

                    <?php
                    $amount = '';
                    if (isset($_POST['levels'])) {
                        $amount = explode('$', $_POST['levels']);
                        $amount = isset($amount[1]) ? $amount[1] : '';
                        if (strlen($amount) > 1) {
                            $amount = explode(' ', $amount);
                            $amount = $amount[0];
                        }
                    }
                    ?>

                    <ul id="error_ul" style="color: red; display: none;">
                        <li>Please fill out the mandatory fields.</li>
                    </ul>
                    <form name="donate_form" action="thankyou.php" method="post">
                        <table>
                            <tr>
                                <td><label for="first_name">First Name: </label><span style="color: red">*</span></td>
                                <td><input type="text" name="first_name" id="first_name" required /></td>
                                <td><label for="last_name">Last Name: </label><span style="color: red">*</span></td>
                                <td><input type="text" name="last_name" id="last_name" required /></td>
                            </tr>
                            <tr>
                                <td><label for="address">Address: </label><span style="color: red">*</span></td>
                                <td colspan="3"><input name="address" id="address" required size="62" /></td>
                            </tr>
                            <tr>
                                <td><label for="city">City: </label><span style="color: red">*</span></td>
                                <td><input type="text" name="city" id="city" required /></td>
                            </tr>
                            <tr>
                                <td><label for="state">State: </label><span style="color: red">*</span></td>
                                <td><input type="text" name="state" id="state" required /></td>
                            </tr>
                            <tr>
                                <td><label for="zip">Zip Code: </label><span style="color: red">*</span></td>
                                <td><input type="text" name="zip" id="zip" required /></td>
                            </tr>
                            <tr>
                                <td><label for="credit_card">Debit/Credit card number: </label><span style="color: red">*</span></td>
                                <td><input type="text" name="credit_card" id="credit_card" required /></td>
                            </tr>
                            <tr>
                                <td><label for="date_for_expiration">Date for expiration: </label><span style="color: red">*</span></td>
                                <td><input type="text" name="date_for_expiration" id="date_for_expiration" required /></td>
                            </tr>
                            <tr>
                                <td><label for="cvv">CVV: </label><span style="color: red">*</span></td>
                                <td><input type="text" name="cvv" id="cvv" required /></td>
                            </tr>
                            <tr>
                                <td><label for="amount">Donation Amount ($): </label><span style="color: red">*</span></td>
                                <td><input type="number" name="amount" id="amount" required value="<?php echo $amount; ?>" /></td>
                            </tr>
                            <tr>
                                <td><label for="phone_number">Phone Number: </label></td>
                                <td><input type="tel" name="phone_number" id="phone_number" /></td>
                            </tr>
                            <tr>
                                <td><label for="email_address">Email: </label><span style="color: red">*</span></td>
                                <td><input type="email" name="email_address" id="email_address" required /></td>
                            </tr>
                            <tr>
                                <td><label for="donation_comments">Donation Comments: </label></td>
                                <td colspan="3"><textarea name="donation_comments" id="donation_comments" cols="38"></textarea></td>
                            </tr>
                            <tr>
                                <td></td>
                                <td>
                                    <input type="submit" name="confirm" id="confirm" value="Confirm" onclick="return form_check();" />
                                    <input type="button" name="cancel" id="cancel" value="Cancel" onclick="window.location.href = 'index.php'" />
                                </td>
                            </tr>
                        </table>
                    </form>
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
