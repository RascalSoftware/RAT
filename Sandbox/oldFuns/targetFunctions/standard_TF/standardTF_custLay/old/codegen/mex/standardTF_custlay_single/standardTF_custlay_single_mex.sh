MATLAB="/usr/local/MATLAB/R2016b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/arwel/.matlab/R2016b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for standardTF_custlay_single" > standardTF_custlay_single_mex.mki
echo "CC=$CC" >> standardTF_custlay_single_mex.mki
echo "CFLAGS=$CFLAGS" >> standardTF_custlay_single_mex.mki
echo "CLIBS=$CLIBS" >> standardTF_custlay_single_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> standardTF_custlay_single_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> standardTF_custlay_single_mex.mki
echo "CXX=$CXX" >> standardTF_custlay_single_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> standardTF_custlay_single_mex.mki
echo "CXXLIBS=$CXXLIBS" >> standardTF_custlay_single_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> standardTF_custlay_single_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> standardTF_custlay_single_mex.mki
echo "LDFLAGS=$LDFLAGS" >> standardTF_custlay_single_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> standardTF_custlay_single_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> standardTF_custlay_single_mex.mki
echo "Arch=$Arch" >> standardTF_custlay_single_mex.mki
echo "LD=$LD" >> standardTF_custlay_single_mex.mki
echo OMPFLAGS= >> standardTF_custlay_single_mex.mki
echo OMPLINKFLAGS= >> standardTF_custlay_single_mex.mki
echo "EMC_COMPILER=gcc" >> standardTF_custlay_single_mex.mki
echo "EMC_CONFIG=optim" >> standardTF_custlay_single_mex.mki
"/usr/local/MATLAB/R2016b/bin/glnxa64/gmake" -B -f standardTF_custlay_single_mex.mk
