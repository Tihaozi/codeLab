// madoodia@gmail.com

#include <iostream>

#include <maya/MSimple.h>
#include <maya/MIOStream.h>
using namespace std;

DeclareSimpleCommand(HelloWorld, "Madoodia", "2015");

MStatus HelloWorld::doIt(const MArgList&)
{
	cout << "Hello World\n" << endl;
	return MS::kSuccess;
}
