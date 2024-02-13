//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// chiSquared.cpp
//
// Code generation for function 'chiSquared'
//

// Include files
#include "chiSquared.h"
#include "blockedSummation.h"
#include "find.h"
#include "minOrMax.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  real_T chiSquared(const ::coder::array<real_T, 2U> &thisData, const ::coder::
                    array<real_T, 2U> &thisFit, real_T P)
  {
    ::coder::array<real_T, 1U> b_i;
    ::coder::array<real_T, 1U> b_thisData;
    ::coder::array<real_T, 1U> terms;
    ::coder::array<int32_T, 1U> r;
    ::coder::array<boolean_T, 1U> terms_data;
    real_T b_dv[2];
    real_T N;
    real_T y;
    int32_T i;
    int32_T loop_ub;
    int32_T terms_size;
    int16_T tmp_data[10000];
    boolean_T b_terms_data[10000];

    //  Chi-squared function is used to evaluate the goodness of fit.
    //  It is a measure of the difference between the observed and expected.
    // allChis = zeros(1,numberOfContrasts);
    //      thisData = allData{i};
    //      thisFit = allFits{i};
    b_dv[0] = thisData.size(0);
    b_dv[1] = 1.0;
    N = coder::internal::maximum(b_dv);
    if (N <= P) {
      N = P + 1.0;
    }

    loop_ub = thisData.size(0);
    b_thisData.set_size(thisData.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_thisData[i] = (thisData[i + thisData.size(0)] - thisFit[i + thisFit.size
                       (0)]) / thisData[i + thisData.size(0) * 2];
    }

    coder::power(b_thisData, b_i);
    terms.set_size(b_i.size(0));
    loop_ub = b_i.size(0);
    for (i = 0; i < loop_ub; i++) {
      terms[i] = b_i[i];
    }

    terms_size = terms.size(0);
    loop_ub = terms.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_terms_data[i] = (terms[i] == rtInf);
    }

    terms_data.set(&b_terms_data[0], terms_size);
    coder::eml_find(terms_data, r);
    b_i.set_size(r.size(0));
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_i[i] = r[i];
    }

    if (b_i.size(0) != 0) {
      terms_size = b_i.size(0);
      loop_ub = b_i.size(0);
      for (i = 0; i < loop_ub; i++) {
        tmp_data[i] = static_cast<int16_T>(static_cast<int32_T>(b_i[i]));
      }

      for (i = 0; i < terms_size; i++) {
        terms[tmp_data[i] - 1] = 0.0;
      }
    }

    if (terms.size(0) == 0) {
      y = 0.0;
    } else {
      y = coder::nestedIter(terms, terms.size(0));
    }

    return 1.0 / (N - P) * y;

    // allChis(i) = chi2;
  }
}

// End of code generation (chiSquared.cpp)
