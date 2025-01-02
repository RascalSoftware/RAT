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
  struct e_struct_T;
  struct struct4_T;
  struct struct6_T;
  struct f_struct_T;
  struct struct0_T;
}

// Function Declarations
namespace RAT
{
  void b_reflectivityCalculation(const e_struct_T *problemStruct, const
    struct4_T *controls, struct6_T *result);
  void reflectivityCalculation(const e_struct_T *problemStruct, const struct4_T *
    controls, struct6_T *result);
  void reflectivityCalculation(const e_struct_T *problemStruct, const struct4_T *
    controls, f_struct_T *result);
  void reflectivityCalculation(const struct0_T *problemStruct, const struct4_T
    *controls, struct6_T *result);
}

#endif

// End of code generation (reflectivityCalculation.h)
