//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeEmptyBayesResultsStruct.cpp
//
// Code generation for function 'makeEmptyBayesResultsStruct'
//

// Include files
#include "makeEmptyBayesResultsStruct.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "structConstructorHelper.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  static void cast(const real_T t24_percentile95_data[], const int32_T
                   t24_percentile95_size[2], const real_T t24_percentile65_data[],
                   const int32_T t24_percentile65_size[2], const real_T
                   t24_mean_data[], const int32_T t24_mean_size[2], ::coder::
                   array<real_T, 2U> &t25_percentile95, ::coder::array<real_T,
                   2U> &t25_percentile65, ::coder::array<real_T, 2U> &t25_mean);
  static void cast(const ::coder::array<real_T, 3U> &t22_allChains, const ::
                   coder::array<real_T, 2U> &t22_outlierChains, real_T
                   t22_runtime, real_T t22_iteration, real_T t22_modelOutput,
                   const ::coder::array<real_T, 2U> &t22_AR, const ::coder::
                   array<real_T, 2U> &t22_R_stat, const ::coder::array<real_T,
                   2U> &t22_CR, ::coder::array<real_T, 3U> &t23_allChains,
                   real_T t23_outlierChains_data[], int32_T
                   t23_outlierChains_size[2], real_T *t23_runtime, real_T
                   *t23_iteration, real_T *t23_modelOutput, real_T t23_AR_data[],
                   int32_T t23_AR_size[2], ::coder::array<real_T, 2U>
                   &t23_R_stat, ::coder::array<real_T, 2U> &t23_CR);
}

// Function Definitions
namespace RAT
{
  static void cast(const real_T t24_percentile95_data[], const int32_T
                   t24_percentile95_size[2], const real_T t24_percentile65_data[],
                   const int32_T t24_percentile65_size[2], const real_T
                   t24_mean_data[], const int32_T t24_mean_size[2], ::coder::
                   array<real_T, 2U> &t25_percentile95, ::coder::array<real_T,
                   2U> &t25_percentile65, ::coder::array<real_T, 2U> &t25_mean)
  {
    int32_T i;
    int32_T loop_ub;
    t25_percentile95.set_size(2, t24_percentile95_size[1]);
    loop_ub = t24_percentile95_size[1];
    for (i = 0; i < loop_ub; i++) {
      t25_percentile95[2 * i] = t24_percentile95_data[2 * i];
      t25_percentile95[2 * i + 1] = t24_percentile95_data[2 * i + 1];
    }

    t25_percentile65.set_size(2, t24_percentile65_size[1]);
    loop_ub = t24_percentile65_size[1];
    for (i = 0; i < loop_ub; i++) {
      t25_percentile65[2 * i] = t24_percentile65_data[2 * i];
      t25_percentile65[2 * i + 1] = t24_percentile65_data[2 * i + 1];
    }

    t25_mean.set_size(1, t24_mean_size[1]);
    loop_ub = t24_mean_size[1];
    for (i = 0; i < loop_ub; i++) {
      t25_mean[i] = t24_mean_data[i];
    }
  }

