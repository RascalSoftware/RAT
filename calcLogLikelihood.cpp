//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// calcLogLikelihood.cpp
//
// Code generation for function 'calcLogLikelihood'
//

// Include files
#include "calcLogLikelihood.h"
#include "DREAMWrapper.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void calcLogLikelihood(const ::coder::array<double, 2U> &x, const DreamParams
    &DREAMPar, const ProblemDefinition &ratInputs_problemStruct, const Controls *
    ratInputs_controls, ::coder::array<double, 1U> &log_L_x)
  {
    ::coder::array<double, 2U> b_x;
    int loop_ub_tmp;

    //  Written by Jasper A. Vrugt
    //  Compute the log-likelihood of each d-vector of x values.
    //
    //  If DREAMPar.CPU > 1, runs in parallel.
    //
    //  Parameters
    //  ----------
    //  x : array
    //      The points at which to calculate likelihood and log-likelihood.
    //  DREAMPar : struct
    //      Algorithmic control information for DREAM.
    //  ratInputs : struct
    //      Project and controls information from RAT.
    //
    //  Returns
    //  -------
    //  log_L_x : array
    //      The log-likelihood for each point in ``x``.
    //
    loop_ub_tmp = static_cast<int>(DREAMPar.nChains);
    log_L_x.set_size(loop_ub_tmp);
    for (int i{0}; i < loop_ub_tmp; i++) {
      log_L_x[i] = 0.0;
    }

    //  Sequential evaluation
    //  Loop over each d-vector of parameter values of x using 1 worker
    for (int ii{0}; ii < loop_ub_tmp; ii++) {
      int loop_ub;

      //  Execute the model and return the model simulation
      loop_ub = x.size(1);
      b_x.set_size(1, x.size(1));
      for (int i{0}; i < loop_ub; i++) {
        b_x[i] = x[ii + x.size(0) * i];
      }

      log_L_x[ii] = DREAMWrapper(b_x, ratInputs_problemStruct,
        ratInputs_controls);
    }
  }
}

// End of code generation (calcLogLikelihood.cpp)
