//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: shiftdata.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef SHIFTDATA_H
#define SHIFTDATA_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void shiftdata(real_T scalefac, real_T horshift, real_T dataPresent, real_T
                 data_data[], const int32_T data_size[2], const real_T
                 dataLimits[2], const real_T simLimits_data[], real_T
                 shifted_data_data[], int32_T shifted_data_size[2]);
}

#endif

//
// File trailer for shiftdata.h
//
// [EOF]
//
