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
  struct d_struct_T;
  struct struct2_T;
  struct struct1_T;
  struct cell_12;
}

// Function Declarations
namespace RAT
{
  void nestedSampler(const d_struct_T *data_f1, const struct2_T *data_f2, const
                     struct1_T *data_f3, const cell_12 *data_f4, real_T nLive,
                     real_T nMCMC, real_T tolerance, const ::coder::array<real_T,
                     2U> &prior, real_T *logZ, ::coder::array<real_T, 2U>
                     &nest_samples, ::coder::array<real_T, 2U> &post_samples,
                     real_T *H);
}

#endif

// End of code generation (nestedSampler.h)
