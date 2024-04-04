//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivityCalculation1.h
//
// Code generation for function 'reflectivityCalculation1'
//
#ifndef REFLECTIVITYCALCULATION1_H
#define REFLECTIVITYCALCULATION1_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct f_struct_T;
  struct cell_11;
  struct struct2_T;
  struct c_struct_T;
  struct struct6_T;
  struct cell_wrap_8;
  struct cell_wrap_10;
}

// Function Declarations
namespace RAT
{
  namespace nonPolarisedTF
  {
    void b_reflectivityCalculation(const f_struct_T *problemStruct, const
      cell_11 *problemCells, const struct2_T *controls, c_struct_T
      *contrastParams, struct6_T *calculationResults, ::coder::array<cell_wrap_8,
      1U> &reflectivity, ::coder::array<cell_wrap_8, 1U> &simulation, ::coder::
      array<cell_wrap_10, 1U> &shiftedData, ::coder::array<cell_wrap_10, 1U>
      &layerSlds, ::coder::array<cell_wrap_10, 1U> &sldProfiles, ::coder::array<
      cell_wrap_10, 1U> &resampledLayers);
  }
}

#endif

// End of code generation (reflectivityCalculation1.h)
