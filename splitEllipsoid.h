//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// splitEllipsoid.h
//
// Code generation for function 'splitEllipsoid'
//
#ifndef SPLITELLIPSOID_H
#define SPLITELLIPSOID_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  double splitEllipsoid(const ::coder::array<double, 2U> &u, double VS, ::coder::
                        array<double, 2U> &u1, ::coder::array<double, 2U> &u2,
                        double VE1_data[], int VE1_size[2], double VE2_data[],
                        int VE2_size[2]);
}

#endif

// End of code generation (splitEllipsoid.h)
