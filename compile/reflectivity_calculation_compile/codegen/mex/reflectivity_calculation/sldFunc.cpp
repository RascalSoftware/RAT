//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sldFunc.cpp
//
//  Code generation for function 'sldFunc'
//


// Include files
#include "sldFunc.h"
#include "chiSquared.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo kd_emlrtRSI = { 24, // lineNo
  "sldFunc",                           // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pathName 
};

static emlrtRSInfo ld_emlrtRSI = { 29, // lineNo
  "sldFunc",                           // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pathName 
};

static emlrtRSInfo md_emlrtRSI = { 30, // lineNo
  "sldFunc",                           // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pathName 
};

static emlrtBCInfo ff_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  27,                                  // lineNo
  18,                                  // colNo
  "rho",                               // aName
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo gf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  31,                                  // lineNo
  23,                                  // colNo
  "belowVals",                         // aName
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo hf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  32,                                  // lineNo
  23,                                  // colNo
  "aboveVals",                         // aName
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo if_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  34,                                  // lineNo
  18,                                  // colNo
  "rho",                               // aName
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  35,                                  // lineNo
  18,                                  // colNo
  "rho",                               // aName
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  38,                                  // lineNo
  15,                                  // colNo
  "z",                                 // aName
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo lf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  38,                                  // lineNo
  26,                                  // colNo
  "z",                                 // aName
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo mf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  42,                                  // lineNo
  20,                                  // colNo
  "z",                                 // aName
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo dg_emlrtRTEI = { 24,// lineNo
  14,                                  // colNo
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pName 
};

static emlrtRTEInfo gg_emlrtRTEI = { 24,// lineNo
  1,                                   // colNo
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pName 
};

static emlrtRTEInfo hg_emlrtRTEI = { 29,// lineNo
  22,                                  // colNo
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pName 
};

static emlrtRTEInfo ig_emlrtRTEI = { 29,// lineNo
  5,                                   // colNo
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pName 
};

static emlrtRTEInfo jg_emlrtRTEI = { 30,// lineNo
  22,                                  // colNo
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pName 
};

static emlrtRTEInfo kg_emlrtRTEI = { 30,// lineNo
  5,                                   // colNo
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pName 
};

static emlrtRTEInfo lg_emlrtRTEI = { 48,// lineNo
  9,                                   // colNo
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pName 
};

static emlrtRTEInfo mg_emlrtRTEI = { 46,// lineNo
  9,                                   // colNo
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pName 
};

static emlrtRTEInfo ng_emlrtRTEI = { 27,// lineNo
  5,                                   // colNo
  "sldFunc",                           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/sldFunc.m"// pName 
};

