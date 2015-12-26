// madoodia@gmail.com

#include "cmdPlgWithArgs.h"

// command line flags
#define	kHelpFlag			"-h"
#define	kHelpLongFlag		"-help"
#define	kSparseFlag			"-s"
#define	kSparseLongFlag		"-sparse"
#define	helpMessage			"This command is used to attach a particle on each vertex of a poly mesh"

using namespace std;

int counter = 0;

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
	MGlobal::displayError("here1");
	parseArgs(argList);
	MGlobal::displayError("here2");
	if (sparse != NULL) {
		MGlobal::displayError("here3");
		redoIt();
		MGlobal::displayError("here4");
	}
	return MS::kSuccess;
}

MStatus CommandPluginWithArgs::redoIt()
{
	MString msg;
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
	for (int i = 0; i < mPointArray.length();i++) {
		if (fmod(i, sparse) == 0) {
			mFnParticle.emit(mPointArray[i]);
			counter += 1;
		}
	}
	msg = "Total Points: " + counter;
	MGlobal::displayInfo(msg);
	mFnParticle.saveInitialState();

	return MS::kSuccess;
}

MStatus CommandPluginWithArgs::undoIt()
{
	MFnDagNode mFnDagNode(mObjParticle);
	MDagModifier mDagMod;
	mDagMod.deleteNode(mFnDagNode.parent(0));
	mDagMod.doIt();
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
	MArgDatabase parsedArguments(syntax(), argList);
	if (parsedArguments.isFlagSet(kSparseFlag)) {
		sparse = parsedArguments.flagArgumentDouble(kSparseFlag, 0);
		return MS::kSuccess;
	}
	if (parsedArguments.isFlagSet(kSparseLongFlag)) {
		sparse = parsedArguments.flagArgumentDouble(kSparseLongFlag, 0);
		return MS::kSuccess;
	}

	if (parsedArguments.isFlagSet(kHelpFlag)) {
		setResult(helpMessage);
		return MS::kSuccess;
	}
	if (parsedArguments.isFlagSet(kHelpLongFlag)) {
		setResult(helpMessage);
		return MS::kSuccess;
	}
}

