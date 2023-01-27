//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: linspace.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef LINSPACE_H
#define LINSPACE_H

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
    void linspace(real_T d1, real_T d2, real_T n, ::coder::array<real_T, 2U> &y);
    void linspace(real_T d1, real_T d2, real_T y[100]);
  }
}

#endif

//
// File trailer for linspace.h
//
// [EOF]
//
