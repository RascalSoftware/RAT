//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzsyhetrd.cpp
//
// Code generation for function 'xzsyhetrd'
//

// Include files
#include "xzsyhetrd.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
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
        void xzsyhetrd(::coder::array<double, 2U> &A, ::coder::array<double, 1U>
                       &D, ::coder::array<double, 1U> &E, ::coder::array<double,
                       1U> &tau)
        {
          int n;
          int ntau;
          n = A.size(0) - 1;
          if (A.size(0) < 1) {
            ntau = 0;
          } else {
            ntau = A.size(0) - 1;
          }

          D.set_size(A.size(0));
          E.set_size(ntau);
          tau.set_size(ntau);
          if (A.size(0) > 0) {
            int i;
            i = A.size(0);
            for (int b_i{0}; b_i <= i - 2; b_i++) {
              double taui;
              int b_taui_tmp;
              int taui_tmp;
              int u1;
              E[b_i] = A[(b_i + A.size(0) * b_i) + 1];
              taui_tmp = n - b_i;
              b_taui_tmp = b_i * (n + 1);
              ntau = b_i + 3;
              u1 = n + 1;
              if (ntau <= u1) {
                u1 = ntau;
              }

              taui = xzlarfg(taui_tmp, &E[b_i], A, b_taui_tmp + u1);
              if (taui != 0.0) {
                double tau_tmp;
                double temp1;
                double temp2;
                int i1;
                A[(b_i + A.size(0) * b_i) + 1] = 1.0;
                for (ntau = b_i + 1; ntau <= n; ntau++) {
                  tau[ntau - 1] = 0.0;
                }

                for (int jj{0}; jj < taui_tmp; jj++) {
                  u1 = b_i + jj;
                  temp1 = taui * A[(u1 + A.size(0) * b_i) + 1];
                  temp2 = 0.0;
                  tau[u1] = tau[u1] + temp1 * A[(u1 + A.size(0) * (u1 + 1)) + 1];
                  i1 = jj + 2;
                  for (int ii{i1}; ii <= taui_tmp; ii++) {
                    ntau = b_i + ii;
                    tau_tmp = A[ntau + A.size(0) * (u1 + 1)];
                    tau[ntau - 1] = tau[ntau - 1] + temp1 * tau_tmp;
                    temp2 += tau_tmp * A[ntau + A.size(0) * b_i];
                  }

                  tau[u1] = tau[u1] + taui * temp2;
                }

                ntau = (b_taui_tmp + b_i) + 2;
                blas::xaxpy(taui_tmp, -0.5 * taui * blas::xdotc(taui_tmp, tau,
                  b_i + 1, A, ntau), A, ntau, tau, b_i + 1);
                for (int jj{0}; jj < taui_tmp; jj++) {
                  u1 = b_i + jj;
                  temp1 = A[(u1 + A.size(0) * b_i) + 1];
                  temp2 = tau[u1];
                  tau_tmp = temp2 * temp1;
                  A[(u1 + A.size(0) * (u1 + 1)) + 1] = (A[(u1 + A.size(0) * (u1
                    + 1)) + 1] - tau_tmp) - tau_tmp;
                  i1 = jj + 2;
                  for (int ii{i1}; ii <= taui_tmp; ii++) {
                    ntau = b_i + ii;
                    A[ntau + A.size(0) * (u1 + 1)] = (A[ntau + A.size(0) * (u1 +
                      1)] - tau[ntau - 1] * temp1) - A[ntau + A.size(0) * b_i] *
                      temp2;
                  }
                }
              }

              A[(b_i + A.size(0) * b_i) + 1] = E[b_i];
              D[b_i] = A[b_i + A.size(0) * b_i];
              tau[b_i] = taui;
            }

            D[n] = A[n + A.size(0) * n];
          }
        }
      }
    }
  }
}

// End of code generation (xzsyhetrd.cpp)
