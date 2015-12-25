// madoodia@gmail.com

#include "commandExample.h"

CommandExample::CommandExample()
{
	MGlobal::displayInfo("----- This is Constructor -----");
}

CommandExample::~CommandExample()
{
	MGlobal::displayInfo("----- This is Destructor -----");
}

void* CommandExample::creator()
{
	return new CommandExample;
}

MStatus CommandExample::doIt(const MArgList& argList)
{
	MGlobal::displayInfo("----- This is doIt method -----");

	return MS::kSuccess;
}

MStatus CommandExample::undoIt()
{
	MGlobal::displayInfo("----- This is undoIt method -----");

	return MS::kSuccess;
}

MStatus CommandExample::redoIt()
{
	MGlobal::displayInfo("----- This is redoIt method -----");

	return MS::kSuccess;
}

bool CommandExample::isUndoable() const
{
	MGlobal::displayInfo("----- This is isUndoable method -----");

	return (false);
}