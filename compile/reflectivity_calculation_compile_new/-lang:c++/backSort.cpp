//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: backSort.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "backSort.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Distributes the background and shift values among the different contrasts
//
//      USAGE::
//
//          [backg,qshift,sf,nba,nbs,resol] = backsort(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,shifts,sf,nba,nbs,res)
//
//      INPUTS:
//         * cBacks  :         Which backround value is associated with each contrast
//         * cShifts  :        Which qz_shift value is associated with each contrast
//         * cScales  :        Which scalefactor value is associated with each contrast
//         * cNbas  :          Which NBa value is associated with each contrast
//         * cNbss  :          Which Nbs value is associated with each contrast
//         * cRes  :           Which resolution value is associated with each contrast
//         * backs  :          List of all background values.
//         * shifts  :         List of all qz-shift values
//         * sf :              List of all scalefactor values
//         * nba :             List of all nba values
//         * nbs :             List of all nbs values
//         * res :             List of all resolution values
//
//      OUTPUTS:
//         * backgs : list of actual background values for each contrast
//         * qshifts : list of actual shift values for each contrast
//         * sfs : list of actual shift values for each contrast
//         * nbas : list of actual shift values for each contrast
//         * nbss : list of actual shift values for each contrast
//         * nbss : list of actual shift values for each contrast
//
//
//
// Arguments    : real_T cBacks
//                real_T cShifts
//                real_T cScales
//                real_T cNbas
//                real_T cNbss
//                real_T cRes
//                const real_T backs_data[]
//                const real_T shifts_data[]
//                const real_T sf_data[]
//                const real_T nba_data[]
//                const real_T nbs_data[]
//                const real_T res_data[]
//                real_T *backg
//                real_T *qshift
//                real_T *sf
//                real_T *nba
//                real_T *nbs
//                real_T *resol
// Return Type  : void
//
namespace RAT
{
  void backSort(real_T cBacks, real_T cShifts, real_T cScales, real_T cNbas,
                real_T cNbss, real_T cRes, const real_T backs_data[], const
                real_T shifts_data[], const real_T sf_data[], const real_T
                nba_data[], const real_T nbs_data[], const real_T res_data[],
                real_T *backg, real_T *qshift, real_T *sf, real_T *nba, real_T
                *nbs, real_T *resol)
  {
    // for i = 1:nc
    // thisBack = cBacks(i);
    *backg = backs_data[static_cast<int32_T>(cBacks) - 1];

    // thisShift = cShifts(i);
    *qshift = shifts_data[static_cast<int32_T>(cShifts) - 1];

    // thisScale = cScales(i);
    *sf = sf_data[static_cast<int32_T>(cScales) - 1];

    // thisNbair = cNbas(i);
    *nba = nba_data[static_cast<int32_T>(cNbas) - 1];

    // thisNbsub = cNbss(i);
    *nbs = nbs_data[static_cast<int32_T>(cNbss) - 1];

    // thisResol = cRes(i);
    if (cRes != -1.0) {
      *resol = res_data[static_cast<int32_T>(cRes) - 1];
    } else {
      *resol = -1.0;

      //  Negative value means we have a data resolution..
    }

    // end
  }
}

//
// File trailer for backSort.cpp
//
// [EOF]
//
