//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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

// Function Definitions
namespace RAT
{
  void getFitNames(const ::coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_params, const ::coder::array<
                   cell_wrap_10, 2U> &problemStruct_names_backgroundParams,
                   const ::coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_scalefactors, const ::coder::array<
                   cell_wrap_10, 2U> &problemStruct_names_bulkIns, const ::coder::
                   array<cell_wrap_10, 2U> &problemStruct_names_bulkOuts, const ::
                   coder::array<cell_wrap_10, 2U>
                   &problemStruct_names_resolutionParams, const ::coder::array<
                   cell_wrap_10, 2U> &problemStruct_names_domainRatios, const ::
                   coder::array<double, 2U> &problemStruct_checks_params, const ::
                   coder::array<double, 2U>
                   &problemStruct_checks_backgroundParams, const ::coder::array<
                   double, 2U> &problemStruct_checks_scalefactors, const ::coder::
                   array<double, 2U> &problemStruct_checks_bulkIns, const ::
                   coder::array<double, 2U> &problemStruct_checks_bulkOuts,
                   const ::coder::array<double, 2U>
                   &problemStruct_checks_resolutionParams, const ::coder::array<
                   double, 2U> &problemStruct_checks_domainRatios, ::coder::
                   array<cell_wrap_10, 1U> &fitNames)
  {
    static int fitIndices_data[10000];
    double fitCounter;
    int fitIndices_size[2];
    int i;
    int loop_ub;

    //  Note that this order of parameters fields is hard-coded by this
    //  routine, packParams, packParamsPriors, and unpackParams
    i = static_cast<int>((((((coder::sum(problemStruct_checks_params) + coder::
      sum(problemStruct_checks_backgroundParams)) + coder::sum
      (problemStruct_checks_scalefactors)) + coder::sum
      (problemStruct_checks_bulkIns)) + coder::sum(problemStruct_checks_bulkOuts))
                          + coder::sum(problemStruct_checks_resolutionParams)) +
                         coder::sum(problemStruct_checks_domainRatios));
    fitNames.set_size(static_cast<int>((((((coder::sum
      (problemStruct_checks_params) + coder::sum
      (problemStruct_checks_backgroundParams)) + coder::sum
      (problemStruct_checks_scalefactors)) + coder::sum
      (problemStruct_checks_bulkIns)) + coder::sum(problemStruct_checks_bulkOuts))
      + coder::sum(problemStruct_checks_resolutionParams)) + coder::sum
      (problemStruct_checks_domainRatios)));
    for (int b_i{0}; b_i < i; b_i++) {
      fitNames[b_i].f1.set_size(1, 0);
    }

    coder::d_eml_find(problemStruct_checks_params, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int n{0}; n < i; n++) {
      fitNames[n].f1.set_size(1,
        problemStruct_names_params[problemStruct_names_params.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_params[fitIndices_data[n] - 1].f1.size(1);
      for (int i1{0}; i1 < loop_ub; i1++) {
        fitNames[n].f1[i1] = problemStruct_names_params[fitIndices_data[n] - 1].
          f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 < 0) {
      fitCounter = 1.0;
    } else {
      fitCounter = (static_cast<double>(fitIndices_size[1] - 1) + 1.0) + 1.0;
    }

    coder::d_eml_find(problemStruct_checks_backgroundParams, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int n{0}; n < i; n++) {
      fitNames[(static_cast<int>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_backgroundParams[problemStruct_names_backgroundParams.size
        (0) * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_backgroundParams[fitIndices_data[n] - 1].
        f1.size(1);
      for (int i1{0}; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_backgroundParams[fitIndices_data[n] - 1].f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<double>(fitIndices_size[1] - 1) + 1.0;
    }

    coder::d_eml_find(problemStruct_checks_scalefactors, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int n{0}; n < i; n++) {
      fitNames[(static_cast<int>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_scalefactors[problemStruct_names_scalefactors.size(0)
        * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_scalefactors[fitIndices_data[n] - 1].f1.size
        (1);
      for (int i1{0}; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_scalefactors[fitIndices_data[n] - 1].f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<double>(fitIndices_size[1] - 1) + 1.0;
    }

    coder::d_eml_find(problemStruct_checks_bulkIns, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int n{0}; n < i; n++) {
      fitNames[(static_cast<int>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_bulkIns[problemStruct_names_bulkIns.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_bulkIns[fitIndices_data[n] - 1].f1.size(1);
      for (int i1{0}; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_bulkIns[fitIndices_data[n] - 1].f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<double>(fitIndices_size[1] - 1) + 1.0;
    }

    coder::d_eml_find(problemStruct_checks_bulkOuts, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int n{0}; n < i; n++) {
      fitNames[(static_cast<int>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_bulkOuts[problemStruct_names_bulkOuts.size(0) *
        (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_bulkOuts[fitIndices_data[n] - 1].f1.size(1);
      for (int i1{0}; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_bulkOuts[fitIndices_data[n] - 1].f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<double>(fitIndices_size[1] - 1) + 1.0;
    }

    coder::d_eml_find(problemStruct_checks_resolutionParams, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int n{0}; n < i; n++) {
      fitNames[(static_cast<int>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_resolutionParams[problemStruct_names_resolutionParams.size
        (0) * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_resolutionParams[fitIndices_data[n] - 1].
        f1.size(1);
      for (int i1{0}; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_resolutionParams[fitIndices_data[n] - 1].f1[i1];
      }
    }

    if (fitIndices_size[1] - 1 >= 0) {
      fitCounter += static_cast<double>(fitIndices_size[1] - 1) + 1.0;
    }

    coder::d_eml_find(problemStruct_checks_domainRatios, fitIndices_data,
                      fitIndices_size);
    i = fitIndices_size[1];
    for (int n{0}; n < i; n++) {
      fitNames[(static_cast<int>(fitCounter) + n) - 1].f1.set_size(1,
        problemStruct_names_domainRatios[problemStruct_names_domainRatios.size(0)
        * (fitIndices_data[fitIndices_size[0] * n] - 1)].f1.size(1));
      loop_ub = problemStruct_names_domainRatios[fitIndices_data[n] - 1].f1.size
        (1);
      for (int i1{0}; i1 < loop_ub; i1++) {
        fitNames[(static_cast<int>(fitCounter) + n) - 1].f1[i1] =
          problemStruct_names_domainRatios[fitIndices_data[n] - 1].f1[i1];
      }
    }
  }
}

// End of code generation (getFitNames.cpp)
