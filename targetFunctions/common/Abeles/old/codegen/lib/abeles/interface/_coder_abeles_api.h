/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_abeles_api.h
 *
 * Code generation for function '_coder_abeles_api'
 *
 */

#ifndef _CODER_ABELES_API_H
#define _CODER_ABELES_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_abeles_api.h"

/* Type Definitions */
#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

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
extern void abeles(emxArray_real_T *x, emxArray_creal_T *sld, creal_T nbair,
                   creal_T nbsub, real_T nrepeats, real_T ssub, real_T layers,
                   real_T points, emxArray_real_T *out);
extern void abeles_api(const mxArray * const prhs[8], int32_T nlhs, const
  mxArray *plhs[1]);
extern void abeles_atexit(void);
extern void abeles_initialize(void);
extern void abeles_terminate(void);
extern void abeles_xil_shutdown(void);
extern void abeles_xil_terminate(void);

#endif

/* End of code generation (_coder_abeles_api.h) */
