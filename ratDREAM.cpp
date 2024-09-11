//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// ratDREAM.cpp
//
// Code generation for function 'ratDREAM'
//

// Include files
#include "ratDREAM.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "adaptPCR.h"
#include "blockedSummation.h"
#include "calcDensity.h"
#include "calcProposal.h"
#include "combineVectorElements.h"
#include "drawCR.h"
#include "evaluateModel.h"
#include "find.h"
#include "gelman.h"
#include "ifWhileCond.h"
#include "initializeDREAM.h"
#include "isRATStopped.h"
#include "metropolisRule.h"
#include "mod.h"
#include "power.h"
#include "removeOutlier.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "setupDREAM.h"
#include "sprintf.h"
#include "std.h"
#include "strcmp.h"
#include "strjoin.h"
#include "tic.h"
#include "toc.h"
#include "triggerEvent.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <cmath>

// Function Declarations
namespace RAT
{
  static void printParameters(const struct11_T *DREAMPar);
}

// Function Definitions
namespace RAT
{
  static void printParameters(const struct11_T *DREAMPar)
  {
    static const char_T b_cv[72]{ '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', ' ', 'S', 'u', 'm', 'm', 'a',
      'r', 'y', ' ', 'o', 'f', ' ', 't', 'h', 'e', ' ', 'm', 'a', 'i', 'n', ' ',
      's', 'e', 't', 't', 'i', 'n', 'g', 's', ' ', 'u', 's', 'e', 'd', ' ', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '\x0a' };

    static const char_T t20_f2[72]{ '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '\x0a' };

    static const char_T t10_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 's', 't', 'e', 'p',
      's', ':', ' ' };

    static const char_T t11_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'z', 'e', 't',
      'a', ':', ' ' };

