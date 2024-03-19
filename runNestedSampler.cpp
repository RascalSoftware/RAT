//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runNestedSampler.cpp
//
// Code generation for function 'runNestedSampler'
//

// Include files
#include "runNestedSampler.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "getFittedPriors.h"
#include "makeEmptyBayesResultsStruct.h"
#include "mean.h"
#include "nestedSampler.h"
#include "packParams.h"
#include "processBayes.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  void runNestedSampler(f_struct_T *problemStruct, const cell_11 *problemCells,
                        const struct1_T *problemLimits, const struct2_T
                        *controls, const struct4_T *inPriors, struct5_T *result,
                        struct8_T *bayesResults)
  {
    static e_struct_T t8_bayesRes;
    static f_struct_T b_problemStruct;
    ::coder::array<cell_wrap_1, 1U> fitNames;
    ::coder::array<cell_wrap_10, 2U> expl_temp_sld;
    ::coder::array<cell_wrap_10, 2U> t8_predlims_sldPredInts;
    ::coder::array<cell_wrap_10, 2U> t8_predlims_sldXdata;
    ::coder::array<cell_wrap_10, 1U> expl_temp_data;
    ::coder::array<cell_wrap_10, 1U> expl_temp_ref;
    ::coder::array<cell_wrap_10, 1U> t8_predlims_refPredInts;
    ::coder::array<real_T, 2U> b_bayesResults;
    ::coder::array<real_T, 2U> b_expl_temp;
    ::coder::array<real_T, 2U> bayesOutputs_chain;
    ::coder::array<real_T, 2U> c_bayesResults;
    ::coder::array<real_T, 2U> expl_temp;
    ::coder::array<real_T, 2U> expl_temp_mean;
    ::coder::array<real_T, 2U> expl_temp_par65;
    ::coder::array<real_T, 2U> expl_temp_par95;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    i_struct_T nestResults;
    real_T t8_predlims_sampleChi_data[1000];
    real_T bayesOutputs_bestPars_data[51];
    real_T H;
    real_T expl_temp_chi;
    real_T logZ;
    int32_T bayesOutputs_bestPars_size[2];
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T t8_predlims_sampleChi_size;
    packParams(problemStruct, problemCells->f7, problemCells->f8,
               problemCells->f9, problemCells->f10, problemCells->f11,
               problemCells->f12, problemCells->f13, problemCells->f20,
               problemLimits, &controls->checks, fitNames);

    //  Make an empty struct for bayesResults to hold the outputs of the
    //  calculation
    b_makeEmptyBayesResultsStruct(problemStruct->numberOfContrasts, coder::
      internal::b_strcmp(problemStruct->TF.data, problemStruct->TF.size),
      expl_temp_ref, expl_temp_sld, &expl_temp_chi, expl_temp_data,
      t8_predlims_refPredInts, t8_predlims_sldPredInts,
      bayesResults->predlims.refXdata, t8_predlims_sldXdata,
      t8_predlims_sampleChi_data, &t8_predlims_sampleChi_size, expl_temp_par95,
      expl_temp_par65, expl_temp_mean, expl_temp, &t8_bayesRes, b_expl_temp);
    bayesResults->bayesRes.allChains.set_size(t8_bayesRes.allChains.size(0),
      t8_bayesRes.allChains.size(1), t8_bayesRes.allChains.size(2));
    t8_predlims_sampleChi_size = t8_bayesRes.allChains.size(2);
    for (i = 0; i < t8_predlims_sampleChi_size; i++) {
      loop_ub = t8_bayesRes.allChains.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = t8_bayesRes.allChains.size(0);
        for (int32_T i2{0}; i2 < b_loop_ub; i2++) {
          bayesResults->bayesRes.allChains[(i2 +
            bayesResults->bayesRes.allChains.size(0) * i1) +
            bayesResults->bayesRes.allChains.size(0) *
            bayesResults->bayesRes.allChains.size(1) * i] =
            t8_bayesRes.allChains[(i2 + t8_bayesRes.allChains.size(0) * i1) +
            t8_bayesRes.allChains.size(0) * t8_bayesRes.allChains.size(1) * i];
        }
      }
    }

    bayesResults->bayesRes.dreamOutput = t8_bayesRes.dreamOutput;

    // Deal with priors.
    // Tuning Parameters
    getFittedPriors(fitNames, inPriors->priorNames, inPriors->priorValues,
                    problemStruct->fitLimits, r);
    nestedSampler(problemStruct, controls, problemLimits, problemCells,
                  controls->Nlive, controls->Nmcmc, controls->nsTolerance, r,
                  &logZ, bayesResults->bayesRes.nestOutput.nestSamples,
                  bayesResults->bayesRes.nestOutput.postSamples, &H);

    //  Process the results...
    //  chain = nest_samples(:,1:end-1);
    if (1 > fitNames.size(0)) {
      t8_predlims_sampleChi_size = 0;
    } else {
      t8_predlims_sampleChi_size = fitNames.size(0);
    }

    loop_ub = bayesResults->bayesRes.nestOutput.postSamples.size(0);
    b_bayesResults.set_size(bayesResults->bayesRes.nestOutput.postSamples.size(0),
      t8_predlims_sampleChi_size);
    for (i = 0; i < t8_predlims_sampleChi_size; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_bayesResults[i1 + b_bayesResults.size(0) * i] =
          bayesResults->bayesRes.nestOutput.postSamples[i1 +
          bayesResults->bayesRes.nestOutput.postSamples.size(0) * i];
      }
    }

    coder::mean(b_bayesResults, r1);
    bayesOutputs_bestPars_size[0] = 1;
    bayesOutputs_bestPars_size[1] = r1.size(1);
    loop_ub = r1.size(1);
    for (i = 0; i < loop_ub; i++) {
      bayesOutputs_bestPars_data[i] = r1[i];
    }

    loop_ub = bayesResults->bayesRes.nestOutput.postSamples.size(0);
    bayesOutputs_chain.set_size
      (bayesResults->bayesRes.nestOutput.postSamples.size(0),
       t8_predlims_sampleChi_size);
    for (i = 0; i < t8_predlims_sampleChi_size; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesOutputs_chain[i1 + bayesOutputs_chain.size(0) * i] =
          bayesResults->bayesRes.nestOutput.postSamples[i1 +
          bayesResults->bayesRes.nestOutput.postSamples.size(0) * i];
      }
    }

    b_problemStruct = *problemStruct;
    processBayes(bayesOutputs_bestPars_data, bayesOutputs_bestPars_size,
                 bayesOutputs_chain, &b_problemStruct, controls, problemLimits,
                 problemCells, problemStruct, result, &nestResults);
    cast(nestResults.predlims.refPredInts, bayesResults->predlims.refPredInts);
    cast(nestResults.predlims.sldPredInts, bayesResults->predlims.sldPredInts);
    bayesResults->predlims.refXdata.set_size(nestResults.predlims.refXdata.size
      (0));
    for (i = 0; i < nestResults.predlims.refXdata.size(0); i++) {
      bayesResults->predlims.refXdata[i].f1.set_size(1,
        nestResults.predlims.refXdata[i].f1.size(1));
      loop_ub = nestResults.predlims.refXdata[i].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesResults->predlims.refXdata[i].f1[bayesResults->predlims.refXdata[i]
          .f1.size(0) * i1] = nestResults.predlims.refXdata[i].f1[i1];
      }
    }

    cast(nestResults.predlims.sldXdata, bayesResults->predlims.sldXdata);
    bayesResults->predlims.sampleChi.size[0] = 1000;
    std::copy(&nestResults.predlims.sampleChi[0],
              &nestResults.predlims.sampleChi[1000],
              &bayesResults->predlims.sampleChi.data[0]);
    cast(nestResults.bestFitsMean.ref, bayesResults->bestFitsMean.ref);
    bayesResults->bestFitsMean.sld.set_size(nestResults.bestFitsMean.sld.size(0),
      nestResults.bestFitsMean.sld.size(1));
    loop_ub = nestResults.bestFitsMean.sld.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = nestResults.bestFitsMean.sld.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesResults->bestFitsMean.sld[i1 + bayesResults->bestFitsMean.sld.size
          (0) * i] = nestResults.bestFitsMean.sld[i1 +
          nestResults.bestFitsMean.sld.size(0) * i];
      }
    }

    bayesResults->bestFitsMean.chi = nestResults.bestFitsMean.chi;
    cast(nestResults.bestFitsMean.data, bayesResults->bestFitsMean.data);
    bayesResults->parConfInts = nestResults.parConfInts;
    loop_ub = bayesResults->bayesRes.nestOutput.postSamples.size(0);
    c_bayesResults.set_size(bayesResults->bayesRes.nestOutput.postSamples.size(0),
      t8_predlims_sampleChi_size);
    for (i = 0; i < t8_predlims_sampleChi_size; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_bayesResults[i1 + c_bayesResults.size(0) * i] =
          bayesResults->bayesRes.nestOutput.postSamples[i1 +
          bayesResults->bayesRes.nestOutput.postSamples.size(0) * i];
      }
    }

    coder::blockedSummation(c_bayesResults,
      bayesResults->bayesRes.nestOutput.postSamples.size(0), r1);
    bayesResults->bestPars.set_size(1, r1.size(1));
    loop_ub = r1.size(1);
    for (i = 0; i < loop_ub; i++) {
      bayesResults->bestPars[i] = r1[i] / static_cast<real_T>
        (bayesResults->bayesRes.nestOutput.postSamples.size(0));
    }

    loop_ub = bayesResults->bayesRes.nestOutput.postSamples.size(0);
    bayesResults->chain.set_size
      (bayesResults->bayesRes.nestOutput.postSamples.size(0),
       t8_predlims_sampleChi_size);
    for (i = 0; i < t8_predlims_sampleChi_size; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        bayesResults->chain[i1 + bayesResults->chain.size(0) * i] =
          bayesResults->bayesRes.nestOutput.postSamples[i1 +
          bayesResults->bayesRes.nestOutput.postSamples.size(0) * i];
      }
    }

    bayesResults->bayesRes.nestOutput.LogZ = logZ;
  }
}

// End of code generation (runNestedSampler.cpp)
