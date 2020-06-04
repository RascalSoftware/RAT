MATLAB="/usr/local/MATLAB/R2016b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/arwel/.matlab/R2016b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for matlabEngineCaller_customLayers" > matlabEngineCaller_customLayers_mex.mki
echo "CC=$CC" >> matlabEngineCaller_customLayers_mex.mki
echo "CFLAGS=$CFLAGS" >> matlabEngineCaller_customLayers_mex.mki
echo "CLIBS=$CLIBS" >> matlabEngineCaller_customLayers_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> matlabEngineCaller_customLayers_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> matlabEngineCaller_customLayers_mex.mki
echo "CXX=$CXX" >> matlabEngineCaller_customLayers_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> matlabEngineCaller_customLayers_mex.mki
echo "CXXLIBS=$CXXLIBS" >> matlabEngineCaller_customLayers_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> matlabEngineCaller_customLayers_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> matlabEngineCaller_customLayers_mex.mki
echo "LDFLAGS=$LDFLAGS" >> matlabEngineCaller_customLayers_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> matlabEngineCaller_customLayers_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> matlabEngineCaller_customLayers_mex.mki
echo "Arch=$Arch" >> matlabEngineCaller_customLayers_mex.mki
echo "LD=$LD" >> matlabEngineCaller_customLayers_mex.mki
echo OMPFLAGS= >> matlabEngineCaller_customLayers_mex.mki
echo OMPLINKFLAGS= >> matlabEngineCaller_customLayers_mex.mki
echo "EMC_COMPILER=gcc" >> matlabEngineCaller_customLayers_mex.mki
echo "EMC_CONFIG=optim" >> matlabEngineCaller_customLayers_mex.mki
"/usr/local/MATLAB/R2016b/bin/glnxa64/gmake" -B -f matlabEngineCaller_customLayers_mex.mk
