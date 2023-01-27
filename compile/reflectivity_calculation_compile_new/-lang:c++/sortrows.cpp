//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: sortrows.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "sortrows.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static void apply_row_permutation(::coder::array<real_T, 2U> &y, const ::
      coder::array<int32_T, 1U> &idx);
  }
}

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 2U> &y
//                const ::coder::array<int32_T, 1U> &idx
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    static void apply_row_permutation(::coder::array<real_T, 2U> &y, const ::
      coder::array<int32_T, 1U> &idx)
    {
      ::coder::array<real_T, 1U> ycol;
      int32_T m;
      m = y.size(0) - 1;
      ycol.set_size(y.size(0));
      for (int32_T j{0}; j < 2; j++) {
        for (int32_T i{0}; i <= m; i++) {
          ycol[i] = y[(idx[i] + y.size(0) * j) - 1];
        }

        for (int32_T i{0}; i <= m; i++) {
          y[i + y.size(0) * j] = ycol[i];
        }
      }
    }

    //
    // Arguments    : ::coder::array<real_T, 2U> &y
    // Return Type  : void
    //
    void sortrows(::coder::array<real_T, 2U> &y)
    {
      ::coder::array<int32_T, 1U> r;
      int32_T col_data[2];
      col_data[0] = 1;
      col_data[1] = 2;
      internal::sortIdx(y, col_data, r);
      apply_row_permutation(y, r);
    }
  }
}

//
// File trailer for sortrows.cpp
//
// [EOF]
//
