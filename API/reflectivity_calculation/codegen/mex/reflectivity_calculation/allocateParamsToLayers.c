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
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtBCInfo df_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  29,                                  /* colNo */
  "thisLayer",                         /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ef_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  31,                                  /* colNo */
  "layersDetails",                     /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ff_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  25,                                  /* colNo */
  "thisLayer",                         /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  5,                                   /* colNo */
  "outLayers",                         /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  31,                                  /* colNo */
  "params",                            /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 17,  /* lineNo */
  31,                                  /* colNo */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo cg_emlrtRTEI = { 9,/* lineNo */
  20,                                  /* colNo */
  "allocateParamsToLayers",            /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m"/* pName */
};

/* Function Definitions */
void allocateParamsToLayers(const emlrtStack *sp, const emxArray_real_T *params,
  const emxArray_cell_wrap_2 *layersDetails, emxArray_cell_wrap_14 *outLayers)
{
  int32_T i;
  real_T thisOutLayer[5];
  int32_T b_i;
  int32_T i1;
  int32_T n;
  int32_T b_n;
  int32_T i2;

  /* This function takes the list of all layers (in terms of parameter */
  /* numbers) in layersDetails, and loops through putting in the correct */
  /* parameter value from the parameter array in each layer.  */
  for (i = 0; i < 5; i++) {
    thisOutLayer[i] = 0.0;
  }

  i = outLayers->size[0] * outLayers->size[1];
  outLayers->size[0] = 1;
  outLayers->size[1] = layersDetails->size[0];
  emxEnsureCapacity_cell_wrap_14(sp, outLayers, i, &cg_emlrtRTEI);
  i = layersDetails->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    i1 = layersDetails->size[0] - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ef_emlrtBCI, sp);
    }

    i1 = layersDetails->data[b_i].f1->size[1];
    n = 1;
    for (b_n = 0; b_n <= i1 - 2; b_n++) {
      n = b_n + 1;
      i2 = b_n + 1;
      if ((i2 < 1) || (i2 > layersDetails->data[b_i].f1->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, layersDetails->data[b_i].f1->size[1],
          &df_emlrtBCI, sp);
      }

      if (!muDoubleScalarIsNaN(layersDetails->data[b_i].f1->data[b_n])) {
        if (layersDetails->data[b_i].f1->data[b_n] != (int32_T)
            muDoubleScalarFloor(layersDetails->data[b_i].f1->data[b_n])) {
          emlrtIntegerCheckR2012b(layersDetails->data[b_i].f1->data[b_n],
            &r_emlrtDCI, sp);
        }

        i2 = (int32_T)layersDetails->data[b_i].f1->data[b_n];
        if ((i2 < 1) || (i2 > params->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, params->size[1], &hf_emlrtBCI, sp);
        }

        thisOutLayer[b_n] = params->data[i2 - 1];
      } else {
        thisOutLayer[b_n] = rtNaN;
      }
    }

    if (layersDetails->data[b_i].f1->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(layersDetails->data[b_i].f1->size[1], 1,
        layersDetails->data[b_i].f1->size[1], &ff_emlrtBCI, sp);
    }

    thisOutLayer[n] = layersDetails->data[b_i].f1->data[layersDetails->data[b_i]
      .f1->size[1] - 1];
    i1 = outLayers->size[1] - 1;
    for (i2 = 0; i2 < 5; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &gf_emlrtBCI, sp);
      }

      outLayers->data[b_i].f1[i2] = thisOutLayer[i2];
    }
  }
}

/* End of code generation (allocateParamsToLayers.c) */
