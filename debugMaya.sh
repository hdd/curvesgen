echo "RUNNIG MAYA IN DEBUG MODE...."
export MAYA_LOCATION=/usr/autodesk/maya
export LD_LIBRARY_PATH=/usr/autodesk/maya/lib/
export AW_DEBUGGING=F
export MAYA_DEBUG_NO_SIGNAL_HANDLERS=1

ddd /usr/autodesk/maya2008/bin/maya.bin

