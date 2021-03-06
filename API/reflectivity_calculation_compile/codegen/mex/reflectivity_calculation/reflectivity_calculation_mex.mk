MATLAB_ROOT = /usr/local/MATLAB/R2018b
MAKEFILE = reflectivity_calculation_mex.mk

include reflectivity_calculation_mex.mki


SRC_FILES =  \
	/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabCallFun.c \
	/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabCallFun.h \
	reflectivity_calculation_mexutil.c \
	reflectivity_calculation_data.c \
	reflectivity_calculation_initialize.c \
	reflectivity_calculation_terminate.c \
	reflectivity_calculation.c \
	eml_int_forloop_overflow_check.c \
	standardTF_reflectivityCalculation.c \
	standardTF_stanLay_reflectivityCalculation.c \
	standardTF_stanlay_single.c \
	allocateParamsToLayers.c \
	allocateLayersForContrast.c \
	groupLayers_Mod.c \
	makeSLDProfiles.c \
	makeSLDProfileXY.c \
	sum.c \
	combineVectorElements.c \
	asymconvstep.c \
	sqrt.c \
	error.c \
	erf.c \
	resampleLayers.c \
	resample_sld.c \
	indexShapeCheck.c \
	interp1.c \
	shiftdata.c \
	callReflectivity.c \
	abeles.c \
	chiSquared.c \
	standardTF_stanlay_parallel.c \
	standardTF_custLay_reflectivityCalculation.c \
	standardTF_custlay_single.c \
	_coder_reflectivity_calculation_info.c \
	_coder_reflectivity_calculation_api.c \
	_coder_reflectivity_calculation_mex.c \
	reflectivity_calculation_emxutil.c \
	c_mexapi_version.c

MEX_FILE_NAME_WO_EXT = reflectivity_calculation_mex
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexa64
TARGET = $(MEX_FILE_NAME)

_LIBS = "$(MATLAB_ROOT)/bin/glnxa64/libeng.so" "$(MATLAB_ROOT)/bin/glnxa64/libmx.so" 
SYS_LIBS = $(_LIBS) 


#
#====================================================================
# gmake makefile fragment for building MEX functions using Unix
# Copyright 2007-2016 The MathWorks, Inc.
#====================================================================
#

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

SYS_INCLUDE += -I "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/codegen/mex/reflectivity_calculation"
SYS_INCLUDE += -I "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation"
SYS_INCLUDE += -I "$(MATLAB_ROOT)/extern/include"
SYS_INCLUDE += -I "./interface"
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

CCFLAGS = $(COMP_FLAGS) -std=c99   $(USER_INCLUDE) $(SYS_INCLUDE)
CPPFLAGS = $(CXX_FLAGS) -std=c++11   $(USER_INCLUDE) $(SYS_INCLUDE)

%.$(OBJEXT) : %.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : %.cpp
	$(CXX) $(CPPFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : /home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : /home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/codegen/mex/reflectivity_calculation/%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : interface/%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : /home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/%.c
	$(CC) $(CCFLAGS) "$<"



%.$(OBJEXT) : /home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : /home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/codegen/mex/reflectivity_calculation/%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : interface/%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : /home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/%.cpp
	$(CXX) $(CPPFLAGS) "$<"



%.$(OBJEXT) : /home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : /home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/codegen/mex/reflectivity_calculation/%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : interface/%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : /home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/%.cu
	$(CC) $(CCFLAGS) "$<"




$(TARGET): $(OBJLIST) $(MAKEFILE)
	$(LD) $(EXPORTOPT) $(OBJLIST) $(LINK_FLAGS) $(SYS_LIBS)

#====================================================================

