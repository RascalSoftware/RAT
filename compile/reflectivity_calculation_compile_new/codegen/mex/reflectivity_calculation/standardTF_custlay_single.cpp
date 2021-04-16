//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  standardTF_custlay_single.cpp
//
//  Code generation for function 'standardTF_custlay_single'
//


// Include files
#include "standardTF_custlay_single.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "groupLayers_Mod.h"
#include "makeSLDProfileXY.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_mexutil.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "standardTF_reflectivityCalculation.h"
#include "strcmp.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo xg_emlrtRSI = { 67, // lineNo
  "standardTF_custlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pathName 
};

static emlrtRSInfo yg_emlrtRSI = { 71, // lineNo
  "standardTF_custlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pathName 
};

static emlrtRSInfo ah_emlrtRSI = { 93, // lineNo
  "standardTF_custlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pathName 
};

static emlrtRSInfo bh_emlrtRSI = { 10, // lineNo
  "call_customLayers",                 // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/call_customLayers.m"// pathName 
};

static emlrtMCInfo emlrtMCI = { 44,    // lineNo
  5,                                   // colNo
  "callMatlabCustomLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callMatlabFunction/callMatlabCustomLayers.m"// pName 
};

static emlrtMCInfo b_emlrtMCI = { 47,  // lineNo
  9,                                   // colNo
  "callMatlabCustomLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callMatlabFunction/callMatlabCustomLayers.m"// pName 
};

