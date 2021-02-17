/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 * File: _coder_mycode_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 08-Jan-2021 10:39:07
 */

#ifndef _CODER_MYCODE_API_H
#define _CODER_MYCODE_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern int32_T mycode(void);
extern void mycode_api(int32_T nlhs, const mxArray *plhs[1]);
extern void mycode_atexit(void);
extern void mycode_initialize(void);
extern void mycode_terminate(void);
extern void mycode_xil_shutdown(void);
extern void mycode_xil_terminate(void);

#endif

/*
 * File trailer for _coder_mycode_api.h
 *
 * [EOF]
 */
