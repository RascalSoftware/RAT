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
#include "standardTF_custlay_parallel.h"
#include "resampleLayers.h"
#include "standardTF_custlay_parallel_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "mean.h"
#include "sum.h"
#include "indexShapeCheck.h"
#include "resample_sld.h"
#include "standardTF_custlay_parallel_data.h"

/* Variable Definitions */
static emlrtRSInfo tb_emlrtRSI = { 3,  /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 4,  /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 5,  /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 6,  /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 13, /* lineNo */
  "resampleLayers",                    /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 17, /* lineNo */
  "groupSamples",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 18, /* lineNo */
  "groupSamples",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 24, /* lineNo */
  "groupSamples",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 25, /* lineNo */
  "groupSamples",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pathName */
};

static emlrtRTEInfo q_emlrtRTEI = { 1, /* lineNo */
  19,                                  /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 5, /* lineNo */
  1,                                   /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 6, /* lineNo */
  1,                                   /* colNo */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 9, /* lineNo */
  1,                                   /* colNo */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m"/* pName */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  25,                                  /* colNo */
  "y",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  16,                                  /* colNo */
  "y",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  14,                                  /* colNo */
  "y",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  14,                                  /* colNo */
  "x",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  13,                                  /* colNo */
  "newSld",                            /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  13,                                  /* colNo */
  "newSld",                            /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  12,                                  /* colNo */
  "allNonZero",                        /* aName */
  "resampleLayers",                    /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/resampleLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  22,                                  /* colNo */
  "x",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  22,                                  /* colNo */
  "y",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  34,                                  /* colNo */
  "x",                                 /* aName */
  "groupSamples",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/groupSamples.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
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
  int32_T i12;
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
  boolean_T b0;
  emxArray_real_T *newSld;
  emxArray_int32_T *ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv5[2];
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
  emxInit_real_T1(sp, &allNonZero, 1, &t_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_yn, 1, &q_emlrtRTEI, true);
  emxInit_real_T(sp, &nx, 2, &q_emlrtRTEI, true);
  emxInit_real_T(sp, &ny, 2, &q_emlrtRTEI, true);
  emxInit_real_T(sp, &thisLayerx, 2, &u_emlrtRTEI, true);
  emxInit_real_T(sp, &thisLayery, 2, &v_emlrtRTEI, true);
  st.site = &tb_emlrtRSI;
  resample_sld(&st, layerSLD, allNonZero, b_yn);
  st.site = &ub_emlrtRSI;
  i12 = nx->size[0] * nx->size[1];
  nx->size[0] = 1;
  nx->size[1] = 0;
  emxEnsureCapacity(&st, (emxArray__common *)nx, i12, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  i12 = ny->size[0] * ny->size[1];
  ny->size[0] = 1;
  ny->size[1] = 0;
  emxEnsureCapacity(&st, (emxArray__common *)ny, i12, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  idx = allNonZero->size[0];
  if (!(1 <= idx)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, idx, &xc_emlrtBCI, &st);
  }

  i12 = thisLayerx->size[0] * thisLayerx->size[1];
  thisLayerx->size[0] = 1;
  thisLayerx->size[1] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)thisLayerx, i12, (int32_T)sizeof
                    (real_T), &q_emlrtRTEI);
  thisLayerx->data[0] = allNonZero->data[0];
  yn_idx_0 = b_yn->size[0];
  if (!(1 <= yn_idx_0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, yn_idx_0, &wc_emlrtBCI, &st);
  }

  i12 = thisLayery->size[0] * thisLayery->size[1];
  thisLayery->size[0] = 1;
  thisLayery->size[1] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)thisLayery, i12, (int32_T)sizeof
                    (real_T), &q_emlrtRTEI);
  thisLayery->data[0] = b_yn->data[0];
  i = 1;
  emxInit_real_T(&st, &b_nx, 2, &q_emlrtRTEI, true);
  emxInit_real_T(&st, &b_ny, 2, &q_emlrtRTEI, true);
  do {
    exitg2 = 0;
    idx = allNonZero->size[0];
    if (i - 1 <= idx - 2) {
      yn_idx_0 = b_yn->size[0];
      i12 = (int32_T)((1.0 + (real_T)(i - 1)) + 1.0);
      if (!((i12 >= 1) && (i12 <= yn_idx_0))) {
        emlrtDynamicBoundsCheckR2012b(i12, 1, yn_idx_0, &vc_emlrtBCI, &st);
      }

      yn_idx_0 = b_yn->size[0];
      i12 = (i - 1) + 1;
      if (!((i12 >= 1) && (i12 <= yn_idx_0))) {
        emlrtDynamicBoundsCheckR2012b(i12, 1, yn_idx_0, &uc_emlrtBCI, &st);
      }

      diff = muDoubleScalarAbs(b_yn->data[i] - b_yn->data[i - 1]);
      if (diff <= 1.0E-8) {
        ny_idx_0 = thisLayerx->size[1];
        i12 = thisLayerx->size[0] * thisLayerx->size[1];
        thisLayerx->size[1] = ny_idx_0 + 1;
        emxEnsureCapacity(&st, (emxArray__common *)thisLayerx, i12, (int32_T)
                          sizeof(real_T), &q_emlrtRTEI);
        idx = allNonZero->size[0];
        if (!((i >= 1) && (i <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, idx, &ed_emlrtBCI, &st);
        }

        thisLayerx->data[ny_idx_0] = allNonZero->data[i - 1];
        ny_idx_0 = thisLayery->size[1];
        i12 = thisLayery->size[0] * thisLayery->size[1];
        thisLayery->size[1] = ny_idx_0 + 1;
        emxEnsureCapacity(&st, (emxArray__common *)thisLayery, i12, (int32_T)
                          sizeof(real_T), &q_emlrtRTEI);
        yn_idx_0 = b_yn->size[0];
        if (!((i >= 1) && (i <= yn_idx_0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, yn_idx_0, &fd_emlrtBCI, &st);
        }

        thisLayery->data[ny_idx_0] = b_yn->data[i - 1] + diff / 2.0;
      } else {
        b_st.site = &rc_emlrtRSI;
        diff = b_sum(&b_st, thisLayerx);
        i12 = b_nx->size[0] * b_nx->size[1];
        b_nx->size[0] = 1;
        b_nx->size[1] = nx->size[1] + 1;
        emxEnsureCapacity(&st, (emxArray__common *)b_nx, i12, (int32_T)sizeof
                          (real_T), &q_emlrtRTEI);
        yn_idx_0 = nx->size[1];
        for (i12 = 0; i12 < yn_idx_0; i12++) {
          b_nx->data[b_nx->size[0] * i12] = nx->data[nx->size[0] * i12];
        }

        b_nx->data[b_nx->size[0] * nx->size[1]] = diff;
        i12 = nx->size[0] * nx->size[1];
        nx->size[0] = 1;
        nx->size[1] = b_nx->size[1];
        emxEnsureCapacity(&st, (emxArray__common *)nx, i12, (int32_T)sizeof
                          (real_T), &q_emlrtRTEI);
        yn_idx_0 = b_nx->size[1];
        for (i12 = 0; i12 < yn_idx_0; i12++) {
          nx->data[nx->size[0] * i12] = b_nx->data[b_nx->size[0] * i12];
        }

        b_st.site = &sc_emlrtRSI;
        diff = mean(&b_st, thisLayery);
        i12 = b_ny->size[0] * b_ny->size[1];
        b_ny->size[0] = 1;
        b_ny->size[1] = ny->size[1] + 1;
        emxEnsureCapacity(&st, (emxArray__common *)b_ny, i12, (int32_T)sizeof
                          (real_T), &q_emlrtRTEI);
        yn_idx_0 = ny->size[1];
        for (i12 = 0; i12 < yn_idx_0; i12++) {
          b_ny->data[b_ny->size[0] * i12] = ny->data[ny->size[0] * i12];
        }

        b_ny->data[b_ny->size[0] * ny->size[1]] = diff;
        i12 = ny->size[0] * ny->size[1];
        ny->size[0] = 1;
        ny->size[1] = b_ny->size[1];
        emxEnsureCapacity(&st, (emxArray__common *)ny, i12, (int32_T)sizeof
                          (real_T), &q_emlrtRTEI);
        yn_idx_0 = b_ny->size[1];
        for (i12 = 0; i12 < yn_idx_0; i12++) {
          ny->data[ny->size[0] * i12] = b_ny->data[b_ny->size[0] * i12];
        }

        i12 = thisLayerx->size[0] * thisLayerx->size[1];
        thisLayerx->size[0] = 1;
        thisLayerx->size[1] = 1;
        emxEnsureCapacity(&st, (emxArray__common *)thisLayerx, i12, (int32_T)
                          sizeof(real_T), &q_emlrtRTEI);
        idx = allNonZero->size[0];
        if (!((i >= 1) && (i <= idx))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, idx, &cd_emlrtBCI, &st);
        }

        thisLayerx->data[0] = allNonZero->data[i - 1];
        i12 = thisLayery->size[0] * thisLayery->size[1];
        thisLayery->size[0] = 1;
        thisLayery->size[1] = 1;
        emxEnsureCapacity(&st, (emxArray__common *)thisLayery, i12, (int32_T)
                          sizeof(real_T), &q_emlrtRTEI);
        yn_idx_0 = b_yn->size[0];
        if (!((i >= 1) && (i <= yn_idx_0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, yn_idx_0, &dd_emlrtBCI, &st);
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
  emxInit_real_T(&st, &c_nx, 2, &q_emlrtRTEI, true);
  b_st.site = &tc_emlrtRSI;
  diff = b_sum(&b_st, thisLayerx);
  i12 = c_nx->size[0] * c_nx->size[1];
  c_nx->size[0] = 1;
  c_nx->size[1] = nx->size[1] + 1;
  emxEnsureCapacity(&st, (emxArray__common *)c_nx, i12, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  yn_idx_0 = nx->size[1];
  emxFree_real_T(&thisLayerx);
  for (i12 = 0; i12 < yn_idx_0; i12++) {
    c_nx->data[c_nx->size[0] * i12] = nx->data[nx->size[0] * i12];
  }

  c_nx->data[c_nx->size[0] * nx->size[1]] = diff;
  i12 = nx->size[0] * nx->size[1];
  nx->size[0] = 1;
  nx->size[1] = c_nx->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)nx, i12, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  yn_idx_0 = c_nx->size[1];
  for (i12 = 0; i12 < yn_idx_0; i12++) {
    nx->data[nx->size[0] * i12] = c_nx->data[c_nx->size[0] * i12];
  }

  emxFree_real_T(&c_nx);
  emxInit_real_T(&st, &c_ny, 2, &q_emlrtRTEI, true);
  b_st.site = &uc_emlrtRSI;
  diff = mean(&b_st, thisLayery);
  i12 = c_ny->size[0] * c_ny->size[1];
  c_ny->size[0] = 1;
  c_ny->size[1] = ny->size[1] + 1;
  emxEnsureCapacity(&st, (emxArray__common *)c_ny, i12, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  yn_idx_0 = ny->size[1];
  emxFree_real_T(&thisLayery);
  for (i12 = 0; i12 < yn_idx_0; i12++) {
    c_ny->data[c_ny->size[0] * i12] = ny->data[ny->size[0] * i12];
  }

  c_ny->data[c_ny->size[0] * ny->size[1]] = diff;
  i12 = ny->size[0] * ny->size[1];
  ny->size[0] = 1;
  ny->size[1] = c_ny->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)ny, i12, (int32_T)sizeof(real_T),
                    &q_emlrtRTEI);
  yn_idx_0 = c_ny->size[1];
  for (i12 = 0; i12 < yn_idx_0; i12++) {
    ny->data[ny->size[0] * i12] = c_ny->data[c_ny->size[0] * i12];
  }

  emxFree_real_T(&c_ny);
  st.site = &vb_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  b0 = true;
  yn_idx_0 = nx->size[1];
  ny_idx_0 = ny->size[1];
  if (yn_idx_0 != ny_idx_0) {
    b0 = false;
  }

  if (!b0) {
    emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T(&c_st, &newSld, 2, &s_emlrtRTEI, true);
  yn_idx_0 = nx->size[1];
  ny_idx_0 = ny->size[1];
  i12 = newSld->size[0] * newSld->size[1];
  newSld->size[0] = yn_idx_0;
  newSld->size[1] = 2;
  emxEnsureCapacity(&b_st, (emxArray__common *)newSld, i12, (int32_T)sizeof
                    (real_T), &q_emlrtRTEI);
  for (i12 = 0; i12 < yn_idx_0; i12++) {
    newSld->data[i12] = nx->data[i12];
  }

  emxFree_real_T(&nx);
  for (i12 = 0; i12 < ny_idx_0; i12++) {
    newSld->data[i12 + newSld->size[0]] = ny->data[i12];
  }

  emxFree_real_T(&ny);
  emxInit_int32_T(&b_st, &ii, 1, &w_emlrtRTEI, true);
  st.site = &wb_emlrtRSI;
  b_st.site = &oc_emlrtRSI;
  i12 = newSld->size[0];
  idx = 0;
  ny_idx_0 = newSld->size[0];
  yn_idx_0 = ii->size[0];
  ii->size[0] = ny_idx_0;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, yn_idx_0, (int32_T)sizeof
                    (int32_T), &q_emlrtRTEI);
  c_st.site = &pc_emlrtRSI;
  ny_idx_0 = newSld->size[0];
  if (ny_idx_0 > 2147483646) {
    d_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  yn_idx_0 = 1;
  exitg1 = false;
  while ((!exitg1) && (yn_idx_0 <= i12)) {
    guard1 = false;
    if (newSld->data[yn_idx_0 - 1] != 0.0) {
      idx++;
      ii->data[idx - 1] = yn_idx_0;
      if (idx >= i12) {
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

  i12 = newSld->size[0];
  if (!(idx <= i12)) {
    emlrtErrorWithMessageIdR2012b(&b_st, &hc_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  i12 = newSld->size[0];
  if (i12 == 1) {
    if (idx == 0) {
      i12 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i12, (int32_T)sizeof
                        (int32_T), &q_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      i12 = 0;
    } else {
      i12 = idx;
    }

    iv5[0] = 1;
    iv5[1] = i12;
    c_st.site = &qc_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv5);
    ny_idx_0 = ii->size[0];
    ii->size[0] = i12;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, ny_idx_0, (int32_T)sizeof
                      (int32_T), &r_emlrtRTEI);
  }

  i12 = allNonZero->size[0];
  allNonZero->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)allNonZero, i12, (int32_T)sizeof
                    (real_T), &q_emlrtRTEI);
  yn_idx_0 = ii->size[0];
  for (i12 = 0; i12 < yn_idx_0; i12++) {
    allNonZero->data[i12] = ii->data[i12];
  }

  emxFree_int32_T(&ii);
  i12 = allNonZero->size[0];
  ny_idx_0 = allNonZero->size[0];
  if (!((ny_idx_0 >= 1) && (ny_idx_0 <= i12))) {
    emlrtDynamicBoundsCheckR2012b(ny_idx_0, 1, i12, &bd_emlrtBCI, sp);
  }

  if (1.0 > allNonZero->data[allNonZero->size[0] - 1]) {
    ny_idx_0 = 0;
  } else {
    i12 = newSld->size[0];
    ny_idx_0 = (int32_T)allNonZero->data[allNonZero->size[0] - 1];
    if (!((ny_idx_0 >= 1) && (ny_idx_0 <= i12))) {
      emlrtDynamicBoundsCheckR2012b(ny_idx_0, 1, i12, &ad_emlrtBCI, sp);
    }
  }

  if (1.0 > allNonZero->data[allNonZero->size[0] - 1]) {
    yn_idx_0 = 0;
  } else {
    i12 = newSld->size[0];
    yn_idx_0 = (int32_T)allNonZero->data[allNonZero->size[0] - 1];
    if (!((yn_idx_0 >= 1) && (yn_idx_0 <= i12))) {
      emlrtDynamicBoundsCheckR2012b(yn_idx_0, 1, i12, &yc_emlrtBCI, sp);
    }
  }

  i12 = allNonZero->size[0];
  allNonZero->size[0] = ny_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)allNonZero, i12, (int32_T)sizeof
                    (real_T), &q_emlrtRTEI);
  for (i12 = 0; i12 < ny_idx_0; i12++) {
    allNonZero->data[i12] = 1.0E-20;
  }

  st.site = &xb_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  b0 = true;
  if (ny_idx_0 != yn_idx_0) {
    b0 = false;
  }

  if (!b0) {
    emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  idx = allNonZero->size[0];
  if (ny_idx_0 != idx) {
    b0 = false;
  }

  if (!b0) {
    emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T1(&c_st, &b_newSld, 1, &q_emlrtRTEI, true);
  i12 = b_newSld->size[0];
  b_newSld->size[0] = ny_idx_0;
  emxEnsureCapacity(&b_st, (emxArray__common *)b_newSld, i12, (int32_T)sizeof
                    (real_T), &q_emlrtRTEI);
  for (i12 = 0; i12 < ny_idx_0; i12++) {
    b_newSld->data[i12] = newSld->data[i12];
  }

  emxInit_real_T1(&b_st, &c_newSld, 1, &q_emlrtRTEI, true);
  i12 = c_newSld->size[0];
  c_newSld->size[0] = yn_idx_0;
  emxEnsureCapacity(&b_st, (emxArray__common *)c_newSld, i12, (int32_T)sizeof
                    (real_T), &q_emlrtRTEI);
  for (i12 = 0; i12 < yn_idx_0; i12++) {
    c_newSld->data[i12] = newSld->data[i12 + newSld->size[0]];
  }

  emxFree_real_T(&newSld);
  idx = allNonZero->size[0];
  i12 = newSLD->size[0] * newSLD->size[1];
  newSLD->size[0] = ny_idx_0;
  newSLD->size[1] = 3;
  emxEnsureCapacity(&b_st, (emxArray__common *)newSLD, i12, (int32_T)sizeof
                    (real_T), &q_emlrtRTEI);
  for (i12 = 0; i12 < ny_idx_0; i12++) {
    newSLD->data[i12] = b_newSld->data[i12];
  }

  emxFree_real_T(&b_newSld);
  for (i12 = 0; i12 < yn_idx_0; i12++) {
    newSLD->data[i12 + newSLD->size[0]] = c_newSld->data[i12];
  }

  emxFree_real_T(&c_newSld);
  for (i12 = 0; i12 < idx; i12++) {
    newSLD->data[i12 + (newSLD->size[0] << 1)] = allNonZero->data[i12];
  }

  emxFree_real_T(&allNonZero);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (resampleLayers.c) */
