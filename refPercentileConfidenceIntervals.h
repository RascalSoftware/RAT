//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// refPercentileConfidenceIntervals.h
//
// Code generation for function 'refPercentileConfidenceIntervals'
//
#ifndef REFPERCENTILECONFIDENCEINTERVALS_H
#define REFPERCENTILECONFIDENCEINTERVALS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct g_struct_T;
  struct cell_12;
  struct struct1_T;
  struct struct2_T;
  struct struct5_T;
  struct i_struct_T;
}

// Function Declarations
namespace RAT
{
  void refPercentileConfidenceIntervals(const ::coder::array<real_T, 2U>
    &bayesOutputs_chain, g_struct_T *problemStruct, const cell_12 *problemCells,
    const struct1_T *problemLimits, const struct2_T *controlsStruct, const
    struct5_T *results, i_struct_T *allPredInts);
}

#endif

// End of code generation (refPercentileConfidenceIntervals.h)
