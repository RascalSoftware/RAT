//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortLE.h
//
// Code generation for function 'sortLE'
//

#ifndef SORTLE_H
#define SORTLE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
boolean_T sortLE(const ::coder::array<double, 2U> &v, const int dir_data[],
                 int idx1, int idx2);

}
} // namespace coder

#endif
// End of code generation (sortLE.h)
