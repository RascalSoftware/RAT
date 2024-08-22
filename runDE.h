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
  struct cell_13;
  struct struct1_T;
  struct struct2_T;
  struct g_struct_T;
  struct struct5_T;
  struct struct_T;
  struct e_struct_T;
}

// Function Declarations
namespace RAT
{
  void intrafun(const ::coder::array<real_T, 2U> &p, d_struct_T *problemStruct,
                const cell_13 *problemCells, const struct1_T *problemLimits,
                const struct2_T *controls, struct_T *S_MSE, e_struct_T *result);
  void runDE(const d_struct_T *problemStruct, const cell_13 *problemCells, const
             struct1_T *problemLimits, const struct2_T *controls, g_struct_T
             *b_problemStruct, struct5_T *result);
}

#endif

// End of code generation (runDE.h)
