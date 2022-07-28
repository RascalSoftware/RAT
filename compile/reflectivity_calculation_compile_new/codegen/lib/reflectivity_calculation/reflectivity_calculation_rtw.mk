###########################################################################
## Makefile generated for component 'reflectivity_calculation'. 
## 
## Makefile     : reflectivity_calculation_rtw.mk
## Generated on : Thu Jul 28 15:24:38 2022
## Final product: ./reflectivity_calculation.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = reflectivity_calculation
MAKEFILE                  = reflectivity_calculation_rtw.mk
MATLAB_ROOT               = /Applications/MATLAB_R2021a.app
MATLAB_BIN                = /Applications/MATLAB_R2021a.app/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/maci64
START_DIR                 = /Users/arwel/Documents/coding/RAT/compile/reflectivity_calculation_compile_new/codegen/lib/reflectivity_calculation
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
C_STANDARD_OPTS           = -fno-common -fexceptions
CPP_STANDARD_OPTS         = -std=c++14 -fno-common -fexceptions
MODELLIB                  = reflectivity_calculation.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Clang v3.1 | gmake (64-bit Mac)
# Supported Version(s):    3.1
# ToolchainInfo Version:   2021a
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

ARCHS             = x86_64
XCODE_SDK_VER     = $(shell perl $(MATLAB_ROOT)/rtw/c/tools/macsdkver.pl)
XCODE_SDK         = MacOSX$(XCODE_SDK_VER).sdk
XCODE_DEVEL_DIR   = $(shell xcode-select -print-path)
XCODE_SDK_ROOT    = $(XCODE_DEVEL_DIR)/Platforms/MacOSX.platform/Developer/SDKs/$(XCODE_SDK)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Clang C Compiler
CC = xcrun clang

# Linker: Clang Linker
LD = xcrun clang++

# C++ Compiler: Clang C++ Compiler
CPP = xcrun clang++

# C++ Linker: Clang C++ Linker
CPP_LD = xcrun clang++

# Archiver: Clang Archiver
AR = xcrun ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/maci64
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
CFLAGS               = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(C_STANDARD_OPTS) -mmacosx-version-min=10.14 \
                       -O3
CPPFLAGS             = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(CPP_STANDARD_OPTS) -mmacosx-version-min=10.14 \
                       -O3
