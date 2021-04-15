//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: reflectivity_calculation_data.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:21:20
//
#ifndef REFLECTIVITY_CALCULATION_DATA_H
#define REFLECTIVITY_CALCULATION_DATA_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

// Variable Declarations
extern omp_nest_lock_t emlrtNestLockGlobal;
extern boolean_T isInitialized_reflectivity_calculation;

#define MAX_THREADS                    omp_get_max_threads()
#endif

//
// File trailer for reflectivity_calculation_data.h
//
// [EOF]
//
