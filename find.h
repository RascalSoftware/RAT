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
    void b_eml_find(const ::coder::array<boolean_T, 1U> &x, int i_data[], int
                    *i_size);
    void c_eml_find(const ::coder::array<boolean_T, 1U> &x, ::coder::array<int,
                    1U> &i);
    void d_eml_find(const ::coder::array<double, 2U> &x, int i_data[], int
                    i_size[2]);
    void e_eml_find(const boolean_T x[2], int i_data[], int i_size[2]);
    void eml_find(const ::coder::array<boolean_T, 1U> &x, ::coder::array<int, 1U>
                  &i);
    void f_eml_find(const ::coder::array<boolean_T, 2U> &x, ::coder::array<int,
                    1U> &i);
    void g_eml_find(const ::coder::array<boolean_T, 2U> &x, ::coder::array<int,
                    2U> &i);
  }
}

#endif

// End of code generation (find.h)
