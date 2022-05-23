//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// groupLayers_Mod.h
//
// Code generation for function 'groupLayers_Mod'
//

#ifndef GROUPLAYERS_MOD_H
#define GROUPLAYERS_MOD_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void groupLayers_Mod(const coder::array<double, 2U> &allLayers,
                     double allRoughs, const coder::array<char, 2U> &geometry,
                     double nbair, double nbsubs,
                     coder::array<double, 2U> &outLayers, double *outSsubs);

#endif
// End of code generation (groupLayers_Mod.h)
