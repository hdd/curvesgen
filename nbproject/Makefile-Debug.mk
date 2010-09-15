#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=
CCC=g++412
CXX=g++412
FC=

# Macros
PLATFORM=FOR_MAYA-Linux-x86

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Debug/${PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/curvesGenNode.o \
	${OBJECTDIR}/mainPlugin.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/autodesk/maya/lib -lOpenMaya -lFoundation

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/${PLATFORM}/libcurvesGen.so

dist/Debug/${PLATFORM}/libcurvesGen.so: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/${PLATFORM}
	${LINK.cc} -shared -o dist/Debug/${PLATFORM}/libcurvesGen.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/curvesGenNode.o: curvesGenNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -DLINUX -D_BOOL -DINCLUDE_IOSTREAM -DREQUIRE_IOSTREAM -I/usr/autodesk/maya/include -fPIC  -o ${OBJECTDIR}/curvesGenNode.o curvesGenNode.cpp

${OBJECTDIR}/mainPlugin.o: mainPlugin.cpp 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -g -DLINUX -D_BOOL -DINCLUDE_IOSTREAM -DREQUIRE_IOSTREAM -I/usr/autodesk/maya/include -fPIC  -o ${OBJECTDIR}/mainPlugin.o mainPlugin.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/${PLATFORM}/libcurvesGen.so

# Subprojects
.clean-subprojects:
