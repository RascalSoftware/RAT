###########################################################################
## Makefile generated for MATLAB file/project 'reflectivity_calculation'. 
## 
## Makefile     : reflectivity_calculation_rtw.mk
## Generated on : Wed Feb 24 09:21:41 2021
## MATLAB Coder version: 5.0 (R2020a)
## 
## Build Info:
## 
## Final product: ./reflectivity_calculation.so
## Product type : dynamic-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# DEF_FILE                Definition file

PRODUCT_NAME              = reflectivity_calculation
MAKEFILE                  = reflectivity_calculation_rtw.mk
MATLAB_ROOT               = /usr/local/MATLAB/R2020a
MATLAB_BIN                = /usr/local/MATLAB/R2020a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
MASTER_ANCHOR_DIR         = 
START_DIR                 = /home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation_compile/codegen/dll/reflectivity_calculation
TGT_FCN_LIB               = None
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
DEF_FILE                  = $(PRODUCT_NAME).def
C_STANDARD_OPTS           = -fwrapv -ansi -pedantic -Wno-long-long
CPP_STANDARD_OPTS         = -fwrapv -std=c++03 -pedantic -Wno-long-long

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU gcc/g++ | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   2020a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = g++

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(C_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)"
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./reflectivity_calculation.so
PRODUCT_TYPE = "dynamic-library"
BUILD_TYPE = "Dynamic Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation_compile -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DBUILDING_REFLECTIVITY_CALCULATION -DMODEL=reflectivity_calculation
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=reflectivity_calculation

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/rt_nonfinite.cpp $(START_DIR)/rtGetNaN.cpp $(START_DIR)/rtGetInf.cpp $(START_DIR)/reflectivity_calculation_rtwutil.cpp $(START_DIR)/reflectivity_calculation_data.cpp $(START_DIR)/reflectivity_calculation_initialize.cpp $(START_DIR)/reflectivity_calculation_terminate.cpp $(START_DIR)/reflectivity_calculation.cpp $(START_DIR)/standardTF_stanLay_reflectivityCalculation.cpp $(START_DIR)/allocateParamsToLayers.cpp $(START_DIR)/backSort.cpp $(START_DIR)/allocateLayersForContrast.cpp $(START_DIR)/standardTF_layers_core.cpp $(START_DIR)/groupLayers_Mod.cpp $(START_DIR)/makeSLDProfileXY.cpp $(START_DIR)/sqrt.cpp $(START_DIR)/applyScalarFunction.cpp $(START_DIR)/resampleLayers.cpp $(START_DIR)/adaptive.cpp $(START_DIR)/sldFunc.cpp $(START_DIR)/sortLE.cpp $(START_DIR)/shiftdata.cpp $(START_DIR)/callReflectivity.cpp $(START_DIR)/abeles_single.cpp $(START_DIR)/chiSquared.cpp $(START_DIR)/abeles_paraPoints.cpp $(START_DIR)/resolution_polly_paraPoints.cpp $(START_DIR)/standardTF_stanlay_paraContrasts.cpp $(START_DIR)/standardTF_stanlay_paraAll.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = rt_nonfinite.o rtGetNaN.o rtGetInf.o reflectivity_calculation_rtwutil.o reflectivity_calculation_data.o reflectivity_calculation_initialize.o reflectivity_calculation_terminate.o reflectivity_calculation.o standardTF_stanLay_reflectivityCalculation.o allocateParamsToLayers.o backSort.o allocateLayersForContrast.o standardTF_layers_core.o groupLayers_Mod.o makeSLDProfileXY.o sqrt.o applyScalarFunction.o resampleLayers.o adaptive.o sldFunc.o sortLE.o shiftdata.o callReflectivity.o abeles_single.o chiSquared.o abeles_paraPoints.o resolution_polly_paraPoints.o standardTF_stanlay_paraContrasts.o standardTF_stanlay_paraAll.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -L"$(MATLAB_ROOT)/sys/os/glnxa64" -lm -lstdc++ -liomp5

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ = -fvisibility=hidden
CFLAGS_OPTS = -fopenmp
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_) $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ = -fvisibility=hidden
CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_) $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#----------------------------------------
# Create a dynamic library
#----------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating dynamic library "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_SHAREDLIB_LDFLAGS) -o $(PRODUCT) $(OBJS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : /home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation_compile/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : /home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation_compile/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reflectivity_calculation_rtwutil.o : $(START_DIR)/reflectivity_calculation_rtwutil.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reflectivity_calculation_data.o : $(START_DIR)/reflectivity_calculation_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reflectivity_calculation_initialize.o : $(START_DIR)/reflectivity_calculation_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reflectivity_calculation_terminate.o : $(START_DIR)/reflectivity_calculation_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reflectivity_calculation.o : $(START_DIR)/reflectivity_calculation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_stanLay_reflectivityCalculation.o : $(START_DIR)/standardTF_stanLay_reflectivityCalculation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


allocateParamsToLayers.o : $(START_DIR)/allocateParamsToLayers.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


backSort.o : $(START_DIR)/backSort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


allocateLayersForContrast.o : $(START_DIR)/allocateLayersForContrast.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_layers_core.o : $(START_DIR)/standardTF_layers_core.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


groupLayers_Mod.o : $(START_DIR)/groupLayers_Mod.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


makeSLDProfileXY.o : $(START_DIR)/makeSLDProfileXY.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sqrt.o : $(START_DIR)/sqrt.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


applyScalarFunction.o : $(START_DIR)/applyScalarFunction.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


resampleLayers.o : $(START_DIR)/resampleLayers.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


adaptive.o : $(START_DIR)/adaptive.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sldFunc.o : $(START_DIR)/sldFunc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortLE.o : $(START_DIR)/sortLE.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


shiftdata.o : $(START_DIR)/shiftdata.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


callReflectivity.o : $(START_DIR)/callReflectivity.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


abeles_single.o : $(START_DIR)/abeles_single.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


chiSquared.o : $(START_DIR)/chiSquared.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


abeles_paraPoints.o : $(START_DIR)/abeles_paraPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


resolution_polly_paraPoints.o : $(START_DIR)/resolution_polly_paraPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_stanlay_paraContrasts.o : $(START_DIR)/standardTF_stanlay_paraContrasts.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_stanlay_paraAll.o : $(START_DIR)/standardTF_stanlay_paraAll.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


