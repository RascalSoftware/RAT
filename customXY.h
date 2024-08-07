//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// customXY.h
//
// Code generation for function 'customXY'
//
#ifndef CUSTOMXY_H
#define CUSTOMXY_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct d_struct_T;
  struct cell_11;
  struct struct2_T;
  struct cell_wrap_8;
  struct cell_wrap_10;
}

// Function Declarations
namespace RAT
{
  namespace nonPolarisedTF
  {
    void b_customXY(const d_struct_T *problemStruct, const cell_11 *problemCells,
                    const struct2_T *controls, ::coder::array<real_T, 1U>
                    &backgroundParams, ::coder::array<real_T, 1U> &qzshifts, ::
                    coder::array<real_T, 1U> &scalefactors, ::coder::array<
                    real_T, 1U> &bulkIns, ::coder::array<real_T, 1U> &bulkOuts, ::
                    coder::array<real_T, 1U> &resolutionParams, ::coder::array<
                    real_T, 1U> &chis, ::coder::array<cell_wrap_8, 1U>
                    &reflectivity, ::coder::array<cell_wrap_8, 1U> &simulation, ::
                    coder::array<cell_wrap_10, 1U> &shiftedData, ::coder::array<
                    cell_wrap_10, 1U> &layerSlds, ::coder::array<cell_wrap_10,
                    1U> &sldProfiles, ::coder::array<cell_wrap_10, 1U>
                    &resampledLayers, ::coder::array<real_T, 1U> &subRoughs);
  }
}

#endif

// End of code generation (customXY.h)
