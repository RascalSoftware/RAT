/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * abeles_single.c
 *
 * Code generation for function 'abeles_single'
 *
 */

/* Include files */
#include "abeles_single.h"
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "rt_nonfinite.h"
#include "sqrt1.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo gg_emlrtRSI = {
    28,              /* lineNo */
    "abeles_single", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m" /* pathName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    14,     /* lineNo */
    9,      /* colNo */
    "asin", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/lib/matlab/elfun/asin.m" /* pName
                                                                           */
};

static emlrtBCInfo bg_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    41,              /* lineNo */
    25,              /* colNo */
    "sld",           /* aName */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtRTEInfo w_emlrtRTEI = {
    39,              /* lineNo */
    19,              /* colNo */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m" /* pName */
};

static emlrtBCInfo cg_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    34,              /* lineNo */
    17,              /* colNo */
    "sld",           /* aName */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo dg_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    27,              /* lineNo */
    11,              /* colNo */
    "x",             /* aName */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo eg_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    43,              /* lineNo */
    21,              /* colNo */
    "sld",           /* aName */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo fg_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    72,              /* lineNo */
    5,               /* colNo */
    "out",           /* aName */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtRTEInfo kg_emlrtRTEI = {
    9,               /* lineNo */
    7,               /* colNo */
    "abeles_single", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/"
    "reflectivityCalculations/Abeles/abeles_single.m" /* pName */
};

