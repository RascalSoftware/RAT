//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  allocateParamsToLayers.cpp
//
//  Code generation for function 'allocateParamsToLayers'
//


// Include files
#include "allocateParamsToLayers.h"
#include "allocateLayersForContrast.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtBCInfo td_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  14,                                  // lineNo
  29,                                  // colNo
  "thisLayer",                         // aName
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ud_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  12,                                  // lineNo
  31,                                  // colNo
  "layersDetails",                     // aName
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo vd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  16,                                  // lineNo
  31,                                  // colNo
  "params",                            // aName
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo s_emlrtDCI = { 16,  // lineNo
  31,                                  // colNo
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo wd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  21,                                  // lineNo
  39,                                  // colNo
  "thisLayer",                         // aName
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xd_emlrtBCI = { 1,  // iFirst
  5,                                   // iLast
  21,                                  // lineNo
  5,                                   // colNo
  "thisOutLayer",                      // aName
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",// pName 
  3                                    // checkKind
};

static emlrtBCInfo yd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  22,                                  // lineNo
  5,                                   // colNo
  "outLayers",                         // aName
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo se_emlrtRTEI = { 9,// lineNo
  20,                                  // colNo
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m"// pName 
};

// Function Definitions
void allocateParamsToLayers(const emlrtStack *sp, const coder::array<real_T, 2U>
  &params, const coder::array<cell_wrap_12, 1U> &layersDetails, coder::array<
  cell_wrap_17, 2U> &outLayers)
{
  int32_T i;
  real_T thisOutLayer[5];

  // This function takes the list of all layers (in terms of parameter
  // numbers) in layersDetails, and loops through putting in the correct
  // parameter value from the parameter array in each layer.
  for (i = 0; i < 5; i++) {
    thisOutLayer[i] = 0.0;
  }

  outLayers.set_size((&se_emlrtRTEI), sp, 1, layersDetails.size(0));
  i = layersDetails.size(0);
  for (int32_T b_i = 0; b_i < i; b_i++) {
    int32_T i1;
    int32_T n;
    int32_T i2;
    i1 = layersDetails.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ud_emlrtBCI, sp);
    }

    if ((layersDetails[b_i].f1.size(0) == 0) || (layersDetails[b_i].f1.size(1) ==
         0)) {
      n = 0;
    } else if (layersDetails[b_i].f1.size(0) > layersDetails[b_i].f1.size(1)) {
      n = layersDetails[b_i].f1.size(0);
    } else {
      n = layersDetails[b_i].f1.size(1);
    }

    for (int32_T b_n = 0; b_n <= n - 2; b_n++) {
      i1 = layersDetails[b_i].f1.size(0) * layersDetails[b_i].f1.size(1);
      i2 = b_n + 1;
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &td_emlrtBCI, sp);
      }

      if (!muDoubleScalarIsNaN(layersDetails[b_i].f1[b_n])) {
        if (layersDetails[b_i].f1[b_n] != static_cast<int32_T>
            (muDoubleScalarFloor(layersDetails[b_i].f1[b_n]))) {
          emlrtIntegerCheckR2012b(layersDetails[b_i].f1[b_n], &s_emlrtDCI, sp);
        }

        i1 = static_cast<int32_T>(layersDetails[b_i].f1[b_n]);
        if ((i1 < 1) || (i1 > params.size(1))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, params.size(1), &vd_emlrtBCI, sp);
        }

        thisOutLayer[b_n] = params[i1 - 1];
      } else {
        thisOutLayer[b_n] = rtNaN;
      }
    }

    if ((layersDetails[b_i].f1.size(0) == 0) || (layersDetails[b_i].f1.size(1) ==
         0)) {
      n = 0;
    } else if (layersDetails[b_i].f1.size(0) > layersDetails[b_i].f1.size(1)) {
      n = layersDetails[b_i].f1.size(0);
    } else {
      n = layersDetails[b_i].f1.size(1);
    }

    i1 = layersDetails[b_i].f1.size(0) * layersDetails[b_i].f1.size(1);
    i2 = layersDetails[b_i].f1.size(0) * layersDetails[b_i].f1.size(1);
    if ((i2 < 1) || (i2 > i1)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &wd_emlrtBCI, sp);
    }

    if ((n < 1) || (n > 5)) {
      emlrtDynamicBoundsCheckR2012b(n, 1, 5, &xd_emlrtBCI, sp);
    }

    thisOutLayer[n - 1] = layersDetails[b_i].f1[i2 - 1];
    i1 = outLayers.size(1) - 1;
    for (i2 = 0; i2 < 5; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yd_emlrtBCI, sp);
      }

      outLayers[b_i].f1[i2] = thisOutLayer[i2];
    }
  }
}

// End of code generation (allocateParamsToLayers.cpp)
