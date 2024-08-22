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
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void unpackParams(d_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                    &controls_checks_fitParam, const ::coder::array<real_T, 2U>
                    &controls_checks_fitBackgroundParam, const ::coder::array<
                    real_T, 2U> &controls_checks_fitQzshift, const ::coder::
                    array<real_T, 2U> &controls_checks_fitScalefactor, const ::
                    coder::array<real_T, 2U> &controls_checks_fitBulkIn, const ::
                    coder::array<real_T, 2U> &controls_checks_fitBulkOut, const ::
                    coder::array<real_T, 2U> &controls_checks_fitResolutionParam,
                    const ::coder::array<real_T, 2U>
                    &controls_checks_fitDomainRatio)
  {
    ::coder::array<real_T, 2U> uppars;
    int32_T b_i;
    int32_T i;
    int32_T packed_counter;
    int32_T unnamed_idx_1;
    int32_T uppars_counter;
    uint32_T unpacked_counter;

    // Unpack the params out of the fitParams and otherParams arrays
    // back into problem.params
    // problem = getappdata(0,'problem');
    unpacked_counter = 1U;
    packed_counter = 0;
    uppars_counter = 0;
    unnamed_idx_1 = problemStruct->params.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    i = controls_checks_fitParam.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitParam[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->params.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->params[i] = uppars[i];
    }

    // Also the backgrounds
    unnamed_idx_1 = problemStruct->backgroundParams.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitBackgroundParam.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitBackgroundParam[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->backgroundParams.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->backgroundParams[i] = uppars[i];
    }

    // Scalefactors
    unnamed_idx_1 = problemStruct->scalefactors.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitScalefactor.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitScalefactor[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->scalefactors.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->scalefactors[i] = uppars[i];
    }

    // qzshifts
    unnamed_idx_1 = problemStruct->qzshifts.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitQzshift.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitQzshift[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->qzshifts.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->qzshifts[i] = uppars[i];
    }

    // Bulk In
    unnamed_idx_1 = problemStruct->bulkIn.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitBulkIn.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitBulkIn[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->bulkIn.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->bulkIn[i] = uppars[i];
    }

    // Bulk Out
    unnamed_idx_1 = problemStruct->bulkOut.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitBulkOut.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitBulkOut[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->bulkOut.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->bulkOut[i] = uppars[i];
    }

    // Resolutions
    unnamed_idx_1 = problemStruct->resolutionParams.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitResolutionParam.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitResolutionParam[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->resolutionParams.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->resolutionParams[i] = uppars[i];
    }

    // Domain Ratios
    unnamed_idx_1 = problemStruct->domainRatio.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitDomainRatio.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitDomainRatio[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->domainRatio.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->domainRatio[i] = uppars[i];
    }
  }

  void unpackParams(g_struct_T *problemStruct, const ::coder::array<real_T, 2U>
                    &controls_checks_fitParam, const ::coder::array<real_T, 2U>
                    &controls_checks_fitBackgroundParam, const ::coder::array<
                    real_T, 2U> &controls_checks_fitQzshift, const ::coder::
                    array<real_T, 2U> &controls_checks_fitScalefactor, const ::
                    coder::array<real_T, 2U> &controls_checks_fitBulkIn, const ::
                    coder::array<real_T, 2U> &controls_checks_fitBulkOut, const ::
                    coder::array<real_T, 2U> &controls_checks_fitResolutionParam,
                    const ::coder::array<real_T, 2U>
                    &controls_checks_fitDomainRatio)
  {
    ::coder::array<real_T, 2U> uppars;
    int32_T b_i;
    int32_T i;
    int32_T packed_counter;
    int32_T unnamed_idx_1;
    int32_T uppars_counter;
    uint32_T unpacked_counter;

    // Unpack the params out of the fitParams and otherParams arrays
    // back into problem.params
    // problem = getappdata(0,'problem');
    unpacked_counter = 1U;
    packed_counter = 0;
    uppars_counter = 0;
    unnamed_idx_1 = problemStruct->params.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    i = controls_checks_fitParam.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitParam[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->params.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->params[i] = uppars[i];
    }

    // Also the backgrounds
    unnamed_idx_1 = problemStruct->backgroundParams.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitBackgroundParam.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitBackgroundParam[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->backgroundParams.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->backgroundParams[i] = uppars[i];
    }

    // Scalefactors
    unnamed_idx_1 = problemStruct->scalefactors.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitScalefactor.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitScalefactor[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->scalefactors.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->scalefactors[i] = uppars[i];
    }

    // qzshifts
    unnamed_idx_1 = problemStruct->qzshifts.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitQzshift.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitQzshift[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->qzshifts.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->qzshifts[i] = uppars[i];
    }

    // Bulk In
    unnamed_idx_1 = problemStruct->bulkIn.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitBulkIn.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitBulkIn[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->bulkIn.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->bulkIn[i] = uppars[i];
    }

    // Bulk Out
    unnamed_idx_1 = problemStruct->bulkOut.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitBulkOut.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitBulkOut[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->bulkOut.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->bulkOut[i] = uppars[i];
    }

    // Resolutions
    unnamed_idx_1 = problemStruct->resolutionParams.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitResolutionParam.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitResolutionParam[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->resolutionParams.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->resolutionParams[i] = uppars[i];
    }

    // Domain Ratios
    unnamed_idx_1 = problemStruct->domainRatio.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = controls_checks_fitDomainRatio.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      if (controls_checks_fitDomainRatio[b_i] == 1.0) {
        uppars[uppars_counter] = problemStruct->fitParams[static_cast<int32_T>
          (unpacked_counter) - 1];
        unpacked_counter++;
        uppars_counter++;
      } else {
        uppars[uppars_counter] = problemStruct->otherParams[packed_counter];
        packed_counter++;
        uppars_counter++;
      }
    }

    problemStruct->domainRatio.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->domainRatio[i] = uppars[i];
    }
  }
}

// End of code generation (unpackParams.cpp)
