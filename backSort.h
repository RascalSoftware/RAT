//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void backSort(double contrastQzshifts, double contrastScalefactors, double
                contrastBulkIns, double contrastBulkOuts, const ::coder::array<
                double, 2U> &qzshifts, const ::coder::array<double, 2U>
                &scalefactors, const ::coder::array<double, 2U> &bulkIn, const ::
                coder::array<double, 2U> &bulkOut, double *outQzshift, double
                *outScalefactor, double *outBulkIn, double *outBulkOut);
}

#endif

// End of code generation (backSort.h)
