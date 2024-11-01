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
  struct d_struct_T;
  struct cell_12;
  struct struct1_T;
  struct struct2_T;
  struct l_struct_T;
}

// Function Declarations
namespace RAT
{
  void ratDREAM(real_T dreamVariables_nParams, real_T dreamVariables_nChains,
                real_T dreamVariables_nGenerations, real_T
                dreamVariables_jumpProbability, real_T dreamVariables_pUnitGamma,
                boolean_T dreamVariables_adaptPCR, const ::coder::array<real_T,
                2U> &paramInfo_min, const ::coder::array<real_T, 2U>
                &paramInfo_max, const char_T paramInfo_boundhandling_data[],
                const int32_T paramInfo_boundhandling_size[2], const d_struct_T *
                ratInputs_problemStruct, const cell_12 *ratInputs_problemCells,
                const struct1_T *ratInputs_problemLimits, const struct2_T
                *ratInputs_controls, const ::coder::array<real_T, 2U>
                &ratInputs_priors, ::coder::array<real_T, 3U> &chain, l_struct_T
                *output, ::coder::array<real_T, 2U> &fx);
}

#endif

// End of code generation (ratDREAM.h)
