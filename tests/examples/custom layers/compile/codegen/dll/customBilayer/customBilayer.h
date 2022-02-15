//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// customBilayer.h
//
// Code generation for function 'customBilayer'
//

#ifndef CUSTOMBILAYER_H
#define CUSTOMBILAYER_H

// Include files
#include "customBilayer_spec.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
CUSTOMBILAYER_DLL_EXPORT extern void
customBilayer(const coder::array<double, 2U> &params, double bulk_in,
              double bulk_out, double contrast, double output[18],
              double *sub_rough);

#endif
// End of code generation (customBilayer.h)
