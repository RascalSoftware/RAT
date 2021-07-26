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
#include "find.h"
#include "minOrMax.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"

// Function Definitions
double chiSquared(const coder::array<double, 2U> &thisData,
                  const coder::array<double, 2U> &thisFit, double P)
{
  coder::array<double, 1U> b_thisData;
  coder::array<double, 1U> terms;
  coder::array<int, 1U> n;
  coder::array<boolean_T, 1U> b_terms;
  double b_dv[2];
  double N;
  int i;
  int loop_ub;
  // chi_squared(func,data,numparams,errors)
  // allChis = zeros(1,numberOfContrasts);
  //      thisData = allData{i};
  //      thisFit = allFits{i};
  b_dv[0] = thisData.size(0);
  b_dv[1] = 1.0;
  N = coder::internal::b_maximum(b_dv);
  if (N <= P) {
    N = P + 1.0;
  }
  loop_ub = thisData.size(0);
  b_thisData.set_size(thisData.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_thisData[i] =
        (thisData[i + thisData.size(0)] - thisFit[i + thisFit.size(0)]) /
        thisData[i + thisData.size(0) * 2];
  }
  coder::power(b_thisData, terms);
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

// End of code generation (chiSquared.cpp)
