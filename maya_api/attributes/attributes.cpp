// Attribute Types
////////////////////////////////////////////
// MFnNumericAttribute
#include <maya/MFnNumericAttribute.h>

// Simple numeric data types
float, float2, float3,
int, int2, int3,
long, long2, long3,
short, short2, short3,
double, double2, double3, double4,
bool, byte, char

// Data function set
MFnNumericAttribute nAttr;
MObject aMyAttribute = nAttr.create("myAttribute", "myAttribute", MFnNumericData::kFloat);

// Data handle accessors
MDataHandle::asDouble(), MDataHandle::setDouble()
MDataHandle::asFloat(), MDataHandle::setFloat()
MDataHandle::asInt(), MDataHandle::setInt()
MDataHandle::asBool(), MDataHandle::setBool()
MDataHandle::asChar(), MDataHandle::setChar()
MDataHandle::asFloat2(), MDataHandle::setFloat2()
MDataHandle::asDouble3(), MDataHandle::setDouble3()

// MPlug accessors
MPlug::asDouble(), MPlug::setDouble()
MPlug::asFloat(), MPlug::setFloat()
MPlug::asInt(), MPlug::setInt()
MPlug::asBool(), MPlug::setBool()
MPlug::asChar(), MPlug::setChar()
etc...

// For the short array types
MObject oData = MPlug::asMObject();
MFnNumericData fnData(oData);
float val1, val2, val3;
fnData.getData3Float(val1, val2, val3);

MFnNumericData fnData;
MObject oData = fnData.create(MFnNumericData::k3Float);
fnData.setData3Float(val1, val2, val3);
plug.setMObject(oData);

////////////////////////////////////////////
// MFnTypedAttribute
#include <maya/MFnTypedAttribute.h>

// Array value and geometry
MFnData::kMesh
MFnData::kNurbsSurface
MFnData::kNurbsCurve
MFnData::kString
MFnData::kStringArray
MFnData::kDoubleArray
MFnData::kIntArray
MFnData::kVectorArray
MFnData::kPointArray
MFnData::kComponentList
etc..

// Data function set
MFnData
MFnTypedAttribute tAttr;
MObject aMyAttribute = tAttr.create("myAttribute", "myAttribute", MFnData::kMesh);

// Data handle accessors
MDataHandle::asString()
MDataHandle::asMesh()
MDataHandle::asNurbsCurve()
MDataHandle::asNurbsSurface()

MObject oData = MDataHandle::data()
MFnVectorArrayData fnData(oData);
MFnPointArrayData fnData(oData);
MFnStringArrayData fnData(oData);
MFnIntArrayData fnData(oData);
MFnDoubleArrayData fnData(oData);
MDoubleArray values = fnData.array()
MFnComponentListData fnData(oData);

MFnDoubleArrayData fnData;
MDoubleArray fnData;
MObject oData = fnData.create(doubleArray);
MDataHandle::setMObject(oData);

// MPlug accessors
MPlug::setString, MPlug::asString

// Everything is done with MObject
MObject oData = MPlug::asMObject();
MFnIntArrayData fnData(oData);

MFnDoubleArrayData fnData;
MDoubleArray doubleArray;
MObject oData = fnData.create(doubleArray);
MPlug::setMObject(oData);

////////////////////////////////////////////
// MFnMatrixAttribute
#include <maya/MFnMatrixAttribute.h>

// Double or float matrices
MFnMatrixAttribute mAttr;
MObject aMyAttribute = mAttr.create("myAttribute", "myAttribute");
MObject aMyAttribute = mAttr.create("myAttribute", "myAttribute", MFnMatrixAttribute::kFloat);

// Data handle accessors
MDataHandle::asMatrix(), MDataHandle::setMMatrix()
MDataHandle::asFloatMatrix(), MDataHandle::setMFloatMatrix()

// MPlug accessors
MObject oData = MPlug::asMObject();
MFnMatrixData fnData(oData);
MMatrix matrix = fnData.matrix();

MFnMatrixData fnData;
MObject oData = fnData.create(matrix);
MPlug::setMObject(oData);

////////////////////////////////////////////
// MFnEnumAttribute
#include <maya/MFnEnumAttribute.h>

// Drop down menu of short values
MFnEnumAttribute eAttr;
MObject aMyAttribute = eAttr.create("myAttribute", "myAttribute");
eAttr.addField("First Item", 0);
eAttr.addField("Second Item", 1);
eAttr.addField("Third Item", 2);

// Data handle accessors
MDataHandle::asShort(), MDataHandle::setShort()

// MPlug accessors
MPlug::asShort(), MPlug::setShort()

