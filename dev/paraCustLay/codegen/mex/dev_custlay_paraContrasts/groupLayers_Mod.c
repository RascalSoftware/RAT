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
#include "dev_custlay_paraContrasts_data.h"
#include "dev_custlay_paraContrasts_emxutil.h"
#include "dev_custlay_paraContrasts_types.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = {
    65,                /* lineNo */
    "groupLayers_Mod", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    63,                /* lineNo */
    "groupLayers_Mod", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    56,                /* lineNo */
    "groupLayers_Mod", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    47,                /* lineNo */
    "groupLayers_Mod", /* fcnName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI =
    {
        63,       /* lineNo */
        "strcmp", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
        "strcmp.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI =
    {
        138,          /* lineNo */
        "loc_strcmp", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
        "strcmp.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI =
    {
        216,       /* lineNo */
        "charcmp", /* fcnName */
        "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
        "strcmp.m" /* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    15,                      /* lineNo */
    9,                       /* colNo */
    "assertSupportedString", /* fName */
    "/Applications/MATLAB_R2021a.app/toolbox/eml/eml/+coder/+internal/"
    "assertSupportedString.m" /* pName */
};

static emlrtBCInfo hd_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    51,                /* lineNo */
    35,                /* colNo */
    "output",          /* aName */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    52,                /* lineNo */
    34,                /* colNo */
    "output",          /* aName */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    56,                /* lineNo */
    48,                /* colNo */
    "roughs",          /* aName */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = {
    2,                 /* nDims */
    45,                /* lineNo */
    5,                 /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtECInfo f_emlrtECI = {
    2,                 /* nDims */
    48,                /* lineNo */
    17,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtBCInfo kd_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    82,                /* lineNo */
    30,                /* colNo */
    "layers",          /* aName */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    90,                /* lineNo */
    26,                /* colNo */
    "layers",          /* aName */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    75,                /* lineNo */
    28,                /* colNo */
    "output",          /* aName */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    76,                /* lineNo */
    20,                /* colNo */
    "output",          /* aName */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    82,                /* lineNo */
    78,                /* colNo */
    "layers",          /* aName */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m", /* pName */
    0                    /* checkKind */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    45,                /* lineNo */
    14,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    92,                /* lineNo */
    5,                 /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    90,                /* lineNo */
    5,                 /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = {
    48,                /* lineNo */
    17,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = {
    58,                /* lineNo */
    21,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    56,                /* lineNo */
    21,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    65,                /* lineNo */
    21,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    63,                /* lineNo */
    21,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    45,                /* lineNo */
    5,                 /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    51,                /* lineNo */
    17,                /* colNo */
    "groupLayers_Mod", /* fName */
    "/Users/arwel/Documents/coding/RAT/targetFunctions/common/groupLayers/"
    "groupLayers_Mod.m" /* pName */
};

/* Function Definitions */
void groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
                     real_T allRoughs, const emxArray_char_T *geometry,
                     real_T nbair, real_T nbsubs, emxArray_real_T *outLayers,
                     real_T *outSsubs)
{
  static const char_T cv[128] = {
      '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
      '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10', '\x11',
      '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
      '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
      '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
      '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
      '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
      '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
      'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
      'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
      'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
      'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
      'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
      'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
      '~',    '\x7f'};
  static const char_T cv1[13] = {'a', 'i', 'r', '/', 's', 'u', 'b',
                                 's', 't', 'r', 'a', 't', 'e'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *layers;
  emxArray_real_T *roughs;
  real_T pc_add;
  real_T this_pcw;
  int32_T iv[2];
  int32_T b_loop_ub;
  int32_T exitg1;
  int32_T i;
  int32_T kstr;
  int32_T loop_ub;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &layers, 2, &yc_emlrtRTEI, true);
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
  layers->size[1] = allLayers->size[1];
  emxEnsureCapacity_real_T(sp, layers, i, &qc_emlrtRTEI);
  loop_ub = allLayers->size[0] * allLayers->size[1];
  for (i = 0; i < loop_ub; i++) {
    layers->data[i] = 0.0;
  }
  if (5 < allLayers->size[1]) {
    emlrtDimSizeGeqCheckR2012b(5, allLayers->size[1], &e_emlrtECI,
                               (emlrtCTX)sp);
  }
  if ((allLayers->size[0] != 0) && (allLayers->size[1] != 0)) {
    st.site = &n_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    c_st.site = &p_emlrtRSI;
    b_bool = false;
    if (geometry->size[1] == 13) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 13) {
          d_st.site = &q_emlrtRSI;
          i = (uint8_T)geometry->data[kstr];
          if (i > 127) {
            emlrtErrorWithMessageIdR2018a(
                &d_st, &g_emlrtRTEI, "Coder:toolbox:unsupportedString",
                "Coder:toolbox:unsupportedString", 2, 12, 127);
          }
          if (cv[i] != cv[(int32_T)cv1[kstr]]) {
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
      if (5 < allLayers->size[1]) {
        emlrtDimSizeGeqCheckR2012b(5, allLayers->size[1], &f_emlrtECI,
                                   (emlrtCTX)sp);
      }
      i = layers->size[0] * layers->size[1];
      layers->size[0] = allLayers->size[0];
      layers->size[1] = allLayers->size[1];
      emxEnsureCapacity_real_T(sp, layers, i, &tc_emlrtRTEI);
      loop_ub = allLayers->size[0] * allLayers->size[1];
      for (i = 0; i < loop_ub; i++) {
        layers->data[i] = allLayers->data[i];
      }
      /* s_sub = rsub; */
    } else {
      if (3 > allLayers->size[1]) {
        emlrtDynamicBoundsCheckR2012b(3, 1, allLayers->size[1], &hd_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (2 > allLayers->size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, allLayers->size[1], &id_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      *outSsubs =
          allLayers->data[(allLayers->size[0] + allLayers->size[0] * 2) - 1];
      emxInit_real_T(sp, &roughs, 1, &ad_emlrtRTEI, true);
      if (allLayers->size[0] > 1) {
        if (allLayers->size[0] - 1 > allLayers->size[0]) {
          emlrtDynamicBoundsCheckR2012b(allLayers->size[0] - 1, 1,
                                        allLayers->size[0], &jd_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        iv[0] = 1;
        iv[1] = allLayers->size[0] - 1;
        st.site = &m_emlrtRSI;
        indexShapeCheck(&st, allLayers->size[0], iv);
        loop_ub = allLayers->size[0];
        i = roughs->size[0];
        roughs->size[0] = allLayers->size[0];
        emxEnsureCapacity_real_T(sp, roughs, i, &vc_emlrtRTEI);
        roughs->data[0] = allRoughs;
        for (i = 0; i <= loop_ub - 2; i++) {
          roughs->data[i + 1] = allLayers->data[i + allLayers->size[0] * 2];
        }
      } else {
        i = roughs->size[0];
        roughs->size[0] = 1;
        emxEnsureCapacity_real_T(sp, roughs, i, &uc_emlrtRTEI);
        roughs->data[0] = allRoughs;
      }
      if (allLayers->size[1] == 5) {
        st.site = &l_emlrtRSI;
        b_st.site = &w_emlrtRSI;
        c_st.site = &x_emlrtRSI;
        if (roughs->size[0] != allLayers->size[0]) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &h_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        loop_ub = allLayers->size[0];
        kstr = allLayers->size[0];
        b_loop_ub = allLayers->size[0];
        i = layers->size[0] * layers->size[1];
        layers->size[0] = allLayers->size[0];
        layers->size[1] = 4;
        emxEnsureCapacity_real_T(sp, layers, i, &xc_emlrtRTEI);
        for (i = 0; i < loop_ub; i++) {
          layers->data[i] = allLayers->data[i];
        }
        for (i = 0; i < kstr; i++) {
          layers->data[i + layers->size[0]] =
              allLayers->data[i + allLayers->size[0]];
        }
        loop_ub = roughs->size[0];
        for (i = 0; i < loop_ub; i++) {
          layers->data[i + layers->size[0] * 2] = roughs->data[i];
        }
        for (i = 0; i < b_loop_ub; i++) {
          layers->data[i + layers->size[0] * 3] =
              allLayers->data[i + allLayers->size[0] * 3];
        }
      } else {
        st.site = &k_emlrtRSI;
        b_st.site = &w_emlrtRSI;
        c_st.site = &x_emlrtRSI;
        if (roughs->size[0] != allLayers->size[0]) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &h_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        loop_ub = allLayers->size[0];
        kstr = allLayers->size[0];
        i = layers->size[0] * layers->size[1];
        layers->size[0] = allLayers->size[0];
        layers->size[1] = 3;
        emxEnsureCapacity_real_T(sp, layers, i, &wc_emlrtRTEI);
        for (i = 0; i < loop_ub; i++) {
          layers->data[i] = allLayers->data[i];
        }
        for (i = 0; i < kstr; i++) {
          layers->data[i + layers->size[0]] =
              allLayers->data[i + allLayers->size[0]];
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
      for (kstr = 0; kstr < i; kstr++) {
        if (kstr + 1 > allLayers->size[0]) {
          emlrtDynamicBoundsCheckR2012b(kstr + 1, 1, allLayers->size[0],
                                        &md_emlrtBCI, (emlrtCTX)sp);
        }
        this_pcw = allLayers->data[kstr + allLayers->size[0] * 3];
        if (kstr + 1 > allLayers->size[0]) {
          emlrtDynamicBoundsCheckR2012b(kstr + 1, 1, allLayers->size[0],
                                        &nd_emlrtBCI, (emlrtCTX)sp);
        }
        if (allLayers->data[kstr + allLayers->size[0] * 4] == 1.0) {
          pc_add = nbair;
        } else {
          pc_add = nbsubs;
        }
        if (!muDoubleScalarIsNaN(this_pcw)) {
          if (2 > layers->size[1]) {
            emlrtDynamicBoundsCheckR2012b(2, 1, layers->size[1], &kd_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (kstr + 1 > layers->size[0]) {
            emlrtDynamicBoundsCheckR2012b(kstr + 1, 1, layers->size[0],
                                          &od_emlrtBCI, (emlrtCTX)sp);
          }
          layers->data[kstr + layers->size[0]] =
              pc_add * (this_pcw / 100.0) +
              (1.0 - this_pcw / 100.0) * layers->data[kstr + layers->size[0]];
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
    emxEnsureCapacity_real_T(sp, outLayers, i, &sc_emlrtRTEI);
    for (i = 0; i < 3; i++) {
      for (kstr = 0; kstr < loop_ub; kstr++) {
        if (i + 1 > layers->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, layers->size[1], &ld_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        outLayers->data[kstr + outLayers->size[0] * i] =
            layers->data[kstr + layers->size[0] * i];
      }
    }
  } else {
    i = outLayers->size[0] * outLayers->size[1];
    outLayers->size[0] = 1;
    outLayers->size[1] = 3;
    emxEnsureCapacity_real_T(sp, outLayers, i, &rc_emlrtRTEI);
    outLayers->data[0] = 0.0;
    outLayers->data[1] = 0.0;
    outLayers->data[2] = 0.0;
  }
  emxFree_real_T(&layers);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (groupLayers_Mod.c) */
