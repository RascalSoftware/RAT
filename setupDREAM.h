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
  struct DreamParams;
  struct g_struct_T;
}

// Function Declarations
namespace RAT
{
  void setupDREAM(double DREAMPar_nParams, double DREAMPar_nChains, double
                  DREAMPar_nGenerations, double DREAMPar_jumpProbability, double
                  DREAMPar_pUnitGamma, boolean_T DREAMPar_adaptPCR, b_struct_T
                  *Meas_info, DreamParams *outDREAMPar, ::coder::array<double,
                  3U> &chain, g_struct_T *output, ::coder::array<double, 2U>
                  &log_L, ::coder::array<double, 2U> &Table_gamma);
}

#endif

// End of code generation (setupDREAM.h)
