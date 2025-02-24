//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xztgevc.cpp
//
// Code generation for function 'xztgevc'
//

// Include files
#include "xztgevc.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        void xztgevc(const ::coder::array<creal_T, 2U> &A, ::coder::array<
                     creal_T, 2U> &V)
        {
          ::coder::array<creal_T, 1U> work1;
          ::coder::array<creal_T, 1U> work2;
          ::coder::array<double, 1U> rworka;
          double BIG;
          double BIGNUM;
          double SMALL;
          double anorm;
          double ascale;
          double d_re;
          double xmx;
          int b_i;
          int i;
          int j;
          int n;
          n = A.size(0) - 1;
          work1.set_size(A.size(0));
          i = A.size(0);
          for (b_i = 0; b_i < i; b_i++) {
            work1[b_i].re = 0.0;
            work1[b_i].im = 0.0;
          }

          work2.set_size(A.size(0));
          i = A.size(0);
          for (b_i = 0; b_i < i; b_i++) {
            work2[b_i].re = 0.0;
            work2[b_i].im = 0.0;
          }

          SMALL = 2.2250738585072014E-308 * static_cast<double>(A.size(0)) /
            2.2204460492503131E-16;
          BIG = 1.0 / SMALL;
          BIGNUM = 1.0 / (2.2250738585072014E-308 * static_cast<double>(A.size(0)));
          rworka.set_size(A.size(0));
          i = A.size(0);
          for (b_i = 0; b_i < i; b_i++) {
            rworka[b_i] = 0.0;
          }

          anorm = std::abs(A[0].re) + std::abs(A[0].im);
          b_i = A.size(0);
          for (j = 0; j <= b_i - 2; j++) {
            for (i = 0; i <= j; i++) {
              rworka[j + 1] = rworka[j + 1] + (std::abs(A[i + A.size(0) * (j + 1)]
                .re) + std::abs(A[i + A.size(0) * (j + 1)].im));
            }

            d_re = rworka[j + 1] + (std::abs(A[(j + A.size(0) * (j + 1)) + 1].re)
              + std::abs(A[(j + A.size(0) * (j + 1)) + 1].im));
            if (d_re > anorm) {
              anorm = d_re;
            }
          }

          xmx = anorm;
          if (2.2250738585072014E-308 > anorm) {
            xmx = 2.2250738585072014E-308;
          }

          ascale = 1.0 / xmx;
          b_i = static_cast<int>(((-1.0 - static_cast<double>(A.size(0))) + 1.0)
            / -1.0);
          for (int je{0}; je < b_i; je++) {
            double acoeff;
            double dmin;
            double salpha_im;
            double salpha_re;
            double scale;
            double temp;
            double z;
            int b_je;
            int jr;
            boolean_T lscalea;
            boolean_T lscaleb;
            b_je = n - je;
            xmx = (std::abs(A[b_je + A.size(0) * b_je].re) + std::abs(A[b_je +
                    A.size(0) * b_je].im)) * ascale;
            if (1.0 > xmx) {
              xmx = 1.0;
            }

            temp = 1.0 / xmx;
            salpha_re = ascale * (temp * A[b_je + A.size(0) * b_je].re);
            salpha_im = ascale * (temp * A[b_je + A.size(0) * b_je].im);
            acoeff = temp * ascale;
            if ((temp >= 2.2250738585072014E-308) && (acoeff < SMALL)) {
              lscalea = true;
            } else {
              lscalea = false;
            }

            z = std::abs(salpha_re) + std::abs(salpha_im);
            if ((z >= 2.2250738585072014E-308) && (z < SMALL)) {
              lscaleb = true;
            } else {
              lscaleb = false;
            }

            scale = 1.0;
            if (lscalea) {
              xmx = anorm;
              if (BIG < anorm) {
                xmx = BIG;
              }

              scale = SMALL / temp * xmx;
            }

            if (lscaleb) {
              d_re = SMALL / z;
              if (d_re > scale) {
                scale = d_re;
              }
            }

            if (lscalea || lscaleb) {
              xmx = acoeff;
              if (1.0 > acoeff) {
                xmx = 1.0;
              }

              if (z > xmx) {
                xmx = z;
              }

              d_re = 1.0 / (2.2250738585072014E-308 * xmx);
              if (d_re < scale) {
                scale = d_re;
              }

              if (lscalea) {
                acoeff = ascale * (scale * temp);
              } else {
                acoeff *= scale;
              }

              salpha_re *= scale;
              salpha_im *= scale;
            }

            for (jr = 0; jr <= n; jr++) {
              work1[jr].re = 0.0;
              work1[jr].im = 0.0;
            }

            work1[b_je].re = 1.0;
            work1[b_je].im = 0.0;
            dmin = 2.2204460492503131E-16 * acoeff * anorm;
            d_re = 2.2204460492503131E-16 * (std::abs(salpha_re) + std::abs
              (salpha_im));
            if (d_re > dmin) {
              dmin = d_re;
            }

            if (2.2250738585072014E-308 > dmin) {
              dmin = 2.2250738585072014E-308;
            }

            for (jr = 0; jr < b_je; jr++) {
              work1[jr].re = acoeff * A[jr + A.size(0) * b_je].re;
              work1[jr].im = acoeff * A[jr + A.size(0) * b_je].im;
            }

            work1[b_je].re = 1.0;
            work1[b_je].im = 0.0;
            i = static_cast<int>(((-1.0 - (static_cast<double>(b_je + 1) - 1.0))
                                  + 1.0) / -1.0);
            for (j = 0; j < i; j++) {
              double ai;
              double brm;
              double d_im;
              int b_j;
              b_j = (b_je - j) - 1;
              d_re = acoeff * A[b_j + A.size(0) * b_j].re - salpha_re;
              d_im = acoeff * A[b_j + A.size(0) * b_j].im - salpha_im;
              if (std::abs(d_re) + std::abs(d_im) <= dmin) {
                d_re = dmin;
                d_im = 0.0;
              }

              brm = std::abs(d_re);
              scale = std::abs(d_im);
              xmx = brm + scale;
              if (xmx < 1.0) {
                z = std::abs(work1[b_j].re) + std::abs(work1[b_j].im);
                if (z >= BIGNUM * xmx) {
                  temp = 1.0 / z;
                  for (jr = 0; jr <= b_je; jr++) {
                    work1[jr].re = temp * work1[jr].re;
                    work1[jr].im = temp * work1[jr].im;
                  }
                }
              }

              temp = -work1[b_j].re;
              ai = -work1[b_j].im;
              if (d_im == 0.0) {
                if (ai == 0.0) {
                  scale = temp / d_re;
                  xmx = 0.0;
                } else if (temp == 0.0) {
                  scale = 0.0;
                  xmx = ai / d_re;
                } else {
                  scale = temp / d_re;
                  xmx = ai / d_re;
                }
              } else if (d_re == 0.0) {
                if (temp == 0.0) {
                  scale = ai / d_im;
                  xmx = 0.0;
                } else if (ai == 0.0) {
                  scale = 0.0;
                  xmx = -(temp / d_im);
                } else {
                  scale = ai / d_im;
                  xmx = -(temp / d_im);
                }
              } else if (brm > scale) {
                z = d_im / d_re;
                xmx = d_re + z * d_im;
                scale = (temp + z * ai) / xmx;
                xmx = (ai - z * temp) / xmx;
              } else if (scale == brm) {
                if (d_re > 0.0) {
                  z = 0.5;
                } else {
                  z = -0.5;
                }

                if (d_im > 0.0) {
                  xmx = 0.5;
                } else {
                  xmx = -0.5;
                }

                scale = (temp * z + ai * xmx) / brm;
                xmx = (ai * z - temp * xmx) / brm;
              } else {
                z = d_re / d_im;
                xmx = d_im + z * d_re;
                scale = (z * temp + ai) / xmx;
                xmx = (z * ai - temp) / xmx;
              }

              work1[b_j].re = scale;
              work1[b_j].im = xmx;
              if (b_j + 1 > 1) {
                if (std::abs(work1[b_j].re) + std::abs(work1[b_j].im) > 1.0) {
                  temp = 1.0 / (std::abs(work1[b_j].re) + std::abs(work1[b_j].im));
                  if (acoeff * rworka[b_j] >= BIGNUM * temp) {
                    for (jr = 0; jr <= b_je; jr++) {
                      work1[jr].re = temp * work1[jr].re;
                      work1[jr].im = temp * work1[jr].im;
                    }
                  }
                }

                d_re = acoeff * work1[b_j].re;
                d_im = acoeff * work1[b_j].im;
                for (jr = 0; jr < b_j; jr++) {
                  work1[jr].re = work1[jr].re + (d_re * A[jr + A.size(0) * b_j].
                    re - d_im * A[jr + A.size(0) * b_j].im);
                  work1[jr].im = work1[jr].im + (d_re * A[jr + A.size(0) * b_j].
                    im + d_im * A[jr + A.size(0) * b_j].re);
                }
              }
            }

            for (jr = 0; jr <= n; jr++) {
              work2[jr].re = 0.0;
              work2[jr].im = 0.0;
            }

            for (i = 0; i <= b_je; i++) {
              for (jr = 0; jr <= n; jr++) {
                work2[jr].re = work2[jr].re + (V[jr + V.size(0) * i].re *
                  work1[i].re - V[jr + V.size(0) * i].im * work1[i].im);
                work2[jr].im = work2[jr].im + (V[jr + V.size(0) * i].re *
                  work1[i].im + V[jr + V.size(0) * i].im * work1[i].re);
              }
            }

            xmx = std::abs(work2[0].re) + std::abs(work2[0].im);
            if (n + 1 > 1) {
              for (jr = 0; jr < n; jr++) {
                d_re = std::abs(work2[jr + 1].re) + std::abs(work2[jr + 1].im);
                if (d_re > xmx) {
                  xmx = d_re;
                }
              }
            }

            if (xmx > 2.2250738585072014E-308) {
              temp = 1.0 / xmx;
              for (jr = 0; jr <= n; jr++) {
                V[jr + V.size(0) * b_je].re = temp * work2[jr].re;
                V[jr + V.size(0) * b_je].im = temp * work2[jr].im;
              }
            } else {
              for (jr = 0; jr <= n; jr++) {
                V[jr + V.size(0) * b_je].re = 0.0;
                V[jr + V.size(0) * b_je].im = 0.0;
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (xztgevc.cpp)
