//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// calcEllipsoid.h
//
// Code generation for function 'calcEllipsoid'
//
#ifndef CALCELLIPSOID_H
#define CALCELLIPSOID_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  double calcEllipsoid(const ::coder::array<double, 2U> &u, double VS, ::coder::
                       array<double, 2U> &B, ::coder::array<double, 2U> &mu,
                       double VE_data[], int VE_size[2]);
}

#endif

// End of code generation (calcEllipsoid.h)
