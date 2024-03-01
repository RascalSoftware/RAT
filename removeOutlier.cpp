//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
  static void iqr(const ::coder::array<real_T, 2U> &log_L, ::coder::array<real_T,
                  2U> &idx_outlier);
}

// Function Definitions
namespace RAT
{
  static void iqr(const ::coder::array<real_T, 2U> &log_L, ::coder::array<real_T,
                  2U> &idx_outlier)
  {
    ::coder::array<int32_T, 2U> r;
    ::coder::array<boolean_T, 2U> b_log_L;
    real_T Q[2];
    real_T b_Q;
    int32_T i;
    int32_T loop_ub;

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
    for (i = 0; i < loop_ub; i++) {
      b_log_L[i] = (log_L[i] < b_Q);
    }

    coder::d_eml_find(b_log_L, r);
    idx_outlier.set_size(1, r.size(1));
    loop_ub = r.size(1);
    for (i = 0; i < loop_ub; i++) {
      idx_outlier[i] = r[i];
    }
  }

  void removeOutlier(::coder::array<real_T, 2U> &X, ::coder::array<real_T, 2U>
                     &log_L, const real_T outlier_data[], const int32_T
                     outlier_size[2], const struct14_T *DREAMPar, ::coder::array<
                     real_T, 2U> &outputOutlier)
  {
    ::coder::array<real_T, 2U> b_chain_select;
    ::coder::array<real_T, 2U> b_log_L;
    ::coder::array<real_T, 2U> b_outputOutlier;
    ::coder::array<real_T, 2U> chain_id;
    ::coder::array<real_T, 2U> chain_select;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 1U> c_log_L;
    ::coder::array<int32_T, 2U> b_chain_id;
    int32_T b_loop_ub;
    int32_T chain_select_tmp;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T t;
    int32_T t_half;

    //  Finds outlier chains and removes them when needed
    //  Determine the number of elements of L_density
    t = log_L.size(0);
    t_half = static_cast<int32_T>(std::floor(static_cast<real_T>(log_L.size(0)) /
      2.0));

    //  Then determine the mean log density of the active chains
    if (t_half > log_L.size(0)) {
      i = 0;
      i1 = 0;
    } else {
      i = t_half - 1;
      i1 = log_L.size(0);
    }

    if (1.0 > DREAMPar->N) {
      loop_ub = 0;
    } else {
      loop_ub = static_cast<int32_T>(DREAMPar->N);
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

    //  % Create outlier handle
    //  evalstr = strcat('chain_id=',DREAMPar.outlier,'(mean_log_L);');
    //
    //  % Now evaluate outlier handle
    //  try
    //      eval(evalstr);
    //  catch
    //      % Warning -- not enough chains to do sampling -- increase number of chains!
    //      fprintf('DREAM WARNING: Unknown outlier detection test at %d generations \n',t);
    //      % Now print warning to screen and to file
    //      %fprintf(evalstr); % fprintf(fid,evalstr);
    //      % No outlier detected
    //      outlier = [];
    //      return
    //  end
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
      //  Re-initialize ecah outlier chain to current state random other chain
      if (std::isnan(DREAMPar->N)) {
        b_chain_select.set_size(1, 1);
        b_chain_select[0] = rtNaN;
      } else if (DREAMPar->N < 1.0) {
        b_chain_select.set_size(1, 0);
      } else if (std::isinf(DREAMPar->N) && (1.0 == DREAMPar->N)) {
        b_chain_select.set_size(1, 1);
        b_chain_select[0] = rtNaN;
      } else {
        loop_ub = static_cast<int32_T>(std::floor(DREAMPar->N - 1.0));
        b_chain_select.set_size(1, loop_ub + 1);
        for (i = 0; i <= loop_ub; i++) {
          b_chain_select[i] = static_cast<real_T>(i) + 1.0;
        }
      }

      b_chain_id.set_size(1, chain_id.size(1));
      loop_ub = chain_id.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_chain_id[i] = static_cast<int32_T>(chain_id[i]);
      }

      coder::internal::nullAssignment(b_chain_select, b_chain_id);

      //  Randomly permute these available chains
      coder::randperm(DREAMPar->N - static_cast<real_T>(chain_id.size(1)), r);
      chain_select.set_size(1, r.size(1));
      loop_ub = r.size(1);
      for (i = 0; i < loop_ub; i++) {
        chain_select[i] = b_chain_select[static_cast<int32_T>(r[i]) - 1];
      }

      b_chain_select.set_size(1, chain_select.size(1));
      loop_ub = chain_select.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_chain_select[i] = chain_select[i];
      }

      //  Loop over each outlier chain
      i = chain_id.size(1);
      loop_ub = static_cast<int32_T>(DREAMPar->d + 2.0);
      for (int32_T j{0}; j < i; j++) {
        int32_T chain_id_tmp;
        int16_T i2;

        //  Added -- update log_L -- chain will not be considered as an outlier chain then
        b_loop_ub = log_L.size(0) - 1;
        chain_select_tmp = static_cast<int32_T>(b_chain_select[j]);
        chain_id_tmp = static_cast<int32_T>(chain_id[j]);
        c_log_L.set_size(b_loop_ub + 1);
        for (i1 = 0; i1 <= b_loop_ub; i1++) {
          c_log_L[i1] = log_L[i1 + log_L.size(0) * (chain_select_tmp - 1)];
        }

        b_loop_ub = c_log_L.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          log_L[i1 + log_L.size(0) * (chain_id_tmp - 1)] = c_log_L[i1];
        }

        //  Jump outlier chain to r_idx -- X
        chain_select.set_size(1, loop_ub);
        for (i1 = 0; i1 < loop_ub; i1++) {
          chain_select[i1] = X[(chain_select_tmp + X.size(0) * i1) - 1];
        }

        b_loop_ub = chain_select.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          X[(chain_id_tmp + X.size(0) * i1) - 1] = chain_select[i1];
        }

        //  Add to chain_outlier and print to screen
        if (outputOutlier.size(0) != 0) {
          i2 = static_cast<int16_T>(outputOutlier.size(0));
        } else {
          i2 = 0;
        }

        if (outputOutlier.size(0) != 0) {
          b_loop_ub = static_cast<int16_T>(outputOutlier.size(0));
        } else {
          b_loop_ub = 0;
        }

        b_outputOutlier.set_size(i2 + 1, 2);
        for (i1 = 0; i1 < 2; i1++) {
          for (chain_select_tmp = 0; chain_select_tmp < b_loop_ub;
               chain_select_tmp++) {
            b_outputOutlier[chain_select_tmp + b_outputOutlier.size(0) * i1] =
              outputOutlier[chain_select_tmp + i2 * i1];
          }
        }

        b_outputOutlier[b_loop_ub] = t;
        b_outputOutlier[b_loop_ub + b_outputOutlier.size(0)] = chain_id[j];
        outputOutlier.set_size(b_outputOutlier.size(0), 2);
        b_loop_ub = b_outputOutlier.size(0);
        for (i1 = 0; i1 < 2; i1++) {
          for (chain_select_tmp = 0; chain_select_tmp < b_loop_ub;
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
