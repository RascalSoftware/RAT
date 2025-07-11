//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  struct cell_wrap_43
  {
    ::coder::array<double, 2U> f1;
  };

  struct cell_wrap_47
  {
    ::coder::array<cell_wrap_43, 1U> f1;
  };

  struct cell_wrap_48
  {
    ::coder::array<cell_wrap_43, 2U> f1;
  };
}

// Function Declarations
namespace RAT
{
  static void cast(const cell_wrap_47 &r, cell_wrap_45 &r1);
  static void cast(const cell_wrap_48 &r, cell_wrap_46 &r1);
  static void cast(const double t4_percentile95_data[], const int
                   t4_percentile95_size[2], const double t4_percentile65_data[],
                   const int t4_percentile65_size[2], const double t4_mean_data[],
                   const int t4_mean_size[2], ::coder::array<double, 2U>
                   &t5_percentile95, ::coder::array<double, 2U> &t5_percentile65,
                   ::coder::array<double, 2U> &t5_mean);
  static double cast(const ::coder::array<double, 3U> &t2_allChains, const ::
                     coder::array<double, 2U> &t2_outlierChains, const ::coder::
                     array<double, 2U> &t2_AR, const ::coder::array<double, 2U>
                     &t2_R_stat, const ::coder::array<double, 2U> &t2_CR, ::
                     coder::array<double, 3U> &t3_allChains, double
                     t3_outlierChains_data[], int t3_outlierChains_size[2],
                     double t3_AR_data[], int t3_AR_size[2], ::coder::array<
                     double, 2U> &t3_R_stat, ::coder::array<double, 2U> &t3_CR,
                     double &t3_iteration);
}

