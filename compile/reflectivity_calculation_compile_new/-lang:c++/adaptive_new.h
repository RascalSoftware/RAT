//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: adaptive_new.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef ADAPTIVE_NEW_H
#define ADAPTIVE_NEW_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_23;
}

// Function Declarations
namespace RAT
{
  void adaptive_new(const ::coder::array<real_T, 2U> &sldProfile, const real_T
                    startDomain[2], real_T minAngle, real_T nPoints, cell_23
                    *out);
  void adaptive_new(const real_T sldProfile_data[], const int32_T
                    sldProfile_size[2], const real_T startDomain[2], real_T
                    minAngle, real_T nPoints, cell_23 *out);
}

#endif

//
// File trailer for adaptive_new.h
//
// [EOF]
//
