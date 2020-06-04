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
#include "mpower.h"
#include "error.h"
#include "standardTF_custlay_single_emxutil.h"
#include "sqrt.h"
#include "standardTF_custlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo gd_emlrtRSI = { 28, /* lineNo */
  "abeles",                            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 29, /* lineNo */
  "abeles",                            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 45, /* lineNo */
  "abeles",                            /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 13, /* lineNo */
  "asin",                              /* fcnName */
  "/usr/local/MATLAB/R2016b/toolbox/eml/lib/matlab/elfun/asin.m"/* pathName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 1,/* lineNo */
  16,                                  /* colNo */
  "abeles",                            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m"/* pName */
};

static emlrtBCInfo ve_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  9,                                   /* colNo */
  "x",                                 /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  17,                                  /* colNo */
  "sld",                               /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo fc_emlrtRTEI = { 39,/* lineNo */
  19,                                  /* colNo */
  "abeles",                            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m"/* pName */
};

static emlrtBCInfo xe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  25,                                  /* colNo */
  "sld",                               /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  23,                                  /* colNo */
  "sld",                               /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  25,                                  /* colNo */
  "sld",                               /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  5,                                   /* colNo */
  "out",                               /* aName */
  "abeles",                            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/abeles.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void abeles(const emlrtStack *sp, const emxArray_real_T *x, const
            emxArray_real_T *sld, real_T nbair, real_T nbsub, real_T nrepeats,
            real_T ssub, real_T layers, real_T points, emxArray_real_T *out)
{
  real_T snair;
  real_T snsub;
  int32_T i14;
  int32_T loop;
  int32_T i15;
  real_T preal;
  real_T theta;
  creal_T psub;
  real_T plast_re;
  real_T plast_im;
  real_T blast_re;
  real_T blast_im;
  creal_T MI[4];
  int32_T reploop;
  int32_T nl;
  real_T im;
  real_T rij_re;
  real_T ai;
  real_T x_re;
  real_T r;
  real_T x_im;
  real_T brm;
  creal_T pimag;
  creal_T N[4];
  creal_T b_MI[4];
  int32_T i16;
  real_T b_r;
  real_T b_rij_re;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 13U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 0U);

  /*  nbair = nbairs(thisCont); */
  /*  nbsub = nbsubs(thisCont); */
  /*  ssub = ssubs(thisCont); */
  /*  nrepeats = nrepeatss(thisCont); */
  /*  resol = resols(thisCont); */
  snair = 1.0 - nbair * 3.2228875976108808;
  snsub = 1.0 - nbsub * 3.2228875976108808;
  i14 = out->size[0];
  out->size[0] = (int32_T)points;
  emxEnsureCapacity(sp, (emxArray__common *)out, i14, (int32_T)sizeof(real_T),
                    &mb_emlrtRTEI);
  loop = 0;
  while (loop <= (int32_T)points - 1) {
    covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 1U);
    i14 = x->size[1];
    i15 = loop + 1;
    if (!((i15 >= 1) && (i15 <= i14))) {
      emlrtDynamicBoundsCheckR2012b(i15, 1, i14, &ve_emlrtBCI, sp);
    }

    preal = x->data[loop] * 4.5 / 12.566370614359172;
    st.site = &gd_emlrtRSI;
    if ((preal < -1.0) || (preal > 1.0)) {
      b_st.site = &jd_emlrtRSI;
      c_error(&b_st);
    }

    theta = muDoubleScalarAsin(preal);
    st.site = &hd_emlrtRSI;
    preal = snsub * snsub - snair * snair * b_mpower(muDoubleScalarCos(theta));
    psub.re = preal;
    psub.im = preal * 0.0;
    b_sqrt(&psub);
    plast_re = snair * muDoubleScalarSin(theta);
    plast_im = snair * muDoubleScalarSin(theta) * 0.0;
    blast_re = 0.0;
    blast_im = 0.0;
    i14 = sld->size[0];
    if (!(1 <= i14)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i14, &we_emlrtBCI, sp);
    }

    MI[0].re = 1.0;
    MI[0].im = 0.0;
    MI[3].re = 1.0;
    MI[3].im = 0.0;
    MI[2].re = 0.0;
    MI[2].im = 0.0;
    MI[1].re = 0.0;
    MI[1].im = 0.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nrepeats, mxDOUBLE_CLASS, (int32_T)
      nrepeats, &fc_emlrtRTEI, sp);
    reploop = 0;
    while (reploop <= (int32_T)nrepeats - 1) {
      covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 1, 1);
      nl = 0;
      while (nl <= (int32_T)layers - 1) {
        covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 2, 1);
        covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 2U);
        i14 = sld->size[0];
        i15 = nl + 1;
        if (!((i15 >= 1) && (i15 <= i14))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, i14, &xe_emlrtBCI, sp);
        }

        i14 = sld->size[0];
        i15 = nl + 1;
        if (!((i15 >= 1) && (i15 <= i14))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, i14, &ye_emlrtBCI, sp);
        }

        i14 = sld->size[0];
        i15 = nl + 1;
        if (!((i15 >= 1) && (i15 <= i14))) {
          emlrtDynamicBoundsCheckR2012b(i15, 1, i14, &af_emlrtBCI, sp);
        }

        preal = 1.0 - sld->data[nl + sld->size[0]] * 3.2228875976108808;
        st.site = &id_emlrtRSI;
        preal = preal * preal - snair * snair * b_mpower(muDoubleScalarCos(theta));
        pimag.re = preal;
        pimag.im = preal * 0.0;
        b_sqrt(&pimag);
        preal = -78.956835208714864 * plast_re;
        im = -78.956835208714864 * plast_im;
        rij_re = (preal * pimag.re - im * pimag.im) * (sld->data[nl + (sld->
          size[0] << 1)] * sld->data[nl + (sld->size[0] << 1)]);
        ai = (preal * pimag.im + im * pimag.re) * (sld->data[nl + (sld->size[0] <<
          1)] * sld->data[nl + (sld->size[0] << 1)]);
        if (ai == 0.0) {
          rij_re /= 20.25;
          preal = 0.0;
        } else if (rij_re == 0.0) {
          rij_re = 0.0;
          preal = ai / 20.25;
        } else {
          rij_re /= 20.25;
          preal = ai / 20.25;
        }

        if (preal == 0.0) {
          x_re = muDoubleScalarExp(rij_re);
          x_im = 0.0;
        } else if (muDoubleScalarIsInf(preal) && muDoubleScalarIsInf(rij_re) &&
                   (rij_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          r = muDoubleScalarExp(rij_re / 2.0);
          x_re = r * (r * muDoubleScalarCos(preal));
          x_im = r * (r * muDoubleScalarSin(preal));
        }

        rij_re = plast_re - pimag.re;
        ai = plast_im - pimag.im;
        preal = plast_re + pimag.re;
        r = plast_im + pimag.im;
        if (r == 0.0) {
          if (ai == 0.0) {
            plast_re = rij_re / preal;
            plast_im = 0.0;
          } else if (rij_re == 0.0) {
            plast_re = 0.0;
            plast_im = ai / preal;
          } else {
            plast_re = rij_re / preal;
            plast_im = ai / preal;
          }
        } else if (preal == 0.0) {
          if (rij_re == 0.0) {
            plast_re = ai / r;
            plast_im = 0.0;
          } else if (ai == 0.0) {
            plast_re = 0.0;
            plast_im = -(rij_re / r);
          } else {
            plast_re = ai / r;
            plast_im = -(rij_re / r);
          }
        } else {
          brm = muDoubleScalarAbs(preal);
          plast_im = muDoubleScalarAbs(r);
          if (brm > plast_im) {
            plast_im = r / preal;
            preal += plast_im * r;
            plast_re = (rij_re + plast_im * ai) / preal;
            plast_im = (ai - plast_im * rij_re) / preal;
          } else if (plast_im == brm) {
            if (preal > 0.0) {
              im = 0.5;
            } else {
              im = -0.5;
            }

            if (r > 0.0) {
              preal = 0.5;
            } else {
              preal = -0.5;
            }

            plast_re = (rij_re * im + ai * preal) / brm;
            plast_im = (ai * im - rij_re * preal) / brm;
          } else {
            plast_im = preal / r;
            preal = r + plast_im * preal;
            plast_re = (plast_im * rij_re + ai) / preal;
            plast_im = (plast_im * ai - rij_re) / preal;
          }
        }

        rij_re = plast_re * x_re - plast_im * x_im;
        preal = plast_re * x_im + plast_im * x_re;
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
          r = muDoubleScalarExp(x_re / 2.0);
          x_re = r * (r * muDoubleScalarCos(x_im));
          x_im = r * (r * muDoubleScalarSin(x_im));
        }

        N[0].re = x_re;
        N[0].im = x_im;
        x_re = -blast_re * 0.0 - (-blast_im);
        x_im = -blast_re + -blast_im * 0.0;
        if (x_im == 0.0) {
          x_re = muDoubleScalarExp(x_re);
          x_im = 0.0;
        } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) &&
                   (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          r = muDoubleScalarExp(x_re / 2.0);
          x_re = r * (r * muDoubleScalarCos(x_im));
          x_im = r * (r * muDoubleScalarSin(x_im));
        }

        N[1].re = rij_re * x_re - preal * x_im;
        N[1].im = rij_re * x_im + preal * x_re;
        x_re = -blast_re * 0.0 - (-blast_im);
        x_im = -blast_re + -blast_im * 0.0;
        if (x_im == 0.0) {
          x_re = muDoubleScalarExp(x_re);
          x_im = 0.0;
        } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) &&
                   (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          r = muDoubleScalarExp(x_re / 2.0);
          x_re = r * (r * muDoubleScalarCos(x_im));
          x_im = r * (r * muDoubleScalarSin(x_im));
        }

        N[3].re = x_re;
        N[3].im = x_im;
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
          r = muDoubleScalarExp(x_re / 2.0);
          x_re = r * (r * muDoubleScalarCos(x_im));
          x_im = r * (r * muDoubleScalarSin(x_im));
        }

        N[2].re = rij_re * x_re - preal * x_im;
        N[2].im = rij_re * x_im + preal * x_re;
        plast_re = pimag.re;
        plast_im = pimag.im;
        blast_re = 1.3962634015954636 * sld->data[nl] * pimag.re;
        blast_im = 1.3962634015954636 * sld->data[nl] * pimag.im;
        for (i14 = 0; i14 < 2; i14++) {
          for (i15 = 0; i15 < 2; i15++) {
            b_MI[i14 + (i15 << 1)].re = 0.0;
            b_MI[i14 + (i15 << 1)].im = 0.0;
            for (i16 = 0; i16 < 2; i16++) {
              b_MI[i14 + (i15 << 1)].re += MI[i14 + (i16 << 1)].re * N[i16 +
                (i15 << 1)].re - MI[i14 + (i16 << 1)].im * N[i16 + (i15 << 1)].
                im;
              b_MI[i14 + (i15 << 1)].im += MI[i14 + (i16 << 1)].re * N[i16 +
                (i15 << 1)].im + MI[i14 + (i16 << 1)].im * N[i16 + (i15 << 1)].
                re;
            }
          }
        }

        for (i14 = 0; i14 < 2; i14++) {
          for (i15 = 0; i15 < 2; i15++) {
            MI[i15 + (i14 << 1)] = b_MI[i15 + (i14 << 1)];
          }
        }

        nl++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 2, 0);
      reploop++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 1, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 3U);
    preal = -78.956835208714864 * plast_re;
    im = -78.956835208714864 * plast_im;
    rij_re = (preal * psub.re - im * psub.im) * (ssub * ssub);
    ai = (preal * psub.im + im * psub.re) * (ssub * ssub);
    if (ai == 0.0) {
      rij_re /= 20.25;
      preal = 0.0;
    } else if (rij_re == 0.0) {
      rij_re = 0.0;
      preal = ai / 20.25;
    } else {
      rij_re /= 20.25;
      preal = ai / 20.25;
    }

    if (preal == 0.0) {
      x_re = muDoubleScalarExp(rij_re);
      x_im = 0.0;
    } else if (muDoubleScalarIsInf(preal) && muDoubleScalarIsInf(rij_re) &&
               (rij_re < 0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      r = muDoubleScalarExp(rij_re / 2.0);
      x_re = r * (r * muDoubleScalarCos(preal));
      x_im = r * (r * muDoubleScalarSin(preal));
    }

    rij_re = plast_re - psub.re;
    ai = plast_im - psub.im;
    preal = plast_re + psub.re;
    r = plast_im + psub.im;
    if (r == 0.0) {
      if (ai == 0.0) {
        plast_re = rij_re / preal;
        plast_im = 0.0;
      } else if (rij_re == 0.0) {
        plast_re = 0.0;
        plast_im = ai / preal;
      } else {
        plast_re = rij_re / preal;
        plast_im = ai / preal;
      }
    } else if (preal == 0.0) {
      if (rij_re == 0.0) {
        plast_re = ai / r;
        plast_im = 0.0;
      } else if (ai == 0.0) {
        plast_re = 0.0;
        plast_im = -(rij_re / r);
      } else {
        plast_re = ai / r;
        plast_im = -(rij_re / r);
      }
    } else {
      brm = muDoubleScalarAbs(preal);
      plast_im = muDoubleScalarAbs(r);
      if (brm > plast_im) {
        plast_im = r / preal;
        preal += plast_im * r;
        plast_re = (rij_re + plast_im * ai) / preal;
        plast_im = (ai - plast_im * rij_re) / preal;
      } else if (plast_im == brm) {
        if (preal > 0.0) {
          im = 0.5;
        } else {
          im = -0.5;
        }

        if (r > 0.0) {
          preal = 0.5;
        } else {
          preal = -0.5;
        }

        plast_re = (rij_re * im + ai * preal) / brm;
        plast_im = (ai * im - rij_re * preal) / brm;
      } else {
        plast_im = preal / r;
        preal = r + plast_im * preal;
        plast_re = (plast_im * rij_re + ai) / preal;
        plast_im = (plast_im * ai - rij_re) / preal;
      }
    }

    rij_re = plast_re * x_re - plast_im * x_im;
    preal = plast_re * x_im + plast_im * x_re;
    x_re = blast_re * 0.0 - blast_im;
    x_im = blast_re + blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = muDoubleScalarExp(x_re);
      x_im = 0.0;
    } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) && (x_re <
                0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      r = muDoubleScalarExp(x_re / 2.0);
      x_re = r * (r * muDoubleScalarCos(x_im));
      x_im = r * (r * muDoubleScalarSin(x_im));
    }

    N[0].re = x_re;
    N[0].im = x_im;
    x_re = -blast_re * 0.0 - (-blast_im);
    x_im = -blast_re + -blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = muDoubleScalarExp(x_re);
      x_im = 0.0;
    } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) && (x_re <
                0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      r = muDoubleScalarExp(x_re / 2.0);
      x_re = r * (r * muDoubleScalarCos(x_im));
      x_im = r * (r * muDoubleScalarSin(x_im));
    }

    N[1].re = rij_re * x_re - preal * x_im;
    N[1].im = rij_re * x_im + preal * x_re;
    x_re = -blast_re * 0.0 - (-blast_im);
    x_im = -blast_re + -blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = muDoubleScalarExp(x_re);
      x_im = 0.0;
    } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) && (x_re <
                0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      r = muDoubleScalarExp(x_re / 2.0);
      x_re = r * (r * muDoubleScalarCos(x_im));
      x_im = r * (r * muDoubleScalarSin(x_im));
    }

    N[3].re = x_re;
    N[3].im = x_im;
    x_re = blast_re * 0.0 - blast_im;
    x_im = blast_re + blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = muDoubleScalarExp(x_re);
      x_im = 0.0;
    } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) && (x_re <
                0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      r = muDoubleScalarExp(x_re / 2.0);
      x_re = r * (r * muDoubleScalarCos(x_im));
      x_im = r * (r * muDoubleScalarSin(x_im));
    }

    N[2].re = rij_re * x_re - preal * x_im;
    N[2].im = rij_re * x_im + preal * x_re;
    for (i14 = 0; i14 < 2; i14++) {
      for (i15 = 0; i15 < 2; i15++) {
        b_MI[i14 + (i15 << 1)].re = 0.0;
        b_MI[i14 + (i15 << 1)].im = 0.0;
        for (i16 = 0; i16 < 2; i16++) {
          b_MI[i14 + (i15 << 1)].re += MI[i14 + (i16 << 1)].re * N[i16 + (i15 <<
            1)].re - MI[i14 + (i16 << 1)].im * N[i16 + (i15 << 1)].im;
          b_MI[i14 + (i15 << 1)].im += MI[i14 + (i16 << 1)].re * N[i16 + (i15 <<
            1)].im + MI[i14 + (i16 << 1)].im * N[i16 + (i15 << 1)].re;
        }
      }
    }

    for (i14 = 0; i14 < 2; i14++) {
      for (i15 = 0; i15 < 2; i15++) {
        MI[i15 + (i14 << 1)] = b_MI[i15 + (i14 << 1)];
      }
    }

    preal = MI[1].re * MI[1].re - MI[1].im * -MI[1].im;
    im = MI[1].re * -MI[1].im + MI[1].im * MI[1].re;
    r = MI[0].re * MI[0].re - MI[0].im * -MI[0].im;
    rij_re = MI[0].re * -MI[0].im + MI[0].im * MI[0].re;
    if (rij_re == 0.0) {
      if (im == 0.0) {
        preal /= r;
      } else if (preal == 0.0) {
        preal = 0.0;
      } else {
        preal /= r;
      }
    } else if (r == 0.0) {
      if (preal == 0.0) {
        preal = im / rij_re;
      } else if (im == 0.0) {
        preal = 0.0;
      } else {
        preal = im / rij_re;
      }
    } else {
      brm = muDoubleScalarAbs(r);
      plast_im = muDoubleScalarAbs(rij_re);
      if (brm > plast_im) {
        plast_im = rij_re / r;
        preal = (preal + plast_im * im) / (r + plast_im * rij_re);
      } else if (plast_im == brm) {
        if (r > 0.0) {
          b_r = 0.5;
        } else {
          b_r = -0.5;
        }

        if (rij_re > 0.0) {
          b_rij_re = 0.5;
        } else {
          b_rij_re = -0.5;
        }

        preal = (preal * b_r + im * b_rij_re) / brm;
      } else {
        plast_im = r / rij_re;
        preal = (plast_im * preal + im) / (rij_re + plast_im * r);
      }
    }

    i14 = out->size[0];
    if (!((loop + 1 >= 1) && (loop + 1 <= i14))) {
      emlrtDynamicBoundsCheckR2012b(loop + 1, 1, i14, &bf_emlrtBCI, sp);
    }

    out->data[loop] = preal;
    loop++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 13U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 13U, 4U);
}

/* End of code generation (abeles.c) */
