# madoodia@gmail.com

# For loading plugin
# 1. Save this to a .py file
# 2. run this code:
#	from maya import cmds
#	cmds.loadPlugin("C:\Plugins\plugin.py")
# 3. run this code:
#	cmds.firstCmd()
#####################################
import sys

from maya.OpenMaya import *
from maya.OpenMayaMPx import *


commandName = "firstCmd"


class FirstCommand(MPxCommand):

    def __init__(self):
        super(FirstCommand, self).__init__()

    def doIt(self, argList):
        sys.stdout.write("I just wrote my first command plugin! (python plugin)")
        return True


def creator():
    return asMPxPtr(FirstCommand())


def initializePlugin(mObj):
    mPlugin = MFnPlugin(mObj, "madoodia", "1.0", "Any")
    try:
        mPlugin.registerCommand(commandName, creator)
    except:
        sys.stderr.write("Failed to register command: " + commandName)


def uninitializePlugin(mObj):
    mPlugin = MFnPlugin(mObj)
    try:
        mPlugin.deregisterCommand(commandName)
    except:
        sys.stderr.write("Failed to deregister command: " + commandName)
