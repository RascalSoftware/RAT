//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// callReflectivity.h
//
// Code generation for function 'callReflectivity'
//

#ifndef CALLREFLECTIVITY_H
#define CALLREFLECTIVITY_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void b_callReflectivity(double nbairs, double nbsubs, const double simLimits[2],
                        const double repeatLayers[2],
                        const coder::array<double, 2U> &this_data,
                        const coder::array<double, 2U> &layers, double ssubs,
                        double res, coder::array<double, 2U> &reflectivity,
                        coder::array<double, 2U> &Simulation);

void callReflectivity(double nbairs, double nbsubs, const double simLimits[2],
                      const double repeatLayers[2],
                      const coder::array<double, 2U> &this_data,
                      const coder::array<double, 2U> &layers, double ssubs,
                      double res, coder::array<double, 2U> &reflectivity,
                      coder::array<double, 2U> &Simulation);

#endif
// End of code generation (callReflectivity.h)
