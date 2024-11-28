//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// drawMCMC.h
//
// Code generation for function 'drawMCMC'
//
#ifndef DRAWMCMC_H
#define DRAWMCMC_H

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
  struct struct2_T;
}

// Function Declarations
namespace RAT
{
  void drawMCMC(const ::coder::array<real_T, 2U> &livepoints, const ::coder::
                array<real_T, 2U> &cholmat, real_T logLmin, const ::coder::array<
                real_T, 2U> &prior, const e_struct_T *data_f1, const struct3_T
                *data_f2, const struct2_T *data_f3, real_T nMCMC, ::coder::array<
                real_T, 2U> &sample, real_T *logL);
}

#endif

// End of code generation (drawMCMC.h)
