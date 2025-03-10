//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// chiSquared.cpp
//
// Code generation for function 'chiSquared'
//

// Include files
#include "chiSquared.h"
#include "find.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "unsafeSxfun.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  double chiSquared(const ::coder::array<double, 2U> &thisData, const ::coder::
                    array<double, 2U> &thisFit, double P)
  {
    ::coder::array<double, 1U> terms;
    ::coder::array<int, 1U> n;
    ::coder::array<boolean_T, 1U> b_terms;
    double b_thisData[2];
    double N;
    int i;
    int loop_ub;

    //  Chi-squared function is used to evaluate the goodness of fit.
    //  It is a measure of the difference between the observed and expected.
    // chiValues = zeros(1,numberOfContrasts);
    //      thisData = data{i};
    //      thisFit = allFits{i};
    b_thisData[0] = thisData.size(0);
    b_thisData[1] = 1.0;
    N = coder::internal::maximum(b_thisData);
    if (N <= P) {
      N = P + 1.0;
    }

    if (thisData.size(0) == 1) {
      i = thisFit.size(0);
    } else {
      i = thisData.size(0);
    }

    if ((thisData.size(0) == thisFit.size(0)) && (i == thisData.size(0))) {
      terms.set_size(thisData.size(0));
      loop_ub = thisData.size(0);
      for (i = 0; i < loop_ub; i++) {
        double varargin_1;
        varargin_1 = (thisData[i + thisData.size(0)] - thisFit[i + thisFit.size
                      (0)]) / thisData[i + thisData.size(0) * 2];
        terms[i] = varargin_1 * varargin_1;
      }
    } else {
      binary_expand_op(terms, thisData, thisFit);
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

    // chiValues(i) = chi2;
  }
}

// End of code generation (chiSquared.cpp)
