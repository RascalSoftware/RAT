//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// multrnd.h
//
// Code generation for function 'multrnd'
//
#ifndef MULTRND_H
#define MULTRND_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void multrnd(real_T n, const real_T p_data[], const int32_T p_size[2], real_T
               X_data[], int32_T X_size[2]);
}

#endif

// End of code generation (multrnd.h)
