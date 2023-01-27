//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: reflectivity_calculation_terminate.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "reflectivity_calculation_terminate.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"
#include "omp.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace RAT
{
  void reflectivity_calculation_terminate()
  {
    omp_destroy_nest_lock(&reflectivity_calculation_nestLockGlobal);
  }
}

//
// File trailer for reflectivity_calculation_terminate.cpp
//
// [EOF]
//
