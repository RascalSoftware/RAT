/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * rascal_deopt.h
 *
 * Code generation for function 'rascal_deopt'
 *
 */

#ifndef RASCAL_DEOPT_H
#define RASCAL_DEOPT_H

/* Include files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "linear_DE_new_test_types.h"

/* Function Declarations */
extern void rascal_deopt(const double problem_data[15], const double
  S_struct_FVr_minbound[2], const double S_struct_FVr_maxbound[2], double
  FVr_bestmem[2]);

#endif

/* End of code generation (rascal_deopt.h) */
