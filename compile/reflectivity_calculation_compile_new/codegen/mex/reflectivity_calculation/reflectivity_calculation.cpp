//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation.cpp
//
//  Code generation for function 'reflectivity_calculation'
//


// Include files
#include "reflectivity_calculation.h"
#include "allocateParamsToLayers.h"
#include "mwmathutil.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_mexutil.h"
#include "rt_nonfinite.h"
#include "standardTF_custlay_single.h"
#include "standardTF_reflectivityCalculation.h"
#include "standardTF_stanlay_paraAll.h"
#include "strcmp.h"

// Type Definitions
struct cell_wrap_11
{
  coder::array<real_T, 2U> f1;
};

struct cell_wrap_12
{
  coder::array<real_T, 1U> f1;
};

// Variable Definitions
static emlrtRSInfo emlrtRSI = { 59,    // lineNo
  "reflectivity_calculation",          // fcnName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pathName 
};

static emlrtDCInfo emlrtDCI = { 19,    // lineNo
  21,                                  // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo b_emlrtDCI = { 19,  // lineNo
  21,                                  // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  1                                    // checkKind
};

static emlrtRTEInfo emlrtRTEI = { 20,  // lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtDCInfo c_emlrtDCI = { 25,  // lineNo
  19,                                  // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  1                                    // checkKind
};

