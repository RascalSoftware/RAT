/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * paratt.c
 *
 * Code generation for function 'paratt'
 *
 */

/* Include files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "paratt.h"
#include "sqrt.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_rtwutil.h"

/* Function Definitions */
void paratt(const emxArray_real_T *x, const emxArray_real_T *sld, double nbair,
            double nbsub, double nrepeats, double ssub, double layers, double
            points, emxArray_real_T *out)
{
  double snair;
  double snsub;
  int i14;
  int i15;
  int loop;
  double theta;
  double a_tmp;
  double psub_tmp_tmp;
  double rough;
  creal_T psub;
  double pair_re;
  double pair_im;
  double blast_re;
  double blast_im;
  creal_T MI[4];
  int reploop;
  double r;
  int i16;
  double im;
  int nl;
  double ar;
  double z_re;
  creal_T pimag;
  double z_im;
  double brm;
  creal_T N[4];
  creal_T b_MI[4];
  int i17;

  /*  nbair = nbairs(thisCont); */
  /*  nbsub = nbsubs(thisCont); */
  /*  ssub = ssubs(thisCont); */
  /*  nrepeats = nrepeatss(thisCont); */
  /*  resol = resols(thisCont); */
  /* pi = 3.141592653589; */
  snair = 1.0 - nbair * 3.2228875976108808;
  snsub = 1.0 - nbsub * 3.2228875976108808;
  i14 = (int)points;
  i15 = out->size[0];
  out->size[0] = i14;
  emxEnsureCapacity_real_T(out, i15);
  for (loop = 0; loop < i14; loop++) {
    theta = asin(x->data[loop] * 4.5 / 12.566370614359172);
    a_tmp = cos(theta);
    psub_tmp_tmp = snair * snair;
    rough = snsub * snsub - psub_tmp_tmp * (a_tmp * a_tmp);
    psub.re = rough;
    psub.im = rough * 0.0;
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
    i15 = (int)nrepeats;
    for (reploop = 0; reploop < i15; reploop++) {
      i16 = (int)layers;
      for (nl = 0; nl < i16; nl++) {
        rough = sld->data[nl + (sld->size[0] << 1)];
        theta = 1.0 - sld->data[nl + sld->size[0]] * 3.2228875976108808;
        theta = theta * theta - psub_tmp_tmp * (a_tmp * a_tmp);
        pimag.re = theta;
        pimag.im = theta * 0.0;
        b_sqrt(&pimag);
        r = -78.956835208714864 * pair_re;
        im = -78.956835208714864 * pair_im;
        theta = rough * rough;
        ar = (r * pimag.re - im * pimag.im) * theta;
        r = (r * pimag.im + im * pimag.re) * theta;
        if (r == 0.0) {
          z_re = ar / 20.25;
          z_im = 0.0;
        } else if (ar == 0.0) {
          z_re = 0.0;
          z_im = r / 20.25;
        } else {
          z_re = ar / 20.25;
          z_im = r / 20.25;
        }

        if (z_im == 0.0) {
          z_re = exp(z_re);
          z_im = 0.0;
        } else if (rtIsInf(z_im) && rtIsInf(z_re) && (z_re < 0.0)) {
          z_re = 0.0;
          z_im = 0.0;
        } else {
          r = exp(z_re / 2.0);
          z_re = r * (r * cos(z_im));
          z_im = r * (r * sin(z_im));
        }

        ar = pair_re - pimag.re;
        r = pair_im - pimag.im;
        theta = pair_re + pimag.re;
        rough = pair_im + pimag.im;
        if (rough == 0.0) {
          if (r == 0.0) {
            im = ar / theta;
            pair_im = 0.0;
          } else if (ar == 0.0) {
            im = 0.0;
            pair_im = r / theta;
          } else {
            im = ar / theta;
            pair_im = r / theta;
          }
        } else if (theta == 0.0) {
          if (ar == 0.0) {
            im = r / rough;
            pair_im = 0.0;
          } else if (r == 0.0) {
            im = 0.0;
            pair_im = -(ar / rough);
          } else {
            im = r / rough;
            pair_im = -(ar / rough);
          }
        } else {
          brm = fabs(theta);
          pair_im = fabs(rough);
          if (brm > pair_im) {
            pair_im = rough / theta;
            theta += pair_im * rough;
            im = (ar + pair_im * r) / theta;
            pair_im = (r - pair_im * ar) / theta;
          } else if (pair_im == brm) {
            if (theta > 0.0) {
              pair_im = 0.5;
            } else {
              pair_im = -0.5;
            }

            if (rough > 0.0) {
              theta = 0.5;
            } else {
              theta = -0.5;
            }

            im = (ar * pair_im + r * theta) / brm;
            pair_im = (r * pair_im - ar * theta) / brm;
          } else {
            pair_im = theta / rough;
            theta = rough + pair_im * theta;
            im = (pair_im * ar + r) / theta;
            pair_im = (pair_im * r - ar) / theta;
          }
        }

        pair_re = im * z_re - pair_im * z_im;
        pair_im = im * z_im + pair_im * z_re;
        z_re = blast_re * 0.0 - blast_im;
        z_im = blast_re + blast_im * 0.0;
        if (z_im == 0.0) {
          N[0].re = exp(z_re);
          N[0].im = 0.0;
        } else if (rtIsInf(z_im) && rtIsInf(z_re) && (z_re < 0.0)) {
          N[0].re = 0.0;
          N[0].im = 0.0;
        } else {
          r = exp(z_re / 2.0);
          N[0].re = r * (r * cos(z_im));
          N[0].im = r * (r * sin(z_im));
        }

        z_re = -blast_re * 0.0 - (-blast_im);
        z_im = -blast_re + -blast_im * 0.0;
        if (z_im == 0.0) {
          z_re = exp(z_re);
          z_im = 0.0;
        } else if (rtIsInf(z_im) && rtIsInf(z_re) && (z_re < 0.0)) {
          z_re = 0.0;
          z_im = 0.0;
        } else {
          r = exp(z_re / 2.0);
          z_re = r * (r * cos(z_im));
          z_im = r * (r * sin(z_im));
        }

        N[1].re = pair_re * z_re - pair_im * z_im;
        N[1].im = pair_re * z_im + pair_im * z_re;
        z_re = -blast_re * 0.0 - (-blast_im);
        z_im = -blast_re + -blast_im * 0.0;
        if (z_im == 0.0) {
          N[3].re = exp(z_re);
          N[3].im = 0.0;
        } else if (rtIsInf(z_im) && rtIsInf(z_re) && (z_re < 0.0)) {
          N[3].re = 0.0;
          N[3].im = 0.0;
        } else {
          theta = exp(z_re / 2.0);
          N[3].re = theta * (theta * cos(z_im));
          N[3].im = theta * (theta * sin(z_im));
        }

        z_re = blast_re * 0.0 - blast_im;
        z_im = blast_re + blast_im * 0.0;
        if (z_im == 0.0) {
          z_re = exp(z_re);
          z_im = 0.0;
        } else if (rtIsInf(z_im) && rtIsInf(z_re) && (z_re < 0.0)) {
          z_re = 0.0;
          z_im = 0.0;
        } else {
          r = exp(z_re / 2.0);
          z_re = r * (r * cos(z_im));
          z_im = r * (r * sin(z_im));
        }

        N[2].re = pair_re * z_re - pair_im * z_im;
        N[2].im = pair_re * z_im + pair_im * z_re;
        pair_re = pimag.re;
        pair_im = pimag.im;
        blast_re = 1.3962634015954636 * sld->data[nl] * pimag.re;
        blast_im = 1.3962634015954636 * sld->data[nl] * pimag.im;
        for (i17 = 0; i17 < 2; i17++) {
          b_MI[i17].re = (MI[i17].re * N[0].re - MI[i17].im * N[0].im) + (MI[i17
            + 2].re * N[1].re - MI[i17 + 2].im * N[1].im);
          b_MI[i17].im = (MI[i17].re * N[0].im + MI[i17].im * N[0].re) + (MI[i17
            + 2].re * N[1].im + MI[i17 + 2].im * N[1].re);
          b_MI[i17 + 2].re = (MI[i17].re * N[2].re - MI[i17].im * N[2].im) +
            (MI[i17 + 2].re * N[3].re - MI[i17 + 2].im * N[3].im);
          b_MI[i17 + 2].im = (MI[i17].re * N[2].im + MI[i17].im * N[2].re) +
            (MI[i17 + 2].re * N[3].im + MI[i17 + 2].im * N[3].re);
        }

        memcpy(&MI[0], &b_MI[0], sizeof(creal_T) << 2);
      }
    }

    r = -78.956835208714864 * pair_re;
    im = -78.956835208714864 * pair_im;
    theta = ssub * ssub;
    ar = (r * psub.re - im * psub.im) * theta;
    r = (r * psub.im + im * psub.re) * theta;
    if (r == 0.0) {
      z_re = ar / 20.25;
      z_im = 0.0;
    } else if (ar == 0.0) {
      z_re = 0.0;
      z_im = r / 20.25;
    } else {
      z_re = ar / 20.25;
      z_im = r / 20.25;
    }

    if (z_im == 0.0) {
      z_re = exp(z_re);
      z_im = 0.0;
    } else if (rtIsInf(z_im) && rtIsInf(z_re) && (z_re < 0.0)) {
      z_re = 0.0;
      z_im = 0.0;
    } else {
      r = exp(z_re / 2.0);
      z_re = r * (r * cos(z_im));
      z_im = r * (r * sin(z_im));
    }

    ar = pair_re - psub.re;
    r = pair_im - psub.im;
    theta = pair_re + psub.re;
    rough = pair_im + psub.im;
    if (rough == 0.0) {
      if (r == 0.0) {
        im = ar / theta;
        pair_im = 0.0;
      } else if (ar == 0.0) {
        im = 0.0;
        pair_im = r / theta;
      } else {
        im = ar / theta;
        pair_im = r / theta;
      }
    } else if (theta == 0.0) {
      if (ar == 0.0) {
        im = r / rough;
        pair_im = 0.0;
      } else if (r == 0.0) {
        im = 0.0;
        pair_im = -(ar / rough);
      } else {
        im = r / rough;
        pair_im = -(ar / rough);
      }
    } else {
      brm = fabs(theta);
      pair_im = fabs(rough);
      if (brm > pair_im) {
        pair_im = rough / theta;
        theta += pair_im * rough;
        im = (ar + pair_im * r) / theta;
        pair_im = (r - pair_im * ar) / theta;
      } else if (pair_im == brm) {
        if (theta > 0.0) {
          pair_im = 0.5;
        } else {
          pair_im = -0.5;
        }

        if (rough > 0.0) {
          theta = 0.5;
        } else {
          theta = -0.5;
        }

        im = (ar * pair_im + r * theta) / brm;
        pair_im = (r * pair_im - ar * theta) / brm;
      } else {
        pair_im = theta / rough;
        theta = rough + pair_im * theta;
        im = (pair_im * ar + r) / theta;
        pair_im = (pair_im * r - ar) / theta;
      }
    }

    pair_re = im * z_re - pair_im * z_im;
    pair_im = im * z_im + pair_im * z_re;
    theta = blast_re * 0.0 - blast_im;
    rough = blast_re + blast_im * 0.0;
    if (rough == 0.0) {
      N[0].re = exp(theta);
      N[0].im = 0.0;
    } else if (rtIsInf(rough) && rtIsInf(theta) && (theta < 0.0)) {
      N[0].re = 0.0;
      N[0].im = 0.0;
    } else {
      r = exp(theta / 2.0);
      N[0].re = r * (r * cos(rough));
      N[0].im = r * (r * sin(rough));
    }

    z_re = -blast_re * 0.0 - (-blast_im);
    z_im = -blast_re + -blast_im * 0.0;
    if (z_im == 0.0) {
      z_re = exp(z_re);
      z_im = 0.0;
    } else if (rtIsInf(z_im) && rtIsInf(z_re) && (z_re < 0.0)) {
      z_re = 0.0;
      z_im = 0.0;
    } else {
      r = exp(z_re / 2.0);
      z_re = r * (r * cos(z_im));
      z_im = r * (r * sin(z_im));
    }

    N[1].re = pair_re * z_re - pair_im * z_im;
    N[1].im = pair_re * z_im + pair_im * z_re;
    z_re = -blast_re * 0.0 - (-blast_im);
    z_im = -blast_re + -blast_im * 0.0;
    if (z_im == 0.0) {
      N[3].re = exp(z_re);
      N[3].im = 0.0;
    } else if (rtIsInf(z_im) && rtIsInf(z_re) && (z_re < 0.0)) {
      N[3].re = 0.0;
      N[3].im = 0.0;
    } else {
      r = exp(z_re / 2.0);
      N[3].re = r * (r * cos(z_im));
      N[3].im = r * (r * sin(z_im));
    }

    if (rough == 0.0) {
      z_re = exp(theta);
      z_im = 0.0;
    } else if (rtIsInf(rough) && rtIsInf(theta) && (theta < 0.0)) {
      z_re = 0.0;
      z_im = 0.0;
    } else {
      theta = exp(theta / 2.0);
      z_re = theta * (theta * cos(rough));
      z_im = theta * (theta * sin(rough));
    }

    N[2].re = pair_re * z_re - pair_im * z_im;
    N[2].im = pair_re * z_im + pair_im * z_re;
    for (i15 = 0; i15 < 2; i15++) {
      b_MI[i15].re = (MI[i15].re * N[0].re - MI[i15].im * N[0].im) + (MI[i15 + 2]
        .re * N[1].re - MI[i15 + 2].im * N[1].im);
      b_MI[i15].im = (MI[i15].re * N[0].im + MI[i15].im * N[0].re) + (MI[i15 + 2]
        .re * N[1].im + MI[i15 + 2].im * N[1].re);
      b_MI[i15 + 2].re = (MI[i15].re * N[2].re - MI[i15].im * N[2].im) + (MI[i15
        + 2].re * N[3].re - MI[i15 + 2].im * N[3].im);
      b_MI[i15 + 2].im = (MI[i15].re * N[2].im + MI[i15].im * N[2].re) + (MI[i15
        + 2].re * N[3].im + MI[i15 + 2].im * N[3].re);
    }

    memcpy(&MI[0], &b_MI[0], sizeof(creal_T) << 2);
    im = MI[1].re * MI[1].re - MI[1].im * -MI[1].im;
    r = MI[1].re * -MI[1].im + MI[1].im * MI[1].re;
    theta = MI[0].re * MI[0].re - MI[0].im * -MI[0].im;
    rough = MI[0].re * -MI[0].im + MI[0].im * MI[0].re;
    if (rough == 0.0) {
      if (r == 0.0) {
        pair_re = im / theta;
        pair_im = 0.0;
      } else if (im == 0.0) {
        pair_re = 0.0;
        pair_im = r / theta;
      } else {
        pair_re = im / theta;
        pair_im = r / theta;
      }
    } else if (theta == 0.0) {
      if (im == 0.0) {
        pair_re = r / rough;
        pair_im = 0.0;
      } else if (r == 0.0) {
        pair_re = 0.0;
        pair_im = -(im / rough);
      } else {
        pair_re = r / rough;
        pair_im = -(im / rough);
      }
    } else {
      brm = fabs(theta);
      pair_im = fabs(rough);
      if (brm > pair_im) {
        pair_im = rough / theta;
        theta += pair_im * rough;
        pair_re = (im + pair_im * r) / theta;
        pair_im = (r - pair_im * im) / theta;
      } else if (pair_im == brm) {
        if (theta > 0.0) {
          pair_im = 0.5;
        } else {
          pair_im = -0.5;
        }

        if (rough > 0.0) {
          theta = 0.5;
        } else {
          theta = -0.5;
        }

        pair_re = (im * pair_im + r * theta) / brm;
        pair_im = (r * pair_im - im * theta) / brm;
      } else {
        pair_im = theta / rough;
        theta = rough + pair_im * theta;
        pair_re = (pair_im * im + r) / theta;
        pair_im = (pair_im * r - im) / theta;
      }
    }

    out->data[loop] = rt_hypotd_snf(pair_re, pair_im);
  }
}

/* End of code generation (paratt.c) */
