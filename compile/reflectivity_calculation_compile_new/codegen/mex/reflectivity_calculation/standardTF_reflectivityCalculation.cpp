//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  standardTF_reflectivityCalculation.cpp
//
//  Code generation for function 'standardTF_reflectivityCalculation'
//


// Include files
#include "standardTF_reflectivityCalculation.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_mexutil.h"
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "standardTF_stanLay_reflectivityCalculation.h"
#include "strcmp.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo b_emlrtRSI = { 51,  // lineNo
  "standardTF_reflectivityCalculation",// fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pathName 
};

static emlrtRSInfo c_emlrtRSI = { 55,  // lineNo
  "standardTF_reflectivityCalculation",// fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pathName 
};

static emlrtRSInfo vg_emlrtRSI = { 54, // lineNo
  "standardTF_custLay_reflectivityCalculation",// fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pathName 
};

static emlrtRSInfo wg_emlrtRSI = { 87, // lineNo
  "standardTF_custLay_reflectivityCalculation",// fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pathName 
};

static emlrtDCInfo d_emlrtDCI = { 6,   // lineNo
  18,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo e_emlrtDCI = { 6,   // lineNo
  18,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo f_emlrtDCI = { 19,  // lineNo
  21,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtRTEInfo m_emlrtRTEI = { 20,// lineNo
  9,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo n_emlrtRTEI = { 25,// lineNo
  9,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo o_emlrtRTEI = { 30,// lineNo
  9,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo p_emlrtRTEI = { 35,// lineNo
  9,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo q_emlrtRTEI = { 40,// lineNo
  9,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo r_emlrtRTEI = { 45,// lineNo
  9,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtDCInfo g_emlrtDCI = { 19,  // lineNo
  21,                                  // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtRTEInfo s_emlrtRTEI = { 20,// lineNo
  9,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo t_emlrtRTEI = { 25,// lineNo
  9,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo u_emlrtRTEI = { 30,// lineNo
  9,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo v_emlrtRTEI = { 35,// lineNo
  9,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo w_emlrtRTEI = { 40,// lineNo
  9,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo x_emlrtRTEI = { 45,// lineNo
  9,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtBCInfo r_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  21,                                  // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo s_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  26,                                  // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo t_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  31,                                  // lineNo
  5,                                   // colNo
  "shifted_data",                      // aName
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo u_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  5,                                   // colNo
  "layerSlds",                         // aName
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo v_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  41,                                  // lineNo
  5,                                   // colNo
  "sldProfiles",                       // aName
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo w_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  46,                                  // lineNo
  5,                                   // colNo
  "allLayers",                         // aName
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo h_emlrtDCI = { 79,  // lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo i_emlrtDCI = { 79,  // lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo j_emlrtDCI = { 80,  // lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo k_emlrtDCI = { 81,  // lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo l_emlrtDCI = { 82,  // lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo m_emlrtDCI = { 83,  // lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo n_emlrtDCI = { 84,  // lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo o_emlrtDCI = { 15,  // lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo p_emlrtDCI = { 85,  // lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo q_emlrtDCI = { 88,  // lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo x_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  21,                                  // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo y_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  26,                                  // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ab_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  31,                                  // lineNo
  5,                                   // colNo
  "shifted_data",                      // aName
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  5,                                   // colNo
  "layerSlds",                         // aName
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo cb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  41,                                  // lineNo
  5,                                   // colNo
  "sldProfiles",                       // aName
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo db_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  46,                                  // lineNo
  5,                                   // colNo
  "allLayers",                         // aName
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo be_emlrtRTEI = { 9,// lineNo
  26,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ce_emlrtRTEI = { 10,// lineNo
  32,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo de_emlrtRTEI = { 11,// lineNo
  28,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ee_emlrtRTEI = { 12,// lineNo
  33,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo fe_emlrtRTEI = { 13,// lineNo
  27,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ge_emlrtRTEI = { 14,// lineNo
  27,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo he_emlrtRTEI = { 15,// lineNo
  32,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ie_emlrtRTEI = { 16,// lineNo
  51,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo je_emlrtRTEI = { 17,// lineNo
  32,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ke_emlrtRTEI = { 1,// lineNo
  91,                                  // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo le_emlrtRTEI = { 21,// lineNo
  5,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo me_emlrtRTEI = { 26,// lineNo
  5,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ne_emlrtRTEI = { 31,// lineNo
  5,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo oe_emlrtRTEI = { 36,// lineNo
  5,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo pe_emlrtRTEI = { 41,// lineNo
  5,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo qe_emlrtRTEI = { 46,// lineNo
  5,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo re_emlrtRTEI = { 79,// lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo se_emlrtRTEI = { 80,// lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo te_emlrtRTEI = { 81,// lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ue_emlrtRTEI = { 82,// lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ve_emlrtRTEI = { 83,// lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo we_emlrtRTEI = { 84,// lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo xe_emlrtRTEI = { 15,// lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ye_emlrtRTEI = { 85,// lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo af_emlrtRTEI = { 88,// lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo bf_emlrtRTEI = { 55,// lineNo
  9,                                   // colNo
  "standardTF_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo cf_emlrtRTEI = { 21,// lineNo
  5,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo df_emlrtRTEI = { 26,// lineNo
  5,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ef_emlrtRTEI = { 31,// lineNo
  5,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo ff_emlrtRTEI = { 36,// lineNo
  5,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo gf_emlrtRTEI = { 41,// lineNo
  5,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo hf_emlrtRTEI = { 46,// lineNo
  5,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo if_emlrtRTEI = { 54,// lineNo
  62,                                  // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo jf_emlrtRTEI = { 55,// lineNo
  60,                                  // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo kf_emlrtRTEI = { 55,// lineNo
  14,                                  // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

static emlrtRTEInfo lf_emlrtRTEI = { 86,// lineNo
  1,                                   // colNo
  "standardTF_custLay_reflectivityCalculation",// fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"// pName 
};

// Function Definitions
void c_standardTF_reflectivityCalcul(const emlrtStack *sp, const struct0_T
  *problemDef, const cell_14 *problemDef_cells, const struct2_T *controls,
  struct4_T *problem, coder::array<cell_wrap_7, 1U> &reflectivity, coder::array<
  cell_wrap_7, 1U> &Simulation, coder::array<cell_wrap_1, 1U> &shifted_data,
  coder::array<cell_wrap_8, 1U> &layerSlds, coder::array<cell_wrap_1, 1U>
  &sldProfiles, coder::array<cell_wrap_1, 1U> &allLayers)
{
  int32_T i;
  int32_T loop_ub_tmp;
  int32_T i1;
  int32_T b_i;
  int32_T i2;
  boolean_T b_bool;
  int32_T exitg1;
  static const char_T cv[6] = { 'l', 'a', 'y', 'e', 'r', 's' };

  static const char_T cv1[13] = { 'c', 'u', 's', 't', 'o', 'm', ' ', 'l', 'a',
    'y', 'e', 'r', 's' };

  coder::array<real_T, 1U> chis;
  static const char_T cv2[6] = { 's', 'i', 'n', 'g', 'l', 'e' };

  coder::array<cell_wrap_10, 1U> r;
  coder::array<cell_wrap_10, 1U> r1;
  coder::array<cell_wrap_22, 1U> r2;
  coder::array<cell_wrap_7, 1U> b_reflectivity;
  coder::array<cell_wrap_7, 1U> b_Simulation;
  coder::array<cell_wrap_1, 1U> b_allLayers;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  // Decide what kind of calculation it is and call the appropriate one
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &d_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(muDoubleScalarFloor(problemDef->numberOfContrasts));
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &e_emlrtDCI, sp);
  }

  //  Pre-allocate the output arrays..
  loop_ub_tmp = static_cast<int32_T>(problemDef->numberOfContrasts);
  problem->ssubs.set_size((&be_emlrtRTEI), sp, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->ssubs[i1] = 0.0;
  }

  problem->backgrounds.set_size((&ce_emlrtRTEI), sp, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->backgrounds[i1] = 0.0;
  }

  problem->qshifts.set_size((&de_emlrtRTEI), sp, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->qshifts[i1] = 0.0;
  }

  problem->scalefactors.set_size((&ee_emlrtRTEI), sp, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->scalefactors[i1] = 0.0;
  }

  problem->nbairs.set_size((&fe_emlrtRTEI), sp, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->nbairs[i1] = 0.0;
  }

  problem->nbsubs.set_size((&ge_emlrtRTEI), sp, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->nbsubs[i1] = 0.0;
  }

  problem->resolutions.set_size((&he_emlrtRTEI), sp, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->resolutions[i1] = 0.0;
  }

  problem->calculations.all_chis.set_size((&ie_emlrtRTEI), sp, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->calculations.all_chis[i1] = 0.0;
  }

  problem->calculations.sum_chi = 0.0;
  problem->allSubRough.set_size((&je_emlrtRTEI), sp, loop_ub_tmp);
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    problem->allSubRough[i1] = 0.0;
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &f_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &m_emlrtRTEI, sp);
  reflectivity.set_size((&ke_emlrtRTEI), sp, loop_ub_tmp);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    i1 = reflectivity.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &r_emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&le_emlrtRTEI), sp, 2, reflectivity[b_i].
      f1.size(1));
    i1 = reflectivity.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &r_emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&le_emlrtRTEI), sp, reflectivity[b_i].f1.size
      (0), 2);
    i1 = reflectivity.size(0) - 1;
    i2 = reflectivity.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &r_emlrtBCI, sp);
    }

    i2 = reflectivity.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &r_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &r_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &r_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &r_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &r_emlrtBCI, sp);
    }

    reflectivity[b_i].f1[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &n_emlrtRTEI, sp);
  Simulation.set_size((&ke_emlrtRTEI), sp, loop_ub_tmp);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    i1 = Simulation.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &s_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&me_emlrtRTEI), sp, 2, Simulation[b_i].f1.size
      (1));
    i1 = Simulation.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &s_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&me_emlrtRTEI), sp, Simulation[b_i].f1.size(0),
      2);
    i1 = Simulation.size(0) - 1;
    i2 = Simulation.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &s_emlrtBCI, sp);
    }

    i2 = Simulation.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &s_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &s_emlrtBCI, sp);
    }

    Simulation[b_i].f1[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &s_emlrtBCI, sp);
    }

    Simulation[b_i].f1[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &s_emlrtBCI, sp);
    }

    Simulation[b_i].f1[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &s_emlrtBCI, sp);
    }

    Simulation[b_i].f1[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &o_emlrtRTEI, sp);
  shifted_data.set_size((&ke_emlrtRTEI), sp, loop_ub_tmp);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    i1 = shifted_data.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &t_emlrtBCI, sp);
    }

    shifted_data[b_i].f1.set_size((&ne_emlrtRTEI), sp, 2, shifted_data[b_i].
      f1.size(1));
    i1 = shifted_data.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &t_emlrtBCI, sp);
    }

    shifted_data[b_i].f1.set_size((&ne_emlrtRTEI), sp, shifted_data[b_i].f1.size
      (0), 3);
    i1 = shifted_data.size(0) - 1;
    i2 = shifted_data.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &t_emlrtBCI, sp);
    }

    i2 = shifted_data.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &t_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &t_emlrtBCI, sp);
      }

      shifted_data[b_i].f1[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &p_emlrtRTEI, sp);
  layerSlds.set_size((&ke_emlrtRTEI), sp, loop_ub_tmp);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    i1 = layerSlds.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &u_emlrtBCI, sp);
    }

    layerSlds[b_i].f1.set_size((&oe_emlrtRTEI), sp, 2, layerSlds[b_i].f1.size(1));
    i1 = layerSlds.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &u_emlrtBCI, sp);
    }

    layerSlds[b_i].f1.set_size((&oe_emlrtRTEI), sp, layerSlds[b_i].f1.size(0), 3);
    i1 = layerSlds.size(0) - 1;
    i2 = layerSlds.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &u_emlrtBCI, sp);
    }

    i2 = layerSlds.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &u_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &u_emlrtBCI, sp);
      }

      layerSlds[b_i].f1[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &q_emlrtRTEI, sp);
  sldProfiles.set_size((&ke_emlrtRTEI), sp, loop_ub_tmp);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    i1 = sldProfiles.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &v_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1.set_size((&pe_emlrtRTEI), sp, 2, sldProfiles[b_i].
      f1.size(1));
    i1 = sldProfiles.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &v_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1.set_size((&pe_emlrtRTEI), sp, sldProfiles[b_i].f1.size(0),
      2);
    i1 = sldProfiles.size(0) - 1;
    i2 = sldProfiles.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &v_emlrtBCI, sp);
    }

    i2 = sldProfiles.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &v_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &v_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &v_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[1] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &v_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[2] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &v_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &r_emlrtRTEI, sp);
  allLayers.set_size((&ke_emlrtRTEI), sp, loop_ub_tmp);
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    i1 = allLayers.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &w_emlrtBCI, sp);
    }

    allLayers[b_i].f1.set_size((&qe_emlrtRTEI), sp, 2, allLayers[b_i].f1.size(1));
    i1 = allLayers.size(0) - 1;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &w_emlrtBCI, sp);
    }

    allLayers[b_i].f1.set_size((&qe_emlrtRTEI), sp, allLayers[b_i].f1.size(0), 1);
    i1 = allLayers.size(0) - 1;
    i2 = allLayers.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &w_emlrtBCI, sp);
    }

    i2 = allLayers.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &w_emlrtBCI, sp);
    }

    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &w_emlrtBCI, sp);
    }

    allLayers[b_i].f1[0] = 1.0;
    if (b_i > i1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &w_emlrtBCI, sp);
    }

    allLayers[b_i].f1[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  b_bool = false;
  if (problemDef->modelType.size(1) == 6) {
    b_i = 0;
    do {
      exitg1 = 0;
      if (b_i < 6) {
        if (problemDef->modelType[b_i] != cv[b_i]) {
          exitg1 = 1;
        } else {
          b_i++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    b_i = 0;
  } else {
    b_bool = false;
    if (problemDef->modelType.size(1) == 13) {
      b_i = 0;
      do {
        exitg1 = 0;
        if (b_i < 13) {
          if (problemDef->modelType[b_i] != cv1[b_i]) {
            exitg1 = 1;
          } else {
            b_i++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      b_i = 1;
    } else {
      b_i = -1;
    }
  }

  switch (b_i) {
   case 0:
    st.site = &b_emlrtRSI;
    c_standardTF_stanLay_reflectivi(&st, problemDef, problemDef_cells, controls,
      problem, reflectivity, Simulation, shifted_data, layerSlds, sldProfiles,
      allLayers);
    break;

   case 1:
    {
      real_T d;
      st.site = &c_emlrtRSI;

      //  Pre-allocation - It's necessary to
      //  pre-allocate the memory for all the arrays
      //  for compilation, so do this in this block.
      if (!(problemDef->numberOfContrasts >= 0.0)) {
        emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &i_emlrtDCI,
          &st);
      }

      d = static_cast<int32_T>(muDoubleScalarFloor(problemDef->numberOfContrasts));
      if (problemDef->numberOfContrasts != d) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI, &st);
      }

      problem->ssubs.set_size((&re_emlrtRTEI), (&st), loop_ub_tmp);
      if (!(problemDef->numberOfContrasts >= 0.0)) {
        emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &i_emlrtDCI,
          &st);
      }

      if (problemDef->numberOfContrasts != d) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &h_emlrtDCI, &st);
      }

      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problem->ssubs[i1] = 0.0;
      }

      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI, &st);
      }

      problem->backgrounds.set_size((&se_emlrtRTEI), (&st), loop_ub_tmp);
      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &j_emlrtDCI, &st);
      }

      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problem->backgrounds[i1] = 0.0;
      }

      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI, &st);
      }

      problem->qshifts.set_size((&te_emlrtRTEI), (&st), loop_ub_tmp);
      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &k_emlrtDCI, &st);
      }

      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problem->qshifts[i1] = 0.0;
      }

      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &l_emlrtDCI, &st);
      }

      problem->scalefactors.set_size((&ue_emlrtRTEI), (&st), loop_ub_tmp);
      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &l_emlrtDCI, &st);
      }

      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problem->scalefactors[i1] = 0.0;
      }

      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &m_emlrtDCI, &st);
      }

      problem->nbairs.set_size((&ve_emlrtRTEI), (&st), loop_ub_tmp);
      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &m_emlrtDCI, &st);
      }

      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problem->nbairs[i1] = 0.0;
      }

      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI, &st);
      }

      problem->nbsubs.set_size((&we_emlrtRTEI), (&st), loop_ub_tmp);
      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &n_emlrtDCI, &st);
      }

      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problem->nbsubs[i1] = 0.0;
      }

      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI, &st);
      }

      chis.set_size((&xe_emlrtRTEI), (&st), loop_ub_tmp);
      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &o_emlrtDCI, &st);
      }

      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        chis[i1] = 0.0;
      }

      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &p_emlrtDCI, &st);
      }

      problem->resolutions.set_size((&ye_emlrtRTEI), (&st), loop_ub_tmp);
      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &p_emlrtDCI, &st);
      }

      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problem->resolutions[i1] = 0.0;
      }

      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &q_emlrtDCI, &st);
      }

      problem->allSubRough.set_size((&af_emlrtRTEI), (&st), loop_ub_tmp);
      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &q_emlrtDCI, &st);
      }

      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problem->allSubRough[i1] = 0.0;
      }

      if (problemDef->numberOfContrasts != i) {
        emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &g_emlrtDCI, &st);
      }

      emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
        mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
        &s_emlrtRTEI, &st);
      reflectivity.set_size((&bf_emlrtRTEI), (&st), loop_ub_tmp);
      for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
        i = reflectivity.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, &st);
        }

        reflectivity[b_i].f1.set_size((&cf_emlrtRTEI), (&st), 2,
          reflectivity[b_i].f1.size(1));
        i = reflectivity.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, &st);
        }

        reflectivity[b_i].f1.set_size((&cf_emlrtRTEI), (&st), reflectivity[b_i].
          f1.size(0), 2);
        i = reflectivity.size(0) - 1;
        i1 = reflectivity.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &x_emlrtBCI, &st);
        }

        i1 = reflectivity.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &x_emlrtBCI, &st);
        }

        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, &st);
        }

        reflectivity[b_i].f1[0] = 1.0;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, &st);
        }

        reflectivity[b_i].f1[1] = 1.0;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, &st);
        }

        reflectivity[b_i].f1[2] = 1.0;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &x_emlrtBCI, &st);
        }

        reflectivity[b_i].f1[3] = 1.0;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
        mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
        &t_emlrtRTEI, &st);
      Simulation.set_size((&bf_emlrtRTEI), (&st), loop_ub_tmp);
      for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
        i = Simulation.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, &st);
        }

        Simulation[b_i].f1.set_size((&df_emlrtRTEI), (&st), 2, Simulation[b_i].
          f1.size(1));
        i = Simulation.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, &st);
        }

        Simulation[b_i].f1.set_size((&df_emlrtRTEI), (&st), Simulation[b_i].
          f1.size(0), 2);
        i = Simulation.size(0) - 1;
        i1 = Simulation.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &y_emlrtBCI, &st);
        }

        i1 = Simulation.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &y_emlrtBCI, &st);
        }

        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, &st);
        }

        Simulation[b_i].f1[0] = 1.0;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, &st);
        }

        Simulation[b_i].f1[1] = 1.0;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, &st);
        }

        Simulation[b_i].f1[2] = 1.0;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &y_emlrtBCI, &st);
        }

        Simulation[b_i].f1[3] = 1.0;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
        mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
        &u_emlrtRTEI, &st);
      shifted_data.set_size((&bf_emlrtRTEI), (&st), loop_ub_tmp);
      for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
        i = shifted_data.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ab_emlrtBCI, &st);
        }

        shifted_data[b_i].f1.set_size((&ef_emlrtRTEI), (&st), 2,
          shifted_data[b_i].f1.size(1));
        i = shifted_data.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ab_emlrtBCI, &st);
        }

        shifted_data[b_i].f1.set_size((&ef_emlrtRTEI), (&st), shifted_data[b_i].
          f1.size(0), 3);
        i = shifted_data.size(0) - 1;
        i1 = shifted_data.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ab_emlrtBCI, &st);
        }

        i1 = shifted_data.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &ab_emlrtBCI, &st);
        }

        for (i1 = 0; i1 < 6; i1++) {
          if (b_i > i) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &ab_emlrtBCI, &st);
          }

          shifted_data[b_i].f1[i1] = 1.0;
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
        mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
        &v_emlrtRTEI, &st);
      layerSlds.set_size((&bf_emlrtRTEI), (&st), loop_ub_tmp);
      for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
        i = layerSlds.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bb_emlrtBCI, &st);
        }

        layerSlds[b_i].f1.set_size((&ff_emlrtRTEI), (&st), 2, layerSlds[b_i].
          f1.size(1));
        i = layerSlds.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bb_emlrtBCI, &st);
        }

        layerSlds[b_i].f1.set_size((&ff_emlrtRTEI), (&st), layerSlds[b_i].
          f1.size(0), 3);
        i = layerSlds.size(0) - 1;
        i1 = layerSlds.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bb_emlrtBCI, &st);
        }

        i1 = layerSlds.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bb_emlrtBCI, &st);
        }

        for (i1 = 0; i1 < 6; i1++) {
          if (b_i > i) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &bb_emlrtBCI, &st);
          }

          layerSlds[b_i].f1[i1] = 1.0;
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
        mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
        &w_emlrtRTEI, &st);
      sldProfiles.set_size((&bf_emlrtRTEI), (&st), loop_ub_tmp);
      for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
        i = sldProfiles.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, &st);
        }

        sldProfiles[b_i].f1.set_size((&gf_emlrtRTEI), (&st), 2, sldProfiles[b_i]
          .f1.size(1));
        i = sldProfiles.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, &st);
        }

        sldProfiles[b_i].f1.set_size((&gf_emlrtRTEI), (&st), sldProfiles[b_i].
          f1.size(0), 2);
        i = sldProfiles.size(0) - 1;
        i1 = sldProfiles.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cb_emlrtBCI, &st);
        }

        i1 = sldProfiles.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &cb_emlrtBCI, &st);
        }

        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, &st);
        }

        sldProfiles[b_i].f1[0] = 1.0;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, &st);
        }

        sldProfiles[b_i].f1[1] = 1.0;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, &st);
        }

        sldProfiles[b_i].f1[2] = 1.0;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &cb_emlrtBCI, &st);
        }

        sldProfiles[b_i].f1[3] = 1.0;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
        mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
        &x_emlrtRTEI, &st);
      allLayers.set_size((&bf_emlrtRTEI), (&st), loop_ub_tmp);
      for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
        i = allLayers.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &db_emlrtBCI, &st);
        }

        allLayers[b_i].f1.set_size((&hf_emlrtRTEI), (&st), 2, allLayers[b_i].
          f1.size(1));
        i = allLayers.size(0) - 1;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &db_emlrtBCI, &st);
        }

        allLayers[b_i].f1.set_size((&hf_emlrtRTEI), (&st), allLayers[b_i].
          f1.size(0), 1);
        i = allLayers.size(0) - 1;
        i1 = allLayers.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, &st);
        }

        i1 = allLayers.size(0) - 1;
        if (b_i > i1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &db_emlrtBCI, &st);
        }

        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &db_emlrtBCI, &st);
        }

        allLayers[b_i].f1[0] = 1.0;
        if (b_i > i) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &db_emlrtBCI, &st);
        }

        allLayers[b_i].f1[1] = 1.0;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      b_bool = false;
      if (controls->para.size(1) == 6) {
        b_i = 0;
        do {
          exitg1 = 0;
          if (b_i < 6) {
            if (controls->para[b_i] != cv2[b_i]) {
              exitg1 = 1;
            } else {
              b_i++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        loop_ub_tmp = 0;
      } else {
        loop_ub_tmp = -1;
      }

      switch (loop_ub_tmp) {
       case 0:
        b_st.site = &vg_emlrtRSI;
        standardTF_custlay_single(&b_st, problemDef, problemDef_cells, controls,
          problem->ssubs, problem->backgrounds, problem->qshifts,
          problem->scalefactors, problem->nbairs, problem->nbsubs,
          problem->resolutions, chis, r, r1, shifted_data, layerSlds,
          sldProfiles, r2, problem->allSubRough);
        b_reflectivity.set_size((&if_emlrtRTEI), (&st), r.size(0));
        i = r.size(0);
        for (i1 = 0; i1 < i; i1++) {
          b_reflectivity[i1].f1.set_size((&if_emlrtRTEI), (&st), r[i1].f1.size(0),
            2);
          b_i = r[i1].f1.size(0) * r[i1].f1.size(1);
          for (i2 = 0; i2 < b_i; i2++) {
            b_reflectivity[i1].f1[i2] = r[i1].f1[i2];
          }

          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        b_Simulation.set_size((&if_emlrtRTEI), (&st), r1.size(0));
        i = r1.size(0);
        for (i1 = 0; i1 < i; i1++) {
          b_Simulation[i1].f1.set_size((&if_emlrtRTEI), (&st), r1[i1].f1.size(0),
            2);
          b_i = r1[i1].f1.size(0) * r1[i1].f1.size(1);
          for (i2 = 0; i2 < b_i; i2++) {
            b_Simulation[i1].f1[i2] = r1[i1].f1[i2];
          }

          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        b_allLayers.set_size((&jf_emlrtRTEI), (&st), r2.size(0));
        i = r2.size(0);
        for (i1 = 0; i1 < i; i1++) {
          b_allLayers[i1].f1.set_size((&jf_emlrtRTEI), (&st), r2[i1].f1.size(0),
            r2[i1].f1.size(1));
          b_i = r2[i1].f1.size(0) * r2[i1].f1.size(1);
          for (i2 = 0; i2 < b_i; i2++) {
            b_allLayers[i1].f1[i2] = r2[i1].f1[i2];
          }

          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        reflectivity.set_size((&if_emlrtRTEI), (&st), b_reflectivity.size(0));
        b_i = b_reflectivity.size(0);
        for (i = 0; i < b_i; i++) {
          reflectivity[i] = b_reflectivity[i];
        }

        Simulation.set_size((&kf_emlrtRTEI), (&st), b_Simulation.size(0));
        b_i = b_Simulation.size(0);
        for (i = 0; i < b_i; i++) {
          Simulation[i] = b_Simulation[i];
        }

        allLayers.set_size((&jf_emlrtRTEI), (&st), b_allLayers.size(0));
        b_i = b_allLayers.size(0);
        for (i = 0; i < b_i; i++) {
          allLayers[i] = b_allLayers[i];
        }

        //      case 'points'
        //
        //            [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,... 
        //               Simulation,shifted_data,layerSlds,sldProfiles,allLayers,... 
        //               allRoughs] = standardTF_custlay_paraPoints(problemDef,problemDef_cells,... 
        //               problemDef_limits,controls);
        //       case 'contrasts'
        //                  [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,... 
        //              reflectivity,Simulation,shifted_data,layerSlds,...
        //              sldProfiles,allLayers,allRoughs] = ...
        //              standardTF_custlay_paraContrasts...
        //              (resample,numberOfContrasts,geometry,repeatLayers,cBacks, ... 
        //              cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs, ... 
        //              res,dataPresent,allData,dataLimits,simLimits,nParams,params, ... 
        //              contrastLayers,numberOfLayers,layersDetails,problemDef_limits, ... 
        //              fname,lang,path,backsType,calcSLD);
        break;
      }

      problem->calculations.all_chis.set_size((&lf_emlrtRTEI), (&st), chis.size
        (0));
      b_i = chis.size(0);
      for (i = 0; i < b_i; i++) {
        problem->calculations.all_chis[i] = chis[i];
      }

      b_st.site = &wg_emlrtRSI;
      problem->calculations.sum_chi = sum(&b_st, chis);

      //     case 'Custom XY'
      //         [problem,reflectivity,Simulation,...
      //             shifted_data,layerSlds,sldProfiles,...
      //             allLayers] = standardTF_custXY_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); 
    }
    break;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (standardTF_reflectivityCalculation.cpp)
