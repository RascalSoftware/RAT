//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// prctile.h
//
// Code generation for function 'prctile'
//
#ifndef PRCTILE_H
#define PRCTILE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void b_prctile(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T,
                   2U> &y);
    void b_prctile(const real_T x_data[], int32_T x_size, real_T y[2]);
    void prctile(const ::coder::array<real_T, 2U> &x, real_T y[2]);
    void prctile(const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U>
                 &y);
    void prctile(const real_T x_data[], int32_T x_size, real_T y[2]);
  }
}

#endif

// End of code generation (prctile.h)
