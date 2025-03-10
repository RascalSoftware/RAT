//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct Controls;
  struct Results;
  struct e_struct_T;
}

// Function Declarations
namespace RAT
{
  void processBayes(const double bayesOutputs_bestParams_data[], const int
                    bayesOutputs_bestParams_size[2], const ::coder::array<double,
                    2U> &bayesOutputs_chain, ProblemDefinition &problemStruct,
                    Controls &controls, Results *result, e_struct_T
                    &bayesResults);
  void processBayes(const ::coder::array<double, 2U> &bayesOutputs_bestParams,
                    const ::coder::array<double, 2U> &bayesOutputs_chain,
                    ProblemDefinition &problemStruct, Controls &controls,
                    Results *result, e_struct_T &bayesResults);
}

#endif

// End of code generation (processBayes.h)
