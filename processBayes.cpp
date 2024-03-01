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
                    2U> &bayesOutputs_chain, const f_struct_T *allProblem_f1,
                    const struct2_T *allProblem_f2, const struct1_T
                    *allProblem_f3, const cell_11 *allProblem_f4, f_struct_T
                    *problemStruct, struct5_T *result, i_struct_T *bayesResults)
  {
    static struct2_T controlsStruct;
    f_struct_T b_problemStruct;
    int32_T i;
    int32_T loop_ub;

    // problem = {problemStruct ; controls ; problemLimits ; problemCells};
    *problemStruct = *allProblem_f1;
    controlsStruct = *allProblem_f2;

    //  Need to impose that we calculate the SLD..
    controlsStruct.calcSldDuringFit = true;

    // ... and use the Bayes bestpars
    problemStruct->fitParams.set_size(1, bayesOutputs_bestPars_size[1]);
    loop_ub = bayesOutputs_bestPars_size[1];
    for (i = 0; i < loop_ub; i++) {
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
    prctileConfInts(bayesOutputs_chain, bayesResults->parConfInts.par95,
                    bayesResults->parConfInts.par65,
                    bayesResults->parConfInts.mean);

    // iterShortest(output.chain,length(fitNames),[],0.95);
    //  Calculate 'mean' best fit curves
    reflectivityCalculation(problemStruct, allProblem_f4, allProblem_f3,
      &controlsStruct, result);
    bayesResults->bestFitsMean.ref.set_size(result->reflectivity.size(0));
    loop_ub = result->reflectivity.size(0);
    for (i = 0; i < loop_ub; i++) {
      bayesResults->bestFitsMean.ref[i] = result->reflectivity[i];
    }

    bayesResults->bestFitsMean.sld.set_size(result->sldProfiles.size(0),
      result->sldProfiles.size(1));
    loop_ub = result->sldProfiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      int32_T b_loop_ub;
      b_loop_ub = result->sldProfiles.size(0);
      for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
        bayesResults->bestFitsMean.sld[i1 + bayesResults->bestFitsMean.sld.size
          (0) * i] = result->sldProfiles[i1 + result->sldProfiles.size(0) * i];
      }
    }

    bayesResults->bestFitsMean.chi = result->calculationResults.sumChi;
    bayesResults->bestFitsMean.data.set_size(result->shiftedData.size(0));
    loop_ub = result->shiftedData.size(0);
    for (i = 0; i < loop_ub; i++) {
      bayesResults->bestFitsMean.data[i] = result->shiftedData[i];
    }

    //  2. Reflectivity and SLD shading
    b_problemStruct = *problemStruct;
    refPrctileConfInts(bayesOutputs_chain, &b_problemStruct, allProblem_f4,
                       allProblem_f3, &controlsStruct, &bayesResults->predlims);

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
                    f_struct_T *allProblem_f1, const struct2_T *allProblem_f2,
                    const struct1_T *allProblem_f3, const cell_11 *allProblem_f4,
                    f_struct_T *problemStruct, struct5_T *result, i_struct_T
                    *bayesResults)
  {
    static struct2_T controlsStruct;
    f_struct_T b_problemStruct;
    int32_T i;
    int32_T loop_ub;

    // problem = {problemStruct ; controls ; problemLimits ; problemCells};
    *problemStruct = *allProblem_f1;
    controlsStruct = *allProblem_f2;

    //  Need to impose that we calculate the SLD..
    controlsStruct.calcSldDuringFit = true;

    // ... and use the Bayes bestpars
    problemStruct->fitParams.set_size(1, bayesOutputs_bestPars.size(1));
    loop_ub = bayesOutputs_bestPars.size(1);
    for (i = 0; i < loop_ub; i++) {
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
    prctileConfInts(bayesOutputs_chain, bayesResults->parConfInts.par95,
                    bayesResults->parConfInts.par65,
                    bayesResults->parConfInts.mean);

    // iterShortest(output.chain,length(fitNames),[],0.95);
    //  Calculate 'mean' best fit curves
    reflectivityCalculation(problemStruct, allProblem_f4, allProblem_f3,
      &controlsStruct, result);
    bayesResults->bestFitsMean.ref.set_size(result->reflectivity.size(0));
    loop_ub = result->reflectivity.size(0);
    for (i = 0; i < loop_ub; i++) {
      bayesResults->bestFitsMean.ref[i] = result->reflectivity[i];
    }

    bayesResults->bestFitsMean.sld.set_size(result->sldProfiles.size(0),
      result->sldProfiles.size(1));
    loop_ub = result->sldProfiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      int32_T b_loop_ub;
      b_loop_ub = result->sldProfiles.size(0);
      for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
        bayesResults->bestFitsMean.sld[i1 + bayesResults->bestFitsMean.sld.size
          (0) * i] = result->sldProfiles[i1 + result->sldProfiles.size(0) * i];
      }
    }

    bayesResults->bestFitsMean.chi = result->calculationResults.sumChi;
    bayesResults->bestFitsMean.data.set_size(result->shiftedData.size(0));
    loop_ub = result->shiftedData.size(0);
    for (i = 0; i < loop_ub; i++) {
      bayesResults->bestFitsMean.data[i] = result->shiftedData[i];
    }

    //  2. Reflectivity and SLD shading
    b_problemStruct = *problemStruct;
    refPrctileConfInts(bayesOutputs_chain, &b_problemStruct, allProblem_f4,
                       allProblem_f3, &controlsStruct, &bayesResults->predlims);

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
