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
#include "matlabCallFun.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo nh_emlrtRSI = { 10, /* lineNo */
  "matlabEngineCaller_customLayers",   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pathName */
};

static emlrtBCInfo sl_emlrtBCI = { 1,  /* iFirst */
  3,                                   /* iLast */
  80,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo tl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ul_emlrtBCI = { 1,  /* iFirst */
  3000,                                /* iLast */
  79,                                  /* lineNo */
  23,                                  /* colNo */
  "outp",                              /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ic_emlrtDCI = { 77, /* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo jc_emlrtDCI = { 77, /* lineNo */
  24,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo vl_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  17,                                  /* colNo */
  "params",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo sc_emlrtRTEI = { 78,/* lineNo */
  17,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo um_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo vm_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo wm_emlrtRTEI = { 67,/* lineNo */
  34,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo xm_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo ym_emlrtRTEI = { 77,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo an_emlrtRTEI = { 1,/* lineNo */
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
  int32_T input_sizes_idx_1;
  emxArray_char_T *funName;
  int32_T i;
  static const char_T varargin_1[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l',
    'a', 'y', 'e', 'r', 's', ']', ' ', '=', ' ' };

  static const char_T varargin_3[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',',
    'b', 'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u',
    't', ',', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  emxArray_char_T *pathCall;
  emxArray_real_T *b_params;
  real_T outp[3000];
  real_T nLayers;
  uint32_T rowCount;
  int32_T colCount;
  real_T d;
  int32_T b_i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 31U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 0U);

  /*  dotM = strfind(funcName,'.m'); */
  /*  if ~isempty(dotM) */
  /*      funcName = funcName(1:dotM-1); */
  /*  end */
  /* [path,funcName,extension] = fileparts(funcName); */
  st.site = &nh_emlrtRSI;
  b_st.site = &we_emlrtRSI;
  if ((funcName->size[0] != 0) && (funcName->size[1] != 0)) {
    input_sizes_idx_1 = funcName->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  emxInit_char_T(&b_st, &funName, 2, &um_emlrtRTEI, true);
  i = funName->size[0] * funName->size[1];
  funName->size[0] = 1;
  funName->size[1] = input_sizes_idx_1 + 51;
  emxEnsureCapacity_char_T(&b_st, funName, i, &um_emlrtRTEI);
  for (i = 0; i < 17; i++) {
    funName->data[i] = varargin_1[i];
  }

  for (i = 0; i < input_sizes_idx_1; i++) {
    funName->data[i + 17] = funcName->data[i];
  }

  for (i = 0; i < 34; i++) {
    funName->data[(i + input_sizes_idx_1) + 17] = varargin_3[i];
  }

  if (1 > params->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &vl_emlrtBCI, sp);
  }

  emxInit_char_T(sp, &pathCall, 2, &vm_emlrtRTEI, true);
  *sRough = params->data[0];
  i = pathCall->size[0] * pathCall->size[1];
  pathCall->size[0] = 1;
  pathCall->size[1] = funcPath->size[1] + 6;
  emxEnsureCapacity_char_T(sp, pathCall, i, &vm_emlrtRTEI);
  pathCall->data[0] = 'c';
  pathCall->data[1] = 'd';
  pathCall->data[2] = ' ';
  pathCall->data[3] = '\'';
  input_sizes_idx_1 = funcPath->size[1];
  for (i = 0; i < input_sizes_idx_1; i++) {
    pathCall->data[i + 4] = funcPath->data[i];
  }

  emxInit_real_T(sp, &b_params, 2, &an_emlrtRTEI, true);
  pathCall->data[funcPath->size[1] + 4] = '\'';
  pathCall->data[funcPath->size[1] + 5] = ';';
  covrtLogIf(&emlrtCoverageInstance, 31U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 5U);

  /* incPath2 = '/usr/include/openmpi-x86_64'; */
  /* source2 = 'matlabCallFun.h'; */
  /* source1 = 'matlabCallFun.c'; */
  /* source2 = 'matlabCallFun.h'; */
  /* coder.updateBuildInfo('addSourceFiles',source2); */
  /* Need to reserve some meory for the referencenced variables */
  i = b_params->size[0] * b_params->size[1];
  b_params->size[0] = 1;
  b_params->size[1] = params->size[1];
  emxEnsureCapacity_real_T(sp, b_params, i, &wm_emlrtRTEI);
  input_sizes_idx_1 = params->size[0] * params->size[1];
  for (i = 0; i < input_sizes_idx_1; i++) {
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
  if (covrtLogIf(&emlrtCoverageInstance, 31U, 0U, 3, nLayers >= 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 6U);
    i = (int32_T)muDoubleScalarFloor(nLayers);
    if (nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &jc_emlrtDCI, sp);
    }

    input_sizes_idx_1 = output->size[0] * output->size[1];
    output->size[0] = (int32_T)nLayers;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, input_sizes_idx_1, &ym_emlrtRTEI);
    if ((int32_T)nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &ic_emlrtDCI, sp);
    }

    input_sizes_idx_1 = (int32_T)nLayers * 3;
    for (i = 0; i < input_sizes_idx_1; i++) {
      output->data[i] = 0.0;
    }

    d = nLayers * 3.0;
    i = (int32_T)d;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
      &sc_emlrtRTEI, sp);
    for (b_i = 0; b_i < i; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 31U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 7U);
      if (colCount > 3) {
        emlrtDynamicBoundsCheckR2012b(4, 1, 3, &sl_emlrtBCI, sp);
      }

      if (((int32_T)rowCount < 1) || ((int32_T)rowCount > output->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)rowCount, 1, output->size[0],
          &tl_emlrtBCI, sp);
      }

      input_sizes_idx_1 = (int32_T)(b_i + 1U);
      if ((input_sizes_idx_1 < 1) || (input_sizes_idx_1 > 3000)) {
        emlrtDynamicBoundsCheckR2012b(input_sizes_idx_1, 1, 3000, &ul_emlrtBCI,
          sp);
      }

      output->data[((int32_T)rowCount + output->size[0] * (colCount - 1)) - 1] =
        outp[input_sizes_idx_1 - 1];

      /* Make use of Matlab linear indexing. */
      rowCount++;
      if (covrtLogIf(&emlrtCoverageInstance, 31U, 0U, 4, rowCount == (uint32_T)
                     nLayers + 1U)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 8U);
        rowCount = 1U;
        colCount++;
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 31U, 0U, 0, 0);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 31U, 9U);
    i = output->size[0] * output->size[1];
    output->size[0] = 1;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, i, &xm_emlrtRTEI);
    output->data[0] = 1.0;
    output->data[1] = 1.0;
    output->data[2] = 1.0;
    *sRough = 1.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (matlabEngineCaller_customLayers.c) */
