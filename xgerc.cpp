//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xgerc.cpp
//
// Code generation for function 'xgerc'
//

// Include files
#include "xgerc.h"
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
        void xgerc(int m, int n, double alpha1, const ::coder::array<double, 1U>
                   &x, int iy0, ::coder::array<double, 2U> &A, int ia0, int lda)
        {
          if (!(alpha1 == 0.0)) {
            int jA;
            jA = ia0;
            for (int j{0}; j < n; j++) {
              int i;
              i = (iy0 + j) - 1;
              if (A[i] != 0.0) {
                double temp;
                temp = A[i] * alpha1;
                i = m + jA;
                for (int ijA{jA}; ijA < i; ijA++) {
                  A[ijA - 1] = A[ijA - 1] + x[ijA - jA] * temp;
                }
              }

              jA += lda;
            }
          }
        }

        void xgerc(int m, int n, double alpha1, int ix0, const ::coder::array<
                   double, 1U> &y, ::coder::array<double, 2U> &A, int ia0, int
                   lda)
        {
          if (!(alpha1 == 0.0)) {
            int jA;
            jA = ia0;
            for (int j{0}; j < n; j++) {
              if (y[j] != 0.0) {
                double temp;
                int i;
                temp = y[j] * alpha1;
                i = m + jA;
                for (int ijA{jA}; ijA < i; ijA++) {
                  A[ijA - 1] = A[ijA - 1] + A[((ix0 + ijA) - jA) - 1] * temp;
                }
              }

              jA += lda;
            }
          }
        }
      }
    }
  }
}

// End of code generation (xgerc.cpp)
