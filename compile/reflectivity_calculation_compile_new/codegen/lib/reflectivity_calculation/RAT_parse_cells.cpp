//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// RAT_parse_cells.cpp
//
// Code generation for function 'RAT_parse_cells'
//

// Include files
#include "RAT_parse_cells.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
void RAT_parse_cells(const coder::array<cell_wrap_0, 2U> &problemDef_cells_f1,
                     const coder::array<cell_wrap_1, 2U> &problemDef_cells_f2,
                     const coder::array<cell_wrap_0, 2U> &problemDef_cells_f3,
                     const coder::array<cell_wrap_0, 2U> &problemDef_cells_f4,
                     const coder::array<cell_wrap_2, 2U> &problemDef_cells_f5,
                     const coder::array<cell_wrap_2, 1U> &problemDef_cells_f6,
                     coder::array<cell_wrap_0, 2U> &repeatLayers,
                     coder::array<cell_wrap_1, 2U> &allData,
                     coder::array<cell_wrap_0, 2U> &dataLimits,
                     coder::array<cell_wrap_0, 2U> &simLimits,
                     coder::array<cell_wrap_2, 2U> &contrastLayers,
                     coder::array<cell_wrap_2, 1U> &layersDetails)
{
  int i;
  int loop_ub;
  //  Splits up the master input list of all arrays into separate arrays
  //  The min input array 'problemDef_cells' is a master array where
  //  all the cell arrays are grouped together. There are
  //  repeatLayers      - controls repeating of the layers stack
  //  allData           - Array of all the data arrays
  //  dataLimits        - Min max limits in q for the data arrays
  //  simLimits         - Limits in Q for the reflkectivity simulations
  //  Layers details    - Master array of all available layers
  //  contrastLayers    - Which specific combination of arrays are needed for
  //                      each contrast.
  //  Custom files      - Filenames and path for any custom files used
  repeatLayers.set_size(1, problemDef_cells_f1.size(1));
  loop_ub = problemDef_cells_f1.size(1);
  for (i = 0; i < loop_ub; i++) {
    repeatLayers[i] = problemDef_cells_f1[i];
  }
  allData.set_size(1, problemDef_cells_f2.size(1));
  loop_ub = problemDef_cells_f2.size(1);
  for (i = 0; i < loop_ub; i++) {
    allData[i] = problemDef_cells_f2[i];
  }
  dataLimits.set_size(1, problemDef_cells_f3.size(1));
  loop_ub = problemDef_cells_f3.size(1);
  for (i = 0; i < loop_ub; i++) {
    dataLimits[i] = problemDef_cells_f3[i];
  }
  simLimits.set_size(1, problemDef_cells_f4.size(1));
  loop_ub = problemDef_cells_f4.size(1);
  for (i = 0; i < loop_ub; i++) {
    simLimits[i] = problemDef_cells_f4[i];
  }
  contrastLayers.set_size(1, problemDef_cells_f5.size(1));
  loop_ub = problemDef_cells_f5.size(1);
  for (i = 0; i < loop_ub; i++) {
    contrastLayers[i] = problemDef_cells_f5[i];
  }
  layersDetails.set_size(problemDef_cells_f6.size(0));
  loop_ub = problemDef_cells_f6.size(0);
  for (i = 0; i < loop_ub; i++) {
    layersDetails[i] = problemDef_cells_f6[i];
  }
}

void RAT_parse_cells(const coder::array<cell_wrap_0, 2U> &problemDef_cells_f1,
                     const coder::array<cell_wrap_1, 2U> &problemDef_cells_f2,
                     const coder::array<cell_wrap_0, 2U> &problemDef_cells_f3,
                     const coder::array<cell_wrap_0, 2U> &problemDef_cells_f4,
                     const coder::array<cell_wrap_2, 2U> &problemDef_cells_f5,
                     const coder::array<cell_wrap_2, 1U> &problemDef_cells_f6,
                     const coder::array<cell_wrap_5, 2U> &problemDef_cells_f14,
                     coder::array<cell_wrap_0, 2U> &repeatLayers,
                     coder::array<cell_wrap_1, 2U> &allData,
                     coder::array<cell_wrap_0, 2U> &dataLimits,
                     coder::array<cell_wrap_0, 2U> &simLimits,
                     coder::array<cell_wrap_2, 2U> &contrastLayers,
                     coder::array<cell_wrap_2, 1U> &layersDetails,
                     coder::array<cell_wrap_5, 2U> &customFiles)
{
  int i;
  int loop_ub;
  //  Splits up the master input list of all arrays into separate arrays
  //  The min input array 'problemDef_cells' is a master array where
  //  all the cell arrays are grouped together. There are
  //  repeatLayers      - controls repeating of the layers stack
  //  allData           - Array of all the data arrays
  //  dataLimits        - Min max limits in q for the data arrays
  //  simLimits         - Limits in Q for the reflkectivity simulations
  //  Layers details    - Master array of all available layers
  //  contrastLayers    - Which specific combination of arrays are needed for
  //                      each contrast.
  //  Custom files      - Filenames and path for any custom files used
  repeatLayers.set_size(1, problemDef_cells_f1.size(1));
  loop_ub = problemDef_cells_f1.size(1);
  for (i = 0; i < loop_ub; i++) {
    repeatLayers[i] = problemDef_cells_f1[i];
  }
  allData.set_size(1, problemDef_cells_f2.size(1));
  loop_ub = problemDef_cells_f2.size(1);
  for (i = 0; i < loop_ub; i++) {
    allData[i] = problemDef_cells_f2[i];
  }
  dataLimits.set_size(1, problemDef_cells_f3.size(1));
  loop_ub = problemDef_cells_f3.size(1);
  for (i = 0; i < loop_ub; i++) {
    dataLimits[i] = problemDef_cells_f3[i];
  }
  simLimits.set_size(1, problemDef_cells_f4.size(1));
  loop_ub = problemDef_cells_f4.size(1);
  for (i = 0; i < loop_ub; i++) {
    simLimits[i] = problemDef_cells_f4[i];
  }
  contrastLayers.set_size(1, problemDef_cells_f5.size(1));
  loop_ub = problemDef_cells_f5.size(1);
  for (i = 0; i < loop_ub; i++) {
    contrastLayers[i] = problemDef_cells_f5[i];
  }
  layersDetails.set_size(problemDef_cells_f6.size(0));
  loop_ub = problemDef_cells_f6.size(0);
  for (i = 0; i < loop_ub; i++) {
    layersDetails[i] = problemDef_cells_f6[i];
  }
  customFiles.set_size(1, problemDef_cells_f14.size(1));
  loop_ub = problemDef_cells_f14.size(1);
  for (i = 0; i < loop_ub; i++) {
    customFiles[i] = problemDef_cells_f14[i];
  }
}

// End of code generation (RAT_parse_cells.cpp)
