# this file is for testing all matters that 
#i am learning from marcus command prompt project
# ===============================================
# MODULE STUDY: os
import os
# ===============================================
# MODULE STUDY: sys
import sys
# ===============================================
# MODULE STUDY: logging
import logging
# ===============================================
# MODULE STUDY: subprocess
import subprocess
# ===============================================
# MODULE STUDY: functools
from functools import partial
# ===============================================
# function STUDY: lambda
clear_cmd = "cls" if os.name == "nt" else "clear"
cls = lambda: subprocess.call(clear_cmd, shell=True)
# for calling --> cls()

# example:
def printMsg(msg):
    print msg

cmd1 = lambda: printMsg("Hello World!")
cmd1()
# this is like this:
cmd2 = partial(printMsg, "Hello World!")
cmd2()
# ===============================================
class MyClassCommand(object):
    pass

myCls = MyClassCommand()  
# myCls.__name__          # give error
# print MyClassCommand.__name__  # MyClassCommand

class My1Command(MyClassCommand):
    pass

# print My1Command.__name__      # My1

def getName(yourClass):
    return yourClass.__name__.rsplit("Command")[0].lower()

print getName(MyClassCommand)
print getName(My1Command)
# ===============================================

print "_" * 50

msg1 = "First number: {0}, Second number: {1}".format(10, 20)
print msg1
msg2 = "First number: {no}, Second number: {no}".format(no=100)
print msg2

cmd2 = """{LINE}\n\n\t\t\t\t\thello\n{LINE}""".format(LINE="_"*50)
print cmd2

message = """
 {LINE}
|                                                      |
| Command Pattern - Demonstration                      |
| Author: Marcus Ottosson <marcus@abstractfactory.io>  |
|{LINE}|

* Available commands""".format(LINE='_'*54)
print message

# ===============================================
class TestDoc(object):
    """This is docstring of TestDoc Class"""
    pass

def testDoc():
    """This is docstring of testDoc function"""
    pass

print TestDoc.__doc__
print testDoc.__doc__
# ===============================================
COMMANDS = {}
for cmd in ('CreateCommand',
            'DeleteCommand',
            'UpdateCommand',
            'UndoCommand',
            'RedoCommand',
            'HistoryCommand',
            'VerbosityCommand',
            'DataCommand',
            'ClsCommand',
            'HelpCommand',
            'ExitCommand'):
    COMMANDS[cmd.rsplit("Command")[0].lower()] = cmd

print '--------------------------'
print COMMANDS['create']
print COMMANDS.get('create')
print '--------------------------'

# print COMMANDS
for cmd in sorted(COMMANDS):
    print "\t" + cmd + " : " + COMMANDS[cmd]

cmd = 'create'
print '***', COMMANDS.get(cmd)
# ===============================================
class Invoker1(object):
    """Using @classmethod"""
    # Static Data
    CONSTANT = {}
    CONSTANT['madoodia'] = 'Baran'

    @classmethod
    def printMe(cls, msg):
        print "className:", cls.__name__, ">> doc:", cls.__doc__, ">> msg:", msg

    def printMe2(self, msg):
        print "className:", Invoker1.__name__, ">> doc:", Invoker1.__doc__, ">> msg:", msg

cmd = 'madoodia'
print '***', Invoker1.CONSTANT.get(cmd)
Invoker1.printMe("hello class method")
inv1 = Invoker1()
inv1.printMe2("hello class method")
# vs
class Invoker2(object):
    def __init__(self):
        self.CONSTANT = {}
        self.CONSTANT['madoodia'] = 'Baran'

cmd = 'madoodia'
ivnoker = Invoker2()    # should be created an instance of class for use
print '***', ivnoker.CONSTANT.get(cmd)
# ===============================================

print __name__
print __file__

# ===============================================

# cls()
try:
    while True:
        sys.stdout.write("Command> ")
        input_ = raw_input()
        # or  input_ = raw_input("Command> ")
        if input_ == 'exit':
            raise KeyboardInterrupt
except KeyboardInterrupt:
    print "***Goodbye***"

# ===============================================