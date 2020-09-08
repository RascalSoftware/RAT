/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * adaptive.c
 *
 * Code generation for function 'adaptive'
 *
 */

/* Include files */
#include "adaptive.h"
#include "acos.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "power.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sldFunc.h"
#include "sortrows.h"

/* Variable Definitions */
static emlrtRSInfo pd_emlrtRSI = { 398,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 399,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 401,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo sd_emlrtRSI = { 403,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 404,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 405,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 408,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 407,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 409,/* lineNo */
  "calculateCentralAngles",            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 16, /* lineNo */
  "sqrt",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 431,/* lineNo */
  "increaseSampling",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 433,/* lineNo */
  "increaseSampling",                  /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pathName */
};

static emlrtECInfo h_emlrtECI = { 2,   /* nDims */
  398,                                 /* lineNo */
  3,                                   /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  403,                                 /* lineNo */
  21,                                  /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  404,                                 /* lineNo */
  21,                                  /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  405,                                 /* lineNo */
  21,                                  /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  407,                                 /* lineNo */
  4,                                   /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo m_emlrtECI = { -1,  /* nDims */
  408,                                 /* lineNo */
  8,                                   /* colNo */
  "calculateCentralAngles",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtBCInfo xg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  20,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  22,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ah_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  40,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  386,                                 /* lineNo */
  42,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo n_emlrtECI = { 2,   /* nDims */
  386,                                 /* lineNo */
  13,                                  /* colNo */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtBCInfo ch_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  23,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  41,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  43,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo o_emlrtECI = { 2,   /* nDims */
  387,                                 /* lineNo */
  14,                                  /* colNo */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtBCInfo fh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  388,                                 /* lineNo */
  22,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  388,                                 /* lineNo */
  40,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  388,                                 /* lineNo */
  42,                                  /* colNo */
  "XYdata",                            /* aName */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo p_emlrtECI = { 2,   /* nDims */
  388,                                 /* lineNo */
  13,                                  /* colNo */
  "calculateTrianglesSides",           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

static emlrtECInfo bb_emlrtECI = { -1, /* nDims */
  429,                                 /* lineNo */
  29,                                  /* colNo */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo cb_emlrtECI = { -1, /* nDims */
  429,                                 /* lineNo */
  1,                                   /* colNo */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtECInfo db_emlrtECI = { -1, /* nDims */
  431,                                 /* lineNo */
  1,                                   /* colNo */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtBCInfo vq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  425,                                 /* lineNo */
  39,                                  /* colNo */
  "segmentsToSplit",                   /* aName */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  429,                                 /* lineNo */
  40,                                  /* colNo */
  "dataPoints",                        /* aName */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  430,                                 /* lineNo */
  14,                                  /* colNo */
  "dataPoints",                        /* aName */
  "increaseSampling",                  /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  376,                                 /* lineNo */
  20,                                  /* colNo */
  "x",                                 /* aName */
  "normalizeFunction",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ar_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  376,                                 /* lineNo */
  5,                                   /* colNo */
  "y",                                 /* aName */
  "normalizeFunction",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo bj_emlrtRTEI = { 398,/* lineNo */
  3,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo cj_emlrtRTEI = { 397,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo dj_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ej_emlrtRTEI = { 387,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo fj_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo gj_emlrtRTEI = { 403,/* lineNo */
  21,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo hj_emlrtRTEI = { 403,/* lineNo */
  42,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ij_emlrtRTEI = { 404,/* lineNo */
  21,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo jj_emlrtRTEI = { 404,/* lineNo */
  42,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo kj_emlrtRTEI = { 405,/* lineNo */
  21,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo lj_emlrtRTEI = { 405,/* lineNo */
  42,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo mj_emlrtRTEI = { 407,/* lineNo */
  3,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo nj_emlrtRTEI = { 409,/* lineNo */
  20,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo oj_emlrtRTEI = { 409,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo pj_emlrtRTEI = { 403,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo qj_emlrtRTEI = { 404,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo rj_emlrtRTEI = { 405,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo sj_emlrtRTEI = { 391,/* lineNo */
  24,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ho_emlrtRTEI = { 426,/* lineNo */
  1,                                   /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo io_emlrtRTEI = { 429,/* lineNo */
  40,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo jo_emlrtRTEI = { 430,/* lineNo */
  14,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo ko_emlrtRTEI = { 422,/* lineNo */
  23,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo lo_emlrtRTEI = { 429,/* lineNo */
  22,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo mo_emlrtRTEI = { 431,/* lineNo */
  22,                                  /* colNo */
  "adaptive",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"/* pName */
};

static emlrtRTEInfo no_emlrtRTEI = { 303,/* lineNo */
  14,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

/* Function Definitions */
void calculateCentralAngles(const emlrtStack *sp, const emxArray_real_T *XYdata,
  const real_T dataBoxSize[2], emxArray_real_T *cornerAngle)
{
  emxArray_real_T *normalizedData;
  real_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  boolean_T overflow;
  int32_T m;
  int32_T i;
  int32_T b_i;
  real_T b;
  emxArray_real_T *longStep;
  int32_T i1;
  int32_T iv[2];
  int32_T iv1[2];
  emxArray_real_T *firstStep;
  emxArray_real_T *secondStep;
  emxArray_real_T *b_firstStep;
  emxArray_real_T *firstStepSquared;
  emxArray_real_T *r;
  emxArray_real_T *secondStepSquared;
  emxArray_real_T *longStepSquared;
  emxArray_creal_T *r1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &normalizedData, 2, &cj_emlrtRTEI, true);

  /*  Calculate the central angle of the triangles formed by data points. */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the */
  /*  last point are not the central corner of any triangle. */
  /*  Normalize data, because angles depend on scaling. */
  st.site = &pd_emlrtRSI;
  b_st.site = &pd_emlrtRSI;
  repmat(&b_st, dataBoxSize, XYdata->size[0], normalizedData);
  varargin_1[0] = XYdata->size[0];
  varargin_2[0] = (uint32_T)normalizedData->size[0];
  varargin_1[1] = XYdata->size[1];
  varargin_2[1] = (uint32_T)normalizedData->size[1];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)(uint32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  overflow = (int32_T)p;
  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &pb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  m = XYdata->size[0] * XYdata->size[1];
  i = normalizedData->size[0] * normalizedData->size[1];
  normalizedData->size[0] = XYdata->size[0];
  normalizedData->size[1] = 2;
  emxEnsureCapacity_real_T(&st, normalizedData, i, &bj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    normalizedData->data[i] = XYdata->data[i] / normalizedData->data[i];
  }

  st.site = &qd_emlrtRSI;
  b_st.site = &md_emlrtRSI;
  c_st.site = &nd_emlrtRSI;
  d_st.site = &od_emlrtRSI;
  if (XYdata->size[0] == 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &nb_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility",
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (XYdata->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &mb_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &id_emlrtRSI;
  f_st.site = &jd_emlrtRSI;
  g_st.site = &kd_emlrtRSI;
  m = XYdata->size[0];
  overflow = ((2 <= XYdata->size[0]) && (XYdata->size[0] > 2147483646));
  varargin_1[0] = XYdata->data[0];
  h_st.site = &ld_emlrtRSI;
  if (overflow) {
    i_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&i_st);
  }

  for (b_i = 2; b_i <= m; b_i++) {
    b = XYdata->data[b_i - 1];
    if ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(varargin_1[0]) ||
         (varargin_1[0] > b))) {
      varargin_1[0] = b;
    }
  }

  varargin_1[1] = XYdata->data[XYdata->size[0]];
  h_st.site = &ld_emlrtRSI;
  for (b_i = 2; b_i <= m; b_i++) {
    b = XYdata->data[(b_i + XYdata->size[0]) - 1];
    if ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(varargin_1[1]) ||
         (varargin_1[1] > b))) {
      varargin_1[1] = b;
    }
  }

  emxInit_real_T(&g_st, &longStep, 2, &sj_emlrtRTEI, true);
  st.site = &qd_emlrtRSI;
  repmat(&st, varargin_1, XYdata->size[0], longStep);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])normalizedData->size, *(int32_T (*)
    [2])longStep->size, &h_emlrtECI, sp);
  m = normalizedData->size[0] * normalizedData->size[1];
  i = normalizedData->size[0] * normalizedData->size[1];
  normalizedData->size[1] = 2;
  emxEnsureCapacity_real_T(sp, normalizedData, i, &cj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    normalizedData->data[i] -= longStep->data[i];
  }

  /*  calculate cosine of central angles */
  st.site = &rd_emlrtRSI;

  /*  Return the sides (deltaX, deltaY) of the triangles formed by data points. */
  /*  For input size NxM, the output size is (N-2)xN, because the first and the */
  /*  last point are not the central corner of any triangle. */
  if (2 > normalizedData->size[0] - 1) {
    i = -1;
    i1 = -1;
  } else {
    if (2 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, normalizedData->size[0], &xg_emlrtBCI,
        &st);
    }

    i = 0;
    i1 = normalizedData->size[0] - 1;
    if ((i1 < 1) || (i1 > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, normalizedData->size[0], &yg_emlrtBCI,
        &st);
    }

    i1--;
  }

  if (1 > normalizedData->size[0] - 2) {
    b_i = 0;
  } else {
    if (1 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, normalizedData->size[0], &ah_emlrtBCI,
        &st);
    }

    b_i = normalizedData->size[0] - 2;
    if ((b_i < 1) || (b_i > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, normalizedData->size[0],
        &bh_emlrtBCI, &st);
    }
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = b_i;
  iv1[1] = 2;
  if (m != b_i) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &n_emlrtECI, &st);
  }

  emxInit_real_T(&st, &firstStep, 2, &sj_emlrtRTEI, true);
  i1 = firstStep->size[0] * firstStep->size[1];
  firstStep->size[0] = m;
  firstStep->size[1] = 2;
  emxEnsureCapacity_real_T(&st, firstStep, i1, &dj_emlrtRTEI);
  for (i1 = 0; i1 < m; i1++) {
    firstStep->data[i1] = normalizedData->data[(i + i1) + 1] -
      normalizedData->data[i1];
  }

  for (i1 = 0; i1 < m; i1++) {
    firstStep->data[i1 + firstStep->size[0]] = normalizedData->data[((i + i1) +
      normalizedData->size[0]) + 1] - normalizedData->data[i1 +
      normalizedData->size[0]];
  }

  if (3 > normalizedData->size[0]) {
    i = -1;
    i1 = -1;
  } else {
    i = 1;
    if (normalizedData->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0], 1,
        normalizedData->size[0], &ch_emlrtBCI, &st);
    }

    i1 = normalizedData->size[0] - 1;
  }

  if (2 > normalizedData->size[0] - 1) {
    b_i = -1;
    k = 0;
  } else {
    if (2 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, normalizedData->size[0], &dh_emlrtBCI,
        &st);
    }

    b_i = 0;
    k = normalizedData->size[0] - 1;
    if ((k < 1) || (k > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(k, 1, normalizedData->size[0], &eh_emlrtBCI,
        &st);
    }
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = (k - b_i) - 1;
  iv1[1] = 2;
  if (m != iv1[0]) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &o_emlrtECI, &st);
  }

  emxInit_real_T(&st, &secondStep, 2, &sj_emlrtRTEI, true);
  i1 = secondStep->size[0] * secondStep->size[1];
  secondStep->size[0] = m;
  secondStep->size[1] = 2;
  emxEnsureCapacity_real_T(&st, secondStep, i1, &ej_emlrtRTEI);
  for (i1 = 0; i1 < m; i1++) {
    secondStep->data[i1] = normalizedData->data[(i + i1) + 1] -
      normalizedData->data[(b_i + i1) + 1];
  }

  for (i1 = 0; i1 < m; i1++) {
    secondStep->data[i1 + secondStep->size[0]] = normalizedData->data[((i + i1)
      + normalizedData->size[0]) + 1] - normalizedData->data[((b_i + i1) +
      normalizedData->size[0]) + 1];
  }

  if (3 > normalizedData->size[0]) {
    i = -1;
    i1 = -1;
  } else {
    i = 1;
    if (normalizedData->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(normalizedData->size[0], 1,
        normalizedData->size[0], &fh_emlrtBCI, &st);
    }

    i1 = normalizedData->size[0] - 1;
  }

  if (1 > normalizedData->size[0] - 2) {
    b_i = 0;
  } else {
    if (1 > normalizedData->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, normalizedData->size[0], &gh_emlrtBCI,
        &st);
    }

    b_i = normalizedData->size[0] - 2;
    if ((b_i < 1) || (b_i > normalizedData->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, normalizedData->size[0],
        &hh_emlrtBCI, &st);
    }
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = b_i;
  iv1[1] = 2;
  if (m != b_i) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &p_emlrtECI, &st);
  }

  i1 = longStep->size[0] * longStep->size[1];
  longStep->size[0] = m;
  longStep->size[1] = 2;
  emxEnsureCapacity_real_T(&st, longStep, i1, &fj_emlrtRTEI);
  for (i1 = 0; i1 < m; i1++) {
    longStep->data[i1] = normalizedData->data[(i + i1) + 1] -
      normalizedData->data[i1];
  }

  for (i1 = 0; i1 < m; i1++) {
    longStep->data[i1 + longStep->size[0]] = normalizedData->data[((i + i1) +
      normalizedData->size[0]) + 1] - normalizedData->data[i1 +
      normalizedData->size[0]];
  }

  emxFree_real_T(&normalizedData);
  emxInit_real_T(&st, &b_firstStep, 1, &gj_emlrtRTEI, true);

  /*  calculate area of squares of length of triangle sides */
  m = firstStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = firstStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &gj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = firstStep->data[i];
  }

  emxInit_real_T(sp, &firstStepSquared, 1, &pj_emlrtRTEI, true);
  st.site = &sd_emlrtRSI;
  power(&st, b_firstStep, firstStepSquared);
  m = firstStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = firstStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &hj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = firstStep->data[i + firstStep->size[0]];
  }

  emxFree_real_T(&firstStep);
  emxInit_real_T(sp, &r, 1, &sj_emlrtRTEI, true);
  st.site = &sd_emlrtRSI;
  power(&st, b_firstStep, r);
  if (firstStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], r->size[0], &i_emlrtECI,
      sp);
  }

  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    firstStepSquared->data[i] += r->data[i];
  }

  m = secondStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = secondStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &ij_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = secondStep->data[i];
  }

  emxInit_real_T(sp, &secondStepSquared, 1, &qj_emlrtRTEI, true);
  st.site = &td_emlrtRSI;
  power(&st, b_firstStep, secondStepSquared);
  m = secondStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = secondStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &jj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = secondStep->data[i + secondStep->size[0]];
  }

  emxFree_real_T(&secondStep);
  st.site = &td_emlrtRSI;
  power(&st, b_firstStep, r);
  if (secondStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(secondStepSquared->size[0], r->size[0], &j_emlrtECI,
      sp);
  }

  m = secondStepSquared->size[0];
  for (i = 0; i < m; i++) {
    secondStepSquared->data[i] += r->data[i];
  }

  m = longStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = longStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &kj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = longStep->data[i];
  }

  emxInit_real_T(sp, &longStepSquared, 1, &rj_emlrtRTEI, true);
  st.site = &ud_emlrtRSI;
  power(&st, b_firstStep, longStepSquared);
  m = longStep->size[0];
  i = b_firstStep->size[0];
  b_firstStep->size[0] = longStep->size[0];
  emxEnsureCapacity_real_T(sp, b_firstStep, i, &lj_emlrtRTEI);
  for (i = 0; i < m; i++) {
    b_firstStep->data[i] = longStep->data[i + longStep->size[0]];
  }

  emxFree_real_T(&longStep);
  st.site = &ud_emlrtRSI;
  power(&st, b_firstStep, r);
  emxFree_real_T(&b_firstStep);
  if (longStepSquared->size[0] != r->size[0]) {
    emlrtSizeEqCheck1DR2012b(longStepSquared->size[0], r->size[0], &k_emlrtECI,
      sp);
  }

  m = longStepSquared->size[0];
  for (i = 0; i < m; i++) {
    longStepSquared->data[i] += r->data[i];
  }

  emxFree_real_T(&r);
  if (firstStepSquared->size[0] != secondStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], secondStepSquared->size
      [0], &l_emlrtECI, sp);
  }

  if (firstStepSquared->size[0] != longStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], longStepSquared->size[0],
      &l_emlrtECI, sp);
  }

  if (firstStepSquared->size[0] != secondStepSquared->size[0]) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared->size[0], secondStepSquared->size
      [0], &m_emlrtECI, sp);
  }

  st.site = &wd_emlrtRSI;
  i = longStepSquared->size[0];
  longStepSquared->size[0] = firstStepSquared->size[0];
  emxEnsureCapacity_real_T(&st, longStepSquared, i, &mj_emlrtRTEI);
  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    longStepSquared->data[i] = ((firstStepSquared->data[i] +
      secondStepSquared->data[i]) - longStepSquared->data[i]) / 2.0;
  }

  b_st.site = &vd_emlrtRSI;
  m = firstStepSquared->size[0];
  for (i = 0; i < m; i++) {
    firstStepSquared->data[i] *= secondStepSquared->data[i];
  }

  emxFree_real_T(&secondStepSquared);
  overflow = false;
  i = firstStepSquared->size[0];
  for (k = 0; k < i; k++) {
    if (overflow || (firstStepSquared->data[k] < 0.0)) {
      overflow = true;
    }
  }

  if (overflow) {
    emlrtErrorWithMessageIdR2018a(&b_st, &qb_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  c_st.site = &de_emlrtRSI;
  m = firstStepSquared->size[0];
  d_st.site = &ee_emlrtRSI;
  if ((1 <= firstStepSquared->size[0]) && (firstStepSquared->size[0] >
       2147483646)) {
    e_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 0; k < m; k++) {
    firstStepSquared->data[k] = muDoubleScalarSqrt(firstStepSquared->data[k]);
  }

  varargin_1[0] = longStepSquared->size[0];
  varargin_1[1] = 1.0;
  varargin_2[0] = (uint32_T)firstStepSquared->size[0];
  varargin_2[1] = 1U;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)(uint32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  overflow = (int32_T)p;
  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &pb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  emxInit_creal_T(&st, &r1, 1, &nj_emlrtRTEI, true);
  i = r1->size[0];
  r1->size[0] = longStepSquared->size[0];
  emxEnsureCapacity_creal_T(sp, r1, i, &nj_emlrtRTEI);
  m = longStepSquared->size[0];
  for (i = 0; i < m; i++) {
    r1->data[i].re = longStepSquared->data[i] / firstStepSquared->data[i];
    r1->data[i].im = 0.0;
  }

  emxFree_real_T(&longStepSquared);
  emxFree_real_T(&firstStepSquared);
  st.site = &xd_emlrtRSI;
  b_acos(&st, r1);
  i = cornerAngle->size[0];
  cornerAngle->size[0] = r1->size[0];
  emxEnsureCapacity_real_T(sp, cornerAngle, i, &oj_emlrtRTEI);
  m = r1->size[0];
  for (i = 0; i < m; i++) {
    cornerAngle->data[i] = r1->data[i].re;
  }

  emxFree_creal_T(&r1);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void increaseSampling(const emlrtStack *sp, emxArray_real_T *dataPoints, const
                      emxArray_boolean_T *segmentsToSplit, const emxArray_real_T
                      *sldProfile)
{
  int32_T end;
  int32_T i;
  int32_T trueCount;
  int32_T b_i;
  emxArray_real_T *newDataPoints;
  int32_T input_sizes_idx_0;
  emxArray_boolean_T *r;
  emxArray_boolean_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_real_T *r6;
  emxArray_real_T *r7;
  emxArray_real_T *b_dataPoints;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  increaseSampling increase the sampling of an input function */
  end = segmentsToSplit->size[0];
  for (i = 0; i < end; i++) {
    if (segmentsToSplit->data[i]) {
      b_i = i + 1;
      if ((b_i < 1) || (b_i > segmentsToSplit->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, segmentsToSplit->size[0],
          &vq_emlrtBCI, sp);
      }
    }
  }

  end = segmentsToSplit->size[0];
  trueCount = 0;
  for (i = 0; i < end; i++) {
    if (segmentsToSplit->data[i]) {
      trueCount++;
    }
  }

  emxInit_real_T(sp, &newDataPoints, 2, &ho_emlrtRTEI, true);
  b_i = newDataPoints->size[0] * newDataPoints->size[1];
  newDataPoints->size[0] = trueCount;
  newDataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(sp, newDataPoints, b_i, &ho_emlrtRTEI);
  input_sizes_idx_0 = trueCount << 1;
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints->data[b_i] = 0.0;
  }

  emxInit_boolean_T(sp, &r, 1, &io_emlrtRTEI, true);
  b_i = r->size[0];
  r->size[0] = segmentsToSplit->size[0] + 1;
  emxEnsureCapacity_boolean_T(sp, r, b_i, &io_emlrtRTEI);
  input_sizes_idx_0 = segmentsToSplit->size[0];
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r->data[b_i] = segmentsToSplit->data[b_i];
  }

  r->data[segmentsToSplit->size[0]] = false;
  end = r->size[0];
  for (i = 0; i < end; i++) {
    if (r->data[i]) {
      b_i = dataPoints->size[0];
      input_sizes_idx_0 = i + 1;
      if ((input_sizes_idx_0 < 1) || (input_sizes_idx_0 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(input_sizes_idx_0, 1, b_i, &wq_emlrtBCI,
          sp);
      }
    }
  }

  emxInit_boolean_T(sp, &r1, 1, &jo_emlrtRTEI, true);
  b_i = r1->size[0];
  r1->size[0] = segmentsToSplit->size[0] + 1;
  emxEnsureCapacity_boolean_T(sp, r1, b_i, &jo_emlrtRTEI);
  r1->data[0] = false;
  input_sizes_idx_0 = segmentsToSplit->size[0];
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r1->data[b_i + 1] = segmentsToSplit->data[b_i];
  }

  end = r1->size[0];
  for (i = 0; i < end; i++) {
    if (r1->data[i]) {
      b_i = dataPoints->size[0];
      input_sizes_idx_0 = i + 1;
      if ((input_sizes_idx_0 < 1) || (input_sizes_idx_0 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(input_sizes_idx_0, 1, b_i, &xq_emlrtBCI,
          sp);
      }
    }
  }

  end = r->size[0] - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r->data[i]) {
      input_sizes_idx_0++;
    }
  }

  emxInit_int32_T(sp, &r2, 1, &io_emlrtRTEI, true);
  b_i = r2->size[0];
  r2->size[0] = input_sizes_idx_0;
  emxEnsureCapacity_int32_T(sp, r2, b_i, &ko_emlrtRTEI);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r->data[i]) {
      r2->data[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }

  end = r1->size[0] - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1->data[i]) {
      input_sizes_idx_0++;
    }
  }

  emxInit_int32_T(sp, &r3, 1, &jo_emlrtRTEI, true);
  b_i = r3->size[0];
  r3->size[0] = input_sizes_idx_0;
  emxEnsureCapacity_int32_T(sp, r3, b_i, &ko_emlrtRTEI);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1->data[i]) {
      r3->data[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }

  if (r2->size[0] != r3->size[0]) {
    emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &bb_emlrtECI, sp);
  }

  emxFree_int32_T(&r3);
  emxFree_int32_T(&r2);
  end = r->size[0] - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r->data[i]) {
      input_sizes_idx_0++;
    }
  }

  emxInit_int32_T(sp, &r4, 1, &io_emlrtRTEI, true);
  b_i = r4->size[0];
  r4->size[0] = input_sizes_idx_0;
  emxEnsureCapacity_int32_T(sp, r4, b_i, &ko_emlrtRTEI);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r->data[i]) {
      r4->data[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }

  emxFree_boolean_T(&r);
  end = r1->size[0] - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1->data[i]) {
      input_sizes_idx_0++;
    }
  }

  emxInit_int32_T(sp, &r5, 1, &jo_emlrtRTEI, true);
  b_i = r5->size[0];
  r5->size[0] = input_sizes_idx_0;
  emxEnsureCapacity_int32_T(sp, r5, b_i, &ko_emlrtRTEI);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1->data[i]) {
      r5->data[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }

  emxFree_boolean_T(&r1);
  emxInit_real_T(sp, &r6, 1, &ko_emlrtRTEI, true);
  b_i = r6->size[0];
  r6->size[0] = r4->size[0];
  emxEnsureCapacity_real_T(sp, r6, b_i, &lo_emlrtRTEI);
  input_sizes_idx_0 = r4->size[0];
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r6->data[b_i] = 0.5 * (dataPoints->data[r4->data[b_i] - 1] +
      dataPoints->data[r5->data[b_i] - 1]);
  }

  emxFree_int32_T(&r5);
  emxFree_int32_T(&r4);
  emlrtSubAssignSizeCheckR2012b(&trueCount, 1, &r6->size[0], 1, &cb_emlrtECI, sp);
  input_sizes_idx_0 = r6->size[0];
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints->data[b_i] = r6->data[b_i];
  }

  emxInit_real_T(sp, &r7, 1, &ko_emlrtRTEI, true);
  st.site = &ie_emlrtRSI;

  /*  Subfunctions */
  /*  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N */
  /*  is the number of elements of x and M is the number of outputs of func. */
  /*  All the outputs of func must be scalar. */
  /*  The optional parameter 'vectorizable' (default false) allows to specify */
  /*  that the input function can be vectorized. */
  /*  Modified by AVH for use with coder */
  /* if (~exist('vectorizable','var') || isempty(vectorizable)) */
  /*  end */
  /* abs(nargout(func)); %for anonymous functions nargout<0 */
  b_i = r7->size[0];
  r7->size[0] = newDataPoints->size[0];
  emxEnsureCapacity_real_T(&st, r7, b_i, &mo_emlrtRTEI);

  /*  if vectorizable */
  /*    % For uniformity reasons, transform the 'x' array into a column vector. */
  /*    % In this way it does not matter if it is given as a column or a row */
  /*    % vector. */
  /*    [newValues{:}] = func(x(:)); */
  /*    y = cell2mat(newValues); */
  /*  else */
  b_i = newDataPoints->size[0] - 1;
  for (i = 0; i <= b_i; i++) {
    /*  Remove cell array so no need for cell2mat */
    /*  which won't compile - AVH */
    /* [newValues{:}] = func(x(i)); */
    /* y(i,:) = cell2mat(newValues); */
    input_sizes_idx_0 = i + 1;
    if ((input_sizes_idx_0 < 1) || (input_sizes_idx_0 > newDataPoints->size[0]))
    {
      emlrtDynamicBoundsCheckR2012b(input_sizes_idx_0, 1, newDataPoints->size[0],
        &yq_emlrtBCI, &st);
    }

    b_st.site = &ad_emlrtRSI;
    sldFunc(&b_st, newDataPoints->data[input_sizes_idx_0 - 1], sldProfile, r6);
    if (1 != r6->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(1, r6->size[0], &e_emlrtECI, &st);
    }

    input_sizes_idx_0 = i + 1;
    if ((input_sizes_idx_0 < 1) || (input_sizes_idx_0 > r7->size[0])) {
      emlrtDynamicBoundsCheckR2012b(input_sizes_idx_0, 1, r7->size[0],
        &ar_emlrtBCI, &st);
    }

    r7->data[input_sizes_idx_0 - 1] = r6->data[0];
  }

  emxFree_real_T(&r6);

  /* end */
  emlrtSubAssignSizeCheckR2012b(&newDataPoints->size[0], 1, &r7->size[0], 1,
    &db_emlrtECI, sp);
  input_sizes_idx_0 = r7->size[0];
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints->data[b_i + newDataPoints->size[0]] = r7->data[b_i];
  }

  emxFree_real_T(&r7);
  emxInit_real_T(sp, &b_dataPoints, 2, &no_emlrtRTEI, true);

  /*  For simplicity append the new points at the end and then sort. */
  st.site = &je_emlrtRSI;
  if (newDataPoints->size[0] != 0) {
    input_sizes_idx_0 = newDataPoints->size[0];
  } else {
    input_sizes_idx_0 = 0;
  }

  if (dataPoints->size[0] != 0) {
    end = dataPoints->size[0];
  } else {
    end = 0;
  }

  b_i = b_dataPoints->size[0] * b_dataPoints->size[1];
  b_dataPoints->size[0] = end + input_sizes_idx_0;
  b_dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b_dataPoints, b_i, &no_emlrtRTEI);
  for (b_i = 0; b_i < end; b_i++) {
    b_dataPoints->data[b_i] = dataPoints->data[b_i];
  }

  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    b_dataPoints->data[b_i + end] = newDataPoints->data[b_i];
  }

  for (b_i = 0; b_i < end; b_i++) {
    b_dataPoints->data[b_i + b_dataPoints->size[0]] = dataPoints->data[b_i +
      dataPoints->size[0]];
  }

  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    b_dataPoints->data[(b_i + end) + b_dataPoints->size[0]] =
      newDataPoints->data[b_i + newDataPoints->size[0]];
  }

  emxFree_real_T(&newDataPoints);
  b_i = dataPoints->size[0] * dataPoints->size[1];
  dataPoints->size[0] = b_dataPoints->size[0];
  dataPoints->size[1] = 2;
  emxEnsureCapacity_real_T(sp, dataPoints, b_i, &ko_emlrtRTEI);
  input_sizes_idx_0 = b_dataPoints->size[0];
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    dataPoints->data[b_i] = b_dataPoints->data[b_i];
  }

  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    dataPoints->data[b_i + dataPoints->size[0]] = b_dataPoints->data[b_i +
      b_dataPoints->size[0]];
  }

  emxFree_real_T(&b_dataPoints);
  st.site = &je_emlrtRSI;
  sortrows(&st, dataPoints);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (adaptive.c) */
