//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// adaptPCR.cpp
//
// Code generation for function 'adaptPCR'
//

// Include files
#include "adaptPCR.h"
#include "RATMain_types.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void adaptPCR(const DreamParams &DREAMPar, const ::coder::array<double, 2U>
                &CR, const double delta_tot_data[], const double lCRold_data[],
                double pCR_data[], int pCR_size[2], double lCR_data[], int
                lCR_size[2])
  {
    ::coder::array<double, 2U> y;
    ::coder::array<int, 1U> r;
    ::coder::array<boolean_T, 1U> c_CR;
    double b_zz;
    int b_CR;

    //  Update the probabilities of the various crossover values.
    //
    //  Parameters
    //  ----------
    //  DREAMPar : struct
    //      Algorithmic control settings for DREAM.
    //  CR : vector
    //      The vector of crossover values.
    //  delta_tot : float
    //      The normalised Euclidean distance for each crossover value.
    //  lCRold : array
    //      The old jumping distance weights for each crossover value.
    //
    //  Returns
    //  -------
    //  pCR : array
    //      The crossover selection probability for each parameter.
    //  lCR : array
    //      The jumping distance weights for each crossover value.
    //  Make CR to be a single vector
    //  Determine lCR
    lCR_size[0] = 1;
    lCR_size[1] = 3;

    //  Adapt pCR using information from averaged normalized jumping distance
    y.set_size(1, 3);
    b_CR = CR.size(0) * CR.size(1);
    for (int zz{0}; zz < 3; zz++) {
      //  Determine how many times a particular CR value is used
      //  This is used to weight delta_tot
      b_zz = (static_cast<double>(zz) + 1.0) / 3.0;
      c_CR.set_size(b_CR);
      for (int i{0}; i < b_CR; i++) {
        c_CR[i] = (CR[i] == b_zz);
      }

      coder::eml_find(c_CR, r);
      b_zz = lCRold_data[zz] + static_cast<double>(r.size(0));
      lCR_data[zz] = b_zz;
      y[zz] = DREAMPar.nChains * (delta_tot_data[zz] / b_zz);
    }

    //  / sum(delta_tot);
    //  Normalize pCR so that selection probabilities add up to 1
    b_zz = coder::sum(y);
    pCR_size[0] = 1;
    pCR_size[1] = 3;
    for (int i{0}; i < 3; i++) {
      pCR_data[i] = y[i] / b_zz;
    }
  }
}

// End of code generation (adaptPCR.cpp)
