//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// normalize.cpp
//
// Code generation for function 'normalize'
//

// Include files
#include "normalize.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void normalize(const double a[2], double n[2])
    {
      double fillA[2];
      int partialTrueCount;
      int trueCount;
      signed char tmp_data[2];
      boolean_T unnamed_idx_0;
      boolean_T unnamed_idx_1;
      trueCount = 0;
      fillA[0] = a[0];
      unnamed_idx_1 = std::isnan(a[0]);
      unnamed_idx_0 = unnamed_idx_1;
      if (unnamed_idx_1) {
        trueCount = 1;
      }

      fillA[1] = a[1];
      unnamed_idx_1 = std::isnan(a[1]);
      if (unnamed_idx_1) {
        trueCount++;
      }

      partialTrueCount = 0;
      if (unnamed_idx_0) {
        tmp_data[0] = 1;
        partialTrueCount = 1;
      }

      if (unnamed_idx_1) {
        tmp_data[partialTrueCount] = 2;
      }

      for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount
           ++) {
        fillA[tmp_data[partialTrueCount] - 1] = 0.0;
      }

      double y;
      y = std::abs(fillA[0]) + std::abs(fillA[1]);
      n[0] = a[0] / y;
      n[1] = a[1] / y;
    }

    void normalize(const double a_data[], double n_data[], int n_size[2])
    {
      double fillA_data[3];
      int partialTrueCount;
      int trueCount;
      signed char tmp_data[3];
      boolean_T tmp_data_idx_0;
      boolean_T tmp_data_idx_1;
      boolean_T tmp_data_idx_2;
      trueCount = 0;
      fillA_data[0] = a_data[0];
      tmp_data_idx_2 = std::isnan(a_data[0]);
      tmp_data_idx_0 = tmp_data_idx_2;
      if (tmp_data_idx_2) {
        trueCount = 1;
      }

      fillA_data[1] = a_data[1];
      tmp_data_idx_2 = std::isnan(a_data[1]);
      tmp_data_idx_1 = tmp_data_idx_2;
      if (tmp_data_idx_2) {
        trueCount++;
      }

      fillA_data[2] = a_data[2];
      tmp_data_idx_2 = std::isnan(a_data[2]);
      if (tmp_data_idx_2) {
        trueCount++;
      }

      partialTrueCount = 0;
      if (tmp_data_idx_0) {
        tmp_data[0] = 1;
        partialTrueCount = 1;
      }

      if (tmp_data_idx_1) {
        tmp_data[partialTrueCount] = 2;
        partialTrueCount++;
      }

      if (tmp_data_idx_2) {
        tmp_data[partialTrueCount] = 3;
      }

      for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount
           ++) {
        fillA_data[tmp_data[partialTrueCount] - 1] = 0.0;
      }

      double s;
      s = (std::abs(fillA_data[0]) + std::abs(fillA_data[1])) + std::abs
        (fillA_data[2]);
      n_size[0] = 1;
      n_size[1] = 3;
      n_data[0] = a_data[0] / s;
      n_data[1] = a_data[1] / s;
      n_data[2] = a_data[2] / s;
    }
  }
}

// End of code generation (normalize.cpp)
