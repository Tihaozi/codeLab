# BASH ( Bourne-Again SHell )
# Tip: To find all available shells in your system type following command:
~$ cat /etc/shells
# Result:
# /bin/sh
# /bin/bash
# /bin/dash
# /bin/rbash

# Tip: To find your current shell type following command
~$ echo $SHELL 


# Shell script defined as:
# "Shell Script is series of command written in plain text file.
# Shell script is just like batch file is MS-DOS but have more power than the MS-DOS batch file."


# Opening VI editor
~$ vi

# All executable files are in
~$ /bin

# hello.sh
~$ echo hello world

# for running hello.sh
~$ /bin/bash hello.sh
# or
~$ bash hello.sh
# or
~$ sh hello.sh
# or
~$ ./hello.sh 		# this works if chmod used for this file (755)

# show current directory
~$ pwd


~$ cd 							# Go to your home directory
~$ mkdir bin					# Now created bin directory
~$ cp hello.sh bin				# copy your script 'first' to your bin directory
~$ hello.sh					# Test whether script is running or not (It will run)

~$ rm hello.sh					# remove file
~$ rmdir "test folder" 			# remove folder

# set execute permission for your script as follows:
~$ chmod +x your-script-name
~$ chmod 755 your-script-name
# Note: This will set read write execute(7) permission for owner, for group and other permission is read and execute only(5)


# ...................
# Now you are ready to write first shell script that will print "Knowledge is Power" on screen

~$ vi first

#
# My first shell script
#
clear
echo "Knowledge is Power"

# for saving esc:w

~$ chmod 755 first

~$ ./first
# ...................
~$ vi ginfo.sh
#
#
# Script to print user information who currently login , current date & time
#
clear
echo "Hello $USER"
echo "Today is \c ";date
echo "Number of user login : \c" ; who | wc -l
echo "Calendar"
cal
exit 0

# for saving esc:w

~$ chmod 755 ginfo.sh
~$ ./ginfo.sh
# ...................
# ................................................................................................................
# Variables in Shell
# In Linux (Shell), there are two types of variable:
# (1) System variables - Created and maintained by Linux itself. This type of variable defined in CAPITAL LETTERS.
# (2) User defined variables (UDV) - Created and maintained by user. This type of variable defined in lower letters.

# BASH=/bin/bash								Our shell name
# BASH_VERSION=1.14.7(1)						Our shell version name
# COLUMNS=80									No. of columns for our screen
# HOME=/home/vivek							Our home directory
# LINES=25									No. of columns for our screen
# LOGNAME=students							students Our logging name
# OSTYPE=Linux								Our Os type
# PATH=/usr/bin:/sbin:/bin:/usr/sbin			Our path settings
# PS1=[\u@\h \W]\$							Our prompt settings
# PWD=/home/students/Common					Our current working directory
# SHELL=/bin/bash								Our shell name
# USERNAME=vivek								User name who is currently login to this PC

# You can print any of the above variables contains as follows:
~$ echo $USERNAME
~$ echo $HOME

# Warning: It is always a good idea not to change the following environment variables. Some can be changed and may results into unstable session for you:
# SHELL
# UID
# RANDOM
# PWD
# PPID
# SSH_AUTH_SOCK
# USER
# HOME
# LINENO

# How to define User defined variables (UDV)
~$ madoodia=testing_UDV
~$ echo $madoodia 		# testing_UDV
# NULL variable
~$ vech=
# or
~$ vech=""

# ...................
~$ vi variscript
#
#
# Script to test MY knowledge about variables!
#
myname=madoodia
myos = Ubuntu
myno=7
echo "My name is $myname"
echo "My os is $myos"
echo "My number is myno, can you see this number"
echo "My number is $myno, can you see this number"
# ...................

# History: Getting more info about your shell session
~$ history
# or
~$ history 20

# Changing your identity with sudo or su
# The syntax is as follows:

~$ su userName
 
## To log in as a tom user ##
~$ su tom
 
## To start a new login shell for tom user ##
~$ su tom
 
## To login as root user ##
~$ su -
 
## The sudo command syntax (must be configured on your system) ##
~$ sudo -s
~$ sudo tom

# Shell Arithmetic
# Syntax:
# expr op1 math-operator op2
# Examples:
~$ expr 1 + 3
~$ expr 2 - 1
~$ expr 10 / 2
~$ expr 20 % 3
~$ expr 10 \* 3
~$ echo `expr 6 + 3` 	# we used ` (back quote) sign not the (single quote i.e. ') sign

# More about Quotes
# "		Double Quotes		"Double Quotes" - Anything enclose in double quotes removed meaning of that characters (except \ and $).
# '		Single quotes		'Single quotes' - Enclosed in single quotes remains unchanged.
# `		Back quote			`Back quote` - To execute command

# Exit Status
# (1) If return value is zero (0), command is successful.
# (2) If return value is nonzero, command is not successful or some sort of error executing command/shell script.
# For e.g. (This example assumes that unknow1file doest not exist on your hard drive)
~$ rm unknow1file
# and after that if you give command
~$ echo $?
# it will print nonzero value to indicate error. Now give command
~$ ls
~$ echo $?
# It will print 0 to indicate command is successful.

# The read Statement
~$ vi sayHello
#
#Script to read your name from key-board
#
echo "Your first name please:"
read fname
echo "Hello $fname, Lets be friend!"

# Run it as follows:
~$ chmod 755 sayHello
~$ ./sayHello

# Your first name please: Madoodia
# Hello Madoodia, Lets be friend!

# Wild cards (Filename Shorthand or meta Characters)

# *			Matches any string or group of characters.			$ ls *				will show all files
# 																$ ls a*				will show all files whose first name is starting with letter 'a'
# 																$ ls *.c  			will show all files having extension .c
# 																$ ls ut*.c			will show all files having extension .c but file name must begin with 'ut'.
# ?			Matches any single character.						$ ls ?  			will show all files whose names are 1 character long 
# 																$ ls fo?			will show all files whose names are 3 character long and file name begin with fo
# [...]		Matches any one of the enclosed characters			$ ls [abc]* 		will show all files beginning with letters a,b,c

# Example:
~$ ls /bin/[a-c]* 

# More command on one command line
# Syntax:
# command1;command2
# To run two command with one command line.

# Examples:
~$ date;who 

