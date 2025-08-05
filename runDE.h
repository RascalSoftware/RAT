//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// runDE.h
//
// Code generation for function 'runDE'
//
#ifndef RUNDE_H
#define RUNDE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct b_struct_T;
  struct Controls;
}

// Function Declarations
namespace RAT
{
  double intrafun(const ::coder::array<double, 2U> &p, ProblemDefinition &
                  problemStruct, const char controls_parallel_data[], const int
                  controls_parallel_size[2], double controls_numSimulationPoints,
                  double controls_resampleMinAngle, double
                  controls_resampleNPoints, boolean_T controls_calcSLD,
                  b_struct_T &result, double &S_MSE_FVr_ca, double &S_MSE_I_no,
                  double &S_MSE_FVr_oa);
  void runDE(ProblemDefinition &problemStruct, Controls &controls, b_struct_T
             &result);
}

#endif

// End of code generation (runDE.h)
