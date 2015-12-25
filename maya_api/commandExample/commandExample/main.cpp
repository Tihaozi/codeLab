// madoodia@gmail.com

#include "commandExample.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject mObj)
{
	MStatus status;

	MFnPlugin mPlugin(mObj, "madoodia", "1.0", "Any");
	status = mPlugin.registerCommand("cmdExample", CommandExample::creator);

	CHECK_MSTATUS_AND_RETURN_IT(status);
	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject mObj)
{
	MStatus status;

	MFnPlugin mPlugin(mObj);
	status = mPlugin.deregisterCommand("cmdExample");

	CHECK_MSTATUS_AND_RETURN_IT(status);
	return MS::kSuccess;
}