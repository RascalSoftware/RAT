//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// allocateParamsToLayers.h
//
// Code generation for function 'allocateParamsToLayers'
//
#ifndef ALLOCATEPARAMSTOLAYERS_H
#define ALLOCATEPARAMSTOLAYERS_H

// Include files
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void allocateParamsToLayers(const ::coder::array<double, 2U> &paramValues,
    const ::coder::array<cell_wrap_9, 2U> &layersDetails, ::coder::array<
    cell_wrap_51, 2U> &layerValues);
}

#endif

// End of code generation (allocateParamsToLayers.h)
