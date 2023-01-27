//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: backSort.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef BACKSORT_H
#define BACKSORT_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void backSort(real_T cBacks, real_T cShifts, real_T cScales, real_T cNbas,
                real_T cNbss, real_T cRes, const real_T backs_data[], const
                real_T shifts_data[], const real_T sf_data[], const real_T
                nba_data[], const real_T nbs_data[], const real_T res_data[],
                real_T *backg, real_T *qshift, real_T *sf, real_T *nba, real_T
                *nbs, real_T *resol);
}

#endif

//
// File trailer for backSort.h
//
// [EOF]
//
