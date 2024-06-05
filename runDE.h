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
  struct f_struct_T;
  struct cell_11;
  struct struct1_T;
  struct struct2_T;
  struct struct_T;
  struct struct5_T;
}

// Function Declarations
namespace RAT
{
  void intrafun(const ::coder::array<real_T, 2U> &p, f_struct_T *problemStruct,
                const cell_11 *problemCells, const struct1_T *problemLimits,
                const struct2_T *controls, struct_T *S_MSE, struct5_T *result);
  void runDE(f_struct_T *problemStruct, const cell_11 *problemCells, const
             struct1_T *problemLimits, const struct2_T *controls, struct5_T
             *result);
}

#endif

// End of code generation (runDE.h)
