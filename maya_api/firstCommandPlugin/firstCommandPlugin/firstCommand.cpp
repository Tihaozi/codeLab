// madoodia@gmail.com

#include "firstCommand.h"

FirstCommand::FirstCommand()
{
}

FirstCommand::~FirstCommand()
{
}

void* FirstCommand::creator()
{
	return new FirstCommand;
}

MStatus FirstCommand::doIt(const MArgList& argList)
{
	MGlobal::displayInfo("I just wrote my first command plugin!");
	// for print message on output window (does not work: i don't know why!)
	std::cout << "this is First Command" << std::endl;
	// MS is typedef of MStatus
	return MS::kSuccess;
}