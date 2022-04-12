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
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo df_emlrtRSI = {
    28,       /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

static emlrtRSInfo ef_emlrtRSI = {
    69,       /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    58,                   /* lineNo */
    23,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo qk_emlrtRTEI = {
    59,       /* lineNo */
    28,       /* colNo */
    "repmat", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pName
                                                                         */
};

/* Function Definitions */
void repmat(const emlrtStack *sp, const real_T a[2], real_T varargin_1,
            emxArray_real_T *b)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T ibmat;
  int32_T itilerow;
  int32_T jcol;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &df_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (varargin_1 != varargin_1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &qb_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  i = (int32_T)varargin_1;
  ibmat = b->size[0] * b->size[1];
  b->size[0] = (int32_T)varargin_1;
  b->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b, ibmat, &qk_emlrtRTEI);
  overflow = ((1 <= (int32_T)varargin_1) && ((int32_T)varargin_1 > 2147483646));
  for (jcol = 0; jcol < 2; jcol++) {
    ibmat = jcol * (int32_T)varargin_1;
    st.site = &ef_emlrtRSI;
    if (overflow) {
      b_st.site = &j_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (itilerow = 0; itilerow < i; itilerow++) {
      b->data[ibmat + itilerow] = a[jcol];
    }
  }
}

/* End of code generation (repmat.c) */
