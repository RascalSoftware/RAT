//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: allocateParamsToLayers.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef ALLOCATEPARAMSTOLAYERS_H
#define ALLOCATEPARAMSTOLAYERS_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_14;
  struct cell_wrap_19;
}

// Function Declarations
namespace RAT
{
  void allocateParamsToLayers(const real_T params_data[], const cell_wrap_14
    layersDetails_data[], const int32_T *layersDetails_size, cell_wrap_19
    outLayers_data[], int32_T outLayers_size[2]);
}

#endif

//
// File trailer for allocateParamsToLayers.h
//
// [EOF]
//
