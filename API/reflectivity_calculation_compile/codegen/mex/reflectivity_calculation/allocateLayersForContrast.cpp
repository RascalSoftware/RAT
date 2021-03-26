//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  allocateLayersForContrast.cpp
//
//  Code generation for function 'allocateLayersForContrast'
//


// Include files
#include "allocateLayersForContrast.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtBCInfo ge_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  11,                                  // lineNo
  24,                                  // colNo
  "thisContrastLayers",                // aName
  "allocateLayersForContrast",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo he_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  17,                                  // colNo
  "outParameterisedLayers",            // aName
  "allocateLayersForContrast",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo ab_emlrtDCI = { 10, // lineNo
  17,                                  // colNo
  "allocateLayersForContrast",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo ie_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  17,                                  // colNo
  "contrastLayers",                    // aName
  "allocateLayersForContrast",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo re_emlrtRTEI = { 7,// lineNo
  1,                                   // colNo
  "allocateLayersForContrast",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m"// pName 
};

// Function Definitions
void allocateLayersForContrast(const emlrtStack *sp, const coder::array<real_T,
  2U> &contrastLayers, const coder::array<cell_wrap_19, 2U>
  &outParameterisedLayers, coder::array<real_T, 2U> &thisContrastLayers)
{
  int32_T n;
  int32_T i;

  //  Take the layers list for a contrast and build an
  //  array of real valued layers
  if ((contrastLayers.size(0) == 0) || (contrastLayers.size(1) == 0)) {
    n = 0;
  } else {
    n = contrastLayers.size(1);
  }

  thisContrastLayers.set_size((&re_emlrtRTEI), sp, n, 5);
  n *= 5;
  for (i = 0; i < n; i++) {
    thisContrastLayers[i] = 0.0;
  }

  if ((contrastLayers.size(0) == 0) || (contrastLayers.size(1) == 0)) {
    n = 0;
  } else {
    n = contrastLayers.size(1);
  }

  for (int32_T b_i = 0; b_i < n; b_i++) {
    int32_T i1;
    i = b_i + 1;
    if ((i < 1) || (i > thisContrastLayers.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, thisContrastLayers.size(0),
        &ge_emlrtBCI, sp);
    }

    i = outParameterisedLayers.size(1) - 1;
    i1 = b_i + 1;
    for (int32_T i2 = 0; i2 < 5; i2++) {
      int32_T i3;
      real_T d;
      i3 = contrastLayers.size(0) * contrastLayers.size(1);
      if ((i1 < 1) || (i1 > i3)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i3, &ie_emlrtBCI, sp);
      }

      d = contrastLayers[i1 - 1];
      if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
        emlrtIntegerCheckR2012b(d, &ab_emlrtDCI, sp);
      }

      i3 = static_cast<int32_T>(d) - 1;
      if ((i3 < 0) || (i3 > i)) {
        emlrtDynamicBoundsCheckR2012b(i3, 0, i, &he_emlrtBCI, sp);
      }

      thisContrastLayers[b_i + thisContrastLayers.size(0) * i2] =
        outParameterisedLayers[i3].f1[i2];
    }
  }
}

// End of code generation (allocateLayersForContrast.cpp)
