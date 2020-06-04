/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_standard_layers_mod_api.h
 *
 * Code generation for function '_coder_standard_layers_mod_api'
 *
 */

#ifndef _CODER_STANDARD_LAYERS_MOD_API_H
#define _CODER_STANDARD_LAYERS_MOD_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_standard_layers_mod_api.h"

/* Type Definitions */
#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct {
  real_T f1[5];
} cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

#ifndef struct_emxArray_cell_wrap_0
#define struct_emxArray_cell_wrap_0

struct emxArray_cell_wrap_0
{
  cell_wrap_0 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_cell_wrap_0*/

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0

typedef struct emxArray_cell_wrap_0 emxArray_cell_wrap_0;

#endif                                 /*typedef_emxArray_cell_wrap_0*/

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
extern void standard_layers_mod(emxArray_real_T *params, real_T contrastLayers[2],
  real_T numberOfLayers, emxArray_cell_wrap_0 *layersDetails, real_T
  layersOutput_data[], int32_T layersOutput_size[2], real_T *sRoughOutput);
extern void standard_layers_mod_api(const mxArray *prhs[4], const mxArray *plhs
  [2]);
extern void standard_layers_mod_atexit(void);
extern void standard_layers_mod_initialize(void);
extern void standard_layers_mod_terminate(void);
extern void standard_layers_mod_xil_terminate(void);

#endif

/* End of code generation (_coder_standard_layers_mod_api.h) */
