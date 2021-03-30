//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  standardTF_stanLay_reflectivityCalculation.cpp
//
//  Code generation for function 'standardTF_stanLay_reflectivityCalculation'
//


// Include files
#include "standardTF_stanLay_reflectivityCalculation.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "groupLayers_Mod.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "standardTF_stanlay_paraAll.h"
#include "standardTF_stanlay_paraContrasts.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo c_emlrtRSI = { 50,  // lineNo
  "standardTF_stanLay_reflectivityCalculation",// fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 57,  // lineNo
  "standardTF_stanLay_reflectivityCalculation",// fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 65,  // lineNo
  "standardTF_stanLay_reflectivityCalculation",// fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pathName 
};

static emlrtRSInfo f_emlrtRSI = { 72,  // lineNo
  "standardTF_stanLay_reflectivityCalculation",// fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pathName 
};

static emlrtRSInfo g_emlrtRSI = { 87,  // lineNo
  "standardTF_stanLay_reflectivityCalculation",// fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pathName 
};

static emlrtRSInfo h_emlrtRSI = { 57,  // lineNo
  "standardTF_stanlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pathName 
};

static emlrtRSInfo i_emlrtRSI = { 66,  // lineNo
  "standardTF_stanlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pathName 
};

static emlrtRSInfo j_emlrtRSI = { 71,  // lineNo
  "standardTF_stanlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pathName 
};

static emlrtRSInfo k_emlrtRSI = { 91,  // lineNo
  "standardTF_stanlay_single",         // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pathName 
};

static emlrtRSInfo cg_emlrtRSI = { 58, // lineNo
  "standardTF_stanlay_paraPoints",     // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pathName 
};

static emlrtRSInfo dg_emlrtRSI = { 67, // lineNo
  "standardTF_stanlay_paraPoints",     // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pathName 
};

static emlrtRSInfo eg_emlrtRSI = { 72, // lineNo
  "standardTF_stanlay_paraPoints",     // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pathName 
};

static emlrtRSInfo fg_emlrtRSI = { 91, // lineNo
  "standardTF_stanlay_paraPoints",     // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pathName 
};

