//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// erfinv.cpp
//
// Code generation for function 'erfinv'
//

// Include files
#include "erfinv.h"
#include "eml_erfcore.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    double erfinv(double y)
    {
      double x;
      if ((y > 1.0) || (y < -1.0) || std::isnan(y)) {
        x = rtNaN;
      } else if (y == 1.0) {
        x = rtInf;
      } else if (y == -1.0) {
        x = rtMinusInf;
      } else {
        double z;
        if (y < -0.7) {
          z = std::sqrt(-std::log((y + 1.0) / 2.0));
          x = -(((1.641345311 * z + 3.429567803) * z - 1.624906493) * z -
                1.970840454) / ((1.6370678 * z + 3.5438892) * z + 1.0);
        } else if (y > 0.7) {
          z = std::sqrt(-std::log((1.0 - y) / 2.0));
          x = (((1.641345311 * z + 3.429567803) * z - 1.624906493) * z -
               1.970840454) / ((1.6370678 * z + 3.5438892) * z + 1.0);
        } else {
          z = y * y;
          x = y * (((-0.140543331 * z + 0.914624893) * z - 1.645349621) * z +
                   0.886226899) / ((((0.012229801 * z - 0.329097515) * z +
            1.442710462) * z - 2.118377725) * z + 1.0);
        }

        if (y > 0.5) {
          z = -(eml_erfcore(x) - (1.0 - y)) / (1.1283791670955126 * std::exp(-x *
            x));
          x -= z / (x * z + 1.0);
          z = -(eml_erfcore(x) - (1.0 - y)) / (1.1283791670955126 * std::exp(-x *
            x));
          x -= z / (x * z + 1.0);
        } else if (y < -0.5) {
          z = (eml_erfcore(-x) - (y + 1.0)) / (1.1283791670955126 * std::exp(-x *
            x));
          x -= z / (x * z + 1.0);
          z = (eml_erfcore(-x) - (y + 1.0)) / (1.1283791670955126 * std::exp(-x *
            x));
          x -= z / (x * z + 1.0);
        } else {
          z = (b_eml_erfcore(x) - y) / (1.1283791670955126 * std::exp(-x * x));
          x -= z / (x * z + 1.0);
          z = (b_eml_erfcore(x) - y) / (1.1283791670955126 * std::exp(-x * x));
          x -= z / (x * z + 1.0);
        }
      }

      return x;
    }
  }
}

// End of code generation (erfinv.cpp)
