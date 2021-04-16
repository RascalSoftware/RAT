//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  callReflectivity.cpp
//
//  Code generation for function 'callReflectivity'
//


// Include files
#include "callReflectivity.h"
#include "abeles_paraPoints.h"
#include "abeles_single.h"
#include "colon.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_mexutil.h"
#include "resolution_polly_paraPoints.h"
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo nf_emlrtRSI = { 37, // lineNo
  "callReflectivity",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pathName 
};

static emlrtRSInfo of_emlrtRSI = { 44, // lineNo
  "callReflectivity",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pathName 
};

static emlrtRSInfo pf_emlrtRSI = { 67, // lineNo
  "callReflectivity",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pathName 
};

static emlrtRSInfo qf_emlrtRSI = { 68, // lineNo
  "callReflectivity",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pathName 
};

static emlrtRSInfo rf_emlrtRSI = { 103,// lineNo
  "colon",                             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pathName
};

static emlrtRSInfo xf_emlrtRSI = { 26, // lineNo
  "resolution_polly",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m"// pathName 
};

static emlrtRSInfo hg_emlrtRSI = { 62, // lineNo
  "callReflectivity",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pathName 
};

static emlrtRSInfo ig_emlrtRSI = { 63, // lineNo
  "callReflectivity",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pathName 
};

static emlrtBCInfo ig_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  28,                                  // lineNo
  9,                                   // colNo
  "dummydata",                         // aName
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  28,                                  // lineNo
  39,                                  // colNo
  "dummyref",                          // aName
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  28,                                  // lineNo
  24,                                  // colNo
  "dummydata",                         // aName
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo lg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  26,                                  // lineNo
  48,                                  // colNo
  "xdata",                             // aName
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo mg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  26,                                  // lineNo
  33,                                  // colNo
  "xdata",                             // aName
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ng_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  26,                                  // lineNo
  22,                                  // colNo
  "xdata",                             // aName
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo og_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  31,                                  // lineNo
  9,                                   // colNo
  "dummydata",                         // aName
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo pg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  31,                                  // lineNo
  24,                                  // colNo
  "dummydata",                         // aName
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo qg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  5,                                   // colNo
  "dummydata",                         // aName
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo rg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  26,                                  // colNo
  "xdata",                             // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo sg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  43,                                  // lineNo
  30,                                  // colNo
  "xdata",                             // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo tg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  43,                                  // lineNo
  13,                                  // colNo
  "xdata",                             // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ug_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  42,                                  // lineNo
  13,                                  // colNo
  "xdata",                             // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo ac_emlrtRTEI = { 25,// lineNo
  13,                                  // colNo
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m"// pName 
};

