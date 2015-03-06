# Commands:

# Detecting user:
~$ whoami

# Go to Root User for free to execute all commands:
~$ sudo -s
# Exit from root:
~$ exit

# Shutdown system
~$ poweroff

# Change Password of User:
~$ sudo passwd root 

# Tip: To find all available shells in your system type following command:
~$ cat /etc/shells
~$ ps $$
~$ ps -p $$
~$ echo "$0"

~$ type -a zsh
~$ type -a ksh
~$ type -a sh
~$ type -a bash

~$ sudo apt-get install csh 		# for installinh csh shell


# Changing your current shell permanently with chsh command
~$ chsh -s /bin/zsh
# Want to change the other user's shell from bash to ksh permanently?
~$ sudo chsh -s /bin/ksh userNameHere
# Finding out your current environment
~$ env
~$ env | more
~$ env | less
~$ env | grep 'NAME'

## Use printenv ##
~$ printenv HOME
 
## or use echo ##
~$ echo "$HOME"
 
# or use printf for portability ##
~$ printf "%s\n" "$HOME"

# Adding or setting a new variables
## The syntax is ##
~$ VAR=value
~$ FOO=bar
 
## Set the default editor to vim ##
~$ EDITOR=vim
~$ export $EDITOR
 
## Set default shell timeout for security ##
~$ TMOUT=300
~$ export TMOUT
 
## You can directly use export command to set the search path for commands ##
~$ export PATH=$PATH:$HOME/bin:/usr/local/bin:/path/to/mycoolapps

~$ printenv PATH
~$ echo "$EDITOR"
~$ printf "%s\n" $TMOUT

# How do I change an existing environment variables?
~$ export VAR=value
## OR ##
~$ VAR=value
~$ export $VAR
 
## Change the default editor from vim to emacs ##
~$ echo "$EDITOR" ## <--- print vim
~$ EDITOR=emacs   ## <--- change it 
~$ export $EDITOR ## <--- export it for next session too 
~$ echo "$EDITOR" ## <--- print emacs 

# The syntax is as follows for the tcsh shell for adding or changing a variables:
## Syntax 
~$ setenv var value
~$ printenv var
 
## Set foo variable with bar as a value ##
~$ setenv foo bar
~$ echo "$foo"
~$ printenv foo
 
## Set PATH variable ##
~$ setenv PATH $PATH\:$HOME/bin
~$ echo "$PATH"
 
## set PAGER variable ##
~$ setenv PAGER most
~$ printf "%s\n" $PAGER

# Finding your bash shell configuration files
# Type the following command to list your bash shell files, enter:
~$ ls -l ~/.bash* ~/.profile /etc/bash* /etc/profile

# To edit files located in /etc/, type:
## first make a backup.. just in case 
~$ sudo cp -v /etc/bashrc /etc/bashrc.bak.22_jan_15
 
########################################################################
## Alright, edit it to your hearts content and by all means, have fun ##
## with your environment or just increase the productivity :)         ##
########################################################################
~$ sudo vim /etc/bashrc

# History: Getting more info about your shell session
~$ history
~$ history 20

# To see command #93 (hddtemp /dev/sda)from above history session, type:
!93

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


# Create an alias
# The bash/zsh syntax is:

~$ alias c='clear'
~$ alias down='sudo /sbin/shutdown -h now'

