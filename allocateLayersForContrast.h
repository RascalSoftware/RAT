//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// allocateLayersForContrast.h
//
// Code generation for function 'allocateLayersForContrast'
//
#ifndef ALLOCATELAYERSFORCONTRAST_H
#define ALLOCATELAYERSFORCONTRAST_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_43;
}

// Function Declarations
namespace RAT
{
  void allocateLayersForContrast(const ::coder::array<real_T, 2U>
    &contrastLayers, const ::coder::array<cell_wrap_43, 2U>
    &outParameterisedLayers, boolean_T useImaginary, ::coder::array<real_T, 2U>
    &thisContrastLayers);
}

#endif

// End of code generation (allocateLayersForContrast.h)
