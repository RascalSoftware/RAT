/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customLayers.c
 *
 * Code generation for function 'matlabEngineCaller_customLayers'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "matlabEngineCaller_customLayers.h"
#include "matlabEngineCaller_customLayers_emxutil.h"
#include "matlabEngineCaller_customLayers_data.h"
#include "matlabCallFun.h"
#include "matlabCallFun.c"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 5,   /* lineNo */
  1,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m"             /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 8, /* lineNo */
  1,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m"             /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 62,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m"             /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 63,/* lineNo */
  17,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m"             /* pName */
};

static emlrtDCInfo emlrtDCI = { 62,    /* lineNo */
  24,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m",            /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 62,  /* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m",            /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  300,                                 /* iLast */
  64,                                  /* lineNo */
  23,                                  /* colNo */
  "outp",                              /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m",            /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  65,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m",            /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  65,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_single/matlabEngin"
  "eCaller_customLayers.m",            /* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void matlabEngineCaller_customLayers(const emlrtStack *sp, const real_T params[8],
  real_T contrast, const emxArray_char_T *funcName, const emxArray_char_T
  *funcPath, real_T bulkIn, real_T bulkOut, emxArray_real_T *output, real_T
  sRough_data[], int32_T sRough_size[2])
{
  emxArray_char_T *funName;
  int32_T i0;
  int32_T loop_ub;
  static const char_T cv0[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a',
    'y', 'e', 'r', 's', ']', ' ', '=', ' ' };

  emxArray_char_T *pathCall;
  static const char_T cv1[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b',
    'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't',
    ',', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  real_T b_params[8];
  real_T outp[300];
  real_T nLayers;
  uint32_T rowCount;
  int32_T colCount;
  real_T d0;
  int32_T i;
  int32_T i1;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_char_T(sp, &funName, 2, &emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  i0 = funName->size[0] * funName->size[1];
  funName->size[0] = 1;
  funName->size[1] = 51 + funcName->size[1];
  emxEnsureCapacity_char_T(sp, funName, i0, &emlrtRTEI);
  for (i0 = 0; i0 < 17; i0++) {
    funName->data[i0] = cv0[i0];
  }

  loop_ub = funcName->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    funName->data[i0 + 17] = funcName->data[i0];
  }

  for (i0 = 0; i0 < 34; i0++) {
    funName->data[(i0 + funcName->size[1]) + 17] = cv1[i0];
  }

  emxInit_char_T(sp, &pathCall, 2, &b_emlrtRTEI, true);
  sRough_size[0] = 1;
  sRough_size[1] = 1;
  sRough_data[0] = params[0];
  i0 = pathCall->size[0] * pathCall->size[1];
  pathCall->size[0] = 1;
  pathCall->size[1] = 6 + funcPath->size[1];
  emxEnsureCapacity_char_T(sp, pathCall, i0, &b_emlrtRTEI);
  pathCall->data[0] = 'c';
  pathCall->data[1] = 'd';
  pathCall->data[2] = ' ';
  pathCall->data[3] = '\'';
  loop_ub = funcPath->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    pathCall->data[i0 + 4] = funcPath->data[i0];
  }

  pathCall->data[funcPath->size[1] + 4] = '\'';
  pathCall->data[funcPath->size[1] + 5] = ';';
  covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);

  /* Need to reserve some meory for the referencenced variables */
  memcpy(&b_params[0], &params[0], sizeof(real_T) << 3);
  matlabCallFun(b_params, 8.0, &funName->data[0], &pathCall->data[0], bulkIn,
                bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 1;

  /* reshape the output to [layers * 3] array */
  emxFree_char_T(&pathCall);
  emxFree_char_T(&funName);
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 2, nLayers >= 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);
    i0 = output->size[0] * output->size[1];
    d0 = (int32_T)muDoubleScalarFloor(nLayers);
    if (nLayers != d0) {
      emlrtIntegerCheckR2012b(nLayers, &emlrtDCI, sp);
    }

    loop_ub = (int32_T)nLayers;
    output->size[0] = loop_ub;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, i0, &c_emlrtRTEI);
    if (nLayers != d0) {
      emlrtIntegerCheckR2012b(nLayers, &b_emlrtDCI, sp);
    }

    loop_ub *= 3;
    for (i0 = 0; i0 < loop_ub; i0++) {
      output->data[i0] = 0.0;
    }

    d0 = nLayers * 3.0;
    i0 = (int32_T)d0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, d0, mxDOUBLE_CLASS, (int32_T)d0,
      &e_emlrtRTEI, sp);
    for (i = 0; i < i0; i++) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);
      loop_ub = (int32_T)(1U + i);
      if ((loop_ub < 1) || (loop_ub > 300)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 300, &emlrtBCI, sp);
      }

      i1 = output->size[0];
      if (((int32_T)rowCount < 1) || ((int32_T)rowCount > i1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)rowCount, 1, i1, &b_emlrtBCI, sp);
      }

      if (colCount > 3) {
        emlrtDynamicBoundsCheckR2012b(4, 1, 3, &c_emlrtBCI, sp);
      }

      output->data[((int32_T)rowCount + output->size[0] * (colCount - 1)) - 1] =
        outp[loop_ub - 1];

      /* Make use of Matlab linear indexing. */
      rowCount++;
      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 3, rowCount == nLayers +
                     1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
        rowCount = 1U;
        colCount++;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 7U);
    output->size[0] = 0;
    output->size[1] = 3;
    sRough_size[0] = 0;
    sRough_size[1] = 0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (matlabEngineCaller_customLayers.c) */
