//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xnrm2.cpp
//
// Code generation for function 'xnrm2'
//

// Include files
#include "xnrm2.h"
#include "RATMain_rtwutil.h"
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
        real_T b_xnrm2(int32_T n, const ::coder::array<real_T, 1U> &x)
        {
          real_T scale;
          real_T y;
          y = 0.0;
          scale = 3.3121686421112381E-170;
          for (int32_T k{0}; k < n; k++) {
            real_T absxk;
            absxk = std::abs(x[k]);
            if (absxk > scale) {
              real_T t;
              t = scale / absxk;
              y = y * t * t + 1.0;
              scale = absxk;
            } else {
              real_T t;
              t = absxk / scale;
              y += t * t;
            }
          }

          return scale * std::sqrt(y);
        }

        real_T xnrm2(int32_T n, const ::coder::array<real_T, 1U> &x)
        {
          real_T y;
          y = 0.0;
          if (n >= 1) {
            if (n == 1) {
              y = std::abs(x[1]);
            } else {
              real_T scale;
              int32_T kend;
              scale = 3.3121686421112381E-170;
              kend = n + 1;
              for (int32_T k{2}; k <= kend; k++) {
                real_T absxk;
                absxk = std::abs(x[k - 1]);
                if (absxk > scale) {
                  real_T t;
                  t = scale / absxk;
                  y = y * t * t + 1.0;
                  scale = absxk;
                } else {
                  real_T t;
                  t = absxk / scale;
                  y += t * t;
                }
              }

              y = scale * std::sqrt(y);
            }
          }

          return y;
        }

        real_T xnrm2(int32_T n, const ::coder::array<creal_T, 2U> &x, int32_T
                     ix0)
        {
          real_T y;
          y = 0.0;
          if (n == 1) {
            y = rt_hypotd_snf(x[ix0 - 1].re, x[ix0 - 1].im);
          } else {
            real_T scale;
            int32_T kend;
            scale = 3.3121686421112381E-170;
            kend = (ix0 + n) - 1;
            for (int32_T k{ix0}; k <= kend; k++) {
              real_T absxk;
              real_T t;
              absxk = std::abs(x[k - 1].re);
              if (absxk > scale) {
                t = scale / absxk;
                y = y * t * t + 1.0;
                scale = absxk;
              } else {
                t = absxk / scale;
                y += t * t;
              }

              absxk = std::abs(x[k - 1].im);
              if (absxk > scale) {
                t = scale / absxk;
                y = y * t * t + 1.0;
                scale = absxk;
              } else {
                t = absxk / scale;
                y += t * t;
              }
            }

            y = scale * std::sqrt(y);
          }

          return y;
        }

        real_T xnrm2(int32_T n, const ::coder::array<real_T, 2U> &x, int32_T ix0)
        {
          real_T y;
          y = 0.0;
          if (n >= 1) {
            if (n == 1) {
              y = std::abs(x[ix0 - 1]);
            } else {
              real_T scale;
              int32_T kend;
              scale = 3.3121686421112381E-170;
              kend = (ix0 + n) - 1;
              for (int32_T k{ix0}; k <= kend; k++) {
                real_T absxk;
                absxk = std::abs(x[k - 1]);
                if (absxk > scale) {
                  real_T t;
                  t = scale / absxk;
                  y = y * t * t + 1.0;
                  scale = absxk;
                } else {
                  real_T t;
                  t = absxk / scale;
                  y += t * t;
                }
              }

              y = scale * std::sqrt(y);
            }
          }

          return y;
        }

        real_T xnrm2(int32_T n, const real_T x[3])
        {
          real_T y;
          y = 0.0;
          if (n >= 1) {
            if (n == 1) {
              y = std::abs(x[1]);
            } else {
              real_T absxk;
              real_T scale;
              real_T t;
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
      }
    }
  }
}

// End of code generation (xnrm2.cpp)
