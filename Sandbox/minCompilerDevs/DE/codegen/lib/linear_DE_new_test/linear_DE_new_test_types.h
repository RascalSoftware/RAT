/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * linear_DE_new_test_types.h
 *
 * Code generation for function 'linear_DE_new_test'
 *
 */

#ifndef LINEAR_DE_NEW_TEST_TYPES_H
#define LINEAR_DE_NEW_TEST_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  double I_lentol;
  double FVr_x;
  double FVr_lim_up;
  double FVr_lim_lo;
  double I_NP;
  double F_weight;
  double F_CR;
  double I_D;
  double FVr_minbound[2];
  double FVr_maxbound[2];
  double I_bnd_constr[4];
  double I_itermax;
  double F_VTR;
  double I_strategy;
  double I_refresh;
  double I_plotting;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  double data[15];
  double fitpars[2];
  double fitconstr[4];
  struct1_T S_struct;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  double I_nc;
  double FVr_ca;
  double I_no;
  double FVr_oa;
} struct_T;

#endif                                 /*typedef_struct_T*/
#endif

/* End of code generation (linear_DE_new_test_types.h) */