////////////////////////////////////////////
// MFnGenericAttribute
#include <maya/MFnGenericAttribute.h>

// An attibute that accept multiple types of data
MFnGenericAttribute gAttr;
MObject aMyAttribute = gAttr.create("myAttribute", "myAttribute")
gAttr.addDataAccept(MFnData::kMesh);
gAttr.addDataAccept(MFnData::kNurbsSurface);
gAttr.addDataAccept(MFnData::kNurbsCurve);

gAttr.addNumericDataAccept(MFnNumericData::kFloat);
gAttr.addNumericDataAccept(MFnNumericData::kInt);

// Data handle accessors
MFnData::Type dataType = MDataHandle::type();
if(dataType == MFnData::kMesh){
	MDataHandle::asMesh();
}

MFnNumericData::Type numericType = MDataHandle::numericType();

// MPlug accessors
MObject oData = MPlug::asMObject();
if(oData.hasFn(MFnData::kMesh)){
	MFnMesh fnMesh(oData);
}

////////////////////////////////////////////
// MFnUnitAttribute
#include <maya/MFnUnitAttribute.h>

// Angle, Distance and Time
MFnUnitAttribute uAttr;
MObject aMyAttribute = uAttr.create("myAttribute", "myAttribute", MFnUnitAttribute::kAngle);

// Data handle accessors
MDataHandle::asDistance(), MDataHandle::setMDistance() 
MDataHandle::asAngle(), MDataHandle::setMAngle() 
MDataHandle::asTime(), MDataHandle::setMTime() 

//MPlug accessors
MPlug::asMDistance(), MPlug::setMDistance() 
MPlug::asMAngle(), MPlug::setMAngle() 
MPlug::asMTime(), MPlug::setMTime() 

////////////////////////////////////////////
// MFnMessageAttribute
#include <maya/MFnMessageAttribute.h>

// Message connection, no data
MFnMessageAttribute msgAttr;
MObject aMyAttribute = msgAttr.create("myAttribute", "myAttribute");

////////////////////////////////////////////
// MFnCompoundAttribute
#include <maya/MFnCompoundAttribute.h>

// Attribute used to group other attribute
MFnCompoundAttribute cAttr;
MObject aMyAttribute = cAttr.create("myAttribute", "myAttribute");
cAttr.addChild(aChildeAttribute1)
cAttr.addChild(aChildeAttribute2)
cAttr.addChild(aChildeAttribute3)

"someNode1.myAttribute.childAttribute1"
"someNode1.myAttribute.childAttribute2"
"someNode1.myAttribute.childAttribute3"

// Data handle accessors
MDataHandle hCompoundAttribute = MDataBlock.inputValue(aMyAttribute);
MDataHandle hChildAttribute = hCompoundAttribute.child(aChildeAttribute1);

// MPlug accessors
MPlug plugCompoundAttribute(oNode, aMyAttribute);
MPlug plugChildAttribute1 = plugCompoundAttribute.child(0);
MPlug plugChildAttribute2 = plugCompoundAttribute.child(aChildeAttribute2);

// -------------------------------------------------------------------------------- //
// Attribute Options
////////////////////////////////////////////
// Output attribute options
setStorable(false);
setWritable(false);

////////////////////////////////////////////
// Other usefull attribute options
setKeyable(true);
setChannelBox(true);
setHidden(true);
setConnectable(true);

////////////////////////////////////////////
// Array attributes
setArray(true);

MFnNumericAttribute nAttr;
MObject myAttribute = nAttr.create("myAttribute", "myAttribute", MFnNumericData::kFloat);
nAattr.setArray(true);

// Two different type of array indeces : logical and physical
node.myAttribute[0] = 1.3
node.myAttribute[3] = 2.6
node.myAttribute[7] = 4.1
node.myAttribute[9] = 2.1

// Logical: 	0	3	7	9
// physical:	0	1	2	3

// Logical indeces can be sparse

// Data handle iteration of array attributes
// Ex. 1: Iterating by physical index
MArrayDataHandle hArrayHandle = data.inputArrayValue(aMyAttribute);
unsigned int numElements = hArrayHandle.elementCount();
unsigned int logicalIndex;
float value;
for(unsigned int i = 0;i < numElements;++i){
	hArrayHandle.jumpToArrayElement(i);
	logicalIndex = hArrayHandle.elementIndex();
	value = hArrayHandle.inputValue().asFloat();
}
// Ex. 2: Iterating with next()
MArrayDataHandle hArrayHandle = data.inputArrayValue(aMyAttribute);
unsigned int numElements = hArrayHandle.elementCount();
if(numElements > 0){
	hArrayHandle.jumpToArrayElement(0);
}
unsigned int logicalIndex;
float value;
for(unsigned int i = 0;i < numElements;++i){
	value = hArrayHandle.inputValue().asFloat();
	logicalIndex = hArrayHandle.elementIndex();
	hArrayHandle.next();
}

