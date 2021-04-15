/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * call_StandardLayers.c
 *
 * Code generation for function 'call_StandardLayers'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_stanlay_single.h"
#include "call_StandardLayers.h"
#include "standardTF_stanlay_single_emxutil.h"
#include "standardTF_stanlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo i_emlrtRSI = { 4,   /* lineNo */
  "call_StandardLayers",               /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/call_StandardLayers.m"/* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = { 1, /* lineNo */
  32,                                  /* colNo */
  "call_StandardLayers",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_single/call_StandardLayers.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 8, /* lineNo */
  5,                                   /* colNo */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m"/* pName */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  17,                                  /* colNo */
  "params",                            /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo cc_emlrtRTEI = { 9,/* lineNo */
  13,                                  /* colNo */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m"/* pName */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  24,                                  /* colNo */
  "thisLayer",                         /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  21,                                  /* colNo */
  "thisLayer",                         /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  23,                                  /* colNo */
  "contrastLayers",                    /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 32,  /* lineNo */
  44,                                  /* colNo */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  44,                                  /* colNo */
  "layersValues",                      /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  13,                                  /* colNo */
  "params",                            /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  24,                                  /* colNo */
  "layersList",                        /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  32,                                  /* lineNo */
  13,                                  /* colNo */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m"/* pName */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  21,                                  /* colNo */
  "layersDetails",                     /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 8,   /* lineNo */
  26,                                  /* colNo */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 8,  /* lineNo */
  26,                                  /* colNo */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  26,                                  /* colNo */
  "layersValues",                      /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  30,                                  /* colNo */
  "layersValues",                      /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  37,                                  /* colNo */
  "params",                            /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  30,                                  /* colNo */
  "layersValues",                      /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void call_StandardLayers(const emlrtStack *sp, const emxArray_real_T *params,
  const emxArray_real_T *contrastLayers, real_T numberOfLayers, const
  emxArray_cell_wrap_0 *layersDetails, emxArray_real_T *layersList, real_T
  *sRough)
{
  boolean_T b0;
  emxArray_real_T *layersValues;
  int32_T i2;
  int32_T loop_ub;
  int32_T n;
  int32_T m;
  real_T d0;
  int32_T i3;
  int32_T iv2[2];
  int32_T iv3[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  b0 = false;
  st.site = &i_emlrtRSI;
  if (numberOfLayers == 0.0) {
    i2 = params->size[1];
    if (!(1 <= i2)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i2, &dc_emlrtBCI, &st);
    }

    i2 = layersList->size[0] * layersList->size[1];
    layersList->size[0] = 0;
    layersList->size[1] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)layersList, i2, (int32_T)sizeof
                      (real_T), &h_emlrtRTEI);
  } else {
    emxInit_real_T(&st, &layersValues, 2, &i_emlrtRTEI, true);
    i2 = layersValues->size[0] * layersValues->size[1];
    if (!(numberOfLayers >= 0.0)) {
      emlrtNonNegativeCheckR2012b(numberOfLayers, &ab_emlrtDCI, &st);
    }

    if (numberOfLayers != (int32_T)muDoubleScalarFloor(numberOfLayers)) {
      emlrtIntegerCheckR2012b(numberOfLayers, &y_emlrtDCI, &st);
    }

    layersValues->size[0] = (int32_T)numberOfLayers;
    layersValues->size[1] = 5;
    emxEnsureCapacity(&st, (emxArray__common *)layersValues, i2, (int32_T)sizeof
                      (real_T), &h_emlrtRTEI);
    if (!(numberOfLayers >= 0.0)) {
      emlrtNonNegativeCheckR2012b(numberOfLayers, &ab_emlrtDCI, &st);
    }

    if (numberOfLayers != (int32_T)muDoubleScalarFloor(numberOfLayers)) {
      emlrtIntegerCheckR2012b(numberOfLayers, &y_emlrtDCI, &st);
    }

    loop_ub = (int32_T)numberOfLayers * 5;
    for (i2 = 0; i2 < loop_ub; i2++) {
      layersValues->data[i2] = 0.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfLayers, mxDOUBLE_CLASS,
      (int32_T)numberOfLayers, &cc_emlrtRTEI, &st);
    n = 0;
    while (n <= (int32_T)numberOfLayers - 1) {
      i2 = layersDetails->size[1] - 1;
      if (!((n >= 0) && (n <= i2))) {
        emlrtDynamicBoundsCheckR2012b(n, 0, i2, &kc_emlrtBCI, &st);
      }

      m = 0;
      while (m < 4) {
        i2 = layersDetails->data[layersDetails->size[0] * n].f1->size[1];
        loop_ub = 1 + m;
        if (!(loop_ub <= i2)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &ec_emlrtBCI, &st);
        }

        if (!muDoubleScalarIsNaN(layersDetails->data[layersDetails->size[0] * n]
             .f1->data[m])) {
          i2 = params->size[1];
          d0 = layersDetails->data[layersDetails->size[0] * n].f1->data[m];
          if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
            emlrtIntegerCheckR2012b(d0, &bb_emlrtDCI, &st);
          }

          loop_ub = (int32_T)d0;
          if (!((loop_ub >= 1) && (loop_ub <= i2))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &nc_emlrtBCI, &st);
          }

          i2 = layersValues->size[0];
          i3 = 1 + n;
          if (!((i3 >= 1) && (i3 <= i2))) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &oc_emlrtBCI, &st);
          }

          layersValues->data[(i3 + layersValues->size[0] * m) - 1] =
            params->data[loop_ub - 1];
        } else {
          i2 = layersValues->size[0];
          loop_ub = 1 + n;
          if (!((loop_ub >= 1) && (loop_ub <= i2))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &mc_emlrtBCI, &st);
          }

          layersValues->data[(loop_ub + layersValues->size[0] * m) - 1] = rtNaN;
        }

        m++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      i2 = layersDetails->data[layersDetails->size[0] * n].f1->size[1];
      if (!(5 <= i2)) {
        emlrtDynamicBoundsCheckR2012b(5, 1, i2, &fc_emlrtBCI, &st);
      }

      i2 = layersValues->size[0];
      loop_ub = 1 + n;
      if (!((loop_ub >= 1) && (loop_ub <= i2))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &lc_emlrtBCI, &st);
      }

      layersValues->data[(loop_ub + (layersValues->size[0] << 2)) - 1] =
        (layersDetails->data[layersDetails->size[0] * n].f1->data[4] == 2.0);
      n++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    if (!(contrastLayers->size[1] == 0)) {
      i2 = layersList->size[0] * layersList->size[1];
      layersList->size[0] = contrastLayers->size[1];
      layersList->size[1] = 5;
      emxEnsureCapacity(&st, (emxArray__common *)layersList, i2, (int32_T)sizeof
                        (real_T), &h_emlrtRTEI);
      loop_ub = contrastLayers->size[1] * 5;
      for (i2 = 0; i2 < loop_ub; i2++) {
        layersList->data[i2] = 0.0;
      }

      n = 0;
      while (n <= contrastLayers->size[1] - 1) {
        i2 = contrastLayers->size[1];
        loop_ub = n + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i2))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &gc_emlrtBCI, &st);
        }

        i2 = layersList->size[0];
        loop_ub = n + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i2))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &jc_emlrtBCI, &st);
        }

        if (!b0) {
          for (i2 = 0; i2 < 2; i2++) {
            iv2[i2] = 1 + (i2 << 2);
            iv3[i2] = 1 + (i2 << 2);
          }

          b0 = true;
        }

        emlrtSubAssignSizeCheckR2012b(iv2, 2, iv3, 2, &d_emlrtECI, &st);
        d0 = contrastLayers->data[n];
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &x_emlrtDCI, &st);
        }

        i2 = layersValues->size[0];
        loop_ub = (int32_T)d0;
        if (!((loop_ub >= 1) && (loop_ub <= i2))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &hc_emlrtBCI, &st);
        }

        for (i2 = 0; i2 < 5; i2++) {
          layersList->data[n + layersList->size[0] * i2] = layersValues->data
            [(loop_ub + layersValues->size[0] * i2) - 1];
        }

        n++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
    } else {
      i2 = layersList->size[0] * layersList->size[1];
      layersList->size[0] = 0;
      layersList->size[1] = 0;
      emxEnsureCapacity(&st, (emxArray__common *)layersList, i2, (int32_T)sizeof
                        (real_T), &h_emlrtRTEI);
    }

    emxFree_real_T(&layersValues);
  }

  i2 = params->size[1];
  if (!(1 <= i2)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i2, &ic_emlrtBCI, &st);
  }

  *sRough = params->data[0];
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (call_StandardLayers.c) */
