//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// customXY1.h
//
// Code generation for function 'customXY1'
//
#ifndef CUSTOMXY1_H
#define CUSTOMXY1_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
  struct Controls;
  struct cell_wrap_7;
  struct cell_wrap_8;
  struct cell_wrap_9;
  struct b_ProblemDefinition;
}

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    void b_customXY(const ProblemDefinition *problemStruct, const Controls
                    *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                    array<double, 1U> &scalefactors, ::coder::array<double, 1U>
                    &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::
                    array<double, 1U> &chis, ::coder::array<cell_wrap_7, 1U>
                    &reflectivity, ::coder::array<cell_wrap_7, 1U> &simulation, ::
                    coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::array<
                    cell_wrap_8, 1U> &backgrounds, ::coder::array<cell_wrap_7,
                    1U> &resolutions, ::coder::array<cell_wrap_9, 2U>
                    &domainLayerSlds, ::coder::array<cell_wrap_9, 2U>
                    &domainSldProfiles, ::coder::array<cell_wrap_9, 2U>
                    &domainResampledLayers, ::coder::array<double, 1U>
                    &subRoughs);
    void b_customXY(const b_ProblemDefinition *problemStruct, const Controls
                    *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                    array<double, 1U> &scalefactors, ::coder::array<double, 1U>
                    &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::
                    array<double, 1U> &chis, ::coder::array<cell_wrap_7, 1U>
                    &reflectivity, ::coder::array<cell_wrap_7, 1U> &simulation, ::
                    coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::array<
                    cell_wrap_8, 1U> &backgrounds, ::coder::array<cell_wrap_7,
                    1U> &resolutions, ::coder::array<cell_wrap_9, 2U>
                    &domainLayerSlds, ::coder::array<cell_wrap_9, 2U>
                    &domainSldProfiles, ::coder::array<cell_wrap_9, 2U>
                    &domainResampledLayers, ::coder::array<double, 1U>
                    &subRoughs);
  }
}

#endif

// End of code generation (customXY1.h)
