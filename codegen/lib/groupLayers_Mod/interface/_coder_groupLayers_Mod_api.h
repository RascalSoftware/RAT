/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_groupLayers_Mod_api.h
 *
 * Code generation for function '_coder_groupLayers_Mod_api'
 *
 */

#ifndef _CODER_GROUPLAYERS_MOD_API_H
#define _CODER_GROUPLAYERS_MOD_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_groupLayers_Mod_api.h"

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
extern void groupLayers_Mod(emxArray_real_T *allLayers, real_T allRoughs,
  emxArray_char_T *geometry, real_T nbair, real_T nbsubs, emxArray_real_T
  *outLayers, real_T *outSsubs);
extern void groupLayers_Mod_api(const mxArray *prhs[5], const mxArray *plhs[2]);
extern void groupLayers_Mod_atexit(void);
extern void groupLayers_Mod_initialize(void);
extern void groupLayers_Mod_terminate(void);
extern void groupLayers_Mod_xil_terminate(void);

#endif

/* End of code generation (_coder_groupLayers_Mod_api.h) */
