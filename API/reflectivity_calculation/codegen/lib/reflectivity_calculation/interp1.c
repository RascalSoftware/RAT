/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * interp1.c
 *
 * Code generation for function 'interp1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "interp1.h"

/* Function Definitions */
void interp1Linear(const double y[2], const emxArray_real_T *xi, emxArray_real_T
                   *yi, const double varargin_1[2])
{
  double minx;
  double maxx;
  int ub_loop;
  int k;
  double r;
  minx = varargin_1[0];
  maxx = varargin_1[1];
  ub_loop = xi->size[1];
  ub_loop--;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r)

  for (k = 0; k <= ub_loop; k++) {
    if (rtIsNaN(xi->data[k])) {
      yi->data[k] = rtNaN;
    } else {
      if ((!(xi->data[k] > maxx)) && (!(xi->data[k] < minx))) {
        r = (xi->data[k] - varargin_1[0]) / (varargin_1[1] - varargin_1[0]);
        if (r == 0.0) {
          yi->data[k] = y[0];
        } else if (r == 1.0) {
          yi->data[k] = y[1];
        } else if (y[0] == y[1]) {
          yi->data[k] = y[0];
        } else {
          yi->data[k] = (1.0 - r) * y[0] + r * y[1];
        }
      }
    }
  }
}

/* End of code generation (interp1.c) */
