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
  struct ProblemDefinition;
  struct Controls;
}

// Function Declarations
namespace RAT
{
  void nestedSampler(const ProblemDefinition *data_f1, const Controls *data_f2,
                     double nLive, double nMCMC, double tolerance, const ::coder::
                     array<double, 2U> &prior, double *logZ, ::coder::array<
                     double, 2U> &nest_samples, ::coder::array<double, 2U>
                     &post_samples, double *H);
}

#endif

// End of code generation (nestedSampler.h)
