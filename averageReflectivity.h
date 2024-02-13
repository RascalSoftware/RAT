//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// averageReflectivity.h
//
// Code generation for function 'averageReflectivity'
//
#ifndef AVERAGEREFLECTIVITY_H
#define AVERAGEREFLECTIVITY_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    void averageReflectivity(const ::coder::array<real_T, 2U> &reflect1, const ::
      coder::array<real_T, 2U> &reflect2, const ::coder::array<real_T, 2U>
      &simul1, const ::coder::array<real_T, 2U> &simul2, real_T domainRatio, ::
      coder::array<real_T, 2U> &totReflect, ::coder::array<real_T, 2U> &totSimul);
  }
}

#endif

// End of code generation (averageReflectivity.h)
