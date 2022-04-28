/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "power.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo wk_emlrtRTEI = {
    71,                                                           /* lineNo */
    5,                                                            /* colNo */
    "power",                                                      /* fName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/ops/power.m" /* pName */
};

/* Function Definitions */
void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emlrtStack st;
  const real_T *a_data;
  real_T varargin_1;
  real_T *y_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  a_data = a->data;
  st.site = &oc_emlrtRSI;
  i = y->size[0];
  y->size[0] = a->size[0];
  emxEnsureCapacity_real_T(&st, y, i, &wk_emlrtRTEI);
  y_data = y->data;
  loop_ub = a->size[0];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = a_data[i];
    y_data[i] = varargin_1 * varargin_1;
  }
}

/* End of code generation (power.c) */
