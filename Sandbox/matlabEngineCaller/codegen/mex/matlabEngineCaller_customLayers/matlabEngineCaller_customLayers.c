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
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 74,  /* lineNo */
  17,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 73,    /* lineNo */
  24,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 73,  /* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  300,                                 /* iLast */
  75,                                  /* lineNo */
  23,                                  /* colNo */
  "outp",                              /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  76,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m",/* pName */
  3                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 84,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/matlabEngineCaller/matlabEngineCaller_customLayers.m"/* pName */
};

/* Function Definitions */
void matlabEngineCaller_customLayers(const emlrtStack *sp, const real_T params[4],
  real_T contrast, const char_T funcName[9], const char_T funcPath[41], real_T
  bulkIn, real_T bulkOut, emxArray_real_T *output, real_T *sRough)
{
  int32_T i;
  char_T cv[60];
  static const char_T cv1[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a',
    'y', 'e', 'r', 's', ']', ' ', '=', ' ' };

  char_T cv2[47];
  static const char_T cv3[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b',
    'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't',
    ',', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  real_T b_params[4];
  real_T outp[300];
  real_T nLayers;
  uint32_T rowCount;
  int32_T colCount;
  int32_T loop_ub;
  real_T d;
  int32_T b_i;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /*  dotM = strfind(funcName,'.m'); */
  /*  if ~isempty(dotM) */
  /*      funcName = funcName(1:dotM-1); */
  /*  end */
  /* [path,funcName,extension] = fileparts(funcName); */
  *sRough = params[0];
  covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);

  /* incPath2 = '/usr/include/openmpi-x86_64'; */
  /* source2 = '/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabCallFun.h'; */
  /* source1 = 'matlabCallFun.c'; */
  /* source2 = 'matlabCallFun.h'; */
  /* coder.cinclude(source2); */
  /* coder.updateBuildInfo('addSourceFiles',source2); */
  /* coder.updateBuildInfo('addIncludePaths',incPath2); */
  /* Need to reserve some meory for the referencenced variables */
  for (i = 0; i < 17; i++) {
    cv[i] = cv1[i];
  }

  for (i = 0; i < 9; i++) {
    cv[i + 17] = funcName[i];
  }

  for (i = 0; i < 34; i++) {
    cv[i + 26] = cv3[i];
  }

  cv2[0] = 'c';
  cv2[1] = 'd';
  cv2[2] = ' ';
  cv2[3] = '\'';
  for (i = 0; i < 41; i++) {
    cv2[i + 4] = funcPath[i];
  }

  cv2[45] = '\'';
  cv2[46] = ';';
  b_params[0] = params[0];
  b_params[1] = params[1];
  b_params[2] = params[2];
  b_params[3] = params[3];
  matlabCallFun(b_params, 4, cv, cv2, bulkIn, bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 1;

  /* reshape the output to [layers * 3] array */
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 3, nLayers >= 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
    i = (int32_T)muDoubleScalarFloor(nLayers);
    if (nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &emlrtDCI, sp);
    }

    loop_ub = output->size[0] * output->size[1];
    output->size[0] = (int32_T)nLayers;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, loop_ub, &c_emlrtRTEI);
    if ((int32_T)nLayers != i) {
      emlrtIntegerCheckR2012b(nLayers, &b_emlrtDCI, sp);
    }

    loop_ub = (int32_T)nLayers * 3;
    for (i = 0; i < loop_ub; i++) {
      output->data[i] = 0.0;
    }

    d = nLayers * 3.0;
    i = (int32_T)d;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
      &emlrtRTEI, sp);
    for (b_i = 0; b_i < i; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 7U);
      loop_ub = (int32_T)(b_i + 1U);
      if ((loop_ub < 1) || (loop_ub > 300)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 300, &emlrtBCI, sp);
      }

      if (((int32_T)rowCount < 1) || ((int32_T)rowCount > output->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)rowCount, 1, output->size[0],
          &b_emlrtBCI, sp);
      }

      if (colCount > 3) {
        emlrtDynamicBoundsCheckR2012b(4, 1, 3, &c_emlrtBCI, sp);
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
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, i, &b_emlrtRTEI);
    output->data[0] = 1.0;
    output->data[1] = 1.0;
    output->data[2] = 1.0;
    *sRough = 1.0;
  }
}

/* End of code generation (matlabEngineCaller_customLayers.c) */
