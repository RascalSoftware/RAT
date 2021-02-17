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
#include "matlabEngineCaller_customLayers.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtBCInfo nm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  17,                                  /* colNo */
  "params",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo mc_emlrtRTEI = { 75,/* lineNo */
  17,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtDCInfo dc_emlrtDCI = { 74, /* lineNo */
  24,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ec_emlrtDCI = { 74, /* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo om_emlrtBCI = { 1,  /* iFirst */
  3000,                                /* iLast */
  76,                                  /* lineNo */
  23,                                  /* colNo */
  "outp",                              /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qm_emlrtBCI = { 1,  /* iFirst */
  3,                                   /* iLast */
  77,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo wn_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo xn_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo yn_emlrtRTEI = { 64,/* lineNo */
  34,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo ao_emlrtRTEI = { 85,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo bo_emlrtRTEI = { 74,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo co_emlrtRTEI = { 1,/* lineNo */
  28,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

/* Function Definitions */
void matlabEngineCaller_customLayers(const emlrtStack *sp, const emxArray_real_T
  *params, real_T contrast, const emxArray_char_T *funcName, const
  emxArray_char_T *funcPath, real_T bulkIn, real_T bulkOut, emxArray_real_T
  *output, real_T *sRough)
{
  emxArray_char_T *funName;
  int32_T i;
  int32_T loop_ub;
  static const char_T b_cv[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a',
    'y', 'e', 'r', 's', ']', ' ', '=', ' ' };

  static const char_T b_cv1[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b',
    'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't',
    ',', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  emxArray_char_T *pathCall;
  emxArray_real_T *b_params;
  real_T outp[3000];
  real_T nLayers;
  uint32_T rowCount;
  int32_T colCount;
  real_T d;
  int32_T b_i;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_char_T(sp, &funName, 2, &wn_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 27U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 27U, 0U);

  /*  dotM = strfind(funcName,'.m'); */
  /*  if ~isempty(dotM) */
  /*      funcName = funcName(1:dotM-1); */
  /*  end */
  /* [path,funcName,extension] = fileparts(funcName); */
  i = funName->size[0] * funName->size[1];
  funName->size[0] = 1;
  funName->size[1] = funcName->size[1] + 51;
  emxEnsureCapacity_char_T(sp, funName, i, &wn_emlrtRTEI);
  for (i = 0; i < 17; i++) {
    funName->data[i] = b_cv[i];
  }

  loop_ub = funcName->size[1];
  for (i = 0; i < loop_ub; i++) {
    funName->data[i + 17] = funcName->data[i];
  }

  for (i = 0; i < 34; i++) {
    funName->data[(i + funcName->size[1]) + 17] = b_cv1[i];
  }

  if (1 > params->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &nm_emlrtBCI, sp);
  }

  emxInit_char_T(sp, &pathCall, 2, &xn_emlrtRTEI, true);
  *sRough = params->data[0];
  i = pathCall->size[0] * pathCall->size[1];
  pathCall->size[0] = 1;
  pathCall->size[1] = funcPath->size[1] + 6;
  emxEnsureCapacity_char_T(sp, pathCall, i, &xn_emlrtRTEI);
  pathCall->data[0] = 'c';
  pathCall->data[1] = 'd';
  pathCall->data[2] = ' ';
  pathCall->data[3] = '\'';
  loop_ub = funcPath->size[1];
  for (i = 0; i < loop_ub; i++) {
    pathCall->data[i + 4] = funcPath->data[i];
  }

  emxInit_real_T(sp, &b_params, 2, &co_emlrtRTEI, true);
  pathCall->data[funcPath->size[1] + 4] = '\'';
  pathCall->data[funcPath->size[1] + 5] = ';';
  covrtLogIf(&emlrtCoverageInstance, 27U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 27U, 5U);

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
  emxEnsureCapacity_real_T(sp, b_params, i, &yn_emlrtRTEI);
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

  /* reshape the output to [layers * 3] array */
  emxFree_real_T(&b_params);
  emxFree_char_T(&pathCall);
  emxFree_char_T(&funName);
  if (covrtLogIf(&emlrtCoverageInstance, 27U, 0U, 3, nLayers >= 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 27U, 6U);
    i = (int32_T)muDoubleScalarFloor(nLayers);
    if (nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &dc_emlrtDCI, sp);
    }

    loop_ub = output->size[0] * output->size[1];
    output->size[0] = (int32_T)nLayers;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, loop_ub, &bo_emlrtRTEI);
    if ((int32_T)nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &ec_emlrtDCI, sp);
    }

    loop_ub = (int32_T)nLayers * 3;
    for (i = 0; i < loop_ub; i++) {
      output->data[i] = 0.0;
    }

    d = nLayers * 3.0;
    i = (int32_T)d;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
      &mc_emlrtRTEI, sp);
    for (b_i = 0; b_i < i; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 27U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 27U, 7U);
      loop_ub = (int32_T)(b_i + 1U);
      if ((loop_ub < 1) || (loop_ub > 3000)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 3000, &om_emlrtBCI, sp);
      }

      if (((int32_T)rowCount < 1) || ((int32_T)rowCount > output->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)rowCount, 1, output->size[0],
          &pm_emlrtBCI, sp);
      }

      if (colCount > 3) {
        emlrtDynamicBoundsCheckR2012b(4, 1, 3, &qm_emlrtBCI, sp);
      }

      output->data[((int32_T)rowCount + output->size[0] * (colCount - 1)) - 1] =
        outp[loop_ub - 1];

      /* Make use of Matlab linear indexing. */
      rowCount++;
      if (covrtLogIf(&emlrtCoverageInstance, 27U, 0U, 4, rowCount == (uint32_T)
                     nLayers + 1U)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 27U, 8U);
        rowCount = 1U;
        colCount++;
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 27U, 0U, 0, 0);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 27U, 9U);
    i = output->size[0] * output->size[1];
    output->size[0] = 1;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, i, &ao_emlrtRTEI);
    output->data[0] = 1.0;
    output->data[1] = 1.0;
    output->data[2] = 1.0;
    *sRough = 1.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (matlabEngineCaller_customLayers.c) */
