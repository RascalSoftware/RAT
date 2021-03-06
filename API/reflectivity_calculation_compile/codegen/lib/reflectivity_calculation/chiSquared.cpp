//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: chiSquared.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 24-Feb-2021 09:15:13
//

// Include Files
#include "chiSquared.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_rtwutil.h"
#include "rt_nonfinite.h"
#include "standardTF_stanLay_reflectivityCalculation.h"

// Function Definitions

//
// chi_squared(func,data,numparams,errors)
// Arguments    : const coder::array<double, 2U> *thisData
//                const coder::array<double, 2U> *thisFit
//                double P
// Return Type  : double
//
double chiSquared(const coder::array<double, 2U> &thisData, const coder::array<
                  double, 2U> &thisFit, double P)
{
  double chi2;
  double N;
  int idx;
  coder::array<double, 1U> n;
  int k;
  coder::array<double, 1U> terms;
  int nx;
  coder::array<boolean_T, 1U> x;
  coder::array<int, 1U> ii;
  boolean_T exitg1;
  double y;

  // allChis = zeros(1,numberOfContrasts);
  //      thisData = allData{i};
  //      thisFit = allFits{i};
  if (thisData.size(0) < 1) {
    N = 1.0;
  } else {
    N = static_cast<unsigned int>(thisData.size(0));
  }

  if (N <= P) {
    N = P + 1.0;
  }

  idx = thisData.size(0);
  n.set_size(thisData.size(0));
  for (k = 0; k < idx; k++) {
    n[k] = (thisData[k + thisData.size(0)] - thisFit[k + thisFit.size(0)]) /
      thisData[k + thisData.size(0) * 2];
  }

  terms.set_size(n.size(0));
  nx = n.size(0);
  for (k = 0; k < nx; k++) {
    terms[k] = rt_powd_snf(n[k], 2.0);
  }

  x.set_size(terms.size(0));
  idx = terms.size(0);
  for (k = 0; k < idx; k++) {
    x[k] = (terms[k] == rtInf);
  }

  nx = x.size(0);
  idx = 0;
  ii.set_size(x.size(0));
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= nx - 1)) {
    if (x[k]) {
      idx++;
      ii[idx - 1] = k + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        k++;
      }
    } else {
      k++;
    }
  }

  if (x.size(0) == 1) {
    if (idx == 0) {
      ii.set_size(0);
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }

    ii.set_size(idx);
  }

  n.set_size(ii.size(0));
  idx = ii.size(0);
  for (k = 0; k < idx; k++) {
    n[k] = ii[k];
  }

  if (n.size(0) != 0) {
    ii.set_size(n.size(0));
    idx = n.size(0);
    for (k = 0; k < idx; k++) {
      ii[k] = static_cast<int>(n[k]);
    }

    idx = ii.size(0);
    for (k = 0; k < idx; k++) {
      terms[ii[k] - 1] = 0.0;
    }
  }

  idx = terms.size(0);
  if (terms.size(0) == 0) {
    y = 0.0;
  } else {
    y = terms[0];
    for (k = 2; k <= idx; k++) {
      y += terms[k - 1];
    }
  }

  chi2 = 1.0 / (N - P) * y;

  // allChis(i) = chi2;
  return chi2;
}

//
// File trailer for chiSquared.cpp
//
// [EOF]
//
