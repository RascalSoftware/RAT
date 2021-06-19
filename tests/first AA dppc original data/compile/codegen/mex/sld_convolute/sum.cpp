//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sum.cpp
//
//  Code generation for function 'sum'
//


// Include files
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sld_convolute.h"
#include "sld_convolute_data.h"

// Variable Definitions
static emlrtRSInfo ab_emlrtRSI = { 20, // lineNo
  "sum",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sum.m"// pathName
};

static emlrtRSInfo bb_emlrtRSI = { 99, // lineNo
  "sumprod",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"// pathName 
};

static emlrtRSInfo cb_emlrtRSI = { 125,// lineNo
  "combineVectorElements",             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

static emlrtRSInfo db_emlrtRSI = { 185,// lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

// Function Definitions
real_T sum(const emlrtStack *sp, const coder::array<real_T, 2U> &x)
{
  real_T y;
  int32_T vlen;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ab_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &bb_emlrtRSI;
  vlen = x.size(1);
  if (x.size(1) == 0) {
    y = 0.0;
  } else {
    c_st.site = &cb_emlrtRSI;
    y = x[0];
    d_st.site = &db_emlrtRSI;
    if ((2 <= x.size(1)) && (x.size(1) > 2147483646)) {
      e_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (int32_T k = 2; k <= vlen; k++) {
      y += x[k - 1];
    }
  }

  return y;
}

// End of code generation (sum.cpp)
