
"""
creator function
"""
def createCurveSystem():
	"""
	select original curves and run this script
	by default 50 curves was genereated
	"""
	curvesGenerated=50
	curves=cmd.ls(sl=1)
	C=curveSystem(curves,curvesGenerated)


"""
base class to create system
"""

class curveSystem:

    def __init__(self,origCurves,numChild):
        """
            init function
        """
        if origCurves != None:
            self.__curves    = origCurves
            self.__numCurves = numChild
            self.__nodeName  = self.createCGNode()
            self.connectCurves()
	    self.createSubCurves()
	    return


    def createCGNode(self):
        """
            create a curvesGenNode
        """
        node = cmd.createNode("curvesGen",n="CGNode")
        return node

    def connectCurves(self):
        for c in range(len(self.__curves)):
            outAttr=".".join([self.__curves[c],"worldMatrix[0]"])
            inAttr=".".join([self.__nodeName,"inputCurvesM[%d]"%(c)])
            try:
                cmd.connectAttr(outAttr,inAttr,f=1)
            except:
                # insert warning here
                pass

    def createSubCurves(self):
        CGName="curvesGen1"
        cmd.setAttr("%s.numCurves"%self.__nodeName,self.__numCurves)
        for c in range(self.__numCurves):
            C=cmd.curve(d=3,p=[0,0,0])
            Cs=cmd.listRelatives(C,s=1)[0]
            try:
                cmd.connectAttr("%s.outputCurves[%d]"%(self.__nodeName,c),"%s.create"%(Cs))
            except:
                # insert warning here
                pass