static emlrtRTEInfo b_emlrtRTEI = { 26,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo c_emlrtRTEI = { 32,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo d_emlrtRTEI = { 38,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo e_emlrtRTEI = { 44,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo f_emlrtRTEI = { 50,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo g_emlrtRTEI = { 72,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo h_emlrtRTEI = { 79,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo i_emlrtRTEI = { 86,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo j_emlrtRTEI = { 93,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo k_emlrtRTEI = { 100,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo l_emlrtRTEI = { 107,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtBCInfo emlrtBCI = { -1,    // iFirst
  -1,                                  // iLast
  21,                                  // lineNo
  5,                                   // colNo
  "reflectivity",                      // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo b_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  27,                                  // lineNo
  5,                                   // colNo
  "Simulation",                        // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo c_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  33,                                  // lineNo
  5,                                   // colNo
  "shifted_data",                      // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  39,                                  // lineNo
  5,                                   // colNo
  "layerSlds",                         // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  45,                                  // lineNo
  5,                                   // colNo
  "sldProfiles",                       // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo f_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  51,                                  // lineNo
  5,                                   // colNo
  "allLayers",                         // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo g_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  16,                                  // colNo
  "reflectivity",                      // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo h_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  73,                                  // lineNo
  5,                                   // colNo
  "cell1",                             // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo i_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  16,                                  // colNo
  "Simulation",                        // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo j_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  5,                                   // colNo
  "cell2",                             // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo k_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  87,                                  // lineNo
  16,                                  // colNo
  "shifted_data",                      // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo l_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  87,                                  // lineNo
  5,                                   // colNo
  "cell3",                             // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo m_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  16,                                  // colNo
  "layerSlds",                         // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo n_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  5,                                   // colNo
  "cell4",                             // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo o_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  101,                                 // lineNo
  16,                                  // colNo
  "sldProfiles",                       // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo p_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  101,                                 // lineNo
  5,                                   // colNo
  "cell5",                             // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo q_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  108,                                 // lineNo
  5,                                   // colNo
  "cell6",                             // aName
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo sc_emlrtRTEI = { 6,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo tc_emlrtRTEI = { 7,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo uc_emlrtRTEI = { 8,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo vc_emlrtRTEI = { 9,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo wc_emlrtRTEI = { 10,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo xc_emlrtRTEI = { 11,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo yc_emlrtRTEI = { 12,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo ad_emlrtRTEI = { 13,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo bd_emlrtRTEI = { 15,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo cd_emlrtRTEI = { 2,// lineNo
  29,                                  // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo dd_emlrtRTEI = { 21,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo ed_emlrtRTEI = { 27,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo fd_emlrtRTEI = { 33,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo gd_emlrtRTEI = { 39,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo hd_emlrtRTEI = { 45,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo id_emlrtRTEI = { 51,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo jd_emlrtRTEI = { 59,// lineNo
  136,                                 // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo kd_emlrtRTEI = { 59,// lineNo
  9,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo ld_emlrtRTEI = { 59,// lineNo
  18,                                  // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo md_emlrtRTEI = { 59,// lineNo
  42,                                  // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo nd_emlrtRTEI = { 59,// lineNo
  55,                                  // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo od_emlrtRTEI = { 59,// lineNo
  65,                                  // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo pd_emlrtRTEI = { 73,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo qd_emlrtRTEI = { 75,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo rd_emlrtRTEI = { 80,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo sd_emlrtRTEI = { 82,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo td_emlrtRTEI = { 87,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo ud_emlrtRTEI = { 89,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo vd_emlrtRTEI = { 94,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo wd_emlrtRTEI = { 96,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo xd_emlrtRTEI = { 101,// lineNo
  5,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo yd_emlrtRTEI = { 103,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

static emlrtRTEInfo ae_emlrtRTEI = { 110,// lineNo
  1,                                   // colNo
  "reflectivity_calculation",          // fName
  "/home/arwel/Documents/RascalDev/RAT/compile/reflectivity_calculation_compile_new/reflectivity_calculation.m"// pName 
};

// Function Definitions
void reflectivity_calculation(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_6 *problemDef_cells, const struct1_T *, const struct2_T *controls,
  struct4_T *problem, cell_9 *result)
{
  int32_T i;
  int32_T i1;
  coder::array<cell_wrap_10, 1U> reflectivity;
  int32_T b_i;
  int32_T i2;
  coder::array<cell_wrap_10, 1U> Simulation;
  coder::array<cell_wrap_11, 1U> shifted_data;
  int32_T i3;
  coder::array<cell_wrap_11, 1U> layerSlds;
  coder::array<cell_wrap_10, 1U> sldProfiles;
  coder::array<cell_wrap_12, 1U> allLayers;
  boolean_T b_bool;
  int32_T kstr;
  static const char_T cv[10] = { 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T',
    'F' };

  coder::array<cell_wrap_0, 2U> t0_f1;
  coder::array<cell_wrap_7, 1U> cell1;
  coder::array<cell_wrap_1, 2U> t0_f2;
  coder::array<cell_wrap_0, 2U> t0_f3;
  coder::array<cell_wrap_0, 2U> t0_f4;
  coder::array<cell_wrap_2, 2U> t0_f5;
  coder::array<cell_wrap_2, 1U> t0_f6;
  coder::array<cell_wrap_8, 1U> cell3;
  coder::array<cell_wrap_4, 2U> t0_f7;
  coder::array<cell_wrap_4, 2U> t0_f8;
  coder::array<cell_wrap_4, 2U> t0_f9;
  coder::array<cell_wrap_4, 2U> t0_f10;
  coder::array<cell_wrap_4, 2U> t0_f11;
  coder::array<cell_wrap_4, 2U> t0_f12;
  coder::array<cell_wrap_4, 2U> t0_f13;
  coder::array<int8_T, 1U> cell6;
  coder::array<cell_wrap_5, 2U> t0_f14;
  cell_14 expl_temp;
  coder::array<cell_wrap_7, 1U> b_Simulation;
  coder::array<cell_wrap_1, 1U> b_shifted_data;
  coder::array<cell_wrap_1, 1U> b_sldProfiles;
  coder::array<cell_wrap_1, 1U> b_allLayers;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  // Preallocatin of outputs
  problem->ssubs.set_size((&sc_emlrtRTEI), sp, 1);
  problem->ssubs[0] = 0.0;
  problem->backgrounds.set_size((&tc_emlrtRTEI), sp, 1);
  problem->backgrounds[0] = 0.0;
  problem->qshifts.set_size((&uc_emlrtRTEI), sp, 1);
  problem->qshifts[0] = 0.0;
  problem->scalefactors.set_size((&vc_emlrtRTEI), sp, 1);
  problem->scalefactors[0] = 0.0;
  problem->nbairs.set_size((&wc_emlrtRTEI), sp, 1);
  problem->nbairs[0] = 0.0;
  problem->nbsubs.set_size((&xc_emlrtRTEI), sp, 1);
  problem->nbsubs[0] = 0.0;
  problem->resolutions.set_size((&yc_emlrtRTEI), sp, 1);
  problem->resolutions[0] = 0.0;
  problem->calculations.all_chis.set_size((&ad_emlrtRTEI), sp, 1);
  problem->calculations.all_chis[0] = 0.0;
  problem->calculations.sum_chi = 0.0;
  problem->allSubRough.set_size((&bd_emlrtRTEI), sp, 1);
  problem->allSubRough[0] = 0.0;
  if (!(problemDef->numberOfContrasts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(problemDef->numberOfContrasts, &emlrtDCI, sp);
  }

  i = static_cast<int32_T>(muDoubleScalarFloor(problemDef->numberOfContrasts));
  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &b_emlrtDCI, sp);
  }

  i1 = static_cast<int32_T>(problemDef->numberOfContrasts);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &emlrtRTEI, sp);
  reflectivity.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i2 = reflectivity.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&dd_emlrtRTEI), sp, 2, reflectivity[b_i].
      f1.size(1));
    i2 = reflectivity.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    reflectivity[b_i].f1.set_size((&dd_emlrtRTEI), sp, reflectivity[b_i].f1.size
      (0), 2);
    i2 = reflectivity.size(0) - 1;
    i3 = reflectivity.size(0) - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &emlrtBCI, sp);
    }

    i3 = reflectivity.size(0) - 1;
    if (b_i > i3) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &emlrtBCI, sp);
    }

    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    reflectivity[b_i].f1[0] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    reflectivity[b_i].f1[1] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    reflectivity[b_i].f1[2] = 1.0;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &emlrtBCI, sp);
    }

    reflectivity[b_i].f1[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (problemDef->numberOfContrasts != i) {
    emlrtIntegerCheckR2012b(problemDef->numberOfContrasts, &c_emlrtDCI, sp);
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &b_emlrtRTEI, sp);
  Simulation.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&ed_emlrtRTEI), sp, 2, Simulation[b_i].f1.size
      (1));
    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    Simulation[b_i].f1.set_size((&ed_emlrtRTEI), sp, Simulation[b_i].f1.size(0),
      2);
    i = Simulation.size(0) - 1;
    i2 = Simulation.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &b_emlrtBCI, sp);
    }

    i2 = Simulation.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &b_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    Simulation[b_i].f1[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    Simulation[b_i].f1[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    Simulation[b_i].f1[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &b_emlrtBCI, sp);
    }

    Simulation[b_i].f1[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &c_emlrtRTEI, sp);
  shifted_data.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = shifted_data.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &c_emlrtBCI, sp);
    }

    shifted_data[b_i].f1.set_size((&fd_emlrtRTEI), sp, 2, shifted_data[b_i].
      f1.size(1));
    i = shifted_data.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &c_emlrtBCI, sp);
    }

    shifted_data[b_i].f1.set_size((&fd_emlrtRTEI), sp, shifted_data[b_i].f1.size
      (0), 3);
    i = shifted_data.size(0) - 1;
    i2 = shifted_data.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &c_emlrtBCI, sp);
    }

    i2 = shifted_data.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &c_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &c_emlrtBCI, sp);
      }

      shifted_data[b_i].f1[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &d_emlrtRTEI, sp);
  layerSlds.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = layerSlds.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &d_emlrtBCI, sp);
    }

    layerSlds[b_i].f1.set_size((&gd_emlrtRTEI), sp, 2, layerSlds[b_i].f1.size(1));
    i = layerSlds.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &d_emlrtBCI, sp);
    }

    layerSlds[b_i].f1.set_size((&gd_emlrtRTEI), sp, layerSlds[b_i].f1.size(0), 3);
    i = layerSlds.size(0) - 1;
    i2 = layerSlds.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &d_emlrtBCI, sp);
    }

    i2 = layerSlds.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &d_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < 6; i2++) {
      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &d_emlrtBCI, sp);
      }

      layerSlds[b_i].f1[i2] = 1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &e_emlrtRTEI, sp);
  sldProfiles.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = sldProfiles.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1.set_size((&hd_emlrtRTEI), sp, 2, sldProfiles[b_i].
      f1.size(1));
    i = sldProfiles.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1.set_size((&hd_emlrtRTEI), sp, sldProfiles[b_i].f1.size(0),
      2);
    i = sldProfiles.size(0) - 1;
    i2 = sldProfiles.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &e_emlrtBCI, sp);
    }

    i2 = sldProfiles.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &e_emlrtBCI, sp);
    }

    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[1] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[2] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &e_emlrtBCI, sp);
    }

    sldProfiles[b_i].f1[3] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &f_emlrtRTEI, sp);
  allLayers.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = allLayers.size(0) - 1;
    i2 = allLayers.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &f_emlrtBCI, sp);
    }

    allLayers[b_i].f1.set_size((&id_emlrtRTEI), sp, 2);
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &f_emlrtBCI, sp);
    }

    allLayers[b_i].f1[0] = 1.0;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &f_emlrtBCI, sp);
    }

    allLayers[b_i].f1[1] = 1.0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  // Decide which target function we are calling
  b_bool = false;
  if (problemDef->TF.size(1) == 10) {
    kstr = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (problemDef->TF[kstr] != cv[kstr]) {
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
    kstr = -1;
  }

  switch (kstr) {
   case 0:
    t0_f1.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f1.size(1));
    kstr = problemDef_cells->f1.size(0) * problemDef_cells->f1.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f1[i] = problemDef_cells->f1[i];
    }

    t0_f2.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f2.size(1));
    kstr = problemDef_cells->f2.size(0) * problemDef_cells->f2.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f2[i] = problemDef_cells->f2[i];
    }

    t0_f3.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f3.size(1));
    kstr = problemDef_cells->f3.size(0) * problemDef_cells->f3.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f3[i] = problemDef_cells->f3[i];
    }

    t0_f4.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f4.size(1));
    kstr = problemDef_cells->f4.size(0) * problemDef_cells->f4.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f4[i] = problemDef_cells->f4[i];
    }

    t0_f5.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f5.size(1));
    kstr = problemDef_cells->f5.size(0) * problemDef_cells->f5.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f5[i] = problemDef_cells->f5[i];
    }

    t0_f6.set_size((&jd_emlrtRTEI), sp, problemDef_cells->f6.size(0));
    i = problemDef_cells->f6.size(0);
    for (i2 = 0; i2 < i; i2++) {
      t0_f6[i2].f1.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f6[i2].
                            f1.size[1]);
      kstr = problemDef_cells->f6[i2].f1.size[0] * problemDef_cells->f6[i2].
        f1.size[1];
      for (i3 = 0; i3 < kstr; i3++) {
        t0_f6[i2].f1[i3] = problemDef_cells->f6[i2].f1.data[i3];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    t0_f7.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f7.size(1));
    kstr = problemDef_cells->f7.size(0) * problemDef_cells->f7.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f7[i] = problemDef_cells->f7[i];
    }

    t0_f8.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f8.size(1));
    kstr = problemDef_cells->f8.size(0) * problemDef_cells->f8.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f8[i] = problemDef_cells->f8[i];
    }

    t0_f9.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f9.size(1));
    kstr = problemDef_cells->f9.size(0) * problemDef_cells->f9.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f9[i] = problemDef_cells->f9[i];
    }

    t0_f10.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f10.size(1));
    kstr = problemDef_cells->f10.size(0) * problemDef_cells->f10.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f10[i] = problemDef_cells->f10[i];
    }

    t0_f11.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f11.size(1));
    kstr = problemDef_cells->f11.size(0) * problemDef_cells->f11.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f11[i] = problemDef_cells->f11[i];
    }

    t0_f12.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f12.size(1));
    kstr = problemDef_cells->f12.size(0) * problemDef_cells->f12.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f12[i] = problemDef_cells->f12[i];
    }

    t0_f13.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f13.size(1));
    kstr = problemDef_cells->f13.size(0) * problemDef_cells->f13.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f13[i] = problemDef_cells->f13[i];
    }

    t0_f14.set_size((&jd_emlrtRTEI), sp, 1, problemDef_cells->f14.size(1));
    kstr = problemDef_cells->f14.size(0) * problemDef_cells->f14.size(1);
    for (i = 0; i < kstr; i++) {
      t0_f14[i] = problemDef_cells->f14[i];
    }

    expl_temp.f14.set_size((&kd_emlrtRTEI), sp, 1, t0_f14.size(1));
    kstr = t0_f14.size(0) * t0_f14.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f14[i] = t0_f14[i];
    }

    expl_temp.f13.set_size((&kd_emlrtRTEI), sp, 1, t0_f13.size(1));
    kstr = t0_f13.size(0) * t0_f13.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f13[i] = t0_f13[i];
    }

    expl_temp.f12.set_size((&kd_emlrtRTEI), sp, 1, t0_f12.size(1));
    kstr = t0_f12.size(0) * t0_f12.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f12[i] = t0_f12[i];
    }

    expl_temp.f11.set_size((&kd_emlrtRTEI), sp, 1, t0_f11.size(1));
    kstr = t0_f11.size(0) * t0_f11.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f11[i] = t0_f11[i];
    }

    expl_temp.f10.set_size((&kd_emlrtRTEI), sp, 1, t0_f10.size(1));
    kstr = t0_f10.size(0) * t0_f10.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f10[i] = t0_f10[i];
    }

    expl_temp.f9.set_size((&kd_emlrtRTEI), sp, 1, t0_f9.size(1));
    kstr = t0_f9.size(0) * t0_f9.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f9[i] = t0_f9[i];
    }

    expl_temp.f8.set_size((&kd_emlrtRTEI), sp, 1, t0_f8.size(1));
    kstr = t0_f8.size(0) * t0_f8.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f8[i] = t0_f8[i];
    }

    expl_temp.f7.set_size((&kd_emlrtRTEI), sp, 1, t0_f7.size(1));
    kstr = t0_f7.size(0) * t0_f7.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f7[i] = t0_f7[i];
    }

    expl_temp.f6.set_size((&kd_emlrtRTEI), sp, t0_f6.size(0));
    kstr = t0_f6.size(0);
    for (i = 0; i < kstr; i++) {
      expl_temp.f6[i] = t0_f6[i];
    }

    expl_temp.f5.set_size((&kd_emlrtRTEI), sp, 1, t0_f5.size(1));
    kstr = t0_f5.size(0) * t0_f5.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f5[i] = t0_f5[i];
    }

    expl_temp.f4.set_size((&kd_emlrtRTEI), sp, 1, t0_f4.size(1));
    kstr = t0_f4.size(0) * t0_f4.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f4[i] = t0_f4[i];
    }

    expl_temp.f3.set_size((&kd_emlrtRTEI), sp, 1, t0_f3.size(1));
    kstr = t0_f3.size(0) * t0_f3.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f3[i] = t0_f3[i];
    }

    expl_temp.f2.set_size((&kd_emlrtRTEI), sp, 1, t0_f2.size(1));
    kstr = t0_f2.size(0) * t0_f2.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f2[i] = t0_f2[i];
    }

    expl_temp.f1.set_size((&kd_emlrtRTEI), sp, 1, t0_f1.size(1));
    kstr = t0_f1.size(0) * t0_f1.size(1);
    for (i = 0; i < kstr; i++) {
      expl_temp.f1[i] = t0_f1[i];
    }

    st.site = &emlrtRSI;
    c_standardTF_reflectivityCalcul(&st, problemDef, &expl_temp, controls,
      problem, cell1, b_Simulation, b_shifted_data, cell3, b_sldProfiles,
      b_allLayers);
    reflectivity.set_size((&ld_emlrtRTEI), sp, cell1.size(0));
    i = cell1.size(0);
    for (i2 = 0; i2 < i; i2++) {
      reflectivity[i2].f1.set_size((&ld_emlrtRTEI), sp, cell1[i2].f1.size(0), 2);
      kstr = cell1[i2].f1.size(0) * cell1[i2].f1.size(1);
      for (i3 = 0; i3 < kstr; i3++) {
        reflectivity[i2].f1[i3] = cell1[i2].f1[i3];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    Simulation.set_size((&ld_emlrtRTEI), sp, b_Simulation.size(0));
    i = b_Simulation.size(0);
    for (i2 = 0; i2 < i; i2++) {
      Simulation[i2].f1.set_size((&ld_emlrtRTEI), sp, b_Simulation[i2].f1.size(0),
        2);
      kstr = b_Simulation[i2].f1.size(0) * b_Simulation[i2].f1.size(1);
      for (i3 = 0; i3 < kstr; i3++) {
        Simulation[i2].f1[i3] = b_Simulation[i2].f1[i3];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    shifted_data.set_size((&md_emlrtRTEI), sp, b_shifted_data.size(0));
    i = b_shifted_data.size(0);
    for (i2 = 0; i2 < i; i2++) {
      shifted_data[i2].f1.set_size((&md_emlrtRTEI), sp, b_shifted_data[i2].
        f1.size(0), b_shifted_data[i2].f1.size(1));
      kstr = b_shifted_data[i2].f1.size(0) * b_shifted_data[i2].f1.size(1);
      for (i3 = 0; i3 < kstr; i3++) {
        shifted_data[i2].f1[i3] = b_shifted_data[i2].f1[i3];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    layerSlds.set_size((&nd_emlrtRTEI), sp, cell3.size(0));
    i = cell3.size(0);
    for (i2 = 0; i2 < i; i2++) {
      layerSlds[i2].f1.set_size((&nd_emlrtRTEI), sp, cell3[i2].f1.size(0), 3);
      kstr = cell3[i2].f1.size(0) * cell3[i2].f1.size(1);
      for (i3 = 0; i3 < kstr; i3++) {
        layerSlds[i2].f1[i3] = cell3[i2].f1[i3];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    sldProfiles.set_size((&od_emlrtRTEI), sp, b_sldProfiles.size(0));
    i = b_sldProfiles.size(0);
    for (i2 = 0; i2 < i; i2++) {
      sldProfiles[i2].f1.set_size((&od_emlrtRTEI), sp, b_sldProfiles[i2].f1.size
        (0), b_sldProfiles[i2].f1.size(1));
      kstr = b_sldProfiles[i2].f1.size(0) * b_sldProfiles[i2].f1.size(1);
      for (i3 = 0; i3 < kstr; i3++) {
        sldProfiles[i2].f1[i3] = b_sldProfiles[i2].f1[i3];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    // case 'oilWaterTF'
    // problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);     
    // case 'polarisedTF'
    // problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls); 
    // case 'domainsTF'
    // problem = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls); 
    break;
  }

  // cell1Length = numberOfContrasts;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &g_emlrtRTEI, sp);
  cell1.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = reflectivity.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &g_emlrtBCI, sp);
    }

    i = reflectivity.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &g_emlrtBCI, sp);
    }

    kstr = reflectivity[b_i].f1.size(0) * reflectivity[b_i].f1.size(1);
    i = reflectivity.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &g_emlrtBCI, sp);
    }

    i = cell1.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &h_emlrtBCI, sp);
    }

    cell1[b_i].f1.set_size((&pd_emlrtRTEI), sp, reflectivity[b_i].f1.size(0),
      cell1[b_i].f1.size(1));
    i = cell1.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &h_emlrtBCI, sp);
    }

    cell1[b_i].f1.set_size((&pd_emlrtRTEI), sp, cell1[b_i].f1.size(0), 2);
    i = cell1.size(0) - 1;
    i2 = cell1.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &h_emlrtBCI, sp);
    }

    i2 = cell1.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &h_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      i3 = reflectivity.size(0) - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &g_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &h_emlrtBCI, sp);
      }

      cell1[b_i].f1[i2] = reflectivity[b_i].f1[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  result->f1.set_size((&qd_emlrtRTEI), sp, cell1.size(0));
  kstr = cell1.size(0);
  for (i = 0; i < kstr; i++) {
    result->f1[i] = cell1[i];
  }

  //  cell2Length = 7;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &h_emlrtRTEI, sp);
  cell1.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &i_emlrtBCI, sp);
    }

    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &i_emlrtBCI, sp);
    }

    kstr = Simulation[b_i].f1.size(0) * Simulation[b_i].f1.size(1);
    i = Simulation.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &i_emlrtBCI, sp);
    }

    i = cell1.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &j_emlrtBCI, sp);
    }

    cell1[b_i].f1.set_size((&rd_emlrtRTEI), sp, Simulation[b_i].f1.size(0),
      cell1[b_i].f1.size(1));
    i = cell1.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &j_emlrtBCI, sp);
    }

    cell1[b_i].f1.set_size((&rd_emlrtRTEI), sp, cell1[b_i].f1.size(0), 2);
    i = cell1.size(0) - 1;
    i2 = cell1.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &j_emlrtBCI, sp);
    }

    i2 = cell1.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &j_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      i3 = Simulation.size(0) - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &i_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &j_emlrtBCI, sp);
      }

      cell1[b_i].f1[i2] = Simulation[b_i].f1[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  result->f2.set_size((&sd_emlrtRTEI), sp, cell1.size(0));
  kstr = cell1.size(0);
  for (i = 0; i < kstr; i++) {
    result->f2[i] = cell1[i];
  }

  //
  //  cell3Length = 7;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &i_emlrtRTEI, sp);
  cell3.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = shifted_data.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &k_emlrtBCI, sp);
    }

    i = shifted_data.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &k_emlrtBCI, sp);
    }

    kstr = shifted_data[b_i].f1.size(0) * shifted_data[b_i].f1.size(1);
    i = shifted_data.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &k_emlrtBCI, sp);
    }

    i = cell3.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &l_emlrtBCI, sp);
    }

    cell3[b_i].f1.set_size((&td_emlrtRTEI), sp, shifted_data[b_i].f1.size(0),
      cell3[b_i].f1.size(1));
    i = cell3.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &l_emlrtBCI, sp);
    }

    cell3[b_i].f1.set_size((&td_emlrtRTEI), sp, cell3[b_i].f1.size(0), 3);
    i = cell3.size(0) - 1;
    i2 = cell3.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &l_emlrtBCI, sp);
    }

    i2 = cell3.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &l_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      i3 = shifted_data.size(0) - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &k_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &l_emlrtBCI, sp);
      }

      cell3[b_i].f1[i2] = shifted_data[b_i].f1[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  result->f3.set_size((&ud_emlrtRTEI), sp, cell3.size(0));
  kstr = cell3.size(0);
  for (i = 0; i < kstr; i++) {
    result->f3[i] = cell3[i];
  }

  //
  //  cell4Length = 7;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &j_emlrtRTEI, sp);
  cell3.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = layerSlds.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &m_emlrtBCI, sp);
    }

    i = layerSlds.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &m_emlrtBCI, sp);
    }

    kstr = layerSlds[b_i].f1.size(0) * layerSlds[b_i].f1.size(1);
    i = layerSlds.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &m_emlrtBCI, sp);
    }

    i = cell3.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &n_emlrtBCI, sp);
    }

    cell3[b_i].f1.set_size((&vd_emlrtRTEI), sp, layerSlds[b_i].f1.size(0),
      cell3[b_i].f1.size(1));
    i = cell3.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &n_emlrtBCI, sp);
    }

    cell3[b_i].f1.set_size((&vd_emlrtRTEI), sp, cell3[b_i].f1.size(0), 3);
    i = cell3.size(0) - 1;
    i2 = cell3.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &n_emlrtBCI, sp);
    }

    i2 = cell3.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &n_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      i3 = layerSlds.size(0) - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &m_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &n_emlrtBCI, sp);
      }

      cell3[b_i].f1[i2] = layerSlds[b_i].f1[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  result->f4.set_size((&wd_emlrtRTEI), sp, cell3.size(0));
  kstr = cell3.size(0);
  for (i = 0; i < kstr; i++) {
    result->f4[i] = cell3[i];
  }

  //
  //  cell5Length = 7;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &k_emlrtRTEI, sp);
  cell1.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = sldProfiles.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &o_emlrtBCI, sp);
    }

    i = sldProfiles.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &o_emlrtBCI, sp);
    }

    kstr = sldProfiles[b_i].f1.size(0) * sldProfiles[b_i].f1.size(1);
    i = sldProfiles.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &o_emlrtBCI, sp);
    }

    i = cell1.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &p_emlrtBCI, sp);
    }

    cell1[b_i].f1.set_size((&xd_emlrtRTEI), sp, sldProfiles[b_i].f1.size(0),
      cell1[b_i].f1.size(1));
    i = cell1.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &p_emlrtBCI, sp);
    }

    cell1[b_i].f1.set_size((&xd_emlrtRTEI), sp, cell1[b_i].f1.size(0), 2);
    i = cell1.size(0) - 1;
    i2 = cell1.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &p_emlrtBCI, sp);
    }

    i2 = cell1.size(0) - 1;
    if (b_i > i2) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i2, &p_emlrtBCI, sp);
    }

    for (i2 = 0; i2 < kstr; i2++) {
      i3 = sldProfiles.size(0) - 1;
      if (b_i > i3) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i3, &o_emlrtBCI, sp);
      }

      if (b_i > i) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &p_emlrtBCI, sp);
      }

      cell1[b_i].f1[i2] = sldProfiles[b_i].f1[i2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  result->f5.set_size((&yd_emlrtRTEI), sp, cell1.size(0));
  kstr = cell1.size(0);
  for (i = 0; i < kstr; i++) {
    result->f5[i] = cell1[i];
  }

  //
  //  cell6Length = 7;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, problemDef->numberOfContrasts,
    mxDOUBLE_CLASS, static_cast<int32_T>(problemDef->numberOfContrasts),
    &l_emlrtRTEI, sp);
  cell6.set_size((&cd_emlrtRTEI), sp, i1);
  for (b_i = 0; b_i < i1; b_i++) {
    i = cell6.size(0) - 1;
    if (b_i > i) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i, &q_emlrtBCI, sp);
    }

    cell6[b_i] = 0;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  result->f6.set_size((&ae_emlrtRTEI), sp, cell6.size(0));
  kstr = cell6.size(0);
  for (i = 0; i < kstr; i++) {
    result->f6[i] = cell6[i];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (reflectivity_calculation.cpp)
