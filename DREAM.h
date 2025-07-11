//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// DREAM.h
//
// Code generation for function 'DREAM'
//
#ifndef DREAM_H
#define DREAM_H

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
  struct f_struct_T;
}

// Function Declarations
namespace RAT
{
  void DREAM(double dreamVariables_nParams, double dreamVariables_nChains,
             double dreamVariables_nGenerations, double
             dreamVariables_jumpProbability, double dreamVariables_pUnitGamma,
             boolean_T dreamVariables_adaptPCR, const ::coder::array<double, 2U>
             &paramInfo_min, const ::coder::array<double, 2U> &paramInfo_max,
             const char paramInfo_boundhandling_data[], const int
             paramInfo_boundhandling_size[2], const ProblemDefinition &
             ratInputs_problemStruct, const Controls *ratInputs_controls, const ::
             coder::array<double, 2U> &ratInputs_priors, ::coder::array<double,
             3U> &chain, f_struct_T &output, ::coder::array<double, 2U> &log_L);
}

#endif

// End of code generation (DREAM.h)
