//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// RATMain.h
//
// Code generation for function 'RATMain'
//
#ifndef RATMAIN_H
#define RATMAIN_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  extern void RATMain(b_ProblemDefinition *problemStruct, const ProblemLimits
                      *problemLimits, Controls *controls, Results *results,
                      BayesResults *bayesResults);
}

#endif

// End of code generation (RATMain.h)
