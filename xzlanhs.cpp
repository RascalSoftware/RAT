//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzlanhs.cpp
//
// Code generation for function 'xzlanhs'
//

// Include files
#include "xzlanhs.h"
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
      namespace reflapack
      {
        real_T xzlanhs(const ::coder::array<creal_T, 2U> &A, int32_T ilo,
                       int32_T ihi)
        {
          real_T f;
          f = 0.0;
          if (ilo <= ihi) {
            real_T scale;
            real_T ssq;
            int32_T nm1;
            scale = 3.3121686421112381E-170;
            ssq = 0.0;
            nm1 = ihi - ilo;
            for (int32_T j{0}; j <= nm1; j++) {
              real_T absxk;
              real_T colscale;
              real_T colssq;
              int32_T col;
              int32_T u0;
              colscale = 3.3121686421112381E-170;
              colssq = 0.0;
              col = (ilo + j) - 1;
              u0 = j + 1;
              if (u0 >= nm1) {
                u0 = nm1;
              }

              u0 += ilo;
              for (int32_T row{ilo}; row <= u0; row++) {
                real_T t;
                absxk = std::abs(A[(row + A.size(0) * col) - 1].re);
                if (absxk > colscale) {
                  t = colscale / absxk;
                  colssq = colssq * t * t + 1.0;
                  colscale = absxk;
                } else {
                  t = absxk / colscale;
                  colssq += t * t;
                }

                absxk = std::abs(A[(row + A.size(0) * col) - 1].im);
                if (absxk > colscale) {
                  t = colscale / absxk;
                  colssq = colssq * t * t + 1.0;
                  colscale = absxk;
                } else {
                  t = absxk / colscale;
                  colssq += t * t;
                }
              }

              if (scale >= colscale) {
                absxk = colscale / scale;
                ssq += absxk * absxk * colssq;
              } else {
                absxk = scale / colscale;
                ssq = colssq + absxk * absxk * ssq;
                scale = colscale;
              }
            }

            f = scale * std::sqrt(ssq);
          }

          return f;
        }
      }
    }
  }
}

// End of code generation (xzlanhs.cpp)
