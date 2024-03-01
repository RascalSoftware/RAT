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
  struct struct14_T;
}

// Function Declarations
namespace RAT
{
  void adaptPCR(const struct14_T *DREAMPar, const ::coder::array<real_T, 2U> &CR,
                const real_T delta_tot_data[], const real_T lCRold_data[],
                real_T pCR_data[], int32_T pCR_size[2], real_T lCR_data[],
                int32_T lCR_size[2]);
}

#endif

// End of code generation (adaptPCR.h)
