/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_paraContrasts.c
 *
 * Code generation for function 'standardTF_custlay_paraContrasts'
 *
 */

/* Include files */
#include "standardTF_custlay_paraContrasts.h"
#include "backSort.h"
#include "loopCppCustlayWrapper.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_mexutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo oh_emlrtRSI = { 78, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo ph_emlrtRSI = { 82, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo qh_emlrtRSI = { 96, /* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtRSInfo rh_emlrtRSI = { 117,/* lineNo */
  "standardTF_custlay_paraContrasts",  /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pathName */
};

static emlrtMCInfo c_emlrtMCI = { 23,  /* lineNo */
  2,                                   /* colNo */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pName */
};

static emlrtDCInfo pc_emlrtDCI = { 45, /* lineNo */
  18,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo vc_emlrtRTEI = { 51,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 61,/* lineNo */
  9,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtDCInfo qc_emlrtDCI = { 91, /* lineNo */
  14,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo yc_emlrtRTEI = { 91,/* lineNo */
  12,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtBCInfo sq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  101,                                 /* lineNo */
  27,                                  /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  29,                                  /* colNo */
  "resample",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  35,                                  /* colNo */
  "dataPresent",                       /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  31,                                  /* colNo */
  "backsType",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo fb_emlrtECI = { 1,  /* nDims */
  134,                                 /* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtBCInfo wq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  20,                                  /* colNo */
  "customFiles",                       /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  36,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yq_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  37,                                  /* colNo */
  "repeatLayers",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ar_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  24,                                  /* colNo */
  "allData",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo br_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  107,                                 /* lineNo */
  33,                                  /* colNo */
  "dataLimits",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  31,                                  /* colNo */
  "simLimits",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo rc_emlrtDCI = { 9,  /* lineNo */
  23,                                  /* colNo */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo ad_emlrtRTEI = { 13,/* lineNo */
  10,                                  /* colNo */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 28,/* lineNo */
  10,                                  /* colNo */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pName */
};

static emlrtBCInfo dr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  30,                                  /* colNo */
  "tempAllLayers",                     /* aName */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo er_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  16,                                  /* colNo */
  "allLayers",                         /* aName */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ir_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  20,                                  /* colNo */
  "tempAllLayers",                     /* aName */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  16,                                  /* colNo */
  "allLayers",                         /* aName */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  17,                                  /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  18,                                  /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  16,                                  /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  132,                                 /* lineNo */
  18,                                  /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo or_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  15,                                  /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo sc_emlrtDCI = { 37, /* lineNo */
  17,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo tc_emlrtDCI = { 36, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo uc_emlrtDCI = { 36, /* lineNo */
  16,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo vc_emlrtDCI = { 42, /* lineNo */
  1,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo pr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  6,                                   /* colNo */
  "tempAllLayers",                     /* aName */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  6,                                   /* colNo */
  "allLayers",                         /* aName */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  77,                                  /* colNo */
  "cBacks",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  87,                                  /* colNo */
  "cShifts",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  98,                                  /* colNo */
  "cScales",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ur_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  109,                                 /* colNo */
  "cNbas",                             /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  118,                                 /* colNo */
  "cNbss",                             /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  127,                                 /* colNo */
  "cRes",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  133,                                 /* lineNo */
  5,                                   /* colNo */
  "layerSlds",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yr_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  128,                                 /* lineNo */
  5,                                   /* colNo */
  "outSsubs",                          /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo as_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  5,                                   /* colNo */
  "sldProfiles",                       /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ds_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  132,                                 /* lineNo */
  5,                                   /* colNo */
  "shifted_data",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo es_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  136,                                 /* lineNo */
  5,                                   /* colNo */
  "chis",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  137,                                 /* lineNo */
  5,                                   /* colNo */
  "backgs",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  138,                                 /* lineNo */
  5,                                   /* colNo */
  "qshifts",                           /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo is_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  139,                                 /* lineNo */
  5,                                   /* colNo */
  "sfs",                               /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo js_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  140,                                 /* lineNo */
  5,                                   /* colNo */
  "nbas",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ks_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  141,                                 /* lineNo */
  5,                                   /* colNo */
  "nbss",                              /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ls_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  142,                                 /* lineNo */
  5,                                   /* colNo */
  "resols",                            /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ms_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  143,                                 /* lineNo */
  5,                                   /* colNo */
  "allRoughs",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ns_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "reflectivity",                      /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo os_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  5,                                   /* colNo */
  "Simulation",                        /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ps_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  5,                                   /* colNo */
  "allLayers",                         /* aName */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qs_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  6,                                   /* colNo */
  "allLayers",                         /* aName */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ip_emlrtRTEI = { 36,/* lineNo */
  10,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo jp_emlrtRTEI = { 42,/* lineNo */
  1,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo kp_emlrtRTEI = { 32,/* lineNo */
  11,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo lp_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo mp_emlrtRTEI = { 57,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo np_emlrtRTEI = { 43,/* lineNo */
  12,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo op_emlrtRTEI = { 78,/* lineNo */
  6,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo pp_emlrtRTEI = { 9,/* lineNo */
  23,                                  /* colNo */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pName */
};

static emlrtRTEInfo qp_emlrtRTEI = { 14,/* lineNo */
  6,                                   /* colNo */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pName */
};

static emlrtRTEInfo rp_emlrtRTEI = { 24,/* lineNo */
  57,                                  /* colNo */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pName */
};

static emlrtRTEInfo sp_emlrtRTEI = { 15,/* lineNo */
  6,                                   /* colNo */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pName */
};

static emlrtRTEInfo tp_emlrtRTEI = { 34,/* lineNo */
  6,                                   /* colNo */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pName */
};

static emlrtRTEInfo up_emlrtRTEI = { 129,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo vp_emlrtRTEI = { 130,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo wp_emlrtRTEI = { 131,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo xp_emlrtRTEI = { 132,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo yp_emlrtRTEI = { 3,/* lineNo */
  18,                                  /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo aq_emlrtRTEI = { 105,/* lineNo */
  5,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

static emlrtRTEInfo bq_emlrtRTEI = { 9,/* lineNo */
  2,                                   /* colNo */
  "loopMatalbCustlayWrapper",          /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pName */
};

static emlrtRSInfo yi_emlrtRSI = { 23, /* lineNo */
  "loopMatalbCustlayWrapper",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pathName */
};

static emlrtRSInfo dj_emlrtRSI = { 38, /* lineNo */
  "loopMatalbCustlayWrapper",          /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/loopMatlabCustomLayers/loopMatalbCustlayWrapper.m"/* pathName */
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    const mxArray *d, const mxArray *e, const mxArray *f, const
                    mxArray *g, const mxArray *h, const mxArray *i, const
                    mxArray *j, const mxArray *k, const mxArray *l, const
                    mxArray *m, const mxArray *n, const mxArray *o, const
                    mxArray *p, const mxArray *q, const mxArray *r, emlrtMCInfo *
                    location, const mxArray **s, const mxArray **t);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tempAllLayers, const char_T *identifier, emxArray_cell_wrap_26 *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_26 *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tempAllRoughs, const char_T *identifier, emxArray_real_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    const mxArray *d, const mxArray *e, const mxArray *f, const
                    mxArray *g, const mxArray *h, const mxArray *i, const
                    mxArray *j, const mxArray *k, const mxArray *l, const
                    mxArray *m, const mxArray *n, const mxArray *o, const
                    mxArray *p, const mxArray *q, const mxArray *r, emlrtMCInfo *
                    location, const mxArray **s, const mxArray **t)
{
  const mxArray *pArrays[17];
  const mxArray *mv[2];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  pArrays[5] = g;
  pArrays[6] = h;
  pArrays[7] = i;
  pArrays[8] = j;
  pArrays[9] = k;
  pArrays[10] = l;
  pArrays[11] = m;
  pArrays[12] = n;
  pArrays[13] = o;
  pArrays[14] = p;
  pArrays[15] = q;
  pArrays[16] = r;
  emlrtAssign(s, emlrtCallMATLABR2012b(sp, 2, &mv[0], 17, pArrays, "feval", true,
    location));
  emlrtAssign(t, mv[1]);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tempAllLayers, const char_T *identifier, emxArray_cell_wrap_26 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(tempAllLayers), &thisId, y);
  emlrtDestroyArray(&tempAllLayers);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_cell_wrap_26 *y)
{
  emlrtMsgIdentifier thisId;
  int32_T n[1];
  int32_T sizes[1];
  int32_T i;
  char_T str[11];
  boolean_T bv[1];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  n[0] = -1;
  bv[0] = true;
  emlrtCheckVsCell(sp, parentId, u, 1U, n, bv, sizes);
  i = y->size[0];
  y->size[0] = sizes[0];
  emxEnsureCapacity_cell_wrap_26(sp, y, i, (emlrtRTEInfo *)NULL);
  for (i = 0; i < sizes[0]; i++) {
    sprintf(&str[0], "%d", i + 1);
    thisId.fIdentifier = &str[0];
    i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i)), &thisId,
                       y->data[i].f1);
  }

  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  sb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *tempAllRoughs, const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  k_emlrt_marshallIn(sp, emlrtAlias(tempAllRoughs), &thisId, y);
  emlrtDestroyArray(&tempAllRoughs);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  tb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 10000, 5 };

  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = { true, true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  int32_T iv[1];
  int32_T i;
  const boolean_T bv[1] = { true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv[0],
    iv);
  i = ret->size[0];
  ret->size[0] = iv[0];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

void c_standardTF_custlay_paraContra(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_16 *problemDef_cells, const struct2_T *controls,
  emxArray_real_T *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts,
  emxArray_real_T *sfs, emxArray_real_T *nbas, emxArray_real_T *nbss,
  emxArray_real_T *resols, emxArray_real_T *chis, emxArray_cell_wrap_9
  *reflectivity, emxArray_cell_wrap_9 *Simulation, emxArray_cell_wrap_14
  *shifted_data, emxArray_cell_wrap_10 *layerSlds, emxArray_cell_wrap_14
  *sldProfiles, emxArray_cell_wrap_25 *allLayers, emxArray_real_T *allRoughs)
{
  static const int32_T iv[2] = { 1, 22 };

  static const char_T u[22] = { 'l', 'o', 'o', 'p', 'M', 'a', 't', 'l', 'a', 'b',
    'C', 'u', 's', 't', 'o', 'm', 'L', 'a', 'y', 'e', 'r', 's' };

  static const char_T b_cv[6] = { 'm', 'a', 't', 'l', 'a', 'b' };

  static const char_T b_cv1[3] = { 'c', 'p', 'p' };

  jmp_buf b_emlrtJBEnviron;
  jmp_buf * volatile emlrtJBStack;
  cell_wrap_6 b_u[3];
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_cell_wrap_14 *b_allLayers;
  emxArray_cell_wrap_25 *r;
  emxArray_cell_wrap_26 *b_tempAllLayers;
  emxArray_char_T *c_u;
  emxArray_real_T c_allLayers;
  emxArray_real_T *Simul;
  emxArray_real_T *reflect;
  emxArray_real_T *resamLayers;
  emxArray_real_T *sldProfile;
  emxArray_real_T *thisData;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *tempAllLayers;
  const mxArray *tempAllRoughs;
  const mxArray *y;
  real_T calcSld;
  real_T thisBackground;
  real_T thisChiSquared;
  real_T thisNba;
  real_T thisNbs;
  real_T thisQshift;
  real_T thisResol;
  real_T thisSf;
  real_T thisSsubs;
  int32_T iv1[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_i;
  int32_T d_allLayers;
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T kstr;
  int32_T loop_ub;
  int32_T nParams;
  boolean_T b_bool;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Multi threaded version of the custom layers over reflectivity contrasts */
  /*  for standardTF reflectivity calculation.  */
  /*  The function extracts the relevant parameters from the input */
  /*  arrays, allocates these on a pre-contrast basis, then calls the 'core'  */
  /*  calculation (the core layers standardTf calc is shared between multiple */
  /*  calculation types). */
  /*  This differs from the other two paralellisations in that the custom model */
  /*  files are processed in a paralell loop (using the Matlab Paralell */
  /*  Computing Toolbox) outside the main loop, before the main loop is then processed */
  /*  in the compiled version using OpenMP. */
  /*  Extract individual cell arrays */
  /*  Splits up the master input list of all arrays into separate arrays */
  /*  The min input array 'problemDef_cells' is a master array where */
  /*  all the cell arrays are grouped together. There are */
  /*  repeatLayers      - controls repeating of the layers stack */
  /*  allData           - Array of all the data arrays */
  /*  dataLimits        - Min max limits in q for the data arrays */
  /*  simLimits         - Limits in Q for the reflkectivity simulations */
  /*  Layers details    - Master array of all available layers */
  /*  contrastLayers    - Which specific combination of arrays are needed for */
  /*                      each contrast. */
  /*  Custom files      - Filenames and path for any custom files used */
  /*  Extract individual parameters from problemDef struct */
  /* Extract individual parameters from problemDef */
  nParams = problemDef->params->size[1];
  calcSld = controls->calcSld;

  /*  Pre-Allocation of output arrays... */
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &uc_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(problemDef->numberOfContrasts);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &tc_emlrtDCI, sp);
  }

  i1 = backgs->size[0];
  backgs->size[0] = (int32_T)problemDef->numberOfContrasts;
  emxEnsureCapacity_real_T(sp, backgs, i1, &ip_emlrtRTEI);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &sc_emlrtDCI, sp);
  }

  i1 = allRoughs->size[0];
  loop_ub = (int32_T)problemDef->numberOfContrasts;
  allRoughs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, allRoughs, i1, &jp_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &vc_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    allRoughs->data[i1] = 0.0;
  }

  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &pc_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &vc_emlrtRTEI, sp);
  i1 = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i1, &kp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &er_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &lp_emlrtRTEI);
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &er_emlrtBCI, sp);
    }

    i1 = reflectivity->data[b_i].f1->size[0] * reflectivity->data[b_i].f1->size
      [1];
    reflectivity->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, reflectivity->data[b_i].f1, i1, &lp_emlrtRTEI);
    i1 = reflectivity->size[0];
    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &er_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &er_emlrtBCI, sp);
    }

    if (b_i > reflectivity->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, reflectivity->size[0] - 1,
        &ns_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ns_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ns_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ns_emlrtBCI, sp);
    }

    reflectivity->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &wc_emlrtRTEI, sp);
  i1 = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i1, &kp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &fr_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[0] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &mp_emlrtRTEI);
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &fr_emlrtBCI, sp);
    }

    i1 = Simulation->data[b_i].f1->size[0] * Simulation->data[b_i].f1->size[1];
    Simulation->data[b_i].f1->size[1] = 2;
    emxEnsureCapacity_real_T(sp, Simulation->data[b_i].f1, i1, &mp_emlrtRTEI);
    i1 = Simulation->size[0];
    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &fr_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &fr_emlrtBCI, sp);
    }

    if (b_i > Simulation->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, Simulation->size[0] - 1,
        &os_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &os_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[1] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &os_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &os_emlrtBCI, sp);
    }

    Simulation->data[b_i].f1->data[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &xc_emlrtRTEI, sp);
  i1 = allLayers->size[0];
  allLayers->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_25(sp, allLayers, i1, &kp_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &gr_emlrtBCI,
        sp);
    }

    allLayers->data[b_i].f1.size[0] = 2;
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &gr_emlrtBCI,
        sp);
    }

    allLayers->data[b_i].f1.size[1] = 1;
    i1 = allLayers->size[0];
    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &gr_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &gr_emlrtBCI,
        sp);
    }

    if (b_i > allLayers->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, allLayers->size[0] - 1, &ps_emlrtBCI,
        sp);
    }

    allLayers->data[b_i].f1.data[0] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &ps_emlrtBCI, sp);
    }

    allLayers->data[b_i].f1.data[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*    --- End Memory Allocation --- */
  /*  Depending on custom layer language we change the functions used */
  if (0 > problemDef_cells->f14->size[1] - 1) {
    emlrtDynamicBoundsCheckR2012b(0, 0, problemDef_cells->f14->size[1] - 1,
      &wq_emlrtBCI, sp);
  }

  /*  so if there are multiple language models we should have a variable that seeks what language model is being used */
  b_bool = false;
  if (problemDef_cells->f14->data[0].f1[1].f1->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (problemDef_cells->f14->data[0].f1[1].f1->data[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (problemDef_cells->f14->data[0].f1[1].f1->size[1] == 3) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 3) {
          if (problemDef_cells->f14->data[0].f1[1].f1->data[kstr] != b_cv1[kstr])
          {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      kstr = 1;
    } else {
      kstr = -1;
    }
  }

  emxInit_cell_wrap_14(sp, &b_allLayers, 1, &yp_emlrtRTEI, true);
  switch (kstr) {
   case 0:
    /*  Call the Matlab parallel loop to process the custom models..... */
    st.site = &oh_emlrtRSI;
    tempAllLayers = NULL;
    tempAllRoughs = NULL;

    /*  Wrapper function for calling 'loopMatlabCustomLayers'. This wrapper is */
    /*  necessary to deal with typedef problems for the coder if feval is used */
    /*  directly from the main function */
    if (loop_ub != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &rc_emlrtDCI, &st);
    }

    emxInit_cell_wrap_26(&st, &b_tempAllLayers, 1, &bq_emlrtRTEI, true);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &ad_emlrtRTEI, &st);
    i1 = b_allLayers->size[0];
    b_allLayers->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, b_allLayers, i1, &pp_emlrtRTEI);
    i1 = b_tempAllLayers->size[0];
    b_tempAllLayers->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_26(&st, b_tempAllLayers, i1, &pp_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (b_i > b_allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
          &hr_emlrtBCI, &st);
      }

      i1 = b_allLayers->data[b_i].f1->size[0] * b_allLayers->data[b_i].f1->size
        [1];
      b_allLayers->data[b_i].f1->size[0] = 1;
      emxEnsureCapacity_real_T(&st, b_allLayers->data[b_i].f1, i1, &qp_emlrtRTEI);
      if (b_i > b_allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
          &hr_emlrtBCI, &st);
      }

      i1 = b_allLayers->data[b_i].f1->size[0] * b_allLayers->data[b_i].f1->size
        [1];
      b_allLayers->data[b_i].f1->size[1] = 2;
      emxEnsureCapacity_real_T(&st, b_allLayers->data[b_i].f1, i1, &qp_emlrtRTEI);
      i1 = b_allLayers->size[0];
      if (b_i > b_allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
          &hr_emlrtBCI, &st);
      }

      if (b_i > b_allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
          &hr_emlrtBCI, &st);
      }

      if (b_i > b_allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
          &qs_emlrtBCI, &st);
      }

      b_allLayers->data[b_i].f1->data[0] = 1.0;
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &qs_emlrtBCI, &st);
      }

      b_allLayers->data[b_i].f1->data[1] = 1.0;

      /*  Type def as double (size not important) */
      if (b_i > b_tempAllLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
          &ir_emlrtBCI, &st);
      }

      i1 = b_tempAllLayers->data[b_i].f1->size[0] * b_tempAllLayers->data[b_i].
        f1->size[1];
      b_tempAllLayers->data[b_i].f1->size[0] = 1;
      emxEnsureCapacity_real_T(&st, b_tempAllLayers->data[b_i].f1, i1,
        &sp_emlrtRTEI);
      if (b_i > b_tempAllLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
          &ir_emlrtBCI, &st);
      }

      i1 = b_tempAllLayers->data[b_i].f1->size[0] * b_tempAllLayers->data[b_i].
        f1->size[1];
      b_tempAllLayers->data[b_i].f1->size[1] = 5;
      emxEnsureCapacity_real_T(&st, b_tempAllLayers->data[b_i].f1, i1,
        &sp_emlrtRTEI);
      i1 = b_tempAllLayers->size[0];
      if (b_i > b_tempAllLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
          &ir_emlrtBCI, &st);
      }

      if (b_i > b_tempAllLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
          &ir_emlrtBCI, &st);
      }

      for (i2 = 0; i2 < 5; i2++) {
        if (b_i > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &pr_emlrtBCI, &st);
        }

        b_tempAllLayers->data[b_i].f1->data[i2] = 0.0;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /*  Call the Matlab parallel loop for the custom models..... */
    /*  We do this using feval, which automatically makes this function call */
    /*  only extrinsic... the loop is then handled in the matlab file (using  */
    /*  paralell computing toolbox) */
    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 22, m, &u[0]);
    emlrtAssign(&y, m);
    b_y = NULL;
    m = emlrtCreateDoubleScalar(problemDef->numberOfContrasts);
    emlrtAssign(&b_y, m);
    c_y = NULL;
    emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])
      problemDef_cells->f14->size));
    i1 = 0;
    emxInitMatrix_cell_wrap_6(&st, b_u, &yp_emlrtRTEI, true);
    emxInit_char_T(&st, &c_u, 2, &yp_emlrtRTEI, true);
    while (i1 < problemDef_cells->f14->size[1]) {
      emxCopyStruct_cell_wrap_6(&st, &b_u[0], &problemDef_cells->f14->data[i1].
        f1[0], &rp_emlrtRTEI);
      emxCopyStruct_cell_wrap_6(&st, &b_u[1], &problemDef_cells->f14->data[i1].
        f1[1], &rp_emlrtRTEI);
      emxCopyStruct_cell_wrap_6(&st, &b_u[2], &problemDef_cells->f14->data[i1].
        f1[2], &rp_emlrtRTEI);
      d_y = NULL;
      iv1[0] = 1;
      iv1[1] = 3;
      emlrtAssign(&d_y, emlrtCreateCellArrayR2014a(2, iv1));
      for (i2 = 0; i2 < 3; i2++) {
        b_i = c_u->size[0] * c_u->size[1];
        c_u->size[0] = 1;
        c_u->size[1] = b_u[i2].f1->size[1];
        emxEnsureCapacity_char_T(&st, c_u, b_i, &rp_emlrtRTEI);
        kstr = b_u[i2].f1->size[0] * b_u[i2].f1->size[1];
        for (b_i = 0; b_i < kstr; b_i++) {
          c_u->data[b_i] = b_u[i2].f1->data[b_i];
        }

        e_y = NULL;
        iv1[0] = c_u->size[0];
        iv1[1] = c_u->size[1];
        m = emlrtCreateCharArray(2, &iv1[0]);
        emlrtInitCharArrayR2013a(&st, c_u->size[1], m, &c_u->data[0]);
        emlrtAssign(&e_y, m);
        emlrtSetCell(d_y, i2, e_y);
      }

      emlrtSetCell(c_y, i1, d_y);
      i1++;
    }

    emxFree_char_T(&c_u);
    emxFreeMatrix_cell_wrap_6(b_u);
    b_st.site = &yi_emlrtRSI;
    b_feval(&b_st, y, emlrt_marshallOut(problemDef->contrastBacks),
            emlrt_marshallOut(problemDef->contrastShifts), emlrt_marshallOut
            (problemDef->contrastScales), emlrt_marshallOut
            (problemDef->contrastNbas), emlrt_marshallOut
            (problemDef->contrastNbss), emlrt_marshallOut
            (problemDef->contrastRes), emlrt_marshallOut(problemDef->backs),
            emlrt_marshallOut(problemDef->shifts), emlrt_marshallOut
            (problemDef->sf), emlrt_marshallOut(problemDef->nba),
            emlrt_marshallOut(problemDef->nbs), emlrt_marshallOut
            (problemDef->res), emlrt_marshallOut(problemDef->contrastCustomFiles),
            b_y, c_y, emlrt_marshallOut(problemDef->params), &c_emlrtMCI,
            &tempAllLayers, &tempAllRoughs);
    b_st.site = &yi_emlrtRSI;
    g_emlrt_marshallIn(&b_st, emlrtAlias(tempAllLayers), "tempAllLayers",
                       b_tempAllLayers);

    /*  All the following is intended to be casting from mxArray's to doubles. */
    /*  I'm not sure if all of this is necessary, but it compiles... */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &bd_emlrtRTEI, &st);
    i1 = b_allLayers->size[0];
    b_allLayers->size[0] = loop_ub;
    emxEnsureCapacity_cell_wrap_14(&st, b_allLayers, i1, &pp_emlrtRTEI);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      if (b_i > b_tempAllLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_tempAllLayers->size[0] - 1,
          &dr_emlrtBCI, &st);
      }

      kstr = b_tempAllLayers->data[b_i].f1->size[0] * b_tempAllLayers->data[b_i]
        .f1->size[1];
      if (b_i > b_allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
          &jr_emlrtBCI, &st);
      }

      i1 = b_allLayers->data[b_i].f1->size[0] * b_allLayers->data[b_i].f1->size
        [1];
      b_allLayers->data[b_i].f1->size[0] = b_tempAllLayers->data[b_i].f1->size[0];
      emxEnsureCapacity_real_T(&st, b_allLayers->data[b_i].f1, i1, &tp_emlrtRTEI);
      if (b_i > b_allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
          &jr_emlrtBCI, &st);
      }

      i1 = b_allLayers->data[b_i].f1->size[0] * b_allLayers->data[b_i].f1->size
        [1];
      b_allLayers->data[b_i].f1->size[1] = b_tempAllLayers->data[b_i].f1->size[1];
      emxEnsureCapacity_real_T(&st, b_allLayers->data[b_i].f1, i1, &tp_emlrtRTEI);
      i1 = b_allLayers->size[0];
      if (b_i > b_allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
          &jr_emlrtBCI, &st);
      }

      if (b_i > b_allLayers->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_allLayers->size[0] - 1,
          &jr_emlrtBCI, &st);
      }

      for (i2 = 0; i2 < kstr; i2++) {
        if (b_i > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &qr_emlrtBCI, &st);
        }

        b_allLayers->data[b_i].f1->data[i2] = b_tempAllLayers->data[b_i]
          .f1->data[i2];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emxFree_cell_wrap_26(&b_tempAllLayers);

    /* allLayers = tempAllLayers; */
    b_st.site = &dj_emlrtRSI;
    j_emlrt_marshallIn(&b_st, emlrtAlias(tempAllRoughs), "tempAllRoughs",
                       allRoughs);
    emlrtDestroyArray(&tempAllLayers);
    emlrtDestroyArray(&tempAllRoughs);
    i1 = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_25(sp, allLayers, i1, &op_emlrtRTEI);
    i1 = b_allLayers->size[0];
    for (i2 = 0; i2 < i1; i2++) {
      allLayers->data[i2].f1.size[0] = b_allLayers->data[i2].f1->size[0];
      allLayers->data[i2].f1.size[1] = b_allLayers->data[i2].f1->size[1];
      kstr = b_allLayers->data[i2].f1->size[0] * b_allLayers->data[i2].f1->size
        [1];
      for (b_i = 0; b_i < kstr; b_i++) {
        allLayers->data[i2].f1.data[b_i] = b_allLayers->data[i2].f1->data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*   */
    break;

   case 1:
    emxInit_cell_wrap_25(sp, &r, 1, &yp_emlrtRTEI, true);
    st.site = &ph_emlrtRSI;
    loopCppCustlayWrapper(&st, problemDef->nba, problemDef->nbs,
                          problemDef->numberOfContrasts, problemDef_cells->f14,
                          problemDef->params, r, allRoughs);
    i1 = b_allLayers->size[0];
    b_allLayers->size[0] = r->size[0];
    emxEnsureCapacity_cell_wrap_14(sp, b_allLayers, i1, &bo_emlrtRTEI);
    i1 = r->size[0];
    for (i2 = 0; i2 < i1; i2++) {
      b_i = b_allLayers->data[i2].f1->size[0] * b_allLayers->data[i2].f1->size[1];
      b_allLayers->data[i2].f1->size[0] = r->data[i2].f1.size[0];
      b_allLayers->data[i2].f1->size[1] = r->data[i2].f1.size[1];
      emxEnsureCapacity_real_T(sp, b_allLayers->data[i2].f1, b_i, &bo_emlrtRTEI);
      kstr = r->data[i2].f1.size[0] * r->data[i2].f1.size[1];
      for (b_i = 0; b_i < kstr; b_i++) {
        b_allLayers->data[i2].f1->data[b_i] = r->data[i2].f1.data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    emxFree_cell_wrap_25(&r);
    i1 = allLayers->size[0];
    allLayers->size[0] = b_allLayers->size[0];
    emxEnsureCapacity_cell_wrap_25(sp, allLayers, i1, &op_emlrtRTEI);
    i1 = b_allLayers->size[0];
    for (i2 = 0; i2 < i1; i2++) {
      allLayers->data[i2].f1.size[0] = b_allLayers->data[i2].f1->size[0];
      allLayers->data[i2].f1.size[1] = b_allLayers->data[i2].f1->size[1];
      kstr = b_allLayers->data[i2].f1->size[0] * b_allLayers->data[i2].f1->size
        [1];
      for (b_i = 0; b_i < kstr; b_i++) {
        allLayers->data[i2].f1.data[b_i] = b_allLayers->data[i2].f1->data[b_i];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
    break;
  }

  emxFree_cell_wrap_14(&b_allLayers);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &qc_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, (int32_T)problemDef->numberOfContrasts, &yc_emlrtRTEI, sp);
  i = outSsubs->size[0];
  outSsubs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, outSsubs, i, &np_emlrtRTEI);
  i = sldProfiles->size[0];
  sldProfiles->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, sldProfiles, i, &kp_emlrtRTEI);
  i = reflectivity->size[0];
  reflectivity->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, reflectivity, i, &kp_emlrtRTEI);
  i = Simulation->size[0];
  Simulation->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_9(sp, Simulation, i, &kp_emlrtRTEI);
  i = shifted_data->size[0];
  shifted_data->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_14(sp, shifted_data, i, &kp_emlrtRTEI);
  i = layerSlds->size[0];
  layerSlds->size[0] = loop_ub;
  emxEnsureCapacity_cell_wrap_10(sp, layerSlds, i, &kp_emlrtRTEI);
  i = chis->size[0];
  chis->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, chis, i, &np_emlrtRTEI);
  i = qshifts->size[0];
  qshifts->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, qshifts, i, &np_emlrtRTEI);
  i = sfs->size[0];
  sfs->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, sfs, i, &np_emlrtRTEI);
  i = nbas->size[0];
  nbas->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, nbas, i, &np_emlrtRTEI);
  i = nbss->size[0];
  nbss->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, nbss, i, &np_emlrtRTEI);
  i = resols->size[0];
  resols->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, resols, i, &np_emlrtRTEI);
  kstr = loop_ub - 1;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(sldProfile,reflect,Simul,thisData,resamLayers,thisSsubs,thisChiSquared,thisResol,thisNbs,thisNba,thisSf,thisQshift,thisBackground,b_emlrtJBEnviron,d_st,c_i,i3,c_allLayers,b_loop_ub,d_allLayers) \
 firstprivate(c_st,emlrtHadParallelError)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      c_st.prev = sp;
      c_st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      c_st.site = NULL;
      emlrtSetJmpBuf(&c_st, &b_emlrtJBEnviron);
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
      emxInit_real_T(&c_st, &sldProfile, 2, &yp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &reflect, 2, &yp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &Simul, 2, &yp_emlrtRTEI, true);
      emxInit_real_T(&c_st, &thisData, 2, &aq_emlrtRTEI, true);
      emxInit_real_T(&c_st, &resamLayers, 2, &yp_emlrtRTEI, true);
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (c_i = 0; c_i <= kstr; c_i++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        /*  Multi cored over all contrasts */
        /*  Extract the relevant parameter values for this contrast */
        /*  from the input arrays. */
        /*  First need to decide which values of the backrounds, scalefactors */
        /*  data shifts and bulk contrasts are associated with this contrast */
        if ((int32_T)(c_i + 1U) > problemDef->contrastBacks->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
            problemDef->contrastBacks->size[1], &rr_emlrtBCI, &c_st);
        }

        if ((int32_T)(c_i + 1U) > problemDef->contrastShifts->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
            problemDef->contrastShifts->size[1], &sr_emlrtBCI, &c_st);
        }

        if ((int32_T)(c_i + 1U) > problemDef->contrastScales->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
            problemDef->contrastScales->size[1], &tr_emlrtBCI, &c_st);
        }

        if ((int32_T)(c_i + 1U) > problemDef->contrastNbas->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
            problemDef->contrastNbas->size[1], &ur_emlrtBCI, &c_st);
        }

        if ((int32_T)(c_i + 1U) > problemDef->contrastNbss->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
            problemDef->contrastNbss->size[1], &vr_emlrtBCI, &c_st);
        }

        if ((int32_T)(c_i + 1U) > problemDef->contrastRes->size[1]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(c_i + 1U), 1,
            problemDef->contrastRes->size[1], &wr_emlrtBCI, &c_st);
        }

        d_st.site = &qh_emlrtRSI;
        backSort(&d_st, problemDef->contrastBacks->data[c_i],
                 problemDef->contrastShifts->data[c_i],
                 problemDef->contrastScales->data[c_i], problemDef->
                 contrastNbas->data[c_i], problemDef->contrastNbss->data[c_i],
                 problemDef->contrastRes->data[c_i], problemDef->backs,
                 problemDef->shifts, problemDef->sf, problemDef->nba,
                 problemDef->nbs, problemDef->res, &thisBackground, &thisQshift,
                 &thisSf, &thisNba, &thisNbs, &thisResol);

        /*  Get the custom layers output for this contrast */
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
            &xq_emlrtBCI, &c_st);
        }

        /*  For the other parameters, we extract the correct ones from the input */
        /*  arrays */
        i3 = c_i + 1;
        if (i3 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, allRoughs->size[0], &sq_emlrtBCI,
            &c_st);
        }

        if (c_i > problemDef_cells->f1->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, problemDef_cells->f1->size[1] -
            1, &yq_emlrtBCI, &c_st);
        }

        if (i3 > problemDef->resample->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, problemDef->resample->size[1],
            &tq_emlrtBCI, &c_st);
        }

        if (c_i > problemDef_cells->f2->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, problemDef_cells->f2->size[1] -
            1, &ar_emlrtBCI, &c_st);
        }

        if (i3 > problemDef->dataPresent->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, problemDef->dataPresent->size[1],
            &uq_emlrtBCI, &c_st);
        }

        if (c_i > problemDef_cells->f3->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, problemDef_cells->f3->size[1] -
            1, &br_emlrtBCI, &c_st);
        }

        if (c_i > problemDef_cells->f4->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, problemDef_cells->f4->size[1] -
            1, &cr_emlrtBCI, &c_st);
        }

        if (i3 > problemDef->contrastBacksType->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, problemDef->
            contrastBacksType->size[1], &vq_emlrtBCI, &c_st);
        }

        /*  Now call the core standardTF_stanlay reflectivity calculation */
        /*  In this case we are single cored, so we do not parallelise over */
        /*  points */
        /*  Call the reflectivity calculation */
        if (c_i > layerSlds->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, layerSlds->size[0] - 1,
            &xr_emlrtBCI, &c_st);
        }

        c_allLayers.data = &allLayers->data[c_i].f1.data[0];
        c_allLayers.size = &allLayers->data[c_i].f1.size[0];
        c_allLayers.allocatedSize = 5000;
        c_allLayers.numDimensions = 2;
        c_allLayers.canFreeData = false;
        d_st.site = &rh_emlrtRSI;
        b_standardTF_layers_core(&d_st, &c_allLayers, allRoughs->data[c_i],
          problemDef->geometry, thisNba, thisNbs, problemDef->resample->data[c_i],
          calcSld, thisSf, thisQshift, problemDef->dataPresent->data[c_i],
          problemDef_cells->f2->data[c_i].f1, problemDef_cells->f3->data[c_i].f1,
          (real_T *)problemDef_cells->f4->data[c_i].f1->data,
          problemDef_cells->f4->data[c_i].f1->size, problemDef_cells->f1->
          data[c_i].f1, thisBackground, thisResol, problemDef->
          contrastBacksType->data[c_i], nParams, controls->resamPars, sldProfile,
          reflect, Simul, thisData, layerSlds->data[c_i].f1, resamLayers,
          &thisChiSquared, &thisSsubs);

        /*  Store returned values for this contrast in the output arrays. */
        /*  As well as the calculated profiles, we also store a record of  */
        /*  the other values (background, scalefactors etc) for each contrast */
        /*  for future use. */
        if (c_i + 1 > outSsubs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, outSsubs->size[0],
            &yr_emlrtBCI, &c_st);
        }

        outSsubs->data[c_i] = thisSsubs;
        b_loop_ub = sldProfile->size[0] * sldProfile->size[1];
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
            &kr_emlrtBCI, &c_st);
        }

        i3 = sldProfiles->data[c_i].f1->size[0] * sldProfiles->data[c_i]
          .f1->size[1];
        sldProfiles->data[c_i].f1->size[0] = sldProfile->size[0];
        emxEnsureCapacity_real_T(&c_st, sldProfiles->data[c_i].f1, i3,
          &up_emlrtRTEI);
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
            &kr_emlrtBCI, &c_st);
        }

        i3 = sldProfiles->data[c_i].f1->size[0] * sldProfiles->data[c_i]
          .f1->size[1];
        sldProfiles->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, sldProfiles->data[c_i].f1, i3,
          &up_emlrtRTEI);
        i3 = sldProfiles->size[0];
        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
            &kr_emlrtBCI, &c_st);
        }

        if (c_i > sldProfiles->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, sldProfiles->size[0] - 1,
            &kr_emlrtBCI, &c_st);
        }

        for (d_allLayers = 0; d_allLayers < b_loop_ub; d_allLayers++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &as_emlrtBCI, &c_st);
          }

          sldProfiles->data[c_i].f1->data[d_allLayers] = sldProfile->
            data[d_allLayers];
        }

        b_loop_ub = reflect->size[0] * reflect->size[1];
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
            &lr_emlrtBCI, &c_st);
        }

        i3 = reflectivity->data[c_i].f1->size[0] * reflectivity->data[c_i]
          .f1->size[1];
        reflectivity->data[c_i].f1->size[0] = reflect->size[0];
        emxEnsureCapacity_real_T(&c_st, reflectivity->data[c_i].f1, i3,
          &vp_emlrtRTEI);
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
            &lr_emlrtBCI, &c_st);
        }

        i3 = reflectivity->data[c_i].f1->size[0] * reflectivity->data[c_i]
          .f1->size[1];
        reflectivity->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, reflectivity->data[c_i].f1, i3,
          &vp_emlrtRTEI);
        i3 = reflectivity->size[0];
        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
            &lr_emlrtBCI, &c_st);
        }

        if (c_i > reflectivity->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, reflectivity->size[0] - 1,
            &lr_emlrtBCI, &c_st);
        }

        for (d_allLayers = 0; d_allLayers < b_loop_ub; d_allLayers++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &bs_emlrtBCI, &c_st);
          }

          reflectivity->data[c_i].f1->data[d_allLayers] = reflect->
            data[d_allLayers];
        }

        b_loop_ub = Simul->size[0] * Simul->size[1];
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
            &mr_emlrtBCI, &c_st);
        }

        i3 = Simulation->data[c_i].f1->size[0] * Simulation->data[c_i].f1->size
          [1];
        Simulation->data[c_i].f1->size[0] = Simul->size[0];
        emxEnsureCapacity_real_T(&c_st, Simulation->data[c_i].f1, i3,
          &wp_emlrtRTEI);
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
            &mr_emlrtBCI, &c_st);
        }

        i3 = Simulation->data[c_i].f1->size[0] * Simulation->data[c_i].f1->size
          [1];
        Simulation->data[c_i].f1->size[1] = 2;
        emxEnsureCapacity_real_T(&c_st, Simulation->data[c_i].f1, i3,
          &wp_emlrtRTEI);
        i3 = Simulation->size[0];
        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
            &mr_emlrtBCI, &c_st);
        }

        if (c_i > Simulation->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, Simulation->size[0] - 1,
            &mr_emlrtBCI, &c_st);
        }

        for (d_allLayers = 0; d_allLayers < b_loop_ub; d_allLayers++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &cs_emlrtBCI, &c_st);
          }

          Simulation->data[c_i].f1->data[d_allLayers] = Simul->data[d_allLayers];
        }

        b_loop_ub = thisData->size[0] * thisData->size[1];
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
            &nr_emlrtBCI, &c_st);
        }

        i3 = shifted_data->data[c_i].f1->size[0] * shifted_data->data[c_i]
          .f1->size[1];
        shifted_data->data[c_i].f1->size[0] = thisData->size[0];
        emxEnsureCapacity_real_T(&c_st, shifted_data->data[c_i].f1, i3,
          &xp_emlrtRTEI);
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
            &nr_emlrtBCI, &c_st);
        }

        i3 = shifted_data->data[c_i].f1->size[0] * shifted_data->data[c_i]
          .f1->size[1];
        shifted_data->data[c_i].f1->size[1] = thisData->size[1];
        emxEnsureCapacity_real_T(&c_st, shifted_data->data[c_i].f1, i3,
          &xp_emlrtRTEI);
        i3 = shifted_data->size[0];
        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
            &nr_emlrtBCI, &c_st);
        }

        if (c_i > shifted_data->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, shifted_data->size[0] - 1,
            &nr_emlrtBCI, &c_st);
        }

        for (d_allLayers = 0; d_allLayers < b_loop_ub; d_allLayers++) {
          if (c_i > i3 - 1) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, i3 - 1, &ds_emlrtBCI, &c_st);
          }

          shifted_data->data[c_i].f1->data[d_allLayers] = thisData->
            data[d_allLayers];
        }

        if (1000 < resamLayers->size[0]) {
          emlrtDimSizeGeqCheckR2012b(1000, resamLayers->size[0], &fb_emlrtECI,
            &c_st);
        }

        b_loop_ub = resamLayers->size[0] * resamLayers->size[1];
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
            &or_emlrtBCI, &c_st);
        }

        allLayers->data[c_i].f1.size[0] = resamLayers->size[0];
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
            &or_emlrtBCI, &c_st);
        }

        allLayers->data[c_i].f1.size[1] = 3;
        d_allLayers = allLayers->size[0] - 1;
        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
            &or_emlrtBCI, &c_st);
        }

        if (c_i > allLayers->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(c_i, 0, allLayers->size[0] - 1,
            &or_emlrtBCI, &c_st);
        }

        for (i3 = 0; i3 < b_loop_ub; i3++) {
          if (c_i > d_allLayers) {
            emlrtDynamicBoundsCheckR2012b(c_i, 0, d_allLayers, &es_emlrtBCI,
              &c_st);
          }

          allLayers->data[c_i].f1.data[i3] = resamLayers->data[i3];
        }

        if (c_i + 1 > chis->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, chis->size[0], &fs_emlrtBCI,
            &c_st);
        }

        chis->data[c_i] = thisChiSquared;
        if (c_i + 1 > backgs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, backgs->size[0],
            &gs_emlrtBCI, &c_st);
        }

        backgs->data[c_i] = thisBackground;
        if (c_i + 1 > qshifts->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, qshifts->size[0],
            &hs_emlrtBCI, &c_st);
        }

        qshifts->data[c_i] = thisQshift;
        if (c_i + 1 > sfs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, sfs->size[0], &is_emlrtBCI,
            &c_st);
        }

        sfs->data[c_i] = thisSf;
        if (c_i + 1 > nbas->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, nbas->size[0], &js_emlrtBCI,
            &c_st);
        }

        nbas->data[c_i] = thisNba;
        if (c_i + 1 > nbss->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, nbss->size[0], &ks_emlrtBCI,
            &c_st);
        }

        nbss->data[c_i] = thisNbs;
        if (c_i + 1 > resols->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, resols->size[0],
            &ls_emlrtBCI, &c_st);
        }

        resols->data[c_i] = thisResol;
        if (c_i + 1 > allRoughs->size[0]) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, allRoughs->size[0],
            &ms_emlrtBCI, &c_st);
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&c_st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }

    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&c_st, 5);
      emxFree_real_T(&resamLayers);
      emxFree_real_T(&thisData);
      emxFree_real_T(&Simul);
      emxFree_real_T(&reflect);
      emxFree_real_T(&sldProfile);
    }
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (standardTF_custlay_paraContrasts.c) */
