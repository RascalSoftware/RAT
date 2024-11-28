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

// Type Definitions
namespace RAT
{
  struct cell_wrap_47
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_51
  {
    ::coder::array<cell_wrap_47, 1U> f1;
  };

  struct cell_wrap_52
  {
    ::coder::array<cell_wrap_47, 2U> f1;
  };
}

// Function Declarations
namespace RAT
{
  static void cast(const cell_wrap_51 *b, cell_wrap_49 *c);
  static void cast(const cell_wrap_52 *b, cell_wrap_50 *c);
  static void cast(const real_T t28_percentile95_data[], const int32_T
                   t28_percentile95_size[2], const real_T t28_percentile65_data[],
                   const int32_T t28_percentile65_size[2], const real_T
                   t28_mean_data[], const int32_T t28_mean_size[2], ::coder::
                   array<real_T, 2U> &t29_percentile95, ::coder::array<real_T,
                   2U> &t29_percentile65, ::coder::array<real_T, 2U> &t29_mean);
  static void cast(const ::coder::array<real_T, 3U> &t26_allChains, const ::
                   coder::array<real_T, 2U> &t26_outlierChains, real_T
                   t26_runtime, real_T t26_iteration, real_T t26_modelOutput,
                   const ::coder::array<real_T, 2U> &t26_AR, const ::coder::
                   array<real_T, 2U> &t26_R_stat, const ::coder::array<real_T,
                   2U> &t26_CR, ::coder::array<real_T, 3U> &t27_allChains,
                   real_T t27_outlierChains_data[], int32_T
                   t27_outlierChains_size[2], real_T *t27_runtime, real_T
                   *t27_iteration, real_T *t27_modelOutput, real_T t27_AR_data[],
                   int32_T t27_AR_size[2], ::coder::array<real_T, 2U>
                   &t27_R_stat, ::coder::array<real_T, 2U> &t27_CR);
}

// Function Definitions
namespace RAT
{
  static void cast(const cell_wrap_51 *b, cell_wrap_49 *c)
  {
    int32_T i;
    i = b->f1.size(0);
    c->f1.set_size(b->f1.size(0));
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b->f1[i1].f1.size(1);
      c->f1[i1].f1.set_size(5, b->f1[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        for (int32_T i3{0}; i3 < 5; i3++) {
          c->f1[i1].f1[i3 + 5 * i2] = b->f1[i1].f1[i3 + 5 * i2];
        }
      }
    }
  }

  static void cast(const cell_wrap_52 *b, cell_wrap_50 *c)
  {
    int32_T i;
    i = b->f1.size(0) * b->f1.size(1);
    c->f1.set_size(b->f1.size(0), b->f1.size(1));
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = b->f1[i1].f1.size(1);
      c->f1[i1].f1.set_size(5, b->f1[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        for (int32_T i3{0}; i3 < 5; i3++) {
          c->f1[i1].f1[i3 + 5 * i2] = b->f1[i1].f1[i3 + 5 * i2];
        }
      }
    }
  }

  static void cast(const real_T t28_percentile95_data[], const int32_T
                   t28_percentile95_size[2], const real_T t28_percentile65_data[],
                   const int32_T t28_percentile65_size[2], const real_T
                   t28_mean_data[], const int32_T t28_mean_size[2], ::coder::
                   array<real_T, 2U> &t29_percentile95, ::coder::array<real_T,
                   2U> &t29_percentile65, ::coder::array<real_T, 2U> &t29_mean)
  {
    int32_T i;
    int32_T loop_ub;
    t29_percentile95.set_size(2, t28_percentile95_size[1]);
    loop_ub = t28_percentile95_size[1];
    for (i = 0; i < loop_ub; i++) {
      t29_percentile95[2 * i] = t28_percentile95_data[2 * i];
      t29_percentile95[2 * i + 1] = t28_percentile95_data[2 * i + 1];
    }

    t29_percentile65.set_size(2, t28_percentile65_size[1]);
    loop_ub = t28_percentile65_size[1];
    for (i = 0; i < loop_ub; i++) {
      t29_percentile65[2 * i] = t28_percentile65_data[2 * i];
      t29_percentile65[2 * i + 1] = t28_percentile65_data[2 * i + 1];
    }

    t29_mean.set_size(1, t28_mean_size[1]);
    loop_ub = t28_mean_size[1];
    for (i = 0; i < loop_ub; i++) {
      t29_mean[i] = t28_mean_data[i];
    }
  }

