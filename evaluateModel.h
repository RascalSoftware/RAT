//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// evaluateModel.h
//
// Code generation for function 'evaluateModel'
//
#ifndef EVALUATEMODEL_H
#define EVALUATEMODEL_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
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
  void evaluateModel(const ::coder::array<double, 2U> &x, const DreamParams
                     *DREAMPar, const ProblemDefinition *ratInputs_problemStruct,
                     const Controls *ratInputs_controls, ::coder::array<double,
                     2U> &fx);
}

#endif

// End of code generation (evaluateModel.h)
