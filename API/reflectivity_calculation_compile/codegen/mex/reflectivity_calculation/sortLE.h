//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sortLE.h
//
//  Code generation for function 'sortLE'
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
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
boolean_T sortLE(const coder::array<real_T, 2U> &v, const int32_T dir_data[],
                 int32_T idx1, int32_T idx2);

// End of code generation (sortLE.h)
