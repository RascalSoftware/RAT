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

/* Variable Definitions */
static emlrtRSInfo s_emlrtRSI = { 57,  /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 61,  /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo mh_emlrtRSI = { 63, /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  44,                                  /* colNo */
  "roughs",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  24,                                  /* colNo */
  "roughs",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  28,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  20,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  78,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  21,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo wg_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo xg_emlrtRTEI = { 90,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo yg_emlrtRTEI = { 88,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = { 50,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = { 57,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = { 61,/* lineNo */
  21,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = { 53,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo jn_emlrtRTEI = { 63,/* lineNo */
  21,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static const char_T cv1[13] = { 'a', 'i', 'r', '/', 's', 'u', 'b', 's', 't', 'r',
  'a', 't', 'e' };

static const char_T cv2[16] = { 's', 'u', 'b', 's', 't', 'r', 'a', 't', 'e', '/',
  'l', 'i', 'q', 'u', 'i', 'd' };

/* Function Definitions */
void b_groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
  real_T allRoughs, const emxArray_char_T *geometry, emxArray_real_T *outLayers,
  real_T *outSsubs)
{
  emxArray_real_T *layers;
  uint32_T unnamed_idx_0;
  int32_T i;
  int32_T loop_ub;
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  emxArray_real_T *roughs;
  int32_T iv[2];
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
  emxInit_real_T(sp, &layers, 2, &wg_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 8U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 0U);

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
  layers->size[1] = 3;
  emxEnsureCapacity_real_T(sp, layers, i, &wg_emlrtRTEI);
  loop_ub = (int32_T)unnamed_idx_0 * 3;
  for (i = 0; i < loop_ub; i++) {
    layers->data[i] = 0.0;
  }

  covrtLogCond(&emlrtCoverageInstance, 8U, 0U, 0, false);
  covrtLogMcdc(&emlrtCoverageInstance, 8U, 0U, 0, true);
  covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 0, true);
  b_bool = false;
  if (geometry->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
        if (geometry->data[kstr] != cv1[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (geometry->size[1] == 16) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 16) {
          if (geometry->data[kstr] != cv2[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      kstr = 1;
    } else {
      kstr = -1;
    }
  }

  switch (kstr) {
   case 0:
    covrtLogSwitch(&emlrtCoverageInstance, 8U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 1U);
    i = layers->size[0] * layers->size[1];
    layers->size[0] = allLayers->size[0];
    layers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layers, i, &ah_emlrtRTEI);
    loop_ub = allLayers->size[0] * allLayers->size[1];
    for (i = 0; i < loop_ub; i++) {
      layers->data[i] = allLayers->data[i];
    }

    /* s_sub = rsub; */
    break;

   case 1:
    covrtLogSwitch(&emlrtCoverageInstance, 8U, 0U, 0, 2);
    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 2U);
    if (allLayers->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(allLayers->size[0], 1, allLayers->size[0],
        &td_emlrtBCI, sp);
    }

    *outSsubs = allLayers->data[(allLayers->size[0] + allLayers->size[0] * 2) -
      1];
    if (1 > allLayers->size[0] - 1) {
      loop_ub = 0;
    } else {
      loop_ub = allLayers->size[0] - 1;
      if ((loop_ub < 1) || (loop_ub > allLayers->size[0])) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, allLayers->size[0],
          &sd_emlrtBCI, sp);
      }
    }

    emxInit_real_T(sp, &roughs, 1, &dh_emlrtRTEI, true);
    iv[0] = 1;
    iv[1] = loop_ub;
    st.site = &s_emlrtRSI;
    indexShapeCheck(&st, allLayers->size[0], iv);
    i = roughs->size[0];
    roughs->size[0] = loop_ub + 1;
    emxEnsureCapacity_real_T(sp, roughs, i, &bh_emlrtRTEI);
    roughs->data[0] = allRoughs;
    for (i = 0; i < loop_ub; i++) {
      roughs->data[i + 1] = allLayers->data[i + allLayers->size[0] * 2];
    }

    covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 1, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 4U);
    st.site = &mh_emlrtRSI;
    b_st.site = &v_emlrtRSI;
    c_st.site = &w_emlrtRSI;
    if (roughs->size[0] != allLayers->size[0]) {
      emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
        "MATLAB:catenate:matrixDimensionMismatch",
        "MATLAB:catenate:matrixDimensionMismatch", 0);
    }

    loop_ub = allLayers->size[0];
    kstr = allLayers->size[0];
    i = layers->size[0] * layers->size[1];
    layers->size[0] = allLayers->size[0];
    layers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, layers, i, &jn_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      layers->data[i] = allLayers->data[i];
    }

    for (i = 0; i < kstr; i++) {
      layers->data[i + layers->size[0]] = allLayers->data[i + allLayers->size[0]];
    }

    loop_ub = roughs->size[0];
    for (i = 0; i < loop_ub; i++) {
      layers->data[i + layers->size[0] * 2] = roughs->data[i];
    }

    emxFree_real_T(&roughs);
    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 5U);
    break;

   default:
    covrtLogSwitch(&emlrtCoverageInstance, 8U, 0U, 0, 0);
    break;
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 6U);

  /* Deal with the %coverage if present */
  covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 2, false);

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  covrtLogCond(&emlrtCoverageInstance, 8U, 0U, 2, false);
  covrtLogMcdc(&emlrtCoverageInstance, 8U, 0U, 2, true);
  covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 5, true);
  covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 11U);
  loop_ub = layers->size[0];
  i = outLayers->size[0] * outLayers->size[1];
  outLayers->size[0] = layers->size[0];
  outLayers->size[1] = 3;
  emxEnsureCapacity_real_T(sp, outLayers, i, &yg_emlrtRTEI);
  for (i = 0; i < 3; i++) {
    for (kstr = 0; kstr < loop_ub; kstr++) {
      outLayers->data[kstr + outLayers->size[0] * i] = layers->data[kstr +
        layers->size[0] * i];
    }
  }

  emxFree_real_T(&layers);
  covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 13U);

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
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  int32_T i1;
  int32_T b_loop_ub;
  emxArray_real_T *roughs;
  int32_T iv[2];
  real_T this_pcw;
  real_T pc_add;
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
  emxInit_real_T(sp, &layers, 2, &wg_emlrtRTEI, true);
  covrtLogFcn(&emlrtCoverageInstance, 8U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 0U);

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
  emxEnsureCapacity_real_T(sp, layers, i, &wg_emlrtRTEI);
  loop_ub = (int32_T)unnamed_idx_0 * 5;
  for (i = 0; i < loop_ub; i++) {
    layers->data[i] = 0.0;
  }

  if (covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 0, covrtLogMcdc
                 (&emlrtCoverageInstance, 8U, 0U, 0, !covrtLogCond
                  (&emlrtCoverageInstance, 8U, 0U, 0, allLayers->size[0] == 0))))
  {
    b_bool = false;
    if (geometry->size[1] == 13) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 13) {
          if (geometry->data[kstr] != cv1[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      kstr = 0;
    } else {
      b_bool = false;
      if (geometry->size[1] == 16) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 16) {
            if (geometry->data[kstr] != cv2[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        kstr = 1;
      } else {
        kstr = -1;
      }
    }

    switch (kstr) {
     case 0:
      covrtLogSwitch(&emlrtCoverageInstance, 8U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 1U);
      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = 5;
      emxEnsureCapacity_real_T(sp, layers, i, &ah_emlrtRTEI);
      loop_ub = allLayers->size[0] * allLayers->size[1];
      for (i = 0; i < loop_ub; i++) {
        layers->data[i] = allLayers->data[i];
      }

      /* s_sub = rsub; */
      break;

     case 1:
      covrtLogSwitch(&emlrtCoverageInstance, 8U, 0U, 0, 2);
      covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 2U);
      if (allLayers->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(allLayers->size[0], 1, allLayers->size[0],
          &td_emlrtBCI, sp);
      }

      *outSsubs = allLayers->data[(allLayers->size[0] + allLayers->size[0] * 2)
        - 1];
      if (1 > allLayers->size[0] - 1) {
        loop_ub = 0;
      } else {
        loop_ub = allLayers->size[0] - 1;
        if ((loop_ub < 1) || (loop_ub > allLayers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, allLayers->size[0],
            &sd_emlrtBCI, sp);
        }
      }

      emxInit_real_T(sp, &roughs, 1, &dh_emlrtRTEI, true);
      iv[0] = 1;
      iv[1] = loop_ub;
      st.site = &s_emlrtRSI;
      indexShapeCheck(&st, allLayers->size[0], iv);
      i = roughs->size[0];
      roughs->size[0] = loop_ub + 1;
      emxEnsureCapacity_real_T(sp, roughs, i, &bh_emlrtRTEI);
      roughs->data[0] = allRoughs;
      for (i = 0; i < loop_ub; i++) {
        roughs->data[i + 1] = allLayers->data[i + allLayers->size[0] * 2];
      }

      covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 1, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 3U);
      st.site = &t_emlrtRSI;
      b_st.site = &v_emlrtRSI;
      c_st.site = &w_emlrtRSI;
      if (roughs->size[0] != allLayers->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      loop_ub = allLayers->size[0];
      kstr = allLayers->size[0];
      b_loop_ub = allLayers->size[0];
      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = 4;
      emxEnsureCapacity_real_T(sp, layers, i, &ch_emlrtRTEI);
      for (i = 0; i < loop_ub; i++) {
        layers->data[i] = allLayers->data[i];
      }

      for (i = 0; i < kstr; i++) {
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

      covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 5U);
      break;

     default:
      covrtLogSwitch(&emlrtCoverageInstance, 8U, 0U, 0, 0);
      break;
    }

    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 6U);

    /* Deal with the %coverage if present */
    covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 2, true);
    i = allLayers->size[0];
    for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
      covrtLogFor(&emlrtCoverageInstance, 8U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 7U);
      i1 = b_loop_ub + 1;
      if ((i1 < 1) || (i1 > allLayers->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers->size[0], &ud_emlrtBCI,
          sp);
      }

      this_pcw = allLayers->data[(i1 + allLayers->size[0] * 3) - 1];
      i1 = b_loop_ub + 1;
      if ((i1 < 1) || (i1 > allLayers->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers->size[0], &vd_emlrtBCI,
          sp);
      }

      if (covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 3, allLayers->data[(i1 +
            allLayers->size[0] * 4) - 1] == 1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 8U);
        pc_add = nbsubs;
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 9U);
        pc_add = nbair;
      }

      if (covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 4, covrtLogMcdc
                     (&emlrtCoverageInstance, 8U, 0U, 1, !covrtLogCond
                      (&emlrtCoverageInstance, 8U, 0U, 1, muDoubleScalarIsNaN
                       (this_pcw))))) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 10U);
        i1 = b_loop_ub + 1;
        if ((i1 < 1) || (i1 > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, layers->size[0], &wd_emlrtBCI, sp);
        }

        kstr = b_loop_ub + 1;
        if ((kstr < 1) || (kstr > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, layers->size[0], &xd_emlrtBCI,
            sp);
        }

        layers->data[(kstr + layers->size[0]) - 1] = pc_add * (this_pcw / 100.0)
          + (1.0 - this_pcw / 100.0) * layers->data[(i1 + layers->size[0]) - 1];
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 8U, 0U, 0, 0);
  }

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  if (covrtLogIf(&emlrtCoverageInstance, 8U, 0U, 5, covrtLogMcdc
                 (&emlrtCoverageInstance, 8U, 0U, 2, !covrtLogCond
                  (&emlrtCoverageInstance, 8U, 0U, 2, layers->size[0] == 0)))) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 11U);
    loop_ub = layers->size[0];
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = layers->size[0];
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &yg_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        outLayers->data[i1 + outLayers->size[0] * i] = layers->data[i1 +
          layers->size[0] * i];
      }
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 12U);
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = 1;
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &xg_emlrtRTEI);
    outLayers->data[0] = 0.0;
    outLayers->data[1] = 0.0;
    outLayers->data[2] = 0.0;
  }

  emxFree_real_T(&layers);
  covrtLogBasicBlock(&emlrtCoverageInstance, 8U, 13U);

  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (groupLayers_Mod.c) */