static emlrtRTEInfo oc_emlrtRTEI = { 40,// lineNo
  9,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo pc_emlrtRTEI = { 46,// lineNo
  9,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo qc_emlrtRTEI = { 52,// lineNo
  9,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo rc_emlrtRTEI = { 62,// lineNo
  9,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtDCInfo jc_emlrtDCI = { 70, // lineNo
  34,                                  // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  1                                    // checkKind
};

static emlrtECInfo u_emlrtECI = { 1,   // nDims
  72,                                  // lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtECInfo v_emlrtECI = { 2,   // nDims
  72,                                  // lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtBCInfo qk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  77,                                  // lineNo
  27,                                  // colNo
  "allRoughs",                         // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo rk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  29,                                  // colNo
  "resample",                          // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo sk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  82,                                  // lineNo
  35,                                  // colNo
  "dataPresent",                       // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo tk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  85,                                  // lineNo
  31,                                  // colNo
  "backsType",                         // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo w_emlrtECI = { 1,   // nDims
  106,                                 // lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtECInfo x_emlrtECI = { 1,   // nDims
  107,                                 // lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtBCInfo uk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  70,                                  // lineNo
  34,                                  // colNo
  "customFiles",                       // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo vk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  78,                                  // lineNo
  37,                                  // colNo
  "repeatLayers",                      // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo wk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  81,                                  // lineNo
  24,                                  // colNo
  "allData",                           // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  83,                                  // lineNo
  33,                                  // colNo
  "dataLimits",                        // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo yk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  84,                                  // lineNo
  31,                                  // colNo
  "simLimits",                         // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo kc_emlrtDCI = { 26, // lineNo
  17,                                  // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo lc_emlrtDCI = { 25, // lineNo
  16,                                  // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo mc_emlrtDCI = { 25, // lineNo
  16,                                  // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  4                                    // checkKind
};

static emlrtBCInfo al_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  41,                                  // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  47,                                  // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo cl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  53,                                  // lineNo
  5,                                   // colNo
  "allLayers",                         // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo dl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  77,                                  // colNo
  "cBacks",                            // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo el_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  87,                                  // colNo
  "cShifts",                           // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo fl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  98,                                  // colNo
  "cScales",                           // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo gl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  109,                                 // colNo
  "cNbas",                             // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo hl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  118,                                 // colNo
  "cNbss",                             // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo il_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  127,                                 // colNo
  "cRes",                              // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  70,                                  // lineNo
  34,                                  // colNo
  "cCustFiles",                        // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  71,                                  // lineNo
  16,                                  // colNo
  "allRoughs",                         // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ll_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  5,                                   // colNo
  "allLayers",                         // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ml_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  104,                                 // lineNo
  5,                                   // colNo
  "outSsubs",                          // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo nl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  110,                                 // lineNo
  5,                                   // colNo
  "chis",                              // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ol_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  105,                                 // lineNo
  5,                                   // colNo
  "sldProfiles",                       // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo pl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  106,                                 // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ql_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  107,                                 // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo rl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  108,                                 // lineNo
  5,                                   // colNo
  "shifted_data",                      // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo sl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  109,                                 // lineNo
  5,                                   // colNo
  "layerSlds",                         // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo tl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  111,                                 // lineNo
  5,                                   // colNo
  "backgs",                            // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ul_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  5,                                   // colNo
  "qshifts",                           // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo vl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  5,                                   // colNo
  "sfs",                               // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo wl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  5,                                   // colNo
  "nbas",                              // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  5,                                   // colNo
  "nbss",                              // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo yl_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  116,                                 // lineNo
  5,                                   // colNo
  "resols",                            // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo am_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  117,                                 // lineNo
  5,                                   // colNo
  "allRoughs",                         // aName
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo nc_emlrtDCI = { 48, // lineNo
  20,                                  // colNo
  "callMatlabCustomLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callMatlabFunction/callMatlabCustomLayers.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo oc_emlrtDCI = { 48, // lineNo
  20,                                  // colNo
  "callMatlabCustomLayers",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callMatlabFunction/callMatlabCustomLayers.m",// pName 
  4                                    // checkKind
};

static emlrtRTEInfo ul_emlrtRTEI = { 25,// lineNo
  10,                                  // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo vl_emlrtRTEI = { 3,// lineNo
  18,                                  // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo wl_emlrtRTEI = { 41,// lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo xl_emlrtRTEI = { 47,// lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo yl_emlrtRTEI = { 53,// lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo am_emlrtRTEI = { 31,// lineNo
  13,                                  // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo bm_emlrtRTEI = { 72,// lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo cm_emlrtRTEI = { 105,// lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo dm_emlrtRTEI = { 106,// lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo em_emlrtRTEI = { 107,// lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo fm_emlrtRTEI = { 108,// lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRTEInfo gm_emlrtRTEI = { 109,// lineNo
  5,                                   // colNo
  "standardTF_custlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/standardTF_custlay_single.m"// pName 
};

static emlrtRSInfo dh_emlrtRSI = { 44, // lineNo
  "callMatlabCustomLayers",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callMatlabFunction/callMatlabCustomLayers.m"// pathName 
};

static emlrtRSInfo eh_emlrtRSI = { 47, // lineNo
  "callMatlabCustomLayers",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callMatlabFunction/callMatlabCustomLayers.m"// pathName 
};

static emlrtRSInfo fh_emlrtRSI = { 50, // lineNo
  "callMatlabCustomLayers",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callMatlabFunction/callMatlabCustomLayers.m"// pathName 
};

static emlrtRSInfo gh_emlrtRSI = { 51, // lineNo
  "callMatlabCustomLayers",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callMatlabFunction/callMatlabCustomLayers.m"// pathName 
};

// Function Declarations
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tempRough,
  const char_T *identifier);
static void customFileWrapper(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location, const mxArray **g, const mxArray **h);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tempOut,
  const char_T *identifier, coder::array<real_T, 2U> &y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_size_, const char_T *identifier, real_T y[2]);
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static const mxArray *size(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
  *location);

// Function Definitions
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tempRough,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(tempRough), &thisId);
  emlrtDestroyArray(&tempRough);
  return y;
}

static void customFileWrapper(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location, const mxArray **g, const mxArray **h)
{
  const mxArray *pArrays[5];
  const mxArray *mv[2];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  emlrtAssign(g, emlrtCallMATLABR2012b(sp, 2, &mv[0], 5, &pArrays[0],
    "customFileWrapper", true, location));
  emlrtAssign(h, mv[1]);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tempOut,
  const char_T *identifier, coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(tempOut), &thisId, y);
  emlrtDestroyArray(&tempOut);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_size_, const char_T *identifier, real_T y[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_size_), &thisId, y);
  emlrtDestroyArray(&a__output_of_size_);
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *y;
  int32_T iv[2];
  const mxArray *m;
  real_T *pData;
  int32_T i;
  y = NULL;
  iv[0] = u.size(0);
  iv[1] = u.size(1);
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i = 0; b_i < u.size(1); b_i++) {
    pData[i] = u[b_i];
    i++;
  }

  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *size(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
  *location)
{
  const mxArray *pArray;
  const mxArray *m;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m, 1, &pArray, "size", true, location);
}

