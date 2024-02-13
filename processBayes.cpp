//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// processBayes.cpp
//
// Code generation for function 'processBayes'
//

// Include files
#include "processBayes.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "parseResultToStruct.h"
#include "prctileConfInts.h"
#include "refPrctileConfInts.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "unpackParams.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void processBayes(const real_T bayesOutputs_bestPars_data[], const int32_T
                    bayesOutputs_bestPars_size[2], const ::coder::array<real_T,
                    2U> &bayesOutputs_chain, const d_struct_T *allProblem_f1,
                    const struct2_T *allProblem_f2, const cell_11 *allProblem_f4,
                    d_struct_T *problemStruct, e_struct_T *contrastParams,
                    cell_wrap_9 result[6], f_struct_T *bayesResults_bestFitsMean,
                    g_struct_T *bayesResults_predlims, struct10_T
                    *bayesResults_parConfInts)
  {
    static struct2_T controlsStruct;
    ::coder::array<cell_wrap_8, 2U> b_expl_temp;
    ::coder::array<cell_wrap_8, 2U> c_expl_temp;
    ::coder::array<cell_wrap_8, 2U> expl_temp;
    d_struct_T b_problemStruct;
    e_struct_T d_expl_temp;
    real_T p_calculationResults_sumChi;
    int32_T loop_ub;

    // problem = {problemStruct ; controls ; problemLimits ; problemCells};
    *problemStruct = *allProblem_f1;
    controlsStruct = *allProblem_f2;

    //  Need to impose that we calculate the SLD..
    controlsStruct.calcSldDuringFit = true;

    // ... and use the Bayes bestpars
    problemStruct->fitParams.set_size(1, bayesOutputs_bestPars_size[1]);
    loop_ub = bayesOutputs_bestPars_size[1];
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct->fitParams[problemStruct->fitParams.size(0) * i] =
        bayesOutputs_bestPars_data[i];
    }

    unpackParams(problemStruct, controlsStruct.checks.fitParam,
                 controlsStruct.checks.fitBackgroundParam,
                 controlsStruct.checks.fitQzshift,
                 controlsStruct.checks.fitScalefactor,
                 controlsStruct.checks.fitBulkIn,
                 controlsStruct.checks.fitBulkOut,
                 controlsStruct.checks.fitResolutionParam,
                 controlsStruct.checks.fitDomainRatio);
    prctileConfInts(bayesOutputs_chain, bayesResults_parConfInts->par95,
                    bayesResults_parConfInts->par65,
                    bayesResults_parConfInts->mean);

    // iterShortest(output.chain,length(fitNames),[],0.95);
    //  Calculate 'mean' best fit curves
    reflectivityCalculation(problemStruct, allProblem_f4, &controlsStruct,
      contrastParams, result);
    parseResultToStruct(contrastParams, result, bayesResults_bestFitsMean->ref,
                        expl_temp, bayesResults_bestFitsMean->data, b_expl_temp,
                        bayesResults_bestFitsMean->sld, c_expl_temp,
                        &p_calculationResults_sumChi, &d_expl_temp);
    bayesResults_bestFitsMean->chi = p_calculationResults_sumChi;

    //  2. Reflectivity and SLD shading
    b_problemStruct = *problemStruct;
    refPrctileConfInts(bayesOutputs_chain, &b_problemStruct, allProblem_f4,
                       &controlsStruct, bayesResults_predlims);

    //  ---------------------------------
    //  bayesResults.chain = bayesOutputs.chain;
    // bayesResults.bestPars_Max = bestPars_max;
    // bayesResults.bayesData = bayesOutputs.data;
    //  bayesResults.bestFitsMax = {bestFitMax_Ref, bestFitMax_Sld, bestFitMax_chi};
    //  bayesResults.bestFitsMean = bestFitMean;
    //  bayesResults.predlims = allPredInts;
    //  bayesResults.parConfInts = parConfInts;
    //  bayesResults.bestPars = bayesOutputs.bestPars;
  }

  void processBayes(const ::coder::array<real_T, 2U> &bayesOutputs_bestPars,
                    const ::coder::array<real_T, 2U> &bayesOutputs_chain, const
                    d_struct_T *allProblem_f1, const struct2_T *allProblem_f2,
                    const cell_11 *allProblem_f4, d_struct_T *problemStruct,
                    e_struct_T *contrastParams, cell_wrap_9 result[6],
                    f_struct_T *bayesResults_bestFitsMean, g_struct_T
                    *bayesResults_predlims, struct10_T *bayesResults_parConfInts)
  {
    ::coder::array<cell_wrap_8, 2U> b_expl_temp;
    ::coder::array<cell_wrap_8, 2U> c_expl_temp;
    ::coder::array<cell_wrap_8, 2U> expl_temp;
    d_struct_T b_problemStruct;
    e_struct_T d_expl_temp;
    struct2_T controlsStruct;
    real_T p_calculationResults_sumChi;
    int32_T loop_ub;

    // problem = {problemStruct ; controls ; problemLimits ; problemCells};
    *problemStruct = *allProblem_f1;
    controlsStruct = *allProblem_f2;

    //  Need to impose that we calculate the SLD..
    controlsStruct.calcSldDuringFit = true;

    // ... and use the Bayes bestpars
    problemStruct->fitParams.set_size(1, bayesOutputs_bestPars.size(1));
    loop_ub = bayesOutputs_bestPars.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct->fitParams[problemStruct->fitParams.size(0) * i] =
        bayesOutputs_bestPars[i];
    }

    unpackParams(problemStruct, controlsStruct.checks.fitParam,
                 controlsStruct.checks.fitBackgroundParam,
                 controlsStruct.checks.fitQzshift,
                 controlsStruct.checks.fitScalefactor,
                 controlsStruct.checks.fitBulkIn,
                 controlsStruct.checks.fitBulkOut,
                 controlsStruct.checks.fitResolutionParam,
                 controlsStruct.checks.fitDomainRatio);
    prctileConfInts(bayesOutputs_chain, bayesResults_parConfInts->par95,
                    bayesResults_parConfInts->par65,
                    bayesResults_parConfInts->mean);

    // iterShortest(output.chain,length(fitNames),[],0.95);
    //  Calculate 'mean' best fit curves
    reflectivityCalculation(problemStruct, allProblem_f4, &controlsStruct,
      contrastParams, result);
    parseResultToStruct(contrastParams, result, bayesResults_bestFitsMean->ref,
                        expl_temp, bayesResults_bestFitsMean->data, b_expl_temp,
                        bayesResults_bestFitsMean->sld, c_expl_temp,
                        &p_calculationResults_sumChi, &d_expl_temp);
    bayesResults_bestFitsMean->chi = p_calculationResults_sumChi;

    //  2. Reflectivity and SLD shading
    b_problemStruct = *problemStruct;
    refPrctileConfInts(bayesOutputs_chain, &b_problemStruct, allProblem_f4,
                       &controlsStruct, bayesResults_predlims);

    //  ---------------------------------
    //  bayesResults.chain = bayesOutputs.chain;
    // bayesResults.bestPars_Max = bestPars_max;
    // bayesResults.bayesData = bayesOutputs.data;
    //  bayesResults.bestFitsMax = {bestFitMax_Ref, bestFitMax_Sld, bestFitMax_chi};
    //  bayesResults.bestFitsMean = bestFitMean;
    //  bayesResults.predlims = allPredInts;
    //  bayesResults.parConfInts = parConfInts;
    //  bayesResults.bestPars = bayesOutputs.bestPars;
  }
}

// End of code generation (processBayes.cpp)
