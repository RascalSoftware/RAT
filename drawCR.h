//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  void drawCR(const DreamParams &DREAMPar, const double pCR_data[], const int
              pCR_size[2], ::coder::array<double, 2U> &CR);
}

#endif

// End of code generation (drawCR.h)
