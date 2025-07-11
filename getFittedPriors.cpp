//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
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
  void getFittedPriors(const ::coder::array<cell_wrap_10, 1U> &paramNames, const
                       ::coder::array<cell_wrap_10, 1U> &priorNames, const ::
                       coder::array<double, 2U> &priorValues, const ::coder::
                       array<double, 2U> &fitLimits, ::coder::array<double, 2U>
                       &priorFitList)
  {
    ::coder::array<int, 1U> r1;
    ::coder::array<char, 2U> f1;
    ::coder::array<boolean_T, 1U> b_tmp_data;
    ::coder::array<boolean_T, 1U> d_tmp_data;
    cell_wrap_10 r;
    int i;
    int loop_ub;
    boolean_T c_tmp_data[10000];
    boolean_T tmp_data[10000];

    //  Convert RAT prior information into an array.
    //
    //  Parameters
    //  ----------
    //  paramNames : array
    //      The name of each parameter in the list.
    //  priorNames : array
    //      The name of the prior for each parameter ('uniform', 'gaussian', or 'jeffreys')
    //  priorValues : array
    //      The values for the prior (mu/sigma for Gaussian, unused otherwise)
    //  fitLimits : array
    //      The lower and upper limits for each parameter.
    //
    //  Returns
    //  -------
    //  priorFitList : array
    //      a ``length(paramNames)x5`` array, where each row
    //      is the index of the parameter, a numeric flag for the prior,
    //      the prior values, and the limits for each parameter.
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
      for (int i1{0}; i1 < loop_ub; i1++) {
        priorFitList[i1 + priorFitList.size(0) * i] = 0.0;
      }
    }

    //  In order to keep 'priorFitList' homogenous (otherwise we would need to
    //  use a struct), we change the prior type to a numeric flag. So....
    //  'uniform' = 1
    //  'gaussian' = 2
    //  'jeffreys' = 3
    i = paramNames.size(0);
    for (int b_i{0}; b_i < i; b_i++) {
      int indices_data[10000];
      loop_ub = paramNames[b_i].f1.size(1);
      f1.set_size(1, paramNames[b_i].f1.size(1));
      for (int i1{0}; i1 < loop_ub; i1++) {
        f1[i1] = paramNames[b_i].f1[i1];
      }

      r.f1 = f1;
      loop_ub = coder::internal::db_strcmp(r, priorNames, tmp_data);
      b_tmp_data.set(&tmp_data[0], loop_ub);
      coder::eml_find(b_tmp_data, r1);
      loop_ub = r1.size(0);
      for (int i1{0}; i1 < loop_ub; i1++) {
        indices_data[i1] = r1[i1];
      }

      r.f1 = f1;
      loop_ub = coder::internal::db_strcmp(r, priorNames, c_tmp_data);
      d_tmp_data.set(&c_tmp_data[0], loop_ub);
      coder::eml_find(d_tmp_data, r1);
      if (r1.size(0) != 0) {
        priorFitList[b_i] = priorValues[indices_data[0] - 1];
        priorFitList[b_i + priorFitList.size(0)] = priorValues[(indices_data[0]
          + priorValues.size(0)) - 1];
        priorFitList[b_i + priorFitList.size(0) * 2] = priorValues
          [(indices_data[0] + priorValues.size(0) * 2) - 1];
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
