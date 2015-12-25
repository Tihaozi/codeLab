// madoodia@gmail.com

#ifndef FIRSTCOMMAND_H
#define FIRSTCOMMAND_H

#include <maya/MPxCommand.h>
#include <maya/MGlobal.h>
#include <maya/MObject.h>

class FirstCommand : public MPxCommand {
public:
	FirstCommand();
	~FirstCommand();
	virtual MStatus doIt(const MArgList& argList);
	static void* creator();
};

#endif // FIRSTCOMMAND_H
