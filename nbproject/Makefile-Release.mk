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
CC=gcc412
CCC=g++412
CXX=g++412
FC=
AS=

# Macros
CND_PLATFORM=FOR_MAYA-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

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

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L${MAYA_LOCATION}/maya/lib -lOpenMaya -lFoundation

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/FOR_MAYA-Linux-x86/libcurvesgen.so

dist/Release/FOR_MAYA-Linux-x86/libcurvesgen.so: ${OBJECTFILES}
	${MKDIR} -p dist/Release/FOR_MAYA-Linux-x86
	${LINK.cc} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcurvesgen.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/curvesGenNode.o: nbproject/Makefile-${CND_CONF}.mk curvesGenNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -DLINUX -D_BOOL -DINCLUDE_IOSTREAM -DREQUIRE_IOSTREAM -I${MAYA_LOCATION}/maya/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/curvesGenNode.o curvesGenNode.cpp

${OBJECTDIR}/mainPlugin.o: nbproject/Makefile-${CND_CONF}.mk mainPlugin.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -DLINUX -D_BOOL -DINCLUDE_IOSTREAM -DREQUIRE_IOSTREAM -I${MAYA_LOCATION}/maya/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/mainPlugin.o mainPlugin.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/FOR_MAYA-Linux-x86/libcurvesgen.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
