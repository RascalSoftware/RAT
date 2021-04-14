/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * allocateLayersForContrast.c
 *
 * Code generation for function 'allocateLayersForContrast'
 *
 */

/* Include files */
#include "allocateLayersForContrast.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  24,                                  /* colNo */
  "thisContrastLayers",                /* aName */
  "allocateLayersForContrast",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  17,                                  /* colNo */
  "outParameterisedLayers",            /* aName */
  "allocateLayersForContrast",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 10, /* lineNo */
  17,                                  /* colNo */
  "allocateLayersForContrast",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  17,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "allocateLayersForContrast",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ug_emlrtRTEI = { 7,/* lineNo */
  1,                                   /* colNo */
  "allocateLayersForContrast",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateLayersForContrast.m"/* pName */
};

/* Function Definitions */
void allocateLayersForContrast(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, const emxArray_cell_wrap_18 *outParameterisedLayers,
  emxArray_real_T *thisContrastLayers)
{
  int32_T n;
  int32_T i;
  int32_T b_i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  real_T d;
  covrtLogFcn(&emlrtCoverageInstance, 8U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 0U);

  /*  Take the layers list for a contrast and build an */
  /*  array of real valued layers  */
  if ((contrastLayers->size[0] == 0) || (contrastLayers->size[1] == 0)) {
    n = 0;
  } else {
    n = contrastLayers->size[1];
  }

  i = thisContrastLayers->size[0] * thisContrastLayers->size[1];
  thisContrastLayers->size[0] = n;
  thisContrastLayers->size[1] = 5;
  emxEnsureCapacity_real_T(sp, thisContrastLayers, i, &ug_emlrtRTEI);
  n *= 5;
  for (i = 0; i < n; i++) {
    thisContrastLayers->data[i] = 0.0;
  }

  if ((contrastLayers->size[0] == 0) || (contrastLayers->size[1] == 0)) {
    n = 0;
  } else {
    n = contrastLayers->size[1];
  }

  for (b_i = 0; b_i < n; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 8U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 1U);
    i = b_i + 1;
    if ((i < 1) || (i > thisContrastLayers->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, thisContrastLayers->size[0],
        &xc_emlrtBCI, sp);
    }

    i = outParameterisedLayers->size[1] - 1;
    i1 = b_i + 1;
    for (i2 = 0; i2 < 5; i2++) {
      i3 = contrastLayers->size[0] * contrastLayers->size[1];
      if ((i1 < 1) || (i1 > i3)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i3, &ad_emlrtBCI, sp);
      }

      d = contrastLayers->data[i1 - 1];
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &cb_emlrtDCI, sp);
      }

      i3 = (int32_T)d - 1;
      if ((i3 < 0) || (i3 > i)) {
        emlrtDynamicBoundsCheckR2012b(i3, 0, i, &yc_emlrtBCI, sp);
      }

      thisContrastLayers->data[b_i + thisContrastLayers->size[0] * i2] =
        outParameterisedLayers->data[i3].f1[i2];
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 8U, 0U, 0, 0);
}

/* End of code generation (allocateLayersForContrast.c) */
