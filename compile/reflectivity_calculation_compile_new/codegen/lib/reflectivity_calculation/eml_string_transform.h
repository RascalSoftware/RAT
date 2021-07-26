//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eml_string_transform.h
//
// Code generation for function 'eml_string_transform'
//

#ifndef EML_STRING_TRANSFORM_H
#define EML_STRING_TRANSFORM_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void eml_string_transform(const ::coder::array<char, 2U> &x,
                          ::coder::array<char, 2U> &y);

char eml_string_transform(char x);

} // namespace coder

#endif
// End of code generation (eml_string_transform.h)
