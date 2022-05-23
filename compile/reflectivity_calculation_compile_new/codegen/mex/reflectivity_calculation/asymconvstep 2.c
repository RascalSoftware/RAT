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
#include "applyScalarFunction.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo nc_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/ops/mpower.m" /* pathName
                                                                           */
};

static emlrtRSInfo sc_emlrtRSI = {
    39,             /* lineNo */
    "asymconvstep", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "asymconvstep.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    40,             /* lineNo */
    "asymconvstep", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "asymconvstep.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    45,             /* lineNo */
    "asymconvstep", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "asymconvstep.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    9,     /* lineNo */
    "erf", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/specfun/erf.m" /* pathName
                                                                            */
};

static emlrtRSInfo wc_emlrtRSI = {
    12,            /* lineNo */
    "eml_erfcore", /* fcnName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/specfun/private/"
    "eml_erfcore.m" /* pathName */
};

static emlrtECInfo e_emlrtECI = {
    2,              /* nDims */
    45,             /* lineNo */
    12,             /* colNo */
    "asymconvstep", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "asymconvstep.m" /* pName */
};

static emlrtRTEInfo ji_emlrtRTEI = {
    42,             /* lineNo */
    5,              /* colNo */
    "asymconvstep", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "asymconvstep.m" /* pName */
};

static emlrtRTEInfo ki_emlrtRTEI = {
    43,             /* lineNo */
    5,              /* colNo */
    "asymconvstep", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "asymconvstep.m" /* pName */
};

static emlrtRTEInfo li_emlrtRTEI = {
    45,             /* lineNo */
    1,              /* colNo */
    "asymconvstep", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "asymconvstep.m" /* pName */
};

static emlrtRTEInfo mi_emlrtRTEI = {
    1,              /* lineNo */
    14,             /* colNo */
    "asymconvstep", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "asymconvstep.m" /* pName */
};

/* Function Definitions */
void asymconvstep(const emlrtStack *sp, const emxArray_real_T *x, real_T xw,
                  real_T xcen, real_T s1, real_T s2, real_T h,
                  emxArray_real_T *f)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *b_r;
  emxArray_real_T *b_x;
  real_T aFactor;
  real_T bFactor;
  real_T l;
  real_T r;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_x, 2, &ji_emlrtRTEI, true);
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
  st.site = &sc_emlrtRSI;
  b_st.site = &nc_emlrtRSI;
  aFactor = 1.4142135623730951 * s1;
  st.site = &tc_emlrtRSI;
  b_st.site = &nc_emlrtRSI;
  bFactor = 1.4142135623730951 * s2;
  st.site = &uc_emlrtRSI;
  b_st.site = &vc_emlrtRSI;
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity_real_T(&b_st, b_x, i, &ji_emlrtRTEI);
  loop_ub = x->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_x->data[i] = (x->data[i] - l) / aFactor;
  }
  c_st.site = &wc_emlrtRSI;
  applyScalarFunction(&c_st, b_x, f);
  st.site = &uc_emlrtRSI;
  b_st.site = &vc_emlrtRSI;
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity_real_T(&b_st, b_x, i, &ki_emlrtRTEI);
  loop_ub = x->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_x->data[i] = (x->data[i] - r) / bFactor;
  }
  emxInit_real_T(&b_st, &b_r, 2, &mi_emlrtRTEI, true);
  c_st.site = &wc_emlrtRSI;
  applyScalarFunction(&c_st, b_x, b_r);
  iv[0] = (*(int32_T(*)[2])f->size)[0];
  iv[1] = (*(int32_T(*)[2])f->size)[1];
  iv1[0] = (*(int32_T(*)[2])b_r->size)[0];
  iv1[1] = (*(int32_T(*)[2])b_r->size)[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &e_emlrtECI, (emlrtCTX)sp);
  r = h / 2.0;
  i = f->size[0] * f->size[1];
  f->size[0] = 1;
  emxEnsureCapacity_real_T(sp, f, i, &li_emlrtRTEI);
  loop_ub = f->size[1] - 1;
  emxFree_real_T(&b_x);
  for (i = 0; i <= loop_ub; i++) {
    f->data[i] = r * (f->data[i] - b_r->data[i]);
  }
  emxFree_real_T(&b_r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (asymconvstep.c) */
