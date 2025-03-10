//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// colon.cpp
//
// Code generation for function 'colon'
//

// Include files
#include "colon.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static int float_colon_length(double a, double d, double b, double &anew,
      double &bnew, boolean_T &n_too_large);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static int float_colon_length(double a, double d, double b, double &anew,
      double &bnew, boolean_T &n_too_large)
    {
      double cdiff;
      double ndbl;
      int n;
      anew = a;
      ndbl = std::floor((b - a) / d + 0.5);
      bnew = a + ndbl * d;
      if (d > 0.0) {
        cdiff = bnew - b;
      } else {
        cdiff = b - bnew;
      }

      if (std::abs(cdiff) < 4.4408920985006262E-16 * std::fmax(std::abs(a), std::
           abs(b))) {
        ndbl++;
        bnew = b;
      } else if (cdiff > 0.0) {
        bnew = a + (ndbl - 1.0) * d;
      } else {
        ndbl++;
      }

      n_too_large = (ndbl > 2.147483647E+9);
      if (ndbl >= 0.0) {
        n = static_cast<int>(ndbl);
      } else {
        n = 0;
      }

      return n;
    }

    void eml_float_colon(double a, double d, double b, ::coder::array<double, 2U>
                         &y)
    {
      double a1;
      double b1;
      int n;
      boolean_T n_too_large;
      n = float_colon_length(a, d, b, a1, b1, n_too_large);
      y.set_size(1, n);
      if (n > 0) {
        y[0] = a1;
        if (n > 1) {
          double kd;
          int nm1d2;
          y[n - 1] = b1;
          nm1d2 = (n - 1) / 2;
          for (int k{0}; k <= nm1d2 - 2; k++) {
            kd = (static_cast<double>(k) + 1.0) * d;
            y[k + 1] = a1 + kd;
            y[(n - k) - 2] = b1 - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            y[nm1d2] = (a1 + b1) / 2.0;
          } else {
            kd = static_cast<double>(nm1d2) * d;
            y[nm1d2] = a1 + kd;
            y[nm1d2 + 1] = b1 - kd;
          }
        }
      }
    }

    void eml_integer_colon_dispatcher(int b, ::coder::array<int, 2U> &y)
    {
      int n;
      if (b < 1) {
        n = 0;
      } else {
        n = b;
      }

      y.set_size(1, n);
      if (n > 0) {
        int yk;
        y[0] = 1;
        yk = 1;
        for (int k{2}; k <= n; k++) {
          yk++;
          y[k - 1] = yk;
        }
      }
    }
  }
}

// End of code generation (colon.cpp)
