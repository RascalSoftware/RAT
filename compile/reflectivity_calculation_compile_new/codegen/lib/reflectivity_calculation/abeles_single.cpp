//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// abeles_single.cpp
//
// Code generation for function 'abeles_single'
//

// Include files
#include "abeles_single.h"
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
void abeles_single(const coder::array<double, 1U> &x,
                   const coder::array<double, 2U> &sld, double nbair,
                   double nbsub, double nrepeats, double rsub, double layers,
                   double points, coder::array<double, 1U> &out)
{
  creal_T MI[4];
  creal_T N[4];
  creal_T b_MI[4];
  creal_T N_tmp;
  creal_T pair;
  creal_T pimag;
  creal_T psub;
  creal_T rij;
  double ar_tmp;
  double snair;
  double snlay;
  double snsub;
  double theta;
  int i;
  int i1;
  int i2;
  //  nbair = nbairs(thisCont);
  //  nbsub = nbsubs(thisCont);
  //  ssub = ssubs(thisCont);
  //  nrepeats = nrepeatss(thisCont);
  //  resol = resols(thisCont);
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
    ar_tmp = rsub * rsub;
  }
  for (int loop{0}; loop < i; loop++) {
    double ar;
    double bim;
    double blast_im;
    double blast_re;
    double brm;
    double d;
    double d1;
    double pair_re;
    double psub_tmp_tmp;
    double re;
    double rough;
    int i3;
    theta = x[loop] * 1.54 / 12.566370614359172;
    coder::b_asin(&theta);
    snlay = theta;
    coder::b_cos(&snlay);
    psub_tmp_tmp = snair * snair * (snlay * snlay);
    snlay = snsub * snsub - psub_tmp_tmp;
    psub.re = snlay;
    psub.im = snlay * 0.0;
    coder::b_sqrt(&psub);
    coder::b_sin(&theta);
    snlay = snair * theta;
    pair.re = snlay;
    pair.im = snlay * 0.0;
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
    for (int reploop{0}; reploop < i1; reploop++) {
      for (int nl{0}; nl < i2; nl++) {
        rough = sld[nl + sld.size(0) * 2];
        snlay = 1.0 - sld[nl + sld.size(0)] * 0.377451863036739;
        theta = snlay * snlay - psub_tmp_tmp;
        pimag.re = theta;
        pimag.im = theta * 0.0;
        coder::b_sqrt(&pimag);
        re = -78.956835208714864 * pair.re;
        snlay = -78.956835208714864 * pair.im;
        theta = rough * rough;
        ar = (re * pimag.re - snlay * pimag.im) * theta;
        rough = (re * pimag.im + snlay * pimag.re) * theta;
        if (rough == 0.0) {
          rij.re = ar / 2.3716;
          rij.im = 0.0;
        } else if (ar == 0.0) {
          rij.re = 0.0;
          rij.im = rough / 2.3716;
        } else {
          rij.re = ar / 2.3716;
          rij.im = rough / 2.3716;
        }
        coder::b_exp(&rij);
        ar = pair.re - pimag.re;
        rough = pair.im - pimag.im;
        theta = pair.re + pimag.re;
        snlay = pair.im + pimag.im;
        if (snlay == 0.0) {
          if (rough == 0.0) {
            pair_re = ar / theta;
            theta = 0.0;
          } else if (ar == 0.0) {
            pair_re = 0.0;
            theta = rough / theta;
          } else {
            pair_re = ar / theta;
            theta = rough / theta;
          }
        } else if (theta == 0.0) {
          if (ar == 0.0) {
            pair_re = rough / snlay;
            theta = 0.0;
          } else if (rough == 0.0) {
            pair_re = 0.0;
            theta = -(ar / snlay);
          } else {
            pair_re = rough / snlay;
            theta = -(ar / snlay);
          }
        } else {
          brm = std::abs(theta);
          bim = std::abs(snlay);
          if (brm > bim) {
            bim = snlay / theta;
            theta += bim * snlay;
            pair_re = (ar + bim * rough) / theta;
            theta = (rough - bim * ar) / theta;
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
            theta = (rough * bim - ar * theta) / brm;
          } else {
            bim = theta / snlay;
            theta = snlay + bim * theta;
            pair_re = (bim * ar + rough) / theta;
            theta = (bim * rough - ar) / theta;
          }
        }
        re = pair_re * rij.re - theta * rij.im;
        snlay = pair_re * rij.im + theta * rij.re;
        N_tmp.re = blast_re * 0.0 - blast_im;
        N_tmp.im = blast_re + blast_im * 0.0;
        coder::b_exp(&N_tmp);
        pair.re = -blast_re * 0.0 - (-blast_im);
        pair.im = -blast_re + -blast_im * 0.0;
        coder::b_exp(&pair);
        ar = re * pair.re - snlay * pair.im;
        d = re * pair.im + snlay * pair.re;
        N[3] = pair;
        d1 = re * N_tmp.re - snlay * N_tmp.im;
        theta = re * N_tmp.im + snlay * N_tmp.re;
        pair = pimag;
        blast_re = 4.0799904592075231 * sld[nl] * pimag.re;
        blast_im = 4.0799904592075231 * sld[nl] * pimag.im;
        snlay = N[3].re;
        rough = N[3].im;
        for (i3 = 0; i3 < 2; i3++) {
          re = MI[i3].re;
          bim = MI[i3].im;
          pair_re = MI[i3 + 2].re;
          brm = MI[i3 + 2].im;
          b_MI[i3].re =
              (re * N_tmp.re - bim * N_tmp.im) + (pair_re * ar - brm * d);
          b_MI[i3].im =
              (re * N_tmp.im + bim * N_tmp.re) + (pair_re * d + brm * ar);
          b_MI[i3 + 2].re =
              (re * d1 - bim * theta) + (pair_re * snlay - brm * rough);
          b_MI[i3 + 2].im =
              (re * theta + bim * d1) + (pair_re * rough + brm * snlay);
        }
        std::copy(&b_MI[0], &b_MI[4], &MI[0]);
      }
    }
    re = -78.956835208714864 * pair.re;
    snlay = -78.956835208714864 * pair.im;
    ar = (re * psub.re - snlay * psub.im) * ar_tmp;
    rough = (re * psub.im + snlay * psub.re) * ar_tmp;
    if (rough == 0.0) {
      rij.re = ar / 2.3716;
      rij.im = 0.0;
    } else if (ar == 0.0) {
      rij.re = 0.0;
      rij.im = rough / 2.3716;
    } else {
      rij.re = ar / 2.3716;
      rij.im = rough / 2.3716;
    }
    coder::b_exp(&rij);
    ar = pair.re - psub.re;
    rough = pair.im - psub.im;
    theta = pair.re + psub.re;
    snlay = pair.im + psub.im;
    if (snlay == 0.0) {
      if (rough == 0.0) {
        pair_re = ar / theta;
        theta = 0.0;
      } else if (ar == 0.0) {
        pair_re = 0.0;
        theta = rough / theta;
      } else {
        pair_re = ar / theta;
        theta = rough / theta;
      }
    } else if (theta == 0.0) {
      if (ar == 0.0) {
        pair_re = rough / snlay;
        theta = 0.0;
      } else if (rough == 0.0) {
        pair_re = 0.0;
        theta = -(ar / snlay);
      } else {
        pair_re = rough / snlay;
        theta = -(ar / snlay);
      }
    } else {
      brm = std::abs(theta);
      bim = std::abs(snlay);
      if (brm > bim) {
        bim = snlay / theta;
        theta += bim * snlay;
        pair_re = (ar + bim * rough) / theta;
        theta = (rough - bim * ar) / theta;
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
        theta = (rough * bim - ar * theta) / brm;
      } else {
        bim = theta / snlay;
        theta = snlay + bim * theta;
        pair_re = (bim * ar + rough) / theta;
        theta = (bim * rough - ar) / theta;
      }
    }
    re = pair_re * rij.re - theta * rij.im;
    snlay = pair_re * rij.im + theta * rij.re;
    N_tmp.re = blast_re * 0.0 - blast_im;
    N_tmp.im = blast_re + blast_im * 0.0;
    coder::b_exp(&N_tmp);
    pair.re = -blast_re * 0.0 - (-blast_im);
    pair.im = -blast_re + -blast_im * 0.0;
    coder::b_exp(&pair);
    ar = re * pair.re - snlay * pair.im;
    d = re * pair.im + snlay * pair.re;
    d1 = re * N_tmp.re - snlay * N_tmp.im;
    theta = re * N_tmp.im + snlay * N_tmp.re;
    for (i3 = 0; i3 < 2; i3++) {
      snlay = MI[i3].re;
      rough = MI[i3].im;
      re = MI[i3 + 2].re;
      bim = MI[i3 + 2].im;
      b_MI[i3].re = (snlay * N_tmp.re - rough * N_tmp.im) + (re * ar - bim * d);
      b_MI[i3].im = (snlay * N_tmp.im + rough * N_tmp.re) + (re * d + bim * ar);
      b_MI[i3 + 2].re =
          (snlay * d1 - rough * theta) + (re * pair.re - bim * pair.im);
      b_MI[i3 + 2].im =
          (snlay * theta + rough * d1) + (re * pair.im + bim * pair.re);
    }
    rough = b_MI[1].re * b_MI[1].re - b_MI[1].im * -b_MI[1].im;
    re = b_MI[1].re * -b_MI[1].im + b_MI[1].im * b_MI[1].re;
    theta = b_MI[0].re * b_MI[0].re - b_MI[0].im * -b_MI[0].im;
    snlay = b_MI[0].re * -b_MI[0].im + b_MI[0].im * b_MI[0].re;
    if (snlay == 0.0) {
      if (re == 0.0) {
        psub.re = rough / theta;
        psub.im = 0.0;
      } else if (rough == 0.0) {
        psub.re = 0.0;
        psub.im = re / theta;
      } else {
        psub.re = rough / theta;
        psub.im = re / theta;
      }
    } else if (theta == 0.0) {
      if (rough == 0.0) {
        psub.re = re / snlay;
        psub.im = 0.0;
      } else if (re == 0.0) {
        psub.re = 0.0;
        psub.im = -(rough / snlay);
      } else {
        psub.re = re / snlay;
        psub.im = -(rough / snlay);
      }
    } else {
      brm = std::abs(theta);
      bim = std::abs(snlay);
      if (brm > bim) {
        bim = snlay / theta;
        theta += bim * snlay;
        psub.re = (rough + bim * re) / theta;
        psub.im = (re - bim * rough) / theta;
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
        psub.re = (rough * bim + re * theta) / brm;
        psub.im = (re * bim - rough * theta) / brm;
      } else {
        bim = theta / snlay;
        theta = snlay + bim * theta;
        psub.re = (bim * rough + re) / theta;
        psub.im = (bim * re - rough) / theta;
      }
    }
    out[loop] = coder::b_abs(psub);
  }
}

// End of code generation (abeles_single.cpp)
