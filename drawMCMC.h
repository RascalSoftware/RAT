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
  struct d_struct_T;
  struct struct2_T;
  struct struct1_T;
  struct cell_11;
}

// Function Declarations
namespace RAT
{
  void drawMCMC(const ::coder::array<real_T, 2U> &livepoints, const ::coder::
                array<real_T, 2U> &cholmat, real_T logLmin, const ::coder::array<
                real_T, 2U> &prior, const d_struct_T *data_f1, const struct2_T
                *data_f2, const struct1_T *data_f3, const cell_11 *data_f4,
                real_T nMCMC, ::coder::array<real_T, 2U> &sample, real_T *logL);
}

#endif

// End of code generation (drawMCMC.h)
