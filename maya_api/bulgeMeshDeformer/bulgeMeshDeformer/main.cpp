// madoodia@gmail.com
// usage: Mel command: deformer -type bulgeDeformer

#include "bulgeDeformer.h"
#include "sphereCollideDeformer.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject mObj)
{
	MStatus status;
	MFnPlugin mPlugin(mObj, "madoodia", "1.0", "Any");

	// we can register more than one node
	status = mPlugin.registerNode("bulgeDeformer",
		BulgeDeformer::id,
		BulgeDeformer::creator,
		BulgeDeformer::initialize,
		BulgeDeformer::kDeformerNode);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = mPlugin.registerNode("collideDeformer",
		SphereCollideDeformer::id,
		SphereCollideDeformer::creator,
		SphereCollideDeformer::initialize,
		SphereCollideDeformer::kDeformerNode);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject mObj)
{
	MStatus status;
	MFnPlugin mPlugin(mObj);

	status = mPlugin.deregisterNode(BulgeDeformer::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = mPlugin.deregisterNode(SphereCollideDeformer::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}