static emlrtBCInfo vg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  74,                                  // lineNo
  37,                                  // colNo
  "Simulation",                        // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo wg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  74,                                  // lineNo
  27,                                  // colNo
  "Simulation",                        // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo r_emlrtECI = { -1,  // nDims
  73,                                  // lineNo
  1,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtECInfo s_emlrtECI = { -1,  // nDims
  53,                                  // lineNo
  1,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtBCInfo xg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  37,                                  // lineNo
  40,                                  // colNo
  "xdata",                             // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo yg_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  28,                                  // colNo
  "xdata",                             // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ah_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  19,                                  // colNo
  "xdata",                             // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  35,                                  // lineNo
  19,                                  // colNo
  "xdata",                             // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ch_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  32,                                  // lineNo
  29,                                  // colNo
  "this_data",                         // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo dh_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  19,                                  // lineNo
  21,                                  // colNo
  "this_data",                         // aName
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo ej_emlrtRTEI = { 26,// lineNo
  5,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtRTEInfo fj_emlrtRTEI = { 23,// lineNo
  5,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtRTEInfo gj_emlrtRTEI = { 39,// lineNo
  5,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtRTEInfo hj_emlrtRTEI = { 37,// lineNo
  5,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtRTEInfo ij_emlrtRTEI = { 46,// lineNo
  5,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtRTEInfo jj_emlrtRTEI = { 44,// lineNo
  5,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtRTEInfo kj_emlrtRTEI = { 49,// lineNo
  1,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtRTEInfo lj_emlrtRTEI = { 52,// lineNo
  1,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtRTEInfo mj_emlrtRTEI = { 5,// lineNo
  1,                                   // colNo
  "resolution_polly",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Resolution_Functions/Simple_Gaussian/resolution_polly.m"// pName 
};

static emlrtRTEInfo nj_emlrtRTEI = { 74,// lineNo
  1,                                   // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

static emlrtRTEInfo vj_emlrtRTEI = { 103,// lineNo
  9,                                   // colNo
  "colon",                             // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pName
};

static emlrtRTEInfo wj_emlrtRTEI = { 63,// lineNo
  63,                                  // colNo
  "callReflectivity",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/callReflectivity.m"// pName 
};

// Function Definitions
void b_callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs,
  const real_T simLimits[2], const real_T repeatLayers[2], const coder::array<
  real_T, 2U> &this_data, const coder::array<real_T, 2U> &layers, real_T ssubs,
  real_T res, coder::array<real_T, 2U> &reflectivity, coder::array<real_T, 2U>
  &Simulation)
{
  int32_T loop_ub;
  coder::array<real_T, 2U> slds;
  int32_T i;
  int32_T lays;
  int32_T n;
  coder::array<real_T, 2U> firstSection;
  real_T step;
  coder::array<real_T, 2U> lastSection;
  real_T kd;
  coder::array<real_T, 1U> simXdata;
  int32_T nm1d2;
  real_T ndbl;
  real_T apnd;
  uint32_T splits_idx_1;
  real_T cdiff;
  coder::array<real_T, 1U> simRef;
  coder::array<real_T, 1U> b_simRef;
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

  //  nbairs = problem.nbairs;
  //  nbsubs = problem.nbsubs;
  //  simLimits = problem.simLimits;
  //  repeatLayers = problem.repeatLayers;
  //  allData = problem.shifted_data;
  //  layers = problem.layers;
  //  ssubs = problem.ssubs;
  //  numberOfContrasts = problem.numberOfContrasts;
  //  reflectivity = cell(numberOfContrasts,1);
  //  Simulation = cell(numberOfContrasts,1);
  //
  //  parfor i = 1:numberOfContrasts
  // this_data = allData{i};
  if (1 > this_data.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data.size(1), &dh_emlrtBCI, sp);
  }

  if (layers.size(0) == 0) {
    slds.set_size((&fj_emlrtRTEI), sp, 1, 3);
    slds[0] = 0.0;
    slds[1] = nbairs;
    slds[2] = 0.0;
    lays = 0;
  } else {
    loop_ub = layers.size(0);
    slds.set_size((&ej_emlrtRTEI), sp, layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (n = 0; n < loop_ub; n++) {
        slds[n + slds.size(0) * i] = layers[n + layers.size(0) * i];
      }
    }

    lays = layers.size(0);
  }

  if (1 > this_data.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data.size(1), &ch_emlrtBCI, sp);
  }

  if (1 > this_data.size(0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data.size(0), &bh_emlrtBCI, sp);
  }

  if (simLimits[0] < this_data[0]) {
    if (2 > this_data.size(0)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, this_data.size(0), &ah_emlrtBCI, sp);
    }

    if (1 > this_data.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data.size(0), &yg_emlrtBCI, sp);
    }

    step = this_data[1] - this_data[0];
    if (1 > this_data.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data.size(0), &xg_emlrtBCI, sp);
    }

    st.site = &nf_emlrtRSI;
    kd = this_data[0] - step;
    if (muDoubleScalarIsNaN(step) || muDoubleScalarIsNaN(kd)) {
      firstSection.set_size((&hj_emlrtRTEI), (&st), 1, 1);
      firstSection[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < kd) && (step < 0.0)) || ((kd <
                 simLimits[0]) && (step > 0.0))) {
      firstSection.set_size((&hj_emlrtRTEI), (&st), 1, 0);
    } else if ((muDoubleScalarIsInf(simLimits[0]) || muDoubleScalarIsInf(kd)) &&
               (muDoubleScalarIsInf(step) || (simLimits[0] == kd))) {
      firstSection.set_size((&hj_emlrtRTEI), (&st), 1, 1);
      firstSection[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      firstSection.set_size((&hj_emlrtRTEI), (&st), 1, 1);
      firstSection[0] = simLimits[0];
    } else if ((muDoubleScalarFloor(simLimits[0]) == simLimits[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      loop_ub = static_cast<int32_T>(muDoubleScalarFloor((kd - simLimits[0]) /
        step));
      firstSection.set_size((&hj_emlrtRTEI), (&st), 1, (loop_ub + 1));
      for (i = 0; i <= loop_ub; i++) {
        firstSection[i] = simLimits[0] + step * static_cast<real_T>(i);
      }
    } else {
      b_st.site = &rf_emlrtRSI;
      ndbl = muDoubleScalarFloor((kd - simLimits[0]) / step + 0.5);
      apnd = simLimits[0] + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - kd;
      } else {
        cdiff = kd - apnd;
      }

      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
          (muDoubleScalarAbs(simLimits[0]), muDoubleScalarAbs(kd))) {
        ndbl++;
        apnd = kd;
      } else if (cdiff > 0.0) {
        apnd = simLimits[0] + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = static_cast<int32_T>(ndbl);
      } else {
        n = 0;
      }

      c_st.site = &sf_emlrtRSI;
      if (ndbl > 2.147483647E+9) {
        emlrtErrorWithMessageIdR2018a(&c_st, &bc_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", "Coder:MATLAB:pmaxsize", 0);
      }

      firstSection.set_size((&vj_emlrtRTEI), (&b_st), 1, n);
      if (n > 0) {
        firstSection[0] = simLimits[0];
        if (n > 1) {
          firstSection[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (loop_ub = 0; loop_ub <= nm1d2 - 2; loop_ub++) {
            kd = (static_cast<real_T>(loop_ub) + 1.0) * step;
            firstSection[loop_ub + 1] = simLimits[0] + kd;
            firstSection[(n - loop_ub) - 2] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            firstSection[nm1d2] = (simLimits[0] + apnd) / 2.0;
          } else {
            kd = static_cast<real_T>(nm1d2) * step;
            firstSection[nm1d2] = simLimits[0] + kd;
            firstSection[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }
  } else {
    firstSection.set_size((&gj_emlrtRTEI), sp, 1, 0);
  }

  if (this_data.size(0) < 1) {
    emlrtDynamicBoundsCheckR2012b(this_data.size(0), 1, this_data.size(0),
      &ug_emlrtBCI, sp);
  }

  if (simLimits[1] > this_data[this_data.size(0) - 1]) {
    real_T a;
    i = this_data.size(0) - 1;
    if ((i < 1) || (i > this_data.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, this_data.size(0), &sg_emlrtBCI, sp);
    }

    if (this_data.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data.size(0), 1, this_data.size(0),
        &tg_emlrtBCI, sp);
    }

    step = this_data[this_data.size(0) - 1] - this_data[i - 1];
    st.site = &of_emlrtRSI;
    if (this_data.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data.size(0), 1, this_data.size(0),
        &rg_emlrtBCI, &st);
    }

    a = this_data[this_data.size(0) - 1] + step;
    if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(step)) {
      lastSection.set_size((&jj_emlrtRTEI), (&st), 1, 1);
      lastSection[0] = rtNaN;
    } else if ((step == 0.0) || ((a < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < a) && (step > 0.0))) {
      lastSection.set_size((&jj_emlrtRTEI), (&st), 1, 0);
    } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(simLimits[1])) &&
               (muDoubleScalarIsInf(step) || (a == simLimits[1]))) {
      lastSection.set_size((&jj_emlrtRTEI), (&st), 1, 1);
      lastSection[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      lastSection.set_size((&jj_emlrtRTEI), (&st), 1, 1);
      lastSection[0] = a;
    } else if ((muDoubleScalarFloor(a) == a) && (muDoubleScalarFloor(step) ==
                step)) {
      loop_ub = static_cast<int32_T>(muDoubleScalarFloor((simLimits[1] - a) /
        step));
      lastSection.set_size((&jj_emlrtRTEI), (&st), 1, (loop_ub + 1));
      for (i = 0; i <= loop_ub; i++) {
        lastSection[i] = a + step * static_cast<real_T>(i);
      }
    } else {
      b_st.site = &rf_emlrtRSI;
      ndbl = muDoubleScalarFloor((simLimits[1] - a) / step + 0.5);
      apnd = a + ndbl * step;
      if (step > 0.0) {
        cdiff = apnd - simLimits[1];
      } else {
        cdiff = simLimits[1] - apnd;
      }

      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * muDoubleScalarMax
          (muDoubleScalarAbs(a), muDoubleScalarAbs(simLimits[1]))) {
        ndbl++;
        apnd = simLimits[1];
      } else if (cdiff > 0.0) {
        apnd = a + (ndbl - 1.0) * step;
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = static_cast<int32_T>(ndbl);
      } else {
        n = 0;
      }

      c_st.site = &sf_emlrtRSI;
      if (ndbl > 2.147483647E+9) {
        emlrtErrorWithMessageIdR2018a(&c_st, &bc_emlrtRTEI,
          "Coder:MATLAB:pmaxsize", "Coder:MATLAB:pmaxsize", 0);
      }

      lastSection.set_size((&vj_emlrtRTEI), (&b_st), 1, n);
      if (n > 0) {
        lastSection[0] = a;
        if (n > 1) {
          lastSection[n - 1] = apnd;
          nm1d2 = (n - 1) / 2;
          for (loop_ub = 0; loop_ub <= nm1d2 - 2; loop_ub++) {
            kd = (static_cast<real_T>(loop_ub) + 1.0) * step;
            lastSection[loop_ub + 1] = a + kd;
            lastSection[(n - loop_ub) - 2] = apnd - kd;
          }

          if (nm1d2 << 1 == n - 1) {
            lastSection[nm1d2] = (a + apnd) / 2.0;
          } else {
            kd = static_cast<real_T>(nm1d2) * step;
            lastSection[nm1d2] = a + kd;
            lastSection[nm1d2 + 1] = apnd - kd;
          }
        }
      }
    }
  } else {
    lastSection.set_size((&ij_emlrtRTEI), sp, 1, 0);
  }

  n = firstSection.size(1);
  loop_ub = this_data.size(0);
  simXdata.set_size((&kj_emlrtRTEI), sp, ((firstSection.size(1) + this_data.size
    (0)) + lastSection.size(1)));
  nm1d2 = firstSection.size(1);
  for (i = 0; i < nm1d2; i++) {
    simXdata[i] = firstSection[i];
  }

  for (i = 0; i < loop_ub; i++) {
    simXdata[i + n] = this_data[i];
  }

  nm1d2 = lastSection.size(1);
  for (i = 0; i < nm1d2; i++) {
    simXdata[(i + n) + loop_ub] = lastSection[i];
  }

  splits_idx_1 = static_cast<uint32_T>(firstSection.size(1)) + this_data.size(0);
  Simulation.set_size((&lj_emlrtRTEI), sp, simXdata.size(0), 2);
  loop_ub = simXdata.size(0) << 1;
  for (i = 0; i < loop_ub; i++) {
    Simulation[i] = 0.0;
  }

  emlrtSubAssignSizeCheckR2012b(simXdata.size(), 1, simXdata.size(), 1,
    &s_emlrtECI, sp);
  loop_ub = simXdata.size(0);
  for (i = 0; i < loop_ub; i++) {
    Simulation[i] = simXdata[i];
  }

  //  Parallelise over points
  st.site = &hg_emlrtRSI;
  abeles_paraPoints(&st, simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                    static_cast<real_T>(lays), static_cast<real_T>(simXdata.size
    (0)), simRef);

  // (x,sld,nbair,nbsub,nrepeats,ssub,layers,points)
  b_simRef.set_size((&wj_emlrtRTEI), sp, simRef.size(0));
  loop_ub = simRef.size(0) - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_simRef[i] = simRef[i];
  }

  st.site = &ig_emlrtRSI;
  resolution_polly_paraPoints(&st, simXdata, b_simRef, res, static_cast<real_T>
    (simXdata.size(0)), simRef);
  emlrtSubAssignSizeCheckR2012b(Simulation.size(), 1, simRef.size(), 1,
    &r_emlrtECI, sp);
  loop_ub = simRef.size(0);
  for (i = 0; i < loop_ub; i++) {
    Simulation[i + Simulation.size(0)] = simRef[i];
  }

  if (firstSection.size(1) + 1U > splits_idx_1) {
    i = 0;
    n = 0;
  } else {
    i = static_cast<int32_T>(firstSection.size(1) + 1U);
    if ((i < 1) || (i > Simulation.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, Simulation.size(0), &wg_emlrtBCI, sp);
    }

    i--;
    if ((static_cast<int32_T>(splits_idx_1) < 1) || (static_cast<int32_T>
         (splits_idx_1) > Simulation.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(splits_idx_1), 1,
        Simulation.size(0), &vg_emlrtBCI, sp);
    }

    n = static_cast<int32_T>(splits_idx_1);
  }

  loop_ub = n - i;
  reflectivity.set_size((&nj_emlrtRTEI), sp, loop_ub, 2);
  for (n = 0; n < loop_ub; n++) {
    reflectivity[n] = Simulation[i + n];
  }

  for (n = 0; n < loop_ub; n++) {
    reflectivity[n + reflectivity.size(0)] = Simulation[(i + n) +
      Simulation.size(0)];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void callReflectivity(const emlrtStack *sp, real_T nbairs, real_T nbsubs, const
                      real_T simLimits[2], const real_T repeatLayers[2], const
                      coder::array<real_T, 2U> &this_data, const coder::array<
                      real_T, 2U> &layers, real_T ssubs, real_T res, coder::
                      array<real_T, 2U> &reflectivity, coder::array<real_T, 2U>
                      &Simulation)
{
  int32_T ilow;
  coder::array<real_T, 2U> slds;
  int32_T i;
  int32_T lays;
  int32_T i1;
  coder::array<real_T, 2U> firstSection;
  real_T step;
  coder::array<real_T, 2U> lastSection;
  int32_T firstSection_idx_0;
  real_T g;
  coder::array<real_T, 1U> simXdata;
  int32_T loop_ub;
  uint32_T splits_idx_1;
  coder::array<real_T, 1U> simRef;
  int32_T varargin_2;
  coder::array<real_T, 1U> dummydata;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  //  nbairs = problem.nbairs;
  //  nbsubs = problem.nbsubs;
  //  simLimits = problem.simLimits;
  //  repeatLayers = problem.repeatLayers;
  //  allData = problem.shifted_data;
  //  layers = problem.layers;
  //  ssubs = problem.ssubs;
  //  numberOfContrasts = problem.numberOfContrasts;
  //  reflectivity = cell(numberOfContrasts,1);
  //  Simulation = cell(numberOfContrasts,1);
  //
  //  parfor i = 1:numberOfContrasts
  // this_data = allData{i};
  if (1 > this_data.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data.size(1), &dh_emlrtBCI, sp);
  }

  if (layers.size(0) == 0) {
    slds.set_size((&fj_emlrtRTEI), sp, 1, 3);
    slds[0] = 0.0;
    slds[1] = nbairs;
    slds[2] = 0.0;
    lays = 0;
  } else {
    ilow = layers.size(0);
    slds.set_size((&ej_emlrtRTEI), sp, layers.size(0), 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < ilow; i1++) {
        slds[i1 + slds.size(0) * i] = layers[i1 + layers.size(0) * i];
      }
    }

    lays = layers.size(0);
  }

  if (1 > this_data.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data.size(1), &ch_emlrtBCI, sp);
  }

  if (1 > this_data.size(0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, this_data.size(0), &bh_emlrtBCI, sp);
  }

  if (simLimits[0] < this_data[0]) {
    if (2 > this_data.size(0)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, this_data.size(0), &ah_emlrtBCI, sp);
    }

    if (1 > this_data.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data.size(0), &yg_emlrtBCI, sp);
    }

    step = this_data[1] - this_data[0];
    if (1 > this_data.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, this_data.size(0), &xg_emlrtBCI, sp);
    }

    st.site = &nf_emlrtRSI;
    g = this_data[0] - step;
    if (muDoubleScalarIsNaN(step) || muDoubleScalarIsNaN(g)) {
      firstSection.set_size((&hj_emlrtRTEI), (&st), 1, 1);
      firstSection[0] = rtNaN;
    } else if ((step == 0.0) || ((simLimits[0] < g) && (step < 0.0)) || ((g <
                 simLimits[0]) && (step > 0.0))) {
      firstSection.set_size((&hj_emlrtRTEI), (&st), 1, 0);
    } else if ((muDoubleScalarIsInf(simLimits[0]) || muDoubleScalarIsInf(g)) &&
               (muDoubleScalarIsInf(step) || (simLimits[0] == g))) {
      firstSection.set_size((&hj_emlrtRTEI), (&st), 1, 1);
      firstSection[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      firstSection.set_size((&hj_emlrtRTEI), (&st), 1, 1);
      firstSection[0] = simLimits[0];
    } else if ((muDoubleScalarFloor(simLimits[0]) == simLimits[0]) &&
               (muDoubleScalarFloor(step) == step)) {
      ilow = static_cast<int32_T>(muDoubleScalarFloor((g - simLimits[0]) / step));
      firstSection.set_size((&hj_emlrtRTEI), (&st), 1, (ilow + 1));
      for (i = 0; i <= ilow; i++) {
        firstSection[i] = simLimits[0] + step * static_cast<real_T>(i);
      }
    } else {
      b_st.site = &rf_emlrtRSI;
      eml_float_colon(&b_st, simLimits[0], step, g, firstSection);
    }
  } else {
    firstSection.set_size((&gj_emlrtRTEI), sp, 1, 0);
  }

  if (this_data.size(0) < 1) {
    emlrtDynamicBoundsCheckR2012b(this_data.size(0), 1, this_data.size(0),
      &ug_emlrtBCI, sp);
  }

  if (simLimits[1] > this_data[this_data.size(0) - 1]) {
    i = this_data.size(0) - 1;
    if ((i < 1) || (i > this_data.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, this_data.size(0), &sg_emlrtBCI, sp);
    }

    if (this_data.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data.size(0), 1, this_data.size(0),
        &tg_emlrtBCI, sp);
    }

    step = this_data[this_data.size(0) - 1] - this_data[i - 1];
    st.site = &of_emlrtRSI;
    if (this_data.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(this_data.size(0), 1, this_data.size(0),
        &rg_emlrtBCI, &st);
    }

    g = this_data[this_data.size(0) - 1] + step;
    if (muDoubleScalarIsNaN(g) || muDoubleScalarIsNaN(step)) {
      lastSection.set_size((&jj_emlrtRTEI), (&st), 1, 1);
      lastSection[0] = rtNaN;
    } else if ((step == 0.0) || ((g < simLimits[1]) && (step < 0.0)) ||
               ((simLimits[1] < g) && (step > 0.0))) {
      lastSection.set_size((&jj_emlrtRTEI), (&st), 1, 0);
    } else if ((muDoubleScalarIsInf(g) || muDoubleScalarIsInf(simLimits[1])) &&
               (muDoubleScalarIsInf(step) || (g == simLimits[1]))) {
      lastSection.set_size((&jj_emlrtRTEI), (&st), 1, 1);
      lastSection[0] = rtNaN;
    } else if (muDoubleScalarIsInf(step)) {
      lastSection.set_size((&jj_emlrtRTEI), (&st), 1, 1);
      lastSection[0] = g;
    } else if ((muDoubleScalarFloor(g) == g) && (muDoubleScalarFloor(step) ==
                step)) {
      ilow = static_cast<int32_T>(muDoubleScalarFloor((simLimits[1] - g) / step));
      lastSection.set_size((&jj_emlrtRTEI), (&st), 1, (ilow + 1));
      for (i = 0; i <= ilow; i++) {
        lastSection[i] = g + step * static_cast<real_T>(i);
      }
    } else {
      b_st.site = &rf_emlrtRSI;
      eml_float_colon(&b_st, g, step, simLimits[1], lastSection);
    }
  } else {
    lastSection.set_size((&ij_emlrtRTEI), sp, 1, 0);
  }

  firstSection_idx_0 = firstSection.size(1);
  ilow = this_data.size(0);
  simXdata.set_size((&kj_emlrtRTEI), sp, ((firstSection.size(1) + this_data.size
    (0)) + lastSection.size(1)));
  loop_ub = firstSection.size(1);
  for (i = 0; i < loop_ub; i++) {
    simXdata[i] = firstSection[i];
  }

  for (i = 0; i < ilow; i++) {
    simXdata[i + firstSection_idx_0] = this_data[i];
  }

  loop_ub = lastSection.size(1);
  for (i = 0; i < loop_ub; i++) {
    simXdata[(i + firstSection_idx_0) + ilow] = lastSection[i];
  }

  splits_idx_1 = static_cast<uint32_T>(firstSection.size(1)) + this_data.size(0);
  Simulation.set_size((&lj_emlrtRTEI), sp, simXdata.size(0), 2);
  ilow = simXdata.size(0) << 1;
  for (i = 0; i < ilow; i++) {
    Simulation[i] = 0.0;
  }

  emlrtSubAssignSizeCheckR2012b(simXdata.size(), 1, simXdata.size(), 1,
    &s_emlrtECI, sp);
  ilow = simXdata.size(0);
  for (i = 0; i < ilow; i++) {
    Simulation[i] = simXdata[i];
  }

  //  Single cored over points
  st.site = &pf_emlrtRSI;
  abeles_single(&st, simXdata, slds, nbairs, nbsubs, repeatLayers[1], ssubs,
                static_cast<real_T>(lays), static_cast<real_T>(simXdata.size(0)),
                simRef);
  varargin_2 = simXdata.size(0) - 10;
  st.site = &qf_emlrtRSI;
  dummydata.set_size((&mj_emlrtRTEI), (&st), simXdata.size(0));
  ilow = simXdata.size(0);
  for (i = 0; i < ilow; i++) {
    dummydata[i] = 0.0;
  }

  i = simXdata.size(0);
  for (int32_T j = 0; j < i; j++) {
    step = 0.0;
    i1 = j + 1;
    if ((i1 < 1) || (i1 > dummydata.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, dummydata.size(0), &qg_emlrtBCI, &st);
    }

    dummydata[i1 - 1] = 0.0;
    if (j + 1 > 10) {
      ilow = -10;
    } else {
      ilow = -j;
    }

    if (j + 1 < varargin_2) {
      lays = 1;
    } else {
      lays = varargin_2 - j;
    }

    //     try
    i1 = (lays - ilow) + 9;
    emlrtForLoopVectorCheckR2012b(static_cast<real_T>(ilow), 1.0,
      static_cast<real_T>(lays + 9), mxDOUBLE_CLASS, i1 + 1, &ac_emlrtRTEI, &st);
    for (int32_T b_i = 0; b_i <= i1; b_i++) {
      b_st.site = &xf_emlrtRSI;
      lays = j + 1;
      if ((lays < 1) || (lays > simXdata.size(0))) {
        emlrtDynamicBoundsCheckR2012b(lays, 1, simXdata.size(0), &lg_emlrtBCI,
          &b_st);
      }

      firstSection_idx_0 = j + 1;
      if ((firstSection_idx_0 < 1) || (firstSection_idx_0 > simXdata.size(0))) {
        emlrtDynamicBoundsCheckR2012b(firstSection_idx_0, 1, simXdata.size(0),
          &mg_emlrtBCI, &b_st);
      }

      loop_ub = static_cast<int32_T>((static_cast<real_T>(j) + 1.0) +
        static_cast<real_T>(ilow + b_i));
      if ((loop_ub < 1) || (loop_ub > simXdata.size(0))) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, simXdata.size(0), &ng_emlrtBCI,
          &b_st);
      }

      g = (simXdata[loop_ub - 1] - simXdata[firstSection_idx_0 - 1]) / ((res +
        0.0001) * simXdata[lays - 1]);
      g = muDoubleScalarExp(-(g * g));
      step += g;
      lays = j + 1;
      if ((lays < 1) || (lays > dummydata.size(0))) {
        emlrtDynamicBoundsCheckR2012b(lays, 1, dummydata.size(0), &ig_emlrtBCI,
          &st);
      }

      if (loop_ub > simRef.size(0)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, simRef.size(0), &jg_emlrtBCI,
          &st);
      }

      firstSection_idx_0 = j + 1;
      if ((firstSection_idx_0 < 1) || (firstSection_idx_0 > dummydata.size(0)))
      {
        emlrtDynamicBoundsCheckR2012b(firstSection_idx_0, 1, dummydata.size(0),
          &kg_emlrtBCI, &st);
      }

      dummydata[lays - 1] = dummydata[firstSection_idx_0 - 1] + simRef[loop_ub -
        1] * g;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    if (step != 0.0) {
      i1 = j + 1;
      if ((i1 < 1) || (i1 > dummydata.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, dummydata.size(0), &og_emlrtBCI,
          &st);
      }

      lays = j + 1;
      if ((lays < 1) || (lays > dummydata.size(0))) {
        emlrtDynamicBoundsCheckR2012b(lays, 1, dummydata.size(0), &pg_emlrtBCI,
          &st);
      }

      dummydata[i1 - 1] = dummydata[lays - 1] / step;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  emlrtSubAssignSizeCheckR2012b(Simulation.size(), 1, dummydata.size(), 1,
    &r_emlrtECI, sp);
  ilow = dummydata.size(0);
  for (i = 0; i < ilow; i++) {
    Simulation[i + Simulation.size(0)] = dummydata[i];
  }

  if (firstSection.size(1) + 1U > splits_idx_1) {
    i = 0;
    i1 = 0;
  } else {
    i = static_cast<int32_T>(firstSection.size(1) + 1U);
    if ((i < 1) || (i > Simulation.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, Simulation.size(0), &wg_emlrtBCI, sp);
    }

    i--;
    if ((static_cast<int32_T>(splits_idx_1) < 1) || (static_cast<int32_T>
         (splits_idx_1) > Simulation.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(splits_idx_1), 1,
        Simulation.size(0), &vg_emlrtBCI, sp);
    }

    i1 = static_cast<int32_T>(splits_idx_1);
  }

  ilow = i1 - i;
  reflectivity.set_size((&nj_emlrtRTEI), sp, ilow, 2);
  for (i1 = 0; i1 < ilow; i1++) {
    reflectivity[i1] = Simulation[i + i1];
  }

  for (i1 = 0; i1 < ilow; i1++) {
    reflectivity[i1 + reflectivity.size(0)] = Simulation[(i + i1) +
      Simulation.size(0)];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (callReflectivity.cpp)
