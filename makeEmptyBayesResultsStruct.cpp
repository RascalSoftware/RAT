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
  static void cast(const real_T t2_percentile95_data[], const int32_T
                   t2_percentile95_size[2], const real_T t2_percentile65_data[],
                   const int32_T t2_percentile65_size[2], const real_T
                   t2_mean_data[], const int32_T t2_mean_size[2], ::coder::array<
                   real_T, 2U> &t3_percentile95, ::coder::array<real_T, 2U>
                   &t3_percentile65, ::coder::array<real_T, 2U> &t3_mean);
  static void cast(const ::coder::array<real_T, 3U> &t0_allChains, const ::coder::
                   array<real_T, 2U> &t0_outlierChains, real_T t0_runtime,
                   real_T t0_iteration, real_T t0_modelOutput, const ::coder::
                   array<real_T, 2U> &t0_AR, const ::coder::array<real_T, 2U>
                   &t0_R_stat, const ::coder::array<real_T, 2U> &t0_CR, ::coder::
                   array<real_T, 3U> &t1_allChains, real_T
                   t1_outlierChains_data[], int32_T t1_outlierChains_size[2],
                   real_T *t1_runtime, real_T *t1_iteration, real_T
                   *t1_modelOutput, real_T t1_AR_data[], int32_T t1_AR_size[2], ::
                   coder::array<real_T, 2U> &t1_R_stat, ::coder::array<real_T,
                   2U> &t1_CR);
}

// Function Definitions
namespace RAT
{
  static void cast(const real_T t2_percentile95_data[], const int32_T
                   t2_percentile95_size[2], const real_T t2_percentile65_data[],
                   const int32_T t2_percentile65_size[2], const real_T
                   t2_mean_data[], const int32_T t2_mean_size[2], ::coder::array<
                   real_T, 2U> &t3_percentile95, ::coder::array<real_T, 2U>
                   &t3_percentile65, ::coder::array<real_T, 2U> &t3_mean)
  {
    int32_T i;
    int32_T loop_ub;
    t3_percentile95.set_size(2, t2_percentile95_size[1]);
    loop_ub = t2_percentile95_size[1];
    for (i = 0; i < loop_ub; i++) {
      t3_percentile95[2 * i] = t2_percentile95_data[2 * i];
      t3_percentile95[2 * i + 1] = t2_percentile95_data[2 * i + 1];
    }

    t3_percentile65.set_size(2, t2_percentile65_size[1]);
    loop_ub = t2_percentile65_size[1];
    for (i = 0; i < loop_ub; i++) {
      t3_percentile65[2 * i] = t2_percentile65_data[2 * i];
      t3_percentile65[2 * i + 1] = t2_percentile65_data[2 * i + 1];
    }

    t3_mean.set_size(1, t2_mean_size[1]);
    loop_ub = t2_mean_size[1];
    for (i = 0; i < loop_ub; i++) {
      t3_mean[i] = t2_mean_data[i];
    }
  }

