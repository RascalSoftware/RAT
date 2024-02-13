//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void splitEllipsoid(const ::coder::array<real_T, 2U> &u, real_T VS, ::coder::
                      array<real_T, 2U> &u1, ::coder::array<real_T, 2U> &u2,
                      real_T VE1_data[], int32_T VE1_size[2], real_T VE2_data[],
                      int32_T VE2_size[2], real_T *nosplit);
}

#endif

// End of code generation (splitEllipsoid.h)
