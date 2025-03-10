//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzgebal.cpp
//
// Code generation for function 'xzgebal'
//

// Include files
#include "xzgebal.h"
#include "ixamax.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xswap.h"
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
        int xzgebal(::coder::array<double, 2U> &A, ::coder::array<double, 1U>
                    &scale, int &ihi)
        {
          int b_k;
          int ilo;
          int k;
          int n;
          int r_tmp;
          boolean_T converged;
          boolean_T notdone;
          n = A.size(0);
          k = A.size(0);
          scale.set_size(k);
          for (r_tmp = 0; r_tmp < k; r_tmp++) {
            scale[r_tmp] = 1.0;
          }

          b_k = 0;
          ihi = A.size(0);
          converged = (A.size(0) == 0);
          notdone = (A.size(1) == 0);
          if (converged || notdone) {
            ilo = 1;
            ihi = n;
          } else {
            int exitg5;
            int i;
            notdone = true;
            do {
              exitg5 = 0;
              if (notdone) {
                int exitg4;
                notdone = false;
                k = ihi;
                do {
                  exitg4 = 0;
                  if (k > 0) {
                    boolean_T exitg6;
                    converged = false;
                    i = 0;
                    exitg6 = false;
                    while ((!exitg6) && (i <= ihi - 1)) {
                      if ((i + 1 == k) || (!(A[(k + A.size(0) * i) - 1] != 0.0)))
                      {
                        i++;
                      } else {
                        converged = true;
                        exitg6 = true;
                      }
                    }

                    if (converged) {
                      k--;
                    } else {
                      scale[ihi - 1] = k;
                      if (k != ihi) {
                        blas::xswap(ihi, A, (k - 1) * n + 1, (ihi - 1) * n + 1);
                        blas::xswap(n, A, k, n, ihi, n);
                      }

                      exitg4 = 1;
                    }
                  } else {
                    exitg4 = 2;
                  }
                } while (exitg4 == 0);

                if (exitg4 == 1) {
                  if (ihi == 1) {
                    ilo = 1;
                    ihi = 1;
                    exitg5 = 1;
                  } else {
                    ihi--;
                    notdone = true;
                  }
                }
              } else {
                notdone = true;
                while (notdone) {
                  boolean_T exitg6;
                  notdone = false;
                  k = b_k + 1;
                  exitg6 = false;
                  while ((!exitg6) && (k <= ihi)) {
                    boolean_T exitg7;
                    converged = false;
                    i = b_k;
                    exitg7 = false;
                    while ((!exitg7) && (i + 1 <= ihi)) {
                      if ((i + 1 == k) || (!(A[i + A.size(0) * (k - 1)] != 0.0)))
                      {
                        i++;
                      } else {
                        converged = true;
                        exitg7 = true;
                      }
                    }

                    if (converged) {
                      k++;
                    } else {
                      scale[b_k] = k;
                      if (k != b_k + 1) {
                        r_tmp = b_k * n;
                        blas::xswap(ihi, A, (k - 1) * n + 1, r_tmp + 1);
                        blas::xswap(n - b_k, A, r_tmp + k, n, (r_tmp + b_k) + 1,
                                    n);
                      }

                      b_k++;
                      notdone = true;
                      exitg6 = true;
                    }
                  }
                }

                ilo = b_k + 1;
                converged = false;
                exitg5 = 2;
              }
            } while (exitg5 == 0);

            if (exitg5 != 1) {
              boolean_T exitg3;
              exitg3 = false;
              while ((!exitg3) && (!converged)) {
                int exitg2;
                converged = true;
                i = b_k;
                do {
                  exitg2 = 0;
                  if (i + 1 <= ihi) {
                    double c;
                    double ca;
                    double r;
                    double ra;
                    int c_tmp;
                    k = ihi - b_k;
                    c_tmp = i * n;
                    c = blas::xnrm2(k, A, (c_tmp + b_k) + 1);
                    r_tmp = (b_k * n + i) + 1;
                    r = blas::xnrm2(k, A, r_tmp, n);
                    ca = std::abs(A[(blas::ixamax(ihi, A, c_tmp + 1) + A.size(0)
                                     * i) - 1]);
                    k = n - b_k;
                    ra = std::abs(A[i + A.size(0) * ((blas::ixamax(k, A, r_tmp,
                      n) + b_k) - 1)]);
                    if ((c == 0.0) || (r == 0.0)) {
                      i++;
                    } else {
                      double f;
                      double g;
                      double s;
                      int exitg1;
                      g = r / 2.0;
                      f = 1.0;
                      s = c + r;
                      do {
                        exitg1 = 0;
                        if ((c < g) && (std::fmax(f, std::fmax(c, ca)) <
                                        4.9896007738368E+291) && (std::fmin(r,
                              std::fmin(g, ra)) > 2.0041683600089728E-292)) {
                          if (std::isnan(((((c + f) + ca) + r) + g) + ra)) {
                            exitg1 = 1;
                          } else {
                            f *= 2.0;
                            c *= 2.0;
                            ca *= 2.0;
                            r /= 2.0;
                            g /= 2.0;
                            ra /= 2.0;
                          }
                        } else {
                          g = c / 2.0;
                          while ((g >= r) && (std::fmax(r, ra) <
                                              4.9896007738368E+291) && (std::
                                  fmin(std::fmin(f, c), std::fmin(g, ca)) >
                                  2.0041683600089728E-292)) {
                            f /= 2.0;
                            c /= 2.0;
                            g /= 2.0;
                            ca /= 2.0;
                            r *= 2.0;
                            ra *= 2.0;
                          }

                          if ((!(c + r >= 0.95 * s)) && ((!(f < 1.0)) ||
                               (!(scale[i] < 1.0)) || (!(f * scale[i] <=
                                 1.0020841800044864E-292))) && ((!(f > 1.0)) ||
                               (!(scale[i] > 1.0)) || (!(scale[i] >=
                                 9.9792015476736E+291 / f)))) {
                            scale[i] = scale[i] * f;
                            blas::xscal(k, 1.0 / f, A, r_tmp, n);
                            r_tmp = c_tmp + ihi;
                            for (k = c_tmp + 1; k <= r_tmp; k++) {
                              A[k - 1] = f * A[k - 1];
                            }

                            converged = false;
                          }

                          exitg1 = 2;
                        }
                      } while (exitg1 == 0);

                      if (exitg1 == 1) {
                        exitg2 = 2;
                      } else {
                        i++;
                      }
                    }
                  } else {
                    exitg2 = 1;
                  }
                } while (exitg2 == 0);

                if (exitg2 != 1) {
                  exitg3 = true;
                }
              }
            }
          }

          return ilo;
        }
      }
    }
  }
}

// End of code generation (xzgebal.cpp)
