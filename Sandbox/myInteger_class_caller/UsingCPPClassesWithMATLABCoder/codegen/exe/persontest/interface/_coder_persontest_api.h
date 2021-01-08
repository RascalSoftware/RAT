/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 * File: _coder_persontest_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 18-Dec-2020 16:40:07
 */

#ifndef _CODER_PERSONTEST_API_H
#define _CODER_PERSONTEST_API_H

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
extern void persontest(char_T name_data[], int32_T name_size[2], int16_T age,
  char_T pname_data[], int32_T pname_size[2], int32_T *page);
extern void persontest_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[2]);
extern void persontest_atexit(void);
extern void persontest_initialize(void);
extern void persontest_terminate(void);
extern void persontest_xil_shutdown(void);
extern void persontest_xil_terminate(void);

#endif

/*
 * File trailer for _coder_persontest_api.h
 *
 * [EOF]
 */
