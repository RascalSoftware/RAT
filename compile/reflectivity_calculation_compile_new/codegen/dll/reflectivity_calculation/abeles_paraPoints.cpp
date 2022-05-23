//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// abeles_paraPoints.cpp
//
// Code generation for function 'abeles_paraPoints'
//

// Include files
#include "abeles_paraPoints.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
void abeles_paraPoints(const coder::array<double, 1U> &x,
                       const coder::array<double, 2U> &sld, double nbair,
                       double nbsub, double nrepeats, double rsub,
                       double layers, double points,
                       coder::array<double, 1U> &out)
{
  creal_T MI[2][2];
  creal_T N[2][2];
  creal_T b_MI[2][2];
  creal_T beta;
  creal_T blast;
  creal_T num;
  creal_T pimag;
  creal_T psub;
  creal_T quo;
  double ar;
  double brm;
  double d;
  double d1;
  double im;
  double preal;
  double preal_tmp;
  double quo_re;
  double re;
  double rough;
  double snair;
  double snsub;
  double thick;
  double x_im;
  double x_re;
  int i;
  int i1;
  int i2;
  int loop;
  int nl;
  int reploop;
  int ub_loop;
  //  nbair = nbairs(thisCont);
  //  nbsub = nbsubs(thisCont);
  //  ssub = ssubs(thisCont);
  //  nrepeats = nrepeatss(thisCont);
  //  resol = resols(thisCont);
  out.set_size(static_cast<int>(points));
  // pi = 3.141592653589;
  snair = 1.0 - nbair * 0.377451863036739;
  snsub = 1.0 - nbsub * 0.377451863036739;
  ub_loop = static_cast<int>(points) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    quo, num, MI, beta, pimag, preal, rough, thick, blast, psub, N, loop,      \
    preal_tmp, i, reploop, re, i1, nl, im, ar, d, quo_re, x_re, x_im, d1, i2,  \
    brm, b_MI)

  for (loop = 0; loop <= ub_loop; loop++) {
    thick = std::asin(x[loop] * 1.54 / 12.566370614359172);
    preal = std::cos(thick);
    preal_tmp = snair * snair * (preal * preal);
    preal = snsub * snsub - preal_tmp;
    psub.re = preal;
    psub.im = preal * 0.0;
    coder::internal::scalar::b_sqrt(&psub);
    preal = snair * std::sin(thick);
    quo.re = preal;
    quo.im = preal * 0.0;
    blast.re = 0.0;
    blast.im = 0.0;
    MI[0][0].re = 1.0;
    MI[0][0].im = 0.0;
    MI[1][1].re = 1.0;
    MI[1][1].im = 0.0;
    MI[1][0].re = 0.0;
    MI[1][0].im = 0.0;
    MI[0][1].re = 0.0;
    MI[0][1].im = 0.0;
    i = static_cast<int>(nrepeats);
    for (reploop = 0; reploop < i; reploop++) {
      i1 = static_cast<int>(layers);
      for (nl = 0; nl < i1; nl++) {
        thick = sld[nl];
        preal = sld[nl + sld.size(0)];
        rough = sld[nl + sld.size(0) * 2];
        preal = 1.0 - preal * 0.377451863036739;
        preal = preal * preal - preal_tmp;
        pimag.re = preal;
        pimag.im = preal * 0.0;
        coder::internal::scalar::b_sqrt(&pimag);
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
          d = num.re;
          num.re = std::exp(d);
          num.im = 0.0;
        } else if (std::isinf(num.im) && std::isinf(num.re) && (num.re < 0.0)) {
          num.re = 0.0;
          num.im = 0.0;
        } else {
          preal = std::exp(num.re / 2.0);
          d = num.im;
          d1 = num.im;
          num.re = preal * (preal * std::cos(d));
          num.im = preal * (preal * std::sin(d1));
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
        } else if (std::isinf(x_im) && std::isinf(x_re) && (x_re < 0.0)) {
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
          d = quo.re;
          quo.re = std::exp(d);
          quo.im = 0.0;
        } else if (std::isinf(quo.im) && std::isinf(quo.re) && (quo.re < 0.0)) {
          quo.re = 0.0;
          quo.im = 0.0;
        } else {
          preal = std::exp(quo.re / 2.0);
          d = quo.im;
          d1 = quo.im;
          quo.re = preal * (preal * std::cos(d));
          quo.im = preal * (preal * std::sin(d1));
        }
        d = re * quo.re - im * quo.im;
        d1 = re * quo.im + im * quo.re;
        N[1][1] = quo;
        ar = re * x_re - im * x_im;
        preal = re * x_im + im * x_re;
        quo = pimag;
        blast = beta;
        thick = N[1][1].re;
        rough = N[1][1].im;
        for (i2 = 0; i2 < 2; i2++) {
          im = MI[0][i2].re;
          re = MI[0][i2].im;
          brm = MI[1][i2].re;
          quo_re = MI[1][i2].im;
          b_MI[0][i2].re = (im * x_re - re * x_im) + (brm * d - quo_re * d1);
          b_MI[0][i2].im = (im * x_im + re * x_re) + (brm * d1 + quo_re * d);
          b_MI[1][i2].re =
              (im * ar - re * preal) + (brm * thick - quo_re * rough);
          b_MI[1][i2].im =
              (im * preal + re * ar) + (brm * rough + quo_re * thick);
        }
        MI[0][0] = b_MI[0][0];
        MI[0][1] = b_MI[0][1];
        MI[1][0] = b_MI[1][0];
        MI[1][1] = b_MI[1][1];
      }
    }
    re = -78.956835208714864 * quo.re;
    im = -78.956835208714864 * quo.im;
    thick = rsub * rsub;
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
      d = num.re;
      num.re = std::exp(d);
      num.im = 0.0;
    } else if (std::isinf(num.im) && std::isinf(num.re) && (num.re < 0.0)) {
      num.re = 0.0;
      num.im = 0.0;
    } else {
      preal = std::exp(num.re / 2.0);
      d = num.im;
      d1 = num.im;
      num.re = preal * (preal * std::cos(d));
      num.im = preal * (preal * std::sin(d1));
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
    } else if (std::isinf(x_im) && std::isinf(x_re) && (x_re < 0.0)) {
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
      d = quo.re;
      quo.re = std::exp(d);
      quo.im = 0.0;
    } else if (std::isinf(quo.im) && std::isinf(quo.re) && (quo.re < 0.0)) {
      quo.re = 0.0;
      quo.im = 0.0;
    } else {
      preal = std::exp(quo.re / 2.0);
      d = quo.im;
      d1 = quo.im;
      quo.re = preal * (preal * std::cos(d));
      quo.im = preal * (preal * std::sin(d1));
    }
    d = re * quo.re - im * quo.im;
    d1 = re * quo.im + im * quo.re;
    ar = re * x_re - im * x_im;
    preal = re * x_im + im * x_re;
    for (i = 0; i < 2; i++) {
      thick = MI[0][i].re;
      rough = MI[0][i].im;
      im = MI[1][i].re;
      re = MI[1][i].im;
      b_MI[0][i].re = (thick * x_re - rough * x_im) + (im * d - re * d1);
      b_MI[0][i].im = (thick * x_im + rough * x_re) + (im * d1 + re * d);
      b_MI[1][i].re =
          (thick * ar - rough * preal) + (im * quo.re - re * quo.im);
      b_MI[1][i].im =
          (thick * preal + rough * ar) + (im * quo.im + re * quo.re);
    }
    num.re = b_MI[0][1].re * b_MI[0][1].re - b_MI[0][1].im * -b_MI[0][1].im;
    num.im = b_MI[0][1].re * -b_MI[0][1].im + b_MI[0][1].im * b_MI[0][1].re;
    thick = b_MI[0][0].re * b_MI[0][0].re - b_MI[0][0].im * -b_MI[0][0].im;
    preal = b_MI[0][0].re * -b_MI[0][0].im + b_MI[0][0].im * b_MI[0][0].re;
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

// End of code generation (abeles_paraPoints.cpp)
