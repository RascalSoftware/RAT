//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// calcProposal.h
//
// Code generation for function 'calcProposal'
//
#ifndef CALCPROPOSAL_H
#define CALCPROPOSAL_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct struct13_T;
}

// Function Declarations
namespace RAT
{
  void calcProposal(const ::coder::array<real_T, 2U> &X, real_T CR_data[], const
                    struct13_T *DREAMPar, const ::coder::array<real_T, 2U>
                    &Table_gamma, const ::coder::array<real_T, 2U> &Par_info_min,
                    const ::coder::array<real_T, 2U> &Par_info_max, const char_T
                    Par_info_boundhandling_data[], const int32_T
                    Par_info_boundhandling_size[2], ::coder::array<real_T, 2U>
                    &x_new);
}

#endif

// End of code generation (calcProposal.h)
