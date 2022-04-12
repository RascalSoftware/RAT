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
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "sqrt1.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo lh_emlrtRSI = {
    31,                  /* lineNo */
    "abeles_paraPoints", /* fcnName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\refl"
    "ectivityCalculations\\Abeles\\abeles_paraPoints.m" /* pathName */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    42,                  /* lineNo */
    19,                  /* colNo */
    "abeles_paraPoints", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\refl"
    "ectivityCalculations\\Abeles\\abeles_paraPoints.m" /* pName */
};

static emlrtBCInfo kl_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    37,                  /* lineNo */
    17,                  /* colNo */
    "sld",               /* aName */
    "abeles_paraPoints", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\refl"
    "ectivityCalculations\\Abeles\\abeles_paraPoints.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo ll_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    30,                  /* lineNo */
    11,                  /* colNo */
    "x",                 /* aName */
    "abeles_paraPoints", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\refl"
    "ectivityCalculations\\Abeles\\abeles_paraPoints.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo ml_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    44,                  /* lineNo */
    21,                  /* colNo */
    "sld",               /* aName */
    "abeles_paraPoints", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\refl"
    "ectivityCalculations\\Abeles\\abeles_paraPoints.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo nl_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    45,                  /* lineNo */
    19,                  /* colNo */
    "sld",               /* aName */
    "abeles_paraPoints", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\refl"
    "ectivityCalculations\\Abeles\\abeles_paraPoints.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo ol_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    46,                  /* lineNo */
    21,                  /* colNo */
    "sld",               /* aName */
    "abeles_paraPoints", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\refl"
    "ectivityCalculations\\Abeles\\abeles_paraPoints.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtBCInfo pl_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    75,                  /* lineNo */
    5,                   /* colNo */
    "out",               /* aName */
    "abeles_paraPoints", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\refl"
    "ectivityCalculations\\Abeles\\abeles_paraPoints.m", /* pName */
    0                                                    /* checkKind */
};

static emlrtRTEInfo sm_emlrtRTEI = {
    9,                   /* lineNo */
    7,                   /* colNo */
    "abeles_paraPoints", /* fName */
    "C:"
    "\\Users\\oba7931403\\Documents\\GitHub\\RAT\\targetFunctions\\common\\refl"
    "ectivityCalculations\\Abeles\\abeles_paraPoints.m" /* pName */
};

