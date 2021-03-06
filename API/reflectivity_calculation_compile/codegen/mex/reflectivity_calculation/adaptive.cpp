//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  adaptive.cpp
//
//  Code generation for function 'adaptive'
//


// Include files
#include "adaptive.h"
#include "acos.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "power.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sldFunc.h"
#include "sortrows.h"
#include "standardTF_layers_core.h"
#include "sum.h"

// Variable Definitions
static emlrtRSInfo vc_emlrtRSI = { 252,// lineNo
  "adaptive",                          // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo wc_emlrtRSI = { 267,// lineNo
  "adaptive",                          // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo xc_emlrtRSI = { 281,// lineNo
  "adaptive",                          // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo yc_emlrtRSI = { 304,// lineNo
  "adaptive",                          // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo ad_emlrtRSI = { 305,// lineNo
  "adaptive",                          // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo bd_emlrtRSI = { 376,// lineNo
  "normalizeFunction",                 // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo jd_emlrtRSI = { 167,// lineNo
  "unaryMinOrMax",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo kd_emlrtRSI = { 326,// lineNo
  "unaryMinOrMaxDispatch",             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo ld_emlrtRSI = { 394,// lineNo
  "minOrMax2D",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo md_emlrtRSI = { 476,// lineNo
  "minOrMax2DColumnMajorDim1",         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

static emlrtRSInfo nd_emlrtRSI = { 14, // lineNo
  "min",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/min.m"// pathName
};

static emlrtRSInfo od_emlrtRSI = { 46, // lineNo
  "minOrMax",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

static emlrtRSInfo pd_emlrtRSI = { 92, // lineNo
  "minimum",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

static emlrtRSInfo qd_emlrtRSI = { 398,// lineNo
  "calculateCentralAngles",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo rd_emlrtRSI = { 399,// lineNo
  "calculateCentralAngles",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo sd_emlrtRSI = { 401,// lineNo
  "calculateCentralAngles",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo td_emlrtRSI = { 403,// lineNo
  "calculateCentralAngles",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo ud_emlrtRSI = { 404,// lineNo
  "calculateCentralAngles",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo vd_emlrtRSI = { 405,// lineNo
  "calculateCentralAngles",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo wd_emlrtRSI = { 408,// lineNo
  "calculateCentralAngles",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo xd_emlrtRSI = { 407,// lineNo
  "calculateCentralAngles",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo yd_emlrtRSI = { 409,// lineNo
  "calculateCentralAngles",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo ee_emlrtRSI = { 16, // lineNo
  "sqrt",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/sqrt.m"// pathName
};

static emlrtRSInfo he_emlrtRSI = { 13, // lineNo
  "any",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/any.m"// pathName
};

static emlrtRSInfo ie_emlrtRSI = { 143,// lineNo
  "allOrAny",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/allOrAny.m"// pathName 
};

static emlrtRSInfo je_emlrtRSI = { 431,// lineNo
  "increaseSampling",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtRSInfo ke_emlrtRSI = { 433,// lineNo
  "increaseSampling",                  // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pathName 
};

static emlrtDCInfo jb_emlrtDCI = { 274,// lineNo
  30,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  4                                    // checkKind
};

static emlrtECInfo f_emlrtECI = { -1,  // nDims
  283,                                 // lineNo
  25,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtECInfo g_emlrtECI = { -1,  // nDims
  289,                                 // lineNo
  21,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo mb_emlrtRTEI = { 26,// lineNo
  27,                                  // colNo
  "unaryMinOrMax",                     // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pName 
};

static emlrtRTEInfo nb_emlrtRTEI = { 95,// lineNo
  27,                                  // colNo
  "unaryMinOrMax",                     // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pName 
};

static emlrtECInfo h_emlrtECI = { -1,  // nDims
  376,                                 // lineNo
  5,                                   // colNo
  "normalizeFunction",                 // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtECInfo i_emlrtECI = { 2,   // nDims
  398,                                 // lineNo
  3,                                   // colNo
  "calculateCentralAngles",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtECInfo j_emlrtECI = { -1,  // nDims
  403,                                 // lineNo
  21,                                  // colNo
  "calculateCentralAngles",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtECInfo k_emlrtECI = { -1,  // nDims
  404,                                 // lineNo
  21,                                  // colNo
  "calculateCentralAngles",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtECInfo l_emlrtECI = { -1,  // nDims
  405,                                 // lineNo
  21,                                  // colNo
  "calculateCentralAngles",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtECInfo m_emlrtECI = { -1,  // nDims
  407,                                 // lineNo
  4,                                   // colNo
  "calculateCentralAngles",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtECInfo n_emlrtECI = { -1,  // nDims
  408,                                 // lineNo
  8,                                   // colNo
  "calculateCentralAngles",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtBCInfo qf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  386,                                 // lineNo
  20,                                  // colNo
  "XYdata",                            // aName
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo rf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  386,                                 // lineNo
  22,                                  // colNo
  "XYdata",                            // aName
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo sf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  386,                                 // lineNo
  40,                                  // colNo
  "XYdata",                            // aName
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo tf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  386,                                 // lineNo
  42,                                  // colNo
  "XYdata",                            // aName
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo o_emlrtECI = { 2,   // nDims
  386,                                 // lineNo
  13,                                  // colNo
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtBCInfo uf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  387,                                 // lineNo
  23,                                  // colNo
  "XYdata",                            // aName
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo vf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  387,                                 // lineNo
  41,                                  // colNo
  "XYdata",                            // aName
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo wf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  387,                                 // lineNo
  43,                                  // colNo
  "XYdata",                            // aName
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo p_emlrtECI = { 2,   // nDims
  387,                                 // lineNo
  14,                                  // colNo
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtBCInfo xf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  388,                                 // lineNo
  22,                                  // colNo
  "XYdata",                            // aName
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo yf_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  388,                                 // lineNo
  40,                                  // colNo
  "XYdata",                            // aName
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ag_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  388,                                 // lineNo
  42,                                  // colNo
  "XYdata",                            // aName
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo q_emlrtECI = { 2,   // nDims
  388,                                 // lineNo
  13,                                  // colNo
  "calculateTrianglesSides",           // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo qb_emlrtRTEI = { 13,// lineNo
  9,                                   // colNo
  "sqrt",                              // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/sqrt.m"// pName
};

static emlrtECInfo u_emlrtECI = { -1,  // nDims
  429,                                 // lineNo
  29,                                  // colNo
  "increaseSampling",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtECInfo v_emlrtECI = { -1,  // nDims
  429,                                 // lineNo
  1,                                   // colNo
  "increaseSampling",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtECInfo w_emlrtECI = { -1,  // nDims
  431,                                 // lineNo
  1,                                   // colNo
  "increaseSampling",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtBCInfo jk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  425,                                 // lineNo
  39,                                  // colNo
  "segmentsToSplit",                   // aName
  "increaseSampling",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  429,                                 // lineNo
  40,                                  // colNo
  "dataPoints",                        // aName
  "increaseSampling",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo lk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  430,                                 // lineNo
  14,                                  // colNo
  "dataPoints",                        // aName
  "increaseSampling",                  // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo mk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  376,                                 // lineNo
  20,                                  // colNo
  "x",                                 // aName
  "normalizeFunction",                 // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo nk_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  376,                                 // lineNo
  5,                                   // colNo
  "y",                                 // aName
  "normalizeFunction",                 // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo xf_emlrtRTEI = { 255,// lineNo
  1,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo yf_emlrtRTEI = { 281,// lineNo
  42,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo ag_emlrtRTEI = { 282,// lineNo
  5,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo bg_emlrtRTEI = { 283,// lineNo
  5,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo cg_emlrtRTEI = { 289,// lineNo
  21,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo dg_emlrtRTEI = { 289,// lineNo
  50,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo eg_emlrtRTEI = { 334,// lineNo
  3,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo qg_emlrtRTEI = { 398,// lineNo
  3,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo rg_emlrtRTEI = { 397,// lineNo
  1,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo sg_emlrtRTEI = { 386,// lineNo
  1,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo tg_emlrtRTEI = { 387,// lineNo
  1,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo ug_emlrtRTEI = { 388,// lineNo
  1,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo vg_emlrtRTEI = { 403,// lineNo
  21,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo wg_emlrtRTEI = { 403,// lineNo
  42,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo xg_emlrtRTEI = { 404,// lineNo
  21,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo yg_emlrtRTEI = { 404,// lineNo
  42,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo ah_emlrtRTEI = { 405,// lineNo
  21,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo bh_emlrtRTEI = { 405,// lineNo
  42,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo ch_emlrtRTEI = { 407,// lineNo
  3,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo dh_emlrtRTEI = { 409,// lineNo
  20,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo eh_emlrtRTEI = { 409,// lineNo
  1,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo yi_emlrtRTEI = { 426,// lineNo
  1,                                   // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo aj_emlrtRTEI = { 429,// lineNo
  40,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo bj_emlrtRTEI = { 430,// lineNo
  14,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo cj_emlrtRTEI = { 422,// lineNo
  23,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo dj_emlrtRTEI = { 429,// lineNo
  22,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo ej_emlrtRTEI = { 431,// lineNo
  22,                                  // colNo
  "adaptive",                          // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/resampleLayers/adaptive.m"// pName 
};

static emlrtRTEInfo fj_emlrtRTEI = { 303,// lineNo
  14,                                  // colNo
  "cat",                               // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"// pName
};

// Function Declarations
static void calculateCentralAngles(const emlrtStack *sp, const coder::array<
  real_T, 2U> &XYdata, const real_T dataBoxSize[2], coder::array<real_T, 1U>
  &cornerAngle);
static void increaseSampling(const emlrtStack *sp, coder::array<real_T, 2U>
  &dataPoints, const coder::array<boolean_T, 1U> &segmentsToSplit, const coder::
  array<real_T, 2U> &sldProfile);

// Function Definitions
static void calculateCentralAngles(const emlrtStack *sp, const coder::array<
  real_T, 2U> &XYdata, const real_T dataBoxSize[2], coder::array<real_T, 1U>
  &cornerAngle)
{
  coder::array<real_T, 2U> normalizedData;
  real_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  boolean_T overflow;
  int32_T m;
  int32_T i;
  int32_T b_i;
  real_T b;
  coder::array<real_T, 2U> longStep;
  int32_T i1;
  int32_T iv[2];
  int32_T iv1[2];
  coder::array<real_T, 2U> firstStep;
  coder::array<real_T, 2U> secondStep;
  coder::array<real_T, 1U> b_firstStep;
  coder::array<real_T, 1U> firstStepSquared;
  coder::array<real_T, 1U> r;
  coder::array<real_T, 1U> secondStepSquared;
  coder::array<real_T, 1U> longStepSquared;
  coder::array<creal_T, 1U> r1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  //  Calculate the central angle of the triangles formed by data points.
  //  For input size NxM, the output size is (N-2)xN, because the first and the
  //  last point are not the central corner of any triangle.
  //  Normalize data, because angles depend on scaling.
  st.site = &qd_emlrtRSI;
  b_st.site = &qd_emlrtRSI;
  repmat(&b_st, dataBoxSize, static_cast<real_T>(XYdata.size(0)), normalizedData);
  varargin_1[0] = XYdata.size(0);
  varargin_2[0] = static_cast<uint32_T>(normalizedData.size(0));
  varargin_1[1] = XYdata.size(1);
  varargin_2[1] = static_cast<uint32_T>(normalizedData.size(1));
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (static_cast<int32_T>(static_cast<uint32_T>(varargin_1[k])) !=
        static_cast<int32_T>(varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  overflow = p;
  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &pb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  m = XYdata.size(0) * XYdata.size(1);
  normalizedData.set_size((&qg_emlrtRTEI), (&st), XYdata.size(0), 2);
  for (i = 0; i < m; i++) {
    normalizedData[i] = XYdata[i] / normalizedData[i];
  }

  st.site = &rd_emlrtRSI;
  b_st.site = &nd_emlrtRSI;
  c_st.site = &od_emlrtRSI;
  d_st.site = &pd_emlrtRSI;
  if (XYdata.size(0) == 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &mb_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility",
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (XYdata.size(0) < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &nb_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &jd_emlrtRSI;
  f_st.site = &kd_emlrtRSI;
  g_st.site = &ld_emlrtRSI;
  m = XYdata.size(0);
  overflow = ((2 <= XYdata.size(0)) && (XYdata.size(0) > 2147483646));
  varargin_1[0] = XYdata[0];
  h_st.site = &md_emlrtRSI;
  if (overflow) {
    i_st.site = &nb_emlrtRSI;
    check_forloop_overflow_error(&i_st);
  }

  for (b_i = 2; b_i <= m; b_i++) {
    b = XYdata[b_i - 1];
    if ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(varargin_1[0]) ||
         (varargin_1[0] > b))) {
      varargin_1[0] = b;
    }
  }

  varargin_1[1] = XYdata[XYdata.size(0)];
  h_st.site = &md_emlrtRSI;
  for (b_i = 2; b_i <= m; b_i++) {
    b = XYdata[(b_i + XYdata.size(0)) - 1];
    if ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN(varargin_1[1]) ||
         (varargin_1[1] > b))) {
      varargin_1[1] = b;
    }
  }

  st.site = &rd_emlrtRSI;
  repmat(&st, varargin_1, static_cast<real_T>(XYdata.size(0)), longStep);
  emlrtSizeEqCheckNDR2012b(normalizedData.size(), longStep.size(), &i_emlrtECI,
    sp);
  m = normalizedData.size(0) * normalizedData.size(1);
  normalizedData.set_size((&rg_emlrtRTEI), sp, normalizedData.size(0), 2);
  for (i = 0; i < m; i++) {
    normalizedData[i] = normalizedData[i] - longStep[i];
  }

  //  calculate cosine of central angles
  st.site = &sd_emlrtRSI;

  //  Return the sides (deltaX, deltaY) of the triangles formed by data points.
  //  For input size NxM, the output size is (N-2)xN, because the first and the
  //  last point are not the central corner of any triangle.
  if (2 > normalizedData.size(0) - 1) {
    i = -1;
    i1 = -1;
  } else {
    if (2 > normalizedData.size(0)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, normalizedData.size(0), &qf_emlrtBCI,
        &st);
    }

    i = 0;
    i1 = normalizedData.size(0) - 1;
    if ((i1 < 1) || (i1 > normalizedData.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, normalizedData.size(0), &rf_emlrtBCI,
        &st);
    }

    i1--;
  }

  if (1 > normalizedData.size(0) - 2) {
    b_i = 0;
  } else {
    if (1 > normalizedData.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, normalizedData.size(0), &sf_emlrtBCI,
        &st);
    }

    b_i = normalizedData.size(0) - 2;
    if ((b_i < 1) || (b_i > normalizedData.size(0))) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, normalizedData.size(0), &tf_emlrtBCI,
        &st);
    }
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = b_i;
  iv1[1] = 2;
  if (m != b_i) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &o_emlrtECI, &st);
  }

  firstStep.set_size((&sg_emlrtRTEI), (&st), m, 2);
  for (i1 = 0; i1 < m; i1++) {
    firstStep[i1] = normalizedData[(i + i1) + 1] - normalizedData[i1];
  }

  for (i1 = 0; i1 < m; i1++) {
    firstStep[i1 + firstStep.size(0)] = normalizedData[((i + i1) +
      normalizedData.size(0)) + 1] - normalizedData[i1 + normalizedData.size(0)];
  }

  if (3 > normalizedData.size(0)) {
    i = -1;
    i1 = -1;
  } else {
    i = 1;
    if (normalizedData.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(normalizedData.size(0), 1,
        normalizedData.size(0), &uf_emlrtBCI, &st);
    }

    i1 = normalizedData.size(0) - 1;
  }

  if (2 > normalizedData.size(0) - 1) {
    b_i = -1;
    k = 0;
  } else {
    if (2 > normalizedData.size(0)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, normalizedData.size(0), &vf_emlrtBCI,
        &st);
    }

    b_i = 0;
    k = normalizedData.size(0) - 1;
    if ((k < 1) || (k > normalizedData.size(0))) {
      emlrtDynamicBoundsCheckR2012b(k, 1, normalizedData.size(0), &wf_emlrtBCI,
        &st);
    }
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = (k - b_i) - 1;
  iv1[1] = 2;
  if (m != iv1[0]) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &p_emlrtECI, &st);
  }

  secondStep.set_size((&tg_emlrtRTEI), (&st), m, 2);
  for (i1 = 0; i1 < m; i1++) {
    secondStep[i1] = normalizedData[(i + i1) + 1] - normalizedData[(b_i + i1) +
      1];
  }

  for (i1 = 0; i1 < m; i1++) {
    secondStep[i1 + secondStep.size(0)] = normalizedData[((i + i1) +
      normalizedData.size(0)) + 1] - normalizedData[((b_i + i1) +
      normalizedData.size(0)) + 1];
  }

  if (3 > normalizedData.size(0)) {
    i = -1;
    i1 = -1;
  } else {
    i = 1;
    if (normalizedData.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(normalizedData.size(0), 1,
        normalizedData.size(0), &xf_emlrtBCI, &st);
    }

    i1 = normalizedData.size(0) - 1;
  }

  if (1 > normalizedData.size(0) - 2) {
    b_i = 0;
  } else {
    if (1 > normalizedData.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, normalizedData.size(0), &yf_emlrtBCI,
        &st);
    }

    b_i = normalizedData.size(0) - 2;
    if ((b_i < 1) || (b_i > normalizedData.size(0))) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, normalizedData.size(0), &ag_emlrtBCI,
        &st);
    }
  }

  m = i1 - i;
  iv[0] = m;
  iv[1] = 2;
  iv1[0] = b_i;
  iv1[1] = 2;
  if (m != b_i) {
    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &q_emlrtECI, &st);
  }

  longStep.set_size((&ug_emlrtRTEI), (&st), m, 2);
  for (i1 = 0; i1 < m; i1++) {
    longStep[i1] = normalizedData[(i + i1) + 1] - normalizedData[i1];
  }

  for (i1 = 0; i1 < m; i1++) {
    longStep[i1 + longStep.size(0)] = normalizedData[((i + i1) +
      normalizedData.size(0)) + 1] - normalizedData[i1 + normalizedData.size(0)];
  }

  //  calculate area of squares of length of triangle sides
  m = firstStep.size(0);
  b_firstStep.set_size((&vg_emlrtRTEI), sp, firstStep.size(0));
  for (i = 0; i < m; i++) {
    b_firstStep[i] = firstStep[i];
  }

  st.site = &td_emlrtRSI;
  power(&st, b_firstStep, firstStepSquared);
  m = firstStep.size(0);
  b_firstStep.set_size((&wg_emlrtRTEI), sp, firstStep.size(0));
  for (i = 0; i < m; i++) {
    b_firstStep[i] = firstStep[i + firstStep.size(0)];
  }

  st.site = &td_emlrtRSI;
  power(&st, b_firstStep, r);
  if (firstStepSquared.size(0) != r.size(0)) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared.size(0), r.size(0), &j_emlrtECI,
      sp);
  }

  m = firstStepSquared.size(0);
  for (i = 0; i < m; i++) {
    firstStepSquared[i] = firstStepSquared[i] + r[i];
  }

  m = secondStep.size(0);
  b_firstStep.set_size((&xg_emlrtRTEI), sp, secondStep.size(0));
  for (i = 0; i < m; i++) {
    b_firstStep[i] = secondStep[i];
  }

  st.site = &ud_emlrtRSI;
  power(&st, b_firstStep, secondStepSquared);
  m = secondStep.size(0);
  b_firstStep.set_size((&yg_emlrtRTEI), sp, secondStep.size(0));
  for (i = 0; i < m; i++) {
    b_firstStep[i] = secondStep[i + secondStep.size(0)];
  }

  st.site = &ud_emlrtRSI;
  power(&st, b_firstStep, r);
  if (secondStepSquared.size(0) != r.size(0)) {
    emlrtSizeEqCheck1DR2012b(secondStepSquared.size(0), r.size(0), &k_emlrtECI,
      sp);
  }

  m = secondStepSquared.size(0);
  for (i = 0; i < m; i++) {
    secondStepSquared[i] = secondStepSquared[i] + r[i];
  }

  m = longStep.size(0);
  b_firstStep.set_size((&ah_emlrtRTEI), sp, longStep.size(0));
  for (i = 0; i < m; i++) {
    b_firstStep[i] = longStep[i];
  }

  st.site = &vd_emlrtRSI;
  power(&st, b_firstStep, longStepSquared);
  m = longStep.size(0);
  b_firstStep.set_size((&bh_emlrtRTEI), sp, longStep.size(0));
  for (i = 0; i < m; i++) {
    b_firstStep[i] = longStep[i + longStep.size(0)];
  }

  st.site = &vd_emlrtRSI;
  power(&st, b_firstStep, r);
  if (longStepSquared.size(0) != r.size(0)) {
    emlrtSizeEqCheck1DR2012b(longStepSquared.size(0), r.size(0), &l_emlrtECI, sp);
  }

  m = longStepSquared.size(0);
  for (i = 0; i < m; i++) {
    longStepSquared[i] = longStepSquared[i] + r[i];
  }

  if (firstStepSquared.size(0) != secondStepSquared.size(0)) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared.size(0), secondStepSquared.size(0),
      &m_emlrtECI, sp);
  }

  if (firstStepSquared.size(0) != longStepSquared.size(0)) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared.size(0), longStepSquared.size(0),
      &m_emlrtECI, sp);
  }

  if (firstStepSquared.size(0) != secondStepSquared.size(0)) {
    emlrtSizeEqCheck1DR2012b(firstStepSquared.size(0), secondStepSquared.size(0),
      &n_emlrtECI, sp);
  }

  st.site = &xd_emlrtRSI;
  longStepSquared.set_size((&ch_emlrtRTEI), (&st), firstStepSquared.size(0));
  m = firstStepSquared.size(0);
  for (i = 0; i < m; i++) {
    longStepSquared[i] = ((firstStepSquared[i] + secondStepSquared[i]) -
                          longStepSquared[i]) / 2.0;
  }

  b_st.site = &wd_emlrtRSI;
  m = firstStepSquared.size(0);
  for (i = 0; i < m; i++) {
    firstStepSquared[i] = firstStepSquared[i] * secondStepSquared[i];
  }

  overflow = false;
  i = firstStepSquared.size(0);
  for (k = 0; k < i; k++) {
    if (overflow || (firstStepSquared[k] < 0.0)) {
      overflow = true;
    }
  }

  if (overflow) {
    emlrtErrorWithMessageIdR2018a(&b_st, &qb_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  c_st.site = &ee_emlrtRSI;
  m = firstStepSquared.size(0);
  d_st.site = &fe_emlrtRSI;
  if ((1 <= firstStepSquared.size(0)) && (firstStepSquared.size(0) > 2147483646))
  {
    e_st.site = &nb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 0; k < m; k++) {
    firstStepSquared[k] = muDoubleScalarSqrt(firstStepSquared[k]);
  }

  varargin_1[0] = longStepSquared.size(0);
  varargin_1[1] = 1.0;
  varargin_2[0] = static_cast<uint32_T>(firstStepSquared.size(0));
  varargin_2[1] = 1U;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (static_cast<int32_T>(static_cast<uint32_T>(varargin_1[k])) !=
        static_cast<int32_T>(varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  overflow = p;
  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &pb_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  r1.set_size((&dh_emlrtRTEI), sp, longStepSquared.size(0));
  m = longStepSquared.size(0);
  for (i = 0; i < m; i++) {
    r1[i].re = longStepSquared[i] / firstStepSquared[i];
    r1[i].im = 0.0;
  }

  st.site = &yd_emlrtRSI;
  b_acos(&st, r1);
  cornerAngle.set_size((&eh_emlrtRTEI), sp, r1.size(0));
  m = r1.size(0);
  for (i = 0; i < m; i++) {
    cornerAngle[i] = r1[i].re;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void increaseSampling(const emlrtStack *sp, coder::array<real_T, 2U>
  &dataPoints, const coder::array<boolean_T, 1U> &segmentsToSplit, const coder::
  array<real_T, 2U> &sldProfile)
{
  int32_T end;
  int32_T i;
  int32_T trueCount;
  int32_T b_i;
  coder::array<real_T, 2U> newDataPoints;
  int32_T input_sizes_idx_0;
  coder::array<boolean_T, 1U> r;
  coder::array<boolean_T, 1U> r1;
  coder::array<int32_T, 1U> r2;
  coder::array<int32_T, 1U> r3;
  coder::array<int32_T, 1U> r4;
  coder::array<int32_T, 1U> r5;
  coder::array<real_T, 1U> r6;
  coder::array<real_T, 1U> r7;
  coder::array<real_T, 2U> b_dataPoints;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  //  increaseSampling increase the sampling of an input function
  end = segmentsToSplit.size(0);
  for (i = 0; i < end; i++) {
    if (segmentsToSplit[i]) {
      b_i = i + 1;
      if ((b_i < 1) || (b_i > segmentsToSplit.size(0))) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, segmentsToSplit.size(0),
          &jk_emlrtBCI, sp);
      }
    }
  }

  end = segmentsToSplit.size(0);
  trueCount = 0;
  for (i = 0; i < end; i++) {
    if (segmentsToSplit[i]) {
      trueCount++;
    }
  }

  newDataPoints.set_size((&yi_emlrtRTEI), sp, trueCount, 2);
  input_sizes_idx_0 = trueCount << 1;
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i] = 0.0;
  }

  r.set_size((&aj_emlrtRTEI), sp, (segmentsToSplit.size(0) + 1));
  input_sizes_idx_0 = segmentsToSplit.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r[b_i] = segmentsToSplit[b_i];
  }

  r[segmentsToSplit.size(0)] = false;
  end = r.size(0);
  for (i = 0; i < end; i++) {
    if (r[i]) {
      b_i = dataPoints.size(0);
      input_sizes_idx_0 = i + 1;
      if ((input_sizes_idx_0 < 1) || (input_sizes_idx_0 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(input_sizes_idx_0, 1, b_i, &kk_emlrtBCI,
          sp);
      }
    }
  }

  r1.set_size((&bj_emlrtRTEI), sp, (segmentsToSplit.size(0) + 1));
  r1[0] = false;
  input_sizes_idx_0 = segmentsToSplit.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r1[b_i + 1] = segmentsToSplit[b_i];
  }

  end = r1.size(0);
  for (i = 0; i < end; i++) {
    if (r1[i]) {
      b_i = dataPoints.size(0);
      input_sizes_idx_0 = i + 1;
      if ((input_sizes_idx_0 < 1) || (input_sizes_idx_0 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(input_sizes_idx_0, 1, b_i, &lk_emlrtBCI,
          sp);
      }
    }
  }

  end = r.size(0) - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r[i]) {
      input_sizes_idx_0++;
    }
  }

  r2.set_size((&cj_emlrtRTEI), sp, input_sizes_idx_0);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r[i]) {
      r2[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }

  end = r1.size(0) - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1[i]) {
      input_sizes_idx_0++;
    }
  }

  r3.set_size((&cj_emlrtRTEI), sp, input_sizes_idx_0);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1[i]) {
      r3[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }

  if (r2.size(0) != r3.size(0)) {
    emlrtSizeEqCheck1DR2012b(r2.size(0), r3.size(0), &u_emlrtECI, sp);
  }

  end = r.size(0) - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r[i]) {
      input_sizes_idx_0++;
    }
  }

  r4.set_size((&cj_emlrtRTEI), sp, input_sizes_idx_0);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r[i]) {
      r4[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }

  end = r1.size(0) - 1;
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1[i]) {
      input_sizes_idx_0++;
    }
  }

  r5.set_size((&cj_emlrtRTEI), sp, input_sizes_idx_0);
  input_sizes_idx_0 = 0;
  for (i = 0; i <= end; i++) {
    if (r1[i]) {
      r5[input_sizes_idx_0] = i + 1;
      input_sizes_idx_0++;
    }
  }

  r6.set_size((&dj_emlrtRTEI), sp, r4.size(0));
  input_sizes_idx_0 = r4.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    r6[b_i] = 0.5 * (dataPoints[r4[b_i] - 1] + dataPoints[r5[b_i] - 1]);
  }

  emlrtSubAssignSizeCheckR2012b(&trueCount, 1, r6.size(), 1, &v_emlrtECI, sp);
  input_sizes_idx_0 = r6.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i] = r6[b_i];
  }

  st.site = &je_emlrtRSI;

  //  Subfunctions
  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
  //  Modified by AVH for use with coder
  // if (~exist('vectorizable','var') || isempty(vectorizable))
  //  end
  // abs(nargout(func)); %for anonymous functions nargout<0
  r7.set_size((&ej_emlrtRTEI), (&st), newDataPoints.size(0));

  //  if vectorizable
  //    % For uniformity reasons, transform the 'x' array into a column vector.
  //    % In this way it does not matter if it is given as a column or a row
  //    % vector.
  //    [newValues{:}] = func(x(:));
  //    y = cell2mat(newValues);
  //  else
  b_i = newDataPoints.size(0) - 1;
  for (i = 0; i <= b_i; i++) {
    //  Remove cell array so no need for cell2mat
    //  which won't compile - AVH
    // [newValues{:}] = func(x(i));
    // y(i,:) = cell2mat(newValues);
    input_sizes_idx_0 = i + 1;
    if ((input_sizes_idx_0 < 1) || (input_sizes_idx_0 > newDataPoints.size(0)))
    {
      emlrtDynamicBoundsCheckR2012b(input_sizes_idx_0, 1, newDataPoints.size(0),
        &mk_emlrtBCI, &st);
    }

    b_st.site = &bd_emlrtRSI;
    sldFunc(&b_st, newDataPoints[input_sizes_idx_0 - 1], sldProfile, r6);
    if (1 != r6.size(0)) {
      emlrtSubAssignSizeCheck1dR2017a(1, r6.size(0), &h_emlrtECI, &st);
    }

    input_sizes_idx_0 = i + 1;
    if ((input_sizes_idx_0 < 1) || (input_sizes_idx_0 > r7.size(0))) {
      emlrtDynamicBoundsCheckR2012b(input_sizes_idx_0, 1, r7.size(0),
        &nk_emlrtBCI, &st);
    }

    r7[input_sizes_idx_0 - 1] = r6[0];
  }

  // end
  emlrtSubAssignSizeCheckR2012b(newDataPoints.size(), 1, r7.size(), 1,
    &w_emlrtECI, sp);
  input_sizes_idx_0 = r7.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    newDataPoints[b_i + newDataPoints.size(0)] = r7[b_i];
  }

  //  For simplicity append the new points at the end and then sort.
  st.site = &ke_emlrtRSI;
  if (newDataPoints.size(0) != 0) {
    input_sizes_idx_0 = newDataPoints.size(0);
  } else {
    input_sizes_idx_0 = 0;
  }

  if (dataPoints.size(0) != 0) {
    end = dataPoints.size(0);
  } else {
    end = 0;
  }

  b_dataPoints.set_size((&fj_emlrtRTEI), sp, (end + input_sizes_idx_0), 2);
  for (b_i = 0; b_i < end; b_i++) {
    b_dataPoints[b_i] = dataPoints[b_i];
  }

  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    b_dataPoints[b_i + end] = newDataPoints[b_i];
  }

  for (b_i = 0; b_i < end; b_i++) {
    b_dataPoints[b_i + b_dataPoints.size(0)] = dataPoints[b_i + dataPoints.size
      (0)];
  }

  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    b_dataPoints[(b_i + end) + b_dataPoints.size(0)] = newDataPoints[b_i +
      newDataPoints.size(0)];
  }

  dataPoints.set_size((&cj_emlrtRTEI), sp, b_dataPoints.size(0), 2);
  input_sizes_idx_0 = b_dataPoints.size(0);
  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    dataPoints[b_i] = b_dataPoints[b_i];
  }

  for (b_i = 0; b_i < input_sizes_idx_0; b_i++) {
    dataPoints[b_i + dataPoints.size(0)] = b_dataPoints[b_i + b_dataPoints.size
      (0)];
  }

  st.site = &ke_emlrtRSI;
  sortrows(&st, dataPoints);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void adaptive(const emlrtStack *sp, const coder::array<real_T, 2U> &sldProfile,
              const real_T startDomain[2], cell_19 *out)
{
  real_T d1;
  real_T y[50];
  int32_T k;
  real_T delta1;
  real_T delta2;
  int32_T i;
  coder::array<real_T, 1U> cornerAngle;
  coder::array<real_T, 2U> dataPoints;
  real_T b_y[100];
  real_T hiVal[50];
  real_T maxval[2];
  coder::array<real_T, 2U> b_dataPoints;
  coder::array<boolean_T, 1U> sharpCorners;
  coder::array<boolean_T, 1U> segmentsToSplit;
  coder::array<boolean_T, 1U> r;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  //  adaptive: evaluates a matlab function on a given range
  //
  //  'adaptive.m' allows to sample a function using a reduced number of
  //  points. It works iteratively adding new points where needed.
  //  It is especially useful for functions which are computationally intensive
  //  (e.g. involve solving a differential equation).
  //
  //  Usage:
  //  XY = adaptive(func, [xstart, xend])
  //   evaluates 'func' in the range [xstart, xend]. Key-value arguments are
  //   used to control the function evaluation. If the function 'func' returns
  //   multiple output values, only the first one is used for the refinement
  //   process, but all of them are calculated and returned as additional
  //   columns in the output matrix. The output matrix XY contains the new
  //   domain points in the first column and the output values in the other
  //   columns.
  //  [x,yy] = adaptive(func, [xstart, xend])
  //    as before but separately returns the array with the domain points and
  //    the array/matrix with the function output values.
  //  [x,yy] = adaptive(func, xarray, ...)
  //    as before but explicitly provide an initial array of domain points.
  //
  //  Methods:
  //    'adaptive' provides three methods for refining the function evaluation:
  //    1) add more points near the sharp corners, which are found by
  //     considering the triangles formed by three successive points and
  //     measuring the central angle.
  //    2) measure the area of the same triangles and add more points when the
  //     area is bigger than a threshold.
  //    3) measure the length of the segments formed by pairs of successive
  //     and split the segments which are longer than a threshold.
  //    If no methods is explicitly specified, the 'angle' method is used.
  //
  //  Input parameters
  //   - func: input function (function handle)
  //   - initialDomain: initial domain points (1D array)
  //
  //  Optional key-value input parameters
  //   - 'nPoints': (default 20)
  //        initial number of domain points, only used if an initial domain
  //        array is not excplitely provided.
  //   - 'maxRefinements': (default 10)
  //        Specifies the maximum number of refinement steps.
  //   - 'minAngle': (default 0.8*pi)
  //        Refine near the  points which forms, together with their left and right 
  //        neighbours, a triangle with central angle smaller than a given value. 
  //   - 'maxArea': (default 5e-4)
  //        Refine near the points which forms, together with their left and right 
  //        neighbours, a triangle with area larger than a threshold. The threshold 
  //        in normalized to the area enclosing th graph:
  //        threshold==maxArea*(max(x)-min(x))*(max(f(x))-min(f(x)))
  //   - 'maxLength': (default Inf)
  //        Refine all the sements which are longer than a given threshold. The
  //        threshold is relative to the input and output ranges. Specifically,
  //        before applying the threshold, the data are normalized so that
  //        max(x)-min(x)==1 and max(f(x))-min(f(x))==1.
  //   - 'minLength': (default 0)
  //        Exclude from the refinement process the segments which are shorter
  //        than a given threshold. The threshold is relative to the input and
  //        output ranges. Specifically, before applying the threshold, the
  //        data are normalized so that max(x)-min(x)==1 and max(f(x))-min(f(x))==1. 
  //   - 'minSignal': (default 0.2)
  //        Exclude from the refinement process the points where the function is 
  //        below a threshold. The threshold is relative to the output range: In 
  //        this example threshold == 0.01*(max(f(x))-min(f(x))).
  //   - 'vectorizable': (default false)
  //        Specifies whether the input function accepts arrays as input
  //        (e.g. f(x)==x.^2).
  //   - 'waitbar': (default false)
  //        Display a waitbar.
  //
  //  Output parameters
  //   - a NxM array where N is the number of domain points and M is the number
  //     of output parameters of the input function.
  //
  //
  //  Examples:
  //
  //    % Refine a function near sharp corners. The option 'minAngle' is useful
  //    % for having more points near the peaks of the function.
  //    f = @(x) exp(-x.^2/4).*sin(3*x);
  //    % for test-purpose also evaluate the function directly
  //    x2 = -10:0.01:10;
  //    y2 = f(x2);
  //    y = adaptive(f, [-5,5], 'minAngle',0.8*pi);
  //    figure(1); plot(x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('high sampling','adaptive')
  //    title('y = adaptive(f, [xstart, xend], ''minAngle'',0.8*pi)')
  //    % as before but starting with an inital array of domain points
  //    x = -5:5;
  //    y = adaptive(f, x, 'minAngle',0.8*pi);
  //    figure(2); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''minAngle'',0.8*pi)')
  //
  //    % Refine a function near sharp corners, but do not split segments which
  //    % are already shorter than 'minLength'.
  //    y = adaptive(f, x, 'minAngle',0.8*pi, 'minLength',0.05);
  //    figure(3); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''minAngle'',0.8*pi, ''minLength'',0.05)');
  //
  //    % Refine a function until the areas of the triangles formed by
  //    % triplets of successive points are smaller than 'maxArea'.
  //    y = adaptive(f, x, 'maxArea',1e-3);
  //    figure(4); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''maxArea'',1e-3)')
  //
  //    % Refine a function until the segments formed by pairs of successive
  //    % points are shorter than 'maxLength'.
  //    y = adaptive(f, x, 'maxLength',0.1);
  //    figure(5); plot(x,f(x),'s-',x2,f(x2),'k--',y(:,1),y(:,2),'o-');
  //    legend('initial sampling','high sampling','adaptive')
  //    title('y = adaptive(f, x, ''maxLength'',0.1)');
  //  Copyright
  //  2017, Alberto Comin -  LMU Muenchen
  //  Version changes:
  //
  //  24/01/2017: 1) new default: when no optional argument is given, use the
  //   'angle' method as default 2) it is now possible to provide just the
  //   start and the end of the function domain, instead of having to
  //   explicitly provide an initial array 3) a new key-word argument
  //   'nPoints' controls the number of initial domain points in the cases when
  //   the initial array is not explicitly provided. 4) it is now possible to
  //   return the domain points and the function values either as a single 2D
  //   array or as two separate arrays.
  //  25/01/2017: fixed defaults for the case when no method is specified
  //  Default settings
  //  units normalized to data range
  //  units normalized to data range
  //  units normalized to data range
  //  units normalized to data range
  //  Test-mode
  //  The test mode is activated by calling 'adaptive.m' with no input.
  //  if nargin==0
  //    initialDomain =  -10:10;
  //    input_func = @(x) 100*exp(-(x+5.2).^2) + 50*exp(-5*(x-0.5).^2)+ 20*exp(-10*(x-5.8).^2); 
  //    thresholdingAngles = true;
  //    minAngle = 0.8*pi;
  //    thresholdingLength = true;
  //    minLength = 0.02;
  //    disp('Running adaptive.m in test mode');
  //    fprintf('input function: %s\n',func2str(input_func));
  //    disp('Plotting the function on a initial set of points');
  //    testFigureHandle = figure();
  //    plot(initialDomain, input_func(initialDomain),'bs-','LineWidth',1.5);
  //    grid on; xlabel('x'); ylabel('y'); title('adaptive.m example');
  //  end
  //  Processing input arguments
  //  assert(isa(input_func,'function_handle'),'adaptiveFunctionEvaluation:ArgChk',... 
  //    'the first argument must be a function handle');
  //  assert(isnumeric(initialDomain) && isvector(initialDomain),...
  //    'adaptiveFunctionEvaluation:ArgChk','initial points must be specified as a numeric vector'); 
  //
  //  if mod(nExtraArgIn,2)==1
  //    error('adaptiveFunctionEvaluation:ArgChk', ...
  //      'At least a key or a value is missing in the key-value arguments list.'); 
  //  end
  //  while n < nExtraArgIn
  //    switch lower(varargin{n})
  //      case 'minangle'
  //      case 'maxarea'
  //        maxArea = varargin{n+1};
  //        thresholdingArea = true;
  //        usingDefaultMethod = false;
  //        n = n+2;
  //      case 'maxlength'
  //        maxLength = varargin{n+1};
  //        thresholdingLength = true;
  //        usingDefaultMethod = false;
  //        n = n+2;
  //      case 'minlength'
  //        minLength = varargin{n+1};
  //        thresholdingLength = true;
  //        n = n+2;
  //      case 'minsignal'
  //        minSignal = varargin{n+1};
  //        thresholdingSignal = true;
  //        n = n+2;
  //      case 'npoints'
  //        nPoints = varargin{n+1};
  //        n = n+2;
  //      case 'vectorize'
  //        vectorizable = varargin{n+1};
  //        n = n+2;
  //      case 'maxrefinements'
  //        maxRefinements = varargin{n+1};
  //        n = n+2;
  //      case 'waitbar'
  //        displayWaitbar = varargin{n+1};
  //        n = n+2;
  //      otherwise
  //        error('adaptiveFunctionEvaluation:ArgChk',...
  //          ['unknown keyword argument: ', varargin{n}]);
  //    end
  //  end
  //  if no method is specified use the 'angle' method as default
  //  Initial function evaluation
  //  if initialDomain only contains the start and the end points, create a new
  //  array with 'nPoints' points.
  d1 = startDomain[0];
  y[49] = startDomain[1];
  y[0] = startDomain[0];
  if (startDomain[0] == -startDomain[1]) {
    for (k = 0; k < 48; k++) {
      y[k + 1] = startDomain[1] * ((2.0 * (static_cast<real_T>(k) + 2.0) - 51.0)
        / 49.0);
    }
  } else if (((startDomain[0] < 0.0) != (startDomain[1] < 0.0)) &&
             ((muDoubleScalarAbs(startDomain[0]) > 8.9884656743115785E+307) ||
              (muDoubleScalarAbs(startDomain[1]) > 8.9884656743115785E+307))) {
    delta1 = startDomain[0] / 49.0;
    delta2 = startDomain[1] / 49.0;
    for (k = 0; k < 48; k++) {
      y[k + 1] = (d1 + delta2 * (static_cast<real_T>(k) + 1.0)) - delta1 * (
        static_cast<real_T>(k) + 1.0);
    }
  } else {
    delta1 = (startDomain[1] - startDomain[0]) / 49.0;
    for (k = 0; k < 48; k++) {
      y[k + 1] = d1 + (static_cast<real_T>(k) + 1.0) * delta1;
    }
  }

  //  Normalize the input function: This step allows to use the same syntax for
  //  functions with single or multiple output parameters.
  //  Remove this syntax for compile - AVH
  // func = @(x) normalizeFunction(x,sldProfile,vectorizable);
  //  Evaluate the input function on the initial set of points.
  st.site = &vc_emlrtRSI;

  //  Subfunctions
  //  NORMALIZEFUNCTION evaluates a function and returns a NxM array, where N
  //  is the number of elements of x and M is the number of outputs of func.
  //  All the outputs of func must be scalar.
  //  The optional parameter 'vectorizable' (default false) allows to specify
  //  that the input function can be vectorized.
  //  Modified by AVH for use with coder
  // if (~exist('vectorizable','var') || isempty(vectorizable))
  //  end
  // abs(nargout(func)); %for anonymous functions nargout<0
  //  if vectorizable
  //    % For uniformity reasons, transform the 'x' array into a column vector.
  //    % In this way it does not matter if it is given as a column or a row
  //    % vector.
  //    [newValues{:}] = func(x(:));
  //    y = cell2mat(newValues);
  //  else
  for (k = 0; k < 50; k++) {
    //  Remove cell array so no need for cell2mat
    //  which won't compile - AVH
    // [newValues{:}] = func(x(i));
    // y(i,:) = cell2mat(newValues);
    b_st.site = &bd_emlrtRSI;
    sldFunc(&b_st, y[k], sldProfile, cornerAngle);
    if (1 != cornerAngle.size(0)) {
      emlrtSubAssignSizeCheck1dR2017a(1, cornerAngle.size(0), &h_emlrtECI, &st);
    }

    hiVal[k] = cornerAngle[0];
  }

  // end
  // dataPoints = [initialDomain(:), func(initialDomain(:))];
  for (i = 0; i < 50; i++) {
    b_y[i] = y[i];
    b_y[i + 50] = hiVal[i];
  }

  dataPoints.set_size((&xf_emlrtRTEI), sp, 50, 2);
  for (i = 0; i < 100; i++) {
    dataPoints[i] = b_y[i];
  }

  //  Iterative function refinement
  //  if displayWaitbar
  //    refinementWaitbar = waitbar(0,['Evaluating function ',func2str(func)],... 
  //      'CreateCancelBtn','setappdata(gcbf,''canceling'',true)');
  //    setappdata(refinementWaitbar,'canceling',false)
  //  end
  for (int32_T nRefinements = 0; nRefinements < 10; nRefinements++) {
    boolean_T overflow;
    boolean_T exitg1;

    //  calculate the box which encloses the current data points:
    st.site = &wc_emlrtRSI;
    b_st.site = &mc_emlrtRSI;
    c_st.site = &nc_emlrtRSI;
    d_st.site = &oc_emlrtRSI;
    i = dataPoints.size(0);
    if (dataPoints.size(0) == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &mb_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility",
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (dataPoints.size(0) < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &nb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &jd_emlrtRSI;
    f_st.site = &kd_emlrtRSI;
    g_st.site = &ld_emlrtRSI;
    overflow = ((2 <= dataPoints.size(0)) && (dataPoints.size(0) > 2147483646));
    maxval[0] = dataPoints[0];
    h_st.site = &md_emlrtRSI;
    if (overflow) {
      i_st.site = &nb_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }

    for (k = 2; k <= i; k++) {
      d1 = dataPoints[k - 1];
      if ((!muDoubleScalarIsNaN(d1)) && (muDoubleScalarIsNaN(maxval[0]) ||
           (maxval[0] < d1))) {
        maxval[0] = d1;
      }
    }

    maxval[1] = dataPoints[dataPoints.size(0)];
    h_st.site = &md_emlrtRSI;
    for (k = 2; k <= i; k++) {
      d1 = dataPoints[(k + dataPoints.size(0)) - 1];
      if ((!muDoubleScalarIsNaN(d1)) && (muDoubleScalarIsNaN(maxval[1]) ||
           (maxval[1] < d1))) {
        maxval[1] = d1;
      }
    }

    st.site = &wc_emlrtRSI;
    b_st.site = &nd_emlrtRSI;
    c_st.site = &od_emlrtRSI;
    d_st.site = &pd_emlrtRSI;
    i = dataPoints.size(0);
    if (dataPoints.size(0) == 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &mb_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility",
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (dataPoints.size(0) < 1) {
      emlrtErrorWithMessageIdR2018a(&d_st, &nb_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero",
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    e_st.site = &jd_emlrtRSI;
    f_st.site = &kd_emlrtRSI;
    g_st.site = &ld_emlrtRSI;
    overflow = ((2 <= dataPoints.size(0)) && (dataPoints.size(0) > 2147483646));
    delta1 = dataPoints[0];
    h_st.site = &md_emlrtRSI;
    if (overflow) {
      i_st.site = &nb_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }

    for (k = 2; k <= i; k++) {
      d1 = dataPoints[k - 1];
      if ((!muDoubleScalarIsNaN(d1)) && (muDoubleScalarIsNaN(delta1) || (delta1 >
            d1))) {
        delta1 = d1;
      }
    }

    delta2 = dataPoints[dataPoints.size(0)];
    h_st.site = &md_emlrtRSI;
    for (k = 2; k <= i; k++) {
      d1 = dataPoints[(k + dataPoints.size(0)) - 1];
      if ((!muDoubleScalarIsNaN(d1)) && (muDoubleScalarIsNaN(delta2) || (delta2 >
            d1))) {
        delta2 = d1;
      }
    }

    //  Each point is considered as the central corner of the triangle formed
    //  with its left and right hand side neighbours. The first and the last
    //  points are not the central corner of any triangle, so for N points
    //  there are only N-2 triangles.
    k = dataPoints.size(0);
    if (!(static_cast<real_T>(dataPoints.size(0)) - 2.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(static_cast<real_T>(dataPoints.size(0)) - 2.0,
        &jb_emlrtDCI, sp);
    }

    b_dataPoints.set_size((&yf_emlrtRTEI), sp, dataPoints.size(0), 2);
    for (i = 0; i < k; i++) {
      b_dataPoints[i] = dataPoints[i];
    }

    maxval[0] -= delta1;
    for (i = 0; i < k; i++) {
      b_dataPoints[i + b_dataPoints.size(0)] = dataPoints[i + dataPoints.size(0)];
    }

    maxval[1] -= delta2;
    st.site = &xc_emlrtRSI;
    calculateCentralAngles(&st, b_dataPoints, maxval, cornerAngle);
    sharpCorners.set_size((&ag_emlrtRTEI), sp, cornerAngle.size(0));
    k = cornerAngle.size(0);
    for (i = 0; i < k; i++) {
      sharpCorners[i] = (cornerAngle[i] < 2.1991148575128552);
    }

    i = dataPoints.size(0) - 2;
    if (i != sharpCorners.size(0)) {
      emlrtSizeEqCheck1DR2012b(i, sharpCorners.size(0), &f_emlrtECI, sp);
    }

    sharpCorners.set_size((&bg_emlrtRTEI), sp, (dataPoints.size(0) - 2));

    //  For N points there are N-2 triangles and N-1 triangle sides. Each
    //  triangle side is a segment, which can be split or not depending on the
    //  refinement parameters.
    segmentsToSplit.set_size((&cg_emlrtRTEI), sp, (dataPoints.size(0) - 1));
    k = dataPoints.size(0) - 2;
    for (i = 0; i < k; i++) {
      segmentsToSplit[i] = sharpCorners[i];
    }

    segmentsToSplit[dataPoints.size(0) - 2] = false;
    r.set_size((&dg_emlrtRTEI), sp, (dataPoints.size(0) - 1));
    r[0] = false;
    k = dataPoints.size(0) - 2;
    for (i = 0; i < k; i++) {
      r[i + 1] = sharpCorners[i];
    }

    if (segmentsToSplit.size(0) != r.size(0)) {
      emlrtSizeEqCheck1DR2012b(segmentsToSplit.size(0), r.size(0), &g_emlrtECI,
        sp);
    }

    k = segmentsToSplit.size(0);
    for (i = 0; i < k; i++) {
      segmentsToSplit[i] = (segmentsToSplit[i] || r[i]);
    }

    st.site = &yc_emlrtRSI;
    b_st.site = &he_emlrtRSI;
    overflow = false;
    c_st.site = &ie_emlrtRSI;
    if (segmentsToSplit.size(0) > 2147483646) {
      d_st.site = &nb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    k = 1;
    exitg1 = false;
    while ((!exitg1) && (k <= segmentsToSplit.size(0))) {
      if (!segmentsToSplit[k - 1]) {
        k++;
      } else {
        overflow = true;
        exitg1 = true;
      }
    }

    if (overflow) {
      st.site = &ad_emlrtRSI;
      increaseSampling(&st, dataPoints, segmentsToSplit, sldProfile);

      //    else
      //      break;
    }

    //  Removed waitbar for compile - AVH
    //    if displayWaitbar
    //      if getappdata(refinementWaitbar,'canceling'), break; end
    //      waitbar(nRefinements/maxRefinements,refinementWaitbar);
    //    end
  }

  //  if displayWaitbar
  //    delete(refinementWaitbar);
  //  end
  //  Plotting refined function
  //  Removed for compile - AVH
  //  if nargin==0 % test mode
  //    figure(testFigureHandle);
  //    hold on;
  //    plot(dataPoints(:,1), dataPoints(:,2),'ro-');
  //    legend('initial', 'refiniment');
  //  end
  out->f1.set_size((&eg_emlrtRTEI), sp, dataPoints.size(0), 2);
  k = dataPoints.size(0) * dataPoints.size(1);
  for (i = 0; i < k; i++) {
    out->f1[i] = dataPoints[i];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (adaptive.cpp)
