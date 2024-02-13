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
  struct struct4_T;
  struct e_struct_T;
  struct cell_wrap_9;
  struct h_struct_T;
}

// Function Declarations
namespace RAT
{
  void runDREAM(const d_struct_T *problemStruct, const cell_11 *problemCells,
                const struct1_T *problemLimits, const struct2_T *controls, const
                struct4_T *priors, d_struct_T *outProblemStruct, e_struct_T
                *contrastParams, cell_wrap_9 result[6], h_struct_T *bayesResults);
}

#endif

// End of code generation (runDREAM.h)
