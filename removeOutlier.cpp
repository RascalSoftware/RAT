//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// removeOutlier.cpp
//
// Code generation for function 'removeOutlier'
//

// Include files
#include "removeOutlier.h"
#include "RATMain_types.h"
#include "find.h"
#include "mean.h"
#include "nullAssignment.h"
#include "prctile.h"
#include "randperm.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void iqr(const ::coder::array<double, 2U> &log_L, ::coder::array<double,
                  2U> &idx_outlier);
}

// Function Definitions
namespace RAT
{
  static void iqr(const ::coder::array<double, 2U> &log_L, ::coder::array<double,
                  2U> &idx_outlier)
  {
    ::coder::array<int, 2U> r;
    ::coder::array<boolean_T, 2U> b_log_L;
    double Q[2];
    double b_Q;
    int loop_ub;

    //  Secondary functions used by this function
    //  -------------------------------------------------------------------------
    //  ------------------- Interquartie range diagnostic -----------------------
    //  -------------------------------------------------------------------------
    //  Derive the upper and lower quantile of the data
    coder::prctile(log_L, Q);

    //  Derive the inter quartile range
    //  Are there any outlier chains ( 2 * IQR is liberal - normal is 1.5 * IQR)
    b_Q = Q[1] - 2.0 * (Q[0] - Q[1]);
    b_log_L.set_size(1, log_L.size(1));
    loop_ub = log_L.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_log_L[i] = (log_L[i] < b_Q);
    }

