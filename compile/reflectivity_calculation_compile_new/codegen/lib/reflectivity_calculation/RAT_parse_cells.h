//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// RAT_parse_cells.h
//
// Code generation for function 'RAT_parse_cells'
//

#ifndef RAT_PARSE_CELLS_H
#define RAT_PARSE_CELLS_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct cell_wrap_0;

struct cell_wrap_1;

struct cell_wrap_2;

struct cell_wrap_5;

// Function Declarations
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
                     coder::array<cell_wrap_2, 1U> &layersDetails);

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
                     coder::array<cell_wrap_5, 2U> &customFiles);

#endif
// End of code generation (RAT_parse_cells.h)
