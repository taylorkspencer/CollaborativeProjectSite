<?php
  // Include shared functions and variables if they aren't already included
  include_once('defines.inc');
  
  // Prints entries from a table in the MySQL database to the page
  function printEntries($server, $db, $user, $pass, $table)
  {
  	// Connect to the MySQL database
  	$mysqli = new mysqli($server, $user, $pass, $db);
  	if ($mysqli->connect_errno)
  	{
  		// If the script could not connect to the MySQL database, print an
  		// error message and return -1
  		echo "<div class=\"errorMsg\">MySQL database connection failed: Error " . $mysqli->connect_errno . ": " . $mysqli->connect_error . "</div>\n";
  		return -1;
  	}
  	
  	// Get the entry titles and contents from the specified table
  	$entries = $mysqli->query("SELECT Title, Contents FROM `{$table}`", MYSQLI_STORE_RESULT);
  	if (!$entries)
  	{
  		// If either of the queries could not be performed, print an error
  		// message, disconnect from the database, and return -1
  		echo "<div class=\"errorMsg\">Error: Could not query for entries from the table {$table}.</div>\n";
  		if (!$mysqli->close())
	  	{
	  		// If the script could not disconnect from the MySQL database,
	  		// print an error message and return -1
	  		echo "<div class=\"errorMsg\">Could not disconnect from the MySQL database.</div>\n";
	  		return -1;
	  	}
	  	return -1;
  	}
  	
  	// Print entries from the table to the page
  	for ($entry=0; $entry<($entries->num_rows); $entry++)
  	{
  		// Fetch the row for the entry
  		$row = $entries->fetch_row();
  		
  		// Print the pointer to the entry
  		echo "<a name=\"{$entry}\"></a>\n";
  		// Print the opening tag to the entry
  		echo "<div class=\"entry\">\n";
  		
  		// Print the title to the entry
  		echo TAB . "<div class=\"heading\">" . htmlentities($row[0], ENT_QUOTES | ENT_SUBSTITUTE) . "</div>\n";
  		
  		// Print a horizontal rule
  		echo TAB . "<hr/>\n";
  		
  		// Print the contents of the entry, converted to HTML paragraphs
  		echo TAB . mkToHTML($row[1], false);
  		
  		// Print the closing tag to the entry
  		echo "</div>\n";
  	}
  	
  	// Free the memory used by the results from the query
  	$entries->free();
  	
  	// Disconnect from the MySQL database
  	if (!$mysqli->close())
  	{
  		// If the script could not disconnect from the MySQL database,
  		// print an error message and return -1
  		echo "<div class=\"errorMsg\">Could not disconnect from the MySQL database.</div>\n";
  		return -1;
  	}
  }
  
  // Prints excerts from a table in the MySQL database to the page
  function printExcerts($server, $db, $user, $pass, $table, $page)
  {
  	// Connect to the MySQL database
  	$mysqli = new mysqli($server, $user, $pass, $db);
  	if ($mysqli->connect_errno)
  	{
  		// If the script could not connect to the MySQL database, print an
  		// error message and return -1
  		echo "<div class=\"errorMsg\">MySQL database connection failed: Error " . $mysqli->connect_errno . ": " . $mysqli->connect_error . "</div>\n";
  		return -1;
  	}
  	
  	// Get the entry titles and contents from the specified table
  	$entries = $mysqli->query("SELECT Title, Contents FROM `{$table}`", MYSQLI_STORE_RESULT);
  	if (!$entries)
  	{
  		// If either of the queries could not be performed, print an error
  		// message, disconnect from the database, and return -1
  		echo "<div class=\"errorMsg\">Error: Could not query for entries from the table {$table}.</div>\n";
  		if (!$mysqli->close())
	  	{
	  		// If the script could not disconnect from the MySQL database,
	  		// print an error message and return -1
	  		echo "<div class=\"errorMsg\">Could not disconnect from the MySQL database.</div>\n";
	  		return -1;
	  	}
	  	return -1;
  	}
  	
  	// Print excerts from the table to the page
  	for ($entry=0; $entry<($entries->num_rows); $entry++)
  	{
  		// Fetch the row for the entry
  		$row = $entries->fetch_row();
  		
  		// Print the opening tag to the entry
  		echo "<div class=\"entry\">\n";
  		
  		// Print the title to the entry
  		echo TAB . "<div class=\"heading\">" . htmlentities($row[0], ENT_QUOTES | ENT_SUBSTITUTE) . "</div>\n";
  		
  		// Print a horizontal rule
  		echo TAB . "<hr/>\n";
  		
  		// Print excerts of the contents of the entry, converted to HTML paragraphs
  		echo TAB . mkToHTML($row[1], true);
  		
  		// Print a link to the full article
  		echo TAB . "<a href=\"{$page}#{$entry}\">Read More</a>\n";
  		
  		// Print the closing tag to the entry
  		echo "</div>\n";
  	}
  	
  	// Free the memory used by the results from the query
  	$entries->free();
  	
  	// Disconnect from the MySQL database
  	if (!$mysqli->close())
  	{
  		// If the script could not disconnect from the MySQL database,
  		// print an error message and return -1
  		echo "<div class=\"errorMsg\">Could not disconnect from the MySQL database.</div>\n";
  		return -1;
  	}
  }
  
  // Prints links from a table in the MySQL database to the page
  function printLinks($server, $db, $user, $pass, $table, $page)
  {
  	// If a seventh argument was given, put its contents in title
  	if (func_num_args()>6)
  	{
  		$title = func_get_arg(6);
  	}
  	
  	// Connect to the MySQL database
  	$mysqli = new mysqli($server, $user, $pass, $db);
  	if ($mysqli->connect_errno)
  	{
  		// If the script could not connect to the MySQL database, print an
  		// error message and return -1
  		echo "<div class=\"errorMsg\">MySQL database connection failed: Error " . $mysqli->connect_errno . ": " . $mysqli->connect_error . "</div>\n";
  		return -1;
  	}
  	
  	// Get the entry titles from the specified table
  	$entries = $mysqli->query("SELECT Title FROM `{$table}`", MYSQLI_STORE_RESULT);
  	if (!$entries)
  	{
  		// If either of the queries could not be performed, print an error
  		// message, disconnect from the database, and return -1
  		echo "<div class=\"errorMsg\">Error: Could not query for entries from the table {$table}.</div>\n";
  		if (!$mysqli->close())
	  	{
	  		// If the script could not disconnect from the MySQL database,
	  		// print an error message and return -1
	  		echo "<div class=\"errorMsg\">Could not disconnect from the MySQL database.</div>\n";
	  		return -1;
	  	}
	  	return -1;
  	}
  	
  	// Print the opening tag to the entry
  	echo "<div class=\"entry\">\n";
  	
  	// If no title was given for the page, set the title equal to the table name
  	if (!isset($title))
  	{
  		$title = $table;
  	}
  	
  	// Print the title for the entry
  	echo TAB . "<div class=\"heading\">" . htmlentities($title, ENT_QUOTES | ENT_SUBSTITUTE) . "</div>\n";
  	
  	// Print the opening tag to the links list
  	echo TAB . "<ul class=\"linksList\">\n";
  	
  	// Print links to entries from the table to the page
  	for ($entry=0; $entry<($entries->num_rows); $entry++)
  	{
  		// Fetch the row for the entry
  		$row = $entries->fetch_row();
  		
  		echo TAB . TAB . "<li><a href=\"{$page}#{$entry}\">" . htmlentities($row[0], ENT_QUOTES | ENT_SUBSTITUTE) . "</a></li>\n";
  	}
  	
  	// Print the closing tag to the links list
  	echo TAB . "</ul>\n";
  	
  	// Print the closing tag to the entry
  	echo "</div>\n";
  	
  	// Free the memory used by the results from the query
  	$entries->free();
  	
  	// Disconnect from the MySQL database
  	if (!$mysqli->close())
  	{
  		// If the script could not disconnect from the MySQL database,
  		// print an error message and return -1
  		echo "<div class=\"errorMsg\">Could not disconnect from the MySQL database.</div>\n";
  		return -1;
  	}
  }
  
  // Converts the markup language used by the database into HTML for the printEntries
  // and printExcerts functions
  function mkToHTML($toConvert, $isExcert)
  {
  	// If the string is an excert, pass it to makeExcert before converting into HTML
  	if ($isExcert)
  	{
  		$toConvert = makeExcert($toConvert);
  	}
  	
  	// Parse the string line-by-line
  	$strArray = explode("\n", $toConvert);
  	
  	foreach ($strArray as &$line)
  	{
  		// Convert any special characters to HTML codes
		$line = htmlentities($line, ENT_QUOTES | ENT_SUBSTITUTE);
		
		// Replace double spaces with "&nbsp; "
		$doubleSpaceCount = substr_count($line, '  ');
		$line = str_replace('  ', '&nbsp; ', $line, $doubleSpaceCount);
		
  		// Pass anything that is not in a markup tag to paraToHTML
  		if ((!substr_count($line, '['))&&(!substr_count($line, ']'))&&(!substr_count($line, '[/'))
  			&&(!substr_count($line, '* ')))
  		{
  			$line = paraToHTML($line);
  		}
  		// Handle the ul tags
  		if ((substr_count($line, '[ul '))||(substr_count($line, '[ul]'))
  			||(substr_count($line, '[/ul]')))
  		{
	  		// If a name follows the ul tag, make that its class name
	  		if ((substr_count($line, '[ul '))&&(substr_count($line, ']')))
	  		{
	  			$line = str_replace('[ul ', '<ul class="', $line);
	  			$line = str_replace(']', '">', $line);
	  		}
	  		
	  		// Otherwise, create a ul tag without a class name
	  		if (substr_count($line, '[ul]'))
	  		{
	  			$line = str_replace('[ul]', '<ul>', $line);
	  		}
	  		
	  		// Handle the closing ul tag
	  		if (substr_count($line, '[/ul]'))
	  		{
	  			$line = str_replace('[/ul]', '</ul>', $line);
	  		}
	  	}
	  	// Replace asterik list lines with li tags
	  	if (substr_count($line, '* '))
	  	{
	  		$line = str_replace('* ', '<li>', $line);
	  		$line .= '</li>';
	  	}
	  	// Replace the link tag with a tags pointed to the URL inside
	  	if ((substr_count($line, '[link '))||(substr_count($line, '[link]'))
  			||(substr_count($line, '[/link]')))
  		{
  			// Get the link inside the tag
  			$link = substr($line, strpos($line, ']'), strpos($line, '[/link]')-strpos($line, ']'));
  			
  			// If the link is an email address, append mailto to it
  			if ((substr_count($link, '@'))&&(substr_count($link, '.')))
  			{
  				$link = 'mailto:' . $link;
  			}
  			// If the link is a telephone number, append tel to it
  			else if ((preg_match("/^[0-9]{11}$/", $link))
  				||(preg_match("/^[0-9]{12}$/", $link))
  				||(preg_match("/^[0-9]{3}-[0-9]{4}-[0-9]{4}$/", $link))
  				||(preg_match("/^[0-9]{1}-[0-9]{3}-[0-9]{4}-[0-9]{4}$/", $link)))
  			{
  				$link = 'tel:' . $link;
  			}
  			
  			// If a name follows the link tag, make that its class name
	  		if ((substr_count($line, '[link '))&&(substr_count($line, ']')))
	  		{
	  			$line = str_replace('[link ', "<a href=\"{$link}\" class=\"", $line);
	  			$line = str_replace(']', '">', $line);
	  		}
	  		
	  		// Otherwise, create an a tag without a class name
	  		if (substr_count($line, '[link]'))
	  		{
	  			$line = str_replace('[link]', "<a href=\"{$link}\">", $line);
	  		}
	  		
	  		// Handle the closing link tag
	  		if (substr_count($line, '[/link]'))
	  		{
	  			$line = str_replace('[/link]', '</a>', $line);
	  		}
  		}
	  	// Make a div tag whose class name is the name of the tag
  		// Must be done last to prevent erronious replacement of ul or link markup tags
  		if ((substr_count($line, '['))||(substr_count($line, ']'))||(substr_count($line, '[/')))
  		{
  			// Replace the closing tag (must be done first to avoid replacing the opening tag)
  			if ((substr_count($line, '[/'))&&(substr_count($line, ']')))
  			{
  				$line = preg_replace('/\[\/.*\]/', '</div>', $line);
  			}
  			// Replace the opening tag
  			if ((substr_count($line, '['))&&(substr_count($line, ']')))
  			{
  				$line = str_replace('[', '<div class="', $line);
  				$line = str_replace(']', '">', $line);
  			}
  		}
  	}
  	
  	// Copy the modified array back to a string
  	$toReturn = join("\n", $strArray);
  	
  	// Return the converted string
  	return $toReturn;
  }
  
  // Converts plain text paragraphs into HTML for the printEntries and printExcerts functions
  function paraToHTML($toConvert)
  {
  	// Add an opening paragraph tag to the beginning of the string
  	$toConvert = "<div class=\"paragraph\">" . $toConvert;
  	
  	// Find how many line breaks are in the plain text string
  	$numOfLineBreaks = substr_count($toConvert, "\n");
  	// Replace the line breaks in the plain text string with closing and opening paragraph tags
  	$toConvert = str_replace("\n", "</div>\n<div class=\"paragraph\">", $toConvert, $numOfLineBreaks);
  	
  	// Add a closing paragraph tag to the end of the string
  	$toConvert .= "</div>\n";
  	
  	// Return the converted string
  	return $toConvert;
  }
  
  // Abbreviates plain text paragraphs for the printExcerts function
  function makeExcert($toAbbreviate)
  {
	// Replace double spaces with "&nbsp; " to avoid adding spaces
	$doubleSpaceCount = substr_count($toAbbreviate, '  ');
	$toAbbreviate = str_replace('  ', '&nbsp; ', $toAbbreviate, $doubleSpaceCount);
	
	// Shorten the plain text string to 26 words (to exclude 25-word strings)
	$strArray = explode(' ', $toAbbreviate, 26);
	
  	// Check to see if the string is longer than 25 words
  	if (count($strArray)>25)
  	{
  		// Remove the last word from the array
  		array_pop($strArray);
  		
  		// Replace the string with the shortened array
  		$toAbbreviate = join(' ', $strArray);
  		
  		// Append a ellipis to the end of the string
  		$toAbbreviate .= "\342\200\246";
  	}
  	
	// Restore double spaces to the string
	$toAbbreviate = str_replace('&nbsp; ', '  ', $toAbbreviate, $doubleSpaceCount);
	
  	// Return the abbreviated string
  	return $toAbbreviate;
  }
?>
