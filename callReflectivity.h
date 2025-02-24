//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// callReflectivity.h
//
// Code generation for function 'callReflectivity'
//
#ifndef CALLREFLECTIVITY_H
#define CALLREFLECTIVITY_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void callReflectivity(double bulkIn, double bulkOut, const ::coder::array<
                        double, 1U> &simulationXData, const double dataIndices[2],
                        const double repeatLayers[2], ::coder::array<double, 2U>
                        &layers, double ssubs, const ::coder::array<double, 2U>
                        &resolution, const char parallel_data[], const int
                        parallel_size[2], boolean_T useImaginary, ::coder::array<
                        double, 2U> &reflectivity, ::coder::array<double, 2U>
                        &simulation);
}

#endif

// End of code generation (callReflectivity.h)