/* Function Definitions */
void abeles_single(const emlrtStack *sp, const emxArray_real_T *x,
                   const emxArray_real_T *sld, real_T nbair, real_T nbsub,
                   real_T nrepeats, real_T rsub, real_T layers, real_T points,
                   emxArray_real_T *out)
{
  emlrtStack st;
  creal_T MI[4];
  creal_T b_MI[4];
  creal_T pimag;
  creal_T psub;
  real_T ar;
  real_T ar_tmp;
  real_T blast_im;
  real_T blast_re;
  real_T brm;
  real_T d;
  real_T d1;
  real_T pair_im;
  real_T pair_re;
  real_T psub_tmp_tmp;
  real_T re;
  real_T rij_im;
  real_T rij_re;
  real_T rough;
  real_T snair;
  real_T snlay;
  real_T snsub;
  real_T theta;
  real_T x_im;
  real_T x_re;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop;
  int32_T nl;
  int32_T reploop;
  st.prev = sp;
  st.tls = sp->tls;
  /*  nbair = nbairs(thisCont); */
  /*  nbsub = nbsubs(thisCont); */
  /*  ssub = ssubs(thisCont); */
  /*  nrepeats = nrepeatss(thisCont); */
  /*  resol = resols(thisCont); */
  i = (int32_T)points;
  i1 = out->size[0];
  out->size[0] = (int32_T)points;
  emxEnsureCapacity_real_T(sp, out, i1, &kg_emlrtRTEI);
  /* pi = 3.141592653589; */
  snair = 1.0 - nbair * 0.377451863036739;
  snsub = 1.0 - nbsub * 0.377451863036739;
  if (0 <= i - 1) {
    i2 = (int32_T)nrepeats;
    if (0 <= i2 - 1) {
      i3 = (int32_T)layers;
    }
    ar_tmp = rsub * rsub;
  }
  for (loop = 0; loop < i; loop++) {
    if ((loop + 1 < 1) || (loop + 1 > x->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop + 1, 1, x->size[0], &dg_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &gg_emlrtRSI;
    theta = x->data[loop] * 1.54 / 12.566370614359172;
    if ((theta < -1.0) || (theta > 1.0)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &v_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "asin");
    }
    theta = muDoubleScalarAsin(theta);
    snlay = muDoubleScalarCos(theta);
    psub_tmp_tmp = snair * snair * (snlay * snlay);
    snlay = snsub * snsub - psub_tmp_tmp;
    psub.re = snlay;
    psub.im = snlay * 0.0;
    c_sqrt(&psub);
    pair_re = snair * muDoubleScalarSin(theta);
    pair_im = pair_re * 0.0;
    blast_re = 0.0;
    blast_im = 0.0;
    if (1 > sld->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, sld->size[0], &cg_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    MI[0].re = 1.0;
    MI[0].im = 0.0;
    MI[3].re = 1.0;
    MI[3].im = 0.0;
    MI[2].re = 0.0;
    MI[2].im = 0.0;
    MI[1].re = 0.0;
    MI[1].im = 0.0;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, nrepeats, mxDOUBLE_CLASS,
                                  (int32_T)nrepeats, &w_emlrtRTEI,
                                  (emlrtCTX)sp);
    for (reploop = 0; reploop < i2; reploop++) {
      for (nl = 0; nl < i3; nl++) {
        if ((nl + 1 < 1) || (nl + 1 > sld->size[0])) {
          emlrtDynamicBoundsCheckR2012b(nl + 1, 1, sld->size[0], &bg_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (((int32_T)(nl + 1U) < 1) || ((int32_T)(nl + 1U) > sld->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(nl + 1U), 1, sld->size[0],
                                        &eg_emlrtBCI, (emlrtCTX)sp);
        }
        rough = sld->data[nl + sld->size[0] * 2];
        snlay = 1.0 - sld->data[nl + sld->size[0]] * 0.377451863036739;
        theta = snlay * snlay - psub_tmp_tmp;
        pimag.re = theta;
        pimag.im = theta * 0.0;
        c_sqrt(&pimag);
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
          rij_re = muDoubleScalarExp(rij_re);
          rij_im = 0.0;
        } else if (muDoubleScalarIsInf(rij_im) && muDoubleScalarIsInf(rij_re) &&
                   (rij_re < 0.0)) {
          rij_re = 0.0;
          rij_im = 0.0;
        } else {
          theta = muDoubleScalarExp(rij_re / 2.0);
          rij_re = theta * (theta * muDoubleScalarCos(rij_im));
          rij_im = theta * (theta * muDoubleScalarSin(rij_im));
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
          brm = muDoubleScalarAbs(theta);
          re = muDoubleScalarAbs(snlay);
          if (brm > re) {
            re = snlay / theta;
            theta += re * snlay;
            pair_re = (ar + re * rough) / theta;
            pair_im = (rough - re * ar) / theta;
          } else if (re == brm) {
            if (theta > 0.0) {
              re = 0.5;
            } else {
              re = -0.5;
            }
            if (snlay > 0.0) {
              theta = 0.5;
            } else {
              theta = -0.5;
            }
            pair_re = (ar * re + rough * theta) / brm;
            pair_im = (rough * re - ar * theta) / brm;
          } else {
            re = theta / snlay;
            theta = snlay + re * theta;
            pair_re = (re * ar + rough) / theta;
            pair_im = (re * rough - ar) / theta;
          }
        }
        re = pair_re * rij_re - pair_im * rij_im;
        snlay = pair_re * rij_im + pair_im * rij_re;
        x_re = blast_re * 0.0 - blast_im;
        x_im = blast_re + blast_im * 0.0;
        if (x_im == 0.0) {
          x_re = muDoubleScalarExp(x_re);
          x_im = 0.0;
        } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) &&
                   (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          theta = muDoubleScalarExp(x_re / 2.0);
          x_re = theta * (theta * muDoubleScalarCos(x_im));
          x_im = theta * (theta * muDoubleScalarSin(x_im));
        }
        pair_re = -blast_re * 0.0 - (-blast_im);
        pair_im = -blast_re + -blast_im * 0.0;
        if (pair_im == 0.0) {
          pair_re = muDoubleScalarExp(pair_re);
          pair_im = 0.0;
        } else if (muDoubleScalarIsInf(pair_im) &&
                   muDoubleScalarIsInf(pair_re) && (pair_re < 0.0)) {
          pair_re = 0.0;
          pair_im = 0.0;
        } else {
          theta = muDoubleScalarExp(pair_re / 2.0);
          pair_re = theta * (theta * muDoubleScalarCos(pair_im));
          pair_im = theta * (theta * muDoubleScalarSin(pair_im));
        }
        brm = re * pair_re - snlay * pair_im;
        rij_im = re * pair_im + snlay * pair_re;
        ar = pair_re;
        d = pair_im;
        d1 = re * x_re - snlay * x_im;
        theta = re * x_im + snlay * x_re;
        pair_re = pimag.re;
        pair_im = pimag.im;
        blast_re = 4.0799904592075231 * sld->data[nl] * pimag.re;
        blast_im = 4.0799904592075231 * sld->data[nl] * pimag.im;
        for (i1 = 0; i1 < 2; i1++) {
          snlay = MI[i1].re;
          rough = MI[i1].im;
          rij_re = MI[i1 + 2].re;
          re = MI[i1 + 2].im;
          b_MI[i1].re =
              (snlay * x_re - rough * x_im) + (rij_re * brm - re * rij_im);
          b_MI[i1].im =
              (snlay * x_im + rough * x_re) + (rij_re * rij_im + re * brm);
          b_MI[i1 + 2].re =
              (snlay * d1 - rough * theta) + (rij_re * ar - re * d);
          b_MI[i1 + 2].im =
              (snlay * theta + rough * d1) + (rij_re * d + re * ar);
        }
        memcpy(&MI[0], &b_MI[0], 4U * sizeof(creal_T));
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtCTX)sp);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
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
      rij_re = muDoubleScalarExp(rij_re);
      rij_im = 0.0;
    } else if (muDoubleScalarIsInf(rij_im) && muDoubleScalarIsInf(rij_re) &&
               (rij_re < 0.0)) {
      rij_re = 0.0;
      rij_im = 0.0;
    } else {
      theta = muDoubleScalarExp(rij_re / 2.0);
      rij_re = theta * (theta * muDoubleScalarCos(rij_im));
      rij_im = theta * (theta * muDoubleScalarSin(rij_im));
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
      brm = muDoubleScalarAbs(theta);
      re = muDoubleScalarAbs(snlay);
      if (brm > re) {
        re = snlay / theta;
        theta += re * snlay;
        pair_re = (ar + re * rough) / theta;
        pair_im = (rough - re * ar) / theta;
      } else if (re == brm) {
        if (theta > 0.0) {
          re = 0.5;
        } else {
          re = -0.5;
        }
        if (snlay > 0.0) {
          theta = 0.5;
        } else {
          theta = -0.5;
        }
        pair_re = (ar * re + rough * theta) / brm;
        pair_im = (rough * re - ar * theta) / brm;
      } else {
        re = theta / snlay;
        theta = snlay + re * theta;
        pair_re = (re * ar + rough) / theta;
        pair_im = (re * rough - ar) / theta;
      }
    }
    re = pair_re * rij_re - pair_im * rij_im;
    snlay = pair_re * rij_im + pair_im * rij_re;
    x_re = blast_re * 0.0 - blast_im;
    x_im = blast_re + blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = muDoubleScalarExp(x_re);
      x_im = 0.0;
    } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) &&
               (x_re < 0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      theta = muDoubleScalarExp(x_re / 2.0);
      x_re = theta * (theta * muDoubleScalarCos(x_im));
      x_im = theta * (theta * muDoubleScalarSin(x_im));
    }
    pair_re = -blast_re * 0.0 - (-blast_im);
    pair_im = -blast_re + -blast_im * 0.0;
    if (pair_im == 0.0) {
      pair_re = muDoubleScalarExp(pair_re);
      pair_im = 0.0;
    } else if (muDoubleScalarIsInf(pair_im) && muDoubleScalarIsInf(pair_re) &&
               (pair_re < 0.0)) {
      pair_re = 0.0;
      pair_im = 0.0;
    } else {
      theta = muDoubleScalarExp(pair_re / 2.0);
      pair_re = theta * (theta * muDoubleScalarCos(pair_im));
      pair_im = theta * (theta * muDoubleScalarSin(pair_im));
    }
    brm = re * pair_re - snlay * pair_im;
    rij_im = re * pair_im + snlay * pair_re;
    ar = re * x_re - snlay * x_im;
    d = re * x_im + snlay * x_re;
    for (i1 = 0; i1 < 2; i1++) {
      d1 = MI[i1].re;
      theta = MI[i1].im;
      snlay = MI[i1 + 2].re;
      rough = MI[i1 + 2].im;
      b_MI[i1].re = (d1 * x_re - theta * x_im) + (snlay * brm - rough * rij_im);
      b_MI[i1].im = (d1 * x_im + theta * x_re) + (snlay * rij_im + rough * brm);
      b_MI[i1 + 2].re =
          (d1 * ar - theta * d) + (snlay * pair_re - rough * pair_im);
      b_MI[i1 + 2].im =
          (d1 * d + theta * ar) + (snlay * pair_im + rough * pair_re);
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
      brm = muDoubleScalarAbs(theta);
      re = muDoubleScalarAbs(snlay);
      if (brm > re) {
        re = snlay / theta;
        theta += re * snlay;
        pair_re = (rough + re * rij_re) / theta;
        pair_im = (rij_re - re * rough) / theta;
      } else if (re == brm) {
        if (theta > 0.0) {
          re = 0.5;
        } else {
          re = -0.5;
        }
        if (snlay > 0.0) {
          theta = 0.5;
        } else {
          theta = -0.5;
        }
        pair_re = (rough * re + rij_re * theta) / brm;
        pair_im = (rij_re * re - rough * theta) / brm;
      } else {
        re = theta / snlay;
        theta = snlay + re * theta;
        pair_re = (re * rough + rij_re) / theta;
        pair_im = (re * rij_re - rough) / theta;
      }
    }
    if (((int32_T)(loop + 1U) < 1) || ((int32_T)(loop + 1U) > out->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(loop + 1U), 1, out->size[0],
                                    &fg_emlrtBCI, (emlrtCTX)sp);
    }
    out->data[loop] = muDoubleScalarHypot(pair_re, pair_im);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
}

/* End of code generation (abeles_single.c) */
