//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// sortIdx.h
//
// Code generation for function 'sortIdx'
//
#ifndef SORTIDX_H
#define SORTIDX_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void b_sortIdx(::coder::array<double, 1U> &x, ::coder::array<int, 1U> &idx);
      void merge_block(int idx_data[], ::coder::array<double, 2U> &x, int offset,
                       int n, int preSortLevel, int iwork_data[], ::coder::array<
                       double, 1U> &xwork);
      void merge_pow2_block(int idx_data[], ::coder::array<double, 2U> &x, int
                            offset);
      void sortIdx(const ::coder::array<double, 2U> &x, ::coder::array<int, 2U>
                   &idx);
      void sortIdx(const ::coder::array<double, 2U> &x, ::coder::array<int, 1U>
                   &idx);
      void sortIdx(const ::coder::array<double, 1U> &x, ::coder::array<int, 1U>
                   &idx);
    }
  }
}

#endif

// End of code generation (sortIdx.h)
