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
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_mexutil.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtBCInfo ne_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  11,                                  // lineNo
  24,                                  // colNo
  "thisContrastLayers",                // aName
  "allocateLayersForContrast",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo oe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  17,                                  // colNo
  "outParameterisedLayers",            // aName
  "allocateLayersForContrast",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo qb_emlrtDCI = { 10, // lineNo
  17,                                  // colNo
  "allocateLayersForContrast",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo pe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  17,                                  // colNo
  "contrastLayers",                    // aName
  "allocateLayersForContrast",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo qg_emlrtRTEI = { 7,// lineNo
  1,                                   // colNo
  "allocateLayersForContrast",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m"// pName 
};

// Function Definitions
void allocateLayersForContrast(const emlrtStack *sp, const coder::array<real_T,
  2U> &contrastLayers, const coder::array<cell_wrap_15, 2U>
  &outParameterisedLayers, coder::array<real_T, 2U> &thisContrastLayers)
{
  int32_T loop_ub;
  int32_T i;

  //  Take the layers list for a contrast and build an
  //  array of real valued layers
  thisContrastLayers.set_size((&qg_emlrtRTEI), sp, contrastLayers.size(1), 5);
  loop_ub = contrastLayers.size(1) * 5;
  for (i = 0; i < loop_ub; i++) {
    thisContrastLayers[i] = 0.0;
  }

  i = contrastLayers.size(1);
  for (int32_T b_i = 0; b_i < i; b_i++) {
    int32_T i1;
    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > thisContrastLayers.size(0))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, thisContrastLayers.size(0),
        &ne_emlrtBCI, sp);
    }

    loop_ub = outParameterisedLayers.size(1) - 1;
    i1 = b_i + 1;
    for (int32_T i2 = 0; i2 < 5; i2++) {
      real_T d;
      int32_T i3;
      if ((i1 < 1) || (i1 > contrastLayers.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, contrastLayers.size(1),
          &pe_emlrtBCI, sp);
      }

      d = contrastLayers[i1 - 1];
      if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
        emlrtIntegerCheckR2012b(d, &qb_emlrtDCI, sp);
      }

      i3 = static_cast<int32_T>(d) - 1;
      if ((i3 < 0) || (i3 > loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(i3, 0, loop_ub, &oe_emlrtBCI, sp);
      }

      thisContrastLayers[b_i + thisContrastLayers.size(0) * i2] =
        outParameterisedLayers[i3].f1[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

// End of code generation (allocateLayersForContrast.cpp)
