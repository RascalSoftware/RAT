//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// simplexIntrafun.h
//
// Code generation for function 'simplexIntrafun'
//
#ifndef SIMPLEXINTRAFUN_H
#define SIMPLEXINTRAFUN_H

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
  struct struct1_T;
  struct struct2_T;
  struct l_struct_T;
  struct struct5_T;
}

// Function Declarations
namespace RAT
{
  void simplexIntrafun(const ::coder::array<real_T, 1U> &x, d_struct_T
                       *problemStruct, const cell_11 *problemCells, const
                       struct1_T *problemLimits, const struct2_T *controls,
                       const l_struct_T *params, real_T *fval, struct5_T *result);
}

#endif

// End of code generation (simplexIntrafun.h)
