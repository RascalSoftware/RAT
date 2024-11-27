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
  struct cell_16;
  struct struct1_T;
  struct struct2_T;
  struct struct4_T;
  struct f_struct_T;
  struct struct5_T;
  struct j_struct_T;
}

// Function Declarations
namespace RAT
{
  void runDREAM(const d_struct_T *problemStruct, const cell_16 *problemCells,
                const struct1_T *problemLimits, const struct2_T *controls, const
                struct4_T *priors, f_struct_T *outProblemStruct, struct5_T
                *result, j_struct_T *bayesResults);
}

#endif

// End of code generation (runDREAM.h)
