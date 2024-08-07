//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// processBayes.h
//
// Code generation for function 'processBayes'
//
#ifndef PROCESSBAYES_H
#define PROCESSBAYES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct d_struct_T;
  struct cell_11;
  struct struct1_T;
  struct struct2_T;
  struct struct5_T;
  struct h_struct_T;
}

// Function Declarations
namespace RAT
{
  void processBayes(const real_T bayesOutputs_bestParams_data[], const int32_T
                    bayesOutputs_bestParams_size[2], const ::coder::array<real_T,
                    2U> &bayesOutputs_chain, d_struct_T *problemStruct, const
                    cell_11 *problemCells, const struct1_T *problemLimits,
                    struct2_T *controls, struct5_T *result, h_struct_T
                    *bayesResults);
  void processBayes(const ::coder::array<real_T, 2U> &bayesOutputs_bestParams,
                    const ::coder::array<real_T, 2U> &bayesOutputs_chain,
                    d_struct_T *problemStruct, const cell_11 *problemCells,
                    const struct1_T *problemLimits, struct2_T *controls,
                    struct5_T *result, h_struct_T *bayesResults);
}

#endif

// End of code generation (processBayes.h)
