//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xnrm2.cpp
//
// Code generation for function 'xnrm2'
//

// Include files
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace blas
      {
        double b_xnrm2(int n, const ::coder::array<double, 1U> &x)
        {
          double y;
          y = 0.0;
          if (n >= 1) {
            if (n == 1) {
              y = std::abs(x[1]);
            } else {
              double scale;
              int kend;
              scale = 3.3121686421112381E-170;
              kend = n + 1;
              for (int k{2}; k <= kend; k++) {
                double absxk;
                absxk = std::abs(x[k - 1]);
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

        double xnrm2(int n, const ::coder::array<double, 2U> &x)
        {
          double y;
          y = 0.0;
          if (n >= 1) {
            if (n == 1) {
              y = std::abs(x[0]);
            } else {
              double scale;
              scale = 3.3121686421112381E-170;
              for (int k{0}; k < n; k++) {
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

        double xnrm2(int n, const ::coder::array<double, 2U> &x, int ix0, int
                     incx)
        {
          double y;
          y = 0.0;
          if ((n >= 1) && (incx >= 1)) {
            if (n == 1) {
              y = std::abs(x[ix0 - 1]);
            } else {
              double scale;
              int kend;
              scale = 3.3121686421112381E-170;
              kend = ix0 + (n - 1) * incx;
              for (int k{ix0}; incx < 0 ? k >= kend : k <= kend; k += incx) {
                double absxk;
                absxk = std::abs(x[k - 1]);
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

        double xnrm2(int n, const double x[3])
        {
          double y;
          y = 0.0;
          if (n >= 1) {
            if (n == 1) {
              y = std::abs(x[1]);
            } else {
              double absxk;
              double scale;
              double t;
              scale = 3.3121686421112381E-170;
              absxk = std::abs(x[1]);
              if (absxk > 3.3121686421112381E-170) {
                y = 1.0;
                scale = absxk;
              } else {
                t = absxk / 3.3121686421112381E-170;
                y = t * t;
              }

              absxk = std::abs(x[2]);
              if (absxk > scale) {
                t = scale / absxk;
                y = y * t * t + 1.0;
                scale = absxk;
              } else {
                t = absxk / scale;
                y += t * t;
              }

              y = scale * std::sqrt(y);
            }
          }

          return y;
        }

        double xnrm2(int n, const ::coder::array<double, 2U> &x, int ix0)
        {
          double y;
          y = 0.0;
          if (n >= 1) {
            if (n == 1) {
              y = std::abs(x[ix0 - 1]);
            } else {
              double scale;
              int kend;
              scale = 3.3121686421112381E-170;
              kend = (ix0 + n) - 1;
              for (int k{ix0}; k <= kend; k++) {
                double absxk;
                absxk = std::abs(x[k - 1]);
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

        double xnrm2(int n, const ::coder::array<double, 1U> &x)
        {
          double scale;
          double y;
          y = 0.0;
          scale = 3.3121686421112381E-170;
          for (int k{0}; k < n; k++) {
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

          return scale * std::sqrt(y);
        }
      }
    }
  }
}

// End of code generation (xnrm2.cpp)
