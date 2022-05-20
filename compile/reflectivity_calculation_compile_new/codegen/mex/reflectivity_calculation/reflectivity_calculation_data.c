/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_data.c
 *
 * Code generation for function 'reflectivity_calculation_data'
 *
 */

/* Include files */
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131595U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "reflectivity_calculation",          /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo j_emlrtRSI = { 21,         /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 58,         /* lineNo */
  "standardTF_layers_core",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 69,         /* lineNo */
  "standardTF_layers_core",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pathName */
};

emlrtRSInfo y_emlrtRSI = { 76,         /* lineNo */
  "standardTF_layers_core",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pathName */
};

emlrtRSInfo ab_emlrtRSI = { 84,        /* lineNo */
  "standardTF_layers_core",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 88,        /* lineNo */
  "standardTF_layers_core",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 91,        /* lineNo */
  "standardTF_layers_core",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pathName */
};

emlrtRSInfo db_emlrtRSI = { 94,        /* lineNo */
  "standardTF_layers_core",            /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pathName */
};

emlrtRSInfo nb_emlrtRSI = { 22,        /* lineNo */
  "cat",                               /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo ob_emlrtRSI = { 102,       /* lineNo */
  "cat_impl",                          /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo bc_emlrtRSI = { 20,        /* lineNo */
  "sum",                               /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 99,        /* lineNo */
  "sumprod",                           /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 133,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 194,       /* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 14,        /* lineNo */
  "max",                               /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

emlrtRSInfo ed_emlrtRSI = { 44,        /* lineNo */
  "minOrMax",                          /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo fd_emlrtRSI = { 79,        /* lineNo */
  "maximum",                           /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo xd_emlrtRSI = { 39,        /* lineNo */
  "find",                              /* fcnName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo xe_emlrtRSI = { 33,        /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

emlrtRTEInfo y_emlrtRTEI = { 15,       /* lineNo */
  9,                                   /* colNo */
  "assertSupportedString",             /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/assertSupportedString.m"/* pName */
};

emlrtDCInfo cb_emlrtDCI = { 3,         /* lineNo */
  8,                                   /* colNo */
  "applyBackgroundCorrection",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m",/* pName */
  1                                    /* checkKind */
};

emlrtBCInfo re_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  23,                                  /* colNo */
  "shifted_dat",                       /* aName */
  "applyBackgroundCorrection",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m",/* pName */
  0                                    /* checkKind */
};

emlrtECInfo emlrtECI = { -1,           /* nDims */
  10,                                  /* lineNo */
  9,                                   /* colNo */
  "applyBackgroundCorrection",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"/* pName */
};

emlrtRTEInfo hb_emlrtRTEI = { 283,     /* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

emlrtRTEInfo pb_emlrtRTEI = { 20,      /* lineNo */
  15,                                  /* colNo */
  "rdivide_helper",                    /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/rdivide_helper.m"/* pName */
};

emlrtRTEInfo sb_emlrtRTEI = { 14,      /* lineNo */
  9,                                   /* colNo */
  "asin",                              /* fName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/elfun/asin.m"/* pName */
};

emlrtRTEInfo nd_emlrtRTEI = { 13,      /* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "/opt/matlab2020b/toolbox/eml/eml/+coder/+internal/toLogicalCheck.m"/* pName */
};

emlrtRTEInfo kh_emlrtRTEI = { 71,      /* lineNo */
  5,                                   /* colNo */
  "standardTF_layers_core",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pName */
};

emlrtRTEInfo lh_emlrtRTEI = { 79,      /* lineNo */
  5,                                   /* colNo */
  "standardTF_layers_core",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pName */
};

emlrtRTEInfo mh_emlrtRTEI = { 77,      /* lineNo */
  5,                                   /* colNo */
  "standardTF_layers_core",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pName */
};

emlrtRTEInfo nh_emlrtRTEI = { 80,      /* lineNo */
  5,                                   /* colNo */
  "standardTF_layers_core",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pName */
};

emlrtRTEInfo ph_emlrtRTEI = { 6,       /* lineNo */
  9,                                   /* colNo */
  "applyBackgroundCorrection",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"/* pName */
};

emlrtRTEInfo qh_emlrtRTEI = { 10,      /* lineNo */
  28,                                  /* colNo */
  "applyBackgroundCorrection",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"/* pName */
};

emlrtRTEInfo rh_emlrtRTEI = { 7,       /* lineNo */
  9,                                   /* colNo */
  "applyBackgroundCorrection",         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"/* pName */
};

emlrtRTEInfo sh_emlrtRTEI = { 76,      /* lineNo */
  5,                                   /* colNo */
  "standardTF_layers_core",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"/* pName */
};

emlrtRTEInfo xj_emlrtRTEI = { 31,      /* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "/opt/matlab2020b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo bo_emlrtRTEI = { 82,      /* lineNo */
  6,                                   /* colNo */
  "standardTF_custlay_paraContrasts",  /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_paraContrasts.m"/* pName */
};

const char_T cv[9] = { 'c', 'o', 'n', 't', 'r', 'a', 's', 't', 's' };

const char_T cv1[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06',
  '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10',
  '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
  '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$', '%', '&',
  '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5',
  '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b', 'c', 'd', 'e',
  'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
  'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd',
  'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
  'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

/* End of code generation (reflectivity_calculation_data.c) */
