// madoodia@gmail.com
// apply gaussian function to nodes

#ifndef FIRSTNODE_H
#define FIRSTNODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>

#include <math.h>

// A macro for detecting errors
#define McheckErr(stat,msg)			\
	if (stat != MS::kSuccess) {		\
		cerr << msg;				\
		return MS::kFailure;		\
	}

class FirstNode : public MPxNode {

public:
							FirstNode();
	virtual					~FirstNode();
	static void*			creator();
	static MStatus			initialize();

	virtual MStatus			compute(const MPlug& plug, MDataBlock& data);

	static MTypeId		id;
	static MObject		aOutValue;
	static MObject		aInValue;
	static MObject		aMagnitude;
	static MObject		aMean;
	static MObject		aVariance;

};

#endif // FIRSTNODE_H