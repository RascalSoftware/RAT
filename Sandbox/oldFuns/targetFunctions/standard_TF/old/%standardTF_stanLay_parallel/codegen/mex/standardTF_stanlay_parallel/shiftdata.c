/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * shiftdata.c
 *
 * Code generation for function 'shiftdata'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_parallel.h"
#include "shiftdata.h"
#include "rdivide.h"
#include "standardTF_stanlay_parallel_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "standardTF_stanlay_parallel_data.h"

/* Variable Definitions */
static emlrtRSInfo xc_emlrtRSI = { 24, /* lineNo */
  "shiftdata",                         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 31, /* lineNo */
  "shiftdata",                         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pathName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 1,/* lineNo */
  25,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtBCInfo qe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  29,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  19,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  18,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  17,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtDCInfo gb_emlrtDCI = { 12, /* lineNo */
  8,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  24,                                  /* colNo */
  "lowIndex",                          /* aName */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void shiftdata(const emlrtStack *sp, real_T scalefac, real_T horshift, real_T
               dataPresent, emxArray_real_T *data, const real_T dataLimits[2],
               emxArray_real_T *shifted_data)
{
  int32_T i15;
  emxArray_int32_T *ii;
  int32_T nx;
  emxArray_real_T *b_data;
  int32_T b_ii[1];
  emxArray_real_T *c_data;
  int32_T d_data[1];
  int32_T e_data;
  emxArray_real_T *f_data;
  emxArray_real_T *lowIndex;
  int32_T c_ii[1];
  emxArray_real_T *g_data;
  int32_T d_ii[1];
  emxArray_boolean_T *x;
  int32_T idx;
  boolean_T overflow;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int32_T iv9[2];
  int32_T b_lowIndex;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv10[2];
  int32_T hiIndex;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* Shifts the data according to scale factor */
  /*  scalefac = problem.scalefactors; */
  /*  horshift = problem.qshifts; */
  /*  numberOfContrasts = problem.numberOfContrasts; */
  /*  dataPresent = problem.dataPresent; */
  /*  allData = problem.data; */
  /*  dataLimits = problem.dataLimits; */
  /* shifted_data = cell(1,numberOfContrasts); */
  if (dataPresent != (int32_T)muDoubleScalarFloor(dataPresent)) {
    emlrtIntegerCheckR2012b(dataPresent, &gb_emlrtDCI, sp);
  }

  switch ((int32_T)dataPresent) {
   case 1:
    if (scalefac == 0.0) {
      scalefac = 1.0E-30;
    }

    emxInit_int32_T(sp, &ii, 1, &bb_emlrtRTEI, true);
    nx = data->size[0];
    i15 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                      &jb_emlrtRTEI);
    for (i15 = 0; i15 < nx; i15++) {
      ii->data[i15] = i15;
    }

    emxInit_real_T1(sp, &b_data, 1, &jb_emlrtRTEI, true);
    b_ii[0] = ii->size[0];
    nx = data->size[0];
    i15 = b_data->size[0];
    b_data->size[0] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)b_data, i15, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    for (i15 = 0; i15 < nx; i15++) {
      b_data->data[i15] = data->data[i15];
    }

    emxInit_real_T1(sp, &c_data, 1, &jb_emlrtRTEI, true);
    d_data[0] = b_data->size[0];
    emlrtSubAssignSizeCheckR2012b(b_ii, 1, d_data, 1, &h_emlrtECI, sp);
    e_data = data->size[0];
    i15 = c_data->size[0];
    c_data->size[0] = e_data;
    emxEnsureCapacity(sp, (emxArray__common *)c_data, i15, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    emxFree_real_T(&b_data);
    for (i15 = 0; i15 < e_data; i15++) {
      c_data->data[i15] = data->data[i15] + horshift;
    }

    nx = c_data->size[0];
    for (i15 = 0; i15 < nx; i15++) {
      data->data[ii->data[i15]] = c_data->data[i15];
    }

    emxFree_real_T(&c_data);
    nx = data->size[0];
    i15 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                      &jb_emlrtRTEI);
    for (i15 = 0; i15 < nx; i15++) {
      ii->data[i15] = i15;
    }

    emxInit_real_T1(sp, &f_data, 1, &jb_emlrtRTEI, true);
    nx = data->size[0];
    i15 = f_data->size[0];
    f_data->size[0] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)f_data, i15, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    for (i15 = 0; i15 < nx; i15++) {
      f_data->data[i15] = data->data[i15 + data->size[0]];
    }

    emxInit_real_T1(sp, &lowIndex, 1, &kb_emlrtRTEI, true);
    rdivide(sp, f_data, scalefac, lowIndex);
    c_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(c_ii, 1, *(int32_T (*)[1])lowIndex->size, 1,
      &g_emlrtECI, sp);
    nx = lowIndex->size[0];
    emxFree_real_T(&f_data);
    for (i15 = 0; i15 < nx; i15++) {
      data->data[ii->data[i15] + data->size[0]] = lowIndex->data[i15];
    }

    nx = data->size[0];
    i15 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                      &jb_emlrtRTEI);
    for (i15 = 0; i15 < nx; i15++) {
      ii->data[i15] = i15;
    }

    emxInit_real_T1(sp, &g_data, 1, &jb_emlrtRTEI, true);
    nx = data->size[0];
    i15 = g_data->size[0];
    g_data->size[0] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)g_data, i15, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    for (i15 = 0; i15 < nx; i15++) {
      g_data->data[i15] = data->data[i15 + (data->size[0] << 1)];
    }

    rdivide(sp, g_data, scalefac, lowIndex);
    d_ii[0] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(d_ii, 1, *(int32_T (*)[1])lowIndex->size, 1,
      &f_emlrtECI, sp);
    nx = lowIndex->size[0];
    emxFree_real_T(&g_data);
    for (i15 = 0; i15 < nx; i15++) {
      data->data[ii->data[i15] + (data->size[0] << 1)] = lowIndex->data[i15];
    }

    emxInit_boolean_T(sp, &x, 1, &jb_emlrtRTEI, true);
    st.site = &xc_emlrtRSI;
    nx = data->size[0];
    i15 = x->size[0];
    x->size[0] = nx;
    emxEnsureCapacity(&st, (emxArray__common *)x, i15, (int32_T)sizeof(boolean_T),
                      &jb_emlrtRTEI);
    for (i15 = 0; i15 < nx; i15++) {
      x->data[i15] = (data->data[i15] < dataLimits[0]);
    }

    b_st.site = &pc_emlrtRSI;
    nx = x->size[0];
    idx = 0;
    i15 = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i15, (int32_T)sizeof
                      (int32_T), &jb_emlrtRTEI);
    c_st.site = &qc_emlrtRSI;
    overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
    if (overflow) {
      d_st.site = &eb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    e_data = 1;
    exitg2 = false;
    while ((!exitg2) && (e_data <= nx)) {
      guard2 = false;
      if (x->data[e_data - 1]) {
        idx++;
        ii->data[idx - 1] = e_data;
        if (idx >= nx) {
          exitg2 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        e_data++;
      }
    }

    if (!(idx <= x->size[0])) {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (x->size[0] == 1) {
      if (idx == 0) {
        i15 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)ii, i15, (int32_T)sizeof
                          (int32_T), &jb_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        i15 = 0;
      } else {
        i15 = idx;
      }

      iv9[0] = 1;
      iv9[1] = i15;
      c_st.site = &rc_emlrtRSI;
      indexShapeCheck(&c_st, ii->size[0], iv9);
      idx = ii->size[0];
      ii->size[0] = i15;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                        (int32_T), &v_emlrtRTEI);
    }

    i15 = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)lowIndex, i15, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    nx = ii->size[0];
    for (i15 = 0; i15 < nx; i15++) {
      lowIndex->data[i15] = ii->data[i15];
    }

    if (!(lowIndex->size[0] == 0)) {
      i15 = lowIndex->size[0];
      idx = lowIndex->size[0];
      if (!((idx >= 1) && (idx <= i15))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i15, &re_emlrtBCI, sp);
      }

      b_lowIndex = (int32_T)lowIndex->data[idx - 1];
    } else {
      b_lowIndex = 1;
    }

    st.site = &yc_emlrtRSI;
    nx = data->size[0];
    i15 = x->size[0];
    x->size[0] = nx;
    emxEnsureCapacity(&st, (emxArray__common *)x, i15, (int32_T)sizeof(boolean_T),
                      &jb_emlrtRTEI);
    for (i15 = 0; i15 < nx; i15++) {
      x->data[i15] = (data->data[i15] > dataLimits[1]);
    }

    b_st.site = &pc_emlrtRSI;
    nx = x->size[0];
    idx = 0;
    i15 = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, i15, (int32_T)sizeof
                      (int32_T), &jb_emlrtRTEI);
    c_st.site = &qc_emlrtRSI;
    overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
    if (overflow) {
      d_st.site = &eb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    e_data = 1;
    exitg1 = false;
    while ((!exitg1) && (e_data <= nx)) {
      guard1 = false;
      if (x->data[e_data - 1]) {
        idx++;
        ii->data[idx - 1] = e_data;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        e_data++;
      }
    }

    if (!(idx <= x->size[0])) {
      emlrtErrorWithMessageIdR2012b(&b_st, &lc_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (x->size[0] == 1) {
      if (idx == 0) {
        i15 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)ii, i15, (int32_T)sizeof
                          (int32_T), &jb_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        i15 = 0;
      } else {
        i15 = idx;
      }

      iv10[0] = 1;
      iv10[1] = i15;
      c_st.site = &rc_emlrtRSI;
      indexShapeCheck(&c_st, ii->size[0], iv10);
      idx = ii->size[0];
      ii->size[0] = i15;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                        (int32_T), &v_emlrtRTEI);
    }

    emxFree_boolean_T(&x);
    i15 = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)lowIndex, i15, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    nx = ii->size[0];
    for (i15 = 0; i15 < nx; i15++) {
      lowIndex->data[i15] = ii->data[i15];
    }

    emxFree_int32_T(&ii);
    if (!(lowIndex->size[0] == 0)) {
      hiIndex = (int32_T)lowIndex->data[0];
    } else {
      hiIndex = data->size[0];
    }

    emxFree_real_T(&lowIndex);
    if (b_lowIndex > hiIndex) {
      i15 = 0;
      hiIndex = 0;
    } else {
      i15 = data->size[0];
      if (!((b_lowIndex >= 1) && (b_lowIndex <= i15))) {
        emlrtDynamicBoundsCheckR2012b(b_lowIndex, 1, i15, &qe_emlrtBCI, sp);
      }

      i15 = b_lowIndex - 1;
      idx = data->size[0];
      if (!((hiIndex >= 1) && (hiIndex <= idx))) {
        emlrtDynamicBoundsCheckR2012b(hiIndex, 1, idx, &qe_emlrtBCI, sp);
      }
    }

    idx = shifted_data->size[0] * shifted_data->size[1];
    shifted_data->size[0] = hiIndex - i15;
    shifted_data->size[1] = 3;
    emxEnsureCapacity(sp, (emxArray__common *)shifted_data, idx, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    for (idx = 0; idx < 3; idx++) {
      nx = hiIndex - i15;
      for (e_data = 0; e_data < nx; e_data++) {
        shifted_data->data[e_data + shifted_data->size[0] * idx] = data->data
          [(i15 + e_data) + data->size[0] * idx];
      }
    }
    break;

   default:
    i15 = shifted_data->size[0] * shifted_data->size[1];
    shifted_data->size[0] = data->size[0];
    shifted_data->size[1] = 3;
    emxEnsureCapacity(sp, (emxArray__common *)shifted_data, i15, (int32_T)sizeof
                      (real_T), &jb_emlrtRTEI);
    nx = data->size[0] * data->size[1];
    for (i15 = 0; i15 < nx; i15++) {
      shifted_data->data[i15] = data->data[i15];
    }
    break;
  }

  /*  function Ref = makeFresnelData(problem,contrast) */
  /*   */
  /*      this_data = problem.shifted_data{contrast}; */
  /*      xdata = this_data(:,1); */
  /*      nbair = problem.nbairs(contrast); */
  /*      nbsub = problem.nbsubs(contrast); */
  /*      slds = [0 0 0]; */
  /*      resol = problem.resolution; */
  /*      resolType = problem.resolType; */
  /*      %abeles(xdata,SLDs,nbair,nbsub,ssub,nrepeats,sinter,resol) */
  /*      %Ref = abeles_new_2(xdata,slds,nbair,nbsub,s_sub,repeats, */
  /*      Ref = abeles_new_2(xdata,slds,nbair,nbsub,0,1,resolType,resol); */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (shiftdata.c) */
