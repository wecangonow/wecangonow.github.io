---
layout: post
title: PHP caching to speed up dynamically generated sites
category: php
---



This entire site, like many, is built in PHP. PHP provides the power to simply 'pull' content from an external source, in the case of my site this is flat files but it could just as easily be an MySQL database or an XML file etc..


The downside to this is processing time, each request for one page can trigger multiple database queries, processing of the output, and formatting it for display... This can be quite slow on complex sites (or slower servers)


Ironically, these so-called 'dynamic' sites probably have very little changing content, this page will almost never be updated after the day it is written - yet each time someone requests it the scripts goes and fetches the content, applies various functions and filters to it, then outputs it to you...


#Entering Caching 

This is where caching can help us out,instead of regenerating the page every time,the scripts running this site generate it the first time they are asked to,then store a copy of what they send back to your browser.The next time a visitor requests the same page,the script will know it'd already generated on recently,and simply send that to the browser without all the hassle of re-running database queries or searches.


#An Illustration  

This example shows a request for a "News" page on a website,the News changes daily so it makes sense to have it in a database rather than in a static file so it can be easily updated and searched,The News page is a PHP script which does the following:

*	Connect to an Mysql Database
*	Request 5 most recent news items
*	Sort news items from most recent to oldest
*	Read a template file and substitute variables for content
*	Output the finished page to the user 

![Alt text](http://www.theukwebdesigncompany.com/articles/images/article251/nocache.png)


This takes a considerable amount of time,it's negigable if you get one or two visitors an hour,but if you get 500 visitors an hour it makes a big difference.


Consider the difference between this,and a straight forward request for a normal .html file. The web server doesnt have to do any hard work serve up a .html file,it just finds the file and dumps it's contents to browser ... using caching allow you experience this speed gain even with dynamic sites.


Continuing the same example, but where caching is in place, the first user to request the News page would cause the script to do exactly as above, and in addition actually increase the load by making it write the result to a file, as well as to the browser. However, subsequent requests would work something like this:


![Alt text](http://www.theukwebdesigncompany.com/articles/images/article251/withcache.png)

As you can see, the MySQL database and Templates aren't touched, the web server just sends back the contents of a plain .html file to the browser. The request is completed in a fraction of the time, the user gets their page faster, and your server has less load on it - everyone's happy.


#Implementing a Cache in PHP


The Output Buffer, introduced in recent versions of PHP, is ideal for this. Basically if you call ob_start() at the start of your program, it supresses all output until you specifically flush the output buffer. You can therefore easily get at the output of any PHP script.


Let's look at the most basic,and rather useless,cache.This little snippet of code will save  the output of a call for the 'home' page into a file called home.html

	<?php
		// start the output buffer 
		ob_start();
		// your usual PHP script and HTML here ... 
	?>

	<?php
		$cachefile = "cache/home.html";

		$fp = fopen(\$cachefile,'w');

		fwrite($fp,ob_get_contents());

		fclose($fp);

		ob_end_flush();

	?>

Not tremendously useful, because now all we have is a script that generates a file called "cache/home.html" each time it is ran. But it's a good basis for a cache, it saves the content generated by the PHP script to a file. If you were to visit cache/home.html in a web browser you would see exactly the same page as if you visited the script the generated it, but that's no use unless the user knows where to look for it.


#Using the cache files


Now we have our code to generate a cache file, we need to find a way of using these files constructively. There are two types of request a 'MISS' and a 'HIT'.

If a user requests a page that has not been requested before, or that was requested long enough ago that it might be out of date, that is considered a MISS, in this situation the script should regenerate the page from it's database (or whatever) sources, and save a new cache file.

If a user requests a page that has been requested recently, and is in the cache, the script just needs to pass that file to the user and doesnt need to do anything else. This is known as a HIT.

Checking to see if a page has already been cached is easy:

	<?php

		$cachefile = "cache/home.html";

		if (file_exists($cachefile)) {

			include($cachefile);

			exit;
		
		}
	?>

Placing that code at the start of your script will cause it to use the cached file if it exists, and then exit from the script (so the rest of it will never run). If you have a site that never changes then that's enough, but very few sites never change. The other time when this snippet along would be enough is if you had a site that only changed every day or so, then you could use cron to empty the cache directory each day. This wouldn't be suitable for many sites, we need a way of expiring content in the cache so that it isnt use idefinitely.

















