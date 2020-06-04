/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * call_customLayers.c
 *
 * Code generation for function 'call_customLayers'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "call_customLayers.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_data.h"
#include "matlabCallFun.h"
#include "matlabCallFun.c"

/* Variable Definitions */
static emlrtRSInfo qe_emlrtRSI = { 3,  /* lineNo */
  "call_customLayers",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_single/call_customLayers.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 5,  /* lineNo */
  "matlabEngineCaller_customLayers",   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m"             /* pathName */
};

static emlrtRTEInfo od_emlrtRTEI = { 1,/* lineNo */
  28,                                  /* colNo */
  "call_customLayers",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_single/call_customLayers.m"/* pName */
};

static emlrtBCInfo kk_emlrtBCI = { 1,  /* iFirst */
  300,                                 /* iLast */
  63,                                  /* lineNo */
  23,                                  /* colNo */
  "outp",                              /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m",            /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo rf_emlrtRTEI = { 62,/* lineNo */
  17,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m"             /* pName */
};

static emlrtBCInfo lk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  10,                                  /* colNo */
  "params",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m",            /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  10,                                  /* colNo */
  "params",                            /* aName */
  "call_customLayers",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_single/call_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ke_emlrtDCI = { 61, /* lineNo */
  24,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m",            /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo nk_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  20,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m",            /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ok_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  29,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m",            /* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void call_customLayers(const emlrtStack *sp, const emxArray_real_T *b_params,
  real_T contrast, const emxArray_char_T *file, const emxArray_char_T *callPath,
  real_T bulkIn, real_T bulkOut, emxArray_real_T *output, real_T *sRough)
{
  int32_T result;
  emxArray_real_T *c_params;
  int32_T i40;
  int32_T loop_ub;
  emxArray_char_T *funName;
  static const char_T varargin_1[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l',
    'a', 'y', 'e', 'r', 's', ']', ' ', '=', ' ' };

  emxArray_char_T *pathCall;
  static const char_T varargin_3[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',',
    'b', 'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u',
    't', ',', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  static const char_T cv15[4] = { 'c', 'd', ' ', '\'' };

  real_T outp[300];
  static const char_T cv16[2] = { '\'', ';' };

  real_T nLayers;
  uint32_T rowCount;
  int32_T colCount;
  real_T d7;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 23U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 23U, 0U);
  st.site = &qe_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 24U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 0U);
  b_st.site = &re_emlrtRSI;
  c_st.site = &sc_emlrtRSI;
  if (!((file->size[0] == 0) || (file->size[1] == 0))) {
    result = file->size[1];
  } else {
    result = 0;
  }

  emxInit_real_T(&c_st, &c_params, 2, &od_emlrtRTEI, true);
  i40 = b_params->size[1];
  if (!(1 <= i40)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i40, &lk_emlrtBCI, &st);
  }

  covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 3U);

  /* Need to reserve some meory for the referencenced variables */
  i40 = c_params->size[0] * c_params->size[1];
  c_params->size[0] = 1;
  c_params->size[1] = b_params->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)c_params, i40, (int32_T)sizeof
                    (real_T), &od_emlrtRTEI);
  loop_ub = b_params->size[0] * b_params->size[1];
  for (i40 = 0; i40 < loop_ub; i40++) {
    c_params->data[i40] = b_params->data[i40];
  }

  emxInit_char_T(&st, &funName, 2, &od_emlrtRTEI, true);
  i40 = funName->size[0] * funName->size[1];
  funName->size[0] = 1;
  funName->size[1] = 51 + result;
  emxEnsureCapacity(&st, (emxArray__common *)funName, i40, (int32_T)sizeof
                    (char_T), &od_emlrtRTEI);
  for (i40 = 0; i40 < 17; i40++) {
    funName->data[funName->size[0] * i40] = varargin_1[i40];
  }

  for (i40 = 0; i40 < result; i40++) {
    funName->data[funName->size[0] * (i40 + 17)] = file->data[i40];
  }

  for (i40 = 0; i40 < 34; i40++) {
    funName->data[funName->size[0] * ((i40 + result) + 17)] = varargin_3[i40];
  }

  emxInit_char_T(&st, &pathCall, 2, &od_emlrtRTEI, true);
  i40 = pathCall->size[0] * pathCall->size[1];
  pathCall->size[0] = 1;
  pathCall->size[1] = 6 + callPath->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)pathCall, i40, (int32_T)sizeof
                    (char_T), &od_emlrtRTEI);
  for (i40 = 0; i40 < 4; i40++) {
    pathCall->data[pathCall->size[0] * i40] = cv15[i40];
  }

  loop_ub = callPath->size[1];
  for (i40 = 0; i40 < loop_ub; i40++) {
    pathCall->data[pathCall->size[0] * (i40 + 4)] = callPath->data
      [callPath->size[0] * i40];
  }

  for (i40 = 0; i40 < 2; i40++) {
    pathCall->data[pathCall->size[0] * ((i40 + callPath->size[1]) + 4)] =
      cv16[i40];
  }

  matlabCallFun(&c_params->data[0], (real_T)b_params->size[1], &funName->data[0],
                &pathCall->data[0], bulkIn, bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 1;

  /* reshape the output to [layers * 3] array */
  emxFree_char_T(&pathCall);
  emxFree_char_T(&funName);
  emxFree_real_T(&c_params);
  if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 2, nLayers >= 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 4U);
    i40 = output->size[0] * output->size[1];
    if (nLayers != (int32_T)muDoubleScalarFloor(nLayers)) {
      emlrtIntegerCheckR2012b(nLayers, &ke_emlrtDCI, &st);
    }

    output->size[0] = (int32_T)nLayers;
    output->size[1] = 3;
    emxEnsureCapacity(&st, (emxArray__common *)output, i40, (int32_T)sizeof
                      (real_T), &od_emlrtRTEI);
    if (nLayers != (int32_T)muDoubleScalarFloor(nLayers)) {
      emlrtIntegerCheckR2012b(nLayers, &ke_emlrtDCI, &st);
    }

    loop_ub = (int32_T)nLayers * 3;
    for (i40 = 0; i40 < loop_ub; i40++) {
      output->data[i40] = 0.0;
    }

    d7 = nLayers * 3.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, d7, mxDOUBLE_CLASS, (int32_T)d7,
      &rf_emlrtRTEI, &st);
    for (result = 0; result < (int32_T)d7; result++) {
      covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 5U);
      i40 = result + 1;
      if (!((i40 >= 1) && (i40 <= 300))) {
        emlrtDynamicBoundsCheckR2012b(i40, 1, 300, &kk_emlrtBCI, &st);
      }

      /* Make use of Matlab linear indexing. */
      i40 = output->size[0];
      loop_ub = (int32_T)rowCount;
      if (!((loop_ub >= 1) && (loop_ub <= i40))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i40, &nk_emlrtBCI, &st);
      }

      if (!((colCount >= 1) && (colCount <= 3))) {
        emlrtDynamicBoundsCheckR2012b(colCount, 1, 3, &ok_emlrtBCI, &st);
      }

      output->data[(loop_ub + output->size[0] * (colCount - 1)) - 1] =
        outp[result];
      rowCount++;
      if (covrtLogIf(&emlrtCoverageInstance, 24U, 0U, 3, rowCount == nLayers +
                     1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 6U);
        rowCount = 1U;
        colCount++;
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 24U, 0U, 0, 0);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 24U, 7U);
    i40 = output->size[0] * output->size[1];
    output->size[0] = 0;
    output->size[1] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)output, i40, (int32_T)sizeof
                      (real_T), &od_emlrtRTEI);
  }

  i40 = b_params->size[1];
  if (!(1 <= i40)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i40, &mk_emlrtBCI, sp);
  }

  *sRough = b_params->data[0];
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (call_customLayers.c) */
