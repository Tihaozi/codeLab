// madoodia@gmail.com

#include "firstNode.h"

MTypeId		FirstNode::id(0x00000232);
MObject		FirstNode::aOutValue;
MObject		FirstNode::aInValue;
MObject		FirstNode::aMagnitude;
MObject		FirstNode::aMean;
MObject		FirstNode::aVariance;

FirstNode::FirstNode(){}

FirstNode::~FirstNode(){}

void* FirstNode::creator()
{
	return new FirstNode;
}

MStatus FirstNode::initialize()
{
	MStatus status;
	MFnNumericAttribute nAttr;

	FirstNode::aOutValue = nAttr.create("outValue", "outValue", MFnNumericData::kFloat, 0.0, &status);
	nAttr.setWritable(false);
	nAttr.setStorable(false);

	FirstNode::aInValue = nAttr.create("inValue", "inValue", MFnNumericData::kFloat);
	nAttr.setKeyable(true);

	FirstNode::aMagnitude = nAttr.create("magnitude", "magnitude", MFnNumericData::kFloat);
	nAttr.setKeyable(true);

	FirstNode::aMean = nAttr.create("mean", "mean", MFnNumericData::kFloat);
	nAttr.setKeyable(true);

	FirstNode::aVariance = nAttr.create("variance", "variance", MFnNumericData::kFloat);
	nAttr.setKeyable(true);

	addAttribute(FirstNode::aOutValue);
	addAttribute(FirstNode::aInValue);
	addAttribute(FirstNode::aMagnitude);
	addAttribute(FirstNode::aMean);
	addAttribute(FirstNode::aVariance);

	status = attributeAffects(FirstNode::aInValue, FirstNode::aOutValue);
	status = attributeAffects(FirstNode::aMagnitude, FirstNode::aOutValue);
	status = attributeAffects(FirstNode::aMean, FirstNode::aOutValue);
	status = attributeAffects(FirstNode::aVariance, FirstNode::aOutValue);	
	
	//McheckErr(status, "ERROR in attributeAffects\n");

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
