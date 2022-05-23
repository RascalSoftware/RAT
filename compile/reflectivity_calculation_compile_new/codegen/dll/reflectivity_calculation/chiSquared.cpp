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
#include "reflectivity_calculation_rtwutil.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"

// Function Definitions
double chiSquared(const coder::array<double, 2U> &thisData,
                  const coder::array<double, 2U> &thisFit, double P)
{
  coder::array<double, 1U> n;
  coder::array<double, 1U> terms;
  coder::array<int, 1U> r;
  coder::array<boolean_T, 1U> b_terms;
  double N;
  int b_N;
  int k;
  unsigned int varargin_1_idx_0;
  // chi_squared(func,data,numparams,errors)
  // allChis = zeros(1,numberOfContrasts);
  //      thisData = allData{i};
  //      thisFit = allFits{i};
  varargin_1_idx_0 = static_cast<unsigned int>(thisData.size(0));
  if (static_cast<int>(varargin_1_idx_0) < 1) {
    N = 1.0;
  } else {
    N = varargin_1_idx_0;
  }
  if (N <= P) {
    N = P + 1.0;
  }
  b_N = thisData.size(0);
  n.set_size(thisData.size(0));
  for (k = 0; k < b_N; k++) {
    n[k] = (thisData[k + thisData.size(0)] - thisFit[k + thisFit.size(0)]) /
           thisData[k + thisData.size(0) * 2];
  }
  terms.set_size(n.size(0));
  b_N = n.size(0);
  for (k = 0; k < b_N; k++) {
    terms[k] = rt_powd_snf(n[k], 2.0);
  }
  b_terms.set_size(terms.size(0));
  b_N = terms.size(0);
  for (k = 0; k < b_N; k++) {
    b_terms[k] = (terms[k] == rtInf);
  }
  coder::eml_find(b_terms, r);
  n.set_size(r.size(0));
  b_N = r.size(0);
  for (k = 0; k < b_N; k++) {
    n[k] = r[k];
  }
  if (n.size(0) != 0) {
    r.set_size(n.size(0));
    b_N = n.size(0);
    for (k = 0; k < b_N; k++) {
      r[k] = static_cast<int>(n[k]);
    }
    b_N = r.size(0);
    for (k = 0; k < b_N; k++) {
      terms[r[k] - 1] = 0.0;
    }
  }
  return 1.0 / (N - P) * coder::sum(terms);
  // allChis(i) = chi2;
}

// End of code generation (chiSquared.cpp)
