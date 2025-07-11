//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// setupDREAM.cpp
//
// Code generation for function 'setupDREAM'
//

// Include files
#include "setupDREAM.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "eml_setop.h"
#include "rng.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  void setupDREAM(double DREAMPar_nParams, double DREAMPar_nChains, double
                  DREAMPar_nGenerations, double DREAMPar_jumpProbability, double
                  DREAMPar_pUnitGamma, boolean_T DREAMPar_adaptPCR, DreamParams
                  &outDREAMPar, ::coder::array<double, 3U> &chain, f_struct_T
                  &output, ::coder::array<double, 2U> &log_L, ::coder::array<
                  double, 2U> &Table_gamma)
  {
    ::coder::array<double, 2U> c;
    ::coder::array<double, 2U> y;
    ::coder::array<double, 1U> r;
    ::coder::array<int, 1U> ia;
    double value_f3_tmp;
    int b_loop_ub_tmp;
    int i;
    int k;
    int loop_ub;
    int loop_ub_tmp;

    //  Initialize the main variables used in DREAM.
    //
    //  Parameters
    //  ----------
    //  DREAMPar : struct
    //      Algorithmic control information for DREAM.
    //  paramInfo : struct
    //      Ranges, priors and boundary handling for each parameter.
    //
    //  Returns
    //  -------
    //  outDREAMPar : struct
    //      The options for DREAMPar with defaults applied.
    //  paramInfo : struct
    //      The input ``paramInfo`` after range validation.
    //  chain : array
    //      The initial MCMC chain array.
    //  output : struct
    //      The initial empty output struct.
    //  log_L : array
    //      The initial array of log-likelihood values sampled from chains.
    //  Table_gamma : array
    //      The initial DE jump length values for each parameter.
    //  iloc : int
    //      The index of the current sample in the chains.
    //  iteration : int
    //      The initial iteration number.
    //  gen : int
    //      The number of new candidates generated this generation.
    //  To keep coder happy, we have to define the full version of DREAMPar here
    loop_ub_tmp = static_cast<int>(DREAMPar_nChains);
    outDREAMPar.R.set_size(loop_ub_tmp, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      for (int i1{0}; i1 < loop_ub_tmp; i1++) {
        outDREAMPar.R[i1 + outDREAMPar.R.size(0) * i] = 0.0;
      }
    }

    //  Generate new seed
    coder::rng();

    // randn('state', sum(100*clock));     % random number generator state
    //  Do an initial copy of all set fields from DREAMPar to outDREAMPar....
    outDREAMPar.nParams = DREAMPar_nParams;
    outDREAMPar.nChains = DREAMPar_nChains;
    outDREAMPar.nGenerations = DREAMPar_nGenerations;
    outDREAMPar.CPU = 1.0;

    //  Set default values algorithmic variables DREAM - if not specified
    value_f3_tmp = std::fmax(std::fmax(std::floor(DREAMPar_nGenerations / 50.0),
      1.0), 50.0);

    //  Name variable
    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar.nCR = 3.0;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar.delta = 3.0;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar.steps = value_f3_tmp;
    outDREAMPar.jumpProbability = DREAMPar_jumpProbability;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar.zeta = 1.0E-12;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar.outlier[0] = 'i';
    outDREAMPar.outlier[1] = 'q';
    outDREAMPar.outlier[2] = 'r';
    outDREAMPar.pUnitGamma = DREAMPar_pUnitGamma;
    outDREAMPar.adaptPCR = DREAMPar_adaptPCR;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar.thinning = 1.0;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar.epsilon = 0.025;

    //  Set default value to 'No' if not specified
    //  Set variable of DREAMPar to false
    // evalstr = strcat('DREAMPar.',char(default(j)),'=false',';'); eval(evalstr);
    outDREAMPar.ABC = false;
    outDREAMPar.parallel = false;

    //  Set variable of DREAMPar to false
    // evalstr = strcat('DREAMPar.',char(default(j)),'=false',';'); eval(evalstr);
    outDREAMPar.IO = false;

    //  Set variable of DREAMPar to false
    // evalstr = strcat('DREAMPar.',char(default(j)),'=false',';'); eval(evalstr);
    outDREAMPar.storeOutput = false;

    //  Matrix DREAMPar.R: Store for each chain (as row) the index of all other chains available for DE
    if (static_cast<int>(DREAMPar_nChains) - 1 >= 0) {
      if (DREAMPar_nChains < 1.0) {
        y.set_size(1, 0);
      } else {
        y.set_size(1, static_cast<int>(DREAMPar_nChains - 1.0) + 1);
        loop_ub = static_cast<int>(DREAMPar_nChains - 1.0);
        for (i = 0; i <= loop_ub; i++) {
          y[i] = static_cast<double>(i) + 1.0;
        }
      }

      if (DREAMPar_nChains - 1.0 < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = static_cast<int>(DREAMPar_nChains - 1.0);
      }
    }

    for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
      coder::do_vectors(y, static_cast<double>(b_i) + 1.0, c, ia);
      for (i = 0; i < loop_ub; i++) {
        outDREAMPar.R[b_i + outDREAMPar.R.size(0) * i] = c[i];
      }
    }

    //  Check whether parameter ranges have been defined or not
    //  Initialize output information -- Outlier chains
    output.outlierChains.size[0] = 1;
    output.outlierChains.size[1] = 2;
    output.outlierChains.data[0] = 0.0;
    output.outlierChains.data[output.outlierChains.size[0]] = 0.0;

    //  ..also run time
    output.runtime = 0.0;
    output.DREAMPar = outDREAMPar;
    output.iteration = 1.0;
    output.iloc = 0.0;
    output.modelOutput = 0.0;

    //  Initialize matrix with log_likelihood of each chain
    loop_ub = static_cast<int>(DREAMPar_nGenerations);
    b_loop_ub_tmp = static_cast<int>(DREAMPar_nChains + 1.0);
    log_L.set_size(loop_ub, b_loop_ub_tmp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        log_L[i1 + log_L.size(0) * i] = rtNaN;
      }
    }

    //  Initialize vector with acceptance rates
    b_loop_ub_tmp = static_cast<int>(std::floor(DREAMPar_nGenerations /
      value_f3_tmp) + 1.0);
    output.AR.size[0] = static_cast<int>(std::floor(DREAMPar_nGenerations /
      value_f3_tmp) + 1.0);
    output.AR.size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (int i1{0}; i1 < b_loop_ub_tmp; i1++) {
        output.AR.data[i1 + output.AR.size[0] * i] = rtNaN;
      }
    }

    // NaN(floor(outDREAMPar.nGenerations/outDREAMPar.steps)+1,2);
    output.AR.data[0] = DREAMPar_nChains;

    //  Initialize matrix with potential scale reduction convergence diagnostic
    k = static_cast<int>(DREAMPar_nParams + 1.0);
    output.R_stat.set_size(b_loop_ub_tmp, k);
    for (i = 0; i < k; i++) {
      for (int i1{0}; i1 < b_loop_ub_tmp; i1++) {
        output.R_stat[i1 + output.R_stat.size(0) * i] = rtNaN;
      }
    }

    //  Initialize matix with crossover values
    output.CR.set_size(b_loop_ub_tmp, 4);
    for (i = 0; i < 4; i++) {
      for (int i1{0}; i1 < b_loop_ub_tmp; i1++) {
        output.CR[i1 + output.CR.size(0) * i] = rtNaN;
      }
    }

    //  Initialize array (3D-matrix) of chain trajectories
    b_loop_ub_tmp = static_cast<int>(DREAMPar_nParams + 2.0);
    chain.set_size(loop_ub, b_loop_ub_tmp, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      for (int i1{0}; i1 < b_loop_ub_tmp; i1++) {
        for (k = 0; k < loop_ub; k++) {
          chain[(k + chain.size(0) * i1) + chain.size(0) * chain.size(1) * i] =
            rtNaN;
        }
      }
    }

    //  Generate Table with jump rates (dependent on DREAMPar.nParams and DREAMPar.delta)
    //  More efficient to read from Table
    loop_ub_tmp = static_cast<int>(DREAMPar_nParams);
    Table_gamma.set_size(loop_ub_tmp, 3);
    for (i = 0; i < 3; i++) {
      for (int i1{0}; i1 < loop_ub_tmp; i1++) {
        Table_gamma[i1 + Table_gamma.size(0) * i] = 0.0;
      }
    }

    if (std::isnan(DREAMPar_nParams)) {
      y.set_size(1, 1);
      y[0] = rtNaN;
    } else if (DREAMPar_nParams < 1.0) {
      y.set_size(1, 0);
    } else {
      y.set_size(1, static_cast<int>(DREAMPar_nParams - 1.0) + 1);
      loop_ub = static_cast<int>(DREAMPar_nParams - 1.0);
      for (i = 0; i <= loop_ub; i++) {
        y[i] = static_cast<double>(i) + 1.0;
      }
    }

    loop_ub = y.size(1);
    for (int zz{0}; zz < 3; zz++) {
      k = (zz + 1) << 1;
      r.set_size(y.size(1));
      for (i = 0; i < loop_ub; i++) {
        r[i] = static_cast<double>(k) * y[i];
      }

      i = r.size(0);
      for (k = 0; k < i; k++) {
        r[k] = std::sqrt(r[k]);
      }

      k = Table_gamma.size(0);
      for (i = 0; i < k; i++) {
        Table_gamma[i + Table_gamma.size(0) * zz] = 2.38 / r[i];
      }
    }

    //  Initialize few important counters
  }
}

// End of code generation (setupDREAM.cpp)
