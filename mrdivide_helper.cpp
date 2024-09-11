//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// mrdivide_helper.cpp
//
// Code generation for function 'mrdivide_helper'
//

// Include files
#include "mrdivide_helper.h"
#include "lusolve.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void mrdiv(const ::coder::array<real_T, 2U> &A, const ::coder::array<
                 real_T, 2U> &B, ::coder::array<real_T, 2U> &Y)
      {
        ::coder::array<real_T, 2U> b_A;
        ::coder::array<real_T, 1U> c_A;
        ::coder::array<real_T, 1U> r;
        ::coder::array<real_T, 1U> tau;
        ::coder::array<int32_T, 2U> jpvt;
        if ((A.size(1) == 0) || ((B.size(0) == 0) || (B.size(1) == 0))) {
          int32_T loop_ub;
          Y.set_size(1, B.size(0));
          loop_ub = B.size(0);
          for (int32_T i{0}; i < loop_ub; i++) {
            Y[i] = 0.0;
          }
        } else if (B.size(0) == B.size(1)) {
          lusolve(B, A, Y);
        } else {
          int32_T i;
          int32_T loop_ub;
          b_A.set_size(B.size(1), B.size(0));
          loop_ub = B.size(0);
          for (i = 0; i < loop_ub; i++) {
            int32_T b_loop_ub;
            b_loop_ub = B.size(1);
            for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
              b_A[i1 + b_A.size(0) * i] = B[i + B.size(0) * i1];
            }
          }

          lapack::xgeqp3(b_A, tau, jpvt);
          c_A.set_size(A.size(1));
          loop_ub = A.size(1);
          for (i = 0; i < loop_ub; i++) {
            c_A[i] = A[i];
          }

          LSQFromQR(b_A, tau, jpvt, c_A, rankFromQR(b_A), r);
          Y.set_size(1, r.size(0));
          loop_ub = r.size(0);
          for (i = 0; i < loop_ub; i++) {
            Y[i] = r[i];
          }
        }
      }

      void mrdiv(const ::coder::array<real_T, 2U> &A, const ::coder::array<
                 real_T, 2U> &B, ::coder::array<real_T, 1U> &Y)
      {
        ::coder::array<real_T, 2U> b_A;
        ::coder::array<real_T, 2U> r;
        ::coder::array<real_T, 1U> b_B;
        if ((A.size(0) == 0) || (A.size(1) == 0) || (B.size(1) == 0)) {
          int32_T loop_ub;
          Y.set_size(A.size(0));
          loop_ub = A.size(0);
          for (int32_T i{0}; i < loop_ub; i++) {
            Y[i] = 0.0;
          }
        } else if (1 == B.size(1)) {
          int32_T loop_ub;
          loop_ub = A.size(0);
          Y.set_size(A.size(0));
          for (int32_T i{0}; i < loop_ub; i++) {
            Y[i] = A[i] / B[0];
          }
        } else {
          int32_T i;
          int32_T loop_ub;
          b_B.set_size(B.size(1));
          loop_ub = B.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_B[i] = B[i];
          }

          b_A.set_size(A.size(1), A.size(0));
          loop_ub = A.size(0);
          for (i = 0; i < loop_ub; i++) {
            int32_T b_loop_ub;
            b_loop_ub = A.size(1);
            for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
              b_A[i1 + b_A.size(0) * i] = A[i + A.size(0) * i1];
            }
          }

          qrsolve(b_B, b_A, r);
          Y.set_size(r.size(1));
          loop_ub = r.size(1);
          for (i = 0; i < loop_ub; i++) {
            Y[i] = r[i];
          }
        }
      }

      void mrdiv(const real_T A_data[], int32_T A_size, const real_T B_data[],
                 int32_T B_size, real_T Y_data[], int32_T Y_size[2])
      {
        if ((A_size == 0) || (B_size == 0)) {
          int32_T loop_ub;
          Y_size[0] = static_cast<int8_T>(A_size);
          Y_size[1] = static_cast<int8_T>(B_size);
          loop_ub = static_cast<int8_T>(B_size);
          if (0 <= loop_ub - 1) {
            loop_ub = static_cast<int8_T>(A_size);
            if (0 <= loop_ub - 1) {
              Y_data[0] = 0.0;
            }
          }
        } else {
          Y_size[0] = 1;
          Y_size[1] = 1;
          Y_data[0] = A_data[0] / B_data[0];
        }
      }
    }
  }
}

// End of code generation (mrdivide_helper.cpp)
