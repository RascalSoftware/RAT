//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// norm.cpp
//
// Code generation for function 'norm'
//

// Include files
#include "norm.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    double genpnorm(const ::coder::array<double, 2U> &x)
    {
      double y;
      y = 0.0;
      if (x.size(1) >= 1) {
        if (x.size(1) == 1) {
          y = std::abs(x[0]);
        } else {
          double scale;
          int kend;
          scale = 3.3121686421112381E-170;
          kend = x.size(1);
          for (int k{0}; k < kend; k++) {
            double absxk;
            absxk = std::abs(x[k]);
            if (absxk > scale) {
              double t;
              t = scale / absxk;
              y = y * t * t + 1.0;
              scale = absxk;
            } else {
              double t;
              t = absxk / scale;
              y += t * t;
            }
          }

          y = scale * std::sqrt(y);
        }
      }

      return y;
    }
  }
}

// End of code generation (norm.cpp)
