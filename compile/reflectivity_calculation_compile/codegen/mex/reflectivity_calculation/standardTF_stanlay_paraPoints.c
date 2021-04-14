/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_paraPoints.c
 *
 * Code generation for function 'standardTF_stanlay_paraPoints'
 *
 */

/* Include files */
#include "standardTF_stanlay_paraPoints.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"

/* Variable Definitions */
static emlrtRSInfo hg_emlrtRSI = { 58, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 67, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 72, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 91, /* lineNo */
  "standardTF_stanlay_paraPoints",     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pathName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 39,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 49,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 61,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtBCInfo rf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  84,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  95,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  106,                                 /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  115,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  124,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  132,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  24,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  78,                                  /* lineNo */
  29,                                  /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ag_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  35,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  31,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  37,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  24,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  33,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  31,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo lb_emlrtDCI = { 26, /* lineNo */
  17,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo mb_emlrtDCI = { 25, /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo nb_emlrtDCI = { 25, /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo gg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ig_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ng_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo og_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  5,                                   /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  5,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  5,                                   /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ug_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  5,                                   /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo lk_emlrtRTEI = { 25,/* lineNo */
  10,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo mk_emlrtRTEI = { 4,/* lineNo */
  18,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo nk_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo ok_emlrtRTEI = { 45,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo pk_emlrtRTEI = { 50,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo qk_emlrtRTEI = { 32,/* lineNo */
  12,                                  /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo rk_emlrtRTEI = { 102,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo sk_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo tk_emlrtRTEI = { 58,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

static emlrtRTEInfo uk_emlrtRTEI = { 72,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_paraPoints",     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"/* pName */
};

/* Function Definitions */
void standardTF_stanlay_paraPoints(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_15 *problemDef_cells, const struct2_T *controls,
  emxArray_real_T *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts,
  emxArray_real_T *sfs, emxArray_real_T *nbas, emxArray_real_T *nbss,
  emxArray_real_T *resols, emxArray_real_T *chis, emxArray_cell_wrap_12
  *reflectivity, emxArray_cell_wrap_7 *Simulation, emxArray_cell_wrap_1
  *shifted_data, emxArray_cell_wrap_1 *layerSlds, emxArray_cell_wrap_12
  *sldProfiles, emxArray_cell_wrap_12 *allLayers, emxArray_real_T *allRoughs)
{
  int32_T i;
  int32_T i1;
  int32_T b_i;
  int32_T i2;
  emxArray_cell_wrap_18 *outParameterisedLayers;
  emxArray_real_T *thisContrastLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *reflect;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T loop_ub;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 23U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 0U);

  /*  Extract individual cell arrays */
  covrtLogFcn(&emlrtCoverageInstance, 4U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 0U);

  /*  Extract individual parameters from problemDef */
  covrtLogFcn(&emlrtCoverageInstance, 5U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 0U);

  /* Extract individual parameters from problemDef */
  /*  Allocate the memory for the output arrays before the main loop */
  /*    --- Begin memory allocation --- */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &nb_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &mb_emlrtDCI, sp);
  }

  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &lk_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &lb_emlrtDCI, sp);
  }

  i = (int32_T)problemDef->numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &tb_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i1, &mk_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 1U);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gg_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &nk_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gg_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &nk_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gg_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &gg_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gg_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gg_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gg_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gg_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ub_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_7(sp, Simulation, i1, &mk_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 3U);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hg_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &ok_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hg_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &ok_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hg_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &hg_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hg_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hg_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hg_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &hg_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &vb_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, allLayers, i1, &mk_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 5U);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ig_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &pk_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ig_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &pk_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ig_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ig_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ig_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ig_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  emxInit_cell_wrap_18(sp, &outParameterisedLayers, 2, &tk_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 6U);

  /*  ---end memory allocation--- */
  /*  First we need to allocate the absolute values of the input */
  /*  parameters to all the layers in the layers list. This only needs */
  /*  to be done once, and so is done outside the contrasts loop */
  st.site = &hg_emlrtRSI;
  allocateParamsToLayers(&st, problemDef->params, problemDef_cells->f6,
    outParameterisedLayers);

  /*  Single Loop over all the contrasts */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &wb_emlrtRTEI, sp);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &qk_emlrtRTEI);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i1, &mk_emlrtRTEI);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i1, &mk_emlrtRTEI);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_7(sp, Simulation, i1, &mk_emlrtRTEI);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i1, &mk_emlrtRTEI);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i1, &mk_emlrtRTEI);
  i1 = chis->size[0];
  chis->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &qk_emlrtRTEI);
  i1 = qshifts->size[0];
  qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i1, &qk_emlrtRTEI);
  i1 = sfs->size[0];
  sfs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i1, &qk_emlrtRTEI);
  i1 = nbas->size[0];
  nbas->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i1, &qk_emlrtRTEI);
  i1 = nbss->size[0];
  nbss->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i1, &qk_emlrtRTEI);
  i1 = resols->size[0];
  resols->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i1, &qk_emlrtRTEI);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &qk_emlrtRTEI);
  emxInit_real_T(sp, &thisContrastLayers, 2, &uk_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &mk_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &mk_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 7U);

    /*  Extract the relevant parameter values for this contrast */
    /*  from the input arrays. */
    /*  First need to decide which values of the backrounds, scalefactors */
    /*  data shifts and bulk contrasts are associated with this contrast */
    st.site = &ig_emlrtRSI;
    i1 = b_i + 1;
    if (i1 > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastBacks->size[1],
        &rf_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastShifts->size[1],
        &sf_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastScales->size[1],
        &tf_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastNbas->size[1],
        &uf_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastNbss->size[1],
        &vf_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastRes->size[1],
        &wf_emlrtBCI, &st);
    }

    covrtLogFcn(&emlrtCoverageInstance, 7U, 0U);
    covrtLogBasicBlock(&emlrtCoverageInstance, 7U, 0U);

    /* Distributes the background and shift values among the different contrasts. */
    /*  */
    /* [backgs,qshifts,sfs,nbas,nbss,resols] = backSort(nc,cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res) */
    /*  Inputs: */
    /*        nc = number of contrasts (double) */
    /*        cBacks = Which backround value is associated with each contrast? */
    /*        cShifts = Which qz_shift value is associated with each contrast? */
    /*        cScales = Which scalefactor value is associated with each contrast? */
    /*        cNba = Which NBa value is associated with each contrast? */
    /*        cNbs = Which Nbs value is associated with each contrast? */
    /*        cRes = Which resolution value is associated with each contrast? */
    /*        backs = List of all background values. */
    /*        shifts = List of all qz-shift values */
    /*        sf = List of all scalefactor values */
    /*        nba = List of all nba values */
    /*        nbs = List of all nbs values */
    /*        res = List of all resolution values */
    /*  */
    /*  Outputs: */
    /*        backgs = list of actual background values for each contrast */
    /*        qshifts = list of actual shift values for each contrast       */
    /*        sfs = list of actual shift values for each contrast      */
    /*        nbas = list of actual shift values for each contrast      */
    /*        nbss = list of actual shift values for each contrast */
    /*        nbss = list of actual shift values for each contrast   */
    /*  backgs = 0;%zeros(1,nc); */
    /*  qshifts = 0;%zeros(1,nc); */
    /*  sfs = 0;%zeros(1,nc); */
    /*  nbas = 0;%zeros(1,nc); */
    /*  nbss = 0;%zeros(1,nc); */
    /*  resols = 0;%zeros(1,nc); */
    /* for i = 1:nc */
    /* thisBack = cBacks(i); */
    if (problemDef->contrastBacks->data[b_i] != (int32_T)muDoubleScalarFloor
        (problemDef->contrastBacks->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastBacks->data[b_i], &r_emlrtDCI,
        &st);
    }

    i1 = (int32_T)problemDef->contrastBacks->data[b_i];
    if ((i1 < 1) || (i1 > problemDef->backs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->backs->size[1],
        &sb_emlrtBCI, &st);
    }

    /* thisShift = cShifts(i); */
    if (problemDef->contrastShifts->data[b_i] != (int32_T)muDoubleScalarFloor
        (problemDef->contrastShifts->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastShifts->data[b_i], &s_emlrtDCI,
        &st);
    }

    i2 = (int32_T)problemDef->contrastShifts->data[b_i];
    if ((i2 < 1) || (i2 > problemDef->shifts->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, problemDef->shifts->size[1],
        &tb_emlrtBCI, &st);
    }

    /* thisScale = cScales(i); */
    if (problemDef->contrastScales->data[b_i] != (int32_T)muDoubleScalarFloor
        (problemDef->contrastScales->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastScales->data[b_i], &t_emlrtDCI,
        &st);
    }

    i3 = (int32_T)problemDef->contrastScales->data[b_i];
    if ((i3 < 1) || (i3 > problemDef->sf->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, problemDef->sf->size[1], &ub_emlrtBCI,
        &st);
    }

    /* thisNbair = cNbas(i); */
    if (problemDef->contrastNbas->data[b_i] != (int32_T)muDoubleScalarFloor
        (problemDef->contrastNbas->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastNbas->data[b_i], &u_emlrtDCI,
        &st);
    }

    i4 = (int32_T)problemDef->contrastNbas->data[b_i];
    if ((i4 < 1) || (i4 > problemDef->nba->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, problemDef->nba->size[1],
        &vb_emlrtBCI, &st);
    }

    /* thisNbsub = cNbss(i); */
    if (problemDef->contrastNbss->data[b_i] != (int32_T)muDoubleScalarFloor
        (problemDef->contrastNbss->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastNbss->data[b_i], &v_emlrtDCI,
        &st);
    }

    i5 = (int32_T)problemDef->contrastNbss->data[b_i];
    if ((i5 < 1) || (i5 > problemDef->nbs->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, problemDef->nbs->size[1],
        &wb_emlrtBCI, &st);
    }

    /* thisResol = cRes(i); */
    if (problemDef->contrastRes->data[b_i] != (int32_T)muDoubleScalarFloor
        (problemDef->contrastRes->data[b_i])) {
      emlrtIntegerCheckR2012b(problemDef->contrastRes->data[b_i], &w_emlrtDCI,
        &st);
    }

    i6 = (int32_T)problemDef->contrastRes->data[b_i];
    if ((i6 < 1) || (i6 > problemDef->res->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, problemDef->res->size[1],
        &xb_emlrtBCI, &st);
    }

    /* end */
    /*  Also need to determine which layers from the overall layers list */
    /*  are required for this contrast, and put them in the correct order  */
    /*  according to geometry */
    i7 = problemDef_cells->f5->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &jg_emlrtBCI, sp);
    }

    st.site = &jg_emlrtRSI;
    allocateLayersForContrast(&st, problemDef_cells->f5->data[b_i].f1,
      outParameterisedLayers, thisContrastLayers);

    /*  For the other parameters, we extract the correct ones from the input */
    /*  arrays */
    if (1 > problemDef->params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
        &xf_emlrtBCI, sp);
    }

    /*  Substrate roughness is always first parameter for standard layers */
    i7 = problemDef_cells->f1->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &cg_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if (i7 > problemDef->resample->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, problemDef->resample->size[1],
        &yf_emlrtBCI, sp);
    }

    i7 = problemDef_cells->f2->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &dg_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if (i7 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, problemDef->dataPresent->size[1],
        &ag_emlrtBCI, sp);
    }

    i7 = problemDef_cells->f3->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &eg_emlrtBCI, sp);
    }

    i7 = problemDef_cells->f4->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &fg_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if (i7 > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, problemDef->contrastBacksType->size[1],
        &bg_emlrtBCI, sp);
    }

    /*  Now call the core standardTF_stanlay reflectivity calculation */
    /*  In this case we parallelise over points. */
    /*  Call the calculation */
    i7 = Simulation->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &kg_emlrtBCI, sp);
    }

    i7 = shifted_data->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &lg_emlrtBCI, sp);
    }

    i7 = layerSlds->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &mg_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if (i7 > chis->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, chis->size[0], &ng_emlrtBCI, sp);
    }

    i8 = b_i + 1;
    if (i8 > outSsubs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i8, 1, outSsubs->size[0], &og_emlrtBCI, sp);
    }

    st.site = &kg_emlrtRSI;
    b_standardTF_layers_core(&st, thisContrastLayers, problemDef->params->data[0],
      problemDef->geometry, problemDef->nba->data[(int32_T)
      problemDef->contrastNbas->data[b_i] - 1], problemDef->nbs->data[(int32_T)
      problemDef->contrastNbss->data[b_i] - 1], problemDef->resample->data[b_i],
      controls->calcSld, problemDef->sf->data[(int32_T)
      problemDef->contrastScales->data[b_i] - 1], problemDef->shifts->data
      [(int32_T)problemDef->contrastShifts->data[b_i] - 1],
      problemDef->dataPresent->data[b_i], problemDef_cells->f2->data[b_i].f1,
      problemDef_cells->f3->data[b_i].f1, problemDef_cells->f4->data[b_i].f1,
      problemDef_cells->f1->data[b_i].f1, problemDef->backs->data[(int32_T)
      problemDef->contrastBacks->data[b_i] - 1], problemDef->res->data[(int32_T)
      problemDef->contrastRes->data[b_i] - 1], problemDef->
      contrastBacksType->data[b_i], problemDef->params->size[1], sldProfile,
      reflect, Simulation->data[b_i].f1, shifted_data->data[b_i].f1,
      layerSlds->data[b_i].f1, &chis->data[i7 - 1], &outSsubs->data[i8 - 1]);

    /*  Store returned values for this contrast in the output arrays. */
    /*  As well as the calculated profiles, we also store a record of  */
    /*  the other values (background, scalefactors etc) for each contrast */
    /*  for future use. */
    loop_ub = sldProfile->size[0] * sldProfile->size[1];
    i7 = sldProfiles->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &pg_emlrtBCI, sp);
    }

    i7 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i7, &rk_emlrtRTEI);
    i7 = sldProfiles->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &pg_emlrtBCI, sp);
    }

    i7 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i7, &rk_emlrtRTEI);
    i7 = sldProfiles->size[0] - 1;
    i8 = sldProfiles->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &pg_emlrtBCI, sp);
    }

    i8 = sldProfiles->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &pg_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &pg_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i8] = sldProfile->data[i8];
    }

    loop_ub = reflect->size[0] * reflect->size[1];
    i7 = reflectivity->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &qg_emlrtBCI, sp);
    }

    i7 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = reflect->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i7, &sk_emlrtRTEI);
    i7 = reflectivity->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &qg_emlrtBCI, sp);
    }

    i7 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i7, &sk_emlrtRTEI);
    i7 = reflectivity->size[0] - 1;
    i8 = reflectivity->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &qg_emlrtBCI, sp);
    }

    i8 = reflectivity->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &qg_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &qg_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i8] = reflect->data[i8];
    }

    i7 = b_i + 1;
    if (i7 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, backgs->size[0], &rg_emlrtBCI, sp);
    }

    backgs->data[i7 - 1] = problemDef->backs->data[i1 - 1];
    i1 = b_i + 1;
    if (i1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &sg_emlrtBCI, sp);
    }

    qshifts->data[i1 - 1] = problemDef->shifts->data[i2 - 1];
    i1 = b_i + 1;
    if (i1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sfs->size[0], &tg_emlrtBCI, sp);
    }

    sfs->data[i1 - 1] = problemDef->sf->data[i3 - 1];
    i1 = b_i + 1;
    if (i1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &ug_emlrtBCI, sp);
    }

    nbas->data[i1 - 1] = problemDef->nba->data[i4 - 1];
    i1 = b_i + 1;
    if (i1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &vg_emlrtBCI, sp);
    }

    nbss->data[i1 - 1] = problemDef->nbs->data[i5 - 1];
    i1 = b_i + 1;
    if (i1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resols->size[0], &wg_emlrtBCI, sp);
    }

    resols->data[i1 - 1] = problemDef->res->data[i6 - 1];
    i1 = b_i + 1;
    if (i1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &xg_emlrtBCI, sp);
    }

    allRoughs->data[i1 - 1] = problemDef->params->data[0];
  }

  emxFree_real_T(&reflect);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&thisContrastLayers);
  emxFree_cell_wrap_18(&outParameterisedLayers);
  covrtLogFor(&emlrtCoverageInstance, 23U, 0U, 3, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_stanlay_paraPoints.c) */
