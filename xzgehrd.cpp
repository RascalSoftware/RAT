//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzgehrd.cpp
//
// Code generation for function 'xzgehrd'
//

// Include files
#include "xzgehrd.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        void xzgehrd(::coder::array<double, 2U> &a, int ilo, int ihi, ::coder::
                     array<double, 1U> &tau)
        {
          ::coder::array<double, 1U> work;
          double alpha1;
          int n;
          int ntau;
          n = a.size(0);
          if (a.size(0) < 1) {
            ntau = 0;
          } else {
            ntau = a.size(0) - 1;
          }

          tau.set_size(ntau);
          if ((ihi - ilo) + 1 > 1) {
            int b_i;
            for (int i{0}; i <= ilo - 2; i++) {
              tau[i] = 0.0;
            }

            for (int i{ihi}; i <= ntau; i++) {
              tau[i - 1] = 0.0;
            }

            ntau = a.size(0);
            work.set_size(ntau);
            for (b_i = 0; b_i < ntau; b_i++) {
              work[b_i] = 0.0;
            }

            b_i = ihi - 1;
            for (int i{ilo}; i <= b_i; i++) {
              double d;
              int i1;
              int in;
              int u0;
              ntau = (i - 1) * n;
              in = i * n + 1;
              alpha1 = a[i + a.size(0) * (i - 1)];
              i1 = ihi - i;
              u0 = i + 2;
              if (u0 > n) {
                u0 = n;
              }

              d = xzlarfg(i1, &alpha1, a, u0 + ntau);
              tau[i - 1] = d;
              a[i + a.size(0) * (i - 1)] = 1.0;
              ntau = (i + ntau) + 1;
              b_xzlarf(ihi, i1, ntau, d, a, in, n, work);
              xzlarf(i1, n - i, ntau, d, a, i + in, n, work);
              a[i + a.size(0) * (i - 1)] = alpha1;
            }
          }
        }

        void xzgehrd(::coder::array<double, 2U> &a, int ihi, ::coder::array<
                     double, 1U> &tau)
        {
          ::coder::array<double, 1U> work;
          double alpha1;
          int n;
          int ntau;
          n = a.size(0);
          if (a.size(0) < 1) {
            ntau = 0;
          } else {
            ntau = a.size(0) - 1;
          }

          tau.set_size(ntau);
          if (ihi > 1) {
            int b_i;
            for (int i{ihi}; i <= ntau; i++) {
              tau[i - 1] = 0.0;
            }

            ntau = a.size(0);
            work.set_size(ntau);
            for (b_i = 0; b_i < ntau; b_i++) {
              work[b_i] = 0.0;
            }

            for (int i{0}; i <= ihi - 2; i++) {
              double d;
              int in;
              int u0;
              ntau = i * n;
              in = (i + 1) * n;
              alpha1 = a[(i + a.size(0) * i) + 1];
              b_i = (ihi - i) - 1;
              u0 = i + 3;
              if (u0 > n) {
                u0 = n;
              }

              d = xzlarfg(b_i, &alpha1, a, u0 + ntau);
              tau[i] = d;
              a[(i + a.size(0) * i) + 1] = 1.0;
              ntau = (i + ntau) + 2;
              b_xzlarf(ihi, b_i, ntau, d, a, in + 1, n, work);
              xzlarf(b_i, (n - i) - 1, ntau, d, a, (i + in) + 2, n, work);
              a[(i + a.size(0) * i) + 1] = alpha1;
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzgehrd.cpp)
