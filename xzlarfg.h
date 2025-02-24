//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xzlarfg.h
//
// Code generation for function 'xzlarfg'
//
#ifndef XZLARFG_H
#define XZLARFG_H

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
    namespace internal
    {
      namespace reflapack
      {
        double xzlarfg(int n, double *alpha1, ::coder::array<double, 1U> &x);
        double xzlarfg(int n, double *alpha1, ::coder::array<double, 2U> &x, int
                       ix0);
        double xzlarfg(int n, double *alpha1, double x[3]);
      }
    }
  }
}

#endif

// End of code generation (xzlarfg.h)
