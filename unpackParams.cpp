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
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void unpackParams(e_struct_T *problemStruct)
  {
    ::coder::array<real_T, 2U> uppars;
    int32_T i;
    int32_T j;
    int32_T packed_counter;
    int32_T unnamed_idx_1;
    int32_T uppars_counter;
    uint32_T unpacked_counter;

    //  Unpack the params out of the fitParams and otherParams arrays
    //  back into problem.params
    //  Note that this order of parameters fields is hard-coded by this
    //  routine, packParams, packParamsPriors, and getFitNames
    unpacked_counter = 1U;
    packed_counter = 0;
    unnamed_idx_1 = problemStruct->params.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = problemStruct->checks.params.size(1);
    for (j = 0; j < i; j++) {
      if (problemStruct->checks.params[j] == 1.0) {
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

    unnamed_idx_1 = problemStruct->backgroundParams.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = problemStruct->checks.backgroundParams.size(1);
    for (j = 0; j < i; j++) {
      if (problemStruct->checks.backgroundParams[j] == 1.0) {
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

    unnamed_idx_1 = problemStruct->scalefactors.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = problemStruct->checks.scalefactors.size(1);
    for (j = 0; j < i; j++) {
      if (problemStruct->checks.scalefactors[j] == 1.0) {
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

    unnamed_idx_1 = problemStruct->qzshifts.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = problemStruct->checks.qzshifts.size(1);
    for (j = 0; j < i; j++) {
      if (problemStruct->checks.qzshifts[j] == 1.0) {
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

    unnamed_idx_1 = problemStruct->bulkIns.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = problemStruct->checks.bulkIns.size(1);
    for (j = 0; j < i; j++) {
      if (problemStruct->checks.bulkIns[j] == 1.0) {
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

    problemStruct->bulkIns.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->bulkIns[i] = uppars[i];
    }

    unnamed_idx_1 = problemStruct->bulkOuts.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = problemStruct->checks.bulkOuts.size(1);
    for (j = 0; j < i; j++) {
      if (problemStruct->checks.bulkOuts[j] == 1.0) {
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

    problemStruct->bulkOuts.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->bulkOuts[i] = uppars[i];
    }

    unnamed_idx_1 = problemStruct->resolutionParams.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = problemStruct->checks.resolutionParams.size(1);
    for (j = 0; j < i; j++) {
      if (problemStruct->checks.resolutionParams[j] == 1.0) {
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

    unnamed_idx_1 = problemStruct->domainRatios.size(1);
    uppars.set_size(1, unnamed_idx_1);
    for (i = 0; i < unnamed_idx_1; i++) {
      uppars[i] = 0.0;
    }

    uppars_counter = 0;
    i = problemStruct->checks.domainRatios.size(1);
    for (j = 0; j < i; j++) {
      if (problemStruct->checks.domainRatios[j] == 1.0) {
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

    problemStruct->domainRatios.set_size(1, uppars.size(1));
    unnamed_idx_1 = uppars.size(1);
    for (i = 0; i < unnamed_idx_1; i++) {
      problemStruct->domainRatios[i] = uppars[i];
    }
  }
}

// End of code generation (unpackParams.cpp)
