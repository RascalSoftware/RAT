//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// makeSLDProfiles.h
//
// Code generation for function 'makeSLDProfiles'
//

#ifndef MAKESLDPROFILES_H
#define MAKESLDPROFILES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void makeSLDProfiles(double nbair, double nbsub,
                     const coder::array<double, 2U> &sld, double ssub,
                     const double repeats[2],
                     coder::array<double, 2U> &sldProfile);

#endif
// End of code generation (makeSLDProfiles.h)
