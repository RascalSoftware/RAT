//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzlarf.h
//
// Code generation for function 'xzlarf'
//
#ifndef XZLARF_H
#define XZLARF_H

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
        void b_xzlarf(int m, int n, int iv0, double tau, ::coder::array<double,
                      2U> &C, int ic0, int ldc, ::coder::array<double, 1U> &work);
        void xzlarf(int m, int n, int iv0, double tau, ::coder::array<double, 2U>
                    &C, int ic0, int ldc, ::coder::array<double, 1U> &work);
      }
    }
  }
}

#endif

// End of code generation (xzlarf.h)
