//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// deopt.h
//
// Code generation for function 'deopt'
//
#ifndef DEOPT_H
#define DEOPT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct e_struct_T;
  struct l_struct_T;
}

// Function Declarations
namespace RAT
{
  void deopt(const e_struct_T *problem, const char_T controls_parallel_data[],
             const int32_T controls_parallel_size[2], real_T
             controls_resampleMinAngle, real_T controls_resampleNPoints,
             boolean_T controls_calcSldDuringFit, const char_T
             controls_display_data[], const int32_T controls_display_size[2],
             real_T controls_updateFreq, real_T controls_updatePlotFreq, const
             char_T controls_IPCFilePath_data[], const int32_T
             controls_IPCFilePath_size[2], const l_struct_T *S_struct, ::coder::
             array<real_T, 2U> &FVr_bestmem);
}

#endif

// End of code generation (deopt.h)
