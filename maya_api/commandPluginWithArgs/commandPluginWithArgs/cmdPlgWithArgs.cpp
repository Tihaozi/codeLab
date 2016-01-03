// madoodia@gmail.com

#include "cmdPlgWithArgs.h"

// command line flags
#define	kHelpFlag			"-h"
#define	kHelpLongFlag		"-help"
#define	kSparseFlag			"-s"
#define	kSparseLongFlag		"-sparse"
#define	helpMessage			"This command is used to attach a particle on each vertex of a poly mesh"

using namespace std;

double CommandPluginWithArgs::sparse = NULL;

CommandPluginWithArgs::CommandPluginWithArgs()
{
}

CommandPluginWithArgs::~CommandPluginWithArgs()
{
}

bool CommandPluginWithArgs::isUndoable() const
{
	return true;
}

MStatus CommandPluginWithArgs::doIt(const MArgList& argList)
{
	MStatus status;
	status = parseArgs(argList);
	if (status == MS::kSuccess) {
		redoIt();

	}
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return MS::kSuccess;
}

MStatus CommandPluginWithArgs::redoIt()
{
	int counter = 0;

	MStatus status;
	MString msg, info;
	MSelectionList mSel;
	MDagPath mDagPath;
	MFnMesh mFnMesh;
	MGlobal::getActiveSelectionList(mSel);

	if (mSel.length() >= 1) {
		try
		{
			mSel.getDagPath(0, mDagPath);
			mFnMesh.setObject(mDagPath);
		}
		catch (const exception&)
		{
			MGlobal::displayError("Select a Poly mesh");
			return MS::kUnknownParameter;
		}
	}
	else {
		MGlobal::displayError("Select a Poly mesh");
		return MS::kUnknownParameter;
	}
	MPointArray mPointArray;
	mFnMesh.getPoints(mPointArray, MSpace::kWorld);

	MFnParticleSystem mFnParticle;
	mObjParticle = mFnParticle.create();
	// For fix the maya bug
	mFnParticle.setObject(mObjParticle);

	for (int i = 0; i < mPointArray.length();i++) {
		if (fmod(i, CommandPluginWithArgs::sparse) == 0) {
			mFnParticle.emit(mPointArray[i]);
			//info = i;
			//MGlobal::displayInfo(info);
			counter += 1;
		}
	}
	msg = "Total Points: ";
	msg += counter;
	MGlobal::displayInfo(msg);
	mFnParticle.saveInitialState();
	
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return MS::kSuccess;
}

MStatus CommandPluginWithArgs::undoIt()
{
	MStatus status;
	MFnDagNode mFnDagNode(mObjParticle);
	MDagModifier mDagMod;
	mDagMod.deleteNode(mFnDagNode.parent(0));
	mDagMod.doIt();
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return MS::kSuccess;
}

void* CommandPluginWithArgs::creator()
{
	return new CommandPluginWithArgs;
}

MSyntax CommandPluginWithArgs::newSyntax()
{
	MSyntax mSyntax;
	mSyntax.addFlag(kHelpFlag, kHelpLongFlag);
	mSyntax.addFlag(kSparseFlag, kSparseLongFlag, MSyntax::kDouble);
	return mSyntax;
}

MStatus CommandPluginWithArgs::parseArgs(const MArgList& argList)
{
	MStatus status = MS::kSuccess;
	MString msg;
	// For fix the maya bug
	// this will work in python api with MArgDatabase instead MArgParser
	MArgParser argData(syntax(), argList, &status);
	if (argData.isFlagSet(kSparseFlag)) {
		CommandPluginWithArgs::sparse = argData.flagArgumentDouble(kSparseFlag, 0);
		return MS::kSuccess;
	}
	if (argData.isFlagSet(kSparseLongFlag)) {
		CommandPluginWithArgs::sparse = argData.flagArgumentDouble(kSparseLongFlag, 0);
		return MS::kSuccess;
	}

	if (argData.isFlagSet(kHelpFlag)) {
		setResult(helpMessage);
		return MS::kSuccess;
	}
	if (argData.isFlagSet(kHelpLongFlag)) {
		setResult(helpMessage);
		return MS::kSuccess;
	}
}

