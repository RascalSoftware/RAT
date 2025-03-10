//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// packParams.cpp
//
// Code generation for function 'packParams'
//

// Include files
#include "packParams.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void packParams(ProblemDefinition &problemStruct, const ::coder::array<double,
                  2U> &limits_params, const ::coder::array<double, 2U>
                  &limits_backgroundParams, const ::coder::array<double, 2U>
                  &limits_scalefactors, const ::coder::array<double, 2U>
                  &limits_bulkIns, const ::coder::array<double, 2U>
                  &limits_bulkOuts, const ::coder::array<double, 2U>
                  &limits_resolutionParams, const ::coder::array<double, 2U>
                  &limits_domainRatios, ::coder::array<cell_wrap_10, 1U>
                  &fitNames)
  {
    double numberOfFitted;
    int fitIndices_data[10000];
    int fitIndices_size[2];
    unsigned int fitCounter;
    int i;
    int i1;
    int loop_ub;

    //  We need to pack the parameters into an array consisting of those
    //  that are being fitted.
    //  Note that this order of parameters fields is hard-coded by this
    //  routine, packParamsPriors, unpackParams, and getFitNames
    numberOfFitted = (((((coder::sum(problemStruct.checks.params) + coder::sum
                          (problemStruct.checks.backgroundParams)) + coder::sum
                         (problemStruct.checks.scalefactors)) + coder::sum
                        (problemStruct.checks.bulkIns)) + coder::sum
                       (problemStruct.checks.bulkOuts)) + coder::sum
                      (problemStruct.checks.resolutionParams)) + coder::sum
      (problemStruct.checks.domainRatios);
    problemStruct.fitParams.set_size(1, problemStruct.fitParams.size(1));
    loop_ub = static_cast<int>((((((coder::sum(problemStruct.checks.params) +
      coder::sum(problemStruct.checks.backgroundParams)) + coder::sum
      (problemStruct.checks.scalefactors)) + coder::sum
      (problemStruct.checks.bulkIns)) + coder::sum(problemStruct.checks.bulkOuts))
      + coder::sum(problemStruct.checks.resolutionParams)) + coder::sum
      (problemStruct.checks.domainRatios));
    i = static_cast<int>(numberOfFitted);
    problemStruct.fitParams.set_size(problemStruct.fitParams.size(0), i);
    for (i = 0; i < loop_ub; i++) {
      problemStruct.fitParams[i] = 0.0;
    }

    i = static_cast<int>(numberOfFitted);
    problemStruct.fitLimits.set_size(i, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        problemStruct.fitLimits[i1 + problemStruct.fitLimits.size(0) * i] = 0.0;
      }
    }

    i = static_cast<int>(numberOfFitted);
    fitNames.set_size(i);
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      fitNames[b_i].f1.set_size(1, 0);
    }

    coder::d_eml_find(problemStruct.checks.params, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      i1 = fitIndices_data[j];
      problemStruct.fitParams[j] = problemStruct.params[i1 - 1];
      problemStruct.fitLimits[j] = limits_params[i1 - 1];
      problemStruct.fitLimits[j + problemStruct.fitLimits.size(0)] =
        limits_params[(i1 + limits_params.size(0)) - 1];
      fitNames[j].f1.set_size(1,
        problemStruct.names.params[problemStruct.names.params.size(0) *
        (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size(1));
      loop_ub = problemStruct.names.params[fitIndices_data[j] - 1].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[j].f1[i1] = problemStruct.names.params[fitIndices_data[j] - 1].
          f1[i1];
      }
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
      i1 = fitIndices_data[j];
      loop_ub = static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1;
      problemStruct.fitParams[loop_ub] = problemStruct.backgroundParams[i1 - 1];
      problemStruct.fitLimits[loop_ub] = limits_backgroundParams[i1 - 1];
      problemStruct.fitLimits[loop_ub + problemStruct.fitLimits.size(0)] =
        limits_backgroundParams[(i1 + limits_backgroundParams.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1].
        f1.set_size(1,
                    problemStruct.names.backgroundParams[problemStruct.names.backgroundParams.size
                    (0) * (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size
                    (1));
      loop_ub = problemStruct.names.backgroundParams[fitIndices_data[j] - 1].
        f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1]
          .f1[i1] = problemStruct.names.backgroundParams[fitIndices_data[j] - 1]
          .f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<unsigned int>(fitIndices_size[1]);
    }

    coder::d_eml_find(problemStruct.checks.scalefactors, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      i1 = fitIndices_data[j];
      loop_ub = static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1;
      problemStruct.fitParams[loop_ub] = problemStruct.scalefactors[i1 - 1];
      problemStruct.fitLimits[loop_ub] = limits_scalefactors[i1 - 1];
      problemStruct.fitLimits[loop_ub + problemStruct.fitLimits.size(0)] =
        limits_scalefactors[(i1 + limits_scalefactors.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1].
        f1.set_size(1,
                    problemStruct.names.scalefactors[problemStruct.names.scalefactors.size
                    (0) * (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size
                    (1));
      loop_ub = problemStruct.names.scalefactors[fitIndices_data[j] - 1].f1.size
        (1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1]
          .f1[i1] = problemStruct.names.scalefactors[fitIndices_data[j] - 1]
          .f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<unsigned int>(fitIndices_size[1]);
    }

    coder::d_eml_find(problemStruct.checks.bulkIns, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      i1 = fitIndices_data[j];
      loop_ub = static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1;
      problemStruct.fitParams[loop_ub] = problemStruct.bulkIns[i1 - 1];
      problemStruct.fitLimits[loop_ub] = limits_bulkIns[i1 - 1];
      problemStruct.fitLimits[loop_ub + problemStruct.fitLimits.size(0)] =
        limits_bulkIns[(i1 + limits_bulkIns.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1].
        f1.set_size(1,
                    problemStruct.names.bulkIns[problemStruct.names.bulkIns.size
                    (0) * (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size
                    (1));
      loop_ub = problemStruct.names.bulkIns[fitIndices_data[j] - 1].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1]
          .f1[i1] = problemStruct.names.bulkIns[fitIndices_data[j] - 1].f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<unsigned int>(fitIndices_size[1]);
    }

    coder::d_eml_find(problemStruct.checks.bulkOuts, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      i1 = fitIndices_data[j];
      loop_ub = static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1;
      problemStruct.fitParams[loop_ub] = problemStruct.bulkOuts[i1 - 1];
      problemStruct.fitLimits[loop_ub] = limits_bulkOuts[i1 - 1];
      problemStruct.fitLimits[loop_ub + problemStruct.fitLimits.size(0)] =
        limits_bulkOuts[(i1 + limits_bulkOuts.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1].
        f1.set_size(1,
                    problemStruct.names.bulkOuts[problemStruct.names.bulkOuts.size
                    (0) * (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size
                    (1));
      loop_ub = problemStruct.names.bulkOuts[fitIndices_data[j] - 1].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1]
          .f1[i1] = problemStruct.names.bulkOuts[fitIndices_data[j] - 1].f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<unsigned int>(fitIndices_size[1]);
    }

    coder::d_eml_find(problemStruct.checks.resolutionParams, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      i1 = fitIndices_data[j];
      loop_ub = static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1;
      problemStruct.fitParams[loop_ub] = problemStruct.resolutionParams[i1 - 1];
      problemStruct.fitLimits[loop_ub] = limits_resolutionParams[i1 - 1];
      problemStruct.fitLimits[loop_ub + problemStruct.fitLimits.size(0)] =
        limits_resolutionParams[(i1 + limits_resolutionParams.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1].
        f1.set_size(1,
                    problemStruct.names.resolutionParams[problemStruct.names.resolutionParams.size
                    (0) * (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size
                    (1));
      loop_ub = problemStruct.names.resolutionParams[fitIndices_data[j] - 1].
        f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1]
          .f1[i1] = problemStruct.names.resolutionParams[fitIndices_data[j] - 1]
          .f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<unsigned int>(fitIndices_size[1]);
    }

    coder::d_eml_find(problemStruct.checks.domainRatios, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int j{0}; j < i; j++) {
      i1 = fitIndices_data[j];
      loop_ub = static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1;
      problemStruct.fitParams[loop_ub] = problemStruct.domainRatios[i1 - 1];
      problemStruct.fitLimits[loop_ub] = limits_domainRatios[i1 - 1];
      problemStruct.fitLimits[loop_ub + problemStruct.fitLimits.size(0)] =
        limits_domainRatios[(i1 + limits_domainRatios.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1].
        f1.set_size(1,
                    problemStruct.names.domainRatios[problemStruct.names.domainRatios.size
                    (0) * (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size
                    (1));
      loop_ub = problemStruct.names.domainRatios[fitIndices_data[j] - 1].f1.size
        (1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[static_cast<int>(fitCounter + static_cast<unsigned int>(j)) - 1]
          .f1[i1] = problemStruct.names.domainRatios[fitIndices_data[j] - 1]
          .f1[i1];
      }
    }
  }
}

// End of code generation (packParams.cpp)
