<script type="text/javascript" src="stickyDonatePane.js"></script>
<div class="donatePane">
    <div class="heading">Help Support Us</div>
    <form name="custom" class="option" action="donate.php">
        <div class="heading">Custom Amount</div>
        <hr/>
        <input type="submit" value="Donate" onclick="Donating('0')"/>
    </form>
    <form name="preset" class="option" action="donate.php" method="post">
        <div class="heading">Contribution Levels</div>
        <hr/>
        <select name="levels">
            <option selected="selected">Friend $10 USD</option>
            <option>Contributor $25 USD</option>
            <option>Benefactor $50 USD</option>
            <option>Sustainer $100 USD</option>
        </select>
        <input type="submit" value="Donate" onclick="Donating('1')"/>
    </form>
</div>
