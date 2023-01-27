//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: sortIdx.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "sortIdx.h"
#include "mergesort.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &x
//                const int32_T col_data[]
//                ::coder::array<int32_T, 1U> &idx
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void sortIdx(const ::coder::array<real_T, 2U> &x, const int32_T col_data[],
                   ::coder::array<int32_T, 1U> &idx)
      {
        int32_T k;
        int32_T n;
        n = x.size(0);
        idx.set_size(x.size(0));
        k = x.size(0);
        for (int32_T i{0}; i < k; i++) {
          idx[i] = 0;
        }

        if (x.size(0) == 0) {
          for (k = 0; k < n; k++) {
            idx[k] = k + 1;
          }
        } else {
          b_mergesort(idx, x, col_data, x.size(0));
        }
      }
    }
  }
}

//
// File trailer for sortIdx.cpp
//
// [EOF]
//
