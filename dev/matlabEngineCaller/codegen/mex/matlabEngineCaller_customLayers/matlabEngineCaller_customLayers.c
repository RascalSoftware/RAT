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
#include "matlabEngineCaller_customLayers_data.h"
#include "matlabEngineCaller_customLayers_emxutil.h"
#include "matlabEngineCaller_customLayers_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    15,                                /* lineNo */
    17,                                /* colNo */
    "params",                          /* aName */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", /* pName */
    0                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    95,                                /* lineNo */
    17,                                /* colNo */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    94,                                /* lineNo */
    24,                                /* colNo */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", /* pName */
    1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    94,                                /* lineNo */
    9,                                 /* colNo */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", /* pName */
    1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    1,                                 /* iFirst */
    300,                               /* iLast */
    96,                                /* lineNo */
    23,                                /* colNo */
    "outp",                            /* aName */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", /* pName */
    0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    97,                                /* lineNo */
    13,                                /* colNo */
    "output",                          /* aName */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", /* pName */
    0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                                 /* iFirst */
    3,                                 /* iLast */
    97,                                /* lineNo */
    13,                                /* colNo */
    "output",                          /* aName */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m", /* pName */
    3                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    14,                                /* lineNo */
    1,                                 /* colNo */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    19,                                /* lineNo */
    1,                                 /* colNo */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    84,                                /* lineNo */
    34,                                /* colNo */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    105,                               /* lineNo */
    9,                                 /* colNo */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    94,                                /* lineNo */
    9,                                 /* colNo */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    1,                                 /* lineNo */
    28,                                /* colNo */
    "matlabEngineCaller_customLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/dev/matlabEngineCaller/"
    "matlabEngineCaller_customLayers.m" /* pName */
};

/* Function Definitions */
void matlabEngineCaller_customLayers(
    const emlrtStack *sp, const emxArray_real_T *params, real_T contrast,
    const emxArray_char_T *funcName, const emxArray_char_T *funcPath,
    real_T bulkIn, real_T bulkOut, emxArray_real_T *output, real_T *sRough)
{
  static const char_T cv1[34] = {'(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b',
                                 'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u',
                                 'l', 'k', '_', 'o', 'u', 't', ',', 'c', 'o',
                                 'n', 't', 'r', 'a', 's', 't', ')'};
  static const char_T cv[17] = {'[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a',
                                'y', 'e', 'r', 's', ']', ' ', '=', ' '};
  emxArray_char_T *funName;
  emxArray_char_T *pathCall;
  emxArray_real_T *b_params;
  real_T outp[300];
  real_T d;
  real_T nLayers;
  int32_T colCount;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  uint32_T rowCount;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_char_T(sp, &funName, 2, &b_emlrtRTEI, true);
  /*  Evaluate matlab function from compiled mex using an external Matlab */
  /*  engine. This version uses the Matlab Engine API for C  */
  /*  (https://uk.mathworks.com/help/matlab/calling-matlab-engine-from-c-programs-1.html)
   */
  /*  In reality, we want to be using a Class via the Matleb engine API for C++
   */
  /*  (https://uk.mathworks.com/help/matlab/matlab_external/matlab-engine-api-for-c.html)
   */
  /*  Irrespective of we use Matlab or Mex, we need the same calling string. */
  /*  We put together the Matlab command string that that we will excecute */
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
    emlrtDynamicBoundsCheckR2012b(1, 1, params->size[1], &emlrtBCI,
                                  (emlrtCTX)sp);
  }
  emxInit_char_T(sp, &pathCall, 2, &c_emlrtRTEI, true);
  *sRough = params->data[0];
  /*  Also make a commans string to change the Matlab Path to the location of */
  /*  the Matlab function */
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
  /*  If not compiled, excecute our custom function from Matlab */
  /*  Matlab coder will compile from here */
  /*  Path to the engine 'h' files. This is always relative to the base */
  /*  Matlab path on any system */
  /*  Link path to the Matlab shared libraries. This will vary depending on */
  /*  the OS */
  /*  The libraries we need */
  /*  The source file including Path */
  /* source2 =
   * '/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabCallFun.h';
   */
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
  loop_ub = params->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_params->data[i] = params->data[i];
  }
  i = params->size[1];
  if (params->size[1] > 32767) {
    i = 32767;
  }
  matlabCallFun(&b_params->data[0], (int16_T)i, &funName->data[0],
                &pathCall->data[0], bulkIn, bulkOut, contrast, &outp[0],
                &nLayers);
  rowCount = 1U;
  colCount = 1;
  /* reshape the output to [layers * 3] array */
  emxFree_real_T(&b_params);
  emxFree_char_T(&pathCall);
  emxFree_char_T(&funName);
  if (nLayers >= 1.0) {
    i = (int32_T)muDoubleScalarFloor(nLayers);
    if (nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &emlrtDCI, (emlrtCTX)sp);
    }
    loop_ub = output->size[0] * output->size[1];
    i1 = (int32_T)nLayers;
    output->size[0] = i1;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, loop_ub, &f_emlrtRTEI);
    if (i1 != i) {
      emlrtIntegerCheckR2012b(nLayers, &b_emlrtDCI, (emlrtCTX)sp);
    }
    loop_ub = i1 * 3;
    for (i = 0; i < loop_ub; i++) {
      output->data[i] = 0.0;
    }
    d = nLayers * 3.0;
    i = (int32_T)d;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
                                  &emlrtRTEI, (emlrtCTX)sp);
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) > 300)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, 300,
                                      &b_emlrtBCI, (emlrtCTX)sp);
      }
      if (((int32_T)rowCount < 1) || ((int32_T)rowCount > output->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)rowCount, 1, output->size[0],
                                      &c_emlrtBCI, (emlrtCTX)sp);
      }
      if (colCount > 3) {
        emlrtDynamicBoundsCheckR2012b(4, 1, 3, &d_emlrtBCI, (emlrtCTX)sp);
      }
      output->data[((int32_T)rowCount + output->size[0] * (colCount - 1)) - 1] =
          outp[loop_ub];
      /* Make use of Matlab linear indexing. */
      rowCount++;
      if (rowCount == (uint32_T)nLayers + 1U) {
        rowCount = 1U;
        colCount++;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
  } else {
    i = output->size[0] * output->size[1];
    output->size[0] = 1;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, i, &e_emlrtRTEI);
    output->data[0] = 1.0;
    output->data[1] = 1.0;
    output->data[2] = 1.0;
    *sRough = 1.0;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (matlabEngineCaller_customLayers.c) */
