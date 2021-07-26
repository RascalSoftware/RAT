//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sortrowsLE.h
//
// Code generation for function 'sortrowsLE'
//

#ifndef SORTROWSLE_H
#define SORTROWSLE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
boolean_T sortrowsLE(const ::coder::array<double, 2U> &v, const int col_data[],
                     int irow1, int irow2);

}
} // namespace coder

#endif
// End of code generation (sortrowsLE.h)
