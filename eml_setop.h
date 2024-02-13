//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eml_setop.h
//
// Code generation for function 'eml_setop'
//
#ifndef EML_SETOP_H
#define EML_SETOP_H

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
    void do_vectors(const ::coder::array<real_T, 2U> &a, real_T b, ::coder::
                    array<real_T, 2U> &c, ::coder::array<int32_T, 1U> &ia,
                    int32_T *ib_size);
  }
}

#endif

// End of code generation (eml_setop.h)
