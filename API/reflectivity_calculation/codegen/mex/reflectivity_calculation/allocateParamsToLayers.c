/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * allocateParamsToLayers.c
 *
 * Code generation for function 'allocateParamsToLayers'
 *
 */

/* Include files */
#include "allocateParamsToLayers.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  29,                                  /* colNo */
  "thisLayer",                         /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  31,                                  /* colNo */
  "layersDetails",                     /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  39,                                  /* colNo */
  "thisLayer",                         /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { 1,  /* iFirst */
  5,                                   /* iLast */
  21,                                  /* lineNo */
  5,                                   /* colNo */
  "thisOutLayer",                      /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  5,                                   /* colNo */
  "outLayers",                         /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  31,                                  /* colNo */
  "params",                            /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 16,  /* lineNo */
  31,                                  /* colNo */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo oh_emlrtRTEI = { 9,/* lineNo */
  20,                                  /* colNo */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m"/* pName */
};

/* Function Definitions */
void allocateParamsToLayers(const emlrtStack *sp, const emxArray_real_T *params,
  const emxArray_cell_wrap_3 *layersDetails, emxArray_cell_wrap_16 *outLayers)
{
  int32_T i;
  real_T thisOutLayer[5];
  int32_T b_i;
  int32_T i1;
  int32_T n;
  int32_T i2;
  real_T d;
  covrtLogFcn(&emlrtCoverageInstance, 5U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 0U);

  /* This function takes the list of all layers (in terms of parameter */
  /* numbers) in layersDetails, and loops through putting in the correct */
  /* parameter value from the parameter array in each layer.  */
  for (i = 0; i < 5; i++) {
    thisOutLayer[i] = 0.0;
  }

  i = outLayers->size[0] * outLayers->size[1];
  outLayers->size[0] = 1;
  outLayers->size[1] = layersDetails->size[0];
  emxEnsureCapacity_cell_wrap_16(sp, outLayers, i, &oh_emlrtRTEI);
  i = layersDetails->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 5U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 1U);
    i1 = layersDetails->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xc_emlrtBCI, sp);
    }

    i1 = layersDetails->data[b_i].f1.size[1];
    for (n = 0; n <= i1 - 2; n++) {
      covrtLogFor(&emlrtCoverageInstance, 5U, 0U, 1, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 2U);
      i2 = n + 1;
      if ((i2 < 1) || (i2 > layersDetails->data[b_i].f1.size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, layersDetails->data[b_i].f1.size[1],
          &wc_emlrtBCI, sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 5U, 0U, 0, covrtLogMcdc
                     (&emlrtCoverageInstance, 5U, 0U, 0, !covrtLogCond
                      (&emlrtCoverageInstance, 5U, 0U, 0, muDoubleScalarIsNaN
                       (layersDetails->data[b_i].f1.data[n]))))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 3U);
        d = layersDetails->data[b_i].f1.data[n];
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &x_emlrtDCI, sp);
        }

        i2 = (int32_T)d;
        if ((i2 < 1) || (i2 > params->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, params->size[1], &cd_emlrtBCI, sp);
        }

        thisOutLayer[n] = params->data[i2 - 1];
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 4U);
        thisOutLayer[n] = rtNaN;
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 5U, 0U, 1, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 5U, 5U);
    if (layersDetails->data[b_i].f1.size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(layersDetails->data[b_i].f1.size[1], 1,
        layersDetails->data[b_i].f1.size[1], &yc_emlrtBCI, sp);
    }

    if ((layersDetails->data[b_i].f1.size[1] < 1) || (layersDetails->data[b_i].
         f1.size[1] > 5)) {
      emlrtDynamicBoundsCheckR2012b(layersDetails->data[b_i].f1.size[1], 1, 5,
        &ad_emlrtBCI, sp);
    }

    thisOutLayer[layersDetails->data[b_i].f1.size[1] - 1] = layersDetails->
      data[b_i].f1.data[layersDetails->data[b_i].f1.size[1] - 1];
    i1 = outLayers->size[1] - 1;
    for (i2 = 0; i2 < 5; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bd_emlrtBCI, sp);
      }

      outLayers->data[b_i].f1[i2] = thisOutLayer[i2];
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 5U, 0U, 0, 0);
}

/* End of code generation (allocateParamsToLayers.c) */
