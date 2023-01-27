//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: colon.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "colon.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static void float_colon_length(real_T a, real_T d, real_T b, int32_T *n,
      real_T *anew, real_T *bnew, boolean_T *n_too_large);
  }
}

// Function Definitions
//
// Arguments    : real_T a
//                real_T d
//                real_T b
//                int32_T *n
//                real_T *anew
//                real_T *bnew
//                boolean_T *n_too_large
// Return Type  : void
//
namespace RAT
{
  namespace coder
  {
    static void float_colon_length(real_T a, real_T d, real_T b, int32_T *n,
      real_T *anew, real_T *bnew, boolean_T *n_too_large)
    {
      real_T cdiff;
      real_T ndbl;
      *anew = a;
      ndbl = std::floor((b - a) / d + 0.5);
      *bnew = a + ndbl * d;
      if (d > 0.0) {
        cdiff = *bnew - b;
      } else {
        cdiff = b - *bnew;
      }

      if (std::abs(cdiff) < 4.4408920985006262E-16 * std::fmax(std::abs(a), std::
           abs(b))) {
        ndbl++;
        *bnew = b;
      } else if (cdiff > 0.0) {
        *bnew = a + (ndbl - 1.0) * d;
      } else {
        ndbl++;
      }

      *n_too_large = (ndbl > 2.147483647E+9);
      if (ndbl >= 0.0) {
        *n = static_cast<int32_T>(ndbl);
      } else {
        *n = 0;
      }
    }

    //
    // Arguments    : real_T a
    //                real_T d
    //                real_T b
    //                ::coder::array<real_T, 2U> &y
    // Return Type  : void
    //
    void eml_float_colon(real_T a, real_T d, real_T b, ::coder::array<real_T, 2U>
                         &y)
    {
      real_T a1;
      real_T b1;
      int32_T n;
      boolean_T n_too_large;
      float_colon_length(a, d, b, &n, &a1, &b1, &n_too_large);
      y.set_size(1, n);
      if (n > 0) {
        y[0] = a1;
        if (n > 1) {
          real_T kd;
          int32_T nm1d2;
          y[n - 1] = b1;
          nm1d2 = (n - 1) / 2;
          for (int32_T k{0}; k <= nm1d2 - 2; k++) {
            kd = (static_cast<real_T>(k) + 1.0) * d;
            y[k + 1] = a1 + kd;
            y[(n - k) - 2] = b1 - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            y[nm1d2] = (a1 + b1) / 2.0;
          } else {
            kd = static_cast<real_T>(nm1d2) * d;
            y[nm1d2] = a1 + kd;
            y[nm1d2 + 1] = b1 - kd;
          }
        }
      }
    }
  }
}

//
// File trailer for colon.cpp
//
// [EOF]
//
