/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_customBilayer_api.h
 *
 * Code generation for function 'customBilayer'
 *
 */

#ifndef _CODER_CUSTOMBILAYER_API_H
#define _CODER_CUSTOMBILAYER_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void customBilayer(emxArray_real_T *params, real_T bulk_in, real_T bulk_out,
                   real_T contrast, real_T output[18], real_T *sub_rough);

void customBilayer_api(const mxArray *const prhs[4], int32_T nlhs,
                       const mxArray *plhs[2]);

void customBilayer_atexit(void);

void customBilayer_initialize(void);

void customBilayer_terminate(void);

void customBilayer_xil_shutdown(void);

void customBilayer_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_customBilayer_api.h) */
