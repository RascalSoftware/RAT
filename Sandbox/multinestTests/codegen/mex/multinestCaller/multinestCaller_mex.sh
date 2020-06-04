MATLAB="/usr/local/MATLAB/R2016b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/arwel/.matlab/R2016b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for multinestCaller" > multinestCaller_mex.mki
echo "CC=$CC" >> multinestCaller_mex.mki
echo "CFLAGS=$CFLAGS" >> multinestCaller_mex.mki
echo "CLIBS=$CLIBS" >> multinestCaller_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> multinestCaller_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> multinestCaller_mex.mki
echo "CXX=$CXX" >> multinestCaller_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> multinestCaller_mex.mki
echo "CXXLIBS=$CXXLIBS" >> multinestCaller_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> multinestCaller_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> multinestCaller_mex.mki
echo "LDFLAGS=$LDFLAGS" >> multinestCaller_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> multinestCaller_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> multinestCaller_mex.mki
echo "Arch=$Arch" >> multinestCaller_mex.mki
echo "LD=$LD" >> multinestCaller_mex.mki
echo OMPFLAGS= >> multinestCaller_mex.mki
echo OMPLINKFLAGS= >> multinestCaller_mex.mki
echo "EMC_COMPILER=gcc" >> multinestCaller_mex.mki
echo "EMC_CONFIG=optim" >> multinestCaller_mex.mki
"/usr/local/MATLAB/R2016b/bin/glnxa64/gmake" -B -f multinestCaller_mex.mk
