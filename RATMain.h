//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// RATMain.h
//
// Code generation for function 'RATMain'
//
#ifndef RATMAIN_H
#define RATMAIN_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  extern void RATMain(struct0_T *problemStruct, const struct3_T *problemLimits,
                      struct4_T *controls, const struct5_T *priors, struct6_T
                      *result, struct9_T *bayesResults);
}

#endif

// End of code generation (RATMain.h)
