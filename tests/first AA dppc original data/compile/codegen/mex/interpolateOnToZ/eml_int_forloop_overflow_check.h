//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  eml_int_forloop_overflow_check.h
//
//  Code generation for function 'eml_int_forloop_overflow_check'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "interpolateOnToZ_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
void check_forloop_overflow_error(const emlrtStack *sp);

// End of code generation (eml_int_forloop_overflow_check.h)
