//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runDE.h
//
// Code generation for function 'runDE'
//
#ifndef RUNDE_H
#define RUNDE_H

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
  struct struct3_T;
  struct cell_wrap_2;
  struct cell_wrap_8;
  struct cell_wrap_1;
  struct struct_T;
  struct cell_11;
  struct struct1_T;
  struct struct2_T;
  struct e_struct_T;
  struct cell_wrap_9;
}

// Function Declarations
namespace RAT
{
  struct_T intrafun(const ::coder::array<real_T, 2U> &p, d_struct_T
                    *problemStruct, const char_T controls_parallel_data[], const
                    int32_T controls_parallel_size[2], const real_T
                    controls_resamPars[2], boolean_T controls_calcSldDuringFit,
                    const struct3_T *controls_checks, const ::coder::array<
                    cell_wrap_2, 2U> &problemCells_f1, const ::coder::array<
                    cell_wrap_8, 2U> &problemCells_f2, const ::coder::array<
                    cell_wrap_2, 2U> &problemCells_f3, const ::coder::array<
                    cell_wrap_2, 2U> &problemCells_f4, const ::coder::array<
                    cell_wrap_8, 2U> &problemCells_f5, const ::coder::array<
                    cell_wrap_8, 1U> &problemCells_f6, const ::coder::array<
                    cell_wrap_1, 2U> &problemCells_f14, const ::coder::array<
                    cell_wrap_8, 2U> &problemCells_f19);
  void runDE(d_struct_T *problemStruct, const cell_11 *problemCells, const
             struct1_T *problemLimits, const struct2_T *controls, e_struct_T
             *contrastParams, cell_wrap_9 result[6]);
}

#endif

// End of code generation (runDE.h)
