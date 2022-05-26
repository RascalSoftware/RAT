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
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void customBilayer(const coder::array<double, 1U> &params,
                          double bulk_in, const double bulk_out[3],
                          double contrast, double output[3][6],
                          double *sub_rough);

#endif
// End of code generation (customBilayer.h)
