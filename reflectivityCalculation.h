//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivityCalculation.h
//
// Code generation for function 'reflectivityCalculation'
//
#ifndef REFLECTIVITYCALCULATION_H
#define REFLECTIVITYCALCULATION_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct d_struct_T;
  struct cell_12;
  struct struct1_T;
  struct struct2_T;
  struct e_struct_T;
  struct g_struct_T;
  struct struct5_T;
}

// Function Declarations
namespace RAT
{
  void reflectivityCalculation(const g_struct_T *problemStruct, const cell_12
    *problemCells, const struct1_T *problemLimits, const struct2_T *controls,
    struct5_T *result);
  void reflectivityCalculation(const d_struct_T *problemStruct, const cell_12
    *problemCells, const struct1_T *problemLimits, const struct2_T *controls,
    e_struct_T *result);
}

#endif

// End of code generation (reflectivityCalculation.h)
