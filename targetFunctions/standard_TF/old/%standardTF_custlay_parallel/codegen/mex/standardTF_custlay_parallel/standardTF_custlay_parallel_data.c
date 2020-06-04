/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_parallel_data.c
 *
 * Code generation for function 'standardTF_custlay_parallel_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "standardTF_custlay_parallel_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131435U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "standardTF_custlay_parallel",       /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo l_emlrtRSI = { 18,         /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

emlrtRSInfo m_emlrtRSI = { 20,         /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo n_emlrtRSI = { 100,        /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo ab_emlrtRSI = { 9,         /* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 58,        /* lineNo */
  "sumprod",                           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 70,        /* lineNo */
  "combine_vector_elements",           /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"/* pathName */
};

emlrtRSInfo db_emlrtRSI = { 20,        /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo fb_emlrtRSI = { 49,        /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo hb_emlrtRSI = { 87,        /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 102,       /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo lb_emlrtRSI = { 45,        /* lineNo */
  "asymconvstep",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pathName */
};

emlrtRSInfo fc_emlrtRSI = { 98,        /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo gc_emlrtRSI = { 275,       /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 283,       /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo oc_emlrtRSI = { 44,        /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo pc_emlrtRSI = { 234,       /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo qc_emlrtRSI = { 253,       /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRTEInfo r_emlrtRTEI = { 253,      /* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo w_emlrtRTEI = { 36,       /* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo ac_emlrtRTEI = { 281,     /* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

emlrtRTEInfo bc_emlrtRTEI = { 88,      /* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

emlrtECInfo emlrtECI = { 2,            /* nDims */
  45,                                  /* lineNo */
  12,                                  /* colNo */
  "asymconvstep",                      /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pName */
};

emlrtRTEInfo hc_emlrtRTEI = { 243,     /* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo ic_emlrtRTEI = { 381,     /* lineNo */
  15,                                  /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

/* End of code generation (standardTF_custlay_parallel_data.c) */
