//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeSimulationRange.h
//
// Code generation for function 'makeSimulationRange'
//
#ifndef MAKESIMULATIONRANGE_H
#define MAKESIMULATIONRANGE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void makeSimulationRange(const ::coder::array<real_T, 2U> &data, const real_T
    simulationLimits[2], ::coder::array<real_T, 1U> &simXdata, real_T splits[2]);
}

#endif

// End of code generation (makeSimulationRange.h)
