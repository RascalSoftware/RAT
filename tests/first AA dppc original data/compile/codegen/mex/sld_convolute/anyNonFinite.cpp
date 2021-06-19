//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  anyNonFinite.cpp
//
//  Code generation for function 'anyNonFinite'
//


// Include files
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sld_convolute.h"
#include "sld_convolute_data.h"

// Variable Definitions
static emlrtRSInfo ib_emlrtRSI = { 29, // lineNo
  "anyNonFinite",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/anyNonFinite.m"// pathName 
};

static emlrtRSInfo jb_emlrtRSI = { 44, // lineNo
  "vAllOrAny",                         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"// pathName 
};

static emlrtRSInfo kb_emlrtRSI = { 103,// lineNo
  "flatVectorAllOrAny",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"// pathName 
};

// Function Definitions
boolean_T anyNonFinite(const emlrtStack *sp, const coder::array<real_T, 2U> &x)
{
  boolean_T p;
  int32_T nx;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ib_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &jb_emlrtRSI;
  nx = x.size(1);
  p = true;
  c_st.site = &kb_emlrtRSI;
  if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
    d_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (int32_T k = 0; k < nx; k++) {
    if (p) {
      real_T b_x;
      b_x = x[k];
      if (muDoubleScalarIsInf(b_x) || muDoubleScalarIsNaN(b_x)) {
        p = false;
      }
    } else {
      p = false;
    }
  }

  return !p;
}

// End of code generation (anyNonFinite.cpp)
