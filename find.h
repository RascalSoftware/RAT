//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// find.h
//
// Code generation for function 'find'
//
#ifndef FIND_H
#define FIND_H

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
    void b_eml_find(const boolean_T x[2], int32_T i_data[], int32_T i_size[2]);
    void c_eml_find(const ::coder::array<boolean_T, 2U> &x, ::coder::array<
                    int32_T, 1U> &i);
    void d_eml_find(const ::coder::array<boolean_T, 2U> &x, ::coder::array<
                    int32_T, 2U> &i);
    void eml_find(const ::coder::array<boolean_T, 1U> &x, ::coder::array<int32_T,
                  1U> &i);
  }
}

#endif

// End of code generation (find.h)
