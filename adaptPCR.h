//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// adaptPCR.h
//
// Code generation for function 'adaptPCR'
//
#ifndef ADAPTPCR_H
#define ADAPTPCR_H

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
  void adaptPCR(const DreamParams &DREAMPar, const ::coder::array<double, 2U>
                &CR, const double delta_tot_data[], const double lCRold_data[],
                double pCR_data[], int pCR_size[2], double lCR_data[], int
                lCR_size[2]);
}

#endif

// End of code generation (adaptPCR.h)