    static const char_T t12_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', 'u', 't', 'l', 'i', 'e',
      'r', ':', ' ' };

    static const char_T t13_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'a', 'd', 'a', 'p', 't', 'P', 'C',
      'R', ':', ' ' };

    static const char_T t14_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', 'h', 'i', 'n', 'n', 'i', 'n',
      'g', ':', ' ' };

    static const char_T t15_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', 'B',
      'C', ':', ' ' };

    static const char_T t16_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'e', 'p', 's', 'i', 'l', 'o',
      'n', ':', ' ' };

    static const char_T t17_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'I',
      'O', ':', ' ' };

    static const char_T t18_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', 's', 't', 'o', 'r', 'e', 'O', 'u', 't', 'p', 'u',
      't', ':', ' ' };

    static const char_T t19_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'R', ':', ' ' };

    static const char_T t1_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'n', 'P', 'a', 'r', 'a', 'm',
      's', ':', ' ' };

    static const char_T t2_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'n', 'C', 'h', 'a', 'i', 'n',
      's', ':', ' ' };

    static const char_T t3_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', 'n', 'G', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n',
      's', ':', ' ' };

    static const char_T t4_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'p', 'a', 'r', 'a', 'l', 'l', 'e',
      'l', ':', ' ' };

    static const char_T t5_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'P',
      'U', ':', ' ' };

    static const char_T t6_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', 'j', 'u', 'm', 'p', 'P', 'r', 'o', 'b', 'a', 'b', 'i', 'l', 'i', 't',
      'y', ':', ' ' };

    static const char_T t7_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', 'p', 'U', 'n', 'i', 't', 'G', 'a', 'm', 'm',
      'a', ':', ' ' };

    static const char_T t8_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'n', 'C',
      'R', ':', ' ' };

    static const char_T t9_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'd', 'e', 'l', 't',
      'a', ':', ' ' };

    static const char_T b_cv1[5]{ 'f', 'a', 'l', 's', 'e' };

    ::coder::array<char_T, 2U> ab_f1;
    ::coder::array<char_T, 2U> b_f1;
    ::coder::array<char_T, 2U> bb_f1;
    ::coder::array<char_T, 2U> c_f1;
    ::coder::array<char_T, 2U> cb_f1;
    ::coder::array<char_T, 2U> d_f1;
    ::coder::array<char_T, 2U> db_f1;
    ::coder::array<char_T, 2U> e_f1;
    ::coder::array<char_T, 2U> eb_f1;
    ::coder::array<char_T, 2U> f1;
    ::coder::array<char_T, 2U> f_f1;
    ::coder::array<char_T, 2U> fb_f1;
    ::coder::array<char_T, 2U> g_f1;
    ::coder::array<char_T, 2U> gb_f1;
    ::coder::array<char_T, 2U> h_f1;
    ::coder::array<char_T, 2U> hb_f1;
    ::coder::array<char_T, 2U> i_f1;
    ::coder::array<char_T, 2U> ib_f1;
    ::coder::array<char_T, 2U> j_f1;
    ::coder::array<char_T, 2U> jb_f1;
    ::coder::array<char_T, 2U> k_f1;
    ::coder::array<char_T, 2U> kb_f1;
    ::coder::array<char_T, 2U> l_f1;
    ::coder::array<char_T, 2U> lb_f1;
    ::coder::array<char_T, 2U> m_f1;
    ::coder::array<char_T, 2U> mb_f1;
    ::coder::array<char_T, 2U> n_f1;
    ::coder::array<char_T, 2U> nb_f1;
    ::coder::array<char_T, 2U> o_f1;
    ::coder::array<char_T, 2U> ob_f1;
    ::coder::array<char_T, 2U> p_f1;
    ::coder::array<char_T, 2U> q_f1;
    ::coder::array<char_T, 2U> r;
    ::coder::array<char_T, 2U> r_f1;
    ::coder::array<char_T, 2U> s_f1;
    ::coder::array<char_T, 2U> t1_f1;
    ::coder::array<char_T, 2U> t_f1;
    ::coder::array<char_T, 2U> u_f1;
    ::coder::array<char_T, 2U> v_f1;
    ::coder::array<char_T, 2U> w_f1;
    ::coder::array<char_T, 2U> x_f1;
    ::coder::array<char_T, 2U> y_f1;
    cell_wrap_1 bools[2];
    cell_wrap_1 rv[2];
    int32_T tmp_size[2];
    int32_T i;
    int32_T loop_ub;
    char_T tmp_data[100];
    char_T b_DREAMPar[4];

    //  Print the dream parameters
    t1_f1.set_size(1, 72);
    for (i = 0; i < 72; i++) {
      t1_f1[i] = b_cv[i];
    }

    f1.set_size(1, 5);
    for (i = 0; i < 5; i++) {
      f1[i] = b_cv1[i];
    }

    b_f1.set_size(1, 4);
    b_f1[0] = 't';
    b_f1[1] = 'r';
    b_f1[2] = 'u';
    b_f1[3] = 'e';
    bools[0].f1 = f1;
    bools[1].f1 = b_f1;
    coder::strjoin(t1_f1, t1_f2, tmp_data, tmp_size);
    c_f1.set_size(1, 100);
    for (i = 0; i < 100; i++) {
      c_f1[i] = tmp_data[i];
    }

    coder::c_snPrint(DREAMPar->nParams, d_f1);
    rv[0].f1 = c_f1;
    rv[1].f1 = d_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t2_f2, e_f1);
    coder::c_snPrint(DREAMPar->nChains, f_f1);
    rv[0].f1 = e_f1;
    rv[1].f1 = f_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t3_f2, g_f1);
    coder::c_snPrint(DREAMPar->nGenerations, h_f1);
    rv[0].f1 = g_f1;
    rv[1].f1 = h_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t4_f2, i_f1);
    t1_f1.set_size(1, 6);
    for (i = 0; i < 5; i++) {
      t1_f1[i] = f1[i];
    }

    t1_f1[5] = '\x00';
    tmp_size[0] = (*(int32_T (*)[2])t1_f1.size())[0];
    tmp_size[1] = (*(int32_T (*)[2])t1_f1.size())[1];
    coder::snPrint((const char_T *)t1_f1.data(), tmp_size, j_f1);
    rv[0].f1 = i_f1;
    rv[1].f1 = j_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t5_f2, k_f1);
    coder::c_snPrint(1.0, l_f1);
    rv[0].f1 = k_f1;
    rv[1].f1 = l_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t6_f2, m_f1);
    coder::c_snPrint(DREAMPar->jumpProbability, n_f1);
    rv[0].f1 = m_f1;
    rv[1].f1 = n_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t7_f2, o_f1);
    coder::c_snPrint(DREAMPar->pUnitGamma, p_f1);
    rv[0].f1 = o_f1;
    rv[1].f1 = p_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t8_f2, q_f1);
    coder::c_snPrint(3.0, r_f1);
    rv[0].f1 = q_f1;
    rv[1].f1 = r_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t9_f2, s_f1);
    coder::c_snPrint(3.0, t_f1);
    rv[0].f1 = s_f1;
    rv[1].f1 = t_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t10_f2, u_f1);
    coder::c_snPrint(DREAMPar->steps, v_f1);
    rv[0].f1 = u_f1;
    rv[1].f1 = v_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t11_f2, w_f1);
    coder::c_snPrint(1.0E-12, x_f1);
    rv[0].f1 = w_f1;
    rv[1].f1 = x_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t12_f2, y_f1);
    b_DREAMPar[0] = DREAMPar->outlier[0];
    b_DREAMPar[1] = DREAMPar->outlier[1];
    b_DREAMPar[2] = DREAMPar->outlier[2];
    b_DREAMPar[3] = '\x00';
    coder::snPrint(b_DREAMPar, ab_f1);
    rv[0].f1 = y_f1;
    rv[1].f1 = ab_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t13_f2, bb_f1);
    i = DREAMPar->adaptPCR;
    t1_f1.set_size(1, bools[i].f1.size(1) + 1);
    loop_ub = bools[i].f1.size(1);
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      t1_f1[i1] = bools[static_cast<int32_T>(DREAMPar->adaptPCR)].f1[i1];
    }

    t1_f1[bools[i].f1.size(1)] = '\x00';
    tmp_size[0] = (*(int32_T (*)[2])t1_f1.size())[0];
    tmp_size[1] = (*(int32_T (*)[2])t1_f1.size())[1];
    coder::snPrint((const char_T *)t1_f1.data(), tmp_size, cb_f1);
    rv[0].f1 = bb_f1;
    rv[1].f1 = cb_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t14_f2, db_f1);
    coder::c_snPrint(1.0, eb_f1);
    rv[0].f1 = db_f1;
    rv[1].f1 = eb_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t15_f2, fb_f1);
    t1_f1.set_size(1, 6);
    for (i = 0; i < 5; i++) {
      t1_f1[i] = f1[i];
    }

    t1_f1[5] = '\x00';
    tmp_size[0] = (*(int32_T (*)[2])t1_f1.size())[0];
    tmp_size[1] = (*(int32_T (*)[2])t1_f1.size())[1];
    coder::snPrint((const char_T *)t1_f1.data(), tmp_size, gb_f1);
    rv[0].f1 = fb_f1;
    rv[1].f1 = gb_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t16_f2, hb_f1);
    coder::c_snPrint(0.025, ib_f1);
    rv[0].f1 = hb_f1;
    rv[1].f1 = ib_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t17_f2, jb_f1);
    t1_f1.set_size(1, 6);
    for (i = 0; i < 5; i++) {
      t1_f1[i] = f1[i];
    }

    t1_f1[5] = '\x00';
    tmp_size[0] = (*(int32_T (*)[2])t1_f1.size())[0];
    tmp_size[1] = (*(int32_T (*)[2])t1_f1.size())[1];
    coder::snPrint((const char_T *)t1_f1.data(), tmp_size, kb_f1);
    rv[0].f1 = jb_f1;
    rv[1].f1 = kb_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t18_f2, lb_f1);
    t1_f1.set_size(1, 6);
    for (i = 0; i < 5; i++) {
      t1_f1[i] = f1[i];
    }

    t1_f1[5] = '\x00';
    tmp_size[0] = (*(int32_T (*)[2])t1_f1.size())[0];
    tmp_size[1] = (*(int32_T (*)[2])t1_f1.size())[1];
    coder::snPrint((const char_T *)t1_f1.data(), tmp_size, mb_f1);
    rv[0].f1 = lb_f1;
    rv[1].f1 = mb_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t19_f2, nb_f1);
    if (DREAMPar->R.size(0) * DREAMPar->R.size(1) != 1) {
      coder::snPrint(static_cast<real_T>(static_cast<int16_T>(DREAMPar->R.size(0))),
                     static_cast<real_T>(static_cast<int16_T>(DREAMPar->R.size(1))),
                     "double", ob_f1);
      rv[0].f1 = nb_f1;
      rv[1].f1 = ob_f1;
      coder::strjoin(rv, t1_f1);
    } else {
      coder::c_snPrint(DREAMPar->R[0], ob_f1);
      rv[0].f1 = nb_f1;
      rv[1].f1 = ob_f1;
      coder::strjoin(rv, t1_f1);
    }

    coder::b_strjoin(t1_f1, t20_f2, r);
    triggerEvent(r);
  }

  void ratDREAM(real_T dreamVariables_nParams, real_T dreamVariables_nChains,
                real_T dreamVariables_nGenerations, real_T
                dreamVariables_jumpProbability, real_T dreamVariables_pUnitGamma,
                boolean_T dreamVariables_adaptPCR, const ::coder::array<real_T,
                2U> &paramInfo_min, const ::coder::array<real_T, 2U>
                &paramInfo_max, const char_T paramInfo_boundhandling_data[],
                const int32_T paramInfo_boundhandling_size[2], const d_struct_T *
                ratInputs_problemStruct, const cell_13 *ratInputs_problemCells,
                const struct1_T *ratInputs_problemLimits, const struct2_T
                *ratInputs_controls, const ::coder::array<real_T, 2U>
                &ratInputs_priors, ::coder::array<real_T, 3U> &chain, l_struct_T
                *output, ::coder::array<real_T, 2U> &fx)
  {
    ::coder::array<real_T, 3U> b_chain;
    ::coder::array<real_T, 2U> CR;
    ::coder::array<real_T, 2U> Table_gamma;
    ::coder::array<real_T, 2U> X;
    ::coder::array<real_T, 2U> b_X;
    ::coder::array<real_T, 2U> b_paramInfo_max;
    ::coder::array<real_T, 2U> b_paramInfo_min;
    ::coder::array<real_T, 2U> b_r;
    ::coder::array<real_T, 2U> e_X;
    ::coder::array<real_T, 2U> fx_new;
    ::coder::array<real_T, 2U> log_L;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    ::coder::array<real_T, 2U> xnew;
    ::coder::array<real_T, 2U> xold;
    ::coder::array<real_T, 1U> b_delta_normX_data;
    ::coder::array<real_T, 1U> c_X;
    ::coder::array<real_T, 1U> d_X;
    ::coder::array<real_T, 1U> idx_ac;
    ::coder::array<real_T, 1U> log_L_xnew;
    ::coder::array<real_T, 1U> log_PR_xnew;
    ::coder::array<int32_T, 1U> r2;
    ::coder::array<boolean_T, 1U> CR_data;
    ::coder::array<boolean_T, 1U> accept;
    ::coder::bounded_array<char_T, 10000U, 2U> paramInfo_boundhandling;
    b_struct_T Meas_info;
    struct11_T DREAMPar;
    real_T delta_normX_data[100];
    real_T b_lCR_data[3];
    real_T delta_tot_data[3];
    real_T lCR_data[3];
    real_T pCR_data[3];
    real_T totaccept;
    int32_T delta_tot_size[2];
    int32_T lCR_size[2];
    int32_T pCR_size[2];
    int32_T delta_normX_size;
    int32_T gen;
    int32_T i;
    int32_T iteration;
    int32_T loop_ub;
    int32_T t;
    uint32_T iloc;
    boolean_T b_CR_data[100];
    boolean_T b;
    boolean_T exitg1;

    //  Modified version of Vrugt DREAm algorithm to be specific for RAT....
    //  ----------------------------------------------------------------------------------------------%
    //                                                                                                %
    //  DDDDDDDDDDDDDDD    RRRRRRRRRRRRRR     EEEEEEEEEEEEEEEE       AAAAA       MMM             MMM  %
    //  DDDDDDDDDDDDDDDD   RRRRRRRRRRRRRRR    EEEEEEEEEEEEEEEE       AAAAA       MMMM           MMMM  %
    //  DDD          DDD   RRR          RRR   EEE                   AAA AAA      MMMMM         MMMMM  %
    //  DDD          DDD   RRR          RRR   EEE                   AAA AAA      MMMMMM       MMMMMM  %
    //  DDD          DDD   RRR          RRR   EEE                  AAA   AAA     MMM MMM     MMM MMM  %
    //  DDD          DDD   RRR          RRR   EEE                  AAA   AAA     MMM  MMM   MMM  MMM  %
    //  DDD          DDD   RRRRRRRRRRRRRRR    EEEEEEEEEEEEEEEE    AAA     AAA    MMM   MMM MMM   MMM  %
    //  DDD          DDD   RRRRRRRRRRRRRR     EEEEEEEEEEEEEEEE    AAAAAAAAAAA    MMM    MMMM     MMM  %
    //  DDD          DDD   RRR          RR    EEE                AAA       AAA   MMM             MMM  %
    //  DDD          DDD   RRR          RRR   EEE                AAA       AAA   MMM             MMM  %
    //  DDD          DDD   RRR          RRR   EEE               AAA         AAA  MMM             MMM  %
    //  DDD          DDD   RRR          RRR   EEE               AAA         AAA  MMM             MMM  %
    //  DDDDDDDDDDDDDDDD   RRR          RRR   EEEEEEEEEEEEEEEE  AAA         AAA  MMM             MMM  %
    //  DDDDDDDDDDDDDDD    RRR          RRR   EEEEEEEEEEEEEEEE  AAA         AAA  MMM             MMM  %
    //                                                                                                %
    //  ----------------------------------------------------------------------------------------------%
    //  ----------------- DiffeRential Evolution Adaptive Metropolis algorithm -----------------------%
    //                                                                                                %
    //  DREAM runs multiple different chains simultaneously for global exploration, and automatically %
    //  tunes the scale and orientation of the proposal distribution using differential evolution.    %
    //  The algorithm maintains detailed balance and ergodicity and works well and efficient for a    %
    //  large range of problems, especially in the presence of high-dimensionality and                %
    //  multimodality.                                                                                %
    //                                                                                                %
    //  DREAM developed by Jasper A. Vrugt and Cajo ter Braak                                         %
    //                                                                                                %
    //  --------------------------------------------------------------------------------------------- %
    //                                                                                                %
    //  SYNOPSIS: [chain,output,fx,log_L] = DREAM(Func_name,DREAMPar)                                 %
    //            [chain,output,fx,log_L] = DREAM(Func_name,DREAMPar,paramInfo)                        %
    //            [chain,output,fx,log_L] = DREAM(Func_name,DREAMPar,paramInfo,Meas_info)              %
    //                                                                                                %
    //  Input:    Func_name = name of the function ( = model ) that returns density of proposal       %
    //            DREAMPar = structure with algorithmic / computatinal settings of DREAM              %
    //            paramInfo = structure with parameter ranges, prior distribution, boundary handling   %
    //            Meas_info = optional structure with measurements to be evaluated against            %
    //                                                                                                %
    //  Output:   chain = 3D array with chain trajectories, log-prior and log-likelihood values       %
    //            output = structure with convergence properties, acceptance rate, CR values, etc.    %
    //            fx = matrix with model simulations                                                  %
    //            log_L = matrix with log-likelihood values sampled chains                            %
    //                                                                                                %
    //  The directory \PostProcessing contains a script "PostProcMCMC" that will compute various      %
    //  posterior statistics (MEAN, STD, MAP, CORR) and create create various plots including,        %
    //  marginal posterior parameter distributions, R_stat convergence diagnostic, two-dimensional    %
    //  correlation plots of the posterior parameter samples, chain convergence plots, and parameter  %
    //  and total posterior simulation uncertainty ranges (interval can be specified)                 %
    //                                                                                                %
    //  --------------------------------------------------------------------------------------------- %
    //                                                                                                %
    //  This algorithm has been described in:                                                         %
    //                                                                                                %
    //    Vrugt, J.A., C.J.F. ter Braak, M.P. Clark, J.M. Hyman, and B.A. Robinson, Treatment of      %
    //       input uncertainty in hydrologic modeling: Doing hydrology backward with Markov chain     %
    //       Monte Carlo simulation, Water Resources Research, 44, W00B09, doi:10.1029/2007WR006720,  %
    //       2008.                                                                                    %
    //                                                                                                %
    //    Vrugt, J.A., C.J.F. ter Braak, C.G.H. Diks, D. Higdon, B.A. Robinson, and J.M. Hyman,       %
    //        Accelerating Markov chain Monte Carlo simulation by differential evolution with         %
    //        self-adaptive randomized subspace sampling, International Journal of Nonlinear          %
    //        Sciences and Numerical Simulation, 10(3), 271-288, 2009.                                %
    //                                                                                                %
    //    Vrugt, J.A., C.J.F. ter Braak, H.V. Gupta, and B.A. Robinson, Equifinality of formal        %
    //        (DREAM) and informal (GLUE) Bayesian approaches in hydrologic modeling?, Stochastic     %
    //        Environmental Research and Risk Assessment, 23(7), 1011-1026, 				            %
    //        doi:10.1007/s00477-008-0274-y, 2009                                                     %
    //                                                                                                %
    //    Laloy, E., and J.A. Vrugt, High-dimensional posterior exploration of hydrologic models      %
    //        using multiple-try DREAM_(ZS) and high-performance computing, Water Resources Research, %
    //        48, W01526, doi:10.1029/2011WR010608, 2012.                                             %
    //                                                                                                %
    //    Vrugt, J.A., and M. Sadegh, Toward diagnostic model calibration and evaluation:             %
    //        Approximate Bayesian computation, Water Resources Research, 49, 4335�4345,              %
    //        doi:10.1002/wrcr.20354, 2013.                                                           %
    //                                                                                                %
    //    Sadegh, M., and J.A. Vrugt, Approximate Bayesian computation using Markov chain Monte       %
    //        Carlo simulation: DREAM_(ABC), Water Resources Research, doi:10.1002/2014WR015386,      %
    //        2014.                                                                                   %
    //                                                                                                %
    //  For more information please read:                                                             %
    //                                                                                                %
    //    Ter Braak, C.J.F., A Markov Chain Monte Carlo version of the genetic algorithm Differential %
    //        Evolution: easy Bayesian computing for real parameter spaces, Stat. Comput., 16,        %
    //        239 - 249, doi:10.1007/s11222-006-8769-1, 2006.                                         %
    //                                                                                                %
    //    Vrugt, J.A., H.V. Gupta, W. Bouten and S. Sorooshian, A Shuffled Complex Evolution          %
    //        Metropolis algorithm for optimization and uncertainty assessment of hydrologic model    %
    //        parameters, Water Resour. Res., 39 (8), 1201, doi:10.1029/2002WR001642, 2003.           %
    //                                                                                                %
    //    Ter Braak, C.J.F., and J.A. Vrugt, Differential Evolution Markov Chain with snooker updater %
    //        and fewer chains, Statistics and Computing, 10.1007/s11222-008-9104-9, 2008.            %
    //                                                                                                %
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //                                                                                                %
    //      Copyright (C) 2011-2012  the authors                                                      %
    //                                                                                                %
    //      This program is free software: you can modify it under the terms of the GNU General       %
    //      Public License as published by the Free Software Foundation, either version 3 of the      %
    //      License, or (at your option) any later version.                                           %
    //                                                                                                %
    //      This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; %
    //      without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. %
    //      See the GNU General Public License for more details.                                      %
    //                                                                                                %
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //                                                                                                %
    //  MATLAB code written by Jasper A. Vrugt, University of California Irvine, jasper@uci.edu      	%
    //                                                                                                %
    //  Version 0.5: June 2008                                                                        %
    //  Version 1.0: October 2008       Adaption updated and generalized CR implementation            %
    //  Version 1.1: January 2010       Restart run and new AR-1 likelihood function with model error %
    //  Version 1.2: August 2010        Generalized likelihood function and prior distribution        %
    //  Version 1.3: September 2010     Explicit treatment of prior distribution                      %
    //  Version 1.4: October 2010       Limits of acceptability (GLUE) and few small changes          %
    //  Version 1.5: April 2011         Small maintenance updates -- 2 external executables           %
    //  Version 1.6: August 2011        whittle likelihood function (SPECTRAL ANALYSIS !!)            %
    //  Version 1.7: April 2012         Simplified code (removed variables) + graphical interface     %
    //  Version 1.8: May 2012           Added new option for Approximate Bayesian Computation         %
    //  Version 1.9: June 2012          Simulations stored, new example, and updated likelihood func. %
    //  Version 2.0: January 2013       Simplification of metrop.m and DREAM.m                        %
    //  Version 2.1: September 2013     Added inference of measurement error as new option            %
    //  Version 2.4: May 2014           Parallellization using parfor (done if CPU > 1)               %
    //                                                                                                %
    //  --------------------------------------------------------------------------------------------- %
    // ------ AVH -- Always will have consistent variable numbers -------
    //  Check how many input variables
    //  if nargin < 4, Meas_info.Y = []; end;
    //  if isempty(Meas_info), Meas_info.Y = []; end;
    //  ------------------------------------------------------------------------
    //  Initialize the main variables used in DREAM
    b_paramInfo_min.set_size(1, paramInfo_min.size(1));
    loop_ub = paramInfo_min.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_paramInfo_min[i] = paramInfo_min[i];
    }

    b_paramInfo_max.set_size(1, paramInfo_max.size(1));
    loop_ub = paramInfo_max.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_paramInfo_max[i] = paramInfo_max[i];
    }

    paramInfo_boundhandling.size[0] = 1;
    paramInfo_boundhandling.size[1] = paramInfo_boundhandling_size[1];
    loop_ub = paramInfo_boundhandling_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&paramInfo_boundhandling_data[0],
                &paramInfo_boundhandling_data[loop_ub],
                &paramInfo_boundhandling.data[0]);
    }

    Meas_info.Y = 0.0;
    Meas_info.N = 0.0;
    setupDREAM(dreamVariables_nParams, dreamVariables_nChains,
               dreamVariables_nGenerations, dreamVariables_jumpProbability,
               dreamVariables_pUnitGamma, dreamVariables_adaptPCR, &Meas_info,
               &DREAMPar, chain, output, log_L, Table_gamma);
    iloc = 1U;
    iteration = 1;
    gen = 1;

    //  Check for setup errors
    //  [stop,fid] = checkDREAM(DREAMPar,paramInfo,Meas_info);
    //  stop = checkDREAM(inDREAMPar,paramInfo,Meas_info);
    //  Return to main program
    //  if stop; return; end
    //  Create computing environment (depending whether multi-core is used)
    //  We use 1 CPU (processor)
    DREAMPar.CPU = 1.0;

    //  Now print to screen all the settings
    b = coder::internal::p_strcmp(ratInputs_controls->display.data,
      ratInputs_controls->display.size);
    if (!b) {
      printParameters(&DREAMPar);
    }

    //  Now check how the measurement sigma is arranged (estimated or defined)
    //
    //  -----------------------------------------
    //  We do not have user inputted sigma in this form for the RAT
    //  implementation - Measurement Error is dealt with downstream in the
    //  likelihood function. So, we can remove the check for sigma.
    //  --------------- AVH -------------------------
    // Meas_info = checkSigma(Meas_info);
    //  Create the initial states of each of the chains (initial population)
    initializeDREAM(&DREAMPar, b_paramInfo_min, b_paramInfo_max,
                    paramInfo_boundhandling.data, paramInfo_boundhandling.size,
                    chain, output, log_L, ratInputs_problemStruct,
                    ratInputs_problemCells, ratInputs_problemLimits,
                    ratInputs_controls, ratInputs_priors, X, fx, CR, pCR_data,
                    pCR_size, lCR_data, lCR_size, delta_tot_data, delta_tot_size);

    //  Initialize waitbar.
    triggerEvent(static_cast<real_T>(0.0));
    totaccept = 0.0;
    coder::tic();

    //  Now start iteration ...
    t = 0;
    exitg1 = false;
    while ((!exitg1) && (t <= static_cast<int32_T>(DREAMPar.nGenerations + -1.0)
                         - 1)) {
      real_T j;
      int32_T b_loop_ub;
      int32_T i1;
      int32_T input_sizes_idx_1;
      int32_T result;
      int8_T b_input_sizes_idx_1;
      int8_T sizes_idx_1;
      boolean_T empty_non_axis_sizes;

      //  Unoack current state of chain and associated log-likelihood and log-prior values
      if (1.0 > static_cast<real_T>(X.size(1)) - 2.0) {
        loop_ub = 0;
      } else {
        loop_ub = X.size(1) - 2;
      }

      b_loop_ub = X.size(0);
      xold.set_size(X.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          xold[i1 + xold.size(0) * i] = X[i1 + X.size(0) * i];
        }
      }

      //  Now generate candidate in each sequence using current point and members of X
      b_loop_ub = CR.size(0);
      delta_normX_size = CR.size(0);
      for (i = 0; i < b_loop_ub; i++) {
        delta_normX_data[i] = CR[i + CR.size(0) * gen];
      }

      b_loop_ub = X.size(0);
      b_X.set_size(X.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_X[i1 + b_X.size(0) * i] = X[i1 + X.size(0) * i];
        }
      }

      calcProposal(b_X, delta_normX_data, &DREAMPar, Table_gamma,
                   b_paramInfo_min, b_paramInfo_max,
                   paramInfo_boundhandling.data, paramInfo_boundhandling.size,
                   xnew);
      for (i = 0; i < delta_normX_size; i++) {
        CR[i + CR.size(0) * gen] = delta_normX_data[i];
      }

      //  Now evaluate the model ( = pdf ) and return fx
      evaluateModel(xnew, &DREAMPar, ratInputs_problemStruct,
                    ratInputs_problemCells, ratInputs_problemLimits,
                    ratInputs_controls, fx_new);

      //  Calculate the log-likelihood and log-prior of x (fx)
      calcDensity(xnew, fx_new, &DREAMPar, ratInputs_problemStruct->fitLimits,
                  ratInputs_priors, log_L_xnew, log_PR_xnew);

      //  Calculate the Metropolis ratio
      loop_ub = X.size(0);
      c_X.set_size(X.size(0));
      d_X.set_size(X.size(0));
      for (i = 0; i < loop_ub; i++) {
        c_X[i] = X[i + X.size(0) * (X.size(1) - 1)];
        d_X[i] = X[i + X.size(0) * (X.size(1) - 2)];
      }

      metropolisRule(&DREAMPar, log_L_xnew, log_PR_xnew, c_X, d_X, accept,
                     idx_ac);

      //  And update X and the model simulation
      if (1.0 > DREAMPar.nParams) {
        loop_ub = 0;
      } else {
        loop_ub = static_cast<int32_T>(DREAMPar.nParams);
      }

      if ((idx_ac.size(0) != 0) && (loop_ub != 0)) {
        result = idx_ac.size(0);
      } else if (idx_ac.size(0) != 0) {
        result = idx_ac.size(0);
      } else {
        result = 0;
      }

      empty_non_axis_sizes = (result == 0);
      if (empty_non_axis_sizes || ((idx_ac.size(0) != 0) && (loop_ub != 0))) {
        input_sizes_idx_1 = loop_ub;
      } else {
        input_sizes_idx_1 = 0;
      }

      if (empty_non_axis_sizes || (idx_ac.size(0) != 0)) {
        b_input_sizes_idx_1 = 1;
      } else {
        b_input_sizes_idx_1 = 0;
      }

      if (empty_non_axis_sizes || (idx_ac.size(0) != 0)) {
        sizes_idx_1 = 1;
      } else {
        sizes_idx_1 = 0;
      }

      b_X.set_size(idx_ac.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = idx_ac.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_X[i1 + b_X.size(0) * i] = xnew[(static_cast<int32_T>(idx_ac[i1]) +
            xnew.size(0) * i) - 1];
        }
      }

      d_X.set_size(idx_ac.size(0));
      loop_ub = idx_ac.size(0);
      c_X.set_size(idx_ac.size(0));
      for (i = 0; i < loop_ub; i++) {
        delta_normX_size = static_cast<int32_T>(idx_ac[i]) - 1;
        d_X[i] = log_PR_xnew[delta_normX_size];
        c_X[i] = log_L_xnew[delta_normX_size];
      }

      for (i = 0; i < input_sizes_idx_1; i++) {
        for (i1 = 0; i1 < result; i1++) {
          X[(static_cast<int32_T>(idx_ac[i1]) + X.size(0) * i) - 1] = b_X[i1 +
            result * i];
        }
      }

      loop_ub = b_input_sizes_idx_1;
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < result; i1++) {
          X[(static_cast<int32_T>(idx_ac[i1]) + X.size(0) * input_sizes_idx_1) -
            1] = d_X[i1];
        }
      }

      loop_ub = sizes_idx_1;
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < result; i1++) {
          X[(static_cast<int32_T>(idx_ac[i1]) + X.size(0) * (input_sizes_idx_1 +
              b_input_sizes_idx_1)) - 1] = c_X[i1];
        }
      }

      loop_ub = idx_ac.size(0);
      for (i = 0; i < loop_ub; i++) {
        delta_normX_size = static_cast<int32_T>(idx_ac[i]) - 1;
        fx[delta_normX_size] = fx_new[delta_normX_size];
      }

      //  Check whether to add the current points to the chains or not?
      if (coder::b_mod(static_cast<real_T>(t) + 2.0, 1.0) == 0.0) {
        //  Store the current sample in chain
        iloc++;
        e_X.set_size(X.size(1), X.size(0));
        loop_ub = X.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = X.size(1);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            e_X[i1 + e_X.size(0) * i] = X[i + X.size(0) * i1];
          }
        }

        delta_normX_size = static_cast<int32_T>(DREAMPar.nParams + 2.0);
        loop_ub = static_cast<int32_T>(DREAMPar.nChains);
        for (i = 0; i < loop_ub; i++) {
          for (i1 = 0; i1 < delta_normX_size; i1++) {
            chain[((static_cast<int32_T>(iloc) + chain.size(0) * i1) +
                   chain.size(0) * chain.size(1) * i) - 1] = e_X[i1 +
              delta_normX_size * i];
          }
        }

        //  kf added 16/10/2015
        //  store the distance between the simualted and observed signatures
        //  Store the model simulations (if appropriate)
        //  storeDREAMResults(DREAMPar,fx,Meas_info,'a+');
      }

      //  Check whether we update the crossover values
      if (DREAMPar.adaptPCR) {
        //  Calculate the standard deviation of each dimension of X
        if (1.0 > DREAMPar.nChains) {
          loop_ub = 0;
        } else {
          loop_ub = static_cast<int32_T>(DREAMPar.nChains);
        }

        if (1.0 > DREAMPar.nParams) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = static_cast<int32_T>(DREAMPar.nParams);
        }

        e_X.set_size(loop_ub, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            e_X[i1 + e_X.size(0) * i] = X[i1 + X.size(0) * i];
          }
        }

        coder::b_std(e_X, r);
        coder::repmat(r, DREAMPar.nChains, b_r);

        //  Compute the Euclidean distance between new X and old X
        if (1 > xold.size(0)) {
          loop_ub = 0;
        } else {
          loop_ub = xold.size(0);
        }

        if (1.0 > DREAMPar.nParams) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = static_cast<int32_T>(DREAMPar.nParams);
        }

        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            xold[i1 + loop_ub * i] = (xold[i1 + xold.size(0) * i] - X[i1 +
              X.size(0) * i]) / b_r[i1 + b_r.size(0) * i];
          }
        }

        xold.set_size(loop_ub, b_loop_ub);
        coder::b_power(xold, b_X);
        e_X.set_size(b_X.size(0), b_X.size(1));
        loop_ub = b_X.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = b_X.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            e_X[i1 + e_X.size(0) * i] = b_X[i1 + b_X.size(0) * i];
          }
        }

        //  Use this information to update sum_p2 to update N_CR
        if (1.0 > DREAMPar.nChains) {
          loop_ub = 0;
        } else {
          loop_ub = static_cast<int32_T>(DREAMPar.nChains);
        }

        coder::blockedSummation(e_X, e_X.size(1), c_X);

        //  Calculate total normalized Euclidean distance for each crossover value
        //  Derive sum_p2 for each different CR value
        for (int32_T b_j{0}; b_j < 3; b_j++) {
          //  Find which chains are updated with j/DREAMPar.nCR
          //  Add the normalized squared distance tot the current delta_tot;
          j = (static_cast<real_T>(b_j) + 1.0) / 3.0;
          for (i = 0; i < loop_ub; i++) {
            b_CR_data[i] = (CR[i + CR.size(0) * gen] == j);
          }

          CR_data.set(&b_CR_data[0], loop_ub);
          coder::eml_find(CR_data, r2);
          delta_normX_size = r2.size(0);
          b_loop_ub = r2.size(0);
          for (i = 0; i < b_loop_ub; i++) {
            delta_normX_data[i] = c_X[r2[i] - 1];
          }

          b_delta_normX_data.set(&delta_normX_data[0], delta_normX_size);
          if (b_delta_normX_data.size(0) == 0) {
            j = 0.0;
          } else {
            j = coder::nestedIter(b_delta_normX_data, b_delta_normX_data.size(0));
          }

          delta_tot_data[b_j] += j;
        }
      }

      //  Update gen
      gen++;

      //  How many candidate points have been accepted -- to calculate acceptance rate
      totaccept += static_cast<real_T>(coder::c_combineVectorElements(accept));

      //  Update log_L
      if (1.0 > DREAMPar.nChains) {
        loop_ub = 0;
      } else {
        loop_ub = static_cast<int32_T>(DREAMPar.nChains);
      }

      j = (static_cast<real_T>(t) + 2.0) * DREAMPar.nChains;
      log_L[t + 1] = j;
      for (i = 0; i < loop_ub; i++) {
        log_L[(t + log_L.size(0) * (i + 1)) + 1] = X[i + X.size(0) * (
          static_cast<int32_T>(DREAMPar.nParams + 2.0) - 1)];
      }

      //  Update the waitbar. TJP Edit to check for graphical enviro
      //  waitbar(t/DREAMPar.nGenerations,h);
      b_triggerEvent((static_cast<real_T>(t) + 2.0) / DREAMPar.nGenerations);

      //  If t equal to MCMC.steps then convergence checks and updates
      if (coder::b_mod(static_cast<real_T>(t) + 2.0, DREAMPar.steps) == 0.0) {
        int32_T start_idx;

        //  Save some important output -- Acceptance Rate
        output->AR.data[iteration] = j;
        output->AR.data[iteration + output->AR.size[0]] = 100.0 * totaccept /
          (DREAMPar.nChains * DREAMPar.steps);

        //  Check whether to update individual pCR values
        if (static_cast<real_T>(t) + 2.0 <= DREAMPar.nGenerations / 10.0) {
          if (DREAMPar.adaptPCR) {
            //  Update pCR values
            for (i = 0; i < 3; i++) {
              b_lCR_data[i] = lCR_data[i];
            }

            adaptPCR(&DREAMPar, CR, delta_tot_data, b_lCR_data, pCR_data,
                     pCR_size, lCR_data, lCR_size);
          }
        } else {
          //  See whether there are any outlier chains, and remove them to current best value of X
          if (2.0 > DREAMPar.nChains + 1.0) {
            i = 0;
            i1 = 0;
          } else {
            i = 1;
            i1 = static_cast<int32_T>(DREAMPar.nChains + 1.0);
          }

          loop_ub = i1 - i;
          e_X.set_size(t + 2, loop_ub);
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (result = 0; result <= t + 1; result++) {
              e_X[result + e_X.size(0) * i1] = log_L[result + log_L.size(0) * (i
                + i1)];
            }
          }

          removeOutlier(X, e_X, output->outlierChains.data,
                        output->outlierChains.size, &DREAMPar, r1);
          output->outlierChains.size[0] = r1.size(0);
          output->outlierChains.size[1] = r1.size(1);
          loop_ub = r1.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_loop_ub = r1.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              output->outlierChains.data[i1 + output->outlierChains.size[0] * i]
                = r1[i1 + r1.size(0) * i];
            }
          }

          i = !(2.0 > DREAMPar.nChains + 1.0);
          loop_ub = e_X.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = e_X.size(0);
            for (result = 0; result < b_loop_ub; result++) {
              log_L[result + log_L.size(0) * (i + i1)] = e_X[result + e_X.size(0)
                * i1];
            }
          }
        }

        //  Store diagnostic information -- Probability of individual crossover values
        output->CR[iteration] = j;
        output->CR[iteration + output->CR.size(0)] = pCR_data[0];
        output->CR[iteration + output->CR.size(0) * 2] = pCR_data[1];
        output->CR[iteration + output->CR.size(0) * 3] = pCR_data[2];

        //  Generate new crossover values
        drawCR(&DREAMPar, pCR_data, pCR_size, CR);

        //  Calculate Gelman and Rubin Convergence Diagnostic
        start_idx = static_cast<int32_T>(std::fmax(1.0, std::floor
          (static_cast<real_T>(iloc) / 2.0)));

        //  Compute the R-statistic using 50% burn-in from chain
        if (start_idx > static_cast<int32_T>(iloc)) {
          i = 0;
          i1 = 0;
        } else {
          i = start_idx - 1;
          i1 = static_cast<int32_T>(iloc);
        }

        if (1.0 > DREAMPar.nParams) {
          loop_ub = 0;
        } else {
          loop_ub = static_cast<int32_T>(DREAMPar.nParams);
        }

        if (1.0 > DREAMPar.nChains) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = static_cast<int32_T>(DREAMPar.nChains);
        }

        delta_normX_size = i1 - i;
        b_chain.set_size(delta_normX_size, loop_ub, b_loop_ub);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          for (result = 0; result < loop_ub; result++) {
            for (input_sizes_idx_1 = 0; input_sizes_idx_1 < delta_normX_size;
                 input_sizes_idx_1++) {
              b_chain[(input_sizes_idx_1 + b_chain.size(0) * result) +
                b_chain.size(0) * b_chain.size(1) * i1] = chain[((i +
                input_sizes_idx_1) + chain.size(0) * result) + chain.size(0) *
                chain.size(1) * i1];
            }
          }
        }

        gelman(b_chain, &DREAMPar, r);
        output->R_stat[iteration] = j;
        loop_ub = r.size(1);
        for (i = 0; i < loop_ub; i++) {
          output->R_stat[iteration + output->R_stat.size(0) * (i + 1)] = r[i];
        }

        //  Update the iteration, set gen back to 1 and totaccept to zero
        iteration++;
        gen = 0;
        totaccept = 0.0;
      }

      isRATStopped(ratInputs_controls->IPCFilePath.data,
                   ratInputs_controls->IPCFilePath.size, (boolean_T *)
                   &empty_non_axis_sizes, &delta_normX_size);
      if (coder::internal::ifWhileCond((const boolean_T *)&empty_non_axis_sizes,
           delta_normX_size)) {
        if (!b) {
          h_triggerEvent();
        }

        exitg1 = true;
      } else {
        t++;
      }
    }

    //  -------------------------------------------------------------------------
    //  Determine total run time
    output->runtime = coder::toc();

    //  Variables have been pre-allocated --> need to remove zeros at end
    //  [chain,output,fx] = DREAMEnd(DREAMPar,Meas_info,chain,output,iteration,iloc);
    //  Place everything in output to do diagnostics later (outside C++)
    output->DREAMPar = DREAMPar;
    output->Meas_info = Meas_info;
    output->iteration = iteration + 1;
    output->iloc = iloc;

    //  Close the waitbar
    triggerEvent(1.0);

    // close(h);
  }
}

// End of code generation (ratDREAM.cpp)
