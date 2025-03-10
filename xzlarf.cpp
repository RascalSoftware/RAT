//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        static int ilazlc(int m, int n, const ::coder::array<double, 2U> &A, int
                          ia0, int lda);
        static int ilazlr(int m, int n, const ::coder::array<double, 2U> &A, int
                          ia0, int lda);
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
        static int ilazlc(int m, int n, const ::coder::array<double, 2U> &A, int
                          ia0, int lda)
        {
          int j;
          boolean_T exitg2;
          j = n;
          exitg2 = false;
          while ((!exitg2) && (j > 0)) {
            int coltop;
            int exitg1;
            int ia;
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

        static int ilazlr(int m, int n, const ::coder::array<double, 2U> &A, int
                          ia0, int lda)
        {
          int i;
          boolean_T exitg2;
          i = m;
          exitg2 = false;
          while ((!exitg2) && (i > 0)) {
            int exitg1;
            int rowleft;
            int rowright;
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

        void b_xzlarf(int m, int n, int iv0, double tau, ::coder::array<double,
                      2U> &C, int ic0, int ldc, ::coder::array<double, 1U> &work)
        {
          int lastc;
          int lastv;
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

        void xzlarf(int m, int n, int iv0, double tau, ::coder::array<double, 2U>
                    &C, int ic0, int ldc, ::coder::array<double, 1U> &work)
        {
          int lastc;
          int lastv;
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
