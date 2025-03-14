//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// processCustomFunction.h
//
// Code generation for function 'processCustomFunction'
//
#ifndef PROCESSCUSTOMFUNCTION_H
#define PROCESSCUSTOMFUNCTION_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace normalTF
  {
    void b_processCustomFunction(const ::coder::array<double, 2U>
      &contrastBulkIns, const ::coder::array<double, 2U> &contrastBulkOuts,
      const ::coder::array<double, 2U> &bulkInValues, const ::coder::array<
      double, 2U> &bulkOutValues, const ::coder::array<double, 2U>
      &contrastCustomFiles, double numberOfContrasts, const ::coder::array<
      cell_wrap_10, 2U> &customFiles, const ::coder::array<double, 2U>
      &paramValues, boolean_T useImaginary, ::coder::array<cell_wrap_9, 1U>
      &outputs, ::coder::array<double, 1U> &subRoughs);
    void processCustomFunction(const ::coder::array<double, 2U> &contrastBulkIns,
      const ::coder::array<double, 2U> &contrastBulkOuts, const ::coder::array<
      double, 2U> &bulkInValues, const ::coder::array<double, 2U> &bulkOutValues,
      const ::coder::array<double, 2U> &contrastCustomFiles, double
      numberOfContrasts, const ::coder::array<cell_wrap_10, 2U> &customFiles,
      const ::coder::array<double, 2U> &paramValues, boolean_T useImaginary, ::
      coder::array<cell_wrap_9, 1U> &outputs, ::coder::array<double, 1U>
      &subRoughs);
  }
}

#endif

// End of code generation (processCustomFunction.h)
