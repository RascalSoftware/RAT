/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * exp.c
 *
 * Code generation for function 'exp'
 *
 */

/* Include files */
#include "exp.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void b_exp(creal_T *x)
{
  real_T d;
  real_T r;
  if (x->im == 0.0) {
    x->re = muDoubleScalarExp(x->re);
    x->im = 0.0;
  } else if (muDoubleScalarIsInf(x->im) && muDoubleScalarIsInf(x->re) && (x->re <
              0.0)) {
    x->re = 0.0;
    x->im = 0.0;
  } else {
    r = muDoubleScalarExp(x->re / 2.0);
    d = x->im;
    x->re = r * (r * muDoubleScalarCos(x->im));
    x->im = r * (r * muDoubleScalarSin(d));
  }
}

/* End of code generation (exp.c) */
