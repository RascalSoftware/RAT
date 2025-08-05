//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// DREAM.cpp
//
// Code generation for function 'DREAM'
//

// Include files
#include "DREAM.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "adaptPCR.h"
#include "blockedSummation.h"
#include "calcLogLikelihood.h"
#include "calcLogPrior.h"
#include "calcProposal.h"
#include "combineVectorElements.h"
#include "drawCR.h"
#include "find.h"
#include "gelman.h"
#include "ifWhileCond.h"
#include "initializeDREAM.h"
#include "isRATStopped.h"
#include "metropolisRule.h"
#include "mod.h"
#include "removeOutlier.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "setupDREAM.h"
#include "sprintf.h"
#include "std.h"
#include "strcmp.h"
#include "strjoin.h"
#include "sum.h"
#include "tic.h"
#include "toc.h"
#include "triggerEvent.h"
#include "unsafeSxfun.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <cmath>

// Function Declarations
namespace RAT
{
  static void printParameters(const DreamParams &DREAMPar);
}

// Function Definitions
namespace RAT
{
  static void printParameters(const DreamParams &DREAMPar)
  {
    static const char b_cv[72]{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', ' ', 'S', 'u', 'm', 'm', 'a', 'r',
      'y', ' ', 'o', 'f', ' ', 't', 'h', 'e', ' ', 'm', 'a', 'i', 'n', ' ', 's',
      'e', 't', 't', 'i', 'n', 'g', 's', ' ', 'u', 's', 'e', 'd', ' ', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '\n' };

    static const char t34_f2[72]{ '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
      '-', '-', '\n' };

    static const char t15_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'n', 'P', 'a', 'r', 'a', 'm',
      's', ':', ' ' };

