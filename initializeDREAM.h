//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// initializeDREAM.h
//
// Code generation for function 'initializeDREAM'
//
#ifndef INITIALIZEDREAM_H
#define INITIALIZEDREAM_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct DreamParams;
  struct g_struct_T;
  struct ProblemDefinition;
  struct Controls;
}

// Function Declarations
namespace RAT
{
  void initializeDREAM(const DreamParams *DREAMPar, const ::coder::array<double,
                       2U> &paramInfo_min, const ::coder::array<double, 2U>
                       &paramInfo_max, const char paramInfo_boundhandling_data[],
                       const int paramInfo_boundhandling_size[2], ::coder::array<
                       double, 3U> &chain, g_struct_T *output, ::coder::array<
                       double, 2U> &log_L, const ProblemDefinition
                       *ratInputs_problemStruct, const Controls
                       *ratInputs_controls, const ::coder::array<double, 2U>
                       &ratInputs_priors, ::coder::array<double, 2U> &X, ::coder::
                       array<double, 2U> &fx, ::coder::array<double, 2U> &CR,
                       double pCR_data[], int pCR_size[2], double lCR_data[],
                       int lCR_size[2], double delta_tot_data[], int
                       delta_tot_size[2]);
}

#endif

// End of code generation (initializeDREAM.h)
