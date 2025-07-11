//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
#include "calcLogLikelihood.h"
#include "calcLogPrior.h"
#include "drawCR.h"
#include "rand.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<double, 2U> &in3, const
    DreamParams &in4);
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<double, 2U> &in3, const ::coder::
    array<double, 2U> &in4);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<double, 2U> &in3, const
    DreamParams &in4)
  {
    ::coder::array<double, 2U> b_in2;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    if (in3.size(1) == 1) {
      loop_ub = in2.size(1);
    } else {
      loop_ub = in3.size(1);
    }

    b_in2.set_size(1, loop_ub);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_1 = (in3.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in2[i] = in2[i * stride_0_1] - in3[i * stride_1_1];
    }

    coder::repmat(b_in2, in4.nChains, in1);
  }

  static void binary_expand_op(::coder::array<double, 2U> &in1, const ::coder::
    array<double, 2U> &in2, const ::coder::array<double, 2U> &in3, const ::coder::
    array<double, 2U> &in4)
  {
    int aux_0_1;
    int aux_1_1;
    int aux_2_1;
    int b_loop_ub;
    int i;
    int loop_ub;
    int stride_0_0;
    int stride_0_1;
    int stride_1_0;
    int stride_1_1;
    int stride_2_0;
    int stride_2_1;
    if (in4.size(0) == 1) {
      i = in3.size(0);
    } else {
      i = in4.size(0);
    }

    if (i == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = i;
    }

    in1.set_size(loop_ub, in1.size(1));
    if (in4.size(1) == 1) {
      i = in3.size(1);
    } else {
      i = in4.size(1);
    }

    if (i == 1) {
      b_loop_ub = in2.size(1);
    } else {
      b_loop_ub = i;
    }

    in1.set_size(in1.size(0), b_loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_0_1 = (in2.size(1) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_1_1 = (in3.size(1) != 1);
    stride_2_0 = (in4.size(0) != 1);
    stride_2_1 = (in4.size(1) != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    aux_2_1 = 0;
    for (i = 0; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        in1[i1 + in1.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) * aux_0_1]
          + in3[i1 * stride_1_0 + in3.size(0) * aux_1_1] * in4[i1 * stride_2_0 +
          in4.size(0) * aux_2_1];
      }

      aux_2_1 += stride_2_1;
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }

  void initializeDREAM(const DreamParams &DREAMPar, const ::coder::array<double,
                       2U> &paramInfo_min, const ::coder::array<double, 2U>
                       &paramInfo_max, const char paramInfo_boundhandling_data[],
                       const int paramInfo_boundhandling_size[2], ::coder::array<
                       double, 3U> &chain, f_struct_T &output, ::coder::array<
                       double, 2U> &log_L, const ProblemDefinition &
                       ratInputs_problemStruct, const Controls
                       *ratInputs_controls, const ::coder::array<double, 2U>
                       &ratInputs_priors, ::coder::array<double, 2U> &X, ::coder::
                       array<double, 2U> &CR, double pCR_data[], int pCR_size[2],
                       double lCR_data[], int lCR_size[2], double
                       delta_tot_data[], int delta_tot_size[2])
  {
    ::coder::array<double, 2U> b_X;
    ::coder::array<double, 2U> b_paramInfo_max;
    ::coder::array<double, 2U> b_x;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 2U> x;
    ::coder::array<double, 2U> y;
    ::coder::array<double, 1U> log_L_x;
    ::coder::array<double, 1U> log_PR_x;
    int b_loop_ub;
    int i;
    int i1;
    int input_sizes_idx_1;
    int loop_ub;
    signed char b_input_sizes_idx_1;
    signed char sizes_idx_1;
    boolean_T b;
    boolean_T empty_non_axis_sizes;

    //  Initialize the starting positions of the Markov chains.
    //
    //  Parameters
    //  ----------
    //  DREAMPar : struct
    //      Algorithmic control information for DREAM.
    //  paramInfo : struct
    //      Prior, bound, and boundary handling information for each parameter.
    //  chain : array
    //      The initial chain array created by setupDREAM.
    //  output : struct
    //      The initial output struct created by setupDREAM.
    //  log_L : array
    //      The array of log-likelihood values sampled from chains.
    //  ratInputs : struct
    //      The project and controls inputs from RAT.
    //
    //  Returns
    //  -------
    //  chain : array
    //      The initial MCMC chain array.
    //  output : struct
    //      The initial empty output struct.
    //  X : array
    //      The starting Markov chains.
    //  CR : array
    //      The crossover values for each parameter.
    //  pCR : array
    //      The selection probability of crossover for each parameter.
    //  lCR : array
    //      The jumping distance weights for each crossover value.
    //  delta_tot : array
    //      The initial normalised Euclidean distance for each crossover value.
    //  log_L : array
    //      The initial log-likelihood for each chain value.
    //
    coder::b_rand(DREAMPar.nChains, DREAMPar.nParams, b_X);
    if (paramInfo_max.size(1) == paramInfo_min.size(1)) {
      b_paramInfo_max.set_size(1, paramInfo_max.size(1));
      loop_ub = paramInfo_max.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_paramInfo_max[i] = paramInfo_max[i] - paramInfo_min[i];
      }

      coder::repmat(b_paramInfo_max, DREAMPar.nChains, x);
    } else {
      binary_expand_op(x, paramInfo_max, paramInfo_min, DREAMPar);
    }

    r.set_size(x.size(0), x.size(1));
    loop_ub = x.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = x.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        r[i1 + r.size(0) * i] = x[i1 + x.size(0) * i];
      }
    }

    coder::repmat(paramInfo_min, DREAMPar.nChains, x);

    //  If specified do boundary handling ( "Bound","Reflect","Fold")
    if (b_X.size(0) == 1) {
      i = r.size(0);
    } else {
      i = b_X.size(0);
    }

    if (b_X.size(1) == 1) {
      i1 = r.size(1);
    } else {
      i1 = b_X.size(1);
    }

    if ((b_X.size(0) == r.size(0)) && (b_X.size(1) == r.size(1)) && (x.size(0) ==
         i) && (x.size(1) == i1)) {
      b_x.set_size(x.size(0), x.size(1));
      loop_ub = x.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_loop_ub = x.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_x[i1 + b_x.size(0) * i] = x[i1 + x.size(0) * i] + b_X[i1 + b_X.size
            (0) * i] * r[i1 + r.size(0) * i];
        }
      }
    } else {
      binary_expand_op(b_x, x, b_X, r);
    }

    boundaryHandling(b_x, paramInfo_min, paramInfo_max,
                     paramInfo_boundhandling_data, paramInfo_boundhandling_size);

    //  Now evaluate the model ( = pdf ) and return log-likelihood
    calcLogLikelihood(b_x, DREAMPar, ratInputs_problemStruct, ratInputs_controls,
                      log_L_x);

    //  calculate log-prior
    x.set_size(b_x.size(0), b_x.size(1));
    loop_ub = b_x.size(1) - 1;
    for (i = 0; i <= loop_ub; i++) {
      b_loop_ub = b_x.size(0) - 1;
      for (i1 = 0; i1 <= b_loop_ub; i1++) {
        x[i1 + x.size(0) * i] = b_x[i1 + b_x.size(0) * i];
      }
    }

    calcLogPrior(x, ratInputs_priors, log_PR_x);

    //  Define starting x values, corresponding density, log densty and simulations (Xfx)
    b = ((b_x.size(0) != 0) && (b_x.size(1) != 0));
    if (b) {
      b_loop_ub = b_x.size(0);
    } else if (log_PR_x.size(0) != 0) {
      b_loop_ub = log_PR_x.size(0);
    } else if (log_L_x.size(0) != 0) {
      b_loop_ub = log_L_x.size(0);
    } else {
      b_loop_ub = b_x.size(0);
    }

    empty_non_axis_sizes = (b_loop_ub == 0);
    if (empty_non_axis_sizes || b) {
      input_sizes_idx_1 = b_x.size(1);
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

    i = input_sizes_idx_1 + b_input_sizes_idx_1;
    X.set_size(b_loop_ub, i + sizes_idx_1);
    for (i1 = 0; i1 < input_sizes_idx_1; i1++) {
      for (int i2{0}; i2 < b_loop_ub; i2++) {
        X[i2 + X.size(0) * i1] = b_x[i2 + b_loop_ub * i1];
      }
    }

    loop_ub = b_input_sizes_idx_1;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (int i2{0}; i2 < b_loop_ub; i2++) {
        X[i2 + X.size(0) * input_sizes_idx_1] = log_PR_x[i2];
      }
    }

    loop_ub = sizes_idx_1;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (int i2{0}; i2 < b_loop_ub; i2++) {
        X[i2 + X.size(0) * i] = log_L_x[i2];
      }
    }

    //  Set the first point of each of the DREAMPar.nChains chain equal to the initial X values
    b_X.set_size(X.size(1), X.size(0));
    loop_ub = X.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = X.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_X[i1 + b_X.size(0) * i] = X[i + X.size(0) * i1];
      }
    }

    b_loop_ub = static_cast<int>(DREAMPar.nParams + 2.0);
    if (DREAMPar.nChains < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = static_cast<int>(DREAMPar.nChains);
    }

    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        chain[chain.size(0) * i1 + chain.size(0) * chain.size(1) * i] = b_X[i1 +
          b_loop_ub * i];
      }
    }

    int iv[2];

    //  Define selection probability of each crossover
    y.set_size(1, 3);
    pCR_size[0] = 1;
    pCR_size[1] = 3;
    y[0] = 0.33333333333333331;
    pCR_data[0] = 0.33333333333333331;
    y[1] = 0.33333333333333331;
    pCR_data[1] = 0.33333333333333331;
    y[2] = 0.33333333333333331;
    pCR_data[2] = 0.33333333333333331;

    //  Generate the actula CR value, lCR and delta_tot
    iv[0] = (*(int (*)[2])y.size())[0];
    iv[1] = (*(int (*)[2])y.size())[1];
    drawCR(DREAMPar, (const double *)y.data(), iv, CR);
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
    output.CR[0] = DREAMPar.nChains;
    for (i = 0; i < 3; i++) {
      output.CR[output.CR.size(0) * (i + 1)] = 0.33333333333333331;
    }

    //  Save history log density of individual chains
    log_L[0] = DREAMPar.nChains;
    loop_ub = log_L_x.size(0);
    for (i = 0; i < loop_ub; i++) {
      log_L[log_L.size(0) * (i + 1)] = log_L_x[i];
    }

    //  Compute the R-statistic
    //  ----------------------------------------------------
    //  For more information please refer to: Gelman, A. and D.R. Rubin, 1992.
    //  Inference from Iterative Simulation Using Multiple Chain,
    //  Statistical Science, Volume 7, Issue 4, 457-472.
    //  URL: https://www.jstor.org/stable/2246093
    //
    //  Written by Jasper A. Vrugt
    //  Los Alamos, August 2007
    //  ----------------------------------------------------
    //  Calculate the R-statistic convergence diagnostic.
    //
    //  Parameters
    //  ----------
    //  chain : array
    //      The Markov chains from the optimisation so far.
    //  DREAMPar : struct
    //      Algorithmic control information for DREAM.
    //
    //  Returns
    //  -------
    //  R_stat
    //      The R-statistic convergence diagnostic for each parameter.
    //  Compute the dimensions of chain
    //  Set the R-statistic to a large value
    output.R_stat[0] = DREAMPar.nChains;
    loop_ub = static_cast<int>(DREAMPar.nParams);
    for (i = 0; i < loop_ub; i++) {
      output.R_stat[output.R_stat.size(0) * (i + 1)] = rtNaN;
    }
  }
}

// End of code generation (initializeDREAM.cpp)
