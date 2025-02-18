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
  struct e_struct_T;
  struct struct5_T;
}

// Function Declarations
namespace RAT
{
  void simplexIntrafun(const ::coder::array<real_T, 1U> &x, e_struct_T
                       *problemStruct, const char_T controls_parallel_data[],
                       const int32_T controls_parallel_size[2], real_T
                       controls_resampleMinAngle, real_T
                       controls_resampleNPoints, boolean_T
                       controls_calcSldDuringFit, const ::coder::array<real_T,
                       1U> &params_LB, const ::coder::array<real_T, 1U>
                       &params_UB, const ::coder::array<real_T, 1U>
                       &params_BoundClass, real_T *fval, struct5_T *result);
}

#endif

// End of code generation (simplexIntrafun.h)
