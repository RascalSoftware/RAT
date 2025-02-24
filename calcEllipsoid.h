//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void calcEllipsoid(const ::coder::array<double, 2U> &u, double VS, ::coder::
                     array<double, 2U> &B, ::coder::array<double, 2U> &mu,
                     double VE_data[], int VE_size[2], double *flag);
}

#endif

// End of code generation (calcEllipsoid.h)
