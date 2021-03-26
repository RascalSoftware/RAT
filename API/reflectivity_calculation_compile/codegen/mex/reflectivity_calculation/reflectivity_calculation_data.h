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
extern emlrtRSInfo y_emlrtRSI;
extern emlrtRSInfo ab_emlrtRSI;
extern emlrtRSInfo bb_emlrtRSI;
extern emlrtRSInfo cb_emlrtRSI;
extern emlrtRSInfo eb_emlrtRSI;
extern emlrtRSInfo fb_emlrtRSI;
extern emlrtRSInfo rb_emlrtRSI;
extern emlrtRSInfo sb_emlrtRSI;
extern emlrtRSInfo tb_emlrtRSI;
extern emlrtRSInfo ub_emlrtRSI;
extern emlrtRSInfo vb_emlrtRSI;
extern emlrtRSInfo ac_emlrtRSI;
extern emlrtRSInfo bc_emlrtRSI;
extern emlrtRSInfo ic_emlrtRSI;
extern emlrtRSInfo jc_emlrtRSI;
extern emlrtRSInfo kc_emlrtRSI;
extern emlrtRSInfo lc_emlrtRSI;
extern emlrtRSInfo mc_emlrtRSI;
extern emlrtRSInfo nc_emlrtRSI;
extern emlrtRSInfo oc_emlrtRSI;
extern emlrtRSInfo pc_emlrtRSI;
extern emlrtRSInfo qc_emlrtRSI;
extern emlrtRSInfo rc_emlrtRSI;
extern emlrtRSInfo uc_emlrtRSI;
extern emlrtRSInfo vc_emlrtRSI;
extern emlrtRSInfo wc_emlrtRSI;
extern emlrtRSInfo yc_emlrtRSI;
extern emlrtRSInfo ad_emlrtRSI;
extern emlrtRSInfo bd_emlrtRSI;
extern emlrtRSInfo cd_emlrtRSI;
extern emlrtRSInfo nd_emlrtRSI;
extern emlrtRSInfo od_emlrtRSI;
extern emlrtRSInfo pd_emlrtRSI;
extern emlrtRSInfo qd_emlrtRSI;
extern emlrtRSInfo ne_emlrtRSI;
extern emlrtRSInfo te_emlrtRSI;
extern emlrtRSInfo ff_emlrtRSI;
extern emlrtRSInfo gf_emlrtRSI;
extern emlrtRSInfo rf_emlrtRSI;
extern emlrtRSInfo sf_emlrtRSI;
extern emlrtRSInfo uf_emlrtRSI;
extern emlrtRSInfo vf_emlrtRSI;
extern emlrtRSInfo jg_emlrtRSI;
extern emlrtRSInfo kg_emlrtRSI;
extern emlrtRTEInfo ib_emlrtRTEI;
extern emlrtRTEInfo lb_emlrtRTEI;
extern emlrtRTEInfo pb_emlrtRTEI;
extern emlrtRTEInfo qb_emlrtRTEI;
extern emlrtRTEInfo ub_emlrtRTEI;
extern emlrtRTEInfo vb_emlrtRTEI;
extern emlrtRTEInfo eg_emlrtRTEI;
extern emlrtRTEInfo fg_emlrtRTEI;

#define MAX_THREADS                    omp_get_max_threads()

// End of code generation (reflectivity_calculation_data.h)