  static void cast(const ::coder::array<real_T, 3U> &t26_allChains, const ::
                   coder::array<real_T, 2U> &t26_outlierChains, real_T
                   t26_runtime, real_T t26_iteration, real_T t26_modelOutput,
                   const ::coder::array<real_T, 2U> &t26_AR, const ::coder::
                   array<real_T, 2U> &t26_R_stat, const ::coder::array<real_T,
                   2U> &t26_CR, ::coder::array<real_T, 3U> &t27_allChains,
                   real_T t27_outlierChains_data[], int32_T
                   t27_outlierChains_size[2], real_T *t27_runtime, real_T
                   *t27_iteration, real_T *t27_modelOutput, real_T t27_AR_data[],
                   int32_T t27_AR_size[2], ::coder::array<real_T, 2U>
                   &t27_R_stat, ::coder::array<real_T, 2U> &t27_CR)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    t27_allChains.set_size(t26_allChains.size(0), t26_allChains.size(1),
      t26_allChains.size(2));
    loop_ub = t26_allChains.size(2);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t26_allChains.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        int32_T c_loop_ub;
        c_loop_ub = t26_allChains.size(0);
        for (int32_T i2{0}; i2 < c_loop_ub; i2++) {
          t27_allChains[(i2 + t27_allChains.size(0) * i1) + t27_allChains.size(0)
            * t27_allChains.size(1) * i] = t26_allChains[(i2 +
            t26_allChains.size(0) * i1) + t26_allChains.size(0) *
            t26_allChains.size(1) * i];
        }
      }
    }

    t27_outlierChains_size[0] = t26_outlierChains.size(0);
    t27_outlierChains_size[1] = t26_outlierChains.size(1);
    loop_ub = t26_outlierChains.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t26_outlierChains.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t27_outlierChains_data[i1 + t27_outlierChains_size[0] * i] =
          t26_outlierChains[i1 + t26_outlierChains.size(0) * i];
      }
    }

    t27_AR_size[0] = t26_AR.size(0);
    t27_AR_size[1] = t26_AR.size(1);
    loop_ub = t26_AR.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t26_AR.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t27_AR_data[i1 + t27_AR_size[0] * i] = t26_AR[i1 + t26_AR.size(0) * i];
      }
    }

    t27_R_stat.set_size(t26_R_stat.size(0), t26_R_stat.size(1));
    loop_ub = t26_R_stat.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t26_R_stat.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t27_R_stat[i1 + t27_R_stat.size(0) * i] = t26_R_stat[i1 +
          t26_R_stat.size(0) * i];
      }
    }

    t27_CR.set_size(t26_CR.size(0), t26_CR.size(1));
    loop_ub = t26_CR.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t26_CR.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        t27_CR[i1 + t27_CR.size(0) * i] = t26_CR[i1 + t26_CR.size(0) * i];
      }
    }

    *t27_runtime = t26_runtime;
    *t27_iteration = t26_iteration;
    *t27_modelOutput = t26_modelOutput;
  }

  void b_makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains, ::
    coder::array<cell_wrap_11, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_11,
    2U> &bayesResults_predictionIntervals_sld, real_T
    bayesResults_predictionIntervals_sampleChi_data[], int32_T
    *bayesResults_predictionIntervals_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_mean, struct12_T *bayesResults_dreamParams,
    struct13_T *bayesResults_dreamOutput, c_struct_T
    *bayesResults_nestedSamplerOutput, ::coder::array<real_T, 2U>
    &bayesResults_chain)
  {
    ::coder::array<cell_wrap_47, 2U> b_f1;
    ::coder::array<cell_wrap_47, 1U> f1;
    ::coder::array<real_T, 3U> t32_allChains;
    ::coder::array<real_T, 2U> t32_AR;
    ::coder::array<real_T, 2U> t32_CR;
    ::coder::array<real_T, 2U> t32_R_stat;
    ::coder::array<real_T, 2U> t32_outlierChains;
    ::coder::array<real_T, 1U> c_f1;
    cell_wrap_45 r2;
    cell_wrap_49 r3;
    cell_wrap_50 r4;
    cell_wrap_51 r;
    cell_wrap_52 r1;
    real_T t33_percentile65_data[2000];
    real_T t33_percentile95_data[2000];
    real_T t33_mean_data[1000];
    int32_T t33_mean_size[2];
    int32_T t33_percentile65_size[2];
    int32_T t33_percentile95_size[2];
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

    c_f1.set_size(1);
    c_f1[0] = 0.0;
    r.f1 = f1;
    r1.f1 = b_f1;
    r2.f1 = c_f1;
    cast(&r, &r3);
    cast(&r1, &r4);
    coder::internal::structConstructorHelper(&r3, &r4, &r2,
      bayesResults_predictionIntervals_reflectivity,
      bayesResults_predictionIntervals_sld,
      bayesResults_predictionIntervals_sampleChi_data,
      bayesResults_predictionIntervals_sampleChi_size);

    //  ------------------------------------------------------------------
    //  (2) bayesResults.confidenceIntervals
    t33_percentile95_size[0] = 2;
    t33_percentile95_size[1] = 1;
    t33_percentile65_size[0] = 2;
    t33_percentile65_size[1] = 1;
    t33_percentile95_data[0] = 0.0;
    t33_percentile65_data[0] = 0.0;
    t33_percentile95_data[1] = 0.0;
    t33_percentile65_data[1] = 0.0;
    t33_mean_size[0] = 1;
    t33_mean_size[1] = 1;
    t33_mean_data[0] = 0.0;
    cast(t33_percentile95_data, t33_percentile95_size, t33_percentile65_data,
         t33_percentile65_size, t33_mean_data, t33_mean_size,
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
    t32_allChains.set_size(1, 3, 1);
    bayesResults_dreamParams->outlier[0] = 'i';
    t32_allChains[0] = 1.0;
    bayesResults_dreamParams->outlier[1] = 'q';
    t32_allChains[t32_allChains.size(0)] = 1.0;
    bayesResults_dreamParams->outlier[2] = 'r';
    t32_allChains[t32_allChains.size(0) * 2] = 1.0;
    t32_outlierChains.set_size(1, 2);
    t32_AR.set_size(1, 2);
    t32_R_stat.set_size(1, 2);
    t32_CR.set_size(1, 2);

    //  -------------------------------------------------------------------
    //  (5) bayesResults.nestedSamplerOutput
    //  Nested Sampler
    bayesResults_nestedSamplerOutput->nestSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->nestSamples.size[1] = 2;
    bayesResults_nestedSamplerOutput->postSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->postSamples.size[1] = 2;
    t32_outlierChains[0] = 1.0;
    t32_AR[0] = 0.0;
    t32_R_stat[0] = 0.0;
    t32_CR[0] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[0] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[0] = 0.0;
    t32_outlierChains[t32_outlierChains.size(0)] = 1.0;
    t32_AR[t32_AR.size(0)] = 0.0;
    t32_R_stat[t32_R_stat.size(0)] = 0.0;
    t32_CR[t32_CR.size(0)] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[1] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[1] = 0.0;
    cast(t32_allChains, t32_outlierChains, 100.0, 0.0, 0.0, t32_AR, t32_R_stat,
         t32_CR, bayesResults_dreamOutput->allChains,
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
    2U> &bayesResults_predictionIntervals_sld, real_T
    bayesResults_predictionIntervals_sampleChi_data[], int32_T
    *bayesResults_predictionIntervals_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<real_T, 2U>
    &bayesResults_confidenceIntervals_mean, struct12_T *bayesResults_dreamParams,
    struct13_T *bayesResults_dreamOutput, c_struct_T
    *bayesResults_nestedSamplerOutput, ::coder::array<real_T, 2U>
    &bayesResults_chain)
  {
    ::coder::array<cell_wrap_47, 2U> b_f1;
    ::coder::array<cell_wrap_47, 1U> f1;
    ::coder::array<real_T, 3U> t30_allChains;
    ::coder::array<real_T, 2U> t30_AR;
    ::coder::array<real_T, 2U> t30_CR;
    ::coder::array<real_T, 2U> t30_R_stat;
    ::coder::array<real_T, 2U> t30_outlierChains;
    ::coder::array<real_T, 1U> c_f1;
    cell_wrap_45 r2;
    cell_wrap_49 r3;
    cell_wrap_50 r4;
    cell_wrap_51 r;
    cell_wrap_52 r1;
    real_T t31_percentile65_data[2000];
    real_T t31_percentile95_data[2000];
    real_T t31_mean_data[1000];
    int32_T t31_mean_size[2];
    int32_T t31_percentile65_size[2];
    int32_T t31_percentile95_size[2];
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

    c_f1.set_size(1);
    c_f1[0] = 0.0;
    r.f1 = f1;
    r1.f1 = b_f1;
    r2.f1 = c_f1;
    cast(&r, &r3);
    cast(&r1, &r4);
    coder::internal::structConstructorHelper(&r3, &r4, &r2,
      bayesResults_predictionIntervals_reflectivity,
      bayesResults_predictionIntervals_sld,
      bayesResults_predictionIntervals_sampleChi_data,
      bayesResults_predictionIntervals_sampleChi_size);

    //  ------------------------------------------------------------------
    //  (2) bayesResults.confidenceIntervals
    t31_percentile95_size[0] = 2;
    t31_percentile95_size[1] = 1;
    t31_percentile65_size[0] = 2;
    t31_percentile65_size[1] = 1;
    t31_percentile95_data[0] = 0.0;
    t31_percentile65_data[0] = 0.0;
    t31_percentile95_data[1] = 0.0;
    t31_percentile65_data[1] = 0.0;
    t31_mean_size[0] = 1;
    t31_mean_size[1] = 1;
    t31_mean_data[0] = 0.0;
    cast(t31_percentile95_data, t31_percentile95_size, t31_percentile65_data,
         t31_percentile65_size, t31_mean_data, t31_mean_size,
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
    t30_allChains.set_size(1, 3, 1);
    bayesResults_dreamParams->outlier[0] = 'i';
    t30_allChains[0] = 1.0;
    bayesResults_dreamParams->outlier[1] = 'q';
    t30_allChains[t30_allChains.size(0)] = 1.0;
    bayesResults_dreamParams->outlier[2] = 'r';
    t30_allChains[t30_allChains.size(0) * 2] = 1.0;
    t30_outlierChains.set_size(1, 2);
    t30_AR.set_size(1, 2);
    t30_R_stat.set_size(1, 2);
    t30_CR.set_size(1, 2);

    //  -------------------------------------------------------------------
    //  (5) bayesResults.nestedSamplerOutput
    //  Nested Sampler
    bayesResults_nestedSamplerOutput->nestSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->nestSamples.size[1] = 2;
    bayesResults_nestedSamplerOutput->postSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput->postSamples.size[1] = 2;
    t30_outlierChains[0] = 1.0;
    t30_AR[0] = 0.0;
    t30_R_stat[0] = 0.0;
    t30_CR[0] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[0] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[0] = 0.0;
    t30_outlierChains[t30_outlierChains.size(0)] = 1.0;
    t30_AR[t30_AR.size(0)] = 0.0;
    t30_R_stat[t30_R_stat.size(0)] = 0.0;
    t30_CR[t30_CR.size(0)] = 0.0;
    bayesResults_nestedSamplerOutput->nestSamples.data[1] = 0.0;
    bayesResults_nestedSamplerOutput->postSamples.data[1] = 0.0;
    cast(t30_allChains, t30_outlierChains, 100.0, 0.0, 0.0, t30_AR, t30_R_stat,
         t30_CR, bayesResults_dreamOutput->allChains,
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
