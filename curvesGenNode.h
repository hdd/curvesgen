#ifndef _curvesGenNode
#define _curvesGenNode
//
// Copyright (C) hdd
//
// File: curvesGenNode.h
//
// Dependency Graph Node: curvesGen
//
// Author: Maya Plug-in Wizard 2.0
//

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MTypeId.h>
#include <maya/MMatrix.h>
#include <maya/MPointArray.h>
#include <vector>

using std::vector;

class curvesGen : public MPxNode
{
public:
					curvesGen();
	virtual				~curvesGen();

	virtual MStatus		compute( const MPlug& plug, MDataBlock& data );
	MPointArray distributePoints(int numPoints);

	static  void*		creator();
	static  MStatus		initialize();

public:


	static  MObject		curvesInput;
	static  MObject		curvesOutput;
	static  MObject		numCurves;
        static  MObject		degree;

	MPointArray FinalMPointArray;
	vector<MPointArray> MPointArrayVector;
	static MPointArray      PP ;


	static	MTypeId		id;
};

#endif
