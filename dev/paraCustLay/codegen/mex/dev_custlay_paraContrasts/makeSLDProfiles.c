/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * makeSLDProfiles.c
 *
 * Code generation for function 'makeSLDProfiles'
 *
 */

/* Include files */
#include "makeSLDProfiles.h"
#include "asymconvstep.h"
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = {
    12,                /* lineNo */
    "makeSLDProfiles", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfiles.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    4,                  /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    11,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    26,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    37,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    42,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    45,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    47,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    48,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    49,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    54,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pathName */
};

static emlrtECInfo g_emlrtECI = {
    -1,                 /* nDims */
    40,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtBCInfo pd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    40,                 /* lineNo */
    12,                 /* colNo */
    "Lays",             /* aName */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    0                     /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = {
    40,                 /* lineNo */
    12,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    1                     /* checkKind */
};

static emlrtECInfo h_emlrtECI = {
    -1,                 /* nDims */
    37,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtBCInfo qd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    37,                 /* lineNo */
    12,                 /* colNo */
    "Lays",             /* aName */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    0                     /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = {
    37,                 /* lineNo */
    12,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    1                     /* checkKind */
};

static emlrtECInfo i_emlrtECI = {
    -1,                 /* nDims */
    27,                 /* lineNo */
    13,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtBCInfo rd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    27,                 /* lineNo */
    20,                 /* colNo */
    "Lays",             /* aName */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    33,                 /* lineNo */
    23,                 /* colNo */
    "x",                /* aName */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    16,                 /* lineNo */
    33,                 /* colNo */
    "layers",           /* aName */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    0                     /* checkKind */
};

static emlrtRTEInfo j_emlrtRTEI = {
    13,                 /* lineNo */
    13,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtDCInfo r_emlrtDCI = {
    7,                  /* lineNo */
    28,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    1                     /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = {
    7,                  /* lineNo */
    28,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    4                     /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = {
    7,                  /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    1                     /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = {
    7,                  /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    4                     /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    15,                 /* lineNo */
    28,                 /* colNo */
    "layers",           /* aName */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    0                     /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    19,                 /* lineNo */
    32,                 /* colNo */
    "layers",           /* aName */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m", /* pName */
    0                     /* checkKind */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    44,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    4,                  /* lineNo */
    23,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    6,                  /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = {
    7,                  /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = {
    44,                 /* lineNo */
    9,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = {
    50,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = {
    42,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo id_emlrtRTEI = {
    12,                /* lineNo */
    1,                 /* colNo */
    "makeSLDProfiles", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfiles.m" /* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = {
    11,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = {
    26,                 /* lineNo */
    13,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/makeSLDProfiles/"
    "makeSLDProfileXY.m" /* pName */
};

/* Function Definitions */
void makeSLDProfiles(const emlrtStack *sp, real_T nbair, real_T nbsub,
                     const emxArray_real_T *sld, real_T ssub,
                     const real_T repeats[2], emxArray_real_T *sldProfile)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_real_T *Lays;
  emxArray_real_T *SLD;
  emxArray_real_T *airBox;
  emxArray_real_T *b_sld;
  emxArray_real_T *r;
  emxArray_real_T *thisBox;
  emxArray_real_T *x;
  real_T subBox_data[101];
  real_T lastBoxEdge;
  real_T layerThicks;
  real_T nextLayRough;
  real_T nrepeats;
  real_T thisLayThick;
  int32_T b_i;
  int32_T ex;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T n;
  int32_T numberOfLayers;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  numberOfLayers = sld->size[0];
  if (repeats[0] == 0.0) {
    nrepeats = 1.0;
  } else {
    nrepeats = repeats[1];
  }
  st.site = &y_emlrtRSI;
  emxInit_real_T(&st, &x, 2, &dd_emlrtRTEI, true);
  emxInit_real_T(&st, &airBox, 2, &jd_emlrtRTEI, true);
  emxInit_real_T(&st, &thisBox, 2, &kd_emlrtRTEI, true);
  emxInit_real_T(&st, &SLD, 2, &hd_emlrtRTEI, true);
  if (sld->size[0] > 0) {
    emxInit_real_T(&st, &b_sld, 1, &cd_emlrtRTEI, true);
    k = sld->size[0];
    i = b_sld->size[0];
    b_sld->size[0] = sld->size[0];
    emxEnsureCapacity_real_T(&st, b_sld, i, &cd_emlrtRTEI);
    for (i = 0; i < k; i++) {
      b_sld->data[i] = sld->data[i];
    }
    b_st.site = &ab_emlrtRSI;
    layerThicks = sum(&b_st, b_sld);
    layerThicks = layerThicks * nrepeats + 150.0;
    if (muDoubleScalarIsNaN(layerThicks)) {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity_real_T(&st, x, i, &dd_emlrtRTEI);
      x->data[0] = rtNaN;
    } else if (layerThicks < 0.0) {
      x->size[0] = 1;
      x->size[1] = 0;
    } else if (muDoubleScalarIsInf(layerThicks) && (0.0 == layerThicks)) {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity_real_T(&st, x, i, &dd_emlrtRTEI);
      x->data[0] = rtNaN;
    } else {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      k = (int32_T)muDoubleScalarFloor(layerThicks);
      x->size[1] = k + 1;
      emxEnsureCapacity_real_T(&st, x, i, &dd_emlrtRTEI);
      for (i = 0; i <= k; i++) {
        x->data[i] = i;
      }
    }
    emxInit_real_T(&st, &Lays, 2, &ed_emlrtRTEI, true);
    i = Lays->size[0] * Lays->size[1];
    Lays->size[0] = x->size[1];
    emxEnsureCapacity_real_T(&st, Lays, i, &ed_emlrtRTEI);
    layerThicks = (real_T)sld->size[0] * nrepeats + 2.0;
    if (!(layerThicks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(layerThicks, &s_emlrtDCI, &st);
    }
    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &r_emlrtDCI, &st);
    }
    i = Lays->size[0] * Lays->size[1];
    Lays->size[1] = (int32_T)layerThicks;
    emxEnsureCapacity_real_T(&st, Lays, i, &ed_emlrtRTEI);
    layerThicks = (real_T)sld->size[0] * nrepeats + 2.0;
    if (!(layerThicks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(layerThicks, &u_emlrtDCI, &st);
    }
    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &t_emlrtDCI, &st);
    }
    k = x->size[1] * (int32_T)layerThicks;
    for (i = 0; i < k; i++) {
      Lays->data[i] = 0.0;
    }
    nextLayRough = sld->data[sld->size[0] * 2];
    b_st.site = &bb_emlrtRSI;
    asymconvstep(&b_st, x, 100.0, 0.0, nextLayRough, nextLayRough, nbair,
                 airBox);
    lastBoxEdge = 50.0;
    i = (int32_T)nrepeats;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, nrepeats, mxDOUBLE_CLASS,
                                  (int32_T)nrepeats, &j_emlrtRTEI, &st);
    for (n = 0; n < i; n++) {
      for (b_i = 0; b_i < numberOfLayers; b_i++) {
        if (b_i + 1 > sld->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sld->size[0], &ud_emlrtBCI,
                                        &st);
        }
        thisLayThick = sld->data[b_i];
        if (b_i + 1 > sld->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sld->size[0], &td_emlrtBCI,
                                        &st);
        }
        if (b_i + 1 < numberOfLayers) {
          if (((int32_T)(b_i + 2U) < 1) ||
              ((int32_T)(b_i + 2U) > sld->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 2U), 1, sld->size[0],
                                          &vd_emlrtBCI, &st);
          }
          nextLayRough = sld->data[(b_i + sld->size[0] * 2) + 1];
          /*              elseif (i == numberOfLayers) && (n < nrepeats) */
          /*                  nextLayRough = layers(1,3); */
        } else {
          nextLayRough = ssub;
        }
        layerThicks = lastBoxEdge + thisLayThick / 2.0;
        b_st.site = &cb_emlrtRSI;
        asymconvstep(&b_st, x, thisLayThick, layerThicks,
                     sld->data[b_i + sld->size[0] * 2], nextLayRough,
                     sld->data[b_i + sld->size[0]], thisBox);
        ex = (int32_T)(((real_T)b_i + 1.0) +
                       (real_T)numberOfLayers * (((real_T)n + 1.0) - 1.0));
        if ((ex < 1) || (ex > Lays->size[1])) {
          emlrtDynamicBoundsCheckR2012b(ex, 1, Lays->size[1], &rd_emlrtBCI,
                                        &st);
        }
        emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &thisBox->size[0], 2,
                                      &i_emlrtECI, &st);
        k = Lays->size[0];
        for (i1 = 0; i1 < k; i1++) {
          Lays->data[i1 + Lays->size[0] * (ex - 1)] = thisBox->data[i1];
        }
        lastBoxEdge = layerThicks + thisLayThick / 2.0;
        /* plot(x,Lays(:,i)); */
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    /* layers(end,3); */
    if (x->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(x->size[1], 1, x->size[1], &sd_emlrtBCI,
                                    &st);
    }
    layerThicks = (real_T)sld->size[0] * nrepeats + 1.0;
    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &q_emlrtDCI, &st);
    }
    if (((int32_T)layerThicks < 1) || ((int32_T)layerThicks > Lays->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)layerThicks, 1, Lays->size[1],
                                    &qd_emlrtBCI, &st);
    }
    b_st.site = &db_emlrtRSI;
    asymconvstep(&b_st, x, (x->data[x->size[1] - 1] - lastBoxEdge) * 2.0,
                 x->data[x->size[1] - 1], nextLayRough, ssub, nbsub, thisBox);
    emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &thisBox->size[0], 2,
                                  &h_emlrtECI, &st);
    k = Lays->size[0];
    for (i = 0; i < k; i++) {
      Lays->data[i + Lays->size[0] * ((int32_T)layerThicks - 1)] =
          thisBox->data[i];
    }
    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+1)) */
    layerThicks = (real_T)sld->size[0] * nrepeats + 2.0;
    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &p_emlrtDCI, &st);
    }
    if (((int32_T)layerThicks < 1) || ((int32_T)layerThicks > Lays->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)layerThicks, 1, Lays->size[1],
                                    &pd_emlrtBCI, &st);
    }
    emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &airBox->size[0], 2,
                                  &g_emlrtECI, &st);
    k = Lays->size[0];
    for (i = 0; i < k; i++) {
      Lays->data[i + Lays->size[0] * ((int32_T)layerThicks - 1)] =
          airBox->data[i];
    }
    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+2)) */
    b_st.site = &eb_emlrtRSI;
    b_sum(&b_st, Lays, b_sld);
    i = SLD->size[0] * SLD->size[1];
    SLD->size[0] = b_sld->size[0];
    SLD->size[1] = 1;
    emxEnsureCapacity_real_T(&st, SLD, i, &hd_emlrtRTEI);
    k = b_sld->size[0];
    emxFree_real_T(&Lays);
    for (i = 0; i < k; i++) {
      SLD->data[i] = b_sld->data[i];
    }
    emxFree_real_T(&b_sld);
  } else {
    i = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = 101;
    emxEnsureCapacity_real_T(&st, x, i, &bd_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      x->data[i] = i;
    }
    b_st.site = &fb_emlrtRSI;
    c_st.site = &ad_emlrtRSI;
    d_st.site = &bd_emlrtRSI;
    e_st.site = &cd_emlrtRSI;
    f_st.site = &dd_emlrtRSI;
    numberOfLayers = 0;
    for (k = 0; k < 100; k++) {
      if (numberOfLayers < k + 1) {
        numberOfLayers = k + 1;
      }
    }
    b_st.site = &gb_emlrtRSI;
    c_st.site = &ad_emlrtRSI;
    d_st.site = &bd_emlrtRSI;
    e_st.site = &cd_emlrtRSI;
    f_st.site = &dd_emlrtRSI;
    g_st.site = &ed_emlrtRSI;
    ex = 0;
    for (k = 0; k < 100; k++) {
      if (ex < k + 1) {
        ex = k + 1;
      }
    }
    emxInit_real_T(&g_st, &r, 2, &fd_emlrtRTEI, true);
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = 101;
    emxEnsureCapacity_real_T(&st, r, i, &fd_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      r->data[i] = i;
    }
    b_st.site = &hb_emlrtRSI;
    asymconvstep(&b_st, r, ex, 0.0, ssub, ssub, nbair, airBox);
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = 101;
    emxEnsureCapacity_real_T(&st, r, i, &fd_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      r->data[i] = i;
    }
    b_st.site = &ib_emlrtRSI;
    asymconvstep(&b_st, r, ex, numberOfLayers, ssub, ssub, nbsub, thisBox);
    k = thisBox->size[1];
    emxFree_real_T(&r);
    for (i = 0; i < k; i++) {
      subBox_data[i] = thisBox->data[i];
    }
    i = SLD->size[0] * SLD->size[1];
    SLD->size[0] = 1;
    SLD->size[1] = airBox->size[1];
    emxEnsureCapacity_real_T(&st, SLD, i, &gd_emlrtRTEI);
    k = airBox->size[1];
    for (i = 0; i < k; i++) {
      SLD->data[i] = airBox->data[i] + subBox_data[i];
    }
  }
  emxFree_real_T(&thisBox);
  emxFree_real_T(&airBox);
  /* plot(x,SLD) */
  b_st.site = &jb_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  d_st.site = &x_emlrtRSI;
  if (SLD->size[0] * SLD->size[1] != x->size[1]) {
    emlrtErrorWithMessageIdR2018a(&d_st, &h_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  numberOfLayers = SLD->size[0] * SLD->size[1];
  i = sldProfile->size[0] * sldProfile->size[1];
  sldProfile->size[0] = x->size[1];
  sldProfile->size[1] = 2;
  emxEnsureCapacity_real_T(&c_st, sldProfile, i, &id_emlrtRTEI);
  k = x->size[1];
  for (i = 0; i < k; i++) {
    sldProfile->data[i] = x->data[i];
  }
  emxFree_real_T(&x);
  for (i = 0; i < numberOfLayers; i++) {
    sldProfile->data[i + sldProfile->size[0]] = SLD->data[i];
  }
  emxFree_real_T(&SLD);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (makeSLDProfiles.c) */
