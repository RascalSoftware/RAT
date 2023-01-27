//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: reflectivity_calculation_rtwutil.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "reflectivity_calculation_rtwutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<cell_wrap_1, 1U> &r
//                ::coder::array<cell_wrap_14, 1U> &r1
// Return Type  : void
//
namespace RAT
{
  void cast(const ::coder::array<cell_wrap_1, 1U> &r, ::coder::array<
            cell_wrap_14, 1U> &r1)
  {
    int32_T i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size[1];
      r1[i1].f1.set_size(r[i1].f1.size[0], r[i1].f1.size[1]);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = r[i1].f1.size[0];
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1[i3 + r1[i1].f1.size(0) * i2] = r[i1].f1.data[i3 + r[i1].
            f1.size[0] * i2];
        }
      }
    }
  }

  //
  // Arguments    : real_T u0
  //                real_T u1
  // Return Type  : real_T
  //
  real_T rt_hypotd_snf(real_T u0, real_T u1)
  {
    real_T a;
    real_T b;
    real_T y;
    a = std::abs(u0);
    b = std::abs(u1);
    if (a < b) {
      a /= b;
      y = b * std::sqrt(a * a + 1.0);
    } else if (a > b) {
      b /= a;
      y = a * std::sqrt(b * b + 1.0);
    } else if (std::isnan(b)) {
      y = rtNaN;
    } else {
      y = a * 1.4142135623730951;
    }

    return y;
  }
}

//
// File trailer for reflectivity_calculation_rtwutil.cpp
//
// [EOF]
//