// Function Definitions
namespace RAT
{
  static void cast(const cell_wrap_47 &r, cell_wrap_45 &r1)
  {
    int i;
    i = r.f1.size(0);
    r1.f1.set_size(r.f1.size(0));
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = r.f1[i1].f1.size(1);
      r1.f1[i1].f1.set_size(5, r.f1[i1].f1.size(1));
      for (int i2{0}; i2 < loop_ub; i2++) {
        for (int i3{0}; i3 < 5; i3++) {
          r1.f1[i1].f1[i3 + 5 * i2] = r.f1[i1].f1[i3 + 5 * i2];
        }
      }
    }
  }

  static void cast(const cell_wrap_48 &r, cell_wrap_46 &r1)
  {
    int i;
    i = r.f1.size(0) * r.f1.size(1);
    r1.f1.set_size(r.f1.size(0), r.f1.size(1));
    for (int i1{0}; i1 < i; i1++) {
      int loop_ub;
      loop_ub = r.f1[i1].f1.size(1);
      r1.f1[i1].f1.set_size(5, r.f1[i1].f1.size(1));
      for (int i2{0}; i2 < loop_ub; i2++) {
        for (int i3{0}; i3 < 5; i3++) {
          r1.f1[i1].f1[i3 + 5 * i2] = r.f1[i1].f1[i3 + 5 * i2];
        }
      }
    }
  }

  static void cast(const double t4_percentile95_data[], const int
                   t4_percentile95_size[2], const double t4_percentile65_data[],
                   const int t4_percentile65_size[2], const double t4_mean_data[],
                   const int t4_mean_size[2], ::coder::array<double, 2U>
                   &t5_percentile95, ::coder::array<double, 2U> &t5_percentile65,
                   ::coder::array<double, 2U> &t5_mean)
  {
    int loop_ub;
    t5_percentile95.set_size(2, t4_percentile95_size[1]);
    loop_ub = t4_percentile95_size[1];
    for (int i{0}; i < loop_ub; i++) {
      t5_percentile95[2 * i] = t4_percentile95_data[2 * i];
      t5_percentile95[2 * i + 1] = t4_percentile95_data[2 * i + 1];
    }

    t5_percentile65.set_size(2, t4_percentile65_size[1]);
    loop_ub = t4_percentile65_size[1];
    for (int i{0}; i < loop_ub; i++) {
      t5_percentile65[2 * i] = t4_percentile65_data[2 * i];
      t5_percentile65[2 * i + 1] = t4_percentile65_data[2 * i + 1];
    }

    t5_mean.set_size(1, t4_mean_size[1]);
    loop_ub = t4_mean_size[1];
    for (int i{0}; i < loop_ub; i++) {
      t5_mean[i] = t4_mean_data[i];
    }
  }

  static double cast(const ::coder::array<double, 3U> &t2_allChains, const ::
                     coder::array<double, 2U> &t2_outlierChains, const ::coder::
                     array<double, 2U> &t2_AR, const ::coder::array<double, 2U>
                     &t2_R_stat, const ::coder::array<double, 2U> &t2_CR, ::
                     coder::array<double, 3U> &t3_allChains, double
                     t3_outlierChains_data[], int t3_outlierChains_size[2],
                     double t3_AR_data[], int t3_AR_size[2], ::coder::array<
                     double, 2U> &t3_R_stat, ::coder::array<double, 2U> &t3_CR,
                     double &t3_iteration)
  {
    double t3_runtime;
    int b_loop_ub;
    int loop_ub;
    t3_allChains.set_size(t2_allChains.size(0), t2_allChains.size(1),
                          t2_allChains.size(2));
    loop_ub = t2_allChains.size(2);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = t2_allChains.size(1);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        int c_loop_ub;
        c_loop_ub = t2_allChains.size(0);
        for (int i2{0}; i2 < c_loop_ub; i2++) {
          t3_allChains[(i2 + t3_allChains.size(0) * i1) + t3_allChains.size(0) *
            t3_allChains.size(1) * i] = t2_allChains[(i2 + t2_allChains.size(0) *
            i1) + t2_allChains.size(0) * t2_allChains.size(1) * i];
        }
      }
    }

    t3_outlierChains_size[0] = t2_outlierChains.size(0);
    t3_outlierChains_size[1] = t2_outlierChains.size(1);
    loop_ub = t2_outlierChains.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = t2_outlierChains.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t3_outlierChains_data[i1 + t3_outlierChains_size[0] * i] =
          t2_outlierChains[i1 + t2_outlierChains.size(0) * i];
      }
    }

    t3_AR_size[0] = t2_AR.size(0);
    t3_AR_size[1] = t2_AR.size(1);
    loop_ub = t2_AR.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = t2_AR.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t3_AR_data[i1 + t3_AR_size[0] * i] = t2_AR[i1 + t2_AR.size(0) * i];
      }
    }

    t3_R_stat.set_size(t2_R_stat.size(0), t2_R_stat.size(1));
    loop_ub = t2_R_stat.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = t2_R_stat.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t3_R_stat[i1 + t3_R_stat.size(0) * i] = t2_R_stat[i1 + t2_R_stat.size(0)
          * i];
      }
    }

    t3_CR.set_size(t2_CR.size(0), t2_CR.size(1));
    loop_ub = t2_CR.size(1);
    for (int i{0}; i < loop_ub; i++) {
      b_loop_ub = t2_CR.size(0);
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        t3_CR[i1 + t3_CR.size(0) * i] = t2_CR[i1 + t2_CR.size(0) * i];
      }
    }

    t3_runtime = 100.0;
    t3_iteration = 0.0;
    return t3_runtime;
  }

  int b_makeEmptyBayesResultsStruct(double nContrasts, boolean_T isDomains, ::
    coder::array<cell_wrap_11, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_11,
    2U> &bayesResults_predictionIntervals_sld, double
    bayesResults_predictionIntervals_sampleChi_data[], ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_mean, DreamParams &
    bayesResults_dreamParams, DreamOutput &bayesResults_dreamOutput, struct_T
    &bayesResults_nestedSamplerOutput, ::coder::array<double, 2U>
    &bayesResults_chain)
  {
    ::coder::array<cell_wrap_43, 2U> b_f1;
    ::coder::array<cell_wrap_43, 1U> f1;
    ::coder::array<double, 3U> t6_allChains;
    ::coder::array<double, 2U> t6_AR;
    ::coder::array<double, 2U> t6_CR;
    ::coder::array<double, 2U> t6_R_stat;
    ::coder::array<double, 2U> t6_outlierChains;
    ::coder::array<double, 1U> c_f1;
    cell_wrap_45 r3;
    cell_wrap_46 r4;
    cell_wrap_47 r;
    cell_wrap_48 r1;
    cell_wrap_49 r2;
    double t7_percentile65_data[2000];
    double t7_percentile95_data[2000];
    double t7_mean_data[1000];
    int t7_mean_size[2];
    int t7_percentile65_size[2];
    int t7_percentile95_size[2];
    int bayesResults_predictionIntervals_sampleChi_size;
    int i;

    //  A function to make an empty container to hold the results of a Bayesian calculation.
    //
    //  Parameters
    //  ----------
    //  nContrasts : int
    //      The number of contrasts.
    //  isDomains : bool
    //      Whether the calculation is a domains calculation.
    //  nChains : int
    //      The number of chains in the calculation.
    //
    //  Returns
    //  -------
    //  bayesResults : struct
    //      A struct with the following fields:
    //
    //      - predictionIntervals: [1×1 struct]
    //      - confidenceIntervals: [1×1 struct]
    //      - dreamParams: [1×1 struct]
    //      - dreamOutput: [1×1 struct]
    //      - nestedSamplerOutput: [1×1 struct]
    //      - chain: [array of double]
    //  Make the individual structs....
    //  (1) bayesResults.predictionIntervals
    i = static_cast<int>(nContrasts);
    f1.set_size(i);
    for (int b_i{0}; b_i < i; b_i++) {
      f1[b_i].f1.set_size(5, 1);
      for (int i1{0}; i1 < 5; i1++) {
        f1[b_i].f1[i1] = 1.0;
      }
    }

    if (isDomains) {
      b_f1.set_size(i, 2);
      for (int b_i{0}; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(5, 1);
        b_f1[b_i + b_f1.size(0)].f1.set_size(5, 1);
        for (int i1{0}; i1 < 5; i1++) {
          b_f1[b_i].f1[i1] = 1.0;
          b_f1[b_i + b_f1.size(0)].f1[i1] = 1.0;
        }
      }
    } else {
      b_f1.set_size(i, 1);
      for (int b_i{0}; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(5, 1);
        for (int i1{0}; i1 < 5; i1++) {
          b_f1[b_i].f1[i1] = 1.0;
        }
      }
    }

    c_f1.set_size(1);
    c_f1[0] = 0.0;
    r.f1 = f1;
    r1.f1 = b_f1;
    r2.f1 = c_f1;
    cast(r, r3);
    cast(r1, r4);
    bayesResults_predictionIntervals_sampleChi_size = coder::internal::
      structConstructorHelper(r3, r4, r2,
      bayesResults_predictionIntervals_reflectivity,
      bayesResults_predictionIntervals_sld,
      bayesResults_predictionIntervals_sampleChi_data);

    //  ------------------------------------------------------------------
    //  (2) bayesResults.confidenceIntervals
    t7_percentile95_size[0] = 2;
    t7_percentile95_size[1] = 1;
    t7_percentile65_size[0] = 2;
    t7_percentile65_size[1] = 1;
    t7_percentile95_data[0] = 0.0;
    t7_percentile65_data[0] = 0.0;
    t7_percentile95_data[1] = 0.0;
    t7_percentile65_data[1] = 0.0;
    t7_mean_size[0] = 1;
    t7_mean_size[1] = 1;
    t7_mean_data[0] = 0.0;
    cast(t7_percentile95_data, t7_percentile95_size, t7_percentile65_data,
         t7_percentile65_size, t7_mean_data, t7_mean_size,
         bayesResults_confidenceIntervals_percentile95,
         bayesResults_confidenceIntervals_percentile65,
         bayesResults_confidenceIntervals_mean);

    //  -------------------------------------------------------------------
    //  (3) bayesResults.dreamParams
    bayesResults_dreamParams.R.set_size(1, 1);
    bayesResults_dreamParams.R[0] = 0.0;
    bayesResults_dreamParams.nParams = 17.0;
    bayesResults_dreamParams.nChains = 10.0;
    bayesResults_dreamParams.nGenerations = 1000.0;
    bayesResults_dreamParams.parallel = false;
    bayesResults_dreamParams.CPU = 1.0;
    bayesResults_dreamParams.jumpProbability = 0.5;
    bayesResults_dreamParams.pUnitGamma = 0.2;
    bayesResults_dreamParams.nCR = 3.0;
    bayesResults_dreamParams.delta = 3.0;
    bayesResults_dreamParams.steps = 50.0;
    bayesResults_dreamParams.zeta = 1.0E-12;
    bayesResults_dreamParams.adaptPCR = false;
    bayesResults_dreamParams.thinning = 1.0;
    bayesResults_dreamParams.ABC = false;
    bayesResults_dreamParams.epsilon = 0.025;
    bayesResults_dreamParams.IO = false;
    bayesResults_dreamParams.storeOutput = false;

    //  -------------------------------------------------------------------
    //  (4) bayesResults.dreamOutput
    t6_allChains.set_size(1, 3, 1);
    bayesResults_dreamParams.outlier[0] = 'i';
    t6_allChains[0] = 1.0;
    bayesResults_dreamParams.outlier[1] = 'q';
    t6_allChains[t6_allChains.size(0)] = 1.0;
    bayesResults_dreamParams.outlier[2] = 'r';
    t6_allChains[t6_allChains.size(0) * 2] = 1.0;
    t6_outlierChains.set_size(1, 2);
    t6_AR.set_size(1, 2);
    t6_R_stat.set_size(1, 2);
    t6_CR.set_size(1, 2);

    //  -------------------------------------------------------------------
    //  (5) bayesResults.nestedSamplerOutput
    //  Nested Sampler
    bayesResults_nestedSamplerOutput.nestSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput.nestSamples.size[1] = 2;
    bayesResults_nestedSamplerOutput.postSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput.postSamples.size[1] = 2;
    t6_outlierChains[0] = 1.0;
    t6_AR[0] = 0.0;
    t6_R_stat[0] = 0.0;
    t6_CR[0] = 0.0;
    bayesResults_nestedSamplerOutput.nestSamples.data[0] = 0.0;
    bayesResults_nestedSamplerOutput.postSamples.data[0] = 0.0;
    t6_outlierChains[t6_outlierChains.size(0)] = 1.0;
    t6_AR[t6_AR.size(0)] = 0.0;
    t6_R_stat[t6_R_stat.size(0)] = 0.0;
    t6_CR[t6_CR.size(0)] = 0.0;
    bayesResults_nestedSamplerOutput.nestSamples.data[1] = 0.0;
    bayesResults_nestedSamplerOutput.postSamples.data[1] = 0.0;
    bayesResults_dreamOutput.runtime = cast(t6_allChains, t6_outlierChains,
      t6_AR, t6_R_stat, t6_CR, bayesResults_dreamOutput.allChains,
      bayesResults_dreamOutput.outlierChains.data,
      bayesResults_dreamOutput.outlierChains.size,
      bayesResults_dreamOutput.AR.data, bayesResults_dreamOutput.AR.size,
      bayesResults_dreamOutput.R_stat, bayesResults_dreamOutput.CR,
      bayesResults_dreamOutput.iteration);
    bayesResults_nestedSamplerOutput.LogZ = 0.0;
    bayesResults_nestedSamplerOutput.LogZErr = 0.0;

    //  ------------------------------------------------------------------
    //  (6) chain
    bayesResults_chain.set_size(1, 2);
    bayesResults_chain[0] = 0.0;
    bayesResults_chain[bayesResults_chain.size(0)] = 0.0;

    //  -------------------------------------------------------------------
    //  Make the final structure...
    return bayesResults_predictionIntervals_sampleChi_size;
  }

  int makeEmptyBayesResultsStruct(double nContrasts, boolean_T isDomains, double
    nChains, ::coder::array<cell_wrap_11, 1U>
    &bayesResults_predictionIntervals_reflectivity, ::coder::array<cell_wrap_11,
    2U> &bayesResults_predictionIntervals_sld, double
    bayesResults_predictionIntervals_sampleChi_data[], ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile95, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_percentile65, ::coder::array<double, 2U>
    &bayesResults_confidenceIntervals_mean, DreamParams &
    bayesResults_dreamParams, DreamOutput &bayesResults_dreamOutput, struct_T
    &bayesResults_nestedSamplerOutput, ::coder::array<double, 2U>
    &bayesResults_chain)
  {
    ::coder::array<cell_wrap_43, 2U> b_f1;
    ::coder::array<cell_wrap_43, 1U> f1;
    ::coder::array<double, 3U> t35_allChains;
    ::coder::array<double, 2U> t35_AR;
    ::coder::array<double, 2U> t35_CR;
    ::coder::array<double, 2U> t35_R_stat;
    ::coder::array<double, 2U> t35_outlierChains;
    ::coder::array<double, 1U> c_f1;
    cell_wrap_45 r3;
    cell_wrap_46 r4;
    cell_wrap_47 r;
    cell_wrap_48 r1;
    cell_wrap_49 r2;
    double t36_percentile65_data[2000];
    double t36_percentile95_data[2000];
    double t36_mean_data[1000];
    int t36_mean_size[2];
    int t36_percentile65_size[2];
    int t36_percentile95_size[2];
    int bayesResults_predictionIntervals_sampleChi_size;
    int i;
    int loop_ub_tmp;

    //  A function to make an empty container to hold the results of a Bayesian calculation.
    //
    //  Parameters
    //  ----------
    //  nContrasts : int
    //      The number of contrasts.
    //  isDomains : bool
    //      Whether the calculation is a domains calculation.
    //  nChains : int
    //      The number of chains in the calculation.
    //
    //  Returns
    //  -------
    //  bayesResults : struct
    //      A struct with the following fields:
    //
    //      - predictionIntervals: [1×1 struct]
    //      - confidenceIntervals: [1×1 struct]
    //      - dreamParams: [1×1 struct]
    //      - dreamOutput: [1×1 struct]
    //      - nestedSamplerOutput: [1×1 struct]
    //      - chain: [array of double]
    //  Make the individual structs....
    //  (1) bayesResults.predictionIntervals
    i = static_cast<int>(nContrasts);
    f1.set_size(i);
    for (int b_i{0}; b_i < i; b_i++) {
      f1[b_i].f1.set_size(5, 1);
      for (int i1{0}; i1 < 5; i1++) {
        f1[b_i].f1[i1] = 1.0;
      }
    }

    if (isDomains) {
      b_f1.set_size(i, 2);
      for (int b_i{0}; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(5, 1);
        b_f1[b_i + b_f1.size(0)].f1.set_size(5, 1);
        for (int i1{0}; i1 < 5; i1++) {
          b_f1[b_i].f1[i1] = 1.0;
          b_f1[b_i + b_f1.size(0)].f1[i1] = 1.0;
        }
      }
    } else {
      b_f1.set_size(i, 1);
      for (int b_i{0}; b_i < i; b_i++) {
        b_f1[b_i].f1.set_size(5, 1);
        for (int i1{0}; i1 < 5; i1++) {
          b_f1[b_i].f1[i1] = 1.0;
        }
      }
    }

    c_f1.set_size(1);
    c_f1[0] = 0.0;
    r.f1 = f1;
    r1.f1 = b_f1;
    r2.f1 = c_f1;
    cast(r, r3);
    cast(r1, r4);
    bayesResults_predictionIntervals_sampleChi_size = coder::internal::
      structConstructorHelper(r3, r4, r2,
      bayesResults_predictionIntervals_reflectivity,
      bayesResults_predictionIntervals_sld,
      bayesResults_predictionIntervals_sampleChi_data);

    //  ------------------------------------------------------------------
    //  (2) bayesResults.confidenceIntervals
    t36_percentile95_size[0] = 2;
    t36_percentile95_size[1] = 1;
    t36_percentile65_size[0] = 2;
    t36_percentile65_size[1] = 1;
    t36_percentile95_data[0] = 0.0;
    t36_percentile65_data[0] = 0.0;
    t36_percentile95_data[1] = 0.0;
    t36_percentile65_data[1] = 0.0;
    t36_mean_size[0] = 1;
    t36_mean_size[1] = 1;
    t36_mean_data[0] = 0.0;
    cast(t36_percentile95_data, t36_percentile95_size, t36_percentile65_data,
         t36_percentile65_size, t36_mean_data, t36_mean_size,
         bayesResults_confidenceIntervals_percentile95,
         bayesResults_confidenceIntervals_percentile65,
         bayesResults_confidenceIntervals_mean);

    //  -------------------------------------------------------------------
    //  (3) bayesResults.dreamParams
    loop_ub_tmp = static_cast<int>(nChains);
    bayesResults_dreamParams.R.set_size(loop_ub_tmp, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      for (int i1{0}; i1 < loop_ub_tmp; i1++) {
        bayesResults_dreamParams.R[i1 + bayesResults_dreamParams.R.size(0) * i] =
          0.0;
      }
    }

    bayesResults_dreamParams.nParams = 17.0;
    bayesResults_dreamParams.nChains = 10.0;
    bayesResults_dreamParams.nGenerations = 1000.0;
    bayesResults_dreamParams.parallel = false;
    bayesResults_dreamParams.CPU = 1.0;
    bayesResults_dreamParams.jumpProbability = 0.5;
    bayesResults_dreamParams.pUnitGamma = 0.2;
    bayesResults_dreamParams.nCR = 3.0;
    bayesResults_dreamParams.delta = 3.0;
    bayesResults_dreamParams.steps = 50.0;
    bayesResults_dreamParams.zeta = 1.0E-12;
    bayesResults_dreamParams.adaptPCR = false;
    bayesResults_dreamParams.thinning = 1.0;
    bayesResults_dreamParams.ABC = false;
    bayesResults_dreamParams.epsilon = 0.025;
    bayesResults_dreamParams.IO = false;
    bayesResults_dreamParams.storeOutput = false;

    //  -------------------------------------------------------------------
    //  (4) bayesResults.dreamOutput
    t35_allChains.set_size(1, 3, 1);
    bayesResults_dreamParams.outlier[0] = 'i';
    t35_allChains[0] = 1.0;
    bayesResults_dreamParams.outlier[1] = 'q';
    t35_allChains[t35_allChains.size(0)] = 1.0;
    bayesResults_dreamParams.outlier[2] = 'r';
    t35_allChains[t35_allChains.size(0) * 2] = 1.0;
    t35_outlierChains.set_size(1, 2);
    t35_AR.set_size(1, 2);
    t35_R_stat.set_size(1, 2);
    t35_CR.set_size(1, 2);

    //  -------------------------------------------------------------------
    //  (5) bayesResults.nestedSamplerOutput
    //  Nested Sampler
    bayesResults_nestedSamplerOutput.nestSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput.nestSamples.size[1] = 2;
    bayesResults_nestedSamplerOutput.postSamples.size[0] = 1;
    bayesResults_nestedSamplerOutput.postSamples.size[1] = 2;
    t35_outlierChains[0] = 1.0;
    t35_AR[0] = 0.0;
    t35_R_stat[0] = 0.0;
    t35_CR[0] = 0.0;
    bayesResults_nestedSamplerOutput.nestSamples.data[0] = 0.0;
    bayesResults_nestedSamplerOutput.postSamples.data[0] = 0.0;
    t35_outlierChains[t35_outlierChains.size(0)] = 1.0;
    t35_AR[t35_AR.size(0)] = 0.0;
    t35_R_stat[t35_R_stat.size(0)] = 0.0;
    t35_CR[t35_CR.size(0)] = 0.0;
    bayesResults_nestedSamplerOutput.nestSamples.data[1] = 0.0;
    bayesResults_nestedSamplerOutput.postSamples.data[1] = 0.0;
    bayesResults_dreamOutput.runtime = cast(t35_allChains, t35_outlierChains,
      t35_AR, t35_R_stat, t35_CR, bayesResults_dreamOutput.allChains,
      bayesResults_dreamOutput.outlierChains.data,
      bayesResults_dreamOutput.outlierChains.size,
      bayesResults_dreamOutput.AR.data, bayesResults_dreamOutput.AR.size,
      bayesResults_dreamOutput.R_stat, bayesResults_dreamOutput.CR,
      bayesResults_dreamOutput.iteration);
    bayesResults_nestedSamplerOutput.LogZ = 0.0;
    bayesResults_nestedSamplerOutput.LogZErr = 0.0;

    //  ------------------------------------------------------------------
    //  (6) chain
    bayesResults_chain.set_size(1, 2);
    bayesResults_chain[0] = 0.0;
    bayesResults_chain[bayesResults_chain.size(0)] = 0.0;

    //  -------------------------------------------------------------------
    //  Make the final structure...
    return bayesResults_predictionIntervals_sampleChi_size;
  }
}

// End of code generation (makeEmptyBayesResultsStruct.cpp)
