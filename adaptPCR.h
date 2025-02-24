//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
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
  void adaptPCR(const DreamParams *DREAMPar, const ::coder::array<double, 2U>
                &CR, const double delta_tot_data[], const double lCRold_data[],
                double pCR_data[], int pCR_size[2], double lCR_data[], int
                lCR_size[2]);
}

#endif

// End of code generation (adaptPCR.h)
