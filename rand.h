//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// rand.h
//
// Code generation for function 'rand'
//
#ifndef RAND_H
#define RAND_H

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
    void b_rand(real_T r[4]);
    real_T b_rand();
    void b_rand(real_T varargin_1, real_T varargin_2, ::coder::array<real_T, 2U>
                &r);
    void b_rand(const real_T varargin_1[2], ::coder::array<real_T, 2U> &r);
    void b_rand(real_T varargin_1, ::coder::array<real_T, 1U> &r);
    void b_rand(int32_T varargin_1, ::coder::array<real_T, 1U> &r);
    void b_rand(real_T varargin_2, ::coder::array<real_T, 2U> &r);
    void c_rand(real_T r[1000]);
  }
}

#endif

// End of code generation (rand.h)
