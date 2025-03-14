//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// makeSLDProfileXY.h
//
// Code generation for function 'makeSLDProfileXY'
//
#ifndef MAKESLDPROFILEXY_H
#define MAKESLDPROFILEXY_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void makeSLDProfileXY(double bulkIn, double bulkOut, double ssub, const ::
                        coder::array<double, 2U> &layers, double numberOfLayers,
                        double nrepeats, ::coder::array<double, 2U> &SLDProfile);
  void makeSLDProfileXY(double ssub, const ::coder::array<double, 2U> &layers,
                        double numberOfLayers, double nrepeats, ::coder::array<
                        double, 2U> &SLDProfile);
}

#endif

// End of code generation (makeSLDProfileXY.h)
