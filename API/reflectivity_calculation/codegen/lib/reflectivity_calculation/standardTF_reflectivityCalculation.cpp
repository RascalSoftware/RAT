//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: standardTF_reflectivityCalculation.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "standardTF_reflectivityCalculation.h"
#include "matlabEngineCaller_customLayers.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"
#include "standardTF_custLay_reflectivityCalculation.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include "standardTF_stanLay_reflectivityCalculation.h"

// Function Definitions

//
// Decide what kind of calculation it is and call the appropriate one
// Arguments    : const struct0_T *problemDef
//                const cell_13 *problemDef_cells
//                const struct2_T *controls
//                struct4_T *problem
//                coder::array<cell_wrap_11, 1U> *reflectivity
//                coder::array<cell_wrap_6, 1U> *Simulation
//                coder::array<cell_wrap_1, 1U> *shifted_data
//                coder::array<cell_wrap_1, 1U> *layerSlds
//                coder::array<cell_wrap_11, 1U> *sldProfiles
//                coder::array<cell_wrap_11, 1U> *allLayers
// Return Type  : void
//
void c_standardTF_reflectivityCalcul(const struct0_T *problemDef, const cell_13 *
  problemDef_cells, const struct2_T *controls, struct4_T *problem, coder::array<
  cell_wrap_11, 1U> &reflectivity, coder::array<cell_wrap_6, 1U> &Simulation,
  coder::array<cell_wrap_1, 1U> &shifted_data, coder::array<cell_wrap_1, 1U>
  &layerSlds, coder::array<cell_wrap_11, 1U> &sldProfiles, coder::array<
  cell_wrap_11, 1U> &allLayers)
{
  int loop_ub;
  int i;
  boolean_T b_bool;
  int exitg1;
  static const char b_cv[6] = { 'l', 'a', 'y', 'e', 'r', 's' };

  coder::array<cell_wrap_14, 1U> r;
  coder::array<cell_wrap_8, 1U> r1;
  coder::array<cell_wrap_9, 1U> r2;
  coder::array<cell_wrap_9, 1U> r3;
  coder::array<cell_wrap_8, 1U> r4;
  coder::array<cell_wrap_15, 1U> r5;
  coder::array<cell_wrap_11, 1U> b_reflectivity;
  int b_i;
  static const char b_cv1[13] = { 'C', 'u', 's', 't', 'o', 'm', ' ', 'L', 'a',
    'y', 'e', 'r', 's' };

  coder::array<cell_wrap_6, 1U> b_Simulation;
  static const char b_cv2[9] = { 'C', 'u', 's', 't', 'o', 'm', ' ', 'X', 'Y' };

  coder::array<cell_wrap_1, 1U> b_shifted_data;
  coder::array<cell_wrap_1, 1U> b_layerSlds;
  coder::array<cell_wrap_11, 1U> b_sldProfiles;
  coder::array<cell_wrap_11, 1U> b_allLayers;

  //  Pre-allocate the output arrays..
  loop_ub = static_cast<int>(problemDef->numberOfContrasts);
  problem->ssubs.set_size(loop_ub);
  problem->backgrounds.set_size(loop_ub);
  problem->qshifts.set_size(loop_ub);
  problem->scalefactors.set_size(loop_ub);
  problem->nbairs.set_size(loop_ub);
  problem->nbsubs.set_size(loop_ub);
  problem->resolutions.set_size(loop_ub);
  problem->calculations.all_chis.set_size(loop_ub);
  problem->calculations.sum_chi = 0.0;
  problem->allSubRough.set_size(loop_ub);
  reflectivity.set_size(loop_ub);
  Simulation.set_size(loop_ub);
  shifted_data.set_size(loop_ub);
  layerSlds.set_size(loop_ub);
  sldProfiles.set_size(loop_ub);
  allLayers.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    problem->ssubs[i] = 0.0;
    problem->backgrounds[i] = 0.0;
    problem->qshifts[i] = 0.0;
    problem->scalefactors[i] = 0.0;
    problem->nbairs[i] = 0.0;
    problem->nbsubs[i] = 0.0;
    problem->resolutions[i] = 0.0;
    problem->calculations.all_chis[i] = 0.0;
    problem->allSubRough[i] = 0.0;
    reflectivity[i].f1.set_size(2, 2);
    reflectivity[i].f1[0] = 1.0;
    reflectivity[i].f1[1] = 1.0;
    reflectivity[i].f1[2] = 1.0;
    reflectivity[i].f1[3] = 1.0;
    Simulation[i].f1.set_size(2, 2);
    Simulation[i].f1[0] = 1.0;
    Simulation[i].f1[1] = 1.0;
    Simulation[i].f1[2] = 1.0;
    Simulation[i].f1[3] = 1.0;
    shifted_data[i].f1.set_size(2, 3);
    layerSlds[i].f1.set_size(2, 3);
    for (b_i = 0; b_i < 6; b_i++) {
      shifted_data[i].f1[b_i] = 1.0;
      layerSlds[i].f1[b_i] = 1.0;
    }

    sldProfiles[i].f1.set_size(2, 2);
    sldProfiles[i].f1[0] = 1.0;
    sldProfiles[i].f1[1] = 1.0;
    sldProfiles[i].f1[2] = 1.0;
    sldProfiles[i].f1[3] = 1.0;
    allLayers[i].f1.set_size(2, 1);
    allLayers[i].f1[0] = 1.0;
    allLayers[i].f1[1] = 1.0;
  }

  b_bool = false;
  if (problemDef->modelType.size(1) == 6) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 6) {
        if (problemDef->modelType[loop_ub] != b_cv[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    loop_ub = 0;
  } else {
    b_bool = false;
    if (problemDef->modelType.size(1) == 13) {
      loop_ub = 0;
      do {
        exitg1 = 0;
        if (loop_ub < 13) {
          if (problemDef->modelType[loop_ub] != b_cv1[loop_ub]) {
            exitg1 = 1;
          } else {
            loop_ub++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (b_bool) {
      loop_ub = 1;
    } else {
      b_bool = false;
      if (problemDef->modelType.size(1) == 9) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 9) {
            if (problemDef->modelType[loop_ub] != b_cv2[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }

      if (b_bool) {
        loop_ub = 2;
      } else {
        loop_ub = -1;
      }
    }
  }

  switch (loop_ub) {
   case 0:
    c_standardTF_stanLay_reflectivi(problemDef, problemDef_cells, controls,
      problem, reflectivity, Simulation, shifted_data, layerSlds, sldProfiles,
      allLayers);
    break;

   case 1:
    {
      int i1;
      c_standardTF_custLay_reflectivi(problemDef, problemDef_cells, controls,
        problem, r, r1, r2, r3, r4, r5);
      b_reflectivity.set_size(r.size(0));
      b_i = r.size(0);
      for (i = 0; i < b_i; i++) {
        b_reflectivity[i].f1.set_size(r[i].f1.size(0), r[i].f1.size(1));
        loop_ub = r[i].f1.size(0) * r[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_reflectivity[i].f1[i1] = r[i].f1[i1];
        }
      }

      b_Simulation.set_size(r1.size(0));
      b_i = r1.size(0);
      for (i = 0; i < b_i; i++) {
        b_Simulation[i].f1.set_size(r1[i].f1.size(0), 2);
        loop_ub = r1[i].f1.size(0) * r1[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_Simulation[i].f1[i1] = r1[i].f1[i1];
        }
      }

      b_shifted_data.set_size(r2.size(0));
      b_i = r2.size(0);
      for (i = 0; i < b_i; i++) {
        b_shifted_data[i].f1.set_size(r2[i].f1.size(0), 3);
        loop_ub = r2[i].f1.size(0) * r2[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_shifted_data[i].f1[i1] = r2[i].f1[i1];
        }
      }

      b_layerSlds.set_size(r3.size(0));
      b_i = r3.size(0);
      for (i = 0; i < b_i; i++) {
        b_layerSlds[i].f1.set_size(r3[i].f1.size(0), 3);
        loop_ub = r3[i].f1.size(0) * r3[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_layerSlds[i].f1[i1] = r3[i].f1[i1];
        }
      }

      b_sldProfiles.set_size(r4.size(0));
      b_i = r4.size(0);
      for (i = 0; i < b_i; i++) {
        b_sldProfiles[i].f1.set_size(r4[i].f1.size(0), 2);
        loop_ub = r4[i].f1.size(0) * r4[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_sldProfiles[i].f1[i1] = r4[i].f1[i1];
        }
      }

      b_allLayers.set_size(r5.size(0));
      b_i = r5.size(0);
      for (i = 0; i < b_i; i++) {
        b_allLayers[i].f1.set_size(r5[i].f1.size(0), r5[i].f1.size(1));
        loop_ub = r5[i].f1.size(0) * r5[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_allLayers[i].f1[i1] = r5[i].f1[i1];
        }
      }

      reflectivity.set_size(b_reflectivity.size(0));
      loop_ub = b_reflectivity.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        reflectivity[b_i] = b_reflectivity[b_i];
      }

      Simulation.set_size(b_Simulation.size(0));
      loop_ub = b_Simulation.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        Simulation[b_i] = b_Simulation[b_i];
      }

      shifted_data.set_size(b_shifted_data.size(0));
      loop_ub = b_shifted_data.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        shifted_data[b_i] = b_shifted_data[b_i];
      }

      layerSlds.set_size(b_layerSlds.size(0));
      loop_ub = b_layerSlds.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        layerSlds[b_i] = b_layerSlds[b_i];
      }

      sldProfiles.set_size(b_sldProfiles.size(0));
      loop_ub = b_sldProfiles.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        sldProfiles[b_i] = b_sldProfiles[b_i];
      }

      allLayers.set_size(b_allLayers.size(0));
      loop_ub = b_allLayers.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        allLayers[b_i] = b_allLayers[b_i];
      }
    }
    break;

   case 2:
    {
      int i1;
      c_standardTF_custXY_reflectivit(problemDef, problemDef_cells, controls,
        problem, r, r1, r2, r3, r4, r5);
      b_reflectivity.set_size(r.size(0));
      b_i = r.size(0);
      for (i = 0; i < b_i; i++) {
        b_reflectivity[i].f1.set_size(r[i].f1.size(0), r[i].f1.size(1));
        loop_ub = r[i].f1.size(0) * r[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_reflectivity[i].f1[i1] = r[i].f1[i1];
        }
      }

      b_Simulation.set_size(r1.size(0));
      b_i = r1.size(0);
      for (i = 0; i < b_i; i++) {
        b_Simulation[i].f1.set_size(r1[i].f1.size(0), 2);
        loop_ub = r1[i].f1.size(0) * r1[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_Simulation[i].f1[i1] = r1[i].f1[i1];
        }
      }

      b_shifted_data.set_size(r2.size(0));
      b_i = r2.size(0);
      for (i = 0; i < b_i; i++) {
        b_shifted_data[i].f1.set_size(r2[i].f1.size(0), 3);
        loop_ub = r2[i].f1.size(0) * r2[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_shifted_data[i].f1[i1] = r2[i].f1[i1];
        }
      }

      b_layerSlds.set_size(r3.size(0));
      b_i = r3.size(0);
      for (i = 0; i < b_i; i++) {
        b_layerSlds[i].f1.set_size(r3[i].f1.size(0), 3);
        loop_ub = r3[i].f1.size(0) * r3[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_layerSlds[i].f1[i1] = r3[i].f1[i1];
        }
      }

      b_sldProfiles.set_size(r4.size(0));
      b_i = r4.size(0);
      for (i = 0; i < b_i; i++) {
        b_sldProfiles[i].f1.set_size(r4[i].f1.size(0), 2);
        loop_ub = r4[i].f1.size(0) * r4[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_sldProfiles[i].f1[i1] = r4[i].f1[i1];
        }
      }

      b_allLayers.set_size(r5.size(0));
      b_i = r5.size(0);
      for (i = 0; i < b_i; i++) {
        b_allLayers[i].f1.set_size(r5[i].f1.size(0), r5[i].f1.size(1));
        loop_ub = r5[i].f1.size(0) * r5[i].f1.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_allLayers[i].f1[i1] = r5[i].f1[i1];
        }
      }

      reflectivity.set_size(b_reflectivity.size(0));
      loop_ub = b_reflectivity.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        reflectivity[b_i] = b_reflectivity[b_i];
      }

      Simulation.set_size(b_Simulation.size(0));
      loop_ub = b_Simulation.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        Simulation[b_i] = b_Simulation[b_i];
      }

      shifted_data.set_size(b_shifted_data.size(0));
      loop_ub = b_shifted_data.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        shifted_data[b_i] = b_shifted_data[b_i];
      }

      layerSlds.set_size(b_layerSlds.size(0));
      loop_ub = b_layerSlds.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        layerSlds[b_i] = b_layerSlds[b_i];
      }

      sldProfiles.set_size(b_sldProfiles.size(0));
      loop_ub = b_sldProfiles.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        sldProfiles[b_i] = b_sldProfiles[b_i];
      }

      allLayers.set_size(b_allLayers.size(0));
      loop_ub = b_allLayers.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        allLayers[b_i] = b_allLayers[b_i];
      }
    }
    break;
  }
}

//
// File trailer for standardTF_reflectivityCalculation.cpp
//
// [EOF]
//
