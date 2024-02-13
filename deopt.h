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
  struct d_struct_T;
  struct cell_wrap_2;
  struct cell_wrap_8;
  struct cell_wrap_1;
  struct struct3_T;
  struct k_struct_T;
}

// Function Declarations
namespace RAT
{
  void deopt(const d_struct_T *problem, const ::coder::array<cell_wrap_2, 2U>
             &problemCells_f1, const ::coder::array<cell_wrap_8, 2U>
             &problemCells_f2, const ::coder::array<cell_wrap_2, 2U>
             &problemCells_f3, const ::coder::array<cell_wrap_2, 2U>
             &problemCells_f4, const ::coder::array<cell_wrap_8, 2U>
             &problemCells_f5, const ::coder::array<cell_wrap_8, 1U>
             &problemCells_f6, const ::coder::array<cell_wrap_1, 2U>
             &problemCells_f14, const ::coder::array<cell_wrap_8, 2U>
             &problemCells_f19, const char_T controls_parallel_data[], const
             int32_T controls_parallel_size[2], const real_T controls_resamPars
             [2], boolean_T controls_calcSldDuringFit, const char_T
             controls_display_data[], const int32_T controls_display_size[2],
             const struct3_T *controls_checks, const k_struct_T *S_struct, ::
             coder::array<real_T, 2U> &FVr_bestmem);
}

#endif

// End of code generation (deopt.h)
