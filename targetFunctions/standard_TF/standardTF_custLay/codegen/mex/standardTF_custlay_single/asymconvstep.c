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
#include "standardTF_custlay_single.h"
#include "asymconvstep.h"
#include "mpower.h"
#include "standardTF_custlay_single_emxutil.h"
#include "erf.h"
#include "standardTF_custlay_single_data.h"

/* Variable Definitions */
static emlrtRTEInfo p_emlrtRTEI = { 1, /* lineNo */
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
  emxArray_real_T *r3;
  int32_T c_f[2];
  int32_T iv6[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_x, 2, &p_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 7U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 0U);

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
  mpower();
  aFactor = 1.4142135623730951 * s1;
  mpower();
  bFactor = 1.4142135623730951 * s2;
  b_f = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_x, b_f, (int32_T)sizeof(real_T),
                    &p_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1];
  for (b_f = 0; b_f < loop_ub; b_f++) {
    b_x->data[b_f] = (x->data[b_f] - l) / aFactor;
  }

  emxInit_real_T(sp, &c_x, 2, &p_emlrtRTEI, true);
  st.site = &lb_emlrtRSI;
  b_erf(&st, b_x, f);
  b_f = c_x->size[0] * c_x->size[1];
  c_x->size[0] = 1;
  c_x->size[1] = x->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c_x, b_f, (int32_T)sizeof(real_T),
                    &p_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1];
  emxFree_real_T(&b_x);
  for (b_f = 0; b_f < loop_ub; b_f++) {
    c_x->data[b_f] = (x->data[b_f] - r) / bFactor;
  }

  emxInit_real_T(sp, &r3, 2, &p_emlrtRTEI, true);
  st.site = &lb_emlrtRSI;
  b_erf(&st, c_x, r3);
  emxFree_real_T(&c_x);
  for (b_f = 0; b_f < 2; b_f++) {
    c_f[b_f] = f->size[b_f];
  }

  for (b_f = 0; b_f < 2; b_f++) {
    iv6[b_f] = r3->size[b_f];
  }

  if ((c_f[0] != iv6[0]) || (c_f[1] != iv6[1])) {
    emlrtSizeEqCheckNDR2012b(&c_f[0], &iv6[0], &emlrtECI, sp);
  }

  r = h / 2.0;
  b_f = f->size[0] * f->size[1];
  f->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)f, b_f, (int32_T)sizeof(real_T),
                    &p_emlrtRTEI);
  b_f = f->size[0];
  loop_ub = f->size[1];
  loop_ub *= b_f;
  for (b_f = 0; b_f < loop_ub; b_f++) {
    f->data[b_f] = r * (f->data[b_f] - r3->data[b_f]);
  }

  emxFree_real_T(&r3);
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
  int32_T i8;
  emxArray_real_T *r4;
  int32_T loop_ub;
  emxArray_real_T *b_x;
  real_T tmp_data[101];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &x, 2, &p_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 7U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 0U);

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
  mpower();
  aFactor = 1.4142135623730951 * s1;
  mpower();
  bFactor = 1.4142135623730951 * s2;
  i8 = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = 101;
  emxEnsureCapacity(sp, (emxArray__common *)x, i8, (int32_T)sizeof(real_T),
                    &p_emlrtRTEI);
  for (i8 = 0; i8 < 101; i8++) {
    x->data[i8] = (x_data[i8] - l) / aFactor;
  }

  emxInit_real_T(sp, &r4, 2, &p_emlrtRTEI, true);
  st.site = &lb_emlrtRSI;
  b_erf(&st, x, r4);
  loop_ub = r4->size[0] * r4->size[1];
  emxFree_real_T(&x);
  for (i8 = 0; i8 < loop_ub; i8++) {
    f_data[i8] = r4->data[i8];
  }

  emxInit_real_T(sp, &b_x, 2, &p_emlrtRTEI, true);
  i8 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = 101;
  emxEnsureCapacity(sp, (emxArray__common *)b_x, i8, (int32_T)sizeof(real_T),
                    &p_emlrtRTEI);
  for (i8 = 0; i8 < 101; i8++) {
    b_x->data[i8] = (x_data[i8] - r) / bFactor;
  }

  st.site = &lb_emlrtRSI;
  b_erf(&st, b_x, r4);
  loop_ub = r4->size[0] * r4->size[1];
  emxFree_real_T(&b_x);
  for (i8 = 0; i8 < loop_ub; i8++) {
    tmp_data[i8] = r4->data[i8];
  }

  emxFree_real_T(&r4);
  r = h / 2.0;
  f_size[0] = 1;
  f_size[1] = 101;
  for (i8 = 0; i8 < 101; i8++) {
    f_data[i8] = r * (f_data[i8] - tmp_data[i8]);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (asymconvstep.c) */
