//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: sldFunc.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef SLDFUNC_H
#define SLDFUNC_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void sldFunc(real_T x, const ::coder::array<real_T, 2U> &SLD, ::coder::array<
               real_T, 1U> &sldVal);
  void sldFunc(real_T x, const real_T SLD_data[], const int32_T SLD_size[2],
               real_T sldVal_data[], int32_T *sldVal_size);
}

#endif

//
// File trailer for sldFunc.h
//
// [EOF]
//
