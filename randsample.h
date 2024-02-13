//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// randsample.h
//
// Code generation for function 'randsample'
//
#ifndef RANDSAMPLE_H
#define RANDSAMPLE_H

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
    void randsample(real_T varargin_2, const real_T varargin_4[2], ::coder::
                    array<real_T, 2U> &y);
    void randsample(const real_T varargin_1_data[], real_T varargin_2, const
                    real_T varargin_4_data[], ::coder::array<real_T, 2U> &y);
  }
}

#endif

// End of code generation (randsample.h)
