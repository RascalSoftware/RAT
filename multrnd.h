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
  void multrnd(double n, const double p_data[], const int p_size[2], double
               X_data[], int X_size[2]);
}

#endif

// End of code generation (multrnd.h)
