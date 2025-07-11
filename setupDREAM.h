//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct DreamParams;
  struct f_struct_T;
}

// Function Declarations
namespace RAT
{
  void setupDREAM(double DREAMPar_nParams, double DREAMPar_nChains, double
                  DREAMPar_nGenerations, double DREAMPar_jumpProbability, double
                  DREAMPar_pUnitGamma, boolean_T DREAMPar_adaptPCR, DreamParams
                  &outDREAMPar, ::coder::array<double, 3U> &chain, f_struct_T
                  &output, ::coder::array<double, 2U> &log_L, ::coder::array<
                  double, 2U> &Table_gamma);
}

#endif

// End of code generation (setupDREAM.h)
