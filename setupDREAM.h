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
  struct b_struct_T;
  struct struct12_T;
  struct l_struct_T;
}

// Function Declarations
namespace RAT
{
  void setupDREAM(real_T DREAMPar_nParams, real_T DREAMPar_nChains, real_T
                  DREAMPar_nGenerations, real_T DREAMPar_jumpProbability, real_T
                  DREAMPar_pUnitGamma, boolean_T DREAMPar_adaptPCR, b_struct_T
                  *Meas_info, struct12_T *outDREAMPar, ::coder::array<real_T, 3U>
                  &chain, l_struct_T *output, ::coder::array<real_T, 2U> &log_L,
                  ::coder::array<real_T, 2U> &Table_gamma);
}

#endif

// End of code generation (setupDREAM.h)
