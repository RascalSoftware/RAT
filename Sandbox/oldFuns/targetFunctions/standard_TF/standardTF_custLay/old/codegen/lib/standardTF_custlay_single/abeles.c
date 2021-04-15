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
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "abeles.h"
#include "sqrt.h"
#include "standardTF_custlay_single_emxutil.h"

/* Function Definitions */
void abeles(const emxArray_real_T *x, const emxArray_real_T *sld, double nbair,
            double nbsub, double nrepeats, double ssub, double layers, double
            points, emxArray_real_T *out)
{
  double snair;
  double snsub;
  int i9;
  int loop;
  double theta;
  double rij_im;
  creal_T psub;
  double plast_re;
  double plast_im;
  double blast_re;
  double blast_im;
  creal_T MI[4];
  int reploop;
  int nl;
  double im;
  double ar;
  double ai;
  double rij_re;
  creal_T pimag;
  double x_re;
  double r;
  double x_im;
  double brm;
  creal_T N[4];
  creal_T b_MI[4];
  int i10;
  int i11;
  double b_im;
  double b_r;

  /*  nbair = nbairs(thisCont); */
  /*  nbsub = nbsubs(thisCont); */
  /*  ssub = ssubs(thisCont); */
  /*  nrepeats = nrepeatss(thisCont); */
  /*  resol = resols(thisCont); */
  snair = 1.0 - nbair * 3.2228875976108808;
  snsub = 1.0 - nbsub * 3.2228875976108808;
  i9 = out->size[0];
  out->size[0] = (int)points;
  emxEnsureCapacity((emxArray__common *)out, i9, (int)sizeof(double));
  for (loop = 0; loop < (int)points; loop++) {
    theta = asin(x->data[loop] * 4.5 / 12.566370614359172);
    rij_im = cos(theta);
    psub.re = snsub * snsub - snair * snair * (rij_im * rij_im);
    psub.im = (snsub * snsub - snair * snair * (rij_im * rij_im)) * 0.0;
    b_sqrt(&psub);
    plast_re = snair * sin(theta);
    plast_im = snair * sin(theta) * 0.0;
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
    for (reploop = 0; reploop < (int)nrepeats; reploop++) {
      for (nl = 0; nl < (int)layers; nl++) {
        rij_re = 1.0 - sld->data[nl + sld->size[0]] * 3.2228875976108808;
        rij_im = cos(theta);
        pimag.re = rij_re * rij_re - snair * snair * (rij_im * rij_im);
        pimag.im = (rij_re * rij_re - snair * snair * (rij_im * rij_im)) * 0.0;
        b_sqrt(&pimag);
        rij_im = -78.956835208714864 * plast_re;
        im = -78.956835208714864 * plast_im;
        ar = (rij_im * pimag.re - im * pimag.im) * (sld->data[nl + (sld->size[0]
          << 1)] * sld->data[nl + (sld->size[0] << 1)]);
        ai = (rij_im * pimag.im + im * pimag.re) * (sld->data[nl + (sld->size[0]
          << 1)] * sld->data[nl + (sld->size[0] << 1)]);
        if (ai == 0.0) {
          rij_re = ar / 20.25;
          rij_im = 0.0;
        } else if (ar == 0.0) {
          rij_re = 0.0;
          rij_im = ai / 20.25;
        } else {
          rij_re = ar / 20.25;
          rij_im = ai / 20.25;
        }

        if (rij_im == 0.0) {
          x_re = exp(rij_re);
          x_im = 0.0;
        } else if (rtIsInf(rij_im) && rtIsInf(rij_re) && (rij_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          r = exp(rij_re / 2.0);
          x_re = r * (r * cos(rij_im));
          x_im = r * (r * sin(rij_im));
        }

        ar = plast_re - pimag.re;
        ai = plast_im - pimag.im;
        im = plast_re + pimag.re;
        r = plast_im + pimag.im;
        if (r == 0.0) {
          if (ai == 0.0) {
            plast_re = ar / im;
            plast_im = 0.0;
          } else if (ar == 0.0) {
            plast_re = 0.0;
            plast_im = ai / im;
          } else {
            plast_re = ar / im;
            plast_im = ai / im;
          }
        } else if (im == 0.0) {
          if (ar == 0.0) {
            plast_re = ai / r;
            plast_im = 0.0;
          } else if (ai == 0.0) {
            plast_re = 0.0;
            plast_im = -(ar / r);
          } else {
            plast_re = ai / r;
            plast_im = -(ar / r);
          }
        } else {
          brm = fabs(im);
          plast_im = fabs(r);
          if (brm > plast_im) {
            plast_im = r / im;
            rij_re = im + plast_im * r;
            plast_re = (ar + plast_im * ai) / rij_re;
            plast_im = (ai - plast_im * ar) / rij_re;
          } else if (plast_im == brm) {
            if (im > 0.0) {
              rij_im = 0.5;
            } else {
              rij_im = -0.5;
            }

            if (r > 0.0) {
              im = 0.5;
            } else {
              im = -0.5;
            }

            plast_re = (ar * rij_im + ai * im) / brm;
            plast_im = (ai * rij_im - ar * im) / brm;
          } else {
            plast_im = im / r;
            rij_re = r + plast_im * im;
            plast_re = (plast_im * ar + ai) / rij_re;
            plast_im = (plast_im * ai - ar) / rij_re;
          }
        }

        rij_re = plast_re * x_re - plast_im * x_im;
        rij_im = plast_re * x_im + plast_im * x_re;
        x_re = blast_re * 0.0 - blast_im;
        x_im = blast_re + blast_im * 0.0;
        if (x_im == 0.0) {
          x_re = exp(x_re);
          x_im = 0.0;
        } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          r = exp(x_re / 2.0);
          x_re = r * (r * cos(x_im));
          x_im = r * (r * sin(x_im));
        }

        N[0].re = x_re;
        N[0].im = x_im;
        x_re = -blast_re * 0.0 - (-blast_im);
        x_im = -blast_re + -blast_im * 0.0;
        if (x_im == 0.0) {
          x_re = exp(x_re);
          x_im = 0.0;
        } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          r = exp(x_re / 2.0);
          x_re = r * (r * cos(x_im));
          x_im = r * (r * sin(x_im));
        }

        N[1].re = rij_re * x_re - rij_im * x_im;
        N[1].im = rij_re * x_im + rij_im * x_re;
        x_re = -blast_re * 0.0 - (-blast_im);
        x_im = -blast_re + -blast_im * 0.0;
        if (x_im == 0.0) {
          x_re = exp(x_re);
          x_im = 0.0;
        } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          r = exp(x_re / 2.0);
          x_re = r * (r * cos(x_im));
          x_im = r * (r * sin(x_im));
        }

        N[3].re = x_re;
        N[3].im = x_im;
        x_re = blast_re * 0.0 - blast_im;
        x_im = blast_re + blast_im * 0.0;
        if (x_im == 0.0) {
          x_re = exp(x_re);
          x_im = 0.0;
        } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          r = exp(x_re / 2.0);
          x_re = r * (r * cos(x_im));
          x_im = r * (r * sin(x_im));
        }

        N[2].re = rij_re * x_re - rij_im * x_im;
        N[2].im = rij_re * x_im + rij_im * x_re;
        plast_re = pimag.re;
        plast_im = pimag.im;
        blast_re = 1.3962634015954636 * sld->data[nl] * pimag.re;
        blast_im = 1.3962634015954636 * sld->data[nl] * pimag.im;
        for (i9 = 0; i9 < 2; i9++) {
          for (i10 = 0; i10 < 2; i10++) {
            b_MI[i9 + (i10 << 1)].re = 0.0;
            b_MI[i9 + (i10 << 1)].im = 0.0;
            for (i11 = 0; i11 < 2; i11++) {
              b_MI[i9 + (i10 << 1)].re += MI[i9 + (i11 << 1)].re * N[i11 + (i10 <<
                1)].re - MI[i9 + (i11 << 1)].im * N[i11 + (i10 << 1)].im;
              b_MI[i9 + (i10 << 1)].im += MI[i9 + (i11 << 1)].re * N[i11 + (i10 <<
                1)].im + MI[i9 + (i11 << 1)].im * N[i11 + (i10 << 1)].re;
            }
          }
        }

        for (i9 = 0; i9 < 2; i9++) {
          for (i10 = 0; i10 < 2; i10++) {
            MI[i10 + (i9 << 1)] = b_MI[i10 + (i9 << 1)];
          }
        }
      }
    }

    rij_im = -78.956835208714864 * plast_re;
    im = -78.956835208714864 * plast_im;
    ar = (rij_im * psub.re - im * psub.im) * (ssub * ssub);
    ai = (rij_im * psub.im + im * psub.re) * (ssub * ssub);
    if (ai == 0.0) {
      rij_re = ar / 20.25;
      rij_im = 0.0;
    } else if (ar == 0.0) {
      rij_re = 0.0;
      rij_im = ai / 20.25;
    } else {
      rij_re = ar / 20.25;
      rij_im = ai / 20.25;
    }

    if (rij_im == 0.0) {
      x_re = exp(rij_re);
      x_im = 0.0;
    } else if (rtIsInf(rij_im) && rtIsInf(rij_re) && (rij_re < 0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      r = exp(rij_re / 2.0);
      x_re = r * (r * cos(rij_im));
      x_im = r * (r * sin(rij_im));
    }

    ar = plast_re - psub.re;
    ai = plast_im - psub.im;
    im = plast_re + psub.re;
    r = plast_im + psub.im;
    if (r == 0.0) {
      if (ai == 0.0) {
        plast_re = ar / im;
        plast_im = 0.0;
      } else if (ar == 0.0) {
        plast_re = 0.0;
        plast_im = ai / im;
      } else {
        plast_re = ar / im;
        plast_im = ai / im;
      }
    } else if (im == 0.0) {
      if (ar == 0.0) {
        plast_re = ai / r;
        plast_im = 0.0;
      } else if (ai == 0.0) {
        plast_re = 0.0;
        plast_im = -(ar / r);
      } else {
        plast_re = ai / r;
        plast_im = -(ar / r);
      }
    } else {
      brm = fabs(im);
      plast_im = fabs(r);
      if (brm > plast_im) {
        plast_im = r / im;
        rij_re = im + plast_im * r;
        plast_re = (ar + plast_im * ai) / rij_re;
        plast_im = (ai - plast_im * ar) / rij_re;
      } else if (plast_im == brm) {
        if (im > 0.0) {
          rij_im = 0.5;
        } else {
          rij_im = -0.5;
        }

        if (r > 0.0) {
          im = 0.5;
        } else {
          im = -0.5;
        }

        plast_re = (ar * rij_im + ai * im) / brm;
        plast_im = (ai * rij_im - ar * im) / brm;
      } else {
        plast_im = im / r;
        rij_re = r + plast_im * im;
        plast_re = (plast_im * ar + ai) / rij_re;
        plast_im = (plast_im * ai - ar) / rij_re;
      }
    }

    rij_re = plast_re * x_re - plast_im * x_im;
    rij_im = plast_re * x_im + plast_im * x_re;
    x_re = blast_re * 0.0 - blast_im;
    x_im = blast_re + blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = exp(x_re);
      x_im = 0.0;
    } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      r = exp(x_re / 2.0);
      x_re = r * (r * cos(x_im));
      x_im = r * (r * sin(x_im));
    }

    N[0].re = x_re;
    N[0].im = x_im;
    x_re = -blast_re * 0.0 - (-blast_im);
    x_im = -blast_re + -blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = exp(x_re);
      x_im = 0.0;
    } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      r = exp(x_re / 2.0);
      x_re = r * (r * cos(x_im));
      x_im = r * (r * sin(x_im));
    }

    N[1].re = rij_re * x_re - rij_im * x_im;
    N[1].im = rij_re * x_im + rij_im * x_re;
    x_re = -blast_re * 0.0 - (-blast_im);
    x_im = -blast_re + -blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = exp(x_re);
      x_im = 0.0;
    } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      r = exp(x_re / 2.0);
      x_re = r * (r * cos(x_im));
      x_im = r * (r * sin(x_im));
    }

    N[3].re = x_re;
    N[3].im = x_im;
    x_re = blast_re * 0.0 - blast_im;
    x_im = blast_re + blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = exp(x_re);
      x_im = 0.0;
    } else if (rtIsInf(x_im) && rtIsInf(x_re) && (x_re < 0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      r = exp(x_re / 2.0);
      x_re = r * (r * cos(x_im));
      x_im = r * (r * sin(x_im));
    }

    N[2].re = rij_re * x_re - rij_im * x_im;
    N[2].im = rij_re * x_im + rij_im * x_re;
    for (i9 = 0; i9 < 2; i9++) {
      for (i10 = 0; i10 < 2; i10++) {
        b_MI[i9 + (i10 << 1)].re = 0.0;
        b_MI[i9 + (i10 << 1)].im = 0.0;
        for (i11 = 0; i11 < 2; i11++) {
          b_MI[i9 + (i10 << 1)].re += MI[i9 + (i11 << 1)].re * N[i11 + (i10 << 1)]
            .re - MI[i9 + (i11 << 1)].im * N[i11 + (i10 << 1)].im;
          b_MI[i9 + (i10 << 1)].im += MI[i9 + (i11 << 1)].re * N[i11 + (i10 << 1)]
            .im + MI[i9 + (i11 << 1)].im * N[i11 + (i10 << 1)].re;
        }
      }
    }

    for (i9 = 0; i9 < 2; i9++) {
      for (i10 = 0; i10 < 2; i10++) {
        MI[i10 + (i9 << 1)] = b_MI[i10 + (i9 << 1)];
      }
    }

    rij_im = MI[1].re * MI[1].re - MI[1].im * -MI[1].im;
    rij_re = MI[1].re * -MI[1].im + MI[1].im * MI[1].re;
    im = MI[0].re * MI[0].re - MI[0].im * -MI[0].im;
    r = MI[0].re * -MI[0].im + MI[0].im * MI[0].re;
    if (r == 0.0) {
      if (rij_re == 0.0) {
        rij_im /= im;
      } else if (rij_im == 0.0) {
        rij_im = 0.0;
      } else {
        rij_im /= im;
      }
    } else if (im == 0.0) {
      if (rij_im == 0.0) {
        rij_im = rij_re / r;
      } else if (rij_re == 0.0) {
        rij_im = 0.0;
      } else {
        rij_im = rij_re / r;
      }
    } else {
      brm = fabs(im);
      plast_im = fabs(r);
      if (brm > plast_im) {
        plast_im = r / im;
        rij_im = (rij_im + plast_im * rij_re) / (im + plast_im * r);
      } else if (plast_im == brm) {
        if (im > 0.0) {
          b_im = 0.5;
        } else {
          b_im = -0.5;
        }

        if (r > 0.0) {
          b_r = 0.5;
        } else {
          b_r = -0.5;
        }

        rij_im = (rij_im * b_im + rij_re * b_r) / brm;
      } else {
        plast_im = im / r;
        rij_im = (plast_im * rij_im + rij_re) / (r + plast_im * im);
      }
    }

    out->data[loop] = rij_im;
  }
}

/* End of code generation (abeles.c) */
