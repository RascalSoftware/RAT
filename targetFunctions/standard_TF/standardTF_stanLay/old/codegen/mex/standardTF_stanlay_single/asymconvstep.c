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
#include "standardTF_stanlay_single_data.h"

/* Variable Definitions */
static emlrtRTEInfo v_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "asymconvstep",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pName */
};

/* Function Definitions */
void asymconvstep(const emlrtStack *sp, const emxArray_real_T *x, real_T xw,
                  real_T xcen, real_T s1, real_T s2, real_T h, emxArray_real_T
                  *f)
{
  emxArray_real_T *b_x;
  real_T r;
  real_T l;
  real_T aFactor;
  real_T bFactor;
  int32_T b_f;
  int32_T loop_ub;
  emxArray_real_T *c_x;
  emxArray_real_T *r4;
  int32_T c_f[2];
  int32_T iv8[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_x, 2, &v_emlrtRTEI, true);

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
  emxEnsureCapacity(sp, (emxArray__common *)b_x, b_f, (int32_T)sizeof(real_T),
                    &v_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1];
  for (b_f = 0; b_f < loop_ub; b_f++) {
    b_x->data[b_f] = (x->data[b_f] - l) / aFactor;
  }

  emxInit_real_T(sp, &c_x, 2, &v_emlrtRTEI, true);
  st.site = &mb_emlrtRSI;
  b_erf(&st, b_x, f);
  b_f = c_x->size[0] * c_x->size[1];
  c_x->size[0] = 1;
  c_x->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_x, b_f, (int32_T)sizeof(real_T),
                    &v_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1];
  emxFree_real_T(&b_x);
  for (b_f = 0; b_f < loop_ub; b_f++) {
    c_x->data[b_f] = (x->data[b_f] - r) / bFactor;
  }

  emxInit_real_T(sp, &r4, 2, &v_emlrtRTEI, true);
  st.site = &mb_emlrtRSI;
  b_erf(&st, c_x, r4);
  emxFree_real_T(&c_x);
  for (b_f = 0; b_f < 2; b_f++) {
    c_f[b_f] = f->size[b_f];
  }

  for (b_f = 0; b_f < 2; b_f++) {
    iv8[b_f] = r4->size[b_f];
  }

  if ((c_f[0] != iv8[0]) || (c_f[1] != iv8[1])) {
    emlrtSizeEqCheckNDR2012b(&c_f[0], &iv8[0], &e_emlrtECI, sp);
  }

  r = h / 2.0;
  b_f = f->size[0] * f->size[1];
  f->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)f, b_f, (int32_T)sizeof(real_T),
                    &v_emlrtRTEI);
  b_f = f->size[0];
  loop_ub = f->size[1];
  loop_ub *= b_f;
  for (b_f = 0; b_f < loop_ub; b_f++) {
    f->data[b_f] = r * (f->data[b_f] - r4->data[b_f]);
  }

  emxFree_real_T(&r4);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void b_asymconvstep(const emlrtStack *sp, const real_T x_data[], real_T xw,
                    real_T xcen, real_T s1, real_T s2, real_T h, real_T f_data[],
                    int32_T f_size[2])
{
  emxArray_real_T *x;
  real_T r;
  real_T l;
  real_T aFactor;
  real_T bFactor;
  int32_T i7;
  emxArray_real_T *r5;
  int32_T loop_ub;
  emxArray_real_T *b_x;
  real_T tmp_data[101];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &x, 2, &v_emlrtRTEI, true);

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
  i7 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = 101;
  emxEnsureCapacity(sp, (emxArray__common *)x, i7, (int32_T)sizeof(real_T),
                    &v_emlrtRTEI);
  for (i7 = 0; i7 < 101; i7++) {
    x->data[i7] = (x_data[i7] - l) / aFactor;
  }

  emxInit_real_T(sp, &r5, 2, &v_emlrtRTEI, true);
  st.site = &mb_emlrtRSI;
  b_erf(&st, x, r5);
  loop_ub = r5->size[0] * r5->size[1];
  emxFree_real_T(&x);
  for (i7 = 0; i7 < loop_ub; i7++) {
    f_data[i7] = r5->data[i7];
  }

  emxInit_real_T(sp, &b_x, 2, &v_emlrtRTEI, true);
  i7 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = 101;
  emxEnsureCapacity(sp, (emxArray__common *)b_x, i7, (int32_T)sizeof(real_T),
                    &v_emlrtRTEI);
  for (i7 = 0; i7 < 101; i7++) {
    b_x->data[i7] = (x_data[i7] - r) / bFactor;
  }

  st.site = &mb_emlrtRSI;
  b_erf(&st, b_x, r5);
  loop_ub = r5->size[0] * r5->size[1];
  emxFree_real_T(&b_x);
  for (i7 = 0; i7 < loop_ub; i7++) {
    tmp_data[i7] = r5->data[i7];
  }

  emxFree_real_T(&r5);
  r = h / 2.0;
  f_size[0] = 1;
  f_size[1] = 101;
  for (i7 = 0; i7 < 101; i7++) {
    f_data[i7] = r * (f_data[i7] - tmp_data[i7]);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (asymconvstep.c) */
