//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// scaledGaussPrior.cpp
//
// Code generation for function 'scaledGaussPrior'
//

// Include files
#include "scaledGaussPrior.h"
#include "blockedSummation.h"
#include "find.h"
#include "power.h"
#include "rescale.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  real_T scaledGaussPrior(const ::coder::array<real_T, 2U> &m, const ::coder::
    array<real_T, 2U> &extras_problemStruct_fitLimits, const ::coder::array<
    real_T, 2U> &extras_priors)
  {
    ::coder::array<real_T, 2U> usedConstr;
    ::coder::array<real_T, 2U> usedPriors;
    ::coder::array<real_T, 1U> b_usedConstr;
    ::coder::array<real_T, 1U> b_usedPriors;
    ::coder::array<real_T, 1U> c_usedConstr;
    ::coder::array<real_T, 1U> muSc;
    ::coder::array<real_T, 1U> sigSc;
    ::coder::array<real_T, 1U> valsSc;
    ::coder::array<int32_T, 1U> usedPriorInd;
    ::coder::array<boolean_T, 1U> b_extras_priors;
    real_T pVal2;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;

    //  All are in range, so check for Gaussian priors....
    //  We pick out any priors that are Gaussians and calculate the mvnpdf
    //  Find all the Gaussian priors....
    //  usedPriorInd = find(strcmpi(priorList(:,1),'gaussian'));
    loop_ub = extras_priors.size(0);
    b_extras_priors.set_size(extras_priors.size(0));
    for (i = 0; i < loop_ub; i++) {
      b_extras_priors[i] = (extras_priors[i] == 2.0);
    }

    coder::eml_find(b_extras_priors, usedPriorInd);
    usedPriors.set_size(usedPriorInd.size(0), 5);
    loop_ub = usedPriorInd.size(0);
    for (i = 0; i < 5; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        usedPriors[i1 + usedPriors.size(0) * i] = extras_priors[(usedPriorInd[i1]
          + extras_priors.size(0) * i) - 1];
      }
    }

    usedConstr.set_size(usedPriorInd.size(0), 2);
    loop_ub = usedPriorInd.size(0);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        usedConstr[i1 + usedConstr.size(0) * i] =
          extras_problemStruct_fitLimits[(usedPriorInd[i1] +
          extras_problemStruct_fitLimits.size(0) * i) - 1];
      }
    }

    if (usedPriorInd.size(0) != 0) {
      real_T y;

      //  There may be no Gaussian priors defined!
      //  Scale (minVal+prior) will give scaled sigma since minVal goes to 0...
      loop_ub = usedPriorInd.size(0);
      b_usedPriors.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_usedPriors[i] = usedPriors[i + usedPriors.size(0)];
      }

      loop_ub = usedPriorInd.size(0);
      b_usedConstr.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_usedConstr[i] = usedConstr[i];
      }

      loop_ub = usedPriorInd.size(0);
      c_usedConstr.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        c_usedConstr[i] = usedConstr[i + usedConstr.size(0)];
      }

      coder::rescale(b_usedPriors, b_usedConstr, c_usedConstr, muSc);
      loop_ub = usedPriorInd.size(0);
      b_usedPriors.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_usedPriors[i] = usedPriors[i + usedPriors.size(0) * 2] + usedConstr[i];
      }

      loop_ub = usedPriorInd.size(0);
      b_usedConstr.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_usedConstr[i] = usedConstr[i];
      }

      loop_ub = usedPriorInd.size(0);
      c_usedConstr.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        c_usedConstr[i] = usedConstr[i + usedConstr.size(0)];
      }

      coder::rescale(b_usedPriors, b_usedConstr, c_usedConstr, sigSc);
      b_usedPriors.set_size(usedPriorInd.size(0));
      loop_ub = usedPriorInd.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_usedPriors[i] = m[usedPriorInd[i] - 1];
      }

      loop_ub = usedPriorInd.size(0);
      b_usedConstr.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_usedConstr[i] = usedConstr[i];
      }

      loop_ub = usedPriorInd.size(0);
      c_usedConstr.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        c_usedConstr[i] = usedConstr[i + usedConstr.size(0)];
      }

      coder::rescale(b_usedPriors, b_usedConstr, c_usedConstr, valsSc);
      loop_ub = valsSc.size(0);
      for (i = 0; i < loop_ub; i++) {
        valsSc[i] = (valsSc[i] - muSc[i]) / sigSc[i];
      }

      coder::power(valsSc, b_usedPriors);
      if (b_usedPriors.size(0) == 0) {
        y = 0.0;
      } else {
        y = coder::nestedIter(b_usedPriors, b_usedPriors.size(0));
      }

      pVal2 = -y;
    } else {
      pVal2 = 0.0;
    }

    return pVal2;
  }
}

// End of code generation (scaledGaussPrior.cpp)
