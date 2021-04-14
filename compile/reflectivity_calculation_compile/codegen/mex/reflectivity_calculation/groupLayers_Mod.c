/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * groupLayers_Mod.c
 *
 * Code generation for function 'groupLayers_Mod'
 *
 */

/* Include files */
#include "groupLayers_Mod.h"
#include "indexShapeCheck.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "strcmp.h"

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = { 48,  /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 56,  /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 60,  /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo oh_emlrtRSI = { 62, /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  44,                                  /* colNo */
  "roughs",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  24,                                  /* colNo */
  "roughs",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  28,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  20,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  78,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  21,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ah_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = { 49,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = { 89,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = { 87,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo eh_emlrtRTEI = { 56,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo fh_emlrtRTEI = { 60,/* lineNo */
  21,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo gh_emlrtRTEI = { 52,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo bn_emlrtRTEI = { 62,/* lineNo */
  21,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

/* Function Definitions */
void b_groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
  real_T allRoughs, const emxArray_char_T *geometry, emxArray_real_T *outLayers,
  real_T *outSsubs)
{
  emxArray_real_T *layers;
  int32_T i;
  int32_T loop_ub;
  emxArray_real_T *roughs;
  int32_T iv[2];
  int32_T b_loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 10U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 0U);

  /* Arrange layers according to geometry and apply any coverage correction. */
  /*  */
  /* [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs) */
  /*  Inputs: */
  /*      allLayers = cell array, one for each contrast. Each cell is the  */
  /*                  list of layer values for each contrast. */
  /*                  e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which */
  /*                                       d2, rho2, r2, %hyd2, hyd_which_2.. */
  /*                                       etc] */
  /*      allRoughs = Double of substrate roughness for each contrast. */
  /*      numberOfContrasts = double. */
  /*      geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid' */
  /*      nbairs = vector of nbair values. */
  /*      nbsubs = vector of nbsub values. */
  /*  */
  /*      The paratt calculation procedds through the  */
  /*      z,rho,rough stack, and the parameter 'ssub' in */
  /*      callParatt is the final roughness encountered.  */
  /*      For air liquid 'ssub' is therefore the substrate roughness. */
  /*      For solid liquid, the substrate roughness is the first roughness */
  /*      encountered, and 'ssub' is then the roughness of the outermost layer. */
  /*      The rougnesses need to be arranged accordingly. */
  /*  */
  /*  */
  /*  Outputs: */
  /*      outLayers = cell array of layers param values for each contrast. */
  /*                  e.g. outLayers{1} = [d1 rho1 r1; */
  /*                                       d2 rho2 r2 */
  /*                                       ... etc   ] */
  /*      outSsubs = vector of substrate roughness values. */
  /*  */
  /* outLayers = cell(1,numberOfContrasts); */
  /* outSsubs = zeros(1,numberOfContrasts); */
  /* for i = 1:numberOfContrasts */
  *outSsubs = allRoughs;
  covrtLogCond(&emlrtCoverageInstance, 10U, 0U, 0, false);
  covrtLogMcdc(&emlrtCoverageInstance, 10U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 0, true);
  emxInit_real_T(sp, &layers, 2, &ah_emlrtRTEI, true);
  st.site = &v_emlrtRSI;
  if (covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 1, b_strcmp(&st, geometry))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 1U);
    i = layers->size[0] * layers->size[1];
    layers->size[0] = allLayers->size[0];
    layers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layers, i, &bh_emlrtRTEI);
    loop_ub = allLayers->size[0] * allLayers->size[1];
    for (i = 0; i < loop_ub; i++) {
      layers->data[i] = allLayers->data[i];
    }

    /* s_sub = rsub; */
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 2U);
    if (allLayers->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(allLayers->size[0], 1, allLayers->size[0],
        &cd_emlrtBCI, sp);
    }

    *outSsubs = allLayers->data[(allLayers->size[0] + allLayers->size[0] * 2) -
      1];
    if (1 > allLayers->size[0] - 1) {
      loop_ub = 0;
    } else {
      loop_ub = allLayers->size[0] - 1;
      if ((loop_ub < 1) || (loop_ub > allLayers->size[0])) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, allLayers->size[0],
          &bd_emlrtBCI, sp);
      }
    }

    emxInit_real_T(sp, &roughs, 1, &gh_emlrtRTEI, true);
    iv[0] = 1;
    iv[1] = loop_ub;
    st.site = &w_emlrtRSI;
    indexShapeCheck(&st, allLayers->size[0], iv);
    i = roughs->size[0];
    roughs->size[0] = loop_ub + 1;
    emxEnsureCapacity_real_T(sp, roughs, i, &eh_emlrtRTEI);
    roughs->data[0] = allRoughs;
    for (i = 0; i < loop_ub; i++) {
      roughs->data[i + 1] = allLayers->data[i + allLayers->size[0] * 2];
    }

    covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 2, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 4U);
    st.site = &oh_emlrtRSI;
    b_st.site = &hb_emlrtRSI;
    c_st.site = &ib_emlrtRSI;
    if (roughs->size[0] != allLayers->size[0]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    loop_ub = allLayers->size[0];
    b_loop_ub = allLayers->size[0];
    i = layers->size[0] * layers->size[1];
    layers->size[0] = allLayers->size[0];
    layers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layers, i, &bn_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      layers->data[i] = allLayers->data[i];
    }

    for (i = 0; i < b_loop_ub; i++) {
      layers->data[i + layers->size[0]] = allLayers->data[i + allLayers->size[0]];
    }

    loop_ub = roughs->size[0];
    for (i = 0; i < loop_ub; i++) {
      layers->data[i + layers->size[0] * 2] = roughs->data[i];
    }

    emxFree_real_T(&roughs);
    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 5U);
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 6U);

  /* Deal with the %coverage if present */
  covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 3, false);

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  covrtLogCond(&emlrtCoverageInstance, 10U, 0U, 2, false);
  covrtLogMcdc(&emlrtCoverageInstance, 10U, 0U, 2, true);
  covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 6, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 11U);
  loop_ub = layers->size[0];
  i = outLayers->size[0] * outLayers->size[1];
  outLayers->size[0] = layers->size[0];
  outLayers->size[1] = 3;
  emxEnsureCapacity_real_T(sp, outLayers, i, &dh_emlrtRTEI);
  for (i = 0; i < 3; i++) {
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      outLayers->data[b_loop_ub + outLayers->size[0] * i] = layers->
        data[b_loop_ub + layers->size[0] * i];
    }
  }

  emxFree_real_T(&layers);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 13U);

  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
                     real_T allRoughs, const emxArray_char_T *geometry, real_T
                     nbair, real_T nbsubs, emxArray_real_T *outLayers, real_T
                     *outSsubs)
{
  emxArray_real_T *layers;
  uint32_T unnamed_idx_0;
  int32_T i;
  int32_T loop_ub;
  emxArray_real_T *roughs;
  int32_T iv[2];
  int32_T i1;
  int32_T b_loop_ub;
  real_T this_pcw;
  real_T pc_add;
  int32_T c_loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &layers, 2, &ah_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 10U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 0U);

  /* Arrange layers according to geometry and apply any coverage correction. */
  /*  */
  /* [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs) */
  /*  Inputs: */
  /*      allLayers = cell array, one for each contrast. Each cell is the  */
  /*                  list of layer values for each contrast. */
  /*                  e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which */
  /*                                       d2, rho2, r2, %hyd2, hyd_which_2.. */
  /*                                       etc] */
  /*      allRoughs = Double of substrate roughness for each contrast. */
  /*      numberOfContrasts = double. */
  /*      geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid' */
  /*      nbairs = vector of nbair values. */
  /*      nbsubs = vector of nbsub values. */
  /*  */
  /*      The paratt calculation procedds through the  */
  /*      z,rho,rough stack, and the parameter 'ssub' in */
  /*      callParatt is the final roughness encountered.  */
  /*      For air liquid 'ssub' is therefore the substrate roughness. */
  /*      For solid liquid, the substrate roughness is the first roughness */
  /*      encountered, and 'ssub' is then the roughness of the outermost layer. */
  /*      The rougnesses need to be arranged accordingly. */
  /*  */
  /*  */
  /*  Outputs: */
  /*      outLayers = cell array of layers param values for each contrast. */
  /*                  e.g. outLayers{1} = [d1 rho1 r1; */
  /*                                       d2 rho2 r2 */
  /*                                       ... etc   ] */
  /*      outSsubs = vector of substrate roughness values. */
  /*  */
  /* outLayers = cell(1,numberOfContrasts); */
  /* outSsubs = zeros(1,numberOfContrasts); */
  /* for i = 1:numberOfContrasts */
  *outSsubs = allRoughs;
  unnamed_idx_0 = (uint32_T)allLayers->size[0];
  i = layers->size[0] * layers->size[1];
  layers->size[0] = (int32_T)unnamed_idx_0;
  layers->size[1] = 5;
  emxEnsureCapacity_real_T(sp, layers, i, &ah_emlrtRTEI);
  loop_ub = (int32_T)unnamed_idx_0 * 5;
  for (i = 0; i < loop_ub; i++) {
    layers->data[i] = 0.0;
  }

  if (covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 0, covrtLogMcdc
                 (&emlrtCoverageInstance, 10U, 0U, 0, !covrtLogCond
                  (&emlrtCoverageInstance, 10U, 0U, 0, allLayers->size[0] == 0))))
  {
    st.site = &v_emlrtRSI;
    if (covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 1, b_strcmp(&st, geometry)))
    {
      covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 1U);
      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = 5;
      emxEnsureCapacity_real_T(sp, layers, i, &bh_emlrtRTEI);
      loop_ub = allLayers->size[0] * allLayers->size[1];
      for (i = 0; i < loop_ub; i++) {
        layers->data[i] = allLayers->data[i];
      }

      /* s_sub = rsub; */
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 2U);
      if (allLayers->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(allLayers->size[0], 1, allLayers->size[0],
          &cd_emlrtBCI, sp);
      }

      *outSsubs = allLayers->data[(allLayers->size[0] + allLayers->size[0] * 2)
        - 1];
      if (1 > allLayers->size[0] - 1) {
        loop_ub = 0;
      } else {
        loop_ub = allLayers->size[0] - 1;
        if ((loop_ub < 1) || (loop_ub > allLayers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, allLayers->size[0],
            &bd_emlrtBCI, sp);
        }
      }

      emxInit_real_T(sp, &roughs, 1, &gh_emlrtRTEI, true);
      iv[0] = 1;
      iv[1] = loop_ub;
      st.site = &w_emlrtRSI;
      indexShapeCheck(&st, allLayers->size[0], iv);
      i = roughs->size[0];
      roughs->size[0] = loop_ub + 1;
      emxEnsureCapacity_real_T(sp, roughs, i, &eh_emlrtRTEI);
      roughs->data[0] = allRoughs;
      for (i = 0; i < loop_ub; i++) {
        roughs->data[i + 1] = allLayers->data[i + allLayers->size[0] * 2];
      }

      covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 2, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 3U);
      st.site = &x_emlrtRSI;
      b_st.site = &hb_emlrtRSI;
      c_st.site = &ib_emlrtRSI;
      if (roughs->size[0] != allLayers->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      loop_ub = allLayers->size[0];
      c_loop_ub = allLayers->size[0];
      b_loop_ub = allLayers->size[0];
      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = 4;
      emxEnsureCapacity_real_T(sp, layers, i, &fh_emlrtRTEI);
      for (i = 0; i < loop_ub; i++) {
        layers->data[i] = allLayers->data[i];
      }

      for (i = 0; i < c_loop_ub; i++) {
        layers->data[i + layers->size[0]] = allLayers->data[i + allLayers->size
          [0]];
      }

      loop_ub = roughs->size[0];
      for (i = 0; i < loop_ub; i++) {
        layers->data[i + layers->size[0] * 2] = roughs->data[i];
      }

      emxFree_real_T(&roughs);
      for (i = 0; i < b_loop_ub; i++) {
        layers->data[i + layers->size[0] * 3] = allLayers->data[i +
          allLayers->size[0] * 3];
      }

      covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 5U);
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 6U);

    /* Deal with the %coverage if present */
    covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 3, true);
    i = allLayers->size[0];
    for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
      covrtLogFor(&emlrtCoverageInstance, 10U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 7U);
      i1 = b_loop_ub + 1;
      if ((i1 < 1) || (i1 > allLayers->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers->size[0], &dd_emlrtBCI,
          sp);
      }

      this_pcw = allLayers->data[(i1 + allLayers->size[0] * 3) - 1];
      i1 = b_loop_ub + 1;
      if ((i1 < 1) || (i1 > allLayers->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers->size[0], &ed_emlrtBCI,
          sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 4, allLayers->data[(i1 +
            allLayers->size[0] * 4) - 1] == 1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 8U);
        pc_add = nbair;
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 9U);
        pc_add = nbsubs;
      }

      if (covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 5, covrtLogMcdc
                     (&emlrtCoverageInstance, 10U, 0U, 1, !covrtLogCond
                      (&emlrtCoverageInstance, 10U, 0U, 1, muDoubleScalarIsNaN
                       (this_pcw))))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 10U);
        i1 = b_loop_ub + 1;
        if ((i1 < 1) || (i1 > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, layers->size[0], &fd_emlrtBCI, sp);
        }

        c_loop_ub = b_loop_ub + 1;
        if ((c_loop_ub < 1) || (c_loop_ub > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(c_loop_ub, 1, layers->size[0],
            &gd_emlrtBCI, sp);
        }

        layers->data[(c_loop_ub + layers->size[0]) - 1] = pc_add * (this_pcw /
          100.0) + (1.0 - this_pcw / 100.0) * layers->data[(i1 + layers->size[0])
          - 1];
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 10U, 0U, 0, 0);
  }

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  if (covrtLogIf(&emlrtCoverageInstance, 10U, 0U, 6, covrtLogMcdc
                 (&emlrtCoverageInstance, 10U, 0U, 2, !covrtLogCond
                  (&emlrtCoverageInstance, 10U, 0U, 2, layers->size[0] == 0))))
  {
    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 11U);
    loop_ub = layers->size[0];
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = layers->size[0];
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &dh_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        outLayers->data[i1 + outLayers->size[0] * i] = layers->data[i1 +
          layers->size[0] * i];
      }
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 12U);
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = 1;
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &ch_emlrtRTEI);
    outLayers->data[0] = 0.0;
    outLayers->data[1] = 0.0;
    outLayers->data[2] = 0.0;
  }

  emxFree_real_T(&layers);
  covrtLogBasicBlock(&emlrtCoverageInstance, 10U, 13U);

  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (groupLayers_Mod.c) */
