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
  void callReflectivity(real_T bulkIn, real_T bulkOut, const ::coder::array<
                        real_T, 1U> &simulationXData, const real_T dataIndices[2],
                        const real_T repeatLayers[2], ::coder::array<real_T, 2U>
                        &layers, real_T ssubs, const ::coder::array<real_T, 2U>
                        &resolution, const char_T parallel_data[], const int32_T
                        parallel_size[2], boolean_T useImaginary, ::coder::array<
                        real_T, 2U> &reflectivity, ::coder::array<real_T, 2U>
                        &simulation);
}

#endif

// End of code generation (callReflectivity.h)
