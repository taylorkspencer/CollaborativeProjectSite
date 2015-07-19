// When a scroll occurs, see if the donate pane needs to be repositioned
addListener(window, 'scroll', function()
{
	// Get the donate pane
	var donatePane = getElementsByClass("donatePane")[0];
	
	// If the donate pane's position is at or less than 25px, make
	// its position fixed at 25px
	if ((getScrollY()-donatePane.offsetTop)>=-25)
	{
		donatePane.style.position = 'fixed';
		donatePane.style.top = '25px';
		donatePane.style.right = '12px';
	}
	// If the donate pane's position is greater than 25px, make its
	// position relative
	else
	{
		donatePane.style.position = 'relative';
		donatePane.style.top = '0%';
		donatePane.style.right = '0%';
	}
});
