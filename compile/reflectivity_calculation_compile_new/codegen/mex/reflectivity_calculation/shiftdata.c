/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * shiftdata.c
 *
 * Code generation for function 'shiftdata'
 *
 */

/* Include files */
#include "shiftdata.h"
#include "find.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo fg_emlrtRSI = {
    26,          /* lineNo */
    "shiftdata", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pathName */
};

static emlrtRSInfo gg_emlrtRSI = {
    33,          /* lineNo */
    "shiftdata", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pathName */
};

static emlrtBCInfo fh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    19,          /* lineNo */
    28,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo gh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    19,          /* lineNo */
    16,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtECInfo u_emlrtECI = {
    -1,          /* nDims */
    19,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtBCInfo hh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    20,          /* lineNo */
    28,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo ih_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    20,          /* lineNo */
    16,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtECInfo v_emlrtECI = {
    -1,          /* nDims */
    20,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtBCInfo jh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    21,          /* lineNo */
    28,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo kh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    21,          /* lineNo */
    16,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtECInfo w_emlrtECI = {
    -1,          /* nDims */
    21,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtBCInfo lh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    26,          /* lineNo */
    32,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo mh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    33,          /* lineNo */
    31,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo nh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    37,          /* lineNo */
    37,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo oh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    40,          /* lineNo */
    29,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo ph_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    40,          /* lineNo */
    38,          /* colNo */
    "data",      /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo qh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    43,          /* lineNo */
    27,          /* colNo */
    "simLimits", /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtBCInfo rh_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    44,          /* lineNo */
    27,          /* colNo */
    "simLimits", /* aName */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    0              /* checkKind */
};

static emlrtDCInfo lb_emlrtDCI = {
    14,          /* lineNo */
    1,           /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m", /* pName */
    1              /* checkKind */
};

static emlrtRTEInfo xk_emlrtRTEI = {
    19,          /* lineNo */
    21,          /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo yk_emlrtRTEI = {
    47,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo al_emlrtRTEI = {
    20,          /* lineNo */
    21,          /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo bl_emlrtRTEI = {
    21,          /* lineNo */
    21,          /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo cl_emlrtRTEI = {
    26,          /* lineNo */
    25,          /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo dl_emlrtRTEI = {
    26,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo el_emlrtRTEI = {
    33,          /* lineNo */
    24,          /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo fl_emlrtRTEI = {
    33,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

static emlrtRTEInfo gl_emlrtRTEI = {
    40,          /* lineNo */
    9,           /* colNo */
    "shiftdata", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/shiftData/"
    "shiftdata.m" /* pName */
};

/* Function Definitions */
void shiftdata(const emlrtStack *sp, real_T scalefac, real_T horshift,
               real_T dataPresent, emxArray_real_T *data,
               const real_T dataLimits[2], const real_T simLimits_data[],
               const int32_T simLimits_size[2], emxArray_real_T *shifted_data)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_boolean_T *b_data;
  emxArray_int32_T *ii;
  emxArray_real_T *lowIndex;
  real_T b_simXData[300];
  real_T simXData[100];
  real_T d2scaled;
  real_T delta1;
  real_T delta2;
  real_T *data_data;
  real_T *shifted_data_data;
  int32_T b_lowIndex;
  int32_T hiIndex;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T *ii_data;
  boolean_T *b_data_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  data_data = data->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  Shifts the data according to scale factor. If there is no data, makes  */
  /*  x-data over the simulation range. */
  /*  scalefac = problem.scalefactors; */
  /*  horshift = problem.qshifts; */
  /*  numberOfContrasts = problem.numberOfContrasts; */
  /*  dataPresent = problem.dataPresent; */
  /*  allData = problem.data; */
  /*  dataLimits = problem.dataLimits; */
  /* shifted_data = cell(1,numberOfContrasts); */
  if (dataPresent != (int32_T)muDoubleScalarFloor(dataPresent)) {
    emlrtIntegerCheckR2012b(dataPresent, &lb_emlrtDCI, (emlrtCTX)sp);
  }
  if ((int32_T)dataPresent == 1) {
    if (scalefac == 0.0) {
      scalefac = 1.0E-30;
    }
    if (1 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &gh_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (1 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &fh_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    emxInit_real_T(sp, &lowIndex, 1, &dl_emlrtRTEI, true);
    emlrtSubAssignSizeCheckR2012b(&data->size[0], 1, &data->size[0], 1,
                                  &u_emlrtECI, (emlrtCTX)sp);
    b_lowIndex = data->size[0] - 1;
    i = lowIndex->size[0];
    lowIndex->size[0] = data->size[0];
    emxEnsureCapacity_real_T(sp, lowIndex, i, &xk_emlrtRTEI);
    shifted_data_data = lowIndex->data;
    for (i = 0; i <= b_lowIndex; i++) {
      shifted_data_data[i] = data_data[i] + horshift;
    }
    loop_ub = lowIndex->size[0];
    for (i = 0; i < loop_ub; i++) {
      data_data[i] = shifted_data_data[i];
    }
    if (2 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, data->size[1], &ih_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (2 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, data->size[1], &hh_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub = data->size[0];
    i = lowIndex->size[0];
    lowIndex->size[0] = data->size[0];
    emxEnsureCapacity_real_T(sp, lowIndex, i, &al_emlrtRTEI);
    shifted_data_data = lowIndex->data;
    for (i = 0; i < loop_ub; i++) {
      shifted_data_data[i] = data_data[i + data->size[0]] / scalefac;
    }
    emlrtSubAssignSizeCheckR2012b(&data->size[0], 1, &lowIndex->size[0], 1,
                                  &v_emlrtECI, (emlrtCTX)sp);
    loop_ub = lowIndex->size[0];
    for (i = 0; i < loop_ub; i++) {
      data_data[i + data->size[0]] = shifted_data_data[i];
    }
    if (3 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(3, 1, data->size[1], &kh_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (3 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(3, 1, data->size[1], &jh_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub = data->size[0];
    i = lowIndex->size[0];
    lowIndex->size[0] = data->size[0];
    emxEnsureCapacity_real_T(sp, lowIndex, i, &bl_emlrtRTEI);
    shifted_data_data = lowIndex->data;
    for (i = 0; i < loop_ub; i++) {
      shifted_data_data[i] = data_data[i + data->size[0] * 2] / scalefac;
    }
    emlrtSubAssignSizeCheckR2012b(&data->size[0], 1, &lowIndex->size[0], 1,
                                  &w_emlrtECI, (emlrtCTX)sp);
    loop_ub = lowIndex->size[0];
    for (i = 0; i < loop_ub; i++) {
      data_data[i + data->size[0] * 2] = shifted_data_data[i];
    }
    if (1 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &lh_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    emxInit_boolean_T(sp, &b_data, &cl_emlrtRTEI);
    st.site = &fg_emlrtRSI;
    loop_ub = data->size[0];
    i = b_data->size[0];
    b_data->size[0] = data->size[0];
    emxEnsureCapacity_boolean_T(&st, b_data, i, &cl_emlrtRTEI);
    b_data_data = b_data->data;
    for (i = 0; i < loop_ub; i++) {
      b_data_data[i] = (data_data[i] < dataLimits[0]);
    }
    emxInit_int32_T(&st, &ii, &yj_emlrtRTEI);
    b_st.site = &ie_emlrtRSI;
    eml_find(&b_st, b_data, ii);
    ii_data = ii->data;
    i = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, lowIndex, i, &dl_emlrtRTEI);
    shifted_data_data = lowIndex->data;
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      shifted_data_data[i] = ii_data[i];
    }
    if (lowIndex->size[0] != 0) {
      b_lowIndex = (int32_T)shifted_data_data[lowIndex->size[0] - 1];
    } else {
      b_lowIndex = 1;
    }
    if (1 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &mh_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &gg_emlrtRSI;
    loop_ub = data->size[0];
    i = b_data->size[0];
    b_data->size[0] = data->size[0];
    emxEnsureCapacity_boolean_T(&st, b_data, i, &el_emlrtRTEI);
    b_data_data = b_data->data;
    for (i = 0; i < loop_ub; i++) {
      b_data_data[i] = (data_data[i] > dataLimits[1]);
    }
    b_st.site = &ie_emlrtRSI;
    eml_find(&b_st, b_data, ii);
    ii_data = ii->data;
    i = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, lowIndex, i, &fl_emlrtRTEI);
    shifted_data_data = lowIndex->data;
    loop_ub = ii->size[0];
    emxFree_boolean_T(&st, &b_data);
    for (i = 0; i < loop_ub; i++) {
      shifted_data_data[i] = ii_data[i];
    }
    emxFree_int32_T(&st, &ii);
    if (lowIndex->size[0] != 0) {
      hiIndex = (int32_T)shifted_data_data[0];
    } else {
      if (1 > data->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &nh_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      hiIndex = data->size[0];
    }
    emxFree_real_T(sp, &lowIndex);
    if (b_lowIndex > hiIndex) {
      i = 0;
      hiIndex = 0;
    } else {
      if ((b_lowIndex < 1) || (b_lowIndex > data->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_lowIndex, 1, data->size[0],
                                      &oh_emlrtBCI, (emlrtCTX)sp);
      }
      i = b_lowIndex - 1;
      if ((hiIndex < 1) || (hiIndex > data->size[0])) {
        emlrtDynamicBoundsCheckR2012b(hiIndex, 1, data->size[0], &ph_emlrtBCI,
                                      (emlrtCTX)sp);
      }
    }
    loop_ub = data->size[1];
    b_lowIndex = hiIndex - i;
    hiIndex = shifted_data->size[0] * shifted_data->size[1];
    shifted_data->size[0] = b_lowIndex;
    shifted_data->size[1] = data->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data, hiIndex, &gl_emlrtRTEI);
    shifted_data_data = shifted_data->data;
    for (hiIndex = 0; hiIndex < loop_ub; hiIndex++) {
      for (i1 = 0; i1 < b_lowIndex; i1++) {
        shifted_data_data[i1 + shifted_data->size[0] * hiIndex] =
            data_data[(i + i1) + data->size[0] * hiIndex];
      }
    }
  } else {
    i = simLimits_size[0] * simLimits_size[1];
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &qh_emlrtBCI, (emlrtCTX)sp);
    }
    d2scaled = simLimits_data[0];
    if (2 > i) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i, &rh_emlrtBCI, (emlrtCTX)sp);
    }
    simXData[99] = simLimits_data[1];
    simXData[0] = simLimits_data[0];
    if (simLimits_data[0] == -simLimits_data[1]) {
      d2scaled = simLimits_data[1] / 99.0;
      for (b_lowIndex = 0; b_lowIndex < 98; b_lowIndex++) {
        simXData[b_lowIndex + 1] =
            (2.0 * ((real_T)b_lowIndex + 2.0) - 101.0) * d2scaled;
      }
    } else if (((simLimits_data[0] < 0.0) != (simLimits_data[1] < 0.0)) &&
               ((muDoubleScalarAbs(simLimits_data[0]) >
                 8.9884656743115785E+307) ||
                (muDoubleScalarAbs(simLimits_data[1]) >
                 8.9884656743115785E+307))) {
      delta1 = simLimits_data[0] / 99.0;
      delta2 = simLimits_data[1] / 99.0;
      for (b_lowIndex = 0; b_lowIndex < 98; b_lowIndex++) {
        simXData[b_lowIndex + 1] =
            (d2scaled + delta2 * ((real_T)b_lowIndex + 1.0)) -
            delta1 * ((real_T)b_lowIndex + 1.0);
      }
    } else {
      delta1 = (simLimits_data[1] - simLimits_data[0]) / 99.0;
      for (b_lowIndex = 0; b_lowIndex < 98; b_lowIndex++) {
        simXData[b_lowIndex + 1] =
            d2scaled + ((real_T)b_lowIndex + 1.0) * delta1;
      }
    }
    for (i = 0; i < 100; i++) {
      b_simXData[i] = simXData[i];
      b_simXData[i + 100] = 0.0;
      b_simXData[i + 200] = 0.0;
    }
    i = shifted_data->size[0] * shifted_data->size[1];
    shifted_data->size[0] = 100;
    shifted_data->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data, i, &yk_emlrtRTEI);
    shifted_data_data = shifted_data->data;
    for (i = 0; i < 300; i++) {
      shifted_data_data[i] = b_simXData[i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (shiftdata.c) */
