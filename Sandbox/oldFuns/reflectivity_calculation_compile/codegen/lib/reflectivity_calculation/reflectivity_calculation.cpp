//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: reflectivity_calculation.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Apr-2021 11:38:50
//

// Include Files
#include "reflectivity_calculation.h"
#include "groupLayers_Mod.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_initialize.h"
#include "rt_nonfinite.h"
#include "standardTF_stanLay_reflectivityCalculation.h"
#include "standardTF_stanlay_paraAll.h"

// Type Definitions
struct cell_wrap_11
{
  coder::array<double, 2U> f1;
};

struct cell_wrap_12
{
  coder::array<double, 2U> f1;
};

// Function Definitions

//
// Preallocatin of outputs
// Arguments    : const struct0_T *problemDef
//                const cell_7 *problemDef_cells
//                const struct1_T *problemDef_limits
//                const struct2_T *controls
//                struct4_T *problem
//                cell_10 *result
// Return Type  : void
//
void reflectivity_calculation(const struct0_T *problemDef, const cell_7
  *problemDef_cells, const struct1_T *, const struct2_T *controls, struct4_T
  *problem, cell_10 *result)
{
  int loop_ub;
  coder::array<cell_wrap_11, 1U> reflectivity;
  coder::array<cell_wrap_11, 1U> Simulation;
  coder::array<cell_wrap_12, 1U> shifted_data;
  coder::array<cell_wrap_12, 1U> layerSlds;
  coder::array<cell_wrap_11, 1U> sldProfiles;
  int i;
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv[10] = { 's', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T', 'F'
  };

  coder::array<cell_wrap_0, 2U> t0_f1;
  coder::array<cell_wrap_8, 1U> cell1;
  int b_i;
  coder::array<cell_wrap_1, 2U> t0_f2;
  coder::array<cell_wrap_0, 2U> t0_f3;
  coder::array<cell_wrap_0, 2U> t0_f4;
  coder::array<cell_wrap_2, 2U> t0_f5;
  coder::array<cell_wrap_9, 1U> cell3;
  coder::array<cell_wrap_2, 1U> t0_f6;
  coder::array<cell_wrap_4, 2U> t0_f7;
  coder::array<cell_wrap_4, 2U> t0_f8;
  coder::array<cell_wrap_4, 2U> t0_f9;
  coder::array<cell_wrap_4, 2U> t0_f10;
  coder::array<cell_wrap_4, 2U> t0_f11;
  coder::array<cell_wrap_4, 2U> t0_f12;
  coder::array<signed char, 1U> cell6;
  coder::array<cell_wrap_4, 2U> t0_f13;
  coder::array<cell_wrap_8, 1U> b_Simulation;
  coder::array<cell_wrap_1, 1U> b_shifted_data;
  coder::array<cell_wrap_1, 1U> b_sldProfiles;
  static const char cv1[6] = { 'l', 'a', 'y', 'e', 'r', 's' };

  cell_15 expl_temp;
  coder::array<cell_wrap_13, 1U> allLayers;
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
  loop_ub = static_cast<int>(problemDef->numberOfContrasts);
  reflectivity.set_size(loop_ub);
  Simulation.set_size(loop_ub);
  shifted_data.set_size(loop_ub);
  layerSlds.set_size(loop_ub);
  sldProfiles.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
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
  }

  // Decide which target function we are calling
  b_bool = false;
  if (problemDef->TF.size(1) == 10) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (problemDef->TF[kstr] != cv[kstr]) {
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
      int i1;
      t0_f1.set_size(1, problemDef_cells->f1.size(1));
      kstr = problemDef_cells->f1.size(0) * problemDef_cells->f1.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f1[b_i] = problemDef_cells->f1[b_i];
      }

      t0_f2.set_size(1, problemDef_cells->f2.size(1));
      kstr = problemDef_cells->f2.size(0) * problemDef_cells->f2.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f2[b_i] = problemDef_cells->f2[b_i];
      }

      t0_f3.set_size(1, problemDef_cells->f3.size(1));
      kstr = problemDef_cells->f3.size(0) * problemDef_cells->f3.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f3[b_i] = problemDef_cells->f3[b_i];
      }

      t0_f4.set_size(1, problemDef_cells->f4.size(1));
      kstr = problemDef_cells->f4.size(0) * problemDef_cells->f4.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f4[b_i] = problemDef_cells->f4[b_i];
      }

      t0_f5.set_size(1, problemDef_cells->f5.size(1));
      kstr = problemDef_cells->f5.size(0) * problemDef_cells->f5.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f5[b_i] = problemDef_cells->f5[b_i];
      }

      t0_f6.set_size(problemDef_cells->f6.size(0));
      b_i = problemDef_cells->f6.size(0);
      for (i = 0; i < b_i; i++) {
        t0_f6[i].f1.set_size(1, problemDef_cells->f6[i].f1.size[1]);
        kstr = problemDef_cells->f6[i].f1.size[0] * problemDef_cells->f6[i].
          f1.size[1];
        for (i1 = 0; i1 < kstr; i1++) {
          t0_f6[i].f1[i1] = problemDef_cells->f6[i].f1.data[i1];
        }
      }

      t0_f7.set_size(1, problemDef_cells->f7.size(1));
      kstr = problemDef_cells->f7.size(0) * problemDef_cells->f7.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f7[b_i] = problemDef_cells->f7[b_i];
      }

      t0_f8.set_size(1, problemDef_cells->f8.size(1));
      kstr = problemDef_cells->f8.size(0) * problemDef_cells->f8.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f8[b_i] = problemDef_cells->f8[b_i];
      }

      t0_f9.set_size(1, problemDef_cells->f9.size(1));
      kstr = problemDef_cells->f9.size(0) * problemDef_cells->f9.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f9[b_i] = problemDef_cells->f9[b_i];
      }

      t0_f10.set_size(1, problemDef_cells->f10.size(1));
      kstr = problemDef_cells->f10.size(0) * problemDef_cells->f10.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f10[b_i] = problemDef_cells->f10[b_i];
      }

      t0_f11.set_size(1, problemDef_cells->f11.size(1));
      kstr = problemDef_cells->f11.size(0) * problemDef_cells->f11.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f11[b_i] = problemDef_cells->f11[b_i];
      }

      t0_f12.set_size(1, problemDef_cells->f12.size(1));
      kstr = problemDef_cells->f12.size(0) * problemDef_cells->f12.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f12[b_i] = problemDef_cells->f12[b_i];
      }

      t0_f13.set_size(1, problemDef_cells->f13.size(1));
      kstr = problemDef_cells->f13.size(0) * problemDef_cells->f13.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        t0_f13[b_i] = problemDef_cells->f13[b_i];
      }

      // Decide what kind of calculation it is and call the appropriate one
      //  Pre-allocate the output arrays..
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
      cell1.set_size(loop_ub);
      b_Simulation.set_size(loop_ub);
      b_shifted_data.set_size(loop_ub);
      cell3.set_size(loop_ub);
      b_sldProfiles.set_size(loop_ub);
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
        cell1[i].f1.set_size(2, 2);
        cell1[i].f1[0] = 1.0;
        cell1[i].f1[1] = 1.0;
        cell1[i].f1[2] = 1.0;
        cell1[i].f1[3] = 1.0;
        b_Simulation[i].f1.set_size(2, 2);
        b_Simulation[i].f1[0] = 1.0;
        b_Simulation[i].f1[1] = 1.0;
        b_Simulation[i].f1[2] = 1.0;
        b_Simulation[i].f1[3] = 1.0;
        b_shifted_data[i].f1.set_size(2, 3);
        cell3[i].f1.set_size(2, 3);
        for (b_i = 0; b_i < 6; b_i++) {
          b_shifted_data[i].f1[b_i] = 1.0;
          cell3[i].f1[b_i] = 1.0;
        }

        b_sldProfiles[i].f1.set_size(2, 2);
        b_sldProfiles[i].f1[0] = 1.0;
        b_sldProfiles[i].f1[1] = 1.0;
        b_sldProfiles[i].f1[2] = 1.0;
        b_sldProfiles[i].f1[3] = 1.0;
      }

      b_bool = false;
      if (problemDef->modelType.size(1) == 6) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 6) {
            if (problemDef->modelType[kstr] != cv1[kstr]) {
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
        expl_temp.f14[0] = problemDef_cells->f14[0];
        expl_temp.f13.set_size(1, t0_f13.size(1));
        kstr = t0_f13.size(0) * t0_f13.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f13[b_i] = t0_f13[b_i];
        }

        expl_temp.f12.set_size(1, t0_f12.size(1));
        kstr = t0_f12.size(0) * t0_f12.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f12[b_i] = t0_f12[b_i];
        }

        expl_temp.f11.set_size(1, t0_f11.size(1));
        kstr = t0_f11.size(0) * t0_f11.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f11[b_i] = t0_f11[b_i];
        }

        expl_temp.f10.set_size(1, t0_f10.size(1));
        kstr = t0_f10.size(0) * t0_f10.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f10[b_i] = t0_f10[b_i];
        }

        expl_temp.f9.set_size(1, t0_f9.size(1));
        kstr = t0_f9.size(0) * t0_f9.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f9[b_i] = t0_f9[b_i];
        }

        expl_temp.f8.set_size(1, t0_f8.size(1));
        kstr = t0_f8.size(0) * t0_f8.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f8[b_i] = t0_f8[b_i];
        }

        expl_temp.f7.set_size(1, t0_f7.size(1));
        kstr = t0_f7.size(0) * t0_f7.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f7[b_i] = t0_f7[b_i];
        }

        expl_temp.f6.set_size(t0_f6.size(0));
        kstr = t0_f6.size(0);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f6[b_i] = t0_f6[b_i];
        }

        expl_temp.f5.set_size(1, t0_f5.size(1));
        kstr = t0_f5.size(0) * t0_f5.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f5[b_i] = t0_f5[b_i];
        }

        expl_temp.f4.set_size(1, t0_f4.size(1));
        kstr = t0_f4.size(0) * t0_f4.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f4[b_i] = t0_f4[b_i];
        }

        expl_temp.f3.set_size(1, t0_f3.size(1));
        kstr = t0_f3.size(0) * t0_f3.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f3[b_i] = t0_f3[b_i];
        }

        expl_temp.f2.set_size(1, t0_f2.size(1));
        kstr = t0_f2.size(0) * t0_f2.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f2[b_i] = t0_f2[b_i];
        }

        expl_temp.f1.set_size(1, t0_f1.size(1));
        kstr = t0_f1.size(0) * t0_f1.size(1);
        for (b_i = 0; b_i < kstr; b_i++) {
          expl_temp.f1[b_i] = t0_f1[b_i];
        }

        c_standardTF_stanLay_reflectivi(problemDef, &expl_temp, controls,
          problem, cell1, b_Simulation, b_shifted_data, cell3, b_sldProfiles,
          allLayers);

        //      case 'custom layers'
        //          [problem,reflectivity,Simulation,...
        //              shifted_data,layerSlds,sldProfiles,...
        //              allLayers] = standardTF_custLay_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); 
        //     case 'Custom XY'
        //         [problem,reflectivity,Simulation,...
        //             shifted_data,layerSlds,sldProfiles,...
        //             allLayers] = standardTF_custXY_reflectivityCalculation(problemDef,problemDef_cells,problemDef_limits,controls); 
        break;
      }

      reflectivity.set_size(cell1.size(0));
      b_i = cell1.size(0);
      for (i = 0; i < b_i; i++) {
        reflectivity[i].f1.set_size(cell1[i].f1.size(0), 2);
        kstr = cell1[i].f1.size(0) * cell1[i].f1.size(1);
        for (i1 = 0; i1 < kstr; i1++) {
          reflectivity[i].f1[i1] = cell1[i].f1[i1];
        }
      }

      Simulation.set_size(b_Simulation.size(0));
      b_i = b_Simulation.size(0);
      for (i = 0; i < b_i; i++) {
        Simulation[i].f1.set_size(b_Simulation[i].f1.size(0), 2);
        kstr = b_Simulation[i].f1.size(0) * b_Simulation[i].f1.size(1);
        for (i1 = 0; i1 < kstr; i1++) {
          Simulation[i].f1[i1] = b_Simulation[i].f1[i1];
        }
      }

      shifted_data.set_size(b_shifted_data.size(0));
      b_i = b_shifted_data.size(0);
      for (i = 0; i < b_i; i++) {
        shifted_data[i].f1.set_size(b_shifted_data[i].f1.size(0),
          b_shifted_data[i].f1.size(1));
        kstr = b_shifted_data[i].f1.size(0) * b_shifted_data[i].f1.size(1);
        for (i1 = 0; i1 < kstr; i1++) {
          shifted_data[i].f1[i1] = b_shifted_data[i].f1[i1];
        }
      }

      layerSlds.set_size(cell3.size(0));
      b_i = cell3.size(0);
      for (i = 0; i < b_i; i++) {
        layerSlds[i].f1.set_size(cell3[i].f1.size(0), 3);
        kstr = cell3[i].f1.size(0) * cell3[i].f1.size(1);
        for (i1 = 0; i1 < kstr; i1++) {
          layerSlds[i].f1[i1] = cell3[i].f1[i1];
        }
      }

      sldProfiles.set_size(b_sldProfiles.size(0));
      b_i = b_sldProfiles.size(0);
      for (i = 0; i < b_i; i++) {
        sldProfiles[i].f1.set_size(b_sldProfiles[i].f1.size(0), b_sldProfiles[i]
          .f1.size(1));
        kstr = b_sldProfiles[i].f1.size(0) * b_sldProfiles[i].f1.size(1);
        for (i1 = 0; i1 < kstr; i1++) {
          sldProfiles[i].f1[i1] = b_sldProfiles[i].f1[i1];
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
  cell1.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    cell1[i].f1.set_size(reflectivity[i].f1.size(0), 2);
    kstr = reflectivity[i].f1.size(0) * reflectivity[i].f1.size(1);
    for (b_i = 0; b_i < kstr; b_i++) {
      cell1[i].f1[b_i] = reflectivity[i].f1[b_i];
    }
  }

  result->f1.set_size(cell1.size(0));
  kstr = cell1.size(0);
  for (b_i = 0; b_i < kstr; b_i++) {
    result->f1[b_i] = cell1[b_i];
  }

  //  cell2Length = 7;
  cell1.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    cell1[i].f1.set_size(Simulation[i].f1.size(0), 2);
    kstr = Simulation[i].f1.size(0) * Simulation[i].f1.size(1);
    for (b_i = 0; b_i < kstr; b_i++) {
      cell1[i].f1[b_i] = Simulation[i].f1[b_i];
    }
  }

  result->f2.set_size(cell1.size(0));
  kstr = cell1.size(0);
  for (b_i = 0; b_i < kstr; b_i++) {
    result->f2[b_i] = cell1[b_i];
  }

  //
  //  cell3Length = 7;
  cell3.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    cell3[i].f1.set_size(shifted_data[i].f1.size(0), 3);
    kstr = shifted_data[i].f1.size(0) * shifted_data[i].f1.size(1);
    for (b_i = 0; b_i < kstr; b_i++) {
      cell3[i].f1[b_i] = shifted_data[i].f1[b_i];
    }
  }

  result->f3.set_size(cell3.size(0));
  kstr = cell3.size(0);
  for (b_i = 0; b_i < kstr; b_i++) {
    result->f3[b_i] = cell3[b_i];
  }

  //
  //  cell4Length = 7;
  cell3.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    cell3[i].f1.set_size(layerSlds[i].f1.size(0), 3);
    kstr = layerSlds[i].f1.size(0) * layerSlds[i].f1.size(1);
    for (b_i = 0; b_i < kstr; b_i++) {
      cell3[i].f1[b_i] = layerSlds[i].f1[b_i];
    }
  }

  result->f4.set_size(cell3.size(0));
  kstr = cell3.size(0);
  for (b_i = 0; b_i < kstr; b_i++) {
    result->f4[b_i] = cell3[b_i];
  }

  //
  //  cell5Length = 7;
  cell1.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    cell1[i].f1.set_size(sldProfiles[i].f1.size(0), 2);
    kstr = sldProfiles[i].f1.size(0) * sldProfiles[i].f1.size(1);
    for (b_i = 0; b_i < kstr; b_i++) {
      cell1[i].f1[b_i] = sldProfiles[i].f1[b_i];
    }
  }

  result->f5.set_size(cell1.size(0));
  kstr = cell1.size(0);
  for (b_i = 0; b_i < kstr; b_i++) {
    result->f5[b_i] = cell1[b_i];
  }

  //
  //  cell6Length = 7;
  cell6.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    cell6[i] = 0;
  }

  result->f6.set_size(cell6.size(0));
  loop_ub = cell6.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    result->f6[b_i] = cell6[b_i];
  }
}

//
// File trailer for reflectivity_calculation.cpp
//
// [EOF]
//
