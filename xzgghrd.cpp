//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzgghrd.cpp
//
// Code generation for function 'xzgghrd'
//

// Include files
#include "xzgghrd.h"
#include "eye.h"
#include "rt_nonfinite.h"
#include "xzlartg.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        void xzgghrd(int ilo, int ihi, ::coder::array<creal_T, 2U> &A, ::coder::
                     array<creal_T, 2U> &Z)
        {
          ::coder::array<creal_T, 2U> b_A;
          ::coder::array<double, 2U> r;
          creal_T s;
          double c;
          int i;
          int i1;
          int j;
          int loop_ub;
          int n;
          n = A.size(0);
          eye(A.size(0), r);
          Z.set_size(r.size(0), r.size(1));
          j = r.size(1);
          for (i = 0; i < j; i++) {
            loop_ub = r.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              Z[i1 + Z.size(0) * i].re = r[i1 + r.size(0) * i];
              Z[i1 + Z.size(0) * i].im = 0.0;
            }
          }

          if ((A.size(0) > 1) && (ihi >= ilo + 2)) {
            for (int jcol{ilo - 1}; jcol + 1 < ihi - 1; jcol++) {
              int jcolp1;
              jcolp1 = jcol + 2;
              for (int jrow{ihi - 1}; jrow + 1 > jcol + 2; jrow--) {
                double d;
                double d1;
                double stemp_im;
                double stemp_re;
                xzlartg(A[(jrow + A.size(0) * jcol) - 1], A[jrow + A.size(0) *
                        jcol], &c, &s, &A[(jrow + A.size(0) * jcol) - 1]);
                A[jrow + A.size(0) * jcol].re = 0.0;
                A[jrow + A.size(0) * jcol].im = 0.0;
                for (j = jcolp1; j <= n; j++) {
                  stemp_re = c * A[(jrow + A.size(0) * (j - 1)) - 1].re + (s.re *
                    A[jrow + A.size(0) * (j - 1)].re - s.im * A[jrow + A.size(0)
                    * (j - 1)].im);
                  stemp_im = c * A[(jrow + A.size(0) * (j - 1)) - 1].im + (s.re *
                    A[jrow + A.size(0) * (j - 1)].im + s.im * A[jrow + A.size(0)
                    * (j - 1)].re);
                  d = A[(jrow + A.size(0) * (j - 1)) - 1].im;
                  d1 = A[(jrow + A.size(0) * (j - 1)) - 1].re;
                  A[jrow + A.size(0) * (j - 1)].re = c * A[jrow + A.size(0) * (j
                    - 1)].re - (s.re * A[(jrow + A.size(0) * (j - 1)) - 1].re +
                                s.im * A[(jrow + A.size(0) * (j - 1)) - 1].im);
                  A[jrow + A.size(0) * (j - 1)].im = c * A[jrow + A.size(0) * (j
                    - 1)].im - (s.re * d - s.im * d1);
                  A[(jrow + A.size(0) * (j - 1)) - 1].re = stemp_re;
                  A[(jrow + A.size(0) * (j - 1)) - 1].im = stemp_im;
                }

                s.re = -s.re;
                s.im = -s.im;
                for (j = 1; j <= ihi; j++) {
                  stemp_re = c * A[(j + A.size(0) * jrow) - 1].re + (s.re * A[(j
                    + A.size(0) * (jrow - 1)) - 1].re - s.im * A[(j + A.size(0) *
                    (jrow - 1)) - 1].im);
                  stemp_im = c * A[(j + A.size(0) * jrow) - 1].im + (s.re * A[(j
                    + A.size(0) * (jrow - 1)) - 1].im + s.im * A[(j + A.size(0) *
                    (jrow - 1)) - 1].re);
                  d = A[(j + A.size(0) * jrow) - 1].im;
                  d1 = A[(j + A.size(0) * jrow) - 1].re;
                  A[(j + A.size(0) * (jrow - 1)) - 1].re = c * A[(j + A.size(0) *
                    (jrow - 1)) - 1].re - (s.re * A[(j + A.size(0) * jrow) - 1].
                    re + s.im * A[(j + A.size(0) * jrow) - 1].im);
                  A[(j + A.size(0) * (jrow - 1)) - 1].im = c * A[(j + A.size(0) *
                    (jrow - 1)) - 1].im - (s.re * d - s.im * d1);
                  A[(j + A.size(0) * jrow) - 1].re = stemp_re;
                  A[(j + A.size(0) * jrow) - 1].im = stemp_im;
                }

                b_A.set_size(Z.size(0), Z.size(1));
                j = Z.size(1);
                for (i = 0; i < j; i++) {
                  loop_ub = Z.size(0);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_A[i1 + b_A.size(0) * i] = Z[i1 + Z.size(0) * i];
                  }
                }

                for (j = 1; j <= n; j++) {
                  stemp_re = c * b_A[(j + b_A.size(0) * jrow) - 1].re + (s.re *
                    b_A[(j + b_A.size(0) * (jrow - 1)) - 1].re - s.im * b_A[(j +
                    b_A.size(0) * (jrow - 1)) - 1].im);
                  stemp_im = c * b_A[(j + b_A.size(0) * jrow) - 1].im + (s.re *
                    b_A[(j + b_A.size(0) * (jrow - 1)) - 1].im + s.im * b_A[(j +
                    b_A.size(0) * (jrow - 1)) - 1].re);
                  d = b_A[(j + b_A.size(0) * jrow) - 1].re;
                  b_A[(j + b_A.size(0) * (jrow - 1)) - 1].re = c * b_A[(j +
                    b_A.size(0) * (jrow - 1)) - 1].re - (s.re * b_A[(j +
                    b_A.size(0) * jrow) - 1].re + s.im * b_A[(j + b_A.size(0) *
                    jrow) - 1].im);
                  b_A[(j + b_A.size(0) * (jrow - 1)) - 1].im = c * b_A[(j +
                    b_A.size(0) * (jrow - 1)) - 1].im - (s.re * b_A[(j +
                    b_A.size(0) * jrow) - 1].im - s.im * d);
                  b_A[(j + b_A.size(0) * jrow) - 1].re = stemp_re;
                  b_A[(j + b_A.size(0) * jrow) - 1].im = stemp_im;
                }

                Z.set_size(b_A.size(0), b_A.size(1));
                j = b_A.size(1);
                for (i = 0; i < j; i++) {
                  loop_ub = b_A.size(0);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    Z[i1 + Z.size(0) * i] = b_A[i1 + b_A.size(0) * i];
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzgghrd.cpp)
