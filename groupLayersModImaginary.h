//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// groupLayersModImaginary.h
//
// Code generation for function 'groupLayersModImaginary'
//
#ifndef GROUPLAYERSMODIMAGINARY_H
#define GROUPLAYERSMODIMAGINARY_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  double groupLayersModImaginary(const ::coder::array<double, 2U>
    &resampledLayers, double subRoughs, const char geometry_data[], const int
    geometry_size[2], double bulkIns, double bulkOuts, ::coder::array<double, 2U>
    &outLayers);
}

#endif

// End of code generation (groupLayersModImaginary.h)
