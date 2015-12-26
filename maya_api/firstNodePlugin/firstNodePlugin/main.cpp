// madoodia@gmail.com

#include "firstNode.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject mObj)
{
	MStatus status;

	MFnPlugin mPlugin(mObj, "madoodia", "1.0", "Any");

	status = mPlugin.registerNode("gaussian",
		FirstNode::id,
		FirstNode::creator,
		FirstNode::initialize);

	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject mObj)
{
	MStatus status;

	MFnPlugin mPlugin(mObj);

	status = mPlugin.deregisterNode(FirstNode::id);

	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}