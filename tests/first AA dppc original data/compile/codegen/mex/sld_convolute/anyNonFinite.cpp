//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// anyNonFinite.cpp
//
// Code generation for function 'anyNonFinite'
//

// Include files
#include "anyNonFinite.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sld_convolute_data.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo sb_emlrtRSI{
    29,             // lineNo
    "anyNonFinite", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "anyNonFinite.m" // pathName
};

static emlrtRSInfo tb_emlrtRSI{
    44,          // lineNo
    "vAllOrAny", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "vAllOrAny.m" // pathName
};

static emlrtRSInfo ub_emlrtRSI{
    103,                  // lineNo
    "flatVectorAllOrAny", // fcnName
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "vAllOrAny.m" // pathName
};

// Function Definitions
namespace coder {
namespace internal {
boolean_T anyNonFinite(const emlrtStack *sp,
                       const ::coder::array<real_T, 2U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &tb_emlrtRSI;
  nx = x.size(1);
  p = true;
  c_st.site = &ub_emlrtRSI;
  if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
    d_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (int32_T k{0}; k < nx; k++) {
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

} // namespace internal
} // namespace coder

// End of code generation (anyNonFinite.cpp)
