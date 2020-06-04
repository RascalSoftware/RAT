/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_resampleLayers_api.h
 *
 * Code generation for function '_coder_resampleLayers_api'
 *
 */

#ifndef _CODER_RESAMPLELAYERS_API_H
#define _CODER_RESAMPLELAYERS_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_resampleLayers_api.h"

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
extern void resampleLayers(emxArray_real_T *layerSLD, emxArray_real_T *newSLD);
extern void resampleLayers_api(const mxArray *prhs[1], const mxArray *plhs[1]);
extern void resampleLayers_atexit(void);
extern void resampleLayers_initialize(void);
extern void resampleLayers_terminate(void);
extern void resampleLayers_xil_terminate(void);

#endif

/* End of code generation (_coder_resampleLayers_api.h) */
