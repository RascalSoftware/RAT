/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_stanlay_single_data.c
 *
 * Code generation for function 'standardTF_stanlay_single_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_single.h"
#include "standardTF_stanlay_single_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131435U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "standardTF_stanlay_single",         /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo m_emlrtRSI = { 18,         /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

emlrtRSInfo n_emlrtRSI = { 20,         /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo o_emlrtRSI = { 100,        /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 9,         /* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 58,        /* lineNo */
  "sumprod",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

emlrtRSInfo db_emlrtRSI = { 70,        /* lineNo */
  "combine_vector_elements",           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"/* pathName */
};

emlrtRSInfo eb_emlrtRSI = { 20,        /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo gb_emlrtRSI = { 49,        /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 87,        /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 102,       /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo mb_emlrtRSI = { 45,        /* lineNo */
  "asymconvstep",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pathName */
};

emlrtRSInfo gc_emlrtRSI = { 98,        /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 275,       /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 283,       /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo pc_emlrtRSI = { 44,        /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo qc_emlrtRSI = { 234,       /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 253,       /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRTEInfo b_emlrtRTEI = { 253,      /* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo g_emlrtRTEI = { 36,       /* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo ac_emlrtRTEI = { 243,     /* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo dc_emlrtRTEI = { 281,     /* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

emlrtRTEInfo ec_emlrtRTEI = { 88,      /* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

emlrtECInfo e_emlrtECI = { 2,          /* nDims */
  45,                                  /* lineNo */
  12,                                  /* colNo */
  "asymconvstep",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pName */
};

emlrtRTEInfo kc_emlrtRTEI = { 381,     /* lineNo */
  15,                                  /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

/* End of code generation (standardTF_stanlay_single_data.c) */
