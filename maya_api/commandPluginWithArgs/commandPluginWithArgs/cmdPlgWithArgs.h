// madoodia@gmail.com

#ifndef CMDPLGWITHARGS_H
#define CMDPLGWITHARGS_H

#include <maya/MPxCommand.h>
// #include <maya/MArgList.h> // Forwarded Declaration
#include <maya/MSyntax.h> // Forwarded Declaration
#include <maya/MSelectionList.h>
#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MDagModifier.h>
#include <maya/MDagPath.h>
#include <maya/MFnMesh.h>
#include <maya/MGlobal.h>
#include <maya/MPointArray.h>
#include <maya/MFnParticleSystem.h>
#include <maya/MArgParser.h>

#include <math.h>

class CommandPluginWithArgs : public MPxCommand {

public:
	static double   sparse;

	CommandPluginWithArgs();
	virtual			~CommandPluginWithArgs();

	MStatus			doIt(const MArgList& argList);
	MStatus			redoIt();
	MStatus			undoIt();
	bool			isUndoable() const;

	static void*	creator();
	static MSyntax	newSyntax();
	MStatus			parseArgs(const MArgList& argList);

	MObject			mObjParticle;
};


#endif // CMDPLGWITHARGS_H