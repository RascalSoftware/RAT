//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// makeSLDProfile.h
//
// Code generation for function 'makeSLDProfile'
//
#ifndef MAKESLDPROFILE_H
#define MAKESLDPROFILE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void makeSLDProfile(double bulkIn, double bulkOut, const ::coder::array<double,
                      2U> &layers, double ssub, double nrepeats, ::coder::array<
                      double, 2U> &SLDProfile);
  void makeSLDProfile(const ::coder::array<double, 2U> &layers, double ssub,
                      double nrepeats, ::coder::array<double, 2U> &SLDProfile);
}

#endif

// End of code generation (makeSLDProfile.h)
