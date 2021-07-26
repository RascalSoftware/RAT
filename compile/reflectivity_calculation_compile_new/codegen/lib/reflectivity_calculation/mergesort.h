//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// mergesort.h
//
// Code generation for function 'mergesort'
//

#ifndef MERGESORT_H
#define MERGESORT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void b_mergesort(::coder::array<int, 1U> &idx,
                 const ::coder::array<double, 2U> &x, const int dir_data[],
                 int n);

}
} // namespace coder

#endif
// End of code generation (mergesort.h)
