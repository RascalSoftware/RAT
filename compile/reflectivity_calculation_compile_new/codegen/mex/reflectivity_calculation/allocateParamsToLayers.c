/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
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
static emlrtBCInfo xe_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    17,                       /* lineNo */
    29,                       /* colNo */
    "thisLayer",              /* aName */
    "allocateParamsToLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    15,                       /* lineNo */
    31,                       /* colNo */
    "layersDetails",          /* aName */
    "allocateParamsToLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = {
    1,                        /* iFirst */
    5,                        /* iLast */
    21,                       /* lineNo */
    26,                       /* colNo */
    "thisOutLayer",           /* aName */
    "allocateParamsToLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    3                           /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    19,                       /* lineNo */
    38,                       /* colNo */
    "params",                 /* aName */
    "allocateParamsToLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    0                           /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = {
    19,                       /* lineNo */
    38,                       /* colNo */
    "allocateParamsToLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    1                           /* checkKind */
};

static emlrtBCInfo cf_emlrtBCI = {
    1,                        /* iFirst */
    5,                        /* iLast */
    19,                       /* lineNo */
    26,                       /* colNo */
    "thisOutLayer",           /* aName */
    "allocateParamsToLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    3                           /* checkKind */
};

static emlrtBCInfo df_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    24,                       /* lineNo */
    49,                       /* colNo */
    "thisLayer",              /* aName */
    "allocateParamsToLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    0                           /* checkKind */
};

static emlrtBCInfo ef_emlrtBCI = {
    1,                        /* iFirst */
    5,                        /* iLast */
    24,                       /* lineNo */
    18,                       /* colNo */
    "thisOutLayer",           /* aName */
    "allocateParamsToLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    3                           /* checkKind */
};

static emlrtBCInfo ff_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    25,                       /* lineNo */
    5,                        /* colNo */
    "outLayers",              /* aName */
    "allocateParamsToLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m", /* pName */
    0                           /* checkKind */
};

static emlrtRTEInfo fh_emlrtRTEI = {
    12,                       /* lineNo */
    20,                       /* colNo */
    "allocateParamsToLayers", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "allocateParamsToLayers.m" /* pName */
};

/* Function Definitions */
void allocateParamsToLayers(const emlrtStack *sp, const emxArray_real_T *params,
                            const emxArray_cell_wrap_14 *layersDetails,
                            emxArray_cell_wrap_17 *outLayers)
{
  const cell_wrap_14 *layersDetails_data;
  cell_wrap_17 *outLayers_data;
  real_T thisOutLayer[5];
  const real_T *params_data;
  real_T d;
  int32_T b_i;
  int32_T b_n;
  int32_T i;
  int32_T i1;
  int32_T n;
  layersDetails_data = layersDetails->data;
  params_data = params->data;
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
  emxEnsureCapacity_cell_wrap_17(sp, outLayers, i, &fh_emlrtRTEI);
  outLayers_data = outLayers->data;
  i = layersDetails->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i > layersDetails->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, layersDetails->size[0] - 1,
                                    &ye_emlrtBCI, (emlrtCTX)sp);
    }
    if ((layersDetails_data[b_i].f1->size[0] == 0) ||
        (layersDetails_data[b_i].f1->size[1] == 0)) {
      n = 0;
    } else {
      n = muIntScalarMax_sint32(layersDetails_data[b_i].f1->size[0],
                                layersDetails_data[b_i].f1->size[1]);
    }
    for (b_n = 0; b_n <= n - 2; b_n++) {
      i1 = layersDetails_data[b_i].f1->size[0] *
           layersDetails_data[b_i].f1->size[1];
      if (b_n + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, i1, &xe_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (!muDoubleScalarIsNaN(layersDetails_data[b_i].f1->data[b_n])) {
        d = layersDetails_data[b_i].f1->data[b_n];
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &u_emlrtDCI, (emlrtCTX)sp);
        }
        if (((int32_T)d < 1) || ((int32_T)d > params->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, params->size[1],
                                        &bf_emlrtBCI, (emlrtCTX)sp);
        }
        if (b_n + 1 > 5) {
          emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, 5, &cf_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        thisOutLayer[b_n] = params_data[(int32_T)d - 1];
      } else {
        if (b_n + 1 > 5) {
          emlrtDynamicBoundsCheckR2012b(b_n + 1, 1, 5, &af_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        thisOutLayer[b_n] = rtNaN;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if ((layersDetails_data[b_i].f1->size[0] == 0) ||
        (layersDetails_data[b_i].f1->size[1] == 0)) {
      n = 0;
    } else {
      n = muIntScalarMax_sint32(layersDetails_data[b_i].f1->size[0],
                                layersDetails_data[b_i].f1->size[1]);
    }
    i1 = layersDetails_data[b_i].f1->size[0] *
         layersDetails_data[b_i].f1->size[1];
    b_n = layersDetails_data[b_i].f1->size[0] *
          layersDetails_data[b_i].f1->size[1];
    if ((b_n < 1) || (b_n > i1)) {
      emlrtDynamicBoundsCheckR2012b(b_n, 1, i1, &df_emlrtBCI, (emlrtCTX)sp);
    }
    if ((n < 1) || (n > 5)) {
      emlrtDynamicBoundsCheckR2012b(n, 1, 5, &ef_emlrtBCI, (emlrtCTX)sp);
    }
    thisOutLayer[n - 1] = layersDetails_data[b_i].f1->data[b_n - 1];
    b_n = outLayers->size[1] - 1;
    for (i1 = 0; i1 < 5; i1++) {
      if (b_i > b_n) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, b_n, &ff_emlrtBCI, (emlrtCTX)sp);
      }
      outLayers_data[b_i].f1[i1] = thisOutLayer[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
}

/* End of code generation (allocateParamsToLayers.c) */
