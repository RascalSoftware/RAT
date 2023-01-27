//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: sortIdx.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef SORTIDX_H
#define SORTIDX_H

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
    namespace internal
    {
      void sortIdx(const ::coder::array<real_T, 2U> &x, const int32_T col_data[],
                   ::coder::array<int32_T, 1U> &idx);
    }
  }
}

#endif

//
// File trailer for sortIdx.h
//
// [EOF]
//
