//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// processCustomFunction1.h
//
// Code generation for function 'processCustomFunction1'
//
#ifndef PROCESSCUSTOMFUNCTION1_H
#define PROCESSCUSTOMFUNCTION1_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_10;
  struct cell_wrap_33;
}

// Function Declarations
namespace RAT
{
  namespace normalTF
  {
    namespace customXY
    {
      void processCustomFunction(const ::coder::array<double, 2U>
        &contrastBulkIns, const ::coder::array<double, 2U> &contrastBulkOuts,
        const ::coder::array<double, 2U> &bulkInArray, const ::coder::array<
        double, 2U> &bulkOutArray, const ::coder::array<double, 2U> &cCustFiles,
        double numberOfContrasts, const ::coder::array<cell_wrap_10, 2U>
        &customFiles, const ::coder::array<double, 2U> &params, ::coder::array<
        cell_wrap_33, 1U> &slds, ::coder::array<double, 1U> &subRoughs);
    }
  }
}

#endif

// End of code generation (processCustomFunction1.h)
