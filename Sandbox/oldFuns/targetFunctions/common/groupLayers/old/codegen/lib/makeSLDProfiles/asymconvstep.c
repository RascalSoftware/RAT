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
#include "makeSLDProfiles.h"
#include "asymconvstep.h"
#include "makeSLDProfiles_emxutil.h"
#include "erf.h"
#include "rdivide.h"

/* Function Definitions */
void asymconvstep(const emxArray_real_T *x, double xw, double xcen, double s1,
                  double s2, double h, emxArray_real_T *f)
{
  emxArray_real_T *b_x;
  double r;
  double l;
  int i3;
  int loop_ub;
  emxArray_real_T *r5;
  emxArray_real_T *c_x;
  emxArray_real_T *r6;
  emxInit_real_T1(&b_x, 1);

  /*  Produces a step function convoluted with differnt error functions */
  /*  on each side. */
  /*  Convstep (x,xw,xcen,s1,s2,h) */
  /*        x = vector of x values */
  /*       xw = Width of step function */
  /*     xcen = Centre point of step function */
  /*        s1 = Roughness parameter of left side */
  /*        s2 = Roughness parameter of right side */
  /*        h = Height of step function. */
  r = xcen + xw / 2.0;
  l = xcen - xw / 2.0;

  /* f = (h/2)*(Faddeeva_erf(a)-Faddeeva_erf(b)); */
  i3 = b_x->size[0];
  b_x->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)b_x, i3, (int)sizeof(double));
  loop_ub = x->size[0];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_x->data[i3] = x->data[i3] - l;
  }

  emxInit_real_T1(&r5, 1);
  emxInit_real_T1(&c_x, 1);
  b_rdivide(b_x, 1.4142135623730951 * s1, r5);
  c_erf(r5, f);
  i3 = c_x->size[0];
  c_x->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)c_x, i3, (int)sizeof(double));
  loop_ub = x->size[0];
  emxFree_real_T(&b_x);
  for (i3 = 0; i3 < loop_ub; i3++) {
    c_x->data[i3] = x->data[i3] - r;
  }

  emxInit_real_T1(&r6, 1);
  b_rdivide(c_x, 1.4142135623730951 * s2, r5);
  c_erf(r5, r6);
  r = h / 2.0;
  i3 = f->size[0];
  emxEnsureCapacity((emxArray__common *)f, i3, (int)sizeof(double));
  loop_ub = f->size[0];
  emxFree_real_T(&c_x);
  emxFree_real_T(&r5);
  for (i3 = 0; i3 < loop_ub; i3++) {
    f->data[i3] = r * (f->data[i3] - r6->data[i3]);
  }

  emxFree_real_T(&r6);
}

void b_asymconvstep(const double x_data[], double xw, double xcen, double s1,
                    double s2, double h, double f_data[], int f_size[2])
{
  double r;
  double l;
  double b_x_data[101];
  int x_size[2];
  int i5;
  emxArray_real_T *r7;
  emxArray_real_T *r8;
  emxArray_real_T c_x_data;
  int loop_ub;
  double d_x_data[101];
  int b_x_size[2];
  emxArray_real_T e_x_data;
  double tmp_data[101];

  /*  Produces a step function convoluted with differnt error functions */
  /*  on each side. */
  /*  Convstep (x,xw,xcen,s1,s2,h) */
  /*        x = vector of x values */
  /*       xw = Width of step function */
  /*     xcen = Centre point of step function */
  /*        s1 = Roughness parameter of left side */
  /*        s2 = Roughness parameter of right side */
  /*        h = Height of step function. */
  r = xcen + xw / 2.0;
  l = xcen - xw / 2.0;

  /* f = (h/2)*(Faddeeva_erf(a)-Faddeeva_erf(b)); */
  x_size[0] = 1;
  x_size[1] = 101;
  for (i5 = 0; i5 < 101; i5++) {
    b_x_data[i5] = x_data[i5] - l;
  }

  emxInit_real_T(&r7, 2);
  emxInit_real_T(&r8, 2);
  c_x_data.data = (double *)&b_x_data;
  c_x_data.size = (int *)&x_size;
  c_x_data.allocatedSize = 101;
  c_x_data.numDimensions = 2;
  c_x_data.canFreeData = false;
  rdivide(&c_x_data, 1.4142135623730951 * s1, r7);
  b_erf(r7, r8);
  loop_ub = r8->size[0] * r8->size[1];
  for (i5 = 0; i5 < loop_ub; i5++) {
    f_data[i5] = r8->data[i5];
  }

  b_x_size[0] = 1;
  b_x_size[1] = 101;
  for (i5 = 0; i5 < 101; i5++) {
    d_x_data[i5] = x_data[i5] - r;
  }

  e_x_data.data = (double *)&d_x_data;
  e_x_data.size = (int *)&b_x_size;
  e_x_data.allocatedSize = 101;
  e_x_data.numDimensions = 2;
  e_x_data.canFreeData = false;
  rdivide(&e_x_data, 1.4142135623730951 * s2, r7);
  b_erf(r7, r8);
  loop_ub = r8->size[0] * r8->size[1];
  emxFree_real_T(&r7);
  for (i5 = 0; i5 < loop_ub; i5++) {
    tmp_data[i5] = r8->data[i5];
  }

  emxFree_real_T(&r8);
  r = h / 2.0;
  f_size[0] = 1;
  f_size[1] = 101;
  for (i5 = 0; i5 < 101; i5++) {
    f_data[i5] = r * (f_data[i5] - tmp_data[i5]);
  }
}

/* End of code generation (asymconvstep.c) */
