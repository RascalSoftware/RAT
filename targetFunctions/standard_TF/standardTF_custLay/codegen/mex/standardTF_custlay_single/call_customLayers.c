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
#include "standardTF_custlay_single.h"
#include "call_customLayers.h"
#include "standardTF_custlay_single_emxutil.h"
#include "standardTF_custlay_single_data.h"
#include "matlabCallFun.h"

/* Variable Definitions */
static emlrtRSInfo i_emlrtRSI = { 3,   /* lineNo */
  "call_customLayers",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/call_customLayers.m"/* pathName */
};

static emlrtRTEInfo e_emlrtRTEI = { 1, /* lineNo */
  28,                                  /* colNo */
  "call_customLayers",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/call_customLayers.m"/* pName */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  10,                                  /* colNo */
  "params",                            /* aName */
  "call_customLayers",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custlay_single/call_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  10,                                  /* colNo */
  "params",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo qb_emlrtRTEI = { 61,/* lineNo */
  17,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtBCInfo dc_emlrtBCI = { 1,  /* iFirst */
  300,                                 /* iLast */
  62,                                  /* lineNo */
  23,                                  /* colNo */
  "outp",                              /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 60,  /* lineNo */
  24,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  20,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  29,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void call_customLayers(const emlrtStack *sp, const emxArray_real_T *params,
  real_T contrast, const emxArray_char_T *file, const emxArray_char_T *callPath,
  real_T bulkIn, real_T bulkOut, emxArray_real_T *output, real_T *sRough)
{
  emxArray_real_T *b_params;
  int32_T i3;
  int32_T loop_ub;
  emxArray_char_T *funName;
  static const char_T cv0[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a',
    'y', 'e', 'r', 's', ']', ' ', '=', ' ' };

  emxArray_char_T *pathCall;
  static const char_T cv1[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b',
    'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't',
    ',', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  static const char_T cv2[4] = { 'c', 'd', ' ', '\'' };

  real_T outp[300];
  static const char_T cv3[2] = { '\'', ';' };

  real_T nLayers;
  uint32_T rowCount;
  int32_T colCount;
  real_T d0;
  int32_T i4;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_params, 2, &e_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 2U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 0U);
  st.site = &i_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 3U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 0U);

  /* Build with....    codegen matlabEngineCaller_customLayers -o matlabEngineCaller_customLayers */
  i3 = params->size[1];
  if (!(1 <= i3)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i3, &cc_emlrtBCI, &st);
  }

  covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 3U);

  /* Need to reserve some meory for the referencenced variables */
  i3 = b_params->size[0] * b_params->size[1];
  b_params->size[0] = 1;
  b_params->size[1] = params->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)b_params, i3, (int32_T)sizeof
                    (real_T), &e_emlrtRTEI);
  loop_ub = params->size[0] * params->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    b_params->data[i3] = params->data[i3];
  }

  emxInit_char_T(&st, &funName, 2, &e_emlrtRTEI, true);
  i3 = funName->size[0] * funName->size[1];
  funName->size[0] = 1;
  funName->size[1] = 51 + file->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)funName, i3, (int32_T)sizeof(char_T),
                    &e_emlrtRTEI);
  for (i3 = 0; i3 < 17; i3++) {
    funName->data[funName->size[0] * i3] = cv0[i3];
  }

  loop_ub = file->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    funName->data[funName->size[0] * (i3 + 17)] = file->data[file->size[0] * i3];
  }

  for (i3 = 0; i3 < 34; i3++) {
    funName->data[funName->size[0] * ((i3 + file->size[1]) + 17)] = cv1[i3];
  }

  emxInit_char_T(&st, &pathCall, 2, &e_emlrtRTEI, true);
  i3 = pathCall->size[0] * pathCall->size[1];
  pathCall->size[0] = 1;
  pathCall->size[1] = 6 + callPath->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)pathCall, i3, (int32_T)sizeof
                    (char_T), &e_emlrtRTEI);
  for (i3 = 0; i3 < 4; i3++) {
    pathCall->data[pathCall->size[0] * i3] = cv2[i3];
  }

  loop_ub = callPath->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    pathCall->data[pathCall->size[0] * (i3 + 4)] = callPath->data[callPath->
      size[0] * i3];
  }

  for (i3 = 0; i3 < 2; i3++) {
    pathCall->data[pathCall->size[0] * ((i3 + callPath->size[1]) + 4)] = cv3[i3];
  }

  matlabCallFun(&b_params->data[0], (real_T)params->size[1], &funName->data[0],
                &pathCall->data[0], bulkIn, bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 1;
  emxFree_char_T(&pathCall);
  emxFree_char_T(&funName);
  emxFree_real_T(&b_params);
  if (covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 2, nLayers >= 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 4U);
    i3 = output->size[0] * output->size[1];
    if (nLayers != (int32_T)muDoubleScalarFloor(nLayers)) {
      emlrtIntegerCheckR2012b(nLayers, &x_emlrtDCI, &st);
    }

    output->size[0] = (int32_T)nLayers;
    output->size[1] = 3;
    emxEnsureCapacity(&st, (emxArray__common *)output, i3, (int32_T)sizeof
                      (real_T), &e_emlrtRTEI);
    if (nLayers != (int32_T)muDoubleScalarFloor(nLayers)) {
      emlrtIntegerCheckR2012b(nLayers, &x_emlrtDCI, &st);
    }

    loop_ub = (int32_T)nLayers * 3;
    for (i3 = 0; i3 < loop_ub; i3++) {
      output->data[i3] = 0.0;
    }

    d0 = nLayers * 3.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, d0, mxDOUBLE_CLASS, (int32_T)d0,
      &qb_emlrtRTEI, &st);
    loop_ub = 0;
    while (loop_ub <= (int32_T)d0 - 1) {
      covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 5U);
      i3 = loop_ub + 1;
      if (!((i3 >= 1) && (i3 <= 300))) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 300, &dc_emlrtBCI, &st);
      }

      /* Make use of Matlab linear indexing. */
      i3 = output->size[0];
      i4 = (int32_T)rowCount;
      if (!((i4 >= 1) && (i4 <= i3))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &ec_emlrtBCI, &st);
      }

      if (!((colCount >= 1) && (colCount <= 3))) {
        emlrtDynamicBoundsCheckR2012b(colCount, 1, 3, &fc_emlrtBCI, &st);
      }

      output->data[(i4 + output->size[0] * (colCount - 1)) - 1] = outp[loop_ub];
      rowCount++;
      if (covrtLogIf(&emlrtCoverageInstance, 3U, 0U, 3, rowCount == nLayers +
                     1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 6U);
        rowCount = 1U;
        colCount++;
      }

      loop_ub++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 3U, 0U, 0, 0);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 7U);
    i3 = output->size[0] * output->size[1];
    output->size[0] = 0;
    output->size[1] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)output, i3, (int32_T)sizeof
                      (real_T), &e_emlrtRTEI);
  }

  i3 = params->size[1];
  if (!(1 <= i3)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i3, &bc_emlrtBCI, sp);
  }

  *sRough = params->data[0];
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (call_customLayers.c) */
