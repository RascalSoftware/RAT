//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xdlanv2.h
//
// Code generation for function 'xdlanv2'
//
#ifndef XDLANV2_H
#define XDLANV2_H

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
      namespace reflapack
      {
        void xdlanv2(double *a, double *b, double *c, double *d, double *rt1r,
                     double *rt1i, double *rt2r, double *rt2i, double *cs,
                     double *sn);
      }
    }
  }
}

#endif

// End of code generation (xdlanv2.h)
