// madoodia@gmail.com
// usage: Mel command: deformer -type blendMesh

#include "blendMesh.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject mObj)
{
	MStatus status;
	MFnPlugin mPlugin(mObj, "madoodia", "1.0", "Any");
	status = mPlugin.registerNode("blendMesh",
		BlendMesh::id,
		BlendMesh::creator,
		BlendMesh::initialize,
		MPxNode::kDeformerNode);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject mObj)
{
	MStatus status;
	MFnPlugin mPlugin(mObj);
	status = mPlugin.deregisterNode(BlendMesh::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}
