//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// RATMain_terminate.cpp
//
// Code generation for function 'RATMain_terminate'
//

// Include files
#include "RATMain_terminate.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include "omp.h"

// Function Definitions
namespace RAT
{
  void RATMain_terminate()
  {
    omp_destroy_nest_lock(&RATMain_nestLockGlobal);
  }
}

// End of code generation (RATMain_terminate.cpp)
