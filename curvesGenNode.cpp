//
// Copyright (C) hdd
//
// File: curvesGenNode.cpp
//
// Dependency Graph Node: curvesGen
//
// Author: Maya Plug-in Wizard 2.0
//

#include "curvesGenNode.h"
#include <cstdlib>
#include <cmath>
#include <maya/MPlug.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MArrayDataHandle.h>
#include <maya/MGlobal.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnMatrixAttribute.h>
#include <maya/MFnNurbsCurve.h>
#include <maya/MTransformationMatrix.h>
#include <maya/MMatrix.h>
#include <maya/MPoint.h>
#include <maya/MPointArray.h>
#include <maya/MFnNurbsCurveData.h>

#define PI 3.14159265


//#error change the following to a unique value and then erase this line
MTypeId     curvesGen::id( 0x87005 );

MObject     curvesGen::curvesInput;
MObject     curvesGen::curvesOutput;
MObject     curvesGen::numCurves;
MObject     curvesGen::degree;

MPointArray curvesGen::PP;

curvesGen::curvesGen() {}
curvesGen::~curvesGen() {}

MStatus curvesGen::compute( const MPlug& plug, MDataBlock& data )

{
	MStatus returnStatus;
	if( plug == curvesOutput )
	{
		curvesGen::MPointArrayVector.clear();
                curvesGen::FinalMPointArray.clear();


		MArrayDataHandle inputCurvesData = data.inputArrayValue( curvesInput, &returnStatus );
		MDataHandle inputNumCurvesData = data.inputValue( numCurves, &returnStatus );
                MDataHandle degreeData = data.inputValue( degree, &returnStatus );

		MArrayDataHandle outputCurvesData = data.outputArrayValue(curvesOutput,&returnStatus );

		int numP = inputNumCurvesData.asInt();
		int numCurves = inputCurvesData.elementCount();
                int deg = degreeData.asInt();
                
                if (PP.length() != numP){
                    PP=distributePoints(numP);
                }
                
		for (int i=0;i<numCurves;i++){
			inputCurvesData.jumpToElement(i);
			MDataHandle curveH = inputCurvesData.inputValue();
			MMatrix curveM = curveH.asMatrix();
                        MPointArray PPM;
                        
                        for (int p =0; p< PP.length();p++){
                            MPoint PM = PP[p]*curveM;
                            PPM.append(PM);
                        }
                MPointArrayVector.push_back(PPM);
		}

		
		for (unsigned int j=0;j < curvesGen::MPointArrayVector.size();j++){
			for (int k=0; k<numP ;k++){
				MPoint finalP= MPointArrayVector[j][k];
				curvesGen::FinalMPointArray.append(finalP);
			}
		}

                
		for (int p=0;p<numP;p++){
			MPointArray tmpArray;
			for (int c=0; c < numCurves; c++){
				tmpArray.append(FinalMPointArray[c*numP+p]);
			}
			MFnNurbsCurveData curveCreator;
			MObject finalCurve = curveCreator.create();
			MFnNurbsCurve finalCurveFn;
			finalCurveFn.createWithEditPoints(tmpArray,deg,MFnNurbsCurve::kOpen,false,false,true,finalCurve);
			outputCurvesData.jumpToArrayElement(p);
                        MDataHandle curveH = outputCurvesData.outputValue();
			curveH.set(finalCurve);
                    
		}
                
	data.setClean(plug);


	} else {
		return MS::kUnknownParameter;
	}

	return MS::kSuccess;
}

void* curvesGen::creator()

{
	return new curvesGen();
}

MStatus curvesGen::initialize()
{

	MFnNumericAttribute nAttr;
	MFnMatrixAttribute mAttr;
	MFnTypedAttribute tAttr;

	MStatus				stat;

	numCurves = nAttr.create( "numCurves", "in", MFnNumericData::kInt, 10);
 	nAttr.setStorable(true);
 	nAttr.setKeyable(true);

	degree = nAttr.create( "degree", "d", MFnNumericData::kInt, 3);
 	nAttr.setStorable(true);
 	nAttr.setKeyable(true);

	curvesInput = mAttr.create( "inputCurvesM", "inC", MFnMatrixAttribute::kDouble);
 	mAttr.setStorable(true);
 	mAttr.setArray(true);

	curvesOutput = tAttr.create( "outputCurves", "outC",MFnData::kNurbsCurve);
	tAttr.setWritable(false);
	//tAttr.setStorable(false);
 	tAttr.setArray(true);


	stat = addAttribute( numCurves );
		if (!stat) { stat.perror("addAttribute"); return stat;}

	stat = addAttribute( degree );
		if (!stat) { stat.perror("addAttribute"); return stat;}

	stat = addAttribute( curvesInput );
		if (!stat) { stat.perror("addAttribute"); return stat;}
	stat = addAttribute( curvesOutput );
		if (!stat) { stat.perror("addAttribute"); return stat;}

	stat = attributeAffects( numCurves, curvesOutput );
		if (!stat) { stat.perror("attributeAffects"); return stat;}

        stat = attributeAffects( curvesInput, curvesOutput );
		if (!stat) { stat.perror("attributeAffects"); return stat;}
        
	stat = attributeAffects( degree, curvesOutput );
		if (!stat) { stat.perror("attributeAffects"); return stat;}
	return MS::kSuccess;

}

double randomRange(double min, double max)
{
	return (double)((max - min) * rand()/(double)RAND_MAX + min);
}

MPointArray curvesGen::distributePoints(int numPoints){
        /*
         calcolo della distribuzioni dei punti in un cerchio
         */
	MPointArray numPointsArray;
	double radius=1.0;
	for(int i=0; i<numPoints; i++){
            double Rnd = randomRange(0.0,2.0*PI);
            double rR = randomRange(0.0,1.0);
            double x = (sqrt(rR)*cos(Rnd)*radius);
            double z = (sqrt(rR)*sin(Rnd)*radius);
            double y = 0;
            MPoint P(x,y,z);

            numPointsArray.append(P);
	}
	return numPointsArray;
}



