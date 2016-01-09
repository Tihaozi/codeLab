// madoodia@gmail.com

#ifndef BULGEDEFORMER_H
#define BULGEDEFORMER_H

#include <maya/MPxDeformerNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnMesh.h>
#include <maya/MFloatVectorArray.h>		// float
#include <maya/MVectorArray.h>			// double
#include <maya/MPointArray.h>
#include <maya/MItGeometry.h>
#include <maya/MGlobal.h>

class BulgeDeformer : public MPxDeformerNode {
public:
	BulgeDeformer();
	virtual				~BulgeDeformer();

	static void*		creator();
	static MStatus		initialize();

	// instead of compute function in node
	// we will implement deform function
	virtual MStatus		deform(MDataBlock& data,
		MItGeometry& itGeo,
		const MMatrix& localToWorldMatrix,
		unsigned int geomIndex);

	// Id
	static MTypeId		id;

	// Attributes
	static MObject		aBulgeAmount;

	// outputGeom is inherited
	// envelope is inherited
};



#endif // BULGEDEFORMER_H