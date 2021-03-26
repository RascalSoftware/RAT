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
  21,                                  // lineNo
  39,                                  // colNo
  "thisLayer",                         // aName
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo wd_emlrtBCI = { 1,  // iFirst
  5,                                   // iLast
  21,                                  // lineNo
  5,                                   // colNo
  "thisOutLayer",                      // aName
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",// pName 
  3                                    // checkKind
};

static emlrtBCInfo xd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  22,                                  // lineNo
  5,                                   // colNo
  "outLayers",                         // aName
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo yd_emlrtBCI = { -1, // iFirst
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

static emlrtRTEInfo qe_emlrtRTEI = { 9,// lineNo
  20,                                  // colNo
  "allocateParamsToLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m"// pName 
};

// Function Definitions
void allocateParamsToLayers(const emlrtStack *sp, const coder::array<real_T, 2U>
  &params, const coder::array<cell_wrap_3, 1U> &layersDetails, coder::array<
  cell_wrap_19, 2U> &outLayers)
{
  int32_T i;
  real_T thisOutLayer[5];

  // This function takes the list of all layers (in terms of parameter
  // numbers) in layersDetails, and loops through putting in the correct
  // parameter value from the parameter array in each layer.
  for (i = 0; i < 5; i++) {
    thisOutLayer[i] = 0.0;
  }

  outLayers.set_size((&qe_emlrtRTEI), sp, 1, layersDetails.size(0));
  i = layersDetails.size(0);
  for (int32_T b_i = 0; b_i < i; b_i++) {
    int32_T i1;
    int32_T i2;
    i1 = layersDetails.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ud_emlrtBCI, sp);
    }

    i1 = layersDetails[b_i].f1.size[1];
    for (int32_T n = 0; n <= i1 - 2; n++) {
      i2 = n + 1;
      if ((i2 < 1) || (i2 > layersDetails[b_i].f1.size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, layersDetails[b_i].f1.size[1],
          &td_emlrtBCI, sp);
      }

      if (!muDoubleScalarIsNaN(layersDetails[b_i].f1.data[n])) {
        real_T d;
        d = layersDetails[b_i].f1.data[n];
        if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
          emlrtIntegerCheckR2012b(d, &s_emlrtDCI, sp);
        }

        i2 = static_cast<int32_T>(d);
        if ((i2 < 1) || (i2 > params.size(1))) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, params.size(1), &yd_emlrtBCI, sp);
        }

        thisOutLayer[n] = params[i2 - 1];
      } else {
        thisOutLayer[n] = rtNaN;
      }
    }

    if (layersDetails[b_i].f1.size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(layersDetails[b_i].f1.size[1], 1,
        layersDetails[b_i].f1.size[1], &vd_emlrtBCI, sp);
    }

    if ((layersDetails[b_i].f1.size[1] < 1) || (layersDetails[b_i].f1.size[1] >
         5)) {
      emlrtDynamicBoundsCheckR2012b(layersDetails[b_i].f1.size[1], 1, 5,
        &wd_emlrtBCI, sp);
    }

    thisOutLayer[layersDetails[b_i].f1.size[1] - 1] = layersDetails[b_i]
      .f1.data[layersDetails[b_i].f1.size[1] - 1];
    i1 = outLayers.size(1) - 1;
    for (i2 = 0; i2 < 5; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xd_emlrtBCI, sp);
      }

      outLayers[b_i].f1[i2] = thisOutLayer[i2];
    }
  }
}

// End of code generation (allocateParamsToLayers.cpp)
