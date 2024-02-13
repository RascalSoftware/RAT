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
#include "RATMain_data.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "adaptPCR.h"
#include "blockedSummation.h"
#include "calcDensity.h"
#include "calcProposal.h"
#include "combineVectorElements.h"
#include "drawCR.h"
#include "evaluateModel.h"
#include "fileManager.h"
#include "find.h"
#include "gelman.h"
#include "initializeDREAM.h"
#include "metropolisRule.h"
#include "mod.h"
#include "power.h"
#include "removeOutlier.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "setupDREAM.h"
#include "std.h"
#include "textProgressBar.h"
#include "tic.h"
#include "toc.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <cmath>
#include <stdio.h>

// Type Definitions
namespace RAT
{
  struct i_struct_T
  {
    char_T prior[7];
    ::coder::array<real_T, 2U> min;
    ::coder::array<real_T, 2U> max;
    ::coder::bounded_array<char_T, 10000U, 2U> boundhandling;
    boolean_T mvnpdf;
  };
}

// Function Definitions
namespace RAT
{
  void ratDREAM(real_T dreamVariables_d, real_T dreamVariables_N, real_T
                dreamVariables_T, real_T dreamVariables_lambda, real_T
                dreamVariables_pUnitGamma, boolean_T dreamVariables_adaptPCR,
                const ::coder::array<real_T, 2U> &Par_info_min, const ::coder::
                array<real_T, 2U> &Par_info_max, const char_T
                Par_info_boundhandling_data[], const int32_T
                Par_info_boundhandling_size[2], const d_struct_T
                *ratInputs_problemStruct, const cell_11 *ratInputs_problemCells,
                const struct2_T *ratInputs_controls, const ::coder::array<real_T,
                2U> &ratInputs_priors, ::coder::array<real_T, 3U> &chain,
                struct12_T *output, ::coder::array<real_T, 2U> &fx)
  {
    ::coder::array<real_T, 3U> b_chain;
    ::coder::array<real_T, 2U> CR;
    ::coder::array<real_T, 2U> Table_gamma;
    ::coder::array<real_T, 2U> X;
    ::coder::array<real_T, 2U> b_X;
    ::coder::array<real_T, 2U> b_r;
    ::coder::array<real_T, 2U> e_X;
    ::coder::array<real_T, 2U> fx_new;
    ::coder::array<real_T, 2U> log_L;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    ::coder::array<real_T, 2U> xnew;
    ::coder::array<real_T, 2U> xold;
    ::coder::array<real_T, 1U> c_X;
    ::coder::array<real_T, 1U> d_X;
    ::coder::array<real_T, 1U> delta_normX;
    ::coder::array<real_T, 1U> idx_ac;
    ::coder::array<real_T, 1U> log_L_xnew;
    ::coder::array<real_T, 1U> log_PR_xnew;
    ::coder::array<int32_T, 1U> r2;
    ::coder::array<boolean_T, 1U> CR_data;
    ::coder::array<boolean_T, 1U> accept;
    i_struct_T Par_info;
    struct13_T DREAMPar;
    struct14_T Meas_info;
    real_T tmp_data[100];
    real_T b_lCR_data[3];
    real_T delta_tot_data[3];
    real_T lCR_data[3];
    real_T pCR_data[3];
    real_T totaccept;
    int32_T delta_tot_size[2];
    int32_T lCR_size[2];
    int32_T pCR_size[2];
    int32_T gen;
    int32_T i;
    int32_T iteration;
    int32_T loop_ub;
    uint32_T iloc;
    boolean_T b_CR_data[100];

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
    //            [chain,output,fx,log_L] = DREAM(Func_name,DREAMPar,Par_info)                        %
    //            [chain,output,fx,log_L] = DREAM(Func_name,DREAMPar,Par_info,Meas_info)              %
    //                                                                                                %
    //  Input:    Func_name = name of the function ( = model ) that returns density of proposal       %
    //            DREAMPar = structure with algorithmic / computatinal settings of DREAM              %
    //            Par_info = structure with parameter ranges, prior distribution, boundary handling   %
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
    // if ~isfield(dreamVariables,'restart') || ~dreamVariables.restart
    //  Initialize the main variables used in DREAM
    Par_info.min.set_size(1, Par_info_min.size(1));
    loop_ub = Par_info_min.size(1);
    for (i = 0; i < loop_ub; i++) {
      Par_info.min[i] = Par_info_min[i];
    }

    Par_info.max.set_size(1, Par_info_max.size(1));
    loop_ub = Par_info_max.size(1);
    for (i = 0; i < loop_ub; i++) {
      Par_info.max[i] = Par_info_max[i];
    }

    Par_info.boundhandling.size[0] = 1;
    Par_info.boundhandling.size[1] = Par_info_boundhandling_size[1];
    loop_ub = Par_info_boundhandling_size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&Par_info_boundhandling_data[0],
                &Par_info_boundhandling_data[loop_ub],
                &Par_info.boundhandling.data[0]);
    }

    Meas_info.Y = 0.0;
    Meas_info.N = 0.0;
    setupDREAM(dreamVariables_d, dreamVariables_N, dreamVariables_T,
               dreamVariables_lambda, dreamVariables_pUnitGamma,
               dreamVariables_adaptPCR, &Meas_info, &DREAMPar, chain, output,
               log_L, Table_gamma);
    iloc = 1U;
    iteration = 1;
    gen = 1;

    //  Check for setup errors
    //  [stop,fid] = checkDREAM(DREAMPar,Par_info,Meas_info);
    //  Check for setup errors
    //  Assign stop to be No
    //  First close all files
    coder::fileManager();

    //  ----------------------REMOVE warning file - AVH
    //  open an output file with warnings
    // fid = fopen('warning_file.txt','w');
    // fprintf(fid,'-------------- DREAM warning file --------------\n');
    //  ------------------------------------------------
    //  Check number of chains
    //  Check parameter ranges
    //  % Check prior distribution
    //  if ( strcmp(lower(DREAMPar.prior),'yes') ) || ( strcmp(lower(Par_info),'prior') ),
    //      % Error -- if explicit prior is used --> marginals need to be defined
    //      if ~isfield(Par_info,'prior_marginal');
    //          evalstr = char('DREAM ERROR: Prior chosen but no marginal distribution specified to sample from -> Define Par_info.prior_marginal!!\n');
    //          % Now print warning to screen and to file
    //          fprintf(evalstr); fprintf(fid,evalstr);
    //          % Stop DREAM
    //          stop = true;
    //      end;
    //  end;
    //  Check whether we specified measurement sigma correctly
    //  if ( DREAMPar.lik == 12 || DREAMPar.lik == 13 ) && ( isfield(Meas_info,'Sigma') == 0 )
    //      % Error -- Meas_info.Sigma needs to be specified!!
    //      error('DREAM ERROR: Meas_info.Sigma needs to be specified either as inline function or one or multiple numerical values!!\n');
    //  end
    //  Check whether the length of the user specified sigma is correct
    //  Return to main program
    //    if stop; return; end
    //  Create computing environment (depending whether multi-core is used)
    //  Sets up sequential / parallel
    //  global DREAM_dir EXAMPLE_dir;
    //  Now create the function handle
    //  Currently using a function handle for RAT - AVH
    //  if isa(Func_name,'function_handle')
    //      f_handle = Func_name;
    //  else
    //      f_handle = eval(['@(x)',char(Func_name),'(x)']);
    //  end
    //  Now check if we want parallel execution of chains or not?
    //  We use 1 CPU (processor)
    DREAMPar.CPU = 1.0;

    //  Now print to screen all the settings
    //  Now check how the measurement sigma is arranged (estimated or defined)
    //
    //  -----------------------------------------
    //  We do not have user inputted sigma in this form for the RAT
    //  implementation - Measurement Error is dealt with downstream in the
    //  likelihood function. So, we can remove the check for sigma.
    //  --------------- AVH -------------------------
    // Meas_info = checkSigma(Meas_info);
    //  Create the initial states of each of the chains (initial population)
    initializeDREAM(&DREAMPar, Par_info.min, Par_info.max,
                    Par_info.boundhandling.data, Par_info.boundhandling.size,
                    chain, output, log_L, ratInputs_problemStruct,
                    ratInputs_problemCells, ratInputs_controls, ratInputs_priors,
                    X, fx, CR, pCR_data, pCR_size, lCR_data, lCR_size,
                    delta_tot_data, delta_tot_size);

    //  elseif DREAMPar.restart
    //
    //      % Print to screen restart run
    //      disp('Restart run');
    //      % If a restart run is being done: just load the output from the previous ongoing trial
    //      load DREAM.mat; [CR] = drawCR(DREAMPar,pCR); DREAMPar.T = 2 * DREAMPar.T;
    //      % And make sure we add zeros to "chain" array
    //      chain = [chain ; nan(size(chain,1)-1,size(chain,2),size(chain,3))];
    //      % Open warning file and set T_start
    //      fid = fopen('warning_file.txt','a+'); T_start = t + 1;
    // end
    //  Initialize waitbar.
    // fprintf('\n');
    lastNchar = 0.0;
    lastNchar_not_empty = true;

    //  h = waitbar(0,'Running DREAM - Please wait...');
    totaccept = 0.0;
    coder::tic();

    //  Now start iteration ...
    i = static_cast<int32_T>(DREAMPar.T + -1.0);
    for (int32_T t{0}; t < i; t++) {
      real_T j;
      int32_T b_loop_ub;
      int32_T i1;
      int32_T i2;
      int32_T input_sizes_idx_1;
      int32_T result;
      int32_T tmp_size;
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
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          xold[i2 + xold.size(0) * i1] = X[i2 + X.size(0) * i1];
        }
      }

      //  Now generate candidate in each sequence using current point and members of X
      b_loop_ub = CR.size(0);
      tmp_size = CR.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        tmp_data[i1] = CR[i1 + CR.size(0) * gen];
      }

      b_loop_ub = X.size(0);
      b_X.set_size(X.size(0), loop_ub);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_X[i2 + b_X.size(0) * i1] = X[i2 + X.size(0) * i1];
        }
      }

      calcProposal(b_X, tmp_data, &DREAMPar, Table_gamma, Par_info.min,
                   Par_info.max, Par_info.boundhandling.data,
                   Par_info.boundhandling.size, xnew);
      for (i1 = 0; i1 < tmp_size; i1++) {
        CR[i1 + CR.size(0) * gen] = tmp_data[i1];
      }

      //  Now evaluate the model ( = pdf ) and return fx
      evaluateModel(xnew, &DREAMPar, ratInputs_problemStruct,
                    ratInputs_problemCells, ratInputs_controls, fx_new);

      //  Calculate the log-likelihood and log-prior of x (fx)
      calcDensity(xnew, fx_new, &DREAMPar, ratInputs_problemStruct->fitLimits,
                  ratInputs_priors, log_L_xnew, log_PR_xnew);

      //  Calculate the Metropolis ratio
      tmp_size = X.size(1);
      loop_ub = X.size(0);
      c_X.set_size(X.size(0));
      d_X.set_size(X.size(0));
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_X[i1] = X[i1 + X.size(0) * (tmp_size - 1)];
        d_X[i1] = X[i1 + X.size(0) * (tmp_size - 2)];
      }

      metropolisRule(&DREAMPar, log_L_xnew, log_PR_xnew, c_X, d_X, accept,
                     idx_ac);

      //  And update X and the model simulation
      if (1.0 > DREAMPar.d) {
        loop_ub = 0;
      } else {
        loop_ub = static_cast<int32_T>(DREAMPar.d);
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
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = idx_ac.size(0);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_X[i2 + b_X.size(0) * i1] = xnew[(static_cast<int32_T>(idx_ac[i2]) +
            xnew.size(0) * i1) - 1];
        }
      }

      loop_ub = idx_ac.size(0);
      d_X.set_size(idx_ac.size(0));
      c_X.set_size(idx_ac.size(0));
      for (i1 = 0; i1 < loop_ub; i1++) {
        tmp_size = static_cast<int32_T>(idx_ac[i1]) - 1;
        d_X[i1] = log_PR_xnew[tmp_size];
        c_X[i1] = log_L_xnew[tmp_size];
      }

      for (i1 = 0; i1 < input_sizes_idx_1; i1++) {
        for (i2 = 0; i2 < result; i2++) {
          X[(static_cast<int32_T>(idx_ac[i2]) + X.size(0) * i1) - 1] = b_X[i2 +
            result * i1];
        }
      }

      loop_ub = b_input_sizes_idx_1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < result; i2++) {
          X[(static_cast<int32_T>(idx_ac[i2]) + X.size(0) * input_sizes_idx_1) -
            1] = d_X[i2];
        }
      }

      loop_ub = sizes_idx_1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < result; i2++) {
          X[(static_cast<int32_T>(idx_ac[i2]) + X.size(0) * (input_sizes_idx_1 +
              b_input_sizes_idx_1)) - 1] = c_X[i2];
        }
      }

      loop_ub = idx_ac.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        tmp_size = static_cast<int32_T>(idx_ac[i1]) - 1;
        fx[tmp_size] = fx_new[tmp_size];
      }

      //  Check whether to add the current points to the chains or not?
      if (coder::b_mod(static_cast<real_T>(t) + 2.0, 1.0) == 0.0) {
        //  Store the current sample in chain
        iloc++;
        loop_ub = X.size(0);
        e_X.set_size(X.size(1), X.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = X.size(1);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            e_X[i2 + e_X.size(0) * i1] = X[i1 + X.size(0) * i2];
          }
        }

        tmp_size = static_cast<int32_T>(DREAMPar.d + 2.0);
        loop_ub = static_cast<int32_T>(DREAMPar.N);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < tmp_size; i2++) {
            chain[((static_cast<int32_T>(iloc) + chain.size(0) * i2) +
                   chain.size(0) * chain.size(1) * i1) - 1] = e_X[i2 + tmp_size *
              i1];
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
        if (1.0 > DREAMPar.N) {
          loop_ub = 0;
        } else {
          loop_ub = static_cast<int32_T>(DREAMPar.N);
        }

        if (1.0 > DREAMPar.d) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = static_cast<int32_T>(DREAMPar.d);
        }

        e_X.set_size(loop_ub, b_loop_ub);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            e_X[i2 + e_X.size(0) * i1] = X[i2 + X.size(0) * i1];
          }
        }

        coder::b_std(e_X, r);
        coder::repmat(r, DREAMPar.N, b_r);

        //  Compute the Euclidean distance between new X and old X
        if (1 > xold.size(0)) {
          loop_ub = 0;
        } else {
          loop_ub = xold.size(0);
        }

        if (1.0 > DREAMPar.d) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = static_cast<int32_T>(DREAMPar.d);
        }

        for (i1 = 0; i1 < b_loop_ub; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            xold[i2 + loop_ub * i1] = (xold[i2 + xold.size(0) * i1] - X[i2 +
              X.size(0) * i1]) / b_r[i2 + b_r.size(0) * i1];
          }
        }

        xold.set_size(loop_ub, b_loop_ub);
        coder::b_power(xold, b_X);
        e_X.set_size(b_X.size(0), b_X.size(1));
        loop_ub = b_X.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = b_X.size(0);
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            e_X[i2 + e_X.size(0) * i1] = b_X[i2 + b_X.size(0) * i1];
          }
        }

        //  Use this information to update sum_p2 to update N_CR
        if (1.0 > DREAMPar.N) {
          loop_ub = 0;
        } else {
          loop_ub = static_cast<int32_T>(DREAMPar.N);
        }

        coder::blockedSummation(e_X, e_X.size(1), c_X);

        //  Calculate total normalized Euclidean distance for each crossover value
        //  Derive sum_p2 for each different CR value
        for (int32_T b_j{0}; b_j < 3; b_j++) {
          //  Find which chains are updated with j/DREAMPar.nCR
          //  Add the normalized squared distance tot the current delta_tot;
          j = (static_cast<real_T>(b_j) + 1.0) / 3.0;
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_CR_data[i1] = (CR[i1 + CR.size(0) * gen] == j);
          }

          CR_data.set(&b_CR_data[0], loop_ub);
          coder::eml_find(CR_data, r2);
          delta_normX.set_size(r2.size(0));
          b_loop_ub = r2.size(0);
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            delta_normX[i1] = c_X[r2[i1] - 1];
          }

          if (delta_normX.size(0) == 0) {
            j = 0.0;
          } else {
            j = coder::nestedIter(delta_normX, delta_normX.size(0));
          }

          delta_tot_data[b_j] += j;
        }
      }

      //  Update gen
      gen++;

      //  How many candidate points have been accepted -- to calculate acceptance rate
      totaccept += static_cast<real_T>(coder::c_combineVectorElements(accept));

      //  Update log_L
      if (1.0 > DREAMPar.N) {
        loop_ub = 0;
      } else {
        loop_ub = static_cast<int32_T>(DREAMPar.N);
      }

      j = (static_cast<real_T>(t) + 2.0) * DREAMPar.N;
      log_L[t + 1] = j;
      for (i1 = 0; i1 < loop_ub; i1++) {
        log_L[(t + log_L.size(0) * (i1 + 1)) + 1] = X[i1 + X.size(0) * (
          static_cast<int32_T>(DREAMPar.d + 2.0) - 1)];
      }

      //  Update the waitbar. TJP Edit to check for graphical enviro
      //  waitbar(t/DREAMPar.T,h);
      textProgressBar((static_cast<real_T>(t) + 2.0) / DREAMPar.T);

      //  If t equal to MCMC.steps then convergence checks and updates
      if (coder::b_mod(static_cast<real_T>(t) + 2.0, DREAMPar.steps) == 0.0) {
        int32_T start_idx;

        //  Save some important output -- Acceptance Rate
        output->AR.data[iteration] = j;
        output->AR.data[iteration + output->AR.size[0]] = 100.0 * totaccept /
          (DREAMPar.N * DREAMPar.steps);

        //  Check whether to update individual pCR values
        if (static_cast<real_T>(t) + 2.0 <= DREAMPar.T / 10.0) {
          if (DREAMPar.adaptPCR) {
            //  Update pCR values
            for (i1 = 0; i1 < 3; i1++) {
              b_lCR_data[i1] = lCR_data[i1];
            }

            adaptPCR(&DREAMPar, CR, delta_tot_data, b_lCR_data, pCR_data,
                     pCR_size, lCR_data, lCR_size);
          }
        } else {
          //  See whether there are any outlier chains, and remove them to current best value of X
          if (2.0 > DREAMPar.N + 1.0) {
            i1 = 0;
            i2 = 0;
          } else {
            i1 = 1;
            i2 = static_cast<int32_T>(DREAMPar.N + 1.0);
          }

          loop_ub = i2 - i1;
          e_X.set_size(t + 2, loop_ub);
          for (i2 = 0; i2 < loop_ub; i2++) {
            for (result = 0; result <= t + 1; result++) {
              e_X[result + e_X.size(0) * i2] = log_L[result + log_L.size(0) *
                (i1 + i2)];
            }
          }

          removeOutlier(X, e_X, output->outlier.data, output->outlier.size,
                        &DREAMPar, r1);
          output->outlier.size[0] = r1.size(0);
          output->outlier.size[1] = r1.size(1);
          loop_ub = r1.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r1.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              output->outlier.data[i2 + output->outlier.size[0] * i1] = r1[i2 +
                r1.size(0) * i1];
            }
          }

          i1 = !(2.0 > DREAMPar.N + 1.0);
          loop_ub = e_X.size(1);
          for (i2 = 0; i2 < loop_ub; i2++) {
            b_loop_ub = e_X.size(0);
            for (result = 0; result < b_loop_ub; result++) {
              log_L[result + log_L.size(0) * (i1 + i2)] = e_X[result + e_X.size
                (0) * i2];
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
          i1 = 0;
          i2 = 0;
        } else {
          i1 = start_idx - 1;
          i2 = static_cast<int32_T>(iloc);
        }

        if (1.0 > DREAMPar.d) {
          loop_ub = 0;
        } else {
          loop_ub = static_cast<int32_T>(DREAMPar.d);
        }

        if (1.0 > DREAMPar.N) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = static_cast<int32_T>(DREAMPar.N);
        }

        tmp_size = i2 - i1;
        b_chain.set_size(tmp_size, loop_ub, b_loop_ub);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          for (result = 0; result < loop_ub; result++) {
            for (input_sizes_idx_1 = 0; input_sizes_idx_1 < tmp_size;
                 input_sizes_idx_1++) {
              b_chain[(input_sizes_idx_1 + b_chain.size(0) * result) +
                b_chain.size(0) * b_chain.size(1) * i2] = chain[((i1 +
                input_sizes_idx_1) + chain.size(0) * result) + chain.size(0) *
                chain.size(1) * i2];
            }
          }
        }

        gelman(b_chain, &DREAMPar, r);
        output->R_stat[iteration] = j;
        loop_ub = r.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          output->R_stat[iteration + output->R_stat.size(0) * (i1 + 1)] = r[i1];
        }

        //  Update the iteration, set gen back to 1 and totaccept to zero
        iteration++;
        gen = 0;
        totaccept = 0.0;

        //  Save the output or not?
        //          if DREAMPar.save
        //
        //              % Store in memory
        //              save DREAM.mat
        //          end
      }
    }

    //  -------------------------------------------------------------------------
    //  Determine total run time
    output->RunTime = coder::toc();

    //  Variables have been pre-allocated --> need to remove zeros at end
    //  [chain,output,fx] = DREAMEnd(DREAMPar,Meas_info,chain,output,iteration,iloc);
    //  Place everything in output to do diagnostics later (outside C++)
    output->DREAMPar = DREAMPar;
    output->Meas_info = Meas_info;
    output->iteration = iteration + 1;
    output->iloc = iloc;

    //  Close the waitbar
    printf("\n");
    fflush(stdout);

    // close(h);
  }
}

// End of code generation (ratDREAM.cpp)
