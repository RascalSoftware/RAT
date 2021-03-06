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
#include "rt_nonfinite.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo s_emlrtRSI = { 57,  // lineNo
  "groupLayers_Mod",                   // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pathName 
};

static emlrtRSInfo t_emlrtRSI = { 61,  // lineNo
  "groupLayers_Mod",                   // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pathName 
};

static emlrtBCInfo le_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  57,                                  // lineNo
  44,                                  // colNo
  "roughs",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo me_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  56,                                  // lineNo
  24,                                  // colNo
  "roughs",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ne_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  28,                                  // colNo
  "output",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo oe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  74,                                  // lineNo
  20,                                  // colNo
  "output",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo pe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  78,                                  // colNo
  "layers",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo qe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  21,                                  // colNo
  "layers",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo bf_emlrtRTEI = { 46,// lineNo
  5,                                   // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo cf_emlrtRTEI = { 50,// lineNo
  17,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo df_emlrtRTEI = { 57,// lineNo
  17,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo ef_emlrtRTEI = { 61,// lineNo
  21,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo ff_emlrtRTEI = { 90,// lineNo
  5,                                   // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo gf_emlrtRTEI = { 88,// lineNo
  5,                                   // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

// Function Definitions
void groupLayers_Mod(const emlrtStack *sp, const coder::array<real_T, 2U>
                     &allLayers, real_T allRoughs, const coder::array<char_T, 2U>
                     &geometry, real_T nbair, real_T nbsubs, coder::array<real_T,
                     2U> &outLayers, real_T *outSsubs)
{
  uint32_T unnamed_idx_0;
  coder::array<real_T, 2U> layers;
  int32_T loop_ub;
  int32_T i;
  static const char_T cv[13] = { 'a', 'i', 'r', '/', 's', 'u', 'b', 's', 't',
    'r', 'a', 't', 'e' };

  int32_T i1;
  static const char_T cv1[16] = { 's', 'u', 'b', 's', 't', 'r', 'a', 't', 'e',
    '/', 'l', 'i', 'q', 'u', 'i', 'd' };

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
  layers.set_size((&bf_emlrtRTEI), sp, (static_cast<int32_T>(unnamed_idx_0)), 5);
  loop_ub = static_cast<int32_T>(unnamed_idx_0) * 5;
  for (i = 0; i < loop_ub; i++) {
    layers[i] = 0.0;
  }

  if (allLayers.size(0) != 0) {
    boolean_T b_bool;
    int32_T kstr;
    int32_T exitg1;
    int32_T b_loop_ub;
    b_bool = false;
    if (geometry.size(1) == 13) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 13) {
          if (geometry[kstr] != cv[kstr]) {
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
      if (geometry.size(1) == 16) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 16) {
            if (geometry[kstr] != cv1[kstr]) {
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
      layers.set_size((&cf_emlrtRTEI), sp, allLayers.size(0), 5);
      loop_ub = allLayers.size(0) * allLayers.size(1);
      for (i = 0; i < loop_ub; i++) {
        layers[i] = allLayers[i];
      }

      // s_sub = rsub;
      break;

     case 1:
      if (allLayers.size(0) < 1) {
        emlrtDynamicBoundsCheckR2012b(allLayers.size(0), 1, allLayers.size(0),
          &me_emlrtBCI, sp);
      }

      *outSsubs = allLayers[(allLayers.size(0) + allLayers.size(0) * 2) - 1];
      if (1 > allLayers.size(0) - 1) {
        loop_ub = 0;
      } else {
        loop_ub = allLayers.size(0) - 1;
        if ((loop_ub < 1) || (loop_ub > allLayers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, allLayers.size(0),
            &le_emlrtBCI, sp);
        }
      }

      iv[0] = 1;
      iv[1] = loop_ub;
      st.site = &s_emlrtRSI;
      indexShapeCheck(&st, allLayers.size(0), iv);
      roughs.set_size((&df_emlrtRTEI), sp, (loop_ub + 1));
      roughs[0] = allRoughs;
      for (i = 0; i < loop_ub; i++) {
        roughs[i + 1] = allLayers[i + allLayers.size(0) * 2];
      }

      st.site = &t_emlrtRSI;
      b_st.site = &v_emlrtRSI;
      c_st.site = &w_emlrtRSI;
      if (roughs.size(0) != allLayers.size(0)) {
        emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      loop_ub = allLayers.size(0);
      kstr = allLayers.size(0);
      b_loop_ub = allLayers.size(0);
      layers.set_size((&ef_emlrtRTEI), sp, allLayers.size(0), 4);
      for (i = 0; i < loop_ub; i++) {
        layers[i] = allLayers[i];
      }

      for (i = 0; i < kstr; i++) {
        layers[i + layers.size(0)] = allLayers[i + allLayers.size(0)];
      }

      loop_ub = roughs.size(0);
      for (i = 0; i < loop_ub; i++) {
        layers[i + layers.size(0) * 2] = roughs[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        layers[i + layers.size(0) * 3] = allLayers[i + allLayers.size(0) * 3];
      }
      break;
    }

    // Deal with the %coverage if present
    i = allLayers.size(0);
    for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
      real_T this_pcw;
      real_T pc_add;
      i1 = b_loop_ub + 1;
      if ((i1 < 1) || (i1 > allLayers.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers.size(0), &ne_emlrtBCI, sp);
      }

      this_pcw = allLayers[(i1 + allLayers.size(0) * 3) - 1];
      i1 = b_loop_ub + 1;
      if ((i1 < 1) || (i1 > allLayers.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers.size(0), &oe_emlrtBCI, sp);
      }

      if (allLayers[(i1 + allLayers.size(0) * 4) - 1] == 1.0) {
        pc_add = nbsubs;
      } else {
        pc_add = nbair;
      }

      if (!muDoubleScalarIsNaN(this_pcw)) {
        i1 = b_loop_ub + 1;
        if ((i1 < 1) || (i1 > layers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, layers.size(0), &pe_emlrtBCI, sp);
        }

        kstr = b_loop_ub + 1;
        if ((kstr < 1) || (kstr > layers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, layers.size(0), &qe_emlrtBCI,
            sp);
        }

        layers[(kstr + layers.size(0)) - 1] = pc_add * (this_pcw / 100.0) + (1.0
          - this_pcw / 100.0) * layers[(i1 + layers.size(0)) - 1];
      }
    }
  }

  //      problem.layers{i} = layers;
  //      problem.ssubs(i) = s_sub;
  if (layers.size(0) != 0) {
    loop_ub = layers.size(0);
    outLayers.set_size((&gf_emlrtRTEI), sp, layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        outLayers[i1 + outLayers.size(0) * i] = layers[i1 + layers.size(0) * i];
      }
    }
  } else {
    outLayers.set_size((&ff_emlrtRTEI), sp, 1, 3);
    outLayers[0] = 0.0;
    outLayers[1] = 0.0;
    outLayers[2] = 0.0;
  }

  // end
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (groupLayers_Mod.cpp)
