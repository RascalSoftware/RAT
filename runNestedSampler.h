//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runNestedSampler.h
//
// Code generation for function 'runNestedSampler'
//
#ifndef RUNNESTEDSAMPLER_H
#define RUNNESTEDSAMPLER_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct f_struct_T;
  struct cell_11;
  struct struct1_T;
  struct struct2_T;
  struct struct4_T;
  struct struct5_T;
  struct struct8_T;
}

// Function Declarations
namespace RAT
{
  void runNestedSampler(f_struct_T *problemStruct, const cell_11 *problemCells,
                        const struct1_T *problemLimits, const struct2_T
                        *controls, const struct4_T *inPriors, struct5_T *result,
                        struct8_T *bayesResults);
}

#endif

// End of code generation (runNestedSampler.h)
