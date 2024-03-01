//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// calcDensity.cpp
//
// Code generation for function 'calcDensity'
//

// Include files
#include "calcDensity.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "scaledGaussPrior.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void calcDensity(const ::coder::array<real_T, 2U> &x, const ::coder::array<
                   real_T, 2U> &fx, const struct14_T *DREAMPar, const ::coder::
                   array<real_T, 2U> &ratInputs_problemStruct_fitLimits, const ::
                   coder::array<real_T, 2U> &ratInputs_priors, ::coder::array<
                   real_T, 1U> &log_L, ::coder::array<real_T, 1U> &log_PR)
  {
    ::coder::array<real_T, 2U> PR;
    ::coder::array<real_T, 2U> b_x;
    int32_T b_i;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T loop_ub_tmp;

    //  Now calculate the likelihood (not used) and log-likelihood (used)
    //  ---------------------------------------
    //  For RAT, all the calculations are of the mvnpdf type, so remove the
    //  other options.
    //  ------------------------------------ AVH
    //  % If number of measurements larger than 0 --> simulation
    //  if Meas_info.N > 0
    //
    //      % Initialize "res" (residual matrix)
    //      res = NaN(Meas_info.N,DREAMPar.N);
    //
    //      % Loop over each model realization
    //      for ii = 1 : DREAMPar.N
    //
    //          % We now calculate the error residual
    //          res(:,ii) = (Meas_info.Y(:) - fx(1:Meas_info.N,ii));
    //
    //      end
    //
    //  else
    //
    //      % Do nothing, fx is a density or log-density returned by the PDF handle
    //
    //  end
    //  ----------------------- Calculate log-prior  ----------------------------
    //  No ABC --> regular priors (pdfs)
    //  if ~DREAMPar.ABC
    //
    //      % Calculate the log-prior
    //      if isfield(Par_info,'prior_marginal')
    //
    //          % Compute prior densities for each parameter in each sequence
    //          for qq = 1 : DREAMPar.d
    //              for zz = 1 : DREAMPar.N
    //                  % Compute prior density of proposal
    //                  PR(zz,qq) = max ( eval(char(strrep(Par_info.prior_marginal(qq),'rnd(','pdf(x(zz,qq),'))) , 1e-299 );
    //              end
    //          end
    //
    //          % Take the log of the densities and their sum
    //          log_PR = sum ( log ( PR ) , 2 );
    //
    //      elseif isfield(Par_info,'mvnpdf')
    //  RAT specific prior funtion (mvnpdf)
    loop_ub_tmp = static_cast<int32_T>(DREAMPar->N);
    PR.set_size(1, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      PR[i] = 0.0;
    }

    if (0 <= loop_ub_tmp - 1) {
      i1 = x.size(1);
      loop_ub = x.size(1);
    }

    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      //  Loop over all the chains..
      b_x.set_size(1, i1);
      for (i = 0; i < loop_ub; i++) {
        b_x[i] = x[b_i + x.size(0) * i];
      }

      PR[b_i] = scaledGaussPrior(b_x, ratInputs_problemStruct_fitLimits,
        ratInputs_priors);

      //  mvnpdf automatically goes over all pars
    }

    //  Take log of any non-zero values..
    log_PR.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      log_PR[i] = 0.0;
    }

    i = PR.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      real_T d;
      d = PR[b_i];
      if (d != 0.0) {
        log_PR[b_i] = d;

        // log(PR(i));     % Does it even need to be log?
      } else {
        //  Otherwise keep the zero values
        log_PR[b_i] = 0.0;
      }
    }

    // log_PR = sum(log_PR(:));         % Enforce column vector
    //     else
    //          No use of prior --> set log-prior to zero (no effect in Metropolis)
    //          log_PR = zeros ( DREAMPar.N , 1 );
    //
    //      end
    //
    //
    //  else
    //
    //      Diagnostic Bayes --> if summary metric is defined as prior
    //      if isfield(DREAMPar,'prior_handle')
    //
    //          Evaluate distance between observed and simulated summary metrics
    //          for ii = 1 : DREAMPar.N
    //
    //              Calculate summary metrics for "fx"
    //              S_sim = DREAMPar.prior_handle ( fx(:,ii) );
    //
    //              Now calculate log-density (not a true log-density! - but does not matter)
    //              log_PR(ii,1) = max ( abs ( Meas_info.S(:) - S_sim(:) ) );
    //
    //          end
    //
    //      Regular ABC with summary metrics as likelihood function
    //      else
    //
    //          log_PR = zeros ( DREAMPar.N , 1 );
    //
    //      end
    //
    //  end
    //  --------------------- End Calculate log-prior ---------------------------
    //  -------------------- Calculate log-likelihood ---------------------------
    //  Loop over each model realization and calculate log-likelihood of each fx
    log_L.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      log_L[i] = 0.0;
    }

    for (int32_T ii{0}; ii < loop_ub_tmp; ii++) {
      log_L[ii] = fx[ii];
    }

    //  ------------------ End Calculate log-likelihood -------------------------
  }
}

// End of code generation (calcDensity.cpp)
