/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * complexTimes.c
 *
 * Code generation for function 'complexTimes'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "resampleLayers_new.h"
#include "complexTimes.h"

/* Function Definitions */
double rescale(double *re, double *im)
{
  double scale;
  double absim;
  scale = fabs(*re);
  absim = fabs(*im);
  if (scale > absim) {
    if (*re < 0.0) {
      *re = -1.0;
    } else {
      *re = 1.0;
    }

    *im /= scale;
  } else if (absim > scale) {
    *re /= absim;
    if (*im < 0.0) {
      *im = -1.0;
    } else {
      *im = 1.0;
    }

    scale = absim;
  } else {
    if (*re < 0.0) {
      *re = -1.0;
    } else {
      *re = 1.0;
    }

    if (*im < 0.0) {
      *im = -1.0;
    } else {
      *im = 1.0;
    }
  }

  return scale;
}

/* End of code generation (complexTimes.c) */
