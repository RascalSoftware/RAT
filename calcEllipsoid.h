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
  void calcEllipsoid(const ::coder::array<real_T, 2U> &u, real_T VS, ::coder::
                     array<real_T, 2U> &B, ::coder::array<real_T, 2U> &mu,
                     real_T VE_data[], int32_T VE_size[2], real_T *flag);
}

#endif

// End of code generation (calcEllipsoid.h)
