/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * abeles.c
 *
 * Code generation for function 'abeles'
 *
 */

/* Include files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "abeles.h"
#include "sqrt.h"
#include "abeles_emxutil.h"

/* Function Definitions */
void abeles(const emxArray_real_T *x, const emxArray_creal_T *sld, const creal_T
            nbair, const creal_T nbsub, double nrepeats, double ssub, double
            layers, double points, emxArray_real_T *out)
{
  creal_T snair;
  creal_T snsub;
  int ub_loop;
  int i0;
  int loop;
  creal_T R;
  creal_T num;
  creal_T MI[4];
  creal_T beta;
  creal_T pimag;
  creal_T blast;
  creal_T psub;
  double theta;
  creal_T N[4];
  double a_tmp;
  double snsub_im_tmp;
  double snair_re_tmp;
  double snair_im_tmp;
  double snsub_re_tmp;
  double snsub_re;
  double snsub_im;
  int i1;
  int reploop;
  int i2;
  int nl;
  double ar;
  double num_re;
  creal_T b_MI[4];
  int i3;
  snair.re = 1.0 - nbair.re * 0.377451863036739;
  snair.im = 0.0 - nbair.im * 0.377451863036739;
  snsub.re = 1.0 - nbsub.re * 0.377451863036739;
  snsub.im = 0.0 - nbsub.im * 0.377451863036739;
  ub_loop = out->size[0];
  i0 = (int)points;
  out->size[0] = i0;
  emxEnsureCapacity_real_T(out, ub_loop);
  ub_loop = i0 - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(R,num,MI,beta,pimag,blast,psub,theta,N,a_tmp,snsub_im_tmp,snair_re_tmp,snair_im_tmp,snsub_re_tmp,snsub_re,snsub_im,i1,reploop,i2,nl,ar,num_re,i3,b_MI)

  for (loop = 0; loop <= ub_loop; loop++) {
    MI[0].re = 1.0;
    MI[0].im = 0.0;
    MI[1].re = 0.0;
    MI[1].im = 0.0;
    MI[2].re = 0.0;
    MI[2].im = 0.0;
    MI[3].re = 1.0;
    MI[3].im = 0.0;
    theta = asin(x->data[loop] * 1.54 / 12.566370614359172);
    a_tmp = cos(theta);
    snsub_im_tmp = snsub.re * snsub.im;
    snair_re_tmp = snair.re * snair.re - snair.im * snair.im;
    snair_im_tmp = snair.re * snair.im;
    snair_im_tmp += snair_im_tmp;
    snsub_re_tmp = a_tmp * a_tmp;
    snsub_re = (snsub.re * snsub.re - snsub.im * snsub.im) - snair_re_tmp *
      snsub_re_tmp;
    snsub_im = (snsub_im_tmp + snsub_im_tmp) - snair_im_tmp * snsub_re_tmp;
    psub.re = snsub_re - snsub_im * 0.0;
    psub.im = snsub_re * 0.0 + snsub_im;
    b_sqrt(&psub);
    snsub_re_tmp = sin(theta);
    snsub_im = snsub_re_tmp * snair.re;
    snsub_im_tmp = snsub_re_tmp * snair.im;
    num.re = snsub_im - snsub_im_tmp * 0.0;
    num.im = snsub_im * 0.0 + snsub_im_tmp;
    blast.re = 0.0;
    blast.im = 0.0;
    i1 = (int)nrepeats;
    for (reploop = 0; reploop < i1; reploop++) {
      i2 = (int)layers;
      for (nl = 0; nl < i2; nl++) {
        R.re = 1.0 - sld->data[nl + sld->size[0]].re * 0.377451863036739;
        R.im = 0.0 - sld->data[nl + sld->size[0]].im * 0.377451863036739;
        snsub_im = R.re * R.re - R.im * R.im;
        snsub_im_tmp = R.re * R.im;
        snsub_re_tmp = a_tmp * a_tmp;
        R.re = snsub_im - snair_re_tmp * snsub_re_tmp;
        R.im = (snsub_im_tmp + snsub_im_tmp) - snair_im_tmp * snsub_re_tmp;
        pimag.re = R.re - R.im * 0.0;
        pimag.im = R.re * 0.0 + R.im;
        b_sqrt(&pimag);
        snsub_im = 4.0799904592075231 * sld->data[nl].re;
        snsub_im_tmp = 4.0799904592075231 * sld->data[nl].im;
        beta.re = snsub_im * pimag.re - snsub_im_tmp * pimag.im;
        beta.im = snsub_im * pimag.im + snsub_im_tmp * pimag.re;
        snsub_im = -78.956835208714864 * num.re;
        snsub_im_tmp = -78.956835208714864 * num.im;
        snsub_re_tmp = snsub_im * pimag.re - snsub_im_tmp * pimag.im;
        snsub_im_tmp = snsub_im * pimag.im + snsub_im_tmp * pimag.re;
        theta = sld->data[nl + (sld->size[0] << 1)].re * sld->data[nl +
          (sld->size[0] << 1)].re - sld->data[nl + (sld->size[0] << 1)].im *
          sld->data[nl + (sld->size[0] << 1)].im;
        snsub_re = sld->data[nl + (sld->size[0] << 1)].re * sld->data[nl +
          (sld->size[0] << 1)].im + sld->data[nl + (sld->size[0] << 1)].im *
          sld->data[nl + (sld->size[0] << 1)].re;
        snsub_im = snsub_re_tmp * theta - snsub_im_tmp * snsub_re;
        snsub_im_tmp = snsub_re_tmp * snsub_re + snsub_im_tmp * theta;
        if (snsub_im_tmp == 0.0) {
          R.re = snsub_im / 2.3716;
          R.im = 0.0;
        } else if (snsub_im == 0.0) {
          R.re = 0.0;
          R.im = snsub_im_tmp / 2.3716;
        } else {
          R.re = snsub_im / 2.3716;
          R.im = snsub_im_tmp / 2.3716;
        }

        if (R.im == 0.0) {
          snsub_im = R.re;
          R.re = exp(snsub_im);
          R.im = 0.0;
        } else if (rtIsInf(R.im) && rtIsInf(R.re) && (R.re < 0.0)) {
          R.re = 0.0;
          R.im = 0.0;
        } else {
          theta = exp(R.re / 2.0);
          snsub_re_tmp = R.im;
          snsub_im_tmp = R.im;
          R.re = theta * (theta * cos(snsub_re_tmp));
          R.im = theta * (theta * sin(snsub_im_tmp));
        }

        ar = num.re - pimag.re;
        theta = num.im - pimag.im;
        snsub_im = num.re + pimag.re;
        snsub_im_tmp = num.im + pimag.im;
        if (snsub_im_tmp == 0.0) {
          if (theta == 0.0) {
            num_re = ar / snsub_im;
            snsub_re = 0.0;
          } else if (ar == 0.0) {
            num_re = 0.0;
            snsub_re = theta / snsub_im;
          } else {
            num_re = ar / snsub_im;
            snsub_re = theta / snsub_im;
          }
        } else if (snsub_im == 0.0) {
          if (ar == 0.0) {
            num_re = theta / snsub_im_tmp;
            snsub_re = 0.0;
          } else if (theta == 0.0) {
            num_re = 0.0;
            snsub_re = -(ar / snsub_im_tmp);
          } else {
            num_re = theta / snsub_im_tmp;
            snsub_re = -(ar / snsub_im_tmp);
          }
        } else {
          snsub_re = fabs(snsub_im);
          snsub_re_tmp = fabs(snsub_im_tmp);
          if (snsub_re > snsub_re_tmp) {
            snsub_re_tmp = snsub_im_tmp / snsub_im;
            snsub_im += snsub_re_tmp * snsub_im_tmp;
            num_re = (ar + snsub_re_tmp * theta) / snsub_im;
            snsub_re = (theta - snsub_re_tmp * ar) / snsub_im;
          } else if (snsub_re_tmp == snsub_re) {
            if (snsub_im > 0.0) {
              snsub_re_tmp = 0.5;
            } else {
              snsub_re_tmp = -0.5;
            }

            if (snsub_im_tmp > 0.0) {
              snsub_im = 0.5;
            } else {
              snsub_im = -0.5;
            }

            num_re = (ar * snsub_re_tmp + theta * snsub_im) / snsub_re;
            snsub_re = (theta * snsub_re_tmp - ar * snsub_im) / snsub_re;
          } else {
            snsub_re_tmp = snsub_im / snsub_im_tmp;
            snsub_im = snsub_im_tmp + snsub_re_tmp * snsub_im;
            num_re = (snsub_re_tmp * ar + theta) / snsub_im;
            snsub_re = (snsub_re_tmp * theta - ar) / snsub_im;
          }
        }

        snsub_im = R.re;
        snsub_re_tmp = R.im;
        R.re = num_re * snsub_im - snsub_re * snsub_re_tmp;
        R.im = num_re * snsub_re_tmp + snsub_re * snsub_im;
        snsub_im = blast.re * 0.0 - blast.im;
        snsub_im_tmp = blast.re + blast.im * 0.0;
        if (snsub_im_tmp == 0.0) {
          N[0].re = exp(snsub_im);
          N[0].im = 0.0;
        } else if (rtIsInf(snsub_im_tmp) && rtIsInf(snsub_im) && (snsub_im < 0.0))
        {
          N[0].re = 0.0;
          N[0].im = 0.0;
        } else {
          theta = exp(snsub_im / 2.0);
          N[0].re = theta * (theta * cos(snsub_im_tmp));
          N[0].im = theta * (theta * sin(snsub_im_tmp));
        }

        num.re = -blast.re * 0.0 - (-blast.im);
        num.im = -blast.re + -blast.im * 0.0;
        if (num.im == 0.0) {
          num_re = num.re;
          num.re = exp(num_re);
          num.im = 0.0;
        } else if (rtIsInf(num.im) && rtIsInf(num.re) && (num.re < 0.0)) {
          num.re = 0.0;
          num.im = 0.0;
        } else {
          theta = exp(num.re / 2.0);
          snsub_re = num.im;
          snsub_im = num.im;
          num.re = theta * (theta * cos(snsub_re));
          num.im = theta * (theta * sin(snsub_im));
        }

        N[1].re = R.re * num.re - R.im * num.im;
        N[1].im = R.re * num.im + R.im * num.re;
        num.re = -blast.re * 0.0 - (-blast.im);
        num.im = -blast.re + -blast.im * 0.0;
        if (num.im == 0.0) {
          N[3].re = exp(num.re);
          N[3].im = 0.0;
        } else if (rtIsInf(num.im) && rtIsInf(num.re) && (num.re < 0.0)) {
          N[3].re = 0.0;
          N[3].im = 0.0;
        } else {
          theta = exp(num.re / 2.0);
          N[3].re = theta * (theta * cos(num.im));
          N[3].im = theta * (theta * sin(num.im));
        }

        snsub_im = blast.re * 0.0 - blast.im;
        snsub_im_tmp = blast.re + blast.im * 0.0;
        if (snsub_im_tmp == 0.0) {
          num.re = exp(snsub_im);
          num.im = 0.0;
        } else if (rtIsInf(snsub_im_tmp) && rtIsInf(snsub_im) && (snsub_im < 0.0))
        {
          num.re = 0.0;
          num.im = 0.0;
        } else {
          theta = exp(snsub_im / 2.0);
          num.re = theta * (theta * cos(snsub_im_tmp));
          num.im = theta * (theta * sin(snsub_im_tmp));
        }

        N[2].re = R.re * num.re - R.im * num.im;
        N[2].im = R.re * num.im + R.im * num.re;
        num = pimag;
        blast = beta;
        for (i3 = 0; i3 < 2; i3++) {
          b_MI[i3].re = (MI[i3].re * N[0].re - MI[i3].im * N[0].im) + (MI[i3 + 2]
            .re * N[1].re - MI[i3 + 2].im * N[1].im);
          b_MI[i3].im = (MI[i3].re * N[0].im + MI[i3].im * N[0].re) + (MI[i3 + 2]
            .re * N[1].im + MI[i3 + 2].im * N[1].re);
          b_MI[i3 + 2].re = (MI[i3].re * N[2].re - MI[i3].im * N[2].im) + (MI[i3
            + 2].re * N[3].re - MI[i3 + 2].im * N[3].im);
          b_MI[i3 + 2].im = (MI[i3].re * N[2].im + MI[i3].im * N[2].re) + (MI[i3
            + 2].re * N[3].im + MI[i3 + 2].im * N[3].re);
        }

        memcpy(&MI[0], &b_MI[0], sizeof(creal_T) << 2);
      }
    }

    snsub_im_tmp = -78.956835208714864 * num.re;
    snsub_re_tmp = -78.956835208714864 * num.im;
    snsub_im = ssub * ssub;
    ar = (snsub_im_tmp * psub.re - snsub_re_tmp * psub.im) * snsub_im;
    theta = (snsub_im_tmp * psub.im + snsub_re_tmp * psub.re) * snsub_im;
    if (theta == 0.0) {
      R.re = ar / 2.3716;
      R.im = 0.0;
    } else if (ar == 0.0) {
      R.re = 0.0;
      R.im = theta / 2.3716;
    } else {
      R.re = ar / 2.3716;
      R.im = theta / 2.3716;
    }

    if (R.im == 0.0) {
      snsub_im = R.re;
      R.re = exp(snsub_im);
      R.im = 0.0;
    } else if (rtIsInf(R.im) && rtIsInf(R.re) && (R.re < 0.0)) {
      R.re = 0.0;
      R.im = 0.0;
    } else {
      theta = exp(R.re / 2.0);
      snsub_re_tmp = R.im;
      snsub_im_tmp = R.im;
      R.re = theta * (theta * cos(snsub_re_tmp));
      R.im = theta * (theta * sin(snsub_im_tmp));
    }

    ar = num.re - psub.re;
    theta = num.im - psub.im;
    snsub_im = num.re + psub.re;
    snsub_im_tmp = num.im + psub.im;
    if (snsub_im_tmp == 0.0) {
      if (theta == 0.0) {
        num_re = ar / snsub_im;
        snsub_re = 0.0;
      } else if (ar == 0.0) {
        num_re = 0.0;
        snsub_re = theta / snsub_im;
      } else {
        num_re = ar / snsub_im;
        snsub_re = theta / snsub_im;
      }
    } else if (snsub_im == 0.0) {
      if (ar == 0.0) {
        num_re = theta / snsub_im_tmp;
        snsub_re = 0.0;
      } else if (theta == 0.0) {
        num_re = 0.0;
        snsub_re = -(ar / snsub_im_tmp);
      } else {
        num_re = theta / snsub_im_tmp;
        snsub_re = -(ar / snsub_im_tmp);
      }
    } else {
      snsub_re = fabs(snsub_im);
      snsub_re_tmp = fabs(snsub_im_tmp);
      if (snsub_re > snsub_re_tmp) {
        snsub_re_tmp = snsub_im_tmp / snsub_im;
        snsub_im += snsub_re_tmp * snsub_im_tmp;
        num_re = (ar + snsub_re_tmp * theta) / snsub_im;
        snsub_re = (theta - snsub_re_tmp * ar) / snsub_im;
      } else if (snsub_re_tmp == snsub_re) {
        if (snsub_im > 0.0) {
          snsub_re_tmp = 0.5;
        } else {
          snsub_re_tmp = -0.5;
        }

        if (snsub_im_tmp > 0.0) {
          snsub_im = 0.5;
        } else {
          snsub_im = -0.5;
        }

        num_re = (ar * snsub_re_tmp + theta * snsub_im) / snsub_re;
        snsub_re = (theta * snsub_re_tmp - ar * snsub_im) / snsub_re;
      } else {
        snsub_re_tmp = snsub_im / snsub_im_tmp;
        snsub_im = snsub_im_tmp + snsub_re_tmp * snsub_im;
        num_re = (snsub_re_tmp * ar + theta) / snsub_im;
        snsub_re = (snsub_re_tmp * theta - ar) / snsub_im;
      }
    }

    snsub_im = R.re;
    snsub_re_tmp = R.im;
    R.re = num_re * snsub_im - snsub_re * snsub_re_tmp;
    R.im = num_re * snsub_re_tmp + snsub_re * snsub_im;
    snsub_im_tmp = blast.re * 0.0 - blast.im;
    snsub_re_tmp = blast.re + blast.im * 0.0;
    if (snsub_re_tmp == 0.0) {
      N[0].re = exp(snsub_im_tmp);
      N[0].im = 0.0;
    } else if (rtIsInf(snsub_re_tmp) && rtIsInf(snsub_im_tmp) && (snsub_im_tmp <
                0.0)) {
      N[0].re = 0.0;
      N[0].im = 0.0;
    } else {
      theta = exp(snsub_im_tmp / 2.0);
      N[0].re = theta * (theta * cos(snsub_re_tmp));
      N[0].im = theta * (theta * sin(snsub_re_tmp));
    }

    num.re = -blast.re * 0.0 - (-blast.im);
    num.im = -blast.re + -blast.im * 0.0;
    if (num.im == 0.0) {
      num_re = num.re;
      num.re = exp(num_re);
      num.im = 0.0;
    } else if (rtIsInf(num.im) && rtIsInf(num.re) && (num.re < 0.0)) {
      num.re = 0.0;
      num.im = 0.0;
    } else {
      theta = exp(num.re / 2.0);
      snsub_re = num.im;
      snsub_im = num.im;
      num.re = theta * (theta * cos(snsub_re));
      num.im = theta * (theta * sin(snsub_im));
    }

    N[1].re = R.re * num.re - R.im * num.im;
    N[1].im = R.re * num.im + R.im * num.re;
    num.re = -blast.re * 0.0 - (-blast.im);
    num.im = -blast.re + -blast.im * 0.0;
    if (num.im == 0.0) {
      N[3].re = exp(num.re);
      N[3].im = 0.0;
    } else if (rtIsInf(num.im) && rtIsInf(num.re) && (num.re < 0.0)) {
      N[3].re = 0.0;
      N[3].im = 0.0;
    } else {
      theta = exp(num.re / 2.0);
      N[3].re = theta * (theta * cos(num.im));
      N[3].im = theta * (theta * sin(num.im));
    }

    if (snsub_re_tmp == 0.0) {
      num.re = exp(snsub_im_tmp);
      num.im = 0.0;
    } else if (rtIsInf(snsub_re_tmp) && rtIsInf(snsub_im_tmp) && (snsub_im_tmp <
                0.0)) {
      num.re = 0.0;
      num.im = 0.0;
    } else {
      theta = exp(snsub_im_tmp / 2.0);
      num.re = theta * (theta * cos(snsub_re_tmp));
      num.im = theta * (theta * sin(snsub_re_tmp));
    }

    N[2].re = R.re * num.re - R.im * num.im;
    N[2].im = R.re * num.im + R.im * num.re;
    for (i1 = 0; i1 < 2; i1++) {
      b_MI[i1].re = (MI[i1].re * N[0].re - MI[i1].im * N[0].im) + (MI[i1 + 2].re
        * N[1].re - MI[i1 + 2].im * N[1].im);
      b_MI[i1].im = (MI[i1].re * N[0].im + MI[i1].im * N[0].re) + (MI[i1 + 2].re
        * N[1].im + MI[i1 + 2].im * N[1].re);
      b_MI[i1 + 2].re = (MI[i1].re * N[2].re - MI[i1].im * N[2].im) + (MI[i1 + 2]
        .re * N[3].re - MI[i1 + 2].im * N[3].im);
      b_MI[i1 + 2].im = (MI[i1].re * N[2].im + MI[i1].im * N[2].re) + (MI[i1 + 2]
        .re * N[3].im + MI[i1 + 2].im * N[3].re);
    }

    memcpy(&MI[0], &b_MI[0], sizeof(creal_T) << 2);
    num.re = MI[1].re * MI[1].re - MI[1].im * -MI[1].im;
    num.im = MI[1].re * -MI[1].im + MI[1].im * MI[1].re;
    snsub_im = MI[0].re * MI[0].re - MI[0].im * -MI[0].im;
    snsub_im_tmp = MI[0].re * -MI[0].im + MI[0].im * MI[0].re;
    if (snsub_im_tmp == 0.0) {
      if (num.im == 0.0) {
        R.re = num.re / snsub_im;
        R.im = 0.0;
      } else if (num.re == 0.0) {
        R.re = 0.0;
        R.im = num.im / snsub_im;
      } else {
        R.re = num.re / snsub_im;
        R.im = num.im / snsub_im;
      }
    } else if (snsub_im == 0.0) {
      if (num.re == 0.0) {
        R.re = num.im / snsub_im_tmp;
        R.im = 0.0;
      } else if (num.im == 0.0) {
        R.re = 0.0;
        R.im = -(num.re / snsub_im_tmp);
      } else {
        R.re = num.im / snsub_im_tmp;
        R.im = -(num.re / snsub_im_tmp);
      }
    } else {
      snsub_re = fabs(snsub_im);
      snsub_re_tmp = fabs(snsub_im_tmp);
      if (snsub_re > snsub_re_tmp) {
        snsub_re_tmp = snsub_im_tmp / snsub_im;
        snsub_im += snsub_re_tmp * snsub_im_tmp;
        R.re = (num.re + snsub_re_tmp * num.im) / snsub_im;
        R.im = (num.im - snsub_re_tmp * num.re) / snsub_im;
      } else if (snsub_re_tmp == snsub_re) {
        if (snsub_im > 0.0) {
          snsub_re_tmp = 0.5;
        } else {
          snsub_re_tmp = -0.5;
        }

        if (snsub_im_tmp > 0.0) {
          snsub_im = 0.5;
        } else {
          snsub_im = -0.5;
        }

        R.re = (num.re * snsub_re_tmp + num.im * snsub_im) / snsub_re;
        R.im = (num.im * snsub_re_tmp - num.re * snsub_im) / snsub_re;
      } else {
        snsub_re_tmp = snsub_im / snsub_im_tmp;
        snsub_im = snsub_im_tmp + snsub_re_tmp * snsub_im;
        R.re = (snsub_re_tmp * num.re + num.im) / snsub_im;
        R.im = (snsub_re_tmp * num.im - num.re) / snsub_im;
      }
    }

    out->data[loop] = R.re * R.re - R.im * R.im;
  }
}

/* End of code generation (abeles.c) */
