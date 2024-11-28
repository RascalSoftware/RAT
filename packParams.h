//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// packParams.h
//
// Code generation for function 'packParams'
//
#ifndef PACKPARAMS_H
#define PACKPARAMS_H

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
  struct struct4_T;
  struct cell_wrap_7;
  struct g_struct_T;
  struct struct0_T;
}

// Function Declarations
namespace RAT
{
  void packParams(e_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                  &limits_param, const ::coder::array<real_T, 2U>
                  &limits_backgroundParam, const ::coder::array<real_T, 2U>
                  &limits_scalefactor, const ::coder::array<real_T, 2U>
                  &limits_qzshift, const ::coder::array<real_T, 2U>
                  &limits_bulkIn, const ::coder::array<real_T, 2U>
                  &limits_bulkOut, const ::coder::array<real_T, 2U>
                  &limits_resolutionParam, const ::coder::array<real_T, 2U>
                  &limits_domainRatio, const struct4_T *checks, ::coder::array<
                  cell_wrap_7, 1U> &fitNames);
  void packParams(g_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                  &limits_param, const ::coder::array<real_T, 2U>
                  &limits_backgroundParam, const ::coder::array<real_T, 2U>
                  &limits_scalefactor, const ::coder::array<real_T, 2U>
                  &limits_qzshift, const ::coder::array<real_T, 2U>
                  &limits_bulkIn, const ::coder::array<real_T, 2U>
                  &limits_bulkOut, const ::coder::array<real_T, 2U>
                  &limits_resolutionParam, const ::coder::array<real_T, 2U>
                  &limits_domainRatio, const struct4_T *checks, ::coder::array<
                  cell_wrap_7, 1U> &fitNames);
  void packParams(struct0_T *problemStruct, const ::coder::array<real_T, 2U>
                  &limits_param, const ::coder::array<real_T, 2U>
                  &limits_backgroundParam, const ::coder::array<real_T, 2U>
                  &limits_scalefactor, const ::coder::array<real_T, 2U>
                  &limits_qzshift, const ::coder::array<real_T, 2U>
                  &limits_bulkIn, const ::coder::array<real_T, 2U>
                  &limits_bulkOut, const ::coder::array<real_T, 2U>
                  &limits_resolutionParam, const ::coder::array<real_T, 2U>
                  &limits_domainRatio, const struct4_T *checks, ::coder::array<
                  cell_wrap_7, 1U> &fitNames);
}

#endif

// End of code generation (packParams.h)
