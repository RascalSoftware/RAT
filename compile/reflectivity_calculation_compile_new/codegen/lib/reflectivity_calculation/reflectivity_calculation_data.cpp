//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivity_calculation_data.cpp
//
// Code generation for function 'reflectivity_calculation_data'
//

// Include files
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
omp_nest_lock_t emlrtNestLockGlobal;

const double dv[9]{10.0, 50.0, 100.0, 1.0E-6, 2.0E-6, 1.0E-6, 3.0, 4.0, 4.0};

boolean_T isInitialized_reflectivity_calculation{false};

// End of code generation (reflectivity_calculation_data.cpp)
