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
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

// Function Definitions
real_T sum(const emlrtStack *sp, const coder::array<real_T, 1U> &x)
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
  st.site = &sb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &tb_emlrtRSI;
  vlen = x.size(0);
  if (x.size(0) == 0) {
    y = 0.0;
  } else {
    c_st.site = &ub_emlrtRSI;
    y = x[0];
    d_st.site = &vb_emlrtRSI;
    if ((2 <= x.size(0)) && (x.size(0) > 2147483646)) {
      e_st.site = &wb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (int32_T k = 2; k <= vlen; k++) {
      y += x[k - 1];
    }
  }

  return y;
}

// End of code generation (sum.cpp)
