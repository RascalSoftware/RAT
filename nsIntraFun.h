//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// nsIntraFun.h
//
// Code generation for function 'nsIntraFun'
//
#ifndef NSINTRAFUN_H
#define NSINTRAFUN_H

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
  struct struct2_T;
  struct cell_11;
}

// Function Declarations
namespace RAT
{
  real_T nsIntraFun(const d_struct_T *data_f1, const struct2_T *data_f2, const
                    cell_11 *data_f4, const ::coder::array<real_T, 2U> &p);
  real_T nsIntraFun(const d_struct_T *data_f1, const struct2_T *data_f2, const
                    cell_11 *data_f4, const ::coder::array<real_T, 1U> &p);
}

#endif

// End of code generation (nsIntraFun.h)
