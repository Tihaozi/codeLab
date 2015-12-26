// madoodia@gmail.com

#ifndef CMDPLGWITHARGS_H
#define CMDPLGWITHARGS_H

#include <cmath>

#include <maya/MPxCommand.h>
#include <maya/MArgList.h>
#include <maya/MSyntax.h>
#include <maya/MSelectionList.h>
#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MDagModifier.h>
#include <maya/MDagPath.h>
#include <maya/MFnMesh.h>
#include <maya/MGlobal.h>
#include <maya/MPointArray.h>
#include <maya/MFnParticleSystem.h>
#include <maya/MArgDatabase.h>


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

private:
	MStatus			parseArgs(const MArgList& argList);
	MObject			mObjParticle;
};


#endif // CMDPLGWITHARGS_H