//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// calcProposal.h
//
// Code generation for function 'calcProposal'
//
#ifndef CALCPROPOSAL_H
#define CALCPROPOSAL_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct DreamParams;
}

// Function Declarations
namespace RAT
{
  void calcProposal(const ::coder::array<double, 2U> &X, double CR_data[], const
                    DreamParams &DREAMPar, const ::coder::array<double, 2U>
                    &Table_gamma, const ::coder::array<double, 2U>
                    &paramInfo_min, const ::coder::array<double, 2U>
                    &paramInfo_max, const char paramInfo_boundhandling_data[],
                    const int paramInfo_boundhandling_size[2], ::coder::array<
                    double, 2U> &x_new);
}

#endif

// End of code generation (calcProposal.h)
