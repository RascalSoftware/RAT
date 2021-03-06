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
#include "rt_nonfinite.h"
#include "matlabEngineCaller_customLayers.h"
#include "matlabEngineCaller_customLayers_emxutil.h"
#include "matlabEngineCaller_customLayers_data.h"
#include "matlabCallFun.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  28,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_loop_single/matlab"
  "EngineCaller_customLayers.m"        /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 61,/* lineNo */
  17,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_loop_single/matlab"
  "EngineCaller_customLayers.m"        /* pName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  300,                                 /* iLast */
  62,                                  /* lineNo */
  23,                                  /* colNo */
  "outp",                              /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_loop_single/matlab"
  "EngineCaller_customLayers.m",       /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 60,    /* lineNo */
  24,                                  /* colNo */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_loop_single/matlab"
  "EngineCaller_customLayers.m",       /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  20,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_loop_single/matlab"
  "EngineCaller_customLayers.m",       /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  29,                                  /* colNo */
  "output",                            /* aName */
  "matlabEngineCaller_customLayers",   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/matlabEngineCaller_customLayers/tmwExample/example_loop_single/matlab"
  "EngineCaller_customLayers.m",       /* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void matlabEngineCaller_customLayers(const emlrtStack *sp, const real_T params[8],
  real_T contrast, const char_T funcName[10], const char_T funcPath[122], real_T
  bulkIn, real_T bulkOut, emxArray_real_T *output, real_T sRough_data[], int32_T
  sRough_size[2])
{
  real_T outp[300];
  real_T nLayers;
  real_T b_params[8];
  char_T cv0[61];
  int32_T i0;
  static const char_T cv1[17] = { '[', 't', 'o', 't', 'a', 'l', ',', 'l', 'a',
    'y', 'e', 'r', 's', ']', ' ', '=', ' ' };

  char_T cv2[128];
  static const char_T cv3[34] = { '(', 'p', 'a', 'r', 'a', 'm', 's', ',', 'b',
    'u', 'l', 'k', '_', 'i', 'n', ',', 'b', 'u', 'l', 'k', '_', 'o', 'u', 't',
    ',', 'c', 'o', 'n', 't', 'r', 'a', 's', 't', ')' };

  static const char_T cv4[4] = { 'c', 'd', ' ', '\'' };

  static const char_T cv5[2] = { '\'', ';' };

  uint32_T rowCount;
  int32_T colCount;
  int32_T loop_ub;
  real_T d0;
  int32_T i1;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  sRough_size[0] = 1;
  sRough_size[1] = 1;
  sRough_data[0] = params[0];
  covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);

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

  for (i0 = 0; i0 < 4; i0++) {
    cv2[i0] = cv4[i0];
  }

  memcpy(&cv2[4], &funcPath[0], 122U * sizeof(char_T));
  for (i0 = 0; i0 < 2; i0++) {
    cv2[i0 + 126] = cv5[i0];
  }

  matlabCallFun(b_params, 8.0, cv0, cv2, bulkIn, bulkOut, contrast, outp,
                &nLayers);
  rowCount = 1U;
  colCount = 1;

  /* reshape the output to [layers * 3] array */
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 2, nLayers >= 1.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);
    i0 = output->size[0] * output->size[1];
    if (nLayers != (int32_T)muDoubleScalarFloor(nLayers)) {
      emlrtIntegerCheckR2012b(nLayers, &emlrtDCI, sp);
    }

    output->size[0] = (int32_T)nLayers;
    output->size[1] = 3;
    emxEnsureCapacity(sp, (emxArray__common *)output, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    if (nLayers != (int32_T)muDoubleScalarFloor(nLayers)) {
      emlrtIntegerCheckR2012b(nLayers, &emlrtDCI, sp);
    }

    loop_ub = (int32_T)nLayers * 3;
    for (i0 = 0; i0 < loop_ub; i0++) {
      output->data[i0] = 0.0;
    }

    d0 = nLayers * 3.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, d0, mxDOUBLE_CLASS, (int32_T)d0,
      &c_emlrtRTEI, sp);
    loop_ub = 0;
    while (loop_ub <= (int32_T)d0 - 1) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);
      i0 = loop_ub + 1;
      if (!((i0 >= 1) && (i0 <= 300))) {
        emlrtDynamicBoundsCheckR2012b(i0, 1, 300, &emlrtBCI, sp);
      }

      /* Make use of Matlab linear indexing. */
      i0 = output->size[0];
      i1 = (int32_T)rowCount;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &b_emlrtBCI, sp);
      }

      if (!((colCount >= 1) && (colCount <= 3))) {
        emlrtDynamicBoundsCheckR2012b(colCount, 1, 3, &c_emlrtBCI, sp);
      }

      output->data[(i1 + output->size[0] * (colCount - 1)) - 1] = outp[loop_ub];
      rowCount++;
      if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 3, rowCount == nLayers +
                     1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 6U);
        rowCount = 1U;
        colCount++;
      }

      loop_ub++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 7U);
    i0 = output->size[0] * output->size[1];
    output->size[0] = 0;
    output->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)output, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    sRough_size[0] = 0;
    sRough_size[1] = 0;
  }
}

/* End of code generation (matlabEngineCaller_customLayers.c) */
