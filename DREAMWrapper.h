//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// DREAMWrapper.h
//
// Code generation for function 'DREAMWrapper'
//
#ifndef DREAMWRAPPER_H
#define DREAMWRAPPER_H

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
}

// Function Declarations
namespace RAT
{
  real_T DREAMWrapper(const ::coder::array<real_T, 2U> &pars, const d_struct_T
                      *ratInputs_problemStruct, const cell_11
                      *ratInputs_problemCells, const struct2_T
                      *ratInputs_controls);
}

#endif

// End of code generation (DREAMWrapper.h)
