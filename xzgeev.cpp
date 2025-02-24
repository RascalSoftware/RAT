//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzgeev.cpp
//
// Code generation for function 'xzgeev'
//

// Include files
#include "xzgeev.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xzggev.h"
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
        void xzgeev(const ::coder::array<double, 2U> &A, int *info, ::coder::
                    array<creal_T, 1U> &alpha1, ::coder::array<creal_T, 1U>
                    &beta1, ::coder::array<creal_T, 2U> &V)
        {
          ::coder::array<creal_T, 2U> At;
          int coltop;
          int i;
          int lastcol;
          int n;
          At.set_size(A.size(0), A.size(1));
          n = A.size(1);
          for (i = 0; i < n; i++) {
            lastcol = A.size(0);
            for (coltop = 0; coltop < lastcol; coltop++) {
              At[coltop + At.size(0) * i].re = A[coltop + A.size(0) * i];
              At[coltop + At.size(0) * i].im = 0.0;
            }
          }

          xzggev(At, info, alpha1, beta1, V);
          n = A.size(0);
          if (A.size(0) > 0) {
            lastcol = (A.size(0) - 1) * A.size(0) + 1;
            for (coltop = 1; n < 0 ? coltop >= lastcol : coltop <= lastcol;
                 coltop += n) {
              double colnorm;
              colnorm = blas::xnrm2(n, V, coltop);
              i = (coltop + n) - 1;
              for (int j{coltop}; j <= i; j++) {
                double ai;
                double im;
                double re;
                im = V[j - 1].re;
                ai = V[j - 1].im;
                if (ai == 0.0) {
                  re = im / colnorm;
                  im = 0.0;
                } else if (im == 0.0) {
                  re = 0.0;
                  im = ai / colnorm;
                } else {
                  re = im / colnorm;
                  im = ai / colnorm;
                }

                V[j - 1].re = re;
                V[j - 1].im = im;
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzgeev.cpp)
