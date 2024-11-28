//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runDREAM.h
//
// Code generation for function 'runDREAM'
//
#ifndef RUNDREAM_H
#define RUNDREAM_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct e_struct_T;
  struct struct2_T;
  struct struct3_T;
  struct cell_wrap_7;
  struct g_struct_T;
  struct struct6_T;
  struct struct10_T;
  struct struct11_T;
  struct struct12_T;
  struct struct13_T;
  struct c_struct_T;
}

// Function Declarations
namespace RAT
{
  void runDREAM(const e_struct_T *problemStruct, const struct2_T *problemLimits,
                const struct3_T *controls, const ::coder::array<cell_wrap_7, 1U>
                &priors_priorNames, const ::coder::array<real_T, 2U>
                &priors_priorValues, g_struct_T *outProblemStruct, struct6_T
                *result, struct10_T *bayesResults_predictionIntervals,
                struct11_T *bayesResults_confidenceIntervals, struct12_T
                *bayesResults_dreamParams, struct13_T *bayesResults_dreamOutput,
                c_struct_T *bayesResults_nestedSamplerOutput, ::coder::array<
                real_T, 2U> &bayesResults_chain);
}

#endif

// End of code generation (runDREAM.h)
