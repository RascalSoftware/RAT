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
  struct e_struct_T;
  struct struct4_T;
}

// Function Declarations
namespace RAT
{
  real_T DREAMWrapper(const ::coder::array<real_T, 2U> &pars, const e_struct_T
                      *ratInputs_problemStruct, const struct4_T
                      *ratInputs_controls);
}

#endif

// End of code generation (DREAMWrapper.h)
