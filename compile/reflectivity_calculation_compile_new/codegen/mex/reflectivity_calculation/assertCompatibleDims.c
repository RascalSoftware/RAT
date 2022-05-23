/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * assertCompatibleDims.c
 *
 * Code generation for function 'assertCompatibleDims'
 *
 */

/* Include files */
#include "assertCompatibleDims.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void assertCompatibleDims(const emlrtStack *sp, const emxArray_real_T *x,
                          const emxArray_real_T *y)
{
  if ((x->size[0] != 1) && (y->size[0] != 1) && (x->size[0] != y->size[0])) {
    emlrtErrorWithMessageIdR2018a(sp, &ob_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
}

/* End of code generation (assertCompatibleDims.c) */
