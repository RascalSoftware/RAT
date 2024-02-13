//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// adaptPCR.cpp
//
// Code generation for function 'adaptPCR'
//

// Include files
#include "adaptPCR.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void adaptPCR(const struct13_T *DREAMPar, const ::coder::array<real_T, 2U> &CR,
                const real_T delta_tot_data[], const real_T lCRold_data[],
                real_T pCR_data[], int32_T pCR_size[2], real_T lCR_data[],
                int32_T lCR_size[2])
  {
    ::coder::array<real_T, 2U> y;
    ::coder::array<int32_T, 1U> r;
    ::coder::array<boolean_T, 1U> c_CR;
    real_T b_zz;
    int32_T b_CR;
    int32_T i;

    //  Updates the probabilities of the various crossover values
    //  Make CR to be a single vector
    //  Determine lCR
    lCR_size[0] = 1;
    lCR_size[1] = 3;

    //  Adapt pCR using information from averaged normalized jumping distance
    y.set_size(1, 3);
    b_CR = CR.size(0) * CR.size(1);
    for (int32_T zz{0}; zz < 3; zz++) {
      //  Determine how many times a particular CR value is used
      //  This is used to weight delta_tot
      b_zz = (static_cast<real_T>(zz) + 1.0) / 3.0;
      c_CR.set_size(b_CR);
      for (i = 0; i < b_CR; i++) {
        c_CR[i] = (CR[i] == b_zz);
      }

      coder::eml_find(c_CR, r);
      b_zz = lCRold_data[zz] + static_cast<real_T>(r.size(0));
      lCR_data[zz] = b_zz;
      y[zz] = DREAMPar->N * (delta_tot_data[zz] / b_zz);
    }

    //  / sum(delta_tot);
    //  Normalize pCR so that selection probabilities add up to 1
    if (y.size(1) == 0) {
      b_zz = 0.0;
    } else {
      b_zz = coder::nestedIter(y, y.size(1));
    }

    pCR_size[0] = 1;
    pCR_size[1] = 3;
    for (i = 0; i < 3; i++) {
      pCR_data[i] = y[i] / b_zz;
    }
  }
}

// End of code generation (adaptPCR.cpp)
