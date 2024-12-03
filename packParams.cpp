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
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void packParams(e_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                  &limits_params, const ::coder::array<real_T, 2U>
                  &limits_backgroundParams, const ::coder::array<real_T, 2U>
                  &limits_scalefactors, const ::coder::array<real_T, 2U>
                  &limits_qzshifts, const ::coder::array<real_T, 2U>
                  &limits_bulkIns, const ::coder::array<real_T, 2U>
                  &limits_bulkOuts, const ::coder::array<real_T, 2U>
                  &limits_resolutionParams, const ::coder::array<real_T, 2U>
                  &limits_domainRatios, ::coder::array<cell_wrap_7, 1U>
                  &fitNames)
  {
    real_T b_y;
    real_T c_y;
    real_T d_y;
    real_T e_y;
    real_T f_y;
    real_T g_y;
    real_T h_y;
    real_T numberOfFitted;
    real_T y;
    int32_T i;
    int32_T i1;
    int32_T loop_ub_tmp;
    int32_T n;
    int32_T numberOfFitted_idx_0_tmp;
    int32_T numberOfTotal;
    int32_T otherCounter;
    uint32_T fitCounter;

    //  We need to pack the parameters into separate vectors of those that
    //  are being fitted, and those that are held constant.
    //  Note that this order of parameters fields is hard-coded by this
    //  routine, packParamsPriors, and getFitNames
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

    if (problemStruct->checks.qzshifts.size(1) == 0) {
      d_y = 0.0;
    } else {
      d_y = coder::nestedIter(problemStruct->checks.qzshifts,
        problemStruct->checks.qzshifts.size(1));
    }

    if (problemStruct->checks.bulkIns.size(1) == 0) {
      e_y = 0.0;
    } else {
      e_y = coder::nestedIter(problemStruct->checks.bulkIns,
        problemStruct->checks.bulkIns.size(1));
    }

    if (problemStruct->checks.bulkOuts.size(1) == 0) {
      f_y = 0.0;
    } else {
      f_y = coder::nestedIter(problemStruct->checks.bulkOuts,
        problemStruct->checks.bulkOuts.size(1));
    }

    if (problemStruct->checks.resolutionParams.size(1) == 0) {
      g_y = 0.0;
    } else {
      g_y = coder::nestedIter(problemStruct->checks.resolutionParams,
        problemStruct->checks.resolutionParams.size(1));
    }

    if (problemStruct->checks.domainRatios.size(1) == 0) {
      h_y = 0.0;
    } else {
      h_y = coder::nestedIter(problemStruct->checks.domainRatios,
        problemStruct->checks.domainRatios.size(1));
    }

    numberOfFitted = ((((((y + b_y) + c_y) + d_y) + e_y) + f_y) + g_y) + h_y;
    numberOfTotal = ((((((problemStruct->params.size(1) +
                          problemStruct->backgroundParams.size(1)) +
                         problemStruct->scalefactors.size(1)) +
                        problemStruct->qzshifts.size(1)) +
                       problemStruct->bulkIns.size(1)) +
                      problemStruct->bulkOuts.size(1)) +
                     problemStruct->resolutionParams.size(1)) +
      problemStruct->domainRatios.size(1);
    loop_ub_tmp = static_cast<int32_T>(numberOfFitted);
    problemStruct->fitParams.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      problemStruct->fitParams[i] = 0.0;
    }

    numberOfFitted_idx_0_tmp = static_cast<int32_T>(static_cast<real_T>
      (numberOfTotal) - numberOfFitted);
    problemStruct->otherParams.set_size(numberOfFitted_idx_0_tmp);
    for (i = 0; i < numberOfFitted_idx_0_tmp; i++) {
      problemStruct->otherParams[i] = 0.0;
    }

    problemStruct->fitLimits.set_size(loop_ub_tmp, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problemStruct->fitLimits[i1 + problemStruct->fitLimits.size(0) * i] =
          0.0;
      }
    }

    problemStruct->otherLimits.set_size(numberOfFitted_idx_0_tmp, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
        problemStruct->otherLimits[i1 + problemStruct->otherLimits.size(0) * i] =
          0.0;
      }
    }

    fitNames.set_size(loop_ub_tmp);
    for (int32_T b_i{0}; b_i < loop_ub_tmp; b_i++) {
      fitNames[b_i].f1.set_size(1, 0);
    }

    fitCounter = 1U;
    otherCounter = 0;
    i = problemStruct->checks.params.size(1);
    for (n = 0; n < i; n++) {
      if (problemStruct->checks.params[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->params[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_params[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_params[n +
          limits_params.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.params[problemStruct->names.params.size(0) * n].
          f1.size(1));
        numberOfFitted_idx_0_tmp = problemStruct->names.params[n].f1.size(1);
        for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.params[n].f1[i1];
        }

        fitCounter++;
      } else {
        problemStruct->otherParams[otherCounter] = problemStruct->params[n];
        problemStruct->otherLimits[otherCounter] = limits_params[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_params[n +
          limits_params.size(0)];
        otherCounter++;
      }
    }

    i = problemStruct->checks.backgroundParams.size(1);
    for (n = 0; n < i; n++) {
      if (problemStruct->checks.backgroundParams[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->backgroundParams[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_backgroundParams[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_backgroundParams[n +
          limits_backgroundParams.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.backgroundParams
          [problemStruct->names.backgroundParams.size(0) * n].f1.size(1));
        numberOfFitted_idx_0_tmp = problemStruct->names.backgroundParams[n].
          f1.size(1);
        for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.backgroundParams[n].f1[i1];
        }

        fitCounter++;
      } else {
        problemStruct->otherParams[otherCounter] =
          problemStruct->backgroundParams[n];
        problemStruct->otherLimits[otherCounter] = limits_backgroundParams[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_backgroundParams[n +
          limits_backgroundParams.size(0)];
        otherCounter++;
      }
    }

    i = problemStruct->checks.scalefactors.size(1);
    for (n = 0; n < i; n++) {
      if (problemStruct->checks.scalefactors[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->scalefactors[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_scalefactors[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_scalefactors[n +
          limits_scalefactors.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.scalefactors
          [problemStruct->names.scalefactors.size(0) * n].f1.size(1));
        numberOfFitted_idx_0_tmp = problemStruct->names.scalefactors[n].f1.size
          (1);
        for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.scalefactors[n].f1[i1];
        }

        fitCounter++;
      } else {
        problemStruct->otherParams[otherCounter] = problemStruct->scalefactors[n];
        problemStruct->otherLimits[otherCounter] = limits_scalefactors[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_scalefactors[n +
          limits_scalefactors.size(0)];
        otherCounter++;
      }
    }

    i = problemStruct->checks.qzshifts.size(1);
    for (n = 0; n < i; n++) {
      if (problemStruct->checks.qzshifts[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->qzshifts[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_qzshifts[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_qzshifts[n +
          limits_qzshifts.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.qzshifts[problemStruct->names.qzshifts.size(0) *
          n].f1.size(1));
        numberOfFitted_idx_0_tmp = problemStruct->names.qzshifts[n].f1.size(1);
        for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.qzshifts[n].f1[i1];
        }

        fitCounter++;
      } else {
        problemStruct->otherParams[otherCounter] = problemStruct->qzshifts[n];
        problemStruct->otherLimits[otherCounter] = limits_qzshifts[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_qzshifts[n +
          limits_qzshifts.size(0)];
        otherCounter++;
      }
    }

    i = problemStruct->checks.bulkIns.size(1);
    for (n = 0; n < i; n++) {
      if (problemStruct->checks.bulkIns[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->bulkIns[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_bulkIns[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_bulkIns[n +
          limits_bulkIns.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.bulkIns[problemStruct->names.bulkIns.size(0) * n]
          .f1.size(1));
        numberOfFitted_idx_0_tmp = problemStruct->names.bulkIns[n].f1.size(1);
        for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.bulkIns[n].f1[i1];
        }

        fitCounter++;
      } else {
        problemStruct->otherParams[otherCounter] = problemStruct->bulkIns[n];
        problemStruct->otherLimits[otherCounter] = limits_bulkIns[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_bulkIns[n +
          limits_bulkIns.size(0)];
        otherCounter++;
      }
    }

    i = problemStruct->checks.bulkOuts.size(1);
    for (n = 0; n < i; n++) {
      if (problemStruct->checks.bulkOuts[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->bulkOuts[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_bulkOuts[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_bulkOuts[n +
          limits_bulkOuts.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.bulkOuts[problemStruct->names.bulkOuts.size(0) *
          n].f1.size(1));
        numberOfFitted_idx_0_tmp = problemStruct->names.bulkOuts[n].f1.size(1);
        for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.bulkOuts[n].f1[i1];
        }

        fitCounter++;
      } else {
        problemStruct->otherParams[otherCounter] = problemStruct->bulkOuts[n];
        problemStruct->otherLimits[otherCounter] = limits_bulkOuts[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_bulkOuts[n +
          limits_bulkOuts.size(0)];
        otherCounter++;
      }
    }

    i = problemStruct->checks.resolutionParams.size(1);
    for (n = 0; n < i; n++) {
      if (problemStruct->checks.resolutionParams[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->resolutionParams[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_resolutionParams[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_resolutionParams[n +
          limits_resolutionParams.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.resolutionParams
          [problemStruct->names.resolutionParams.size(0) * n].f1.size(1));
        numberOfFitted_idx_0_tmp = problemStruct->names.resolutionParams[n].
          f1.size(1);
        for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.resolutionParams[n].f1[i1];
        }

        fitCounter++;
      } else {
        problemStruct->otherParams[otherCounter] =
          problemStruct->resolutionParams[n];
        problemStruct->otherLimits[otherCounter] = limits_resolutionParams[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_resolutionParams[n +
          limits_resolutionParams.size(0)];
        otherCounter++;
      }
    }

    i = problemStruct->checks.domainRatios.size(1);
    for (n = 0; n < i; n++) {
      if (problemStruct->checks.domainRatios[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->domainRatios[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_domainRatios[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_domainRatios[n +
          limits_domainRatios.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.domainRatios
          [problemStruct->names.domainRatios.size(0) * n].f1.size(1));
        numberOfFitted_idx_0_tmp = problemStruct->names.domainRatios[n].f1.size
          (1);
        for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.domainRatios[n].f1[i1];
        }

        fitCounter++;
      } else {
        problemStruct->otherParams[otherCounter] = problemStruct->domainRatios[n];
        problemStruct->otherLimits[otherCounter] = limits_domainRatios[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_domainRatios[n +
          limits_domainRatios.size(0)];
        otherCounter++;
      }
    }
  }
}

// End of code generation (packParams.cpp)
