//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// scaledGaussPrior.cpp
//
// Code generation for function 'scaledGaussPrior'
//

// Include files
#include "scaledGaussPrior.h"
#include "find.h"
#include "rescale.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  static double binary_expand_op(const ::coder::array<double, 1U> &in2, const ::
    coder::array<double, 1U> &in3, const ::coder::array<double, 1U> &in4);
}

// Function Definitions
namespace RAT
{
  static double binary_expand_op(const ::coder::array<double, 1U> &in2, const ::
    coder::array<double, 1U> &in3, const ::coder::array<double, 1U> &in4)
  {
    ::coder::array<double, 1U> b_in2;
    int loop_ub;
    int stride_0_0;
    int stride_1_0;
    int stride_2_0;
    if (in4.size(0) == 1) {
      if (in3.size(0) == 1) {
        loop_ub = in2.size(0);
      } else {
        loop_ub = in3.size(0);
      }
    } else {
      loop_ub = in4.size(0);
    }

    b_in2.set_size(loop_ub);
    stride_0_0 = (in2.size(0) != 1);
    stride_1_0 = (in3.size(0) != 1);
    stride_2_0 = (in4.size(0) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in2[i] = (in2[i * stride_0_0] - in3[i * stride_1_0]) / in4[i *
        stride_2_0];
    }

    loop_ub = b_in2.size(0);
    for (int i{0}; i < loop_ub; i++) {
      double varargin_1;
      varargin_1 = b_in2[i];
      b_in2[i] = varargin_1 * varargin_1;
    }

    return -coder::sum(b_in2);
  }

  double scaledGaussPrior(const ::coder::array<double, 2U> &m, const ::coder::
    array<double, 2U> &extras_problemStruct_fitLimits, const ::coder::array<
    double, 2U> &extras_priors)
  {
    ::coder::array<double, 2U> usedConstr;
    ::coder::array<double, 2U> usedPriors;
    ::coder::array<double, 1U> b_m;
    ::coder::array<double, 1U> b_usedConstr;
    ::coder::array<double, 1U> c_usedConstr;
    ::coder::array<double, 1U> r;
    ::coder::array<double, 1U> r1;
    ::coder::array<double, 1U> r2;
    ::coder::array<int, 1U> usedPriorInd;
    ::coder::array<boolean_T, 1U> b_extras_priors;
    double pVal2;
    int i;
    int loop_ub;

    //  Scale a random value to a Gaussian prior.
    //
    //  Parameters
    //  ----------
    //  m : vector
    //      The point in parameter space to scale.
    //  extras : struct
    //      Additional problem information, including which dimensions of ``m`` need scaling.
    //
    //  Returns
    //  -------
    //  pVal2 : vector
    //      The parameter values rescaled to Gaussian priors.
    //
    //  All are in range, so check for Gaussian priors....
    //  We pick out any priors that are Gaussians and calculate the mvnpdf
    b_extras_priors.set_size(extras_priors.size(0));
    loop_ub = extras_priors.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_extras_priors[i] = (extras_priors[i] == 2.0);
    }

    coder::eml_find(b_extras_priors, usedPriorInd);
    usedPriors.set_size(usedPriorInd.size(0), 5);
    loop_ub = usedPriorInd.size(0);
    for (i = 0; i < 5; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        usedPriors[i1 + usedPriors.size(0) * i] = extras_priors[(usedPriorInd[i1]
          + extras_priors.size(0) * i) - 1];
      }
    }

    usedConstr.set_size(usedPriorInd.size(0), 2);
    loop_ub = usedPriorInd.size(0);
    for (i = 0; i < 2; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        usedConstr[i1 + usedConstr.size(0) * i] =
          extras_problemStruct_fitLimits[(usedPriorInd[i1] +
          extras_problemStruct_fitLimits.size(0) * i) - 1];
      }
    }

    if (usedPriorInd.size(0) != 0) {
      double varargin_1;

      //  There may be no Gaussian priors defined!
      //  Scale (minVal+prior) will give scaled sigma since minVal goes to 0...
      b_m.set_size(usedPriorInd.size(0));
      loop_ub = usedPriorInd.size(0);
      b_usedConstr.set_size(usedPriorInd.size(0));
      c_usedConstr.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_m[i] = m[usedPriorInd[i] - 1];
        b_usedConstr[i] = usedConstr[i];
        c_usedConstr[i] = usedConstr[i + usedConstr.size(0)];
      }

      coder::rescale(b_m, b_usedConstr, c_usedConstr, r);
      b_m.set_size(usedPriorInd.size(0));
      loop_ub = usedPriorInd.size(0);
      b_usedConstr.set_size(usedPriorInd.size(0));
      c_usedConstr.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        b_m[i] = usedPriors[i + usedPriors.size(0)];
        b_usedConstr[i] = usedConstr[i];
        c_usedConstr[i] = usedConstr[i + usedConstr.size(0)];
      }

      coder::rescale(b_m, b_usedConstr, c_usedConstr, r1);
      b_m.set_size(usedPriorInd.size(0));
      loop_ub = usedPriorInd.size(0);
      b_usedConstr.set_size(usedPriorInd.size(0));
      c_usedConstr.set_size(usedPriorInd.size(0));
      for (i = 0; i < loop_ub; i++) {
        varargin_1 = usedConstr[i];
        b_m[i] = usedPriors[i + usedPriors.size(0) * 2] + varargin_1;
        b_usedConstr[i] = varargin_1;
        c_usedConstr[i] = usedConstr[i + usedConstr.size(0)];
      }

      coder::rescale(b_m, b_usedConstr, c_usedConstr, r2);
      if (r.size(0) == 1) {
        i = r1.size(0);
      } else {
        i = r.size(0);
      }

      if ((r.size(0) == r1.size(0)) && (i == r2.size(0))) {
        loop_ub = r.size(0);
        for (i = 0; i < loop_ub; i++) {
          varargin_1 = (r[i] - r1[i]) / r2[i];
          r[i] = varargin_1 * varargin_1;
        }

        pVal2 = -coder::sum(r);
      } else {
        pVal2 = binary_expand_op(r, r1, r2);
      }
    } else {
      pVal2 = 0.0;
    }

    return pVal2;
  }
}

// End of code generation (scaledGaussPrior.cpp)
