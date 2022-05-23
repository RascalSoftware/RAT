/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * sortLE.c
 *
 * Code generation for function 'sortLE'
 *
 */

/* Include files */
#include "sortLE.h"
#include "dev_custlay_paraContrasts_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
boolean_T sortLE(const emxArray_real_T *v, const int32_T dir_data[],
                 int32_T idx1, int32_T idx2)
{
  real_T v1;
  real_T v2;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    v1 = v->data[(idx1 + v->size[0] * (dir_data[k] - 1)) - 1];
    v2 = v->data[(idx2 + v->size[0] * (dir_data[k] - 1)) - 1];
    if ((v1 == v2) || (muDoubleScalarIsNaN(v1) && muDoubleScalarIsNaN(v2))) {
      k++;
    } else {
      if ((!(v1 <= v2)) && (!muDoubleScalarIsNaN(v2))) {
        p = false;
      }
      exitg1 = true;
    }
  }
  return p;
}

/* End of code generation (sortLE.c) */
