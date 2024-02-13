//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eig.h
//
// Code generation for function 'eig'
//
#ifndef EIG_H
#define EIG_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void eig(const ::coder::array<real_T, 2U> &A, ::coder::array<creal_T, 2U> &V,
             ::coder::array<creal_T, 2U> &D);
  }
}

#endif

// End of code generation (eig.h)
