//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// getFitNames.cpp
//
// Code generation for function 'getFitNames'
//

// Include files
#include "getFitNames.h"
#include "RATMain_types.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  void getFitNames(const ::coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_params, const ::coder::array<
                   cell_wrap_10, 2U> &problemStruct_names_backgroundParams,
                   const ::coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_scalefactors, const ::coder::array<
                   cell_wrap_10, 2U> &problemStruct_names_qzshifts, const ::
                   coder::array<cell_wrap_10, 2U> &problemStruct_names_bulkIns,
                   const ::coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_bulkOuts, const ::coder::array<
                   cell_wrap_10, 2U> &problemStruct_names_resolutionParams,
                   const ::coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_domainRatios, const ::coder::array<
                   real_T, 2U> &problemStruct_checks_params, const ::coder::
                   array<real_T, 2U> &problemStruct_checks_backgroundParams,
                   const ::coder::array<real_T, 2U>
                   &problemStruct_checks_scalefactors, const ::coder::array<
                   real_T, 2U> &problemStruct_checks_qzshifts, const ::coder::
                   array<real_T, 2U> &problemStruct_checks_bulkIns, const ::
                   coder::array<real_T, 2U> &problemStruct_checks_bulkOuts,
                   const ::coder::array<real_T, 2U>
                   &problemStruct_checks_resolutionParams, const ::coder::array<
                   real_T, 2U> &problemStruct_checks_domainRatios, ::coder::
                   array<cell_wrap_10, 1U> &fitNames)
  {
    static int32_T fitIndices_data[10000];
    real_T fitCounter;
    int32_T fitIndices_size[2];
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T n;

    //  Note that this order of parameters fields is hard-coded by this
    //  routine, packParams, and packParamsPriors
    i = static_cast<int32_T>(((((((coder::sum(problemStruct_checks_params) +
      coder::sum(problemStruct_checks_backgroundParams)) + coder::sum
      (problemStruct_checks_scalefactors)) + coder::sum
      (problemStruct_checks_qzshifts)) + coder::sum(problemStruct_checks_bulkIns))
      + coder::sum(problemStruct_checks_bulkOuts)) + coder::sum
      (problemStruct_checks_resolutionParams)) + coder::sum
      (problemStruct_checks_domainRatios));
    fitNames.set_size(static_cast<int32_T>(((((((coder::sum
      (problemStruct_checks_params) + coder::sum
      (problemStruct_checks_backgroundParams)) + coder::sum
      (problemStruct_checks_scalefactors)) + coder::sum
      (problemStruct_checks_qzshifts)) + coder::sum(problemStruct_checks_bulkIns))
      + coder::sum(problemStruct_checks_bulkOuts)) + coder::sum
      (problemStruct_checks_resolutionParams)) + coder::sum
      (problemStruct_checks_domainRatios)));
    for (int32_T b_i{0}; b_i < i; b_i++) {
      fitNames[b_i].f1.set_size(1, 0);
    }

    coder::d_eml_find(problemStruct_checks_params, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[n].f1.set_size(1,
        problemStruct_names_params[problemStruct_names_params.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_params[fitIndices_data[n] - 1].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[n].f1[i1] = problemStruct_names_params[fitIndices_data[n] - 1].
          f1[i1];
      }
    }

    coder::d_eml_find(problemStruct_checks_backgroundParams, fitIndices_data,
                      fitIndices_size);
    i1 = fitIndices_size[1];
    for (n = 0; n < i1; n++) {
      fitNames[i + n].f1.set_size(1,
        problemStruct_names_backgroundParams[problemStruct_names_backgroundParams.size
        (0) * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_backgroundParams[fitIndices_data[n] - 1].
        f1.size(1);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        fitNames[i + n].f1[i2] =
          problemStruct_names_backgroundParams[fitIndices_data[n] - 1].f1[i2];
      }
    }

    fitCounter = ((static_cast<real_T>(i - 1) + 1.0) + 1.0) +
      (static_cast<real_T>(fitIndices_size[1] - 1) + 1.0);
    coder::d_eml_find(problemStruct_checks_scalefactors, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_scalefactors[problemStruct_names_scalefactors.size(0)
        * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_scalefactors[fitIndices_data[n] - 1].f1.size
        (1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_scalefactors[fitIndices_data[n] - 1].f1[i1];
      }
    }

    fitCounter += static_cast<real_T>(fitIndices_size[1] - 1) + 1.0;
    coder::d_eml_find(problemStruct_checks_qzshifts, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_qzshifts[problemStruct_names_qzshifts.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_qzshifts[fitIndices_data[n] - 1].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_qzshifts[fitIndices_data[n] - 1].f1[i1];
      }
    }

    fitCounter += static_cast<real_T>(fitIndices_size[1] - 1) + 1.0;
    coder::d_eml_find(problemStruct_checks_bulkIns, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_bulkIns[problemStruct_names_bulkIns.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_bulkIns[fitIndices_data[n] - 1].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_bulkIns[fitIndices_data[n] - 1].f1[i1];
      }
    }

    fitCounter += static_cast<real_T>(fitIndices_size[1] - 1) + 1.0;
    coder::d_eml_find(problemStruct_checks_bulkOuts, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_bulkOuts[problemStruct_names_bulkOuts.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_bulkOuts[fitIndices_data[n] - 1].f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_bulkOuts[fitIndices_data[n] - 1].f1[i1];
      }
    }

    fitCounter += static_cast<real_T>(fitIndices_size[1] - 1) + 1.0;
    coder::d_eml_find(problemStruct_checks_resolutionParams, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_resolutionParams[problemStruct_names_resolutionParams.size
        (0) * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_resolutionParams[fitIndices_data[n] - 1].
        f1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_resolutionParams[fitIndices_data[n] - 1].f1[i1];
      }
    }

    fitCounter += static_cast<real_T>(fitIndices_size[1] - 1) + 1.0;
    coder::d_eml_find(problemStruct_checks_domainRatios, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_domainRatios[problemStruct_names_domainRatios.size(0)
        * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_domainRatios[fitIndices_data[n] - 1].f1.size
        (1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_domainRatios[fitIndices_data[n] - 1].f1[i1];
      }
    }
  }

  void getFitNames(const ::coder::array<cell_wrap_0, 2U>
                   &problemStruct_names_params, const ::coder::array<cell_wrap_0,
                   2U> &problemStruct_names_backgroundParams, const ::coder::
                   array<cell_wrap_0, 2U> &problemStruct_names_scalefactors,
                   const ::coder::array<cell_wrap_0, 2U>
                   &problemStruct_names_qzshifts, const ::coder::array<
                   cell_wrap_0, 2U> &problemStruct_names_bulkIns, const ::coder::
                   array<cell_wrap_0, 2U> &problemStruct_names_bulkOuts, const ::
                   coder::array<cell_wrap_0, 2U>
                   &problemStruct_names_resolutionParams, const ::coder::array<
                   cell_wrap_0, 2U> &problemStruct_names_domainRatios, const ::
                   coder::array<real_T, 2U> &problemStruct_checks_params, const ::
                   coder::array<real_T, 2U>
                   &problemStruct_checks_backgroundParams, const ::coder::array<
                   real_T, 2U> &problemStruct_checks_scalefactors, const ::coder::
                   array<real_T, 2U> &problemStruct_checks_qzshifts, const ::
                   coder::array<real_T, 2U> &problemStruct_checks_bulkIns, const
                   ::coder::array<real_T, 2U> &problemStruct_checks_bulkOuts,
                   const ::coder::array<real_T, 2U>
                   &problemStruct_checks_resolutionParams, const ::coder::array<
                   real_T, 2U> &problemStruct_checks_domainRatios, ::coder::
                   array<cell_wrap_10, 1U> &fitNames)
  {
    real_T fitCounter;
    int32_T fitIndices_data[10000];
    int32_T fitIndices_size[2];
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    int32_T n;

    //  Note that this order of parameters fields is hard-coded by this
    //  routine, packParams, and packParamsPriors
    i = static_cast<int32_T>(((((((coder::sum(problemStruct_checks_params) +
      coder::sum(problemStruct_checks_backgroundParams)) + coder::sum
      (problemStruct_checks_scalefactors)) + coder::sum
      (problemStruct_checks_qzshifts)) + coder::sum(problemStruct_checks_bulkIns))
      + coder::sum(problemStruct_checks_bulkOuts)) + coder::sum
      (problemStruct_checks_resolutionParams)) + coder::sum
      (problemStruct_checks_domainRatios));
    fitNames.set_size(static_cast<int32_T>(((((((coder::sum
      (problemStruct_checks_params) + coder::sum
      (problemStruct_checks_backgroundParams)) + coder::sum
      (problemStruct_checks_scalefactors)) + coder::sum
      (problemStruct_checks_qzshifts)) + coder::sum(problemStruct_checks_bulkIns))
      + coder::sum(problemStruct_checks_bulkOuts)) + coder::sum
      (problemStruct_checks_resolutionParams)) + coder::sum
      (problemStruct_checks_domainRatios)));
    for (int32_T b_i{0}; b_i < i; b_i++) {
      fitNames[b_i].f1.set_size(1, 0);
    }

    coder::d_eml_find(problemStruct_checks_params, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[n].f1.set_size(1,
        problemStruct_names_params[problemStruct_names_params.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size[1]);
      loop_ub = problemStruct_names_params[fitIndices_data[n] - 1].f1.size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[n].f1[i1] = problemStruct_names_params[fitIndices_data[n] - 1].
          f1.data[i1];
      }
    }

    coder::d_eml_find(problemStruct_checks_backgroundParams, fitIndices_data,
                      fitIndices_size);
    i1 = fitIndices_size[1];
    for (n = 0; n < i1; n++) {
      fitNames[i + n].f1.set_size(1,
        problemStruct_names_backgroundParams[problemStruct_names_backgroundParams.size
        (0) * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size[1]);
      loop_ub = problemStruct_names_backgroundParams[fitIndices_data[n] - 1].
        f1.size[1];
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        fitNames[i + n].f1[i2] =
          problemStruct_names_backgroundParams[fitIndices_data[n] - 1]
          .f1.data[i2];
      }
    }

    fitCounter = ((static_cast<real_T>(i - 1) + 1.0) + 1.0) +
      (static_cast<real_T>(fitIndices_size[1] - 1) + 1.0);
    coder::d_eml_find(problemStruct_checks_scalefactors, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_scalefactors[problemStruct_names_scalefactors.size(0)
        * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size[1]);
      loop_ub = problemStruct_names_scalefactors[fitIndices_data[n] - 1]
        .f1.size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_scalefactors[fitIndices_data[n] - 1].f1.data[i1];
      }
    }

    fitCounter += static_cast<real_T>(fitIndices_size[1] - 1) + 1.0;
    coder::d_eml_find(problemStruct_checks_qzshifts, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_qzshifts[problemStruct_names_qzshifts.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size[1]);
      loop_ub = problemStruct_names_qzshifts[fitIndices_data[n] - 1].f1.size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_qzshifts[fitIndices_data[n] - 1].f1.data[i1];
      }
    }

    fitCounter += static_cast<real_T>(fitIndices_size[1] - 1) + 1.0;
    coder::d_eml_find(problemStruct_checks_bulkIns, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_bulkIns[problemStruct_names_bulkIns.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size[1]);
      loop_ub = problemStruct_names_bulkIns[fitIndices_data[n] - 1].f1.size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_bulkIns[fitIndices_data[n] - 1].f1.data[i1];
      }
    }

    fitCounter += static_cast<real_T>(fitIndices_size[1] - 1) + 1.0;
    coder::d_eml_find(problemStruct_checks_bulkOuts, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_bulkOuts[problemStruct_names_bulkOuts.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size[1]);
      loop_ub = problemStruct_names_bulkOuts[fitIndices_data[n] - 1].f1.size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_bulkOuts[fitIndices_data[n] - 1].f1.data[i1];
      }
    }

    fitCounter += static_cast<real_T>(fitIndices_size[1] - 1) + 1.0;
    coder::d_eml_find(problemStruct_checks_resolutionParams, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_resolutionParams[problemStruct_names_resolutionParams.size
        (0) * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size[1]);
      loop_ub = problemStruct_names_resolutionParams[fitIndices_data[n] - 1].
        f1.size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_resolutionParams[fitIndices_data[n] - 1]
          .f1.data[i1];
      }
    }

    fitCounter += static_cast<real_T>(fitIndices_size[1] - 1) + 1.0;
    coder::d_eml_find(problemStruct_checks_domainRatios, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (n = 0; n < i; n++) {
      fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_domainRatios[problemStruct_names_domainRatios.size(0)
        * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size[1]);
      loop_ub = problemStruct_names_domainRatios[fitIndices_data[n] - 1]
        .f1.size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int32_T>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_domainRatios[fitIndices_data[n] - 1].f1.data[i1];
      }
    }
  }
}

// End of code generation (getFitNames.cpp)
