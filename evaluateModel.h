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
  struct struct14_T;
  struct f_struct_T;
  struct cell_11;
  struct struct1_T;
  struct struct2_T;
}

// Function Declarations
namespace RAT
{
  void evaluateModel(const ::coder::array<real_T, 2U> &x, const struct14_T
                     *DREAMPar, const f_struct_T *ratInputs_problemStruct, const
                     cell_11 *ratInputs_problemCells, const struct1_T
                     *ratInputs_problemLimits, const struct2_T
                     *ratInputs_controls, ::coder::array<real_T, 2U> &fx);
}

#endif

// End of code generation (evaluateModel.h)
