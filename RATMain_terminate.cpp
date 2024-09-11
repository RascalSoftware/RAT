//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// RATMain_terminate.cpp
//
// Code generation for function 'RATMain_terminate'
//

// Include files
#include "RATMain_terminate.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace RAT
{
  void RATMain_terminate()
  {
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  }
}

// End of code generation (RATMain_terminate.cpp)
