//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void makeSimulationRange(const ::coder::array<double, 2U> &data, const double
    simulationLimits[2], ::coder::array<double, 1U> &simulationXdata, double
    splits[2]);
}

#endif

// End of code generation (makeSimulationRange.h)
