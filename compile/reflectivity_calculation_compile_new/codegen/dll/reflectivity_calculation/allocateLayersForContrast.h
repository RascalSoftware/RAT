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
struct cell_wrap_15;

// Function Declarations
void allocateLayersForContrast(
    const coder::array<double, 2U> &contrastLayers,
    const coder::array<cell_wrap_15, 2U> &outParameterisedLayers,
    coder::array<double, 2U> &thisContrastLayers);

#endif
// End of code generation (allocateLayersForContrast.h)
