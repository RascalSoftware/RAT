//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  makeSLDProfileXY.cpp
//
//  Code generation for function 'makeSLDProfileXY'
//


// Include files
#include "makeSLDProfileXY.h"
#include "asymconvstep.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo y_emlrtRSI = { 4,   // lineNo
  "makeSLDProfileXY",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pathName 
};

static emlrtRSInfo ab_emlrtRSI = { 11, // lineNo
  "makeSLDProfileXY",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pathName 
};

static emlrtRSInfo bb_emlrtRSI = { 26, // lineNo
  "makeSLDProfileXY",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pathName 
};

static emlrtRSInfo cb_emlrtRSI = { 37, // lineNo
  "makeSLDProfileXY",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pathName 
};

static emlrtRSInfo db_emlrtRSI = { 42, // lineNo
  "makeSLDProfileXY",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pathName 
};

static emlrtRSInfo eb_emlrtRSI = { 45, // lineNo
  "makeSLDProfileXY",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pathName 
};

static emlrtRSInfo fb_emlrtRSI = { 47, // lineNo
  "makeSLDProfileXY",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pathName 
};

static emlrtRSInfo gb_emlrtRSI = { 48, // lineNo
  "makeSLDProfileXY",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pathName 
};

static emlrtRSInfo hb_emlrtRSI = { 49, // lineNo
  "makeSLDProfileXY",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pathName 
};

static emlrtRSInfo ib_emlrtRSI = { 54, // lineNo
  "makeSLDProfileXY",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pathName 
};

