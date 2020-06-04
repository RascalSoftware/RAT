START_DIR = /home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single

MATLAB_ROOT = /usr/local/MATLAB/R2016b
MAKEFILE = standardTF_custlay_single_mex.mk

include standardTF_custlay_single_mex.mki


SRC_FILES =  \
	matlabCallFun.c \
	standardTF_custlay_single_data.c \
	standardTF_custlay_single_initialize.c \
	standardTF_custlay_single_terminate.c \
	standardTF_custlay_single.c \
	call_customLayers.c \
	groupLayers_Mod.c \
	eml_int_forloop_overflow_check.c \
	indexShapeCheck.c \
	scalexpAlloc.c \
	makeSLDProfileXY.c \
	sum.c \
	isequal.c \
	combine_vector_elements.c \
	asymconvstep.c \
	mpower.c \
	sqrt.c \
	error.c \
	erf.c \
	resampleLayers.c \
	resample_sld.c \
	interp1.c \
	mean.c \
	callReflectivity.c \
	abeles.c \
	chiSquared.c \
	_coder_standardTF_custlay_single_info.c \
	_coder_standardTF_custlay_single_api.c \
	_coder_standardTF_custlay_single_mex.c \
	standardTF_custlay_single_emxutil.c

MEX_FILE_NAME_WO_EXT = standardTF_custlay_single_mex
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexa64
TARGET = $(MEX_FILE_NAME)

_LIBS = "/usr/local/MATLAB/R2015b/bin/glnxa64/libeng.so" "/usr/local/MATLAB/R2015b/bin/glnxa64/libmx.so" 
SYS_LIBS = $(_LIBS) 


#
#====================================================================
# gmake makefile fragment for building MEX functions using Unix
# Copyright 2007-2016 The MathWorks, Inc.
#====================================================================
#

ifndef CC
  ifeq ($(Arch),maci64)
    CC = clang
  else
    CC = gcc
  endif  
endif

ifndef CXX
  ifeq ($(Arch),maci64)
    CXX = clang++
  else
    CXX = g++
  endif  
endif

OBJEXT = o
.SUFFIXES: .$(OBJEXT)

OBJLISTC = $(SRC_FILES:.c=.$(OBJEXT))
OBJLISTCPP  = $(OBJLISTC:.cpp=.$(OBJEXT))
OBJLIST  = $(OBJLISTCPP:.cu=.$(OBJEXT))

target: $(TARGET)

ML_INCLUDES = -I "$(MATLAB_ROOT)/simulink/include"
ML_INCLUDES+= -I "$(MATLAB_ROOT)/toolbox/shared/simtargets"
SYS_INCLUDE = $(ML_INCLUDES)

# Additional includes

SYS_INCLUDE += -I "$(START_DIR)"
SYS_INCLUDE += -I "/usr/local/MATLAB/R2015b/extern/include"
SYS_INCLUDE += -I "/usr/include/openmpi"
SYS_INCLUDE += -I "$(START_DIR)/codegen/mex/standardTF_custlay_single"
SYS_INCLUDE += -I "./interface"
SYS_INCLUDE += -I "/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src"
SYS_INCLUDE += -I "$(MATLAB_ROOT)/extern/include"
SYS_INCLUDE += -I "."

EML_LIBS = -lemlrt -lcovrt -lut -lmwmathutil 
SYS_LIBS += $(CLIBS) $(EML_LIBS)


EXPORTFILE = $(MEX_FILE_NAME_WO_EXT)_mex.map
ifeq ($(Arch),maci)
  EXPORTOPT = -Wl,-exported_symbols_list,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS)
  CXX_FLAGS = -c $(CXXFLAGS)
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS))
else ifeq ($(Arch),maci64)
  EXPORTOPT = -Wl,-exported_symbols_list,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS)
  CXX_FLAGS = -c $(CXXFLAGS)
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS)) -Wl,-rpath,@loader_path
else
  EXPORTOPT = -Wl,--version-script,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS) $(OMPFLAGS)
  CXX_FLAGS = -c $(CXXFLAGS) $(OMPFLAGS)
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS)) 
endif
LINK_FLAGS += $(OMPLINKFLAGS)
ifeq ($(Arch),maci)
  LINK_FLAGS += -L$(MATLAB_ROOT)/sys/os/maci
endif
ifeq ($(EMC_CONFIG),optim)
  ifeq ($(Arch),mac)
    COMP_FLAGS += $(CDEBUGFLAGS)
    CXX_FLAGS += $(CXXDEBUGFLAGS)
  else
    COMP_FLAGS += $(COPTIMFLAGS)
    CXX_FLAGS += $(CXXOPTIMFLAGS)
  endif
  LINK_FLAGS += $(LDOPTIMFLAGS)
else
  COMP_FLAGS += $(CDEBUGFLAGS)
  CXX_FLAGS += $(CXXDEBUGFLAGS)
  LINK_FLAGS += $(LDDEBUGFLAGS)
endif
LINK_FLAGS += -o $(TARGET)
LINK_FLAGS += 

CCFLAGS = $(COMP_FLAGS)   $(USER_INCLUDE) $(SYS_INCLUDE)
CPPFLAGS = $(CXX_FLAGS) -std=c++11   $(USER_INCLUDE) $(SYS_INCLUDE)

%.$(OBJEXT) : %.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : %.cpp
	$(CXX) $(CPPFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : /%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)/%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)/codegen/mex/standardTF_custlay_single/%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : interface/%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : /home/arwel/eclipseWorkspace_new/matlabEngine_demo/src/%.c
	$(CC) $(CCFLAGS) "$<"



%.$(OBJEXT) : /%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)/%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)/codegen/mex/standardTF_custlay_single/%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : interface/%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : /home/arwel/eclipseWorkspace_new/matlabEngine_demo/src/%.cu
	$(CC) $(CCFLAGS) "$<"



%.$(OBJEXT) : /%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)/codegen/mex/standardTF_custlay_single/%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : interface/%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : /home/arwel/eclipseWorkspace_new/matlabEngine_demo/src/%.cpp
	$(CXX) $(CPPFLAGS) "$<"



$(TARGET): $(OBJLIST) $(MAKEFILE)
	$(LD) $(EXPORTOPT) $(OBJLIST) $(LINK_FLAGS) $(SYS_LIBS)

#====================================================================

