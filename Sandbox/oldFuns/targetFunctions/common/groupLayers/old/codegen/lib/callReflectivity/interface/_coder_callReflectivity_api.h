/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_callReflectivity_api.h
 *
 * Code generation for function '_coder_callReflectivity_api'
 *
 */

#ifndef _CODER_CALLREFLECTIVITY_API_H
#define _CODER_CALLREFLECTIVITY_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_callReflectivity_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void callReflectivity(real_T nbairs, real_T nbsubs, real_T simLimits[2],
  real_T repeatLayers[2], emxArray_real_T *this_data, emxArray_real_T *layers,
  real_T ssubs, real_T backgrounds, real_T res, emxArray_real_T *reflectivity,
  emxArray_real_T *Simulation);
extern void callReflectivity_api(const mxArray *prhs[9], const mxArray *plhs[2]);
extern void callReflectivity_atexit(void);
extern void callReflectivity_initialize(void);
extern void callReflectivity_terminate(void);
extern void callReflectivity_xil_terminate(void);

#endif

/* End of code generation (_coder_callReflectivity_api.h) */
