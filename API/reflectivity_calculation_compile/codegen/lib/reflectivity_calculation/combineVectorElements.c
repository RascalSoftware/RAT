/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * combineVectorElements.c
 *
 * Code generation for function 'combineVectorElements'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "combineVectorElements.h"
#include <string.h>

/* Function Definitions */
double combineVectorElements(const emxArray_real_T *x)
{
  double y;
  int vlen;
  int k;
  vlen = x->size[1];
  y = x->data[0];
  for (k = 2; k <= vlen; k++) {
    y += x->data[k - 1];
  }

  return y;
}

/* End of code generation (combineVectorElements.c) */
