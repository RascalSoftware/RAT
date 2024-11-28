//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// evaluateModel.h
//
// Code generation for function 'evaluateModel'
//
#ifndef EVALUATEMODEL_H
#define EVALUATEMODEL_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct struct12_T;
  struct e_struct_T;
  struct struct2_T;
  struct struct3_T;
}

// Function Declarations
namespace RAT
{
  void evaluateModel(const ::coder::array<real_T, 2U> &x, const struct12_T
                     *DREAMPar, const e_struct_T *ratInputs_problemStruct, const
                     struct2_T *ratInputs_problemLimits, const struct3_T
                     *ratInputs_controls, ::coder::array<real_T, 2U> &fx);
}

#endif

// End of code generation (evaluateModel.h)
