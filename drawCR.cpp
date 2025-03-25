//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// drawCR.cpp
//
// Code generation for function 'drawCR'
//

// Include files
#include "drawCR.h"
#include "RATMain_types.h"
#include "multrnd.h"
#include "randSample.h"
#include "randperm.h"
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void drawCR(const DreamParams &DREAMPar, const double pCR_data[], const int
              pCR_size[2], ::coder::array<double, 2U> &CR)
  {
    ::coder::array<double, 2U> b_r;
    ::coder::array<double, 2U> r;
    ::coder::array<double, 1U> cCR;
    ::coder::array<int, 1U> r1;
    double L_data[3];
    int tmp_size[2];

    //  Generate CR values based on current crossover probabilities.
    //
    //  Parameters
    //  ----------
    //  DREAMPar : struct
    //      The algorithmic control settings for DREAM.
    //  pCR : array
    //      The selection probability of crossover for each parameter.
    //
    //  Returns
    //  -------
    //  CR : array
    //      The crossover values for each parameter.
    //
    if (DREAMPar.adaptPCR) {
      double L2_data[4];
      double L_tmp;
      int DREAMPar_idx_0_tmp;
      int i;
      int i1;
      int loop_ub;

      //  If crossover probabilities are updated
      //  How many candidate points for each crossover value?
      L_tmp = DREAMPar.nChains * DREAMPar.steps;
      multrnd(L_tmp, pCR_data, pCR_size, L_data, tmp_size);
      L_data[1] += L_data[0];
      L_data[2] += L_data[1];
      L2_data[0] = 0.0;
      L2_data[1] = L_data[0];
      L2_data[2] = L_data[1];
      L2_data[3] = L_data[2];

      //  Then select which candidate points are selected with what CR
      coder::randperm(L_tmp, b_r);

      //  Then generate CR values for each chain
      cCR.set_size(1000000);
      for (i = 0; i < 1000000; i++) {
        cCR[i] = 0.0;
      }

      for (int zz{0}; zz < 3; zz++) {
        double d;

        //  Define start and end
        //  Take the appropriate elements of r
        L_tmp = L2_data[zz + 1];
        d = L2_data[zz];
        if (d + 1.0 > L_tmp) {
          i = 0;
          i1 = 0;
        } else {
          i = static_cast<int>(d + 1.0) - 1;
          i1 = static_cast<int>(L_tmp);
        }

        //  Assign these indices DREAMPar.CR(zz)
        loop_ub = i1 - i;
        r1.set_size(loop_ub);
        for (i1 = 0; i1 < loop_ub; i1++) {
          r1[i1] = static_cast<int>(b_r[i + i1]);
        }

        loop_ub = r1.size(0);
        for (i = 0; i < loop_ub; i++) {
          cCR[r1[i] - 1] = (static_cast<double>(zz) + 1.0) / 3.0;
        }
      }

      //  Now reshape CR
      //  CR = reshape(cCR,DREAMPar.nChains,DREAMPar.steps);
      loop_ub = coder::internal::computeDimsData(DREAMPar.nChains);
      DREAMPar_idx_0_tmp = static_cast<int>(DREAMPar.nChains);
      CR.set_size(static_cast<int>(DREAMPar.nChains), loop_ub);
      for (i = 0; i < loop_ub; i++) {
        int DREAMPar_tmp_tmp;
        DREAMPar_tmp_tmp = static_cast<int>(DREAMPar.nChains);
        for (i1 = 0; i1 < DREAMPar_tmp_tmp; i1++) {
          CR[i1 + CR.size(0) * i] = cCR[i1 + DREAMPar_idx_0_tmp * i];
        }
      }
    } else {
      double tmp_data[3];
      int DREAMPar_idx_0_tmp;
      int DREAMPar_tmp_tmp;

      //  If crossover probabilities are not updated
      tmp_size[0] = 1;
      tmp_size[1] = 3;
      tmp_data[0] = 0.33333333333333331;
      tmp_data[1] = 0.66666666666666663;
      tmp_data[2] = 1.0;
      randSample(tmp_data, tmp_size, DREAMPar.steps * DREAMPar.nChains, pCR_data,
                 r);
      DREAMPar_idx_0_tmp = static_cast<int>(DREAMPar.nChains);
      DREAMPar_tmp_tmp = static_cast<int>(DREAMPar.steps);
      CR.set_size(DREAMPar_idx_0_tmp, DREAMPar_tmp_tmp);
      for (int i{0}; i < DREAMPar_tmp_tmp; i++) {
        for (int i1{0}; i1 < DREAMPar_idx_0_tmp; i1++) {
          CR[i1 + CR.size(0) * i] = r[i1 + DREAMPar_idx_0_tmp * i];
        }
      }
    }
  }
}

// End of code generation (drawCR.cpp)
