//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// drawCR.h
//
// Code generation for function 'drawCR'
//
#ifndef DRAWCR_H
#define DRAWCR_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct struct13_T;
}

// Function Declarations
namespace RAT
{
  void drawCR(const struct13_T *DREAMPar, const real_T pCR_data[], const int32_T
              pCR_size[2], ::coder::array<real_T, 2U> &CR);
}

#endif

// End of code generation (drawCR.h)
