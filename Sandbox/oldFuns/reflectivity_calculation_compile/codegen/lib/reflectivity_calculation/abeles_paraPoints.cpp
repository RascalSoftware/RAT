//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: abeles_paraPoints.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Apr-2021 11:38:50
//

// Include Files
#include "abeles_paraPoints.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "standardTF_stanLay_reflectivityCalculation.h"
#include <cmath>
#include <cstring>

// Function Definitions

//
// nbair = nbairs(thisCont);
//  nbsub = nbsubs(thisCont);
//  ssub = ssubs(thisCont);
//  nrepeats = nrepeatss(thisCont);
//  resol = resols(thisCont);
// Arguments    : const coder::array<double, 1U> *x
//                const coder::array<double, 2U> *sld
//                double nbair
//                double nbsub
//                double nrepeats
//                double rfinal
//                double layers
//                double points
//                coder::array<double, 1U> *out
// Return Type  : void
//
void abeles_paraPoints(const coder::array<double, 1U> &x, const coder::array<
  double, 2U> &sld, double nbair, double nbsub, double nrepeats, double rfinal,
  double layers, double points, coder::array<double, 1U> &out)
{
  int ub_loop;
  double snair;
  double snsub;
  creal_T quo;
  creal_T num;
  creal_T MI[4];
  creal_T beta;
  creal_T pimag;
  double preal;
  double rough;
  double thick;
  creal_T blast;
  creal_T psub;
  creal_T N[4];
  double preal_tmp;
  int i;
  int i1;
  int reploop;
  double re;
  int nl;
  double im;
  double ar;
  double quo_re;
  double brm;
  double x_re;
  double x_im;
  creal_T b_MI[4];
  int i2;
  ub_loop = static_cast<int>(points);
  out.set_size(ub_loop);

  // pi = 3.141592653589;
  snair = 1.0 - nbair * 0.377451863036739;
  snsub = 1.0 - nbsub * 0.377451863036739;
  ub_loop--;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(quo,num,MI,beta,pimag,preal,rough,thick,blast,psub,N,preal_tmp,i,i1,reploop,re,nl,im,ar,quo_re,x_re,x_im,brm,i2,b_MI)

  for (int loop = 0; loop <= ub_loop; loop++) {
    thick = std::asin(x[loop] * 1.54 / 12.566370614359172);
    preal = std::cos(thick);
    preal_tmp = snair * snair * (preal * preal);
    preal = snsub * snsub - preal_tmp;
    psub.re = preal;
    psub.im = preal * 0.0;
    b_sqrt(&psub);
    preal = snair * std::sin(thick);
    quo.re = preal;
    quo.im = preal * 0.0;
    blast.re = 0.0;
    blast.im = 0.0;
    MI[0].re = 1.0;
    MI[0].im = 0.0;
    MI[3].re = 1.0;
    MI[3].im = 0.0;
    MI[2].re = 0.0;
    MI[2].im = 0.0;
    MI[1].re = 0.0;
    MI[1].im = 0.0;
    i = static_cast<int>(nrepeats);
    if (0 <= i - 1) {
      i1 = static_cast<int>(layers);
    }

    for (reploop = 0; reploop < i; reploop++) {
      for (nl = 0; nl < i1; nl++) {
        thick = sld[nl];
        preal = sld[nl + sld.size(0)];
        rough = sld[nl + sld.size(0) * 2];
        preal = 1.0 - preal * 0.377451863036739;
        preal = preal * preal - preal_tmp;
        pimag.re = preal;
        pimag.im = preal * 0.0;
        b_sqrt(&pimag);
        beta.re = 4.0799904592075231 * thick * pimag.re;
        beta.im = 4.0799904592075231 * thick * pimag.im;
        re = -78.956835208714864 * quo.re;
        im = -78.956835208714864 * quo.im;
        thick = rough * rough;
        ar = (re * pimag.re - im * pimag.im) * thick;
        re = (re * pimag.im + im * pimag.re) * thick;
        if (re == 0.0) {
          num.re = ar / 2.3716;
          num.im = 0.0;
        } else if (ar == 0.0) {
          num.re = 0.0;
          num.im = re / 2.3716;
        } else {
          num.re = ar / 2.3716;
          num.im = re / 2.3716;
        }

        if (num.im == 0.0) {
          quo_re = num.re;
          num.re = std::exp(quo_re);
          num.im = 0.0;
        } else if (rtIsInf(num.im) && rtIsInf(num.re) && (num.re < 0.0)) {
          num.re = 0.0;
          num.im = 0.0;
        } else {
          preal = std::exp(num.re / 2.0);
          quo_re = num.im;
          ar = num.im;
          num.re = preal * (preal * std::cos(quo_re));
          num.im = preal * (preal * std::sin(ar));
        }

        ar = quo.re - pimag.re;
        re = quo.im - pimag.im;
        preal = quo.re + pimag.re;
        im = quo.im + pimag.im;
        if (im == 0.0) {
          if (re == 0.0) {
            quo_re = ar / preal;
            preal = 0.0;
          } else if (ar == 0.0) {
            quo_re = 0.0;
            preal = re / preal;
          } else {
            quo_re = ar / preal;
            preal = re / preal;
          }
        } else if (preal == 0.0) {
          if (ar == 0.0) {
            quo_re = re / im;
            preal = 0.0;
          } else if (re == 0.0) {
            quo_re = 0.0;
            preal = -(ar / im);
          } else {
            quo_re = re / im;
            preal = -(ar / im);
          }
        } else {
          brm = std::abs(preal);
          rough = std::abs(im);
          if (brm > rough) {
            rough = im / preal;
            preal += rough * im;
            quo_re = (ar + rough * re) / preal;
            preal = (re - rough * ar) / preal;
          } else if (rough == brm) {
            if (preal > 0.0) {
              thick = 0.5;
            } else {
              thick = -0.5;
            }

            if (im > 0.0) {
              preal = 0.5;
            } else {
              preal = -0.5;
            }

            quo_re = (ar * thick + re * preal) / brm;
            preal = (re * thick - ar * preal) / brm;
          } else {
            rough = preal / im;
            preal = im + rough * preal;
            quo_re = (rough * ar + re) / preal;
            preal = (rough * re - ar) / preal;
          }
        }

        re = quo_re * num.re - preal * num.im;
        im = quo_re * num.im + preal * num.re;
        x_re = blast.re * 0.0 - blast.im;
        x_im = blast.re + blast.im * 0.0;
        if (x_im == 0.0) {
          x_re = std::exp(x_re);
          x_im = 0.0;
        } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          preal = std::exp(x_re / 2.0);
          x_re = preal * (preal * std::cos(x_im));
          x_im = preal * (preal * std::sin(x_im));
        }

        quo_re = -blast.re * 0.0 - (-blast.im);
        ar = -blast.re + -blast.im * 0.0;
        if (ar == 0.0) {
          quo_re = std::exp(quo_re);
          quo.re = quo_re;
          ar = 0.0;
          quo.im = 0.0;
        } else if (rtIsInf(ar) && rtIsInf(quo_re) && (quo_re < 0.0)) {
          quo_re = 0.0;
          quo.re = 0.0;
          ar = 0.0;
          quo.im = 0.0;
        } else {
          preal = std::exp(quo_re / 2.0);
          quo_re = preal * (preal * std::cos(ar));
          quo.re = quo_re;
          ar = preal * (preal * std::sin(ar));
          quo.im = ar;
        }

        brm = re * quo_re - im * ar;
        quo_re = re * ar + im * quo_re;
        N[3] = quo;
        ar = re * x_re - im * x_im;
        preal = re * x_im + im * x_re;
        quo = pimag;
        blast = beta;
        thick = N[3].re;
        rough = N[3].im;
        for (i2 = 0; i2 < 2; i2++) {
          im = MI[i2 + 2].re;
          re = MI[i2 + 2].im;
          b_MI[i2].re = (MI[i2].re * x_re - MI[i2].im * x_im) + (im * brm - re *
            quo_re);
          b_MI[i2].im = (MI[i2].re * x_im + MI[i2].im * x_re) + (im * quo_re +
            re * brm);
          b_MI[i2 + 2].re = (MI[i2].re * ar - MI[i2].im * preal) + (im * thick -
            re * rough);
          b_MI[i2 + 2].im = (MI[i2].re * preal + MI[i2].im * ar) + (im * rough +
            re * thick);
        }

        std::memcpy(&MI[0], &b_MI[0], 4U * sizeof(creal_T));
      }
    }

    re = -78.956835208714864 * quo.re;
    im = -78.956835208714864 * quo.im;
    thick = rfinal * rfinal;
    ar = (re * psub.re - im * psub.im) * thick;
    re = (re * psub.im + im * psub.re) * thick;
    if (re == 0.0) {
      num.re = ar / 2.3716;
      num.im = 0.0;
    } else if (ar == 0.0) {
      num.re = 0.0;
      num.im = re / 2.3716;
    } else {
      num.re = ar / 2.3716;
      num.im = re / 2.3716;
    }

    if (num.im == 0.0) {
      quo_re = num.re;
      num.re = std::exp(quo_re);
      num.im = 0.0;
    } else if (rtIsInf(num.im) && rtIsInf(num.re) && (num.re < 0.0)) {
      num.re = 0.0;
      num.im = 0.0;
    } else {
      preal = std::exp(num.re / 2.0);
      quo_re = num.im;
      ar = num.im;
      num.re = preal * (preal * std::cos(quo_re));
      num.im = preal * (preal * std::sin(ar));
    }

    ar = quo.re - psub.re;
    re = quo.im - psub.im;
    preal = quo.re + psub.re;
    im = quo.im + psub.im;
    if (im == 0.0) {
      if (re == 0.0) {
        quo_re = ar / preal;
        preal = 0.0;
      } else if (ar == 0.0) {
        quo_re = 0.0;
        preal = re / preal;
      } else {
        quo_re = ar / preal;
        preal = re / preal;
      }
    } else if (preal == 0.0) {
      if (ar == 0.0) {
        quo_re = re / im;
        preal = 0.0;
      } else if (re == 0.0) {
        quo_re = 0.0;
        preal = -(ar / im);
      } else {
        quo_re = re / im;
        preal = -(ar / im);
      }
    } else {
      brm = std::abs(preal);
      rough = std::abs(im);
      if (brm > rough) {
        rough = im / preal;
        preal += rough * im;
        quo_re = (ar + rough * re) / preal;
        preal = (re - rough * ar) / preal;
      } else if (rough == brm) {
        if (preal > 0.0) {
          thick = 0.5;
        } else {
          thick = -0.5;
        }

        if (im > 0.0) {
          preal = 0.5;
        } else {
          preal = -0.5;
        }

        quo_re = (ar * thick + re * preal) / brm;
        preal = (re * thick - ar * preal) / brm;
      } else {
        rough = preal / im;
        preal = im + rough * preal;
        quo_re = (rough * ar + re) / preal;
        preal = (rough * re - ar) / preal;
      }
    }

    re = quo_re * num.re - preal * num.im;
    im = quo_re * num.im + preal * num.re;
    x_re = blast.re * 0.0 - blast.im;
    x_im = blast.re + blast.im * 0.0;
    if (x_im == 0.0) {
      x_re = std::exp(x_re);
      x_im = 0.0;
    } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      preal = std::exp(x_re / 2.0);
      x_re = preal * (preal * std::cos(x_im));
      x_im = preal * (preal * std::sin(x_im));
    }

    quo.re = -blast.re * 0.0 - (-blast.im);
    quo.im = -blast.re + -blast.im * 0.0;
    if (quo.im == 0.0) {
      quo_re = quo.re;
      quo.re = std::exp(quo_re);
      quo.im = 0.0;
    } else if (rtIsInf(quo.im) && rtIsInf(quo.re) && (quo.re < 0.0)) {
      quo.re = 0.0;
      quo.im = 0.0;
    } else {
      preal = std::exp(quo.re / 2.0);
      quo_re = quo.im;
      ar = quo.im;
      quo.re = preal * (preal * std::cos(quo_re));
      quo.im = preal * (preal * std::sin(ar));
    }

    quo_re = re * quo.re - im * quo.im;
    ar = re * quo.im + im * quo.re;
    brm = re * x_re - im * x_im;
    preal = re * x_im + im * x_re;
    thick = quo.re;
    rough = quo.im;
    for (i = 0; i < 2; i++) {
      im = MI[i + 2].re;
      re = MI[i + 2].im;
      b_MI[i].re = (MI[i].re * x_re - MI[i].im * x_im) + (im * quo_re - re * ar);
      b_MI[i].im = (MI[i].re * x_im + MI[i].im * x_re) + (im * ar + re * quo_re);
      b_MI[i + 2].re = (MI[i].re * brm - MI[i].im * preal) + (im * thick - re *
        rough);
      b_MI[i + 2].im = (MI[i].re * preal + MI[i].im * brm) + (im * rough + re *
        thick);
    }

    num.re = b_MI[1].re * b_MI[1].re - b_MI[1].im * -b_MI[1].im;
    num.im = b_MI[1].re * -b_MI[1].im + b_MI[1].im * b_MI[1].re;
    thick = b_MI[0].re * b_MI[0].re - b_MI[0].im * -b_MI[0].im;
    preal = b_MI[0].re * -b_MI[0].im + b_MI[0].im * b_MI[0].re;
    if (preal == 0.0) {
      if (num.im == 0.0) {
        quo.re = num.re / thick;
        quo.im = 0.0;
      } else if (num.re == 0.0) {
        quo.re = 0.0;
        quo.im = num.im / thick;
      } else {
        quo.re = num.re / thick;
        quo.im = num.im / thick;
      }
    } else if (thick == 0.0) {
      if (num.re == 0.0) {
        quo.re = num.im / preal;
        quo.im = 0.0;
      } else if (num.im == 0.0) {
        quo.re = 0.0;
        quo.im = -(num.re / preal);
      } else {
        quo.re = num.im / preal;
        quo.im = -(num.re / preal);
      }
    } else {
      brm = std::abs(thick);
      rough = std::abs(preal);
      if (brm > rough) {
        rough = preal / thick;
        preal = thick + rough * preal;
        quo.re = (num.re + rough * num.im) / preal;
        quo.im = (num.im - rough * num.re) / preal;
      } else if (rough == brm) {
        if (thick > 0.0) {
          thick = 0.5;
        } else {
          thick = -0.5;
        }

        if (preal > 0.0) {
          preal = 0.5;
        } else {
          preal = -0.5;
        }

        quo.re = (num.re * thick + num.im * preal) / brm;
        quo.im = (num.im * thick - num.re * preal) / brm;
      } else {
        rough = thick / preal;
        preal += rough * thick;
        quo.re = (rough * num.re + num.im) / preal;
        quo.im = (rough * num.im - num.re) / preal;
      }
    }

    out[loop] = rt_hypotd_snf(quo.re, quo.im);
  }
}

//
// File trailer for abeles_paraPoints.cpp
//
// [EOF]
//
