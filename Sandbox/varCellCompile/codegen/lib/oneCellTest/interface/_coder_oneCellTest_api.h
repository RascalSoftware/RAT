/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_oneCellTest_api.h
 *
 * Code generation for function '_coder_oneCellTest_api'
 *
 */

#ifndef _CODER_ONECELLTEST_API_H
#define _CODER_ONECELLTEST_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_oneCellTest_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T_10x3
#define struct_emxArray_real_T_10x3

struct emxArray_real_T_10x3
{
  real_T data[30];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_10x3*/

#ifndef typedef_emxArray_real_T_10x3
#define typedef_emxArray_real_T_10x3

typedef struct emxArray_real_T_10x3 emxArray_real_T_10x3;

#endif                                 /*typedef_emxArray_real_T_10x3*/

#ifndef struct_sug7NIB4YxuPRsLoDxIYVxG
#define struct_sug7NIB4YxuPRsLoDxIYVxG

struct sug7NIB4YxuPRsLoDxIYVxG
{
  emxArray_real_T_10x3 f1;
};

#endif                                 /*struct_sug7NIB4YxuPRsLoDxIYVxG*/

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct sug7NIB4YxuPRsLoDxIYVxG cell_wrap_0;

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

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void oneCellTest(real_T cell1Length, emxArray_cell_wrap_0 *outResult);
extern void oneCellTest_api(const mxArray * const prhs[1], const mxArray *plhs[1]);
extern void oneCellTest_atexit(void);
extern void oneCellTest_initialize(void);
extern void oneCellTest_terminate(void);
extern void oneCellTest_xil_terminate(void);

#endif

/* End of code generation (_coder_oneCellTest_api.h) */
