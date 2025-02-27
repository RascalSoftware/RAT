//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// packParams.cpp
//
// Code generation for function 'packParams'
//

// Include files
#include "packParams.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void packParams(ProblemDefinition *problemStruct, const ::coder::array<double,
                  2U> &limits_params, const ::coder::array<double, 2U>
                  &limits_backgroundParams, const ::coder::array<double, 2U>
                  &limits_scalefactors, const ::coder::array<double, 2U>
                  &limits_bulkIns, const ::coder::array<double, 2U>
                  &limits_bulkOuts, const ::coder::array<double, 2U>
                  &limits_resolutionParams, const ::coder::array<double, 2U>
                  &limits_domainRatios, ::coder::array<cell_wrap_10, 1U>
                  &fitNames)
  {
    double b_y;
    double c_y;
    double d_y;
    double e_y;
    double f_y;
    double g_y;
    double y;
    int fitIndices_data[10000];
    int fitIndices_size[2];
    unsigned int fitCounter;
    int i;
    int i1;
    int i2;
    int j;
    int loop_ub_tmp;

    //  We need to pack the parameters into an array consisting of those
    //  that are being fitted.
    //  Note that this order of parameters fields is hard-coded by this
    //  routine, packParamsPriors, unpackParams, and getFitNames
    if (problemStruct->checks.params.size(1) == 0) {
      y = 0.0;
    } else {
      y = coder::nestedIter(problemStruct->checks.params,
                            problemStruct->checks.params.size(1));
    }

    if (problemStruct->checks.backgroundParams.size(1) == 0) {
      b_y = 0.0;
    } else {
      b_y = coder::nestedIter(problemStruct->checks.backgroundParams,
        problemStruct->checks.backgroundParams.size(1));
    }

    if (problemStruct->checks.scalefactors.size(1) == 0) {
      c_y = 0.0;
    } else {
      c_y = coder::nestedIter(problemStruct->checks.scalefactors,
        problemStruct->checks.scalefactors.size(1));
    }

    if (problemStruct->checks.bulkIns.size(1) == 0) {
      d_y = 0.0;
    } else {
      d_y = coder::nestedIter(problemStruct->checks.bulkIns,
        problemStruct->checks.bulkIns.size(1));
    }

    if (problemStruct->checks.bulkOuts.size(1) == 0) {
      e_y = 0.0;
    } else {
      e_y = coder::nestedIter(problemStruct->checks.bulkOuts,
        problemStruct->checks.bulkOuts.size(1));
    }

    if (problemStruct->checks.resolutionParams.size(1) == 0) {
      f_y = 0.0;
    } else {
      f_y = coder::nestedIter(problemStruct->checks.resolutionParams,
        problemStruct->checks.resolutionParams.size(1));
    }

    if (problemStruct->checks.domainRatios.size(1) == 0) {
      g_y = 0.0;
    } else {
      g_y = coder::nestedIter(problemStruct->checks.domainRatios,
        problemStruct->checks.domainRatios.size(1));
    }

    problemStruct->fitParams.set_size(1, problemStruct->fitParams.size(1));
    loop_ub_tmp = static_cast<int>((((((y + b_y) + c_y) + d_y) + e_y) + f_y) +
      g_y);
    problemStruct->fitParams.set_size(problemStruct->fitParams.size(0),
      loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      problemStruct->fitParams[i] = 0.0;
    }

    problemStruct->fitLimits.set_size(loop_ub_tmp, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problemStruct->fitLimits[i1 + problemStruct->fitLimits.size(0) * i] =
          0.0;
      }
    }

    fitNames.set_size(loop_ub_tmp);
    for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
      fitNames[b_i].f1.set_size(1, 0);
    }

    coder::d_eml_find(problemStruct->checks.params, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      i1 = fitIndices_data[j];
      problemStruct->fitParams[j] = problemStruct->params[i1 - 1];
      problemStruct->fitLimits[j] = limits_params[i1 - 1];
      problemStruct->fitLimits[j + problemStruct->fitLimits.size(0)] =
        limits_params[(i1 + limits_params.size(0)) - 1];
      fitNames[j].f1.set_size(1, problemStruct->names.params
        [problemStruct->names.params.size(0) * (fitIndices_data[fitIndices_size
        [0] * j] - 1)].f1.size(1));
      loop_ub_tmp = problemStruct->names.params[fitIndices_data[j] - 1].f1.size
        (1);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        fitNames[j].f1[i1] = problemStruct->names.params[fitIndices_data[j] - 1]
          .f1[i1];
      }
    }

    coder::d_eml_find(problemStruct->checks.backgroundParams, fitIndices_data,
                      fitIndices_size);
    i1 = fitIndices_size[1];
    for (j = 0; j < i1; j++) {
      i2 = fitIndices_data[j];
      problemStruct->fitParams[static_cast<int>(static_cast<unsigned int>(i) + j)]
        = problemStruct->backgroundParams[i2 - 1];
      problemStruct->fitLimits[static_cast<int>(static_cast<unsigned int>(i) + j)]
        = limits_backgroundParams[i2 - 1];
      problemStruct->fitLimits[static_cast<int>(static_cast<unsigned int>(i) + j)
        + problemStruct->fitLimits.size(0)] = limits_backgroundParams[(i2 +
        limits_backgroundParams.size(0)) - 1];
      fitNames[static_cast<int>(static_cast<unsigned int>(i) + j)].f1.set_size(1,
        problemStruct->names.backgroundParams
        [problemStruct->names.backgroundParams.size(0) *
        (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size(1));
      loop_ub_tmp = problemStruct->names.backgroundParams[fitIndices_data[j] - 1]
        .f1.size(1);
      for (i2 = 0; i2 < loop_ub_tmp; i2++) {
        fitNames[static_cast<int>(static_cast<unsigned int>(i) + j)].f1[i2] =
          problemStruct->names.backgroundParams[fitIndices_data[j] - 1].f1[i2];
      }
    }

    fitCounter = (static_cast<unsigned int>(i) + fitIndices_size[1]) + 1U;
    coder::d_eml_find(problemStruct->checks.scalefactors, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      i1 = fitIndices_data[j];
      i2 = static_cast<int>(fitCounter + j) - 1;
      problemStruct->fitParams[i2] = problemStruct->scalefactors[i1 - 1];
      problemStruct->fitLimits[i2] = limits_scalefactors[i1 - 1];
      problemStruct->fitLimits[i2 + problemStruct->fitLimits.size(0)] =
        limits_scalefactors[(i1 + limits_scalefactors.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + j) - 1].f1.set_size(1,
        problemStruct->names.scalefactors[problemStruct->names.scalefactors.size
        (0) * (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size(1));
      loop_ub_tmp = problemStruct->names.scalefactors[fitIndices_data[j] - 1].
        f1.size(1);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        fitNames[static_cast<int>(fitCounter + j) - 1].f1[i1] =
          problemStruct->names.scalefactors[fitIndices_data[j] - 1].f1[i1];
      }
    }

    fitCounter += fitIndices_size[1];
    coder::d_eml_find(problemStruct->checks.bulkIns, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      i1 = fitIndices_data[j];
      i2 = static_cast<int>(fitCounter + j) - 1;
      problemStruct->fitParams[i2] = problemStruct->bulkIns[i1 - 1];
      problemStruct->fitLimits[i2] = limits_bulkIns[i1 - 1];
      problemStruct->fitLimits[i2 + problemStruct->fitLimits.size(0)] =
        limits_bulkIns[(i1 + limits_bulkIns.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + j) - 1].f1.set_size(1,
        problemStruct->names.bulkIns[problemStruct->names.bulkIns.size(0) *
        (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size(1));
      loop_ub_tmp = problemStruct->names.bulkIns[fitIndices_data[j] - 1].f1.size
        (1);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        fitNames[static_cast<int>(fitCounter + j) - 1].f1[i1] =
          problemStruct->names.bulkIns[fitIndices_data[j] - 1].f1[i1];
      }
    }

    fitCounter += fitIndices_size[1];
    coder::d_eml_find(problemStruct->checks.bulkOuts, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      i1 = fitIndices_data[j];
      i2 = static_cast<int>(fitCounter + j) - 1;
      problemStruct->fitParams[i2] = problemStruct->bulkOuts[i1 - 1];
      problemStruct->fitLimits[i2] = limits_bulkOuts[i1 - 1];
      problemStruct->fitLimits[i2 + problemStruct->fitLimits.size(0)] =
        limits_bulkOuts[(i1 + limits_bulkOuts.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + j) - 1].f1.set_size(1,
        problemStruct->names.bulkOuts[problemStruct->names.bulkOuts.size(0) *
        (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size(1));
      loop_ub_tmp = problemStruct->names.bulkOuts[fitIndices_data[j] - 1].
        f1.size(1);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        fitNames[static_cast<int>(fitCounter + j) - 1].f1[i1] =
          problemStruct->names.bulkOuts[fitIndices_data[j] - 1].f1[i1];
      }
    }

    fitCounter += fitIndices_size[1];
    coder::d_eml_find(problemStruct->checks.resolutionParams, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      i1 = fitIndices_data[j];
      i2 = static_cast<int>(fitCounter + j) - 1;
      problemStruct->fitParams[i2] = problemStruct->resolutionParams[i1 - 1];
      problemStruct->fitLimits[i2] = limits_resolutionParams[i1 - 1];
      problemStruct->fitLimits[i2 + problemStruct->fitLimits.size(0)] =
        limits_resolutionParams[(i1 + limits_resolutionParams.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + j) - 1].f1.set_size(1,
        problemStruct->names.resolutionParams
        [problemStruct->names.resolutionParams.size(0) *
        (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size(1));
      loop_ub_tmp = problemStruct->names.resolutionParams[fitIndices_data[j] - 1]
        .f1.size(1);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        fitNames[static_cast<int>(fitCounter + j) - 1].f1[i1] =
          problemStruct->names.resolutionParams[fitIndices_data[j] - 1].f1[i1];
      }
    }

    fitCounter += fitIndices_size[1];
    coder::d_eml_find(problemStruct->checks.domainRatios, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (j = 0; j < i; j++) {
      i1 = fitIndices_data[j];
      i2 = static_cast<int>(fitCounter + j) - 1;
      problemStruct->fitParams[i2] = problemStruct->domainRatios[i1 - 1];
      problemStruct->fitLimits[i2] = limits_domainRatios[i1 - 1];
      problemStruct->fitLimits[i2 + problemStruct->fitLimits.size(0)] =
        limits_domainRatios[(i1 + limits_domainRatios.size(0)) - 1];
      fitNames[static_cast<int>(fitCounter + j) - 1].f1.set_size(1,
        problemStruct->names.domainRatios[problemStruct->names.domainRatios.size
        (0) * (fitIndices_data[fitIndices_size[0] * j] - 1)].f1.size(1));
      loop_ub_tmp = problemStruct->names.domainRatios[fitIndices_data[j] - 1].
        f1.size(1);
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        fitNames[static_cast<int>(fitCounter + j) - 1].f1[i1] =
          problemStruct->names.domainRatios[fitIndices_data[j] - 1].f1[i1];
      }
    }
  }
}

// End of code generation (packParams.cpp)
