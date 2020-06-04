/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_backSort_api.h
 *
 * Code generation for function '_coder_backSort_api'
 *
 */

#ifndef _CODER_BACKSORT_API_H
#define _CODER_BACKSORT_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_backSort_api.h"

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
extern void backSort(real_T cBacks, real_T cShifts, real_T cScales, real_T cNbas,
                     real_T cNbss, real_T cRes, emxArray_real_T *backs,
                     emxArray_real_T *shifts, emxArray_real_T *sf,
                     emxArray_real_T *nba, emxArray_real_T *nbs, emxArray_real_T
                     *res, real_T *backg, real_T *qshift, real_T *resol);
extern void backSort_api(const mxArray *prhs[12], const mxArray *plhs[6]);
extern void backSort_atexit(void);
extern void backSort_initialize(void);
extern void backSort_terminate(void);
extern void backSort_xil_terminate(void);

#endif

/* End of code generation (_coder_backSort_api.h) */
