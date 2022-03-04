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
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo
    ne_emlrtRSI =
        {
            28,       /* lineNo */
            "repmat", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/elmat/"
            "repmat.m" /* pathName */
};

static emlrtRSInfo
    oe_emlrtRSI =
        {
            69,       /* lineNo */
            "repmat", /* fcnName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/elmat/"
            "repmat.m" /* pathName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    58,                   /* lineNo */
    23,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo
    pf_emlrtRTEI =
        {
            59,       /* lineNo */
            28,       /* colNo */
            "repmat", /* fName */
            "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/elmat/"
            "repmat.m" /* pName */
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
  st.site = &ne_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((varargin_1 != varargin_1) || muDoubleScalarIsInf(varargin_1)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &r_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  i = (int32_T)varargin_1;
  ibmat = b->size[0] * b->size[1];
  b->size[0] = (int32_T)varargin_1;
  b->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b, ibmat, &pf_emlrtRTEI);
  overflow = ((1 <= (int32_T)varargin_1) && ((int32_T)varargin_1 > 2147483646));
  for (jcol = 0; jcol < 2; jcol++) {
    ibmat = jcol * (int32_T)varargin_1;
    st.site = &oe_emlrtRSI;
    if (overflow) {
      b_st.site = &wb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (itilerow = 0; itilerow < i; itilerow++) {
      b->data[ibmat + itilerow] = a[jcol];
    }
  }
}

/* End of code generation (repmat.c) */
