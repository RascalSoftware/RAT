//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// removeOutlier.h
//
// Code generation for function 'removeOutlier'
//
#ifndef REMOVEOUTLIER_H
#define REMOVEOUTLIER_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct struct13_T;
}

// Function Declarations
namespace RAT
{
  void removeOutlier(::coder::array<real_T, 2U> &X, ::coder::array<real_T, 2U>
                     &log_L, const real_T outlier_data[], const int32_T
                     outlier_size[2], const struct13_T *DREAMPar, ::coder::array<
                     real_T, 2U> &outputOutlier);
}

#endif

// End of code generation (removeOutlier.h)
