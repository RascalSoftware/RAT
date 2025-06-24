//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// shiftData.h
//
// Code generation for function 'shiftData'
//
#ifndef SHIFTDATA_H
#define SHIFTDATA_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void shiftData(double scalefactor, double dataPresent, ::coder::array<double,
                 2U> &data, const double dataLimits[2], const double
                 simulationLimits[2], double numSimulationPoints, ::coder::array<
                 double, 2U> &shiftedData);
}

#endif

// End of code generation (shiftData.h)
