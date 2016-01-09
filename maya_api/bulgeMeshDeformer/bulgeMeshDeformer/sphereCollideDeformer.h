// madoodia@gmail.com

#ifndef SPHERECOLLIDEDEFORMER_H
#define SPHERECOLLIDEDEFORMER_H

#include <maya/MPxDeformerNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnMesh.h>
#include <maya/MPointArray.h>
#include <maya/MItGeometry.h>
#include <maya/MGlobal.h>
#include <maya/MFnMatrixAttribute.h>
#include <maya/MDagModifier.h>
#include <maya/MMatrix.h>

class SphereCollideDeformer : public MPxDeformerNode {
public:
	SphereCollideDeformer();
	virtual				~SphereCollideDeformer();

	static void*		creator();
	static MStatus		initialize();

	virtual MStatus		deform(MDataBlock& data,
							MItGeometry& itGeo,
							const MMatrix& localToWorldMatrix,
							unsigned int geomIndex);

	virtual MObject&	accessoryAttribute() const;
	virtual MStatus		accessoryNodeSetup(MDagModifier& dagMod);

	// Id
	static MTypeId		id;
	
	static MObject		aCollideMatrix;

};



#endif // SPHERECOLLIDEDEFORMER_H