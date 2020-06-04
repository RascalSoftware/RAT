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
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtBCInfo mf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  24,                                  /* colNo */
  "thisContrastLayers",                /* aName */
  "allocateLayersForContrast",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  17,                                  /* colNo */
  "outParameterisedLayers",            /* aName */
  "allocateLayersForContrast",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 10,  /* lineNo */
  17,                                  /* colNo */
  "allocateLayersForContrast",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo of_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  17,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "allocateLayersForContrast",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/groupLayers/allocateLayersForContrast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo xf_emlrtRTEI = { 7,/* lineNo */
  1,                                   /* colNo */
  "allocateLayersForContrast",         /* fName */
  "/home/arwel/Documents/RascalDev/RAT_new/targetFunctions/common/groupLayers/allocateLayersForContrast.m"/* pName */
};

/* Function Definitions */
void allocateLayersForContrast(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, const emxArray_cell_wrap_13 *outParameterisedLayers,
  emxArray_real_T *thisContrastLayers)
{
  int32_T i;
  int32_T loop_ub;
  int32_T b_i;
  int32_T i1;
  int32_T i2;
  real_T d;
  int32_T i3;

  /*  Take the layers list for a contrast and build an */
  /*  array of real valued layers  */
  i = thisContrastLayers->size[0] * thisContrastLayers->size[1];
  thisContrastLayers->size[0] = contrastLayers->size[1];
  thisContrastLayers->size[1] = 5;
  emxEnsureCapacity_real_T(sp, thisContrastLayers, i, &xf_emlrtRTEI);
  loop_ub = contrastLayers->size[1] * 5;
  for (i = 0; i < loop_ub; i++) {
    thisContrastLayers->data[i] = 0.0;
  }

  i = contrastLayers->size[1];
  for (b_i = 0; b_i < i; b_i++) {
    loop_ub = b_i + 1;
    if ((loop_ub < 1) || (loop_ub > thisContrastLayers->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, thisContrastLayers->size[0],
        &mf_emlrtBCI, sp);
    }

    loop_ub = outParameterisedLayers->size[1] - 1;
    i1 = b_i + 1;
    for (i2 = 0; i2 < 5; i2++) {
      if ((i1 < 1) || (i1 > contrastLayers->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, contrastLayers->size[1],
          &of_emlrtBCI, sp);
      }

      d = contrastLayers->data[i1 - 1];
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &y_emlrtDCI, sp);
      }

      i3 = (int32_T)d - 1;
      if ((i3 < 0) || (i3 > loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(i3, 0, loop_ub, &nf_emlrtBCI, sp);
      }

      thisContrastLayers->data[b_i + thisContrastLayers->size[0] * i2] =
        outParameterisedLayers->data[i3].f1[i2];
    }
  }
}

/* End of code generation (allocateLayersForContrast.c) */