static emlrtRSInfo kc_emlrtRSI = { 169,// lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

static emlrtRSInfo lc_emlrtRSI = { 187,// lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

static emlrtRSInfo pc_emlrtRSI = { 145,// lineNo
  "unaryMinOrMax",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtBCInfo re_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  19,                                  // lineNo
  32,                                  // colNo
  "layers",                            // aName
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo se_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  15,                                  // lineNo
  28,                                  // colNo
  "layers",                            // aName
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo cb_emlrtDCI = { 7,  // lineNo
  5,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo db_emlrtDCI = { 7,  // lineNo
  5,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo eb_emlrtDCI = { 7,  // lineNo
  28,                                  // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo fb_emlrtDCI = { 7,  // lineNo
  28,                                  // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  1                                    // checkKind
};

static emlrtECInfo b_emlrtECI = { -1,  // nDims
  40,                                  // lineNo
  5,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtBCInfo te_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  40,                                  // lineNo
  12,                                  // colNo
  "Lays",                              // aName
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo gb_emlrtDCI = { 40, // lineNo
  12,                                  // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  1                                    // checkKind
};

static emlrtECInfo c_emlrtECI = { -1,  // nDims
  37,                                  // lineNo
  5,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtBCInfo ue_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  37,                                  // lineNo
  12,                                  // colNo
  "Lays",                              // aName
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo hb_emlrtDCI = { 37, // lineNo
  12,                                  // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  1                                    // checkKind
};

static emlrtECInfo d_emlrtECI = { -1,  // nDims
  27,                                  // lineNo
  13,                                  // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtBCInfo ve_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  27,                                  // lineNo
  20,                                  // colNo
  "Lays",                              // aName
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo we_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  33,                                  // lineNo
  23,                                  // colNo
  "x",                                 // aName
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xe_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  17,                                  // lineNo
  35,                                  // colNo
  "layers",                            // aName
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ye_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  16,                                  // lineNo
  33,                                  // colNo
  "layers",                            // aName
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo jb_emlrtRTEI = { 13,// lineNo
  13,                                  // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtBCInfo af_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  27,                                  // colNo
  "layers",                            // aName
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo hf_emlrtRTEI = { 44,// lineNo
  5,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtRTEInfo if_emlrtRTEI = { 44,// lineNo
  9,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtRTEInfo jf_emlrtRTEI = { 50,// lineNo
  5,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtRTEInfo kf_emlrtRTEI = { 4,// lineNo
  23,                                  // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtRTEInfo lf_emlrtRTEI = { 6,// lineNo
  5,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtRTEInfo mf_emlrtRTEI = { 7,// lineNo
  5,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtRTEInfo nf_emlrtRTEI = { 125,// lineNo
  13,                                  // colNo
  "combineVectorElements",             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pName 
};

static emlrtRTEInfo of_emlrtRTEI = { 42,// lineNo
  11,                                  // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtRTEInfo pf_emlrtRTEI = { 42,// lineNo
  5,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

static emlrtRTEInfo qf_emlrtRTEI = { 54,// lineNo
  1,                                   // colNo
  "makeSLDProfileXY",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfileXY.m"// pName 
};

// Function Definitions
void makeSLDProfileXY(const emlrtStack *sp, real_T nbair, real_T nbsub, real_T
                      ssub, const coder::array<real_T, 2U> &layers, real_T
                      numberOfLayers, real_T nrepeats, coder::array<real_T, 2U>
                      &out)
{
  coder::array<real_T, 2U> x;
  int32_T vstride;
  int32_T i;
  coder::array<real_T, 1U> b_layers;
  real_T layerThicks;
  coder::array<real_T, 2U> SLD;
  int32_T vlen;
  coder::array<real_T, 2U> airBox;
  coder::array<real_T, 2U> thisBox;
  real_T subBox_data[101];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (numberOfLayers > 0.0) {
    real_T d;
    real_T d1;
    int32_T k;
    int32_T xoffset;
    real_T nextLayRough;
    int32_T n;
    vstride = layers.size(0);
    b_layers.set_size((&kf_emlrtRTEI), sp, layers.size(0));
    for (i = 0; i < vstride; i++) {
      b_layers[i] = layers[i];
    }

    st.site = &y_emlrtRSI;
    layerThicks = sum(&st, b_layers);
    layerThicks = layerThicks * nrepeats + 150.0;
    if (muDoubleScalarIsNaN(layerThicks)) {
      x.set_size((&lf_emlrtRTEI), sp, 1, 1);
      x[0] = rtNaN;
    } else if (layerThicks < 0.0) {
      x.set_size((&lf_emlrtRTEI), sp, 1, 0);
    } else if (muDoubleScalarIsInf(layerThicks) && (0.0 == layerThicks)) {
      x.set_size((&lf_emlrtRTEI), sp, 1, 1);
      x[0] = rtNaN;
    } else {
      vstride = static_cast<int32_T>(muDoubleScalarFloor(layerThicks));
      x.set_size((&lf_emlrtRTEI), sp, 1, (vstride + 1));
      for (i = 0; i <= vstride; i++) {
        x[i] = i;
      }
    }

    SLD.set_size((&mf_emlrtRTEI), sp, x.size(1), SLD.size(1));
    d = numberOfLayers * nrepeats;
    if (!(d + 2.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d + 2.0, &eb_emlrtDCI, sp);
    }

    d1 = static_cast<int32_T>(muDoubleScalarFloor(d + 2.0));
    if (d + 2.0 != d1) {
      emlrtIntegerCheckR2012b(d + 2.0, &fb_emlrtDCI, sp);
    }

    i = static_cast<int32_T>(d + 2.0);
    SLD.set_size((&mf_emlrtRTEI), sp, SLD.size(0), i);
    if (!(d + 2.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d + 2.0, &cb_emlrtDCI, sp);
    }

    if (d + 2.0 != d1) {
      emlrtIntegerCheckR2012b(d + 2.0, &db_emlrtDCI, sp);
    }

    vstride = x.size(1) * i;
    for (xoffset = 0; xoffset < vstride; xoffset++) {
      SLD[xoffset] = 0.0;
    }

    if (1 > layers.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, layers.size(0), &af_emlrtBCI, sp);
    }

    nextLayRough = layers[layers.size(0) * 2];
    st.site = &ab_emlrtRSI;
    asymconvstep(&st, x, 100.0, 0.0, nextLayRough, nextLayRough, nbair, airBox);
    layerThicks = 50.0;
    xoffset = static_cast<int32_T>(nrepeats);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nrepeats, mxDOUBLE_CLASS,
      static_cast<int32_T>(nrepeats), &jb_emlrtRTEI, sp);
    for (n = 0; n < xoffset; n++) {
      k = static_cast<int32_T>(numberOfLayers);
      for (int32_T b_i = 0; b_i < k; b_i++) {
        real_T thisLayThick;
        vlen = static_cast<int32_T>(b_i + 1U);
        if ((vlen < 1) || (vlen > layers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(vlen, 1, layers.size(0), &se_emlrtBCI,
            sp);
        }

        thisLayThick = layers[vlen - 1];
        vlen = b_i + 1;
        if ((vlen < 1) || (vlen > layers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(vlen, 1, layers.size(0), &ye_emlrtBCI,
            sp);
        }

        vlen = b_i + 1;
        if ((vlen < 1) || (vlen > layers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(vlen, 1, layers.size(0), &xe_emlrtBCI,
            sp);
        }

        if (static_cast<real_T>(b_i) + 1.0 < numberOfLayers) {
          vlen = static_cast<int32_T>(b_i + 2U);
          if ((vlen < 1) || (vlen > layers.size(0))) {
            emlrtDynamicBoundsCheckR2012b(vlen, 1, layers.size(0), &re_emlrtBCI,
              sp);
          }

          nextLayRough = layers[(vlen + layers.size(0) * 2) - 1];

          //              elseif (i == numberOfLayers) && (n < nrepeats)
          //                  nextLayRough = layers(1,3);
        } else {
          nextLayRough = ssub;
        }

        layerThicks += thisLayThick / 2.0;
        st.site = &bb_emlrtRSI;
        asymconvstep(&st, x, thisLayThick, layerThicks, layers[b_i + layers.size
                     (0) * 2], nextLayRough, layers[b_i + layers.size(0)],
                     thisBox);
        vlen = static_cast<int32_T>((static_cast<real_T>(b_i) + 1.0) +
          numberOfLayers * ((static_cast<real_T>(n) + 1.0) - 1.0));
        if ((vlen < 1) || (vlen > SLD.size(1))) {
          emlrtDynamicBoundsCheckR2012b(vlen, 1, SLD.size(1), &ve_emlrtBCI, sp);
        }

        vlen--;
        emlrtSubAssignSizeCheckR2012b(SLD.size(), 1, thisBox.size(), 2,
          &d_emlrtECI, sp);
        vstride = SLD.size(0);
        for (int32_T i1 = 0; i1 < vstride; i1++) {
          SLD[i1 + SLD.size(0) * vlen] = thisBox[i1];
        }

        layerThicks += thisLayThick / 2.0;

        // plot(x,Lays(:,i));
      }
    }

    // layers(end,3);
    if (x.size(1) < 1) {
      emlrtDynamicBoundsCheckR2012b(x.size(1), 1, x.size(1), &we_emlrtBCI, sp);
    }

    if (d + 1.0 != static_cast<int32_T>(muDoubleScalarFloor(d + 1.0))) {
      emlrtIntegerCheckR2012b(d + 1.0, &hb_emlrtDCI, sp);
    }

    xoffset = static_cast<int32_T>(d + 1.0);
    if ((xoffset < 1) || (xoffset > SLD.size(1))) {
      emlrtDynamicBoundsCheckR2012b(xoffset, 1, SLD.size(1), &ue_emlrtBCI, sp);
    }

    xoffset--;
    st.site = &cb_emlrtRSI;
    asymconvstep(&st, x, (x[x.size(1) - 1] - layerThicks) * 2.0, x[x.size(1) - 1],
                 nextLayRough, ssub, nbsub, thisBox);
    emlrtSubAssignSizeCheckR2012b(SLD.size(), 1, thisBox.size(), 2, &c_emlrtECI,
      sp);
    vstride = SLD.size(0);
    for (k = 0; k < vstride; k++) {
      SLD[k + SLD.size(0) * xoffset] = thisBox[k];
    }

    // plot(x,Lays(:,(numberOfLayers*nrepeats)+1))
    if (d + 2.0 != d1) {
      emlrtIntegerCheckR2012b(d + 2.0, &gb_emlrtDCI, sp);
    }

    if ((i < 1) || (i > SLD.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, SLD.size(1), &te_emlrtBCI, sp);
    }

    i--;
    emlrtSubAssignSizeCheckR2012b(SLD.size(), 1, airBox.size(), 2, &b_emlrtECI,
      sp);
    vstride = SLD.size(0);
    for (xoffset = 0; xoffset < vstride; xoffset++) {
      SLD[xoffset + SLD.size(0) * i] = airBox[xoffset];
    }

    // plot(x,Lays(:,(numberOfLayers*nrepeats)+2))
    st.site = &db_emlrtRSI;
    b_st.site = &jb_emlrtRSI;
    c_st.site = &kb_emlrtRSI;
    vlen = SLD.size(1);
    if ((SLD.size(0) == 0) || (SLD.size(1) == 0)) {
      uint32_T sz_idx_0;
      sz_idx_0 = static_cast<uint32_T>(SLD.size(0));
      b_layers.set_size((&of_emlrtRTEI), (&c_st), (static_cast<int32_T>(sz_idx_0)));
      vstride = static_cast<int32_T>(sz_idx_0);
      for (i = 0; i < vstride; i++) {
        b_layers[i] = 0.0;
      }
    } else {
      d_st.site = &lb_emlrtRSI;
      vstride = SLD.size(0);
      b_layers.set_size((&nf_emlrtRTEI), (&d_st), SLD.size(0));
      e_st.site = &kc_emlrtRSI;
      if (SLD.size(0) > 2147483646) {
        f_st.site = &nb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (n = 0; n < vstride; n++) {
        b_layers[n] = SLD[n];
      }

      e_st.site = &mb_emlrtRSI;
      if ((2 <= SLD.size(1)) && (SLD.size(1) > 2147483646)) {
        f_st.site = &nb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (k = 2; k <= vlen; k++) {
        xoffset = (k - 1) * vstride;
        e_st.site = &lc_emlrtRSI;
        if (vstride > 2147483646) {
          f_st.site = &nb_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (n = 0; n < vstride; n++) {
          b_layers[n] = b_layers[n] + SLD[xoffset + n];
        }
      }
    }

    SLD.set_size((&pf_emlrtRTEI), sp, b_layers.size(0), 1);
    vstride = b_layers.size(0);
    for (i = 0; i < vstride; i++) {
      SLD[i] = b_layers[i];
    }
  } else {
    int32_T k;
    x.set_size((&hf_emlrtRTEI), sp, 1, 101);
    for (i = 0; i < 101; i++) {
      x[i] = i;
    }

    st.site = &eb_emlrtRSI;
    b_st.site = &mc_emlrtRSI;
    c_st.site = &nc_emlrtRSI;
    d_st.site = &oc_emlrtRSI;
    e_st.site = &pc_emlrtRSI;
    vlen = 0;
    for (k = 0; k < 100; k++) {
      if (vlen < k + 1) {
        vlen = k + 1;
      }
    }

    st.site = &fb_emlrtRSI;
    b_st.site = &mc_emlrtRSI;
    c_st.site = &nc_emlrtRSI;
    d_st.site = &oc_emlrtRSI;
    e_st.site = &pc_emlrtRSI;
    vstride = 0;
    for (k = 0; k < 100; k++) {
      if (vstride < k + 1) {
        vstride = k + 1;
      }
    }

    SLD.set_size((&if_emlrtRTEI), sp, 1, 101);
    for (i = 0; i < 101; i++) {
      SLD[i] = i;
    }

    st.site = &gb_emlrtRSI;
    asymconvstep(&st, SLD, static_cast<real_T>(vstride), 0.0, ssub, ssub, nbair,
                 airBox);
    SLD.set_size((&if_emlrtRTEI), sp, 1, 101);
    for (i = 0; i < 101; i++) {
      SLD[i] = i;
    }

    st.site = &hb_emlrtRSI;
    asymconvstep(&st, SLD, static_cast<real_T>(vstride), static_cast<real_T>
                 (vlen), ssub, ssub, nbsub, thisBox);
    vstride = thisBox.size(0) * thisBox.size(1);
    for (i = 0; i < vstride; i++) {
      subBox_data[i] = thisBox[i];
    }

    SLD.set_size((&jf_emlrtRTEI), sp, 1, airBox.size(1));
    vstride = airBox.size(0) * airBox.size(1);
    for (i = 0; i < vstride; i++) {
      SLD[i] = airBox[i] + subBox_data[i];
    }
  }

  // plot(x,SLD)
  st.site = &ib_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  if (SLD.size(0) * SLD.size(1) != x.size(1)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &hb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  vlen = SLD.size(0) * SLD.size(1);
  out.set_size((&qf_emlrtRTEI), (&b_st), x.size(1), 2);
  vstride = x.size(1);
  for (i = 0; i < vstride; i++) {
    out[i] = x[i];
  }

  for (i = 0; i < vlen; i++) {
    out[i + out.size(0)] = SLD[i];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (makeSLDProfileXY.cpp)
