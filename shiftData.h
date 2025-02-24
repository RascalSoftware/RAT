//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void shiftData(double scalefactor, double qzshift, double dataPresent, ::coder::
                 array<double, 2U> &data, const double dataLimits[2], const
                 double simLimits[2], ::coder::array<double, 2U> &shiftedData);
}

#endif

// End of code generation (shiftData.h)
