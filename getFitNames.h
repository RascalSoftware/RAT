//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// getFitNames.h
//
// Code generation for function 'getFitNames'
//
#ifndef GETFITNAMES_H
#define GETFITNAMES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_10;
  struct cell_wrap_0;
}

// Function Declarations
namespace RAT
{
  void getFitNames(const ::coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_params, const ::coder::array<
                   cell_wrap_10, 2U> &problemStruct_names_backgroundParams,
                   const ::coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_scalefactors, const ::coder::array<
                   cell_wrap_10, 2U> &problemStruct_names_qzshifts, const ::
                   coder::array<cell_wrap_10, 2U> &problemStruct_names_bulkIns,
                   const ::coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_bulkOuts, const ::coder::array<
                   cell_wrap_10, 2U> &problemStruct_names_resolutionParams,
                   const ::coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_domainRatios, const ::coder::array<
                   real_T, 2U> &problemStruct_checks_params, const ::coder::
                   array<real_T, 2U> &problemStruct_checks_backgroundParams,
                   const ::coder::array<real_T, 2U>
                   &problemStruct_checks_scalefactors, const ::coder::array<
                   real_T, 2U> &problemStruct_checks_qzshifts, const ::coder::
                   array<real_T, 2U> &problemStruct_checks_bulkIns, const ::
                   coder::array<real_T, 2U> &problemStruct_checks_bulkOuts,
                   const ::coder::array<real_T, 2U>
                   &problemStruct_checks_resolutionParams, const ::coder::array<
                   real_T, 2U> &problemStruct_checks_domainRatios, ::coder::
                   array<cell_wrap_10, 1U> &fitNames);
  void getFitNames(const ::coder::array<cell_wrap_0, 2U>
                   &problemStruct_names_params, const ::coder::array<cell_wrap_0,
                   2U> &problemStruct_names_backgroundParams, const ::coder::
                   array<cell_wrap_0, 2U> &problemStruct_names_scalefactors,
                   const ::coder::array<cell_wrap_0, 2U>
                   &problemStruct_names_qzshifts, const ::coder::array<
                   cell_wrap_0, 2U> &problemStruct_names_bulkIns, const ::coder::
                   array<cell_wrap_0, 2U> &problemStruct_names_bulkOuts, const ::
                   coder::array<cell_wrap_0, 2U>
                   &problemStruct_names_resolutionParams, const ::coder::array<
                   cell_wrap_0, 2U> &problemStruct_names_domainRatios, const ::
                   coder::array<real_T, 2U> &problemStruct_checks_params, const ::
                   coder::array<real_T, 2U>
                   &problemStruct_checks_backgroundParams, const ::coder::array<
                   real_T, 2U> &problemStruct_checks_scalefactors, const ::coder::
                   array<real_T, 2U> &problemStruct_checks_qzshifts, const ::
                   coder::array<real_T, 2U> &problemStruct_checks_bulkIns, const
                   ::coder::array<real_T, 2U> &problemStruct_checks_bulkOuts,
                   const ::coder::array<real_T, 2U>
                   &problemStruct_checks_resolutionParams, const ::coder::array<
                   real_T, 2U> &problemStruct_checks_domainRatios, ::coder::
                   array<cell_wrap_10, 1U> &fitNames);
}

#endif

// End of code generation (getFitNames.h)
