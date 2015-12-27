// madoodia@gmail.com

#include "firstNode.h"

MTypeId		FirstNode::id(0x00000231);
MObject		FirstNode::aOutValue;
MObject		FirstNode::aInValue;
MObject		FirstNode::aMagnitude;
MObject		FirstNode::aMean;
MObject		FirstNode::aVariance;

FirstNode::FirstNode()
{
}

FirstNode::~FirstNode()
{
}

void* FirstNode::creator()
{
	return new FirstNode;
}

MStatus FirstNode::initialize()
{
	MStatus status;
	MFnNumericAttribute nAttr;

	aOutValue = nAttr.create("outValue", "outValue", MFnNumericData::kFloat);
	nAttr.setWritable(false);
	nAttr.setStorable(false);
	addAttribute(aOutValue);

	aInValue = nAttr.create("inValue", "inValue", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aInValue);
	attributeAffects(aInValue, aOutValue);

	aMagnitude = nAttr.create("magnitude", "magnitude", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aMagnitude);
	attributeAffects(aMagnitude, aOutValue);

	aMean = nAttr.create("mean", "mean", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aMean);
	attributeAffects(aMean, aOutValue);

	aVariance = nAttr.create("variance", "variance", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aVariance);
	attributeAffects(aVariance, aOutValue);

	return MS::kSuccess;
}

MStatus FirstNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	// check which plug we are calculating
	if (plug != aOutValue) {
		return MS::kUnknownParameter;
	}

	// getting our inputs
	float inputVal = data.inputValue(aInValue, &status).asFloat();
	float magnitude = data.inputValue(aMagnitude, &status).asFloat();
	float mean = data.inputValue(aMean, &status).asFloat();
	float variance = data.inputValue(aVariance, &status).asFloat();
	if (variance <= 0.0f) {
		variance = 0.001f;
	}

	// perform the calculation
	float xMinusB = inputVal - mean;
	float output = magnitude * exp(-(xMinusB * xMinusB) / (2.0f * variance));

	// write that value to output
	MDataHandle hOutput = data.outputValue(aOutValue, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	hOutput.setFloat(output);
	hOutput.setClean();
	data.setClean(plug);

	return MS::kSuccess;
}
