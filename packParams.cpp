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
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  void packParams(e_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                  &limits_param, const ::coder::array<real_T, 2U>
                  &limits_backgroundParam, const ::coder::array<real_T, 2U>
                  &limits_scalefactor, const ::coder::array<real_T, 2U>
                  &limits_qzshift, const ::coder::array<real_T, 2U>
                  &limits_bulkIn, const ::coder::array<real_T, 2U>
                  &limits_bulkOut, const ::coder::array<real_T, 2U>
                  &limits_resolutionParam, const ::coder::array<real_T, 2U>
                  &limits_domainRatio, const struct4_T *checks, ::coder::array<
                  cell_wrap_7, 1U> &fitNames)
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

    // We need to pack the parameters into separate vectors
    // of those that are being fitted, and those that are
    // held constant.
    if (checks->fitParam.size(1) == 0) {
      y = 0.0;
    } else {
      y = coder::nestedIter(checks->fitParam, checks->fitParam.size(1));
    }

    if (checks->fitBackgroundParam.size(1) == 0) {
      b_y = 0.0;
    } else {
      b_y = coder::nestedIter(checks->fitBackgroundParam,
        checks->fitBackgroundParam.size(1));
    }

    if (checks->fitScalefactor.size(1) == 0) {
      c_y = 0.0;
    } else {
      c_y = coder::nestedIter(checks->fitScalefactor,
        checks->fitScalefactor.size(1));
    }

    if (checks->fitQzshift.size(1) == 0) {
      d_y = 0.0;
    } else {
      d_y = coder::nestedIter(checks->fitQzshift, checks->fitQzshift.size(1));
    }

    if (checks->fitBulkIn.size(1) == 0) {
      e_y = 0.0;
    } else {
      e_y = coder::nestedIter(checks->fitBulkIn, checks->fitBulkIn.size(1));
    }

    if (checks->fitBulkOut.size(1) == 0) {
      f_y = 0.0;
    } else {
      f_y = coder::nestedIter(checks->fitBulkOut, checks->fitBulkOut.size(1));
    }

    if (checks->fitResolutionParam.size(1) == 0) {
      g_y = 0.0;
    } else {
      g_y = coder::nestedIter(checks->fitResolutionParam,
        checks->fitResolutionParam.size(1));
    }

    if (checks->fitDomainRatio.size(1) == 0) {
      h_y = 0.0;
    } else {
      h_y = coder::nestedIter(checks->fitDomainRatio,
        checks->fitDomainRatio.size(1));
    }

    numberOfFitted = ((((((y + b_y) + c_y) + d_y) + e_y) + f_y) + g_y) + h_y;
    numberOfTotal = ((((((problemStruct->params.size(1) +
                          problemStruct->backgroundParams.size(1)) +
                         problemStruct->scalefactors.size(1)) +
                        problemStruct->qzshifts.size(1)) +
                       problemStruct->bulkIn.size(1)) +
                      problemStruct->bulkOut.size(1)) +
                     problemStruct->resolutionParams.size(1)) +
      problemStruct->domainRatio.size(1);
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
    problemStruct->otherLimits.set_size(numberOfFitted_idx_0_tmp, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problemStruct->fitLimits[i1 + problemStruct->fitLimits.size(0) * i] =
          0.0;
      }

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
    i = checks->fitParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitParam[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->params[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_param[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_param[n +
          limits_param.size(0)];
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
        problemStruct->otherLimits[otherCounter] = limits_param[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_param[n +
          limits_param.size(0)];
        otherCounter++;
      }
    }

    // Also do the same for backgrounds...
    i = checks->fitBackgroundParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBackgroundParam[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->backgroundParams[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_backgroundParam[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_backgroundParam[n +
          limits_backgroundParam.size(0)];
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
        problemStruct->otherLimits[otherCounter] = limits_backgroundParam[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_backgroundParam[n +
          limits_backgroundParam.size(0)];
        otherCounter++;
      }
    }

    // ..also for the scale factors
    i = checks->fitScalefactor.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitScalefactor[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->scalefactors[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_scalefactor[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_scalefactor[n +
          limits_scalefactor.size(0)];
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
        problemStruct->otherLimits[otherCounter] = limits_scalefactor[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_scalefactor[n +
          limits_scalefactor.size(0)];
        otherCounter++;
      }
    }

    // Need qzshifts
    i = checks->fitQzshift.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitQzshift[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->qzshifts[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_qzshift[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_qzshift[n +
          limits_qzshift.size(0)];
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
        problemStruct->otherLimits[otherCounter] = limits_qzshift[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_qzshift[n +
          limits_qzshift.size(0)];
        otherCounter++;
      }
    }

    // Bulk In
    i = checks->fitBulkIn.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBulkIn[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->bulkIn[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_bulkIn[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_bulkIn[n +
          limits_bulkIn.size(0)];
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
        problemStruct->otherParams[otherCounter] = problemStruct->bulkIn[n];
        problemStruct->otherLimits[otherCounter] = limits_bulkIn[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_bulkIn[n +
          limits_bulkIn.size(0)];
        otherCounter++;
      }
    }

    // Bulk Out
    i = checks->fitBulkOut.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBulkOut[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->bulkOut[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_bulkOut[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_bulkOut[n +
          limits_bulkOut.size(0)];
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
        problemStruct->otherParams[otherCounter] = problemStruct->bulkOut[n];
        problemStruct->otherLimits[otherCounter] = limits_bulkOut[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_bulkOut[n +
          limits_bulkOut.size(0)];
        otherCounter++;
      }
    }

    // Resolution.....
    i = checks->fitResolutionParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitResolutionParam[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->resolutionParams[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_resolutionParam[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_resolutionParam[n +
          limits_resolutionParam.size(0)];
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
        problemStruct->otherLimits[otherCounter] = limits_resolutionParam[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_resolutionParam[n +
          limits_resolutionParam.size(0)];
        otherCounter++;
      }
    }

    //  Domain Ratio
    i = checks->fitDomainRatio.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitDomainRatio[n] == 1.0) {
        problemStruct->fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->domainRatio[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_domainRatio[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_domainRatio[n +
          limits_domainRatio.size(0)];
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
        problemStruct->otherParams[otherCounter] = problemStruct->domainRatio[n];
        problemStruct->otherLimits[otherCounter] = limits_domainRatio[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_domainRatio[n +
          limits_domainRatio.size(0)];
        otherCounter++;
      }
    }
  }

  void packParams(g_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                  &limits_param, const ::coder::array<real_T, 2U>
                  &limits_backgroundParam, const ::coder::array<real_T, 2U>
                  &limits_scalefactor, const ::coder::array<real_T, 2U>
                  &limits_qzshift, const ::coder::array<real_T, 2U>
                  &limits_bulkIn, const ::coder::array<real_T, 2U>
                  &limits_bulkOut, const ::coder::array<real_T, 2U>
                  &limits_resolutionParam, const ::coder::array<real_T, 2U>
                  &limits_domainRatio, const struct4_T *checks, ::coder::array<
                  cell_wrap_7, 1U> &fitNames)
  {
    ::coder::array<real_T, 1U> fitParams;
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

    // We need to pack the parameters into separate vectors
    // of those that are being fitted, and those that are
    // held constant.
    if (checks->fitParam.size(1) == 0) {
      y = 0.0;
    } else {
      y = coder::nestedIter(checks->fitParam, checks->fitParam.size(1));
    }

    if (checks->fitBackgroundParam.size(1) == 0) {
      b_y = 0.0;
    } else {
      b_y = coder::nestedIter(checks->fitBackgroundParam,
        checks->fitBackgroundParam.size(1));
    }

    if (checks->fitScalefactor.size(1) == 0) {
      c_y = 0.0;
    } else {
      c_y = coder::nestedIter(checks->fitScalefactor,
        checks->fitScalefactor.size(1));
    }

    if (checks->fitQzshift.size(1) == 0) {
      d_y = 0.0;
    } else {
      d_y = coder::nestedIter(checks->fitQzshift, checks->fitQzshift.size(1));
    }

    if (checks->fitBulkIn.size(1) == 0) {
      e_y = 0.0;
    } else {
      e_y = coder::nestedIter(checks->fitBulkIn, checks->fitBulkIn.size(1));
    }

    if (checks->fitBulkOut.size(1) == 0) {
      f_y = 0.0;
    } else {
      f_y = coder::nestedIter(checks->fitBulkOut, checks->fitBulkOut.size(1));
    }

    if (checks->fitResolutionParam.size(1) == 0) {
      g_y = 0.0;
    } else {
      g_y = coder::nestedIter(checks->fitResolutionParam,
        checks->fitResolutionParam.size(1));
    }

    if (checks->fitDomainRatio.size(1) == 0) {
      h_y = 0.0;
    } else {
      h_y = coder::nestedIter(checks->fitDomainRatio,
        checks->fitDomainRatio.size(1));
    }

    numberOfFitted = ((((((y + b_y) + c_y) + d_y) + e_y) + f_y) + g_y) + h_y;
    numberOfTotal = ((((((problemStruct->params.size(1) +
                          problemStruct->backgroundParams.size(1)) +
                         problemStruct->scalefactors.size(1)) +
                        problemStruct->qzshifts.size(1)) +
                       problemStruct->bulkIn.size(1)) +
                      problemStruct->bulkOut.size(1)) +
                     problemStruct->resolutionParams.size(1)) +
      problemStruct->domainRatio.size(1);
    loop_ub_tmp = static_cast<int32_T>(numberOfFitted);
    fitParams.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      fitParams[i] = 0.0;
    }

    numberOfFitted_idx_0_tmp = static_cast<int32_T>(static_cast<real_T>
      (numberOfTotal) - numberOfFitted);
    problemStruct->otherParams.set_size(numberOfFitted_idx_0_tmp);
    for (i = 0; i < numberOfFitted_idx_0_tmp; i++) {
      problemStruct->otherParams[i] = 0.0;
    }

    problemStruct->fitLimits.set_size(loop_ub_tmp, 2);
    problemStruct->otherLimits.set_size(numberOfFitted_idx_0_tmp, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problemStruct->fitLimits[i1 + problemStruct->fitLimits.size(0) * i] =
          0.0;
      }

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
    i = checks->fitParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitParam[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] = problemStruct->
          params[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_param[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_param[n +
          limits_param.size(0)];
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
        problemStruct->otherLimits[otherCounter] = limits_param[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_param[n +
          limits_param.size(0)];
        otherCounter++;
      }
    }

    // Also do the same for backgrounds...
    i = checks->fitBackgroundParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBackgroundParam[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->backgroundParams[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_backgroundParam[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_backgroundParam[n +
          limits_backgroundParam.size(0)];
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
        problemStruct->otherLimits[otherCounter] = limits_backgroundParam[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_backgroundParam[n +
          limits_backgroundParam.size(0)];
        otherCounter++;
      }
    }

    // ..also for the scale factors
    i = checks->fitScalefactor.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitScalefactor[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->scalefactors[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_scalefactor[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_scalefactor[n +
          limits_scalefactor.size(0)];
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
        problemStruct->otherLimits[otherCounter] = limits_scalefactor[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_scalefactor[n +
          limits_scalefactor.size(0)];
        otherCounter++;
      }
    }

    // Need qzshifts
    i = checks->fitQzshift.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitQzshift[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->qzshifts[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_qzshift[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_qzshift[n +
          limits_qzshift.size(0)];
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
        problemStruct->otherLimits[otherCounter] = limits_qzshift[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_qzshift[n +
          limits_qzshift.size(0)];
        otherCounter++;
      }
    }

    // Bulk In
    i = checks->fitBulkIn.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBulkIn[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] = problemStruct->
          bulkIn[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_bulkIn[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_bulkIn[n +
          limits_bulkIn.size(0)];
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
        problemStruct->otherParams[otherCounter] = problemStruct->bulkIn[n];
        problemStruct->otherLimits[otherCounter] = limits_bulkIn[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_bulkIn[n +
          limits_bulkIn.size(0)];
        otherCounter++;
      }
    }

    // Bulk Out
    i = checks->fitBulkOut.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBulkOut[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] = problemStruct->
          bulkOut[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_bulkOut[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_bulkOut[n +
          limits_bulkOut.size(0)];
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
        problemStruct->otherParams[otherCounter] = problemStruct->bulkOut[n];
        problemStruct->otherLimits[otherCounter] = limits_bulkOut[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_bulkOut[n +
          limits_bulkOut.size(0)];
        otherCounter++;
      }
    }

    // Resolution.....
    i = checks->fitResolutionParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitResolutionParam[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->resolutionParams[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_resolutionParam[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_resolutionParam[n +
          limits_resolutionParam.size(0)];
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
        problemStruct->otherLimits[otherCounter] = limits_resolutionParam[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_resolutionParam[n +
          limits_resolutionParam.size(0)];
        otherCounter++;
      }
    }

    //  Domain Ratio
    i = checks->fitDomainRatio.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitDomainRatio[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->domainRatio[n];
        problemStruct->fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_domainRatio[n];
        problemStruct->fitLimits[(static_cast<int32_T>(fitCounter) +
          problemStruct->fitLimits.size(0)) - 1] = limits_domainRatio[n +
          limits_domainRatio.size(0)];
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
        problemStruct->otherParams[otherCounter] = problemStruct->domainRatio[n];
        problemStruct->otherLimits[otherCounter] = limits_domainRatio[n];
        problemStruct->otherLimits[otherCounter +
          problemStruct->otherLimits.size(0)] = limits_domainRatio[n +
          limits_domainRatio.size(0)];
        otherCounter++;
      }
    }

    numberOfFitted_idx_0_tmp = fitParams.size(0);
    problemStruct->fitParams.set_size(fitParams.size(0), 1);
    for (i = 0; i < 1; i++) {
      for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
        problemStruct->fitParams[i1] = fitParams[i1];
      }
    }
  }

  void packParams(struct0_T *problemStruct, const ::coder::array<real_T, 2U>
                  &limits_param, const ::coder::array<real_T, 2U>
                  &limits_backgroundParam, const ::coder::array<real_T, 2U>
                  &limits_scalefactor, const ::coder::array<real_T, 2U>
                  &limits_qzshift, const ::coder::array<real_T, 2U>
                  &limits_bulkIn, const ::coder::array<real_T, 2U>
                  &limits_bulkOut, const ::coder::array<real_T, 2U>
                  &limits_resolutionParam, const ::coder::array<real_T, 2U>
                  &limits_domainRatio, const struct4_T *checks, ::coder::array<
                  cell_wrap_7, 1U> &fitNames)
  {
    ::coder::array<real_T, 2U> fitLimits;
    ::coder::array<real_T, 2U> otherLimits;
    ::coder::array<real_T, 1U> fitParams;
    ::coder::array<real_T, 1U> otherParams;
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

    // We need to pack the parameters into separate vectors
    // of those that are being fitted, and those that are
    // held constant.
    if (checks->fitParam.size(1) == 0) {
      y = 0.0;
    } else {
      y = coder::nestedIter(checks->fitParam, checks->fitParam.size(1));
    }

    if (checks->fitBackgroundParam.size(1) == 0) {
      b_y = 0.0;
    } else {
      b_y = coder::nestedIter(checks->fitBackgroundParam,
        checks->fitBackgroundParam.size(1));
    }

    if (checks->fitScalefactor.size(1) == 0) {
      c_y = 0.0;
    } else {
      c_y = coder::nestedIter(checks->fitScalefactor,
        checks->fitScalefactor.size(1));
    }

    if (checks->fitQzshift.size(1) == 0) {
      d_y = 0.0;
    } else {
      d_y = coder::nestedIter(checks->fitQzshift, checks->fitQzshift.size(1));
    }

    if (checks->fitBulkIn.size(1) == 0) {
      e_y = 0.0;
    } else {
      e_y = coder::nestedIter(checks->fitBulkIn, checks->fitBulkIn.size(1));
    }

    if (checks->fitBulkOut.size(1) == 0) {
      f_y = 0.0;
    } else {
      f_y = coder::nestedIter(checks->fitBulkOut, checks->fitBulkOut.size(1));
    }

    if (checks->fitResolutionParam.size(1) == 0) {
      g_y = 0.0;
    } else {
      g_y = coder::nestedIter(checks->fitResolutionParam,
        checks->fitResolutionParam.size(1));
    }

    if (checks->fitDomainRatio.size(1) == 0) {
      h_y = 0.0;
    } else {
      h_y = coder::nestedIter(checks->fitDomainRatio,
        checks->fitDomainRatio.size(1));
    }

    numberOfFitted = ((((((y + b_y) + c_y) + d_y) + e_y) + f_y) + g_y) + h_y;
    numberOfTotal = ((((((problemStruct->params.size(1) +
                          problemStruct->backgroundParams.size(1)) +
                         problemStruct->scalefactors.size(1)) +
                        problemStruct->qzshifts.size(1)) +
                       problemStruct->bulkIn.size(1)) +
                      problemStruct->bulkOut.size(1)) +
                     problemStruct->resolutionParams.size(1)) +
      problemStruct->domainRatio.size(1);
    loop_ub_tmp = static_cast<int32_T>(numberOfFitted);
    fitParams.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      fitParams[i] = 0.0;
    }

    numberOfFitted_idx_0_tmp = static_cast<int32_T>(static_cast<real_T>
      (numberOfTotal) - numberOfFitted);
    otherParams.set_size(numberOfFitted_idx_0_tmp);
    for (i = 0; i < numberOfFitted_idx_0_tmp; i++) {
      otherParams[i] = 0.0;
    }

    fitLimits.set_size(loop_ub_tmp, 2);
    otherLimits.set_size(numberOfFitted_idx_0_tmp, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        fitLimits[i1 + fitLimits.size(0) * i] = 0.0;
      }

      for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
        otherLimits[i1 + otherLimits.size(0) * i] = 0.0;
      }
    }

    fitNames.set_size(loop_ub_tmp);
    for (int32_T b_i{0}; b_i < loop_ub_tmp; b_i++) {
      fitNames[b_i].f1.set_size(1, 0);
    }

    fitCounter = 1U;
    otherCounter = 0;
    i = checks->fitParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitParam[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] = problemStruct->
          params[n];
        fitLimits[static_cast<int32_T>(fitCounter) - 1] = limits_param[n];
        fitLimits[(static_cast<int32_T>(fitCounter) + fitLimits.size(0)) - 1] =
          limits_param[n + limits_param.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.params[problemStruct->names.params.size(0) * n].
          f1.size[1]);
        loop_ub_tmp = problemStruct->names.params[n].f1.size[1];
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.params[n].f1.data[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->params[n];
        otherLimits[otherCounter] = limits_param[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits_param[n +
          limits_param.size(0)];
        otherCounter++;
      }
    }

    // Also do the same for backgrounds...
    i = checks->fitBackgroundParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBackgroundParam[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->backgroundParams[n];
        fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_backgroundParam[n];
        fitLimits[(static_cast<int32_T>(fitCounter) + fitLimits.size(0)) - 1] =
          limits_backgroundParam[n + limits_backgroundParam.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.backgroundParams
          [problemStruct->names.backgroundParams.size(0) * n].f1.size[1]);
        loop_ub_tmp = problemStruct->names.backgroundParams[n].f1.size[1];
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.backgroundParams[n].f1.data[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->backgroundParams[n];
        otherLimits[otherCounter] = limits_backgroundParam[n];
        otherLimits[otherCounter + otherLimits.size(0)] =
          limits_backgroundParam[n + limits_backgroundParam.size(0)];
        otherCounter++;
      }
    }

    // ..also for the scale factors
    i = checks->fitScalefactor.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitScalefactor[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->scalefactors[n];
        fitLimits[static_cast<int32_T>(fitCounter) - 1] = limits_scalefactor[n];
        fitLimits[(static_cast<int32_T>(fitCounter) + fitLimits.size(0)) - 1] =
          limits_scalefactor[n + limits_scalefactor.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.scalefactors
          [problemStruct->names.scalefactors.size(0) * n].f1.size[1]);
        loop_ub_tmp = problemStruct->names.scalefactors[n].f1.size[1];
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.scalefactors[n].f1.data[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->scalefactors[n];
        otherLimits[otherCounter] = limits_scalefactor[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits_scalefactor[n +
          limits_scalefactor.size(0)];
        otherCounter++;
      }
    }

    // Need qzshifts
    i = checks->fitQzshift.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitQzshift[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->qzshifts[n];
        fitLimits[static_cast<int32_T>(fitCounter) - 1] = limits_qzshift[n];
        fitLimits[(static_cast<int32_T>(fitCounter) + fitLimits.size(0)) - 1] =
          limits_qzshift[n + limits_qzshift.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.qzshifts[problemStruct->names.qzshifts.size(0) *
          n].f1.size[1]);
        loop_ub_tmp = problemStruct->names.qzshifts[n].f1.size[1];
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.qzshifts[n].f1.data[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->qzshifts[n];
        otherLimits[otherCounter] = limits_qzshift[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits_qzshift[n +
          limits_qzshift.size(0)];
        otherCounter++;
      }
    }

    // Bulk In
    i = checks->fitBulkIn.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBulkIn[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] = problemStruct->
          bulkIn[n];
        fitLimits[static_cast<int32_T>(fitCounter) - 1] = limits_bulkIn[n];
        fitLimits[(static_cast<int32_T>(fitCounter) + fitLimits.size(0)) - 1] =
          limits_bulkIn[n + limits_bulkIn.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.bulkIns[problemStruct->names.bulkIns.size(0) * n]
          .f1.size[1]);
        loop_ub_tmp = problemStruct->names.bulkIns[n].f1.size[1];
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.bulkIns[n].f1.data[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->bulkIn[n];
        otherLimits[otherCounter] = limits_bulkIn[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits_bulkIn[n +
          limits_bulkIn.size(0)];
        otherCounter++;
      }
    }

    // Bulk Out
    i = checks->fitBulkOut.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBulkOut[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] = problemStruct->
          bulkOut[n];
        fitLimits[static_cast<int32_T>(fitCounter) - 1] = limits_bulkOut[n];
        fitLimits[(static_cast<int32_T>(fitCounter) + fitLimits.size(0)) - 1] =
          limits_bulkOut[n + limits_bulkOut.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.bulkOuts[problemStruct->names.bulkOuts.size(0) *
          n].f1.size[1]);
        loop_ub_tmp = problemStruct->names.bulkOuts[n].f1.size[1];
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.bulkOuts[n].f1.data[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->bulkOut[n];
        otherLimits[otherCounter] = limits_bulkOut[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits_bulkOut[n +
          limits_bulkOut.size(0)];
        otherCounter++;
      }
    }

    // Resolution.....
    i = checks->fitResolutionParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitResolutionParam[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->resolutionParams[n];
        fitLimits[static_cast<int32_T>(fitCounter) - 1] =
          limits_resolutionParam[n];
        fitLimits[(static_cast<int32_T>(fitCounter) + fitLimits.size(0)) - 1] =
          limits_resolutionParam[n + limits_resolutionParam.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.resolutionParams
          [problemStruct->names.resolutionParams.size(0) * n].f1.size[1]);
        loop_ub_tmp = problemStruct->names.resolutionParams[n].f1.size[1];
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.resolutionParams[n].f1.data[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->resolutionParams[n];
        otherLimits[otherCounter] = limits_resolutionParam[n];
        otherLimits[otherCounter + otherLimits.size(0)] =
          limits_resolutionParam[n + limits_resolutionParam.size(0)];
        otherCounter++;
      }
    }

    //  Domain Ratio
    i = checks->fitDomainRatio.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitDomainRatio[n] == 1.0) {
        fitParams[static_cast<int32_T>(fitCounter) - 1] =
          problemStruct->domainRatio[n];
        fitLimits[static_cast<int32_T>(fitCounter) - 1] = limits_domainRatio[n];
        fitLimits[(static_cast<int32_T>(fitCounter) + fitLimits.size(0)) - 1] =
          limits_domainRatio[n + limits_domainRatio.size(0)];
        fitNames[static_cast<int32_T>(fitCounter) - 1].f1.set_size(1,
          problemStruct->names.domainRatios
          [problemStruct->names.domainRatios.size(0) * n].f1.size[1]);
        loop_ub_tmp = problemStruct->names.domainRatios[n].f1.size[1];
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          fitNames[static_cast<int32_T>(fitCounter) - 1].f1[i1] =
            problemStruct->names.domainRatios[n].f1.data[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->domainRatio[n];
        otherLimits[otherCounter] = limits_domainRatio[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits_domainRatio[n +
          limits_domainRatio.size(0)];
        otherCounter++;
      }
    }

    problemStruct->fitParams.set_size(fitParams.size(0));
    loop_ub_tmp = fitParams.size(0);
    for (i = 0; i < loop_ub_tmp; i++) {
      problemStruct->fitParams[i] = fitParams[i];
    }

    problemStruct->otherParams.set_size(otherParams.size(0));
    loop_ub_tmp = otherParams.size(0);
    for (i = 0; i < loop_ub_tmp; i++) {
      problemStruct->otherParams[i] = otherParams[i];
    }

    problemStruct->fitLimits.set_size(fitLimits.size(0), 2);
    problemStruct->otherLimits.set_size(otherLimits.size(0), 2);
    loop_ub_tmp = fitLimits.size(0);
    numberOfFitted_idx_0_tmp = otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        problemStruct->fitLimits[i1 + problemStruct->fitLimits.size(0) * i] =
          fitLimits[i1 + fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < numberOfFitted_idx_0_tmp; i1++) {
        problemStruct->otherLimits[i1 + problemStruct->otherLimits.size(0) * i] =
          otherLimits[i1 + otherLimits.size(0) * i];
      }
    }
  }
}

// End of code generation (packParams.cpp)
