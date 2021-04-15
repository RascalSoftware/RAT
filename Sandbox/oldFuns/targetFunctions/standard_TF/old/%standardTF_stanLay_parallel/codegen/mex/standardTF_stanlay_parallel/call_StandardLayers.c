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
#include "standardTF_stanlay_parallel.h"
#include "call_StandardLayers.h"
#include "standardTF_stanlay_parallel_emxutil.h"
#include "standardTF_stanlay_parallel_data.h"

/* Variable Definitions */
static emlrtRSInfo i_emlrtRSI = { 4,   /* lineNo */
  "call_StandardLayers",               /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_parallel/call_StandardLayers.m"/* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = { 1, /* lineNo */
  32,                                  /* colNo */
  "call_StandardLayers",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_parallel/call_StandardLayers.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 8, /* lineNo */
  5,                                   /* colNo */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m"/* pName */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  5,                                   /* lineNo */
  17,                                  /* colNo */
  "params",                            /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo dc_emlrtRTEI = { 9,/* lineNo */
  13,                                  /* colNo */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m"/* pName */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  24,                                  /* colNo */
  "thisLayer",                         /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  21,                                  /* colNo */
  "thisLayer",                         /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  44,                                  /* colNo */
  "layersValues",                      /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  13,                                  /* colNo */
  "params",                            /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  24,                                  /* colNo */
  "layersList",                        /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  32,                                  /* lineNo */
  13,                                  /* colNo */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m"/* pName */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  26,                                  /* colNo */
  "layersValues",                      /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  30,                                  /* colNo */
  "layersValues",                      /* aName */
  "standard_layers_mod",               /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/standard_layers_mod/standard_layers_mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
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

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
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
  emxArray_cell_wrap_2 *layersDetails, emxArray_real_T *layersList, real_T
  *sRough)
{
  boolean_T b0;
  emxArray_real_T *layersValues;
  int32_T i6;
  int32_T loop_ub;
  int32_T n;
  int32_T m;
  real_T d6;
  int32_T i7;
  int32_T iv0[2];
  int32_T iv1[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  b0 = false;
  st.site = &i_emlrtRSI;
  if (numberOfLayers == 0.0) {
    i6 = params->size[1];
    if (!(1 <= i6)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i6, &yb_emlrtBCI, &st);
    }

    i6 = layersList->size[0] * layersList->size[1];
    layersList->size[0] = 0;
    layersList->size[1] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)layersList, i6, (int32_T)sizeof
                      (real_T), &f_emlrtRTEI);
  } else {
    emxInit_real_T(&st, &layersValues, 2, &g_emlrtRTEI, true);
    i6 = layersValues->size[0] * layersValues->size[1];
    if (!(numberOfLayers >= 0.0)) {
      emlrtNonNegativeCheckR2012b(numberOfLayers, &ab_emlrtDCI, &st);
    }

    if (numberOfLayers != (int32_T)muDoubleScalarFloor(numberOfLayers)) {
      emlrtIntegerCheckR2012b(numberOfLayers, &y_emlrtDCI, &st);
    }

    layersValues->size[0] = (int32_T)numberOfLayers;
    layersValues->size[1] = 5;
    emxEnsureCapacity(&st, (emxArray__common *)layersValues, i6, (int32_T)sizeof
                      (real_T), &f_emlrtRTEI);
    if (!(numberOfLayers >= 0.0)) {
      emlrtNonNegativeCheckR2012b(numberOfLayers, &ab_emlrtDCI, &st);
    }

    if (numberOfLayers != (int32_T)muDoubleScalarFloor(numberOfLayers)) {
      emlrtIntegerCheckR2012b(numberOfLayers, &y_emlrtDCI, &st);
    }

    loop_ub = (int32_T)numberOfLayers * 5;
    for (i6 = 0; i6 < loop_ub; i6++) {
      layersValues->data[i6] = 0.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, numberOfLayers, mxDOUBLE_CLASS,
      (int32_T)numberOfLayers, &dc_emlrtRTEI, &st);
    n = 0;
    while (n <= (int32_T)numberOfLayers - 1) {
      i6 = layersDetails->size[1] - 1;
      if (!((n >= 0) && (n <= i6))) {
        emlrtDynamicBoundsCheckR2012b(n, 0, i6, &gc_emlrtBCI, &st);
      }

      m = 0;
      while (m < 4) {
        i6 = layersDetails->data[layersDetails->size[0] * n].f1->size[1];
        loop_ub = 1 + m;
        if (!(loop_ub <= i6)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, &ac_emlrtBCI, &st);
        }

        if (!muDoubleScalarIsNaN(layersDetails->data[layersDetails->size[0] * n]
             .f1->data[m])) {
          i6 = params->size[1];
          d6 = layersDetails->data[layersDetails->size[0] * n].f1->data[m];
          if (d6 != (int32_T)muDoubleScalarFloor(d6)) {
            emlrtIntegerCheckR2012b(d6, &bb_emlrtDCI, &st);
          }

          loop_ub = (int32_T)d6;
          if (!((loop_ub >= 1) && (loop_ub <= i6))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, &jc_emlrtBCI, &st);
          }

          i6 = layersValues->size[0];
          i7 = 1 + n;
          if (!((i7 >= 1) && (i7 <= i6))) {
            emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &kc_emlrtBCI, &st);
          }

          layersValues->data[(i7 + layersValues->size[0] * m) - 1] =
            params->data[loop_ub - 1];
        } else {
          i6 = layersValues->size[0];
          loop_ub = 1 + n;
          if (!((loop_ub >= 1) && (loop_ub <= i6))) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, &ic_emlrtBCI, &st);
          }

          layersValues->data[(loop_ub + layersValues->size[0] * m) - 1] = rtNaN;
        }

        m++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      i6 = layersDetails->data[layersDetails->size[0] * n].f1->size[1];
      if (!(5 <= i6)) {
        emlrtDynamicBoundsCheckR2012b(5, 1, i6, &bc_emlrtBCI, &st);
      }

      i6 = layersValues->size[0];
      loop_ub = 1 + n;
      if (!((loop_ub >= 1) && (loop_ub <= i6))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, &hc_emlrtBCI, &st);
      }

      layersValues->data[(loop_ub + (layersValues->size[0] << 2)) - 1] =
        (layersDetails->data[layersDetails->size[0] * n].f1->data[4] == 2.0);
      n++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    if (!(contrastLayers->size[1] == 0)) {
      i6 = layersList->size[0] * layersList->size[1];
      layersList->size[0] = contrastLayers->size[1];
      layersList->size[1] = 5;
      emxEnsureCapacity(&st, (emxArray__common *)layersList, i6, (int32_T)sizeof
                        (real_T), &f_emlrtRTEI);
      loop_ub = contrastLayers->size[1] * 5;
      for (i6 = 0; i6 < loop_ub; i6++) {
        layersList->data[i6] = 0.0;
      }

      n = 0;
      while (n <= contrastLayers->size[1] - 1) {
        i6 = contrastLayers->size[1];
        loop_ub = n + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i6))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, &cc_emlrtBCI, &st);
        }

        i6 = layersList->size[0];
        loop_ub = n + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i6))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, &fc_emlrtBCI, &st);
        }

        if (!b0) {
          for (i6 = 0; i6 < 2; i6++) {
            iv0[i6] = 1 + (i6 << 2);
            iv1[i6] = 1 + (i6 << 2);
          }

          b0 = true;
        }

        emlrtSubAssignSizeCheckR2012b(iv0, 2, iv1, 2, &emlrtECI, &st);
        d6 = contrastLayers->data[n];
        if (d6 != (int32_T)muDoubleScalarFloor(d6)) {
          emlrtIntegerCheckR2012b(d6, &x_emlrtDCI, &st);
        }

        i6 = layersValues->size[0];
        loop_ub = (int32_T)d6;
        if (!((loop_ub >= 1) && (loop_ub <= i6))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, &dc_emlrtBCI, &st);
        }

        for (i6 = 0; i6 < 5; i6++) {
          layersList->data[n + layersList->size[0] * i6] = layersValues->data
            [(loop_ub + layersValues->size[0] * i6) - 1];
        }

        n++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
    } else {
      i6 = layersList->size[0] * layersList->size[1];
      layersList->size[0] = 0;
      layersList->size[1] = 0;
      emxEnsureCapacity(&st, (emxArray__common *)layersList, i6, (int32_T)sizeof
                        (real_T), &f_emlrtRTEI);
    }

    emxFree_real_T(&layersValues);
  }

  i6 = params->size[1];
  if (!(1 <= i6)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i6, &ec_emlrtBCI, &st);
  }

  *sRough = params->data[0];
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (call_StandardLayers.c) */
