/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * sldFunc.c
 *
 * Code generation for function 'sldFunc'
 *
 */

/* Include files */
#include "sldFunc.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo nd_emlrtRSI = { 24, /* lineNo */
  "sldFunc",                           /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 29, /* lineNo */
  "sldFunc",                           /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 30, /* lineNo */
  "sldFunc",                           /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pathName */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  18,                                  /* colNo */
  "rho",                               /* aName */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  23,                                  /* colNo */
  "belowVals",                         /* aName */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  23,                                  /* colNo */
  "aboveVals",                         /* aName */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  18,                                  /* colNo */
  "rho",                               /* aName */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  18,                                  /* colNo */
  "rho",                               /* aName */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  15,                                  /* colNo */
  "z",                                 /* aName */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  26,                                  /* colNo */
  "z",                                 /* aName */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  20,                                  /* colNo */
  "z",                                 /* aName */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo li_emlrtRTEI = { 24,/* lineNo */
  14,                                  /* colNo */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo ni_emlrtRTEI = { 24,/* lineNo */
  1,                                   /* colNo */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo pi_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo qi_emlrtRTEI = { 29,/* lineNo */
  22,                                  /* colNo */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo ri_emlrtRTEI = { 29,/* lineNo */
  5,                                   /* colNo */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo si_emlrtRTEI = { 30,/* lineNo */
  22,                                  /* colNo */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo ti_emlrtRTEI = { 30,/* lineNo */
  5,                                   /* colNo */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo ui_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

static emlrtRTEInfo vi_emlrtRTEI = { 46,/* lineNo */
  9,                                   /* colNo */
  "sldFunc",                           /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"/* pName */
};

/* Function Definitions */
void sldFunc(const emlrtStack *sp, real_T x, const emxArray_real_T *SLD,
             emxArray_real_T *sldVal)
{
  emxArray_boolean_T *b_x;
  int32_T loop_ub;
  int32_T i;
  emxArray_int32_T *ii;
  int32_T nx;
  int32_T idx;
  boolean_T overflow;
  boolean_T exitg1;
  int32_T iv[2];
  emxArray_uint32_T *where;
  emxArray_uint32_T *aboveVals;
  real_T deltaY_tmp;
  real_T deltaY;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &b_x, 1, &li_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 16U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 0U);

  /*  sldVal = sldFunc(x,SLD) */
  /*  SLD = [x rho;....xn rho] */
  /*    x = value in Angstrom. */
  /*  */
  /*  This function returns the SLD (y) value associated with the */
  /*  supplied value of x. SLD is a two column, XY array defining an */
  /*  SLD profile. This function interpolates the SLD profile */
  /*  to return the SLD at the specific value of X. X can be a vector of */
  /*  multiple points. */
  /*  */
  /*  (c) Arwel Hughes 2019. */
  /*  Last modified - AVH, 26/11/19. */
  /*  global sldProfile */
  /*   */
  /*  SLD = sldProfile; */
  /* SLD = getappdata(0,'sldFuncSLD'); */
  st.site = &nd_emlrtRSI;
  loop_ub = SLD->size[0];
  i = b_x->size[0];
  b_x->size[0] = SLD->size[0];
  emxEnsureCapacity_boolean_T(&st, b_x, i, &li_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    b_x->data[i] = (SLD->data[i] == x);
  }

  emxInit_int32_T(&st, &ii, 1, &wi_emlrtRTEI, true);
  b_st.site = &qd_emlrtRSI;
  nx = b_x->size[0];
  c_st.site = &rd_emlrtRSI;
  idx = 0;
  i = ii->size[0];
  ii->size[0] = b_x->size[0];
  emxEnsureCapacity_int32_T(&c_st, ii, i, &mi_emlrtRTEI);
  d_st.site = &sd_emlrtRSI;
  overflow = ((1 <= b_x->size[0]) && (b_x->size[0] > 2147483646));
  if (overflow) {
    e_st.site = &yb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= nx - 1)) {
    if (b_x->data[loop_ub]) {
      idx++;
      ii->data[idx - 1] = loop_ub + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        loop_ub++;
      }
    } else {
      loop_ub++;
    }
  }

  if (idx > b_x->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &lb_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (b_x->size[0] == 1) {
    if (idx == 0) {
      ii->size[0] = 0;
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }

    iv[0] = 1;
    iv[1] = idx;
    d_st.site = &td_emlrtRSI;
    indexShapeCheck(&d_st, ii->size[0], iv);
    i = ii->size[0];
    ii->size[0] = idx;
    emxEnsureCapacity_int32_T(&c_st, ii, i, &oi_emlrtRTEI);
  }

  emxInit_uint32_T(&c_st, &where, 1, &ni_emlrtRTEI, true);
  i = where->size[0];
  where->size[0] = ii->size[0];
  emxEnsureCapacity_uint32_T(&st, where, i, &ni_emlrtRTEI);
  loop_ub = ii->size[0];
  for (i = 0; i < loop_ub; i++) {
    where->data[i] = (uint32_T)ii->data[i];
  }

  if (covrtLogIf(&emlrtCoverageInstance, 16U, 0U, 0, covrtLogMcdc
                 (&emlrtCoverageInstance, 16U, 0U, 0, !covrtLogCond
                  (&emlrtCoverageInstance, 16U, 0U, 0, where->size[0] == 0)))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 1U);
    i = sldVal->size[0];
    sldVal->size[0] = where->size[0];
    emxEnsureCapacity_real_T(sp, sldVal, i, &pi_emlrtRTEI);
    loop_ub = where->size[0];
    for (i = 0; i < loop_ub; i++) {
      if (((int32_T)where->data[i] < 1) || ((int32_T)where->data[i] > SLD->size
           [0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)where->data[i], 1, SLD->size[0],
          &yd_emlrtBCI, sp);
      }

      sldVal->data[i] = SLD->data[((int32_T)where->data[i] + SLD->size[0]) - 1];
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 2U);
    st.site = &od_emlrtRSI;
    loop_ub = SLD->size[0];
    i = b_x->size[0];
    b_x->size[0] = SLD->size[0];
    emxEnsureCapacity_boolean_T(&st, b_x, i, &qi_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_x->data[i] = (x > SLD->data[i]);
    }

    b_st.site = &qd_emlrtRSI;
    nx = b_x->size[0];
    c_st.site = &rd_emlrtRSI;
    idx = 0;
    i = ii->size[0];
    ii->size[0] = b_x->size[0];
    emxEnsureCapacity_int32_T(&c_st, ii, i, &mi_emlrtRTEI);
    d_st.site = &sd_emlrtRSI;
    overflow = ((1 <= b_x->size[0]) && (b_x->size[0] > 2147483646));
    if (overflow) {
      e_st.site = &yb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= nx - 1)) {
      if (b_x->data[loop_ub]) {
        idx++;
        ii->data[idx - 1] = loop_ub + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          loop_ub++;
        }
      } else {
        loop_ub++;
      }
    }

    if (idx > b_x->size[0]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &lb_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (b_x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }

      iv[0] = 1;
      iv[1] = idx;
      d_st.site = &td_emlrtRSI;
      indexShapeCheck(&d_st, ii->size[0], iv);
      i = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(&c_st, ii, i, &oi_emlrtRTEI);
    }

    i = where->size[0];
    where->size[0] = ii->size[0];
    emxEnsureCapacity_uint32_T(&st, where, i, &ri_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      where->data[i] = (uint32_T)ii->data[i];
    }

    st.site = &pd_emlrtRSI;
    loop_ub = SLD->size[0];
    i = b_x->size[0];
    b_x->size[0] = SLD->size[0];
    emxEnsureCapacity_boolean_T(&st, b_x, i, &si_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_x->data[i] = (x < SLD->data[i]);
    }

    b_st.site = &qd_emlrtRSI;
    nx = b_x->size[0];
    c_st.site = &rd_emlrtRSI;
    idx = 0;
    i = ii->size[0];
    ii->size[0] = b_x->size[0];
    emxEnsureCapacity_int32_T(&c_st, ii, i, &mi_emlrtRTEI);
    d_st.site = &sd_emlrtRSI;
    overflow = ((1 <= b_x->size[0]) && (b_x->size[0] > 2147483646));
    if (overflow) {
      e_st.site = &yb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= nx - 1)) {
      if (b_x->data[loop_ub]) {
        idx++;
        ii->data[idx - 1] = loop_ub + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          loop_ub++;
        }
      } else {
        loop_ub++;
      }
    }

    if (idx > b_x->size[0]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &lb_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (b_x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }

      iv[0] = 1;
      iv[1] = idx;
      d_st.site = &td_emlrtRSI;
      indexShapeCheck(&d_st, ii->size[0], iv);
      i = ii->size[0];
      ii->size[0] = idx;
      emxEnsureCapacity_int32_T(&c_st, ii, i, &oi_emlrtRTEI);
    }

    emxInit_uint32_T(&c_st, &aboveVals, 1, &ti_emlrtRTEI, true);
    i = aboveVals->size[0];
    aboveVals->size[0] = ii->size[0];
    emxEnsureCapacity_uint32_T(&st, aboveVals, i, &ti_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      aboveVals->data[i] = (uint32_T)ii->data[i];
    }

    if (where->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(where->size[0], 1, where->size[0],
        &ae_emlrtBCI, sp);
    }

    if (1 > aboveVals->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, aboveVals->size[0], &be_emlrtBCI, sp);
    }

    i = (int32_T)where->data[where->size[0] - 1];
    if ((i < 1) || (i > SLD->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, SLD->size[0], &ce_emlrtBCI, sp);
    }

    i = (int32_T)aboveVals->data[0];
    if ((i < 1) || (i > SLD->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, SLD->size[0], &de_emlrtBCI, sp);
    }

    i = (int32_T)aboveVals->data[0];
    if ((i < 1) || (i > SLD->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, SLD->size[0], &ee_emlrtBCI, sp);
    }

    i = (int32_T)where->data[where->size[0] - 1];
    if ((i < 1) || (i > SLD->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, SLD->size[0], &fe_emlrtBCI, sp);
    }

    i = (int32_T)where->data[where->size[0] - 1];
    if ((i < 1) || (i > SLD->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, SLD->size[0], &ge_emlrtBCI, sp);
    }

    loop_ub = (int32_T)aboveVals->data[0] - 1;
    deltaY_tmp = SLD->data[loop_ub + SLD->size[0]];
    deltaY = (x - SLD->data[(int32_T)where->data[where->size[0] - 1] - 1]) *
      (muDoubleScalarAbs(deltaY_tmp - SLD->data[((int32_T)where->data
         [where->size[0] - 1] + SLD->size[0]) - 1]) / (SLD->data[loop_ub] -
        SLD->data[(int32_T)where->data[where->size[0] - 1] - 1]));
    emxFree_uint32_T(&aboveVals);
    if (covrtLogIf(&emlrtCoverageInstance, 16U, 0U, 1, SLD->data[((int32_T)
          where->data[where->size[0] - 1] + SLD->size[0]) - 1] < deltaY_tmp)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 3U);
      i = sldVal->size[0];
      sldVal->size[0] = 1;
      emxEnsureCapacity_real_T(sp, sldVal, i, &vi_emlrtRTEI);
      sldVal->data[0] = SLD->data[((int32_T)where->data[where->size[0] - 1] +
        SLD->size[0]) - 1] + deltaY;
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 16U, 4U);
      i = sldVal->size[0];
      sldVal->size[0] = 1;
      emxEnsureCapacity_real_T(sp, sldVal, i, &ui_emlrtRTEI);
      sldVal->data[0] = SLD->data[((int32_T)where->data[where->size[0] - 1] +
        SLD->size[0]) - 1] - deltaY;
    }

    /* sldVal = interp1(z,rho,x); */
  }

  emxFree_int32_T(&ii);
  emxFree_boolean_T(&b_x);
  emxFree_uint32_T(&where);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sldFunc.c) */
