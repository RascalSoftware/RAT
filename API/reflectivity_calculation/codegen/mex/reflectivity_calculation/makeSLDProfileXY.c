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
#include "makeSLDProfileXY.h"
#include "asymconvstep.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 4,   /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 11, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 26, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 37, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 42, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 45, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 47, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 48, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 49, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 54, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 169,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 187,/* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 145,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 1019,/* lineNo */
  "maxRealVectorOmitNaN",              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 932,/* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtBCInfo xf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  32,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  28,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 7,  /* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 7,  /* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = { 7,  /* lineNo */
  28,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = { 7,  /* lineNo */
  28,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  40,                                  /* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtBCInfo ag_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  12,                                  /* colNo */
  "Lays",                              /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = { 40, /* lineNo */
  12,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  37,                                  /* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtBCInfo bg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  12,                                  /* colNo */
  "Lays",                              /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = { 37, /* lineNo */
  12,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  27,                                  /* lineNo */
  13,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtBCInfo cg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  20,                                  /* colNo */
  "Lays",                              /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  23,                                  /* colNo */
  "x",                                 /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  23,                                  /* colNo */
  "x",                                 /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  35,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  33,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo jb_emlrtRTEI = { 13,/* lineNo */
  13,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtBCInfo hg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  27,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ii_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo ji_emlrtRTEI = { 4,/* lineNo */
  23,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo ki_emlrtRTEI = { 6,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo li_emlrtRTEI = { 7,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo mi_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo ni_emlrtRTEI = { 50,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo oi_emlrtRTEI = { 42,/* lineNo */
  11,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo pi_emlrtRTEI = { 125,/* lineNo */
  13,                                  /* colNo */
  "combineVectorElements",             /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pName */
};

static emlrtRTEInfo qi_emlrtRTEI = { 54,/* lineNo */
  1,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo ri_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo si_emlrtRTEI = { 11,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo ti_emlrtRTEI = { 26,/* lineNo */
  13,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

/* Function Definitions */
void makeSLDProfileXY(const emlrtStack *sp, real_T nbair, real_T nbsub, real_T
                      ssub, const emxArray_real_T *layers, real_T numberOfLayers,
                      real_T nrepeats, emxArray_real_T *out)
{
  emxArray_real_T *x;
  emxArray_real_T *airBox;
  emxArray_real_T *thisBox;
  emxArray_real_T *SLD;
  int32_T i;
  emxArray_real_T *b_layers;
  int32_T vlen;
  real_T layerThicks;
  int32_T xoffset;
  emxArray_real_T *Lays;
  int32_T k;
  real_T d;
  real_T d1;
  int32_T vstride;
  real_T nextLayRough;
  emxArray_real_T *r;
  int32_T n;
  int32_T b_i;
  real_T thisLayThick;
  real_T subBox_data[101];
  int32_T i1;
  uint32_T sz_idx_0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &x, 2, &ki_emlrtRTEI, true);
  emxInit_real_T(sp, &airBox, 2, &si_emlrtRTEI, true);
  emxInit_real_T(sp, &thisBox, 2, &ti_emlrtRTEI, true);
  emxInit_real_T(sp, &SLD, 2, &ri_emlrtRTEI, true);
  if (numberOfLayers > 0.0) {
    emxInit_real_T(sp, &b_layers, 1, &ji_emlrtRTEI, true);
    vlen = layers->size[0];
    i = b_layers->size[0];
    b_layers->size[0] = layers->size[0];
    emxEnsureCapacity_real_T(sp, b_layers, i, &ji_emlrtRTEI);
    for (i = 0; i < vlen; i++) {
      b_layers->data[i] = layers->data[i];
    }

    st.site = &y_emlrtRSI;
    layerThicks = sum(&st, b_layers);
    layerThicks = layerThicks * nrepeats + 150.0;
    if (muDoubleScalarIsNaN(layerThicks)) {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity_real_T(sp, x, i, &ki_emlrtRTEI);
      x->data[0] = rtNaN;
    } else if (layerThicks < 0.0) {
      x->size[0] = 1;
      x->size[1] = 0;
    } else if (muDoubleScalarIsInf(layerThicks) && (0.0 == layerThicks)) {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity_real_T(sp, x, i, &ki_emlrtRTEI);
      x->data[0] = rtNaN;
    } else {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      vlen = (int32_T)muDoubleScalarFloor(layerThicks);
      x->size[1] = vlen + 1;
      emxEnsureCapacity_real_T(sp, x, i, &ki_emlrtRTEI);
      for (i = 0; i <= vlen; i++) {
        x->data[i] = i;
      }
    }

    emxInit_real_T(sp, &Lays, 2, &li_emlrtRTEI, true);
    i = Lays->size[0] * Lays->size[1];
    Lays->size[0] = x->size[1];
    emxEnsureCapacity_real_T(sp, Lays, i, &li_emlrtRTEI);
    d = numberOfLayers * nrepeats;
    if (!(d + 2.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d + 2.0, &db_emlrtDCI, sp);
    }

    d1 = (int32_T)muDoubleScalarFloor(d + 2.0);
    if (d + 2.0 != d1) {
      emlrtIntegerCheckR2012b(d + 2.0, &eb_emlrtDCI, sp);
    }

    i = Lays->size[0] * Lays->size[1];
    vstride = (int32_T)(d + 2.0);
    Lays->size[1] = vstride;
    emxEnsureCapacity_real_T(sp, Lays, i, &li_emlrtRTEI);
    if (!(d + 2.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d + 2.0, &bb_emlrtDCI, sp);
    }

    if (d + 2.0 != d1) {
      emlrtIntegerCheckR2012b(d + 2.0, &cb_emlrtDCI, sp);
    }

    vlen = x->size[1] * vstride;
    for (i = 0; i < vlen; i++) {
      Lays->data[i] = 0.0;
    }

    if (1 > layers->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, layers->size[0], &hg_emlrtBCI, sp);
    }

    nextLayRough = layers->data[layers->size[0] * 2];
    st.site = &ab_emlrtRSI;
    asymconvstep(&st, x, 100.0, 0.0, nextLayRough, nextLayRough, nbair, airBox);
    layerThicks = 50.0;
    i = (int32_T)nrepeats;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nrepeats, mxDOUBLE_CLASS, (int32_T)
      nrepeats, &jb_emlrtRTEI, sp);
    for (n = 0; n < i; n++) {
      k = (int32_T)numberOfLayers;
      for (b_i = 0; b_i < k; b_i++) {
        xoffset = (int32_T)(b_i + 1U);
        if ((xoffset < 1) || (xoffset > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(xoffset, 1, layers->size[0],
            &yf_emlrtBCI, sp);
        }

        thisLayThick = layers->data[xoffset - 1];
        xoffset = b_i + 1;
        if ((xoffset < 1) || (xoffset > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(xoffset, 1, layers->size[0],
            &gg_emlrtBCI, sp);
        }

        xoffset = b_i + 1;
        if ((xoffset < 1) || (xoffset > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(xoffset, 1, layers->size[0],
            &fg_emlrtBCI, sp);
        }

        if ((real_T)b_i + 1.0 < numberOfLayers) {
          xoffset = (int32_T)(b_i + 2U);
          if ((xoffset < 1) || (xoffset > layers->size[0])) {
            emlrtDynamicBoundsCheckR2012b(xoffset, 1, layers->size[0],
              &xf_emlrtBCI, sp);
          }

          nextLayRough = layers->data[(xoffset + layers->size[0] * 2) - 1];

          /*              elseif (i == numberOfLayers) && (n < nrepeats) */
          /*                  nextLayRough = layers(1,3); */
        } else {
          nextLayRough = ssub;
        }

        layerThicks += thisLayThick / 2.0;
        st.site = &bb_emlrtRSI;
        asymconvstep(&st, x, thisLayThick, layerThicks, layers->data[b_i +
                     layers->size[0] * 2], nextLayRough, layers->data[b_i +
                     layers->size[0]], thisBox);
        xoffset = (int32_T)(((real_T)b_i + 1.0) + numberOfLayers * (((real_T)n +
          1.0) - 1.0));
        if ((xoffset < 1) || (xoffset > Lays->size[1])) {
          emlrtDynamicBoundsCheckR2012b(xoffset, 1, Lays->size[1], &cg_emlrtBCI,
            sp);
        }

        xoffset--;
        emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &thisBox->size[0], 2,
          &c_emlrtECI, sp);
        vlen = Lays->size[0];
        for (i1 = 0; i1 < vlen; i1++) {
          Lays->data[i1 + Lays->size[0] * xoffset] = thisBox->data[i1];
        }

        layerThicks += thisLayThick / 2.0;

        /* plot(x,Lays(:,i)); */
      }
    }

    /* layers(end,3); */
    if (x->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(x->size[1], 1, x->size[1], &eg_emlrtBCI, sp);
    }

    if (x->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(x->size[1], 1, x->size[1], &dg_emlrtBCI, sp);
    }

    if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
      emlrtIntegerCheckR2012b(d + 1.0, &gb_emlrtDCI, sp);
    }

    i = (int32_T)(d + 1.0);
    if ((i < 1) || (i > Lays->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, Lays->size[1], &bg_emlrtBCI, sp);
    }

    i--;
    st.site = &cb_emlrtRSI;
    asymconvstep(&st, x, (x->data[x->size[1] - 1] - layerThicks) * 2.0, x->
                 data[x->size[1] - 1], nextLayRough, ssub, nbsub, thisBox);
    emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &thisBox->size[0], 2,
      &b_emlrtECI, sp);
    vlen = Lays->size[0];
    for (k = 0; k < vlen; k++) {
      Lays->data[k + Lays->size[0] * i] = thisBox->data[k];
    }

    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+1)) */
    if (d + 2.0 != d1) {
      emlrtIntegerCheckR2012b(d + 2.0, &fb_emlrtDCI, sp);
    }

    if ((vstride < 1) || (vstride > Lays->size[1])) {
      emlrtDynamicBoundsCheckR2012b(vstride, 1, Lays->size[1], &ag_emlrtBCI, sp);
    }

    i = vstride - 1;
    emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &airBox->size[0], 2,
      &emlrtECI, sp);
    vlen = Lays->size[0];
    for (vstride = 0; vstride < vlen; vstride++) {
      Lays->data[vstride + Lays->size[0] * i] = airBox->data[vstride];
    }

    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+2)) */
    st.site = &db_emlrtRSI;
    b_st.site = &jb_emlrtRSI;
    c_st.site = &kb_emlrtRSI;
    vlen = Lays->size[1];
    if ((Lays->size[0] == 0) || (Lays->size[1] == 0)) {
      sz_idx_0 = (uint32_T)Lays->size[0];
      i = b_layers->size[0];
      b_layers->size[0] = (int32_T)sz_idx_0;
      emxEnsureCapacity_real_T(&c_st, b_layers, i, &oi_emlrtRTEI);
      vlen = (int32_T)sz_idx_0;
      for (i = 0; i < vlen; i++) {
        b_layers->data[i] = 0.0;
      }
    } else {
      d_st.site = &lb_emlrtRSI;
      vstride = Lays->size[0];
      i = b_layers->size[0];
      b_layers->size[0] = Lays->size[0];
      emxEnsureCapacity_real_T(&d_st, b_layers, i, &pi_emlrtRTEI);
      e_st.site = &kc_emlrtRSI;
      if (Lays->size[0] > 2147483646) {
        f_st.site = &nb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (n = 0; n < vstride; n++) {
        b_layers->data[n] = Lays->data[n];
      }

      e_st.site = &mb_emlrtRSI;
      if ((2 <= Lays->size[1]) && (Lays->size[1] > 2147483646)) {
        f_st.site = &nb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (k = 2; k <= vlen; k++) {
        xoffset = (k - 1) * vstride;
        e_st.site = &lc_emlrtRSI;
        if (vstride > 2147483646) {
          f_st.site = &nb_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (n = 0; n < vstride; n++) {
          b_layers->data[n] += Lays->data[xoffset + n];
        }
      }
    }

    emxFree_real_T(&Lays);
    i = SLD->size[0] * SLD->size[1];
    SLD->size[0] = b_layers->size[0];
    SLD->size[1] = 1;
    emxEnsureCapacity_real_T(sp, SLD, i, &ri_emlrtRTEI);
    vlen = b_layers->size[0];
    for (i = 0; i < vlen; i++) {
      SLD->data[i] = b_layers->data[i];
    }

    emxFree_real_T(&b_layers);
  } else {
    i = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = 101;
    emxEnsureCapacity_real_T(sp, x, i, &ii_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      x->data[i] = i;
    }

    st.site = &eb_emlrtRSI;
    b_st.site = &mc_emlrtRSI;
    c_st.site = &nc_emlrtRSI;
    d_st.site = &oc_emlrtRSI;
    e_st.site = &pc_emlrtRSI;
    f_st.site = &qc_emlrtRSI;
    xoffset = 0;
    for (k = 0; k < 100; k++) {
      if (xoffset < k + 1) {
        xoffset = k + 1;
      }
    }

    st.site = &fb_emlrtRSI;
    b_st.site = &mc_emlrtRSI;
    c_st.site = &nc_emlrtRSI;
    d_st.site = &oc_emlrtRSI;
    e_st.site = &pc_emlrtRSI;
    f_st.site = &qc_emlrtRSI;
    g_st.site = &rc_emlrtRSI;
    vlen = 0;
    for (k = 0; k < 100; k++) {
      if (vlen < k + 1) {
        vlen = k + 1;
      }
    }

    emxInit_real_T(&g_st, &r, 2, &mi_emlrtRTEI, true);
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = 101;
    emxEnsureCapacity_real_T(sp, r, i, &mi_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      r->data[i] = i;
    }

    st.site = &gb_emlrtRSI;
    asymconvstep(&st, r, vlen, 0.0, ssub, ssub, nbair, airBox);
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = 101;
    emxEnsureCapacity_real_T(sp, r, i, &mi_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      r->data[i] = i;
    }

    st.site = &hb_emlrtRSI;
    asymconvstep(&st, r, vlen, xoffset, ssub, ssub, nbsub, thisBox);
    vlen = thisBox->size[0] * thisBox->size[1];
    emxFree_real_T(&r);
    for (i = 0; i < vlen; i++) {
      subBox_data[i] = thisBox->data[i];
    }

    i = SLD->size[0] * SLD->size[1];
    SLD->size[0] = 1;
    SLD->size[1] = airBox->size[1];
    emxEnsureCapacity_real_T(sp, SLD, i, &ni_emlrtRTEI);
    vlen = airBox->size[0] * airBox->size[1];
    for (i = 0; i < vlen; i++) {
      SLD->data[i] = airBox->data[i] + subBox_data[i];
    }
  }

  emxFree_real_T(&thisBox);
  emxFree_real_T(&airBox);

  /* plot(x,SLD) */
  st.site = &ib_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  if (SLD->size[0] * SLD->size[1] != x->size[1]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  xoffset = SLD->size[0] * SLD->size[1];
  i = out->size[0] * out->size[1];
  out->size[0] = x->size[1];
  out->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, out, i, &qi_emlrtRTEI);
  vlen = x->size[1];
  for (i = 0; i < vlen; i++) {
    out->data[i] = x->data[i];
  }

  emxFree_real_T(&x);
  for (i = 0; i < xoffset; i++) {
    out->data[i + out->size[0]] = SLD->data[i];
  }

  emxFree_real_T(&SLD);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (makeSLDProfileXY.c) */
