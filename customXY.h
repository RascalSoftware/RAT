//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// customXY.h
//
// Code generation for function 'customXY'
//
#ifndef CUSTOMXY_H
#define CUSTOMXY_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct ProblemDefinition;
}

// Function Declarations
namespace RAT
{
  namespace normalTF
  {
    void customXY(const ProblemDefinition &problemStruct, const Controls
                  *controls, ::coder::array<double, 1U> &qzshifts, ::coder::
                  array<double, 1U> &scalefactors, ::coder::array<double, 1U>
                  &bulkIns, ::coder::array<double, 1U> &bulkOuts, ::coder::array<
                  double, 1U> &chis, ::coder::array<cell_wrap_7, 1U>
                  &reflectivity, ::coder::array<cell_wrap_7, 1U> &simulation, ::
                  coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::array<
                  cell_wrap_8, 1U> &backgrounds, ::coder::array<cell_wrap_7, 1U>
                  &resolutions, ::coder::array<cell_wrap_9, 2U> &sldProfiles, ::
                  coder::array<cell_wrap_9, 2U> &layers, ::coder::array<
                  cell_wrap_9, 2U> &resampledLayers, ::coder::array<double, 1U>
                  &subRoughs);
  }
}

#endif

// End of code generation (customXY.h)
