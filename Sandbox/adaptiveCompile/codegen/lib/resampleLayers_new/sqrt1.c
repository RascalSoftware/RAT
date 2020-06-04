/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * sqrt1.c
 *
 * Code generation for function 'sqrt1'
 *
 */

/* Include files */
#include <math.h>
#include "rt_nonfinite.h"
#include "resampleLayers_new.h"
#include "sqrt1.h"

/* Function Declarations */
static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */
static double rt_hypotd_snf(double u0, double u1)
{
  double y;
  double a;
  double b;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

void b_sqrt(creal_T *x)
{
  double xr;
  double xi;
  double yr;
  double absxr;
  xr = x->re;
  xi = x->im;
  if (xi == 0.0) {
    if (xr < 0.0) {
      yr = 0.0;
      xr = sqrt(-xr);
    } else {
      yr = sqrt(xr);
      xr = 0.0;
    }
  } else if (xr == 0.0) {
    if (xi < 0.0) {
      yr = sqrt(-xi / 2.0);
      xr = -yr;
    } else {
      yr = sqrt(xi / 2.0);
      xr = yr;
    }
  } else if (rtIsNaN(xr)) {
    yr = xr;
  } else if (rtIsNaN(xi)) {
    yr = xi;
    xr = xi;
  } else if (rtIsInf(xi)) {
    yr = fabs(xi);
    xr = xi;
  } else if (rtIsInf(xr)) {
    if (xr < 0.0) {
      yr = 0.0;
      xr = xi * -xr;
    } else {
      yr = xr;
      xr = 0.0;
    }
  } else {
    absxr = fabs(xr);
    yr = fabs(xi);
    if ((absxr > 4.4942328371557893E+307) || (yr > 4.4942328371557893E+307)) {
      absxr *= 0.5;
      yr = rt_hypotd_snf(absxr, yr * 0.5);
      if (yr > absxr) {
        yr = sqrt(yr) * sqrt(1.0 + absxr / yr);
      } else {
        yr = sqrt(yr) * 1.4142135623730951;
      }
    } else {
      yr = sqrt((rt_hypotd_snf(absxr, yr) + absxr) * 0.5);
    }

    if (xr > 0.0) {
      xr = 0.5 * (xi / yr);
    } else {
      if (xi < 0.0) {
        xr = -yr;
      } else {
        xr = yr;
      }

      yr = 0.5 * (xi / xr);
    }
  }

  x->re = yr;
  x->im = xr;
}

/* End of code generation (sqrt1.c) */
