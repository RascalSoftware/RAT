//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// resampleLayers.h
//
// Code generation for function 'resampleLayers'
//

#ifndef RESAMPLELAYERS_H
#define RESAMPLELAYERS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void resampleLayers(const coder::array<double, 2U> &sldProfile,
                    coder::array<double, 2U> &newSLD);

void resampleLayers(coder::array<double, 2U> &newSLD);

#endif
// End of code generation (resampleLayers.h)
