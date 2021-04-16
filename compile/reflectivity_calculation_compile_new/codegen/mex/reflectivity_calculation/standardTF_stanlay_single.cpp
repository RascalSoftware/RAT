//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  standardTF_stanlay_single.cpp
//
//  Code generation for function 'standardTF_stanlay_single'
//


// Include files
#include "standardTF_stanlay_single.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_mexutil.h"
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "standardTF_layers_core.h"
#include "standardTF_reflectivityCalculation.h"
#include "standardTF_stanlay_paraAll.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo i_emlrtRSI = { 58,  // lineNo
  "standardTF_stanlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pathName 
};

static emlrtRSInfo j_emlrtRSI = { 67,  // lineNo
  "standardTF_stanlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pathName 
};

static emlrtRSInfo k_emlrtRSI = { 72,  // lineNo
  "standardTF_stanlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pathName 
};

static emlrtRSInfo l_emlrtRSI = { 92,  // lineNo
  "standardTF_stanlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pathName 
};

static emlrtRTEInfo jb_emlrtRTEI = { 39,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo kb_emlrtRTEI = { 44,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo lb_emlrtRTEI = { 49,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo mb_emlrtRTEI = { 61,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtBCInfo rc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  76,                                  // lineNo
  24,                                  // colNo
  "params",                            // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo sc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  78,                                  // lineNo
  29,                                  // colNo
  "resample",                          // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo tc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  81,                                  // lineNo
  35,                                  // colNo
  "dataPresent",                       // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo uc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  84,                                  // lineNo
  31,                                  // colNo
  "backsType",                         // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo vc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  77,                                  // lineNo
  37,                                  // colNo
  "repeatLayers",                      // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo wc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  24,                                  // colNo
  "allData",                           // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  82,                                  // lineNo
  33,                                  // colNo
  "dataLimits",                        // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo yc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  83,                                  // lineNo
  31,                                  // colNo
  "simLimits",                         // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo gb_emlrtDCI = { 26, // lineNo
  17,                                  // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo hb_emlrtDCI = { 25, // lineNo
  16,                                  // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo ib_emlrtDCI = { 25, // lineNo
  16,                                  // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  4                                    // checkKind
};

static emlrtBCInfo ad_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  40,                                  // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  45,                                  // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo cd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  5,                                   // colNo
  "allLayers",                         // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo dd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  77,                                  // colNo
  "cBacks",                            // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ed_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  87,                                  // colNo
  "cShifts",                           // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo fd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  98,                                  // colNo
  "cScales",                           // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo gd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  109,                                 // colNo
  "cNbas",                             // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo hd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  118,                                 // colNo
  "cNbss",                             // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo id_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  127,                                 // colNo
  "cRes",                              // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  52,                                  // colNo
  "contrastLayers",                    // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  104,                                 // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ld_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  105,                                 // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo md_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  106,                                 // lineNo
  5,                                   // colNo
  "shifted_data",                      // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo nd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  107,                                 // lineNo
  5,                                   // colNo
  "layerSlds",                         // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo od_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  108,                                 // lineNo
  5,                                   // colNo
  "chis",                              // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo pd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  102,                                 // lineNo
  5,                                   // colNo
  "outSsubs",                          // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo qd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  103,                                 // lineNo
  5,                                   // colNo
  "sldProfiles",                       // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo rd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  109,                                 // lineNo
  5,                                   // colNo
  "backgs",                            // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo sd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  110,                                 // lineNo
  5,                                   // colNo
  "qshifts",                           // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo td_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  111,                                 // lineNo
  5,                                   // colNo
  "sfs",                               // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ud_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  5,                                   // colNo
  "nbas",                              // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo vd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  5,                                   // colNo
  "nbss",                              // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo wd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  5,                                   // colNo
  "resols",                            // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  5,                                   // colNo
  "allRoughs",                         // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo ig_emlrtRTEI = { 25,// lineNo
  10,                                  // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo jg_emlrtRTEI = { 4,// lineNo
  18,                                  // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo kg_emlrtRTEI = { 40,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo lg_emlrtRTEI = { 45,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo mg_emlrtRTEI = { 50,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo ng_emlrtRTEI = { 32,// lineNo
  12,                                  // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo og_emlrtRTEI = { 103,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

// Function Definitions
void standardTF_stanlay_single(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_14 *problemDef_cells, const struct2_T *controls, coder::array<
  real_T, 1U> &outSsubs, coder::array<real_T, 1U> &backgs, coder::array<real_T,
  1U> &qshifts, coder::array<real_T, 1U> &sfs, coder::array<real_T, 1U> &nbas,
  coder::array<real_T, 1U> &nbss, coder::array<real_T, 1U> &resols, coder::array<
  real_T, 1U> &chis, coder::array<cell_wrap_7, 1U> &reflectivity, coder::array<
  cell_wrap_7, 1U> &Simulation, coder::array<cell_wrap_1, 1U> &shifted_data,
  coder::array<cell_wrap_8, 1U> &layerSlds, coder::array<cell_wrap_1, 1U>
  &sldProfiles, coder::array<cell_wrap_1, 1U> &allLayers, coder::array<real_T,
  1U> &allRoughs)
{
  int32_T i;
  int32_T i1;
  int32_T b_i;
  int32_T i2;
  coder::array<cell_wrap_15, 2U> outParameterisedLayers;
  real_T thisBackground;
  real_T thisQshift;
  real_T thisSf;
  real_T thisNba;
  real_T thisNbs;
  real_T thisResol;
  coder::array<real_T, 2U> thisContrastLayers;
  coder::array<real_T, 2U> sldProfile;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  //  Extract individual cell arrays
  //  Extract individual parameters from problemDef struct
  // Extract individual parameters from problemDef
  //  Allocate the memory for the output arrays before the main loop
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &ib_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(muDoubleScalarFloor(problemDef->numberOfContrasts));
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &hb_emlrtDCI, sp);
  }

  i1 = static_cast<int32_T>(problemDef->numberOfContrasts);
  backgs.set_size((&ig_emlrtRTEI), sp, i1);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &gb_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &jb_emlrtRTEI, sp);
  reflectivity.set_size((&jg_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = reflectivity.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ad_emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&kg_emlrtRTEI), sp, 2, reflectivity[b_i].
      f1.size(1));
    i = reflectivity.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ad_emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&kg_emlrtRTEI), sp, reflectivity[b_i].f1.size
      (0), 2);
    i = reflectivity.size(0) - 1;
    i2 = reflectivity.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ad_emlrtBCI, sp);
    }

    i2 = reflectivity.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ad_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ad_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ad_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ad_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ad_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &kb_emlrtRTEI, sp);
  Simulation.set_size((&jg_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bd_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&lg_emlrtRTEI), sp, 2, Simulation[b_i].f1.size
      (1));
    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bd_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&lg_emlrtRTEI), sp, Simulation[b_i].f1.size(0),
      2);
    i = Simulation.size(0) - 1;
    i2 = Simulation.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bd_emlrtBCI, sp);
    }

    i2 = Simulation.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bd_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bd_emlrtBCI, sp);
    }

    Simulation[b_i].f1[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bd_emlrtBCI, sp);
    }

    Simulation[b_i].f1[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bd_emlrtBCI, sp);
    }

    Simulation[b_i].f1[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bd_emlrtBCI, sp);
    }

    Simulation[b_i].f1[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &lb_emlrtRTEI, sp);
  allLayers.set_size((&jg_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = allLayers.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cd_emlrtBCI, sp);
    }

    allLayers[b_i].f1.set_size((&mg_emlrtRTEI), sp, 2, allLayers[b_i].f1.size(1));
    i = allLayers.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cd_emlrtBCI, sp);
    }

    allLayers[b_i].f1.set_size((&mg_emlrtRTEI), sp, allLayers[b_i].f1.size(0), 1);
    i = allLayers.size(0) - 1;
    i2 = allLayers.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &cd_emlrtBCI, sp);
    }

    i2 = allLayers.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &cd_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cd_emlrtBCI, sp);
    }

    allLayers[b_i].f1[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cd_emlrtBCI, sp);
    }

    allLayers[b_i].f1[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  //  end memory allocation.
  //  First we need to allocate the absolute values of the input
  //  parameters to all the layers in the layers list. This only needs
  //  to be done once, and so is done outside the contrasts loop
  st.site = &i_emlrtRSI;
  allocateParamsToLayers(&st, problemDef->params, problemDef_cells->f6,
    outParameterisedLayers);

  //  Loop over all the contrasts
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &mb_emlrtRTEI, sp);
  outSsubs.set_size((&ng_emlrtRTEI), sp, i1);
  sldProfiles.set_size((&jg_emlrtRTEI), sp, i1);
  reflectivity.set_size((&jg_emlrtRTEI), sp, i1);
  Simulation.set_size((&jg_emlrtRTEI), sp, i1);
  shifted_data.set_size((&jg_emlrtRTEI), sp, i1);
  layerSlds.set_size((&jg_emlrtRTEI), sp, i1);
  chis.set_size((&ng_emlrtRTEI), sp, i1);
  qshifts.set_size((&ng_emlrtRTEI), sp, i1);
  sfs.set_size((&ng_emlrtRTEI), sp, i1);
  nbas.set_size((&ng_emlrtRTEI), sp, i1);
  nbss.set_size((&ng_emlrtRTEI), sp, i1);
  resols.set_size((&ng_emlrtRTEI), sp, i1);
  allRoughs.set_size((&ng_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    int32_T loop_ub;

    //  Extract the relevant parameter values for this contrast
    //  from the input arrays.
    //  First need to decide which values of the backrounds, scalefactors
    //  data shifts and bulk contrasts are associated with this contrast
    i = static_cast<int32_T>(b_i + 1U);
    if ((i < 1) || (i > problemDef->contrastBacks.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacks.size(1),
        &dd_emlrtBCI, sp);
    }

    if (i > problemDef->contrastShifts.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastShifts.size(1),
        &ed_emlrtBCI, sp);
    }

    if (i > problemDef->contrastScales.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastScales.size(1),
        &fd_emlrtBCI, sp);
    }

    if (i > problemDef->contrastNbas.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbas.size(1),
        &gd_emlrtBCI, sp);
    }

    if (i > problemDef->contrastNbss.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbss.size(1),
        &hd_emlrtBCI, sp);
    }

    if (i > problemDef->contrastRes.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastRes.size(1),
        &id_emlrtBCI, sp);
    }

    st.site = &j_emlrtRSI;
    backSort(&st, problemDef->contrastBacks[i - 1], problemDef->contrastShifts[i
             - 1], problemDef->contrastScales[i - 1], problemDef->contrastNbas[i
             - 1], problemDef->contrastNbss[i - 1], problemDef->contrastRes[i -
             1], problemDef->backs, problemDef->shifts, problemDef->sf,
             problemDef->nba, problemDef->nbs, problemDef->res, &thisBackground,
             &thisQshift, &thisSf, &thisNba, &thisNbs, &thisResol);

    //  Also need to determine which layers from the overall layers list
    //  are required for this contrast, and put them in the correct order
    //  according to geometry
    i = problemDef_cells->f5.size(1) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &jd_emlrtBCI, sp);
    }

    st.site = &k_emlrtRSI;
    allocateLayersForContrast(&st, problemDef_cells->f5[b_i].f1,
      outParameterisedLayers, thisContrastLayers);

    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    if (1 > problemDef->params.size(1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params.size(1),
        &rc_emlrtBCI, sp);
    }

    //  Substrate roughness is always first parameter for standard layers
    i = problemDef_cells->f1.size(1) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vc_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > problemDef->resample.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample.size(1),
        &sc_emlrtBCI, sp);
    }

    i = problemDef_cells->f2.size(1) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wc_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > problemDef->dataPresent.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->dataPresent.size(1),
        &tc_emlrtBCI, sp);
    }

    i = problemDef_cells->f3.size(1) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xc_emlrtBCI, sp);
    }

    i = problemDef_cells->f4.size(1) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yc_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > problemDef->contrastBacksType.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacksType.size(1),
        &uc_emlrtBCI, sp);
    }

    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we are single cored, so we do not parallelise over
    //  points
    //  Call the calculation
    i = reflectivity.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kd_emlrtBCI, sp);
    }

    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ld_emlrtBCI, sp);
    }

    i = shifted_data.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &md_emlrtBCI, sp);
    }

    i = layerSlds.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nd_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > chis.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, chis.size(0), &od_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > outSsubs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, outSsubs.size(0), &pd_emlrtBCI, sp);
    }

    st.site = &l_emlrtRSI;
    standardTF_layers_core(&st, thisContrastLayers, problemDef->params[0],
      problemDef->geometry, thisNba, thisNbs, problemDef->resample[b_i],
      controls->calcSld, thisSf, thisQshift, problemDef->dataPresent[b_i],
      problemDef_cells->f2[b_i].f1, problemDef_cells->f3[b_i].f1,
      problemDef_cells->f4[b_i].f1, problemDef_cells->f1[b_i].f1, thisBackground,
      thisResol, problemDef->contrastBacksType[b_i], static_cast<real_T>
      (problemDef->params.size(1)), sldProfile, reflectivity[b_i].f1,
      Simulation[b_i].f1, shifted_data[b_i].f1, layerSlds[b_i].f1, &chis[i - 1],
      &outSsubs[i2 - 1]);

    //  Store returned values for this contrast in the output arrays.
    //  As well as the calculated profiles, we also store a record of
    //  the other values (background, scalefactors etc) for each contrast
    //  for future use.
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    i = sldProfiles.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qd_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1.set_size((&og_emlrtRTEI), sp, sldProfile.size(0),
      sldProfiles[b_i].f1.size(1));
    i = sldProfiles.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qd_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1.set_size((&og_emlrtRTEI), sp, sldProfiles[b_i].f1.size(0),
      sldProfile.size(1));
    i = sldProfiles.size(0) - 1;
    i2 = sldProfiles.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &qd_emlrtBCI, sp);
    }

    i2 = sldProfiles.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &qd_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qd_emlrtBCI, sp);
      }

      sldProfiles[b_i].f1[i2] = sldProfile[i2];
    }

    i = b_i + 1;
    if ((i < 1) || (i > backgs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs.size(0), &rd_emlrtBCI, sp);
    }

    backgs[i - 1] = thisBackground;
    i = b_i + 1;
    if ((i < 1) || (i > qshifts.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, qshifts.size(0), &sd_emlrtBCI, sp);
    }

    qshifts[i - 1] = thisQshift;
    i = b_i + 1;
    if ((i < 1) || (i > sfs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, sfs.size(0), &td_emlrtBCI, sp);
    }

    sfs[i - 1] = thisSf;
    i = b_i + 1;
    if ((i < 1) || (i > nbas.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbas.size(0), &ud_emlrtBCI, sp);
    }

    nbas[i - 1] = thisNba;
    i = b_i + 1;
    if ((i < 1) || (i > nbss.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbss.size(0), &vd_emlrtBCI, sp);
    }

    nbss[i - 1] = thisNbs;
    i = b_i + 1;
    if ((i < 1) || (i > resols.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, resols.size(0), &wd_emlrtBCI, sp);
    }

    resols[i - 1] = thisResol;
    i = b_i + 1;
    if ((i < 1) || (i > allRoughs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs.size(0), &xd_emlrtBCI, sp);
    }

    allRoughs[i - 1] = problemDef->params[0];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (standardTF_stanlay_single.cpp)
