/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 * File: _coder_callFoo_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 17-Dec-2020 16:45:44
 */

#ifndef _CODER_CALLFOO_API_H
#define _CODER_CALLFOO_API_H

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
extern real_T callFoo(void);
extern void callFoo_api(int32_T nlhs, const mxArray *plhs[1]);
extern void callFoo_atexit(void);
extern void callFoo_initialize(void);
extern void callFoo_terminate(void);
extern void callFoo_xil_shutdown(void);
extern void callFoo_xil_terminate(void);

#endif

/*
 * File trailer for _coder_callFoo_api.h
 *
 * [EOF]
 */
