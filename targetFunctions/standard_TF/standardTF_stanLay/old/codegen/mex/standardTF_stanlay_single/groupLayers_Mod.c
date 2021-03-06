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
#include "standardTF_stanlay_single.h"
#include "groupLayers_Mod.h"
#include "standardTF_stanlay_single_emxutil.h"
#include "indexShapeCheck.h"
#include "standardTF_stanlay_single_data.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = { 45,  /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 49,  /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 51,  /* lineNo */
  "groupLayers_Mod",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = { 1, /* lineNo */
  34,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 34,/* lineNo */
  5,                                   /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 41,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 42,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 43,/* lineNo */
  17,                                  /* colNo */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"/* pName */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  35,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  34,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  24,                                  /* colNo */
  "roughs",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  35,                                  /* colNo */
  "roughs",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  35,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  37,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  29,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  87,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  30,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  22,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  27,                                  /* colNo */
  "output",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  85,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  28,                                  /* colNo */
  "layers",                            /* aName */
  "groupLayers_Mod",                   /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
                     real_T allRoughs, const emxArray_char_T *geometry, real_T
                     nbair, real_T nbsubs, emxArray_real_T *outLayers, real_T
                     *outSsubs)
{
  emxArray_real_T *layers;
  real_T rsub;
  int32_T i4;
  boolean_T b_bool;
  int32_T kstr;
  int32_T loop_ub;
  int32_T exitg2;
  static const char_T cv0[23] = { 'A', 'i', 'r', ' ', '/', ' ', 'L', 'i', 'q',
    'u', 'i', 'd', ' ', '(', 'o', 'r', ' ', 's', 'o', 'l', 'i', 'd', ')' };

  emxArray_real_T *sldss;
  int32_T exitg1;
  uint32_T n[2];
  static const char_T cv1[14] = { 'S', 'o', 'l', 'i', 'd', ' ', '/', ' ', 'L',
    'i', 'q', 'u', 'i', 'd' };

  int32_T b_loop_ub;
  int32_T c_loop_ub;
  emxArray_real_T *thicks;
  real_T pc_add;
  emxArray_real_T *b_allLayers;
  int32_T iv4[2];
  emxArray_real_T *roughs;
  int32_T roughs_idx_0;
  emxArray_real_T *c_allLayers;
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
  emxInit_real_T(sp, &layers, 2, &k_emlrtRTEI, true);

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
  i4 = layers->size[0] * layers->size[1];
  layers->size[0] = 0;
  layers->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)layers, i4, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  if (!((allLayers->size[0] == 0) || (allLayers->size[1] == 0))) {
    b_bool = false;
    if (geometry->size[1] == 23) {
      kstr = 0;
      do {
        exitg2 = 0;
        if (kstr + 1 < 24) {
          if (geometry->data[kstr] != cv0[kstr]) {
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
        kstr = 1;
      } else {
        kstr = -1;
      }
    }

    switch (kstr) {
     case 0:
      i4 = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = allLayers->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)layers, i4, (int32_T)sizeof
                        (real_T), &j_emlrtRTEI);
      loop_ub = allLayers->size[0] * allLayers->size[1];
      for (i4 = 0; i4 < loop_ub; i4++) {
        layers->data[i4] = allLayers->data[i4];
      }

      /* s_sub = rsub; */
      break;

     case 1:
      emxInit_real_T1(sp, &sldss, 1, &m_emlrtRTEI, true);
      i4 = allLayers->size[1];
      if (!(3 <= i4)) {
        emlrtDynamicBoundsCheckR2012b(3, 1, i4, &pc_emlrtBCI, sp);
      }

      i4 = allLayers->size[1];
      if (!(2 <= i4)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i4, &qc_emlrtBCI, sp);
      }

      loop_ub = allLayers->size[0];
      i4 = sldss->size[0];
      sldss->size[0] = loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)sldss, i4, (int32_T)sizeof
                        (real_T), &j_emlrtRTEI);
      for (i4 = 0; i4 < loop_ub; i4++) {
        sldss->data[i4] = allLayers->data[i4 + allLayers->size[0]];
      }

      emxInit_real_T1(sp, &thicks, 1, &n_emlrtRTEI, true);
      loop_ub = allLayers->size[0];
      i4 = thicks->size[0];
      thicks->size[0] = loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)thicks, i4, (int32_T)sizeof
                        (real_T), &j_emlrtRTEI);
      for (i4 = 0; i4 < loop_ub; i4++) {
        thicks->data[i4] = allLayers->data[i4];
      }

      i4 = allLayers->size[0];
      b_loop_ub = allLayers->size[0];
      if (!((i4 >= 1) && (i4 <= b_loop_ub))) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, b_loop_ub, &rc_emlrtBCI, sp);
      }

      rsub = allLayers->data[(i4 + (allLayers->size[0] << 1)) - 1];
      i4 = allLayers->size[0];
      if (1 > i4 - 1) {
        loop_ub = 0;
      } else {
        loop_ub = allLayers->size[0] - 1;
        i4 = allLayers->size[0];
        if (!((loop_ub >= 1) && (loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &sc_emlrtBCI, sp);
        }
      }

      emxInit_real_T1(sp, &b_allLayers, 1, &j_emlrtRTEI, true);
      i4 = allLayers->size[0];
      iv4[0] = 1;
      iv4[1] = loop_ub;
      st.site = &j_emlrtRSI;
      indexShapeCheck(&st, i4, iv4);
      kstr = allLayers->size[0];
      i4 = b_allLayers->size[0];
      b_allLayers->size[0] = kstr;
      emxEnsureCapacity(sp, (emxArray__common *)b_allLayers, i4, (int32_T)sizeof
                        (real_T), &j_emlrtRTEI);
      for (i4 = 0; i4 < kstr; i4++) {
        b_allLayers->data[i4] = allLayers->data[i4 + (allLayers->size[0] << 1)];
      }

      emxInit_real_T1(sp, &roughs, 1, &l_emlrtRTEI, true);
      i4 = roughs->size[0];
      roughs->size[0] = loop_ub + 1;
      emxEnsureCapacity(sp, (emxArray__common *)roughs, i4, (int32_T)sizeof
                        (real_T), &j_emlrtRTEI);
      roughs->data[0] = allRoughs;
      for (i4 = 0; i4 < loop_ub; i4++) {
        roughs->data[i4 + 1] = b_allLayers->data[i4];
      }

      emxFree_real_T(&b_allLayers);
      if (allLayers->size[1] == 5) {
        st.site = &k_emlrtRSI;
        b_st.site = &n_emlrtRSI;
        kstr = allLayers->size[0];
        c_st.site = &o_emlrtRSI;
        i4 = allLayers->size[0];
        b_bool = (kstr == i4);
        if (!b_bool) {
          emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        i4 = allLayers->size[0];
        if (kstr != i4) {
          b_bool = false;
        }

        if (!b_bool) {
          emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        roughs_idx_0 = roughs->size[0];
        if (kstr != roughs_idx_0) {
          b_bool = false;
        }

        if (!b_bool) {
          emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        i4 = allLayers->size[0];
        if (kstr != i4) {
          b_bool = false;
        }

        if (!b_bool) {
          emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        emxInit_real_T1(&c_st, &c_allLayers, 1, &j_emlrtRTEI, true);
        loop_ub = allLayers->size[0];
        kstr = allLayers->size[0];
        b_loop_ub = allLayers->size[0];
        roughs_idx_0 = roughs->size[0];
        c_loop_ub = allLayers->size[0];
        i4 = c_allLayers->size[0];
        c_allLayers->size[0] = c_loop_ub;
        emxEnsureCapacity(sp, (emxArray__common *)c_allLayers, i4, (int32_T)
                          sizeof(real_T), &j_emlrtRTEI);
        for (i4 = 0; i4 < c_loop_ub; i4++) {
          c_allLayers->data[i4] = allLayers->data[i4 + allLayers->size[0] * 3];
        }

        i4 = layers->size[0] * layers->size[1];
        layers->size[0] = loop_ub;
        layers->size[1] = 4;
        emxEnsureCapacity(sp, (emxArray__common *)layers, i4, (int32_T)sizeof
                          (real_T), &j_emlrtRTEI);
        for (i4 = 0; i4 < loop_ub; i4++) {
          layers->data[i4] = thicks->data[i4];
        }

        for (i4 = 0; i4 < kstr; i4++) {
          layers->data[i4 + layers->size[0]] = sldss->data[i4];
        }

        for (i4 = 0; i4 < roughs_idx_0; i4++) {
          layers->data[i4 + (layers->size[0] << 1)] = roughs->data[i4];
        }

        for (i4 = 0; i4 < b_loop_ub; i4++) {
          layers->data[i4 + layers->size[0] * 3] = c_allLayers->data[i4];
        }

        emxFree_real_T(&c_allLayers);
      } else {
        st.site = &l_emlrtRSI;
        b_st.site = &n_emlrtRSI;
        kstr = allLayers->size[0];
        c_st.site = &o_emlrtRSI;
        i4 = allLayers->size[0];
        b_bool = (kstr == i4);
        if (!b_bool) {
          emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        i4 = allLayers->size[0];
        if (kstr != i4) {
          b_bool = false;
        }

        if (!b_bool) {
          emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        roughs_idx_0 = roughs->size[0];
        if (kstr != roughs_idx_0) {
          b_bool = false;
        }

        if (!b_bool) {
          emlrtErrorWithMessageIdR2012b(&c_st, &dc_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        loop_ub = allLayers->size[0];
        kstr = allLayers->size[0];
        roughs_idx_0 = roughs->size[0];
        i4 = layers->size[0] * layers->size[1];
        layers->size[0] = loop_ub;
        layers->size[1] = 3;
        emxEnsureCapacity(sp, (emxArray__common *)layers, i4, (int32_T)sizeof
                          (real_T), &j_emlrtRTEI);
        for (i4 = 0; i4 < loop_ub; i4++) {
          layers->data[i4] = thicks->data[i4];
        }

        for (i4 = 0; i4 < kstr; i4++) {
          layers->data[i4 + layers->size[0]] = sldss->data[i4];
        }

        for (i4 = 0; i4 < roughs_idx_0; i4++) {
          layers->data[i4 + (layers->size[0] << 1)] = roughs->data[i4];
        }
      }

      emxFree_real_T(&thicks);
      emxFree_real_T(&sldss);
      emxFree_real_T(&roughs);
      break;
    }

    /* Deal with the %coverage if present */
    for (i4 = 0; i4 < 2; i4++) {
      n[i4] = (uint32_T)allLayers->size[i4];
    }

    if ((int32_T)n[1] == 5) {
      kstr = 0;
      while (kstr <= (int32_T)n[0] - 1) {
        i4 = allLayers->size[1];
        if (!(4 <= i4)) {
          emlrtDynamicBoundsCheckR2012b(4, 1, i4, &uc_emlrtBCI, sp);
        }

        i4 = allLayers->size[0];
        b_loop_ub = kstr + 1;
        if (!((b_loop_ub >= 1) && (b_loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i4, &tc_emlrtBCI, sp);
        }

        i4 = allLayers->size[1];
        if (!(5 <= i4)) {
          emlrtDynamicBoundsCheckR2012b(5, 1, i4, &vc_emlrtBCI, sp);
        }

        i4 = allLayers->size[0];
        b_loop_ub = 1 + kstr;
        if (!((b_loop_ub >= 1) && (b_loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i4, &ad_emlrtBCI, sp);
        }

        if (allLayers->data[(b_loop_ub + (allLayers->size[0] << 2)) - 1] == 1.0)
        {
          pc_add = nbsubs;
        } else {
          pc_add = nbair;
        }

        if (!muDoubleScalarIsNaN(allLayers->data[kstr + allLayers->size[0] * 3]))
        {
          i4 = layers->size[1];
          if (!(2 <= i4)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i4, &xc_emlrtBCI, sp);
          }

          i4 = layers->size[1];
          if (!(2 <= i4)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i4, &wc_emlrtBCI, sp);
          }

          i4 = layers->size[0];
          b_loop_ub = 1 + kstr;
          if (!((b_loop_ub >= 1) && (b_loop_ub <= i4))) {
            emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i4, &bd_emlrtBCI, sp);
          }

          i4 = layers->size[0];
          c_loop_ub = 1 + kstr;
          if (!((c_loop_ub >= 1) && (c_loop_ub <= i4))) {
            emlrtDynamicBoundsCheckR2012b(c_loop_ub, 1, i4, &cd_emlrtBCI, sp);
          }

          layers->data[(c_loop_ub + layers->size[0]) - 1] = pc_add *
            (allLayers->data[kstr + allLayers->size[0] * 3] / 100.0) + (1.0 -
            allLayers->data[kstr + allLayers->size[0] * 3] / 100.0) *
            layers->data[(b_loop_ub + layers->size[0]) - 1];
        }

        kstr++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    }
  }

  /*      problem.layers{i} = layers; */
  /*      problem.ssubs(i) = s_sub; */
  loop_ub = layers->size[0];
  kstr = layers->size[1];
  i4 = outLayers->size[0] * outLayers->size[1];
  outLayers->size[0] = loop_ub;
  outLayers->size[1] = 3;
  emxEnsureCapacity(sp, (emxArray__common *)outLayers, i4, (int32_T)sizeof
                    (real_T), &j_emlrtRTEI);
  for (i4 = 0; i4 < 3; i4++) {
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      c_loop_ub = 1 + i4;
      if (!(c_loop_ub <= kstr)) {
        emlrtDynamicBoundsCheckR2012b(c_loop_ub, 1, kstr, &yc_emlrtBCI, sp);
      }

      outLayers->data[b_loop_ub + outLayers->size[0] * i4] = layers->
        data[b_loop_ub + layers->size[0] * (c_loop_ub - 1)];
    }
  }

  emxFree_real_T(&layers);
  *outSsubs = rsub;

  /* end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (groupLayers_Mod.c) */
