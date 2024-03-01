//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// unpackParams.h
//
// Code generation for function 'unpackParams'
//
#ifndef UNPACKPARAMS_H
#define UNPACKPARAMS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct f_struct_T;
}

// Function Declarations
namespace RAT
{
  void unpackParams(f_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                    &controls_checks_fitParam, const ::coder::array<real_T, 2U>
                    &controls_checks_fitBackgroundParam, const ::coder::array<
                    real_T, 2U> &controls_checks_fitQzshift, const ::coder::
                    array<real_T, 2U> &controls_checks_fitScalefactor, const ::
                    coder::array<real_T, 2U> &controls_checks_fitBulkIn, const ::
                    coder::array<real_T, 2U> &controls_checks_fitBulkOut, const ::
                    coder::array<real_T, 2U> &controls_checks_fitResolutionParam,
                    const ::coder::array<real_T, 2U>
                    &controls_checks_fitDomainRatio);
}

#endif

// End of code generation (unpackParams.h)
