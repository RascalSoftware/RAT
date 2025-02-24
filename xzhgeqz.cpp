//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzhgeqz.cpp
//
// Code generation for function 'xzhgeqz'
//

// Include files
#include "xzhgeqz.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "xzlanhs.h"
#include "xzlartg.h"
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
        void xzhgeqz(::coder::array<creal_T, 2U> &A, int ilo, int ihi, ::coder::
                     array<creal_T, 2U> &Z, int *info, ::coder::array<creal_T,
                     1U> &alpha1, ::coder::array<creal_T, 1U> &beta1)
        {
          ::coder::array<creal_T, 2U> b_A;
          creal_T ctemp;
          creal_T stemp;
          creal_T y;
          double anorm;
          double ascale;
          double b_atol;
          double bscale;
          double c;
          double eshift_im;
          double eshift_re;
          int i;
          int i1;
          int ilast;
          int j;
          int jm1;
          int jp1;
          int n;
          boolean_T compz;
          boolean_T failed;
          boolean_T guard1{ false };

          boolean_T guard2{ false };

          *info = 0;
          compz = ((Z.size(0) != 0) && (Z.size(1) != 0));
          if ((A.size(0) == 1) && (A.size(1) == 1)) {
            ihi = 1;
          }

          n = A.size(0);
          jm1 = A.size(0);
          alpha1.set_size(jm1);
          for (i = 0; i < jm1; i++) {
            alpha1[i].re = 0.0;
            alpha1[i].im = 0.0;
          }

          jm1 = A.size(0);
          beta1.set_size(jm1);
          for (i = 0; i < jm1; i++) {
            beta1[i].re = 1.0;
            beta1[i].im = 0.0;
          }

          eshift_re = 0.0;
          eshift_im = 0.0;
          ctemp.re = 0.0;
          ctemp.im = 0.0;
          anorm = xzlanhs(A, ilo, ihi);
          c = 2.2204460492503131E-16 * anorm;
          b_atol = 2.2250738585072014E-308;
          if (c > 2.2250738585072014E-308) {
            b_atol = c;
          }

          c = 2.2250738585072014E-308;
          if (anorm > 2.2250738585072014E-308) {
            c = anorm;
          }

          ascale = 1.0 / c;
          bscale = 1.0 / std::sqrt(static_cast<double>(A.size(0)));
          failed = true;
          i = ihi + 1;
          for (j = i; j <= n; j++) {
            alpha1[j - 1] = A[(j + A.size(0) * (j - 1)) - 1];
          }

          guard1 = false;
          guard2 = false;
          if (ihi >= ilo) {
            int ifirst;
            int ifrstm;
            int iiter;
            int ilastm;
            int ilastm1;
            int istart;
            int jiter;
            boolean_T goto60;
            boolean_T goto70;
            boolean_T goto90;
            ifirst = ilo;
            istart = ilo;
            ilast = ihi - 1;
            ilastm1 = ihi - 2;
            if (compz) {
              ifrstm = 1;
              ilastm = n;
            } else {
              ifrstm = ilo;
              ilastm = ihi;
            }

            iiter = 0;
            goto60 = false;
            goto70 = false;
            goto90 = false;
            jiter = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (jiter <= 30 * ((ihi - ilo) + 1) - 1) {
                boolean_T b_guard1{ false };

                boolean_T exitg2;
                b_guard1 = false;
                if (ilast + 1 == ilo) {
                  goto60 = true;
                  b_guard1 = true;
                } else if (std::abs(A[ilast + A.size(0) * ilastm1].re) + std::
                           abs(A[ilast + A.size(0) * ilastm1].im) <= std::fmax
                           (2.2250738585072014E-308, 2.2204460492503131E-16 *
                            ((std::abs(A[ilast + A.size(0) * ilast].re) + std::
                              abs(A[ilast + A.size(0) * ilast].im)) + (std::abs
                              (A[ilastm1 + A.size(0) * ilastm1].re) + std::abs
                              (A[ilastm1 + A.size(0) * ilastm1].im))))) {
                  A[ilast + A.size(0) * ilastm1].re = 0.0;
                  A[ilast + A.size(0) * ilastm1].im = 0.0;
                  goto60 = true;
                  b_guard1 = true;
                } else {
                  boolean_T guard3{ false };

                  j = ilastm1;
                  guard3 = false;
                  exitg2 = false;
                  while ((!exitg2) && (j + 1 >= ilo)) {
                    if (j + 1 == ilo) {
                      guard3 = true;
                      exitg2 = true;
                    } else if (std::abs(A[j + A.size(0) * (j - 1)].re) + std::
                               abs(A[j + A.size(0) * (j - 1)].im) <= std::fmax
                               (2.2250738585072014E-308, 2.2204460492503131E-16 *
                                ((std::abs(A[j + A.size(0) * j].re) + std::abs
                                  (A[j + A.size(0) * j].im)) + (std::abs(A[(j +
                        A.size(0) * (j - 1)) - 1].re) + std::abs(A[(j + A.size(0)
                      * (j - 1)) - 1].im))))) {
                      A[j + A.size(0) * (j - 1)].re = 0.0;
                      A[j + A.size(0) * (j - 1)].im = 0.0;
                      guard3 = true;
                      exitg2 = true;
                    } else {
                      j--;
                      guard3 = false;
                    }
                  }

                  if (guard3) {
                    ifirst = j + 1;
                    goto70 = true;
                  }

                  if (goto70) {
                    b_guard1 = true;
                  } else {
                    jm1 = alpha1.size(0);
                    alpha1.set_size(jm1);
                    for (i = 0; i < jm1; i++) {
                      alpha1[i].re = rtNaN;
                      alpha1[i].im = 0.0;
                    }

                    jm1 = beta1.size(0);
                    beta1.set_size(jm1);
                    for (i = 0; i < jm1; i++) {
                      beta1[i].re = rtNaN;
                      beta1[i].im = 0.0;
                    }

                    if (compz) {
                      jm1 = Z.size(0);
                      jp1 = Z.size(1);
                      Z.set_size(jm1, jp1);
                      for (i = 0; i < jp1; i++) {
                        for (i1 = 0; i1 < jm1; i1++) {
                          Z[i1 + Z.size(0) * i].re = rtNaN;
                          Z[i1 + Z.size(0) * i].im = 0.0;
                        }
                      }
                    }

                    *info = 1;
                    exitg1 = 1;
                  }
                }

                if (b_guard1) {
                  if (goto60) {
                    goto60 = false;
                    alpha1[ilast] = A[ilast + A.size(0) * ilast];
                    ilast = ilastm1;
                    ilastm1--;
                    if (ilast + 1 < ilo) {
                      failed = false;
                      guard2 = true;
                      exitg1 = 1;
                    } else {
                      iiter = 0;
                      eshift_re = 0.0;
                      eshift_im = 0.0;
                      if (!compz) {
                        ilastm = ilast + 1;
                        if (ifrstm > ilast + 1) {
                          ifrstm = ilo;
                        }
                      }

                      jiter++;
                    }
                  } else {
                    if (goto70) {
                      double ad22_im;
                      double ad22_re;
                      double temp;
                      double temp2;
                      double y_im_tmp;
                      goto70 = false;
                      iiter++;
                      if (!compz) {
                        ifrstm = ifirst;
                      }

                      if (iiter - iiter / 10 * 10 != 0) {
                        anorm = ascale * A[ilast + A.size(0) * ilast].re;
                        c = ascale * A[ilast + A.size(0) * ilast].im;
                        if (c == 0.0) {
                          ad22_re = anorm / bscale;
                          ad22_im = 0.0;
                        } else if (anorm == 0.0) {
                          ad22_re = 0.0;
                          ad22_im = c / bscale;
                        } else {
                          ad22_re = anorm / bscale;
                          ad22_im = c / bscale;
                        }

                        anorm = ascale * A[ilastm1 + A.size(0) * ilast].re;
                        c = ascale * A[ilastm1 + A.size(0) * ilast].im;
                        if (c == 0.0) {
                          stemp.re = anorm / bscale;
                          stemp.im = 0.0;
                        } else if (anorm == 0.0) {
                          stemp.re = 0.0;
                          stemp.im = c / bscale;
                        } else {
                          stemp.re = anorm / bscale;
                          stemp.im = c / bscale;
                        }

                        scalar::d_sqrt(&stemp);
                        anorm = ascale * A[ilast + A.size(0) * ilastm1].re;
                        c = ascale * A[ilast + A.size(0) * ilastm1].im;
                        if (c == 0.0) {
                          y.re = anorm / bscale;
                          y.im = 0.0;
                        } else if (anorm == 0.0) {
                          y.re = 0.0;
                          y.im = c / bscale;
                        } else {
                          y.re = anorm / bscale;
                          y.im = c / bscale;
                        }

                        scalar::d_sqrt(&y);
                        ctemp.re = stemp.re * y.re - stemp.im * y.im;
                        ctemp.im = stemp.re * y.im + stemp.im * y.re;
                        if ((ctemp.re != 0.0) || (ctemp.im != 0.0)) {
                          double x_im;
                          double x_re;
                          anorm = ascale * A[ilastm1 + A.size(0) * ilastm1].re;
                          c = ascale * A[ilastm1 + A.size(0) * ilastm1].im;
                          if (c == 0.0) {
                            anorm /= bscale;
                            c = 0.0;
                          } else if (anorm == 0.0) {
                            anorm = 0.0;
                            c /= bscale;
                          } else {
                            anorm /= bscale;
                            c /= bscale;
                          }

                          x_re = 0.5 * (anorm - ad22_re);
                          x_im = 0.5 * (c - ad22_im);
                          temp2 = std::abs(x_re) + std::abs(x_im);
                          temp = std::fmax(std::abs(ctemp.re) + std::abs
                                           (ctemp.im), temp2);
                          if (x_im == 0.0) {
                            stemp.re = x_re / temp;
                            stemp.im = 0.0;
                          } else if (x_re == 0.0) {
                            stemp.re = 0.0;
                            stemp.im = x_im / temp;
                          } else {
                            stemp.re = x_re / temp;
                            stemp.im = x_im / temp;
                          }

                          if (ctemp.im == 0.0) {
                            y.re = ctemp.re / temp;
                            y.im = 0.0;
                          } else if (ctemp.re == 0.0) {
                            y.re = 0.0;
                            y.im = ctemp.im / temp;
                          } else {
                            y.re = ctemp.re / temp;
                            y.im = ctemp.im / temp;
                          }

                          anorm = stemp.re * stemp.re - stemp.im * stemp.im;
                          c = stemp.re * stemp.im;
                          y_im_tmp = y.re * y.im;
                          stemp.re = anorm + (y.re * y.re - y.im * y.im);
                          stemp.im = (c + c) + (y_im_tmp + y_im_tmp);
                          scalar::d_sqrt(&stemp);
                          y.re = temp * stemp.re;
                          y.im = temp * stemp.im;
                          if (temp2 > 0.0) {
                            if (x_im == 0.0) {
                              c = x_re / temp2;
                              anorm = 0.0;
                            } else {
                              if (x_re == 0.0) {
                                c = 0.0;
                              } else {
                                c = x_re / temp2;
                              }

                              anorm = x_im / temp2;
                            }

                            if (c * y.re + anorm * y.im < 0.0) {
                              y.re = -y.re;
                              y.im = -y.im;
                            }
                          }

                          y_im_tmp = x_re + y.re;
                          temp = x_im + y.im;
                          if (temp == 0.0) {
                            if (ctemp.im == 0.0) {
                              x_re = ctemp.re / y_im_tmp;
                              anorm = 0.0;
                            } else if (ctemp.re == 0.0) {
                              x_re = 0.0;
                              anorm = ctemp.im / y_im_tmp;
                            } else {
                              x_re = ctemp.re / y_im_tmp;
                              anorm = ctemp.im / y_im_tmp;
                            }
                          } else if (y_im_tmp == 0.0) {
                            if (ctemp.re == 0.0) {
                              x_re = ctemp.im / temp;
                              anorm = 0.0;
                            } else if (ctemp.im == 0.0) {
                              x_re = 0.0;
                              anorm = -(ctemp.re / temp);
                            } else {
                              x_re = ctemp.im / temp;
                              anorm = -(ctemp.re / temp);
                            }
                          } else {
                            temp2 = std::abs(y_im_tmp);
                            anorm = std::abs(temp);
                            if (temp2 > anorm) {
                              c = temp / y_im_tmp;
                              anorm = y_im_tmp + c * temp;
                              x_re = (ctemp.re + c * ctemp.im) / anorm;
                              anorm = (ctemp.im - c * ctemp.re) / anorm;
                            } else if (anorm == temp2) {
                              if (y_im_tmp > 0.0) {
                                c = 0.5;
                              } else {
                                c = -0.5;
                              }

                              if (temp > 0.0) {
                                anorm = 0.5;
                              } else {
                                anorm = -0.5;
                              }

                              x_re = (ctemp.re * c + ctemp.im * anorm) / temp2;
                              anorm = (ctemp.im * c - ctemp.re * anorm) / temp2;
                            } else {
                              c = y_im_tmp / temp;
                              anorm = temp + c * y_im_tmp;
                              x_re = (c * ctemp.re + ctemp.im) / anorm;
                              anorm = (c * ctemp.im - ctemp.re) / anorm;
                            }
                          }

                          ad22_re -= ctemp.re * x_re - ctemp.im * anorm;
                          ad22_im -= ctemp.re * anorm + ctemp.im * x_re;
                        }
                      } else {
                        if (iiter - iiter / 20 * 20 == 0) {
                          anorm = ascale * A[ilast + A.size(0) * ilast].re;
                          c = ascale * A[ilast + A.size(0) * ilast].im;
                          if (c == 0.0) {
                            anorm /= bscale;
                            c = 0.0;
                          } else if (anorm == 0.0) {
                            anorm = 0.0;
                            c /= bscale;
                          } else {
                            anorm /= bscale;
                            c /= bscale;
                          }

                          eshift_re += anorm;
                          eshift_im += c;
                        } else {
                          anorm = ascale * A[ilast + A.size(0) * ilastm1].re;
                          c = ascale * A[ilast + A.size(0) * ilastm1].im;
                          if (c == 0.0) {
                            anorm /= bscale;
                            c = 0.0;
                          } else if (anorm == 0.0) {
                            anorm = 0.0;
                            c /= bscale;
                          } else {
                            anorm /= bscale;
                            c /= bscale;
                          }

                          eshift_re += anorm;
                          eshift_im += c;
                        }

                        ad22_re = eshift_re;
                        ad22_im = eshift_im;
                      }

                      j = ilastm1;
                      jp1 = ilastm1 + 1;
                      exitg2 = false;
                      while ((!exitg2) && (j + 1 > ifirst)) {
                        istart = j + 1;
                        ctemp.re = ascale * A[j + A.size(0) * j].re - ad22_re *
                          bscale;
                        ctemp.im = ascale * A[j + A.size(0) * j].im - ad22_im *
                          bscale;
                        temp = std::abs(ctemp.re) + std::abs(ctemp.im);
                        temp2 = ascale * (std::abs(A[jp1 + A.size(0) * j].re) +
                                          std::abs(A[jp1 + A.size(0) * j].im));
                        anorm = temp;
                        if (temp2 > temp) {
                          anorm = temp2;
                        }

                        if ((anorm < 1.0) && (anorm != 0.0)) {
                          temp /= anorm;
                          temp2 /= anorm;
                        }

                        if ((std::abs(A[j + A.size(0) * (j - 1)].re) + std::abs
                             (A[j + A.size(0) * (j - 1)].im)) * temp2 <= temp *
                            b_atol) {
                          goto90 = true;
                          exitg2 = true;
                        } else {
                          jp1 = j;
                          j--;
                        }
                      }

                      if (!goto90) {
                        istart = ifirst;
                        ctemp.re = ascale * A[(ifirst + A.size(0) * (ifirst - 1))
                          - 1].re - ad22_re * bscale;
                        ctemp.im = ascale * A[(ifirst + A.size(0) * (ifirst - 1))
                          - 1].im - ad22_im * bscale;
                      }

                      goto90 = false;
                      stemp.re = ascale * A[istart + A.size(0) * (istart - 1)].
                        re;
                      stemp.im = ascale * A[istart + A.size(0) * (istart - 1)].
                        im;
                      xzlartg(ctemp, stemp, &c, &y);
                      j = istart;
                      jm1 = istart - 2;
                      while (j < ilast + 1) {
                        if (j > istart) {
                          xzlartg(A[(j + A.size(0) * jm1) - 1], A[j + A.size(0) *
                                  jm1], &c, &y, &A[(j + A.size(0) * jm1) - 1]);
                          A[j + A.size(0) * jm1].re = 0.0;
                          A[j + A.size(0) * jm1].im = 0.0;
                        }

                        for (jp1 = j; jp1 <= ilastm; jp1++) {
                          stemp.re = c * A[(j + A.size(0) * (jp1 - 1)) - 1].re +
                            (y.re * A[j + A.size(0) * (jp1 - 1)].re - y.im * A[j
                             + A.size(0) * (jp1 - 1)].im);
                          stemp.im = c * A[(j + A.size(0) * (jp1 - 1)) - 1].im +
                            (y.re * A[j + A.size(0) * (jp1 - 1)].im + y.im * A[j
                             + A.size(0) * (jp1 - 1)].re);
                          anorm = A[(j + A.size(0) * (jp1 - 1)) - 1].im;
                          y_im_tmp = A[(j + A.size(0) * (jp1 - 1)) - 1].re;
                          A[j + A.size(0) * (jp1 - 1)].re = c * A[j + A.size(0) *
                            (jp1 - 1)].re - (y.re * A[(j + A.size(0) * (jp1 - 1))
                                             - 1].re + y.im * A[(j + A.size(0) *
                            (jp1 - 1)) - 1].im);
                          A[j + A.size(0) * (jp1 - 1)].im = c * A[j + A.size(0) *
                            (jp1 - 1)].im - (y.re * anorm - y.im * y_im_tmp);
                          A[(j + A.size(0) * (jp1 - 1)) - 1] = stemp;
                        }

                        y.re = -y.re;
                        y.im = -y.im;
                        jp1 = j;
                        if (ilast + 1 < j + 2) {
                          jp1 = ilast - 1;
                        }

                        for (jm1 = ifrstm; jm1 <= jp1 + 2; jm1++) {
                          stemp.re = c * A[(jm1 + A.size(0) * j) - 1].re + (y.re
                            * A[(jm1 + A.size(0) * (j - 1)) - 1].re - y.im * A
                            [(jm1 + A.size(0) * (j - 1)) - 1].im);
                          stemp.im = c * A[(jm1 + A.size(0) * j) - 1].im + (y.re
                            * A[(jm1 + A.size(0) * (j - 1)) - 1].im + y.im * A
                            [(jm1 + A.size(0) * (j - 1)) - 1].re);
                          anorm = A[(jm1 + A.size(0) * j) - 1].im;
                          y_im_tmp = A[(jm1 + A.size(0) * j) - 1].re;
                          A[(jm1 + A.size(0) * (j - 1)) - 1].re = c * A[(jm1 +
                            A.size(0) * (j - 1)) - 1].re - (y.re * A[(jm1 +
                            A.size(0) * j) - 1].re + y.im * anorm);
                          A[(jm1 + A.size(0) * (j - 1)) - 1].im = c * A[(jm1 +
                            A.size(0) * (j - 1)) - 1].im - (y.re * anorm - y.im *
                            y_im_tmp);
                          A[(jm1 + A.size(0) * j) - 1] = stemp;
                        }

                        if (compz) {
                          b_A.set_size(Z.size(0), Z.size(1));
                          jp1 = Z.size(1);
                          for (i = 0; i < jp1; i++) {
                            jm1 = Z.size(0);
                            for (i1 = 0; i1 < jm1; i1++) {
                              b_A[i1 + b_A.size(0) * i] = Z[i1 + Z.size(0) * i];
                            }
                          }

                          for (jm1 = 1; jm1 <= n; jm1++) {
                            stemp.re = c * b_A[(jm1 + b_A.size(0) * j) - 1].re +
                              (y.re * b_A[(jm1 + b_A.size(0) * (j - 1)) - 1].re
                               - y.im * b_A[(jm1 + b_A.size(0) * (j - 1)) - 1].
                               im);
                            stemp.im = c * b_A[(jm1 + b_A.size(0) * j) - 1].im +
                              (y.re * b_A[(jm1 + b_A.size(0) * (j - 1)) - 1].im
                               + y.im * b_A[(jm1 + b_A.size(0) * (j - 1)) - 1].
                               re);
                            anorm = b_A[(jm1 + b_A.size(0) * j) - 1].re;
                            b_A[(jm1 + b_A.size(0) * (j - 1)) - 1].re = c * b_A
                              [(jm1 + b_A.size(0) * (j - 1)) - 1].re - (y.re *
                              b_A[(jm1 + b_A.size(0) * j) - 1].re + y.im * b_A
                              [(jm1 + b_A.size(0) * j) - 1].im);
                            b_A[(jm1 + b_A.size(0) * (j - 1)) - 1].im = c * b_A
                              [(jm1 + b_A.size(0) * (j - 1)) - 1].im - (y.re *
                              b_A[(jm1 + b_A.size(0) * j) - 1].im - y.im * anorm);
                            b_A[(jm1 + b_A.size(0) * j) - 1] = stemp;
                          }

                          Z.set_size(b_A.size(0), b_A.size(1));
                          jp1 = b_A.size(1);
                          for (i = 0; i < jp1; i++) {
                            jm1 = b_A.size(0);
                            for (i1 = 0; i1 < jm1; i1++) {
                              Z[i1 + Z.size(0) * i] = b_A[i1 + b_A.size(0) * i];
                            }
                          }
                        }

                        jm1 = j - 1;
                        j++;
                      }
                    }

                    jiter++;
                  }
                }
              } else {
                guard2 = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          } else {
            guard1 = true;
          }

          if (guard2) {
            if (failed) {
              *info = ilast + 1;
              for (jm1 = 0; jm1 <= ilast; jm1++) {
                alpha1[jm1].re = rtNaN;
                alpha1[jm1].im = 0.0;
                beta1[jm1].re = rtNaN;
                beta1[jm1].im = 0.0;
              }

              if (compz) {
                jm1 = Z.size(0);
                jp1 = Z.size(1);
                Z.set_size(jm1, jp1);
                for (i = 0; i < jp1; i++) {
                  for (i1 = 0; i1 < jm1; i1++) {
                    Z[i1 + Z.size(0) * i].re = rtNaN;
                    Z[i1 + Z.size(0) * i].im = 0.0;
                  }
                }
              }
            } else {
              guard1 = true;
            }
          }

          if (guard1) {
            for (j = 0; j <= ilo - 2; j++) {
              alpha1[j] = A[j + A.size(0) * j];
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzhgeqz.cpp)
