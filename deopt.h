//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// deopt.h
//
// Code generation for function 'deopt'
//
#ifndef DEOPT_H
#define DEOPT_H

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
  struct struct3_T;
  struct h_struct_T;
}

// Function Declarations
namespace RAT
{
  void deopt(const e_struct_T *problem, const ::coder::array<real_T, 2U>
             &problemLimits_param, const ::coder::array<real_T, 2U>
             &problemLimits_backgroundParam, const ::coder::array<real_T, 2U>
             &problemLimits_scalefactor, const ::coder::array<real_T, 2U>
             &problemLimits_qzshift, const ::coder::array<real_T, 2U>
             &problemLimits_bulkIn, const ::coder::array<real_T, 2U>
             &problemLimits_bulkOut, const ::coder::array<real_T, 2U>
             &problemLimits_resolutionParam, const ::coder::array<real_T, 2U>
             &problemLimits_domainRatio, const struct3_T *controls, const
             h_struct_T *S_struct, ::coder::array<real_T, 2U> &FVr_bestmem);
}

#endif

// End of code generation (deopt.h)