// Function Definitions
void sldFunc(const emlrtStack *sp, real_T x, const coder::array<real_T, 2U> &SLD,
             coder::array<real_T, 1U> &sldVal)
{
  int32_T nx;
  coder::array<boolean_T, 1U> b_x;
  int32_T idx;
  coder::array<int32_T, 1U> ii;
  int32_T b_ii;
  boolean_T exitg1;
  int32_T iv[2];
  coder::array<uint32_T, 1U> where;
  coder::array<uint32_T, 1U> aboveVals;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  //  sldVal = sldFunc(x,SLD)
  //  SLD = [x rho;....xn rho]
  //    x = value in Angstrom.
  //
  //  This function returns the SLD (y) value associated with the
  //  supplied value of x. SLD is a two column, XY array defining an
  //  SLD profile. This function interpolates the SLD profile
  //  to return the SLD at the specific value of X. X can be a vector of
  //  multiple points.
  //
  //  (c) Arwel Hughes 2019.
  //  Last modified - AVH, 26/11/19.
  //  global sldProfile
  //
  //  SLD = sldProfile;
  // SLD = getappdata(0,'sldFuncSLD');
  st.site = &kd_emlrtRSI;
  nx = SLD.size(0);
  b_x.set_size((&dg_emlrtRTEI), (&st), SLD.size(0));
  for (idx = 0; idx < nx; idx++) {
    b_x[idx] = (SLD[idx] == x);
  }

  b_st.site = &nd_emlrtRSI;
  nx = b_x.size(0);
  c_st.site = &od_emlrtRSI;
  idx = 0;
  ii.set_size((&eg_emlrtRTEI), (&c_st), b_x.size(0));
  d_st.site = &pd_emlrtRSI;
  if ((1 <= b_x.size(0)) && (b_x.size(0) > 2147483646)) {
    e_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= nx - 1)) {
    if (b_x[b_ii]) {
      idx++;
      ii[idx - 1] = b_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    } else {
      b_ii++;
    }
  }

  if (idx > b_x.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (b_x.size(0) == 1) {
    if (idx == 0) {
      ii.set_size((&fg_emlrtRTEI), (&c_st), 0);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }

    iv[0] = 1;
    iv[1] = idx;
    d_st.site = &qd_emlrtRSI;
    indexShapeCheck(&d_st, ii.size(0), iv);
    ii.set_size((&fg_emlrtRTEI), (&c_st), idx);
  }

  where.set_size((&gg_emlrtRTEI), (&st), ii.size(0));
  nx = ii.size(0);
  for (idx = 0; idx < nx; idx++) {
    where[idx] = static_cast<uint32_T>(ii[idx]);
  }

  if (where.size(0) != 0) {
    sldVal.set_size((&ng_emlrtRTEI), sp, where.size(0));
    nx = where.size(0);
    for (idx = 0; idx < nx; idx++) {
      if ((static_cast<int32_T>(where[idx]) < 1) || (static_cast<int32_T>
           (where[idx]) > SLD.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(where[idx]), 1,
          SLD.size(0), &ff_emlrtBCI, sp);
      }

      sldVal[idx] = SLD[(static_cast<int32_T>(where[idx]) + SLD.size(0)) - 1];
    }
  } else {
    real_T deltaY_tmp;
    real_T deltaY;
    st.site = &ld_emlrtRSI;
    nx = SLD.size(0);
    b_x.set_size((&hg_emlrtRTEI), (&st), SLD.size(0));
    for (idx = 0; idx < nx; idx++) {
      b_x[idx] = (x > SLD[idx]);
    }

    b_st.site = &nd_emlrtRSI;
    nx = b_x.size(0);
    c_st.site = &od_emlrtRSI;
    idx = 0;
    ii.set_size((&eg_emlrtRTEI), (&c_st), b_x.size(0));
    d_st.site = &pd_emlrtRSI;
    if ((1 <= b_x.size(0)) && (b_x.size(0) > 2147483646)) {
      e_st.site = &vb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii <= nx - 1)) {
      if (b_x[b_ii]) {
        idx++;
        ii[idx - 1] = b_ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          b_ii++;
        }
      } else {
        b_ii++;
      }
    }

    if (idx > b_x.size(0)) {
      emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (b_x.size(0) == 1) {
      if (idx == 0) {
        ii.set_size((&fg_emlrtRTEI), (&c_st), 0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }

      iv[0] = 1;
      iv[1] = idx;
      d_st.site = &qd_emlrtRSI;
      indexShapeCheck(&d_st, ii.size(0), iv);
      ii.set_size((&fg_emlrtRTEI), (&c_st), idx);
    }

    where.set_size((&ig_emlrtRTEI), (&st), ii.size(0));
    nx = ii.size(0);
    for (idx = 0; idx < nx; idx++) {
      where[idx] = static_cast<uint32_T>(ii[idx]);
    }

    st.site = &md_emlrtRSI;
    nx = SLD.size(0);
    b_x.set_size((&jg_emlrtRTEI), (&st), SLD.size(0));
    for (idx = 0; idx < nx; idx++) {
      b_x[idx] = (x < SLD[idx]);
    }

    b_st.site = &nd_emlrtRSI;
    nx = b_x.size(0);
    c_st.site = &od_emlrtRSI;
    idx = 0;
    ii.set_size((&eg_emlrtRTEI), (&c_st), b_x.size(0));
    d_st.site = &pd_emlrtRSI;
    if ((1 <= b_x.size(0)) && (b_x.size(0) > 2147483646)) {
      e_st.site = &vb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii <= nx - 1)) {
      if (b_x[b_ii]) {
        idx++;
        ii[idx - 1] = b_ii + 1;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          b_ii++;
        }
      } else {
        b_ii++;
      }
    }

    if (idx > b_x.size(0)) {
      emlrtErrorWithMessageIdR2018a(&c_st, &pb_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (b_x.size(0) == 1) {
      if (idx == 0) {
        ii.set_size((&fg_emlrtRTEI), (&c_st), 0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }

      iv[0] = 1;
      iv[1] = idx;
      d_st.site = &qd_emlrtRSI;
      indexShapeCheck(&d_st, ii.size(0), iv);
      ii.set_size((&fg_emlrtRTEI), (&c_st), idx);
    }

    aboveVals.set_size((&kg_emlrtRTEI), (&st), ii.size(0));
    nx = ii.size(0);
    for (idx = 0; idx < nx; idx++) {
      aboveVals[idx] = static_cast<uint32_T>(ii[idx]);
    }

    if (where.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(where.size(0), 1, where.size(0),
        &gf_emlrtBCI, sp);
    }

    if (1 > aboveVals.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, aboveVals.size(0), &hf_emlrtBCI, sp);
    }

    idx = static_cast<int32_T>(where[where.size(0) - 1]);
    if ((idx < 1) || (idx > SLD.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, SLD.size(0), &if_emlrtBCI, sp);
    }

    idx = static_cast<int32_T>(aboveVals[0]);
    if ((idx < 1) || (idx > SLD.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, SLD.size(0), &jf_emlrtBCI, sp);
    }

    idx = static_cast<int32_T>(aboveVals[0]);
    if ((idx < 1) || (idx > SLD.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, SLD.size(0), &kf_emlrtBCI, sp);
    }

    idx = static_cast<int32_T>(where[where.size(0) - 1]);
    if ((idx < 1) || (idx > SLD.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, SLD.size(0), &lf_emlrtBCI, sp);
    }

    idx = static_cast<int32_T>(where[where.size(0) - 1]);
    if ((idx < 1) || (idx > SLD.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, SLD.size(0), &mf_emlrtBCI, sp);
    }

    nx = static_cast<int32_T>(aboveVals[0]) - 1;
    deltaY_tmp = SLD[nx + SLD.size(0)];
    deltaY = (x - SLD[static_cast<int32_T>(where[where.size(0) - 1]) - 1]) *
      (muDoubleScalarAbs(deltaY_tmp - SLD[(static_cast<int32_T>(where[where.size
          (0) - 1]) + SLD.size(0)) - 1]) / (SLD[nx] - SLD[static_cast<int32_T>
        (where[where.size(0) - 1]) - 1]));
    if (SLD[(static_cast<int32_T>(where[where.size(0) - 1]) + SLD.size(0)) - 1] <
        deltaY_tmp) {
      sldVal.set_size((&mg_emlrtRTEI), sp, 1);
      sldVal[0] = SLD[(static_cast<int32_T>(where[where.size(0) - 1]) + SLD.size
                       (0)) - 1] + deltaY;
    } else {
      sldVal.set_size((&lg_emlrtRTEI), sp, 1);
      sldVal[0] = SLD[(static_cast<int32_T>(where[where.size(0) - 1]) + SLD.size
                       (0)) - 1] - deltaY;
    }

    // sldVal = interp1(z,rho,x);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (sldFunc.cpp)
