//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: abeles_single.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "abeles_single.h"
#include "abeles_paraPoints.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include <math.h>
#include <string.h>

// Function Definitions

//
// nbair = nbairs(thisCont);
//  nbsub = nbsubs(thisCont);
//  ssub = ssubs(thisCont);
//  nrepeats = nrepeatss(thisCont);
//  resol = resols(thisCont);
// Arguments    : const coder::array<double, 2U> *x
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
void abeles_single(const coder::array<double, 2U> &x, const coder::array<double,
                   2U> &sld, double nbair, double nbsub, double nrepeats, double
                   rfinal, double layers, double points, coder::array<double, 1U>
                   &out)
{
  int i;
  double snair;
  double snsub;
  int i1;
  int i2;
  double theta;
  double ar_tmp;
  creal_T psub;
  creal_T MI[4];
  creal_T pimag;
  creal_T b_MI[4];
  i = static_cast<int>(points);
  out.set_size(i);

  // pi = 3.141592653589;
  snair = 1.0 - nbair * 0.377451863036739;
  snsub = 1.0 - nbsub * 0.377451863036739;
  if (0 <= i - 1) {
    i1 = static_cast<int>(nrepeats);
    if (0 <= i1 - 1) {
      i2 = static_cast<int>(layers);
    }

    ar_tmp = rfinal * rfinal;
  }

  for (int loop = 0; loop < i; loop++) {
    double snlay;
    double psub_tmp_tmp;
    double pair_re;
    double pair_im;
    double blast_re;
    double blast_im;
    double re;
    double ar;
    double rough;
    double rij_re;
    double rij_im;
    double brm;
    double bim;
    double x_re;
    double x_im;
    int i3;
    theta = asin(x[loop] * 1.54 / 12.566370614359172);
    snlay = cos(theta);
    psub_tmp_tmp = snair * snair * (snlay * snlay);
    snlay = snsub * snsub - psub_tmp_tmp;
    psub.re = snlay;
    psub.im = snlay * 0.0;
    b_sqrt(&psub);
    pair_re = snair * sin(theta);
    pair_im = pair_re * 0.0;
    blast_re = 0.0;
    blast_im = 0.0;
    MI[0].re = 1.0;
    MI[0].im = 0.0;
    MI[3].re = 1.0;
    MI[3].im = 0.0;
    MI[2].re = 0.0;
    MI[2].im = 0.0;
    MI[1].re = 0.0;
    MI[1].im = 0.0;
    for (int reploop = 0; reploop < i1; reploop++) {
      for (int nl = 0; nl < i2; nl++) {
        rough = sld[nl + sld.size(0) * 2];
        snlay = 1.0 - sld[nl + sld.size(0)] * 0.377451863036739;
        theta = snlay * snlay - psub_tmp_tmp;
        pimag.re = theta;
        pimag.im = theta * 0.0;
        b_sqrt(&pimag);
        re = -78.956835208714864 * pair_re;
        snlay = -78.956835208714864 * pair_im;
        theta = rough * rough;
        ar = (re * pimag.re - snlay * pimag.im) * theta;
        rough = (re * pimag.im + snlay * pimag.re) * theta;
        if (rough == 0.0) {
          rij_re = ar / 2.3716;
          rij_im = 0.0;
        } else if (ar == 0.0) {
          rij_re = 0.0;
          rij_im = rough / 2.3716;
        } else {
          rij_re = ar / 2.3716;
          rij_im = rough / 2.3716;
        }

        if (rij_im == 0.0) {
          rij_re = exp(rij_re);
          rij_im = 0.0;
        } else if (rtIsInf(rij_im) && rtIsInf(rij_re) && (rij_re < 0.0)) {
          rij_re = 0.0;
          rij_im = 0.0;
        } else {
          theta = exp(rij_re / 2.0);
          rij_re = theta * (theta * cos(rij_im));
          rij_im = theta * (theta * sin(rij_im));
        }

        ar = pair_re - pimag.re;
        rough = pair_im - pimag.im;
        theta = pair_re + pimag.re;
        snlay = pair_im + pimag.im;
        if (snlay == 0.0) {
          if (rough == 0.0) {
            pair_re = ar / theta;
            pair_im = 0.0;
          } else if (ar == 0.0) {
            pair_re = 0.0;
            pair_im = rough / theta;
          } else {
            pair_re = ar / theta;
            pair_im = rough / theta;
          }
        } else if (theta == 0.0) {
          if (ar == 0.0) {
            pair_re = rough / snlay;
            pair_im = 0.0;
          } else if (rough == 0.0) {
            pair_re = 0.0;
            pair_im = -(ar / snlay);
          } else {
            pair_re = rough / snlay;
            pair_im = -(ar / snlay);
          }
        } else {
          brm = fabs(theta);
          bim = fabs(snlay);
          if (brm > bim) {
            bim = snlay / theta;
            theta += bim * snlay;
            pair_re = (ar + bim * rough) / theta;
            pair_im = (rough - bim * ar) / theta;
          } else if (bim == brm) {
            if (theta > 0.0) {
              bim = 0.5;
            } else {
              bim = -0.5;
            }

            if (snlay > 0.0) {
              theta = 0.5;
            } else {
              theta = -0.5;
            }

            pair_re = (ar * bim + rough * theta) / brm;
            pair_im = (rough * bim - ar * theta) / brm;
          } else {
            bim = theta / snlay;
            theta = snlay + bim * theta;
            pair_re = (bim * ar + rough) / theta;
            pair_im = (bim * rough - ar) / theta;
          }
        }

        re = pair_re * rij_re - pair_im * rij_im;
        snlay = pair_re * rij_im + pair_im * rij_re;
        x_re = blast_re * 0.0 - blast_im;
        x_im = blast_re + blast_im * 0.0;
        if (x_im == 0.0) {
          x_re = exp(x_re);
          x_im = 0.0;
        } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          theta = exp(x_re / 2.0);
          x_re = theta * (theta * cos(x_im));
          x_im = theta * (theta * sin(x_im));
        }

        pair_re = -blast_re * 0.0 - (-blast_im);
        pair_im = -blast_re + -blast_im * 0.0;
        if (pair_im == 0.0) {
          pair_re = exp(pair_re);
          pair_im = 0.0;
        } else if (rtIsInf(pair_im) && rtIsInf(pair_re) && (pair_re < 0.0)) {
          pair_re = 0.0;
          pair_im = 0.0;
        } else {
          theta = exp(pair_re / 2.0);
          pair_re = theta * (theta * cos(pair_im));
          pair_im = theta * (theta * sin(pair_im));
        }

        rij_re = re * pair_re - snlay * pair_im;
        bim = re * pair_im + snlay * pair_re;
        brm = pair_re;
        rij_im = pair_im;
        ar = re * x_re - snlay * x_im;
        theta = re * x_im + snlay * x_re;
        pair_re = pimag.re;
        pair_im = pimag.im;
        blast_re = 4.0799904592075231 * sld[nl] * pimag.re;
        blast_im = 4.0799904592075231 * sld[nl] * pimag.im;
        for (i3 = 0; i3 < 2; i3++) {
          snlay = MI[i3 + 2].re;
          rough = MI[i3 + 2].im;
          b_MI[i3].re = (MI[i3].re * x_re - MI[i3].im * x_im) + (snlay * rij_re
            - rough * bim);
          b_MI[i3].im = (MI[i3].re * x_im + MI[i3].im * x_re) + (snlay * bim +
            rough * rij_re);
          b_MI[i3 + 2].re = (MI[i3].re * ar - MI[i3].im * theta) + (snlay * brm
            - rough * rij_im);
          b_MI[i3 + 2].im = (MI[i3].re * theta + MI[i3].im * ar) + (snlay *
            rij_im + rough * brm);
        }

        memcpy(&MI[0], &b_MI[0], 4U * sizeof(creal_T));
      }
    }

    re = -78.956835208714864 * pair_re;
    snlay = -78.956835208714864 * pair_im;
    ar = (re * psub.re - snlay * psub.im) * ar_tmp;
    rough = (re * psub.im + snlay * psub.re) * ar_tmp;
    if (rough == 0.0) {
      rij_re = ar / 2.3716;
      rij_im = 0.0;
    } else if (ar == 0.0) {
      rij_re = 0.0;
      rij_im = rough / 2.3716;
    } else {
      rij_re = ar / 2.3716;
      rij_im = rough / 2.3716;
    }

    if (rij_im == 0.0) {
      rij_re = exp(rij_re);
      rij_im = 0.0;
    } else if (rtIsInf(rij_im) && rtIsInf(rij_re) && (rij_re < 0.0)) {
      rij_re = 0.0;
      rij_im = 0.0;
    } else {
      theta = exp(rij_re / 2.0);
      rij_re = theta * (theta * cos(rij_im));
      rij_im = theta * (theta * sin(rij_im));
    }

    ar = pair_re - psub.re;
    rough = pair_im - psub.im;
    theta = pair_re + psub.re;
    snlay = pair_im + psub.im;
    if (snlay == 0.0) {
      if (rough == 0.0) {
        pair_re = ar / theta;
        pair_im = 0.0;
      } else if (ar == 0.0) {
        pair_re = 0.0;
        pair_im = rough / theta;
      } else {
        pair_re = ar / theta;
        pair_im = rough / theta;
      }
    } else if (theta == 0.0) {
      if (ar == 0.0) {
        pair_re = rough / snlay;
        pair_im = 0.0;
      } else if (rough == 0.0) {
        pair_re = 0.0;
        pair_im = -(ar / snlay);
      } else {
        pair_re = rough / snlay;
        pair_im = -(ar / snlay);
      }
    } else {
      brm = fabs(theta);
      bim = fabs(snlay);
      if (brm > bim) {
        bim = snlay / theta;
        theta += bim * snlay;
        pair_re = (ar + bim * rough) / theta;
        pair_im = (rough - bim * ar) / theta;
      } else if (bim == brm) {
        if (theta > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        if (snlay > 0.0) {
          theta = 0.5;
        } else {
          theta = -0.5;
        }

        pair_re = (ar * bim + rough * theta) / brm;
        pair_im = (rough * bim - ar * theta) / brm;
      } else {
        bim = theta / snlay;
        theta = snlay + bim * theta;
        pair_re = (bim * ar + rough) / theta;
        pair_im = (bim * rough - ar) / theta;
      }
    }

    re = pair_re * rij_re - pair_im * rij_im;
    snlay = pair_re * rij_im + pair_im * rij_re;
    x_re = blast_re * 0.0 - blast_im;
    x_im = blast_re + blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = exp(x_re);
      x_im = 0.0;
    } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      theta = exp(x_re / 2.0);
      x_re = theta * (theta * cos(x_im));
      x_im = theta * (theta * sin(x_im));
    }

    pair_re = -blast_re * 0.0 - (-blast_im);
    pair_im = -blast_re + -blast_im * 0.0;
    if (pair_im == 0.0) {
      pair_re = exp(pair_re);
      pair_im = 0.0;
    } else if (rtIsInf(pair_im) && rtIsInf(pair_re) && (pair_re < 0.0)) {
      pair_re = 0.0;
      pair_im = 0.0;
    } else {
      theta = exp(pair_re / 2.0);
      pair_re = theta * (theta * cos(pair_im));
      pair_im = theta * (theta * sin(pair_im));
    }

    rij_re = re * pair_re - snlay * pair_im;
    bim = re * pair_im + snlay * pair_re;
    brm = re * x_re - snlay * x_im;
    rij_im = re * x_im + snlay * x_re;
    for (i3 = 0; i3 < 2; i3++) {
      ar = MI[i3 + 2].re;
      theta = MI[i3 + 2].im;
      b_MI[i3].re = (MI[i3].re * x_re - MI[i3].im * x_im) + (ar * rij_re - theta
        * bim);
      b_MI[i3].im = (MI[i3].re * x_im + MI[i3].im * x_re) + (ar * bim + theta *
        rij_re);
      b_MI[i3 + 2].re = (MI[i3].re * brm - MI[i3].im * rij_im) + (ar * pair_re -
        theta * pair_im);
      b_MI[i3 + 2].im = (MI[i3].re * rij_im + MI[i3].im * brm) + (ar * pair_im +
        theta * pair_re);
    }

    rough = b_MI[1].re * b_MI[1].re - b_MI[1].im * -b_MI[1].im;
    rij_re = b_MI[1].re * -b_MI[1].im + b_MI[1].im * b_MI[1].re;
    theta = b_MI[0].re * b_MI[0].re - b_MI[0].im * -b_MI[0].im;
    snlay = b_MI[0].re * -b_MI[0].im + b_MI[0].im * b_MI[0].re;
    if (snlay == 0.0) {
      if (rij_re == 0.0) {
        pair_re = rough / theta;
        pair_im = 0.0;
      } else if (rough == 0.0) {
        pair_re = 0.0;
        pair_im = rij_re / theta;
      } else {
        pair_re = rough / theta;
        pair_im = rij_re / theta;
      }
    } else if (theta == 0.0) {
      if (rough == 0.0) {
        pair_re = rij_re / snlay;
        pair_im = 0.0;
      } else if (rij_re == 0.0) {
        pair_re = 0.0;
        pair_im = -(rough / snlay);
      } else {
        pair_re = rij_re / snlay;
        pair_im = -(rough / snlay);
      }
    } else {
      brm = fabs(theta);
      bim = fabs(snlay);
      if (brm > bim) {
        bim = snlay / theta;
        theta += bim * snlay;
        pair_re = (rough + bim * rij_re) / theta;
        pair_im = (rij_re - bim * rough) / theta;
      } else if (bim == brm) {
        if (theta > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        if (snlay > 0.0) {
          theta = 0.5;
        } else {
          theta = -0.5;
        }

        pair_re = (rough * bim + rij_re * theta) / brm;
        pair_im = (rij_re * bim - rough * theta) / brm;
      } else {
        bim = theta / snlay;
        theta = snlay + bim * theta;
        pair_re = (bim * rough + rij_re) / theta;
        pair_im = (bim * rij_re - rough) / theta;
      }
    }

    out[loop] = rt_hypotd_snf(pair_re, pair_im);
  }
}

//
// File trailer for abeles_single.cpp
//
// [EOF]
//