/* Function Definitions */
void abeles_paraPoints(const emlrtStack *sp, const emxArray_real_T *x,
                       const emxArray_real_T *sld, real_T nbair, real_T nbsub,
                       real_T nrepeats, real_T rsub, real_T layers,
                       real_T points, emxArray_real_T *out)
{
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack st;
  creal_T MI[4];
  creal_T N[4];
  creal_T b_MI[4];
  creal_T beta;
  creal_T blast;
  creal_T num;
  creal_T pimag;
  creal_T psub;
  creal_T quo;
  real_T ar;
  real_T brm;
  real_T d;
  real_T d1;
  real_T im;
  real_T preal;
  real_T preal_tmp;
  real_T quo_re;
  real_T re;
  real_T rough;
  real_T snair;
  real_T snsub;
  real_T thick;
  real_T x_im;
  real_T x_re;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop;
  int32_T nl;
  int32_T reploop;
  int32_T ub_loop;
  boolean_T emlrtHadParallelError = false;
  /*  nbair = nbairs(thisCont); */
  /*  nbsub = nbsubs(thisCont); */
  /*  ssub = ssubs(thisCont); */
  /*  nrepeats = nrepeatss(thisCont); */
  /*  resol = resols(thisCont); */
  ub_loop = out->size[0];
  out->size[0] = (int32_T)points;
  emxEnsureCapacity_real_T(sp, out, ub_loop, &sm_emlrtRTEI);
  /* pi = 3.141592653589; */
  snair = 1.0 - nbair * 0.377451863036739;
  snsub = 1.0 - nbsub * 0.377451863036739;
  ub_loop = (int32_T)points - 1;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
#pragma omp parallel num_threads(emlrtAllocRegionTLSs(                         \
    sp->tls, omp_in_parallel(), omp_get_max_threads(),                         \
    omp_get_num_procs())) private(quo, num, MI, beta, pimag, preal, rough,     \
                                  thick, blast, psub, N, emlrtJBEnviron, b_st, \
                                  loop, preal_tmp, i, reploop, re, i1, nl, im, \
                                  ar, d, quo_re, x_re, x_im, d1, i2, b_MI,     \
                                  brm) firstprivate(st, emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {

      st.prev = sp;
      st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &emlrtJBEnviron);
      b_st.prev = &st;
      b_st.tls = st.tls;
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (loop = 0; loop <= ub_loop; loop++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(emlrtJBEnviron) == 0) {

        if ((loop + 1 < 1) || (loop + 1 > x->size[0])) {
          emlrtDynamicBoundsCheckR2012b(loop + 1, 1, x->size[0], &ll_emlrtBCI,
                                        &st);
        }
        b_st.site = &lh_emlrtRSI;
        thick = x->data[loop] * 1.54 / 12.566370614359172;
        if ((thick < -1.0) || (thick > 1.0)) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &rb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "asin");
        }
        thick = muDoubleScalarAsin(thick);
        preal = muDoubleScalarCos(thick);
        preal_tmp = snair * snair * (preal * preal);
        preal = snsub * snsub - preal_tmp;
        psub.re = preal;
        psub.im = preal * 0.0;
        c_sqrt(&psub);
        preal = snair * muDoubleScalarSin(thick);
        quo.re = preal;
        quo.im = preal * 0.0;
        blast.re = 0.0;
        blast.im = 0.0;
        if (1 > sld->size[0]) {
          emlrtDynamicBoundsCheckR2012b(1, 1, sld->size[0], &kl_emlrtBCI, &st);
        }
        MI[0].re = 1.0;
        MI[0].im = 0.0;
        MI[3].re = 1.0;
        MI[3].im = 0.0;
        MI[2].re = 0.0;
        MI[2].im = 0.0;
        MI[1].re = 0.0;
        MI[1].im = 0.0;
        i = (int32_T)nrepeats;
        emlrtForLoopVectorCheckR2021a(1.0, 1.0, nrepeats, mxDOUBLE_CLASS,
                                      (int32_T)nrepeats, &bc_emlrtRTEI, &st);
        for (reploop = 0; reploop < i; reploop++) {
          i1 = (int32_T)layers;
          for (nl = 0; nl < i1; nl++) {
            if (((int32_T)(nl + 1U) < 1) ||
                ((int32_T)(nl + 1U) > sld->size[0])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)(nl + 1U), 1, sld->size[0],
                                            &ml_emlrtBCI, &st);
            }
            thick = sld->data[nl];
            if (((int32_T)(nl + 1U) < 1) ||
                ((int32_T)(nl + 1U) > sld->size[0])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)(nl + 1U), 1, sld->size[0],
                                            &nl_emlrtBCI, &st);
            }
            preal = sld->data[nl + sld->size[0]];
            if (((int32_T)(nl + 1U) < 1) ||
                ((int32_T)(nl + 1U) > sld->size[0])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)(nl + 1U), 1, sld->size[0],
                                            &ol_emlrtBCI, &st);
            }
            rough = sld->data[nl + sld->size[0] * 2];
            preal = 1.0 - preal * 0.377451863036739;
            preal = preal * preal - preal_tmp;
            pimag.re = preal;
            pimag.im = preal * 0.0;
            c_sqrt(&pimag);
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
              num.re = muDoubleScalarExp(d);
              num.im = 0.0;
            } else if (muDoubleScalarIsInf(num.im) &&
                       muDoubleScalarIsInf(num.re) && (num.re < 0.0)) {
              num.re = 0.0;
              num.im = 0.0;
            } else {
              preal = muDoubleScalarExp(num.re / 2.0);
              d = num.im;
              d1 = num.im;
              num.re = preal * (preal * muDoubleScalarCos(d));
              num.im = preal * (preal * muDoubleScalarSin(d1));
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
            quo.re = -blast.re * 0.0 - (-blast.im);
            quo.im = -blast.re + -blast.im * 0.0;
            if (quo.im == 0.0) {
              d = quo.re;
              quo.re = muDoubleScalarExp(d);
              quo.im = 0.0;
            } else if (muDoubleScalarIsInf(quo.im) &&
                       muDoubleScalarIsInf(quo.re) && (quo.re < 0.0)) {
              quo.re = 0.0;
              quo.im = 0.0;
            } else {
              preal = muDoubleScalarExp(quo.re / 2.0);
              d = quo.im;
              d1 = quo.im;
              quo.re = preal * (preal * muDoubleScalarCos(d));
              quo.im = preal * (preal * muDoubleScalarSin(d1));
            }
            d = re * quo.re - im * quo.im;
            d1 = re * quo.im + im * quo.re;
            N[3] = quo;
            ar = re * x_re - im * x_im;
            preal = re * x_im + im * x_re;
            quo = pimag;
            blast = beta;
            thick = N[3].re;
            rough = N[3].im;
            for (i2 = 0; i2 < 2; i2++) {
              im = MI[i2].re;
              re = MI[i2].im;
              brm = MI[i2 + 2].re;
              quo_re = MI[i2 + 2].im;
              b_MI[i2].re = (im * x_re - re * x_im) + (brm * d - quo_re * d1);
              b_MI[i2].im = (im * x_im + re * x_re) + (brm * d1 + quo_re * d);
              b_MI[i2 + 2].re =
                  (im * ar - re * preal) + (brm * thick - quo_re * rough);
              b_MI[i2 + 2].im =
                  (im * preal + re * ar) + (brm * rough + quo_re * thick);
            }
            memcpy(&MI[0], &b_MI[0], 4U * sizeof(creal_T));
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(&st);
            }
          }
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
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
          num.re = muDoubleScalarExp(d);
          num.im = 0.0;
        } else if (muDoubleScalarIsInf(num.im) && muDoubleScalarIsInf(num.re) &&
                   (num.re < 0.0)) {
          num.re = 0.0;
          num.im = 0.0;
        } else {
          preal = muDoubleScalarExp(num.re / 2.0);
          d = num.im;
          d1 = num.im;
          num.re = preal * (preal * muDoubleScalarCos(d));
          num.im = preal * (preal * muDoubleScalarSin(d1));
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
          d = quo.re;
          quo.re = muDoubleScalarExp(d);
          quo.im = 0.0;
        } else if (muDoubleScalarIsInf(quo.im) && muDoubleScalarIsInf(quo.re) &&
                   (quo.re < 0.0)) {
          quo.re = 0.0;
          quo.im = 0.0;
        } else {
          preal = muDoubleScalarExp(quo.re / 2.0);
          d = quo.im;
          d1 = quo.im;
          quo.re = preal * (preal * muDoubleScalarCos(d));
          quo.im = preal * (preal * muDoubleScalarSin(d1));
        }
        d = re * quo.re - im * quo.im;
        d1 = re * quo.im + im * quo.re;
        ar = re * x_re - im * x_im;
        preal = re * x_im + im * x_re;
        for (i = 0; i < 2; i++) {
          thick = MI[i].re;
          rough = MI[i].im;
          im = MI[i + 2].re;
          re = MI[i + 2].im;
          b_MI[i].re = (thick * x_re - rough * x_im) + (im * d - re * d1);
          b_MI[i].im = (thick * x_im + rough * x_re) + (im * d1 + re * d);
          b_MI[i + 2].re =
              (thick * ar - rough * preal) + (im * quo.re - re * quo.im);
          b_MI[i + 2].im =
              (thick * preal + rough * ar) + (im * quo.im + re * quo.re);
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
        if (((int32_T)(loop + 1U) < 1) ||
            ((int32_T)(loop + 1U) > out->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(loop + 1U), 1, out->size[0],
                                        &pl_emlrtBCI, &st);
        }
        out->data[loop] = muDoubleScalarHypot(quo.re, quo.im);
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

/* End of code generation (abeles_paraPoints.c) */
