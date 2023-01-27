//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: allocateLayersForContrast.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef ALLOCATELAYERSFORCONTRAST_H
#define ALLOCATELAYERSFORCONTRAST_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_19;
}

// Function Declarations
namespace RAT
{
  void allocateLayersForContrast(const real_T contrastLayers_data[], const
    int32_T contrastLayers_size[2], const cell_wrap_19
    outParameterisedLayers_data[], real_T thisContrastLayers_data[], int32_T
    thisContrastLayers_size[2]);
}

#endif

//
// File trailer for allocateLayersForContrast.h
//
// [EOF]
//
