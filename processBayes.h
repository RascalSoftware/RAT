//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// processBayes.h
//
// Code generation for function 'processBayes'
//
#ifndef PROCESSBAYES_H
#define PROCESSBAYES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct Controls;
  struct Results;
  struct f_struct_T;
}

// Function Declarations
namespace RAT
{
  void processBayes(const ::coder::array<double, 2U> &bayesOutputs_bestParams,
                    const ::coder::array<double, 2U> &bayesOutputs_chain,
                    ProblemDefinition *problemStruct, Controls *controls,
                    Results *result, f_struct_T *bayesResults);
}

#endif

// End of code generation (processBayes.h)
