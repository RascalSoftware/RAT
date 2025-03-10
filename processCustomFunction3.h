//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// processCustomFunction3.h
//
// Code generation for function 'processCustomFunction3'
//
#ifndef PROCESSCUSTOMFUNCTION3_H
#define PROCESSCUSTOMFUNCTION3_H

// Include files
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    namespace customXY
    {
      void processCustomFunction(const ::coder::array<double, 2U>
        &contrastBulkIns, const ::coder::array<double, 2U> &contrastBulkOuts,
        const ::coder::array<double, 2U> &bulkInArray, const ::coder::array<
        double, 2U> &bulkOutArray, const ::coder::array<double, 2U> &cCustFiles,
        double numberOfContrasts, const ::coder::array<cell_wrap_10, 2U>
        &customFiles, const ::coder::array<double, 2U> &params, ::coder::array<
        cell_wrap_33, 2U> &slds, ::coder::array<double, 1U> &subRoughs);
    }
  }
}

#endif

// End of code generation (processCustomFunction3.h)
