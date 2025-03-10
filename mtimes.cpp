//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// mtimes.cpp
//
// Code generation for function 'mtimes'
//

// Include files
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace blas
      {
        void b_mtimes(const ::coder::array<double, 2U> &A, const ::coder::array<
                      double, 2U> &B, ::coder::array<double, 2U> &C)
        {
          int inner;
          int mc;
          int nc;
          mc = A.size(1) - 1;
          inner = A.size(0);
          nc = B.size(1);
          C.set_size(A.size(1), B.size(1));
          for (int j{0}; j < nc; j++) {
            for (int i{0}; i <= mc; i++) {
              C[i + C.size(0) * j] = 0.0;
            }

            for (int k{0}; k < inner; k++) {
              double bkj;
              bkj = B[k + B.size(0) * j];
              for (int i{0}; i <= mc; i++) {
                C[i + C.size(0) * j] = C[i + C.size(0) * j] + A[k + A.size(0) *
                  i] * bkj;
              }
            }
          }
        }

        void mtimes(const ::coder::array<double, 2U> &A, const ::coder::array<
                    double, 2U> &B, double C_data[], int C_size[2])
        {
          int inner;
          int mc;
          int nc;
          mc = A.size(0) - 1;
          inner = A.size(1);
          nc = B.size(0);
          C_size[0] = A.size(0);
          C_size[1] = B.size(0);
          for (int j{0}; j < nc; j++) {
            if (mc >= 0) {
              C_data[0] = 0.0;
            }

            for (int k{0}; k < inner; k++) {
              double bkj;
              bkj = B[B.size(0) * k];
              for (int i{0}; i <= mc; i++) {
                C_data[0] += A[A.size(0) * k] * bkj;
              }
            }
          }
        }

        void mtimes(const double A_data[], const int A_size[2], const double
                    B_data[], const int B_size[2], double C_data[], int C_size[2])
        {
          int inner;
          int mc;
          int nc;
          mc = A_size[0] - 1;
          inner = A_size[1];
          nc = B_size[1];
          C_size[0] = A_size[0];
          C_size[1] = B_size[1];
          for (int j{0}; j < nc; j++) {
            if (mc >= 0) {
              C_data[0] = 0.0;
            }

            for (int k{0}; k < inner; k++) {
              double bkj;
              bkj = B_data[0];
              for (int i{0}; i <= mc; i++) {
                C_data[0] += A_data[0] * bkj;
              }
            }
          }
        }

        void mtimes(const ::coder::array<creal_T, 2U> &A, const ::coder::array<
                    creal_T, 2U> &B, ::coder::array<creal_T, 2U> &C)
        {
          int inner;
          int n;
          inner = A.size(1);
          n = B.size(0);
          C.set_size(1, B.size(0));
          for (int j{0}; j < n; j++) {
            double s_im;
            double s_re;
            s_re = 0.0;
            s_im = 0.0;
            for (int k{0}; k < inner; k++) {
              double A_re_tmp;
              double B_im;
              double B_re;
              double b_A_re_tmp;
              B_re = B[j + B.size(0) * k].re;
              B_im = -B[j + B.size(0) * k].im;
              A_re_tmp = A[k].re;
              b_A_re_tmp = A[k].im;
              s_re += A_re_tmp * B_re - b_A_re_tmp * B_im;
              s_im += A_re_tmp * B_im + b_A_re_tmp * B_re;
            }

            C[j].re = s_re;
            C[j].im = s_im;
          }
        }

        void mtimes(const ::coder::array<double, 2U> &A, const ::coder::array<
                    double, 2U> &B, ::coder::array<double, 2U> &C)
        {
          int inner;
          int nc;
          inner = A.size(1);
          nc = B.size(0);
          C.set_size(1, B.size(0));
          for (int j{0}; j < nc; j++) {
            C[j] = 0.0;
            for (int k{0}; k < inner; k++) {
              C[j] = C[j] + A[k] * B[j + B.size(0) * k];
            }
          }
        }

        void mtimes(const ::coder::array<double, 2U> &A, const ::coder::array<
                    double, 1U> &B, ::coder::array<double, 1U> &C)
        {
          int inner;
          int mc;
          mc = A.size(0) - 1;
          inner = A.size(1);
          C.set_size(A.size(0));
          for (int i{0}; i <= mc; i++) {
            C[i] = 0.0;
          }

          for (int k{0}; k < inner; k++) {
            for (int i{0}; i <= mc; i++) {
              C[i] = C[i] + A[i + A.size(0) * k] * B[k];
            }
          }
        }
      }
    }
  }
}

// End of code generation (mtimes.cpp)
