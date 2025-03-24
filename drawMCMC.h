//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// drawMCMC.h
//
// Code generation for function 'drawMCMC'
//
#ifndef DRAWMCMC_H
#define DRAWMCMC_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
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
  double drawMCMC(const ::coder::array<double, 2U> &livepoints, const ::coder::
                  array<double, 2U> &cholmat, double logLmin, const ::coder::
                  array<double, 2U> &prior, const ProblemDefinition &data_f1,
                  const Controls &data_f2, double nMCMC, ::coder::array<double,
                  2U> &sample);
}

#endif

// End of code generation (drawMCMC.h)
