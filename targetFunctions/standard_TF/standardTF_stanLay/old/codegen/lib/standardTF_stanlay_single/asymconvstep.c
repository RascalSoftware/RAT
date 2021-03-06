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
#include "standardTF_stanlay_single.h"
#include "asymconvstep.h"
#include "standardTF_stanlay_single_emxutil.h"
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
  int b_f;
  int loop_ub;
  emxArray_real_T *c_x;
  emxArray_real_T *r3;
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
  b_f = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b_x, b_f, (int)sizeof(double));
  loop_ub = x->size[0] * x->size[1];
  for (b_f = 0; b_f < loop_ub; b_f++) {
    b_x->data[b_f] = (x->data[b_f] - l) / aFactor;
  }

  emxInit_real_T(&c_x, 2);
  b_erf(b_x, f);
  b_f = c_x->size[0] * c_x->size[1];
  c_x->size[0] = 1;
  c_x->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)c_x, b_f, (int)sizeof(double));
  loop_ub = x->size[0] * x->size[1];
  emxFree_real_T(&b_x);
  for (b_f = 0; b_f < loop_ub; b_f++) {
    c_x->data[b_f] = (x->data[b_f] - r) / bFactor;
  }

  emxInit_real_T(&r3, 2);
  b_erf(c_x, r3);
  r = h / 2.0;
  b_f = f->size[0] * f->size[1];
  f->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)f, b_f, (int)sizeof(double));
  b_f = f->size[0];
  loop_ub = f->size[1];
  loop_ub *= b_f;
  emxFree_real_T(&c_x);
  for (b_f = 0; b_f < loop_ub; b_f++) {
    f->data[b_f] = r * (f->data[b_f] - r3->data[b_f]);
  }

  emxFree_real_T(&r3);
}

void b_asymconvstep(const double x_data[], double xw, double xcen, double s1,
                    double s2, double h, double f_data[], int f_size[2])
{
  emxArray_real_T *x;
  double r;
  double l;
  double aFactor;
  double bFactor;
  int i3;
  emxArray_real_T *r4;
  int loop_ub;
  emxArray_real_T *b_x;
  double tmp_data[101];
  emxInit_real_T(&x, 2);

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
  i3 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = 101;
  emxEnsureCapacity((emxArray__common *)x, i3, (int)sizeof(double));
  for (i3 = 0; i3 < 101; i3++) {
    x->data[i3] = (x_data[i3] - l) / aFactor;
  }

  emxInit_real_T(&r4, 2);
  b_erf(x, r4);
  loop_ub = r4->size[0] * r4->size[1];
  emxFree_real_T(&x);
  for (i3 = 0; i3 < loop_ub; i3++) {
    f_data[i3] = r4->data[i3];
  }

  emxInit_real_T(&b_x, 2);
  i3 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = 101;
  emxEnsureCapacity((emxArray__common *)b_x, i3, (int)sizeof(double));
  for (i3 = 0; i3 < 101; i3++) {
    b_x->data[i3] = (x_data[i3] - r) / bFactor;
  }

  b_erf(b_x, r4);
  loop_ub = r4->size[0] * r4->size[1];
  emxFree_real_T(&b_x);
  for (i3 = 0; i3 < loop_ub; i3++) {
    tmp_data[i3] = r4->data[i3];
  }

  emxFree_real_T(&r4);
  r = h / 2.0;
  f_size[0] = 1;
  f_size[1] = 101;
  for (i3 = 0; i3 < 101; i3++) {
    f_data[i3] = r * (f_data[i3] - tmp_data[i3]);
  }
}

/* End of code generation (asymconvstep.c) */
