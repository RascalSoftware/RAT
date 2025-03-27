//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// calcLogLikelihood.h
//
// Code generation for function 'calcLogLikelihood'
//
#ifndef CALCLOGLIKELIHOOD_H
#define CALCLOGLIKELIHOOD_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct DreamParams;
  struct ProblemDefinition;
  struct Controls;
}

// Function Declarations
namespace RAT
{
  void calcLogLikelihood(const ::coder::array<double, 2U> &x, const DreamParams
    &DREAMPar, const ProblemDefinition &ratInputs_problemStruct, const Controls *
    ratInputs_controls, ::coder::array<double, 1U> &log_L_x);
}

#endif

// End of code generation (calcLogLikelihood.h)
