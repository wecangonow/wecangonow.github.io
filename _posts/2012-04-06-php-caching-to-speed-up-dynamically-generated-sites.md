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


$An Illustration  

This example shows a request for a "News" page on a website,the News changes daily so it makes sense to have it in a database rather than in a static file so it can be easily updated and searched,The News page is a PHP script which does the following:

*	Connect to an Mysql Database
*	Request 5 most recent news items
*	Sort news items from most recent to oldest
*	Read a template file and substitute variables for content
*	Output the finished page to the user 

![Alt text](http://www.theukwebdesigncompany.com/articles/images/article251/nocache.png "Optional title")

