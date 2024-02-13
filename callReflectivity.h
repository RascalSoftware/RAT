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
  void b_callReflectivity(real_T bulkIns, real_T bulkOuts, const real_T
    simLimits[2], const real_T repeatLayers[2], const ::coder::array<real_T, 2U>
    &thisData, ::coder::array<real_T, 2U> &layers, real_T ssubs, real_T
    resolution, boolean_T useImaginary, ::coder::array<real_T, 2U> &reflectivity,
    ::coder::array<real_T, 2U> &simulation);
  void callReflectivity(real_T bulkIns, real_T bulkOuts, const real_T simLimits
                        [2], const real_T repeatLayers[2], const ::coder::array<
                        real_T, 2U> &thisData, ::coder::array<real_T, 2U>
                        &layers, real_T ssubs, real_T resolution, boolean_T
                        useImaginary, ::coder::array<real_T, 2U> &reflectivity, ::
                        coder::array<real_T, 2U> &simulation);
}

#endif

// End of code generation (callReflectivity.h)
