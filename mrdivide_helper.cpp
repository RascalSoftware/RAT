//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include "xzgeqp3.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
                        double, 2U> &in2, int in3, const ::coder::array<double,
                        2U> &in4, const ::coder::array<double, 2U> &in5)
  {
    ::coder::array<double, 2U> b_in2;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    if (in4.size(1) == 1) {
      loop_ub = in2.size(1);
    } else {
      loop_ub = in4.size(1);
    }

    b_in2.set_size(1, loop_ub);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_1 = (in4.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in2[b_in2.size(0) * i] = in2[in3 + in2.size(0) * (i * stride_0_1)] -
        in4[in4.size(0) * (i * stride_1_1)];
    }

    coder::internal::mrdiv(b_in2, in5, in1);
  }

  void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
                        double, 1U> &in2, const ::coder::array<double, 2U> &in3,
                        const ::coder::array<int, 1U> &in4, const int in5_data[],
                        const int &in5_size)
  {
    ::coder::array<double, 1U> b_in3;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    if (in5_size == 1) {
      loop_ub = in4.size(0);
    } else {
      loop_ub = in5_size;
    }

    b_in3.set_size(loop_ub);
    stride_0_0 = (in4.size(0) != 1);
    stride_1_0 = (in5_size != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in3[i] = in3[in4[i * stride_0_0] - 1] - in3[in5_data[i * stride_1_0] - 1];
    }

    coder::internal::mrdiv(in2, b_in3, in1);
  }

  void c_binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::array<
    double, 2U> &in2, int in3, const ::coder::array<double, 2U> &in4, const ::
    coder::array<double, 2U> &in5)
  {
    ::coder::array<double, 2U> b_in2;
    int aux_0_1;
    int aux_1_1;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    if (in4.size(1) == 1) {
      loop_ub = in2.size(1);
    } else {
      loop_ub = in4.size(1);
    }

    b_in2.set_size(in4.size(0), loop_ub);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_1 = (in4.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (int i{0}; i < loop_ub; i++) {
      int b_loop_ub;
      b_loop_ub = in4.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        b_in2[b_in2.size(0) * i] = in2[in3 + in2.size(0) * aux_0_1] -
          in4[in4.size(0) * aux_1_1];
      }

      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    coder::internal::mrdiv(b_in2, in5, in1);
  }

  namespace coder
  {
    namespace internal
    {
      void mrdiv(const ::coder::array<double, 2U> &A, const ::coder::array<
                 double, 2U> &B, ::coder::array<double, 2U> &Y)
      {
        ::coder::array<double, 2U> b_A;
        ::coder::array<double, 2U> c_A;
        ::coder::array<double, 2U> r;
        ::coder::array<double, 1U> tau;
        ::coder::array<int, 2U> jpvt;
        if ((A.size(0) == 0) || (A.size(1) == 0) || ((B.size(0) == 0) || (B.size
              (1) == 0))) {
          int loop_ub;
          Y.set_size(A.size(0), B.size(0));
          loop_ub = B.size(0);
          for (int i{0}; i < loop_ub; i++) {
            int b_loop_ub;
            b_loop_ub = A.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              Y[Y.size(0) * i] = 0.0;
            }
          }
        } else if (B.size(0) == B.size(1)) {
          lusolve(B, A, Y);
        } else {
          int b_loop_ub;
          int loop_ub;
          b_A.set_size(B.size(1), B.size(0));
          loop_ub = B.size(0);
          b_loop_ub = B.size(1);
          for (int i{0}; i < loop_ub; i++) {
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              b_A[i1 + b_A.size(0) * i] = B[i + B.size(0) * i1];
            }
          }

          lapack::xgeqp3(b_A, tau, jpvt);
          c_A.set_size(A.size(1), 1);
          loop_ub = A.size(1);
          for (int i{0}; i < loop_ub; i++) {
            c_A[i] = A[A.size(0) * i];
          }

          LSQFromQR(b_A, tau, jpvt, c_A, b_rankFromQR(b_A), r);
          Y.set_size(r.size(1), r.size(0));
          loop_ub = r.size(0);
          for (int i{0}; i < loop_ub; i++) {
            b_loop_ub = r.size(1);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              Y[Y.size(0) * i] = r[i];
            }
          }
        }
      }

      void mrdiv(const ::coder::array<double, 2U> &A, const ::coder::array<
                 double, 2U> &B, ::coder::array<double, 1U> &Y)
      {
        ::coder::array<double, 2U> b_A;
        ::coder::array<double, 2U> r;
        ::coder::array<double, 1U> b_B;
        if ((A.size(0) == 0) || (A.size(1) == 0) || (B.size(1) == 0)) {
          int loop_ub;
          Y.set_size(A.size(0));
          loop_ub = A.size(0);
          for (int i{0}; i < loop_ub; i++) {
            Y[i] = 0.0;
          }
        } else if (B.size(1) == 1) {
          int loop_ub;
          Y.set_size(A.size(0));
          loop_ub = A.size(0);
          for (int i{0}; i < loop_ub; i++) {
            Y[i] = A[i] / B[0];
          }
        } else {
          int b_loop_ub;
          int loop_ub;
          b_B.set_size(B.size(1));
          loop_ub = B.size(1);
          for (int i{0}; i < loop_ub; i++) {
            b_B[i] = B[i];
          }

          b_A.set_size(A.size(1), A.size(0));
          loop_ub = A.size(0);
          b_loop_ub = A.size(1);
          for (int i{0}; i < loop_ub; i++) {
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              b_A[i1 + b_A.size(0) * i] = A[i + A.size(0) * i1];
            }
          }

          qrsolve(b_B, b_A, r);
          Y.set_size(r.size(1));
          loop_ub = r.size(1);
          for (int i{0}; i < loop_ub; i++) {
            Y[i] = r[i];
          }
        }
      }

      void mrdiv(const ::coder::array<double, 1U> &A, const ::coder::array<
                 double, 1U> &B, ::coder::array<double, 2U> &Y)
      {
        ::coder::array<double, 2U> b_A;
        ::coder::array<double, 2U> c_A;
        ::coder::array<double, 2U> r;
        ::coder::array<double, 1U> b_Y;
        ::coder::array<int, 2U> jpvt;
        double tau_data;
        if ((A.size(0) == 0) || (B.size(0) == 0)) {
          int loop_ub;
          Y.set_size(A.size(0), B.size(0));
          loop_ub = B.size(0);
          for (int i{0}; i < loop_ub; i++) {
            int b_loop_ub;
            b_loop_ub = A.size(0);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              Y[i1 + Y.size(0) * i] = 0.0;
            }
          }
        } else if (B.size(0) == 1) {
          int loop_ub;
          b_Y.set_size(A.size(0));
          loop_ub = A.size(0);
          for (int i{0}; i < loop_ub; i++) {
            b_Y[i] = A[i] / B[0];
          }

          loop_ub = b_Y.size(0);
          Y.set_size(b_Y.size(0), 1);
          for (int i{0}; i < loop_ub; i++) {
            Y[i] = b_Y[i];
          }
        } else {
          int loop_ub;
          b_A.set_size(1, B.size(0));
          loop_ub = B.size(0);
          for (int i{0}; i < loop_ub; i++) {
            b_A[i] = B[i];
          }

          reflapack::xzgeqp3(b_A, B.size(0), (double *)&tau_data, jpvt);
          c_A.set_size(1, A.size(0));
          loop_ub = A.size(0);
          for (int i{0}; i < loop_ub; i++) {
            c_A[i] = A[i];
          }

          LSQFromQR(b_A, jpvt, c_A, rankFromQR(b_A), r);
          Y.set_size(r.size(1), r.size(0));
          loop_ub = r.size(0);
          for (int i{0}; i < loop_ub; i++) {
            int b_loop_ub;
            b_loop_ub = r.size(1);
            for (int i1{0}; i1 < b_loop_ub; i1++) {
              Y[i1 + Y.size(0) * i] = r[i + r.size(0) * i1];
            }
          }
        }
      }
    }
  }
}

// End of code generation (mrdivide_helper.cpp)
