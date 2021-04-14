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
#include "asymconvstep.h"
#include "erf.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo hc_emlrtRSI = { 45, /* lineNo */
  "asymconvstep",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pathName */
};

static emlrtECInfo d_emlrtECI = { 2,   /* nDims */
  45,                                  /* lineNo */
  12,                                  /* colNo */
  "asymconvstep",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pName */
};

static emlrtRTEInfo rh_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "asymconvstep",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pName */
};

static emlrtRTEInfo sh_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "asymconvstep",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pName */
};

static emlrtRTEInfo th_emlrtRTEI = { 45,/* lineNo */
  1,                                   /* colNo */
  "asymconvstep",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pName */
};

static emlrtRTEInfo uh_emlrtRTEI = { 1,/* lineNo */
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
  int32_T i;
  int32_T loop_ub;
  emxArray_real_T *b_r;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_x, 2, &rh_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 13U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 0U);

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
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity_real_T(sp, b_x, i, &rh_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_x->data[i] = (x->data[i] - l) / aFactor;
  }

  st.site = &hc_emlrtRSI;
  b_erf(&st, b_x, f);
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity_real_T(sp, b_x, i, &sh_emlrtRTEI);
  loop_ub = x->size[0] * x->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_x->data[i] = (x->data[i] - r) / bFactor;
  }

  emxInit_real_T(sp, &b_r, 2, &uh_emlrtRTEI, true);
  st.site = &hc_emlrtRSI;
  b_erf(&st, b_x, b_r);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])f->size, *(int32_T (*)[2])b_r->size,
    &d_emlrtECI, sp);
  r = h / 2.0;
  i = f->size[0] * f->size[1];
  loop_ub = f->size[0] * f->size[1];
  f->size[0] = 1;
  emxEnsureCapacity_real_T(sp, f, loop_ub, &th_emlrtRTEI);
  loop_ub = i - 1;
  emxFree_real_T(&b_x);
  for (i = 0; i <= loop_ub; i++) {
    f->data[i] = r * (f->data[i] - b_r->data[i]);
  }

  emxFree_real_T(&b_r);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (asymconvstep.c) */
