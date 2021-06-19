//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  interpolateOnToZ_terminate.h
//
//  Code generation for function 'interpolateOnToZ_terminate'
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
CODEGEN_EXPORT_SYM void interpolateOnToZ_atexit();
CODEGEN_EXPORT_SYM void interpolateOnToZ_terminate();

// End of code generation (interpolateOnToZ_terminate.h)