CPP_LDFLAGS          = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,$(MATLAB_ARCH_BIN) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR)
CPP_SHAREDLIB_LDFLAGS  = -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) \
                         -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,$(MATLAB_ARCH_BIN) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) \
                       -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./reflectivity_calculation.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I/Users/arwel/Documents/coding/RAT/compile/reflectivity_calculation_compile_new -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=reflectivity_calculation

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/reflectivity_calculation_data.cpp $(START_DIR)/rt_nonfinite.cpp $(START_DIR)/rtGetNaN.cpp $(START_DIR)/rtGetInf.cpp $(START_DIR)/reflectivity_calculation_initialize.cpp $(START_DIR)/reflectivity_calculation_terminate.cpp $(START_DIR)/reflectivity_calculation.cpp $(START_DIR)/strcmp.cpp $(START_DIR)/standardTF_reflectivityCalculation.cpp $(START_DIR)/lower.cpp $(START_DIR)/standardTF_stanLay_reflectivityCalculation.cpp $(START_DIR)/standardTF_stanlay_single.cpp $(START_DIR)/allocateParamsToLayers.cpp $(START_DIR)/length.cpp $(START_DIR)/backSort.cpp $(START_DIR)/allocateLayersForContrast.cpp $(START_DIR)/standardTF_layers_core.cpp $(START_DIR)/groupLayers_Mod.cpp $(START_DIR)/makeSLDProfiles.cpp $(START_DIR)/makeSLDProfileXY.cpp $(START_DIR)/blockedSummation.cpp $(START_DIR)/asymconvstep.cpp $(START_DIR)/erf.cpp $(START_DIR)/eml_erfcore.cpp $(START_DIR)/log2.cpp $(START_DIR)/minOrMax.cpp $(START_DIR)/resampleLayers.cpp $(START_DIR)/linspace.cpp $(START_DIR)/adaptive_new.cpp $(START_DIR)/sldFunc.cpp $(START_DIR)/find.cpp $(START_DIR)/relop.cpp $(START_DIR)/repmat.cpp $(START_DIR)/power.cpp $(START_DIR)/complexTimes.cpp $(START_DIR)/allOrAny.cpp $(START_DIR)/sortIdx.cpp $(START_DIR)/sortLE.cpp $(START_DIR)/sortAscendLE.cpp $(START_DIR)/shiftdata.cpp $(START_DIR)/callReflectivity.cpp $(START_DIR)/colon.cpp $(START_DIR)/abeles_single.cpp $(START_DIR)/data_resolution_polly.cpp $(START_DIR)/resolution_polly.cpp $(START_DIR)/chiSquared.cpp $(START_DIR)/standardTF_stanlay_paraPoints.cpp $(START_DIR)/abeles_paraPoints.cpp $(START_DIR)/standardTF_stanlay_paraContrasts.cpp $(START_DIR)/standardTF_custLay_reflectivityCalculation.cpp $(START_DIR)/standardTF_custlay_single.cpp $(START_DIR)/loopMatalbCustlayWrapper_CustLaysingle.cpp $(START_DIR)/loopCppCustlayWrapper_CustLaysingle.cpp $(START_DIR)/standardTF_custlay_paraPoints.cpp $(START_DIR)/standardTF_custlay_paraContrasts.cpp $(START_DIR)/loopMatalbCustlayWrapper_CustLaycontrast.cpp $(START_DIR)/loopCppCustlayWrapper_CustLaycontrast.cpp $(START_DIR)/standardTF_custXY_reflectivityCalculation.cpp $(START_DIR)/standardTF_custXY_single.cpp $(START_DIR)/loopMatalbCustlayWrapper_XYSingle.cpp $(START_DIR)/standardTF_custXY_paraPoints.cpp $(START_DIR)/standardTF_custXY_paraContrasts.cpp $(START_DIR)/nullAssignment.cpp $(START_DIR)/acos.cpp $(START_DIR)/sqrt.cpp $(START_DIR)/asinh.cpp $(START_DIR)/log1p.cpp $(START_DIR)/sortrows.cpp $(START_DIR)/mergesort.cpp $(START_DIR)/exp.cpp $(START_DIR)/applyBackgroundCorrection.cpp $(START_DIR)/reflectivity_calculation_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = reflectivity_calculation_data.o rt_nonfinite.o rtGetNaN.o rtGetInf.o reflectivity_calculation_initialize.o reflectivity_calculation_terminate.o reflectivity_calculation.o strcmp.o standardTF_reflectivityCalculation.o lower.o standardTF_stanLay_reflectivityCalculation.o standardTF_stanlay_single.o allocateParamsToLayers.o length.o backSort.o allocateLayersForContrast.o standardTF_layers_core.o groupLayers_Mod.o makeSLDProfiles.o makeSLDProfileXY.o blockedSummation.o asymconvstep.o erf.o eml_erfcore.o log2.o minOrMax.o resampleLayers.o linspace.o adaptive_new.o sldFunc.o find.o relop.o repmat.o power.o complexTimes.o allOrAny.o sortIdx.o sortLE.o sortAscendLE.o shiftdata.o callReflectivity.o colon.o abeles_single.o data_resolution_polly.o resolution_polly.o chiSquared.o standardTF_stanlay_paraPoints.o abeles_paraPoints.o standardTF_stanlay_paraContrasts.o standardTF_custLay_reflectivityCalculation.o standardTF_custlay_single.o loopMatalbCustlayWrapper_CustLaysingle.o loopCppCustlayWrapper_CustLaysingle.o standardTF_custlay_paraPoints.o standardTF_custlay_paraContrasts.o loopMatalbCustlayWrapper_CustLaycontrast.o loopCppCustlayWrapper_CustLaycontrast.o standardTF_custXY_reflectivityCalculation.o standardTF_custXY_single.o loopMatalbCustlayWrapper_XYSingle.o standardTF_custXY_paraPoints.o standardTF_custXY_paraContrasts.o nullAssignment.o acos.o sqrt.o asinh.o log1p.o sortrows.o mergesort.o exp.o applyBackgroundCorrection.o reflectivity_calculation_rtwutil.o

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

SYSTEM_LIBS =  -L"$(MATLAB_ROOT)/sys/os/maci64" -lm -lstdc++ -liomp5

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -Xpreprocessor -fopenmp -I/Applications/MATLAB_R2021a.app/toolbox/eml/externalDependency/omp/maci64/include -DOpenMP_omp_LIBRARY=/Applications/MATLAB_R2021a.app/sys/os/maci64/libiomp5.dylib
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -Xpreprocessor -fopenmp -I/Applications/MATLAB_R2021a.app/toolbox/eml/externalDependency/omp/maci64/include -DOpenMP_omp_LIBRARY=/Applications/MATLAB_R2021a.app/sys/os/maci64/libiomp5.dylib
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -Wl,-rpath,$(MATLAB_ROOT)/sys/os/$(ARCH)/  

CPP_LDFLAGS += $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -Wl,-rpath,$(MATLAB_ROOT)/sys/os/$(ARCH)/  

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = -Wl,-rpath,$(MATLAB_ROOT)/sys/os/$(ARCH)/  

LDFLAGS += $(LDFLAGS_)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -Wl,-rpath,$(MATLAB_ROOT)/sys/os/$(ARCH)/  

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

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

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
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


%.o : /Users/arwel/Documents/coding/RAT/compile/reflectivity_calculation_compile_new/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : /Users/arwel/Documents/coding/RAT/compile/reflectivity_calculation_compile_new/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reflectivity_calculation_data.o : $(START_DIR)/reflectivity_calculation_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reflectivity_calculation_initialize.o : $(START_DIR)/reflectivity_calculation_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reflectivity_calculation_terminate.o : $(START_DIR)/reflectivity_calculation_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reflectivity_calculation.o : $(START_DIR)/reflectivity_calculation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


