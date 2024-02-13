//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// refPrctileConfInts.h
//
// Code generation for function 'refPrctileConfInts'
//
#ifndef REFPRCTILECONFINTS_H
#define REFPRCTILECONFINTS_H

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
  struct struct2_T;
  struct g_struct_T;
}

// Function Declarations
namespace RAT
{
  void refPrctileConfInts(const ::coder::array<real_T, 2U> &bayesOutputs_chain,
    d_struct_T *problemStruct, const cell_11 *problemCells, const struct2_T
    *controlsStruct, g_struct_T *allPredInts);
}

#endif

// End of code generation (refPrctileConfInts.h)
