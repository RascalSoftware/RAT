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

// Function Declarations
namespace RAT
{
  namespace coder
  {
    static double genpnorm(const ::coder::array<double, 2U> &x);
    static double mat1norm(const ::coder::array<double, 2U> &x);
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    static double genpnorm(const ::coder::array<double, 2U> &x)
    {
      double y;
      int i;
      y = 0.0;
      i = x.size(0) * x.size(1);
      for (int k{0}; k < i; k++) {
        y += std::abs(x[k]);
      }

      return y;
    }

    static double mat1norm(const ::coder::array<double, 2U> &x)
    {
      double y;
      int j;
      boolean_T exitg1;
      y = 0.0;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j <= x.size(1) - 1)) {
        double s;
        int i;
        s = 0.0;
        i = x.size(0);
        for (int b_i{0}; b_i < i; b_i++) {
          s += std::abs(x[b_i + x.size(0) * j]);
        }

        if (std::isnan(s)) {
          y = rtNaN;
          exitg1 = true;
        } else {
          if (s > y) {
            y = s;
          }

          j++;
        }
      }

      return y;
    }

    double b_genpnorm(const ::coder::array<double, 2U> &x)
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

    double b_norm(const ::coder::array<double, 2U> &x)
    {
      double y;
      if ((x.size(0) == 0) || (x.size(1) == 0)) {
        y = 0.0;
      } else if ((x.size(0) == 1) || (x.size(1) == 1)) {
        y = genpnorm(x);
      } else {
        y = mat1norm(x);
      }

      return y;
    }

    double b_norm(const ::coder::array<double, 1U> &x)
    {
      double y;
      int i;
      y = 0.0;
      i = x.size(0);
      for (int k{0}; k < i; k++) {
        y += std::abs(x[k]);
      }

      return y;
    }
  }
}

// End of code generation (norm.cpp)
