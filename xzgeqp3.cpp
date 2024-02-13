//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include <cstring>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        static void qrpf(::coder::array<real_T, 1U> &A, int32_T m, real_T
                         tau_data[], int32_T *jpvt);
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
        static void qrpf(::coder::array<real_T, 1U> &A, int32_T m, real_T
                         tau_data[], int32_T *jpvt)
        {
          real_T atmp;
          int32_T minmn;
          *jpvt = 1;
          if (m < 1) {
            minmn = m;
          } else {
            minmn = 1;
          }

          for (int32_T i{0}; i < minmn; i++) {
            if (1 < m) {
              atmp = A[0];
              tau_data[0] = xzlarfg(m, &atmp, A);
              A[0] = atmp;
            } else {
              tau_data[0] = 0.0;
            }
          }
        }

        void qrpf(::coder::array<real_T, 2U> &A, int32_T m, int32_T n, ::coder::
                  array<real_T, 1U> &tau, ::coder::array<int32_T, 2U> &jpvt)
        {
          ::coder::array<real_T, 1U> vn1;
          ::coder::array<real_T, 1U> vn2;
          ::coder::array<real_T, 1U> work;
          real_T atmp;
          int32_T itemp;
          int32_T j;
          int32_T ma;
          int32_T minmn;
          ma = A.size(0);
          if (m < n) {
            minmn = m;
          } else {
            minmn = n;
          }

          itemp = A.size(1);
          work.set_size(itemp);
          for (j = 0; j < itemp; j++) {
            work[j] = 0.0;
          }

          itemp = A.size(1);
          vn1.set_size(itemp);
          for (j = 0; j < itemp; j++) {
            vn1[j] = 0.0;
          }

          itemp = A.size(1);
          vn2.set_size(itemp);
          for (j = 0; j < itemp; j++) {
            vn2[j] = 0.0;
          }

          for (j = 0; j < n; j++) {
            atmp = blas::xnrm2(m, A, j * ma + 1);
            vn1[j] = atmp;
            vn2[j] = atmp;
          }

          for (int32_T i{0}; i < minmn; i++) {
            int32_T ii;
            int32_T ip1;
            int32_T mmi;
            int32_T nmi;
            int32_T pvt;
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
              atmp = A[ii];
              tau[i] = xzlarfg(mmi, &atmp, A, ii + 2);
              A[ii] = atmp;
            } else {
              tau[i] = 0.0;
            }

            if (i + 1 < n) {
              atmp = A[ii];
              A[ii] = 1.0;
              xzlarf(mmi, nmi - 1, ii + 1, tau[i], A, (ii + ma) + 1, ma, work);
              A[ii] = atmp;
            }

            for (j = ip1; j <= n; j++) {
              itemp = i + (j - 1) * ma;
              atmp = vn1[j - 1];
              if (atmp != 0.0) {
                real_T temp1;
                real_T temp2;
                temp1 = std::abs(A[itemp]) / atmp;
                temp1 = 1.0 - temp1 * temp1;
                if (temp1 < 0.0) {
                  temp1 = 0.0;
                }

                temp2 = atmp / vn2[j - 1];
                temp2 = temp1 * (temp2 * temp2);
                if (temp2 <= 1.4901161193847656E-8) {
                  if (i + 1 < m) {
                    atmp = blas::xnrm2(mmi - 1, A, itemp + 2);
                    vn1[j - 1] = atmp;
                    vn2[j - 1] = atmp;
                  } else {
                    vn1[j - 1] = 0.0;
                    vn2[j - 1] = 0.0;
                  }
                } else {
                  vn1[j - 1] = atmp * std::sqrt(temp1);
                }
              }
            }
          }
        }

        void xzgeqp3(::coder::array<real_T, 1U> &A, int32_T m, real_T tau_data[],
                     int32_T *tau_size, int32_T *jpvt)
        {
          *tau_size = A.size(0);
          if (*tau_size >= 1) {
            *tau_size = 1;
          }

          if (0 <= *tau_size - 1) {
            std::memset(&tau_data[0], 0, *tau_size * sizeof(real_T));
          }

          if (A.size(0) == 0) {
            *jpvt = 1;
          } else {
            int32_T y;
            if (m < 1) {
              y = m;
            } else {
              y = 1;
            }

            if (y < 1) {
              *jpvt = 1;
            } else {
              *jpvt = 1;
              qrpf(A, m, tau_data, jpvt);
              *jpvt = 1;
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzgeqp3.cpp)
