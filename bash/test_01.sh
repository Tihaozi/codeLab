# BASH ( Bourne-Again SHell )
# ===========================================================================================
# Chapter 1: Quick Introduction to Linux 

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

# ==================================================================================
# Chapter 2: Getting started with Shell Programming
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

# Why Command Line arguments required
~$ vi demo
#!/bin/sh
#
# Script that demos, command line args
#
echo "Total number of command line argument are $#"
echo "$0 is script name"
echo "$1 is first argument"
echo "$2 is second argument"
echo "All of them are :- $* or $@"

# Run it as follows:
~$ chmod 755 demo
~$ ./demo


# For showing content of a file
~$ cat test_ls

# Redirection of Standard output/input i.e. Input - Output redirection
# For e.g.
# $ ls command gives output to screen; to send output to file of ls command give command

~$ ls > filename

# There are three main redirection symbols >,>>,<
# (1) > Redirector Symbol
# Syntax:
# Linux-command > filename
# To output Linux-commands result (output of command or shell script) to file

# (2) >> Redirector Symbol
# Syntax:
# Linux-command >> filename
# To output Linux-commands result (output of command or shell script) to END of file.
~$ date >> myfiles

# (3) < Redirector Symbol
# Syntax:
# Linux-command < filename
# To take input to Linux-command from file instead of key-board.
$ cat < myfiles


# other commands
~$ cat > sname
# vivek
# ashish
# zebra
# babu
# Press CTRL + D to save.

~$ sort < sname > sorted_names
~$ cat sorted_names

# Try one more example to clear your idea:
~$ tr "[a-z]" "[A-Z]" < sname > cap_names
~$ cat cap_names
# VIVEK
# ASHISH
# ZEBRA
# BABU

# tr command is used to translate all lower case characters to upper-case letters.


# Pipes
# A pipe is a way to connect the output of one program to the input of another program without any temporary file.

# Pipe Defined as:
# "A pipe is nothing but a temporary storage place where the output of one command is stored and then passed as the input for second command.
# Pipes are used to run more than two commands ( Multiple commands) from same command line."

# Syntax:
# command1 | command2

~$ ls | more								# Output of ls command is given as input to more command So that output is printed one screen full page at a time.
~$ who | sort 							# Output of who command is given as input to sort command So that it will print sorted list of users
~$ who | sort > user_list				# Same as above except output of sort is send to (redirected) user_list file
~$ who | wc -l 							# Output of who command is given as input to wc command So that it will number of user who logon to system
~$ ls -l | wc  -l   						# Output of ls command is given as input to wc command So that it will print number of files in current directory.
~$ who | grep raju						# Output of who command is given as input to grep command So that it will print if particular user name if he is logon or nothing is printed (To see particular user is logon or not)

# Filter
# If a Linux command accepts its input from the standard input and produces its output on standard output is know as a filter. A filter performs some kind of process on the input and gives output. For e.g.. Suppose you have file called 'hotel.txt' with 100 lines data, And from 'hotel.txt' you would like to print contains from line number 20 to line number 30 and store this result to file called 'hlist' then give command:
~$ tail +20 < hotel.txt | head -n30 >hlist

# Here head command is filter which takes its input from tail command (tail command start selecting from line number 20 of given file i.e. hotel.txt) and passes this lines as input to head, whose output is redirected to 'hlist' file.

# Consider one more following example
~$ sort < sname | uniq > u_sname

# Here uniq is filter which takes its input from sort command and passes this lines as input to uniq; Then uniqs output is redirected to "u_sname" file.

# What is Processes
# Process is kind of program or task carried out by your PC. For e.g.
~$ ls -lR
# ls command or a request to list files in a directory and all subdirectory in your current directory - It is a process.
# Process defined as:
# "A process is program (command given by user) to perform specific Job. In Linux when you start process, it gives a number to process (called PID or process-id), PID starts from 0 to 65535."


# Why Process required
# As You know Linux is multi-user, multitasking Os. It means you can run more than two process simultaneously if you wish. For e.g. To find how many files do you have on your system you may give command like:
~$ ls / -R | wc -l
# This command will take lot of time to search all files on your system. So you can run such command in Background or simultaneously by giving command like
~$ ls / -R | wc -l &
# The ampersand (&) at the end of command tells shells start process (ls / -R | wc -l) and run it in background takes next command immediately.
# Process & PID defined as:
# "An instance of running command is called process and the number printed by shell is called process-id (PID), this PID can be use to refer specific running process."


# ================================================================================
# Chapter 3: Shells (bash) structured Language Constructs
# Introduction
# bc - Linux calculator program.
~$ bc
5 + 4
# 9
5 > 12
5 == 10
5 != 2
5 == 5
12 < 2

# Value					Shown in bc as				Shown in Linux Shell as
# True/Yes					1							0
# False/No					0							Non - zero value

# if condition
# Syntax:

# 	if condition
# 	then
# 		command1 if condition is true or if exit status
# 		of condition is 0 (zero)
# 		...
# 		...
# 	fi

# Condition is defined as:
# "Condition is nothing but comparison between two values."

# Type following commands (assumes you have file called foo)
~$ cat foo
~$ echo $? 

~$ cat > showfile
#!/bin/sh
#
#Script to print file
#
if cat $1
then
echo -e "\n\nFile $1, found and successfully echoed"
fi
# ctrl+d for save

# Run above script as:
~$ chmod 755 showfile
~$./showfile foo


# test command or [ expr ]
# test command or [ expr ] is used to see if an expression is true, and if it is true it return zero(0), otherwise returns nonzero for false.
# Syntax:
# test expression OR [ expression ]

# Example:
# Following script determine whether given argument number is positive.
~$ cat > ispostive
#!/bin/sh
#
# Script to see whether argument is positive
#
if test $1 -gt 0
then
echo "$1 number is positive"
fi
# ctrl+d for save

# Run it as follows
~$ chmod 755 ispostive
~$ ./ispostive 5
# 5 number is positive
~$ ./ispostive -5
# nothing is printed

~$ vi isnump_n
#!/bin/sh
#
# Script to see whether argument is positive or negative
#
if [ $# -eq 0 ]
then
echo "$0 : You must give/supply one integers"
exit 1
fi


if test $1 -gt 0
then
echo "$1 number is positive"
else
echo "$1 number is negative"
fi

# Try it as follows:
~$ chmod 755 isnump_n

~$ isnump_n 5
# 5 number is positive

~$ isnump_n -45
# -45 number is negative

~$ isnump_n
# ./ispos_n : You must give/supply one integers

~$ isnump_n 0
# 0 number is negative