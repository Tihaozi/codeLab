// madoodia@gmail.com

#include "bulgeDeformer.h"

MTypeId		BulgeDeformer::id(0x00000234);

MObject		BulgeDeformer::aBulgeAmount;

BulgeDeformer::BulgeDeformer() {}

BulgeDeformer::~BulgeDeformer() {}

void* BulgeDeformer::creator()
{
	return new BulgeDeformer();
}

MStatus BulgeDeformer::initialize()
{
	MStatus status;

	MFnNumericAttribute nAttr;

	aBulgeAmount = nAttr.create("bulgeAmount", "bulgeAmount", MFnNumericData::kFloat);
	nAttr.setKeyable(true);

	addAttribute(aBulgeAmount);

	attributeAffects(aBulgeAmount, outputGeom);

	// in this line we active the capability of painting on mesh
	// for a blendMesh deformer
	MGlobal::executeCommand("makePaintable -attrType multiFloat -sm deformer bulgeDeformer weights;");

	return MS::kSuccess;
}

MStatus BulgeDeformer::deform(MDataBlock & data,
	MItGeometry & itGeo,
	const MMatrix & localToWorldMatrix,
	unsigned int geomIndex)
{
	MStatus status;

	MArrayDataHandle hInput = data.outputArrayValue(input, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	status = hInput.jumpToElement(geomIndex);
	MDataHandle hInputElement = hInput.outputValue(&status);
	MObject oInputGeom = hInputElement.child(inputGeom).asMesh();

	MFnMesh mFnMesh(oInputGeom, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MFloatVectorArray normals;
	mFnMesh.getVertexNormals(false, normals);

	float bulgeAmount = data.inputValue(aBulgeAmount).asFloat();
	float env = data.inputValue(envelope).asFloat();
	MPoint point;
	float w;
	while (!itGeo.isDone()) {
		w = weightValue(data, geomIndex, itGeo.index());
		point = itGeo.position();

		point += normals[itGeo.index()] * bulgeAmount * env * w;

		itGeo.setPosition(point);

		itGeo.next();
	}

	return MS::kSuccess;
}
