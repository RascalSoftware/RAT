/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * resampleLayers.c
 *
 * Code generation for function 'resampleLayers'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_single.h"
#include "resampleLayers.h"
#include "standardTF_stanlay_single_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "mean.h"
#include "sum.h"
#include "indexShapeCheck.h"
#include "resample_sld.h"
#include "standardTF_stanlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo ub_emlrtRSI = { 3,  /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 4,  /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 5,  /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 6,  /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 13, /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 17, /* lineNo */
  "groupSamples",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 18, /* lineNo */
  "groupSamples",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 24, /* lineNo */
  "groupSamples",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 25, /* lineNo */
  "groupSamples",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pathName */
};

static emlrtRTEInfo w_emlrtRTEI = { 1, /* lineNo */
  19,                                  /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 5, /* lineNo */
  1,                                   /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 6, /* lineNo */
  1,                                   /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pName */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  25,                                  /* colNo */
  "y",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  16,                                  /* colNo */
  "y",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  14,                                  /* colNo */
  "y",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  14,                                  /* colNo */
  "x",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  13,                                  /* colNo */
  "newSld",                            /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  13,                                  /* colNo */
  "newSld",                            /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  12,                                  /* colNo */
  "allNonZero",                        /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  22,                                  /* colNo */
  "x",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  22,                                  /* colNo */
  "y",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  34,                                  /* colNo */
  "x",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  35,                                  /* colNo */
  "y",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void resampleLayers(const emlrtStack *sp, const emxArray_real_T *layerSLD,
                    emxArray_real_T *newSLD)
{
  emxArray_real_T *allNonZero;
  emxArray_real_T *b_yn;
  emxArray_real_T *nx;
  emxArray_real_T *ny;
  emxArray_real_T *thisLayerx;
  emxArray_real_T *thisLayery;
  int32_T i8;
  int32_T idx;
  int32_T yn_idx_0;
  int32_T i;
  emxArray_real_T *b_nx;
  emxArray_real_T *b_ny;
  int32_T exitg2;
  emxArray_real_T *c_nx;
  real_T diff;
  int32_T ny_idx_0;
  emxArray_real_T *c_ny;
  boolean_T b1;
  emxArray_real_T *newSld;
  emxArray_int32_T *ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv9[2];
  emxArray_real_T *b_newSld;
  emxArray_real_T *c_newSld;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &allNonZero, 1, &y_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_yn, 1, &w_emlrtRTEI, true);
  emxInit_real_T(sp, &nx, 2, &w_emlrtRTEI, true);
  emxInit_real_T(sp, &ny, 2, &w_emlrtRTEI, true);
  emxInit_real_T(sp, &thisLayerx, 2, &ab_emlrtRTEI, true);
  emxInit_real_T(sp, &thisLayery, 2, &bb_emlrtRTEI, true);
  st.site = &ub_emlrtRSI;
  resample_sld(&st, layerSLD, allNonZero, b_yn);
  st.site = &vb_emlrtRSI;
  i8 = nx->size[0] * nx->size[1];
  nx->size[0] = 1;
  nx->size[1] = 0;
  emxEnsureCapacity(&st, (emxArray__common *)nx, i8, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  i8 = ny->size[0] * ny->size[1];
  ny->size[0] = 1;
  ny->size[1] = 0;
  emxEnsureCapacity(&st, (emxArray__common *)ny, i8, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  idx = allNonZero->size[0];
  if (!(1 <= idx)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, idx, &qd_emlrtBCI, &st);
  }

  i8 = thisLayerx->size[0] * thisLayerx->size[1];
  thisLayerx->size[0] = 1;
  thisLayerx->size[1] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)thisLayerx, i8, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  thisLayerx->data[0] = allNonZero->data[0];
  yn_idx_0 = b_yn->size[0];
  if (!(1 <= yn_idx_0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, yn_idx_0, &pd_emlrtBCI, &st);
  }

  i8 = thisLayery->size[0] * thisLayery->size[1];
  thisLayery->size[0] = 1;
  thisLayery->size[1] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)thisLayery, i8, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  thisLayery->data[0] = b_yn->data[0];
  i = 1;
  emxInit_real_T(&st, &b_nx, 2, &w_emlrtRTEI, true);
  emxInit_real_T(&st, &b_ny, 2, &w_emlrtRTEI, true);
  do {
    exitg2 = 0;
    idx = allNonZero->size[0];
    if (i - 1 <= idx - 2) {
      yn_idx_0 = b_yn->size[0];
      i8 = (int32_T)((1.0 + (real_T)(i - 1)) + 1.0);
      if (!((i8 >= 1) && (i8 <= yn_idx_0))) {
        emlrtDynamicBoundsCheckR2012b(i8, 1, yn_idx_0, &od_emlrtBCI, &st);
      }

      yn_idx_0 = b_yn->size[0];
      i8 = (i - 1) + 1;
      if (!((i8 >= 1) && (i8 <= yn_idx_0))) {
        emlrtDynamicBoundsCheckR2012b(i8, 1, yn_idx_0, &nd_emlrtBCI, &st);
      }

      diff = muDoubleScalarAbs(b_yn->data[i] - b_yn->data[i - 1]);
      if (diff <= 1.0E-8) {
        ny_idx_0 = thisLayerx->size[1];
        i8 = thisLayerx->size[0] * thisLayerx->size[1];
        thisLayerx->size[1] = ny_idx_0 + 1;
        emxEnsureCapacity(&st, (emxArray__common *)thisLayerx, i8, (int32_T)
                          sizeof(real_T), &w_emlrtRTEI);
        idx = allNonZero->size[0];
        if (!((i >= 1) && (i <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, idx, &wd_emlrtBCI, &st);
        }

        thisLayerx->data[ny_idx_0] = allNonZero->data[i - 1];
        ny_idx_0 = thisLayery->size[1];
        i8 = thisLayery->size[0] * thisLayery->size[1];
        thisLayery->size[1] = ny_idx_0 + 1;
        emxEnsureCapacity(&st, (emxArray__common *)thisLayery, i8, (int32_T)
                          sizeof(real_T), &w_emlrtRTEI);
        yn_idx_0 = b_yn->size[0];
        if (!((i >= 1) && (i <= yn_idx_0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, yn_idx_0, &xd_emlrtBCI, &st);
        }

        thisLayery->data[ny_idx_0] = b_yn->data[i - 1] + diff / 2.0;
      } else {
        b_st.site = &sc_emlrtRSI;
        diff = b_sum(&b_st, thisLayerx);
        i8 = b_nx->size[0] * b_nx->size[1];
        b_nx->size[0] = 1;
        b_nx->size[1] = nx->size[1] + 1;
        emxEnsureCapacity(&st, (emxArray__common *)b_nx, i8, (int32_T)sizeof
                          (real_T), &w_emlrtRTEI);
        yn_idx_0 = nx->size[1];
        for (i8 = 0; i8 < yn_idx_0; i8++) {
          b_nx->data[b_nx->size[0] * i8] = nx->data[nx->size[0] * i8];
        }

        b_nx->data[b_nx->size[0] * nx->size[1]] = diff;
        i8 = nx->size[0] * nx->size[1];
        nx->size[0] = 1;
        nx->size[1] = b_nx->size[1];
        emxEnsureCapacity(&st, (emxArray__common *)nx, i8, (int32_T)sizeof
                          (real_T), &w_emlrtRTEI);
        yn_idx_0 = b_nx->size[1];
        for (i8 = 0; i8 < yn_idx_0; i8++) {
          nx->data[nx->size[0] * i8] = b_nx->data[b_nx->size[0] * i8];
        }

        b_st.site = &tc_emlrtRSI;
        diff = mean(&b_st, thisLayery);
        i8 = b_ny->size[0] * b_ny->size[1];
        b_ny->size[0] = 1;
        b_ny->size[1] = ny->size[1] + 1;
        emxEnsureCapacity(&st, (emxArray__common *)b_ny, i8, (int32_T)sizeof
                          (real_T), &w_emlrtRTEI);
        yn_idx_0 = ny->size[1];
        for (i8 = 0; i8 < yn_idx_0; i8++) {
          b_ny->data[b_ny->size[0] * i8] = ny->data[ny->size[0] * i8];
        }

        b_ny->data[b_ny->size[0] * ny->size[1]] = diff;
        i8 = ny->size[0] * ny->size[1];
        ny->size[0] = 1;
        ny->size[1] = b_ny->size[1];
        emxEnsureCapacity(&st, (emxArray__common *)ny, i8, (int32_T)sizeof
                          (real_T), &w_emlrtRTEI);
        yn_idx_0 = b_ny->size[1];
        for (i8 = 0; i8 < yn_idx_0; i8++) {
          ny->data[ny->size[0] * i8] = b_ny->data[b_ny->size[0] * i8];
        }

        i8 = thisLayerx->size[0] * thisLayerx->size[1];
        thisLayerx->size[0] = 1;
        thisLayerx->size[1] = 1;
        emxEnsureCapacity(&st, (emxArray__common *)thisLayerx, i8, (int32_T)
                          sizeof(real_T), &w_emlrtRTEI);
        idx = allNonZero->size[0];
        if (!((i >= 1) && (i <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, idx, &ud_emlrtBCI, &st);
        }

        thisLayerx->data[0] = allNonZero->data[i - 1];
        i8 = thisLayery->size[0] * thisLayery->size[1];
        thisLayery->size[0] = 1;
        thisLayery->size[1] = 1;
        emxEnsureCapacity(&st, (emxArray__common *)thisLayery, i8, (int32_T)
                          sizeof(real_T), &w_emlrtRTEI);
        yn_idx_0 = b_yn->size[0];
        if (!((i >= 1) && (i <= yn_idx_0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, yn_idx_0, &vd_emlrtBCI, &st);
        }

        thisLayery->data[0] = b_yn->data[i - 1];
      }

      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  emxFree_real_T(&b_ny);
  emxFree_real_T(&b_nx);
  emxFree_real_T(&b_yn);
  emxInit_real_T(&st, &c_nx, 2, &w_emlrtRTEI, true);
  b_st.site = &uc_emlrtRSI;
  diff = b_sum(&b_st, thisLayerx);
  i8 = c_nx->size[0] * c_nx->size[1];
  c_nx->size[0] = 1;
  c_nx->size[1] = nx->size[1] + 1;
  emxEnsureCapacity(&st, (emxArray__common *)c_nx, i8, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  yn_idx_0 = nx->size[1];
  emxFree_real_T(&thisLayerx);
  for (i8 = 0; i8 < yn_idx_0; i8++) {
    c_nx->data[c_nx->size[0] * i8] = nx->data[nx->size[0] * i8];
  }

  c_nx->data[c_nx->size[0] * nx->size[1]] = diff;
  i8 = nx->size[0] * nx->size[1];
  nx->size[0] = 1;
  nx->size[1] = c_nx->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)nx, i8, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  yn_idx_0 = c_nx->size[1];
  for (i8 = 0; i8 < yn_idx_0; i8++) {
    nx->data[nx->size[0] * i8] = c_nx->data[c_nx->size[0] * i8];
  }

  emxFree_real_T(&c_nx);
  emxInit_real_T(&st, &c_ny, 2, &w_emlrtRTEI, true);
  b_st.site = &vc_emlrtRSI;
  diff = mean(&b_st, thisLayery);
  i8 = c_ny->size[0] * c_ny->size[1];
  c_ny->size[0] = 1;
  c_ny->size[1] = ny->size[1] + 1;
  emxEnsureCapacity(&st, (emxArray__common *)c_ny, i8, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  yn_idx_0 = ny->size[1];
  emxFree_real_T(&thisLayery);
  for (i8 = 0; i8 < yn_idx_0; i8++) {
    c_ny->data[c_ny->size[0] * i8] = ny->data[ny->size[0] * i8];
  }

  c_ny->data[c_ny->size[0] * ny->size[1]] = diff;
  i8 = ny->size[0] * ny->size[1];
  ny->size[0] = 1;
  ny->size[1] = c_ny->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)ny, i8, (int32_T)sizeof(real_T),
                    &w_emlrtRTEI);
  yn_idx_0 = c_ny->size[1];
  for (i8 = 0; i8 < yn_idx_0; i8++) {
    ny->data[ny->size[0] * i8] = c_ny->data[c_ny->size[0] * i8];
  }

  emxFree_real_T(&c_ny);
  st.site = &wb_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  b1 = true;
  yn_idx_0 = nx->size[1];
  ny_idx_0 = ny->size[1];
  if (yn_idx_0 != ny_idx_0) {
    b1 = false;
  }

  if (!b1) {
    emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T(&c_st, &newSld, 2, &x_emlrtRTEI, true);
  yn_idx_0 = nx->size[1];
  ny_idx_0 = ny->size[1];
  i8 = newSld->size[0] * newSld->size[1];
  newSld->size[0] = yn_idx_0;
  newSld->size[1] = 2;
  emxEnsureCapacity(&b_st, (emxArray__common *)newSld, i8, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  for (i8 = 0; i8 < yn_idx_0; i8++) {
    newSld->data[i8] = nx->data[i8];
  }

  emxFree_real_T(&nx);
  for (i8 = 0; i8 < ny_idx_0; i8++) {
    newSld->data[i8 + newSld->size[0]] = ny->data[i8];
  }

  emxFree_real_T(&ny);
  emxInit_int32_T(&b_st, &ii, 1, &g_emlrtRTEI, true);
  st.site = &xb_emlrtRSI;
  b_st.site = &pc_emlrtRSI;
  i8 = newSld->size[0];
  idx = 0;
  ny_idx_0 = newSld->size[0];
  yn_idx_0 = ii->size[0];
  ii->size[0] = ny_idx_0;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, yn_idx_0, (int32_T)sizeof
                    (int32_T), &w_emlrtRTEI);
  c_st.site = &qc_emlrtRSI;
  ny_idx_0 = newSld->size[0];
  if (ny_idx_0 > 2147483646) {
    d_st.site = &eb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  yn_idx_0 = 1;
  exitg1 = false;
  while ((!exitg1) && (yn_idx_0 <= i8)) {
    guard1 = false;
    if (newSld->data[yn_idx_0 - 1] != 0.0) {
      idx++;
      ii->data[idx - 1] = yn_idx_0;
      if (idx >= i8) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      yn_idx_0++;
    }
  }

  i8 = newSld->size[0];
  if (!(idx <= i8)) {
    emlrtErrorWithMessageIdR2012b(&b_st, &ac_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  i8 = newSld->size[0];
  if (i8 == 1) {
    if (idx == 0) {
      i8 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i8, (int32_T)sizeof
                        (int32_T), &w_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i8 = 0;
    } else {
      i8 = idx;
    }

    iv9[0] = 1;
    iv9[1] = i8;
    c_st.site = &rc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv9);
    ny_idx_0 = ii->size[0];
    ii->size[0] = i8;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, ny_idx_0, (int32_T)sizeof
                      (int32_T), &b_emlrtRTEI);
  }

  i8 = allNonZero->size[0];
  allNonZero->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)allNonZero, i8, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  yn_idx_0 = ii->size[0];
  for (i8 = 0; i8 < yn_idx_0; i8++) {
    allNonZero->data[i8] = ii->data[i8];
  }

  emxFree_int32_T(&ii);
  i8 = allNonZero->size[0];
  ny_idx_0 = allNonZero->size[0];
  if (!((ny_idx_0 >= 1) && (ny_idx_0 <= i8))) {
    emlrtDynamicBoundsCheckR2012b(ny_idx_0, 1, i8, &td_emlrtBCI, sp);
  }

  if (1.0 > allNonZero->data[allNonZero->size[0] - 1]) {
    ny_idx_0 = 0;
  } else {
    i8 = newSld->size[0];
    ny_idx_0 = (int32_T)allNonZero->data[allNonZero->size[0] - 1];
    if (!((ny_idx_0 >= 1) && (ny_idx_0 <= i8))) {
      emlrtDynamicBoundsCheckR2012b(ny_idx_0, 1, i8, &sd_emlrtBCI, sp);
    }
  }

  if (1.0 > allNonZero->data[allNonZero->size[0] - 1]) {
    yn_idx_0 = 0;
  } else {
    i8 = newSld->size[0];
    yn_idx_0 = (int32_T)allNonZero->data[allNonZero->size[0] - 1];
    if (!((yn_idx_0 >= 1) && (yn_idx_0 <= i8))) {
      emlrtDynamicBoundsCheckR2012b(yn_idx_0, 1, i8, &rd_emlrtBCI, sp);
    }
  }

  i8 = allNonZero->size[0];
  allNonZero->size[0] = ny_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)allNonZero, i8, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  for (i8 = 0; i8 < ny_idx_0; i8++) {
    allNonZero->data[i8] = 1.0E-20;
  }

  st.site = &yb_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  b1 = true;
  if (ny_idx_0 != yn_idx_0) {
    b1 = false;
  }

  if (!b1) {
    emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  idx = allNonZero->size[0];
  if (ny_idx_0 != idx) {
    b1 = false;
  }

  if (!b1) {
    emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T1(&c_st, &b_newSld, 1, &w_emlrtRTEI, true);
  i8 = b_newSld->size[0];
  b_newSld->size[0] = ny_idx_0;
  emxEnsureCapacity(&b_st, (emxArray__common *)b_newSld, i8, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  for (i8 = 0; i8 < ny_idx_0; i8++) {
    b_newSld->data[i8] = newSld->data[i8];
  }

  emxInit_real_T1(&b_st, &c_newSld, 1, &w_emlrtRTEI, true);
  i8 = c_newSld->size[0];
  c_newSld->size[0] = yn_idx_0;
  emxEnsureCapacity(&b_st, (emxArray__common *)c_newSld, i8, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  for (i8 = 0; i8 < yn_idx_0; i8++) {
    c_newSld->data[i8] = newSld->data[i8 + newSld->size[0]];
  }

  emxFree_real_T(&newSld);
  idx = allNonZero->size[0];
  i8 = newSLD->size[0] * newSLD->size[1];
  newSLD->size[0] = ny_idx_0;
  newSLD->size[1] = 3;
  emxEnsureCapacity(&b_st, (emxArray__common *)newSLD, i8, (int32_T)sizeof
                    (real_T), &w_emlrtRTEI);
  for (i8 = 0; i8 < ny_idx_0; i8++) {
    newSLD->data[i8] = b_newSld->data[i8];
  }

  emxFree_real_T(&b_newSld);
  for (i8 = 0; i8 < yn_idx_0; i8++) {
    newSLD->data[i8 + newSLD->size[0]] = c_newSld->data[i8];
  }

  emxFree_real_T(&c_newSld);
  for (i8 = 0; i8 < idx; i8++) {
    newSLD->data[i8 + (newSLD->size[0] << 1)] = allNonZero->data[i8];
  }

  emxFree_real_T(&allNonZero);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (resampleLayers.c) */
