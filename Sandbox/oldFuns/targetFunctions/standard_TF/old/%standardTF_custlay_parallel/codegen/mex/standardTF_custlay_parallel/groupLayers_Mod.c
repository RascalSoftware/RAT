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
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "groupLayers_Mod.h"
#include "standardTF_custlay_parallel_emxutil.h"
#include "indexShapeCheck.h"
#include "standardTF_custlay_parallel_data.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = { 51,  /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 45,  /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = { 1, /* lineNo */
  34,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 34,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 41,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  35,                                  /* colNo */
  "roughs",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  24,                                  /* colNo */
  "roughs",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  34,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  35,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  22,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
                     real_T allRoughs, const emxArray_char_T *geometry,
                     emxArray_real_T *outLayers, real_T *outSsubs)
{
  emxArray_real_T *layers;
  real_T rsub;
  int32_T i8;
  boolean_T b_bool;
  int32_T kstr;
  int32_T loop_ub;
  int32_T b_loop_ub;
  int32_T exitg2;
  static const char_T cv4[23] = { 'A', 'i', 'r', ' ', '/', ' ', 'L', 'i', 'q',
    'u', 'i', 'd', ' ', '(', 'o', 'r', ' ', 's', 'o', 'l', 'i', 'd', ')' };

  int32_T exitg1;
  static const char_T cv5[14] = { 'S', 'o', 'l', 'i', 'd', ' ', '/', ' ', 'L',
    'i', 'q', 'u', 'i', 'd' };

  int32_T roughs_idx_0;
  emxArray_real_T *b_allLayers;
  int32_T iv0[2];
  emxArray_real_T *roughs;
  emxArray_real_T *c_allLayers;
  emxArray_real_T *d_allLayers;
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
  emxInit_real_T(sp, &layers, 2, &g_emlrtRTEI, true);

  /* Arrange layers according to geometry and apply any coberage correction. */
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
  rsub = allRoughs;
  i8 = layers->size[0] * layers->size[1];
  layers->size[0] = 0;
  layers->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)layers, i8, (int32_T)sizeof(real_T),
                    &f_emlrtRTEI);
  if (!((allLayers->size[0] == 0) || (allLayers->size[1] == 0))) {
    b_bool = false;
    if (geometry->size[1] == 23) {
      kstr = 0;
      do {
        exitg2 = 0;
        if (kstr + 1 < 24) {
          if (geometry->data[kstr] != cv4[kstr]) {
            exitg2 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (b_bool) {
      kstr = 0;
    } else {
      b_bool = false;
      if (geometry->size[1] == 14) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr + 1 < 15) {
            if (geometry->data[kstr] != cv5[kstr]) {
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
      i8 = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = allLayers->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)layers, i8, (int32_T)sizeof
                        (real_T), &f_emlrtRTEI);
      loop_ub = allLayers->size[0] * allLayers->size[1];
      for (i8 = 0; i8 < loop_ub; i8++) {
        layers->data[i8] = allLayers->data[i8];
      }

      /* s_sub = rsub; */
      break;

     case 1:
      i8 = allLayers->size[1];
      if (!(3 <= i8)) {
        emlrtDynamicBoundsCheckR2012b(3, 1, i8, &ic_emlrtBCI, sp);
      }

      i8 = allLayers->size[1];
      if (!(2 <= i8)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i8, &hc_emlrtBCI, sp);
      }

      i8 = allLayers->size[0];
      kstr = allLayers->size[0];
      if (!((i8 >= 1) && (i8 <= kstr))) {
        emlrtDynamicBoundsCheckR2012b(i8, 1, kstr, &gc_emlrtBCI, sp);
      }

      rsub = allLayers->data[(i8 + (allLayers->size[0] << 1)) - 1];
      i8 = allLayers->size[0];
      if (1 > i8 - 1) {
        loop_ub = 0;
      } else {
        loop_ub = allLayers->size[0] - 1;
        i8 = allLayers->size[0];
        if (!((loop_ub >= 1) && (loop_ub <= i8))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i8, &fc_emlrtBCI, sp);
        }
      }

      emxInit_real_T1(sp, &b_allLayers, 1, &f_emlrtRTEI, true);
      i8 = allLayers->size[0];
      iv0[0] = 1;
      iv0[1] = loop_ub;
      st.site = &k_emlrtRSI;
      indexShapeCheck(&st, i8, iv0);
      b_loop_ub = allLayers->size[0];
      i8 = b_allLayers->size[0];
      b_allLayers->size[0] = b_loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)b_allLayers, i8, (int32_T)sizeof
                        (real_T), &f_emlrtRTEI);
      for (i8 = 0; i8 < b_loop_ub; i8++) {
        b_allLayers->data[i8] = allLayers->data[i8 + (allLayers->size[0] << 1)];
      }

      emxInit_real_T1(sp, &roughs, 1, &h_emlrtRTEI, true);
      i8 = roughs->size[0];
      roughs->size[0] = loop_ub + 1;
      emxEnsureCapacity(sp, (emxArray__common *)roughs, i8, (int32_T)sizeof
                        (real_T), &f_emlrtRTEI);
      roughs->data[0] = allRoughs;
      for (i8 = 0; i8 < loop_ub; i8++) {
        roughs->data[i8 + 1] = b_allLayers->data[i8];
      }

      emxFree_real_T(&b_allLayers);
      st.site = &j_emlrtRSI;
      b_st.site = &m_emlrtRSI;
      kstr = allLayers->size[0];
      c_st.site = &n_emlrtRSI;
      i8 = allLayers->size[0];
      b_bool = (kstr == i8);
      if (!b_bool) {
        emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      i8 = allLayers->size[0];
      if (kstr != i8) {
        b_bool = false;
      }

      if (!b_bool) {
        emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      roughs_idx_0 = roughs->size[0];
      if (kstr != roughs_idx_0) {
        b_bool = false;
      }

      if (!b_bool) {
        emlrtErrorWithMessageIdR2012b(&c_st, &ac_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      emxInit_real_T1(&c_st, &c_allLayers, 1, &f_emlrtRTEI, true);
      loop_ub = allLayers->size[0];
      b_loop_ub = allLayers->size[0];
      kstr = allLayers->size[0];
      i8 = c_allLayers->size[0];
      c_allLayers->size[0] = kstr;
      emxEnsureCapacity(sp, (emxArray__common *)c_allLayers, i8, (int32_T)sizeof
                        (real_T), &f_emlrtRTEI);
      for (i8 = 0; i8 < kstr; i8++) {
        c_allLayers->data[i8] = allLayers->data[i8];
      }

      emxInit_real_T1(sp, &d_allLayers, 1, &f_emlrtRTEI, true);
      kstr = allLayers->size[0];
      i8 = d_allLayers->size[0];
      d_allLayers->size[0] = kstr;
      emxEnsureCapacity(sp, (emxArray__common *)d_allLayers, i8, (int32_T)sizeof
                        (real_T), &f_emlrtRTEI);
      for (i8 = 0; i8 < kstr; i8++) {
        d_allLayers->data[i8] = allLayers->data[i8 + allLayers->size[0]];
      }

      roughs_idx_0 = roughs->size[0];
      i8 = layers->size[0] * layers->size[1];
      layers->size[0] = loop_ub;
      layers->size[1] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)layers, i8, (int32_T)sizeof
                        (real_T), &f_emlrtRTEI);
      for (i8 = 0; i8 < loop_ub; i8++) {
        layers->data[i8] = c_allLayers->data[i8];
      }

      emxFree_real_T(&c_allLayers);
      for (i8 = 0; i8 < b_loop_ub; i8++) {
        layers->data[i8 + layers->size[0]] = d_allLayers->data[i8];
      }

      emxFree_real_T(&d_allLayers);
      for (i8 = 0; i8 < roughs_idx_0; i8++) {
        layers->data[i8 + (layers->size[0] << 1)] = roughs->data[i8];
      }

      emxFree_real_T(&roughs);
      break;
    }

    /* Deal with the %coverage if present */
  }

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  loop_ub = layers->size[0];
  b_loop_ub = layers->size[1];
  i8 = outLayers->size[0] * outLayers->size[1];
  outLayers->size[0] = loop_ub;
  outLayers->size[1] = 3;
  emxEnsureCapacity(sp, (emxArray__common *)outLayers, i8, (int32_T)sizeof
                    (real_T), &f_emlrtRTEI);
  for (i8 = 0; i8 < 3; i8++) {
    for (kstr = 0; kstr < loop_ub; kstr++) {
      roughs_idx_0 = 1 + i8;
      if (!(roughs_idx_0 <= b_loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(roughs_idx_0, 1, b_loop_ub, &jc_emlrtBCI,
          sp);
      }

      outLayers->data[kstr + outLayers->size[0] * i8] = layers->data[kstr +
        layers->size[0] * (roughs_idx_0 - 1)];
    }
  }

  emxFree_real_T(&layers);
  *outSsubs = rsub;

  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (groupLayers_Mod.c) */
