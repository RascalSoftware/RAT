//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  groupLayers_Mod.cpp
//
//  Code generation for function 'groupLayers_Mod'
//


// Include files
#include "groupLayers_Mod.h"
#include "indexShapeCheck.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_mexutil.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo t_emlrtRSI = { 48,  // lineNo
  "groupLayers_Mod",                   // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pathName 
};

static emlrtRSInfo u_emlrtRSI = { 56,  // lineNo
  "groupLayers_Mod",                   // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pathName 
};

static emlrtRSInfo v_emlrtRSI = { 60,  // lineNo
  "groupLayers_Mod",                   // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pathName 
};

static emlrtRSInfo ch_emlrtRSI = { 62, // lineNo
  "groupLayers_Mod",                   // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pathName 
};

static emlrtBCInfo se_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  56,                                  // lineNo
  44,                                  // colNo
  "roughs",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo te_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  55,                                  // lineNo
  24,                                  // colNo
  "roughs",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ue_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  28,                                  // colNo
  "output",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ve_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  20,                                  // colNo
  "output",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo we_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  78,                                  // colNo
  "layers",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  21,                                  // colNo
  "layers",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bm_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  52,                                  // lineNo
  35,                                  // colNo
  "output",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo cm_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  53,                                  // lineNo
  34,                                  // colNo
  "output",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo y_emlrtECI = { 2,   // nDims
  46,                                  // lineNo
  5,                                   // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtECInfo ab_emlrtECI = { 2,  // nDims
  49,                                  // lineNo
  17,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtBCInfo dm_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  30,                                  // colNo
  "layers",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo em_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  87,                                  // lineNo
  26,                                  // colNo
  "layers",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo xg_emlrtRTEI = { 46,// lineNo
  5,                                   // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo yg_emlrtRTEI = { 56,// lineNo
  17,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo ah_emlrtRTEI = { 60,// lineNo
  21,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo bh_emlrtRTEI = { 49,// lineNo
  17,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo ch_emlrtRTEI = { 89,// lineNo
  5,                                   // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo dh_emlrtRTEI = { 87,// lineNo
  5,                                   // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo hm_emlrtRTEI = { 62,// lineNo
  21,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

// Function Definitions
void b_groupLayers_Mod(const emlrtStack *sp, const coder::array<real_T, 2U>
  &allLayers, real_T allRoughs, const coder::array<char_T, 2U> &geometry, real_T
  nbair, real_T nbsubs, coder::array<real_T, 2U> &outLayers, real_T *outSsubs)
{
  uint32_T unnamed_idx_0;
  uint32_T unnamed_idx_1;
  coder::array<real_T, 2U> layers;
  int32_T loop_ub;
  int32_T i;
  int32_T i1;
  int32_T b_loop_ub;
  int32_T iv[2];
  coder::array<real_T, 1U> roughs;
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

  // Arrange layers according to geometry and apply any coverage correction.
  //
  // [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs) 
  //  Inputs:
  //      allLayers = cell array, one for each contrast. Each cell is the
  //                  list of layer values for each contrast.
  //                  e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which
  //                                       d2, rho2, r2, %hyd2, hyd_which_2..
  //                                       etc]
  //      allRoughs = Double of substrate roughness for each contrast.
  //      numberOfContrasts = double.
  //      geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid'
  //      nbairs = vector of nbair values.
  //      nbsubs = vector of nbsub values.
  //
  //      The paratt calculation procedds through the
  //      z,rho,rough stack, and the parameter 'ssub' in
  //      callParatt is the final roughness encountered.
  //      For air liquid 'ssub' is therefore the substrate roughness.
  //      For solid liquid, the substrate roughness is the first roughness
  //      encountered, and 'ssub' is then the roughness of the outermost layer.
  //      The rougnesses need to be arranged accordingly.
  //
  //
  //  Outputs:
  //      outLayers = cell array of layers param values for each contrast.
  //                  e.g. outLayers{1} = [d1 rho1 r1;
  //                                       d2 rho2 r2
  //                                       ... etc   ]
  //      outSsubs = vector of substrate roughness values.
  //
  // outLayers = cell(1,numberOfContrasts);
  // outSsubs = zeros(1,numberOfContrasts);
  // for i = 1:numberOfContrasts
  *outSsubs = allRoughs;
  unnamed_idx_0 = static_cast<uint32_T>(allLayers.size(0));
  unnamed_idx_1 = static_cast<uint32_T>(allLayers.size(1));
  if (5 < static_cast<int32_T>(unnamed_idx_1)) {
    emlrtDimSizeGeqCheckR2012b(5, static_cast<int32_T>(unnamed_idx_1),
      &y_emlrtECI, sp);
  }

  layers.set_size((&xg_emlrtRTEI), sp, (static_cast<int32_T>(unnamed_idx_0)), (
    static_cast<int32_T>(unnamed_idx_1)));
  loop_ub = static_cast<int32_T>(unnamed_idx_0) * static_cast<int32_T>
    (unnamed_idx_1);
  for (i = 0; i < loop_ub; i++) {
    layers[i] = 0.0;
  }

  if ((allLayers.size(0) != 0) && (allLayers.size(1) != 0)) {
    int32_T c_loop_ub;
    st.site = &t_emlrtRSI;
    if (b_strcmp(&st, geometry)) {
      if (5 < allLayers.size(1)) {
        emlrtDimSizeGeqCheckR2012b(5, allLayers.size(1), &ab_emlrtECI, sp);
      }

      layers.set_size((&bh_emlrtRTEI), sp, allLayers.size(0), allLayers.size(1));
      loop_ub = allLayers.size(0) * allLayers.size(1);
      for (i = 0; i < loop_ub; i++) {
        layers[i] = allLayers[i];
      }

      // s_sub = rsub;
    } else {
      if (3 > allLayers.size(1)) {
        emlrtDynamicBoundsCheckR2012b(3, 1, allLayers.size(1), &bm_emlrtBCI, sp);
      }

      if (2 > allLayers.size(1)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, allLayers.size(1), &cm_emlrtBCI, sp);
      }

      if (allLayers.size(0) < 1) {
        emlrtDynamicBoundsCheckR2012b(allLayers.size(0), 1, allLayers.size(0),
          &te_emlrtBCI, sp);
      }

      *outSsubs = allLayers[(allLayers.size(0) + allLayers.size(0) * 2) - 1];
      if (1 > allLayers.size(0) - 1) {
        loop_ub = 0;
      } else {
        loop_ub = allLayers.size(0) - 1;
        if ((loop_ub < 1) || (loop_ub > allLayers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, allLayers.size(0),
            &se_emlrtBCI, sp);
        }
      }

      iv[0] = 1;
      iv[1] = loop_ub;
      st.site = &u_emlrtRSI;
      indexShapeCheck(&st, allLayers.size(0), iv);
      roughs.set_size((&yg_emlrtRTEI), sp, (loop_ub + 1));
      roughs[0] = allRoughs;
      for (i = 0; i < loop_ub; i++) {
        roughs[i + 1] = allLayers[i + allLayers.size(0) * 2];
      }

      if (allLayers.size(1) == 5) {
        st.site = &v_emlrtRSI;
        b_st.site = &fb_emlrtRSI;
        c_st.site = &gb_emlrtRSI;
        if (roughs.size(0) != allLayers.size(0)) {
          emlrtErrorWithMessageIdR2018a(&c_st, &nb_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch",
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        loop_ub = allLayers.size(0);
        b_loop_ub = allLayers.size(0);
        c_loop_ub = allLayers.size(0);
        layers.set_size((&ah_emlrtRTEI), sp, allLayers.size(0), 4);
        for (i = 0; i < loop_ub; i++) {
          layers[i] = allLayers[i];
        }

        for (i = 0; i < b_loop_ub; i++) {
          layers[i + layers.size(0)] = allLayers[i + allLayers.size(0)];
        }

        loop_ub = roughs.size(0);
        for (i = 0; i < loop_ub; i++) {
          layers[i + layers.size(0) * 2] = roughs[i];
        }

        for (i = 0; i < c_loop_ub; i++) {
          layers[i + layers.size(0) * 3] = allLayers[i + allLayers.size(0) * 3];
        }
      } else {
        st.site = &ch_emlrtRSI;
        b_st.site = &fb_emlrtRSI;
        c_st.site = &gb_emlrtRSI;
        if (roughs.size(0) != allLayers.size(0)) {
          emlrtErrorWithMessageIdR2018a(&c_st, &nb_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch",
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        loop_ub = allLayers.size(0);
        b_loop_ub = allLayers.size(0);
        layers.set_size((&hm_emlrtRTEI), sp, allLayers.size(0), 3);
        for (i = 0; i < loop_ub; i++) {
          layers[i] = allLayers[i];
        }

        for (i = 0; i < b_loop_ub; i++) {
          layers[i + layers.size(0)] = allLayers[i + allLayers.size(0)];
        }

        loop_ub = roughs.size(0);
        for (i = 0; i < loop_ub; i++) {
          layers[i + layers.size(0) * 2] = roughs[i];
        }
      }
    }

    // Deal with the %coverage if present
    if (allLayers.size(1) == 5) {
      i = allLayers.size(0);
      for (c_loop_ub = 0; c_loop_ub < i; c_loop_ub++) {
        real_T this_pcw;
        real_T pc_add;
        i1 = c_loop_ub + 1;
        if ((i1 < 1) || (i1 > allLayers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers.size(0), &ue_emlrtBCI,
            sp);
        }

        this_pcw = allLayers[(i1 + allLayers.size(0) * 3) - 1];
        i1 = c_loop_ub + 1;
        if ((i1 < 1) || (i1 > allLayers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers.size(0), &ve_emlrtBCI,
            sp);
        }

        if (allLayers[(i1 + allLayers.size(0) * 4) - 1] == 1.0) {
          pc_add = nbair;
        } else {
          pc_add = nbsubs;
        }

        if (!muDoubleScalarIsNaN(this_pcw)) {
          if (2 > layers.size(1)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, layers.size(1), &dm_emlrtBCI, sp);
          }

          i1 = c_loop_ub + 1;
          if ((i1 < 1) || (i1 > layers.size(0))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, layers.size(0), &we_emlrtBCI,
              sp);
          }

          b_loop_ub = c_loop_ub + 1;
          if ((b_loop_ub < 1) || (b_loop_ub > layers.size(0))) {
            emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, layers.size(0),
              &xe_emlrtBCI, sp);
          }

          layers[(b_loop_ub + layers.size(0)) - 1] = pc_add * (this_pcw / 100.0)
            + (1.0 - this_pcw / 100.0) * layers[(i1 + layers.size(0)) - 1];
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    }
  }

  //      problem.layers{i} = layers;
  //      problem.ssubs(i) = s_sub;
  if ((layers.size(0) != 0) && (layers.size(1) != 0)) {
    loop_ub = layers.size(0);
    outLayers.set_size((&dh_emlrtRTEI), sp, layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = i + 1;
        if (b_loop_ub > layers.size(1)) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, layers.size(1),
            &em_emlrtBCI, sp);
        }

        outLayers[i1 + outLayers.size(0) * i] = layers[i1 + layers.size(0) *
          (b_loop_ub - 1)];
      }
    }
  } else {
    outLayers.set_size((&ch_emlrtRTEI), sp, 1, 3);
    outLayers[0] = 0.0;
    outLayers[1] = 0.0;
    outLayers[2] = 0.0;
  }

  // end
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void groupLayers_Mod(const emlrtStack *sp, const coder::array<real_T, 2U>
                     &allLayers, real_T allRoughs, const coder::array<char_T, 2U>
                     &geometry, real_T nbair, real_T nbsubs, coder::array<real_T,
                     2U> &outLayers, real_T *outSsubs)
{
  uint32_T unnamed_idx_0;
  coder::array<real_T, 2U> layers;
  int32_T loop_ub;
  int32_T i;
  int32_T iv[2];
  int32_T i1;
  coder::array<real_T, 1U> roughs;
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

  // Arrange layers according to geometry and apply any coverage correction.
  //
  // [outLayers, outSsubs] = groupLayers_Mod(allLayers,allRoughs,numberOfContrasts,geometry,nbairs,nbsubs) 
  //  Inputs:
  //      allLayers = cell array, one for each contrast. Each cell is the
  //                  list of layer values for each contrast.
  //                  e.g. allLayers{1} = [d1, rho1, r1, %hyd, hyd_which
  //                                       d2, rho2, r2, %hyd2, hyd_which_2..
  //                                       etc]
  //      allRoughs = Double of substrate roughness for each contrast.
  //      numberOfContrasts = double.
  //      geometry =  'Air / Liquid (or solid)' or 'Solid / Liquid'
  //      nbairs = vector of nbair values.
  //      nbsubs = vector of nbsub values.
  //
  //      The paratt calculation procedds through the
  //      z,rho,rough stack, and the parameter 'ssub' in
  //      callParatt is the final roughness encountered.
  //      For air liquid 'ssub' is therefore the substrate roughness.
  //      For solid liquid, the substrate roughness is the first roughness
  //      encountered, and 'ssub' is then the roughness of the outermost layer.
  //      The rougnesses need to be arranged accordingly.
  //
  //
  //  Outputs:
  //      outLayers = cell array of layers param values for each contrast.
  //                  e.g. outLayers{1} = [d1 rho1 r1;
  //                                       d2 rho2 r2
  //                                       ... etc   ]
  //      outSsubs = vector of substrate roughness values.
  //
  // outLayers = cell(1,numberOfContrasts);
  // outSsubs = zeros(1,numberOfContrasts);
  // for i = 1:numberOfContrasts
  *outSsubs = allRoughs;
  unnamed_idx_0 = static_cast<uint32_T>(allLayers.size(0));
  layers.set_size((&xg_emlrtRTEI), sp, (static_cast<int32_T>(unnamed_idx_0)), 5);
  loop_ub = static_cast<int32_T>(unnamed_idx_0) * 5;
  for (i = 0; i < loop_ub; i++) {
    layers[i] = 0.0;
  }

  if (allLayers.size(0) != 0) {
    int32_T b_loop_ub;
    int32_T c_loop_ub;
    st.site = &t_emlrtRSI;
    if (b_strcmp(&st, geometry)) {
      layers.set_size((&bh_emlrtRTEI), sp, allLayers.size(0), 5);
      loop_ub = allLayers.size(0) * allLayers.size(1);
      for (i = 0; i < loop_ub; i++) {
        layers[i] = allLayers[i];
      }

      // s_sub = rsub;
    } else {
      if (allLayers.size(0) < 1) {
        emlrtDynamicBoundsCheckR2012b(allLayers.size(0), 1, allLayers.size(0),
          &te_emlrtBCI, sp);
      }

      *outSsubs = allLayers[(allLayers.size(0) + allLayers.size(0) * 2) - 1];
      if (1 > allLayers.size(0) - 1) {
        loop_ub = 0;
      } else {
        loop_ub = allLayers.size(0) - 1;
        if ((loop_ub < 1) || (loop_ub > allLayers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, allLayers.size(0),
            &se_emlrtBCI, sp);
        }
      }

      iv[0] = 1;
      iv[1] = loop_ub;
      st.site = &u_emlrtRSI;
      indexShapeCheck(&st, allLayers.size(0), iv);
      roughs.set_size((&yg_emlrtRTEI), sp, (loop_ub + 1));
      roughs[0] = allRoughs;
      for (i = 0; i < loop_ub; i++) {
        roughs[i + 1] = allLayers[i + allLayers.size(0) * 2];
      }

      st.site = &v_emlrtRSI;
      b_st.site = &fb_emlrtRSI;
      c_st.site = &gb_emlrtRSI;
      if (roughs.size(0) != allLayers.size(0)) {
        emlrtErrorWithMessageIdR2018a(&c_st, &nb_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      loop_ub = allLayers.size(0);
      c_loop_ub = allLayers.size(0);
      b_loop_ub = allLayers.size(0);
      layers.set_size((&ah_emlrtRTEI), sp, allLayers.size(0), 4);
      for (i = 0; i < loop_ub; i++) {
        layers[i] = allLayers[i];
      }

      for (i = 0; i < c_loop_ub; i++) {
        layers[i + layers.size(0)] = allLayers[i + allLayers.size(0)];
      }

      loop_ub = roughs.size(0);
      for (i = 0; i < loop_ub; i++) {
        layers[i + layers.size(0) * 2] = roughs[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        layers[i + layers.size(0) * 3] = allLayers[i + allLayers.size(0) * 3];
      }
    }

    // Deal with the %coverage if present
    i = allLayers.size(0);
    for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
      real_T this_pcw;
      real_T pc_add;
      i1 = b_loop_ub + 1;
      if ((i1 < 1) || (i1 > allLayers.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers.size(0), &ue_emlrtBCI, sp);
      }

      this_pcw = allLayers[(i1 + allLayers.size(0) * 3) - 1];
      i1 = b_loop_ub + 1;
      if ((i1 < 1) || (i1 > allLayers.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers.size(0), &ve_emlrtBCI, sp);
      }

      if (allLayers[(i1 + allLayers.size(0) * 4) - 1] == 1.0) {
        pc_add = nbair;
      } else {
        pc_add = nbsubs;
      }

      if (!muDoubleScalarIsNaN(this_pcw)) {
        i1 = b_loop_ub + 1;
        if ((i1 < 1) || (i1 > layers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, layers.size(0), &we_emlrtBCI, sp);
        }

        c_loop_ub = b_loop_ub + 1;
        if ((c_loop_ub < 1) || (c_loop_ub > layers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(c_loop_ub, 1, layers.size(0),
            &xe_emlrtBCI, sp);
        }

        layers[(c_loop_ub + layers.size(0)) - 1] = pc_add * (this_pcw / 100.0) +
          (1.0 - this_pcw / 100.0) * layers[(i1 + layers.size(0)) - 1];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  //      problem.layers{i} = layers;
  //      problem.ssubs(i) = s_sub;
  if (layers.size(0) != 0) {
    loop_ub = layers.size(0);
    outLayers.set_size((&dh_emlrtRTEI), sp, layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        outLayers[i1 + outLayers.size(0) * i] = layers[i1 + layers.size(0) * i];
      }
    }
  } else {
    outLayers.set_size((&ch_emlrtRTEI), sp, 1, 3);
    outLayers[0] = 0.0;
    outLayers[1] = 0.0;
    outLayers[2] = 0.0;
  }

  // end
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (groupLayers_Mod.cpp)
