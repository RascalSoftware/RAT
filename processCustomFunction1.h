//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// processCustomFunction1.h
//
// Code generation for function 'processCustomFunction1'
//
#ifndef PROCESSCUSTOMFUNCTION1_H
#define PROCESSCUSTOMFUNCTION1_H

// Include files
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
    void b_processCustomFunction(const ::coder::array<double, 1U> &bulkIns,
      const ::coder::array<double, 1U> &bulkOuts, const ::coder::array<double,
      2U> &contrastCustomFiles, double numberOfContrasts, const ::coder::array<
      cell_wrap_10, 2U> &customFiles, const ::coder::array<double, 2U>
      &paramValues, boolean_T useImaginary, ::coder::array<cell_wrap_9, 1U>
      &outputs1, ::coder::array<cell_wrap_9, 1U> &outputs2, ::coder::array<
      double, 1U> &subRoughs);
    void processCustomFunction(const ::coder::array<double, 1U> &bulkIns, const ::
      coder::array<double, 1U> &bulkOuts, const ::coder::array<double, 2U>
      &contrastCustomFiles, double numberOfContrasts, const ::coder::array<
      cell_wrap_10, 2U> &customFiles, const ::coder::array<double, 2U>
      &paramValues, boolean_T useImaginary, ::coder::array<cell_wrap_9, 1U>
      &outputs1, ::coder::array<cell_wrap_9, 1U> &outputs2, ::coder::array<
      double, 1U> &subRoughs);
  }
}

#endif

// End of code generation (processCustomFunction1.h)
