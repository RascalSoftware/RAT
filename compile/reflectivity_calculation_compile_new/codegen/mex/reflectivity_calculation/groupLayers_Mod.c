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
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = { 63, /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 56, /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 47, /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo kh_emlrtRSI = { 65, /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtBCInfo se_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  48,                                  /* colNo */
  "roughs",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  24,                                  /* colNo */
  "roughs",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  28,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  20,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  78,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo so_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  30,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo db_emlrtECI = { 2,  /* nDims */
  48,                                  /* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtECInfo eb_emlrtECI = { 2,  /* nDims */
  45,                                  /* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtBCInfo to_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  34,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  35,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vo_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  26,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo th_emlrtRTEI = { 45,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo uh_emlrtRTEI = { 48,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo vh_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo wh_emlrtRTEI = { 58,/* lineNo */
  21,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo xh_emlrtRTEI = { 90,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo yh_emlrtRTEI = { 56,/* lineNo */
  21,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo ai_emlrtRTEI = { 63,/* lineNo */
  21,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo bi_emlrtRTEI = { 51,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo ro_emlrtRTEI = { 65,/* lineNo */
  21,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

/* Function Definitions */
void b_groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
  real_T allRoughs, const emxArray_char_T *geometry, real_T nbair, real_T nbsubs,
  emxArray_real_T *outLayers, real_T *outSsubs)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *layers;
  emxArray_real_T *roughs;
  real_T pc_add;
  real_T this_pcw;
  int32_T iv[2];
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

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
  if (5 < allLayers->size[1]) {
    emlrtDimSizeGeqCheckR2012b(5, allLayers->size[1], &eb_emlrtECI, sp);
  }

  emxInit_real_T(sp, &layers, 2, &th_emlrtRTEI, true);
  i = layers->size[0] * layers->size[1];
  layers->size[0] = allLayers->size[0];
  layers->size[1] = allLayers->size[1];
  emxEnsureCapacity_real_T(sp, layers, i, &th_emlrtRTEI);
  loop_ub = allLayers->size[0] * allLayers->size[1];
  for (i = 0; i < loop_ub; i++) {
    layers->data[i] = 0.0;
  }

  if ((allLayers->size[0] != 0) && (allLayers->size[1] != 0)) {
    st.site = &gb_emlrtRSI;
    if (b_strcmp(&st, geometry)) {
      if (5 < allLayers->size[1]) {
        emlrtDimSizeGeqCheckR2012b(5, allLayers->size[1], &db_emlrtECI, sp);
      }

      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = allLayers->size[1];
      emxEnsureCapacity_real_T(sp, layers, i, &uh_emlrtRTEI);
      loop_ub = allLayers->size[0] * allLayers->size[1];
      for (i = 0; i < loop_ub; i++) {
        layers->data[i] = allLayers->data[i];
      }

      /* s_sub = rsub; */
    } else {
      if (3 > allLayers->size[1]) {
        emlrtDynamicBoundsCheckR2012b(3, 1, allLayers->size[1], &uo_emlrtBCI, sp);
      }

      if (2 > allLayers->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, allLayers->size[1], &to_emlrtBCI, sp);
      }

      if (allLayers->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(allLayers->size[0], 1, allLayers->size[0],
          &te_emlrtBCI, sp);
      }

      *outSsubs = allLayers->data[(allLayers->size[0] + allLayers->size[0] * 2)
        - 1];
      emxInit_real_T(sp, &roughs, 1, &bi_emlrtRTEI, true);
      if (allLayers->size[0] > 1) {
        if ((allLayers->size[0] - 1 < 1) || (allLayers->size[0] - 1 >
             allLayers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(allLayers->size[0] - 1, 1,
            allLayers->size[0], &se_emlrtBCI, sp);
        }

        iv[0] = 1;
        iv[1] = allLayers->size[0] - 1;
        st.site = &fb_emlrtRSI;
        indexShapeCheck(&st, allLayers->size[0], iv);
        loop_ub = allLayers->size[0];
        i = roughs->size[0];
        roughs->size[0] = allLayers->size[0];
        emxEnsureCapacity_real_T(sp, roughs, i, &yh_emlrtRTEI);
        roughs->data[0] = allRoughs;
        for (i = 0; i <= loop_ub - 2; i++) {
          roughs->data[i + 1] = allLayers->data[i + allLayers->size[0] * 2];
        }
      } else {
        i = roughs->size[0];
        roughs->size[0] = 1;
        emxEnsureCapacity_real_T(sp, roughs, i, &wh_emlrtRTEI);
        roughs->data[0] = allRoughs;
      }

      if (allLayers->size[1] == 5) {
        st.site = &eb_emlrtRSI;
        b_st.site = &nb_emlrtRSI;
        c_st.site = &ob_emlrtRSI;
        if (roughs->size[0] != allLayers->size[0]) {
          emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch",
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        loop_ub = allLayers->size[0];
        b_loop_ub = allLayers->size[0];
        c_loop_ub = allLayers->size[0];
        i = layers->size[0] * layers->size[1];
        layers->size[0] = allLayers->size[0];
        layers->size[1] = 4;
        emxEnsureCapacity_real_T(sp, layers, i, &ai_emlrtRTEI);
        for (i = 0; i < loop_ub; i++) {
          layers->data[i] = allLayers->data[i];
        }

        for (i = 0; i < b_loop_ub; i++) {
          layers->data[i + layers->size[0]] = allLayers->data[i +
            allLayers->size[0]];
        }

        loop_ub = roughs->size[0];
        for (i = 0; i < loop_ub; i++) {
          layers->data[i + layers->size[0] * 2] = roughs->data[i];
        }

        for (i = 0; i < c_loop_ub; i++) {
          layers->data[i + layers->size[0] * 3] = allLayers->data[i +
            allLayers->size[0] * 3];
        }
      } else {
        st.site = &kh_emlrtRSI;
        b_st.site = &nb_emlrtRSI;
        c_st.site = &ob_emlrtRSI;
        if (roughs->size[0] != allLayers->size[0]) {
          emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch",
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        loop_ub = allLayers->size[0];
        b_loop_ub = allLayers->size[0];
        i = layers->size[0] * layers->size[1];
        layers->size[0] = allLayers->size[0];
        layers->size[1] = 3;
        emxEnsureCapacity_real_T(sp, layers, i, &ro_emlrtRTEI);
        for (i = 0; i < loop_ub; i++) {
          layers->data[i] = allLayers->data[i];
        }

        for (i = 0; i < b_loop_ub; i++) {
          layers->data[i + layers->size[0]] = allLayers->data[i +
            allLayers->size[0]];
        }

        loop_ub = roughs->size[0];
        for (i = 0; i < loop_ub; i++) {
          layers->data[i + layers->size[0] * 2] = roughs->data[i];
        }
      }

      emxFree_real_T(&roughs);
    }

    /* Deal with the %coverage if present */
    if (allLayers->size[1] == 5) {
      i = allLayers->size[0];
      for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
        if ((b_loop_ub + 1 < 1) || (b_loop_ub + 1 > allLayers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, allLayers->size[0],
            &ue_emlrtBCI, sp);
        }

        this_pcw = allLayers->data[b_loop_ub + allLayers->size[0] * 3];
        if ((b_loop_ub + 1 < 1) || (b_loop_ub + 1 > allLayers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, allLayers->size[0],
            &ve_emlrtBCI, sp);
        }

        if (allLayers->data[b_loop_ub + allLayers->size[0] * 4] == 1.0) {
          pc_add = nbair;
        } else {
          pc_add = nbsubs;
        }

        if (!muDoubleScalarIsNaN(this_pcw)) {
          if (2 > layers->size[1]) {
            emlrtDynamicBoundsCheckR2012b(2, 1, layers->size[1], &so_emlrtBCI,
              sp);
          }

          if ((b_loop_ub + 1 < 1) || (b_loop_ub + 1 > layers->size[0])) {
            emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, layers->size[0],
              &we_emlrtBCI, sp);
          }

          layers->data[b_loop_ub + layers->size[0]] = pc_add * (this_pcw / 100.0)
            + (1.0 - this_pcw / 100.0) * layers->data[b_loop_ub + layers->size[0]];
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    }
  }

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  if ((layers->size[0] != 0) && (layers->size[1] != 0)) {
    loop_ub = layers->size[0];
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = layers->size[0];
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &xh_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        if (i + 1 > layers->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, layers->size[1], &vo_emlrtBCI,
            sp);
        }

        outLayers->data[b_loop_ub + outLayers->size[0] * i] = layers->
          data[b_loop_ub + layers->size[0] * i];
      }
    }
  } else {
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = 1;
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &vh_emlrtRTEI);
    outLayers->data[0] = 0.0;
    outLayers->data[1] = 0.0;
    outLayers->data[2] = 0.0;
  }

  emxFree_real_T(&layers);

  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
                     real_T allRoughs, const emxArray_char_T *geometry, real_T
                     nbair, real_T nbsubs, emxArray_real_T *outLayers, real_T
                     *outSsubs)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *layers;
  emxArray_real_T *roughs;
  real_T pc_add;
  real_T this_pcw;
  int32_T iv[2];
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &layers, 2, &th_emlrtRTEI, true);

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
  i = layers->size[0] * layers->size[1];
  layers->size[0] = allLayers->size[0];
  layers->size[1] = 5;
  emxEnsureCapacity_real_T(sp, layers, i, &th_emlrtRTEI);
  loop_ub = allLayers->size[0] * 5;
  for (i = 0; i < loop_ub; i++) {
    layers->data[i] = 0.0;
  }

  if (allLayers->size[0] != 0) {
    st.site = &gb_emlrtRSI;
    if (b_strcmp(&st, geometry)) {
      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = 5;
      emxEnsureCapacity_real_T(sp, layers, i, &uh_emlrtRTEI);
      loop_ub = allLayers->size[0] * allLayers->size[1];
      for (i = 0; i < loop_ub; i++) {
        layers->data[i] = allLayers->data[i];
      }

      /* s_sub = rsub; */
    } else {
      if (allLayers->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(allLayers->size[0], 1, allLayers->size[0],
          &te_emlrtBCI, sp);
      }

      *outSsubs = allLayers->data[(allLayers->size[0] + allLayers->size[0] * 2)
        - 1];
      emxInit_real_T(sp, &roughs, 1, &bi_emlrtRTEI, true);
      if (allLayers->size[0] > 1) {
        if ((allLayers->size[0] - 1 < 1) || (allLayers->size[0] - 1 >
             allLayers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(allLayers->size[0] - 1, 1,
            allLayers->size[0], &se_emlrtBCI, sp);
        }

        iv[0] = 1;
        iv[1] = allLayers->size[0] - 1;
        st.site = &fb_emlrtRSI;
        indexShapeCheck(&st, allLayers->size[0], iv);
        loop_ub = allLayers->size[0];
        i = roughs->size[0];
        roughs->size[0] = allLayers->size[0];
        emxEnsureCapacity_real_T(sp, roughs, i, &yh_emlrtRTEI);
        roughs->data[0] = allRoughs;
        for (i = 0; i <= loop_ub - 2; i++) {
          roughs->data[i + 1] = allLayers->data[i + allLayers->size[0] * 2];
        }
      } else {
        i = roughs->size[0];
        roughs->size[0] = 1;
        emxEnsureCapacity_real_T(sp, roughs, i, &wh_emlrtRTEI);
        roughs->data[0] = allRoughs;
      }

      st.site = &eb_emlrtRSI;
      b_st.site = &nb_emlrtRSI;
      c_st.site = &ob_emlrtRSI;
      if (roughs->size[0] != allLayers->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      loop_ub = allLayers->size[0];
      b_loop_ub = allLayers->size[0];
      c_loop_ub = allLayers->size[0];
      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = 4;
      emxEnsureCapacity_real_T(sp, layers, i, &ai_emlrtRTEI);
      for (i = 0; i < loop_ub; i++) {
        layers->data[i] = allLayers->data[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        layers->data[i + layers->size[0]] = allLayers->data[i + allLayers->size
          [0]];
      }

      loop_ub = roughs->size[0];
      for (i = 0; i < loop_ub; i++) {
        layers->data[i + layers->size[0] * 2] = roughs->data[i];
      }

      emxFree_real_T(&roughs);
      for (i = 0; i < c_loop_ub; i++) {
        layers->data[i + layers->size[0] * 3] = allLayers->data[i +
          allLayers->size[0] * 3];
      }
    }

    /* Deal with the %coverage if present */
    i = allLayers->size[0];
    for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
      if ((b_loop_ub + 1 < 1) || (b_loop_ub + 1 > allLayers->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, allLayers->size[0],
          &ue_emlrtBCI, sp);
      }

      this_pcw = allLayers->data[b_loop_ub + allLayers->size[0] * 3];
      if ((b_loop_ub + 1 < 1) || (b_loop_ub + 1 > allLayers->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, allLayers->size[0],
          &ve_emlrtBCI, sp);
      }

      if (allLayers->data[b_loop_ub + allLayers->size[0] * 4] == 1.0) {
        pc_add = nbair;
      } else {
        pc_add = nbsubs;
      }

      if (!muDoubleScalarIsNaN(this_pcw)) {
        if ((b_loop_ub + 1 < 1) || (b_loop_ub + 1 > layers->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, layers->size[0],
            &we_emlrtBCI, sp);
        }

        layers->data[b_loop_ub + layers->size[0]] = pc_add * (this_pcw / 100.0)
          + (1.0 - this_pcw / 100.0) * layers->data[b_loop_ub + layers->size[0]];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  if (layers->size[0] != 0) {
    loop_ub = layers->size[0];
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = layers->size[0];
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &xh_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        outLayers->data[b_loop_ub + outLayers->size[0] * i] = layers->
          data[b_loop_ub + layers->size[0] * i];
      }
    }
  } else {
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = 1;
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &vh_emlrtRTEI);
    outLayers->data[0] = 0.0;
    outLayers->data[1] = 0.0;
    outLayers->data[2] = 0.0;
  }

  emxFree_real_T(&layers);

  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (groupLayers_Mod.c) */
