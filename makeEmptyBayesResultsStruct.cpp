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
  static void cast(const ::coder::array<real_T, 2U> &t2_outlier, real_T
                   t2_RunTime, const struct13_T *t2_DREAMPar, const struct14_T
                   t2_Meas_info, real_T t2_iteration, real_T t2_iloc, real_T
                   t2_fx, const ::coder::array<real_T, 2U> &t2_AR, const ::coder::
                   array<real_T, 2U> &t2_R_stat, const ::coder::array<real_T, 2U>
                   &t2_CR, struct12_T *b);
  static void cast(const real_T t0_par95_data[], const int32_T t0_par95_size[2],
                   const real_T t0_par65_data[], const int32_T t0_par65_size[2],
                   const real_T t0_mean_data[], const int32_T t0_mean_size[2], ::
                   coder::array<real_T, 2U> &t1_par95, ::coder::array<real_T, 2U>
                   &t1_par65, ::coder::array<real_T, 2U> &t1_mean);
}

// Function Definitions
namespace RAT
{
  static void cast(const ::coder::array<real_T, 2U> &t2_outlier, real_T
                   t2_RunTime, const struct13_T *t2_DREAMPar, const struct14_T
                   t2_Meas_info, real_T t2_iteration, real_T t2_iloc, real_T
                   t2_fx, const ::coder::array<real_T, 2U> &t2_AR, const ::coder::
                   array<real_T, 2U> &t2_R_stat, const ::coder::array<real_T, 2U>
                   &t2_CR, struct12_T *b)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    b->outlier.size[0] = t2_outlier.size(0);
    b->outlier.size[1] = t2_outlier.size(1);
    loop_ub = t2_outlier.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t2_outlier.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b->outlier.data[i1 + b->outlier.size[0] * i] = t2_outlier[i1 +
          t2_outlier.size(0) * i];
      }
    }

    b->RunTime = t2_RunTime;
    b->DREAMPar = *t2_DREAMPar;
    b->Meas_info = t2_Meas_info;
    b->iteration = t2_iteration;
    b->iloc = t2_iloc;
    b->fx = t2_fx;
    b->AR.size[0] = t2_AR.size(0);
    b->AR.size[1] = t2_AR.size(1);
    loop_ub = t2_AR.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t2_AR.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b->AR.data[i1 + b->AR.size[0] * i] = t2_AR[i1 + t2_AR.size(0) * i];
      }
    }

    b->R_stat.set_size(t2_R_stat.size(0), t2_R_stat.size(1));
    loop_ub = t2_R_stat.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t2_R_stat.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b->R_stat[i1 + b->R_stat.size(0) * i] = t2_R_stat[i1 + t2_R_stat.size(0)
          * i];
      }
    }

    b->CR.set_size(t2_CR.size(0), t2_CR.size(1));
    loop_ub = t2_CR.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = t2_CR.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b->CR[i1 + b->CR.size(0) * i] = t2_CR[i1 + t2_CR.size(0) * i];
      }
    }
  }

  static void cast(const real_T t0_par95_data[], const int32_T t0_par95_size[2],
                   const real_T t0_par65_data[], const int32_T t0_par65_size[2],
                   const real_T t0_mean_data[], const int32_T t0_mean_size[2], ::
                   coder::array<real_T, 2U> &t1_par95, ::coder::array<real_T, 2U>
                   &t1_par65, ::coder::array<real_T, 2U> &t1_mean)
  {
    int32_T i;
    int32_T loop_ub;
    t1_par95.set_size(2, t0_par95_size[1]);
    loop_ub = t0_par95_size[1];
    for (i = 0; i < loop_ub; i++) {
      t1_par95[2 * i] = t0_par95_data[2 * i];
      t1_par95[2 * i + 1] = t0_par95_data[2 * i + 1];
    }

    t1_par65.set_size(2, t0_par65_size[1]);
    loop_ub = t0_par65_size[1];
    for (i = 0; i < loop_ub; i++) {
      t1_par65[2 * i] = t0_par65_data[2 * i];
      t1_par65[2 * i + 1] = t0_par65_data[2 * i + 1];
    }

    t1_mean.set_size(1, t0_mean_size[1]);
    loop_ub = t0_mean_size[1];
    for (i = 0; i < loop_ub; i++) {
      t1_mean[i] = t0_mean_data[i];
    }
  }

  void b_makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains, ::
    coder::array<cell_wrap_8, 1U> &bayesResults_bestFitsMean_ref, ::coder::array<
    cell_wrap_8, 2U> &bayesResults_bestFitsMean_sld, real_T
    *bayesResults_bestFitsMean_chi, ::coder::array<cell_wrap_8, 1U>
    &bayesResults_bestFitsMean_data, ::coder::array<cell_wrap_8, 1U>
    &bayesResults_predlims_refPredInts, ::coder::array<cell_wrap_8, 2U>
    &bayesResults_predlims_sldPredInts, ::coder::array<cell_wrap_8, 1U>
    &bayesResults_predlims_refXdata, ::coder::array<cell_wrap_8, 2U>
    &bayesResults_predlims_sldXdata, real_T
    bayesResults_predlims_sampleChi_data[], int32_T
    *bayesResults_predlims_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_par95, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_par65, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_mean, ::coder::array<real_T, 2U>
    &bayesResults_bestPars, c_struct_T *bayesResults_bayesRes, ::coder::array<
    real_T, 2U> &bayesResults_chain)
  {
    ::coder::array<cell_wrap_8, 2U> b_f1;
    ::coder::array<cell_wrap_8, 2U> e_f1;
    ::coder::array<cell_wrap_8, 2U> g_f1;
    ::coder::array<cell_wrap_8, 1U> c_f1;
    ::coder::array<cell_wrap_8, 1U> d_f1;
    ::coder::array<cell_wrap_8, 1U> f1;
    ::coder::array<cell_wrap_8, 1U> f_f1;
    ::coder::array<real_T, 2U> t5_AR;
    ::coder::array<real_T, 2U> t5_CR;
    ::coder::array<real_T, 2U> t5_R_stat;
    ::coder::array<real_T, 2U> t5_outlier;
    ::coder::array<real_T, 1U> h_f1;
    cell_wrap_12 r;
    cell_wrap_12 r2;
    cell_wrap_14 r4;
    cell_wrap_9 r1;
    cell_wrap_9 r3;
    struct13_T expl_temp;
    struct14_T b_expl_temp;
    real_T t6_par65_data[2000];
    real_T t6_par95_data[2000];
    real_T t6_mean_data[1000];
    int32_T t6_mean_size[2];
    int32_T t6_par65_size[2];
    int32_T t6_par95_size[2];
    int32_T b_i;
    int32_T i;
    int32_T i1;

    //  A function to make an empty container to hold the results of bayes
    //  calculations. The struct has the following format:
    //
    //  nPar = number of fitted parameters
    //  nContrasts = number of contrasts
    //
    //  bayesResults =
    //
    //    struct with fields:
    //
    //      bestFitsMean: [1×1 struct]
    //          predlims: [1×1 struct]
    //       parConfInts: [1×1 struct]
    //          bestPars: [1xnPars double]
    //          bayesRes: [1×1 struct]
    //             chain: [1000000xnPars double]
    //  -----------------------------------------------------------
    //  Make the individual structs....
    //  (1) bayesResults.bestFitsMean
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

    //  --------------------------------------------------------------------
    //  (2) bayesResults.predlims
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

    //  ------------------------------------------------------------------
    //  (3) bayesResults.parConfInts
    t6_par95_size[0] = 2;
    t6_par95_size[1] = 1;
    t6_par65_size[0] = 2;
    t6_par65_size[1] = 1;
    t6_mean_size[0] = 1;
    t6_mean_size[1] = 1;
    t6_mean_data[0] = 0.0;

    //  -------------------------------------------------------------------
    //  (4) bayesResults.bestPars
    //  -------------------------------------------------------------------
    //  (5) bayesResults.bayesRes
    t5_outlier.set_size(1, 2);
    t5_AR.set_size(1, 2);
    t5_R_stat.set_size(1, 2);
    t5_CR.set_size(1, 2);

    //  Nested Sampler
    t6_par95_data[0] = 0.0;
    t6_par65_data[0] = 0.0;
    t5_outlier[0] = 1.0;
    t5_AR[0] = 0.0;
    t5_R_stat[0] = 0.0;
    t5_CR[0] = 0.0;
    t6_par95_data[1] = 0.0;
    t6_par65_data[1] = 0.0;
    t5_outlier[t5_outlier.size(0)] = 1.0;
    t5_AR[t5_AR.size(0)] = 0.0;
    t5_R_stat[t5_R_stat.size(0)] = 0.0;
    t5_CR[t5_CR.size(0)] = 0.0;
    expl_temp.R.set_size(1, 1);
    expl_temp.save = false;
    expl_temp.restart = false;
    expl_temp.modout = false;
    expl_temp.IO = false;
    expl_temp.ABC = false;
    expl_temp.epsilon = 0.025;
    expl_temp.thinning = 1.0;
    expl_temp.adaptPCR = false;
    expl_temp.outlier[0] = 'i';
    expl_temp.outlier[1] = 'q';
    expl_temp.outlier[2] = 'r';
    expl_temp.zeta = 1.0E-12;
    expl_temp.steps = 50.0;
    expl_temp.delta = 3.0;
    expl_temp.nCR = 3.0;
    expl_temp.pUnitGamma = 0.2;
    expl_temp.lambda = 0.5;
    expl_temp.CPU = 1.0;
    expl_temp.parallel = false;
    expl_temp.T = 1000.0;
    expl_temp.N = 10.0;
    expl_temp.d = 17.0;
    b_expl_temp.N = 0.0;
    b_expl_temp.Y = 0.0;

    //  ------------------------------------------------------------------
    //  (6) chain
    //  -------------------------------------------------------------------
    //  Make the final structure...
    r.f1 = f1;
    r1.f1 = b_f1;
    r2.f1 = c_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2,
      bayesResults_bestFitsMean_ref, bayesResults_bestFitsMean_sld,
      bayesResults_bestFitsMean_chi, bayesResults_bestFitsMean_data);
    h_f1.set_size(1);
    h_f1[0] = 0.0;
    r.f1 = d_f1;
    r1.f1 = e_f1;
    r2.f1 = f_f1;
    r3.f1 = g_f1;
    r4.f1 = h_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2, &r3, &r4,
      bayesResults_predlims_refPredInts, bayesResults_predlims_sldPredInts,
      bayesResults_predlims_refXdata, bayesResults_predlims_sldXdata,
      bayesResults_predlims_sampleChi_data, bayesResults_predlims_sampleChi_size);
    cast(t6_par95_data, t6_par95_size, t6_par65_data, t6_par65_size,
         t6_mean_data, t6_mean_size, bayesResults_parConfInts_par95,
         bayesResults_parConfInts_par65, bayesResults_parConfInts_mean);
    bayesResults_bestPars.set_size(1, 1);
    bayesResults_bestPars[0] = 1.0;
    bayesResults_bayesRes->allChains.set_size(1, 3, 1);
    for (i = 0; i < 1; i++) {
      expl_temp.R[0] = 0.0;
      for (i1 = 0; i1 < 3; i1++) {
        for (int32_T i2{0}; i2 < 1; i2++) {
          bayesResults_bayesRes->allChains[bayesResults_bayesRes->allChains.size
            (0) * i1] = 1.0;
        }
      }
    }

    cast(t5_outlier, 100.0, &expl_temp, b_expl_temp, 0.0, 0.0, 0.0, t5_AR,
         t5_R_stat, t5_CR, &bayesResults_bayesRes->dreamOutput);
    bayesResults_bayesRes->nestOutput.LogZ = 0.0;
    bayesResults_bayesRes->nestOutput.nestSamples.size[0] = 1;
    bayesResults_bayesRes->nestOutput.nestSamples.size[1] = 2;
    bayesResults_bayesRes->nestOutput.postSamples.size[0] = 1;
    bayesResults_bayesRes->nestOutput.postSamples.size[1] = 2;
    bayesResults_chain.set_size(1, 2);
    bayesResults_bayesRes->nestOutput.nestSamples.data[0] = 0.0;
    bayesResults_bayesRes->nestOutput.postSamples.data[0] = 0.0;
    bayesResults_chain[0] = 0.0;
    bayesResults_bayesRes->nestOutput.nestSamples.data[1] = 0.0;
    bayesResults_bayesRes->nestOutput.postSamples.data[1] = 0.0;
    bayesResults_chain[bayesResults_chain.size(0)] = 0.0;
  }

  void makeEmptyBayesResultsStruct(real_T nContrasts, boolean_T isDomains,
    real_T nChains, ::coder::array<cell_wrap_8, 1U>
    &bayesResults_bestFitsMean_ref, ::coder::array<cell_wrap_8, 2U>
    &bayesResults_bestFitsMean_sld, real_T *bayesResults_bestFitsMean_chi, ::
    coder::array<cell_wrap_8, 1U> &bayesResults_bestFitsMean_data, ::coder::
    array<cell_wrap_8, 1U> &bayesResults_predlims_refPredInts, ::coder::array<
    cell_wrap_8, 2U> &bayesResults_predlims_sldPredInts, ::coder::array<
    cell_wrap_8, 1U> &bayesResults_predlims_refXdata, ::coder::array<cell_wrap_8,
    2U> &bayesResults_predlims_sldXdata, real_T
    bayesResults_predlims_sampleChi_data[], int32_T
    *bayesResults_predlims_sampleChi_size, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_par95, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_par65, ::coder::array<real_T, 2U>
    &bayesResults_parConfInts_mean, ::coder::array<real_T, 2U>
    &bayesResults_bestPars, c_struct_T *bayesResults_bayesRes, ::coder::array<
    real_T, 2U> &bayesResults_chain)
  {
    ::coder::array<cell_wrap_8, 2U> b_f1;
    ::coder::array<cell_wrap_8, 2U> e_f1;
    ::coder::array<cell_wrap_8, 2U> g_f1;
    ::coder::array<cell_wrap_8, 1U> c_f1;
    ::coder::array<cell_wrap_8, 1U> d_f1;
    ::coder::array<cell_wrap_8, 1U> f1;
    ::coder::array<cell_wrap_8, 1U> f_f1;
    ::coder::array<real_T, 2U> t16_AR;
    ::coder::array<real_T, 2U> t16_CR;
    ::coder::array<real_T, 2U> t16_R_stat;
    ::coder::array<real_T, 2U> t16_outlier;
    ::coder::array<real_T, 1U> h_f1;
    ::coder::array<int8_T, 2U> t16_DREAMPar_R;
    cell_wrap_12 r;
    cell_wrap_12 r2;
    cell_wrap_14 r4;
    cell_wrap_9 r1;
    cell_wrap_9 r3;
    struct13_T expl_temp;
    struct14_T b_expl_temp;
    real_T t17_par65_data[2000];
    real_T t17_par95_data[2000];
    real_T t17_mean_data[1000];
    int32_T t17_mean_size[2];
    int32_T t17_par65_size[2];
    int32_T t17_par95_size[2];
    int32_T b_i;
    int32_T i;
    int32_T i1;
    int32_T loop_ub_tmp;

    //  A function to make an empty container to hold the results of bayes
    //  calculations. The struct has the following format:
    //
    //  nPar = number of fitted parameters
    //  nContrasts = number of contrasts
    //
    //  bayesResults =
    //
    //    struct with fields:
    //
    //      bestFitsMean: [1×1 struct]
    //          predlims: [1×1 struct]
    //       parConfInts: [1×1 struct]
    //          bestPars: [1xnPars double]
    //          bayesRes: [1×1 struct]
    //             chain: [1000000xnPars double]
    //  -----------------------------------------------------------
    //  Make the individual structs....
    //  (1) bayesResults.bestFitsMean
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

    //  --------------------------------------------------------------------
    //  (2) bayesResults.predlims
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

    //  ------------------------------------------------------------------
    //  (3) bayesResults.parConfInts
    t17_par95_size[0] = 2;
    t17_par95_size[1] = 1;
    t17_par65_size[0] = 2;
    t17_par65_size[1] = 1;
    t17_mean_size[0] = 1;
    t17_mean_size[1] = 1;
    t17_mean_data[0] = 0.0;

    //  -------------------------------------------------------------------
    //  (4) bayesResults.bestPars
    //  -------------------------------------------------------------------
    //  (5) bayesResults.bayesRes
    t16_outlier.set_size(1, 2);
    t17_par95_data[0] = 0.0;
    t17_par65_data[0] = 0.0;
    t16_outlier[0] = 1.0;
    t17_par95_data[1] = 0.0;
    t17_par65_data[1] = 0.0;
    t16_outlier[t16_outlier.size(0)] = 1.0;
    loop_ub_tmp = static_cast<int32_T>(nChains);
    t16_DREAMPar_R.set_size(loop_ub_tmp, loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        t16_DREAMPar_R[i1 + t16_DREAMPar_R.size(0) * i] = 0;
      }
    }

    t16_AR.set_size(1, 2);
    t16_R_stat.set_size(1, 2);
    t16_CR.set_size(1, 2);

    //  Nested Sampler
    t16_AR[0] = 0.0;
    t16_R_stat[0] = 0.0;
    t16_CR[0] = 0.0;
    t16_AR[t16_AR.size(0)] = 0.0;
    t16_R_stat[t16_R_stat.size(0)] = 0.0;
    t16_CR[t16_CR.size(0)] = 0.0;
    expl_temp.R.set_size(t16_DREAMPar_R.size(0), t16_DREAMPar_R.size(1));
    loop_ub_tmp = t16_DREAMPar_R.size(1);
    for (i = 0; i < loop_ub_tmp; i++) {
      int32_T loop_ub;
      loop_ub = t16_DREAMPar_R.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        expl_temp.R[i1 + expl_temp.R.size(0) * i] = 0.0;
      }
    }

    expl_temp.save = false;
    expl_temp.restart = false;
    expl_temp.modout = false;
    expl_temp.IO = false;
    expl_temp.ABC = false;
    expl_temp.epsilon = 0.025;
    expl_temp.thinning = 1.0;
    expl_temp.adaptPCR = false;
    expl_temp.outlier[0] = 'i';
    expl_temp.outlier[1] = 'q';
    expl_temp.outlier[2] = 'r';
    expl_temp.zeta = 1.0E-12;
    expl_temp.steps = 50.0;
    expl_temp.delta = 3.0;
    expl_temp.nCR = 3.0;
    expl_temp.pUnitGamma = 0.2;
    expl_temp.lambda = 0.5;
    expl_temp.CPU = 1.0;
    expl_temp.parallel = false;
    expl_temp.T = 1000.0;
    expl_temp.N = 10.0;
    expl_temp.d = 17.0;
    b_expl_temp.N = 0.0;
    b_expl_temp.Y = 0.0;
    cast(t16_outlier, 100.0, &expl_temp, b_expl_temp, 0.0, 0.0, 0.0, t16_AR,
         t16_R_stat, t16_CR, &bayesResults_bayesRes->dreamOutput);

    //  ------------------------------------------------------------------
    //  (6) chain
    //  -------------------------------------------------------------------
    //  Make the final structure...
    r.f1 = f1;
    r1.f1 = b_f1;
    r2.f1 = c_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2,
      bayesResults_bestFitsMean_ref, bayesResults_bestFitsMean_sld,
      bayesResults_bestFitsMean_chi, bayesResults_bestFitsMean_data);
    h_f1.set_size(1);
    h_f1[0] = 0.0;
    r.f1 = d_f1;
    r1.f1 = e_f1;
    r2.f1 = f_f1;
    r3.f1 = g_f1;
    r4.f1 = h_f1;
    coder::internal::structConstructorHelper(&r, &r1, &r2, &r3, &r4,
      bayesResults_predlims_refPredInts, bayesResults_predlims_sldPredInts,
      bayesResults_predlims_refXdata, bayesResults_predlims_sldXdata,
      bayesResults_predlims_sampleChi_data, bayesResults_predlims_sampleChi_size);
    cast(t17_par95_data, t17_par95_size, t17_par65_data, t17_par65_size,
         t17_mean_data, t17_mean_size, bayesResults_parConfInts_par95,
         bayesResults_parConfInts_par65, bayesResults_parConfInts_mean);
    bayesResults_bestPars.set_size(1, 1);
    bayesResults_bestPars[0] = 1.0;
    bayesResults_bayesRes->allChains.set_size(1, 3, 1);
    for (i = 0; i < 1; i++) {
      for (i1 = 0; i1 < 3; i1++) {
        for (loop_ub_tmp = 0; loop_ub_tmp < 1; loop_ub_tmp++) {
          bayesResults_bayesRes->allChains[bayesResults_bayesRes->allChains.size
            (0) * i1] = 1.0;
        }
      }
    }

    bayesResults_bayesRes->nestOutput.LogZ = 0.0;
    bayesResults_bayesRes->nestOutput.nestSamples.size[0] = 1;
    bayesResults_bayesRes->nestOutput.nestSamples.size[1] = 2;
    bayesResults_bayesRes->nestOutput.postSamples.size[0] = 1;
    bayesResults_bayesRes->nestOutput.postSamples.size[1] = 2;
    bayesResults_chain.set_size(1, 2);
    bayesResults_bayesRes->nestOutput.nestSamples.data[0] = 0.0;
    bayesResults_bayesRes->nestOutput.postSamples.data[0] = 0.0;
    bayesResults_chain[0] = 0.0;
    bayesResults_bayesRes->nestOutput.nestSamples.data[1] = 0.0;
    bayesResults_bayesRes->nestOutput.postSamples.data[1] = 0.0;
    bayesResults_chain[bayesResults_chain.size(0)] = 0.0;
  }
}

// End of code generation (makeEmptyBayesResultsStruct.cpp)
