// madoodia@gmail.com

#include "blendMesh.h"

MTypeId		BlendMesh::id(0x00000233);

MObject		BlendMesh::aBlendMesh;
MObject		BlendMesh::aBlendWeight;

BlendMesh::BlendMesh(){}

BlendMesh::~BlendMesh(){}

void* BlendMesh::creator()
{
	return new BlendMesh();
}

MStatus BlendMesh::initialize()
{
	MStatus status;

	MFnNumericAttribute nAttr;
	MFnTypedAttribute tAttr;

	aBlendMesh = tAttr.create("blendMesh", "blendMesh", MFnData::kMesh);

	aBlendWeight = nAttr.create("blendWeight", "blendWeight", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	nAttr.setMin(0.0);
	nAttr.setMax(1.0);

	addAttribute(aBlendMesh);
	addAttribute(aBlendWeight);

	attributeAffects(aBlendMesh, outputGeom);
	attributeAffects(aBlendWeight, outputGeom);

	// in this line we active the capability of painting on mesh
	// for a blendMesh deformer
	MGlobal::executeCommand("makePaintable -attrType multiFloat -sm deformer blendMesh weights;");

	return MS::kSuccess;
}

MStatus BlendMesh::deform(MDataBlock & data,
						MItGeometry & itGeo,
						const MMatrix & localToWorldMatrix,
						unsigned int geomIndex)
{
	MStatus status;

	MDataHandle hBlendMesh = data.inputValue(aBlendMesh, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	MObject oBlendMesh = hBlendMesh.asMesh();

	if (oBlendMesh.isNull()) {
		return MS::kSuccess;
	}

	MFnMesh mFnMesh(oBlendMesh, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MPointArray blendPoints;
	mFnMesh.getPoints(blendPoints);

	float blendWeight = data.inputValue(aBlendWeight).asFloat();
	float env = data.inputValue(envelope).asFloat();

	MPoint point;
	float w;
	for (; !itGeo.isDone();itGeo.next()) {
		point = itGeo.position();
		w = weightValue(data, geomIndex, itGeo.index());

		point += (blendPoints[itGeo.index()] - point) * blendWeight * env * w;

		itGeo.setPosition(point);
	}

	return MS::kSuccess;
}
