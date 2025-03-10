//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xgeru.cpp
//
// Code generation for function 'xgeru'
//

// Include files
#include "xgeru.h"
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
        void xgeru(int m, int n, int ix0, int iy0, int incy, ::coder::array<
                   double, 2U> &A, int ia0, int lda)
        {
          int jA;
          jA = ia0;
          for (int j{0}; j < n; j++) {
            double yjy;
            int yjy_tmp;
            yjy_tmp = (iy0 + j * incy) - 1;
            yjy = A[yjy_tmp];
            if (A[yjy_tmp] != 0.0) {
              yjy_tmp = m + jA;
              for (int ijA{jA}; ijA < yjy_tmp; ijA++) {
                A[ijA - 1] = A[ijA - 1] + A[((ix0 + ijA) - jA) - 1] * -yjy;
              }
            }

            jA += lda;
          }
        }
      }
    }
  }
}

// End of code generation (xgeru.cpp)
