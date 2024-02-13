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
  extern void RATMain(struct0_T *problemStruct, const cell_7 *problemCells,
                      const struct1_T *problemLimits, struct2_T *controls, const
                      struct4_T *priors, struct5_T *contrastParams, cell_wrap_9
                      resultCells[6], struct7_T *bayesResults);
}

#endif

// End of code generation (RATMain.h)
