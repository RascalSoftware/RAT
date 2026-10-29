//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// diff.cpp
//
// Code generation for function 'diff'
//

// Include files
#include "diff.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void diff(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U> &y)
    {
      int dimSize;
      dimSize = x.size(0);
      if (x.size(0) == 0) {
        y.set_size(0, 2);
      } else {
        int iyStart;
        iyStart = x.size(0) - 1;
        if (iyStart > 1) {
          iyStart = 1;
        }

        if (iyStart < 1) {
          y.set_size(0, 2);
        } else {
          y.set_size(x.size(0) - 1, 2);
          if (x.size(0) - 1 != 0) {
            iyStart = 0;
            for (int r{0}; r < 2; r++) {
              double work_data;
              int ixLead_tmp;
              ixLead_tmp = r * dimSize;
              work_data = x[ixLead_tmp];
              for (int m{2}; m <= dimSize; m++) {
                double d;
                double tmp1;
                tmp1 = x[(ixLead_tmp + m) - 1];
                d = tmp1;
                tmp1 -= work_data;
                work_data = d;
                y[(iyStart + m) - 2] = tmp1;
              }

              iyStart = (iyStart + dimSize) - 1;
            }
          }
        }
      }
    }
  }
}

// End of code generation (diff.cpp)
