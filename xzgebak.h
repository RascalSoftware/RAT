//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzgebak.h
//
// Code generation for function 'xzgebak'
//
#ifndef XZGEBAK_H
#define XZGEBAK_H

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
        void xzgebak(int ilo, int ihi, const ::coder::array<double, 1U> &scale, ::
                     coder::array<double, 2U> &V);
      }
    }
  }
}

#endif

// End of code generation (xzgebak.h)
