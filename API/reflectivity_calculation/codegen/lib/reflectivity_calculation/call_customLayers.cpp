//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: call_customLayers.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "call_customLayers.h"
#include "matlabEngineCaller_customLayers.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const coder::array<double, 2U> *params
//                double contrast
//                const coder::array<char, 2U> *file
//                const coder::array<char, 2U> *callPath
//                double bulkIn
//                double bulkOut
//                coder::array<double, 2U> *output
//                double *sRough
// Return Type  : void
//
void call_customLayers(const coder::array<double, 2U> &params, double contrast,
  const coder::array<char, 2U> &file, const coder::array<char, 2U> &callPath,
  double bulkIn, double bulkOut, coder::array<double, 2U> &output, double
  *sRough)
{
  double layers;
  matlabEngineCaller_customLayers(params, contrast, file, callPath, bulkIn,
    bulkOut, output, &layers);
  *sRough = params[0];
}

//
// File trailer for call_customLayers.cpp
//
// [EOF]
//
