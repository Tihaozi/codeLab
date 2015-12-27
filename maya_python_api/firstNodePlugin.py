# madoodia@gmail.com
# using constructor and destructor in a plugin
import sys
import math

from maya.OpenMaya import *
from maya.OpenMayaMPx import *

nodeName = "gaussianNode"


class FirstNode(MPxNode):

    id_ = MTypeId(0x00000232)
    aOutValue = MObject()
    aInValue = MObject()
    aMagnitude = MObject()
    aMean = MObject()
    aVariance = MObject()

    def __init__(self):
        super(FirstNode, self).__init__()
        print "The Constructor"

    def __del__(self):
        super(FirstNode, self).__del__()
        print "The Destructor"

    def compute(self, plug, data):
        # check which plug we are calculating
        if plug != self.aOutValue:
            return kUnknownParameter

        # getting our inputs
        inputVal = data.inputValue(self.aInValue).asFloat()
        magnitude = data.inputValue(self.aMagnitude).asFloat()
        mean = data.inputValue(self.aMean).asFloat()
        variance = data.inputValue(self.aVariance).asFloat()
        if variance <= 0.0:
            variance = 0.001

        # perform the calculation
        xMinusB = inputVal - mean
        output = magnitude * math.exp(-(xMinusB * xMinusB) / (2.0 * variance))

        # write that value to output
        hOutput = MDataHandle()
        hOutput = data.outputValue(self.aOutValue)

        hOutput.setFloat(output)
        hOutput.setClean()
        data.setClean(plug)

        return True

    @staticmethod
    def creator():
        print "creator function"
        return asMPxPtr(FirstNode())

    @staticmethod
    def initialize():
        print "initialize function"

        nAttr = MFnNumericAttribute()

        FirstNode.aOutValue = nAttr.create(
            "outValue", "outValue", MFnNumericData.kFloat)
        nAttr.setWritable(False)
        nAttr.setStorable(False)
        FirstNode.addAttribute(FirstNode.aOutValue)

        FirstNode.aInValue = nAttr.create(
            "inValue", "inValue", MFnNumericData.kFloat)
        nAttr.setKeyable(True)
        FirstNode.addAttribute(FirstNode.aInValue)
        FirstNode.attributeAffects(FirstNode.aInValue, FirstNode.aOutValue)

        FirstNode.aMagnitude = nAttr.create("magnitude",
                                            "magnitude", MFnNumericData.kFloat)
        nAttr.setKeyable(True)
        FirstNode.addAttribute(FirstNode.aMagnitude)
        FirstNode.attributeAffects(FirstNode.aMagnitude, FirstNode.aOutValue)

        FirstNode.aMean = nAttr.create("mean", "mean", MFnNumericData.kFloat)
        nAttr.setKeyable(True)
        FirstNode.addAttribute(FirstNode.aMean)
        FirstNode.attributeAffects(FirstNode.aMean, FirstNode.aOutValue)

        FirstNode.aVariance = nAttr.create(
            "variance", "variance", MFnNumericData.kFloat)
        nAttr.setKeyable(True)
        FirstNode.addAttribute(FirstNode.aVariance)
        FirstNode.attributeAffects(FirstNode.aVariance, FirstNode.aOutValue)

        return True


def initializePlugin(mObject):

    mPlugin = MFnPlugin(mObject, "Madoodia", "1.0", "201404")
    try:
        mPlugin.registerNode(nodeName,
                             FirstNode.id_,
                             FirstNode.creator,
                             FirstNode.initialize)
        print "initializePlugin function"
    except:
        sys.stderr.write("Failed to register command: %s\n" % nodeName)
        raise


def uninitializePlugin(mObject):
    mPlugin = MFnPlugin(mObject)
    try:
        mPlugin.deregisterNode(FirstNode.id_)
        print "uninitializePlugin function"
    except:
        sys.stderr.write("Failed to unregister command: %s\n" % nodeName)
        raise
