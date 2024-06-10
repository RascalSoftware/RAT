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
  struct f_struct_T;
  struct cell_11;
  struct struct1_T;
  struct struct2_T;
  struct l_struct_T;
}

// Function Declarations
namespace RAT
{
  void deopt(const f_struct_T *problem, const cell_11 *problemCells, const
             struct1_T *problemLimits, const struct2_T *controls, const
             l_struct_T *S_struct, ::coder::array<real_T, 2U> &FVr_bestmem);
}

#endif

// End of code generation (deopt.h)
