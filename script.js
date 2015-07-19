// Shared functions used by all scripts

// Add a second external script to a web page from within a JavaScript file
function include(scriptSrc)
{
	var script = document.createElement("script");
	script.src = scriptSrc;
	script.type = 'text/javascript';
	getDocumentHead().appendChild(script);
}

// Cross-browser alternative for addEventListener and attachEvent
function addListener(control, eventName, eventFunction)
{
	// For most modern browsers
	if (control.addEventListener)
	{
		control.addEventListener(eventName, eventFunction, false);
	}
	// For IE8 and lower (which don't support addEventListener)
	else if (control.attachEvent)
	{
		control.attachEvent('on'+eventName, eventFunction);
	}
}

// Cross-browser alternative for document.head and document.all for getting
// the head tag
// Necessary for include function to work
function getDocumentHead()
{
	// For most modern browsers
	if (document.head)
	{
		return document.head;
	}
	// For IE8 and lower (which don't support document.head)
	else if (document.all.tags)
	{
		return document.all.tags("head")[0];
	}
}

// Cross-browser alternative for querySelectorAll and document.all for getting
// elements by class name
function getElementsByClass(className)
{
	var toReturn;
	// For most modern browsers
	if (document.querySelectorAll)
	{
		// Get all the elements whose class name is equal to className from the page
		toReturn = document.querySelectorAll('.'+className);
	}
	// For IE7 and lower (which don't support querySelectorAll)
	else if (document.all)
	{
		toReturn = new Array();
		
		// Parse through all the elements on the web page
		var elementIndex = 0;
		for (var tagIndex=0; tagIndex<document.all.length; tagIndex++)
		{
			// If the class of the element is equal to className, add it to
			// toReturn and increment elementIndex
			if (document.all[tagIndex].className==className)
			{
				toReturn[elementIndex] = document.all[tagIndex];
				elementIndex++;
			}
		}
	}
	return toReturn;
}

// Cross-browser alternative for getPropertyValue and getAttribute
function getProperty(element, propertyName)
{
	var toReturn;
	// For most modern browsers
	if (element.getPropertyValue)
	{
		toReturn = element.getPropertyValue(propertyName);
	}
	// For IE8 and lower (which don't support getPropertyValue)
	else if (element.getAttribute)
	{
		toReturn = element.getAttribute(propertyName);
	}
	return toReturn;
}

// Cross-browser alternative for setProperty and setAttribute
function setPropertyValue(element, propertyName, propertyValue)
{
	// For most modern browsers
	if (element.setProperty)
	{
		element.setProperty(propertyName, propertyValue, null);
	}
	// For IE8 and lower (which don't support setProperty)
	else if (element.setAttribute)
	{
		element.setAttribute(propertyName, propertyValue);
	}
}

// Cross-browser alternative for window.scrollX and document.documentElement.scrollLeft
function getScrollX()
{
	var toReturn;
	// For most modern browsers
	if (window.scrollX)
	{
		toReturn = window.scrollX;
	}
	// For Internet Explorer
	else if (document.documentElement.scrollLeft)
	{
		toReturn = document.documentElement.scrollLeft;
	}
	return toReturn;
}

// Cross-browser alternative for window.scrollY and document.documentElement.scrollTop
function getScrollY()
{
	var toReturn;
	// For most modern browsers
	if (window.scrollY)
	{
		toReturn = window.scrollY;
	}
	// For Internet Explorer
	else if (document.documentElement.scrollTop)
	{
		toReturn = document.documentElement.scrollTop;
	}
	return toReturn;
}

// Cross-browser alternative for string.startsWith
function strStartsWith(element, comparisionString)
{
	// If the browser supports string.startsWith, use that
	if (element.startsWith)
	{
		return element.startsWith(comparisionString);
	}
	// Otherwise, compare the two strings in a for loop
	else
	{
		// Check to see if the comparisionString is as long as the element string
		if (element.length>=comparisionString.length)
		{
			for (var char=0; ((char<element.length)&&(char<comparisionString.length)); char++)
			{
				// If the two characters are not equal, return false
				if (element.charAt(char)!==comparisionString.charAt(char))
				{
					return false;
				}
			}
			// If all the characters were equal, return true
			return true;
		}
		else
		{
			// If not, return false
			return false;
		}
	}
}

// Return a MIME type for the file at the path given based on its extension
function getMimeType(filePath)
{
	// Check to make sure the file path is not empty
	if (filePath!='')
	{
		// Return a MIME type based on the file path's extension
		// For image files
		if (filePath.match(/.gif$/))
		{
			return 'image/gif';
		}
		else if ((filePath.match(/.jpeg$/))||(filePath.match(/.jpg$/)))
		{
			return 'image/jpeg';
		}
		else if (filePath.match(/.png$/))
		{
			return 'image/png';
		}
		else if (filePath.match(/.svg$/))
		{
			return 'image/svg+xml';
		}
		else if (filePath.match(/.webp$/))
		{
			return 'image/webp';
		}
		
		// For audio files
		if (filePath.match(/.aac$/))
		{
			return 'audio/aac';
		}
		else if (filePath.match(/.flac$/))
		{
			return 'audio/flac';
		}
		else if (filePath.match(/.m4a$/))
		{
			return 'audio/mp4';
		}
		else if (filePath.match(/.mp3$/))
		{
			return 'audio/mpeg';
		}
		else if ((filePath.match(/.ogg$/))||(filePath.match(/.ogx$/)))
		{
			return 'application/ogg';
		}
		else if (filePath.match(/.oga$/))
		{
			return 'audio/ogg';
		}
		
		// For video files
		if (filePath.match(/.flv$/))
		{
			return 'video/x-flv';
		}
		else if ((filePath.match(/.mpeg$/))||(filePath.match(/.mpg$/)))
		{
			return 'video/mpeg';
		}
		else if ((filePath.match(/.mp4$/))||(filePath.match(/.m4v$/)))
		{
			return 'video/mp4';
		}
		else if (filePath.match(/.ogv$/))
		{
			return 'video/ogg';
		}
		else if (filePath.match(/.webm$/))
		{
			return 'video/webm';
		}
		
		// If the file type could not be recognized by the extension, return an empty string
		return '';
	}
	else
	{
		// If the file path is empty, return an empty string
		return '';
	}
}
