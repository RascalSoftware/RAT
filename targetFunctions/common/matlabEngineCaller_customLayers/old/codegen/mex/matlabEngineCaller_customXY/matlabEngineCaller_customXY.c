/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customXY.c
 *
 * Code generation for function 'matlabEngineCaller_customXY'
 *
 */

/* Include files */
#include "matlabEngineCaller_customXY.h"
#include "matlabEngineCaller_customXY_data.h"
#include "matlabEngineCaller_customXY_emxutil.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  17,                                  /* colNo */
  "params",                            /* aName */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 75,  /* lineNo */
  17,                                  /* colNo */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 74,    /* lineNo */
  24,                                  /* colNo */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 74,  /* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  200,                                 /* iLast */
  76,                                  /* lineNo */
  23,                                  /* colNo */
  "outp",                              /* aName */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  2,                                   /* iLast */
  77,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m",/* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 64,/* lineNo */
  34,                                  /* colNo */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 85,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 74,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 1, /* lineNo */
  28,                                  /* colNo */
  "matlabEngineCaller_customXY",       /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/tmwExampleNew/matlabEngineCaller_customXY.m"/* pName */
};

/* Function Definitions */
void matlabEngineCaller_customXY(const emlrtStack *sp, const emxArray_real_T
  *params, real_T contrast, const emxArray_char_T *funcName, const
  emxArray_char_T *funcPath, real_T bulkIn, real_T bulkOut, emxArray_real_T
  *output, real_T *sRough)
{
  emxArray_char_T *funName;
  int32_T i;
  int32_T loop_ub;
  static const char_T cv[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a',
    'y', 'e', 'r', 's', ']', ' ', '=', ' ' };

  static const char_T cv1[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b',
    'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't',
    ',', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  emxArray_char_T *pathCall;
  emxArray_real_T *b_params;
  real_T outp[200];
  real_T nLayers;
  uint32_T rowCount;
  int32_T colCount;
  uint32_T u;
  int32_T b_i;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_char_T(sp, &funName, 2, &b_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /*  dotM = strfind(funcName,'.m'); */
  /*  if ~isempty(dotM) */
  /*      funcName = funcName(1:dotM-1); */
  /*  end */
  /* [path,funcName,extension] = fileparts(funcName); */
  i = funName->size[0] * funName->size[1];
  funName->size[0] = 1;
  funName->size[1] = funcName->size[1] + 51;
  emxEnsureCapacity_char_T(sp, funName, i, &b_emlrtRTEI);
  for (i = 0; i < 17; i++) {
    funName->data[i] = cv[i];
  }

  loop_ub = funcName->size[1];
  for (i = 0; i < loop_ub; i++) {
    funName->data[i + 17] = funcName->data[i];
  }

  for (i = 0; i < 34; i++) {
    funName->data[(i + funcName->size[1]) + 17] = cv1[i];
  }

  if (1 > params->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &emlrtBCI, sp);
  }

  emxInit_char_T(sp, &pathCall, 2, &c_emlrtRTEI, true);
  *sRough = params->data[0];
  i = pathCall->size[0] * pathCall->size[1];
  pathCall->size[0] = 1;
  pathCall->size[1] = funcPath->size[1] + 6;
  emxEnsureCapacity_char_T(sp, pathCall, i, &c_emlrtRTEI);
  pathCall->data[0] = 'c';
  pathCall->data[1] = 'd';
  pathCall->data[2] = ' ';
  pathCall->data[3] = '\'';
  loop_ub = funcPath->size[1];
  for (i = 0; i < loop_ub; i++) {
    pathCall->data[i + 4] = funcPath->data[i];
  }

  emxInit_real_T(sp, &b_params, 2, &g_emlrtRTEI, true);
  pathCall->data[funcPath->size[1] + 4] = '\'';
  pathCall->data[funcPath->size[1] + 5] = ';';
  covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);

  /* incPath2 = '/usr/include/openmpi-x86_64'; */
  /* source2 = 'matlabCallFun.h'; */
  /* source1 = 'matlabCallFun.c'; */
  /* source2 = 'matlabCallFun.h'; */
  /* coder.cinclude(source2); */
  /* coder.updateBuildInfo('addSourceFiles',source2); */
  /* coder.updateBuildInfo('addIncludePaths',incPath2); */
  /* Need to reserve some meory for the referencenced variables */
  i = b_params->size[0] * b_params->size[1];
  b_params->size[0] = 1;
  b_params->size[1] = params->size[1];
  emxEnsureCapacity_real_T(sp, b_params, i, &d_emlrtRTEI);
  loop_ub = params->size[0] * params->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_params->data[i] = params->data[i];
  }

  i = params->size[1];
  if (params->size[1] > 32767) {
    i = 32767;
  } else {
    if (params->size[1] < -32768) {
      i = -32768;
    }
  }

  matlabCallFun(&b_params->data[0], (int16_T)i, &funName->data[0],
                &pathCall->data[0], bulkIn, bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 1;

  /* reshape the output to [layers * 2] array */
  emxFree_real_T(&b_params);
  emxFree_char_T(&pathCall);
  emxFree_char_T(&funName);
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 3, nLayers >= 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
    i = (int32_T)muDoubleScalarFloor(nLayers);
    if (nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &emlrtDCI, sp);
    }

    loop_ub = output->size[0] * output->size[1];
    output->size[0] = (int32_T)nLayers;
    output->size[1] = 2;
    emxEnsureCapacity_real_T(sp, output, loop_ub, &f_emlrtRTEI);
    if ((int32_T)nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &b_emlrtDCI, sp);
    }

    loop_ub = (int32_T)nLayers << 1;
    for (i = 0; i < loop_ub; i++) {
      output->data[i] = 0.0;
    }

    u = (uint32_T)nLayers * 2U;
    i = (int32_T)u;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, u, mxDOUBLE_CLASS, (int32_T)u,
      &emlrtRTEI, sp);
    for (b_i = 0; b_i < i; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 7U);
      loop_ub = (int32_T)(b_i + 1U);
      if ((loop_ub < 1) || (loop_ub > 200)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 200, &b_emlrtBCI, sp);
      }

      if (((int32_T)rowCount < 1) || ((int32_T)rowCount > output->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)rowCount, 1, output->size[0],
          &c_emlrtBCI, sp);
      }

      if (colCount > 2) {
        emlrtDynamicBoundsCheckR2012b(3, 1, 2, &d_emlrtBCI, sp);
      }

      output->data[((int32_T)rowCount + output->size[0] * (colCount - 1)) - 1] =
        outp[loop_ub - 1];

      /* Make use of Matlab linear indexing. */
      rowCount++;
      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 4, rowCount == (uint32_T)
                     nLayers + 1U)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 8U);
        rowCount = 1U;
        colCount++;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 9U);
    i = output->size[0] * output->size[1];
    output->size[0] = 1;
    output->size[1] = 2;
    emxEnsureCapacity_real_T(sp, output, i, &e_emlrtRTEI);
    output->data[0] = 1.0;
    output->data[1] = 1.0;
    *sRough = 1.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (matlabEngineCaller_customXY.c) */
