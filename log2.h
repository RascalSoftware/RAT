//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// log2.h
//
// Code generation for function 'log2'
//
#ifndef LOG2_H
#define LOG2_H

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
    void b_log2(const ::coder::array<real_T, 1U> &x, ::coder::array<real_T, 1U>
                &f, ::coder::array<real_T, 1U> &e);
    void b_log2(real_T x, real_T *f, real_T *e);
  }
}

#endif

// End of code generation (log2.h)
