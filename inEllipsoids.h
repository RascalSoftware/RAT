//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// inEllipsoids.h
//
// Code generation for function 'inEllipsoids'
//
#ifndef INELLIPSOIDS_H
#define INELLIPSOIDS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  real_T inEllipsoids(const ::coder::array<real_T, 2U> &pnt, const ::coder::
                      array<real_T, 2U> &Bs, const ::coder::array<real_T, 2U>
                      &mus);
}

#endif

// End of code generation (inEllipsoids.h)
