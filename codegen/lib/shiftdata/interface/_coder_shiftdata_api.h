/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_shiftdata_api.h
 *
 * Code generation for function '_coder_shiftdata_api'
 *
 */

#ifndef _CODER_SHIFTDATA_API_H
#define _CODER_SHIFTDATA_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_shiftdata_api.h"

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
extern void shiftdata(real_T scalefac, real_T horshift, real_T dataPresent,
                      emxArray_real_T *data, real_T dataLimits[2],
                      emxArray_real_T *shifted_data);
extern void shiftdata_api(const mxArray *prhs[5], const mxArray *plhs[1]);
extern void shiftdata_atexit(void);
extern void shiftdata_initialize(void);
extern void shiftdata_terminate(void);
extern void shiftdata_xil_terminate(void);

#endif

/* End of code generation (_coder_shiftdata_api.h) */
