//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// allocateLayersForContrast.h
//
// Code generation for function 'allocateLayersForContrast'
//
#ifndef ALLOCATELAYERSFORCONTRAST_H
#define ALLOCATELAYERSFORCONTRAST_H

// Include files
#include "RATMain_internal_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void allocateLayersForContrast(const ::coder::array<double, 2U> &layerIndices,
    const ::coder::array<cell_wrap_51, 2U> &layerValues, ::coder::array<double,
    2U> &layers);
}

#endif

// End of code generation (allocateLayersForContrast.h)
