//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: blockedSummation.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef BLOCKEDSUMMATION_H
#define BLOCKEDSUMMATION_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void blockedSummation(const ::coder::array<real_T, 2U> &x, int32_T vlen, ::
                          coder::array<real_T, 1U> &y);
    real_T nestedIter(const ::coder::array<real_T, 1U> &x, int32_T vlen);
  }
}

#endif

//
// File trailer for blockedSummation.h
//
// [EOF]
//
