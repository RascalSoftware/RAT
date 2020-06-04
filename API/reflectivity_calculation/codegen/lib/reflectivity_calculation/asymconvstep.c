/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * asymconvstep.c
 *
 * Code generation for function 'asymconvstep'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "asymconvstep.h"
#include "reflectivity_calculation_emxutil.h"
#include "erf.h"

/* Function Definitions */
void asymconvstep(const emxArray_real_T *x, double xw, double xcen, double s1,
                  double s2, double h, emxArray_real_T *f)
{
  emxArray_real_T *b_x;
  double r;
  double l;
  double aFactor;
  double bFactor;
  int i5;
  int loop_ub;
  emxArray_real_T *r0;
  emxInit_real_T(&b_x, 2);

  /*  Produces a step function convoluted with differnt error functions */
  /*  on each side. */
  /*  Convstep (x,xw,xcen,s1,s2,h) */
  /*        x = vector of x values */
  /*       xw = Width of step function */
  /*     xcen = Centre point of step function */
  /*        s1 = Roughness parameter of left side */
  /*        s2 = Roughness parameter of right side */
  /*        h = Height of step function. */
  /*  if length(xw) > 1 */
  /*      ME = MException('VerifyOutput:OutOfBounds', ... */
  /*               'xw must be single value'); */
  /*      throw(ME); */
  /*  end */
  /*   */
  /*  if length(xcen) > 1 */
  /*      ME = MException('VerifyOutput:OutOfBounds', ... */
  /*               'xcen must be single value'); */
  /*      throw(ME); */
  /*  end */
  /*   */
  /*  if length(s1) > 1 */
  /*      ME = MException('VerifyOutput:OutOfBounds', ... */
  /*               's1 must be single value'); */
  /*      throw(ME); */
  /*  end */
  /*   */
  /*  if length(s2) > 1 */
  /*      ME = MException('VerifyOutput:OutOfBounds', ... */
  /*               's2 must be single value'); */
  /*      throw(ME); */
  /*  end */
  r = xcen + xw / 2.0;
  l = xcen - xw / 2.0;
  aFactor = 1.4142135623730951 * s1;
  bFactor = 1.4142135623730951 * s2;
  i5 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity_real_T(b_x, i5);
  loop_ub = x->size[0] * x->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_x->data[i5] = (x->data[i5] - l) / aFactor;
  }

  b_erf(b_x, f);
  i5 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity_real_T(b_x, i5);
  loop_ub = x->size[0] * x->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_x->data[i5] = (x->data[i5] - r) / bFactor;
  }

  emxInit_real_T(&r0, 2);
  b_erf(b_x, r0);
  r = h / 2.0;
  i5 = f->size[0] * f->size[1];
  loop_ub = f->size[0] * f->size[1];
  f->size[0] = 1;
  emxEnsureCapacity_real_T(f, loop_ub);
  loop_ub = i5 - 1;
  emxFree_real_T(&b_x);
  for (i5 = 0; i5 <= loop_ub; i5++) {
    f->data[i5] = r * (f->data[i5] - r0->data[i5]);
  }

  emxFree_real_T(&r0);
}

/* End of code generation (asymconvstep.c) */