    static const char t16_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'n', 'C', 'h', 'a', 'i', 'n',
      's', ':', ' ' };

    static const char t17_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', 'n', 'G', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n',
      's', ':', ' ' };

    static const char t18_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'p', 'a', 'r', 'a', 'l', 'l', 'e',
      'l', ':', ' ' };

    static const char t19_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'P',
      'U', ':', ' ' };

    static const char t20_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', 'j', 'u', 'm', 'p', 'P', 'r', 'o', 'b', 'a', 'b', 'i', 'l', 'i', 't',
      'y', ':', ' ' };

    static const char t21_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', 'p', 'U', 'n', 'i', 't', 'G', 'a', 'm', 'm',
      'a', ':', ' ' };

    static const char t22_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'n', 'C',
      'R', ':', ' ' };

    static const char t23_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'd', 'e', 'l', 't',
      'a', ':', ' ' };

    static const char t24_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 's', 't', 'e', 'p',
      's', ':', ' ' };

    static const char t25_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'z', 'e', 't',
      'a', ':', ' ' };

    static const char t26_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', 'u', 't', 'l', 'i', 'e',
      'r', ':', ' ' };

    static const char t27_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'a', 'd', 'a', 'p', 't', 'P', 'C',
      'R', ':', ' ' };

    static const char t28_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', 'h', 'i', 'n', 'n', 'i', 'n',
      'g', ':', ' ' };

    static const char t29_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', 'B',
      'C', ':', ' ' };

    static const char t30_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'e', 'p', 's', 'i', 'l', 'o',
      'n', ':', ' ' };

    static const char t31_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'I',
      'O', ':', ' ' };

    static const char t32_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', 's', 't', 'o', 'r', 'e', 'O', 'u', 't', 'p', 'u',
      't', ':', ' ' };

    static const char t33_f2[27]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'R', ':', ' ' };

    static const char b_cv1[5]{ 'f', 'a', 'l', 's', 'e' };

    ::coder::array<char, 2U> ab_f1;
    ::coder::array<char, 2U> b_f1;
    ::coder::array<char, 2U> bb_f1;
    ::coder::array<char, 2U> c_f1;
    ::coder::array<char, 2U> cb_f1;
    ::coder::array<char, 2U> d_f1;
    ::coder::array<char, 2U> db_f1;
    ::coder::array<char, 2U> e_f1;
    ::coder::array<char, 2U> eb_f1;
    ::coder::array<char, 2U> f1;
    ::coder::array<char, 2U> f_f1;
    ::coder::array<char, 2U> fb_f1;
    ::coder::array<char, 2U> g_f1;
    ::coder::array<char, 2U> gb_f1;
    ::coder::array<char, 2U> h_f1;
    ::coder::array<char, 2U> hb_f1;
    ::coder::array<char, 2U> i_f1;
    ::coder::array<char, 2U> ib_f1;
    ::coder::array<char, 2U> j_f1;
    ::coder::array<char, 2U> jb_f1;
    ::coder::array<char, 2U> k_f1;
    ::coder::array<char, 2U> kb_f1;
    ::coder::array<char, 2U> l_f1;
    ::coder::array<char, 2U> lb_f1;
    ::coder::array<char, 2U> m_f1;
    ::coder::array<char, 2U> mb_f1;
    ::coder::array<char, 2U> n_f1;
    ::coder::array<char, 2U> nb_f1;
    ::coder::array<char, 2U> o_f1;
    ::coder::array<char, 2U> ob_f1;
    ::coder::array<char, 2U> p_f1;
    ::coder::array<char, 2U> q_f1;
    ::coder::array<char, 2U> r;
    ::coder::array<char, 2U> r_f1;
    ::coder::array<char, 2U> s_f1;
    ::coder::array<char, 2U> t15_f1;
    ::coder::array<char, 2U> t_f1;
    ::coder::array<char, 2U> u_f1;
    ::coder::array<char, 2U> v_f1;
    ::coder::array<char, 2U> w_f1;
    ::coder::array<char, 2U> x_f1;
    ::coder::array<char, 2U> y_f1;
    cell_wrap_10 bools[2];
    cell_wrap_10 rv[2];
    int i;

    //  Print the dream parameters
    t15_f1.set_size(1, 72);
    for (i = 0; i < 72; i++) {
      t15_f1[i] = b_cv[i];
    }

    f1.set_size(1, 5);
    for (i = 0; i < 5; i++) {
      f1[i] = b_cv1[i];
    }

    int iv[2];
    b_f1.set_size(1, 4);
    b_f1[0] = 't';
    b_f1[1] = 'r';
    b_f1[2] = 'u';
    b_f1[3] = 'e';
    bools[0].f1 = f1;
    bools[1].f1 = b_f1;
    c_f1.reserve(100);
    coder::strjoin(t15_f1, t15_f2, (char *)c_f1.data(), iv);
    (*(int (*)[2])c_f1.size())[0] = iv[0];
    (*(int (*)[2])c_f1.size())[1] = iv[1];
    coder::c_snPrint(DREAMPar.nParams, d_f1);
    rv[0].f1 = c_f1;
    rv[1].f1 = d_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t16_f2, e_f1);
    coder::c_snPrint(DREAMPar.nChains, f_f1);
    rv[0].f1 = e_f1;
    rv[1].f1 = f_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t17_f2, g_f1);
    coder::c_snPrint(DREAMPar.nGenerations, h_f1);
    rv[0].f1 = g_f1;
    rv[1].f1 = h_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t18_f2, i_f1);
    iv[0] = (*(int (*)[2])f1.size())[0];
    iv[1] = (*(int (*)[2])f1.size())[1];
    coder::e_sprintf((const char *)f1.data(), iv, j_f1);
    rv[0].f1 = i_f1;
    rv[1].f1 = j_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t19_f2, k_f1);
    coder::c_snPrint(1.0, l_f1);
    rv[0].f1 = k_f1;
    rv[1].f1 = l_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t20_f2, m_f1);
    coder::c_snPrint(DREAMPar.jumpProbability, n_f1);
    rv[0].f1 = m_f1;
    rv[1].f1 = n_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t21_f2, o_f1);
    coder::c_snPrint(DREAMPar.pUnitGamma, p_f1);
    rv[0].f1 = o_f1;
    rv[1].f1 = p_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t22_f2, q_f1);
    coder::c_snPrint(3.0, r_f1);
    rv[0].f1 = q_f1;
    rv[1].f1 = r_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t23_f2, s_f1);
    coder::c_snPrint(3.0, t_f1);
    rv[0].f1 = s_f1;
    rv[1].f1 = t_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t24_f2, u_f1);
    coder::c_snPrint(DREAMPar.steps, v_f1);
    rv[0].f1 = u_f1;
    rv[1].f1 = v_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t25_f2, w_f1);
    coder::c_snPrint(1.0E-12, x_f1);
    rv[0].f1 = w_f1;
    rv[1].f1 = x_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t26_f2, y_f1);
    coder::b_sprintf(DREAMPar.outlier, ab_f1);
    rv[0].f1 = y_f1;
    rv[1].f1 = ab_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t27_f2, bb_f1);
    iv[0] = (*(int (*)[2])bools[static_cast<int>(DREAMPar.adaptPCR)].f1.size())
      [0];
    iv[1] = (*(int (*)[2])bools[static_cast<int>(DREAMPar.adaptPCR)].f1.size())
      [1];
    coder::e_sprintf((const char *)bools[static_cast<int>(DREAMPar.adaptPCR)].
                     f1.data(), iv, cb_f1);
    rv[0].f1 = bb_f1;
    rv[1].f1 = cb_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t28_f2, db_f1);
    coder::c_snPrint(1.0, eb_f1);
    rv[0].f1 = db_f1;
    rv[1].f1 = eb_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t29_f2, fb_f1);
    iv[0] = (*(int (*)[2])f1.size())[0];
    iv[1] = (*(int (*)[2])f1.size())[1];
    coder::e_sprintf((const char *)f1.data(), iv, gb_f1);
    rv[0].f1 = fb_f1;
    rv[1].f1 = gb_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t30_f2, hb_f1);
    coder::c_snPrint(0.025, ib_f1);
    rv[0].f1 = hb_f1;
    rv[1].f1 = ib_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t31_f2, jb_f1);
    iv[0] = (*(int (*)[2])f1.size())[0];
    iv[1] = (*(int (*)[2])f1.size())[1];
    coder::e_sprintf((const char *)f1.data(), iv, kb_f1);
    rv[0].f1 = jb_f1;
    rv[1].f1 = kb_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t32_f2, lb_f1);
    iv[0] = (*(int (*)[2])f1.size())[0];
    iv[1] = (*(int (*)[2])f1.size())[1];
    coder::e_sprintf((const char *)f1.data(), iv, mb_f1);
    rv[0].f1 = lb_f1;
    rv[1].f1 = mb_f1;
    coder::strjoin(rv, r);
    coder::strjoin(r, t33_f2, nb_f1);
    i = DREAMPar.R.size(0) * DREAMPar.R.size(1);
    if (i != 1) {
      coder::snPrint(static_cast<double>(static_cast<short>(DREAMPar.R.size(0))),
                     static_cast<double>(static_cast<short>(DREAMPar.R.size(1))),
                     ob_f1);
      rv[0].f1 = nb_f1;
      rv[1].f1 = ob_f1;
      coder::strjoin(rv, t15_f1);
    } else {
      coder::c_snPrint(DREAMPar.R[0], ob_f1);
      rv[0].f1 = nb_f1;
      rv[1].f1 = ob_f1;
      coder::strjoin(rv, t15_f1);
    }

    coder::b_strjoin(t15_f1, t34_f2, r);
    triggerEvent(r);
  }

  void DREAM(double dreamVariables_nParams, double dreamVariables_nChains,
             double dreamVariables_nGenerations, double
             dreamVariables_jumpProbability, double dreamVariables_pUnitGamma,
             boolean_T dreamVariables_adaptPCR, const ::coder::array<double, 2U>
             &paramInfo_min, const ::coder::array<double, 2U> &paramInfo_max,
             const char paramInfo_boundhandling_data[], const int
             paramInfo_boundhandling_size[2], const ProblemDefinition &
             ratInputs_problemStruct, const Controls *ratInputs_controls, const ::
             coder::array<double, 2U> &ratInputs_priors, ::coder::array<double,
             3U> &chain, f_struct_T &output, ::coder::array<double, 2U> &log_L)
  {
    ::coder::array<double, 3U> b_chain;
    ::coder::array<double, 2U> CR;
    ::coder::array<double, 2U> Table_gamma;
    ::coder::array<double, 2U> X;
    ::coder::array<double, 2U> b_paramInfo_max;
    ::coder::array<double, 2U> b_paramInfo_min;
    ::coder::array<double, 2U> b_r;
    ::coder::array<double, 2U> b_xnew;
    ::coder::array<double, 2U> r1;
    ::coder::array<double, 2U> r2;
    ::coder::array<double, 2U> r3;
    ::coder::array<double, 2U> x;
    ::coder::array<double, 2U> xnew;
    ::coder::array<double, 2U> xold;
    ::coder::array<double, 1U> b_X;
    ::coder::array<double, 1U> b_delta_normX_data;
    ::coder::array<double, 1U> c_X;
    ::coder::array<double, 1U> idx_ac;
    ::coder::array<double, 1U> log_L_xnew;
    ::coder::array<double, 1U> log_PR_xnew;
    ::coder::array<int, 1U> r;
    ::coder::array<boolean_T, 1U> accept;
    ::coder::array<boolean_T, 1U> b_CR_data;
    ::coder::array<boolean_T, 1U> b_tmp_data;
    ::coder::bounded_array<char, 10000U, 2U> paramInfo_boundhandling;
    DreamParams DREAMPar;
    double delta_normX_data[100];
    double delta_tot_data[3];
    double lCR_data[3];
    double pCR_data[3];
    double totaccept;
    int delta_tot_size[2];
    int lCR_size[2];
    int pCR_size[2];
    int gen;
    int i;
    unsigned int iloc;
    int iteration;
    int loop_ub;
    int t;
    boolean_T CR_data[100];
    boolean_T b;
    boolean_T exitg1;
    boolean_T tmp_data;

    //  Original DREAM docstring:
    //  (this version is modified for RAT)
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
    //  Optimise a function using the Differential Evolution Adaptive Metropolis (DREAM) algorithm.
    //
    //  Parameters
    //  ----------
    //  dreamVariables : struct
    //      Algorithmic control information for DREAM.
    //  paramInfo : struct
    //      Ranges, priors and boundary handling for each parameter.
    //  ratInputs : struct
    //      Project and controls information from RAT.
    //
    //  Returns
    //  -------
    //  chain : array
    //      The MCMC chains generated by the algorithm, with log-prior and log-likelihood values.
    //  output : struct
    //      Diagnostic information such as convergence properties, acceptance rate, CR values, etc.
    //  log_L : array
    //      Matrix of log-likelihood values sampled from chains.
    //
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
    if (loop_ub - 1 >= 0) {
      std::copy(&paramInfo_boundhandling_data[0],
                &paramInfo_boundhandling_data[loop_ub],
                &paramInfo_boundhandling.data[0]);
    }

    setupDREAM(dreamVariables_nParams, dreamVariables_nChains,
               dreamVariables_nGenerations, dreamVariables_jumpProbability,
               dreamVariables_pUnitGamma, dreamVariables_adaptPCR, DREAMPar,
               chain, output, log_L, Table_gamma);
    iloc = 1U;
    iteration = 1;
    gen = 1;

    //  Create computing environment (depending whether multi-core is used)
    //  We use 1 CPU (processor)
    DREAMPar.CPU = 1.0;

    //  Now print to screen all the settings
    b = !coder::internal::d_strcmp(ratInputs_controls->display.data,
      ratInputs_controls->display.size);
    if (b) {
      printParameters(DREAMPar);
    }

    //  Create the initial states of each of the chains (initial population)
    initializeDREAM(DREAMPar, b_paramInfo_min, b_paramInfo_max,
                    paramInfo_boundhandling.data, paramInfo_boundhandling.size,
                    chain, output, log_L, ratInputs_problemStruct,
                    ratInputs_controls, ratInputs_priors, X, CR, pCR_data,
                    pCR_size, lCR_data, lCR_size, delta_tot_data, delta_tot_size);

    //  Initialize waitbar.
    triggerEvent(static_cast<double>(0.0));
    totaccept = 0.0;
    coder::tic();

    //  Now start iteration ...
    t = 0;
    exitg1 = false;
    while ((!exitg1) && (t <= static_cast<int>(DREAMPar.nGenerations - 1.0) - 1))
    {
      double varargin_1;
      int b_loop_ub;
      int i1;
      int input_sizes_idx_1;
      int loop_ub_tmp;
      int result;
      signed char b_input_sizes_idx_1;
      signed char sizes_idx_1;
      boolean_T b1;
      boolean_T empty_non_axis_sizes;

      //  Unoack current state of chain and associated log-likelihood and log-prior values
      if (X.size(1) - 2 < 1) {
        loop_ub = 0;
      } else {
        loop_ub = X.size(1) - 2;
      }

      xold.set_size(X.size(0), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = X.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          xold[i1 + xold.size(0) * i] = X[i1 + X.size(0) * i];
        }
      }

      //  Now generate candidate in each sequence using current point and members of X
      loop_ub = CR.size(0);
      for (i = 0; i < loop_ub; i++) {
        delta_normX_data[i] = CR[i + CR.size(0) * gen];
      }

      calcProposal(xold, delta_normX_data, DREAMPar, Table_gamma,
                   b_paramInfo_min, b_paramInfo_max,
                   paramInfo_boundhandling.data, paramInfo_boundhandling.size,
                   xnew);
      loop_ub = CR.size(0);
      for (i = 0; i < loop_ub; i++) {
        CR[i + CR.size(0) * gen] = delta_normX_data[i];
      }

      //  Now evaluate the model ( = pdf ) and return log-likelihood
      calcLogLikelihood(xnew, DREAMPar, ratInputs_problemStruct,
                        ratInputs_controls, log_L_xnew);

      //  Calculate log-prior
      b_xnew.set_size(xnew.size(0), xnew.size(1));
      loop_ub = xnew.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        b_loop_ub = xnew.size(0) - 1;
        for (i1 = 0; i1 <= b_loop_ub; i1++) {
          b_xnew[i1 + b_xnew.size(0) * i] = xnew[i1 + xnew.size(0) * i];
        }
      }

      calcLogPrior(b_xnew, ratInputs_priors, log_PR_xnew);

      //  Calculate the Metropolis ratio
      b_X.set_size(X.size(0));
      loop_ub = X.size(0);
      c_X.set_size(X.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_X[i] = X[i + X.size(0) * (X.size(1) - 1)];
        c_X[i] = X[i + X.size(0) * (X.size(1) - 2)];
      }

      metropolisRule(DREAMPar, log_L_xnew, log_PR_xnew, b_X, c_X, accept, idx_ac);

      //  And update X and the model simulation
      if (DREAMPar.nParams < 1.0) {
        loop_ub_tmp = 0;
      } else {
        loop_ub_tmp = static_cast<int>(DREAMPar.nParams);
      }

      r.set_size(idx_ac.size(0));
      loop_ub = idx_ac.size(0);
      for (i = 0; i < loop_ub; i++) {
        r[i] = static_cast<int>(idx_ac[i]) - 1;
      }

      b1 = ((idx_ac.size(0) != 0) && (loop_ub_tmp != 0));
      if (b1) {
        result = idx_ac.size(0);
      } else if (idx_ac.size(0) != 0) {
        result = idx_ac.size(0);
      } else {
        result = 0;
      }

      empty_non_axis_sizes = (result == 0);
      if (empty_non_axis_sizes || b1) {
        input_sizes_idx_1 = loop_ub_tmp;
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

      b_xnew.set_size(idx_ac.size(0), loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        loop_ub = idx_ac.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_xnew[i1 + b_xnew.size(0) * i] = xnew[(static_cast<int>(idx_ac[i1]) +
            xnew.size(0) * i) - 1];
        }
      }

      c_X.set_size(idx_ac.size(0));
      loop_ub = idx_ac.size(0);
      b_X.set_size(idx_ac.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = static_cast<int>(idx_ac[i]) - 1;
        c_X[i] = log_PR_xnew[b_loop_ub];
        b_X[i] = log_L_xnew[b_loop_ub];
      }

      i = input_sizes_idx_1 + b_input_sizes_idx_1;
      xnew.set_size(result, i + sizes_idx_1);
      for (i1 = 0; i1 < input_sizes_idx_1; i1++) {
        for (int i2{0}; i2 < result; i2++) {
          xnew[i2 + xnew.size(0) * i1] = b_xnew[i2 + result * i1];
        }
      }

      loop_ub = b_input_sizes_idx_1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (int i2{0}; i2 < result; i2++) {
          xnew[i2 + xnew.size(0) * input_sizes_idx_1] = c_X[i2];
        }
      }

      loop_ub = sizes_idx_1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (int i2{0}; i2 < result; i2++) {
          xnew[i2 + xnew.size(0) * i] = b_X[i2];
        }
      }

      b_loop_ub = r.size(0);
      result = static_cast<int>(DREAMPar.nParams + 2.0);
      for (i = 0; i < result; i++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          X[r[i1] + X.size(0) * i] = xnew[i1 + b_loop_ub * i];
        }
      }

      //  Check whether to add the current points to the chains or not?
      if (coder::b_mod(static_cast<double>(t) + 2.0, 1.0) == 0.0) {
        //  Store the current sample in chain
        iloc++;
        b_xnew.set_size(X.size(1), X.size(0));
        loop_ub = X.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = X.size(1);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            b_xnew[i1 + b_xnew.size(0) * i] = X[i + X.size(0) * i1];
          }
        }

        if (DREAMPar.nChains < 1.0) {
          loop_ub = 0;
        } else {
          loop_ub = static_cast<int>(DREAMPar.nChains);
        }

        for (i = 0; i < loop_ub; i++) {
          for (i1 = 0; i1 < result; i1++) {
            chain[((static_cast<int>(iloc) + chain.size(0) * i1) + chain.size(0)
                   * chain.size(1) * i) - 1] = b_xnew[i1 + result * i];
          }
        }
      }

      //  Check whether we update the crossover values
      if (DREAMPar.adaptPCR) {
        //  Calculate the standard deviation of each dimension of X
        if (DREAMPar.nChains < 1.0) {
          input_sizes_idx_1 = 0;
        } else {
          input_sizes_idx_1 = static_cast<int>(DREAMPar.nChains);
        }

        b_xnew.set_size(input_sizes_idx_1, loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          for (i1 = 0; i1 < input_sizes_idx_1; i1++) {
            b_xnew[i1 + b_xnew.size(0) * i] = X[i1 + X.size(0) * i];
          }
        }

        coder::b_std(b_xnew, r1);
        coder::repmat(r1, DREAMPar.nChains, b_r);

        //  Compute the Euclidean distance between new X and old X
        if (xold.size(0) < 1) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = xold.size(0);
        }

        if ((b_loop_ub == b_r.size(0)) && (loop_ub_tmp == b_r.size(1))) {
          x.set_size(b_loop_ub, loop_ub_tmp);
          for (i = 0; i < loop_ub_tmp; i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              varargin_1 = (xold[i1 + xold.size(0) * i] - X[i1 + X.size(0) * i])
                / b_r[i1 + b_r.size(0) * i];
              x[i1 + x.size(0) * i] = rt_powd_snf(varargin_1, 2.0);
            }
          }
        } else {
          binary_expand_op(x, xold, b_loop_ub - 1, loop_ub_tmp - 1, X, b_loop_ub
                           - 1, loop_ub_tmp - 1, b_r);
        }

        //  Use this information to update sum_p2 to update N_CR
        coder::blockedSummation(x, x.size(1), b_X);

        //  Calculate total normalised Euclidean distance for each crossover value.
        //
        //  Parameters
        //  ----------
        //  DREAMPar : struct
        //      Algorithmic control information for DREAM.
        //  delta_tot : array
        //      The initial normalised Euclidean distance for each crossover value.
        //  delta_normX : array
        //      The Euclidean distance between the new and old crossover value.
        //  CR : array
        //      The crossover values for each parameter.
        //
        //  Returns
        //  -------
        //  delta_tot : array
        //      The updated normalised Euclidean distance for each crossover value.
        //  Derive sum_p2 for each different CR value
        for (int j{0}; j < 3; j++) {
          //  Find which chains are updated with j/DREAMPar.nCR
          //  Add the normalized squared distance tot the current delta_tot;
          varargin_1 = (static_cast<double>(j) + 1.0) / 3.0;
          for (i = 0; i < input_sizes_idx_1; i++) {
            CR_data[i] = (CR[i + CR.size(0) * gen] == varargin_1);
          }

          b_CR_data.set(&CR_data[0], input_sizes_idx_1);
          coder::eml_find(b_CR_data, r);
          b_loop_ub = r.size(0);
          loop_ub = r.size(0);
          for (i = 0; i < loop_ub; i++) {
            delta_normX_data[i] = b_X[r[i] - 1];
          }

          b_delta_normX_data.set(&delta_normX_data[0], b_loop_ub);
          delta_tot_data[j] += coder::sum(b_delta_normX_data);
        }
      }

      //  Update gen
      gen++;

      //  How many candidate points have been accepted -- to calculate acceptance rate
      totaccept += static_cast<double>(coder::c_combineVectorElements(accept));

      //  Update log_L
      if (DREAMPar.nChains < 1.0) {
        input_sizes_idx_1 = 0;
      } else {
        input_sizes_idx_1 = static_cast<int>(DREAMPar.nChains);
      }

      varargin_1 = (static_cast<double>(t) + 2.0) * DREAMPar.nChains;
      log_L[t + 1] = varargin_1;
      for (i = 0; i < input_sizes_idx_1; i++) {
        log_L[(t + log_L.size(0) * (i + 1)) + 1] = X[i + X.size(0) * (result - 1)];
      }

      //  Update the waitbar. TJP Edit to check for graphical enviro
      //  waitbar(t/DREAMPar.nGenerations,h);
      b_triggerEvent((static_cast<double>(t) + 2.0) / DREAMPar.nGenerations);

      //  If t equal to MCMC.steps then convergence checks and updates
      if (coder::b_mod(static_cast<double>(t) + 2.0, DREAMPar.steps) == 0.0) {
        int start_idx;

        //  Save some important output -- Acceptance Rate
        output.AR.data[iteration] = varargin_1;
        output.AR.data[iteration + output.AR.size[0]] = 100.0 * totaccept /
          (DREAMPar.nChains * DREAMPar.steps);

        //  Check whether to update individual pCR values
        if (static_cast<double>(t) + 2.0 <= 0.1 * DREAMPar.nGenerations) {
          if (DREAMPar.adaptPCR) {
            double b_lCR_data[3];

            //  Update pCR values
            for (i = 0; i < 3; i++) {
              b_lCR_data[i] = lCR_data[i];
            }

            adaptPCR(DREAMPar, CR, delta_tot_data, b_lCR_data, pCR_data,
                     pCR_size, lCR_data, lCR_size);
          }
        } else {
          //  See whether there are any outlier chains, and remove them to current best value of X
          if (DREAMPar.nChains + 1.0 < 2.0) {
            i = 0;
            i1 = 0;
          } else {
            i = 1;
            i1 = static_cast<int>(DREAMPar.nChains + 1.0);
          }

          loop_ub = i1 - i;
          x.set_size(t + 2, loop_ub);
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (int i2{0}; i2 <= t + 1; i2++) {
              x[i2 + x.size(0) * i1] = log_L[i2 + log_L.size(0) * (i + i1)];
            }
          }

          removeOutlier(X, x, output.outlierChains.data,
                        output.outlierChains.size, DREAMPar, r2);
          output.outlierChains.size[0] = r2.size(0);
          output.outlierChains.size[1] = r2.size(1);
          loop_ub = r2.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_loop_ub = r2.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              output.outlierChains.data[i1 + output.outlierChains.size[0] * i] =
                r2[i1 + r2.size(0) * i];
            }
          }

          if (DREAMPar.nChains + 1.0 < 2.0) {
            i = 0;
            i1 = 0;
          } else {
            i = 1;
            i1 = static_cast<int>(DREAMPar.nChains + 1.0);
          }

          b_loop_ub = i1 - i;
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            loop_ub = t + 2;
            for (int i2{0}; i2 < loop_ub; i2++) {
              log_L[i2 + log_L.size(0) * (i + i1)] = x[i2 + (t + 2) * i1];
            }
          }
        }

        //  Store diagnostic information -- Probability of individual crossover values
        output.CR[iteration] = varargin_1;
        output.CR[iteration + output.CR.size(0)] = pCR_data[0];
        output.CR[iteration + output.CR.size(0) * 2] = pCR_data[1];
        output.CR[iteration + output.CR.size(0) * 3] = pCR_data[2];

        //  Generate new crossover values
        drawCR(DREAMPar, pCR_data, pCR_size, CR);

        //  Calculate Gelman and Rubin Convergence Diagnostic
        start_idx = static_cast<int>(std::fmax(1.0, std::floor(0.5 *
          static_cast<double>(iloc))));

        //  Compute the R-statistic using 50% burn-in from chain
        if (start_idx > static_cast<int>(iloc)) {
          i = 0;
          i1 = 0;
        } else {
          i = start_idx - 1;
          i1 = static_cast<int>(iloc);
        }

        loop_ub = i1 - i;
        b_chain.set_size(loop_ub, loop_ub_tmp, input_sizes_idx_1);
        for (i1 = 0; i1 < input_sizes_idx_1; i1++) {
          for (int i2{0}; i2 < loop_ub_tmp; i2++) {
            for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
              b_chain[(b_loop_ub + b_chain.size(0) * i2) + b_chain.size(0) *
                b_chain.size(1) * i1] = chain[((i + b_loop_ub) + chain.size(0) *
                i2) + chain.size(0) * chain.size(1) * i1];
            }
          }
        }

        gelman(b_chain, DREAMPar, r1);
        r3.set_size(1, r1.size(1) + 1);
        r3[0] = varargin_1;
        loop_ub = r1.size(1);
        for (i = 0; i < loop_ub; i++) {
          r3[i + 1] = r1[i];
        }

        loop_ub = static_cast<int>(DREAMPar.nParams + 1.0);
        for (i = 0; i < loop_ub; i++) {
          output.R_stat[iteration + output.R_stat.size(0) * i] = r3[i];
        }

        //  Update the iteration, set gen back to 1 and totaccept to zero
        iteration++;
        gen = 0;
        totaccept = 0.0;
      }

      b_loop_ub = isRATStopped(ratInputs_controls->IPCFilePath.data,
        ratInputs_controls->IPCFilePath.size, (boolean_T *)&tmp_data);
      b_tmp_data.set(&tmp_data, b_loop_ub);
      if (coder::internal::ifWhileCond(b_tmp_data)) {
        if (b) {
          h_triggerEvent();
        }

        exitg1 = true;
      } else {
        t++;
      }
    }

    //  -------------------------------------------------------------------------
    //  Determine total run time
    output.runtime = coder::toc();

    //  Place everything in output to do diagnostics later (outside C++)
    output.DREAMPar = DREAMPar;
    output.iteration = iteration + 1;
    output.iloc = iloc;

    //  Close the waitbar
    triggerEvent(1.0);

    // close(h);
  }
}

// End of code generation (DREAM.cpp)