static emlrtDCInfo g_emlrtDCI = { 15,  // lineNo
  21,                                  // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtRTEInfo s_emlrtRTEI = { 16,// lineNo
  9,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo t_emlrtRTEI = { 21,// lineNo
  9,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo u_emlrtRTEI = { 26,// lineNo
  9,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo v_emlrtRTEI = { 31,// lineNo
  9,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo w_emlrtRTEI = { 36,// lineNo
  9,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo x_emlrtRTEI = { 41,// lineNo
  9,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo y_emlrtRTEI = { 38,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo ab_emlrtRTEI = { 43,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo bb_emlrtRTEI = { 48,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo cb_emlrtRTEI = { 60,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtBCInfo x_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  75,                                  // lineNo
  24,                                  // colNo
  "params",                            // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo y_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  77,                                  // lineNo
  29,                                  // colNo
  "resample",                          // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ab_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  35,                                  // colNo
  "dataPresent",                       // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  83,                                  // lineNo
  31,                                  // colNo
  "backsType",                         // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo cb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  76,                                  // lineNo
  37,                                  // colNo
  "repeatLayers",                      // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo db_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  24,                                  // colNo
  "allData",                           // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo eb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  81,                                  // lineNo
  33,                                  // colNo
  "dataLimits",                        // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo fb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  82,                                  // lineNo
  31,                                  // colNo
  "simLimits",                         // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo db_emlrtRTEI = { 39,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pName 
};

static emlrtRTEInfo eb_emlrtRTEI = { 44,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pName 
};

static emlrtRTEInfo fb_emlrtRTEI = { 49,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pName 
};

static emlrtRTEInfo gb_emlrtRTEI = { 61,// lineNo
  9,                                   // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pName 
};

static emlrtBCInfo gb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  76,                                  // lineNo
  24,                                  // colNo
  "params",                            // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo hb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  78,                                  // lineNo
  29,                                  // colNo
  "resample",                          // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ib_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  81,                                  // lineNo
  35,                                  // colNo
  "dataPresent",                       // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  84,                                  // lineNo
  31,                                  // colNo
  "backsType",                         // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  77,                                  // lineNo
  37,                                  // colNo
  "repeatLayers",                      // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo lb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  24,                                  // colNo
  "allData",                           // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo mb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  82,                                  // lineNo
  33,                                  // colNo
  "dataLimits",                        // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo nb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  83,                                  // lineNo
  31,                                  // colNo
  "simLimits",                         // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo h_emlrtDCI = { 25,  // lineNo
  17,                                  // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo i_emlrtDCI = { 26,  // lineNo
  17,                                  // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo j_emlrtDCI = { 79,  // lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo k_emlrtDCI = { 79,  // lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo l_emlrtDCI = { 80,  // lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo m_emlrtDCI = { 81,  // lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo n_emlrtDCI = { 82,  // lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo o_emlrtDCI = { 83,  // lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo p_emlrtDCI = { 84,  // lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo q_emlrtDCI = { 11,  // lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo r_emlrtDCI = { 85,  // lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo s_emlrtDCI = { 88,  // lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo ob_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  17,                                  // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo pb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  22,                                  // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo qb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  27,                                  // lineNo
  5,                                   // colNo
  "shifted_data",                      // aName
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo rb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  32,                                  // lineNo
  5,                                   // colNo
  "layerSlds",                         // aName
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo sb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  37,                                  // lineNo
  5,                                   // colNo
  "sldProfiles",                       // aName
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo tb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  42,                                  // lineNo
  5,                                   // colNo
  "allLayers",                         // aName
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo t_emlrtDCI = { 24,  // lineNo
  16,                                  // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo u_emlrtDCI = { 24,  // lineNo
  16,                                  // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo v_emlrtDCI = { 25,  // lineNo
  16,                                  // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo w_emlrtDCI = { 25,  // lineNo
  16,                                  // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  4                                    // checkKind
};

static emlrtBCInfo ub_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  39,                                  // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo vb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  40,                                  // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo wb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  44,                                  // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  45,                                  // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo yb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  49,                                  // lineNo
  5,                                   // colNo
  "allLayers",                         // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ac_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  50,                                  // lineNo
  5,                                   // colNo
  "allLayers",                         // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  66,                                  // lineNo
  77,                                  // colNo
  "cBacks",                            // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo cc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  66,                                  // lineNo
  87,                                  // colNo
  "cShifts",                           // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo dc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  66,                                  // lineNo
  98,                                  // colNo
  "cScales",                           // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ec_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  66,                                  // lineNo
  109,                                 // colNo
  "cNbas",                             // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo fc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  66,                                  // lineNo
  118,                                 // colNo
  "cNbss",                             // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo gc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  66,                                  // lineNo
  127,                                 // colNo
  "cRes",                              // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo hc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  77,                                  // colNo
  "cBacks",                            // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ic_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  87,                                  // colNo
  "cShifts",                           // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  98,                                  // colNo
  "cScales",                           // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  109,                                 // colNo
  "cNbas",                             // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo lc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  118,                                 // colNo
  "cNbss",                             // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo mc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  127,                                 // colNo
  "cRes",                              // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo nc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  71,                                  // lineNo
  52,                                  // colNo
  "contrastLayers",                    // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo oc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  72,                                  // lineNo
  52,                                  // colNo
  "contrastLayers",                    // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo pc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  104,                                 // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo qc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  105,                                 // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo rc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  106,                                 // lineNo
  5,                                   // colNo
  "shifted_data",                      // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo sc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  107,                                 // lineNo
  5,                                   // colNo
  "layerSlds",                         // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo tc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  108,                                 // lineNo
  5,                                   // colNo
  "chis",                              // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo uc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  102,                                 // lineNo
  5,                                   // colNo
  "outSsubs",                          // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo vc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  103,                                 // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo wc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  104,                                 // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo xc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  105,                                 // lineNo
  5,                                   // colNo
  "shifted_data",                      // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo yc_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  106,                                 // lineNo
  5,                                   // colNo
  "layerSlds",                         // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ad_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  107,                                 // lineNo
  5,                                   // colNo
  "chis",                              // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  101,                                 // lineNo
  5,                                   // colNo
  "outSsubs",                          // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo cd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  103,                                 // lineNo
  5,                                   // colNo
  "sldProfiles",                       // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo dd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  102,                                 // lineNo
  5,                                   // colNo
  "sldProfiles",                       // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ed_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  109,                                 // lineNo
  5,                                   // colNo
  "backgs",                            // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo fd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  108,                                 // lineNo
  5,                                   // colNo
  "backgs",                            // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo gd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  110,                                 // lineNo
  5,                                   // colNo
  "qshifts",                           // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo hd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  109,                                 // lineNo
  5,                                   // colNo
  "qshifts",                           // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo id_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  111,                                 // lineNo
  5,                                   // colNo
  "sfs",                               // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  110,                                 // lineNo
  5,                                   // colNo
  "sfs",                               // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  5,                                   // colNo
  "nbas",                              // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ld_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  111,                                 // lineNo
  5,                                   // colNo
  "nbas",                              // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo md_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  5,                                   // colNo
  "nbss",                              // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo nd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  5,                                   // colNo
  "nbss",                              // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo od_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  5,                                   // colNo
  "resols",                            // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo pd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  5,                                   // colNo
  "resols",                            // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo qd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  5,                                   // colNo
  "allRoughs",                         // aName
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo rd_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  5,                                   // colNo
  "allRoughs",                         // aName
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo qd_emlrtRTEI = { 79,// lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo rd_emlrtRTEI = { 80,// lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo sd_emlrtRTEI = { 81,// lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo td_emlrtRTEI = { 82,// lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ud_emlrtRTEI = { 83,// lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo vd_emlrtRTEI = { 84,// lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo wd_emlrtRTEI = { 11,// lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo xd_emlrtRTEI = { 85,// lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo yd_emlrtRTEI = { 88,// lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ae_emlrtRTEI = { 1,// lineNo
  91,                                  // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo be_emlrtRTEI = { 17,// lineNo
  5,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ce_emlrtRTEI = { 22,// lineNo
  5,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo de_emlrtRTEI = { 27,// lineNo
  5,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ee_emlrtRTEI = { 32,// lineNo
  5,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo fe_emlrtRTEI = { 37,// lineNo
  5,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ge_emlrtRTEI = { 42,// lineNo
  5,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo he_emlrtRTEI = { 39,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo ie_emlrtRTEI = { 44,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo je_emlrtRTEI = { 49,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo ke_emlrtRTEI = { 103,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_single",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_single.m"// pName 
};

static emlrtRTEInfo le_emlrtRTEI = { 40,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pName 
};

static emlrtRTEInfo me_emlrtRTEI = { 45,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pName 
};

static emlrtRTEInfo ne_emlrtRTEI = { 50,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pName 
};

static emlrtRTEInfo oe_emlrtRTEI = { 102,// lineNo
  5,                                   // colNo
  "standardTF_stanlay_paraPoints",     // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay/standardTF_stanlay_paraPoints.m"// pName 
};

static emlrtRTEInfo pe_emlrtRTEI = { 86,// lineNo
  1,                                   // colNo
  "standardTF_stanLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"// pName 
};

// Function Definitions
void c_standardTF_stanLay_reflectivi(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_15 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, coder::array<cell_wrap_7, 1U> &reflectivity, coder::array<
  cell_wrap_7, 1U> &Simulation, coder::array<cell_wrap_1, 1U> &shifted_data,
  coder::array<cell_wrap_1, 1U> &layerSlds, coder::array<cell_wrap_12, 1U>
  &sldProfiles, coder::array<cell_wrap_11, 1U> &allLayers)
{
  int32_T i;
  int32_T loop_ub;
  int32_T i1;
  coder::array<real_T, 1U> chis;
  int32_T b_i;
  int32_T kstr;
  boolean_T b_bool;
  int32_T exitg1;
  static const char_T cv[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  static const char_T cv1[6] = { 'p', 'o', 'i', 'n', 't', 's' };

  static const char_T cv2[9] = { 'c', 'o', 'n', 't', 'r', 'a', 's', 't', 's' };

  coder::array<real_T, 1U> backgs;
  static const char_T cv3[3] = { 'a', 'l', 'l' };

  coder::array<cell_wrap_19, 2U> outParameterisedLayers;
  coder::array<real_T, 1U> qshifts;
  coder::array<real_T, 1U> sfs;
  coder::array<real_T, 1U> nbas;
  coder::array<real_T, 1U> nbss;
  coder::array<real_T, 1U> resols;
  coder::array<real_T, 1U> allRoughs;
  real_T thisBackground;
  real_T thisQshift;
  real_T thisSf;
  real_T thisNba;
  real_T thisNbs;
  real_T thisResol;
  coder::array<real_T, 2U> thisContrastLayers;
  coder::array<real_T, 2U> sldProfile;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  // Pre-allocation
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(muDoubleScalarFloor(problemDef->numberOfContrasts));
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI, sp);
  }

  loop_ub = static_cast<int32_T>(problemDef->numberOfContrasts);
  problem->ssubs.set_size((&qd_emlrtRTEI), sp, loop_ub);
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI, sp);
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->ssubs[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &l_emlrtDCI, sp);
  }

  problem->backgrounds.set_size((&rd_emlrtRTEI), sp, loop_ub);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &l_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->backgrounds[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &m_emlrtDCI, sp);
  }

  problem->qshifts.set_size((&sd_emlrtRTEI), sp, loop_ub);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &m_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->qshifts[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI, sp);
  }

  problem->scalefactors.set_size((&td_emlrtRTEI), sp, loop_ub);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->scalefactors[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI, sp);
  }

  problem->nbairs.set_size((&ud_emlrtRTEI), sp, loop_ub);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbairs[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &p_emlrtDCI, sp);
  }

  problem->nbsubs.set_size((&vd_emlrtRTEI), sp, loop_ub);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &p_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->nbsubs[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &q_emlrtDCI, sp);
  }

  chis.set_size((&wd_emlrtRTEI), sp, loop_ub);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &q_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    chis[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &r_emlrtDCI, sp);
  }

  problem->resolutions.set_size((&xd_emlrtRTEI), sp, loop_ub);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &r_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->resolutions[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &s_emlrtDCI, sp);
  }

  problem->allSubRough.set_size((&yd_emlrtRTEI), sp, loop_ub);
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &s_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    problem->allSubRough[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &g_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &s_emlrtRTEI, sp);
  reflectivity.set_size((&ae_emlrtRTEI), sp, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = reflectivity.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ob_emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&be_emlrtRTEI), sp, 2, reflectivity[b_i].
      f1.size(1));
    i1 = reflectivity.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ob_emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&be_emlrtRTEI), sp, reflectivity[b_i].f1.size
      (0), 2);
    i1 = reflectivity.size(0) - 1;
    kstr = reflectivity.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &ob_emlrtBCI, sp);
    }

    kstr = reflectivity.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &ob_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ob_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ob_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ob_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ob_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &t_emlrtRTEI, sp);
  Simulation.set_size((&ae_emlrtRTEI), sp, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = Simulation.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pb_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&ce_emlrtRTEI), sp, 2, Simulation[b_i].f1.size
      (1));
    i1 = Simulation.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pb_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&ce_emlrtRTEI), sp, Simulation[b_i].f1.size(0),
      2);
    i1 = Simulation.size(0) - 1;
    kstr = Simulation.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &pb_emlrtBCI, sp);
    }

    kstr = Simulation.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &pb_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pb_emlrtBCI, sp);
    }

    Simulation[b_i].f1[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pb_emlrtBCI, sp);
    }

    Simulation[b_i].f1[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pb_emlrtBCI, sp);
    }

    Simulation[b_i].f1[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &pb_emlrtBCI, sp);
    }

    Simulation[b_i].f1[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &u_emlrtRTEI, sp);
  shifted_data.set_size((&ae_emlrtRTEI), sp, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = shifted_data.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qb_emlrtBCI, sp);
    }

    shifted_data[b_i].f1.set_size((&de_emlrtRTEI), sp, 2, shifted_data[b_i].
      f1.size(1));
    i1 = shifted_data.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qb_emlrtBCI, sp);
    }

    shifted_data[b_i].f1.set_size((&de_emlrtRTEI), sp, shifted_data[b_i].f1.size
      (0), 3);
    i1 = shifted_data.size(0) - 1;
    kstr = shifted_data.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &qb_emlrtBCI, sp);
    }

    kstr = shifted_data.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &qb_emlrtBCI, sp);
    }

    for (kstr = 0; kstr < 6; kstr++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &qb_emlrtBCI, sp);
      }

      shifted_data[b_i].f1[kstr] = 1.0;
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &v_emlrtRTEI, sp);
  layerSlds.set_size((&ae_emlrtRTEI), sp, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = layerSlds.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rb_emlrtBCI, sp);
    }

    layerSlds[b_i].f1.set_size((&ee_emlrtRTEI), sp, 2, layerSlds[b_i].f1.size(1));
    i1 = layerSlds.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rb_emlrtBCI, sp);
    }

    layerSlds[b_i].f1.set_size((&ee_emlrtRTEI), sp, layerSlds[b_i].f1.size(0), 3);
    i1 = layerSlds.size(0) - 1;
    kstr = layerSlds.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &rb_emlrtBCI, sp);
    }

    kstr = layerSlds.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &rb_emlrtBCI, sp);
    }

    for (kstr = 0; kstr < 6; kstr++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &rb_emlrtBCI, sp);
      }

      layerSlds[b_i].f1[kstr] = 1.0;
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &w_emlrtRTEI, sp);
  sldProfiles.set_size((&ae_emlrtRTEI), sp, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = sldProfiles.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sb_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1.set_size((&fe_emlrtRTEI), sp, 2, sldProfiles[b_i].
      f1.size(1));
    i1 = sldProfiles.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sb_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1.set_size((&fe_emlrtRTEI), sp, sldProfiles[b_i].f1.size(0),
      2);
    i1 = sldProfiles.size(0) - 1;
    kstr = sldProfiles.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &sb_emlrtBCI, sp);
    }

    kstr = sldProfiles.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &sb_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sb_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sb_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sb_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &sb_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[3] = 1.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &x_emlrtRTEI, sp);
  allLayers.set_size((&ae_emlrtRTEI), sp, loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    i1 = allLayers.size(0) - 1;
    kstr = allLayers.size(0) - 1;
    if (b_i > kstr) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, kstr, &tb_emlrtBCI, sp);
    }

    allLayers[b_i].f1.set_size((&ge_emlrtRTEI), sp, 2);
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tb_emlrtBCI, sp);
    }

    allLayers[b_i].f1[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &tb_emlrtBCI, sp);
    }

    allLayers[b_i].f1[1] = 1.0;
  }

  b_bool = false;
  if (controls->para.size(1) == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (controls->para[kstr] != cv[kstr]) {
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
    if (controls->para.size(1) == 6) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 6) {
          if (controls->para[kstr] != cv1[kstr]) {
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
      b_bool = false;
      if (controls->para.size(1) == 9) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 9) {
            if (controls->para[kstr] != cv2[kstr]) {
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
        kstr = 2;
      } else {
        b_bool = false;
        if (controls->para.size(1) == 3) {
          kstr = 0;
          do {
            exitg1 = 0;
            if (kstr < 3) {
              if (controls->para[kstr] != cv3[kstr]) {
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
          kstr = 3;
        } else {
          kstr = -1;
        }
      }
    }
  }

  switch (kstr) {
   case 0:
    st.site = &c_emlrtRSI;

    //  Extract individual cell arrays
    //  Extract individual parameters from problemDef
    // Extract individual parameters from problemDef
    //  Allocate the memory for the output arrays before the main loop
    if (!(problemDef->numberOfContrasts >= 0.0)) {
      emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &u_emlrtDCI,
        &st);
    }

    if (problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &t_emlrtDCI, &st);
    }

    backgs.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    if (problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI, &st);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
      &y_emlrtRTEI, &st);
    reflectivity.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = reflectivity.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ub_emlrtBCI, &st);
      }

      reflectivity[b_i].f1.set_size((&he_emlrtRTEI), (&st), 2, reflectivity[b_i]
        .f1.size(1));
      i = reflectivity.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ub_emlrtBCI, &st);
      }

      reflectivity[b_i].f1.set_size((&he_emlrtRTEI), (&st), reflectivity[b_i].
        f1.size(0), 2);
      i = reflectivity.size(0) - 1;
      i1 = reflectivity.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ub_emlrtBCI, &st);
      }

      i1 = reflectivity.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ub_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ub_emlrtBCI, &st);
      }

      reflectivity[b_i].f1[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ub_emlrtBCI, &st);
      }

      reflectivity[b_i].f1[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ub_emlrtBCI, &st);
      }

      reflectivity[b_i].f1[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ub_emlrtBCI, &st);
      }

      reflectivity[b_i].f1[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
      &ab_emlrtRTEI, &st);
    Simulation.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = Simulation.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wb_emlrtBCI, &st);
      }

      Simulation[b_i].f1.set_size((&ie_emlrtRTEI), (&st), 2, Simulation[b_i].
        f1.size(1));
      i = Simulation.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wb_emlrtBCI, &st);
      }

      Simulation[b_i].f1.set_size((&ie_emlrtRTEI), (&st), Simulation[b_i].
        f1.size(0), 2);
      i = Simulation.size(0) - 1;
      i1 = Simulation.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wb_emlrtBCI, &st);
      }

      i1 = Simulation.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &wb_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wb_emlrtBCI, &st);
      }

      Simulation[b_i].f1[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wb_emlrtBCI, &st);
      }

      Simulation[b_i].f1[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wb_emlrtBCI, &st);
      }

      Simulation[b_i].f1[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wb_emlrtBCI, &st);
      }

      Simulation[b_i].f1[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
      &bb_emlrtRTEI, &st);
    allLayers.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = allLayers.size(0) - 1;
      i1 = allLayers.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &yb_emlrtBCI, &st);
      }

      allLayers[b_i].f1.set_size((&je_emlrtRTEI), (&st), 2);
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yb_emlrtBCI, &st);
      }

      allLayers[b_i].f1[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yb_emlrtBCI, &st);
      }

      allLayers[b_i].f1[1] = 1.0;
    }

    //  end memory allocation.
    //  First we need to allocate the absolute values of the input
    //  parameters to all the layers in the layers list. This only needs
    //  to be done once, and so is done outside the contrasts loop
    b_st.site = &h_emlrtRSI;
    allocateParamsToLayers(&b_st, problemDef->params, problemDef_cells->f6,
      outParameterisedLayers);

    //  Loop over all the contrasts
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
      &cb_emlrtRTEI, &st);
    problem->ssubs.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    sldProfiles.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    reflectivity.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    Simulation.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    shifted_data.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    layerSlds.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    chis.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    qshifts.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    sfs.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    nbas.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    nbss.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    resols.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    allRoughs.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      i = static_cast<int32_T>(b_i + 1U);
      if ((i < 1) || (i > problemDef->contrastBacks.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacks.size(1),
          &bc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastShifts.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastShifts.size(1),
          &cc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastScales.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastScales.size(1),
          &dc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastNbas.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbas.size(1),
          &ec_emlrtBCI, &st);
      }

      if (i > problemDef->contrastNbss.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbss.size(1),
          &fc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastRes.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastRes.size(1),
          &gc_emlrtBCI, &st);
      }

      b_st.site = &i_emlrtRSI;
      backSort(&b_st, problemDef->contrastBacks[i - 1],
               problemDef->contrastShifts[i - 1], problemDef->contrastScales[i -
               1], problemDef->contrastNbas[i - 1], problemDef->contrastNbss[i -
               1], problemDef->contrastRes[i - 1], problemDef->backs,
               problemDef->shifts, problemDef->sf, problemDef->nba,
               problemDef->nbs, problemDef->res, &thisBackground, &thisQshift,
               &thisSf, &thisNba, &thisNbs, &thisResol);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry
      i = problemDef_cells->f5.size(1) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nc_emlrtBCI, &st);
      }

      b_st.site = &j_emlrtRSI;
      allocateLayersForContrast(&b_st, problemDef_cells->f5[b_i].f1,
        outParameterisedLayers, thisContrastLayers);

      //  For the other parameters, we extract the correct ones from the input
      //  arrays
      if (1 > problemDef->params.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params.size(1),
          &x_emlrtBCI, &st);
      }

      //  Substrate roughness is always first parameter for standard layers
      i = problemDef_cells->f1.size(1) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, &st);
      }

      i = b_i + 1;
      if ((i < 1) || (i > problemDef->resample.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample.size(1),
          &y_emlrtBCI, &st);
      }

      i = problemDef_cells->f2.size(1) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &db_emlrtBCI, &st);
      }

      i = b_i + 1;
      if ((i < 1) || (i > problemDef->dataPresent.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->dataPresent.size(1),
          &ab_emlrtBCI, &st);
      }

      i = problemDef_cells->f3.size(1) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &eb_emlrtBCI, &st);
      }

      i = problemDef_cells->f4.size(1) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &fb_emlrtBCI, &st);
      }

      i = b_i + 1;
      if ((i < 1) || (i > problemDef->contrastBacksType.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacksType.size(1),
          &bb_emlrtBCI, &st);
      }

      //  Now call the core standardTF_stanlay reflectivity calculation
      //  In this case we are single cored, so we do not parallelise over
      //  points
      //  Call the calculation
      i = reflectivity.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &pc_emlrtBCI, &st);
      }

      i = Simulation.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &qc_emlrtBCI, &st);
      }

      i = shifted_data.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &rc_emlrtBCI, &st);
      }

      i = layerSlds.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &sc_emlrtBCI, &st);
      }

      i = b_i + 1;
      if ((i < 1) || (i > chis.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, chis.size(0), &tc_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > problem->ssubs.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, problem->ssubs.size(0),
          &uc_emlrtBCI, &st);
      }

      b_st.site = &k_emlrtRSI;
      standardTF_layers_core(&b_st, thisContrastLayers, problemDef->params[0],
        problemDef->geometry, thisNba, thisNbs, problemDef->resample[b_i],
        controls->calcSld, thisSf, thisQshift, problemDef->dataPresent[b_i],
        problemDef_cells->f2[b_i].f1, problemDef_cells->f3[b_i].f1,
        problemDef_cells->f4[b_i].f1, problemDef_cells->f1[b_i].f1,
        thisBackground, thisResol, problemDef->contrastBacksType[b_i],
        static_cast<real_T>(problemDef->params.size(1)), sldProfile,
        reflectivity[b_i].f1, Simulation[b_i].f1, shifted_data[b_i].f1,
        layerSlds[b_i].f1, &chis[i - 1], &problem->ssubs[i1 - 1]);

      //  Store returned values for this contrast in the output arrays.
      //  As well as the calculated profiles, we also store a record of
      //  the other values (background, scalefactors etc) for each contrast
      //  for future use.
      kstr = sldProfile.size(0) * sldProfile.size(1);
      i = sldProfiles.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cd_emlrtBCI, &st);
      }

      sldProfiles[b_i].f1.set_size((&ke_emlrtRTEI), (&st), sldProfile.size(0),
        sldProfiles[b_i].f1.size(1));
      i = sldProfiles.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cd_emlrtBCI, &st);
      }

      sldProfiles[b_i].f1.set_size((&ke_emlrtRTEI), (&st), sldProfiles[b_i].
        f1.size(0), sldProfile.size(1));
      i = sldProfiles.size(0) - 1;
      i1 = sldProfiles.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cd_emlrtBCI, &st);
      }

      i1 = sldProfiles.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cd_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cd_emlrtBCI, &st);
        }

        sldProfiles[b_i].f1[i1] = sldProfile[i1];
      }

      i = b_i + 1;
      if ((i < 1) || (i > backgs.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs.size(0), &ed_emlrtBCI, &st);
      }

      backgs[i - 1] = thisBackground;
      i = b_i + 1;
      if ((i < 1) || (i > qshifts.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, qshifts.size(0), &gd_emlrtBCI, &st);
      }

      qshifts[i - 1] = thisQshift;
      i = b_i + 1;
      if ((i < 1) || (i > sfs.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, sfs.size(0), &id_emlrtBCI, &st);
      }

      sfs[i - 1] = thisSf;
      i = b_i + 1;
      if ((i < 1) || (i > nbas.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas.size(0), &kd_emlrtBCI, &st);
      }

      nbas[i - 1] = thisNba;
      i = b_i + 1;
      if ((i < 1) || (i > nbss.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbss.size(0), &md_emlrtBCI, &st);
      }

      nbss[i - 1] = thisNbs;
      i = b_i + 1;
      if ((i < 1) || (i > resols.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, resols.size(0), &od_emlrtBCI, &st);
      }

      resols[i - 1] = thisResol;
      i = b_i + 1;
      if ((i < 1) || (i > allRoughs.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs.size(0), &qd_emlrtBCI, &st);
      }

      allRoughs[i - 1] = problemDef->params[0];
    }

    //  Debug plotting
    //  figure(1);clf; hold on
    //  for i = 1:length(sldProfiles)
    //      thisProfile = sldProfiles{i};
    //      plot(thisProfile(:,1),thisProfile(:,2))
    //      drawnow
    //  end
    problem->backgrounds.set_size((&yd_emlrtRTEI), sp, backgs.size(0));
    loop_ub = backgs.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds[i] = backgs[i];
    }

    problem->qshifts.set_size((&yd_emlrtRTEI), sp, qshifts.size(0));
    loop_ub = qshifts.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->qshifts[i] = qshifts[i];
    }

    problem->scalefactors.set_size((&yd_emlrtRTEI), sp, sfs.size(0));
    loop_ub = sfs.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->scalefactors[i] = sfs[i];
    }

    problem->nbairs.set_size((&yd_emlrtRTEI), sp, nbas.size(0));
    loop_ub = nbas.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->nbairs[i] = nbas[i];
    }

    problem->nbsubs.set_size((&yd_emlrtRTEI), sp, nbss.size(0));
    loop_ub = nbss.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->nbsubs[i] = nbss[i];
    }

    problem->resolutions.set_size((&yd_emlrtRTEI), sp, resols.size(0));
    loop_ub = resols.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->resolutions[i] = resols[i];
    }

    problem->allSubRough.set_size((&yd_emlrtRTEI), sp, allRoughs.size(0));
    loop_ub = allRoughs.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->allSubRough[i] = allRoughs[i];
    }
    break;

   case 1:
    st.site = &d_emlrtRSI;

    //  Extract individual cell arrays
    //  Extract individual parameters from problemDef
    // Extract individual parameters from problemDef
    //  Allocate the memory for the output arrays before the main loop
    //    --- Begin memory allocation ---
    if (!(problemDef->numberOfContrasts >= 0.0)) {
      emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &w_emlrtDCI,
        &st);
    }

    if (problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &v_emlrtDCI, &st);
    }

    backgs.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    if (problemDef->numberOfContrasts != i) {
      emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &i_emlrtDCI, &st);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
      &db_emlrtRTEI, &st);
    reflectivity.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = reflectivity.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vb_emlrtBCI, &st);
      }

      reflectivity[b_i].f1.set_size((&le_emlrtRTEI), (&st), 2, reflectivity[b_i]
        .f1.size(1));
      i = reflectivity.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vb_emlrtBCI, &st);
      }

      reflectivity[b_i].f1.set_size((&le_emlrtRTEI), (&st), reflectivity[b_i].
        f1.size(0), 2);
      i = reflectivity.size(0) - 1;
      i1 = reflectivity.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vb_emlrtBCI, &st);
      }

      i1 = reflectivity.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &vb_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vb_emlrtBCI, &st);
      }

      reflectivity[b_i].f1[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vb_emlrtBCI, &st);
      }

      reflectivity[b_i].f1[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vb_emlrtBCI, &st);
      }

      reflectivity[b_i].f1[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vb_emlrtBCI, &st);
      }

      reflectivity[b_i].f1[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
      &eb_emlrtRTEI, &st);
    Simulation.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = Simulation.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xb_emlrtBCI, &st);
      }

      Simulation[b_i].f1.set_size((&me_emlrtRTEI), (&st), 2, Simulation[b_i].
        f1.size(1));
      i = Simulation.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xb_emlrtBCI, &st);
      }

      Simulation[b_i].f1.set_size((&me_emlrtRTEI), (&st), Simulation[b_i].
        f1.size(0), 2);
      i = Simulation.size(0) - 1;
      i1 = Simulation.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xb_emlrtBCI, &st);
      }

      i1 = Simulation.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &xb_emlrtBCI, &st);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xb_emlrtBCI, &st);
      }

      Simulation[b_i].f1[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xb_emlrtBCI, &st);
      }

      Simulation[b_i].f1[1] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xb_emlrtBCI, &st);
      }

      Simulation[b_i].f1[2] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xb_emlrtBCI, &st);
      }

      Simulation[b_i].f1[3] = 1.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
      &fb_emlrtRTEI, &st);
    allLayers.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      i = allLayers.size(0) - 1;
      i1 = allLayers.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ac_emlrtBCI, &st);
      }

      allLayers[b_i].f1.set_size((&ne_emlrtRTEI), (&st), 2);
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ac_emlrtBCI, &st);
      }

      allLayers[b_i].f1[0] = 1.0;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ac_emlrtBCI, &st);
      }

      allLayers[b_i].f1[1] = 1.0;
    }

    //  ---end memory allocation---
    //  First we need to allocate the absolute values of the input
    //  parameters to all the layers in the layers list. This only needs
    //  to be done once, and so is done outside the contrasts loop
    b_st.site = &cg_emlrtRSI;
    allocateParamsToLayers(&b_st, problemDef->params, problemDef_cells->f6,
      outParameterisedLayers);

    //  Single Loop over all the contrasts
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
      mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
      &gb_emlrtRTEI, &st);
    problem->ssubs.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    sldProfiles.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    reflectivity.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    Simulation.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    shifted_data.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    layerSlds.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    chis.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    qshifts.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    sfs.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    nbas.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    nbss.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    resols.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    allRoughs.set_size((&yd_emlrtRTEI), (&st), loop_ub);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      i = static_cast<int32_T>(b_i + 1U);
      if ((i < 1) || (i > problemDef->contrastBacks.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacks.size(1),
          &hc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastShifts.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastShifts.size(1),
          &ic_emlrtBCI, &st);
      }

      if (i > problemDef->contrastScales.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastScales.size(1),
          &jc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastNbas.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbas.size(1),
          &kc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastNbss.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastNbss.size(1),
          &lc_emlrtBCI, &st);
      }

      if (i > problemDef->contrastRes.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastRes.size(1),
          &mc_emlrtBCI, &st);
      }

      b_st.site = &dg_emlrtRSI;
      backSort(&b_st, problemDef->contrastBacks[i - 1],
               problemDef->contrastShifts[i - 1], problemDef->contrastScales[i -
               1], problemDef->contrastNbas[i - 1], problemDef->contrastNbss[i -
               1], problemDef->contrastRes[i - 1], problemDef->backs,
               problemDef->shifts, problemDef->sf, problemDef->nba,
               problemDef->nbs, problemDef->res, &thisBackground, &thisQshift,
               &thisSf, &thisNba, &thisNbs, &thisResol);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry
      i = problemDef_cells->f5.size(1) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &oc_emlrtBCI, &st);
      }

      b_st.site = &eg_emlrtRSI;
      allocateLayersForContrast(&b_st, problemDef_cells->f5[b_i].f1,
        outParameterisedLayers, thisContrastLayers);

      //  For the other parameters, we extract the correct ones from the input
      //  arrays
      if (1 > problemDef->params.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, problemDef->params.size(1),
          &gb_emlrtBCI, &st);
      }

      //  Substrate roughness is always first parameter for standard layers
      i = problemDef_cells->f1.size(1) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &kb_emlrtBCI, &st);
      }

      i = b_i + 1;
      if ((i < 1) || (i > problemDef->resample.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->resample.size(1),
          &hb_emlrtBCI, &st);
      }

      i = problemDef_cells->f2.size(1) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &lb_emlrtBCI, &st);
      }

      i = b_i + 1;
      if ((i < 1) || (i > problemDef->dataPresent.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->dataPresent.size(1),
          &ib_emlrtBCI, &st);
      }

      i = problemDef_cells->f3.size(1) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &mb_emlrtBCI, &st);
      }

      i = problemDef_cells->f4.size(1) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &nb_emlrtBCI, &st);
      }

      i = b_i + 1;
      if ((i < 1) || (i > problemDef->contrastBacksType.size(1))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, problemDef->contrastBacksType.size(1),
          &jb_emlrtBCI, &st);
      }

      //  Now call the core standardTF_stanlay reflectivity calculation
      //  In this case we parallelise over points.
      //  Call the calculation
      i = reflectivity.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &vc_emlrtBCI, &st);
      }

      i = Simulation.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &wc_emlrtBCI, &st);
      }

      i = shifted_data.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &xc_emlrtBCI, &st);
      }

      i = layerSlds.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &yc_emlrtBCI, &st);
      }

      i = b_i + 1;
      if ((i < 1) || (i > chis.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, chis.size(0), &ad_emlrtBCI, &st);
      }

      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > problem->ssubs.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, problem->ssubs.size(0),
          &bd_emlrtBCI, &st);
      }

      b_st.site = &fg_emlrtRSI;
      b_standardTF_layers_core(&b_st, thisContrastLayers, problemDef->params[0],
        problemDef->geometry, thisNba, thisNbs, problemDef->resample[b_i],
        controls->calcSld, thisSf, thisQshift, problemDef->dataPresent[b_i],
        problemDef_cells->f2[b_i].f1, problemDef_cells->f3[b_i].f1,
        problemDef_cells->f4[b_i].f1, problemDef_cells->f1[b_i].f1,
        thisBackground, thisResol, problemDef->contrastBacksType[b_i],
        static_cast<real_T>(problemDef->params.size(1)), sldProfile,
        reflectivity[b_i].f1, Simulation[b_i].f1, shifted_data[b_i].f1,
        layerSlds[b_i].f1, &chis[i - 1], &problem->ssubs[i1 - 1]);

      //  Store returned values for this contrast in the output arrays.
      //  As well as the calculated profiles, we also store a record of
      //  the other values (background, scalefactors etc) for each contrast
      //  for future use.
      kstr = sldProfile.size(0) * sldProfile.size(1);
      i = sldProfiles.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dd_emlrtBCI, &st);
      }

      sldProfiles[b_i].f1.set_size((&oe_emlrtRTEI), (&st), sldProfile.size(0),
        sldProfiles[b_i].f1.size(1));
      i = sldProfiles.size(0) - 1;
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dd_emlrtBCI, &st);
      }

      sldProfiles[b_i].f1.set_size((&oe_emlrtRTEI), (&st), sldProfiles[b_i].
        f1.size(0), sldProfile.size(1));
      i = sldProfiles.size(0) - 1;
      i1 = sldProfiles.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dd_emlrtBCI, &st);
      }

      i1 = sldProfiles.size(0) - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &dd_emlrtBCI, &st);
      }

      for (i1 = 0; i1 < kstr; i1++) {
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &dd_emlrtBCI, &st);
        }

        sldProfiles[b_i].f1[i1] = sldProfile[i1];
      }

      i = b_i + 1;
      if ((i < 1) || (i > backgs.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, backgs.size(0), &fd_emlrtBCI, &st);
      }

      backgs[i - 1] = thisBackground;
      i = b_i + 1;
      if ((i < 1) || (i > qshifts.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, qshifts.size(0), &hd_emlrtBCI, &st);
      }

      qshifts[i - 1] = thisQshift;
      i = b_i + 1;
      if ((i < 1) || (i > sfs.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, sfs.size(0), &jd_emlrtBCI, &st);
      }

      sfs[i - 1] = thisSf;
      i = b_i + 1;
      if ((i < 1) || (i > nbas.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbas.size(0), &ld_emlrtBCI, &st);
      }

      nbas[i - 1] = thisNba;
      i = b_i + 1;
      if ((i < 1) || (i > nbss.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, nbss.size(0), &nd_emlrtBCI, &st);
      }

      nbss[i - 1] = thisNbs;
      i = b_i + 1;
      if ((i < 1) || (i > resols.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, resols.size(0), &pd_emlrtBCI, &st);
      }

      resols[i - 1] = thisResol;
      i = b_i + 1;
      if ((i < 1) || (i > allRoughs.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, allRoughs.size(0), &rd_emlrtBCI, &st);
      }

      allRoughs[i - 1] = problemDef->params[0];
    }

    problem->backgrounds.set_size((&yd_emlrtRTEI), sp, backgs.size(0));
    loop_ub = backgs.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->backgrounds[i] = backgs[i];
    }

    problem->qshifts.set_size((&yd_emlrtRTEI), sp, qshifts.size(0));
    loop_ub = qshifts.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->qshifts[i] = qshifts[i];
    }

    problem->scalefactors.set_size((&yd_emlrtRTEI), sp, sfs.size(0));
    loop_ub = sfs.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->scalefactors[i] = sfs[i];
    }

    problem->nbairs.set_size((&yd_emlrtRTEI), sp, nbas.size(0));
    loop_ub = nbas.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->nbairs[i] = nbas[i];
    }

    problem->nbsubs.set_size((&yd_emlrtRTEI), sp, nbss.size(0));
    loop_ub = nbss.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->nbsubs[i] = nbss[i];
    }

    problem->resolutions.set_size((&yd_emlrtRTEI), sp, resols.size(0));
    loop_ub = resols.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->resolutions[i] = resols[i];
    }

    problem->allSubRough.set_size((&yd_emlrtRTEI), sp, allRoughs.size(0));
    loop_ub = allRoughs.size(0);
    for (i = 0; i < loop_ub; i++) {
      problem->allSubRough[i] = allRoughs[i];
    }
    break;

   case 2:
    st.site = &e_emlrtRSI;
    c_standardTF_stanlay_paraContra(&st, problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, reflectivity, Simulation, shifted_data,
      layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;

   case 3:
    st.site = &f_emlrtRSI;
    standardTF_stanlay_paraAll(&st, problemDef, problemDef_cells, controls,
      problem->ssubs, problem->backgrounds, problem->qshifts,
      problem->scalefactors, problem->nbairs, problem->nbsubs,
      problem->resolutions, chis, reflectivity, Simulation, shifted_data,
      layerSlds, sldProfiles, allLayers, problem->allSubRough);
    break;
  }

  problem->calculations.all_chis.set_size((&pe_emlrtRTEI), sp, chis.size(0));
  loop_ub = chis.size(0);
  for (i = 0; i < loop_ub; i++) {
    problem->calculations.all_chis[i] = chis[i];
  }

  st.site = &g_emlrtRSI;
  problem->calculations.sum_chi = sum(&st, chis);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (standardTF_stanLay_reflectivityCalculation.cpp)
