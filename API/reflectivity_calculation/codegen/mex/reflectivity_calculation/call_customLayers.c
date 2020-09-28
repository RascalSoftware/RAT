/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * call_customLayers.c
 *
 * Code generation for function 'call_customLayers'
 *
 */

/* Include files */
#include "call_customLayers.h"
#include "matlabEngineCaller_customLayers.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo kh_emlrtRSI = { 3,  /* lineNo */
  "call_customLayers",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/call_customLayers.m"/* pathName */
};

static emlrtBCInfo sm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  17,                                  /* colNo */
  "params",                            /* aName */
  "call_customLayers",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/call_customLayers.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void call_customLayers(const emlrtStack *sp, const emxArray_real_T *params,
  real_T contrast, const emxArray_char_T *file, const emxArray_char_T *callPath,
  real_T bulkIn, real_T bulkOut, emxArray_real_T *output, real_T *sRough)
{
  real_T layers;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kh_emlrtRSI;
  matlabEngineCaller_customLayers(&st, params, contrast, file, callPath, bulkIn,
    bulkOut, output, &layers);
  if (1 > params->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &sm_emlrtBCI, sp);
  }

  *sRough = params->data[0];
}

/* End of code generation (call_customLayers.c) */
