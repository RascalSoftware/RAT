//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
  void setupDREAM(real_T DREAMPar_nParams, real_T DREAMPar_nChains, real_T
                  DREAMPar_nGenerations, real_T DREAMPar_jumpProbability, real_T
                  DREAMPar_pUnitGamma, boolean_T DREAMPar_adaptPCR, b_struct_T
                  *Meas_info, struct12_T *outDREAMPar, ::coder::array<real_T, 3U>
                  &chain, j_struct_T *output, ::coder::array<real_T, 2U> &log_L,
                  ::coder::array<real_T, 2U> &Table_gamma)
  {
    ::coder::array<real_T, 2U> c;
    ::coder::array<real_T, 2U> y;
    ::coder::array<real_T, 1U> r;
    ::coder::array<int32_T, 1U> ia;
    real_T value_f3_tmp;
    int32_T b_loop_ub_tmp;
    int32_T i;
    int32_T i1;
    int32_T k;
    int32_T loop_ub;
    int32_T loop_ub_tmp;

    //  Initializes the main variables used in DREAM
    //  To keep coder happy, we have to define the full version of DREAMPar here
    //  fieldNames = {'nParams','nChains','nGenerations','parallel','CPU','jumpProbability','pUnitGamma','nCR','delta','steps',...
    //      'zeta','outlier','adaptPCR','thinning','ABC','epsilon','IO','storeOutput','R'};
    //  values = cell(length(fieldNames),1);
    //  outDREAMPar = cell2struct(values,fieldNames);
    loop_ub_tmp = static_cast<int32_T>(DREAMPar_nChains);
    outDREAMPar->R.set_size(loop_ub_tmp, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        outDREAMPar->R[i1 + outDREAMPar->R.size(0) * i] = 0.0;
      }
    }

    //  Generate new seed
    coder::rng();

    // randn('state', sum(100*clock));     % random number generator state
    //  Now make sure that all strings are lower case --> **TURNS OUT THIS BREAKS
    //  THINGS IF IMPLEMENTED!**
    //  for i = 1 : numel(field_names)
    //      % evalstr = strcat('DREAMPar.',field_names(i),' = lower(DREAMPar.',field_names(i),');');
    //      % Now evaluate
    //      %eval(char(evalstr));
    //      DREAMPar = lowerCaseStruct(DREAMPar);
    //  end
    //  Do an initial copy of all set fields from DREAMPar to outDREAMPar....
    outDREAMPar->nParams = DREAMPar_nParams;
    outDREAMPar->nChains = DREAMPar_nChains;
    outDREAMPar->nGenerations = DREAMPar_nGenerations;
    outDREAMPar->CPU = 1.0;

    //  Set default values algorithmic variables DREAM - if not specified
    value_f3_tmp = std::fmax(std::fmax(std::floor(DREAMPar_nGenerations / 50.0),
      1.0), 50.0);

    //  Name variable
    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar->nCR = 3.0;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar->delta = 3.0;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar->steps = value_f3_tmp;
    outDREAMPar->jumpProbability = DREAMPar_jumpProbability;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar->zeta = 1.0E-12;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar->outlier[0] = 'i';
    outDREAMPar->outlier[1] = 'q';
    outDREAMPar->outlier[2] = 'r';
    outDREAMPar->pUnitGamma = DREAMPar_pUnitGamma;
    outDREAMPar->adaptPCR = DREAMPar_adaptPCR;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar->thinning = 1.0;

    //  Set variable of DREAMPar to "No"
    // evalstr = strcat('DREAMPar.',char(name(j)),'=',value(j),';'); eval(char(evalstr));
    outDREAMPar->epsilon = 0.025;

    //  Set default value to 'No' if not specified
    //  Set variable of DREAMPar to false
    // evalstr = strcat('DREAMPar.',char(default(j)),'=false',';'); eval(evalstr);
    outDREAMPar->ABC = false;
    outDREAMPar->parallel = false;

    //  Set variable of DREAMPar to false
    // evalstr = strcat('DREAMPar.',char(default(j)),'=false',';'); eval(evalstr);
    outDREAMPar->IO = false;

    //  Set variable of DREAMPar to false
    // evalstr = strcat('DREAMPar.',char(default(j)),'=false',';'); eval(evalstr);
    outDREAMPar->storeOutput = false;

    //  Matrix DREAMPar.R: Store for each chain (as row) the index of all other chains available for DE
    if (0 <= static_cast<int32_T>(DREAMPar_nChains) - 1) {
      if (DREAMPar_nChains < 1.0) {
        y.set_size(1, 0);
      } else if (std::isinf(DREAMPar_nChains) && (1.0 == DREAMPar_nChains)) {
        y.set_size(1, 1);
        y[0] = rtNaN;
      } else {
        loop_ub = static_cast<int32_T>(std::floor(DREAMPar_nChains - 1.0));
        y.set_size(1, loop_ub + 1);
        for (i = 0; i <= loop_ub; i++) {
          y[i] = static_cast<real_T>(i) + 1.0;
        }
      }
    }

    for (int32_T b_i{0}; b_i < loop_ub_tmp; b_i++) {
      coder::do_vectors(y, static_cast<real_T>(b_i) + 1.0, c, ia, &k);
      loop_ub = c.size(1);
      for (i = 0; i < loop_ub; i++) {
        outDREAMPar->R[b_i + outDREAMPar->R.size(0) * i] = c[i];
      }
    }

    //  Check whether parameter ranges have been defined or not
    //  Initialize output information -- Outlier chains
    output->outlierChains.size[0] = 1;
    output->outlierChains.size[1] = 2;
    output->outlierChains.data[0] = 0.0;
    output->outlierChains.data[output->outlierChains.size[0]] = 0.0;

    //  ..also run time
    output->runtime = 0.0;
    output->DREAMPar = *outDREAMPar;
    output->Meas_info = *Meas_info;
    output->iteration = 1.0;
    output->iloc = 0.0;
    output->modelOutput = 0.0;

    //  Initialize matrix with log_likelihood of each chain
    loop_ub = static_cast<int32_T>(DREAMPar_nGenerations);
    b_loop_ub_tmp = static_cast<int32_T>(DREAMPar_nChains + 1.0);
    log_L.set_size(loop_ub, b_loop_ub_tmp);
    for (i = 0; i < b_loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        log_L[i1 + log_L.size(0) * i] = rtNaN;
      }
    }

    //  Initialize vector with acceptance rates
    b_loop_ub_tmp = static_cast<int32_T>(std::floor(DREAMPar_nGenerations /
      value_f3_tmp) + 1.0);
    output->AR.size[0] = static_cast<int32_T>(std::floor(DREAMPar_nGenerations /
      value_f3_tmp) + 1.0);
    output->AR.size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
        output->AR.data[i1 + output->AR.size[0] * i] = rtNaN;
      }
    }

    // NaN(floor(outDREAMPar.nGenerations/outDREAMPar.steps)+1,2);
    output->AR.data[0] = DREAMPar_nChains;

    //  Initialize matrix with potential scale reduction convergence diagnostic
    k = static_cast<int32_T>(DREAMPar_nParams + 1.0);
    output->R_stat.set_size(b_loop_ub_tmp, k);
    for (i = 0; i < k; i++) {
      for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
        output->R_stat[i1 + output->R_stat.size(0) * i] = rtNaN;
      }
    }

    //  Initialize matix with crossover values
    output->CR.set_size(b_loop_ub_tmp, 4);
    for (i = 0; i < 4; i++) {
      for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
        output->CR[i1 + output->CR.size(0) * i] = rtNaN;
      }
    }

    //  Initialize array (3D-matrix) of chain trajectories
    b_loop_ub_tmp = static_cast<int32_T>(DREAMPar_nParams + 2.0);
    chain.set_size(loop_ub, b_loop_ub_tmp, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
        for (k = 0; k < loop_ub; k++) {
          chain[(k + chain.size(0) * i1) + chain.size(0) * chain.size(1) * i] =
            rtNaN;
        }
      }
    }

    //  Generate Table with jump rates (dependent on DREAMPar.nParams and DREAMPar.delta)
    //  More efficient to read from Table
    loop_ub_tmp = static_cast<int32_T>(DREAMPar_nParams);
    Table_gamma.set_size(loop_ub_tmp, 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        Table_gamma[i1 + Table_gamma.size(0) * i] = 0.0;
      }
    }

    if (std::isnan(DREAMPar_nParams)) {
      y.set_size(1, 1);
      y[0] = rtNaN;
    } else if (DREAMPar_nParams < 1.0) {
      y.set_size(1, 0);
    } else if (std::isinf(DREAMPar_nParams) && (1.0 == DREAMPar_nParams)) {
      y.set_size(1, 1);
      y[0] = rtNaN;
    } else {
      loop_ub = static_cast<int32_T>(std::floor(DREAMPar_nParams - 1.0));
      y.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        y[i] = static_cast<real_T>(i) + 1.0;
      }
    }

    loop_ub = y.size(1);
    for (int32_T zz{0}; zz < 3; zz++) {
      k = (zz + 1) << 1;
      r.set_size(y.size(1));
      for (i = 0; i < loop_ub; i++) {
        r[i] = static_cast<real_T>(k) * y[i];
      }

      i = r.size(0);
      for (k = 0; k < i; k++) {
        r[k] = std::sqrt(r[k]);
      }

      k = r.size(0);
      for (i = 0; i < k; i++) {
        Table_gamma[i + Table_gamma.size(0) * zz] = 2.38 / r[i];
      }
    }

    //  First calculate the number of calibration data measurements
    Meas_info->N = 0.0;

    //  Initialize few important counters
  }
}

// End of code generation (setupDREAM.cpp)
