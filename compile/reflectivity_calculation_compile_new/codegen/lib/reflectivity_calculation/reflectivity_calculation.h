//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: reflectivity_calculation.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 15-Apr-2021 10:46:16
//
#ifndef REFLECTIVITY_CALCULATION_H
#define REFLECTIVITY_CALCULATION_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void reflectivity_calculation(const struct0_T *problemDef, const cell_6
  *problemDef_cells, const struct1_T *problemDef_limits, const struct2_T
  *controls, struct4_T *problem, cell_9 *result);

#endif

//
// File trailer for reflectivity_calculation.h
//
// [EOF]
//