    coder::g_eml_find(b_log_L, r);
    idx_outlier.set_size(1, r.size(1));
    loop_ub = r.size(1);
    for (int i{0}; i < loop_ub; i++) {
      idx_outlier[i] = r[i];
    }
  }

  void removeOutlier(::coder::array<double, 2U> &X, ::coder::array<double, 2U>
                     &log_L, const double outlier_data[], const int
                     outlier_size[2], const DreamParams &DREAMPar, ::coder::
                     array<double, 2U> &outputOutlier)
  {
    ::coder::array<double, 2U> b_chain_select;
    ::coder::array<double, 2U> b_log_L;
    ::coder::array<double, 2U> b_outputOutlier;
    ::coder::array<double, 2U> chain_id;
    ::coder::array<double, 2U> chain_select;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 1U> c_log_L;
    ::coder::array<int, 2U> b_chain_id;
    int b_loop_ub;
    int chain_select_tmp;
    int i;
    int i1;
    int loop_ub;
    int t_half;

    //  Find outlier chains and remove them when needed.
    //
    //  Parameters
    //  ----------
    //  X : array
    //      The current position for each chain.
    //  log_L : array
    //      The current log-likelihood for each chain.
    //  outlier : array
    //      The current array of outlier chains.
    //  DREAMPar : struct
    //      Algorithmic control information for DREAM.
    //
    //  Returns
    //  -------
    //  X : array
    //      The position for each chain with outliers removed.
    //  log_L : array
    //      The log-likelihood for each chain with outliers removed.
    //  outputOutlier :
    //      The ``outlier`` array with any new removed outliers added.
    //  Determine the number of elements of L_density
    t_half = static_cast<int>(std::floor(0.5 * static_cast<double>(log_L.size(0))));

    //  Then determine the mean log density of the active chains
    if (t_half > log_L.size(0)) {
      i = 0;
      i1 = 0;
    } else {
      i = t_half - 1;
      i1 = log_L.size(0);
    }

    if (DREAMPar.nChains < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = static_cast<int>(DREAMPar.nChains);
    }

    //  ------------------------------
    //  Always use the same outlier check (to remove eval)
    //  ---------------------------------- AVH
    b_loop_ub = i1 - i;
    b_log_L.set_size(b_loop_ub, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (chain_select_tmp = 0; chain_select_tmp < b_loop_ub; chain_select_tmp
           ++) {
        b_log_L[chain_select_tmp + b_log_L.size(0) * i1] = log_L[(i +
          chain_select_tmp) + log_L.size(0) * i1];
      }
    }

    coder::mean(b_log_L, chain_select);
    iqr(chain_select, chain_id);
    outputOutlier.set_size(outlier_size[0], 2);
    loop_ub = outlier_size[0];
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        outputOutlier[i1 + outputOutlier.size(0) * i] = outlier_data[i1 +
          outlier_size[0] * i];
      }
    }

    //  How many outliers?
    //  If at least one outlier chain has been found --> reset its state
    if (chain_id.size(1) > 0) {
      //  Re-initialise ecah outlier chain to current state random other chain
      if (std::isnan(DREAMPar.nChains)) {
        b_chain_select.set_size(1, 1);
        b_chain_select[0] = rtNaN;
      } else if (DREAMPar.nChains < 1.0) {
        b_chain_select.set_size(1, 0);
      } else {
        b_chain_select.set_size(1, static_cast<int>(DREAMPar.nChains - 1.0) + 1);
        loop_ub = static_cast<int>(DREAMPar.nChains - 1.0);
        for (i = 0; i <= loop_ub; i++) {
          b_chain_select[i] = static_cast<double>(i) + 1.0;
        }
      }

      b_chain_id.set_size(1, chain_id.size(1));
      loop_ub = chain_id.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_chain_id[i] = static_cast<int>(chain_id[i]);
      }

      coder::internal::nullAssignment(b_chain_select, b_chain_id);

      //  Randomly permute these available chains
      coder::randperm(DREAMPar.nChains - static_cast<double>(chain_id.size(1)),
                      r);
      chain_select.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        chain_select[i] = b_chain_select[static_cast<int>(r[i]) - 1];
      }

      b_chain_select.set_size(1, chain_select.size(1));
      loop_ub = chain_select.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_chain_select[i] = chain_select[i];
      }

      //  Loop over each outlier chain
      i = chain_id.size(1);
      for (int j{0}; j < i; j++) {
        int chain_id_tmp;
        short i2;

        //  Added -- update log_L -- chain will not be considered as an outlier chain then
        chain_select_tmp = static_cast<int>(b_chain_select[j]);
        loop_ub = log_L.size(0);
        chain_id_tmp = static_cast<int>(chain_id[j]);
        c_log_L.set_size(loop_ub);
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_log_L[i1] = log_L[i1 + log_L.size(0) * (chain_select_tmp - 1)];
        }

        loop_ub = c_log_L.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          log_L[i1 + log_L.size(0) * (chain_id_tmp - 1)] = c_log_L[i1];
        }

        //  Jump outlier chain to r_idx -- X
        b_loop_ub = static_cast<int>(DREAMPar.nParams + 2.0);
        chain_select.set_size(1, b_loop_ub);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          chain_select[i1] = X[(chain_select_tmp + X.size(0) * i1) - 1];
        }

        loop_ub = chain_select.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          X[(chain_id_tmp + X.size(0) * i1) - 1] = chain_select[i1];
        }

        //  Add to chain_outlier and print to screen
        if (outputOutlier.size(0) != 0) {
          i2 = static_cast<short>(outputOutlier.size(0));
        } else {
          i2 = 0;
        }

        b_loop_ub = i2;
        b_outputOutlier.set_size(i2 + 1, 2);
        for (i1 = 0; i1 < 2; i1++) {
          for (chain_select_tmp = 0; chain_select_tmp < b_loop_ub;
               chain_select_tmp++) {
            b_outputOutlier[chain_select_tmp + b_outputOutlier.size(0) * i1] =
              outputOutlier[chain_select_tmp + i2 * i1];
          }
        }

        b_outputOutlier[static_cast<int>(i2)] = log_L.size(0);
        b_outputOutlier[i2 + b_outputOutlier.size(0)] = chain_id[j];
        outputOutlier.set_size(b_outputOutlier.size(0), 2);
        loop_ub = b_outputOutlier.size(0);
        for (i1 = 0; i1 < 2; i1++) {
          for (chain_select_tmp = 0; chain_select_tmp < loop_ub;
               chain_select_tmp++) {
            outputOutlier[chain_select_tmp + outputOutlier.size(0) * i1] =
              b_outputOutlier[chain_select_tmp + b_outputOutlier.size(0) * i1];
          }
        }

        //  Warning -- not enough chains to do sampling -- increase number of chains!
        // evalstr = char(strcat('DREAM WARNING: Irreversible jump chain',{' '},num2str(chain_id(j)),{' '},'at',{' '},num2str(t),{' '},'generations \n'));
        // fprintf(' DREAM WARNING: Irreversible jump chain %0.2f at %0.2f generations \n \n \n',chain_id(j),t)
        //  Now print warning to screen and to file
        // fprintf(evalstr); % fprintf(fid,evalstr);
      }
    }
  }
}

// End of code generation (removeOutlier.cpp)
