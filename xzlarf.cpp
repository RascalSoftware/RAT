//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzlarf.cpp
//
// Code generation for function 'xzlarf'
//

// Include files
#include "xzlarf.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xgerc.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        static int32_T ilazlc(int32_T m, int32_T n, const ::coder::array<real_T,
                              2U> &A, int32_T ia0, int32_T lda);
        static int32_T ilazlr(int32_T m, int32_T n, const ::coder::array<real_T,
                              2U> &A, int32_T ia0, int32_T lda);
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
        static int32_T ilazlc(int32_T m, int32_T n, const ::coder::array<real_T,
                              2U> &A, int32_T ia0, int32_T lda)
        {
          int32_T j;
          boolean_T exitg2;
          j = n;
          exitg2 = false;
          while ((!exitg2) && (j > 0)) {
            int32_T coltop;
            int32_T exitg1;
            int32_T ia;
            coltop = ia0 + (j - 1) * lda;
            ia = coltop;
            do {
              exitg1 = 0;
              if (ia <= (coltop + m) - 1) {
                if (A[ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  ia++;
                }
              } else {
                j--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          return j;
        }

        static int32_T ilazlr(int32_T m, int32_T n, const ::coder::array<real_T,
                              2U> &A, int32_T ia0, int32_T lda)
        {
          int32_T i;
          boolean_T exitg2;
          i = m;
          exitg2 = false;
          while ((!exitg2) && (i > 0)) {
            int32_T exitg1;
            int32_T rowleft;
            int32_T rowright;
            rowleft = (ia0 + i) - 1;
            rowright = rowleft + (n - 1) * lda;
            do {
              exitg1 = 0;
              if (((lda > 0) && (rowleft <= rowright)) || ((lda < 0) && (rowleft
                    >= rowright))) {
                if (A[rowleft - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  rowleft += lda;
                }
              } else {
                i--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          return i;
        }

        void b_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, ::coder::
                      array<real_T, 2U> &C, int32_T ic0, int32_T ldc, ::coder::
                      array<real_T, 1U> &work)
        {
          int32_T lastc;
          int32_T lastv;
          if (tau != 0.0) {
            lastv = n;
            lastc = iv0 + n;
            while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
              lastv--;
              lastc--;
            }

            lastc = ilazlr(m, lastv, C, ic0, ldc);
          } else {
            lastv = 0;
            lastc = 0;
          }

          if (lastv > 0) {
            blas::b_xgemv(lastc, lastv, C, ic0, ldc, C, iv0, work);
            blas::xgerc(lastc, lastv, -tau, work, iv0, C, ic0, ldc);
          }
        }

        void c_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, ::coder::
                      array<real_T, 2U> &C, int32_T ic0, int32_T ldc, ::coder::
                      array<real_T, 1U> &work)
        {
          int32_T lastc;
          int32_T lastv;
          if (tau != 0.0) {
            lastv = m;
            lastc = iv0 + m;
            while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
              lastv--;
              lastc--;
            }

            lastc = ilazlc(lastv, n, C, ic0, ldc);
          } else {
            lastv = 0;
            lastc = 0;
          }

          if (lastv > 0) {
            blas::c_xgemv(lastv, lastc, C, ic0, ldc, C, iv0, work);
            blas::xgerc(lastv, lastc, -tau, iv0, work, C, ic0, ldc);
          }
        }

        void xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, ::coder::
                    array<real_T, 2U> &C, int32_T ic0, int32_T ldc, ::coder::
                    array<real_T, 1U> &work)
        {
          int32_T lastc;
          int32_T lastv;
          if (tau != 0.0) {
            lastv = m;
            lastc = iv0 + m;
            while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
              lastv--;
              lastc--;
            }

            lastc = ilazlc(lastv, n, C, ic0, ldc);
          } else {
            lastv = 0;
            lastc = 0;
          }

          if (lastv > 0) {
            blas::xgemv(lastv, lastc, C, ic0, ldc, C, iv0, work);
            blas::xgerc(lastv, lastc, -tau, iv0, work, C, ic0, ldc);
          }
        }
      }
    }
  }
}

// End of code generation (xzlarf.cpp)
