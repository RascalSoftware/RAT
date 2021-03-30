//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: reflectivity_calculation_initialize.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:15:13
//

// Include Files
#include "reflectivity_calculation_initialize.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void reflectivity_calculation_initialize()
{
  rt_InitInfAndNaN();
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_reflectivity_calculation = true;
}

//
// File trailer for reflectivity_calculation_initialize.cpp
//
// [EOF]
//
