//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// ismember.cpp
//
// Code generation for function 'ismember'
//

// Include files
#include "ismember.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace coder
  {
    boolean_T isMember(const ::coder::array<double, 1U> &s)
    {
      int k;
      boolean_T exitg1;
      boolean_T tf;
      tf = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= s.size(0) - 1)) {
        if (s[k] == 3.0) {
          tf = true;
          exitg1 = true;
        } else {
          k++;
        }
      }

      return tf;
    }
  }
}

// End of code generation (ismember.cpp)
