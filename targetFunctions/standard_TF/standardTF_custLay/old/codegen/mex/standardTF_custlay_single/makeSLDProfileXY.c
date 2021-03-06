/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * makeSLDProfileXY.c
 *
 * Code generation for function 'makeSLDProfileXY'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "makeSLDProfileXY.h"
#include "mpower.h"
#include "standardTF_custlay_single_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "asymconvstep.h"
#include "erf.h"
#include "sum.h"
#include "standardTF_custlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 4,   /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 11,  /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 26,  /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 37,  /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 42,  /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 45,  /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 47,  /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 48,  /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 49,  /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 54,  /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 39, /* lineNo */
  "asymconvstep",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 40, /* lineNo */
  "asymconvstep",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 103,/* lineNo */
  "combine_vector_elements",           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 114,/* lineNo */
  "combine_vector_elements",           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRTEInfo i_emlrtRTEI = { 1, /* lineNo */
  16,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 6, /* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 7, /* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 11,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 26,/* lineNo */
  13,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  40,                                  /* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  12,                                  /* colNo */
  "Lays",                              /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 40,  /* lineNo */
  12,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  37,                                  /* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  12,                                  /* colNo */
  "Lays",                              /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 37, /* lineNo */
  12,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  27,                                  /* lineNo */
  13,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  20,                                  /* colNo */
  "Lays",                              /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  21,                                  /* colNo */
  "x",                                 /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  21,                                  /* colNo */
  "x",                                 /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  35,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  33,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  35,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo tb_emlrtRTEI = { 13,/* lineNo */
  13,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  27,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 7,  /* lineNo */
  28,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 7,  /* lineNo */
  28,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  39,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void makeSLDProfileXY(const emlrtStack *sp, real_T nbair, real_T nbsub, real_T
                      ssub, const emxArray_real_T *layers, real_T numberOfLayers,
                      real_T nrepeats, emxArray_real_T *out)
{
  emxArray_real_T *x;
  emxArray_real_T *airBox;
  emxArray_real_T *SLD;
  emxArray_real_T *b_layers;
  int32_T i6;
  int32_T vlen;
  real_T layerThicks;
  int32_T vstride;
  emxArray_real_T *Lays;
  int32_T mtmp;
  emxArray_real_T *r0;
  real_T subBox_data[101];
  int32_T subBox_size[2];
  emxArray_real_T *b_x;
  real_T nextLayRough;
  emxArray_real_T *r1;
  boolean_T overflow;
  real_T bFactor;
  emxArray_real_T *c_x;
  emxArray_real_T *thisBox;
  int32_T b_airBox[2];
  int32_T b_thisBox[2];
  emxArray_int32_T *r2;
  int32_T k;
  int32_T iv3[1];
  int32_T iv4[1];
  int32_T iv5[1];
  emxArray_real_T *b_SLD;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 6U, 0U);
  emxInit_real_T(sp, &x, 2, &j_emlrtRTEI, true);
  emxInit_real_T(sp, &airBox, 2, &l_emlrtRTEI, true);
  emxInit_real_T(sp, &SLD, 2, &n_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 0, numberOfLayers > 0.0)) {
    emxInit_real_T1(sp, &b_layers, 1, &i_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 0U);
    vlen = layers->size[0];
    i6 = b_layers->size[0];
    b_layers->size[0] = vlen;
    emxEnsureCapacity(sp, (emxArray__common *)b_layers, i6, (int32_T)sizeof
                      (real_T), &i_emlrtRTEI);
    for (i6 = 0; i6 < vlen; i6++) {
      b_layers->data[i6] = layers->data[i6];
    }

    st.site = &p_emlrtRSI;
    layerThicks = sum(&st, b_layers);
    layerThicks = layerThicks * nrepeats + 150.0;
    emxFree_real_T(&b_layers);
    if (muDoubleScalarIsNaN(layerThicks)) {
      i6 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)x, i6, (int32_T)sizeof(real_T),
                        &i_emlrtRTEI);
      x->data[0] = rtNaN;
    } else if (layerThicks < 0.0) {
      i6 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 0;
      emxEnsureCapacity(sp, (emxArray__common *)x, i6, (int32_T)sizeof(real_T),
                        &i_emlrtRTEI);
    } else if (muDoubleScalarIsInf(layerThicks) && (0.0 == layerThicks)) {
      i6 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)x, i6, (int32_T)sizeof(real_T),
                        &i_emlrtRTEI);
      x->data[0] = rtNaN;
    } else {
      i6 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = (int32_T)muDoubleScalarFloor(layerThicks) + 1;
      emxEnsureCapacity(sp, (emxArray__common *)x, i6, (int32_T)sizeof(real_T),
                        &i_emlrtRTEI);
      vlen = (int32_T)muDoubleScalarFloor(layerThicks);
      for (i6 = 0; i6 <= vlen; i6++) {
        x->data[x->size[0] * i6] = i6;
      }
    }

    emxInit_real_T(sp, &Lays, 2, &k_emlrtRTEI, true);
    i6 = Lays->size[0] * Lays->size[1];
    Lays->size[0] = x->size[1];
    layerThicks = numberOfLayers * nrepeats + 2.0;
    if (!(layerThicks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(layerThicks, &cb_emlrtDCI, sp);
    }

    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &bb_emlrtDCI, sp);
    }

    Lays->size[1] = (int32_T)layerThicks;
    emxEnsureCapacity(sp, (emxArray__common *)Lays, i6, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    layerThicks = numberOfLayers * nrepeats + 2.0;
    if (!(layerThicks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(layerThicks, &cb_emlrtDCI, sp);
    }

    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &bb_emlrtDCI, sp);
    }

    vlen = x->size[1] * (int32_T)layerThicks;
    for (i6 = 0; i6 < vlen; i6++) {
      Lays->data[i6] = 0.0;
    }

    emxInit_real_T(sp, &b_x, 2, &i_emlrtRTEI, true);
    i6 = layers->size[0];
    if (!(1 <= i6)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i6, &tc_emlrtBCI, sp);
    }

    nextLayRough = layers->data[layers->size[0] << 1];
    st.site = &q_emlrtRSI;
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
    b_st.site = &jb_emlrtRSI;
    mpower();
    layerThicks = 1.4142135623730951 * layers->data[layers->size[0] << 1];
    b_st.site = &kb_emlrtRSI;
    mpower();
    bFactor = 1.4142135623730951 * layers->data[layers->size[0] << 1];
    i6 = b_x->size[0] * b_x->size[1];
    b_x->size[0] = 1;
    b_x->size[1] = x->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)b_x, i6, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    vlen = x->size[0] * x->size[1];
    for (i6 = 0; i6 < vlen; i6++) {
      b_x->data[i6] = (x->data[i6] - -50.0) / layerThicks;
    }

    emxInit_real_T(&st, &c_x, 2, &i_emlrtRTEI, true);
    b_st.site = &lb_emlrtRSI;
    b_erf(&b_st, b_x, airBox);
    i6 = c_x->size[0] * c_x->size[1];
    c_x->size[0] = 1;
    c_x->size[1] = x->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)c_x, i6, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    vlen = x->size[0] * x->size[1];
    emxFree_real_T(&b_x);
    for (i6 = 0; i6 < vlen; i6++) {
      c_x->data[i6] = (x->data[i6] - 50.0) / bFactor;
    }

    emxInit_real_T(&st, &thisBox, 2, &m_emlrtRTEI, true);
    b_st.site = &lb_emlrtRSI;
    b_erf(&b_st, c_x, thisBox);
    emxFree_real_T(&c_x);
    for (i6 = 0; i6 < 2; i6++) {
      b_airBox[i6] = airBox->size[i6];
    }

    for (i6 = 0; i6 < 2; i6++) {
      b_thisBox[i6] = thisBox->size[i6];
    }

    if ((b_airBox[0] != b_thisBox[0]) || (b_airBox[1] != b_thisBox[1])) {
      emlrtSizeEqCheckNDR2012b(&b_airBox[0], &b_thisBox[0], &emlrtECI, &st);
    }

    layerThicks = nbair / 2.0;
    i6 = airBox->size[0] * airBox->size[1];
    airBox->size[0] = 1;
    emxEnsureCapacity(&st, (emxArray__common *)airBox, i6, (int32_T)sizeof
                      (real_T), &i_emlrtRTEI);
    vlen = airBox->size[0];
    vstride = airBox->size[1];
    vlen *= vstride;
    for (i6 = 0; i6 < vlen; i6++) {
      airBox->data[i6] = layerThicks * (airBox->data[i6] - thisBox->data[i6]);
    }

    bFactor = 50.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nrepeats, mxDOUBLE_CLASS, (int32_T)
      nrepeats, &tb_emlrtRTEI, sp);
    vstride = 0;
    emxInit_int32_T(sp, &r2, 1, &i_emlrtRTEI, true);
    while (vstride <= (int32_T)nrepeats - 1) {
      covrtLogFor(&emlrtCoverageInstance, 6U, 0U, 0, 1);
      k = 0;
      while (k <= (int32_T)numberOfLayers - 1) {
        covrtLogFor(&emlrtCoverageInstance, 6U, 0U, 1, 1);
        covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 1U);
        i6 = layers->size[0];
        mtmp = k + 1;
        if (!((mtmp >= 1) && (mtmp <= i6))) {
          emlrtDynamicBoundsCheckR2012b(mtmp, 1, i6, &sc_emlrtBCI, sp);
        }

        i6 = layers->size[0];
        mtmp = k + 1;
        if (!((mtmp >= 1) && (mtmp <= i6))) {
          emlrtDynamicBoundsCheckR2012b(mtmp, 1, i6, &rc_emlrtBCI, sp);
        }

        i6 = layers->size[0];
        mtmp = k + 1;
        if (!((mtmp >= 1) && (mtmp <= i6))) {
          emlrtDynamicBoundsCheckR2012b(mtmp, 1, i6, &qc_emlrtBCI, sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 6U, 0U, 1, 1.0 + (real_T)k <
                       numberOfLayers)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 2U);
          i6 = layers->size[0];
          mtmp = (int32_T)((1.0 + (real_T)k) + 1.0);
          if (!((mtmp >= 1) && (mtmp <= i6))) {
            emlrtDynamicBoundsCheckR2012b(mtmp, 1, i6, &uc_emlrtBCI, sp);
          }

          nextLayRough = layers->data[(mtmp + (layers->size[0] << 1)) - 1];

          /*              elseif (i == numberOfLayers) && (n < nrepeats) */
          /*                  nextLayRough = layers(1,3); */
        } else {
          covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 3U);
          nextLayRough = ssub;
        }

        covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 4U);
        layerThicks = bFactor + layers->data[k] / 2.0;
        st.site = &r_emlrtRSI;
        asymconvstep(&st, x, layers->data[k], layerThicks, layers->data[k +
                     (layers->size[0] << 1)], nextLayRough, layers->data[k +
                     layers->size[0]], thisBox);
        vlen = Lays->size[0];
        i6 = r2->size[0];
        r2->size[0] = vlen;
        emxEnsureCapacity(sp, (emxArray__common *)r2, i6, (int32_T)sizeof
                          (int32_T), &i_emlrtRTEI);
        for (i6 = 0; i6 < vlen; i6++) {
          r2->data[i6] = i6;
        }

        i6 = Lays->size[1];
        mtmp = (int32_T)((1.0 + (real_T)k) + numberOfLayers * ((1.0 + (real_T)
          vstride) - 1.0));
        if (!((mtmp >= 1) && (mtmp <= i6))) {
          emlrtDynamicBoundsCheckR2012b(mtmp, 1, i6, &nc_emlrtBCI, sp);
        }

        i6 = mtmp - 1;
        iv4[0] = r2->size[0];
        emlrtSubAssignSizeCheckR2012b(iv4, 1, *(int32_T (*)[2])thisBox->size, 2,
          &d_emlrtECI, sp);
        vlen = r2->size[0];
        for (mtmp = 0; mtmp < vlen; mtmp++) {
          Lays->data[r2->data[mtmp] + Lays->size[0] * i6] = thisBox->data[mtmp];
        }

        bFactor = layerThicks + layers->data[k] / 2.0;

        /* plot(x,Lays(:,i)); */
        k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      covrtLogFor(&emlrtCoverageInstance, 6U, 0U, 1, 0);
      vstride++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 6U, 0U, 0, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 5U);

    /* layers(end,3); */
    i6 = x->size[1];
    mtmp = x->size[1];
    if (!((mtmp >= 1) && (mtmp <= i6))) {
      emlrtDynamicBoundsCheckR2012b(mtmp, 1, i6, &pc_emlrtBCI, sp);
    }

    i6 = x->size[1];
    mtmp = x->size[1];
    if (!((mtmp >= 1) && (mtmp <= i6))) {
      emlrtDynamicBoundsCheckR2012b(mtmp, 1, i6, &oc_emlrtBCI, sp);
    }

    vlen = Lays->size[0];
    i6 = r2->size[0];
    r2->size[0] = vlen;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i6, (int32_T)sizeof(int32_T),
                      &i_emlrtRTEI);
    for (i6 = 0; i6 < vlen; i6++) {
      r2->data[i6] = i6;
    }

    i6 = Lays->size[1];
    layerThicks = numberOfLayers * nrepeats + 1.0;
    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &ab_emlrtDCI, sp);
    }

    mtmp = (int32_T)layerThicks;
    if (!((mtmp >= 1) && (mtmp <= i6))) {
      emlrtDynamicBoundsCheckR2012b(mtmp, 1, i6, &mc_emlrtBCI, sp);
    }

    i6 = mtmp - 1;
    st.site = &s_emlrtRSI;
    asymconvstep(&st, x, (x->data[x->size[1] - 1] - bFactor) * 2.0, x->data
                 [x->size[1] - 1], nextLayRough, ssub, nbsub, thisBox);
    iv3[0] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv3, 1, *(int32_T (*)[2])thisBox->size, 2,
      &c_emlrtECI, sp);
    vlen = r2->size[0];
    for (mtmp = 0; mtmp < vlen; mtmp++) {
      Lays->data[r2->data[mtmp] + Lays->size[0] * i6] = thisBox->data[mtmp];
    }

    emxFree_real_T(&thisBox);

    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+1)) */
    vlen = Lays->size[0];
    i6 = r2->size[0];
    r2->size[0] = vlen;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i6, (int32_T)sizeof(int32_T),
                      &i_emlrtRTEI);
    for (i6 = 0; i6 < vlen; i6++) {
      r2->data[i6] = i6;
    }

    i6 = Lays->size[1];
    layerThicks = numberOfLayers * nrepeats + 2.0;
    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &y_emlrtDCI, sp);
    }

    mtmp = (int32_T)layerThicks;
    if (!((mtmp >= 1) && (mtmp <= i6))) {
      emlrtDynamicBoundsCheckR2012b(mtmp, 1, i6, &lc_emlrtBCI, sp);
    }

    i6 = mtmp - 1;
    iv5[0] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv5, 1, *(int32_T (*)[2])airBox->size, 2,
      &b_emlrtECI, sp);
    vlen = r2->size[0];
    for (mtmp = 0; mtmp < vlen; mtmp++) {
      Lays->data[r2->data[mtmp] + Lays->size[0] * i6] = airBox->data[mtmp];
    }

    emxFree_int32_T(&r2);
    emxInit_real_T1(sp, &b_SLD, 1, &i_emlrtRTEI, true);

    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+2)) */
    st.site = &t_emlrtRSI;
    b_st.site = &ab_emlrtRSI;
    c_st.site = &bb_emlrtRSI;
    i6 = b_SLD->size[0];
    b_SLD->size[0] = Lays->size[0];
    emxEnsureCapacity(&c_st, (emxArray__common *)b_SLD, i6, (int32_T)sizeof
                      (real_T), &i_emlrtRTEI);
    if ((Lays->size[0] == 0) || (Lays->size[1] == 0)) {
      vlen = b_SLD->size[0];
      i6 = b_SLD->size[0];
      b_SLD->size[0] = vlen;
      emxEnsureCapacity(&c_st, (emxArray__common *)b_SLD, i6, (int32_T)sizeof
                        (real_T), &i_emlrtRTEI);
      for (i6 = 0; i6 < vlen; i6++) {
        b_SLD->data[i6] = 0.0;
      }
    } else {
      vlen = Lays->size[1];
      vstride = Lays->size[0];
      d_st.site = &pb_emlrtRSI;
      overflow = (Lays->size[0] > 2147483646);
      if (overflow) {
        e_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (mtmp = 0; mtmp + 1 <= vstride; mtmp++) {
        layerThicks = Lays->data[mtmp];
        d_st.site = &qb_emlrtRSI;
        if ((!(2 > vlen)) && (vlen > 2147483646)) {
          e_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (k = 2; k <= vlen; k++) {
          layerThicks += Lays->data[mtmp + (k - 1) * vstride];
        }

        b_SLD->data[mtmp] = layerThicks;
      }
    }

    emxFree_real_T(&Lays);
    i6 = SLD->size[0] * SLD->size[1];
    SLD->size[0] = b_SLD->size[0];
    SLD->size[1] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)SLD, i6, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    vlen = b_SLD->size[0];
    for (i6 = 0; i6 < vlen; i6++) {
      SLD->data[i6] = b_SLD->data[i6];
    }

    emxFree_real_T(&b_SLD);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 6U);
    i6 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = 101;
    emxEnsureCapacity(sp, (emxArray__common *)x, i6, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    for (i6 = 0; i6 < 101; i6++) {
      x->data[i6] = i6;
    }

    st.site = &u_emlrtRSI;
    b_st.site = &rb_emlrtRSI;
    c_st.site = &sb_emlrtRSI;
    vstride = 0;
    for (vlen = 1; vlen + 1 < 102; vlen++) {
      if ((int8_T)vlen > vstride) {
        vstride = (int8_T)vlen;
      }
    }

    st.site = &v_emlrtRSI;
    b_st.site = &rb_emlrtRSI;
    c_st.site = &sb_emlrtRSI;
    mtmp = 0;
    for (vlen = 1; vlen + 1 < 102; vlen++) {
      if ((int8_T)vlen > mtmp) {
        mtmp = (int8_T)vlen;
      }
    }

    emxInit_real_T(sp, &r0, 2, &i_emlrtRTEI, true);
    i6 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    r0->size[1] = 101;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i6, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    for (i6 = 0; i6 < 101; i6++) {
      r0->data[i6] = i6;
    }

    st.site = &w_emlrtRSI;
    b_asymconvstep(&st, r0->data, mtmp, 0.0, ssub, ssub, nbair, subBox_data,
                   subBox_size);
    i6 = airBox->size[0] * airBox->size[1];
    airBox->size[0] = 1;
    airBox->size[1] = 101;
    emxEnsureCapacity(sp, (emxArray__common *)airBox, i6, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    emxFree_real_T(&r0);
    for (i6 = 0; i6 < 101; i6++) {
      airBox->data[i6] = subBox_data[i6];
    }

    emxInit_real_T(sp, &r1, 2, &i_emlrtRTEI, true);
    i6 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = 101;
    emxEnsureCapacity(sp, (emxArray__common *)r1, i6, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    for (i6 = 0; i6 < 101; i6++) {
      r1->data[i6] = i6;
    }

    st.site = &x_emlrtRSI;
    b_asymconvstep(&st, r1->data, mtmp, vstride, ssub, ssub, nbsub, subBox_data,
                   subBox_size);
    i6 = SLD->size[0] * SLD->size[1];
    SLD->size[0] = 1;
    SLD->size[1] = airBox->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)SLD, i6, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    vlen = airBox->size[0] * airBox->size[1];
    emxFree_real_T(&r1);
    for (i6 = 0; i6 < vlen; i6++) {
      SLD->data[i6] = airBox->data[i6] + subBox_data[i6];
    }
  }

  emxFree_real_T(&airBox);
  covrtLogBasicBlock(&emlrtCoverageInstance, 6U, 7U);

  /* plot(x,SLD) */
  st.site = &y_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  overflow = true;
  vstride = x->size[1];
  vlen = SLD->size[0] * SLD->size[1];
  if (vstride != vlen) {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&c_st, &rb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  vstride = x->size[1];
  vlen = SLD->size[0] * SLD->size[1];
  i6 = out->size[0] * out->size[1];
  out->size[0] = vstride;
  out->size[1] = 2;
  emxEnsureCapacity(&b_st, (emxArray__common *)out, i6, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  for (i6 = 0; i6 < vstride; i6++) {
    out->data[i6] = x->data[i6];
  }

  emxFree_real_T(&x);
  for (i6 = 0; i6 < vlen; i6++) {
    out->data[i6 + out->size[0]] = SLD->data[i6];
  }

  emxFree_real_T(&SLD);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (makeSLDProfileXY.c) */
