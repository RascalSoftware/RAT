//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// qrsolve.cpp
//
// Code generation for function 'qrsolve'
//

// Include files
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "xunormqr.h"
#include "xzgeqp3.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      static void LSQFromQR(const ::coder::array<real_T, 1U> &A, const real_T
                            tau_data[], ::coder::array<real_T, 2U> &B, int32_T
                            rankA, ::coder::array<real_T, 2U> &Y);
      static int32_T rankFromQR(const ::coder::array<real_T, 1U> &A);
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
      static void LSQFromQR(const ::coder::array<real_T, 1U> &A, const real_T
                            tau_data[], ::coder::array<real_T, 2U> &B, int32_T
                            rankA, ::coder::array<real_T, 2U> &Y)
      {
        int32_T j;
        int32_T k;
        int32_T nb;
        nb = B.size(1);
        Y.set_size(1, B.size(1));
        k = B.size(1);
        for (j = 0; j < k; j++) {
          Y[j] = 0.0;
        }

        lapack::xunormqr(A, B, tau_data);
        for (k = 0; k < nb; k++) {
          if (0 <= rankA - 1) {
            Y[k] = B[B.size(0) * k];
          }

          for (j = rankA; j >= 1; j--) {
            Y[k] = Y[k] / A[0];
          }
        }
      }

      static int32_T rankFromQR(const ::coder::array<real_T, 1U> &A)
      {
        int32_T r;
        r = 0;
        if (A.size(0) >= 1) {
          real_T tol_tmp;
          tol_tmp = std::abs(A[0]);
          if (!(tol_tmp <= std::fmin(1.4901161193847656E-8,
                2.2204460492503131E-15 * static_cast<real_T>(A.size(0))) *
                tol_tmp)) {
            r = 1;
          }
        }

        return r;
      }

      void LSQFromQR(const ::coder::array<real_T, 2U> &A, const ::coder::array<
                     real_T, 1U> &tau, const ::coder::array<int32_T, 2U> &jpvt, ::
                     coder::array<real_T, 1U> &B, int32_T rankA, ::coder::array<
                     real_T, 1U> &Y)
      {
        int32_T b_i;
        int32_T i;
        Y.set_size(A.size(1));
        i = A.size(1);
        for (b_i = 0; b_i < i; b_i++) {
          Y[b_i] = 0.0;
        }

        lapack::xunormqr(A, B, tau);
        for (i = 0; i < rankA; i++) {
          Y[jpvt[i] - 1] = B[i];
        }

        for (int32_T j{rankA}; j >= 1; j--) {
          b_i = jpvt[j - 1];
          Y[b_i - 1] = Y[b_i - 1] / A[(j + A.size(0) * (j - 1)) - 1];
          for (i = 0; i <= j - 2; i++) {
            Y[jpvt[i] - 1] = Y[jpvt[i] - 1] - Y[jpvt[j - 1] - 1] * A[i + A.size
              (0) * (j - 1)];
          }
        }
      }

      void qrsolve(const ::coder::array<real_T, 1U> &A, const ::coder::array<
                   real_T, 2U> &B, ::coder::array<real_T, 2U> &Y)
      {
        ::coder::array<real_T, 2U> b_B;
        ::coder::array<real_T, 1U> b_A;
        real_T tau_data;
        int32_T i;
        int32_T jpvt;
        int32_T loop_ub;
        b_A.set_size(A.size(0));
        loop_ub = A.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_A[i] = A[i];
        }

        reflapack::xzgeqp3(b_A, A.size(0), (real_T *)&tau_data, &loop_ub, &jpvt);
        b_B.set_size(B.size(0), B.size(1));
        loop_ub = B.size(1) - 1;
        for (i = 0; i <= loop_ub; i++) {
          jpvt = B.size(0) - 1;
          for (int32_T i1{0}; i1 <= jpvt; i1++) {
            b_B[i1 + b_B.size(0) * i] = B[i1 + B.size(0) * i];
          }
        }

        LSQFromQR(b_A, (const real_T *)&tau_data, b_B, rankFromQR(b_A), Y);
      }

      int32_T rankFromQR(const ::coder::array<real_T, 2U> &A)
      {
        int32_T maxmn;
        int32_T minmn;
        int32_T r;
        r = 0;
        if (A.size(0) < A.size(1)) {
          minmn = A.size(0);
          maxmn = A.size(1);
        } else {
          minmn = A.size(1);
          maxmn = A.size(0);
        }

        if (minmn > 0) {
          real_T tol;
          tol = std::fmin(1.4901161193847656E-8, 2.2204460492503131E-15 *
                          static_cast<real_T>(maxmn)) * std::abs(A[0]);
          while ((r < minmn) && (!(std::abs(A[r + A.size(0) * r]) <= tol))) {
            r++;
          }
        }

        return r;
      }
    }
  }
}

// End of code generation (qrsolve.cpp)
