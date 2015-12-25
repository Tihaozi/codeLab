// madoodia@gmail.com

#ifndef COMMANDEXAMPLE_H
#define COMMANDEXAMPLE_H

#include <maya/MPxCommand.h>
#include <maya/MGlobal.h>
#include <maya/MObject.h>

class CommandExample : public MPxCommand {
public:
	CommandExample();
	~CommandExample();
	virtual MStatus doIt(const MArgList& argList);
	virtual MStatus redoIt();
	virtual MStatus undoIt();
	virtual bool isUndoable() const;
	
	static void* creator();
};

#endif  // COMMANDEXAMPLE_H