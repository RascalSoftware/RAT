//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xsyheev.cpp
//
// Code generation for function 'xsyheev'
//

// Include files
#include "xsyheev.h"
#include "rt_nonfinite.h"
#include "xzlascl.h"
#include "xzsteqr.h"
#include "xzsyheev.h"
#include "xzsyhetrd.h"
#include "xzunorgtr.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace lapack
      {
        int xsyheev(::coder::array<double, 2U> &A, ::coder::array<double, 1U> &W)
        {
          ::coder::array<double, 1U> e;
          ::coder::array<double, 1U> tau;
          int info;
          int n;
          info = 0;
          n = A.size(0);
          W.set_size(A.size(0));
          if (A.size(0) != 0) {
            if (A.size(0) == 1) {
              W[0] = A[0];
              A[0] = 1.0;
            } else {
              double anrm;
              anrm = reflapack::computeNormM(A);
              if (std::isinf(anrm) || std::isnan(anrm)) {
                int k;
                n = W.size(0);
                W.set_size(n);
                for (int i{0}; i < n; i++) {
                  W[i] = rtNaN;
                }

                n = A.size(0);
                k = A.size(1);
                A.set_size(n, k);
                for (int i{0}; i < k; i++) {
                  for (int i1{0}; i1 < n; i1++) {
                    A[i1 + A.size(0) * i] = rtNaN;
                  }
                }
              } else {
                boolean_T iscale;
                iscale = false;
                if ((anrm > 0.0) && (anrm < 1.0010415475915505E-146)) {
                  iscale = true;
                  anrm = 1.0010415475915505E-146 / anrm;
                  reflapack::xzlascl(1.0, anrm, A.size(0), A.size(0), A, A.size
                                     (0));
                } else if (anrm > 9.9895953610111751E+145) {
                  iscale = true;
                  anrm = 9.9895953610111751E+145 / anrm;
                  reflapack::xzlascl(1.0, anrm, A.size(0), A.size(0), A, A.size
                                     (0));
                }

                reflapack::xzsyhetrd(A, W, e, tau);
                reflapack::xzunorgtr(A, tau);
                info = reflapack::xzsteqr(W, e, A);
                if (info != 0) {
                  int k;
                  n = W.size(0);
                  W.set_size(n);
                  for (int i{0}; i < n; i++) {
                    W[i] = rtNaN;
                  }

                  n = A.size(0);
                  k = A.size(1);
                  A.set_size(n, k);
                  for (int i{0}; i < k; i++) {
                    for (int i1{0}; i1 < n; i1++) {
                      A[i1 + A.size(0) * i] = rtNaN;
                    }
                  }
                } else if (iscale) {
                  anrm = 1.0 / anrm;
                  for (int k{0}; k < n; k++) {
                    W[k] = anrm * W[k];
                  }
                }
              }
            }
          }

          return info;
        }
      }
    }
  }
}

// End of code generation (xsyheev.cpp)
