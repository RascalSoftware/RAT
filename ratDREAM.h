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
  struct cell_11;
  struct struct2_T;
  struct struct12_T;
}

// Function Declarations
namespace RAT
{
  void ratDREAM(real_T dreamVariables_d, real_T dreamVariables_N, real_T
                dreamVariables_T, real_T dreamVariables_lambda, real_T
                dreamVariables_pUnitGamma, boolean_T dreamVariables_adaptPCR,
                const ::coder::array<real_T, 2U> &Par_info_min, const ::coder::
                array<real_T, 2U> &Par_info_max, const char_T
                Par_info_boundhandling_data[], const int32_T
                Par_info_boundhandling_size[2], const d_struct_T
                *ratInputs_problemStruct, const cell_11 *ratInputs_problemCells,
                const struct2_T *ratInputs_controls, const ::coder::array<real_T,
                2U> &ratInputs_priors, ::coder::array<real_T, 3U> &chain,
                struct12_T *output, ::coder::array<real_T, 2U> &fx);
}

#endif

// End of code generation (ratDREAM.h)
