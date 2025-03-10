//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xtrsv.cpp
//
// Code generation for function 'xtrsv'
//

// Include files
#include "xtrsv.h"
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
        void b_xtrsv(int n, const ::coder::array<double, 2U> &A, int lda, ::
                     coder::array<double, 1U> &x)
        {
          if ((A.size(0) != 0) && (A.size(1) != 0)) {
            for (int j{n}; j >= 1; j--) {
              int jjA;
              jjA = (j + (j - 1) * lda) - 1;
              x[j - 1] = x[j - 1] / A[jjA];
              for (int i{0}; i <= j - 2; i++) {
                int ix;
                ix = (j - i) - 2;
                x[ix] = x[ix] - x[j - 1] * A[(jjA - i) - 1];
              }
            }
          }
        }

        void c_xtrsv(int n, const ::coder::array<double, 2U> &A, int lda, ::
                     coder::array<double, 1U> &x)
        {
          if ((A.size(0) != 0) && (A.size(1) != 0)) {
            for (int j{0}; j < n; j++) {
              double temp;
              int jA;
              jA = j * lda;
              temp = x[j];
              for (int i{0}; i < j; i++) {
                temp -= A[jA + i] * x[i];
              }

              x[j] = temp / A[jA + j];
            }
          }
        }

        void d_xtrsv(int n, const ::coder::array<double, 2U> &A, int lda, ::
                     coder::array<double, 1U> &x)
        {
          if ((A.size(0) != 0) && (A.size(1) != 0)) {
            for (int j{n}; j >= 1; j--) {
              double temp;
              int i;
              int jA;
              jA = (j - 1) * lda;
              temp = x[j - 1];
              i = j + 1;
              for (int b_i{n}; b_i >= i; b_i--) {
                temp -= A[(jA + b_i) - 1] * x[b_i - 1];
              }

              x[j - 1] = temp;
            }
          }
        }

        void xtrsv(int n, const ::coder::array<double, 2U> &A, int lda, ::coder::
                   array<double, 1U> &x)
        {
          if ((A.size(0) != 0) && (A.size(1) != 0)) {
            for (int j{0}; j < n; j++) {
              int i;
              int jjA;
              jjA = j + j * lda;
              i = n - j;
              for (int b_i{0}; b_i <= i - 2; b_i++) {
                int ix;
                ix = (j + b_i) + 1;
                x[ix] = x[ix] - x[j] * A[(jjA + b_i) + 1];
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xtrsv.cpp)
