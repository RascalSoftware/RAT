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
static emlrtBCInfo ef_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    17,                       /* lineNo */
    29,                       /* colNo */
    "thisLayer",              /* aName */
    "allocateParamsToLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo ff_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    15,                       /* lineNo */
    31,                       /* colNo */
    "layersDetails",          /* aName */
    "allocateParamsToLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo gf_emlrtBCI = {
    1,                        /* iFirst */
    5,                        /* iLast */
    21,                       /* lineNo */
    13,                       /* colNo */
    "thisOutLayer",           /* aName */
    "allocateParamsToLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    3                           /* checkKind */
};

static emlrtBCInfo hf_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    19,                       /* lineNo */
    31,                       /* colNo */
    "params",                 /* aName */
    "allocateParamsToLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    0                           /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = {
    19,                       /* lineNo */
    31,                       /* colNo */
    "allocateParamsToLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    1                           /* checkKind */
};

static emlrtBCInfo if_emlrtBCI = {
    1,                        /* iFirst */
    5,                        /* iLast */
    19,                       /* lineNo */
    13,                       /* colNo */
    "thisOutLayer",           /* aName */
    "allocateParamsToLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    3                           /* checkKind */
};

static emlrtBCInfo jf_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    24,                       /* lineNo */
    39,                       /* colNo */
    "thisLayer",              /* aName */
    "allocateParamsToLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo kf_emlrtBCI = {
    1,                        /* iFirst */
    5,                        /* iLast */
    24,                       /* lineNo */
    5,                        /* colNo */
    "thisOutLayer",           /* aName */
    "allocateParamsToLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    3                           /* checkKind */
};

static emlrtBCInfo lf_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    25,                       /* lineNo */
    5,                        /* colNo */
    "outLayers",              /* aName */
    "allocateParamsToLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    0                           /* checkKind */
};

static emlrtRTEInfo eh_emlrtRTEI = {
    12,                       /* lineNo */
    20,                       /* colNo */
    "allocateParamsToLayers", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m" /* pName */
};

/* Function Definitions */
void allocateParamsToLayers(const emlrtStack *sp, const emxArray_real_T *params,
                            const emxArray_cell_wrap_14 *layersDetails,
                            emxArray_cell_wrap_17 *outLayers)
{
  real_T thisOutLayer[5];
  real_T d;
  int32_T b_i;
  int32_T b_n;
  int32_T i;
  int32_T i1;
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
  emxEnsureCapacity_cell_wrap_17(sp, outLayers, i, &eh_emlrtRTEI);
  i = layersDetails->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i > layersDetails->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layersDetails->size[0] - 1,
                                    &ff_emlrtBCI, (emlrtCTX)sp);
    }
    if ((layersDetails->data[b_i].f1->size[0] == 0) ||
        (layersDetails->data[b_i].f1->size[1] == 0)) {
      n = 0;
    } else if (layersDetails->data[b_i].f1->size[0] >
               layersDetails->data[b_i].f1->size[1]) {
      n = layersDetails->data[b_i].f1->size[0];
    } else {
      n = layersDetails->data[b_i].f1->size[1];
    }
    for (b_n = 0; b_n <= n - 2; b_n++) {
      i1 = layersDetails->data[b_i].f1->size[0] *
           layersDetails->data[b_i].f1->size[1];
      if (b_n + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, i1, &ef_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (!muDoubleScalarIsNaN(layersDetails->data[b_i].f1->data[b_n])) {
        d = layersDetails->data[b_i].f1->data[b_n];
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &u_emlrtDCI, (emlrtCTX)sp);
        }
        if (((int32_T)d < 1) || ((int32_T)d > params->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, params->size[1],
                                        &hf_emlrtBCI, (emlrtCTX)sp);
        }
        if (b_n + 1 > 5) {
          emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, 5, &if_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        thisOutLayer[b_n] = params->data[(int32_T)d - 1];
      } else {
        if (b_n + 1 > 5) {
          emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, 5, &gf_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        thisOutLayer[b_n] = rtNaN;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if ((layersDetails->data[b_i].f1->size[0] == 0) ||
        (layersDetails->data[b_i].f1->size[1] == 0)) {
      n = 0;
    } else if (layersDetails->data[b_i].f1->size[0] >
               layersDetails->data[b_i].f1->size[1]) {
      n = layersDetails->data[b_i].f1->size[0];
    } else {
      n = layersDetails->data[b_i].f1->size[1];
    }
    i1 = layersDetails->data[b_i].f1->size[0] *
         layersDetails->data[b_i].f1->size[1];
    b_n = layersDetails->data[b_i].f1->size[0] *
          layersDetails->data[b_i].f1->size[1];
    if ((b_n < 1) || (b_n > i1)) {
      emlrtDynamicBoundsCheckR2012b(b_n, 1, i1, &jf_emlrtBCI, (emlrtCTX)sp);
    }
    if ((n < 1) || (n > 5)) {
      emlrtDynamicBoundsCheckR2012b(n, 1, 5, &kf_emlrtBCI, (emlrtCTX)sp);
    }
    thisOutLayer[n - 1] = layersDetails->data[b_i].f1->data[b_n - 1];
    b_n = outLayers->size[1] - 1;
    for (i1 = 0; i1 < 5; i1++) {
      if (b_i > b_n) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_n, &lf_emlrtBCI, (emlrtCTX)sp);
      }
      outLayers->data[b_i].f1[i1] = thisOutLayer[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
}

/* End of code generation (allocateParamsToLayers.c) */
