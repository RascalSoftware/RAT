//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  resampleLayers.cpp
//
//  Code generation for function 'resampleLayers'
//


// Include files
#include "resampleLayers.h"
#include "adaptive.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_mexutil.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo ed_emlrtRSI = { 18, // lineNo
  "resampleLayers",                    // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"// pathName 
};

static emlrtBCInfo if_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  11,                                  // lineNo
  12,                                  // colNo
  "x",                                 // aName
  "resampleLayers",                    // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  12,                                  // lineNo
  10,                                  // colNo
  "x",                                 // aName
  "resampleLayers",                    // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  27,                                  // lineNo
  18,                                  // colNo
  "newX",                              // aName
  "resampleLayers",                    // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo lf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  28,                                  // lineNo
  18,                                  // colNo
  "newX",                              // aName
  "resampleLayers",                    // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo mf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  29,                                  // lineNo
  18,                                  // colNo
  "newY",                              // aName
  "resampleLayers",                    // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo nf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  30,                                  // lineNo
  18,                                  // colNo
  "newY",                              // aName
  "resampleLayers",                    // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo of_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  39,                                  // lineNo
  12,                                  // colNo
  "layers",                            // aName
  "resampleLayers",                    // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo yb_emlrtDCI = { 23, // lineNo
  16,                                  // colNo
  "resampleLayers",                    // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",// pName 
  4                                    // checkKind
};

static emlrtRTEInfo sh_emlrtRTEI = { 18,// lineNo
  1,                                   // colNo
  "resampleLayers",                    // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"// pName 
};

static emlrtRTEInfo th_emlrtRTEI = { 23,// lineNo
  1,                                   // colNo
  "resampleLayers",                    // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"// pName 
};

// Function Definitions
void resampleLayers(const emlrtStack *sp, const coder::array<real_T, 2U>
                    &sldProfile, coder::array<real_T, 2U> &newSLD)
{
  real_T b_sldProfile[2];
  cell_17 expl_temp;
  coder::array<real_T, 2U> out_f1;
  int32_T loop_ub;
  int32_T i;
  real_T thisLayRho;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  //  Function handle for adaptive resampling
  //  f = @(x) sldFunc(x);
  //
  if (1 > sldProfile.size(0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, sldProfile.size(0), &if_emlrtBCI, sp);
  }

  if (sldProfile.size(0) < 1) {
    emlrtDynamicBoundsCheckR2012b(sldProfile.size(0), 1, sldProfile.size(0),
      &jf_emlrtBCI, sp);
  }

  //  Keep points and minangle as constants for now
  //  will fix later
  b_sldProfile[0] = sldProfile[0];
  b_sldProfile[1] = sldProfile[sldProfile.size(0) - 1];
  st.site = &ed_emlrtRSI;
  adaptive(&st, sldProfile, b_sldProfile, &expl_temp);
  out_f1.set_size((&sh_emlrtRTEI), sp, expl_temp.f1.size(0), 2);
  loop_ub = expl_temp.f1.size(0) * expl_temp.f1.size(1);
  for (i = 0; i < loop_ub; i++) {
    out_f1[i] = expl_temp.f1[i];
  }

  if (out_f1.size(0) == 0) {
    loop_ub = -1;
  } else if (out_f1.size(0) > 1) {
    loop_ub = out_f1.size(0) - 1;
  } else {
    loop_ub = 0;
  }

  if (loop_ub < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(loop_ub), &yb_emlrtDCI, sp);
  }

  newSLD.set_size((&th_emlrtRTEI), sp, loop_ub, 3);
  loop_ub *= 3;
  for (i = 0; i < loop_ub; i++) {
    newSLD[i] = 0.0;
  }

  //  Now build a layer model from these resampled points
  if (out_f1.size(0) == 0) {
    loop_ub = -2;
  } else if (out_f1.size(0) > 1) {
    loop_ub = out_f1.size(0) - 2;
  } else {
    loop_ub = -1;
  }

  for (int32_T n = 0; n <= loop_ub; n++) {
    int32_T i1;
    i = n + 1;
    if ((i < 1) || (i > out_f1.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, out_f1.size(0), &kf_emlrtBCI, sp);
    }

    i = static_cast<int32_T>((static_cast<real_T>(n) + 1.0) + 1.0);
    if ((i < 1) || (i > out_f1.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, out_f1.size(0), &lf_emlrtBCI, sp);
    }

    i1 = n + 1;
    if ((i1 < 1) || (i1 > out_f1.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, out_f1.size(0), &mf_emlrtBCI, sp);
    }

    if (i > out_f1.size(0)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, out_f1.size(0), &nf_emlrtBCI, sp);
    }

    thisLayRho = out_f1[(n + out_f1.size(0)) + 1];
    if (thisLayRho > out_f1[n + out_f1.size(0)]) {
      thisLayRho = (thisLayRho - out_f1[n + out_f1.size(0)]) / 2.0 + out_f1[n +
        out_f1.size(0)];
    } else {
      thisLayRho += (out_f1[n + out_f1.size(0)] - thisLayRho) / 2.0;
    }

    i = n + 1;
    if ((i < 1) || (i > newSLD.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, newSLD.size(0), &of_emlrtBCI, sp);
    }

    newSLD[n] = out_f1[n + 1] - out_f1[n];
    newSLD[n + newSLD.size(0)] = thisLayRho;
    newSLD[n + newSLD.size(0) * 2] = 2.2204460492503131E-16;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (resampleLayers.cpp)
