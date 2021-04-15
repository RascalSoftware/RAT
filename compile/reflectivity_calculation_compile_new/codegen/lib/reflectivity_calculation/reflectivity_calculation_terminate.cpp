//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: reflectivity_calculation_terminate.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//

// Include Files
#include "reflectivity_calculation_terminate.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void reflectivity_calculation_terminate()
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_reflectivity_calculation = false;
}

//
// File trailer for reflectivity_calculation_terminate.cpp
//
// [EOF]
//
