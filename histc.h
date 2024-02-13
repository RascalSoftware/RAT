//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// histc.h
//
// Code generation for function 'histc'
//
#ifndef HISTC_H
#define HISTC_H

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
    void histc(const ::coder::array<real_T, 1U> &X, const real_T edges[3],
               real_T N[3], ::coder::array<real_T, 1U> &BIN);
    void histc(const ::coder::array<real_T, 1U> &X, const real_T edges_data[],
               real_T N_data[], int32_T *N_size, ::coder::array<real_T, 1U> &BIN);
  }
}

#endif

// End of code generation (histc.h)
