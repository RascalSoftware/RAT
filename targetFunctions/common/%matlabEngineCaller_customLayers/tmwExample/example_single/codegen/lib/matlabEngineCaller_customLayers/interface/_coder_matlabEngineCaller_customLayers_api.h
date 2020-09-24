/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_matlabEngineCaller_customLayers_api.h
 *
 * Code generation for function '_coder_matlabEngineCaller_customLayers_api'
 *
 */

#ifndef _CODER_MATLABENGINECALLER_CUSTOMLAYERS_API_H
#define _CODER_MATLABENGINECALLER_CUSTOMLAYERS_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_matlabEngineCaller_customLayers_api.h"

/* Type Definitions */
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_char_T*/

#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T

typedef struct emxArray_char_T emxArray_char_T;

#endif                                 /*typedef_emxArray_char_T*/

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
extern void matlabEngineCaller_customLayers(real_T params[8], real_T contrast,
  emxArray_char_T *funcName, emxArray_char_T *funcPath, real_T bulkIn, real_T
  bulkOut, emxArray_real_T *output, real_T sRough_data[], int32_T sRough_size[2]);
extern void matlabEngineCaller_customLayers_api(const mxArray *prhs[6], const
  mxArray *plhs[2]);
extern void matlabEngineCaller_customLayers_atexit(void);
extern void matlabEngineCaller_customLayers_initialize(void);
extern void matlabEngineCaller_customLayers_terminate(void);
extern void matlabEngineCaller_customLayers_xil_terminate(void);

#endif

/* End of code generation (_coder_matlabEngineCaller_customLayers_api.h) */
