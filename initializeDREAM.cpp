//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// initializeDREAM.cpp
//
// Code generation for function 'initializeDREAM'
//

// Include files
#include "initializeDREAM.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "boundaryHandling.h"
#include "calcDensity.h"
#include "drawCR.h"
#include "evaluateModel.h"
#include "rand.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void initializeDREAM(const struct12_T *DREAMPar, const ::coder::array<real_T,
                       2U> &paramInfo_min, const ::coder::array<real_T, 2U>
                       &paramInfo_max, const char_T
                       paramInfo_boundhandling_data[], const int32_T
                       paramInfo_boundhandling_size[2], ::coder::array<real_T,
                       3U> &chain, k_struct_T *output, ::coder::array<real_T, 2U>
                       &log_L, const f_struct_T *ratInputs_problemStruct, const
                       cell_11 *ratInputs_problemCells, const struct1_T
                       *ratInputs_problemLimits, const struct2_T
                       *ratInputs_controls, const ::coder::array<real_T, 2U>
                       &ratInputs_priors, ::coder::array<real_T, 2U> &X, ::coder::
                       array<real_T, 2U> &fx, ::coder::array<real_T, 2U> &CR,
                       real_T pCR_data[], int32_T pCR_size[2], real_T lCR_data[],
                       int32_T lCR_size[2], real_T delta_tot_data[], int32_T
                       delta_tot_size[2])
  {
    ::coder::array<real_T, 2U> b_X;
    ::coder::array<real_T, 2U> b_paramInfo_max;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    ::coder::array<real_T, 2U> x;
    ::coder::array<real_T, 1U> log_L_x;
    ::coder::array<real_T, 1U> log_PR_x;
    int32_T iv[2];
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T input_sizes_idx_1;
    int32_T loop_ub;
    int8_T b_input_sizes_idx_1;
    int8_T sizes_idx_1;
    boolean_T empty_non_axis_sizes;

    //  Initializes the starting positions of the Markov chains
    //  Create the initial positions of the chains
    //  switch paramInfo.prior
    //
    //      case {'uniform'}
    //  Random sampling
    coder::b_rand(DREAMPar->nChains, DREAMPar->nParams, b_X);
    b_paramInfo_max.set_size(1, paramInfo_max.size(1));
    loop_ub = paramInfo_max.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_paramInfo_max[i] = paramInfo_max[i] - paramInfo_min[i];
    }

    coder::repmat(b_paramInfo_max, DREAMPar->nChains, r);
    coder::repmat(paramInfo_min, DREAMPar->nChains, r1);

    //      case {'latin'}
    //          % Initialize chains with latinHypercubeSampling hypercube sampling
    //          if isfield(paramInfo,'min_initial') && isfield(paramInfo,'max_initial')
    //              [x] = latinHypercubeSampling(paramInfo.min_initial,paramInfo.max_initial,DREAMPar.nChains);
    //          else
    //              [x] = latinHypercubeSampling(paramInfo.min,paramInfo.max,DREAMPar.nChains);
    //          end
    //      case {'normal'}
    //
    //          % Initialize chains with (multi)-normal distribution
    //          [x] = repmat(paramInfo.mu,DREAMPar.nChains,1) + randn(DREAMPar.nChains,DREAMPar.nParams) * chol(paramInfo.cov);
    //
    //      case {'prior'}
    //
    //          % Create the initial position of each chain by drawing each parameter individually from the prior
    //          for qq = 1:DREAMPar.nParams
    //              for zz = 1:DREAMPar.nChains
    //                  x(zz,qq) = eval(char(paramInfo.prior_marginal(qq)));
    //              end
    //          end
    //
    //      otherwise
    //
    //          error('unknown initial sampling method');
    //  end
    //  If specified do boundary handling ( "Bound","Reflect","Fold")
    x.set_size(r1.size(0), r1.size(1));
    loop_ub = r1.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = r1.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        x[i1 + x.size(0) * i] = r1[i1 + r1.size(0) * i] + b_X[i1 + b_X.size(0) *
          i] * r[i1 + r.size(0) * i];
      }
    }

    boundaryHandling(x, paramInfo_min, paramInfo_max,
                     paramInfo_boundhandling_data, paramInfo_boundhandling_size);

    //  Now evaluate the model ( = pdf ) and return fx
    evaluateModel(x, DREAMPar, ratInputs_problemStruct, ratInputs_problemCells,
                  ratInputs_problemLimits, ratInputs_controls, fx);

    //  Calculate the log-likelihood and log-prior of x (fx)
    calcDensity(x, fx, DREAMPar, ratInputs_problemStruct->fitLimits,
                ratInputs_priors, log_L_x, log_PR_x);

    //  Define starting x values, corresponding density, log densty and simulations (Xfx)
    if ((x.size(0) != 0) && (x.size(1) != 0)) {
      b_loop_ub = x.size(0);
    } else if (log_PR_x.size(0) != 0) {
      b_loop_ub = log_PR_x.size(0);
    } else if (log_L_x.size(0) != 0) {
      b_loop_ub = log_L_x.size(0);
    } else {
      b_loop_ub = x.size(0);
    }

    empty_non_axis_sizes = (b_loop_ub == 0);
    if (empty_non_axis_sizes || ((x.size(0) != 0) && (x.size(1) != 0))) {
      input_sizes_idx_1 = x.size(1);
    } else {
      input_sizes_idx_1 = 0;
    }

    if (empty_non_axis_sizes || (log_PR_x.size(0) != 0)) {
      b_input_sizes_idx_1 = 1;
    } else {
      b_input_sizes_idx_1 = 0;
    }

    if (empty_non_axis_sizes || (log_L_x.size(0) != 0)) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }

    X.set_size(b_loop_ub, (input_sizes_idx_1 + b_input_sizes_idx_1) +
               sizes_idx_1);
    for (i = 0; i < input_sizes_idx_1; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        X[i1 + X.size(0) * i] = x[i1 + b_loop_ub * i];
      }
    }

    loop_ub = b_input_sizes_idx_1;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        X[i1 + X.size(0) * input_sizes_idx_1] = log_PR_x[i1];
      }
    }

    loop_ub = sizes_idx_1;
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        X[i1 + X.size(0) * (input_sizes_idx_1 + b_input_sizes_idx_1)] =
          log_L_x[i1];
      }
    }

    //  Store the model simulations (if appropriate)
    //  storeDREAMResults(DREAMPar,fx,Meas_info,'w+');
    //  Set the first point of each of the DREAMPar.nChains chain equal to the initial X values
    b_X.set_size(X.size(1), X.size(0));
    loop_ub = X.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = X.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_X[i1 + b_X.size(0) * i] = X[i + X.size(0) * i1];
      }
    }

    b_loop_ub = static_cast<int32_T>(DREAMPar->nParams + 2.0);
    loop_ub = static_cast<int32_T>(DREAMPar->nChains);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        chain[chain.size(0) * i1 + chain.size(0) * chain.size(1) * i] = b_X[i1 +
          b_loop_ub * i];
      }
    }

    //  Define selection probability of each crossover
    b_paramInfo_max.set_size(1, 3);
    pCR_size[0] = 1;
    pCR_size[1] = 3;
    b_paramInfo_max[0] = 0.33333333333333331;
    pCR_data[0] = 0.33333333333333331;
    b_paramInfo_max[1] = 0.33333333333333331;
    pCR_data[1] = 0.33333333333333331;
    b_paramInfo_max[2] = 0.33333333333333331;
    pCR_data[2] = 0.33333333333333331;

    //  Generate the actula CR value, lCR and delta_tot
    iv[0] = (*(int32_T (*)[2])b_paramInfo_max.size())[0];
    iv[1] = (*(int32_T (*)[2])b_paramInfo_max.size())[1];
    drawCR(DREAMPar, (const real_T *)b_paramInfo_max.data(), iv, CR);

    // coder.varsize('CR',[100 1e4],[1 1]);
    lCR_size[0] = 1;
    lCR_size[1] = 3;
    delta_tot_size[0] = 1;
    delta_tot_size[1] = 3;
    lCR_data[0] = 0.0;
    delta_tot_data[0] = 0.0;
    lCR_data[1] = 0.0;
    delta_tot_data[1] = 0.0;
    lCR_data[2] = 0.0;
    delta_tot_data[2] = 0.0;

    //  Save pCR values in memory
    output->CR[0] = DREAMPar->nChains;
    for (i = 0; i < 3; i++) {
      output->CR[output->CR.size(0) * (i + 1)] = 0.33333333333333331;
    }

    //  Save history log density of individual chains
    log_L[0] = DREAMPar->nChains;
    loop_ub = log_L_x.size(0);
    for (i = 0; i < loop_ub; i++) {
      log_L[log_L.size(0) * (i + 1)] = log_L_x[i];
    }

    //  Compute the R-statistic
    //  Calculates the R-statistic convergence diagnostic
    //  ----------------------------------------------------
    //  For more information please refer to: Gelman, A. and D.R. Rubin, 1992.
    //  Inference from Iterative Simulation Using Multiple chain,
    //  Statistical Science, Volume 7, Issue 4, 457-472.
    //
    //  Written by Jasper A. Vrugt
    //  Los Alamos, August 2007
    //  ----------------------------------------------------
    //  Compute the dimensions of chain
    //  Set the R-statistic to a large value
    output->R_stat[0] = DREAMPar->nChains;
    loop_ub = static_cast<int32_T>(DREAMPar->nParams);
    for (i = 0; i < loop_ub; i++) {
      output->R_stat[output->R_stat.size(0) * (i + 1)] = rtNaN;
    }
  }
}

// End of code generation (initializeDREAM.cpp)
