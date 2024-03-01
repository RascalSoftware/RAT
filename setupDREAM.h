//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// setupDREAM.h
//
// Code generation for function 'setupDREAM'
//
#ifndef SETUPDREAM_H
#define SETUPDREAM_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct struct15_T;
  struct struct14_T;
  struct struct13_T;
}

// Function Declarations
namespace RAT
{
  void setupDREAM(real_T DREAMPar_d, real_T DREAMPar_N, real_T DREAMPar_T,
                  real_T DREAMPar_lambda, real_T DREAMPar_pUnitGamma, boolean_T
                  DREAMPar_adaptPCR, struct15_T *Meas_info, struct14_T
                  *outDREAMPar, ::coder::array<real_T, 3U> &chain, struct13_T
                  *output, ::coder::array<real_T, 2U> &log_L, ::coder::array<
                  real_T, 2U> &Table_gamma);
}

#endif

// End of code generation (setupDREAM.h)