void standardTF_custlay_single(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_14 *problemDef_cells, const struct2_T *controls, coder::array<
  real_T, 1U> &outSsubs, coder::array<real_T, 1U> &backgs, coder::array<real_T,
  1U> &qshifts, coder::array<real_T, 1U> &sfs, coder::array<real_T, 1U> &nbas,
  coder::array<real_T, 1U> &nbss, coder::array<real_T, 1U> &resols, coder::array<
  real_T, 1U> &chis, coder::array<cell_wrap_10, 1U> &reflectivity, coder::array<
  cell_wrap_10, 1U> &Simulation, coder::array<cell_wrap_1, 1U> &shifted_data,
  coder::array<cell_wrap_8, 1U> &layerSlds, coder::array<cell_wrap_1, 1U>
  &sldProfiles, coder::array<cell_wrap_22, 1U> &allLayers, coder::array<real_T,
  1U> &allRoughs)
{
  real_T calcSld;
  int32_T i;
  int32_T i1;
  int32_T b_i;
  int32_T i2;
  real_T thisBackground;
  real_T thisQshift;
  real_T thisSf;
  real_T thisNba;
  real_T thisNbs;
  real_T thisResol;
  const mxArray *tempOut;
  const mxArray *tempRough;
  const mxArray *y;
  int32_T iv[2];
  const mxArray *b_y;
  real_T n[2];
  coder::array<real_T, 2U> output;
  coder::array<real_T, 2U> theseLayers;
  real_T ssubs;
  coder::array<real_T, 2U> sldProfile;
  coder::array<real_T, 2U> b_sldProfile;
  coder::array<real_T, 2U> shifted_dat;
  coder::array<real_T, 2U> Simul;
  coder::array<real_T, 1U> b_shifted_dat;
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

  //  Extract individual cell arrays
  //  Extract individual parameters from problemDef struct
  // Extract individual parameters from problemDef
  calcSld = controls->calcSld;

  //  Pre-Allocation of output arrays...
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &mc_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(muDoubleScalarFloor(problemDef->numberOfContrasts));
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &lc_emlrtDCI, sp);
  }

  i1 = static_cast<int32_T>(problemDef->numberOfContrasts);
  backgs.set_size((&ul_emlrtRTEI), sp, i1);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &kc_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &oc_emlrtRTEI, sp);
  reflectivity.set_size((&vl_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = reflectivity.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &al_emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&wl_emlrtRTEI), sp, 2, reflectivity[b_i].
      f1.size(1));
    i = reflectivity.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &al_emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&wl_emlrtRTEI), sp, reflectivity[b_i].f1.size
      (0), 2);
    i = reflectivity.size(0) - 1;
    i2 = reflectivity.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &al_emlrtBCI, sp);
    }

    i2 = reflectivity.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &al_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &al_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &al_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &al_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &al_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &pc_emlrtRTEI, sp);
  Simulation.set_size((&vl_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bl_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&xl_emlrtRTEI), sp, 2, Simulation[b_i].f1.size
      (1));
    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bl_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&xl_emlrtRTEI), sp, Simulation[b_i].f1.size(0),
      2);
    i = Simulation.size(0) - 1;
    i2 = Simulation.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bl_emlrtBCI, sp);
    }

    i2 = Simulation.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &bl_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bl_emlrtBCI, sp);
    }

    Simulation[b_i].f1[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bl_emlrtBCI, sp);
    }

    Simulation[b_i].f1[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bl_emlrtBCI, sp);
    }

    Simulation[b_i].f1[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bl_emlrtBCI, sp);
    }

    Simulation[b_i].f1[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &qc_emlrtRTEI, sp);
  allLayers.set_size((&vl_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = allLayers.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cl_emlrtBCI, sp);
    }

    allLayers[b_i].f1.set_size((&yl_emlrtRTEI), sp, 2, allLayers[b_i].f1.size(1));
    i = allLayers.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cl_emlrtBCI, sp);
    }

    allLayers[b_i].f1.set_size((&yl_emlrtRTEI), sp, allLayers[b_i].f1.size(0), 1);
    i = allLayers.size(0) - 1;
    i2 = allLayers.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &cl_emlrtBCI, sp);
    }

    i2 = allLayers.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &cl_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cl_emlrtBCI, sp);
    }

    allLayers[b_i].f1[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cl_emlrtBCI, sp);
    }

    allLayers[b_i].f1[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  //    --- End Memory Allocation ---
  //  Single cored over all contrasts
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &rc_emlrtRTEI, sp);
  allRoughs.set_size((&am_emlrtRTEI), sp, i1);
  allLayers.set_size((&vl_emlrtRTEI), sp, i1);
  outSsubs.set_size((&am_emlrtRTEI), sp, i1);
  sldProfiles.set_size((&vl_emlrtRTEI), sp, i1);
  reflectivity.set_size((&vl_emlrtRTEI), sp, i1);
  Simulation.set_size((&vl_emlrtRTEI), sp, i1);
  shifted_data.set_size((&vl_emlrtRTEI), sp, i1);
  layerSlds.set_size((&vl_emlrtRTEI), sp, i1);
  chis.set_size((&am_emlrtRTEI), sp, i1);
  qshifts.set_size((&am_emlrtRTEI), sp, i1);
  sfs.set_size((&am_emlrtRTEI), sp, i1);
  nbas.set_size((&am_emlrtRTEI), sp, i1);
  nbss.set_size((&am_emlrtRTEI), sp, i1);
  resols.set_size((&am_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    real_T reps;
    int32_T loop_ub;
    const mxArray *m;
    const mxArray *m1;

    //  Extract the relevant parameter values for this contrast
    //  from the input arrays.
    //  First need to decide which values of the backrounds, scalefactors
    //  data shifts and bulk contrasts are associated with this contrast
    i = static_cast<int32_T>(b_i + 1U);
    if ((i < 1) || (i > problemDef->contrastBacks.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacks.size(1),
        &dl_emlrtBCI, sp);
    }

    if (i > problemDef->contrastShifts.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastShifts.size(1),
        &el_emlrtBCI, sp);
    }

    if (i > problemDef->contrastScales.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastScales.size(1),
        &fl_emlrtBCI, sp);
    }

    if (i > problemDef->contrastNbas.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbas.size(1),
        &gl_emlrtBCI, sp);
    }

    if (i > problemDef->contrastNbss.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbss.size(1),
        &hl_emlrtBCI, sp);
    }

    if (i > problemDef->contrastRes.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastRes.size(1),
        &il_emlrtBCI, sp);
    }

    st.site = &xg_emlrtRSI;
    backSort(&st, problemDef->contrastBacks[i - 1], problemDef->contrastShifts[i
             - 1], problemDef->contrastScales[i - 1], problemDef->contrastNbas[i
             - 1], problemDef->contrastNbss[i - 1], problemDef->contrastRes[i -
             1], problemDef->backs, problemDef->shifts, problemDef->sf,
             problemDef->nba, problemDef->nbs, problemDef->res, &thisBackground,
             &thisQshift, &thisSf, &thisNba, &thisNbs, &thisResol);

    //  Call the custom layers function to get the layers array...
    if (i > problemDef->contrastCustomFiles.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastCustomFiles.size(1),
        &jl_emlrtBCI, sp);
    }

    reps = problemDef->contrastCustomFiles[i - 1];
    if (reps != static_cast<int32_T>(muDoubleScalarFloor(reps))) {
      emlrtIntegerCheckR2012b(reps, &jc_emlrtDCI, sp);
    }

    i2 = problemDef_cells->f14.size(1) - 1;
    loop_ub = static_cast<int32_T>(reps) - 1;
    if ((loop_ub < 0) || (loop_ub > i2)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, i2, &uk_emlrtBCI, sp);
    }

    st.site = &yg_emlrtRSI;

    //  Split up the custom file array
    //  switch lang
    //      case 'matlab'
    b_st.site = &bh_emlrtRSI;
    tempOut = NULL;
    tempRough = NULL;

    // persistent fileHandle
    //  Use a coder.extrinsic call here. There is no need to explicitly
    //  define the 'coder.extrinsic' call, as Coder will automatically
    //  pass the excecution of the function back to the calling Matlab
    //  session when it encountes feval in a function to be generated.
    //  Ultimately, we will replace this with a C++ class calling a
    //  separate Matlab engine so that Matlab custom model functions are
    //  still usable when the generated code is used from Python.
    //  https://www.mathworks.com/help/matlab/calling-matlab-engine-from-cpp-programs.html 
    //  Pre-define the outputs to keep the compiler happy
    //  Need to define the size of the outputs with coder preprocessor
    //  directives
    //      coder.varsize('output',[1000 7],[1 1]);
    //      coder.varsize('sRough',[1 1],[0 0]);
    //  Fix output variable type by defining example values
    //      coder.varsize('output',[10 3],[1 1]);
    //      output = [0 0 0];
    // sRough = 3;
    y = NULL;
    iv[0] = problemDef_cells->f14[static_cast<int32_T>
      (problemDef->contrastCustomFiles[b_i]) - 1].f1[0].f1.size(0);
    iv[1] = problemDef_cells->f14[static_cast<int32_T>
      (problemDef->contrastCustomFiles[b_i]) - 1].f1[0].f1.size(1);
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&b_st, problemDef_cells->f14[static_cast<int32_T>
      (problemDef->contrastCustomFiles[b_i]) - 1].f1[0].f1.size(1), m,
      &problemDef_cells->f14[static_cast<int32_T>
      (problemDef->contrastCustomFiles[b_i]) - 1].f1[0].f1[0]);
    emlrtAssign(&y, m);
    b_y = NULL;
    m1 = emlrtCreateDoubleScalar(static_cast<real_T>(b_i) + 1.0);
    emlrtAssign(&b_y, m1);
    c_st.site = &dh_emlrtRSI;
    customFileWrapper(&c_st, y, emlrt_marshallOut(problemDef->params),
                      emlrt_marshallOut(problemDef->nba), emlrt_marshallOut
                      (problemDef->nbs), b_y, &emlrtMCI, &tempOut, &tempRough);
    c_st.site = &eh_emlrtRSI;
    emlrt_marshallIn(&c_st, size(&c_st, emlrtAlias(tempOut), &b_emlrtMCI),
                     "<output of size>", n);
    if (!(n[0] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(n[0], &oc_emlrtDCI, &b_st);
    }

    if (n[0] != static_cast<int32_T>(muDoubleScalarFloor(n[0]))) {
      emlrtIntegerCheckR2012b(n[0], &nc_emlrtDCI, &b_st);
    }

    if (!(n[1] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(n[1], &oc_emlrtDCI, &b_st);
    }

    if (n[1] != static_cast<int32_T>(muDoubleScalarFloor(n[1]))) {
      emlrtIntegerCheckR2012b(n[1], &nc_emlrtDCI, &b_st);
    }

    if (i > allRoughs.size(0)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs.size(0), &kl_emlrtBCI, &b_st);
    }

    c_st.site = &fh_emlrtRSI;
    allRoughs[i - 1] = c_emlrt_marshallIn(&c_st, emlrtAlias(tempRough),
      "tempRough");
    c_st.site = &gh_emlrtRSI;
    e_emlrt_marshallIn(&c_st, emlrtAlias(tempOut), "tempOut", output);
    emlrtDestroyArray(&tempOut);
    emlrtDestroyArray(&tempRough);

    // case 'octave'
    //     [output,layers] = octaveCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut); 
    // case 'python'
    //     [output,layers] = pythonCaller_customLayers(params,contrast,file,callPath,bulkIn,bulkOut); 
    // end
    if (10000 < output.size(0)) {
      emlrtDimSizeGeqCheckR2012b(10000, output.size(0), &u_emlrtECI, sp);
    }

    if (3 < output.size(1)) {
      emlrtDimSizeGeqCheckR2012b(3, output.size(1), &v_emlrtECI, sp);
    }

    loop_ub = output.size(0) * output.size(1);
    i = allLayers.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ll_emlrtBCI, sp);
    }

    allLayers[b_i].f1.set_size((&bm_emlrtRTEI), sp, output.size(0),
      allLayers[b_i].f1.size(1));
    i = allLayers.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ll_emlrtBCI, sp);
    }

    allLayers[b_i].f1.set_size((&bm_emlrtRTEI), sp, allLayers[b_i].f1.size(0),
      output.size(1));
    i = allLayers.size(0) - 1;
    i2 = allLayers.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ll_emlrtBCI, sp);
    }

    i2 = allLayers.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ll_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ll_emlrtBCI, sp);
      }

      allLayers[b_i].f1[i2] = output[i2];
    }

    //  For the other parameters, we extract the correct ones from the input
    //  arrays
    i = b_i + 1;
    if ((i < 1) || (i > allRoughs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs.size(0), &qk_emlrtBCI, sp);
    }

    i = problemDef_cells->f1.size(1) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vk_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > problemDef->resample.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample.size(1),
        &rk_emlrtBCI, sp);
    }

    i = problemDef_cells->f2.size(1) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wk_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > problemDef->dataPresent.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->dataPresent.size(1),
        &sk_emlrtBCI, sp);
    }

    i = problemDef_cells->f3.size(1) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xk_emlrtBCI, sp);
    }

    i = problemDef_cells->f4.size(1) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yk_emlrtBCI, sp);
    }

    i = b_i + 1;
    if ((i < 1) || (i > problemDef->contrastBacksType.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacksType.size(1),
        &tk_emlrtBCI, sp);
    }

    //  Now call the core standardTF_stanlay reflectivity calculation
    //  In this case we are single cored, so we do not parallelise over
    //  points
    //  Call the reflectivity calculation
    st.site = &ah_emlrtRSI;
    reps = calcSld;

    //  function [sldProfile,reflect,Simul,shifted_dat,layerSld,chiSquared,ssubs] = ... 
    //      standardTF_stanlay_core(contrastLayers, rough, ...
    //      geometry, nba, nbs, resample, calcSld, sf, qshift,...
    //      dataPresent, data, dataLimits, simLimits, repeatLayers,...
    //      background,resol,backsType,params,paralellPoints)
    //
    //    This is the main reflectivity calculation for Layers models in the
    //    standard target function. The function first arranges the
    //    roughness' in the correct order according
    //    to geometry. Then, if required it calculates the SLD profile and if
    //    requested resamples this into a number of zero-roughness layers
    //    (roughness resampling). It the applies any scalefactors and qz shifts
    //    the data requires. This is done before calculating the reflectivity to 
    //    ensure that the reflectivity is calculated over the same range in qz as 
    //    the shifted datapoints. The main reflectivity calculation is then
    //    called, including the resolution function. The calculation outputs two 
    //    profiles - 'reflect' which is the same range as the points, and
    //    'Simulation' which can be a different range to allow extrapolation.
    //    The background correction is the applied, and finally chi-squared is
    //    calculated.
    //
    //  Inputs:
    //    contrastLayers  :
    //    rough           :
    //    geometry        :
    //    nba             :
    //    nbs             :
    //    resample        :
    //    calcSld         :
    //    sf              :
    //    qshift          :
    //    dataPresent     :
    //    data            :
    //    dataLimits      :
    //    simLimits       :
    //    repeatLayers    :
    //    background      :
    //    resol           :
    //    backsType       :
    //    params          :
    //    paralellPoints  :
    //
    //  Outputs:
    //
    //
    //
    //  ------------------------------------------------------------------------ 
    //
    //        (c) Arwel Hughes  -   12/1/21
    //
    //        Last Modified: 12/1/21 by Arwel Hughes.
    //
    //  ------------------------------------------------------------------------ 
    //  Bulid up the layers matrix for this contrast
    b_st.site = &m_emlrtRSI;
    b_groupLayers_Mod(&b_st, output, allRoughs[b_i], problemDef->geometry,
                      thisNba, thisNbs, theseLayers, &ssubs);
    i = b_i + 1;
    if ((i < 1) || (i > outSsubs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, outSsubs.size(0), &ml_emlrtBCI, &st);
    }

    outSsubs[i - 1] = ssubs;

    //  Make the SLD profiles.
    //  If resampling is needed, then enforce the calcSLD flag, so as to catch
    //  the error af trying to resample a non-existent profile.
    if ((problemDef->resample[b_i] == 1.0) && (calcSld == 0.0)) {
      reps = 1.0;
    }

    //  If cal SLD flag is set, then calculate the SLD profile
    if (reps == 1.0) {
      b_st.site = &n_emlrtRSI;
      if (problemDef_cells->f1[b_i].f1[0] == 0.0) {
        reps = 1.0;
      } else {
        reps = problemDef_cells->f1[b_i].f1[1];
      }

      c_st.site = &hb_emlrtRSI;
      makeSLDProfileXY(&c_st, thisNba, thisNbs, ssubs, theseLayers, static_cast<
                       real_T>(theseLayers.size(0)), reps, b_sldProfile);
      sldProfile.set_size((&sg_emlrtRTEI), (&st), b_sldProfile.size(0), 2);
      loop_ub = b_sldProfile.size(0) * b_sldProfile.size(1);
      for (i = 0; i < loop_ub; i++) {
        sldProfile[i] = b_sldProfile[i];
      }
    } else {
      sldProfile.set_size((&rg_emlrtRTEI), (&st), 1, 3);
      sldProfile[0] = 0.0;
      sldProfile[1] = 0.0;
      sldProfile[2] = 0.0;
    }

    //  If required, then resample the SLD
    if (problemDef->resample[b_i] == 1.0) {
      b_st.site = &o_emlrtRSI;
      resampleLayers(&b_st, sldProfile, theseLayers);
    }

    //  Apply scale factors and q shifts to the data
    shifted_dat.set_size((&tg_emlrtRTEI), (&st), problemDef_cells->
                         f2[problemDef_cells->f2.size(0) * b_i].f1.size(0),
                         problemDef_cells->f2[problemDef_cells->f2.size(0) * b_i]
                         .f1.size(1));
    loop_ub = problemDef_cells->f2[b_i].f1.size(0) * problemDef_cells->f2[b_i].
      f1.size(1);
    for (i = 0; i < loop_ub; i++) {
      shifted_dat[i] = problemDef_cells->f2[b_i].f1[i];
    }

    b_st.site = &p_emlrtRSI;
    shiftdata(&b_st, thisSf, thisQshift, problemDef->dataPresent[b_i],
              shifted_dat, problemDef_cells->f3[b_i].f1);

    //  Calculate the reflectivity
    b_st.site = &q_emlrtRSI;
    callReflectivity(&b_st, thisNba, thisNbs, problemDef_cells->f4[b_i].f1,
                     problemDef_cells->f1[b_i].f1, shifted_dat, theseLayers,
                     ssubs, thisResol, b_sldProfile, Simul);

    //  Apply background correction, either to the simulation or the data
    b_st.site = &r_emlrtRSI;
    if (problemDef->contrastBacksType[b_i] != static_cast<int32_T>
        (muDoubleScalarFloor(problemDef->contrastBacksType[b_i]))) {
      emlrtIntegerCheckR2012b(problemDef->contrastBacksType[b_i], &rb_emlrtDCI,
        &b_st);
    }

    switch (static_cast<int32_T>(problemDef->contrastBacksType[b_i])) {
     case 1:
      // Add background to the simulation
      loop_ub = b_sldProfile.size(0) * b_sldProfile.size(1);
      b_sldProfile.set_size((&ug_emlrtRTEI), (&b_st), b_sldProfile.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        b_sldProfile[i] = b_sldProfile[i] + thisBackground;
      }

      loop_ub = Simul.size(0) * Simul.size(1);
      Simul.set_size((&vg_emlrtRTEI), (&b_st), Simul.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        Simul[i] = Simul[i] + thisBackground;
      }
      break;

     case 2:
      //          %Subtract the background from the data..
      if (2 > shifted_dat.size(1)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat.size(1), &re_emlrtBCI,
          &b_st);
      }

      if (2 > shifted_dat.size(1)) {
        emlrtDynamicBoundsCheckR2012b(2, 1, shifted_dat.size(1), &qe_emlrtBCI,
          &b_st);
      }

      emlrtSubAssignSizeCheckR2012b(shifted_dat.size(), 1, shifted_dat.size(), 1,
        &emlrtECI, &b_st);
      loop_ub = shifted_dat.size(0) - 1;
      b_shifted_dat.set_size((&wg_emlrtRTEI), (&b_st), shifted_dat.size(0));
      for (i = 0; i <= loop_ub; i++) {
        b_shifted_dat[i] = shifted_dat[i + shifted_dat.size(0)] - thisBackground;
      }

      loop_ub = b_shifted_dat.size(0);
      for (i = 0; i < loop_ub; i++) {
        shifted_dat[i + shifted_dat.size(0)] = b_shifted_dat[i];
      }

      // shifted_dat(:,3) = shifted_dat(:,3) - backg;
      break;
    }

    //  Calculate chi squared.
    i = b_i + 1;
    if ((i < 1) || (i > chis.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, chis.size(0), &nl_emlrtBCI, &st);
    }

    b_st.site = &s_emlrtRSI;
    chis[i - 1] = chiSquared(&b_st, shifted_dat, b_sldProfile,
      static_cast<real_T>(problemDef->params.size(1)));

    //  Store returned values for this contrast in the output arrays.
    //  As well as the calculated profiles, we also store a record of
    //  the other values (background, scalefactors etc) for each contrast
    //  for future use.
    loop_ub = sldProfile.size(0) * sldProfile.size(1);
    i = sldProfiles.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ol_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1.set_size((&cm_emlrtRTEI), sp, sldProfile.size(0),
      sldProfiles[b_i].f1.size(1));
    i = sldProfiles.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ol_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1.set_size((&cm_emlrtRTEI), sp, sldProfiles[b_i].f1.size(0),
      sldProfile.size(1));
    i = sldProfiles.size(0) - 1;
    i2 = sldProfiles.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ol_emlrtBCI, sp);
    }

    i2 = sldProfiles.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ol_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ol_emlrtBCI, sp);
      }

      sldProfiles[b_i].f1[i2] = sldProfile[i2];
    }

    if (10000 < b_sldProfile.size(0)) {
      emlrtDimSizeGeqCheckR2012b(10000, b_sldProfile.size(0), &w_emlrtECI, sp);
    }

    loop_ub = b_sldProfile.size(0) * b_sldProfile.size(1);
    i = reflectivity.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pl_emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&dm_emlrtRTEI), sp, b_sldProfile.size(0),
      reflectivity[b_i].f1.size(1));
    i = reflectivity.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pl_emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&dm_emlrtRTEI), sp, reflectivity[b_i].f1.size
      (0), 2);
    i = reflectivity.size(0) - 1;
    i2 = reflectivity.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &pl_emlrtBCI, sp);
    }

    i2 = reflectivity.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &pl_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pl_emlrtBCI, sp);
      }

      reflectivity[b_i].f1[i2] = b_sldProfile[i2];
    }

    if (10000 < Simul.size(0)) {
      emlrtDimSizeGeqCheckR2012b(10000, Simul.size(0), &x_emlrtECI, sp);
    }

    loop_ub = Simul.size(0) * Simul.size(1);
    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ql_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&em_emlrtRTEI), sp, Simul.size(0),
      Simulation[b_i].f1.size(1));
    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ql_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&em_emlrtRTEI), sp, Simulation[b_i].f1.size(0),
      2);
    i = Simulation.size(0) - 1;
    i2 = Simulation.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ql_emlrtBCI, sp);
    }

    i2 = Simulation.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &ql_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ql_emlrtBCI, sp);
      }

      Simulation[b_i].f1[i2] = Simul[i2];
    }

    loop_ub = shifted_dat.size(0) * shifted_dat.size(1);
    i = shifted_data.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rl_emlrtBCI, sp);
    }

    shifted_data[b_i].f1.set_size((&fm_emlrtRTEI), sp, shifted_dat.size(0),
      shifted_data[b_i].f1.size(1));
    i = shifted_data.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rl_emlrtBCI, sp);
    }

    shifted_data[b_i].f1.set_size((&fm_emlrtRTEI), sp, shifted_data[b_i].f1.size
      (0), shifted_dat.size(1));
    i = shifted_data.size(0) - 1;
    i2 = shifted_data.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &rl_emlrtBCI, sp);
    }

    i2 = shifted_data.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &rl_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rl_emlrtBCI, sp);
      }

      shifted_data[b_i].f1[i2] = shifted_dat[i2];
    }

    loop_ub = theseLayers.size(0) * theseLayers.size(1);
    i = layerSlds.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sl_emlrtBCI, sp);
    }

    layerSlds[b_i].f1.set_size((&gm_emlrtRTEI), sp, theseLayers.size(0),
      layerSlds[b_i].f1.size(1));
    i = layerSlds.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sl_emlrtBCI, sp);
    }

    layerSlds[b_i].f1.set_size((&gm_emlrtRTEI), sp, layerSlds[b_i].f1.size(0), 3);
    i = layerSlds.size(0) - 1;
    i2 = layerSlds.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &sl_emlrtBCI, sp);
    }

    i2 = layerSlds.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &sl_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sl_emlrtBCI, sp);
      }

      layerSlds[b_i].f1[i2] = theseLayers[i2];
    }

    i = b_i + 1;
    if ((i < 1) || (i > backgs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, backgs.size(0), &tl_emlrtBCI, sp);
    }

    backgs[i - 1] = thisBackground;
    i = b_i + 1;
    if ((i < 1) || (i > qshifts.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, qshifts.size(0), &ul_emlrtBCI, sp);
    }

    qshifts[i - 1] = thisQshift;
    i = b_i + 1;
    if ((i < 1) || (i > sfs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, sfs.size(0), &vl_emlrtBCI, sp);
    }

    sfs[i - 1] = thisSf;
    i = b_i + 1;
    if ((i < 1) || (i > nbas.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbas.size(0), &wl_emlrtBCI, sp);
    }

    nbas[i - 1] = thisNba;
    i = b_i + 1;
    if ((i < 1) || (i > nbss.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, nbss.size(0), &xl_emlrtBCI, sp);
    }

    nbss[i - 1] = thisNbs;
    i = b_i + 1;
    if ((i < 1) || (i > resols.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, resols.size(0), &yl_emlrtBCI, sp);
    }

    resols[i - 1] = thisResol;
    i = b_i + 1;
    if ((i < 1) || (i > allRoughs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs.size(0), &am_emlrtBCI, sp);
    }

    allRoughs[i - 1] = allRoughs[b_i];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (standardTF_custlay_single.cpp)
