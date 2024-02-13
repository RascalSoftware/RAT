//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// xztgevc.h
//
// Code generation for function 'xztgevc'
//
#ifndef XZTGEVC_H
#define XZTGEVC_H

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
        void xztgevc(const ::coder::array<creal_T, 2U> &A, ::coder::array<
                     creal_T, 2U> &V);
      }
    }
  }
}

#endif

// End of code generation (xztgevc.h)
