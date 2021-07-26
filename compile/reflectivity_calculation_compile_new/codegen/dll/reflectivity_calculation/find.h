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
namespace coder {
void b_eml_find(const boolean_T x[3], int i_data[], int *i_size);

void eml_find(const ::coder::array<boolean_T, 1U> &x,
              ::coder::array<int, 1U> &i);

} // namespace coder

#endif
// End of code generation (find.h)
