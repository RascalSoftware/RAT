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
static emlrtRSInfo s_emlrtRSI = { 48,  // lineNo
  "groupLayers_Mod",                   // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pathName 
};

static emlrtRSInfo t_emlrtRSI = { 56,  // lineNo
  "groupLayers_Mod",                   // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pathName 
};

static emlrtRSInfo u_emlrtRSI = { 60,  // lineNo
  "groupLayers_Mod",                   // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pathName 
};

static emlrtRSInfo v_emlrtRSI = { 63,  // lineNo
  "strcmp",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

static emlrtRSInfo w_emlrtRSI = { 138, // lineNo
  "loc_strcmp",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

static emlrtRSInfo x_emlrtRSI = { 216, // lineNo
  "charcmp",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

static emlrtRTEInfo hb_emlrtRTEI = { 15,// lineNo
  9,                                   // colNo
  "assertSupportedString",             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/assertSupportedString.m"// pName 
};

static emlrtBCInfo je_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  56,                                  // lineNo
  44,                                  // colNo
  "roughs",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ke_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  55,                                  // lineNo
  24,                                  // colNo
  "roughs",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo le_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  28,                                  // colNo
  "output",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo me_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  20,                                  // colNo
  "output",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ne_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  78,                                  // colNo
  "layers",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo oe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  21,                                  // colNo
  "layers",                            // aName
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo ye_emlrtRTEI = { 46,// lineNo
  5,                                   // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo af_emlrtRTEI = { 56,// lineNo
  17,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo bf_emlrtRTEI = { 60,// lineNo
  21,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo cf_emlrtRTEI = { 49,// lineNo
  17,                                  // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo df_emlrtRTEI = { 89,// lineNo
  5,                                   // colNo
  "groupLayers_Mod",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/groupLayers/groupLayers_Mod.m"// pName 
};

static emlrtRTEInfo ef_emlrtRTEI = { 87,// lineNo
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
  int32_T i1;
  int32_T iv[2];
  coder::array<real_T, 1U> roughs;
  static const char_T cv[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
    '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
    '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
    '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
    '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']',
    '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{',
    '|', '}', '~', '\x7f' };

  static const char_T cv1[13] = { 'a', 'i', 'r', '/', 's', 'u', 'b', 's', 't',
    'r', 'a', 't', 'e' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
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
  layers.set_size((&ye_emlrtRTEI), sp, (static_cast<int32_T>(unnamed_idx_0)), 5);
  loop_ub = static_cast<int32_T>(unnamed_idx_0) * 5;
  for (i = 0; i < loop_ub; i++) {
    layers[i] = 0.0;
  }

  if (allLayers.size(0) != 0) {
    boolean_T b_bool;
    int32_T kstr;
    int32_T b_loop_ub;
    st.site = &s_emlrtRSI;
    b_st.site = &v_emlrtRSI;
    c_st.site = &w_emlrtRSI;
    b_bool = false;
    if (geometry.size(1) == 13) {
      kstr = 0;
      int32_T exitg1;
      do {
        exitg1 = 0;
        if (kstr < 13) {
          d_st.site = &x_emlrtRSI;
          i = static_cast<uint8_T>(geometry[kstr]);
          if (i > 127) {
            emlrtErrorWithMessageIdR2018a(&d_st, &hb_emlrtRTEI,
              "Coder:toolbox:unsupportedString",
              "Coder:toolbox:unsupportedString", 2, 12, 127);
          }

          if (cv[i] != cv[static_cast<int32_T>(cv1[kstr])]) {
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
      layers.set_size((&cf_emlrtRTEI), sp, allLayers.size(0), 5);
      loop_ub = allLayers.size(0) * allLayers.size(1);
      for (i = 0; i < loop_ub; i++) {
        layers[i] = allLayers[i];
      }

      // s_sub = rsub;
    } else {
      if (allLayers.size(0) < 1) {
        emlrtDynamicBoundsCheckR2012b(allLayers.size(0), 1, allLayers.size(0),
          &ke_emlrtBCI, sp);
      }

      *outSsubs = allLayers[(allLayers.size(0) + allLayers.size(0) * 2) - 1];
      if (1 > allLayers.size(0) - 1) {
        loop_ub = 0;
      } else {
        loop_ub = allLayers.size(0) - 1;
        if ((loop_ub < 1) || (loop_ub > allLayers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, allLayers.size(0),
            &je_emlrtBCI, sp);
        }
      }

      iv[0] = 1;
      iv[1] = loop_ub;
      st.site = &t_emlrtRSI;
      indexShapeCheck(&st, allLayers.size(0), iv);
      roughs.set_size((&af_emlrtRTEI), sp, (loop_ub + 1));
      roughs[0] = allRoughs;
      for (i = 0; i < loop_ub; i++) {
        roughs[i + 1] = allLayers[i + allLayers.size(0) * 2];
      }

      st.site = &u_emlrtRSI;
      b_st.site = &eb_emlrtRSI;
      c_st.site = &fb_emlrtRSI;
      if (roughs.size(0) != allLayers.size(0)) {
        emlrtErrorWithMessageIdR2018a(&c_st, &ib_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      loop_ub = allLayers.size(0);
      kstr = allLayers.size(0);
      b_loop_ub = allLayers.size(0);
      layers.set_size((&bf_emlrtRTEI), sp, allLayers.size(0), 4);
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
    }

    // Deal with the %coverage if present
    i = allLayers.size(0);
    for (b_loop_ub = 0; b_loop_ub < i; b_loop_ub++) {
      real_T this_pcw;
      real_T pc_add;
      i1 = b_loop_ub + 1;
      if ((i1 < 1) || (i1 > allLayers.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers.size(0), &le_emlrtBCI, sp);
      }

      this_pcw = allLayers[(i1 + allLayers.size(0) * 3) - 1];
      i1 = b_loop_ub + 1;
      if ((i1 < 1) || (i1 > allLayers.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, allLayers.size(0), &me_emlrtBCI, sp);
      }

      if (allLayers[(i1 + allLayers.size(0) * 4) - 1] == 1.0) {
        pc_add = nbair;
      } else {
        pc_add = nbsubs;
      }

      if (!muDoubleScalarIsNaN(this_pcw)) {
        i1 = b_loop_ub + 1;
        if ((i1 < 1) || (i1 > layers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, layers.size(0), &ne_emlrtBCI, sp);
        }

        kstr = b_loop_ub + 1;
        if ((kstr < 1) || (kstr > layers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(kstr, 1, layers.size(0), &oe_emlrtBCI,
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
    outLayers.set_size((&ef_emlrtRTEI), sp, layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        outLayers[i1 + outLayers.size(0) * i] = layers[i1 + layers.size(0) * i];
      }
    }
  } else {
    outLayers.set_size((&df_emlrtRTEI), sp, 1, 3);
    outLayers[0] = 0.0;
    outLayers[1] = 0.0;
    outLayers[2] = 0.0;
  }

  // end
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (groupLayers_Mod.cpp)
