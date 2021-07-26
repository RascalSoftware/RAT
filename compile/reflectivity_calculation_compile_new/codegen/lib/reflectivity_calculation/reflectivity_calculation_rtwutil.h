//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivity_calculation_rtwutil.h
//
// Code generation for function 'reflectivity_calculation_rtwutil'
//

#ifndef REFLECTIVITY_CALCULATION_RTWUTIL_H
#define REFLECTIVITY_CALCULATION_RTWUTIL_H

// Include files
#include "reflectivity_calculation_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void b_cast(const coder::array<double, 2U> &t7_f1,
                   coder::array<double, 2U> &t8_f1);

extern void cast(const coder::array<cell_wrap_10, 1U> &b,
                 coder::array<cell_wrap_7, 1U> &c);

extern void cast(const coder::array<cell_wrap_23, 1U> &b,
                 coder::array<cell_wrap_1, 1U> &c);

extern void cast(const coder::array<double, 2U> &t9_f1,
                 coder::array<double, 2U> &t10_f1);

#endif
// End of code generation (reflectivity_calculation_rtwutil.h)
