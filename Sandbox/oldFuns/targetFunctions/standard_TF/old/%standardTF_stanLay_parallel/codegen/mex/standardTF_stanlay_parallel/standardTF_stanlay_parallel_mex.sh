MATLAB="/usr/local/MATLAB/R2016b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/arwel/.matlab/R2016b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for standardTF_stanlay_parallel" > standardTF_stanlay_parallel_mex.mki
echo "CC=$CC" >> standardTF_stanlay_parallel_mex.mki
echo "CFLAGS=$CFLAGS" >> standardTF_stanlay_parallel_mex.mki
echo "CLIBS=$CLIBS" >> standardTF_stanlay_parallel_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> standardTF_stanlay_parallel_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> standardTF_stanlay_parallel_mex.mki
echo "CXX=$CXX" >> standardTF_stanlay_parallel_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> standardTF_stanlay_parallel_mex.mki
echo "CXXLIBS=$CXXLIBS" >> standardTF_stanlay_parallel_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> standardTF_stanlay_parallel_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> standardTF_stanlay_parallel_mex.mki
echo "LDFLAGS=$LDFLAGS" >> standardTF_stanlay_parallel_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> standardTF_stanlay_parallel_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> standardTF_stanlay_parallel_mex.mki
echo "Arch=$Arch" >> standardTF_stanlay_parallel_mex.mki
echo "LD=$LD" >> standardTF_stanlay_parallel_mex.mki
echo OMPFLAGS=-fopenmp -DOMPLIBNAME='"\"/usr/local/MATLAB/R2016b/sys/os/glnxa64/libiomp5.so\""' >> standardTF_stanlay_parallel_mex.mki
echo OMPLINKFLAGS=-fPIC -L/usr/local/MATLAB/R2016b/sys/os/glnxa64 -liomp5 >> standardTF_stanlay_parallel_mex.mki
echo "EMC_COMPILER=gcc" >> standardTF_stanlay_parallel_mex.mki
echo "EMC_CONFIG=optim" >> standardTF_stanlay_parallel_mex.mki
"/usr/local/MATLAB/R2016b/bin/glnxa64/gmake" -B -f standardTF_stanlay_parallel_mex.mk
