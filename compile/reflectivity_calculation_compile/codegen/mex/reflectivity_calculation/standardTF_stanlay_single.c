/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_single.c
 *
 * Code generation for function 'standardTF_stanlay_single'
 *
 */

/* Include files */
#include "standardTF_stanlay_single.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = { 57,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 66,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 71,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 91,  /* lineNo */
  "standardTF_stanlay_single",         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pathName */
};

static emlrtRTEInfo y_emlrtRTEI = { 38,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 43,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 60,/* lineNo */
  9,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  84,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  95,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  106,                                 /* colNo */
  "cScales",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  115,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  124,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  132,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  24,                                  /* colNo */
  "params",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  29,                                  /* colNo */
  "resample",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  35,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  31,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  37,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  24,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  33,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  31,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 25,  /* lineNo */
  17,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 24,  /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 24, /* lineNo */
  16,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  52,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  5,                                   /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  5,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  5,                                   /* colNo */
  "qshifts",                           /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  5,                                   /* colNo */
  "sfs",                               /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  111,                                 /* lineNo */
  5,                                   /* colNo */
  "nbas",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  112,                                 /* lineNo */
  5,                                   /* colNo */
  "nbss",                              /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  5,                                   /* colNo */
  "resols",                            /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo jg_emlrtRTEI = { 24,/* lineNo */
  10,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo kg_emlrtRTEI = { 4,/* lineNo */
  18,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo lg_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo mg_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo ng_emlrtRTEI = { 49,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo og_emlrtRTEI = { 31,/* lineNo */
  12,                                  /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo pg_emlrtRTEI = { 102,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo qg_emlrtRTEI = { 103,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo rg_emlrtRTEI = { 57,/* lineNo */
  1,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

static emlrtRTEInfo sg_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "standardTF_stanlay_single",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"/* pName */
};

/* Function Definitions */
void standardTF_stanlay_single(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_15 *problemDef_cells, const struct2_T *controls, emxArray_real_T
  *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts, emxArray_real_T *
  sfs, emxArray_real_T *nbas, emxArray_real_T *nbss, emxArray_real_T *resols,
  emxArray_real_T *chis, emxArray_cell_wrap_12 *reflectivity,
  emxArray_cell_wrap_7 *Simulation, emxArray_cell_wrap_1 *shifted_data,
  emxArray_cell_wrap_1 *layerSlds, emxArray_cell_wrap_12 *sldProfiles,
  emxArray_cell_wrap_12 *allLayers, emxArray_real_T *allRoughs)
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
  covrtLogFcn(&emlrtCoverageInstance, 3U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 0U);

  /*  Extract individual cell arrays */
  covrtLogFcn(&emlrtCoverageInstance, 4U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4U, 0U);

  /*  Extract individual parameters from problemDef struct */
  covrtLogFcn(&emlrtCoverageInstance, 5U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 0U);

  /* Extract individual parameters from problemDef */
  /*  Allocate the memory for the output arrays before the main loop */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &ab_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &y_emlrtDCI, sp);
  }

  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &jg_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &x_emlrtDCI, sp);
  }

  i = (int32_T)problemDef->numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &y_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i1, &kg_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 1U);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yb_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &lg_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yb_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &lg_emlrtRTEI);
    i1 = reflectivity->size[0] - 1;
    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &yb_emlrtBCI, sp);
    }

    i2 = reflectivity->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &yb_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yb_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yb_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yb_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yb_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 2U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ab_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_7(sp, Simulation, i1, &kg_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 3U);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ac_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &mg_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ac_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &mg_emlrtRTEI);
    i1 = Simulation->size[0] - 1;
    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ac_emlrtBCI, sp);
    }

    i2 = Simulation->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ac_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ac_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ac_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ac_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ac_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
  }

  covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 4U);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &bb_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, allLayers, i1, &kg_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 5U);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bc_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ng_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bc_emlrtBCI, sp);
    }

    i1 = allLayers->data[b_i].f1->size[0] * allLayers->data[b_i].f1->size[1];
    allLayers->data[b_i].f1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, allLayers->data[b_i].f1, i1, &ng_emlrtRTEI);
    i1 = allLayers->size[0] - 1;
    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bc_emlrtBCI, sp);
    }

    i2 = allLayers->size[0] - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bc_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bc_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bc_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1->data[1] = 1.0;
  }

  emxInit_cell_wrap_18(sp, &outParameterisedLayers, 2, &rg_emlrtRTEI, true);
  covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 6U);

  /*  end memory allocation. */
  /*  First we need to allocate the absolute values of the input */
  /*  parameters to all the layers in the layers list. This only needs */
  /*  to be done once, and so is done outside the contrasts loop */
  st.site = &k_emlrtRSI;
  allocateParamsToLayers(&st, problemDef->params, problemDef_cells->f6,
    outParameterisedLayers);

  /*  Loop over all the contrasts */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &cb_emlrtRTEI, sp);
  i1 = outSsubs->size[0];
  outSsubs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, outSsubs, i1, &og_emlrtRTEI);
  i1 = sldProfiles->size[0];
  sldProfiles->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, sldProfiles, i1, &kg_emlrtRTEI);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_12(sp, reflectivity, i1, &kg_emlrtRTEI);
  i1 = Simulation->size[0];
  Simulation->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_7(sp, Simulation, i1, &kg_emlrtRTEI);
  i1 = shifted_data->size[0];
  shifted_data->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, shifted_data, i1, &kg_emlrtRTEI);
  i1 = layerSlds->size[0];
  layerSlds->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_cell_wrap_1(sp, layerSlds, i1, &kg_emlrtRTEI);
  i1 = chis->size[0];
  chis->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, chis, i1, &og_emlrtRTEI);
  i1 = qshifts->size[0];
  qshifts->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, qshifts, i1, &og_emlrtRTEI);
  i1 = sfs->size[0];
  sfs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, sfs, i1, &og_emlrtRTEI);
  i1 = nbas->size[0];
  nbas->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbas, i1, &og_emlrtRTEI);
  i1 = nbss->size[0];
  nbss->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, nbss, i1, &og_emlrtRTEI);
  i1 = resols->size[0];
  resols->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, resols, i1, &og_emlrtRTEI);
  i1 = allRoughs->size[0];
  allRoughs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &og_emlrtRTEI);
  emxInit_real_T(sp, &thisContrastLayers, 2, &sg_emlrtRTEI, true);
  emxInit_real_T(sp, &sldProfile, 2, &kg_emlrtRTEI, true);
  emxInit_real_T(sp, &reflect, 2, &kg_emlrtRTEI, true);
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 3, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 7U);

    /*  Extract the relevant parameter values for this contrast */
    /*  from the input arrays. */
    /*  First need to decide which values of the backrounds, scalefactors */
    /*  data shifts and bulk contrasts are associated with this contrast */
    st.site = &l_emlrtRSI;
    i1 = b_i + 1;
    if (i1 > problemDef->contrastBacks->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastBacks->size[1],
        &eb_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->contrastShifts->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastShifts->size[1],
        &fb_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->contrastScales->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastScales->size[1],
        &gb_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->contrastNbas->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastNbas->size[1],
        &hb_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->contrastNbss->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastNbss->size[1],
        &ib_emlrtBCI, &st);
    }

    i1 = b_i + 1;
    if (i1 > problemDef->contrastRes->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, problemDef->contrastRes->size[1],
        &jb_emlrtBCI, &st);
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
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &cc_emlrtBCI, sp);
    }

    st.site = &m_emlrtRSI;
    allocateLayersForContrast(&st, problemDef_cells->f5->data[b_i].f1,
      outParameterisedLayers, thisContrastLayers);

    /*  For the other parameters, we extract the correct ones from the input */
    /*  arrays */
    if (1 > problemDef->params->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params->size[1],
        &kb_emlrtBCI, sp);
    }

    /*  Substrate roughness is always first parameter for standard layers */
    i7 = problemDef_cells->f1->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &ob_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if (i7 > problemDef->resample->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, problemDef->resample->size[1],
        &lb_emlrtBCI, sp);
    }

    i7 = problemDef_cells->f2->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &pb_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if (i7 > problemDef->dataPresent->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, problemDef->dataPresent->size[1],
        &mb_emlrtBCI, sp);
    }

    i7 = problemDef_cells->f3->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &qb_emlrtBCI, sp);
    }

    i7 = problemDef_cells->f4->size[1] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &rb_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if (i7 > problemDef->contrastBacksType->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, problemDef->contrastBacksType->size[1],
        &nb_emlrtBCI, sp);
    }

    /*  Now call the core standardTF_stanlay reflectivity calculation */
    /*  In this case we are single cored, so we do not parallelise over */
    /*  points */
    /*  Call the calculation */
    i7 = Simulation->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &dc_emlrtBCI, sp);
    }

    i7 = shifted_data->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &ec_emlrtBCI, sp);
    }

    i7 = layerSlds->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &fc_emlrtBCI, sp);
    }

    i7 = b_i + 1;
    if (i7 > chis->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, chis->size[0], &gc_emlrtBCI, sp);
    }

    i8 = b_i + 1;
    if (i8 > outSsubs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i8, 1, outSsubs->size[0], &hc_emlrtBCI, sp);
    }

    st.site = &n_emlrtRSI;
    standardTF_layers_core(&st, thisContrastLayers, problemDef->params->data[0],
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
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &ic_emlrtBCI, sp);
    }

    i7 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[0] = sldProfile->size[0];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i7, &pg_emlrtRTEI);
    i7 = sldProfiles->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &ic_emlrtBCI, sp);
    }

    i7 = sldProfiles->data[b_i].f1->size[0] * sldProfiles->data[b_i].f1->size[1];
    sldProfiles->data[b_i].f1->size[1] = sldProfile->size[1];
    emxEnsureCapacity_real_T(sp, sldProfiles->data[b_i].f1, i7, &pg_emlrtRTEI);
    i7 = sldProfiles->size[0] - 1;
    i8 = sldProfiles->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &ic_emlrtBCI, sp);
    }

    i8 = sldProfiles->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &ic_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &ic_emlrtBCI, sp);
      }

      sldProfiles->data[b_i].f1->data[i8] = sldProfile->data[i8];
    }

    loop_ub = reflect->size[0] * reflect->size[1];
    i7 = reflectivity->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &jc_emlrtBCI, sp);
    }

    i7 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = reflect->size[0];
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i7, &qg_emlrtRTEI);
    i7 = reflectivity->size[0] - 1;
    if (b_i > i7) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &jc_emlrtBCI, sp);
    }

    i7 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i7, &qg_emlrtRTEI);
    i7 = reflectivity->size[0] - 1;
    i8 = reflectivity->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &jc_emlrtBCI, sp);
    }

    i8 = reflectivity->size[0] - 1;
    if (b_i > i8) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i8, &jc_emlrtBCI, sp);
    }

    for (i8 = 0; i8 < loop_ub; i8++) {
      if (b_i > i7) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i7, &jc_emlrtBCI, sp);
      }

      reflectivity->data[b_i].f1->data[i8] = reflect->data[i8];
    }

    i7 = b_i + 1;
    if (i7 > backgs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i7, 1, backgs->size[0], &kc_emlrtBCI, sp);
    }

    backgs->data[i7 - 1] = problemDef->backs->data[i1 - 1];
    i1 = b_i + 1;
    if (i1 > qshifts->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, qshifts->size[0], &lc_emlrtBCI, sp);
    }

    qshifts->data[i1 - 1] = problemDef->shifts->data[i2 - 1];
    i1 = b_i + 1;
    if (i1 > sfs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, sfs->size[0], &mc_emlrtBCI, sp);
    }

    sfs->data[i1 - 1] = problemDef->sf->data[i3 - 1];
    i1 = b_i + 1;
    if (i1 > nbas->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbas->size[0], &nc_emlrtBCI, sp);
    }

    nbas->data[i1 - 1] = problemDef->nba->data[i4 - 1];
    i1 = b_i + 1;
    if (i1 > nbss->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, nbss->size[0], &oc_emlrtBCI, sp);
    }

    nbss->data[i1 - 1] = problemDef->nbs->data[i5 - 1];
    i1 = b_i + 1;
    if (i1 > resols->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, resols->size[0], &pc_emlrtBCI, sp);
    }

    resols->data[i1 - 1] = problemDef->res->data[i6 - 1];
    i1 = b_i + 1;
    if (i1 > allRoughs->size[0]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, allRoughs->size[0], &qc_emlrtBCI, sp);
    }

    allRoughs->data[i1 - 1] = problemDef->params->data[0];
  }

  emxFree_real_T(&reflect);
  emxFree_real_T(&sldProfile);
  emxFree_real_T(&thisContrastLayers);
  emxFree_cell_wrap_18(&outParameterisedLayers);
  covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 3, 0);

  /*  Debug plotting */
  /*  figure(1);clf; hold on */
  /*  for i = 1:length(sldProfiles) */
  /*      thisProfile = sldProfiles{i}; */
  /*      plot(thisProfile(:,1),thisProfile(:,2)) */
  /*      drawnow */
  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_stanlay_single.c) */
