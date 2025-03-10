//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
        double xzlarfg(int n, double &alpha1, ::coder::array<double, 1U> &x);
        double xzlarfg(int n, double &alpha1, double x[3]);
        double xzlarfg(int n, double *alpha1, ::coder::array<double, 2U> &x, int
                       ix0);
      }
    }
  }
}

#endif

// End of code generation (xzlarfg.h)
