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
      static void LSQFromQR(const ::coder::array<double, 1U> &A, const double
                            tau_data[], ::coder::array<double, 2U> &B, int rankA,
                            ::coder::array<double, 2U> &Y);
      static int rankFromQR(const ::coder::array<double, 1U> &A);
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
      static void LSQFromQR(const ::coder::array<double, 1U> &A, const double
                            tau_data[], ::coder::array<double, 2U> &B, int rankA,
                            ::coder::array<double, 2U> &Y)
      {
        int j;
        int k;
        int nb;
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

      static int rankFromQR(const ::coder::array<double, 1U> &A)
      {
        int r;
        r = 0;
        if (A.size(0) >= 1) {
          double tol_tmp;
          tol_tmp = std::abs(A[0]);
          if (!(tol_tmp <= std::fmin(1.4901161193847656E-8,
                2.2204460492503131E-15 * static_cast<double>(A.size(0))) *
                tol_tmp)) {
            r = 1;
          }
        }

        return r;
      }

      void LSQFromQR(const ::coder::array<double, 2U> &A, const ::coder::array<
                     double, 1U> &tau, const ::coder::array<int, 2U> &jpvt, ::
                     coder::array<double, 1U> &B, int rankA, ::coder::array<
                     double, 1U> &Y)
      {
        int b_i;
        int i;
        Y.set_size(A.size(1));
        i = A.size(1);
        for (b_i = 0; b_i < i; b_i++) {
          Y[b_i] = 0.0;
        }

        lapack::xunormqr(A, B, tau);
        for (i = 0; i < rankA; i++) {
          Y[jpvt[i] - 1] = B[i];
        }

        for (int j{rankA}; j >= 1; j--) {
          b_i = jpvt[j - 1];
          Y[b_i - 1] = Y[b_i - 1] / A[(j + A.size(0) * (j - 1)) - 1];
          for (i = 0; i <= j - 2; i++) {
            Y[jpvt[i] - 1] = Y[jpvt[i] - 1] - Y[jpvt[j - 1] - 1] * A[i + A.size
              (0) * (j - 1)];
          }
        }
      }

      void qrsolve(const ::coder::array<double, 1U> &A, const ::coder::array<
                   double, 2U> &B, ::coder::array<double, 2U> &Y)
      {
        ::coder::array<double, 2U> b_B;
        ::coder::array<double, 1U> b_A;
        double tau_data;
        int i;
        int jpvt;
        int loop_ub;
        b_A.set_size(A.size(0));
        loop_ub = A.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_A[i] = A[i];
        }

        reflapack::xzgeqp3(b_A, A.size(0), (double *)&tau_data, &loop_ub, &jpvt);
        b_B.set_size(B.size(0), B.size(1));
        loop_ub = B.size(1) - 1;
        for (i = 0; i <= loop_ub; i++) {
          jpvt = B.size(0) - 1;
          for (int i1{0}; i1 <= jpvt; i1++) {
            b_B[i1 + b_B.size(0) * i] = B[i1 + B.size(0) * i];
          }
        }

        LSQFromQR(b_A, (const double *)&tau_data, b_B, rankFromQR(b_A), Y);
      }

      int rankFromQR(const ::coder::array<double, 2U> &A)
      {
        int maxmn;
        int minmn;
        int r;
        r = 0;
        if (A.size(0) < A.size(1)) {
          minmn = A.size(0);
          maxmn = A.size(1);
        } else {
          minmn = A.size(1);
          maxmn = A.size(0);
        }

        if (minmn > 0) {
          double tol;
          tol = std::fmin(1.4901161193847656E-8, 2.2204460492503131E-15 *
                          static_cast<double>(maxmn)) * std::abs(A[0]);
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
