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
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = {
    12,                /* lineNo */
    "makeSLDProfiles", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfiles.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    4,                  /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    11,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    26,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    37,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    42,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    45,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    47,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    48,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    49,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    54,                 /* lineNo */
    "makeSLDProfileXY", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pathName */
};

static emlrtRSInfo sd_emlrtRSI = {
    180,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo td_emlrtRSI = {
    891,                    /* lineNo */
    "maxRealVectorOmitNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                 /* nDims */
    40,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtBCInfo cg_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    40,                 /* lineNo */
    12,                 /* colNo */
    "Lays",             /* aName */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    0                                  /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = {
    40,                 /* lineNo */
    12,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    1                                  /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    -1,                 /* nDims */
    37,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtBCInfo dg_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    37,                 /* lineNo */
    12,                 /* colNo */
    "Lays",             /* aName */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    0                                  /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = {
    37,                 /* lineNo */
    12,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    1                                  /* checkKind */
};

static emlrtECInfo d_emlrtECI = {
    -1,                 /* nDims */
    27,                 /* lineNo */
    13,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtBCInfo eg_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    27,                 /* lineNo */
    20,                 /* colNo */
    "Lays",             /* aName */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo fg_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    33,                 /* lineNo */
    23,                 /* colNo */
    "x",                /* aName */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo gg_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    16,                 /* lineNo */
    33,                 /* colNo */
    "layers",           /* aName */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    0                                  /* checkKind */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    13,                 /* lineNo */
    13,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtDCInfo gb_emlrtDCI = {
    7,                  /* lineNo */
    28,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    1                                  /* checkKind */
};

static emlrtDCInfo hb_emlrtDCI = {
    7,                  /* lineNo */
    28,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    4                                  /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = {
    7,                  /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    1                                  /* checkKind */
};

static emlrtDCInfo jb_emlrtDCI = {
    7,                  /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    4                                  /* checkKind */
};

static emlrtBCInfo hg_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    15,                 /* lineNo */
    28,                 /* colNo */
    "layers",           /* aName */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo ig_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    19,                 /* lineNo */
    32,                 /* colNo */
    "layers",           /* aName */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m", /* pName */
    0                                  /* checkKind */
};

static emlrtRTEInfo yh_emlrtRTEI = {
    44,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo ai_emlrtRTEI = {
    4,                  /* lineNo */
    23,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo bi_emlrtRTEI = {
    6,                  /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo ci_emlrtRTEI = {
    7,                  /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo di_emlrtRTEI = {
    44,                 /* lineNo */
    9,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo ei_emlrtRTEI = {
    50,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo fi_emlrtRTEI = {
    42,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo gi_emlrtRTEI = {
    12,                /* lineNo */
    1,                 /* colNo */
    "makeSLDProfiles", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfiles.m" /* pName */
};

static emlrtRTEInfo hi_emlrtRTEI = {
    11,                 /* lineNo */
    5,                  /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
};

static emlrtRTEInfo ii_emlrtRTEI = {
    26,                 /* lineNo */
    13,                 /* colNo */
    "makeSLDProfileXY", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\make"
    "SLDProfiles\\makeSLDProfileXY.m" /* pName */
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
  st.site = &pb_emlrtRSI;
  emxInit_real_T(&st, &x, 2, &bi_emlrtRTEI, true);
  emxInit_real_T(&st, &airBox, 2, &hi_emlrtRTEI, true);
  emxInit_real_T(&st, &thisBox, 2, &ii_emlrtRTEI, true);
  emxInit_real_T(&st, &SLD, 2, &fi_emlrtRTEI, true);
  if (sld->size[0] > 0) {
    emxInit_real_T(&st, &b_sld, 1, &ai_emlrtRTEI, true);
    k = sld->size[0];
    i = b_sld->size[0];
    b_sld->size[0] = sld->size[0];
    emxEnsureCapacity_real_T(&st, b_sld, i, &ai_emlrtRTEI);
    for (i = 0; i < k; i++) {
      b_sld->data[i] = sld->data[i];
    }
    b_st.site = &qb_emlrtRSI;
    layerThicks = sum(&b_st, b_sld);
    layerThicks = layerThicks * nrepeats + 150.0;
    if (muDoubleScalarIsNaN(layerThicks)) {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity_real_T(&st, x, i, &bi_emlrtRTEI);
      x->data[0] = rtNaN;
    } else if (layerThicks < 0.0) {
      x->size[0] = 1;
      x->size[1] = 0;
    } else if (muDoubleScalarIsInf(layerThicks) && (0.0 == layerThicks)) {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity_real_T(&st, x, i, &bi_emlrtRTEI);
      x->data[0] = rtNaN;
    } else {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      k = (int32_T)muDoubleScalarFloor(layerThicks);
      x->size[1] = k + 1;
      emxEnsureCapacity_real_T(&st, x, i, &bi_emlrtRTEI);
      for (i = 0; i <= k; i++) {
        x->data[i] = i;
      }
    }
    emxInit_real_T(&st, &Lays, 2, &ci_emlrtRTEI, true);
    i = Lays->size[0] * Lays->size[1];
    Lays->size[0] = x->size[1];
    emxEnsureCapacity_real_T(&st, Lays, i, &ci_emlrtRTEI);
    layerThicks = (real_T)sld->size[0] * nrepeats + 2.0;
    if (!(layerThicks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(layerThicks, &hb_emlrtDCI, &st);
    }
    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &gb_emlrtDCI, &st);
    }
    i = Lays->size[0] * Lays->size[1];
    Lays->size[1] = (int32_T)layerThicks;
    emxEnsureCapacity_real_T(&st, Lays, i, &ci_emlrtRTEI);
    layerThicks = (real_T)sld->size[0] * nrepeats + 2.0;
    if (!(layerThicks >= 0.0)) {
      emlrtNonNegativeCheckR2012b(layerThicks, &jb_emlrtDCI, &st);
    }
    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &ib_emlrtDCI, &st);
    }
    k = x->size[1] * (int32_T)layerThicks;
    for (i = 0; i < k; i++) {
      Lays->data[i] = 0.0;
    }
    nextLayRough = sld->data[sld->size[0] * 2];
    b_st.site = &rb_emlrtRSI;
    asymconvstep(&b_st, x, 100.0, 0.0, nextLayRough, nextLayRough, nbair,
                 airBox);
    lastBoxEdge = 50.0;
    i = (int32_T)nrepeats;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, nrepeats, mxDOUBLE_CLASS,
                                  (int32_T)nrepeats, &jb_emlrtRTEI, &st);
    for (n = 0; n < i; n++) {
      for (b_i = 0; b_i < numberOfLayers; b_i++) {
        if (b_i + 1 > sld->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sld->size[0], &hg_emlrtBCI,
                                        &st);
        }
        thisLayThick = sld->data[b_i];
        if (b_i + 1 > sld->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, sld->size[0], &gg_emlrtBCI,
                                        &st);
        }
        if (b_i + 1 < numberOfLayers) {
          if (((int32_T)(b_i + 2U) < 1) ||
              ((int32_T)(b_i + 2U) > sld->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 2U), 1, sld->size[0],
                                          &ig_emlrtBCI, &st);
          }
          nextLayRough = sld->data[(b_i + sld->size[0] * 2) + 1];
          /*              elseif (i == numberOfLayers) && (n < nrepeats) */
          /*                  nextLayRough = layers(1,3); */
        } else {
          nextLayRough = ssub;
        }
        layerThicks = lastBoxEdge + thisLayThick / 2.0;
        b_st.site = &sb_emlrtRSI;
        asymconvstep(&b_st, x, thisLayThick, layerThicks,
                     sld->data[b_i + sld->size[0] * 2], nextLayRough,
                     sld->data[b_i + sld->size[0]], thisBox);
        ex = (int32_T)(((real_T)b_i + 1.0) +
                       (real_T)numberOfLayers * (((real_T)n + 1.0) - 1.0));
        if ((ex < 1) || (ex > Lays->size[1])) {
          emlrtDynamicBoundsCheckR2012b(ex, 1, Lays->size[1], &eg_emlrtBCI,
                                        &st);
        }
        emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &thisBox->size[0], 2,
                                      &d_emlrtECI, &st);
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
      emlrtDynamicBoundsCheckR2012b(x->size[1], 1, x->size[1], &fg_emlrtBCI,
                                    &st);
    }
    layerThicks = (real_T)sld->size[0] * nrepeats + 1.0;
    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &fb_emlrtDCI, &st);
    }
    if (((int32_T)layerThicks < 1) || ((int32_T)layerThicks > Lays->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)layerThicks, 1, Lays->size[1],
                                    &dg_emlrtBCI, &st);
    }
    b_st.site = &tb_emlrtRSI;
    asymconvstep(&b_st, x, (x->data[x->size[1] - 1] - lastBoxEdge) * 2.0,
                 x->data[x->size[1] - 1], nextLayRough, ssub, nbsub, thisBox);
    emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &thisBox->size[0], 2,
                                  &c_emlrtECI, &st);
    k = Lays->size[0];
    for (i = 0; i < k; i++) {
      Lays->data[i + Lays->size[0] * ((int32_T)layerThicks - 1)] =
          thisBox->data[i];
    }
    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+1)) */
    layerThicks = (real_T)sld->size[0] * nrepeats + 2.0;
    if (layerThicks != (int32_T)muDoubleScalarFloor(layerThicks)) {
      emlrtIntegerCheckR2012b(layerThicks, &eb_emlrtDCI, &st);
    }
    if (((int32_T)layerThicks < 1) || ((int32_T)layerThicks > Lays->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)layerThicks, 1, Lays->size[1],
                                    &cg_emlrtBCI, &st);
    }
    emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &airBox->size[0], 2,
                                  &b_emlrtECI, &st);
    k = Lays->size[0];
    for (i = 0; i < k; i++) {
      Lays->data[i + Lays->size[0] * ((int32_T)layerThicks - 1)] =
          airBox->data[i];
    }
    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+2)) */
    b_st.site = &ub_emlrtRSI;
    b_sum(&b_st, Lays, b_sld);
    i = SLD->size[0] * SLD->size[1];
    SLD->size[0] = b_sld->size[0];
    SLD->size[1] = 1;
    emxEnsureCapacity_real_T(&st, SLD, i, &fi_emlrtRTEI);
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
    emxEnsureCapacity_real_T(&st, x, i, &yh_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      x->data[i] = i;
    }
    b_st.site = &vb_emlrtRSI;
    c_st.site = &pd_emlrtRSI;
    d_st.site = &qd_emlrtRSI;
    e_st.site = &rd_emlrtRSI;
    f_st.site = &sd_emlrtRSI;
    numberOfLayers = 0;
    for (k = 0; k < 100; k++) {
      if (numberOfLayers < k + 1) {
        numberOfLayers = k + 1;
      }
    }
    b_st.site = &wb_emlrtRSI;
    c_st.site = &pd_emlrtRSI;
    d_st.site = &qd_emlrtRSI;
    e_st.site = &rd_emlrtRSI;
    f_st.site = &sd_emlrtRSI;
    g_st.site = &td_emlrtRSI;
    ex = 0;
    for (k = 0; k < 100; k++) {
      if (ex < k + 1) {
        ex = k + 1;
      }
    }
    emxInit_real_T(&g_st, &r, 2, &di_emlrtRTEI, true);
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = 101;
    emxEnsureCapacity_real_T(&st, r, i, &di_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      r->data[i] = i;
    }
    b_st.site = &xb_emlrtRSI;
    asymconvstep(&b_st, r, ex, 0.0, ssub, ssub, nbair, airBox);
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = 101;
    emxEnsureCapacity_real_T(&st, r, i, &di_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      r->data[i] = i;
    }
    b_st.site = &yb_emlrtRSI;
    asymconvstep(&b_st, r, ex, numberOfLayers, ssub, ssub, nbsub, thisBox);
    k = thisBox->size[1];
    emxFree_real_T(&r);
    for (i = 0; i < k; i++) {
      subBox_data[i] = thisBox->data[i];
    }
    i = SLD->size[0] * SLD->size[1];
    SLD->size[0] = 1;
    SLD->size[1] = airBox->size[1];
    emxEnsureCapacity_real_T(&st, SLD, i, &ei_emlrtRTEI);
    k = airBox->size[1];
    for (i = 0; i < k; i++) {
      SLD->data[i] = airBox->data[i] + subBox_data[i];
    }
  }
  emxFree_real_T(&thisBox);
  emxFree_real_T(&airBox);
  /* plot(x,SLD) */
  b_st.site = &ac_emlrtRSI;
  c_st.site = &nb_emlrtRSI;
  d_st.site = &ob_emlrtRSI;
  if (SLD->size[0] * SLD->size[1] != x->size[1]) {
    emlrtErrorWithMessageIdR2018a(&d_st, &hb_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  numberOfLayers = SLD->size[0] * SLD->size[1];
  i = sldProfile->size[0] * sldProfile->size[1];
  sldProfile->size[0] = x->size[1];
  sldProfile->size[1] = 2;
  emxEnsureCapacity_real_T(&c_st, sldProfile, i, &gi_emlrtRTEI);
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
