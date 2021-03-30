//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  chiSquared.cpp
//
//  Code generation for function 'chiSquared'
//


// Include files
#include "chiSquared.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "power.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo xf_emlrtRSI = { 12, // lineNo
  "chiSquared",                        // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"// pathName 
};

static emlrtRSInfo yf_emlrtRSI = { 16, // lineNo
  "chiSquared",                        // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"// pathName 
};

static emlrtRSInfo ag_emlrtRSI = { 17, // lineNo
  "chiSquared",                        // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"// pathName 
};

static emlrtRSInfo bg_emlrtRSI = { 21, // lineNo
  "chiSquared",                        // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"// pathName 
};

static emlrtBCInfo xg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  19,                                  // lineNo
  15,                                  // colNo
  "terms",                             // aName
  "chiSquared",                        // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo t_emlrtECI = { -1,  // nDims
  16,                                  // lineNo
  15,                                  // colNo
  "chiSquared",                        // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"// pName 
};

static emlrtRTEInfo rh_emlrtRTEI = { 16,// lineNo
  15,                                  // colNo
  "chiSquared",                        // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"// pName 
};

static emlrtRTEInfo sh_emlrtRTEI = { 47,// lineNo
  9,                                   // colNo
  "div",                               // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/div.m"// pName
};

static emlrtRTEInfo th_emlrtRTEI = { 17,// lineNo
  14,                                  // colNo
  "chiSquared",                        // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"// pName 
};

static emlrtRTEInfo uh_emlrtRTEI = { 17,// lineNo
  5,                                   // colNo
  "chiSquared",                        // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"// pName 
};

static emlrtRTEInfo vh_emlrtRTEI = { 19,// lineNo
  15,                                  // colNo
  "chiSquared",                        // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/costFunctions/chiSquared/chiSquared.m"// pName 
};

// Function Definitions
real_T chiSquared(const emlrtStack *sp, const coder::array<real_T, 2U> &thisData,
                  const coder::array<real_T, 2U> &thisFit, real_T P)
{
  real_T chi2;
  real_T N;
  int32_T nx;
  coder::array<real_T, 1U> terms;
  int32_T idx;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  boolean_T exitg1;
  boolean_T b_p;
  coder::array<real_T, 1U> b_terms;
  coder::array<boolean_T, 1U> x;
  coder::array<int32_T, 1U> ii;
  int32_T b_ii;
  int32_T iv[2];
  coder::array<uint32_T, 1U> n;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  // chi_squared(func,data,numparams,errors)
  // allChis = zeros(1,numberOfContrasts);
  //      thisData = allData{i};
  //      thisFit = allFits{i};
  st.site = &xf_emlrtRSI;
  b_st.site = &uc_emlrtRSI;
  c_st.site = &vc_emlrtRSI;
  d_st.site = &wc_emlrtRSI;
  if (thisData.size(0) < 1) {
    N = 1.0;
  } else {
    N = static_cast<uint32_T>(thisData.size(0));
  }

  if (N <= P) {
    N = P + 1.0;
  }

  if (thisData.size(0) != thisFit.size(0)) {
    emlrtSizeEqCheck1DR2012b(thisData.size(0), thisFit.size(0), &t_emlrtECI, sp);
  }

  st.site = &yf_emlrtRSI;
  nx = thisData.size(0);
  terms.set_size((&rh_emlrtRTEI), (&st), thisData.size(0));
  for (idx = 0; idx < nx; idx++) {
    terms[idx] = thisData[idx + thisData.size(0)] - thisFit[idx + thisFit.size(0)];
  }

  varargin_1[0] = static_cast<uint32_T>(terms.size(0));
  varargin_1[1] = 1U;
  varargin_2[0] = static_cast<uint32_T>(thisData.size(0));
  varargin_2[1] = 1U;
  p = true;
  nx = 0;
  exitg1 = false;
  while ((!exitg1) && (nx < 2)) {
    if (static_cast<int32_T>(varargin_1[nx]) != static_cast<int32_T>
        (varargin_2[nx])) {
      p = false;
      exitg1 = true;
    } else {
      nx++;
    }
  }

  b_p = p;
  if (!b_p) {
    emlrtErrorWithMessageIdR2018a(&st, &qb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  b_terms.set_size((&sh_emlrtRTEI), sp, terms.size(0));
  nx = terms.size(0);
  for (idx = 0; idx < nx; idx++) {
    b_terms[idx] = terms[idx] / thisData[idx + thisData.size(0) * 2];
  }

  st.site = &yf_emlrtRSI;
  power(&st, b_terms, terms);
  st.site = &ag_emlrtRSI;
  x.set_size((&th_emlrtRTEI), (&st), terms.size(0));
  nx = terms.size(0);
  for (idx = 0; idx < nx; idx++) {
    x[idx] = (terms[idx] == rtInf);
  }

  b_st.site = &nd_emlrtRSI;
  nx = x.size(0);
  c_st.site = &od_emlrtRSI;
  idx = 0;
  ii.set_size((&eg_emlrtRTEI), (&c_st), x.size(0));
  d_st.site = &pd_emlrtRSI;
  if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
    e_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= nx - 1)) {
    if (x[b_ii]) {
      idx++;
      ii[idx - 1] = b_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }

  if (idx > x.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (x.size(0) == 1) {
    if (idx == 0) {
      ii.set_size((&fg_emlrtRTEI), (&c_st), 0);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }

    iv[0] = 1;
    iv[1] = idx;
    d_st.site = &qd_emlrtRSI;
    indexShapeCheck(&d_st, ii.size(0), iv);
    ii.set_size((&fg_emlrtRTEI), (&c_st), idx);
  }

  n.set_size((&uh_emlrtRTEI), (&st), ii.size(0));
  nx = ii.size(0);
  for (idx = 0; idx < nx; idx++) {
    n[idx] = static_cast<uint32_T>(ii[idx]);
  }

  if (n.size(0) != 0) {
    ii.set_size((&vh_emlrtRTEI), sp, n.size(0));
    nx = n.size(0);
    for (idx = 0; idx < nx; idx++) {
      if ((static_cast<int32_T>(n[idx]) < 1) || (static_cast<int32_T>(n[idx]) >
           terms.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n[idx]), 1,
          terms.size(0), &xg_emlrtBCI, sp);
      }

      ii[idx] = static_cast<int32_T>(n[idx]);
    }

    nx = ii.size(0);
    for (idx = 0; idx < nx; idx++) {
      terms[ii[idx] - 1] = 0.0;
    }
  }

  st.site = &bg_emlrtRSI;
  chi2 = 1.0 / (N - P) * sum(&st, terms);

  // allChis(i) = chi2;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return chi2;
}

// End of code generation (chiSquared.cpp)
