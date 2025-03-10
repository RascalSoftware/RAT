//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct DreamParams;
}

// Function Declarations
namespace RAT
{
  void removeOutlier(::coder::array<double, 2U> &X, ::coder::array<double, 2U>
                     &log_L, const double outlier_data[], const int
                     outlier_size[2], const DreamParams &DREAMPar, ::coder::
                     array<double, 2U> &outputOutlier);
}

#endif

// End of code generation (removeOutlier.h)
