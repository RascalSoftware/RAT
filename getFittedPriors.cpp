//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// getFittedPriors.cpp
//
// Code generation for function 'getFittedPriors'
//

// Include files
#include "getFittedPriors.h"
#include "RATMain_types.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void getFittedPriors(const ::coder::array<cell_wrap_1, 1U> &paramNames, const ::
                       coder::array<cell_wrap_1, 1U> &priors_priorNames, const ::
                       coder::array<real_T, 2U> &priors_priorValues, const ::
                       coder::array<real_T, 2U> &fitLimits, ::coder::array<
                       real_T, 2U> &priorFitList)
  {
    ::coder::array<int32_T, 1U> indices;
    ::coder::array<char_T, 2U> f1;
    ::coder::array<boolean_T, 1U> r1;
    cell_wrap_1 r;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;

    //  Get the list of all the priors..
    //  Find the values for fitParams
    // priorFitList = cell(numberOfParams,5);
    //  for i = 1:numberOfParams
    //      priorFitList{i,1} = 0;
    //      priorFitList{i,2} = 0;
    //      priorFitList{i,3} = 0;
    //      priorFitList{i,4} = 0;
    //      priorFitList{i,5} = 0;
    //  end
    priorFitList.set_size(paramNames.size(0), 5);
    loop_ub = paramNames.size(0);
    for (i = 0; i < 5; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        priorFitList[i1 + priorFitList.size(0) * i] = 0.0;
      }
    }

    //  In order to keep 'priorFitList' homogenous (otherwise we would need to
    //  use a struct), we change the prior type to a numeric flag. So....
    //  'uniform' = 1
    //  'gaussian' = 2
    //  'jeffreys' = 3
    i = paramNames.size(0);
    for (int32_T b_i{0}; b_i < i; b_i++) {
      loop_ub = paramNames[b_i].f1.size(1);
      f1.set_size(1, paramNames[b_i].f1.size(1));
      for (i1 = 0; i1 < loop_ub; i1++) {
        f1[i1] = paramNames[b_i].f1[i1];
      }

      r.f1 = f1;
      coder::internal::x_strcmp(&r, priors_priorNames, r1);
      coder::eml_find(r1, indices);
      if (indices.size(0) != 0) {
        priorFitList[b_i] = priors_priorValues[indices[0] - 1];
        priorFitList[b_i + priorFitList.size(0)] = priors_priorValues[(indices[0]
          + priors_priorValues.size(0)) - 1];
        priorFitList[b_i + priorFitList.size(0) * 2] = priors_priorValues
          [(indices[0] + priors_priorValues.size(0) * 2) - 1];
        priorFitList[b_i + priorFitList.size(0) * 3] = fitLimits[b_i];
        priorFitList[b_i + priorFitList.size(0) * 4] = fitLimits[b_i +
          fitLimits.size(0)];
      } else {
        priorFitList[b_i] = 1.0;
      }
    }
  }
}

// End of code generation (getFittedPriors.cpp)
