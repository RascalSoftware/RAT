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
        double xzlanhs(const ::coder::array<creal_T, 2U> &A, int ilo, int ihi)
        {
          double f;
          f = 0.0;
          if (ilo <= ihi) {
            double scale;
            double ssq;
            int nm1;
            scale = 3.3121686421112381E-170;
            ssq = 0.0;
            nm1 = ihi - ilo;
            for (int j{0}; j <= nm1; j++) {
              double absxk;
              double colscale;
              double colssq;
              int col;
              int u0;
              colscale = 3.3121686421112381E-170;
              colssq = 0.0;
              col = (ilo + j) - 1;
              u0 = j + 1;
              if (u0 >= nm1) {
                u0 = nm1;
              }

              u0 += ilo;
              for (int row{ilo}; row <= u0; row++) {
                double t;
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
