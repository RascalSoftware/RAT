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
  struct e_struct_T;
  struct struct3_T;
  struct struct4_T;
  struct struct5_T;
  struct g_struct_T;
}

// Function Declarations
namespace RAT
{
  void runDREAM(const e_struct_T *problemStruct, const struct3_T *problemLimits,
                const struct4_T *controls, e_struct_T *outProblemStruct,
                struct5_T *result, g_struct_T *bayesResults);
}

#endif

// End of code generation (runDREAM.h)
