//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_data.h
//
//  Code generation for function 'reflectivity_calculation_data'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t emlrtNestLockGlobal;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo v_emlrtRSI;
extern emlrtRSInfo w_emlrtRSI;
extern emlrtRSInfo jb_emlrtRSI;
extern emlrtRSInfo kb_emlrtRSI;
extern emlrtRSInfo lb_emlrtRSI;
extern emlrtRSInfo mb_emlrtRSI;
extern emlrtRSInfo nb_emlrtRSI;
extern emlrtRSInfo rb_emlrtRSI;
extern emlrtRSInfo sb_emlrtRSI;
extern emlrtRSInfo ac_emlrtRSI;
extern emlrtRSInfo bc_emlrtRSI;
extern emlrtRSInfo cc_emlrtRSI;
extern emlrtRSInfo dc_emlrtRSI;
extern emlrtRSInfo ec_emlrtRSI;
extern emlrtRSInfo fc_emlrtRSI;
extern emlrtRSInfo gc_emlrtRSI;
extern emlrtRSInfo hc_emlrtRSI;
extern emlrtRSInfo ic_emlrtRSI;
extern emlrtRSInfo jc_emlrtRSI;
extern emlrtRSInfo mc_emlrtRSI;
extern emlrtRSInfo nc_emlrtRSI;
extern emlrtRSInfo oc_emlrtRSI;
extern emlrtRSInfo qc_emlrtRSI;
extern emlrtRSInfo rc_emlrtRSI;
extern emlrtRSInfo sc_emlrtRSI;
extern emlrtRSInfo tc_emlrtRSI;
extern emlrtRSInfo fd_emlrtRSI;
extern emlrtRSInfo gd_emlrtRSI;
extern emlrtRSInfo hd_emlrtRSI;
extern emlrtRSInfo id_emlrtRSI;
extern emlrtRSInfo fe_emlrtRSI;
extern emlrtRSInfo le_emlrtRSI;
extern emlrtRSInfo we_emlrtRSI;
extern emlrtRSInfo xe_emlrtRSI;
extern emlrtRSInfo jf_emlrtRSI;
extern emlrtRSInfo kf_emlrtRSI;
extern emlrtRSInfo mf_emlrtRSI;
extern emlrtRSInfo nf_emlrtRSI;
extern emlrtRSInfo bg_emlrtRSI;
extern emlrtRSInfo cg_emlrtRSI;
extern emlrtRTEInfo hb_emlrtRTEI;
extern emlrtRTEInfo kb_emlrtRTEI;
extern emlrtRTEInfo ob_emlrtRTEI;
extern emlrtRTEInfo pb_emlrtRTEI;
extern emlrtRTEInfo tb_emlrtRTEI;
extern emlrtRTEInfo ub_emlrtRTEI;
extern emlrtRTEInfo gg_emlrtRTEI;
extern emlrtRTEInfo hg_emlrtRTEI;

#define MAX_THREADS                    omp_get_max_threads()

// End of code generation (reflectivity_calculation_data.h)
