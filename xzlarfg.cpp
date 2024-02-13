//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzlarfg.cpp
//
// Code generation for function 'xzlarfg'
//

// Include files
#include "xzlarfg.h"
#include "RATMain_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
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
        real_T xzlarfg(int32_T n, real_T *alpha1, ::coder::array<real_T, 1U> &x)
        {
          real_T tau;
          tau = 0.0;
          if (n > 0) {
            real_T xnorm;
            xnorm = blas::xnrm2(n - 1, x);
            if (xnorm != 0.0) {
              real_T beta1;
              beta1 = rt_hypotd_snf(*alpha1, xnorm);
              if (*alpha1 >= 0.0) {
                beta1 = -beta1;
              }

              if (std::abs(beta1) < 1.0020841800044864E-292) {
                int32_T k;
                int32_T knt;
                knt = 0;
                do {
                  knt++;
                  for (k = 2; k <= n; k++) {
                    x[k - 1] = 9.9792015476736E+291 * x[k - 1];
                  }

                  beta1 *= 9.9792015476736E+291;
                  *alpha1 *= 9.9792015476736E+291;
                } while ((std::abs(beta1) < 1.0020841800044864E-292) && (knt <
                          20));

                beta1 = rt_hypotd_snf(*alpha1, blas::xnrm2(n - 1, x));
                if (*alpha1 >= 0.0) {
                  beta1 = -beta1;
                }

                tau = (beta1 - *alpha1) / beta1;
                xnorm = 1.0 / (*alpha1 - beta1);
                for (k = 2; k <= n; k++) {
                  x[k - 1] = xnorm * x[k - 1];
                }

                for (k = 0; k < knt; k++) {
                  beta1 *= 1.0020841800044864E-292;
                }

                *alpha1 = beta1;
              } else {
                tau = (beta1 - *alpha1) / beta1;
                xnorm = 1.0 / (*alpha1 - beta1);
                for (int32_T k{2}; k <= n; k++) {
                  x[k - 1] = xnorm * x[k - 1];
                }

                *alpha1 = beta1;
              }
            }
          }

          return tau;
        }

        real_T xzlarfg(int32_T n, real_T *alpha1, ::coder::array<real_T, 2U> &x,
                       int32_T ix0)
        {
          real_T tau;
          tau = 0.0;
          if (n > 0) {
            real_T xnorm;
            xnorm = blas::xnrm2(n - 1, x, ix0);
            if (xnorm != 0.0) {
              real_T beta1;
              beta1 = rt_hypotd_snf(*alpha1, xnorm);
              if (*alpha1 >= 0.0) {
                beta1 = -beta1;
              }

              if (std::abs(beta1) < 1.0020841800044864E-292) {
                int32_T i;
                int32_T k;
                int32_T knt;
                knt = 0;
                i = (ix0 + n) - 2;
                do {
                  knt++;
                  for (k = ix0; k <= i; k++) {
                    x[k - 1] = 9.9792015476736E+291 * x[k - 1];
                  }

                  beta1 *= 9.9792015476736E+291;
                  *alpha1 *= 9.9792015476736E+291;
                } while ((std::abs(beta1) < 1.0020841800044864E-292) && (knt <
                          20));

                beta1 = rt_hypotd_snf(*alpha1, blas::xnrm2(n - 1, x, ix0));
                if (*alpha1 >= 0.0) {
                  beta1 = -beta1;
                }

                tau = (beta1 - *alpha1) / beta1;
                xnorm = 1.0 / (*alpha1 - beta1);
                for (k = ix0; k <= i; k++) {
                  x[k - 1] = xnorm * x[k - 1];
                }

                for (k = 0; k < knt; k++) {
                  beta1 *= 1.0020841800044864E-292;
                }

                *alpha1 = beta1;
              } else {
                int32_T i;
                tau = (beta1 - *alpha1) / beta1;
                xnorm = 1.0 / (*alpha1 - beta1);
                i = (ix0 + n) - 2;
                for (int32_T k{ix0}; k <= i; k++) {
                  x[k - 1] = xnorm * x[k - 1];
                }

                *alpha1 = beta1;
              }
            }
          }

          return tau;
        }

        real_T xzlarfg(int32_T n, real_T *alpha1, real_T x[3])
        {
          real_T tau;
          tau = 0.0;
          if (n > 0) {
            real_T xnorm;
            xnorm = blas::xnrm2(n - 1, x);
            if (xnorm != 0.0) {
              real_T beta1;
              beta1 = rt_hypotd_snf(*alpha1, xnorm);
              if (*alpha1 >= 0.0) {
                beta1 = -beta1;
              }

              if (std::abs(beta1) < 1.0020841800044864E-292) {
                int32_T k;
                int32_T knt;
                knt = 0;
                do {
                  knt++;
                  for (k = 2; k <= n; k++) {
                    x[k - 1] *= 9.9792015476736E+291;
                  }

                  beta1 *= 9.9792015476736E+291;
                  *alpha1 *= 9.9792015476736E+291;
                } while ((std::abs(beta1) < 1.0020841800044864E-292) && (knt <
                          20));

                beta1 = rt_hypotd_snf(*alpha1, blas::xnrm2(n - 1, x));
                if (*alpha1 >= 0.0) {
                  beta1 = -beta1;
                }

                tau = (beta1 - *alpha1) / beta1;
                xnorm = 1.0 / (*alpha1 - beta1);
                for (k = 2; k <= n; k++) {
                  x[k - 1] *= xnorm;
                }

                for (k = 0; k < knt; k++) {
                  beta1 *= 1.0020841800044864E-292;
                }

                *alpha1 = beta1;
              } else {
                tau = (beta1 - *alpha1) / beta1;
                xnorm = 1.0 / (*alpha1 - beta1);
                for (int32_T k{2}; k <= n; k++) {
                  x[k - 1] *= xnorm;
                }

                *alpha1 = beta1;
              }
            }
          }

          return tau;
        }
      }
    }
  }
}

// End of code generation (xzlarfg.cpp)
