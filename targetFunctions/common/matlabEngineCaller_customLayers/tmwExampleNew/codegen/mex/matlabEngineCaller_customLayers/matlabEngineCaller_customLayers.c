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

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 84,  /* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 74,/* lineNo */
  17,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 73,    /* lineNo */
  24,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 73,  /* lineNo */
  9,                                   /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  300,                                 /* iLast */
  75,                                  /* lineNo */
  23,                                  /* colNo */
  "outp",                              /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  76,                                  /* lineNo */
  13,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/matlabEngineCaller_customLayers.m",/* pName */
  3                                    /* checkKind */
};

/* Function Definitions */
void matlabEngineCaller_customLayers(const emlrtStack *sp, const real_T params[8],
  real_T contrast, const char_T funcName[10], const char_T funcPath[54], real_T
  bulkIn, real_T bulkOut, emxArray_real_T *output, real_T *sRough)
{
  real_T b_params[8];
  int32_T i0;
  char_T cv0[61];
  static const char_T cv1[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a',
    'y', 'e', 'r', 's', ']', ' ', '=', ' ' };

  char_T cv2[60];
  static const char_T cv3[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b',
    'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't',
    ',', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  real_T outp[300];
  real_T nLayers;
  uint32_T rowCount;
  int32_T colCount;
  real_T d0;
  int32_T loop_ub;
  int32_T i;
  int32_T i1;
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
  /* source1 = 'matlabCallFun.c'; */
  /* source2 = 'matlabCallFun.h'; */
  /* coder.updateBuildInfo('addIncludePaths',incPath2); */
  /* Need to reserve some meory for the referencenced variables */
  memcpy(&b_params[0], &params[0], sizeof(real_T) << 3);
  for (i0 = 0; i0 < 17; i0++) {
    cv0[i0] = cv1[i0];
  }

  for (i0 = 0; i0 < 10; i0++) {
    cv0[i0 + 17] = funcName[i0];
  }

  for (i0 = 0; i0 < 34; i0++) {
    cv0[i0 + 27] = cv3[i0];
  }

  cv2[0] = 'c';
  cv2[1] = 'd';
  cv2[2] = ' ';
  cv2[3] = '\'';
  for (i0 = 0; i0 < 54; i0++) {
    cv2[i0 + 4] = funcPath[i0];
  }

  cv2[58] = '\'';
  cv2[59] = ';';
  matlabCallFun(b_params, 8, cv0, cv2, bulkIn, bulkOut, contrast, outp, &nLayers);
  rowCount = 1U;
  colCount = 1;

  /* reshape the output to [layers * 3] array */
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 3, nLayers >= 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
    i0 = output->size[0] * output->size[1];
    d0 = (int32_T)muDoubleScalarFloor(nLayers);
    if (nLayers != d0) {
      emlrtIntegerCheckR2012b(nLayers, &emlrtDCI, sp);
    }

    loop_ub = (int32_T)nLayers;
    output->size[0] = loop_ub;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, i0, &b_emlrtRTEI);
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
      &d_emlrtRTEI, sp);
    for (i = 0; i < i0; i++) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 7U);
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
      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 4, rowCount == nLayers +
                     1.0)) {
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
    i0 = output->size[0] * output->size[1];
    output->size[0] = 1;
    output->size[1] = 3;
    emxEnsureCapacity_real_T(sp, output, i0, &emlrtRTEI);
    output->data[0] = 1.0;
    output->data[1] = 1.0;
    output->data[2] = 1.0;
    *sRough = 1.0;
  }
}

/* End of code generation (matlabEngineCaller_customLayers.c) */
