//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// resampleLayersReIm.h
//
// Code generation for function 'resampleLayersReIm'
//
#ifndef RESAMPLELAYERSREIM_H
#define RESAMPLELAYERSREIM_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void resampleLayersReIm(const ::coder::array<double, 2U> &sldProfile, const ::
    coder::array<double, 2U> &sldProfileIm, double minAngle, double nPoints, ::
    coder::array<double, 2U> &newSLD);
}

#endif

// End of code generation (resampleLayersReIm.h)
