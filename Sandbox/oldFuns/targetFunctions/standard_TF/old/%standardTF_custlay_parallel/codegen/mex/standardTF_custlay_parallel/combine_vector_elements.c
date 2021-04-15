/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * combine_vector_elements.c
 *
 * Code generation for function 'combine_vector_elements'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "combine_vector_elements.h"
#include "eml_int_forloop_overflow_check.h"
#include "standardTF_custlay_parallel_data.h"

/* Function Definitions */
real_T combine_vector_elements(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y = x->data[0];
  st.site = &cb_emlrtRSI;
  overflow = ((!(2 > x->size[1])) && (x->size[1] > 2147483646));
  if (overflow) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (k = 2; k <= x->size[1]; k++) {
    y += x->data[k - 1];
  }

  return y;
}

/* End of code generation (combine_vector_elements.c) */
