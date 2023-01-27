//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: applyBackgroundCorrection.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef APPLYBACKGROUNDCORRECTION_H
#define APPLYBACKGROUNDCORRECTION_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void applyBackgroundCorrection(::coder::array<real_T, 2U> &reflect, ::coder::
    array<real_T, 2U> &Simul, real_T shifted_dat_data[], const int32_T
    shifted_dat_size[2], real_T backg, real_T backsType);
}

#endif

//
// File trailer for applyBackgroundCorrection.h
//
// [EOF]
//
