//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivity_calculation_initialize.cpp
//
// Code generation for function 'reflectivity_calculation_initialize'
//

// Include files
#include "reflectivity_calculation_initialize.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void reflectivity_calculation_initialize()
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_reflectivity_calculation = true;
}

// End of code generation (reflectivity_calculation_initialize.cpp)
