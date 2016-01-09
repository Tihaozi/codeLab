// madoodia@gmail.com

#include "sphereCollideDeformer.h"

MTypeId		SphereCollideDeformer::id(0x00000235);
MObject		SphereCollideDeformer::aCollideMatrix;

SphereCollideDeformer::SphereCollideDeformer() {}

SphereCollideDeformer::~SphereCollideDeformer() {}

void* SphereCollideDeformer::creator()
{
	return new SphereCollideDeformer();
}

MObject& SphereCollideDeformer::accessoryAttribute() const
{
	return aCollideMatrix;
}

MStatus	SphereCollideDeformer::accessoryNodeSetup(MDagModifier& dagMod)
{
	MStatus status;

	MObject oLocator = dagMod.createNode("locator", MObject::kNullObj, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MFnDependencyNode  mFnLocator(oLocator, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MPlug plugWorldMatrix = mFnLocator.findPlug("worldMatrix", false, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = plugWorldMatrix.selectAncestorLogicalIndex(0, plugWorldMatrix.attribute());
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MObject oThis = thisMObject();
	MPlug plugCollideMatrix(oThis, aCollideMatrix);

	status = dagMod.connect(plugWorldMatrix, plugCollideMatrix);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	
	return MS::kSuccess;
}

MStatus SphereCollideDeformer::initialize()
{
	MStatus status;

	MFnMatrixAttribute mAttr;
	
	aCollideMatrix = mAttr.create("collideMatrix", "collideMatrix");

	addAttribute(aCollideMatrix);
	attributeAffects(aCollideMatrix, outputGeom);

	// in this line we active the capability of painting on mesh
	// for a blendMesh deformer
	//MGlobal::executeCommand("makePaintable -attrType multiFloat -sm deformer bulgeDeformer weights;");

	return MS::kSuccess;
}

MStatus SphereCollideDeformer::deform(MDataBlock & data,
						MItGeometry & itGeo,
						const MMatrix & localToWorldMatrix,
						unsigned int geomIndex)
{
	MStatus status;

	MMatrix collideMatrix = data.inputValue(aCollideMatrix).asMatrix();
	MMatrix collideMatrixInverse = collideMatrix.inverse();
	MMatrix worldToLocalMatrix = localToWorldMatrix.inverse();

	float env = data.inputValue(envelope).asFloat();
	MPoint point;
	while (!itGeo.isDone()) {
		
		point = itGeo.position();
		point *= localToWorldMatrix;
		point *= collideMatrixInverse;
		if (MVector(point).length() < 1.0) {
			// we are colliding
			point = MVector(point).normal();
		}
		point *= collideMatrix;
		point *= worldToLocalMatrix;

		itGeo.setPosition(point);

		itGeo.next();
	}

	return MS::kSuccess;
}