  static void cast(const ::coder::array<real_T, 3U> &t0_allChains, const ::coder::
                   array<real_T, 2U> &t0_outlierChains, real_T t0_runtime,
                   real_T t0_iteration, real_T t0_modelOutput, const ::coder::
                   array<real_T, 2U> &t0_AR, const ::coder::array<real_T, 2U>
                   &t0_R_stat, const ::coder::array<real_T, 2U> &t0_CR, ::coder::
                   array<real_T, 3U> &t1_allChains, real_T
                   t1_outlierChains_data[], int32_T t1_outlierChains_size[2],
                   real_T *t1_runtime, real_T *t1_iteration, real_T
                   *t1_modelOutput, real_T t1_AR_data[], int32_T t1_AR_size[2], ::
                   coder::array<real_T, 2U> &t1_R_stat, ::coder::array<real_T,
                   2U> &t1_CR)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    t1_allChains.set_size(t0_allChains.size(0), t0_allChains.size(1),
                          t0_allChains.size(2));
    loop_ub = t0_allChains.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t0_allChains.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        int32_T c_loop_ub;
        c_loop_ub = t0_allChains.size(0);
        for (int32_T i2{0}; i2 < c_loop_ub; i2++) {
          t1_allChains[(i2 + t1_allChains.size(0) * i1) + t1_allChains.size(0) *
            t1_allChains.size(1) * i] = t0_allChains[(i2 + t0_allChains.size(0) *
            i1) + t0_allChains.size(0) * t0_allChains.size(1) * i];
        }
      }
    }

    t1_outlierChains_size[0] = t0_outlierChains.size(0);
    t1_outlierChains_size[1] = t0_outlierChains.size(1);
    loop_ub = t0_outlierChains.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t0_outlierChains.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t1_outlierChains_data[i1 + t1_outlierChains_size[0] * i] =
          t0_outlierChains[i1 + t0_outlierChains.size(0) * i];
      }
    }

    t1_AR_size[0] = t0_AR.size(0);
    t1_AR_size[1] = t0_AR.size(1);
    loop_ub = t0_AR.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t0_AR.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t1_AR_data[i1 + t1_AR_size[0] * i] = t0_AR[i1 + t0_AR.size(0) * i];
      }
    }

    t1_R_stat.set_size(t0_R_stat.size(0), t0_R_stat.size(1));
    loop_ub = t0_R_stat.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t0_R_stat.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t1_R_stat[i1 + t1_R_stat.size(0) * i] = t0_R_stat[i1 + t0_R_stat.size(0)
          * i];
      }
    }

    t1_CR.set_size(t0_CR.size(0), t0_CR.size(1));
    loop_ub = t0_CR.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t0_CR.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t1_CR[i1 + t1_CR.size(0) * i] = t0_CR[i1 + t0_CR.size(0) * i];
      }
    }

    *t1_runtime = t0_runtime;
    *t1_iteration = t0_iteration;
    *t1_modelOutput = t0_modelOutput;
  }

  void b_makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains, ::
    coder::array<cell_wrap_10, 1U> &bayesResults_bestFitMean_reflectivity, ::
    coder::array<cell_wrap_10, 2U> &bayesResults_bestFitMean_sld, real_T
    *bayesResults_bestFitMean_chi, ::coder::array<cell_wrap_10, 1U>
    &bayesResults_bestFitMean_data, ::coder::array<cell_wrap_10, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_10,
    2U> &bayesResults_predictionIntervals_sld, ::coder::array<cell_wrap_10, 1U>
    &bayesResults_predictionIntervals_reflectivityXData, ::coder::array<
    cell_wrap_10, 2U> &bayesResults_predictionIntervals_sldXData, real_T
    bayesResults_predictionIntervals_sampleChi_data[], int32_T
    *bayesResults_predictionIntervals_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_mean, struct12_T *bayesResults_dreamParams,
    struct13_T *bayesResults_dreamOutput, e_struct_T
    *bayesResults_nestedSamplerOutput, ::coder::array<real_T, 2U>
    &bayesResults_chain)
  {
    ::coder::array<cell_wrap_10, 2U> b_f1;
    ::coder::array<cell_wrap_10, 2U> e_f1;
    ::coder::array<cell_wrap_10, 2U> g_f1;
    ::coder::array<cell_wrap_10, 1U> c_f1;
    ::coder::array<cell_wrap_10, 1U> d_f1;
    ::coder::array<cell_wrap_10, 1U> f1;
    ::coder::array<cell_wrap_10, 1U> f_f1;
    ::coder::array<real_T, 3U> t4_allChains;
    ::coder::array<real_T, 2U> t4_AR;
    ::coder::array<real_T, 2U> t4_CR;
    ::coder::array<real_T, 2U> t4_R_stat;
    ::coder::array<real_T, 2U> t4_outlierChains;
    ::coder::array<real_T, 1U> h_f1;
    cell_wrap_29 r1;
    cell_wrap_29 r3;
    cell_wrap_34 r;
    cell_wrap_34 r2;
    cell_wrap_36 r4;
    real_T t5_percentile65_data[2000];
    real_T t5_percentile95_data[2000];
    real_T t5_mean_data[1000];
    int32_T t5_mean_size[2];
    int32_T t5_percentile65_size[2];
    int32_T t5_percentile95_size[2];
    int32_T b_i;
    int32_T i;

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
    //          bestFitMean: [1×1 struct]
    //  predictionIntervals: [1×1 struct]
    //  confidenceIntervals: [1×1 struct]
    //            allChains: [1×1 struct]
    //          dreamParams: [1×1 struct]
    //          dreamOutput: [1×1 struct]
    //  nestedSamplerOutput: [1×1 struct]
    //                chain: [1000000xnParams double]
    //  -----------------------------------------------------------
    //  Make the individual structs....
    //  (1) bayesResults.bestFitMean
    i = static_cast<int32_T>(nContrasts);
    f1.set_size(i);
    for (b_i = 0; b_i < i; b_i++) {
      f1[b_i].f1.set_size(1, 3);
      f1[b_i].f1[0] = 1.0;
      f1[b_i].f1[f1[b_i].f1.size(0)] = 1.0;
      f1[b_i].f1[f1[b_i].f1.size(0) * 2] = 1.0;
    }

    if (isDomains) {
      b_f1.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(2, 2);
        b_f1[b_i + b_f1.size(0)].f1.set_size(2, 2);
        b_f1[b_i].f1[0] = 1.0;
        b_f1[b_i + b_f1.size(0)].f1[0] = 1.0;
        b_f1[b_i].f1[1] = 1.0;
        b_f1[b_i + b_f1.size(0)].f1[1] = 1.0;
        b_f1[b_i].f1[b_f1[b_i].f1.size(0)] = 1.0;
        b_f1[b_i + b_f1.size(0)].f1[b_f1[b_i + b_f1.size(0)].f1.size(0)] = 1.0;
        b_f1[b_i].f1[b_f1[b_i].f1.size(0) + 1] = 1.0;
        b_f1[b_i + b_f1.size(0)].f1[b_f1[b_i + b_f1.size(0)].f1.size(0) + 1] =
          1.0;
      }
    } else {
      b_f1.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(1, 2);
        b_f1[b_i].f1[0] = 1.0;
        b_f1[b_i].f1[b_f1[b_i].f1.size(0)] = 1.0;
      }
    }

    c_f1.set_size(i);
    r.f1 = f1;
    r1.f1 = b_f1;

    //  --------------------------------------------------------------------
    //  (2) bayesResults.predictionIntervals
    d_f1.set_size(i);
    for (b_i = 0; b_i < i; b_i++) {
      c_f1[b_i].f1.set_size(1, 3);
      c_f1[b_i].f1[0] = 1.0;
      c_f1[b_i].f1[c_f1[b_i].f1.size(0)] = 1.0;
      c_f1[b_i].f1[c_f1[b_i].f1.size(0) * 2] = 1.0;
      d_f1[b_i].f1.set_size(1, 3);
      d_f1[b_i].f1[0] = 1.0;
      d_f1[b_i].f1[d_f1[b_i].f1.size(0)] = 1.0;
      d_f1[b_i].f1[d_f1[b_i].f1.size(0) * 2] = 1.0;
    }

    r2.f1 = c_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2,
      bayesResults_bestFitMean_reflectivity, bayesResults_bestFitMean_sld,
      bayesResults_bestFitMean_chi, bayesResults_bestFitMean_data);
    if (isDomains) {
      e_f1.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        e_f1[b_i].f1.set_size(1, 3);
        e_f1[b_i + e_f1.size(0)].f1.set_size(1, 3);
        e_f1[b_i].f1[0] = 1.0;
        e_f1[b_i + e_f1.size(0)].f1[0] = 1.0;
        e_f1[b_i].f1[e_f1[b_i].f1.size(0)] = 1.0;
        e_f1[b_i + e_f1.size(0)].f1[e_f1[b_i + e_f1.size(0)].f1.size(0)] = 1.0;
        e_f1[b_i].f1[e_f1[b_i].f1.size(0) * 2] = 1.0;
        e_f1[b_i + e_f1.size(0)].f1[e_f1[b_i + e_f1.size(0)].f1.size(0) * 2] =
          1.0;
      }
    } else {
      e_f1.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        e_f1[b_i].f1.set_size(1, 3);
        e_f1[b_i].f1[0] = 1.0;
        e_f1[b_i].f1[e_f1[b_i].f1.size(0)] = 1.0;
        e_f1[b_i].f1[e_f1[b_i].f1.size(0) * 2] = 1.0;
      }
    }

    f_f1.set_size(i);
    for (b_i = 0; b_i < i; b_i++) {
      f_f1[b_i].f1.set_size(1, 3);
      f_f1[b_i].f1[0] = 1.0;
      f_f1[b_i].f1[f_f1[b_i].f1.size(0)] = 1.0;
      f_f1[b_i].f1[f_f1[b_i].f1.size(0) * 2] = 1.0;
    }

    if (isDomains) {
      g_f1.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        g_f1[b_i].f1.set_size(2, 3);
        g_f1[b_i + g_f1.size(0)].f1.set_size(2, 3);
        for (int32_T i1{0}; i1 < 3; i1++) {
          g_f1[b_i].f1[g_f1[b_i].f1.size(0) * i1] = 1.0;
          g_f1[b_i + g_f1.size(0)].f1[g_f1[b_i + g_f1.size(0)].f1.size(0) * i1] =
            1.0;
          g_f1[b_i].f1[g_f1[b_i].f1.size(0) * i1 + 1] = 1.0;
          g_f1[b_i + g_f1.size(0)].f1[g_f1[b_i + g_f1.size(0)].f1.size(0) * i1 +
            1] = 1.0;
        }
      }
    } else {
      g_f1.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        g_f1[b_i].f1.set_size(1, 3);
        g_f1[b_i].f1[0] = 1.0;
        g_f1[b_i].f1[g_f1[b_i].f1.size(0)] = 1.0;
        g_f1[b_i].f1[g_f1[b_i].f1.size(0) * 2] = 1.0;
      }
    }

    h_f1.set_size(1);
    h_f1[0] = 0.0;
    r.f1 = d_f1;
    r1.f1 = e_f1;
    r2.f1 = f_f1;
    r3.f1 = g_f1;
    r4.f1 = h_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2, &r3, &r4,
      bayesResults_predictionIntervals_reflectivity,
      bayesResults_predictionIntervals_sld,
      bayesResults_predictionIntervals_reflectivityXData,
      bayesResults_predictionIntervals_sldXData,
      bayesResults_predictionIntervals_sampleChi_data,
      bayesResults_predictionIntervals_sampleChi_size);

    //  ------------------------------------------------------------------
    //  (3) bayesResults.confidenceIntervals
    t5_percentile95_size[0] = 2;
    t5_percentile95_size[1] = 1;
    t5_percentile65_size[0] = 2;
    t5_percentile65_size[1] = 1;
    t5_percentile95_data[0] = 0.0;
    t5_percentile65_data[0] = 0.0;
    t5_percentile95_data[1] = 0.0;
    t5_percentile65_data[1] = 0.0;
    t5_mean_size[0] = 1;
    t5_mean_size[1] = 1;
    t5_mean_data[0] = 0.0;
    cast(t5_percentile95_data, t5_percentile95_size, t5_percentile65_data,
         t5_percentile65_size, t5_mean_data, t5_mean_size,
         bayesResults_confidenceIntervals_percentile95,
         bayesResults_confidenceIntervals_percentile65,
         bayesResults_confidenceIntervals_mean);

    //  -------------------------------------------------------------------
    //  (4) bayesResults.dreamParams
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
    //  (5) bayesResults.dreamOutput
    t4_allChains.set_size(1, 3, 1);
    bayesResults_dreamParams->outlier[0] = 'i';
    t4_allChains[0] = 1.0;
    bayesResults_dreamParams->outlier[1] = 'q';
    t4_allChains[t4_allChains.size(0)] = 1.0;
    bayesResults_dreamParams->outlier[2] = 'r';
    t4_allChains[t4_allChains.size(0) * 2] = 1.0;
    t4_outlierChains.set_size(1, 2);
    t4_AR.set_size(1, 2);
    t4_R_stat.set_size(1, 2);
    t4_CR.set_size(1, 2);

    //  -------------------------------------------------------------------
    //  (6) bayesResults.nestedSamplerOutput
    //  Nested Sampler
    bayesResults_nestedSamplerOutput->nestSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->nestSamples.size[1] = 2;
    bayesResults_nestedSamplerOutput->postSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->postSamples.size[1] = 2;
    t4_outlierChains[0] = 1.0;
    t4_AR[0] = 0.0;
    t4_R_stat[0] = 0.0;
    t4_CR[0] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[0] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[0] = 0.0;
    t4_outlierChains[t4_outlierChains.size(0)] = 1.0;
    t4_AR[t4_AR.size(0)] = 0.0;
    t4_R_stat[t4_R_stat.size(0)] = 0.0;
    t4_CR[t4_CR.size(0)] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[1] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[1] = 0.0;
    cast(t4_allChains, t4_outlierChains, 100.0, 0.0, 0.0, t4_AR, t4_R_stat,
         t4_CR, bayesResults_dreamOutput->allChains,
         bayesResults_dreamOutput->outlierChains.data,
         bayesResults_dreamOutput->outlierChains.size,
         &bayesResults_dreamOutput->runtime,
         &bayesResults_dreamOutput->iteration,
         &bayesResults_dreamOutput->modelOutput,
         bayesResults_dreamOutput->AR.data, bayesResults_dreamOutput->AR.size,
         bayesResults_dreamOutput->R_stat, bayesResults_dreamOutput->CR);
    bayesResults_nestedSamplerOutput->LogZ = 0.0;

    //  ------------------------------------------------------------------
    //  (7) chain
    bayesResults_chain.set_size(1, 2);
    bayesResults_chain[0] = 0.0;
    bayesResults_chain[bayesResults_chain.size(0)] = 0.0;

    //  -------------------------------------------------------------------
    //  Make the final structure...
  }

  void makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains,
    real_T nChains, ::coder::array<cell_wrap_10, 1U>
    &bayesResults_bestFitMean_reflectivity, ::coder::array<cell_wrap_10, 2U>
    &bayesResults_bestFitMean_sld, real_T *bayesResults_bestFitMean_chi, ::coder::
    array<cell_wrap_10, 1U> &bayesResults_bestFitMean_data, ::coder::array<
    cell_wrap_10, 1U> &bayesResults_predictionIntervals_reflectivity, ::coder::
    array<cell_wrap_10, 2U> &bayesResults_predictionIntervals_sld, ::coder::
    array<cell_wrap_10, 1U> &bayesResults_predictionIntervals_reflectivityXData,
    ::coder::array<cell_wrap_10, 2U> &bayesResults_predictionIntervals_sldXData,
    real_T bayesResults_predictionIntervals_sampleChi_data[], int32_T
    *bayesResults_predictionIntervals_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_mean, struct12_T *bayesResults_dreamParams,
    struct13_T *bayesResults_dreamOutput, e_struct_T
    *bayesResults_nestedSamplerOutput, ::coder::array<real_T, 2U>
    &bayesResults_chain)
  {
    ::coder::array<cell_wrap_10, 2U> b_f1;
    ::coder::array<cell_wrap_10, 2U> e_f1;
    ::coder::array<cell_wrap_10, 2U> g_f1;
    ::coder::array<cell_wrap_10, 1U> c_f1;
    ::coder::array<cell_wrap_10, 1U> d_f1;
    ::coder::array<cell_wrap_10, 1U> f1;
    ::coder::array<cell_wrap_10, 1U> f_f1;
    ::coder::array<real_T, 3U> t10_allChains;
    ::coder::array<real_T, 2U> t10_AR;
    ::coder::array<real_T, 2U> t10_CR;
    ::coder::array<real_T, 2U> t10_R_stat;
    ::coder::array<real_T, 2U> t10_outlierChains;
    ::coder::array<real_T, 1U> h_f1;
    cell_wrap_29 r1;
    cell_wrap_29 r3;
    cell_wrap_34 r;
    cell_wrap_34 r2;
    cell_wrap_36 r4;
    real_T t11_percentile65_data[2000];
    real_T t11_percentile95_data[2000];
    real_T t11_mean_data[1000];
    int32_T t11_mean_size[2];
    int32_T t11_percentile65_size[2];
    int32_T t11_percentile95_size[2];
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
    //          bestFitMean: [1×1 struct]
    //  predictionIntervals: [1×1 struct]
    //  confidenceIntervals: [1×1 struct]
    //            allChains: [1×1 struct]
    //          dreamParams: [1×1 struct]
    //          dreamOutput: [1×1 struct]
    //  nestedSamplerOutput: [1×1 struct]
    //                chain: [1000000xnParams double]
    //  -----------------------------------------------------------
    //  Make the individual structs....
    //  (1) bayesResults.bestFitMean
    i = static_cast<int32_T>(nContrasts);
    f1.set_size(i);
    for (b_i = 0; b_i < i; b_i++) {
      f1[b_i].f1.set_size(1, 3);
      f1[b_i].f1[0] = 1.0;
      f1[b_i].f1[f1[b_i].f1.size(0)] = 1.0;
      f1[b_i].f1[f1[b_i].f1.size(0) * 2] = 1.0;
    }

    if (isDomains) {
      b_f1.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(2, 2);
        b_f1[b_i + b_f1.size(0)].f1.set_size(2, 2);
        b_f1[b_i].f1[0] = 1.0;
        b_f1[b_i + b_f1.size(0)].f1[0] = 1.0;
        b_f1[b_i].f1[1] = 1.0;
        b_f1[b_i + b_f1.size(0)].f1[1] = 1.0;
        b_f1[b_i].f1[b_f1[b_i].f1.size(0)] = 1.0;
        b_f1[b_i + b_f1.size(0)].f1[b_f1[b_i + b_f1.size(0)].f1.size(0)] = 1.0;
        b_f1[b_i].f1[b_f1[b_i].f1.size(0) + 1] = 1.0;
        b_f1[b_i + b_f1.size(0)].f1[b_f1[b_i + b_f1.size(0)].f1.size(0) + 1] =
          1.0;
      }
    } else {
      b_f1.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(1, 2);
        b_f1[b_i].f1[0] = 1.0;
        b_f1[b_i].f1[b_f1[b_i].f1.size(0)] = 1.0;
      }
    }

    c_f1.set_size(i);
    r.f1 = f1;
    r1.f1 = b_f1;

    //  --------------------------------------------------------------------
    //  (2) bayesResults.predictionIntervals
    d_f1.set_size(i);
    for (b_i = 0; b_i < i; b_i++) {
      c_f1[b_i].f1.set_size(1, 3);
      c_f1[b_i].f1[0] = 1.0;
      c_f1[b_i].f1[c_f1[b_i].f1.size(0)] = 1.0;
      c_f1[b_i].f1[c_f1[b_i].f1.size(0) * 2] = 1.0;
      d_f1[b_i].f1.set_size(1, 3);
      d_f1[b_i].f1[0] = 1.0;
      d_f1[b_i].f1[d_f1[b_i].f1.size(0)] = 1.0;
      d_f1[b_i].f1[d_f1[b_i].f1.size(0) * 2] = 1.0;
    }

    r2.f1 = c_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2,
      bayesResults_bestFitMean_reflectivity, bayesResults_bestFitMean_sld,
      bayesResults_bestFitMean_chi, bayesResults_bestFitMean_data);
    if (isDomains) {
      e_f1.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        e_f1[b_i].f1.set_size(1, 3);
        e_f1[b_i + e_f1.size(0)].f1.set_size(1, 3);
        e_f1[b_i].f1[0] = 1.0;
        e_f1[b_i + e_f1.size(0)].f1[0] = 1.0;
        e_f1[b_i].f1[e_f1[b_i].f1.size(0)] = 1.0;
        e_f1[b_i + e_f1.size(0)].f1[e_f1[b_i + e_f1.size(0)].f1.size(0)] = 1.0;
        e_f1[b_i].f1[e_f1[b_i].f1.size(0) * 2] = 1.0;
        e_f1[b_i + e_f1.size(0)].f1[e_f1[b_i + e_f1.size(0)].f1.size(0) * 2] =
          1.0;
      }
    } else {
      e_f1.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        e_f1[b_i].f1.set_size(1, 3);
        e_f1[b_i].f1[0] = 1.0;
        e_f1[b_i].f1[e_f1[b_i].f1.size(0)] = 1.0;
        e_f1[b_i].f1[e_f1[b_i].f1.size(0) * 2] = 1.0;
      }
    }

    f_f1.set_size(i);
    for (b_i = 0; b_i < i; b_i++) {
      f_f1[b_i].f1.set_size(1, 3);
      f_f1[b_i].f1[0] = 1.0;
      f_f1[b_i].f1[f_f1[b_i].f1.size(0)] = 1.0;
      f_f1[b_i].f1[f_f1[b_i].f1.size(0) * 2] = 1.0;
    }

    if (isDomains) {
      g_f1.set_size(i, 2);
      for (b_i = 0; b_i < i; b_i++) {
        g_f1[b_i].f1.set_size(2, 3);
        g_f1[b_i + g_f1.size(0)].f1.set_size(2, 3);
        for (i1 = 0; i1 < 3; i1++) {
          g_f1[b_i].f1[g_f1[b_i].f1.size(0) * i1] = 1.0;
          g_f1[b_i + g_f1.size(0)].f1[g_f1[b_i + g_f1.size(0)].f1.size(0) * i1] =
            1.0;
          g_f1[b_i].f1[g_f1[b_i].f1.size(0) * i1 + 1] = 1.0;
          g_f1[b_i + g_f1.size(0)].f1[g_f1[b_i + g_f1.size(0)].f1.size(0) * i1 +
            1] = 1.0;
        }
      }
    } else {
      g_f1.set_size(i, 1);
      for (b_i = 0; b_i < i; b_i++) {
        g_f1[b_i].f1.set_size(1, 3);
        g_f1[b_i].f1[0] = 1.0;
        g_f1[b_i].f1[g_f1[b_i].f1.size(0)] = 1.0;
        g_f1[b_i].f1[g_f1[b_i].f1.size(0) * 2] = 1.0;
      }
    }

    h_f1.set_size(1);
    h_f1[0] = 0.0;
    r.f1 = d_f1;
    r1.f1 = e_f1;
    r2.f1 = f_f1;
    r3.f1 = g_f1;
    r4.f1 = h_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2, &r3, &r4,
      bayesResults_predictionIntervals_reflectivity,
      bayesResults_predictionIntervals_sld,
      bayesResults_predictionIntervals_reflectivityXData,
      bayesResults_predictionIntervals_sldXData,
      bayesResults_predictionIntervals_sampleChi_data,
      bayesResults_predictionIntervals_sampleChi_size);

    //  ------------------------------------------------------------------
    //  (3) bayesResults.confidenceIntervals
    t11_percentile95_size[0] = 2;
    t11_percentile95_size[1] = 1;
    t11_percentile65_size[0] = 2;
    t11_percentile65_size[1] = 1;
    t11_percentile95_data[0] = 0.0;
    t11_percentile65_data[0] = 0.0;
    t11_percentile95_data[1] = 0.0;
    t11_percentile65_data[1] = 0.0;
    t11_mean_size[0] = 1;
    t11_mean_size[1] = 1;
    t11_mean_data[0] = 0.0;
    cast(t11_percentile95_data, t11_percentile95_size, t11_percentile65_data,
         t11_percentile65_size, t11_mean_data, t11_mean_size,
         bayesResults_confidenceIntervals_percentile95,
         bayesResults_confidenceIntervals_percentile65,
         bayesResults_confidenceIntervals_mean);

    //  -------------------------------------------------------------------
    //  (4) bayesResults.dreamParams
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
    //  (5) bayesResults.dreamOutput
    t10_allChains.set_size(1, 3, 1);
    bayesResults_dreamParams->outlier[0] = 'i';
    t10_allChains[0] = 1.0;
    bayesResults_dreamParams->outlier[1] = 'q';
    t10_allChains[t10_allChains.size(0)] = 1.0;
    bayesResults_dreamParams->outlier[2] = 'r';
    t10_allChains[t10_allChains.size(0) * 2] = 1.0;
    t10_outlierChains.set_size(1, 2);
    t10_AR.set_size(1, 2);
    t10_R_stat.set_size(1, 2);
    t10_CR.set_size(1, 2);

    //  -------------------------------------------------------------------
    //  (6) bayesResults.nestedSamplerOutput
    //  Nested Sampler
    bayesResults_nestedSamplerOutput->nestSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->nestSamples.size[1] = 2;
    bayesResults_nestedSamplerOutput->postSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->postSamples.size[1] = 2;
    t10_outlierChains[0] = 1.0;
    t10_AR[0] = 0.0;
    t10_R_stat[0] = 0.0;
    t10_CR[0] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[0] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[0] = 0.0;
    t10_outlierChains[t10_outlierChains.size(0)] = 1.0;
    t10_AR[t10_AR.size(0)] = 0.0;
    t10_R_stat[t10_R_stat.size(0)] = 0.0;
    t10_CR[t10_CR.size(0)] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[1] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[1] = 0.0;
    cast(t10_allChains, t10_outlierChains, 100.0, 0.0, 0.0, t10_AR, t10_R_stat,
         t10_CR, bayesResults_dreamOutput->allChains,
         bayesResults_dreamOutput->outlierChains.data,
         bayesResults_dreamOutput->outlierChains.size,
         &bayesResults_dreamOutput->runtime,
         &bayesResults_dreamOutput->iteration,
         &bayesResults_dreamOutput->modelOutput,
         bayesResults_dreamOutput->AR.data, bayesResults_dreamOutput->AR.size,
         bayesResults_dreamOutput->R_stat, bayesResults_dreamOutput->CR);
    bayesResults_nestedSamplerOutput->LogZ = 0.0;

    //  ------------------------------------------------------------------
    //  (7) chain
    bayesResults_chain.set_size(1, 2);
    bayesResults_chain[0] = 0.0;
    bayesResults_chain[bayesResults_chain.size(0)] = 0.0;

    //  -------------------------------------------------------------------
    //  Make the final structure...
  }
}

// End of code generation (makeEmptyBayesResultsStruct.cpp)
