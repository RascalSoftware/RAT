//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// reflectivityCalculation.h
//
// Code generation for function 'reflectivityCalculation'
//
#ifndef REFLECTIVITYCALCULATION_H
#define REFLECTIVITYCALCULATION_H

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
}

// Function Declarations
namespace RAT
{
  void b_reflectivityCalculation(const ProblemDefinition &problemStruct, const
    Controls *controls, b_struct_T &result);
  void reflectivityCalculation(const ProblemDefinition &problemStruct, const
    Controls *controls, b_struct_T &result);
}

#endif

// End of code generation (reflectivityCalculation.h)