// Plug iteration of array attributes
// Ex. 1: Iterating by physical index
MPlug plug(oNode, aMyAttribute);
unsigned int numElements = plug.numElements();
float value;
MPlug plugElement;
for(unsigned int i = 0;i < numElements;++i){
	plugElement = plug.elementByPhysicalIndex(i);
	// plugElement = plug[i];
	value = plugElement.asFloat();
}
// Ex. 1: Iterating by logical index
MPlug plug(oNode, aMyAttribute);
MIntArray logicalIndices;
unsigned int numElements = plug.getExistingArrayAttributeIndeces(logicalIndices);
float value;
MPlug plugElement;
for(unsigned int i = 0;i < numElements;++i){
	plugElement = plug.elementByLogicalIndex(logicalIndices[i]);
	// plugElement = plug[i];
	value = plugElement.asFloat();
}
// Iterating on a plug by logical index will create a plug if one does not exist at that index

// No way to delete a pug in the API
// Must use MEL or maya.cmds: removeMultiInstance

// Multidimentional arrays are create by making array attributes
MFnCompoundAttribute cAttr;
MFnNumericAttribute nAttr;
MObject aValueAttribute = nAttr.create("valueAttribute", "valueAttribute", MFnNumericData::kFloat);
node.setArray(true);

MObject aCompoundAttribute = cAttr.create("compoundAttribute", "compoundAttribute", MFnNumericData::kFloat);
node.setArray(true);
cAttr.addChild(aValueAttribute);
addAttribute(aCompoundAttribute);

node.compoundAttribute[2].valueAttribute[5];

// Array attribute options
// Disconnect behavior
setDistanceBehavior(MFnAttribute::kDelete); 	// The Array index will be deleted when disconnected
setDistanceBehavior(MFnAttribute::kReset);		// The Array value will be reset to its default value when disconnected

// Index matters
setArray(true);
setReadable(false);
setIndexMatters(false);
cmds.connectAttr("sourceNode.attribte", "node.attribte", nextAvailable=True)

// Data builder
// Create array indices at runtime
// Used for output array attributes, attributes that are saved with the default attribute
//Constructing datahandles for array elements not known until runtime
setUsesArrayDataBuilder(true);

// Ex. setting an output attibute for each corresponding input attribute
MStatus MyNode::jumpToElement(MArrayDataHandle& hArray, unsigned int index)
{
	MStatus status;

	status = hArray.jumpToElement(index);
	if(MFAIL(status)){
		MArrayDataBuilder builder = hArray.builder(&status);
		CHECK_MSTATUS_AND_RETURN_IT(status);
		builder.addElement(index, &status);
		CHECK_MSTATUS_AND_RETURN_IT(status);
		status = hArray.set(builder);
		CHECK_MSTATUS_AND_RETURN_IT(status);
		status = hArray.jumpToElement(index);
		CHECK_MSTATUS_AND_RETURN_IT(status);
	}
	return status;
}

MArrayDataHandle hInputArrayHandle = data.inputArrayValue(aInputAttibute);
MArrayDataHandle hOutputArrayHandle = data.outputArrayValue(aOututAttibute);
unsigned int numElements = hInputArrayHandle.elementCount();
unsigned int logicalIndex;
float value;
for(unsigned int i = 0;i < numElements;++i){
	hInputArrayHandle.jumpToElement(i);
	logicalIndex = hInputArrayHandle.elementIndex();
	value = hInputArrayHandle.inputValue().asFloat();
	jumpToElement(hOutputArrayHandle, logicalIndex);
	hOutputArrayHandle.outputValue().asFloat();
}
hOutputArrayHandle.setAllClean();

// Array attributes vs. attributes of an array type
MObject aMultiAttribute = nAttr.create("multiAttribute", "multiAttribute", MFnNumericData::kDouble);
nAttr.setArray(true);

MFnTypedAttribute tAttr;
MObject aArrayAttribute = tAttr.create("arrayAttribute", "arrayAttribute", MFnData::kDoubleArray);

/*
What is the diffeence?

Array type attributes:
* Good for connecting or passing entire arrays through the DG
* Faster to read/write
* Stores every value to disk (more disk space)

Array attributes:
* Allow editing and keying of individual values
* Slower to read/write
* Stores non-default values in blocks to disk (less than space)
*/

////////////////////////////////////////////