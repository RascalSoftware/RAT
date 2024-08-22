//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// initializeDREAM.h
//
// Code generation for function 'initializeDREAM'
//
#ifndef INITIALIZEDREAM_H
#define INITIALIZEDREAM_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct struct11_T;
  struct l_struct_T;
  struct d_struct_T;
  struct cell_13;
  struct struct1_T;
  struct struct2_T;
}

// Function Declarations
namespace RAT
{
  void initializeDREAM(const struct11_T *DREAMPar, const ::coder::array<real_T,
                       2U> &paramInfo_min, const ::coder::array<real_T, 2U>
                       &paramInfo_max, const char_T
                       paramInfo_boundhandling_data[], const int32_T
                       paramInfo_boundhandling_size[2], ::coder::array<real_T,
                       3U> &chain, l_struct_T *output, ::coder::array<real_T, 2U>
                       &log_L, const d_struct_T *ratInputs_problemStruct, const
                       cell_13 *ratInputs_problemCells, const struct1_T
                       *ratInputs_problemLimits, const struct2_T
                       *ratInputs_controls, const ::coder::array<real_T, 2U>
                       &ratInputs_priors, ::coder::array<real_T, 2U> &X, ::coder::
                       array<real_T, 2U> &fx, ::coder::array<real_T, 2U> &CR,
                       real_T pCR_data[], int32_T pCR_size[2], real_T lCR_data[],
                       int32_T lCR_size[2], real_T delta_tot_data[], int32_T
                       delta_tot_size[2]);
}

#endif

// End of code generation (initializeDREAM.h)
