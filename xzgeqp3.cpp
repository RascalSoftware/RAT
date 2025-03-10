//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzgeqp3.cpp
//
// Code generation for function 'xzgeqp3'
//

// Include files
#include "xzgeqp3.h"
#include "ixamax.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xswap.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        static int qrpf(::coder::array<double, 1U> &A, int m, double tau_data[]);
        static void qrpf(::coder::array<double, 2U> &A, int n, double tau_data[],
                         ::coder::array<int, 2U> &jpvt);
      }
    }
  }
}

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        static int qrpf(::coder::array<double, 1U> &A, int m, double tau_data[])
        {
          double atmp;
          int jpvt;
          int y;
          jpvt = 1;
          if (m <= 1) {
            y = m;
          } else {
            y = 1;
          }

          y = static_cast<unsigned char>(y);
          for (int i{0}; i < y; i++) {
            if (m > 1) {
              atmp = A[0];
              tau_data[0] = xzlarfg(m, atmp, A);
              A[0] = atmp;
            } else {
              tau_data[0] = 0.0;
            }
          }

          return jpvt;
        }

        static void qrpf(::coder::array<double, 2U> &A, int n, double tau_data[],
                         ::coder::array<int, 2U> &jpvt)
        {
          ::coder::array<double, 1U> vn1;
          int itemp;
          int pvt;
          pvt = A.size(1);
          vn1.set_size(pvt);
          for (itemp = 0; itemp < pvt; itemp++) {
            vn1[itemp] = 0.0;
          }

          for (pvt = 0; pvt < n; pvt++) {
            vn1[pvt] = std::abs(A[pvt]);
          }

          tau_data[0] = 0.0;
          pvt = blas::ixamax(n, vn1, 1) - 1;
          if (pvt + 1 != 1) {
            blas::xswap(A, pvt + 1);
            itemp = jpvt[pvt];
            jpvt[pvt] = jpvt[0];
            jpvt[0] = itemp;
          }
        }

        void qrpf(::coder::array<double, 2U> &A, int m, int n, ::coder::array<
                  double, 1U> &tau, ::coder::array<int, 2U> &jpvt)
        {
          ::coder::array<double, 1U> vn1;
          ::coder::array<double, 1U> vn2;
          ::coder::array<double, 1U> work;
          double d;
          double temp1;
          int itemp;
          int j;
          int ma;
          int minmn;
          ma = A.size(0);
          if (m <= n) {
            minmn = m;
          } else {
            minmn = n;
          }

          itemp = A.size(1);
          work.set_size(itemp);
          vn1.set_size(A.size(1));
          vn2.set_size(A.size(1));
          for (j = 0; j < itemp; j++) {
            work[j] = 0.0;
            vn1[j] = 0.0;
            vn2[j] = 0.0;
          }

          for (j = 0; j < n; j++) {
            d = blas::xnrm2(m, A, j * ma + 1);
            vn1[j] = d;
            vn2[j] = d;
          }

          for (int i{0}; i < minmn; i++) {
            int ii;
            int ip1;
            int mmi;
            int nmi;
            int pvt;
            ip1 = i + 2;
            j = i * ma;
            ii = j + i;
            nmi = n - i;
            mmi = m - i;
            pvt = (i + blas::ixamax(nmi, vn1, i + 1)) - 1;
            if (pvt + 1 != i + 1) {
              blas::xswap(m, A, pvt * ma + 1, j + 1);
              itemp = jpvt[pvt];
              jpvt[pvt] = jpvt[i];
              jpvt[i] = itemp;
              vn1[pvt] = vn1[i];
              vn2[pvt] = vn2[i];
            }

            if (i + 1 < m) {
              temp1 = A[ii];
              d = xzlarfg(mmi, &temp1, A, ii + 2);
              tau[i] = d;
              A[ii] = temp1;
            } else {
              d = 0.0;
              tau[i] = 0.0;
            }

            if (i + 1 < n) {
              temp1 = A[ii];
              A[ii] = 1.0;
              xzlarf(mmi, nmi - 1, ii + 1, d, A, (ii + ma) + 1, ma, work);
              A[ii] = temp1;
            }

            for (j = ip1; j <= n; j++) {
              itemp = i + (j - 1) * ma;
              d = vn1[j - 1];
              if (d != 0.0) {
                double temp2;
                temp1 = std::abs(A[itemp]) / d;
                temp1 = 1.0 - temp1 * temp1;
                if (temp1 < 0.0) {
                  temp1 = 0.0;
                }

                temp2 = d / vn2[j - 1];
                temp2 = temp1 * (temp2 * temp2);
                if (temp2 <= 1.4901161193847656E-8) {
                  if (i + 1 < m) {
                    d = blas::xnrm2(mmi - 1, A, itemp + 2);
                    vn1[j - 1] = d;
                    vn2[j - 1] = d;
                  } else {
                    vn1[j - 1] = 0.0;
                    vn2[j - 1] = 0.0;
                  }
                } else {
                  vn1[j - 1] = d * std::sqrt(temp1);
                }
              }
            }
          }
        }

        int xzgeqp3(::coder::array<double, 1U> &A, int m, double tau_data[], int
                    &jpvt)
        {
          int tau_size;
          tau_size = A.size(0);
          if (tau_size > 1) {
            tau_size = 1;
          }

          if (tau_size - 1 >= 0) {
            tau_data[0] = 0.0;
          }

          if (A.size(0) == 0) {
            jpvt = 1;
          } else {
            int y;
            if (m <= 1) {
              y = m;
            } else {
              y = 1;
            }

            if (y < 1) {
              jpvt = 1;
            } else {
              qrpf(A, m, tau_data);
              jpvt = 1;
            }
          }

          return tau_size;
        }

        int xzgeqp3(::coder::array<double, 2U> &A, int n, double tau_data[], ::
                    coder::array<int, 2U> &jpvt)
        {
          int k;
          int tau_size;
          k = A.size(1);
          jpvt.set_size(1, k);
          for (int i{0}; i < k; i++) {
            jpvt[i] = 0;
          }

          for (k = 0; k < n; k++) {
            jpvt[k] = k + 1;
          }

          tau_size = 1;
          tau_data[0] = 0.0;
          qrpf(A, n, tau_data, jpvt);
          return tau_size;
        }
      }
    }
  }
}

// End of code generation (xzgeqp3.cpp)
