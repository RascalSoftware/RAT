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
  struct b_struct_T;
  struct e_struct_T;
  struct Controls;
}

// Function Declarations
namespace RAT
{
  void processBayes(const double bayesOutputs_bestParams_data[], const int
                    bayesOutputs_bestParams_size[2], const ::coder::array<double,
                    2U> &bayesOutputs_chain, ProblemDefinition &problemStruct,
                    const char controls_parallel_data[], const int
                    controls_parallel_size[2], double
                    controls_numSimulationPoints, double
                    controls_resampleMinAngle, double controls_resampleNPoints,
                    b_struct_T &result, e_struct_T &bayesResults);
  void processBayes(const ::coder::array<double, 2U> &bayesOutputs_bestParams,
                    const ::coder::array<double, 2U> &bayesOutputs_chain,
                    ProblemDefinition &problemStruct, Controls &controls,
                    b_struct_T &result, e_struct_T &bayesResults);
}

#endif

// End of code generation (processBayes.h)
