---
layout: post
title:PHP Caching to Speed up Dynamically Generated Sites
category:php
---

This entire site, like many, is built in PHP. PHP provides the power to simply 'pull' content from an external source, in the case of my site this is flat files but it could just as easily be an MySQL database or an XML file etc..


The downside to this is processing time, each request for one page can trigger multiple database queries, processing of the output, and formatting it for display... This can be quite slow on complex sites (or slower servers)


Ironically, these so-called 'dynamic' sites probably have very little changing content, this page will almost never be updated after the day it is written - yet each time someone requests it the scripts goes and fetches the content, applies various functions and filters to it, then outputs it to you...
