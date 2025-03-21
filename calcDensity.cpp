//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  void calcDensity(const ::coder::array<double, 2U> &x, const ::coder::array<
                   double, 2U> &fx, const DreamParams &DREAMPar, const ::coder::
                   array<double, 2U> &ratInputs_problemStruct_fitLimits, const ::
                   coder::array<double, 2U> &ratInputs_priors, ::coder::array<
                   double, 1U> &log_L, ::coder::array<double, 1U> &log_PR)
  {
    ::coder::array<double, 2U> PR;
    ::coder::array<double, 2U> b_x;
    int i;
    int loop_ub;
    int loop_ub_tmp;

    //  Calculate the likelihood (not used) and log-likelihood (used) of a point.
    //
    //  Parameters
    //  ----------
    //  x : vector
    //      The point in parameter space to evaluate.
    //  fx : vector
    //      The likelihood and log-likelihood for each chain.
    //  DREAMPar : struct
    //      The algorithmic control settings for DREAM.
    //  paramInfo : struct
    //      Ranges, priors and boundary handling for each parameter.
    //  Meas_info : struct, optional
    //      Struct with measurements to evaluate against.
    //  ratInputs : struct
    //      Project and controls information from RAT.
    //
    //  Returns
    //  -------
    //  log_L : array
    //      The log-likelihood of each ``fx``.
    //  log_PR : array
    //      The log-prior for each chain.
    //  RAT specific prior funtion (mvnpdf)
    loop_ub_tmp = static_cast<int>(DREAMPar.nChains);
    PR.set_size(1, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      PR[i] = 0.0;
    }

    if (loop_ub_tmp - 1 >= 0) {
      loop_ub = x.size(1);
    }

    for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
      //  Loop over all the chains..
      b_x.set_size(1, x.size(1));
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
    for (int b_i{0}; b_i < i; b_i++) {
      double d;
      d = PR[b_i];
      if (d != 0.0) {
        log_PR[b_i] = d;

        // log(PR(i));     % Does it even need to be log?
      } else {
        //  Otherwise keep the zero values
        log_PR[b_i] = 0.0;
      }
    }

    //  -------------------- Calculate log-likelihood ---------------------------
    //  Loop over each model realization and calculate log-likelihood of each fx
    log_L.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      log_L[i] = 0.0;
    }

    for (int ii{0}; ii < loop_ub_tmp; ii++) {
      log_L[ii] = fx[ii];
    }

    //  ------------------ End Calculate log-likelihood -------------------------
  }
}

// End of code generation (calcDensity.cpp)
