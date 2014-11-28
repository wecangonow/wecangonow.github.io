---
layout: post
title: Understanding mysql table types or storage engines
category: mysql
---

Summary:in this tutorial,you will learn various mysql table types,or storage engines.It is essential to understand the features of each table type in mysql so that you can use them effectively to maximize the performance of you databases.

MySQL provides various storage engines for tables as below:

* MyISAM
* InnoBD
* MERGE
* MEMORY(HEAP)
* ARCHIVE
* CSV
* FEDERATED

Each storage engine has its own advantages and disabvantages. It is  crucial to understand each storage engine features and choose the most appropriate one for your tables to maximize the performance of the database. In the following sections we will discuss about each storage engine and its features so that you can decide which one to use.

##MyISAM 

MyISAM extends the former ISAM engine. The MyISAM tables are optimized for compression an speed. MyISAM tables are also portable between platform and OSes.

The size of MyISAM table can be up to 256TB,which is huge. In addition,MyISAM tables can be compressed into read-only tables to save space. At startup,MySQL checks MyISAM tables for corruption and even repair them in case of errors. The MyISAM tables are not transaction-safe.

Before MySQL version 5.5,MyISAM is the default storage engine when you create a table without explicitly specify the stroage engine. From version 5.5,MySQL use InnoDB as the default stroage engine.

## InnoDB

The InnoDB tables fully support ACID-compliant and transactions. They are also very optimal for performance. InnoDB supports foreign keys,commit,rollback,roll-and forward operations. The size of the InnoDB table can be up to 64TB.

Like MyISAM, the InnoDB tables are portable between different platforms and OSes. MySQL also checks and repair InnoDB tables,if necessary,at startup.

## MERGE

A MERGE table is a virtual table that contains multiple MyISAM tables, which has similar structure,into one table. The MERGE storage engine is also known as the MRG_MyISAM engine. The MERGE table does not have its own indexes;it uses indexs of the component  tables instead.

Using MERGE table,you can speed up performance in joining multiple tables. MySQL only allows you perfome SELECT,DELETE,UPDATE and INSERT operations on the MERGE tables. If you use DROP TABLE statement on a MERGE table, only MERGE specification is removed. The underlying tables will not be affected.

## Memory

The memory tables are stored in memory and used hash indexes so that they are faster than MyISAM tables. The lifetime of the data of the memory tables depends on the up time of the database server. The memory storage engine is formerly known as HEAP.

## Archive

The archive storage engine allows you to store a large number of records, which for archiving purpose, into a compressed format to save disk space. The archive storage engine compresses a record when it is inserted and decompress it using zlib library as it is read.

The archive tables only allow INSERT and SELECT commands. The archive tables do not support indexes, so reading records requires a full table scanning.


## CSV

The CSV storage engine stores data in comma-separated values file format. A CSV table brings a convenient way to migrate data into non-SQL applications such as spreadsheet software.

CSV table does not support NULL data type and read operation requires a full table scan.


## FEDERATED

The FEDERATED storage engine allows you to manage data from a remote MySQL server without using cluster or replication technology. The local federated table stores no data. When you query data from a local federated table, the data is pull automatically from the remote federated tables.

In this tutorial, we've discussed about various MySQL storage engines available in MySQL.
