//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// linspace.cpp
//
// Code generation for function 'linspace'
//

// Include files
#include "linspace.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void linspace(double d1, double d2, double n, ::coder::array<double, 2U> &y)
    {
      if (!(n >= 0.0)) {
        y.set_size(1, 0);
      } else {
        double delta1;
        delta1 = std::floor(n);
        y.set_size(1, static_cast<int>(delta1));
        if (static_cast<int>(delta1) >= 1) {
          int y_tmp;
          y_tmp = static_cast<int>(delta1) - 1;
          y[static_cast<int>(delta1) - 1] = d2;
          if (y.size(1) >= 2) {
            y[0] = d1;
            if (y.size(1) >= 3) {
              if (d1 == -d2) {
                delta1 = d2 / (static_cast<double>(y.size(1)) - 1.0);
                for (int k{2}; k <= y_tmp; k++) {
                  y[k - 1] = static_cast<double>(((k << 1) - y.size(1)) - 1) *
                    delta1;
                }

                if ((y.size(1) & 1) == 1) {
                  y[y.size(1) >> 1] = 0.0;
                }
              } else if (((d1 < 0.0) != (d2 < 0.0)) && ((std::abs(d1) >
                           8.9884656743115785E+307) || (std::abs(d2) >
                           8.9884656743115785E+307))) {
                double delta2;
                delta1 = d1 / (static_cast<double>(y.size(1)) - 1.0);
                delta2 = d2 / (static_cast<double>(y.size(1)) - 1.0);
                y_tmp = y.size(1);
                for (int k{0}; k <= y_tmp - 3; k++) {
                  y[k + 1] = (d1 + delta2 * (static_cast<double>(k) + 1.0)) -
                    delta1 * (static_cast<double>(k) + 1.0);
                }
              } else {
                delta1 = (d2 - d1) / (static_cast<double>(y.size(1)) - 1.0);
                y_tmp = y.size(1);
                for (int k{0}; k <= y_tmp - 3; k++) {
                  y[k + 1] = d1 + (static_cast<double>(k) + 1.0) * delta1;
                }
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (linspace.cpp)