  static void cast(const ::coder::array<real_T, 3U> &t22_allChains, const ::
                   coder::array<real_T, 2U> &t22_outlierChains, real_T
                   t22_runtime, real_T t22_iteration, real_T t22_modelOutput,
                   const ::coder::array<real_T, 2U> &t22_AR, const ::coder::
                   array<real_T, 2U> &t22_R_stat, const ::coder::array<real_T,
                   2U> &t22_CR, ::coder::array<real_T, 3U> &t23_allChains,
                   real_T t23_outlierChains_data[], int32_T
                   t23_outlierChains_size[2], real_T *t23_runtime, real_T
                   *t23_iteration, real_T *t23_modelOutput, real_T t23_AR_data[],
                   int32_T t23_AR_size[2], ::coder::array<real_T, 2U>
                   &t23_R_stat, ::coder::array<real_T, 2U> &t23_CR)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    t23_allChains.set_size(t22_allChains.size(0), t22_allChains.size(1),
      t22_allChains.size(2));
    loop_ub = t22_allChains.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t22_allChains.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        int32_T c_loop_ub;
        c_loop_ub = t22_allChains.size(0);
        for (int32_T i2{0}; i2 < c_loop_ub; i2++) {
          t23_allChains[(i2 + t23_allChains.size(0) * i1) + t23_allChains.size(0)
            * t23_allChains.size(1) * i] = t22_allChains[(i2 +
            t22_allChains.size(0) * i1) + t22_allChains.size(0) *
            t22_allChains.size(1) * i];
        }
      }
    }

    t23_outlierChains_size[0] = t22_outlierChains.size(0);
    t23_outlierChains_size[1] = t22_outlierChains.size(1);
    loop_ub = t22_outlierChains.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t22_outlierChains.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t23_outlierChains_data[i1 + t23_outlierChains_size[0] * i] =
          t22_outlierChains[i1 + t22_outlierChains.size(0) * i];
      }
    }

    t23_AR_size[0] = t22_AR.size(0);
    t23_AR_size[1] = t22_AR.size(1);
    loop_ub = t22_AR.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t22_AR.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t23_AR_data[i1 + t23_AR_size[0] * i] = t22_AR[i1 + t22_AR.size(0) * i];
      }
    }

    t23_R_stat.set_size(t22_R_stat.size(0), t22_R_stat.size(1));
    loop_ub = t22_R_stat.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t22_R_stat.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t23_R_stat[i1 + t23_R_stat.size(0) * i] = t22_R_stat[i1 +
          t22_R_stat.size(0) * i];
      }
    }

    t23_CR.set_size(t22_CR.size(0), t22_CR.size(1));
    loop_ub = t22_CR.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t22_CR.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t23_CR[i1 + t23_CR.size(0) * i] = t22_CR[i1 + t22_CR.size(0) * i];
      }
    }

    *t23_runtime = t22_runtime;
    *t23_iteration = t22_iteration;
    *t23_modelOutput = t22_modelOutput;
  }

  void b_makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains, ::
    coder::array<cell_wrap_11, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_11,
    2U> &bayesResults_predictionIntervals_sld, ::coder::array<cell_wrap_12, 1U>
    &bayesResults_predictionIntervals_reflectivityXData, ::coder::array<
    cell_wrap_12, 2U> &bayesResults_predictionIntervals_sldXData, real_T
    bayesResults_predictionIntervals_sampleChi_data[], int32_T
    *bayesResults_predictionIntervals_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_mean, struct11_T *bayesResults_dreamParams,
    struct12_T *bayesResults_dreamOutput, c_struct_T
    *bayesResults_nestedSamplerOutput, ::coder::array<real_T, 2U>
    &bayesResults_chain)
  {
    ::coder::array<cell_wrap_11, 2U> b_f1;
    ::coder::array<cell_wrap_11, 1U> f1;
    ::coder::array<cell_wrap_12, 2U> d_f1;
    ::coder::array<cell_wrap_12, 1U> c_f1;
    ::coder::array<real_T, 3U> t28_allChains;
    ::coder::array<real_T, 2U> t28_AR;
    ::coder::array<real_T, 2U> t28_CR;
    ::coder::array<real_T, 2U> t28_R_stat;
    ::coder::array<real_T, 2U> t28_outlierChains;
    ::coder::array<real_T, 1U> e_f1;
    cell_wrap_36 r4;
    cell_wrap_38 r;
    cell_wrap_39 r1;
    cell_wrap_40 r2;
    cell_wrap_41 r3;
    real_T t29_percentile65_data[2000];
    real_T t29_percentile95_data[2000];
    real_T t29_mean_data[1000];
    int32_T t29_mean_size[2];
    int32_T t29_percentile65_size[2];
    int32_T t29_percentile95_size[2];
    int32_T b_i;
    int32_T i;
    int32_T i1;

    //  A function to make an empty container to hold the results of bayes
    //  calculations. The struct has the following format:
    //
    //  nParams = number of fitted parameters
    //  nContrasts = number of contrasts
    //
    //  bayesResults =
    //
    //    struct with fields:
    //
    //  predictionIntervals: [1×1 struct]
    //  confidenceIntervals: [1×1 struct]
    //            allChains: [1×1 struct]
    //          dreamParams: [1×1 struct]
    //          dreamOutput: [1×1 struct]
    //  nestedSamplerOutput: [1×1 struct]
    //                chain: [1000000xnParams double]
    //  -----------------------------------------------------------
    //  Make the individual structs....
    //  (1) bayesResults.predictionIntervals
    i = static_cast<int32_T>(nContrasts);
    f1.set_size(i);
    for (b_i = 0; b_i < i; b_i++) {
      f1[b_i].f1.set_size(5, 1);
      for (i1 = 0; i1 < 5; i1++) {
        f1[b_i].f1[i1] = 1.0;
      }
    }

    if (isDomains) {
      b_f1.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(5, 1);
        b_f1[b_i + b_f1.size(0)].f1.set_size(5, 1);
        for (i1 = 0; i1 < 5; i1++) {
          b_f1[b_i].f1[i1] = 1.0;
          b_f1[b_i + b_f1.size(0)].f1[i1] = 1.0;
        }
      }
    } else {
      b_f1.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(5, 1);
        for (i1 = 0; i1 < 5; i1++) {
          b_f1[b_i].f1[i1] = 1.0;
        }
      }
    }

    c_f1.set_size(i);
    for (b_i = 0; b_i < i; b_i++) {
      c_f1[b_i].f1.set_size(1, 3);
      c_f1[b_i].f1[0] = 1.0;
      c_f1[b_i].f1[1] = 1.0;
      c_f1[b_i].f1[2] = 1.0;
    }

    if (isDomains) {
      d_f1.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        d_f1[b_i].f1.set_size(1, 3);
        d_f1[b_i + d_f1.size(0)].f1.set_size(1, 3);
        d_f1[b_i].f1[0] = 1.0;
        d_f1[b_i + d_f1.size(0)].f1[0] = 1.0;
        d_f1[b_i].f1[1] = 1.0;
        d_f1[b_i + d_f1.size(0)].f1[1] = 1.0;
        d_f1[b_i].f1[2] = 1.0;
        d_f1[b_i + d_f1.size(0)].f1[2] = 1.0;
      }
    } else {
      d_f1.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        d_f1[b_i].f1.set_size(1, 3);
        d_f1[b_i].f1[0] = 1.0;
        d_f1[b_i].f1[1] = 1.0;
        d_f1[b_i].f1[2] = 1.0;
      }
    }

    e_f1.set_size(1);
    e_f1[0] = 0.0;
    r.f1 = f1;
    r1.f1 = b_f1;
    r2.f1 = c_f1;
    r3.f1 = d_f1;
    r4.f1 = e_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2, &r3, &r4,
      bayesResults_predictionIntervals_reflectivity,
      bayesResults_predictionIntervals_sld,
      bayesResults_predictionIntervals_reflectivityXData,
      bayesResults_predictionIntervals_sldXData,
      bayesResults_predictionIntervals_sampleChi_data,
      bayesResults_predictionIntervals_sampleChi_size);

    //  ------------------------------------------------------------------
    //  (2) bayesResults.confidenceIntervals
    t29_percentile95_size[0] = 2;
    t29_percentile95_size[1] = 1;
    t29_percentile65_size[0] = 2;
    t29_percentile65_size[1] = 1;
    t29_percentile95_data[0] = 0.0;
    t29_percentile65_data[0] = 0.0;
    t29_percentile95_data[1] = 0.0;
    t29_percentile65_data[1] = 0.0;
    t29_mean_size[0] = 1;
    t29_mean_size[1] = 1;
    t29_mean_data[0] = 0.0;
    cast(t29_percentile95_data, t29_percentile95_size, t29_percentile65_data,
         t29_percentile65_size, t29_mean_data, t29_mean_size,
         bayesResults_confidenceIntervals_percentile95,
         bayesResults_confidenceIntervals_percentile65,
         bayesResults_confidenceIntervals_mean);

    //  -------------------------------------------------------------------
    //  (3) bayesResults.dreamParams
    bayesResults_dreamParams->R.set_size(1, 1);
    bayesResults_dreamParams->R[0] = 0.0;
    bayesResults_dreamParams->nParams = 17.0;
    bayesResults_dreamParams->nChains = 10.0;
    bayesResults_dreamParams->nGenerations = 1000.0;
    bayesResults_dreamParams->parallel = false;
    bayesResults_dreamParams->CPU = 1.0;
    bayesResults_dreamParams->jumpProbability = 0.5;
    bayesResults_dreamParams->pUnitGamma = 0.2;
    bayesResults_dreamParams->nCR = 3.0;
    bayesResults_dreamParams->delta = 3.0;
    bayesResults_dreamParams->steps = 50.0;
    bayesResults_dreamParams->zeta = 1.0E-12;
    bayesResults_dreamParams->adaptPCR = false;
    bayesResults_dreamParams->thinning = 1.0;
    bayesResults_dreamParams->ABC = false;
    bayesResults_dreamParams->epsilon = 0.025;
    bayesResults_dreamParams->IO = false;
    bayesResults_dreamParams->storeOutput = false;

    //  -------------------------------------------------------------------
    //  (4) bayesResults.dreamOutput
    t28_allChains.set_size(1, 3, 1);
    bayesResults_dreamParams->outlier[0] = 'i';
    t28_allChains[0] = 1.0;
    bayesResults_dreamParams->outlier[1] = 'q';
    t28_allChains[t28_allChains.size(0)] = 1.0;
    bayesResults_dreamParams->outlier[2] = 'r';
    t28_allChains[t28_allChains.size(0) * 2] = 1.0;
    t28_outlierChains.set_size(1, 2);
    t28_AR.set_size(1, 2);
    t28_R_stat.set_size(1, 2);
    t28_CR.set_size(1, 2);

    //  -------------------------------------------------------------------
    //  (5) bayesResults.nestedSamplerOutput
    //  Nested Sampler
    bayesResults_nestedSamplerOutput->nestSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->nestSamples.size[1] = 2;
    bayesResults_nestedSamplerOutput->postSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->postSamples.size[1] = 2;
    t28_outlierChains[0] = 1.0;
    t28_AR[0] = 0.0;
    t28_R_stat[0] = 0.0;
    t28_CR[0] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[0] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[0] = 0.0;
    t28_outlierChains[t28_outlierChains.size(0)] = 1.0;
    t28_AR[t28_AR.size(0)] = 0.0;
    t28_R_stat[t28_R_stat.size(0)] = 0.0;
    t28_CR[t28_CR.size(0)] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[1] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[1] = 0.0;
    cast(t28_allChains, t28_outlierChains, 100.0, 0.0, 0.0, t28_AR, t28_R_stat,
         t28_CR, bayesResults_dreamOutput->allChains,
         bayesResults_dreamOutput->outlierChains.data,
         bayesResults_dreamOutput->outlierChains.size,
         &bayesResults_dreamOutput->runtime,
         &bayesResults_dreamOutput->iteration,
         &bayesResults_dreamOutput->modelOutput,
         bayesResults_dreamOutput->AR.data, bayesResults_dreamOutput->AR.size,
         bayesResults_dreamOutput->R_stat, bayesResults_dreamOutput->CR);
    bayesResults_nestedSamplerOutput->LogZ = 0.0;

    //  ------------------------------------------------------------------
    //  (6) chain
    bayesResults_chain.set_size(1, 2);
    bayesResults_chain[0] = 0.0;
    bayesResults_chain[bayesResults_chain.size(0)] = 0.0;

    //  -------------------------------------------------------------------
    //  Make the final structure...
  }

  void makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains,
    real_T nChains, ::coder::array<cell_wrap_11, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_11,
    2U> &bayesResults_predictionIntervals_sld, ::coder::array<cell_wrap_12, 1U>
    &bayesResults_predictionIntervals_reflectivityXData, ::coder::array<
    cell_wrap_12, 2U> &bayesResults_predictionIntervals_sldXData, real_T
    bayesResults_predictionIntervals_sampleChi_data[], int32_T
    *bayesResults_predictionIntervals_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_mean, struct11_T *bayesResults_dreamParams,
    struct12_T *bayesResults_dreamOutput, c_struct_T
    *bayesResults_nestedSamplerOutput, ::coder::array<real_T, 2U>
    &bayesResults_chain)
  {
    ::coder::array<cell_wrap_11, 2U> b_f1;
    ::coder::array<cell_wrap_11, 1U> f1;
    ::coder::array<cell_wrap_12, 2U> d_f1;
    ::coder::array<cell_wrap_12, 1U> c_f1;
    ::coder::array<real_T, 3U> t26_allChains;
    ::coder::array<real_T, 2U> t26_AR;
    ::coder::array<real_T, 2U> t26_CR;
    ::coder::array<real_T, 2U> t26_R_stat;
    ::coder::array<real_T, 2U> t26_outlierChains;
    ::coder::array<real_T, 1U> e_f1;
    cell_wrap_36 r4;
    cell_wrap_38 r;
    cell_wrap_39 r1;
    cell_wrap_40 r2;
    cell_wrap_41 r3;
    real_T t27_percentile65_data[2000];
    real_T t27_percentile95_data[2000];
    real_T t27_mean_data[1000];
    int32_T t27_mean_size[2];
    int32_T t27_percentile65_size[2];
    int32_T t27_percentile95_size[2];
    int32_T b_i;
    int32_T i;
    int32_T i1;
    int32_T loop_ub_tmp;

    //  A function to make an empty container to hold the results of bayes
    //  calculations. The struct has the following format:
    //
    //  nParams = number of fitted parameters
    //  nContrasts = number of contrasts
    //
    //  bayesResults =
    //
    //    struct with fields:
    //
    //  predictionIntervals: [1×1 struct]
    //  confidenceIntervals: [1×1 struct]
    //            allChains: [1×1 struct]
    //          dreamParams: [1×1 struct]
    //          dreamOutput: [1×1 struct]
    //  nestedSamplerOutput: [1×1 struct]
    //                chain: [1000000xnParams double]
    //  -----------------------------------------------------------
    //  Make the individual structs....
    //  (1) bayesResults.predictionIntervals
    i = static_cast<int32_T>(nContrasts);
    f1.set_size(i);
    for (b_i = 0; b_i < i; b_i++) {
      f1[b_i].f1.set_size(5, 1);
      for (i1 = 0; i1 < 5; i1++) {
        f1[b_i].f1[i1] = 1.0;
      }
    }

    if (isDomains) {
      b_f1.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(5, 1);
        b_f1[b_i + b_f1.size(0)].f1.set_size(5, 1);
        for (i1 = 0; i1 < 5; i1++) {
          b_f1[b_i].f1[i1] = 1.0;
          b_f1[b_i + b_f1.size(0)].f1[i1] = 1.0;
        }
      }
    } else {
      b_f1.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(5, 1);
        for (i1 = 0; i1 < 5; i1++) {
          b_f1[b_i].f1[i1] = 1.0;
        }
      }
    }

    c_f1.set_size(i);
    for (b_i = 0; b_i < i; b_i++) {
      c_f1[b_i].f1.set_size(1, 3);
      c_f1[b_i].f1[0] = 1.0;
      c_f1[b_i].f1[1] = 1.0;
      c_f1[b_i].f1[2] = 1.0;
    }

    if (isDomains) {
      d_f1.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        d_f1[b_i].f1.set_size(1, 3);
        d_f1[b_i + d_f1.size(0)].f1.set_size(1, 3);
        d_f1[b_i].f1[0] = 1.0;
        d_f1[b_i + d_f1.size(0)].f1[0] = 1.0;
        d_f1[b_i].f1[1] = 1.0;
        d_f1[b_i + d_f1.size(0)].f1[1] = 1.0;
        d_f1[b_i].f1[2] = 1.0;
        d_f1[b_i + d_f1.size(0)].f1[2] = 1.0;
      }
    } else {
      d_f1.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        d_f1[b_i].f1.set_size(1, 3);
        d_f1[b_i].f1[0] = 1.0;
        d_f1[b_i].f1[1] = 1.0;
        d_f1[b_i].f1[2] = 1.0;
      }
    }

    e_f1.set_size(1);
    e_f1[0] = 0.0;
    r.f1 = f1;
    r1.f1 = b_f1;
    r2.f1 = c_f1;
    r3.f1 = d_f1;
    r4.f1 = e_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2, &r3, &r4,
      bayesResults_predictionIntervals_reflectivity,
      bayesResults_predictionIntervals_sld,
      bayesResults_predictionIntervals_reflectivityXData,
      bayesResults_predictionIntervals_sldXData,
      bayesResults_predictionIntervals_sampleChi_data,
      bayesResults_predictionIntervals_sampleChi_size);

    //  ------------------------------------------------------------------
    //  (2) bayesResults.confidenceIntervals
    t27_percentile95_size[0] = 2;
    t27_percentile95_size[1] = 1;
    t27_percentile65_size[0] = 2;
    t27_percentile65_size[1] = 1;
    t27_percentile95_data[0] = 0.0;
    t27_percentile65_data[0] = 0.0;
    t27_percentile95_data[1] = 0.0;
    t27_percentile65_data[1] = 0.0;
    t27_mean_size[0] = 1;
    t27_mean_size[1] = 1;
    t27_mean_data[0] = 0.0;
    cast(t27_percentile95_data, t27_percentile95_size, t27_percentile65_data,
         t27_percentile65_size, t27_mean_data, t27_mean_size,
         bayesResults_confidenceIntervals_percentile95,
         bayesResults_confidenceIntervals_percentile65,
         bayesResults_confidenceIntervals_mean);

    //  -------------------------------------------------------------------
    //  (3) bayesResults.dreamParams
    loop_ub_tmp = static_cast<int32_T>(nChains);
    bayesResults_dreamParams->R.set_size(loop_ub_tmp, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        bayesResults_dreamParams->R[i1 + bayesResults_dreamParams->R.size(0) * i]
          = 0.0;
      }
    }

    bayesResults_dreamParams->nParams = 17.0;
    bayesResults_dreamParams->nChains = 10.0;
    bayesResults_dreamParams->nGenerations = 1000.0;
    bayesResults_dreamParams->parallel = false;
    bayesResults_dreamParams->CPU = 1.0;
    bayesResults_dreamParams->jumpProbability = 0.5;
    bayesResults_dreamParams->pUnitGamma = 0.2;
    bayesResults_dreamParams->nCR = 3.0;
    bayesResults_dreamParams->delta = 3.0;
    bayesResults_dreamParams->steps = 50.0;
    bayesResults_dreamParams->zeta = 1.0E-12;
    bayesResults_dreamParams->adaptPCR = false;
    bayesResults_dreamParams->thinning = 1.0;
    bayesResults_dreamParams->ABC = false;
    bayesResults_dreamParams->epsilon = 0.025;
    bayesResults_dreamParams->IO = false;
    bayesResults_dreamParams->storeOutput = false;

    //  -------------------------------------------------------------------
    //  (4) bayesResults.dreamOutput
    t26_allChains.set_size(1, 3, 1);
    bayesResults_dreamParams->outlier[0] = 'i';
    t26_allChains[0] = 1.0;
    bayesResults_dreamParams->outlier[1] = 'q';
    t26_allChains[t26_allChains.size(0)] = 1.0;
    bayesResults_dreamParams->outlier[2] = 'r';
    t26_allChains[t26_allChains.size(0) * 2] = 1.0;
    t26_outlierChains.set_size(1, 2);
    t26_AR.set_size(1, 2);
    t26_R_stat.set_size(1, 2);
    t26_CR.set_size(1, 2);

    //  -------------------------------------------------------------------
    //  (5) bayesResults.nestedSamplerOutput
    //  Nested Sampler
    bayesResults_nestedSamplerOutput->nestSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->nestSamples.size[1] = 2;
    bayesResults_nestedSamplerOutput->postSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->postSamples.size[1] = 2;
    t26_outlierChains[0] = 1.0;
    t26_AR[0] = 0.0;
    t26_R_stat[0] = 0.0;
    t26_CR[0] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[0] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[0] = 0.0;
    t26_outlierChains[t26_outlierChains.size(0)] = 1.0;
    t26_AR[t26_AR.size(0)] = 0.0;
    t26_R_stat[t26_R_stat.size(0)] = 0.0;
    t26_CR[t26_CR.size(0)] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[1] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[1] = 0.0;
    cast(t26_allChains, t26_outlierChains, 100.0, 0.0, 0.0, t26_AR, t26_R_stat,
         t26_CR, bayesResults_dreamOutput->allChains,
         bayesResults_dreamOutput->outlierChains.data,
         bayesResults_dreamOutput->outlierChains.size,
         &bayesResults_dreamOutput->runtime,
         &bayesResults_dreamOutput->iteration,
         &bayesResults_dreamOutput->modelOutput,
         bayesResults_dreamOutput->AR.data, bayesResults_dreamOutput->AR.size,
         bayesResults_dreamOutput->R_stat, bayesResults_dreamOutput->CR);
    bayesResults_nestedSamplerOutput->LogZ = 0.0;

    //  ------------------------------------------------------------------
    //  (6) chain
    bayesResults_chain.set_size(1, 2);
    bayesResults_chain[0] = 0.0;
    bayesResults_chain[bayesResults_chain.size(0)] = 0.0;

    //  -------------------------------------------------------------------
    //  Make the final structure...
  }
}

// End of code generation (makeEmptyBayesResultsStruct.cpp)
