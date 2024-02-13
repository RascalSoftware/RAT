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
  void packParams(d_struct_T *problemStruct, const ::coder::array<cell_wrap_1,
                  2U> &problemCells_f7, const ::coder::array<cell_wrap_1, 2U>
                  &problemCells_f8, const ::coder::array<cell_wrap_1, 2U>
                  &problemCells_f9, const ::coder::array<cell_wrap_1, 2U>
                  &problemCells_f10, const ::coder::array<cell_wrap_1, 2U>
                  &problemCells_f11, const ::coder::array<cell_wrap_1, 2U>
                  &problemCells_f12, const ::coder::array<cell_wrap_1, 2U>
                  &problemCells_f13, const ::coder::array<cell_wrap_1, 2U>
                  &problemCells_f20, const struct1_T *limits, const struct3_T
                  *checks, ::coder::array<cell_wrap_1, 1U> &fitNames)
  {
    ::coder::array<real_T, 2U> fitLimits;
    ::coder::array<real_T, 2U> fitParams;
    ::coder::array<real_T, 2U> otherLimits;
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
    int32_T b_loop_ub;
    int32_T fitCounter;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T n;
    int32_T numberOfTotal;
    int32_T otherCounter;

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
    fitParams.set_size(problemStruct->fitParams.size(0),
                       problemStruct->fitParams.size(1));
    loop_ub = problemStruct->fitParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = problemStruct->fitParams.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        fitParams[i1 + fitParams.size(0) * i] = problemStruct->fitParams[i1 +
          problemStruct->fitParams.size(0) * i];
      }
    }

    // zeros(numberOfFitted,1);
    b_loop_ub = static_cast<int32_T>(static_cast<real_T>(numberOfTotal) -
      numberOfFitted);
    otherParams.set_size(b_loop_ub);
    for (i = 0; i < b_loop_ub; i++) {
      otherParams[i] = 0.0;
    }

    loop_ub = static_cast<int32_T>(numberOfFitted);
    fitLimits.set_size(loop_ub, 2);
    otherLimits.set_size(b_loop_ub, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitLimits[i1 + fitLimits.size(0) * i] = 0.0;
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        otherLimits[i1 + otherLimits.size(0) * i] = 0.0;
      }
    }

    // limits = problemStruct.limits;
    fitNames.set_size(loop_ub);
    for (int32_T b_i{0}; b_i < loop_ub; b_i++) {
      fitNames[b_i].f1.set_size(1, 0);
    }

    fitCounter = 0;
    otherCounter = 0;
    i = checks->fitParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitParam[n] == 1.0) {
        fitParams[fitCounter] = problemStruct->params[n];
        fitLimits[fitCounter] = limits->param[n];
        fitLimits[fitCounter + fitLimits.size(0)] = limits->param[n +
          limits->param.size(0)];
        loop_ub = problemCells_f7[n].f1.size(1);
        fitNames[fitCounter].f1.set_size(1, problemCells_f7[problemCells_f7.size
          (0) * n].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          fitNames[fitCounter].f1[i1] = problemCells_f7[n].f1[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->params[n];
        otherLimits[otherCounter] = limits->param[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits->param[n +
          limits->param.size(0)];
        otherCounter++;
      }
    }

    // Also do the same for backgrounds...
    i = checks->fitBackgroundParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBackgroundParam[n] == 1.0) {
        fitParams[fitCounter] = problemStruct->backgroundParams[n];
        fitLimits[fitCounter] = limits->backgroundParam[n];
        fitLimits[fitCounter + fitLimits.size(0)] = limits->backgroundParam[n +
          limits->backgroundParam.size(0)];
        loop_ub = problemCells_f8[n].f1.size(1);
        fitNames[fitCounter].f1.set_size(1, problemCells_f8[problemCells_f8.size
          (0) * n].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          fitNames[fitCounter].f1[i1] = problemCells_f8[n].f1[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->backgroundParams[n];
        otherLimits[otherCounter] = limits->backgroundParam[n];
        otherLimits[otherCounter + otherLimits.size(0)] =
          limits->backgroundParam[n + limits->backgroundParam.size(0)];
        otherCounter++;
      }
    }

    // ..also for the scale factors
    i = checks->fitScalefactor.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitScalefactor[n] == 1.0) {
        fitParams[fitCounter] = problemStruct->scalefactors[n];
        fitLimits[fitCounter] = limits->scalefactor[n];
        fitLimits[fitCounter + fitLimits.size(0)] = limits->scalefactor[n +
          limits->scalefactor.size(0)];
        loop_ub = problemCells_f9[n].f1.size(1);
        fitNames[fitCounter].f1.set_size(1, problemCells_f9[problemCells_f9.size
          (0) * n].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          fitNames[fitCounter].f1[i1] = problemCells_f9[n].f1[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->scalefactors[n];
        otherLimits[otherCounter] = limits->scalefactor[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits->scalefactor[n
          + limits->scalefactor.size(0)];
        otherCounter++;
      }
    }

    // Need qzshifts
    i = checks->fitQzshift.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitQzshift[n] == 1.0) {
        fitParams[fitCounter] = problemStruct->qzshifts[n];
        fitLimits[fitCounter] = limits->qzshift[n];
        fitLimits[fitCounter + fitLimits.size(0)] = limits->qzshift[n +
          limits->qzshift.size(0)];
        loop_ub = problemCells_f10[n].f1.size(1);
        fitNames[fitCounter].f1.set_size(1,
          problemCells_f10[problemCells_f10.size(0) * n].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          fitNames[fitCounter].f1[i1] = problemCells_f10[n].f1[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->qzshifts[n];
        otherLimits[otherCounter] = limits->qzshift[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits->qzshift[n +
          limits->qzshift.size(0)];
        otherCounter++;
      }
    }

    // Bulk In
    i = checks->fitBulkIn.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBulkIn[n] == 1.0) {
        fitParams[fitCounter] = problemStruct->bulkIn[n];
        fitLimits[fitCounter] = limits->bulkIn[n];
        fitLimits[fitCounter + fitLimits.size(0)] = limits->bulkIn[n +
          limits->bulkIn.size(0)];
        loop_ub = problemCells_f11[n].f1.size(1);
        fitNames[fitCounter].f1.set_size(1,
          problemCells_f11[problemCells_f11.size(0) * n].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          fitNames[fitCounter].f1[i1] = problemCells_f11[n].f1[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->bulkIn[n];
        otherLimits[otherCounter] = limits->bulkIn[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits->bulkIn[n +
          limits->bulkIn.size(0)];
        otherCounter++;
      }
    }

    // Bulk Out
    i = checks->fitBulkOut.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitBulkOut[n] == 1.0) {
        fitParams[fitCounter] = problemStruct->bulkOut[n];
        fitLimits[fitCounter] = limits->bulkOut[n];
        fitLimits[fitCounter + fitLimits.size(0)] = limits->bulkOut[n +
          limits->bulkOut.size(0)];
        loop_ub = problemCells_f12[n].f1.size(1);
        fitNames[fitCounter].f1.set_size(1,
          problemCells_f12[problemCells_f12.size(0) * n].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          fitNames[fitCounter].f1[i1] = problemCells_f12[n].f1[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->bulkOut[n];
        otherLimits[otherCounter] = limits->bulkOut[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits->bulkOut[n +
          limits->bulkOut.size(0)];
        otherCounter++;
      }
    }

    // Resolution.....
    i = checks->fitResolutionParam.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitResolutionParam[n] == 1.0) {
        fitParams[fitCounter] = problemStruct->resolutionParams[n];
        fitLimits[fitCounter] = limits->resolutionParam[n];
        fitLimits[fitCounter + fitLimits.size(0)] = limits->resolutionParam[n +
          limits->resolutionParam.size(0)];
        loop_ub = problemCells_f13[n].f1.size(1);
        fitNames[fitCounter].f1.set_size(1,
          problemCells_f13[problemCells_f13.size(0) * n].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          fitNames[fitCounter].f1[i1] = problemCells_f13[n].f1[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->resolutionParams[n];
        otherLimits[otherCounter] = limits->resolutionParam[n];
        otherLimits[otherCounter + otherLimits.size(0)] =
          limits->resolutionParam[n + limits->resolutionParam.size(0)];
        otherCounter++;
      }
    }

    //  Domain Ratio
    i = checks->fitDomainRatio.size(1);
    for (n = 0; n < i; n++) {
      if (checks->fitDomainRatio[n] == 1.0) {
        fitParams[fitCounter] = problemStruct->domainRatio[n];
        fitLimits[fitCounter] = limits->domainRatio[n];
        fitLimits[fitCounter + fitLimits.size(0)] = limits->domainRatio[n +
          limits->domainRatio.size(0)];
        loop_ub = problemCells_f20[n].f1.size(1);
        fitNames[fitCounter].f1.set_size(1,
          problemCells_f20[problemCells_f20.size(0) * n].f1.size(1));
        for (i1 = 0; i1 < loop_ub; i1++) {
          fitNames[fitCounter].f1[i1] = problemCells_f20[n].f1[i1];
        }

        fitCounter++;
      } else {
        otherParams[otherCounter] = problemStruct->domainRatio[n];
        otherLimits[otherCounter] = limits->domainRatio[n];
        otherLimits[otherCounter + otherLimits.size(0)] = limits->domainRatio[n
          + limits->domainRatio.size(0)];
        otherCounter++;
      }
    }

    problemStruct->fitParams.set_size(fitParams.size(0), fitParams.size(1));
    loop_ub = fitParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = fitParams.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        problemStruct->fitParams[i1 + problemStruct->fitParams.size(0) * i] =
          fitParams[i1 + fitParams.size(0) * i];
      }
    }

    b_loop_ub = otherParams.size(0);
    problemStruct->otherParams.set_size(otherParams.size(0), 1);
    for (i = 0; i < 1; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        problemStruct->otherParams[i1] = otherParams[i1];
      }
    }

    problemStruct->fitLimits.set_size(fitLimits.size(0), 2);
    problemStruct->otherLimits.set_size(otherLimits.size(0), 2);
    loop_ub = fitLimits.size(0);
    b_loop_ub = otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        problemStruct->fitLimits[i1 + problemStruct->fitLimits.size(0) * i] =
          fitLimits[i1 + fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        problemStruct->otherLimits[i1 + problemStruct->otherLimits.size(0) * i] =
          otherLimits[i1 + otherLimits.size(0) * i];
      }
    }
  }
}

// End of code generation (packParams.cpp)
