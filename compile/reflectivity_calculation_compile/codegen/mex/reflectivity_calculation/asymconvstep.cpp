//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  asymconvstep.cpp
//
//  Code generation for function 'asymconvstep'
//


// Include files
#include "asymconvstep.h"
#include "applyScalarFunction.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"

// Variable Definitions
static emlrtRSInfo wb_emlrtRSI = { 45, // lineNo
  "mpower",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/mpower.m"// pathName
};

static emlrtRSInfo cc_emlrtRSI = { 39, // lineNo
  "asymconvstep",                      // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"// pathName 
};

static emlrtRSInfo dc_emlrtRSI = { 40, // lineNo
  "asymconvstep",                      // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"// pathName 
};

static emlrtRSInfo ec_emlrtRSI = { 45, // lineNo
  "asymconvstep",                      // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"// pathName 
};

static emlrtRSInfo fc_emlrtRSI = { 9,  // lineNo
  "erf",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/erf.m"// pathName
};

static emlrtRSInfo gc_emlrtRSI = { 12, // lineNo
  "eml_erfcore",                       // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"// pathName 
};

static emlrtECInfo e_emlrtECI = { 2,   // nDims
  45,                                  // lineNo
  12,                                  // colNo
  "asymconvstep",                      // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"// pName 
};

static emlrtRTEInfo pf_emlrtRTEI = { 42,// lineNo
  5,                                   // colNo
  "asymconvstep",                      // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"// pName 
};

static emlrtRTEInfo qf_emlrtRTEI = { 43,// lineNo
  5,                                   // colNo
  "asymconvstep",                      // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"// pName 
};

static emlrtRTEInfo rf_emlrtRTEI = { 45,// lineNo
  1,                                   // colNo
  "asymconvstep",                      // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"// pName 
};

// Function Definitions
void asymconvstep(const emlrtStack *sp, const coder::array<real_T, 2U> &x,
                  real_T xw, real_T xcen, real_T s1, real_T s2, real_T h, coder::
                  array<real_T, 2U> &f)
{
  real_T r;
  real_T l;
  real_T aFactor;
  real_T bFactor;
  coder::array<real_T, 2U> b_x;
  int32_T loop_ub;
  int32_T i;
  coder::array<real_T, 2U> b_r;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  //  Produces a step function convoluted with differnt error functions
  //  on each side.
  //  Convstep (x,xw,xcen,s1,s2,h)
  //        x = vector of x values
  //       xw = Width of step function
  //     xcen = Centre point of step function
  //        s1 = Roughness parameter of left side
  //        s2 = Roughness parameter of right side
  //        h = Height of step function.
  //  if length(xw) > 1
  //      ME = MException('VerifyOutput:OutOfBounds', ...
  //               'xw must be single value');
  //      throw(ME);
  //  end
  //
  //  if length(xcen) > 1
  //      ME = MException('VerifyOutput:OutOfBounds', ...
  //               'xcen must be single value');
  //      throw(ME);
  //  end
  //
  //  if length(s1) > 1
  //      ME = MException('VerifyOutput:OutOfBounds', ...
  //               's1 must be single value');
  //      throw(ME);
  //  end
  //
  //  if length(s2) > 1
  //      ME = MException('VerifyOutput:OutOfBounds', ...
  //               's2 must be single value');
  //      throw(ME);
  //  end
  r = xcen + xw / 2.0;
  l = xcen - xw / 2.0;
  st.site = &cc_emlrtRSI;
  b_st.site = &wb_emlrtRSI;
  aFactor = 1.4142135623730951 * s1;
  st.site = &dc_emlrtRSI;
  b_st.site = &wb_emlrtRSI;
  bFactor = 1.4142135623730951 * s2;
  st.site = &ec_emlrtRSI;
  b_st.site = &fc_emlrtRSI;
  b_x.set_size((&pf_emlrtRTEI), (&b_st), 1, x.size(1));
  loop_ub = x.size(0) * x.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_x[i] = (x[i] - l) / aFactor;
  }

  c_st.site = &gc_emlrtRSI;
  applyScalarFunction(&c_st, b_x, f);
  st.site = &ec_emlrtRSI;
  b_st.site = &fc_emlrtRSI;
  b_x.set_size((&qf_emlrtRTEI), (&b_st), 1, x.size(1));
  loop_ub = x.size(0) * x.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_x[i] = (x[i] - r) / bFactor;
  }

  c_st.site = &gc_emlrtRSI;
  applyScalarFunction(&c_st, b_x, b_r);
  emlrtSizeEqCheckNDR2012b(f.size(), b_r.size(), &e_emlrtECI, sp);
  r = h / 2.0;
  i = f.size(0) * f.size(1);
  f.set_size((&rf_emlrtRTEI), sp, 1, f.size(1));
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    f[i] = r * (f[i] - b_r[i]);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (asymconvstep.cpp)
