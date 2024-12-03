//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// nestedSampler.h
//
// Code generation for function 'nestedSampler'
//
#ifndef NESTEDSAMPLER_H
#define NESTEDSAMPLER_H

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
  struct struct4_T;
}

// Function Declarations
namespace RAT
{
  void nestedSampler(const e_struct_T *data_f1, const struct4_T *data_f2, real_T
                     nLive, real_T nMCMC, real_T tolerance, const ::coder::array<
                     real_T, 2U> &prior, real_T *logZ, ::coder::array<real_T, 2U>
                     &nest_samples, ::coder::array<real_T, 2U> &post_samples,
                     real_T *H);
}

#endif

// End of code generation (nestedSampler.h)
