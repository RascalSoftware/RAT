/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * asymconvstep.c
 *
 * Code generation for function 'asymconvstep'
 *
 */

/* Include files */
#include "asymconvstep.h"
#include "applyScalarFunction.h"
#include "eml_mtimes_helper.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo nc_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName
                                                                       */
};

static emlrtRSInfo sc_emlrtRSI = {
    39,             /* lineNo */
    "asymconvstep", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "makeSLDProfiles/asymconvstep.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    40,             /* lineNo */
    "asymconvstep", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "makeSLDProfiles/asymconvstep.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    45,             /* lineNo */
    "asymconvstep", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "makeSLDProfiles/asymconvstep.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    9,     /* lineNo */
    "erf", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/specfun/erf.m" /* pathName
                                                                     */
};

static emlrtRSInfo wc_emlrtRSI = {
    12,            /* lineNo */
    "eml_erfcore", /* fcnName */
    "/usr/local/MATLAB/R2021b/toolbox/eml/lib/matlab/specfun/private/"
    "eml_erfcore.m" /* pathName */
};

static emlrtECInfo e_emlrtECI = {
    2,              /* nDims */
    45,             /* lineNo */
    12,             /* colNo */
    "asymconvstep", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "makeSLDProfiles/asymconvstep.m" /* pName */
};

static emlrtRTEInfo ki_emlrtRTEI = {
    42,             /* lineNo */
    5,              /* colNo */
    "asymconvstep", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "makeSLDProfiles/asymconvstep.m" /* pName */
};

static emlrtRTEInfo li_emlrtRTEI = {
    43,             /* lineNo */
    5,              /* colNo */
    "asymconvstep", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "makeSLDProfiles/asymconvstep.m" /* pName */
};

static emlrtRTEInfo mi_emlrtRTEI = {
    45,             /* lineNo */
    1,              /* colNo */
    "asymconvstep", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "makeSLDProfiles/asymconvstep.m" /* pName */
};

static emlrtRTEInfo ni_emlrtRTEI = {
    1,              /* lineNo */
    14,             /* colNo */
    "asymconvstep", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/"
    "makeSLDProfiles/asymconvstep.m" /* pName */
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
  const real_T *x_data;
  real_T aFactor;
  real_T bFactor;
  real_T l;
  real_T r;
  real_T *b_x_data;
  real_T *f_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_x, 2, &ki_emlrtRTEI, true);
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
  emxEnsureCapacity_real_T(&b_st, b_x, i, &ki_emlrtRTEI);
  b_x_data = b_x->data;
  loop_ub = x->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_x_data[i] = (x_data[i] - l) / aFactor;
  }
  c_st.site = &wc_emlrtRSI;
  applyScalarFunction(&c_st, b_x, f);
  st.site = &uc_emlrtRSI;
  b_st.site = &vc_emlrtRSI;
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = 1;
  b_x->size[1] = x->size[1];
  emxEnsureCapacity_real_T(&b_st, b_x, i, &li_emlrtRTEI);
  b_x_data = b_x->data;
  loop_ub = x->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_x_data[i] = (x_data[i] - r) / bFactor;
  }
  emxInit_real_T(&b_st, &b_r, 2, &ni_emlrtRTEI, true);
  c_st.site = &wc_emlrtRSI;
  applyScalarFunction(&c_st, b_x, b_r);
  b_x_data = b_r->data;
  emxFree_real_T(sp, &b_x);
  if ((f->size[1] != b_r->size[1]) &&
      ((f->size[1] != 1) && (b_r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(f->size[1], b_r->size[1], &e_emlrtECI,
                                (emlrtCTX)sp);
  }
  r = h / 2.0;
  if (f->size[1] == b_r->size[1]) {
    loop_ub = f->size[1] - 1;
    i = f->size[0] * f->size[1];
    f->size[0] = 1;
    emxEnsureCapacity_real_T(sp, f, i, &mi_emlrtRTEI);
    f_data = f->data;
    for (i = 0; i <= loop_ub; i++) {
      f_data[i] = r * (f_data[i] - b_x_data[i]);
    }
  } else {
    st.site = &ij_emlrtRSI;
    b_binary_expand_op(&st, f, r, b_r);
  }
  emxFree_real_T(sp, &b_r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (asymconvstep.c) */
