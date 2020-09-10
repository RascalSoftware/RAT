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
#include "call_customLayers.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo jh_emlrtRSI = { 3,  /* lineNo */
  "call_customLayers",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/call_customLayers.m"/* pathName */
};

static emlrtBCInfo sm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  17,                                  /* colNo */
  "params",                            /* aName */
  "call_customLayers",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/call_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  17,                                  /* colNo */
  "params",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo mc_emlrtRTEI = { 74,/* lineNo */
  17,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtDCInfo vb_emlrtDCI = { 73, /* lineNo */
  24,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo wb_emlrtDCI = { 73, /* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo um_emlrtBCI = { 1,  /* iFirst */
  300,                                 /* iLast */
  75,                                  /* lineNo */
  23,                                  /* colNo */
  "outp",                              /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vm_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wm_emlrtBCI = { 1,  /* iFirst */
  3,                                   /* iLast */
  76,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo tm_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo um_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo vm_emlrtRTEI = { 63,/* lineNo */
  34,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo wm_emlrtRTEI = { 84,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo xm_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo ym_emlrtRTEI = { 1,/* lineNo */
  28,                                  /* colNo */
  "call_customLayers",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/call_customLayers.m"/* pName */
};

/* Function Definitions */
void call_customLayers(const emlrtStack *sp, const emxArray_real_T *params,
  real_T contrast, const emxArray_char_T *file, const emxArray_char_T *callPath,
  real_T bulkIn, real_T bulkOut, emxArray_real_T *output, real_T *sRough)
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
  real_T outp[300];
  real_T nLayers;
  uint32_T rowCount;
  int32_T colCount;
  real_T d;
  int32_T b_i;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_char_T(sp, &funName, 2, &tm_emlrtRTEI, true);
  st.site = &jh_emlrtRSI;

  /*  dotM = strfind(funcName,'.m'); */
  /*  if ~isempty(dotM) */
  /*      funcName = funcName(1:dotM-1); */
  /*  end */
  /* [path,funcName,extension] = fileparts(funcName); */
  i = funName->size[0] * funName->size[1];
  funName->size[0] = 1;
  funName->size[1] = file->size[1] + 51;
  emxEnsureCapacity_char_T(&st, funName, i, &tm_emlrtRTEI);
  for (i = 0; i < 17; i++) {
    funName->data[i] = b_cv[i];
  }

  loop_ub = file->size[1];
  for (i = 0; i < loop_ub; i++) {
    funName->data[i + 17] = file->data[i];
  }

  for (i = 0; i < 34; i++) {
    funName->data[(i + file->size[1]) + 17] = b_cv1[i];
  }

  if (1 > params->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &tm_emlrtBCI, &st);
  }

  emxInit_char_T(&st, &pathCall, 2, &um_emlrtRTEI, true);
  i = pathCall->size[0] * pathCall->size[1];
  pathCall->size[0] = 1;
  pathCall->size[1] = callPath->size[1] + 6;
  emxEnsureCapacity_char_T(&st, pathCall, i, &um_emlrtRTEI);
  pathCall->data[0] = 'c';
  pathCall->data[1] = 'd';
  pathCall->data[2] = ' ';
  pathCall->data[3] = '\'';
  loop_ub = callPath->size[1];
  for (i = 0; i < loop_ub; i++) {
    pathCall->data[i + 4] = callPath->data[i];
  }

  emxInit_real_T(&st, &b_params, 2, &ym_emlrtRTEI, true);
  pathCall->data[callPath->size[1] + 4] = '\'';
  pathCall->data[callPath->size[1] + 5] = ';';

  /* incPath2 = '/usr/include/openmpi-x86_64'; */
  /* source2 = '/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabCallFun.h'; */
  /* source1 = 'matlabCallFun.c'; */
  /* source2 = 'matlabCallFun.h'; */
  /* coder.cinclude(source2); */
  /* coder.updateBuildInfo('addSourceFiles',source2); */
  /* coder.updateBuildInfo('addIncludePaths',incPath2); */
  /* Need to reserve some meory for the referencenced variables */
  i = b_params->size[0] * b_params->size[1];
  b_params->size[0] = 1;
  b_params->size[1] = params->size[1];
  emxEnsureCapacity_real_T(&st, b_params, i, &vm_emlrtRTEI);
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
  if (nLayers >= 1.0) {
    i = (int32_T)muDoubleScalarFloor(nLayers);
    if (nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &vb_emlrtDCI, &st);
    }

    loop_ub = output->size[0] * output->size[1];
    output->size[0] = (int32_T)nLayers;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(&st, output, loop_ub, &xm_emlrtRTEI);
    if ((int32_T)nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &wb_emlrtDCI, &st);
    }

    loop_ub = (int32_T)nLayers * 3;
    for (i = 0; i < loop_ub; i++) {
      output->data[i] = 0.0;
    }

    d = nLayers * 3.0;
    i = (int32_T)d;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
      &mc_emlrtRTEI, &st);
    for (b_i = 0; b_i < i; b_i++) {
      loop_ub = (int32_T)(b_i + 1U);
      if ((loop_ub < 1) || (loop_ub > 300)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 300, &um_emlrtBCI, &st);
      }

      if (((int32_T)rowCount < 1) || ((int32_T)rowCount > output->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)rowCount, 1, output->size[0],
          &vm_emlrtBCI, &st);
      }

      if (colCount > 3) {
        emlrtDynamicBoundsCheckR2012b(4, 1, 3, &wm_emlrtBCI, &st);
      }

      output->data[((int32_T)rowCount + output->size[0] * (colCount - 1)) - 1] =
        outp[loop_ub - 1];

      /* Make use of Matlab linear indexing. */
      rowCount++;
      if (rowCount == (uint32_T)nLayers + 1U) {
        rowCount = 1U;
        colCount++;
      }
    }
  } else {
    i = output->size[0] * output->size[1];
    output->size[0] = 1;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(&st, output, i, &wm_emlrtRTEI);
    output->data[0] = 1.0;
    output->data[1] = 1.0;
    output->data[2] = 1.0;
  }

  if (1 > params->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &sm_emlrtBCI, sp);
  }

  *sRough = params->data[0];
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (call_customLayers.c) */
