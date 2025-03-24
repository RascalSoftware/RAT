//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// blockedSummation.h
//
// Code generation for function 'blockedSummation'
//
#ifndef BLOCKEDSUMMATION_H
#define BLOCKEDSUMMATION_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    double blockedSummation(const ::coder::array<double, 2U> &x, int vlen);
    void blockedSummation(const ::coder::array<double, 2U> &x, int vlen, ::coder::
                          array<double, 2U> &y);
    void blockedSummation(const ::coder::array<double, 2U> &x, int vlen, ::coder::
                          array<double, 1U> &y);
    creal_T nestedIter(const ::coder::array<creal_T, 2U> &x, int vlen);
    void nestedIter(const ::coder::array<double, 3U> &x, int vlen, ::coder::
                    array<double, 3U> &y);
    void nestedIter(const ::coder::array<double, 2U> &x, int vlen, ::coder::
                    array<double, 2U> &y);
    double nestedIter(const ::coder::array<double, 2U> &x, int vlen);
    double nestedIter(const ::coder::array<double, 1U> &x, int vlen);
  }
}

#endif

// End of code generation (blockedSummation.h)
