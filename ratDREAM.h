//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// ratDREAM.h
//
// Code generation for function 'ratDREAM'
//
#ifndef RATDREAM_H
#define RATDREAM_H

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
  struct g_struct_T;
}

// Function Declarations
namespace RAT
{
  void ratDREAM(double dreamVariables_nParams, double dreamVariables_nChains,
                double dreamVariables_nGenerations, double
                dreamVariables_jumpProbability, double dreamVariables_pUnitGamma,
                boolean_T dreamVariables_adaptPCR, const ::coder::array<double,
                2U> &paramInfo_min, const ::coder::array<double, 2U>
                &paramInfo_max, const char paramInfo_boundhandling_data[], const
                int paramInfo_boundhandling_size[2], const ProblemDefinition
                *ratInputs_problemStruct, const Controls *ratInputs_controls,
                const ::coder::array<double, 2U> &ratInputs_priors, ::coder::
                array<double, 3U> &chain, g_struct_T *output, ::coder::array<
                double, 2U> &fx);
}

#endif

// End of code generation (ratDREAM.h)
