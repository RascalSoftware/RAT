//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  void unpackParams(ProblemDefinition &problemStruct)
  {
    static int fitIndices_data[10000];
    int fitIndices_size[2];
    unsigned int fitCounter;
    int i;

    //  Unpack params out of fitParams and back into problem.params.
    //
    //  Parameters
    //  ----------
    //  problemStruct : struct
    //      The project struct.
    //
    //  Returns
    //  -------
    //  problemStruct : struct
    //      The project struct with unpacked fit information.
    //  Note that this order of parameters fields is hard-coded by this
    //  routine, packParams, packParamsPriors, and getFitNames
    coder::d_eml_find(problemStruct.checks.params, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      problemStruct.params[fitIndices_data[j] - 1] = problemStruct.fitParams[j];
    }

    if (fitIndices_size[1] - 1 < 0) {
      fitCounter = 1U;
    } else {
      fitCounter = static_cast<unsigned int>(fitIndices_size[1]) + 1U;
    }

    coder::d_eml_find(problemStruct.checks.backgroundParams, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      problemStruct.backgroundParams[fitIndices_data[j] - 1] =
        problemStruct.fitParams[static_cast<int>(fitCounter + static_cast<
        unsigned int>(j)) - 1];
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<unsigned int>(fitIndices_size[1]);
    }

    coder::d_eml_find(problemStruct.checks.scalefactors, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      problemStruct.scalefactors[fitIndices_data[j] - 1] =
        problemStruct.fitParams[static_cast<int>(fitCounter + static_cast<
        unsigned int>(j)) - 1];
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<unsigned int>(fitIndices_size[1]);
    }

    coder::d_eml_find(problemStruct.checks.bulkIns, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      problemStruct.bulkIns[fitIndices_data[j] - 1] = problemStruct.fitParams[
        static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1];
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<unsigned int>(fitIndices_size[1]);
    }

    coder::d_eml_find(problemStruct.checks.bulkOuts, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      problemStruct.bulkOuts[fitIndices_data[j] - 1] = problemStruct.fitParams[
        static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1];
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<unsigned int>(fitIndices_size[1]);
    }

    coder::d_eml_find(problemStruct.checks.resolutionParams, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      problemStruct.resolutionParams[fitIndices_data[j] - 1] =
        problemStruct.fitParams[static_cast<int>(fitCounter + static_cast<
        unsigned int>(j)) - 1];
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<unsigned int>(fitIndices_size[1]);
    }

    coder::d_eml_find(problemStruct.checks.domainRatios, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      problemStruct.domainRatios[fitIndices_data[j] - 1] =
        problemStruct.fitParams[static_cast<int>(fitCounter + static_cast<
        unsigned int>(j)) - 1];
    }
  }
}

// End of code generation (unpackParams.cpp)
