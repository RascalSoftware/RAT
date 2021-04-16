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
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t emlrtNestLockGlobal;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo m_emlrtRSI;
extern emlrtRSInfo n_emlrtRSI;
extern emlrtRSInfo o_emlrtRSI;
extern emlrtRSInfo p_emlrtRSI;
extern emlrtRSInfo q_emlrtRSI;
extern emlrtRSInfo r_emlrtRSI;
extern emlrtRSInfo s_emlrtRSI;
extern emlrtRSInfo ab_emlrtRSI;
extern emlrtRSInfo bb_emlrtRSI;
extern emlrtRSInfo cb_emlrtRSI;
extern emlrtRSInfo db_emlrtRSI;
extern emlrtRSInfo fb_emlrtRSI;
extern emlrtRSInfo gb_emlrtRSI;
extern emlrtRSInfo hb_emlrtRSI;
extern emlrtRSInfo sb_emlrtRSI;
extern emlrtRSInfo tb_emlrtRSI;
extern emlrtRSInfo ub_emlrtRSI;
extern emlrtRSInfo vb_emlrtRSI;
extern emlrtRSInfo wb_emlrtRSI;
extern emlrtRSInfo bc_emlrtRSI;
extern emlrtRSInfo cc_emlrtRSI;
extern emlrtRSInfo jc_emlrtRSI;
extern emlrtRSInfo kc_emlrtRSI;
extern emlrtRSInfo lc_emlrtRSI;
extern emlrtRSInfo mc_emlrtRSI;
extern emlrtRSInfo nc_emlrtRSI;
extern emlrtRSInfo oc_emlrtRSI;
extern emlrtRSInfo pc_emlrtRSI;
extern emlrtRSInfo qc_emlrtRSI;
extern emlrtRSInfo rc_emlrtRSI;
extern emlrtRSInfo sc_emlrtRSI;
extern emlrtRSInfo vc_emlrtRSI;
extern emlrtRSInfo wc_emlrtRSI;
extern emlrtRSInfo xc_emlrtRSI;
extern emlrtRSInfo ad_emlrtRSI;
extern emlrtRSInfo bd_emlrtRSI;
extern emlrtRSInfo cd_emlrtRSI;
extern emlrtRSInfo dd_emlrtRSI;
extern emlrtRSInfo od_emlrtRSI;
extern emlrtRSInfo pd_emlrtRSI;
extern emlrtRSInfo qd_emlrtRSI;
extern emlrtRSInfo rd_emlrtRSI;
extern emlrtRSInfo oe_emlrtRSI;
extern emlrtRSInfo ue_emlrtRSI;
extern emlrtRSInfo gf_emlrtRSI;
extern emlrtRSInfo hf_emlrtRSI;
extern emlrtRSInfo sf_emlrtRSI;
extern emlrtRSInfo tf_emlrtRSI;
extern emlrtRSInfo vf_emlrtRSI;
extern emlrtRSInfo wf_emlrtRSI;
extern emlrtRSInfo kg_emlrtRSI;
extern emlrtRSInfo lg_emlrtRSI;
extern emlrtDCInfo rb_emlrtDCI;
extern emlrtBCInfo qe_emlrtBCI;
extern emlrtBCInfo re_emlrtBCI;
extern emlrtECInfo emlrtECI;
extern emlrtRTEInfo nb_emlrtRTEI;
extern emlrtRTEInfo rb_emlrtRTEI;
extern emlrtRTEInfo vb_emlrtRTEI;
extern emlrtRTEInfo wb_emlrtRTEI;
extern emlrtRTEInfo bc_emlrtRTEI;
extern emlrtRTEInfo cc_emlrtRTEI;
extern emlrtRTEInfo rg_emlrtRTEI;
extern emlrtRTEInfo sg_emlrtRTEI;
extern emlrtRTEInfo tg_emlrtRTEI;
extern emlrtRTEInfo ug_emlrtRTEI;
extern emlrtRTEInfo vg_emlrtRTEI;
extern emlrtRTEInfo wg_emlrtRTEI;
extern emlrtRTEInfo di_emlrtRTEI;
extern emlrtRTEInfo ei_emlrtRTEI;
extern emlrtRTEInfo bk_emlrtRTEI;
extern emlrtRTEInfo ck_emlrtRTEI;
extern emlrtRTEInfo dk_emlrtRTEI;
extern emlrtRTEInfo ek_emlrtRTEI;
extern emlrtRTEInfo fk_emlrtRTEI;
extern emlrtRTEInfo gk_emlrtRTEI;
extern emlrtRTEInfo hk_emlrtRTEI;
extern emlrtRTEInfo ik_emlrtRTEI;
extern emlrtRTEInfo jk_emlrtRTEI;
extern emlrtRTEInfo kk_emlrtRTEI;
extern emlrtRTEInfo lk_emlrtRTEI;
extern emlrtRTEInfo mk_emlrtRTEI;
extern emlrtRTEInfo nk_emlrtRTEI;
extern emlrtRTEInfo ok_emlrtRTEI;
extern emlrtRTEInfo pk_emlrtRTEI;
extern emlrtRTEInfo qk_emlrtRTEI;
extern emlrtRTEInfo rk_emlrtRTEI;
extern emlrtRTEInfo sk_emlrtRTEI;
extern emlrtRTEInfo tk_emlrtRTEI;
extern emlrtRTEInfo uk_emlrtRTEI;
extern emlrtRTEInfo vk_emlrtRTEI;
extern emlrtRTEInfo wk_emlrtRTEI;

#define MAX_THREADS                    omp_get_max_threads()

// End of code generation (reflectivity_calculation_data.h)
