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
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo kb_emlrtRSI = { 4,  /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 11, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 26, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 37, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 42, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 45, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 47, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 48, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 49, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 54, /* lineNo */
  "makeSLDProfileXY",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 145,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 1019,/* lineNo */
  "maxRealVectorOmitNaN",              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 932,/* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  32,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  28,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = { 7,  /* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = { 7,  /* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = { 7,  /* lineNo */
  28,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = { 7,  /* lineNo */
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

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  12,                                  /* colNo */
  "Lays",                              /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo hb_emlrtDCI = { 40, /* lineNo */
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

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  12,                                  /* colNo */
  "Lays",                              /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = { 37, /* lineNo */
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

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  20,                                  /* colNo */
  "Lays",                              /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  23,                                  /* colNo */
  "x",                                 /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  23,                                  /* colNo */
  "x",                                 /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  35,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  33,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo gb_emlrtRTEI = { 13,/* lineNo */
  13,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  27,                                  /* colNo */
  "layers",                            /* aName */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo hh_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo ih_emlrtRTEI = { 4,/* lineNo */
  23,                                  /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo jh_emlrtRTEI = { 6,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo kh_emlrtRTEI = { 7,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo lh_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo mh_emlrtRTEI = { 50,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo nh_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo oh_emlrtRTEI = { 54,/* lineNo */
  1,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo ph_emlrtRTEI = { 11,/* lineNo */
  5,                                   /* colNo */
  "makeSLDProfileXY",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"/* pName */
};

static emlrtRTEInfo qh_emlrtRTEI = { 26,/* lineNo */
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
  emxArray_real_T *b_layers;
  int32_T i;
  int32_T ex;
  real_T layerThicks;
  int32_T b_ex;
  emxArray_real_T *Lays;
  int32_T k;
  real_T d;
  real_T d1;
  real_T nextLayRough;
  emxArray_real_T *r;
  int32_T n;
  int32_T i1;
  int32_T b_i;
  real_T thisLayThick;
  real_T subBox_data[101];
  int32_T i2;
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
  covrtLogFcn(&emlrtCoverageInstance, 12U, 0U);
  emxInit_real_T(sp, &x, 2, &jh_emlrtRTEI, true);
  emxInit_real_T(sp, &airBox, 2, &ph_emlrtRTEI, true);
  emxInit_real_T(sp, &thisBox, 2, &qh_emlrtRTEI, true);
  emxInit_real_T(sp, &SLD, 2, &nh_emlrtRTEI, true);
  if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 0, numberOfLayers > 0.0)) {
    emxInit_real_T(sp, &b_layers, 1, &ih_emlrtRTEI, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 0U);
    ex = layers->size[0];
    i = b_layers->size[0];
    b_layers->size[0] = layers->size[0];
    emxEnsureCapacity_real_T(sp, b_layers, i, &ih_emlrtRTEI);
    for (i = 0; i < ex; i++) {
      b_layers->data[i] = layers->data[i];
    }

    st.site = &kb_emlrtRSI;
    layerThicks = sum(&st, b_layers);
    layerThicks = layerThicks * nrepeats + 150.0;
    if (muDoubleScalarIsNaN(layerThicks)) {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity_real_T(sp, x, i, &jh_emlrtRTEI);
      x->data[0] = rtNaN;
    } else if (layerThicks < 0.0) {
      x->size[0] = 1;
      x->size[1] = 0;
    } else if (muDoubleScalarIsInf(layerThicks) && (0.0 == layerThicks)) {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = 1;
      emxEnsureCapacity_real_T(sp, x, i, &jh_emlrtRTEI);
      x->data[0] = rtNaN;
    } else {
      i = x->size[0] * x->size[1];
      x->size[0] = 1;
      ex = (int32_T)muDoubleScalarFloor(layerThicks);
      x->size[1] = ex + 1;
      emxEnsureCapacity_real_T(sp, x, i, &jh_emlrtRTEI);
      for (i = 0; i <= ex; i++) {
        x->data[i] = i;
      }
    }

    emxInit_real_T(sp, &Lays, 2, &kh_emlrtRTEI, true);
    i = Lays->size[0] * Lays->size[1];
    Lays->size[0] = x->size[1];
    emxEnsureCapacity_real_T(sp, Lays, i, &kh_emlrtRTEI);
    d = numberOfLayers * nrepeats;
    if (!(d + 2.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d + 2.0, &fb_emlrtDCI, sp);
    }

    d1 = (int32_T)muDoubleScalarFloor(d + 2.0);
    if (d + 2.0 != d1) {
      emlrtIntegerCheckR2012b(d + 2.0, &gb_emlrtDCI, sp);
    }

    i = Lays->size[0] * Lays->size[1];
    k = (int32_T)(d + 2.0);
    Lays->size[1] = k;
    emxEnsureCapacity_real_T(sp, Lays, i, &kh_emlrtRTEI);
    if (!(d + 2.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d + 2.0, &db_emlrtDCI, sp);
    }

    if (d + 2.0 != d1) {
      emlrtIntegerCheckR2012b(d + 2.0, &eb_emlrtDCI, sp);
    }

    ex = x->size[1] * k;
    for (i = 0; i < ex; i++) {
      Lays->data[i] = 0.0;
    }

    if (1 > layers->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, layers->size[0], &qd_emlrtBCI, sp);
    }

    nextLayRough = layers->data[layers->size[0] * 2];
    st.site = &lb_emlrtRSI;
    asymconvstep(&st, x, 100.0, 0.0, nextLayRough, nextLayRough, nbair, airBox);
    layerThicks = 50.0;
    i = (int32_T)nrepeats;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nrepeats, mxDOUBLE_CLASS, (int32_T)
      nrepeats, &gb_emlrtRTEI, sp);
    for (n = 0; n < i; n++) {
      covrtLogFor(&emlrtCoverageInstance, 12U, 0U, 0, 1);
      i1 = (int32_T)numberOfLayers;
      for (b_i = 0; b_i < i1; b_i++) {
        covrtLogFor(&emlrtCoverageInstance, 12U, 0U, 1, 1);
        covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 1U);
        b_ex = (int32_T)(b_i + 1U);
        if ((b_ex < 1) || (b_ex > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_ex, 1, layers->size[0], &id_emlrtBCI,
            sp);
        }

        thisLayThick = layers->data[b_ex - 1];
        b_ex = b_i + 1;
        if ((b_ex < 1) || (b_ex > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_ex, 1, layers->size[0], &pd_emlrtBCI,
            sp);
        }

        b_ex = b_i + 1;
        if ((b_ex < 1) || (b_ex > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_ex, 1, layers->size[0], &od_emlrtBCI,
            sp);
        }

        if (covrtLogIf(&emlrtCoverageInstance, 12U, 0U, 1, (real_T)b_i + 1.0 <
                       numberOfLayers)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 2U);
          b_ex = (int32_T)(b_i + 2U);
          if ((b_ex < 1) || (b_ex > layers->size[0])) {
            emlrtDynamicBoundsCheckR2012b(b_ex, 1, layers->size[0], &hd_emlrtBCI,
              sp);
          }

          nextLayRough = layers->data[(b_ex + layers->size[0] * 2) - 1];

          /*              elseif (i == numberOfLayers) && (n < nrepeats) */
          /*                  nextLayRough = layers(1,3); */
        } else {
          covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 3U);
          nextLayRough = ssub;
        }

        covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 4U);
        layerThicks += thisLayThick / 2.0;
        st.site = &mb_emlrtRSI;
        asymconvstep(&st, x, thisLayThick, layerThicks, layers->data[b_i +
                     layers->size[0] * 2], nextLayRough, layers->data[b_i +
                     layers->size[0]], thisBox);
        b_ex = (int32_T)(((real_T)b_i + 1.0) + numberOfLayers * (((real_T)n +
          1.0) - 1.0));
        if ((b_ex < 1) || (b_ex > Lays->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_ex, 1, Lays->size[1], &ld_emlrtBCI, sp);
        }

        b_ex--;
        emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &thisBox->size[0], 2,
          &c_emlrtECI, sp);
        ex = Lays->size[0];
        for (i2 = 0; i2 < ex; i2++) {
          Lays->data[i2 + Lays->size[0] * b_ex] = thisBox->data[i2];
        }

        layerThicks += thisLayThick / 2.0;

        /* plot(x,Lays(:,i)); */
      }

      covrtLogFor(&emlrtCoverageInstance, 12U, 0U, 1, 0);
    }

    covrtLogFor(&emlrtCoverageInstance, 12U, 0U, 0, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 5U);

    /* layers(end,3); */
    if (x->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(x->size[1], 1, x->size[1], &nd_emlrtBCI, sp);
    }

    if (x->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(x->size[1], 1, x->size[1], &md_emlrtBCI, sp);
    }

    if (d + 1.0 != (int32_T)muDoubleScalarFloor(d + 1.0)) {
      emlrtIntegerCheckR2012b(d + 1.0, &ib_emlrtDCI, sp);
    }

    i = (int32_T)(d + 1.0);
    if ((i < 1) || (i > Lays->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, Lays->size[1], &kd_emlrtBCI, sp);
    }

    i--;
    st.site = &nb_emlrtRSI;
    asymconvstep(&st, x, (x->data[x->size[1] - 1] - layerThicks) * 2.0, x->
                 data[x->size[1] - 1], nextLayRough, ssub, nbsub, thisBox);
    emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &thisBox->size[0], 2,
      &b_emlrtECI, sp);
    ex = Lays->size[0];
    for (i1 = 0; i1 < ex; i1++) {
      Lays->data[i1 + Lays->size[0] * i] = thisBox->data[i1];
    }

    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+1)) */
    if (d + 2.0 != d1) {
      emlrtIntegerCheckR2012b(d + 2.0, &hb_emlrtDCI, sp);
    }

    if ((k < 1) || (k > Lays->size[1])) {
      emlrtDynamicBoundsCheckR2012b(k, 1, Lays->size[1], &jd_emlrtBCI, sp);
    }

    i = k - 1;
    emlrtSubAssignSizeCheckR2012b(&Lays->size[0], 1, &airBox->size[0], 2,
      &emlrtECI, sp);
    ex = Lays->size[0];
    for (k = 0; k < ex; k++) {
      Lays->data[k + Lays->size[0] * i] = airBox->data[k];
    }

    /* plot(x,Lays(:,(numberOfLayers*nrepeats)+2)) */
    st.site = &ob_emlrtRSI;
    b_sum(&st, Lays, b_layers);
    i = SLD->size[0] * SLD->size[1];
    SLD->size[0] = b_layers->size[0];
    SLD->size[1] = 1;
    emxEnsureCapacity_real_T(sp, SLD, i, &nh_emlrtRTEI);
    ex = b_layers->size[0];
    emxFree_real_T(&Lays);
    for (i = 0; i < ex; i++) {
      SLD->data[i] = b_layers->data[i];
    }

    emxFree_real_T(&b_layers);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 6U);
    i = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = 101;
    emxEnsureCapacity_real_T(sp, x, i, &hh_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      x->data[i] = i;
    }

    st.site = &pb_emlrtRSI;
    b_st.site = &xc_emlrtRSI;
    c_st.site = &yc_emlrtRSI;
    d_st.site = &ad_emlrtRSI;
    e_st.site = &bd_emlrtRSI;
    f_st.site = &cd_emlrtRSI;
    b_ex = 0;
    for (k = 0; k < 100; k++) {
      if (b_ex < k + 1) {
        b_ex = k + 1;
      }
    }

    st.site = &qb_emlrtRSI;
    b_st.site = &xc_emlrtRSI;
    c_st.site = &yc_emlrtRSI;
    d_st.site = &ad_emlrtRSI;
    e_st.site = &bd_emlrtRSI;
    f_st.site = &cd_emlrtRSI;
    g_st.site = &dd_emlrtRSI;
    ex = 0;
    for (k = 0; k < 100; k++) {
      if (ex < k + 1) {
        ex = k + 1;
      }
    }

    emxInit_real_T(&g_st, &r, 2, &lh_emlrtRTEI, true);
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = 101;
    emxEnsureCapacity_real_T(sp, r, i, &lh_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      r->data[i] = i;
    }

    st.site = &rb_emlrtRSI;
    asymconvstep(&st, r, ex, 0.0, ssub, ssub, nbair, airBox);
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = 101;
    emxEnsureCapacity_real_T(sp, r, i, &lh_emlrtRTEI);
    for (i = 0; i < 101; i++) {
      r->data[i] = i;
    }

    st.site = &sb_emlrtRSI;
    asymconvstep(&st, r, ex, b_ex, ssub, ssub, nbsub, thisBox);
    ex = thisBox->size[0] * thisBox->size[1];
    emxFree_real_T(&r);
    for (i = 0; i < ex; i++) {
      subBox_data[i] = thisBox->data[i];
    }

    i = SLD->size[0] * SLD->size[1];
    SLD->size[0] = 1;
    SLD->size[1] = airBox->size[1];
    emxEnsureCapacity_real_T(sp, SLD, i, &mh_emlrtRTEI);
    ex = airBox->size[0] * airBox->size[1];
    for (i = 0; i < ex; i++) {
      SLD->data[i] = airBox->data[i] + subBox_data[i];
    }
  }

  emxFree_real_T(&thisBox);
  emxFree_real_T(&airBox);
  covrtLogBasicBlock(&emlrtCoverageInstance, 12U, 7U);

  /* plot(x,SLD) */
  st.site = &tb_emlrtRSI;
  b_st.site = &hb_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  if (SLD->size[0] * SLD->size[1] != x->size[1]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  b_ex = SLD->size[0] * SLD->size[1];
  i = out->size[0] * out->size[1];
  out->size[0] = x->size[1];
  out->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, out, i, &oh_emlrtRTEI);
  ex = x->size[1];
  for (i = 0; i < ex; i++) {
    out->data[i] = x->data[i];
  }

  emxFree_real_T(&x);
  for (i = 0; i < b_ex; i++) {
    out->data[i + out->size[0]] = SLD->data[i];
  }

  emxFree_real_T(&SLD);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (makeSLDProfileXY.c) */
