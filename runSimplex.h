//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runSimplex.h
//
// Code generation for function 'runSimplex'
//
#ifndef RUNSIMPLEX_H
#define RUNSIMPLEX_H

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
  struct struct5_T;
}

// Function Declarations
namespace RAT
{
  void runSimplex(d_struct_T *problemStruct, const cell_11 *problemCells, const
                  struct1_T *problemLimits, const struct2_T *controls, struct5_T
                  *result);
}

#endif

// End of code generation (runSimplex.h)
