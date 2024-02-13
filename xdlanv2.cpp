//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xdlanv2.cpp
//
// Code generation for function 'xdlanv2'
//

// Include files
#include "xdlanv2.h"
#include "RATMain_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        void xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1r,
                     real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs,
                     real_T *sn)
        {
          if (*c == 0.0) {
            *cs = 1.0;
            *sn = 0.0;
          } else if (*b == 0.0) {
            real_T temp;
            *cs = 0.0;
            *sn = 1.0;
            temp = *d;
            *d = *a;
            *a = temp;
            *b = -*c;
            *c = 0.0;
          } else {
            real_T temp;
            temp = *a - *d;
            if ((temp == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
              *cs = 1.0;
              *sn = 0.0;
            } else {
              real_T bcmax;
              real_T bcmis;
              real_T p;
              real_T scale;
              real_T z;
              int32_T b_c;
              int32_T count;
              p = 0.5 * temp;
              bcmis = std::abs(*b);
              scale = std::abs(*c);
              bcmax = std::fmax(bcmis, scale);
              if (!(*b < 0.0)) {
                count = 1;
              } else {
                count = -1;
              }

              if (!(*c < 0.0)) {
                b_c = 1;
              } else {
                b_c = -1;
              }

              bcmis = std::fmin(bcmis, scale) * static_cast<real_T>(count) *
                static_cast<real_T>(b_c);
              scale = std::fmax(std::abs(p), bcmax);
              z = p / scale * p + bcmax / scale * bcmis;
              if (z >= 8.8817841970012523E-16) {
                real_T tau;
                *a = std::sqrt(scale) * std::sqrt(z);
                if (p < 0.0) {
                  *a = -*a;
                }

                z = p + *a;
                *a = *d + z;
                *d -= bcmax / z * bcmis;
                tau = rt_hypotd_snf(*c, z);
                *cs = z / tau;
                *sn = *c / tau;
                *b -= *c;
                *c = 0.0;
              } else {
                real_T tau;
                bcmis = *b + *c;
                scale = std::fmax(std::abs(temp), std::abs(bcmis));
                count = 0;
                while ((scale >= 7.4428285367870146E+137) && (count <= 20)) {
                  bcmis *= 1.3435752215134178E-138;
                  temp *= 1.3435752215134178E-138;
                  scale = std::fmax(std::abs(temp), std::abs(bcmis));
                  count++;
                }

                while ((scale <= 1.3435752215134178E-138) && (count <= 20)) {
                  bcmis *= 7.4428285367870146E+137;
                  temp *= 7.4428285367870146E+137;
                  scale = std::fmax(std::abs(temp), std::abs(bcmis));
                  count++;
                }

                tau = rt_hypotd_snf(bcmis, temp);
                *cs = std::sqrt(0.5 * (std::abs(bcmis) / tau + 1.0));
                if (!(bcmis < 0.0)) {
                  count = 1;
                } else {
                  count = -1;
                }

                *sn = -(0.5 * temp / (tau * *cs)) * static_cast<real_T>(count);
                bcmax = *a * *cs + *b * *sn;
                scale = -*a * *sn + *b * *cs;
                z = *c * *cs + *d * *sn;
                bcmis = -*c * *sn + *d * *cs;
                *b = scale * *cs + bcmis * *sn;
                *c = -bcmax * *sn + z * *cs;
                temp = 0.5 * ((bcmax * *cs + z * *sn) + (-scale * *sn + bcmis * *
                  cs));
                *a = temp;
                *d = temp;
                if (*c != 0.0) {
                  if (*b != 0.0) {
                    if ((*b < 0.0) == (*c < 0.0)) {
                      bcmis = std::sqrt(std::abs(*b));
                      scale = std::sqrt(std::abs(*c));
                      *a = bcmis * scale;
                      if (!(*c < 0.0)) {
                        p = *a;
                      } else {
                        p = -*a;
                      }

                      tau = 1.0 / std::sqrt(std::abs(*b + *c));
                      *a = temp + p;
                      *d = temp - p;
                      *b -= *c;
                      *c = 0.0;
                      bcmax = bcmis * tau;
                      bcmis = scale * tau;
                      temp = *cs * bcmax - *sn * bcmis;
                      *sn = *cs * bcmis + *sn * bcmax;
                      *cs = temp;
                    }
                  } else {
                    *b = -*c;
                    *c = 0.0;
                    temp = *cs;
                    *cs = -*sn;
                    *sn = temp;
                  }
                }
              }
            }
          }

          *rt1r = *a;
          *rt2r = *d;
          if (*c == 0.0) {
            *rt1i = 0.0;
            *rt2i = 0.0;
          } else {
            *rt1i = std::sqrt(std::abs(*b)) * std::sqrt(std::abs(*c));
            *rt2i = -*rt1i;
          }
        }
      }
    }
  }
}

// End of code generation (xdlanv2.cpp)
