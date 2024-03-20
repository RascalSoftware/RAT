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
  struct f_struct_T;
  struct struct2_T;
  struct struct1_T;
  struct cell_11;
  struct struct5_T;
  struct i_struct_T;
}

// Function Declarations
namespace RAT
{
  void processBayes(const real_T bayesOutputs_bestPars_data[], const int32_T
                    bayesOutputs_bestPars_size[2], const ::coder::array<real_T,
                    2U> &bayesOutputs_chain, const f_struct_T *problem_f1, const
                    struct2_T *problem_f2, const struct1_T *problem_f3, const
                    cell_11 *problem_f4, f_struct_T *problemStruct, struct5_T
                    *result, i_struct_T *bayesResults);
  void processBayes(const ::coder::array<real_T, 2U> &bayesOutputs_bestPars,
                    const ::coder::array<real_T, 2U> &bayesOutputs_chain, const
                    f_struct_T *problem_f1, const struct2_T *problem_f2, const
                    struct1_T *problem_f3, const cell_11 *problem_f4, f_struct_T
                    *problemStruct, struct5_T *result, i_struct_T *bayesResults);
}

#endif

// End of code generation (processBayes.h)
