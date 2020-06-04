/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_linear_DE_new_test_api.h
 *
 * Code generation for function '_coder_linear_DE_new_test_api'
 *
 */

#ifndef _CODER_LINEAR_DE_NEW_TEST_API_H
#define _CODER_LINEAR_DE_NEW_TEST_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_linear_DE_new_test_api.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T I_lentol;
  real_T FVr_x;
  real_T FVr_lim_up;
  real_T FVr_lim_lo;
  real_T I_NP;
  real_T F_weight;
  real_T F_CR;
  real_T I_D;
  real_T FVr_minbound[2];
  real_T FVr_maxbound[2];
  real_T I_bnd_constr[4];
  real_T I_itermax;
  real_T F_VTR;
  real_T I_strategy;
  real_T I_refresh;
  real_T I_plotting;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T data[15];
  real_T fitpars[2];
  real_T fitconstr[4];
  struct1_T S_struct;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void linear_DE_new_test(struct0_T *problem);
extern void linear_DE_new_test_api(const mxArray *prhs[2], const mxArray *plhs[1]);
extern void linear_DE_new_test_atexit(void);
extern void linear_DE_new_test_initialize(void);
extern void linear_DE_new_test_terminate(void);
extern void linear_DE_new_test_xil_terminate(void);

#endif

/* End of code generation (_coder_linear_DE_new_test_api.h) */
