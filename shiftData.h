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
  void shiftData(real_T scalefactor, real_T qzshift, real_T dataPresent, ::coder::
                 array<real_T, 2U> &data, const real_T dataLimits[2], const
                 real_T simLimits[2], ::coder::array<real_T, 2U> &shiftedData);
}

#endif

// End of code generation (shiftData.h)
