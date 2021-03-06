/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_matlabEngineCaller_customXY_api.h
 *
 * Code generation for function '_coder_matlabEngineCaller_customXY_api'
 *
 */

#ifndef _CODER_MATLABENGINECALLER_CUSTOMXY_API_H
#define _CODER_MATLABENGINECALLER_CUSTOMXY_API_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

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
extern void matlabEngineCaller_customXY(emxArray_real_T *params, real_T contrast,
  emxArray_char_T *funcName, emxArray_char_T *funcPath, real_T bulkIn, real_T
  bulkOut, emxArray_real_T *output, real_T *sRough);
extern void matlabEngineCaller_customXY_api(const mxArray * const prhs[6],
  int32_T nlhs, const mxArray *plhs[2]);
extern void matlabEngineCaller_customXY_atexit(void);
extern void matlabEngineCaller_customXY_initialize(void);
extern void matlabEngineCaller_customXY_terminate(void);
extern void matlabEngineCaller_customXY_xil_shutdown(void);
extern void matlabEngineCaller_customXY_xil_terminate(void);

#endif

/* End of code generation (_coder_matlabEngineCaller_customXY_api.h) */
