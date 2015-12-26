# For using
# load plugin
# from maya import cmds
# cmds.vertexParticle(s = 1)
###########################################
import sys
from maya.OpenMaya import *
from maya.OpenMayaMPx import *
from maya.OpenMayaFX import *

commandName = "vertexParticle"

kHelpFlag = "-h"
kHelpLongFlag = "-help"
kSparseFlag = "-s"
kSparseLongFlag = "-sparse"
helpMessage = "This command is used to attach a particle on each vertex of a poly mesh"


class CommandPluginWithArgs(MPxCommand):

    sparse = None

    def __init__(self):
        super(CommandPluginWithArgs, self).__init__()

    def parseArgs(self, argList):
        syntax = self.syntax()
        parsedArguments = MArgDatabase(syntax, argList)
        if parsedArguments.isFlagSet(kSparseFlag):
            self.sparse = parsedArguments.flagArgumentDouble(kSparseFlag, 0)
            return True
        if parsedArguments.isFlagSet(kSparseLongFlag):
            self.sparse = parsedArguments.flagArgumentDouble(
                kSparseLongFlag, 0)
            return True

        if parsedArguments.isFlagSet(kHelpFlag):
            self.setResult(helpMessage)
            return True
        if parsedArguments.isFlagSet(kHelpLongFlag):
            self.setResult(helpMessage)
            return True

    def isUndoable(self):
        return True

    def undoIt(self):
        print "Undo"
        mFnDagNode = MFnDagNode(self.mObj_particle)
        mDagMod = MDagModifier()
        mDagMod.deleteNode(mFnDagNode.parent(0))
        mDagMod.doIt()
        return True

    def redoIt(self):
        mSel = MSelectionList()
        mDagPath = MDagPath()
        mFnMesh = MFnMesh()
        MGlobal.getActiveSelectionList(mSel)
        if mSel.length() >= 1:
            try:
                mSel.getDagPath(0, mDagPath)
                mFnMesh.setObject(mDagPath)
            except:
                print "Select a poly mesh"
                return kUnknownParameter
        else:
            print "Select a poly mesh"
            return kUnknownParameter

        mPointArray = MPointArray()
        mFnMesh.getPoints(mPointArray, MSpace.kWorld)

        mFnParticle = MFnParticleSystem()
        self.mObj_particle = mFnParticle.create()

        # To fix maya bug
        mFnParticle = MFnParticleSystem(self.mObj_particle)

        counter = 0
        for i in xrange(mPointArray.length()):
            if i % self.sparse == 0:
                mFnParticle.emit(mPointArray[i])
                counter += 1
        print "Total Ponits: " + str(counter)
        mFnParticle.saveInitialState()
        return True

    def doIt(self, argList):
        print "doIt..."
        self.parseArgs(argList)
        if self.sparse != None:
            self.redoIt()
        return True

    @staticmethod
    def creator():
        return asMPxPtr(CommandPluginWithArgs())

    @staticmethod
    def newSyntax():
        mSyntax = MSyntax()
        mSyntax.addFlag(kHelpFlag, kHelpLongFlag)
        mSyntax.addFlag(kSparseFlag, kSparseLongFlag, MSyntax.kDouble)
        return mSyntax


def initializePlugin(mObject):
    mPlugin = MFnPlugin(mObject, "madoodia", "1.0", "Any")
    try:
        mPlugin.registerCommand(commandName,
                                CommandPluginWithArgs.creator,
                                CommandPluginWithArgs.newSyntax)
    except:
        sys.stderr.write("Failed to register command: " + commandName)


def uninitializePlugin(mObject):
    mPlugin = MFnPlugin(mObject)
    try:
        mPlugin.deregisterCommand(commandName)
    except:
        sys.stderr.write("Failed to deregister command: " + commandName)
