//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: chiSquared.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "chiSquared.h"
#include "find.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "unsafeSxfun.h"
#include "coder_array.h"

// Function Definitions
//
// Chi-squared function is used to evaluate the goodness of fit.
//  It is a measure of the difference between the observed and expected.
//
// Arguments    : const real_T thisData_data[]
//                const int32_T thisData_size[2]
//                const ::coder::array<real_T, 2U> &thisFit
//                real_T P
// Return Type  : real_T
//
namespace RAT
{
  real_T chiSquared(const real_T thisData_data[], const int32_T thisData_size[2],
                    const ::coder::array<real_T, 2U> &thisFit, real_T P)
  {
    ::coder::array<real_T, 1U> terms;
    ::coder::array<int32_T, 1U> n;
    ::coder::array<boolean_T, 1U> b_terms;
    real_T thisData[2];
    real_T N;
    int32_T i;
    int32_T loop_ub;

    // allChis = zeros(1,numberOfContrasts);
    //      thisData = allData{i};
    //      thisFit = allFits{i};
    thisData[0] = thisData_size[0];
    thisData[1] = 1.0;
    N = coder::internal::b_maximum(thisData);
    if (N <= P) {
      N = P + 1.0;
    }

    if (thisData_size[0] == 1) {
      i = thisFit.size(0);
    } else {
      i = thisData_size[0];
    }

    if ((thisData_size[0] == thisFit.size(0)) && (i == thisData_size[0])) {
      terms.set_size(thisData_size[0]);
      loop_ub = thisData_size[0];
      for (i = 0; i < loop_ub; i++) {
        real_T varargin_1;
        varargin_1 = (thisData_data[i + thisData_size[0]] - thisFit[i +
                      thisFit.size(0)]) / thisData_data[i + thisData_size[0] * 2];
        terms[i] = varargin_1 * varargin_1;
      }
    } else {
      binary_expand_op(terms, thisData_data, thisData_size, thisFit);
    }

    b_terms.set_size(terms.size(0));
    loop_ub = terms.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_terms[i] = (terms[i] == rtInf);
    }

    coder::eml_find(b_terms, n);
    if (n.size(0) != 0) {
      loop_ub = n.size(0);
      for (i = 0; i < loop_ub; i++) {
        terms[n[i] - 1] = 0.0;
      }
    }

    return 1.0 / (N - P) * coder::sum(terms);

    // allChis(i) = chi2;
  }
}

//
// File trailer for chiSquared.cpp
//
// [EOF]
//
