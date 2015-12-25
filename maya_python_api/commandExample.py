# madoodia@gmail.com
# using constructor and destructor in a plugin

from maya.OpenMaya import *
from maya.OpenMayaMPx import *

kPluginCmdName = "commandExample"


class CommandExample(MPxCommand):

    def __init__(self):
        super(CommandExample, self).__init__()
        print "The Constructor"

    def __del__(self):
        super(CommandExample, self).__del__()
        print "The Destructor"

    def doIt(self, args):
        print "doIt method"
        self.redoIt()

    def redoIt(self):
        print "redoIt method"

    def undoIt(self):
        print "undoIt method"

    def isUndoable(self):
        print "isUndoable method"
        # if this method return True the destructor dose not work
        return False


def creator():
    print "creator function"
    return asMPxPtr(CommandExample())


def initializePlugin(mObject):

    mPlugin = MFnPlugin(mObject, "Madoodia", "1.0", "201404")
    try:
        mPlugin.registerCommand(kPluginCmdName, creator)
        print "initializePlugin function"
    except:
        sys.stderr.write("Failed to register command: %s\n" % kPluginCmdName)
        raise


def uninitializePlugin(mObject):
    mPlugin = MFnPlugin(mObject)
    try:
        mPlugin.deregisterCommand(kPluginCmdName)
        print "uninitializePlugin function"
    except:
        sys.stderr.write("Failed to unregister command: %s\n" % kPluginCmdName)
        raise
