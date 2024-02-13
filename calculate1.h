//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// calculate1.h
//
// Code generation for function 'calculate1'
//
#ifndef CALCULATE1_H
#define CALCULATE1_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct d_struct_T;
  struct cell_11;
  struct struct2_T;
  struct e_struct_T;
  struct cell_wrap_20;
  struct cell_wrap_8;
}

// Function Declarations
namespace RAT
{
  namespace nonPolarisedTF
  {
    namespace customLayers
    {
      void calculate(const d_struct_T *problemStruct, const cell_11
                     *problemCells, const struct2_T *controls, e_struct_T
                     *contrastParams, ::coder::array<cell_wrap_20, 1U>
                     &reflectivity, ::coder::array<cell_wrap_20, 1U> &simulation,
                     ::coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::
                     array<cell_wrap_8, 1U> &layerSlds, ::coder::array<
                     cell_wrap_8, 1U> &sldProfiles, ::coder::array<cell_wrap_8,
                     1U> &allLayers);
    }
  }
}

#endif

// End of code generation (calculate1.h)
