/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker-oscog.40 uuid: 637db40c-33c6-4263-816e-1b8cc19e3c99
   from
	GeniePlugin VMMaker-oscog.40 uuid: 637db40c-33c6-4263-816e-1b8cc19e3c99
 */
static char __buildInfo[] = "GeniePlugin VMMaker-oscog.40 uuid: 637db40c-33c6-4263-816e-1b8cc19e3c99 " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "sqMemoryAccess.h"


/*** Constants ***/


/*** Function Prototypes ***/
static sqInt cSquaredDistanceFromto(int *   aPoint, int *   bPoint);
static sqInt cSubstAngleFactorFromto(sqInt startDegreeNumber, sqInt endDegreeNumber);
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
static sqInt halt(void);
static sqInt majorNO(void);
static sqInt minorNO(void);
static sqInt msg(char *s);
EXPORT(sqInt) primSameClassAbsoluteStrokeDistanceMyPoints_otherPoints_myVectors_otherVectors_mySquaredLengths_otherSquaredLengths_myAngles_otherAngles_maxSizeAndReferenceFlag_rowBase_rowInsertRemove_rowInsertRemoveCount(void);
EXPORT(sqInt) primVersionNO(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
static void sqAssert(sqInt aBool);


/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"GeniePlugin v2.0 30 December 2010 VMMaker-oscog.40 (i)"
#else
	"GeniePlugin v2.0 30 December 2010 VMMaker-oscog.40 (e)"
#endif
;



/*	arguments are pointer to ints paired as x,y coordinates of points */

static sqInt
cSquaredDistanceFromto(int *   aPoint, int *   bPoint)
{
	sqInt aPointX;
	sqInt aPointY;
	sqInt bPointX;
	sqInt bPointY;
	sqInt xDiff;
	sqInt yDiff;

	aPointX = aPoint[0];
	aPointY = aPoint[1];
	bPointX = bPoint[0];
	bPointY = bPoint[1];
	xDiff = bPointX - aPointX;
	yDiff = bPointY - aPointY;
	return (xDiff * xDiff) + (yDiff * yDiff);
}

static sqInt
cSubstAngleFactorFromto(sqInt startDegreeNumber, sqInt endDegreeNumber)
{
	sqInt absDiff;

	absDiff = abs(endDegreeNumber - startDegreeNumber);
	if (absDiff > 180) {
		absDiff = 360 - absDiff;
	}
	return ((usqInt) (absDiff * absDiff) >> 6);
}


/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine *
getInterpreter(void)
{
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

static sqInt
halt(void)
{
	;
	return 0;
}

static sqInt
majorNO(void)
{
	return 2;
}

static sqInt
minorNO(void)
{
	return 0;
}

static sqInt
msg(char *s)
{
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}

EXPORT(sqInt)
primSameClassAbsoluteStrokeDistanceMyPoints_otherPoints_myVectors_otherVectors_mySquaredLengths_otherSquaredLengths_myAngles_otherAngles_maxSizeAndReferenceFlag_rowBase_rowInsertRemove_rowInsertRemoveCount(void)
{
	sqInt additionalMultiInsertRemoveCost;
	sqInt base;
	sqInt forReference;
	sqInt i;
	sqInt iM1;
	sqInt iM1T2;
	sqInt insert;
	sqInt insertBase;
	sqInt insertRemove;
	sqInt insertRemoveCount;
	sqInt j;
	sqInt jLimiT;
	sqInt jM1;
	sqInt jM1T2;
	sqInt maxDist;
	sqInt maxSize;
	sqInt maxSizeAndRefFlag;
	int *   myAngles;
	sqInt myAnglesOop;
	int *   myPoints;
	sqInt myPointsOop;
	int *   mySquaredLengths;
	sqInt mySquaredLengthsOop;
	int *   myVectors;
	sqInt myVectorsOop;
	sqInt myVectorsSize;
	int *   otherAngles;
	sqInt otherAnglesOop;
	int *   otherPoints;
	sqInt otherPointsOop;
	sqInt otherPointsSize;
	int *   otherSquaredLengths;
	sqInt otherSquaredLengthsOop;
	sqInt otherSquaredLengthsSize;
	int *   otherVectors;
	sqInt otherVectorsOop;
	sqInt otherVectorsSize;
	sqInt remove;
	sqInt removeBase;
	int *   rowBase;
	sqInt rowBaseOop;
	sqInt rowBaseSize;
	int *   rowInsertRemove;
	int *   rowInsertRemoveCount;
	sqInt rowInsertRemoveCountOop;
	sqInt rowInsertRemoveOop;
	sqInt subst;
	sqInt substBase;
	sqInt _return_value;

	myPointsOop = interpreterProxy->stackValue(11);
	otherPointsOop = interpreterProxy->stackValue(10);
	myVectorsOop = interpreterProxy->stackValue(9);
	otherVectorsOop = interpreterProxy->stackValue(8);
	mySquaredLengthsOop = interpreterProxy->stackValue(7);
	otherSquaredLengthsOop = interpreterProxy->stackValue(6);
	myAnglesOop = interpreterProxy->stackValue(5);
	otherAnglesOop = interpreterProxy->stackValue(4);
	maxSizeAndRefFlag = interpreterProxy->stackIntegerValue(3);
	rowBaseOop = interpreterProxy->stackValue(2);
	rowInsertRemoveOop = interpreterProxy->stackValue(1);
	rowInsertRemoveCountOop = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		msg("failed 1");
		return null;
	}
	interpreterProxy->success(((((((((((interpreterProxy->isWords(myPointsOop)) && (interpreterProxy->isWords(otherPointsOop))) && (interpreterProxy->isWords(myVectorsOop))) && (interpreterProxy->isWords(otherVectorsOop))) && (interpreterProxy->isWords(mySquaredLengthsOop))) && (interpreterProxy->isWords(otherSquaredLengthsOop))) && (interpreterProxy->isWords(myAnglesOop))) && (interpreterProxy->isWords(otherAnglesOop))) && (interpreterProxy->isWords(rowBaseOop))) && (interpreterProxy->isWords(rowInsertRemoveOop))) && (interpreterProxy->isWords(rowInsertRemoveCountOop)));
	if (interpreterProxy->failed()) {
		msg("failed 2");
		return null;
	}
	interpreterProxy->success((interpreterProxy->isMemberOf(myPointsOop, "PointArray")) && (interpreterProxy->isMemberOf(otherPointsOop, "PointArray")));
	if (interpreterProxy->failed()) {
		msg("failed 3");
		return null;
	}
	myPoints = interpreterProxy->firstIndexableField(myPointsOop);
	otherPoints = interpreterProxy->firstIndexableField(otherPointsOop);
	myVectors = interpreterProxy->firstIndexableField(myVectorsOop);
	otherVectors = interpreterProxy->firstIndexableField(otherVectorsOop);
	mySquaredLengths = interpreterProxy->firstIndexableField(mySquaredLengthsOop);
	otherSquaredLengths = interpreterProxy->firstIndexableField(otherSquaredLengthsOop);
	myAngles = interpreterProxy->firstIndexableField(myAnglesOop);
	otherAngles = interpreterProxy->firstIndexableField(otherAnglesOop);
	rowBase = interpreterProxy->firstIndexableField(rowBaseOop);
	rowInsertRemove = interpreterProxy->firstIndexableField(rowInsertRemoveOop);

	/* Note: myPointsSize and mySquaredLengthsSize variables eliminated to reduce
	method temporary variable count for closure-enabled images */
	/* PointArrays */
	/* myPointsSize := (interpreterProxy stSizeOf: myPointsOop) bitShift: -1. */

	rowInsertRemoveCount = interpreterProxy->firstIndexableField(rowInsertRemoveCountOop);
	otherPointsSize = ((usqInt) (interpreterProxy->stSizeOf(otherPointsOop)) >> 1);
	myVectorsSize = ((usqInt) (interpreterProxy->stSizeOf(myVectorsOop)) >> 1);

	/* IntegerArrays */
	/* mySquaredLengthsSize := interpreterProxy stSizeOf: mySquaredLengthsOop. */

	otherVectorsSize = ((usqInt) (interpreterProxy->stSizeOf(otherVectorsOop)) >> 1);
	otherSquaredLengthsSize = interpreterProxy->stSizeOf(otherSquaredLengthsOop);
	rowBaseSize = interpreterProxy->stSizeOf(rowBaseOop);
	interpreterProxy->success(((rowBaseSize == (interpreterProxy->stSizeOf(rowInsertRemoveOop))) && (rowBaseSize == (interpreterProxy->stSizeOf(rowInsertRemoveCountOop)))) && (rowBaseSize > otherVectorsSize));
	if (interpreterProxy->failed()) {
		msg("failed 4");
		return null;
	}
	interpreterProxy->success(((((((interpreterProxy->stSizeOf(mySquaredLengthsOop)) >= (myVectorsSize - 1)) && ((((usqInt) (interpreterProxy->stSizeOf(myPointsOop)) >> 1)) >= myVectorsSize)) && (otherSquaredLengthsSize >= (otherVectorsSize - 1))) && (otherPointsSize >= otherVectorsSize)) && ((interpreterProxy->stSizeOf(myAnglesOop)) >= (myVectorsSize - 1))) && ((interpreterProxy->stSizeOf(otherAnglesOop)) >= (otherVectorsSize - 1)));
	if (interpreterProxy->failed()) {
		msg("failed 5");
		return null;
	}
	forReference = maxSizeAndRefFlag & 1;
	maxSize = ((usqInt) maxSizeAndRefFlag >> 1);
	maxDist = ((usqInt) 1 << 29);
	if (forReference) {
		additionalMultiInsertRemoveCost = 0;
	}
	else {
		additionalMultiInsertRemoveCost = ((usqInt) (maxSize * maxSize) >> 10);
	}
	rowBase[0] = 0;
	rowInsertRemove[0] = 0;
	rowInsertRemoveCount[0] = 2;
	insertRemove = 0 - additionalMultiInsertRemoveCost;
	jLimiT = otherVectorsSize;
	if (!((otherPointsSize >= (jLimiT - 1)) && (otherSquaredLengthsSize >= (jLimiT - 1)))) {
		interpreterProxy->primitiveFail();
		return null;
	}
	for (j = 1; j <= jLimiT; j += 1) {
		jM1 = j - 1;
		insertRemove = (insertRemove + (((usqInt) ((otherSquaredLengths[jM1]) + (cSquaredDistanceFromto(otherPoints + (((usqInt) jM1 << 1)), myPoints))) >> 7))) + additionalMultiInsertRemoveCost;
		rowInsertRemove[j] = insertRemove;
		rowBase[j] = (insertRemove * j);
		rowInsertRemoveCount[j] = (j + 1);
	}
	insertRemove = (rowInsertRemove[0]) - additionalMultiInsertRemoveCost;
	for (i = 1; i <= myVectorsSize; i += 1) {
		iM1 = i - 1;
		iM1T2 = ((usqInt) iM1 << 1);
		substBase = rowBase[0];
		insertRemove = (insertRemove + (((usqInt) ((mySquaredLengths[iM1]) + (cSquaredDistanceFromto(myPoints + iM1T2, otherPoints))) >> 7))) + additionalMultiInsertRemoveCost;
		rowInsertRemove[0] = insertRemove;
		rowBase[0] = (insertRemove * i);
		rowInsertRemoveCount[0] = (i + 1);
		jLimiT = otherVectorsSize;
		for (j = 1; j <= jLimiT; j += 1) {
			jM1 = j - 1;
			jM1T2 = ((usqInt) jM1 << 1);
			removeBase = rowBase[j];
			insertBase = rowBase[jM1];
			remove = ((usqInt) ((mySquaredLengths[iM1]) + (cSquaredDistanceFromto(myPoints + iM1T2, otherPoints + (((usqInt) j << 1))))) >> 7);
			if (((insertRemove = rowInsertRemove[j])) == 0) {
				removeBase += remove;
			}
			else {
				removeBase = (removeBase + insertRemove) + (remove * (rowInsertRemoveCount[j]));
				remove += insertRemove;
			}
			insert = ((usqInt) ((otherSquaredLengths[jM1]) + (cSquaredDistanceFromto(otherPoints + jM1T2, myPoints + (((usqInt) i << 1))))) >> 7);
			if (((insertRemove = rowInsertRemove[jM1])) == 0) {
				insertBase += insert;
			}
			else {
				insertBase = (insertBase + insertRemove) + (insert * (rowInsertRemoveCount[jM1]));
				insert += insertRemove;
			}
			if (forReference) {
				substBase = maxDist;
			}
			else {
				subst = ((usqInt) (((cSquaredDistanceFromto(otherVectors + jM1T2, myVectors + iM1T2)) + (cSquaredDistanceFromto(otherPoints + jM1T2, myPoints + iM1T2))) * (16 + (cSubstAngleFactorFromto(otherAngles[jM1], myAngles[iM1])))) >> 11);
				substBase += subst;
			}
			if ((substBase <= removeBase)
			 && (substBase <= insertBase)) {
				base = substBase;
				insertRemove = 0;
				insertRemoveCount = 1;
			}
			else {
				if (removeBase <= insertBase) {
					base = removeBase;
					insertRemove = remove + additionalMultiInsertRemoveCost;
					insertRemoveCount = (rowInsertRemoveCount[j]) + 1;
				}
				else {
					base = insertBase;
					insertRemove = insert + additionalMultiInsertRemoveCost;
					insertRemoveCount = (rowInsertRemoveCount[jM1]) + 1;
				}
			}
			substBase = rowBase[j];
			rowBase[j] = (((base < maxDist) ? base : maxDist));
			rowInsertRemove[j] = (((insertRemove < maxDist) ? insertRemove : maxDist));
			rowInsertRemoveCount[j] = insertRemoveCount;
		}
		insertRemove = rowInsertRemove[0];
	}
	_return_value = interpreterProxy->integerObjectOf(base);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(13, _return_value);
	return null;
}


/*	majorNO * 1000 + minorNO */

EXPORT(sqInt)
primVersionNO(void)
{
	sqInt _return_value;

	_return_value = interpreterProxy->integerObjectOf(((2 * 1000) + 0));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}

static void
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* GeniePlugin_exports[][3] = {
	{"GeniePlugin", "getModuleName", (void*)getModuleName},
	{"GeniePlugin", "primSameClassAbsoluteStrokeDistanceMyPoints_otherPoints_myVectors_otherVectors_mySquaredLengths_otherSquaredLengths_myAngles_otherAngles_maxSizeAndReferenceFlag_rowBase_rowInsertRemove_rowInsertRemoveCount", (void*)primSameClassAbsoluteStrokeDistanceMyPoints_otherPoints_myVectors_otherVectors_mySquaredLengths_otherSquaredLengths_myAngles_otherAngles_maxSizeAndReferenceFlag_rowBase_rowInsertRemove_rowInsertRemoveCount},
	{"GeniePlugin", "primVersionNO", (void*)primVersionNO},
	{"GeniePlugin", "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#endif /* ifdef SQ_BUILTIN_PLUGIN */
