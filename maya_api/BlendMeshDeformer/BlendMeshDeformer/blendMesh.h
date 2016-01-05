// madoodia@gmail.com

#ifndef BLENDMESHDEFORMER_H
#define BLENDMESHDEFORMER_H

#include <maya/MPxDeformerNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnMesh.h>
#include <maya/MPointArray.h>
#include <maya/MItGeometry.h>
#include <maya/MGlobal.h>

class BlendMesh : public MPxDeformerNode {
public:
	BlendMesh();
	virtual				~BlendMesh();

	static void*		creator();
	static MStatus		initialize();

	// instead of compute function in node
	// we will implement deform function
	virtual MStatus		deform( MDataBlock& data,
								MItGeometry& itGeo,
								const MMatrix& localToWorldMatrix,
								unsigned int geomIndex);

	// Id
	static MTypeId		id;

	// Attributes
	static MObject		aBlendMesh;
	static MObject		aBlendWeight;

	// outputGeom is inherited
	// envelope is inherited
};



#endif // BLENDMESHDEFORMER_H