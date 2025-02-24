//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
            int i;
            for (i = 0; i <= mc; i++) {
              C[i + C.size(0) * j] = 0.0;
            }

            for (int k{0}; k < inner; k++) {
              double bkj;
              bkj = B[k + B.size(0) * j];
              for (i = 0; i <= mc; i++) {
                C[i + C.size(0) * j] = C[i + C.size(0) * j] + A[k + A.size(0) *
                  i] * bkj;
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
              double B_im;
              double B_re;
              B_re = B[j + B.size(0) * k].re;
              B_im = -B[j + B.size(0) * k].im;
              s_re += A[k].re * B_re - A[k].im * B_im;
              s_im += A[k].re * B_im + A[k].im * B_re;
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
          int i;
          int inner;
          int mc;
          mc = A.size(0) - 1;
          inner = A.size(1);
          C.set_size(A.size(0));
          for (i = 0; i <= mc; i++) {
            C[i] = 0.0;
          }

          for (int k{0}; k < inner; k++) {
            for (i = 0; i <= mc; i++) {
              C[i] = C[i] + A[i + A.size(0) * k] * B[k];
            }
          }
        }
      }
    }
  }
}

// End of code generation (mtimes.cpp)
