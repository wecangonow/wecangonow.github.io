---
layout: post
title: Manage database in mysql
category: mysql
---



* Creating Database

Before doing anything else with the data,you need to create a database. A database is a container of data. It stores contacts,vendors,customers or any kind of data that you can think of. In mysql, a database is a collection of objects that are used to store  and manipulate data such as tables,database views,triggers,stored procedures,etc.

To create a database in mysql,you use the CREATE DATABASE statement as follows:

	1 CREATE DATABASE [IF NOT EXISTS] database_name;
	
* Displaying Databases

The SHOW DATABASE statement displays all databases in the mysql database server. You can use SHOW DAABASE statement to check that you've created or to see all the databasees on the database server before you create a new database,for example:

	1 SHOW DATABASE;

* Selecting a database to work with 

Before working with a particular database,you must tell mysql which database you want to work with by using	USE statement.

	1 USE database_name;

* Removing Databases

Removing database means you delete the database physically. All the data and related objects inside the database are permanently deleted and this can't be undone,therefore it is very important to excute this query with extra cautions.

	1 DROP DATABASE [IF EXISTS] database_name;


In this tutorial,you've learned various statements to manage databases in mysql including create a new database,remove an existing database,selecting a database to work with and displaying all databases in a mysql database server.
