//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// groupLayersMod.h
//
// Code generation for function 'groupLayersMod'
//
#ifndef GROUPLAYERSMOD_H
#define GROUPLAYERSMOD_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void groupLayersMod(const ::coder::array<double, 2U> &resampledLayers, double
                      subRoughs, const char geometry_data[], const int
                      geometry_size[2], double bulkIns, double bulkOuts, ::coder::
                      array<double, 2U> &outLayers, double *ssubs);
}

#endif

// End of code generation (groupLayersMod.h)
