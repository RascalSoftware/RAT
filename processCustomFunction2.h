//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// processCustomFunction2.h
//
// Code generation for function 'processCustomFunction2'
//
#ifndef PROCESSCUSTOMFUNCTION2_H
#define PROCESSCUSTOMFUNCTION2_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_1;
  struct cell_wrap_39;
}

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    namespace customLayers
    {
      void processCustomFunction(const ::coder::array<real_T, 2U>
        &contrastBulkIns, const ::coder::array<real_T, 2U> &contrastBulkOuts,
        const ::coder::array<real_T, 2U> &bulkIn, const ::coder::array<real_T,
        2U> &bulkOut, const ::coder::array<real_T, 2U> &cCustFiles, real_T
        numberOfContrasts, const ::coder::array<cell_wrap_1, 2U> &customFiles,
        const ::coder::array<real_T, 2U> &params, boolean_T useImaginary, ::
        coder::array<cell_wrap_39, 2U> &allLayers, ::coder::array<real_T, 1U>
        &allRoughs);
    }
  }
}

#endif

// End of code generation (processCustomFunction2.h)