strcmp.o : $(START_DIR)/strcmp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_reflectivityCalculation.o : $(START_DIR)/standardTF_reflectivityCalculation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


lower.o : $(START_DIR)/lower.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_stanLay_reflectivityCalculation.o : $(START_DIR)/standardTF_stanLay_reflectivityCalculation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_stanlay_single.o : $(START_DIR)/standardTF_stanlay_single.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


allocateParamsToLayers.o : $(START_DIR)/allocateParamsToLayers.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


length.o : $(START_DIR)/length.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


backSort.o : $(START_DIR)/backSort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


allocateLayersForContrast.o : $(START_DIR)/allocateLayersForContrast.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_layers_core.o : $(START_DIR)/standardTF_layers_core.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


groupLayers_Mod.o : $(START_DIR)/groupLayers_Mod.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


makeSLDProfiles.o : $(START_DIR)/makeSLDProfiles.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


makeSLDProfileXY.o : $(START_DIR)/makeSLDProfileXY.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


blockedSummation.o : $(START_DIR)/blockedSummation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


asymconvstep.o : $(START_DIR)/asymconvstep.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


erf.o : $(START_DIR)/erf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_erfcore.o : $(START_DIR)/eml_erfcore.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


log2.o : $(START_DIR)/log2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


minOrMax.o : $(START_DIR)/minOrMax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


resampleLayers.o : $(START_DIR)/resampleLayers.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linspace.o : $(START_DIR)/linspace.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


adaptive_new.o : $(START_DIR)/adaptive_new.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sldFunc.o : $(START_DIR)/sldFunc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find.o : $(START_DIR)/find.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


relop.o : $(START_DIR)/relop.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


repmat.o : $(START_DIR)/repmat.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


power.o : $(START_DIR)/power.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


complexTimes.o : $(START_DIR)/complexTimes.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


allOrAny.o : $(START_DIR)/allOrAny.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.o : $(START_DIR)/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortLE.o : $(START_DIR)/sortLE.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortAscendLE.o : $(START_DIR)/sortAscendLE.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


shiftdata.o : $(START_DIR)/shiftdata.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


callReflectivity.o : $(START_DIR)/callReflectivity.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


colon.o : $(START_DIR)/colon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


abeles_single.o : $(START_DIR)/abeles_single.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


data_resolution_polly.o : $(START_DIR)/data_resolution_polly.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


resolution_polly.o : $(START_DIR)/resolution_polly.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


chiSquared.o : $(START_DIR)/chiSquared.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_stanlay_paraPoints.o : $(START_DIR)/standardTF_stanlay_paraPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


abeles_paraPoints.o : $(START_DIR)/abeles_paraPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_stanlay_paraContrasts.o : $(START_DIR)/standardTF_stanlay_paraContrasts.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_custLay_reflectivityCalculation.o : $(START_DIR)/standardTF_custLay_reflectivityCalculation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_custlay_single.o : $(START_DIR)/standardTF_custlay_single.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


loopMatalbCustlayWrapper_CustLaysingle.o : $(START_DIR)/loopMatalbCustlayWrapper_CustLaysingle.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


loopCppCustlayWrapper_CustLaysingle.o : $(START_DIR)/loopCppCustlayWrapper_CustLaysingle.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_custlay_paraPoints.o : $(START_DIR)/standardTF_custlay_paraPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_custlay_paraContrasts.o : $(START_DIR)/standardTF_custlay_paraContrasts.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


loopMatalbCustlayWrapper_CustLaycontrast.o : $(START_DIR)/loopMatalbCustlayWrapper_CustLaycontrast.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


loopCppCustlayWrapper_CustLaycontrast.o : $(START_DIR)/loopCppCustlayWrapper_CustLaycontrast.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_custXY_reflectivityCalculation.o : $(START_DIR)/standardTF_custXY_reflectivityCalculation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_custXY_single.o : $(START_DIR)/standardTF_custXY_single.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


loopMatalbCustlayWrapper_XYSingle.o : $(START_DIR)/loopMatalbCustlayWrapper_XYSingle.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_custXY_paraPoints.o : $(START_DIR)/standardTF_custXY_paraPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


standardTF_custXY_paraContrasts.o : $(START_DIR)/standardTF_custXY_paraContrasts.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


nullAssignment.o : $(START_DIR)/nullAssignment.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


acos.o : $(START_DIR)/acos.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sqrt.o : $(START_DIR)/sqrt.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


asinh.o : $(START_DIR)/asinh.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


log1p.o : $(START_DIR)/log1p.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortrows.o : $(START_DIR)/sortrows.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mergesort.o : $(START_DIR)/mergesort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


exp.o : $(START_DIR)/exp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


applyBackgroundCorrection.o : $(START_DIR)/applyBackgroundCorrection.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reflectivity_calculation_rtwutil.o : $(START_DIR)/reflectivity_calculation_rtwutil.cpp
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


