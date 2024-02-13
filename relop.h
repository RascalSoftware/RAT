//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// relop.h
//
// Code generation for function 'relop'
//
#ifndef RELOP_H
#define RELOP_H

// Include files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      boolean_T b_relop(real_T a, real_T b);
      boolean_T c_relop(real_T a, real_T b);
      boolean_T d_relop(real_T a, real_T b);
      boolean_T relop(real_T a, real_T b);
    }
  }
}

#endif

// End of code generation (relop.h)
