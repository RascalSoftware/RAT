//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// unpackParams.h
//
// Code generation for function 'unpackParams'
//
#ifndef UNPACKPARAMS_H
#define UNPACKPARAMS_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct e_struct_T;
  struct g_struct_T;
}

// Function Declarations
namespace RAT
{
  void unpackParams(e_struct_T *problemStruct);
  void unpackParams(g_struct_T *problemStruct);
}

#endif

// End of code generation (unpackParams.h)
