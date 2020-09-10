/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo yd_emlrtRSI = { 28, /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 69, /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 58,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo tj_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

/* Function Definitions */
void repmat(const emlrtStack *sp, const real_T a[2], real_T varargin_1,
            emxArray_real_T *b)
{
  int32_T i;
  int32_T itilerow;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((varargin_1 != varargin_1) || muDoubleScalarIsInf(varargin_1)) {
    emlrtErrorWithMessageIdR2018a(&st, &rb_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  i = (int32_T)varargin_1;
  itilerow = b->size[0] * b->size[1];
  b->size[0] = i;
  b->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b, itilerow, &tj_emlrtRTEI);
  st.site = &ae_emlrtRSI;
  if ((1 <= i) && (i > 2147483646)) {
    b_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (itilerow = 0; itilerow < i; itilerow++) {
    b->data[itilerow] = a[0];
  }

  st.site = &ae_emlrtRSI;
  for (itilerow = 0; itilerow < i; itilerow++) {
    b->data[i + itilerow] = a[1];
  }
}

/* End of code generation (repmat.c) */
