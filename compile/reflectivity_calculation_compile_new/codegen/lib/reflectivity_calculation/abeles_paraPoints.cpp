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
#include "abs.h"
#include "asin.h"
#include "cos.h"
#include "exp.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include "sqrt.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>

// Function Definitions
void abeles_paraPoints(const coder::array<double, 1U> &x,
                       const coder::array<double, 2U> &sld, double nbair,
                       double nbsub, double nrepeats, double rsub,
                       double layers, double points,
                       coder::array<double, 1U> &out)
{
  creal_T MI[4];
  creal_T N[4];
  creal_T b_MI[4];
  creal_T beta;
  creal_T blast;
  creal_T num;
  creal_T pimag;
  creal_T psub;
  creal_T quo;
  double ai;
  double ar;
  double brm;
  double d;
  double d1;
  double preal;
  double preal_tmp;
  double quo_re;
  double re;
  double rough;
  double snair;
  double snsub;
  double thick;
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
    preal_tmp, i, i1, reploop, re, nl, ar, ai, quo_re, d, d1, i2, brm)         \
    firstprivate(b_MI)

  for (loop = 0; loop <= ub_loop; loop++) {
    thick = x[loop] * 1.54 / 12.566370614359172;
    coder::b_asin(&thick);
    preal = thick;
    coder::b_cos(&preal);
    preal_tmp = snair * snair * (preal * preal);
    preal = snsub * snsub - preal_tmp;
    psub.re = preal;
    psub.im = preal * 0.0;
    coder::b_sqrt(&psub);
    coder::b_sin(&thick);
    preal = snair * thick;
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
        coder::b_sqrt(&pimag);
        beta.re = 4.0799904592075231 * thick * pimag.re;
        beta.im = 4.0799904592075231 * thick * pimag.im;
        re = -78.956835208714864 * quo.re;
        preal = -78.956835208714864 * quo.im;
        thick = rough * rough;
        ar = (re * pimag.re - preal * pimag.im) * thick;
        ai = (re * pimag.im + preal * pimag.re) * thick;
        if (ai == 0.0) {
          num.re = ar / 2.3716;
          num.im = 0.0;
        } else if (ar == 0.0) {
          num.re = 0.0;
          num.im = ai / 2.3716;
        } else {
          num.re = ar / 2.3716;
          num.im = ai / 2.3716;
        }
        coder::b_exp(&num);
        ar = quo.re - pimag.re;
        ai = quo.im - pimag.im;
        preal = quo.re + pimag.re;
        re = quo.im + pimag.im;
        if (re == 0.0) {
          if (ai == 0.0) {
            quo_re = ar / preal;
            preal = 0.0;
          } else if (ar == 0.0) {
            quo_re = 0.0;
            preal = ai / preal;
          } else {
            quo_re = ar / preal;
            preal = ai / preal;
          }
        } else if (preal == 0.0) {
          if (ar == 0.0) {
            quo_re = ai / re;
            preal = 0.0;
          } else if (ai == 0.0) {
            quo_re = 0.0;
            preal = -(ar / re);
          } else {
            quo_re = ai / re;
            preal = -(ar / re);
          }
        } else {
          brm = std::abs(preal);
          rough = std::abs(re);
          if (brm > rough) {
            rough = re / preal;
            preal += rough * re;
            quo_re = (ar + rough * ai) / preal;
            preal = (ai - rough * ar) / preal;
          } else if (rough == brm) {
            if (preal > 0.0) {
              thick = 0.5;
            } else {
              thick = -0.5;
            }
            if (re > 0.0) {
              preal = 0.5;
            } else {
              preal = -0.5;
            }
            quo_re = (ar * thick + ai * preal) / brm;
            preal = (ai * thick - ar * preal) / brm;
          } else {
            rough = preal / re;
            preal = re + rough * preal;
            quo_re = (rough * ar + ai) / preal;
            preal = (rough * ai - ar) / preal;
          }
        }
        re = quo_re * num.re - preal * num.im;
        preal = quo_re * num.im + preal * num.re;
        num.re = blast.re * 0.0 - blast.im;
        num.im = blast.re + blast.im * 0.0;
        coder::b_exp(&num);
        quo.re = -blast.re * 0.0 - (-blast.im);
        quo.im = -blast.re + -blast.im * 0.0;
        coder::b_exp(&quo);
        ar = re * quo.re - preal * quo.im;
        d = re * quo.im + preal * quo.re;
        N[3] = quo;
        d1 = re * num.re - preal * num.im;
        preal = re * num.im + preal * num.re;
        quo = pimag;
        blast = beta;
        thick = N[3].re;
        rough = N[3].im;
        for (i2 = 0; i2 < 2; i2++) {
          re = MI[i2].re;
          ai = MI[i2].im;
          brm = MI[i2 + 2].re;
          quo_re = MI[i2 + 2].im;
          b_MI[i2].re = (re * num.re - ai * num.im) + (brm * ar - quo_re * d);
          b_MI[i2].im = (re * num.im + ai * num.re) + (brm * d + quo_re * ar);
          b_MI[i2 + 2].re =
              (re * d1 - ai * preal) + (brm * thick - quo_re * rough);
          b_MI[i2 + 2].im =
              (re * preal + ai * d1) + (brm * rough + quo_re * thick);
        }
        std::copy(&b_MI[0], &b_MI[4], &MI[0]);
      }
    }
    re = -78.956835208714864 * quo.re;
    preal = -78.956835208714864 * quo.im;
    thick = rsub * rsub;
    ar = (re * psub.re - preal * psub.im) * thick;
    ai = (re * psub.im + preal * psub.re) * thick;
    if (ai == 0.0) {
      num.re = ar / 2.3716;
      num.im = 0.0;
    } else if (ar == 0.0) {
      num.re = 0.0;
      num.im = ai / 2.3716;
    } else {
      num.re = ar / 2.3716;
      num.im = ai / 2.3716;
    }
    coder::b_exp(&num);
    ar = quo.re - psub.re;
    ai = quo.im - psub.im;
    preal = quo.re + psub.re;
    re = quo.im + psub.im;
    if (re == 0.0) {
      if (ai == 0.0) {
        quo_re = ar / preal;
        preal = 0.0;
      } else if (ar == 0.0) {
        quo_re = 0.0;
        preal = ai / preal;
      } else {
        quo_re = ar / preal;
        preal = ai / preal;
      }
    } else if (preal == 0.0) {
      if (ar == 0.0) {
        quo_re = ai / re;
        preal = 0.0;
      } else if (ai == 0.0) {
        quo_re = 0.0;
        preal = -(ar / re);
      } else {
        quo_re = ai / re;
        preal = -(ar / re);
      }
    } else {
      brm = std::abs(preal);
      rough = std::abs(re);
      if (brm > rough) {
        rough = re / preal;
        preal += rough * re;
        quo_re = (ar + rough * ai) / preal;
        preal = (ai - rough * ar) / preal;
      } else if (rough == brm) {
        if (preal > 0.0) {
          thick = 0.5;
        } else {
          thick = -0.5;
        }
        if (re > 0.0) {
          preal = 0.5;
        } else {
          preal = -0.5;
        }
        quo_re = (ar * thick + ai * preal) / brm;
        preal = (ai * thick - ar * preal) / brm;
      } else {
        rough = preal / re;
        preal = re + rough * preal;
        quo_re = (rough * ar + ai) / preal;
        preal = (rough * ai - ar) / preal;
      }
    }
    re = quo_re * num.re - preal * num.im;
    preal = quo_re * num.im + preal * num.re;
    num.re = blast.re * 0.0 - blast.im;
    num.im = blast.re + blast.im * 0.0;
    coder::b_exp(&num);
    quo.re = -blast.re * 0.0 - (-blast.im);
    quo.im = -blast.re + -blast.im * 0.0;
    coder::b_exp(&quo);
    ar = re * quo.re - preal * quo.im;
    d = re * quo.im + preal * quo.re;
    d1 = re * num.re - preal * num.im;
    preal = re * num.im + preal * num.re;
    for (i = 0; i < 2; i++) {
      thick = MI[i].re;
      rough = MI[i].im;
      re = MI[i + 2].re;
      ai = MI[i + 2].im;
      b_MI[i].re = (thick * num.re - rough * num.im) + (re * ar - ai * d);
      b_MI[i].im = (thick * num.im + rough * num.re) + (re * d + ai * ar);
      b_MI[i + 2].re =
          (thick * d1 - rough * preal) + (re * quo.re - ai * quo.im);
      b_MI[i + 2].im =
          (thick * preal + rough * d1) + (re * quo.im + ai * quo.re);
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
    out[loop] = coder::b_abs(quo);
  }
}

// End of code generation (abeles_paraPoints.cpp)
