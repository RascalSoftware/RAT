//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// shiftdata.h
//
// Code generation for function 'shiftdata'
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
void shiftdata(double scalefac, double horshift, double dataPresent,
               coder::array<double, 2U> &data, const double dataLimits[2],
               const double simLimits[2],
               coder::array<double, 2U> &shifted_data);

#endif
// End of code generation (shiftdata.h)
