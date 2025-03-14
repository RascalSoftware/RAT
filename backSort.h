//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// backSort.h
//
// Code generation for function 'backSort'
//
#ifndef BACKSORT_H
#define BACKSORT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  double backSort(double scalefactorIndex, double bulkInIndex, double
                  bulkOutIndex, const ::coder::array<double, 2U>
                  &scalefactorValues, const ::coder::array<double, 2U>
                  &bulkInValues, const ::coder::array<double, 2U> &bulkOutValues,
                  double &scalefactor, double &bulkIn, double &bulkOut);
}

#endif

// End of code generation (backSort.h)
