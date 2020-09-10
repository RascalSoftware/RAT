/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * abeles_paraPoints.c
 *
 * Code generation for function 'abeles_paraPoints'
 *
 */

/* Include files */
#include "abeles_paraPoints.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ig_emlrtRSI = { 31, /* lineNo */
  "abeles_paraPoints",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m"/* pathName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 42,/* lineNo */
  19,                                  /* colNo */
  "abeles_paraPoints",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m"/* pName */
};

static emlrtBCInfo hi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  17,                                  /* colNo */
  "sld",                               /* aName */
  "abeles_paraPoints",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ii_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  11,                                  /* colNo */
  "x",                                 /* aName */
  "abeles_paraPoints",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ji_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  21,                                  /* colNo */
  "sld",                               /* aName */
  "abeles_paraPoints",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ki_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  19,                                  /* colNo */
  "sld",                               /* aName */
  "abeles_paraPoints",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo li_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  21,                                  /* colNo */
  "sld",                               /* aName */
  "abeles_paraPoints",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mi_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  5,                                   /* colNo */
  "out",                               /* aName */
  "abeles_paraPoints",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo rk_emlrtRTEI = { 9,/* lineNo */
  7,                                   /* colNo */
  "abeles_paraPoints",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m"/* pName */
};

/* Function Definitions */
void abeles_paraPoints(const emlrtStack *sp, const emxArray_real_T *x, const
  emxArray_real_T *sld, real_T nbair, real_T nbsub, real_T nrepeats, real_T
  rfinal, real_T layers, real_T points, emxArray_real_T *out)
{
  int32_T ub_loop;
  int32_T i;
  real_T snair;
  real_T snsub;
  int32_T loop;
  creal_T quo;
  creal_T num;
  creal_T MI[4];
  creal_T beta;
  creal_T pimag;
  real_T preal;
  real_T rough;
  real_T thick;
  creal_T blast;
  creal_T psub;
  creal_T N[4];
  int32_T i1;
  real_T preal_tmp;
  int32_T i2;
  int32_T reploop;
  real_T re;
  int32_T nl;
  real_T im;
  int32_T i3;
  real_T ar;
  real_T quo_re;
  real_T brm;
  real_T x_re;
  real_T x_im;
  creal_T b_MI[4];
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack b_st;
  boolean_T emlrtHadParallelError = false;

  /*  nbair = nbairs(thisCont); */
  /*  nbsub = nbsubs(thisCont); */
  /*  ssub = ssubs(thisCont); */
  /*  nrepeats = nrepeatss(thisCont); */
  /*  resol = resols(thisCont); */
  ub_loop = (int32_T)points;
  i = out->size[0];
  out->size[0] = ub_loop;
  emxEnsureCapacity_real_T(sp, out, i, &rk_emlrtRTEI);

  /* pi = 3.141592653589; */
  snair = 1.0 - nbair * 0.377451863036739;
  snsub = 1.0 - nbsub * 0.377451863036739;
  ub_loop--;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(quo,num,MI,beta,pimag,preal,rough,thick,blast,psub,N,b_emlrtJBEnviron,b_st,i1,preal_tmp,i2,reploop,re,nl,i3,im,ar,quo_re,x_re,x_im,brm,b_MI) \
 firstprivate(st,emlrtHadParallelError)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &b_emlrtJBEnviron);
      b_st.prev = &st;
      b_st.tls = st.tls;
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (loop = 0; loop <= ub_loop; loop++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        i1 = loop + 1;
        if ((i1 < 1) || (i1 > x->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, x->size[1], &ii_emlrtBCI, &st);
        }

        b_st.site = &ig_emlrtRSI;
        thick = x->data[loop] * 1.54 / 12.566370614359172;
        if ((thick < -1.0) || (thick > 1.0)) {
          emlrtErrorWithMessageIdR2018a(&b_st, &tb_emlrtRTEI,
            "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError",
            3, 4, 4, "asin");
        }

        thick = muDoubleScalarAsin(thick);
        preal = muDoubleScalarCos(thick);
        preal_tmp = snair * snair * (preal * preal);
        preal = snsub * snsub - preal_tmp;
        psub.re = preal;
        psub.im = preal * 0.0;
        b_sqrt(&psub);
        preal = snair * muDoubleScalarSin(thick);
        quo.re = preal;
        quo.im = preal * 0.0;
        blast.re = 0.0;
        blast.im = 0.0;
        if (1 > sld->size[0]) {
          emlrtDynamicBoundsCheckR2012b(1, 1, sld->size[0], &hi_emlrtBCI, &st);
        }

        MI[0].re = 1.0;
        MI[0].im = 0.0;
        MI[3].re = 1.0;
        MI[3].im = 0.0;
        MI[2].re = 0.0;
        MI[2].im = 0.0;
        MI[1].re = 0.0;
        MI[1].im = 0.0;
        i1 = (int32_T)nrepeats;
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, nrepeats, mxDOUBLE_CLASS,
          (int32_T)nrepeats, &wb_emlrtRTEI, &st);
        if (0 <= i1 - 1) {
          i2 = (int32_T)layers;
        }

        for (reploop = 0; reploop < i1; reploop++) {
          for (nl = 0; nl < i2; nl++) {
            i3 = (int32_T)(nl + 1U);
            if ((i3 < 1) || (i3 > sld->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i3, 1, sld->size[0], &ji_emlrtBCI,
                &st);
            }

            thick = sld->data[i3 - 1];
            if (i3 > sld->size[0]) {
              emlrtDynamicBoundsCheckR2012b(i3, 1, sld->size[0], &ki_emlrtBCI,
                &st);
            }

            preal = sld->data[(i3 + sld->size[0]) - 1];
            if (i3 > sld->size[0]) {
              emlrtDynamicBoundsCheckR2012b(i3, 1, sld->size[0], &li_emlrtBCI,
                &st);
            }

            rough = sld->data[(i3 + sld->size[0] * 2) - 1];
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
              num.re = muDoubleScalarExp(quo_re);
              num.im = 0.0;
            } else if (muDoubleScalarIsInf(num.im) && muDoubleScalarIsInf(num.re)
                       && (num.re < 0.0)) {
              num.re = 0.0;
              num.im = 0.0;
            } else {
              preal = muDoubleScalarExp(num.re / 2.0);
              quo_re = num.im;
              ar = num.im;
              num.re = preal * (preal * muDoubleScalarCos(quo_re));
              num.im = preal * (preal * muDoubleScalarSin(ar));
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
              brm = muDoubleScalarAbs(preal);
              rough = muDoubleScalarAbs(im);
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
              x_re = muDoubleScalarExp(x_re);
              x_im = 0.0;
            } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) &&
                       (x_re < 0.0)) {
              x_re = 0.0;
              x_im = 0.0;
            } else {
              preal = muDoubleScalarExp(x_re / 2.0);
              x_re = preal * (preal * muDoubleScalarCos(x_im));
              x_im = preal * (preal * muDoubleScalarSin(x_im));
            }

            quo_re = -blast.re * 0.0 - (-blast.im);
            ar = -blast.re + -blast.im * 0.0;
            if (ar == 0.0) {
              quo_re = muDoubleScalarExp(quo_re);
              quo.re = quo_re;
              ar = 0.0;
              quo.im = 0.0;
            } else if (muDoubleScalarIsInf(ar) && muDoubleScalarIsInf(quo_re) &&
                       (quo_re < 0.0)) {
              quo_re = 0.0;
              quo.re = 0.0;
              ar = 0.0;
              quo.im = 0.0;
            } else {
              preal = muDoubleScalarExp(quo_re / 2.0);
              quo_re = preal * (preal * muDoubleScalarCos(ar));
              quo.re = quo_re;
              ar = preal * (preal * muDoubleScalarSin(ar));
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
            for (i3 = 0; i3 < 2; i3++) {
              im = MI[i3 + 2].re;
              re = MI[i3 + 2].im;
              b_MI[i3].re = (MI[i3].re * x_re - MI[i3].im * x_im) + (im * brm -
                re * quo_re);
              b_MI[i3].im = (MI[i3].re * x_im + MI[i3].im * x_re) + (im * quo_re
                + re * brm);
              b_MI[i3 + 2].re = (MI[i3].re * ar - MI[i3].im * preal) + (im *
                thick - re * rough);
              b_MI[i3 + 2].im = (MI[i3].re * preal + MI[i3].im * ar) + (im *
                rough + re * thick);
            }

            memcpy(&MI[0], &b_MI[0], 4U * sizeof(creal_T));
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
          num.re = muDoubleScalarExp(quo_re);
          num.im = 0.0;
        } else if (muDoubleScalarIsInf(num.im) && muDoubleScalarIsInf(num.re) &&
                   (num.re < 0.0)) {
          num.re = 0.0;
          num.im = 0.0;
        } else {
          preal = muDoubleScalarExp(num.re / 2.0);
          quo_re = num.im;
          ar = num.im;
          num.re = preal * (preal * muDoubleScalarCos(quo_re));
          num.im = preal * (preal * muDoubleScalarSin(ar));
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
          brm = muDoubleScalarAbs(preal);
          rough = muDoubleScalarAbs(im);
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
          x_re = muDoubleScalarExp(x_re);
          x_im = 0.0;
        } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) &&
                   (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          preal = muDoubleScalarExp(x_re / 2.0);
          x_re = preal * (preal * muDoubleScalarCos(x_im));
          x_im = preal * (preal * muDoubleScalarSin(x_im));
        }

        quo.re = -blast.re * 0.0 - (-blast.im);
        quo.im = -blast.re + -blast.im * 0.0;
        if (quo.im == 0.0) {
          quo_re = quo.re;
          quo.re = muDoubleScalarExp(quo_re);
          quo.im = 0.0;
        } else if (muDoubleScalarIsInf(quo.im) && muDoubleScalarIsInf(quo.re) &&
                   (quo.re < 0.0)) {
          quo.re = 0.0;
          quo.im = 0.0;
        } else {
          preal = muDoubleScalarExp(quo.re / 2.0);
          quo_re = quo.im;
          ar = quo.im;
          quo.re = preal * (preal * muDoubleScalarCos(quo_re));
          quo.im = preal * (preal * muDoubleScalarSin(ar));
        }

        quo_re = re * quo.re - im * quo.im;
        ar = re * quo.im + im * quo.re;
        brm = re * x_re - im * x_im;
        preal = re * x_im + im * x_re;
        thick = quo.re;
        rough = quo.im;
        for (i1 = 0; i1 < 2; i1++) {
          im = MI[i1 + 2].re;
          re = MI[i1 + 2].im;
          b_MI[i1].re = (MI[i1].re * x_re - MI[i1].im * x_im) + (im * quo_re -
            re * ar);
          b_MI[i1].im = (MI[i1].re * x_im + MI[i1].im * x_re) + (im * ar + re *
            quo_re);
          b_MI[i1 + 2].re = (MI[i1].re * brm - MI[i1].im * preal) + (im * thick
            - re * rough);
          b_MI[i1 + 2].im = (MI[i1].re * preal + MI[i1].im * brm) + (im * rough
            + re * thick);
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
          brm = muDoubleScalarAbs(thick);
          rough = muDoubleScalarAbs(preal);
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

        i1 = (int32_T)(loop + 1U);
        if ((i1 < 1) || (i1 > out->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, out->size[0], &mi_emlrtBCI, &st);
        }

        out->data[i1 - 1] = muDoubleScalarHypot(quo.re, quo.im);
      } else {
        emlrtHadParallelError = true;
      }
    }
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
}

/* End of code generation (abeles_paraPoints.c) */
