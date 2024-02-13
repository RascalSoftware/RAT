//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// averageReflectivity.cpp
//
// Code generation for function 'averageReflectivity'
//

// Include files
#include "averageReflectivity.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    void averageReflectivity(const ::coder::array<real_T, 2U> &reflect1, const ::
      coder::array<real_T, 2U> &reflect2, const ::coder::array<real_T, 2U>
      &simul1, const ::coder::array<real_T, 2U> &simul2, real_T domainRatio, ::
      coder::array<real_T, 2U> &totReflect, ::coder::array<real_T, 2U> &totSimul)
    {
      int32_T b_loop_ub;
      int32_T i;
      int32_T loop_ub;

      //  Calculates the avereaged reflectivity for domains samples (incoherent
      //  sum)
      loop_ub = reflect1.size(0);
      b_loop_ub = reflect1.size(0);
      totReflect.set_size(reflect1.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        totReflect[i] = reflect1[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        totReflect[i + totReflect.size(0)] = domainRatio * reflect1[i +
          reflect1.size(0)] + (1.0 - domainRatio) * reflect2[i + reflect2.size(0)];
      }

      loop_ub = simul1.size(0);
      b_loop_ub = simul1.size(0);
      totSimul.set_size(simul1.size(0), 2);
      for (i = 0; i < loop_ub; i++) {
        totSimul[i] = simul1[i];
      }

      for (i = 0; i < b_loop_ub; i++) {
        totSimul[i + totSimul.size(0)] = domainRatio * simul1[i + simul1.size(0)]
          + (1.0 - domainRatio) * simul2[i + simul2.size(0)];
      }
    }
  }
}

// End of code generation (averageReflectivity.cpp)
