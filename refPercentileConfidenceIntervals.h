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
  struct f_struct_T;
  struct cell_16;
  struct struct1_T;
  struct struct2_T;
  struct struct5_T;
  struct h_struct_T;
}

// Function Declarations
namespace RAT
{
  void refPercentileConfidenceIntervals(const ::coder::array<real_T, 2U>
    &bayesOutputs_chain, f_struct_T *problemStruct, const cell_16 *problemCells,
    const struct1_T *problemLimits, const struct2_T *controlsStruct, const
    struct5_T *results, h_struct_T *allPredInts);
}

#endif

// End of code generation (refPercentileConfidenceIntervals.h)
