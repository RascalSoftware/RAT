/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
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
static emlrtRSInfo eb_emlrtRSI = {
    63,                /* lineNo */
    "groupLayers_Mod", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    56,                /* lineNo */
    "groupLayers_Mod", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    47,                /* lineNo */
    "groupLayers_Mod", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pathName */
};

static emlrtRSInfo uh_emlrtRSI = {
    65,                /* lineNo */
    "groupLayers_Mod", /* fcnName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pathName */
};

static emlrtBCInfo rf_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    56,                /* lineNo */
    48,                /* colNo */
    "roughs",          /* aName */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo sf_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    75,                /* lineNo */
    35,                /* colNo */
    "output",          /* aName */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo tf_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    76,                /* lineNo */
    27,                /* colNo */
    "output",          /* aName */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo uf_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    82,                /* lineNo */
    85,                /* colNo */
    "layers",          /* aName */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo kq_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    82,                /* lineNo */
    30,                /* colNo */
    "layers",          /* aName */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtECInfo db_emlrtECI = {
    2,                 /* nDims */
    48,                /* lineNo */
    17,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtECInfo eb_emlrtECI = {
    2,                 /* nDims */
    45,                /* lineNo */
    5,                 /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtBCInfo lq_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    52,                /* lineNo */
    34,                /* colNo */
    "output",          /* aName */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo mq_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    51,                /* lineNo */
    35,                /* colNo */
    "output",          /* aName */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo nq_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    90,                /* lineNo */
    26,                /* colNo */
    "layers",          /* aName */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtRTEInfo rh_emlrtRTEI = {
    45,                /* lineNo */
    5,                 /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo sh_emlrtRTEI = {
    48,                /* lineNo */
    17,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo th_emlrtRTEI = {
    58,                /* lineNo */
    21,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo uh_emlrtRTEI = {
    92,                /* lineNo */
    5,                 /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo vh_emlrtRTEI = {
    90,                /* lineNo */
    5,                 /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo wh_emlrtRTEI = {
    56,                /* lineNo */
    21,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo xh_emlrtRTEI = {
    63,                /* lineNo */
    21,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo yh_emlrtRTEI = {
    51,                /* lineNo */
    17,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo uo_emlrtRTEI = {
    65,                /* lineNo */
    21,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

/* Function Definitions */
void b_groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
                       real_T allRoughs, const emxArray_char_T *geometry,
                       real_T nbair, real_T nbsubs, emxArray_real_T *outLayers,
                       real_T *outSsubs)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *layers;
  emxArray_real_T *roughs;
  const real_T *allLayers_data;
  real_T pc_add;
  real_T this_pcw;
  real_T *layers_data;
  real_T *roughs_data;
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
  allLayers_data = allLayers->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /* Arrange layers according to geometry and apply any coverage correction. */
  /*  */
  /* [outLayers, outSsubs] =
   * groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs)
   */
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
  /*      encountered, and 'ssub' is then the roughness of the outermost layer.
   */
  /*      The rougnesses need to be arranged accordingly. */
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
    emlrtDimSizeGeqCheckR2012b(5, allLayers->size[1], &eb_emlrtECI,
                               (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &layers, 2, &rh_emlrtRTEI, true);
  i = layers->size[0] * layers->size[1];
  layers->size[0] = allLayers->size[0];
  layers->size[1] = allLayers->size[1];
  emxEnsureCapacity_real_T(sp, layers, i, &rh_emlrtRTEI);
  layers_data = layers->data;
  loop_ub = allLayers->size[0] * allLayers->size[1];
  for (i = 0; i < loop_ub; i++) {
    layers_data[i] = 0.0;
  }
  if ((allLayers->size[0] != 0) && (allLayers->size[1] != 0)) {
    st.site = &gb_emlrtRSI;
    if (c_strcmp(&st, geometry)) {
      if (5 < allLayers->size[1]) {
        emlrtDimSizeGeqCheckR2012b(5, allLayers->size[1], &db_emlrtECI,
                                   (emlrtCTX)sp);
      }
      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = allLayers->size[1];
      emxEnsureCapacity_real_T(sp, layers, i, &sh_emlrtRTEI);
      layers_data = layers->data;
      loop_ub = allLayers->size[0] * allLayers->size[1];
      for (i = 0; i < loop_ub; i++) {
        layers_data[i] = allLayers_data[i];
      }
      /* s_sub = rsub; */
    } else {
      if (3 > allLayers->size[1]) {
        emlrtDynamicBoundsCheckR2012b(3, 1, allLayers->size[1], &mq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (2 > allLayers->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, allLayers->size[1], &lq_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      *outSsubs =
          allLayers_data[(allLayers->size[0] + allLayers->size[0] * 2) - 1];
      emxInit_real_T(sp, &roughs, 1, &yh_emlrtRTEI, true);
      if (allLayers->size[0] > 1) {
        if (allLayers->size[0] - 1 > allLayers->size[0]) {
          emlrtDynamicBoundsCheckR2012b(allLayers->size[0] - 1, 1,
                                        allLayers->size[0], &rf_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        iv[0] = 1;
        iv[1] = allLayers->size[0] - 1;
        st.site = &fb_emlrtRSI;
        indexShapeCheck(&st, allLayers->size[0], iv);
        loop_ub = allLayers->size[0];
        i = roughs->size[0];
        roughs->size[0] = allLayers->size[0];
        emxEnsureCapacity_real_T(sp, roughs, i, &wh_emlrtRTEI);
        roughs_data = roughs->data;
        roughs_data[0] = allRoughs;
        for (i = 0; i <= loop_ub - 2; i++) {
          roughs_data[i + 1] = allLayers_data[i + allLayers->size[0] * 2];
        }
      } else {
        i = roughs->size[0];
        roughs->size[0] = 1;
        emxEnsureCapacity_real_T(sp, roughs, i, &th_emlrtRTEI);
        roughs_data = roughs->data;
        roughs_data[0] = allRoughs;
      }
      if (allLayers->size[1] == 5) {
        st.site = &eb_emlrtRSI;
        b_st.site = &nb_emlrtRSI;
        c_st.site = &ob_emlrtRSI;
        if (roughs->size[0] != allLayers->size[0]) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &gb_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        loop_ub = allLayers->size[0];
        b_loop_ub = allLayers->size[0];
        c_loop_ub = allLayers->size[0];
        i = layers->size[0] * layers->size[1];
        layers->size[0] = allLayers->size[0];
        layers->size[1] = 4;
        emxEnsureCapacity_real_T(sp, layers, i, &xh_emlrtRTEI);
        layers_data = layers->data;
        for (i = 0; i < loop_ub; i++) {
          layers_data[i] = allLayers_data[i];
        }
        for (i = 0; i < b_loop_ub; i++) {
          layers_data[i + layers->size[0]] =
              allLayers_data[i + allLayers->size[0]];
        }
        loop_ub = roughs->size[0];
        for (i = 0; i < loop_ub; i++) {
          layers_data[i + layers->size[0] * 2] = roughs_data[i];
        }
        for (i = 0; i < c_loop_ub; i++) {
          layers_data[i + layers->size[0] * 3] =
              allLayers_data[i + allLayers->size[0] * 3];
        }
      } else {
        st.site = &uh_emlrtRSI;
        b_st.site = &nb_emlrtRSI;
        c_st.site = &ob_emlrtRSI;
        if (roughs->size[0] != allLayers->size[0]) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &gb_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        loop_ub = allLayers->size[0];
        b_loop_ub = allLayers->size[0];
        i = layers->size[0] * layers->size[1];
        layers->size[0] = allLayers->size[0];
        layers->size[1] = 3;
        emxEnsureCapacity_real_T(sp, layers, i, &uo_emlrtRTEI);
        layers_data = layers->data;
        for (i = 0; i < loop_ub; i++) {
          layers_data[i] = allLayers_data[i];
        }
        for (i = 0; i < b_loop_ub; i++) {
          layers_data[i + layers->size[0]] =
              allLayers_data[i + allLayers->size[0]];
        }
        loop_ub = roughs->size[0];
        for (i = 0; i < loop_ub; i++) {
          layers_data[i + layers->size[0] * 2] = roughs_data[i];
        }
      }
      emxFree_real_T(sp, &roughs);
    }
    /* Deal with the %coverage if present */
    if (allLayers->size[1] == 5) {
      i = allLayers->size[0];
      for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
        if (b_loop_ub + 1 > allLayers->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, allLayers->size[0],
                                        &sf_emlrtBCI, (emlrtCTX)sp);
        }
        this_pcw = allLayers_data[b_loop_ub + allLayers->size[0] * 3];
        if (b_loop_ub + 1 > allLayers->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, allLayers->size[0],
                                        &tf_emlrtBCI, (emlrtCTX)sp);
        }
        if (allLayers_data[b_loop_ub + allLayers->size[0] * 4] == 1.0) {
          pc_add = nbair;
        } else {
          pc_add = nbsubs;
        }
        if (!muDoubleScalarIsNaN(this_pcw)) {
          if (2 > layers->size[1]) {
            emlrtDynamicBoundsCheckR2012b(2, 1, layers->size[1], &kq_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (b_loop_ub + 1 > layers->size[0]) {
            emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, layers->size[0],
                                          &uf_emlrtBCI, (emlrtCTX)sp);
          }
          layers_data[b_loop_ub + layers->size[0]] =
              pc_add * (this_pcw / 100.0) +
              (1.0 - this_pcw / 100.0) *
                  layers_data[b_loop_ub + layers->size[0]];
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtCTX)sp);
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
    emxEnsureCapacity_real_T(sp, outLayers, i, &vh_emlrtRTEI);
    roughs_data = outLayers->data;
    for (i = 0; i < 3; i++) {
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        if (i + 1 > layers->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, layers->size[1], &nq_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        roughs_data[b_loop_ub + outLayers->size[0] * i] =
            layers_data[b_loop_ub + layers->size[0] * i];
      }
    }
  } else {
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = 1;
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &uh_emlrtRTEI);
    roughs_data = outLayers->data;
    roughs_data[0] = 0.0;
    roughs_data[1] = 0.0;
    roughs_data[2] = 0.0;
  }
  emxFree_real_T(sp, &layers);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
                     real_T allRoughs, const emxArray_char_T *geometry,
                     real_T nbair, real_T nbsubs, emxArray_real_T *outLayers,
                     real_T *outSsubs)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *layers;
  emxArray_real_T *roughs;
  const real_T *allLayers_data;
  real_T pc_add;
  real_T this_pcw;
  real_T *layers_data;
  real_T *roughs_data;
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
  allLayers_data = allLayers->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &layers, 2, &rh_emlrtRTEI, true);
  /* Arrange layers according to geometry and apply any coverage correction. */
  /*  */
  /* [outLayers, outSsubs] =
   * groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs)
   */
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
  /*      encountered, and 'ssub' is then the roughness of the outermost layer.
   */
  /*      The rougnesses need to be arranged accordingly. */
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
  emxEnsureCapacity_real_T(sp, layers, i, &rh_emlrtRTEI);
  layers_data = layers->data;
  loop_ub = allLayers->size[0] * 5;
  for (i = 0; i < loop_ub; i++) {
    layers_data[i] = 0.0;
  }
  if (allLayers->size[0] != 0) {
    st.site = &gb_emlrtRSI;
    if (c_strcmp(&st, geometry)) {
      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = 5;
      emxEnsureCapacity_real_T(sp, layers, i, &sh_emlrtRTEI);
      layers_data = layers->data;
      loop_ub = allLayers->size[0] * 5;
      for (i = 0; i < loop_ub; i++) {
        layers_data[i] = allLayers_data[i];
      }
      /* s_sub = rsub; */
    } else {
      *outSsubs =
          allLayers_data[(allLayers->size[0] + allLayers->size[0] * 2) - 1];
      emxInit_real_T(sp, &roughs, 1, &yh_emlrtRTEI, true);
      if (allLayers->size[0] > 1) {
        if (allLayers->size[0] - 1 > allLayers->size[0]) {
          emlrtDynamicBoundsCheckR2012b(allLayers->size[0] - 1, 1,
                                        allLayers->size[0], &rf_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        iv[0] = 1;
        iv[1] = allLayers->size[0] - 1;
        st.site = &fb_emlrtRSI;
        indexShapeCheck(&st, allLayers->size[0], iv);
        loop_ub = allLayers->size[0];
        i = roughs->size[0];
        roughs->size[0] = allLayers->size[0];
        emxEnsureCapacity_real_T(sp, roughs, i, &wh_emlrtRTEI);
        roughs_data = roughs->data;
        roughs_data[0] = allRoughs;
        for (i = 0; i <= loop_ub - 2; i++) {
          roughs_data[i + 1] = allLayers_data[i + allLayers->size[0] * 2];
        }
      } else {
        i = roughs->size[0];
        roughs->size[0] = 1;
        emxEnsureCapacity_real_T(sp, roughs, i, &th_emlrtRTEI);
        roughs_data = roughs->data;
        roughs_data[0] = allRoughs;
      }
      st.site = &eb_emlrtRSI;
      b_st.site = &nb_emlrtRSI;
      c_st.site = &ob_emlrtRSI;
      if (roughs->size[0] != allLayers->size[0]) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &gb_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
            "MATLAB:catenate:matrixDimensionMismatch", 0);
      }
      loop_ub = allLayers->size[0];
      b_loop_ub = allLayers->size[0];
      c_loop_ub = allLayers->size[0];
      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = 4;
      emxEnsureCapacity_real_T(sp, layers, i, &xh_emlrtRTEI);
      layers_data = layers->data;
      for (i = 0; i < loop_ub; i++) {
        layers_data[i] = allLayers_data[i];
      }
      for (i = 0; i < b_loop_ub; i++) {
        layers_data[i + layers->size[0]] =
            allLayers_data[i + allLayers->size[0]];
      }
      loop_ub = roughs->size[0];
      for (i = 0; i < loop_ub; i++) {
        layers_data[i + layers->size[0] * 2] = roughs_data[i];
      }
      emxFree_real_T(sp, &roughs);
      for (i = 0; i < c_loop_ub; i++) {
        layers_data[i + layers->size[0] * 3] =
            allLayers_data[i + allLayers->size[0] * 3];
      }
    }
    /* Deal with the %coverage if present */
    i = allLayers->size[0];
    for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
      if (b_loop_ub + 1 > allLayers->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, allLayers->size[0],
                                      &sf_emlrtBCI, (emlrtCTX)sp);
      }
      this_pcw = allLayers_data[b_loop_ub + allLayers->size[0] * 3];
      if (b_loop_ub + 1 > allLayers->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, allLayers->size[0],
                                      &tf_emlrtBCI, (emlrtCTX)sp);
      }
      if (allLayers_data[b_loop_ub + allLayers->size[0] * 4] == 1.0) {
        pc_add = nbair;
      } else {
        pc_add = nbsubs;
      }
      if (!muDoubleScalarIsNaN(this_pcw)) {
        if (b_loop_ub + 1 > layers->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, layers->size[0],
                                        &uf_emlrtBCI, (emlrtCTX)sp);
        }
        layers_data[b_loop_ub + layers->size[0]] =
            pc_add * (this_pcw / 100.0) +
            (1.0 - this_pcw / 100.0) * layers_data[b_loop_ub + layers->size[0]];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
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
    emxEnsureCapacity_real_T(sp, outLayers, i, &vh_emlrtRTEI);
    roughs_data = outLayers->data;
    for (i = 0; i < 3; i++) {
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        roughs_data[b_loop_ub + outLayers->size[0] * i] =
            layers_data[b_loop_ub + layers->size[0] * i];
      }
    }
  } else {
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = 1;
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &uh_emlrtRTEI);
    roughs_data = outLayers->data;
    roughs_data[0] = 0.0;
    roughs_data[1] = 0.0;
    roughs_data[2] = 0.0;
  }
  emxFree_real_T(sp, &layers);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (groupLayers_Mod.c) */
