//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void b_sortIdx(::coder::array<real_T, 1U> &x, ::coder::array<int32_T, 1U>
                     &idx);
      void merge_block(::coder::array<int32_T, 2U> &idx, ::coder::array<real_T,
                       2U> &x, int32_T offset, int32_T n, int32_T preSortLevel, ::
                       coder::array<int32_T, 1U> &iwork, ::coder::array<real_T,
                       1U> &xwork);
      void merge_pow2_block(::coder::array<int32_T, 2U> &idx, ::coder::array<
                            real_T, 2U> &x, int32_T offset);
      void sortIdx(const ::coder::array<real_T, 2U> &x, ::coder::array<int32_T,
                   2U> &idx);
      void sortIdx(const ::coder::array<real_T, 1U> &x, ::coder::array<int32_T,
                   1U> &idx);
      void sortIdx(const ::coder::array<real_T, 2U> &x, const int32_T col_data[],
                   ::coder::array<int32_T, 1U> &idx);
    }
  }
}

#endif

// End of code generation (sortIdx.h)
