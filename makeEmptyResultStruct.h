//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeEmptyResultStruct.h
//
// Code generation for function 'makeEmptyResultStruct'
//
#ifndef MAKEEMPTYRESULTSTRUCT_H
#define MAKEEMPTYRESULTSTRUCT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_8;
  struct cell_wrap_26;
  struct cell_wrap_10;
  struct struct6_T;
  struct b_struct_T;
  struct cell_wrap_1;
}

// Function Declarations
namespace RAT
{
  void makeEmptyResultStruct(real_T nContrasts, real_T nPars, boolean_T domains,
    ::coder::array<cell_wrap_8, 1U> &result_reflectivity, ::coder::array<
    cell_wrap_8, 1U> &result_simulation, ::coder::array<cell_wrap_26, 1U>
    &result_shiftedData, ::coder::array<cell_wrap_10, 2U> &result_layerSlds, ::
    coder::array<cell_wrap_10, 2U> &result_sldProfiles, ::coder::array<
    cell_wrap_26, 2U> &result_allLayers, struct6_T *result_calculationResults,
    b_struct_T *result_contrastParams, ::coder::array<real_T, 2U>
    &result_bestFitPars, ::coder::array<cell_wrap_1, 1U> &result_fitNames);
}

#endif

// End of code generation (makeEmptyResultStruct.h)
