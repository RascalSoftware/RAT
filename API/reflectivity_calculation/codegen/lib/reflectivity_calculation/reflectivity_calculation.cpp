//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: reflectivity_calculation.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//

// Include Files
#include "reflectivity_calculation.h"
#include "allocateParamsToLayers.h"
#include "matlabEngineCaller_customLayers.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_initialize.h"
#include "rt_nonfinite.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include "standardTF_reflectivityCalculation.h"
#include "standardTF_stanlay_paraContrasts.h"

// Function Definitions

//
// Preallocatin of outputs
// Arguments    : const struct0_T *problemDef
//                const cell_5 *problemDef_cells
//                const struct1_T *problemDef_limits
//                const struct2_T *controls
//                struct4_T *problem
//                cell_7 *result
// Return Type  : void
//
void reflectivity_calculation(const struct0_T *problemDef, const cell_5
  *problemDef_cells, const struct1_T *, const struct2_T *controls, struct4_T
  *problem, cell_7 *result)
{
  int i;
  coder::array<cell_wrap_8, 1U> reflectivity;
  coder::array<cell_wrap_8, 1U> Simulation;
  coder::array<cell_wrap_9, 1U> shifted_data;
  coder::array<cell_wrap_9, 1U> layerSlds;
  coder::array<cell_wrap_8, 1U> sldProfiles;
  int b_i;
  boolean_T b_bool;
  int kstr;
  static const char b_cv[10] = { 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T',
    'F' };

  coder::array<cell_wrap_0, 2U> t0_f1;
  coder::array<cell_wrap_6, 1U> cell1;
  int i1;
  coder::array<cell_wrap_1, 2U> t0_f2;
  coder::array<cell_wrap_0, 2U> t0_f3;
  coder::array<cell_wrap_0, 2U> t0_f4;
  coder::array<cell_wrap_11, 2U> t0_f5;
  coder::array<cell_wrap_1, 1U> cell3;
  coder::array<cell_wrap_3, 1U> t0_f6;
  coder::array<cell_wrap_4, 2U> t0_f7;
  coder::array<cell_wrap_4, 2U> t0_f8;
  coder::array<cell_wrap_4, 2U> t0_f9;
  coder::array<cell_wrap_4, 2U> t0_f10;
  coder::array<cell_wrap_4, 2U> t0_f11;
  coder::array<cell_wrap_4, 2U> t0_f12;
  coder::array<signed char, 1U> cell6;
  coder::array<cell_wrap_4, 2U> t0_f13;
  cell_13 expl_temp;
  coder::array<cell_wrap_11, 1U> b_reflectivity;
  coder::array<cell_wrap_1, 1U> b_layerSlds;
  coder::array<cell_wrap_11, 1U> b_sldProfiles;
  coder::array<cell_wrap_11, 1U> allLayers;
  if (!isInitialized_reflectivity_calculation) {
    reflectivity_calculation_initialize();
  }

  problem->ssubs.set_size(1);
  problem->ssubs[0] = 0.0;
  problem->backgrounds.set_size(1);
  problem->backgrounds[0] = 0.0;
  problem->qshifts.set_size(1);
  problem->qshifts[0] = 0.0;
  problem->scalefactors.set_size(1);
  problem->scalefactors[0] = 0.0;
  problem->nbairs.set_size(1);
  problem->nbairs[0] = 0.0;
  problem->nbsubs.set_size(1);
  problem->nbsubs[0] = 0.0;
  problem->resolutions.set_size(1);
  problem->resolutions[0] = 0.0;
  problem->calculations.all_chis.set_size(1);
  problem->calculations.all_chis[0] = 0.0;
  problem->calculations.sum_chi = 0.0;
  problem->allSubRough.set_size(1);
  problem->allSubRough[0] = 0.0;
  i = static_cast<int>(problemDef->numberOfContrasts);
  reflectivity.set_size(i);
  Simulation.set_size(i);
  shifted_data.set_size(i);
  layerSlds.set_size(i);
  sldProfiles.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    reflectivity[b_i].f1.set_size(2, 2);
    reflectivity[b_i].f1[0] = 1.0;
    reflectivity[b_i].f1[1] = 1.0;
    reflectivity[b_i].f1[2] = 1.0;
    reflectivity[b_i].f1[3] = 1.0;
    Simulation[b_i].f1.set_size(2, 2);
    Simulation[b_i].f1[0] = 1.0;
    Simulation[b_i].f1[1] = 1.0;
    Simulation[b_i].f1[2] = 1.0;
    Simulation[b_i].f1[3] = 1.0;
    shifted_data[b_i].f1.set_size(2, 3);
    layerSlds[b_i].f1.set_size(2, 3);
    for (i1 = 0; i1 < 6; i1++) {
      shifted_data[b_i].f1[i1] = 1.0;
      layerSlds[b_i].f1[i1] = 1.0;
    }

    sldProfiles[b_i].f1.set_size(2, 2);
    sldProfiles[b_i].f1[0] = 1.0;
    sldProfiles[b_i].f1[1] = 1.0;
    sldProfiles[b_i].f1[2] = 1.0;
    sldProfiles[b_i].f1[3] = 1.0;
  }

  // Decide which target function we are calling
  b_bool = false;
  if (problemDef->TF.size(1) == 10) {
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (problemDef->TF[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    kstr = -1;
  }

  switch (kstr) {
   case 0:
    {
      int i2;
      t0_f1.set_size(1, problemDef_cells->f1.size(1));
      kstr = problemDef_cells->f1.size(0) * problemDef_cells->f1.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f1[i1] = problemDef_cells->f1[i1];
      }

      t0_f2.set_size(1, problemDef_cells->f2.size(1));
      kstr = problemDef_cells->f2.size(0) * problemDef_cells->f2.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f2[i1] = problemDef_cells->f2[i1];
      }

      t0_f3.set_size(1, problemDef_cells->f3.size(1));
      kstr = problemDef_cells->f3.size(0) * problemDef_cells->f3.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f3[i1] = problemDef_cells->f3[i1];
      }

      t0_f4.set_size(1, problemDef_cells->f4.size(1));
      kstr = problemDef_cells->f4.size(0) * problemDef_cells->f4.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f4[i1] = problemDef_cells->f4[i1];
      }

      t0_f5.set_size(1, problemDef_cells->f5.size(1));
      i1 = problemDef_cells->f5.size(1) - 1;
      for (b_i = 0; b_i <= i1; b_i++) {
        t0_f5[t0_f5.size(0) * b_i].f1.set_size(problemDef_cells->
          f5[problemDef_cells->f5.size(0) * b_i].f1.size(0),
          problemDef_cells->f5[problemDef_cells->f5.size(0) * b_i].f1.size(1));
        kstr = problemDef_cells->f5[b_i].f1.size(0) * problemDef_cells->f5[b_i].
          f1.size(1);
        for (i2 = 0; i2 < kstr; i2++) {
          t0_f5[b_i].f1[i2] = problemDef_cells->f5[b_i].f1[i2];
        }
      }

      t0_f6.set_size(problemDef_cells->f6.size(0));
      kstr = problemDef_cells->f6.size(0);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f6[i1] = problemDef_cells->f6[i1];
      }

      t0_f7.set_size(1, problemDef_cells->f7.size(1));
      kstr = problemDef_cells->f7.size(0) * problemDef_cells->f7.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f7[i1] = problemDef_cells->f7[i1];
      }

      t0_f8.set_size(1, problemDef_cells->f8.size(1));
      kstr = problemDef_cells->f8.size(0) * problemDef_cells->f8.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f8[i1] = problemDef_cells->f8[i1];
      }

      t0_f9.set_size(1, problemDef_cells->f9.size(1));
      kstr = problemDef_cells->f9.size(0) * problemDef_cells->f9.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f9[i1] = problemDef_cells->f9[i1];
      }

      t0_f10.set_size(1, problemDef_cells->f10.size(1));
      kstr = problemDef_cells->f10.size(0) * problemDef_cells->f10.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f10[i1] = problemDef_cells->f10[i1];
      }

      t0_f11.set_size(1, problemDef_cells->f11.size(1));
      kstr = problemDef_cells->f11.size(0) * problemDef_cells->f11.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f11[i1] = problemDef_cells->f11[i1];
      }

      t0_f12.set_size(1, problemDef_cells->f12.size(1));
      kstr = problemDef_cells->f12.size(0) * problemDef_cells->f12.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f12[i1] = problemDef_cells->f12[i1];
      }

      t0_f13.set_size(1, problemDef_cells->f13.size(1));
      kstr = problemDef_cells->f13.size(0) * problemDef_cells->f13.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        t0_f13[i1] = problemDef_cells->f13[i1];
      }

      expl_temp.f13.set_size(1, t0_f13.size(1));
      kstr = t0_f13.size(0) * t0_f13.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f13[i1] = t0_f13[i1];
      }

      expl_temp.f12.set_size(1, t0_f12.size(1));
      kstr = t0_f12.size(0) * t0_f12.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f12[i1] = t0_f12[i1];
      }

      expl_temp.f11.set_size(1, t0_f11.size(1));
      kstr = t0_f11.size(0) * t0_f11.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f11[i1] = t0_f11[i1];
      }

      expl_temp.f10.set_size(1, t0_f10.size(1));
      kstr = t0_f10.size(0) * t0_f10.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f10[i1] = t0_f10[i1];
      }

      expl_temp.f9.set_size(1, t0_f9.size(1));
      kstr = t0_f9.size(0) * t0_f9.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f9[i1] = t0_f9[i1];
      }

      expl_temp.f8.set_size(1, t0_f8.size(1));
      kstr = t0_f8.size(0) * t0_f8.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f8[i1] = t0_f8[i1];
      }

      expl_temp.f7.set_size(1, t0_f7.size(1));
      kstr = t0_f7.size(0) * t0_f7.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f7[i1] = t0_f7[i1];
      }

      expl_temp.f6.set_size(t0_f6.size(0));
      kstr = t0_f6.size(0);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f6[i1] = t0_f6[i1];
      }

      expl_temp.f5.set_size(1, t0_f5.size(1));
      kstr = t0_f5.size(0) * t0_f5.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f5[i1] = t0_f5[i1];
      }

      expl_temp.f4.set_size(1, t0_f4.size(1));
      kstr = t0_f4.size(0) * t0_f4.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f4[i1] = t0_f4[i1];
      }

      expl_temp.f3.set_size(1, t0_f3.size(1));
      kstr = t0_f3.size(0) * t0_f3.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f3[i1] = t0_f3[i1];
      }

      expl_temp.f2.set_size(1, t0_f2.size(1));
      kstr = t0_f2.size(0) * t0_f2.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f2[i1] = t0_f2[i1];
      }

      expl_temp.f1.set_size(1, t0_f1.size(1));
      kstr = t0_f1.size(0) * t0_f1.size(1);
      for (i1 = 0; i1 < kstr; i1++) {
        expl_temp.f1[i1] = t0_f1[i1];
      }

      c_standardTF_reflectivityCalcul(problemDef, &expl_temp, controls, problem,
        b_reflectivity, cell1, cell3, b_layerSlds, b_sldProfiles, allLayers);
      reflectivity.set_size(b_reflectivity.size(0));
      i1 = b_reflectivity.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        reflectivity[b_i].f1.set_size(b_reflectivity[b_i].f1.size(0),
          b_reflectivity[b_i].f1.size(1));
        kstr = b_reflectivity[b_i].f1.size(0) * b_reflectivity[b_i].f1.size(1);
        for (i2 = 0; i2 < kstr; i2++) {
          reflectivity[b_i].f1[i2] = b_reflectivity[b_i].f1[i2];
        }
      }

      Simulation.set_size(cell1.size(0));
      i1 = cell1.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        Simulation[b_i].f1.set_size(cell1[b_i].f1.size(0), 2);
        kstr = cell1[b_i].f1.size(0) * cell1[b_i].f1.size(1);
        for (i2 = 0; i2 < kstr; i2++) {
          Simulation[b_i].f1[i2] = cell1[b_i].f1[i2];
        }
      }

      shifted_data.set_size(cell3.size(0));
      i1 = cell3.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        shifted_data[b_i].f1.set_size(cell3[b_i].f1.size(0), 3);
        kstr = cell3[b_i].f1.size(0) * cell3[b_i].f1.size(1);
        for (i2 = 0; i2 < kstr; i2++) {
          shifted_data[b_i].f1[i2] = cell3[b_i].f1[i2];
        }
      }

      layerSlds.set_size(b_layerSlds.size(0));
      i1 = b_layerSlds.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        layerSlds[b_i].f1.set_size(b_layerSlds[b_i].f1.size(0), 3);
        kstr = b_layerSlds[b_i].f1.size(0) * b_layerSlds[b_i].f1.size(1);
        for (i2 = 0; i2 < kstr; i2++) {
          layerSlds[b_i].f1[i2] = b_layerSlds[b_i].f1[i2];
        }
      }

      sldProfiles.set_size(b_sldProfiles.size(0));
      i1 = b_sldProfiles.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        sldProfiles[b_i].f1.set_size(b_sldProfiles[b_i].f1.size(0),
          b_sldProfiles[b_i].f1.size(1));
        kstr = b_sldProfiles[b_i].f1.size(0) * b_sldProfiles[b_i].f1.size(1);
        for (i2 = 0; i2 < kstr; i2++) {
          sldProfiles[b_i].f1[i2] = b_sldProfiles[b_i].f1[i2];
        }
      }

      // case 'oilWaterTF'
      // problem = oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);     
      // case 'polarisedTF'
      // problem = polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls); 
      // case 'domainsTF'
      // problem = domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls); 
    }
    break;
  }

  // cell1Length = numberOfContrasts;
  cell1.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    cell1[b_i].f1.set_size(reflectivity[b_i].f1.size(0), 2);
    kstr = reflectivity[b_i].f1.size(0) * reflectivity[b_i].f1.size(1);
    for (i1 = 0; i1 < kstr; i1++) {
      cell1[b_i].f1[i1] = reflectivity[b_i].f1[i1];
    }
  }

  result->f1.set_size(cell1.size(0));
  kstr = cell1.size(0);
  for (i1 = 0; i1 < kstr; i1++) {
    result->f1[i1] = cell1[i1];
  }

  //  cell2Length = 7;
  cell1.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    cell1[b_i].f1.set_size(Simulation[b_i].f1.size(0), 2);
    kstr = Simulation[b_i].f1.size(0) * Simulation[b_i].f1.size(1);
    for (i1 = 0; i1 < kstr; i1++) {
      cell1[b_i].f1[i1] = Simulation[b_i].f1[i1];
    }
  }

  result->f2.set_size(cell1.size(0));
  kstr = cell1.size(0);
  for (i1 = 0; i1 < kstr; i1++) {
    result->f2[i1] = cell1[i1];
  }

  //
  //  cell3Length = 7;
  cell3.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    cell3[b_i].f1.set_size(shifted_data[b_i].f1.size(0), 3);
    kstr = shifted_data[b_i].f1.size(0) * shifted_data[b_i].f1.size(1);
    for (i1 = 0; i1 < kstr; i1++) {
      cell3[b_i].f1[i1] = shifted_data[b_i].f1[i1];
    }
  }

  result->f3.set_size(cell3.size(0));
  kstr = cell3.size(0);
  for (i1 = 0; i1 < kstr; i1++) {
    result->f3[i1] = cell3[i1];
  }

  //
  //  cell4Length = 7;
  cell3.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    cell3[b_i].f1.set_size(layerSlds[b_i].f1.size(0), 3);
    kstr = layerSlds[b_i].f1.size(0) * layerSlds[b_i].f1.size(1);
    for (i1 = 0; i1 < kstr; i1++) {
      cell3[b_i].f1[i1] = layerSlds[b_i].f1[i1];
    }
  }

  result->f4.set_size(cell3.size(0));
  kstr = cell3.size(0);
  for (i1 = 0; i1 < kstr; i1++) {
    result->f4[i1] = cell3[i1];
  }

  //
  //  cell5Length = 7;
  cell1.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    cell1[b_i].f1.set_size(sldProfiles[b_i].f1.size(0), 2);
    kstr = sldProfiles[b_i].f1.size(0) * sldProfiles[b_i].f1.size(1);
    for (i1 = 0; i1 < kstr; i1++) {
      cell1[b_i].f1[i1] = sldProfiles[b_i].f1[i1];
    }
  }

  result->f5.set_size(cell1.size(0));
  kstr = cell1.size(0);
  for (i1 = 0; i1 < kstr; i1++) {
    result->f5[i1] = cell1[i1];
  }

  //
  //  cell6Length = 7;
  cell6.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    cell6[b_i] = 0;
  }

  result->f6.set_size(cell6.size(0));
  kstr = cell6.size(0);
  for (i = 0; i < kstr; i++) {
    result->f6[i] = cell6[i];
  }
}

//
// File trailer for reflectivity_calculation.cpp
//
// [EOF]
//
