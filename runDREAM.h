//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// runDREAM.h
//
// Code generation for function 'runDREAM'
//
#ifndef RUNDREAM_H
#define RUNDREAM_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct Controls;
  struct b_struct_T;
  struct c_struct_T;
}

// Function Declarations
namespace RAT
{
  void runDREAM(const ProblemDefinition &problemStruct, const Controls *controls,
                b_struct_T &result, c_struct_T &bayesResults, ProblemDefinition
                &outProblemStruct);
}

#endif

// End of code generation (runDREAM.h)
