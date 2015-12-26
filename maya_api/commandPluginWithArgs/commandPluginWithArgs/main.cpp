// madoodia@gmail.com
// Usage: in run this mel command:
// vertexParticle -s 2

#include "cmdPlgWithArgs.h"
#include <maya/MFnPlugin.h>

#define	commandName			"vertexParticle"

MStatus initializePlugin(MObject mObj)
{
	MStatus status;

	MFnPlugin mPlugin(mObj, "madoodia", "1.0", "Any");
	status = mPlugin.registerCommand(commandName,
				CommandPluginWithArgs::creator,
				CommandPluginWithArgs::newSyntax);

	CHECK_MSTATUS_AND_RETURN_IT(status);
	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject mObj)
{
	MStatus status;

	MFnPlugin mPlugin(mObj);
	status = mPlugin.deregisterCommand(commandName);

	CHECK_MSTATUS_AND_RETURN_IT(status);
	return MS::kSuccess;
}