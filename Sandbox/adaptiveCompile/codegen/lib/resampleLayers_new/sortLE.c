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
#include "rt_nonfinite.h"
#include "resampleLayers_new.h"
#include "sortLE.h"

/* Function Definitions */
boolean_T sortLE(const emxArray_real_T *v, const int dir_data[], int idx1, int
                 idx2)
{
  boolean_T p;
  int k;
  boolean_T exitg1;
  double v1;
  double v2;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    v1 = v->data[(idx1 + v->size[0] * (dir_data[k] - 1)) - 1];
    v2 = v->data[(idx2 + v->size[0] * (dir_data[k] - 1)) - 1];
    if ((v1 == v2) || (rtIsNaN(v1) && rtIsNaN(v2))) {
      k++;
    } else {
      if ((v1 <= v2) || rtIsNaN(v2)) {
      } else {
        p = false;
      }

      exitg1 = true;
    }
  }

  return p;
}

/* End of code generation (sortLE.c) */
