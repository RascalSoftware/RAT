//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// allocateParamsToLayers.h
//
// Code generation for function 'allocateParamsToLayers'
//
#ifndef ALLOCATEPARAMSTOLAYERS_H
#define ALLOCATEPARAMSTOLAYERS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_8;
  struct cell_wrap_22;
}

// Function Declarations
namespace RAT
{
  void allocateParamsToLayers(const ::coder::array<real_T, 2U> &params, const ::
    coder::array<cell_wrap_8, 1U> &layersDetails, ::coder::array<cell_wrap_22,
    2U> &outLayers);
}

#endif

// End of code generation (allocateParamsToLayers.h)
