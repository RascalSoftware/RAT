//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// DREAMWrapper.h
//
// Code generation for function 'DREAMWrapper'
//
#ifndef DREAMWRAPPER_H
#define DREAMWRAPPER_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct Controls;
}

// Function Declarations
namespace RAT
{
  double DREAMWrapper(const ::coder::array<double, 2U> &pars, const
                      ProblemDefinition &ratInputs_problemStruct, const Controls
                      *ratInputs_controls);
}

#endif

// End of code generation (DREAMWrapper.h)
