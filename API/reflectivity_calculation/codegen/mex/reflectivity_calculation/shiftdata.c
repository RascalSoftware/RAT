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
#include "shiftdata.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo cf_emlrtRSI = { 24, /* lineNo */
  "shiftdata",                         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 31, /* lineNo */
  "shiftdata",                         /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pathName */
};

static emlrtBCInfo mu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  24,                                  /* colNo */
  "lowIndex",                          /* aName */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo sc_emlrtDCI = { 12, /* lineNo */
  8,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo ib_emlrtECI = { -1, /* nDims */
  17,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtECInfo jb_emlrtECI = { -1, /* nDims */
  18,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtECInfo kb_emlrtECI = { -1, /* nDims */
  19,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtBCInfo nu_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  29,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ou_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  38,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo gr_emlrtRTEI = { 17,/* lineNo */
  21,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo hr_emlrtRTEI = { 18,/* lineNo */
  21,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo ir_emlrtRTEI = { 19,/* lineNo */
  21,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo jr_emlrtRTEI = { 24,/* lineNo */
  25,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo kr_emlrtRTEI = { 24,/* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo lr_emlrtRTEI = { 31,/* lineNo */
  24,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo mr_emlrtRTEI = { 31,/* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo nr_emlrtRTEI = { 38,/* lineNo */
  24,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

/* Function Definitions */
void shiftdata(const emlrtStack *sp, real_T scalefac, real_T horshift, real_T
               dataPresent, emxArray_real_T *data, const real_T dataLimits[2])
{
  emxArray_real_T *lowIndex;
  int32_T hiIndex;
  int32_T i;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T nx;
  int32_T idx;
  boolean_T exitg1;
  int32_T iv[2];
  int32_T b_lowIndex;
  emxArray_real_T *b_data;
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

  /* Shifts the data according to scale factor */
  /*  scalefac = problem.scalefactors; */
  /*  horshift = problem.qshifts; */
  /*  numberOfContrasts = problem.numberOfContrasts; */
  /*  dataPresent = problem.dataPresent; */
  /*  allData = problem.data; */
  /*  dataLimits = problem.dataLimits; */
  /* shifted_data = cell(1,numberOfContrasts); */
  if (dataPresent != (int32_T)muDoubleScalarFloor(dataPresent)) {
    emlrtIntegerCheckR2012b(dataPresent, &sc_emlrtDCI, sp);
  }

  switch ((int32_T)dataPresent) {
   case 1:
    if (scalefac == 0.0) {
      scalefac = 1.0E-30;
    }

    emxInit_real_T(sp, &lowIndex, 1, &kr_emlrtRTEI, true);
    emlrtSubAssignSizeCheckR2012b(&data->size[0], 1, &data->size[0], 1,
      &ib_emlrtECI, sp);
    hiIndex = data->size[0] - 1;
    i = lowIndex->size[0];
    lowIndex->size[0] = hiIndex + 1;
    emxEnsureCapacity_real_T(sp, lowIndex, i, &gr_emlrtRTEI);
    for (i = 0; i <= hiIndex; i++) {
      lowIndex->data[i] = data->data[i] + horshift;
    }

    hiIndex = lowIndex->size[0];
    for (i = 0; i < hiIndex; i++) {
      data->data[i] = lowIndex->data[i];
    }

    hiIndex = data->size[0];
    i = lowIndex->size[0];
    lowIndex->size[0] = hiIndex;
    emxEnsureCapacity_real_T(sp, lowIndex, i, &hr_emlrtRTEI);
    for (i = 0; i < hiIndex; i++) {
      lowIndex->data[i] = data->data[i + data->size[0]] / scalefac;
    }

    emlrtSubAssignSizeCheckR2012b(&data->size[0], 1, &lowIndex->size[0], 1,
      &jb_emlrtECI, sp);
    hiIndex = lowIndex->size[0];
    for (i = 0; i < hiIndex; i++) {
      data->data[i + data->size[0]] = lowIndex->data[i];
    }

    hiIndex = data->size[0];
    i = lowIndex->size[0];
    lowIndex->size[0] = hiIndex;
    emxEnsureCapacity_real_T(sp, lowIndex, i, &ir_emlrtRTEI);
    for (i = 0; i < hiIndex; i++) {
      lowIndex->data[i] = data->data[i + data->size[0] * 2] / scalefac;
    }

    emlrtSubAssignSizeCheckR2012b(&data->size[0], 1, &lowIndex->size[0], 1,
      &kb_emlrtECI, sp);
    hiIndex = lowIndex->size[0];
    for (i = 0; i < hiIndex; i++) {
      data->data[i + data->size[0] * 2] = lowIndex->data[i];
    }

    emxInit_boolean_T(sp, &x, 1, &jr_emlrtRTEI, true);
    st.site = &cf_emlrtRSI;
    hiIndex = data->size[0];
    i = x->size[0];
    x->size[0] = hiIndex;
    emxEnsureCapacity_boolean_T(&st, x, i, &jr_emlrtRTEI);
    for (i = 0; i < hiIndex; i++) {
      x->data[i] = (data->data[i] < dataLimits[0]);
    }

    emxInit_int32_T(&st, &ii, 1, &vj_emlrtRTEI, true);
    b_st.site = &fd_emlrtRSI;
    nx = x->size[0];
    c_st.site = &gd_emlrtRSI;
    idx = 0;
    i = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(&c_st, ii, i, &lj_emlrtRTEI);
    d_st.site = &hd_emlrtRSI;
    if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
      e_st.site = &nb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    hiIndex = 0;
    exitg1 = false;
    while ((!exitg1) && (hiIndex <= nx - 1)) {
      if (x->data[hiIndex]) {
        idx++;
        ii->data[idx - 1] = hiIndex + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          hiIndex++;
        }
      } else {
        hiIndex++;
      }
    }

    if (idx > x->size[0]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &ob_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else {
      if (1 > idx) {
        i = 0;
      } else {
        i = idx;
      }

      iv[0] = 1;
      iv[1] = i;
      d_st.site = &id_emlrtRSI;
      indexShapeCheck(&d_st, ii->size[0], iv);
      idx = ii->size[0];
      ii->size[0] = i;
      emxEnsureCapacity_int32_T(&c_st, ii, idx, &mj_emlrtRTEI);
    }

    i = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, lowIndex, i, &kr_emlrtRTEI);
    hiIndex = ii->size[0];
    for (i = 0; i < hiIndex; i++) {
      lowIndex->data[i] = ii->data[i];
    }

    if (lowIndex->size[0] != 0) {
      if (lowIndex->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(lowIndex->size[0], 1, lowIndex->size[0],
          &mu_emlrtBCI, sp);
      }

      b_lowIndex = (int32_T)lowIndex->data[lowIndex->size[0] - 1];
    } else {
      b_lowIndex = 1;
    }

    st.site = &df_emlrtRSI;
    hiIndex = data->size[0];
    i = x->size[0];
    x->size[0] = hiIndex;
    emxEnsureCapacity_boolean_T(&st, x, i, &lr_emlrtRTEI);
    for (i = 0; i < hiIndex; i++) {
      x->data[i] = (data->data[i] > dataLimits[1]);
    }

    b_st.site = &fd_emlrtRSI;
    nx = x->size[0];
    c_st.site = &gd_emlrtRSI;
    idx = 0;
    i = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(&c_st, ii, i, &lj_emlrtRTEI);
    d_st.site = &hd_emlrtRSI;
    if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
      e_st.site = &nb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    hiIndex = 0;
    exitg1 = false;
    while ((!exitg1) && (hiIndex <= nx - 1)) {
      if (x->data[hiIndex]) {
        idx++;
        ii->data[idx - 1] = hiIndex + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          hiIndex++;
        }
      } else {
        hiIndex++;
      }
    }

    if (idx > x->size[0]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &ob_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (x->size[0] == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else {
      if (1 > idx) {
        i = 0;
      } else {
        i = idx;
      }

      iv[0] = 1;
      iv[1] = i;
      d_st.site = &id_emlrtRSI;
      indexShapeCheck(&d_st, ii->size[0], iv);
      idx = ii->size[0];
      ii->size[0] = i;
      emxEnsureCapacity_int32_T(&c_st, ii, idx, &mj_emlrtRTEI);
    }

    emxFree_boolean_T(&x);
    i = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, lowIndex, i, &mr_emlrtRTEI);
    hiIndex = ii->size[0];
    for (i = 0; i < hiIndex; i++) {
      lowIndex->data[i] = ii->data[i];
    }

    emxFree_int32_T(&ii);
    if (lowIndex->size[0] != 0) {
      hiIndex = (int32_T)lowIndex->data[0];
    } else {
      hiIndex = data->size[0];
    }

    emxFree_real_T(&lowIndex);
    if (b_lowIndex > hiIndex) {
      i = 0;
      hiIndex = 0;
    } else {
      i = data->size[0];
      if ((b_lowIndex < 1) || (b_lowIndex > i)) {
        emlrtDynamicBoundsCheckR2012b(b_lowIndex, 1, i, &nu_emlrtBCI, sp);
      }

      i = b_lowIndex - 1;
      idx = data->size[0];
      if ((hiIndex < 1) || (hiIndex > idx)) {
        emlrtDynamicBoundsCheckR2012b(hiIndex, 1, idx, &ou_emlrtBCI, sp);
      }
    }

    emxInit_real_T(sp, &b_data, 2, &nr_emlrtRTEI, true);
    hiIndex -= i;
    idx = b_data->size[0] * b_data->size[1];
    b_data->size[0] = hiIndex;
    b_data->size[1] = 3;
    emxEnsureCapacity_real_T(sp, b_data, idx, &nr_emlrtRTEI);
    for (idx = 0; idx < 3; idx++) {
      for (nx = 0; nx < hiIndex; nx++) {
        b_data->data[nx + b_data->size[0] * idx] = data->data[(i + nx) +
          data->size[0] * idx];
      }
    }

    i = data->size[0] * data->size[1];
    data->size[0] = b_data->size[0];
    data->size[1] = 3;
    emxEnsureCapacity_real_T(sp, data, i, &nr_emlrtRTEI);
    hiIndex = b_data->size[0];
    for (i = 0; i < 3; i++) {
      for (idx = 0; idx < hiIndex; idx++) {
        data->data[idx + data->size[0] * i] = b_data->data[idx + b_data->size[0]
          * i];
      }
    }

    emxFree_real_T(&b_data);
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
