//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// drawMultiNest.h
//
// Code generation for function 'drawMultiNest'
//
#ifndef DRAWMULTINEST_H
#define DRAWMULTINEST_H

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
  void drawMultiNest(const ::coder::array<double, 1U> &fracvol, const ::coder::
                     array<double, 2U> &Bs, const ::coder::array<double, 2U>
                     &mus, double logLmin, const ::coder::array<double, 2U>
                     &prior, const ProblemDefinition *data_f1, const Controls
                     *data_f2, ::coder::array<double, 2U> &sample, double *logL);
}

#endif

// End of code generation (drawMultiNest.h)
