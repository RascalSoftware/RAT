//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// unpackParams.cpp
//
// Code generation for function 'unpackParams'
//

// Include files
#include "unpackParams.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void unpackParams(ProblemDefinition *problemStruct)
  {
    int fitIndices_data[10000];
    int fitIndices_size[2];
    unsigned int fitCounter;
    int i;
    int i1;
    int j;

    //  Unpack the params out of the fitParams and array back into
    //  problem.params
    //  Note that this order of parameters fields is hard-coded by this
    //  routine, packParams, packParamsPriors, and getFitNames
    coder::d_eml_find(problemStruct->checks.params, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      problemStruct->params[fitIndices_data[j] - 1] = problemStruct->fitParams[j];
    }

    coder::d_eml_find(problemStruct->checks.backgroundParams, fitIndices_data,
                      fitIndices_size);
    i1 = fitIndices_size[1];
    for (j = 0; j < i1; j++) {
      problemStruct->backgroundParams[fitIndices_data[j] - 1] =
        problemStruct->fitParams[static_cast<int>(static_cast<unsigned int>(i) +
        j)];
    }

    fitCounter = (static_cast<unsigned int>(i) + fitIndices_size[1]) + 1U;
    coder::d_eml_find(problemStruct->checks.scalefactors, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      problemStruct->scalefactors[fitIndices_data[j] - 1] =
        problemStruct->fitParams[static_cast<int>(fitCounter + j) - 1];
    }

    fitCounter += fitIndices_size[1];
    coder::d_eml_find(problemStruct->checks.bulkIns, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      problemStruct->bulkIns[fitIndices_data[j] - 1] = problemStruct->fitParams[
        static_cast<int>(fitCounter + j) - 1];
    }

    fitCounter += fitIndices_size[1];
    coder::d_eml_find(problemStruct->checks.bulkOuts, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      problemStruct->bulkOuts[fitIndices_data[j] - 1] = problemStruct->
        fitParams[static_cast<int>(fitCounter + j) - 1];
    }

    fitCounter += fitIndices_size[1];
    coder::d_eml_find(problemStruct->checks.resolutionParams, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      problemStruct->resolutionParams[fitIndices_data[j] - 1] =
        problemStruct->fitParams[static_cast<int>(fitCounter + j) - 1];
    }

    fitCounter += fitIndices_size[1];
    coder::d_eml_find(problemStruct->checks.domainRatios, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      problemStruct->domainRatios[fitIndices_data[j] - 1] =
        problemStruct->fitParams[static_cast<int>(fitCounter + j) - 1];
    }
  }
}

// End of code generation (unpackParams.cpp)
