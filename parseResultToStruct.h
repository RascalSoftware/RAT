//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// parseResultToStruct.h
//
// Code generation for function 'parseResultToStruct'
//
#ifndef PARSERESULTTOSTRUCT_H
#define PARSERESULTTOSTRUCT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct e_struct_T;
  struct cell_wrap_9;
  struct cell_wrap_8;
}

// Function Declarations
namespace RAT
{
  void parseResultToStruct(const e_struct_T *contrastParams, const cell_wrap_9
    resultCells[6], ::coder::array<cell_wrap_8, 2U> &result_reflectivity, ::
    coder::array<cell_wrap_8, 2U> &result_simulation, ::coder::array<cell_wrap_8,
    2U> &result_shiftedData, ::coder::array<cell_wrap_8, 2U> &result_layerSlds, ::
    coder::array<cell_wrap_8, 2U> &result_sldProfiles, ::coder::array<
    cell_wrap_8, 2U> &result_allLayers, real_T *result_calculationResults_sumChi,
    e_struct_T *result_contrastParams);
}

#endif

// End of code generation (parseResultToStruct.h)
