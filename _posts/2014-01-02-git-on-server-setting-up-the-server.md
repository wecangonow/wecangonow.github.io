---
layout: post
title: Git on the server - Setting Up the Server!
category: git
---


#Setting Up the Server

Let's walk through setting up SSH access on the server size.In this example, you'll use the authorized_key method for authenticating your users.We also assume you are running a standard distribution like Ubuntu.First,you create a 'git' user and a .ssh directory for that user.

	$ sudo adduser git 
	$ su git 
	$ cd ~
	$ mkdir .ssh 

Next,you need to add some developer SSH public keys to the authorized_keys file for that user.Let's assume you've receive a few keys by e-mail and saved them to temporary files.Again,the public keys look something like this:

	$ cat /tmp/id_rsa.john.pub
	ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCB007n/ww+ouN4gSLKssMxXnBOvf9LGt4LojG6rs6hPB09j9R/T17x4lhJA0F3FR1rP6kYBRsWj2aThGw6HXLm9/5zytK6Ztg3RPKK+4k
Sdfd8AcCIicTDWbqLAcU4UpkaX8KyGlLwsNuuGztobF8m72ALC/nLF6JLtPofwFBlgc+myivdAv8JggJICUvax2T9va5 gsg-keypair


You just append them to your authorized_keys file

	$ cat /tmp/id_rsa.john.pub >> ~/.ssh/authorized_keys
	$ cat /tmp/id_rsa.josie.pub >> ~/.ssh/authorized_keys
	$ cat /tmp/id_rsa.jessica.pub >> ~/.ssh/authorized_keys
