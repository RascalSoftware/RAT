/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_multinestCaller_api.h
 *
 * Code generation for function '_coder_multinestCaller_api'
 *
 */

#ifndef _CODER_MULTINESTCALLER_API_H
#define _CODER_MULTINESTCALLER_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_multinestCaller_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void multinestCaller(void);
extern void multinestCaller_api(const mxArray *plhs[1]);
extern void multinestCaller_atexit(void);
extern void multinestCaller_initialize(void);
extern void multinestCaller_terminate(void);
extern void multinestCaller_xil_terminate(void);

#endif

/* End of code generation (_coder_multinestCaller_api.h) */
