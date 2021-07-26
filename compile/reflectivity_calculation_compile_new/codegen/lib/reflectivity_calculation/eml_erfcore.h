//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eml_erfcore.h
//
// Code generation for function 'eml_erfcore'
//

#ifndef EML_ERFCORE_H
#define EML_ERFCORE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void eml_erfcore(const ::coder::array<double, 2U> &x,
                 ::coder::array<double, 2U> &y);

double scalar_erf(double x);

} // namespace coder

#endif
// End of code generation (eml_erfcore.h)
