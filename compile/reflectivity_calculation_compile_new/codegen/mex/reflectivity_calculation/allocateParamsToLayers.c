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
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  29,                                  /* colNo */
  "thisLayer",                         /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  31,                                  /* colNo */
  "layersDetails",                     /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { 1,  /* iFirst */
  5,                                   /* iLast */
  21,                                  /* lineNo */
  13,                                  /* colNo */
  "thisOutLayer",                      /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  31,                                  /* colNo */
  "params",                            /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 19,  /* lineNo */
  31,                                  /* colNo */
  "allocateParamsToLayers",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { 1,  /* iFirst */
  5,                                   /* iLast */
  19,                                  /* lineNo */
  13,                                  /* colNo */
  "thisOutLayer",                      /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  39,                                  /* colNo */
  "thisLayer",                         /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { 1,  /* iFirst */
  5,                                   /* iLast */
  24,                                  /* lineNo */
  5,                                   /* colNo */
  "thisOutLayer",                      /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  5,                                   /* colNo */
  "outLayers",                         /* aName */
  "allocateParamsToLayers",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo gh_emlrtRTEI = { 12,/* lineNo */
  20,                                  /* colNo */
  "allocateParamsToLayers",            /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/allocateParamsToLayers.m"/* pName */
};

/* Function Definitions */
void allocateParamsToLayers(const emlrtStack *sp, const emxArray_real_T *params,
  const emxArray_cell_wrap_14 *layersDetails, emxArray_cell_wrap_17 *outLayers)
{
  real_T thisOutLayer[5];
  real_T d;
  int32_T b_i;
  int32_T b_n;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T n;

  /*  Allocates parameters from the parameter array to the correct layers */
  /*  */
  /*  This function takes the list of all layers in 'layersDetails',  */
  /*  then loops over all the layers, putting in the correct */
  /*  parameter value from the parameters array into each layer in */
  /*  the 'outLayers' cell array */
  for (i = 0; i < 5; i++) {
    thisOutLayer[i] = 0.0;
  }

  i = outLayers->size[0] * outLayers->size[1];
  outLayers->size[0] = 1;
  outLayers->size[1] = layersDetails->size[0];
  emxEnsureCapacity_cell_wrap_17(sp, outLayers, i, &gh_emlrtRTEI);
  i = layersDetails->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i > layersDetails->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layersDetails->size[0] - 1,
        &ae_emlrtBCI, sp);
    }

    if ((layersDetails->data[b_i].f1->size[0] == 0) || (layersDetails->data[b_i]
         .f1->size[1] == 0)) {
      n = 0;
    } else if (layersDetails->data[b_i].f1->size[0] > layersDetails->data[b_i].
               f1->size[1]) {
      n = layersDetails->data[b_i].f1->size[0];
    } else {
      n = layersDetails->data[b_i].f1->size[1];
    }

    for (b_n = 0; b_n <= n - 2; b_n++) {
      i1 = layersDetails->data[b_i].f1->size[0] * layersDetails->data[b_i]
        .f1->size[1];
      i2 = b_n + 1;
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &yd_emlrtBCI, sp);
      }

      if (!muDoubleScalarIsNaN(layersDetails->data[b_i].f1->data[b_n])) {
        d = layersDetails->data[b_i].f1->data[b_n];
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &t_emlrtDCI, sp);
        }

        if (((int32_T)d < 1) || ((int32_T)d > params->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, params->size[1],
            &ce_emlrtBCI, sp);
        }

        if ((b_n + 1 < 1) || (b_n + 1 > 5)) {
          emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, 5, &de_emlrtBCI, sp);
        }

        thisOutLayer[b_n] = params->data[(int32_T)d - 1];
      } else {
        if ((b_n + 1 < 1) || (b_n + 1 > 5)) {
          emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, 5, &be_emlrtBCI, sp);
        }

        thisOutLayer[b_n] = rtNaN;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if ((layersDetails->data[b_i].f1->size[0] == 0) || (layersDetails->data[b_i]
         .f1->size[1] == 0)) {
      n = 0;
    } else if (layersDetails->data[b_i].f1->size[0] > layersDetails->data[b_i].
               f1->size[1]) {
      n = layersDetails->data[b_i].f1->size[0];
    } else {
      n = layersDetails->data[b_i].f1->size[1];
    }

    i1 = layersDetails->data[b_i].f1->size[0] * layersDetails->data[b_i]
      .f1->size[1];
    i2 = layersDetails->data[b_i].f1->size[0] * layersDetails->data[b_i]
      .f1->size[1];
    if ((i2 < 1) || (i2 > i1)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &ee_emlrtBCI, sp);
    }

    if ((n < 1) || (n > 5)) {
      emlrtDynamicBoundsCheckR2012b(n, 1, 5, &fe_emlrtBCI, sp);
    }

    thisOutLayer[n - 1] = layersDetails->data[b_i].f1->data[i2 - 1];
    n = outLayers->size[1] - 1;
    for (i1 = 0; i1 < 5; i1++) {
      if (b_i > n) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, n, &ge_emlrtBCI, sp);
      }

      outLayers->data[b_i].f1[i1] = thisOutLayer[i1];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (allocateParamsToLayers.c) */
