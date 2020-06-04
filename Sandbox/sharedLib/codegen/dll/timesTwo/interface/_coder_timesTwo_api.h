/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_timesTwo_api.h
 *
 * Code generation for function '_coder_timesTwo_api'
 *
 */

#ifndef _CODER_TIMESTWO_API_H
#define _CODER_TIMESTWO_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_timesTwo_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern real_T timesTwo(real_T in);
  extern void timesTwo_api(const mxArray * const prhs[1], int32_T nlhs, const
    mxArray *plhs[1]);
  extern void timesTwo_atexit(void);
  extern void timesTwo_initialize(void);
  extern void timesTwo_terminate(void);
  extern void timesTwo_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (_coder_timesTwo_api.h) */
