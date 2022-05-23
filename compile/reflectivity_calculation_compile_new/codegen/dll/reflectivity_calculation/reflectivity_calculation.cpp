//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivity_calculation.cpp
//
// Code generation for function 'reflectivity_calculation'
//

// Include files
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_initialize.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_custLay_reflectivityCalculation.h"
#include "standardTF_custXY_reflectivityCalculation.h"
#include "standardTF_stanLay_reflectivityCalculation.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Type Definitions
struct cell_wrap_11 {
  coder::array<double, 2U> f1;
};

// Function Definitions
void reflectivity_calculation(const struct0_T *problemDef,
                              const cell_6 *problemDef_cells, const struct1_T *,
                              const struct2_T *controls, struct4_T *problem,
                              cell_9 *result)
{
  static const char b_cv2[13]{'c', 'u', 's', 't', 'o', 'm', ' ',
                              'l', 'a', 'y', 'e', 'r', 's'};
  static const char b_cv[10]{'s', 't', 'a', 'n', 'd', 'a', 'r', 'd', 'T', 'F'};
  static const char cv3[9]{'c', 'u', 's', 't', 'o', 'm', ' ', 'x', 'y'};
  static const char b_cv1[6]{'l', 'a', 'y', 'e', 'r', 's'};
  coder::array<cell_wrap_1, 1U> allLayers;
  coder::array<cell_wrap_1, 1U> b_shifted_data;
  coder::array<cell_wrap_1, 1U> b_sldProfiles;
  coder::array<cell_wrap_10, 1U> Simulation;
  coder::array<cell_wrap_10, 1U> reflectivity;
  coder::array<cell_wrap_10, 1U> sldProfiles;
  coder::array<cell_wrap_11, 1U> layerSlds;
  coder::array<cell_wrap_11, 1U> shifted_data;
  coder::array<cell_wrap_7, 1U> b_Simulation;
  coder::array<cell_wrap_7, 1U> b_reflectivity;
  coder::array<cell_wrap_8, 1U> b_layerSlds;
  coder::array<char, 2U> switch_expression;
  coder::array<signed char, 1U> cell6;
  cell_14 b_expl_temp;
  cell_14 expl_temp;
  int b_i;
  int c_bool;
  int exitg1;
  int i;
  int i1;
  int kstr;
  int loop_ub_tmp;
  boolean_T b_bool;
  if (!isInitialized_reflectivity_calculation) {
    reflectivity_calculation_initialize();
  }
  // Preallocatin of outputs
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
  loop_ub_tmp = static_cast<int>(problemDef->numberOfContrasts);
  reflectivity.set_size(loop_ub_tmp);
  Simulation.set_size(loop_ub_tmp);
  shifted_data.set_size(loop_ub_tmp);
  layerSlds.set_size(loop_ub_tmp);
  sldProfiles.set_size(loop_ub_tmp);
  for (i = 0; i < loop_ub_tmp; i++) {
    reflectivity[i].f1.set_size(2, 2);
    reflectivity[i].f1[0] = 1.0;
    reflectivity[i].f1[1] = 1.0;
    reflectivity[i].f1[reflectivity[i].f1.size(0)] = 1.0;
    reflectivity[i].f1[reflectivity[i].f1.size(0) + 1] = 1.0;
    Simulation[i].f1.set_size(2, 2);
    Simulation[i].f1[0] = 1.0;
    Simulation[i].f1[1] = 1.0;
    Simulation[i].f1[Simulation[i].f1.size(0)] = 1.0;
    Simulation[i].f1[Simulation[i].f1.size(0) + 1] = 1.0;
    shifted_data[i].f1.set_size(2, 3);
    layerSlds[i].f1.set_size(2, 3);
    for (b_i = 0; b_i < 3; b_i++) {
      shifted_data[i].f1[shifted_data[i].f1.size(0) * b_i] = 1.0;
      shifted_data[i].f1[shifted_data[i].f1.size(0) * b_i + 1] = 1.0;
      layerSlds[i].f1[layerSlds[i].f1.size(0) * b_i] = 1.0;
      layerSlds[i].f1[layerSlds[i].f1.size(0) * b_i + 1] = 1.0;
    }
    sldProfiles[i].f1.set_size(2, 2);
    sldProfiles[i].f1[0] = 1.0;
    sldProfiles[i].f1[1] = 1.0;
    sldProfiles[i].f1[sldProfiles[i].f1.size(0)] = 1.0;
    sldProfiles[i].f1[sldProfiles[i].f1.size(0) + 1] = 1.0;
  }
  // Decide which target function we are calling
  b_bool = false;
  if (problemDef->TF.size(1) == 10) {
    kstr = 0;
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
    c_bool = 0;
  } else {
    c_bool = -1;
  }
  switch (c_bool) {
  case 0: {
    int i2;
    expl_temp.f6.set_size(problemDef_cells->f6.size(0));
    b_i = problemDef_cells->f6.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = problemDef_cells->f6[i1].f1.size[1];
      expl_temp.f6[i1].f1.set_size(1, problemDef_cells->f6[i1].f1.size[1]);
      for (i = 0; i < kstr; i++) {
        expl_temp.f6[i1].f1[i] = problemDef_cells->f6[i1].f1.data[i];
      }
    }
    //  Main function for the standardTF reflectivity calculation
    //  This function decides what type of model is being analysed and barnches
    //  to the correct one. The main options are:
    //  layers            - This is the equivalent of Standard Layers in RasCAL
    //  Custom Layers     - This is also a layers calculation, but the
    //                    specification of the layers is dne using a user
    //                    defined function.
    //  Custom XY         - This also has a model described by a user supplied
    //                    function, but in this case the function generates an
    //                    SLD profile (i.e. XY function) rather than a list of
    //                    layers.
    //  Find out the model type from the input structs
    //  Pre-allocate the output arrays.. this is necessary because otherwise
    //  the compiler complains
    problem->ssubs.set_size(loop_ub_tmp);
    problem->backgrounds.set_size(loop_ub_tmp);
    problem->qshifts.set_size(loop_ub_tmp);
    problem->scalefactors.set_size(loop_ub_tmp);
    problem->nbairs.set_size(loop_ub_tmp);
    problem->nbsubs.set_size(loop_ub_tmp);
    problem->resolutions.set_size(loop_ub_tmp);
    problem->calculations.all_chis.set_size(loop_ub_tmp);
    problem->calculations.sum_chi = 0.0;
    problem->allSubRough.set_size(loop_ub_tmp);
    b_reflectivity.set_size(loop_ub_tmp);
    b_Simulation.set_size(loop_ub_tmp);
    b_shifted_data.set_size(loop_ub_tmp);
    b_layerSlds.set_size(loop_ub_tmp);
    b_sldProfiles.set_size(loop_ub_tmp);
    for (i = 0; i < loop_ub_tmp; i++) {
      problem->ssubs[i] = 0.0;
      problem->backgrounds[i] = 0.0;
      problem->qshifts[i] = 0.0;
      problem->scalefactors[i] = 0.0;
      problem->nbairs[i] = 0.0;
      problem->nbsubs[i] = 0.0;
      problem->resolutions[i] = 0.0;
      problem->calculations.all_chis[i] = 0.0;
      problem->allSubRough[i] = 0.0;
      b_reflectivity[i].f1.set_size(2, 2);
      b_reflectivity[i].f1[0] = 1.0;
      b_reflectivity[i].f1[1] = 1.0;
      b_reflectivity[i].f1[b_reflectivity[i].f1.size(0)] = 1.0;
      b_reflectivity[i].f1[b_reflectivity[i].f1.size(0) + 1] = 1.0;
      b_Simulation[i].f1.set_size(2, 2);
      b_Simulation[i].f1[0] = 1.0;
      b_Simulation[i].f1[1] = 1.0;
      b_Simulation[i].f1[b_Simulation[i].f1.size(0)] = 1.0;
      b_Simulation[i].f1[b_Simulation[i].f1.size(0) + 1] = 1.0;
      b_shifted_data[i].f1.set_size(2, 3);
      b_layerSlds[i].f1.set_size(2, 3);
      for (b_i = 0; b_i < 3; b_i++) {
        b_shifted_data[i].f1[b_shifted_data[i].f1.size(0) * b_i] = 1.0;
        b_shifted_data[i].f1[b_shifted_data[i].f1.size(0) * b_i + 1] = 1.0;
        b_layerSlds[i].f1[b_layerSlds[i].f1.size(0) * b_i] = 1.0;
        b_layerSlds[i].f1[b_layerSlds[i].f1.size(0) * b_i + 1] = 1.0;
      }
      b_sldProfiles[i].f1.set_size(2, 2);
      b_sldProfiles[i].f1[0] = 1.0;
      b_sldProfiles[i].f1[1] = 1.0;
      b_sldProfiles[i].f1[b_sldProfiles[i].f1.size(0)] = 1.0;
      b_sldProfiles[i].f1[b_sldProfiles[i].f1.size(0) + 1] = 1.0;
    }
    switch_expression.set_size(1, problemDef->modelType.size(1));
    b_i = problemDef->modelType.size(1);
    for (kstr = 0; kstr < b_i; kstr++) {
      switch_expression[kstr] =
          cv[static_cast<unsigned char>(problemDef->modelType[kstr]) & 127];
    }
    b_bool = false;
    if (switch_expression.size(1) == 6) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 6) {
          if (switch_expression[kstr] != b_cv1[kstr]) {
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
      b_bool = false;
      if (switch_expression.size(1) == 13) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 13) {
            if (switch_expression[kstr] != b_cv2[kstr]) {
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
        kstr = 1;
      } else {
        b_bool = false;
        if (switch_expression.size(1) == 9) {
          kstr = 0;
          do {
            exitg1 = 0;
            if (kstr < 9) {
              if (switch_expression[kstr] != cv3[kstr]) {
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
          kstr = 2;
        } else {
          kstr = -1;
        }
      }
    }
    switch (kstr) {
    case 0:
      //  Standard layers calculation
      expl_temp.f14.set_size(1, problemDef_cells->f14.size(1));
      kstr = problemDef_cells->f14.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f14[b_i] = problemDef_cells->f14[b_i];
      }
      expl_temp.f13.set_size(1, problemDef_cells->f13.size(1));
      kstr = problemDef_cells->f13.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f13[b_i] = problemDef_cells->f13[b_i];
      }
      expl_temp.f12.set_size(1, problemDef_cells->f12.size(1));
      kstr = problemDef_cells->f12.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f12[b_i] = problemDef_cells->f12[b_i];
      }
      expl_temp.f11.set_size(1, problemDef_cells->f11.size(1));
      kstr = problemDef_cells->f11.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f11[b_i] = problemDef_cells->f11[b_i];
      }
      expl_temp.f10.set_size(1, problemDef_cells->f10.size(1));
      kstr = problemDef_cells->f10.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f10[b_i] = problemDef_cells->f10[b_i];
      }
      expl_temp.f9.set_size(1, problemDef_cells->f9.size(1));
      kstr = problemDef_cells->f9.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f9[b_i] = problemDef_cells->f9[b_i];
      }
      expl_temp.f8.set_size(1, problemDef_cells->f8.size(1));
      kstr = problemDef_cells->f8.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f8[b_i] = problemDef_cells->f8[b_i];
      }
      expl_temp.f7.set_size(1, problemDef_cells->f7.size(1));
      kstr = problemDef_cells->f7.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f7[b_i] = problemDef_cells->f7[b_i];
      }
      expl_temp.f5.set_size(1, problemDef_cells->f5.size(1));
      kstr = problemDef_cells->f5.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f5[b_i] = problemDef_cells->f5[b_i];
      }
      expl_temp.f4.set_size(1, problemDef_cells->f4.size(1));
      kstr = problemDef_cells->f4.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f4[b_i] = problemDef_cells->f4[b_i];
      }
      expl_temp.f3.set_size(1, problemDef_cells->f3.size(1));
      kstr = problemDef_cells->f3.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f3[b_i] = problemDef_cells->f3[b_i];
      }
      expl_temp.f2.set_size(1, problemDef_cells->f2.size(1));
      kstr = problemDef_cells->f2.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f2[b_i] = problemDef_cells->f2[b_i];
      }
      expl_temp.f1.set_size(1, problemDef_cells->f1.size(1));
      kstr = problemDef_cells->f1.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        expl_temp.f1[b_i] = problemDef_cells->f1[b_i];
      }
      standardTF_stanLay_reflectivityCalculation(
          problemDef, &expl_temp, controls, problem, b_reflectivity,
          b_Simulation, b_shifted_data, b_layerSlds, b_sldProfiles, allLayers);
      break;
    case 1:
      //  Custom layers with user supplied custom model file
      b_expl_temp.f14.set_size(1, problemDef_cells->f14.size(1));
      kstr = problemDef_cells->f14.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f14[b_i] = problemDef_cells->f14[b_i];
      }
      b_expl_temp.f13.set_size(1, problemDef_cells->f13.size(1));
      kstr = problemDef_cells->f13.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f13[b_i] = problemDef_cells->f13[b_i];
      }
      b_expl_temp.f12.set_size(1, problemDef_cells->f12.size(1));
      kstr = problemDef_cells->f12.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f12[b_i] = problemDef_cells->f12[b_i];
      }
      b_expl_temp.f11.set_size(1, problemDef_cells->f11.size(1));
      kstr = problemDef_cells->f11.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f11[b_i] = problemDef_cells->f11[b_i];
      }
      b_expl_temp.f10.set_size(1, problemDef_cells->f10.size(1));
      kstr = problemDef_cells->f10.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f10[b_i] = problemDef_cells->f10[b_i];
      }
      b_expl_temp.f9.set_size(1, problemDef_cells->f9.size(1));
      kstr = problemDef_cells->f9.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f9[b_i] = problemDef_cells->f9[b_i];
      }
      b_expl_temp.f8.set_size(1, problemDef_cells->f8.size(1));
      kstr = problemDef_cells->f8.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f8[b_i] = problemDef_cells->f8[b_i];
      }
      b_expl_temp.f7.set_size(1, problemDef_cells->f7.size(1));
      kstr = problemDef_cells->f7.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f7[b_i] = problemDef_cells->f7[b_i];
      }
      b_expl_temp.f6.set_size(expl_temp.f6.size(0));
      kstr = expl_temp.f6.size(0);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f6[b_i] = expl_temp.f6[b_i];
      }
      b_expl_temp.f5.set_size(1, problemDef_cells->f5.size(1));
      kstr = problemDef_cells->f5.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f5[b_i] = problemDef_cells->f5[b_i];
      }
      b_expl_temp.f4.set_size(1, problemDef_cells->f4.size(1));
      kstr = problemDef_cells->f4.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f4[b_i] = problemDef_cells->f4[b_i];
      }
      b_expl_temp.f3.set_size(1, problemDef_cells->f3.size(1));
      kstr = problemDef_cells->f3.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f3[b_i] = problemDef_cells->f3[b_i];
      }
      b_expl_temp.f2.set_size(1, problemDef_cells->f2.size(1));
      kstr = problemDef_cells->f2.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f2[b_i] = problemDef_cells->f2[b_i];
      }
      b_expl_temp.f1.set_size(1, problemDef_cells->f1.size(1));
      kstr = problemDef_cells->f1.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f1[b_i] = problemDef_cells->f1[b_i];
      }
      standardTF_custLay_reflectivityCalculation(
          problemDef, &b_expl_temp, controls, problem, b_reflectivity,
          b_Simulation, b_shifted_data, b_layerSlds, b_sldProfiles, allLayers);
      break;
    case 2:
      //  Custom SLD profile with user defined model file
      b_expl_temp.f14.set_size(1, problemDef_cells->f14.size(1));
      kstr = problemDef_cells->f14.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f14[b_i] = problemDef_cells->f14[b_i];
      }
      b_expl_temp.f13.set_size(1, problemDef_cells->f13.size(1));
      kstr = problemDef_cells->f13.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f13[b_i] = problemDef_cells->f13[b_i];
      }
      b_expl_temp.f12.set_size(1, problemDef_cells->f12.size(1));
      kstr = problemDef_cells->f12.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f12[b_i] = problemDef_cells->f12[b_i];
      }
      b_expl_temp.f11.set_size(1, problemDef_cells->f11.size(1));
      kstr = problemDef_cells->f11.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f11[b_i] = problemDef_cells->f11[b_i];
      }
      b_expl_temp.f10.set_size(1, problemDef_cells->f10.size(1));
      kstr = problemDef_cells->f10.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f10[b_i] = problemDef_cells->f10[b_i];
      }
      b_expl_temp.f9.set_size(1, problemDef_cells->f9.size(1));
      kstr = problemDef_cells->f9.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f9[b_i] = problemDef_cells->f9[b_i];
      }
      b_expl_temp.f8.set_size(1, problemDef_cells->f8.size(1));
      kstr = problemDef_cells->f8.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f8[b_i] = problemDef_cells->f8[b_i];
      }
      b_expl_temp.f7.set_size(1, problemDef_cells->f7.size(1));
      kstr = problemDef_cells->f7.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f7[b_i] = problemDef_cells->f7[b_i];
      }
      b_expl_temp.f6.set_size(expl_temp.f6.size(0));
      kstr = expl_temp.f6.size(0);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f6[b_i] = expl_temp.f6[b_i];
      }
      b_expl_temp.f5.set_size(1, problemDef_cells->f5.size(1));
      kstr = problemDef_cells->f5.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f5[b_i] = problemDef_cells->f5[b_i];
      }
      b_expl_temp.f4.set_size(1, problemDef_cells->f4.size(1));
      kstr = problemDef_cells->f4.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f4[b_i] = problemDef_cells->f4[b_i];
      }
      b_expl_temp.f3.set_size(1, problemDef_cells->f3.size(1));
      kstr = problemDef_cells->f3.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f3[b_i] = problemDef_cells->f3[b_i];
      }
      b_expl_temp.f2.set_size(1, problemDef_cells->f2.size(1));
      kstr = problemDef_cells->f2.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f2[b_i] = problemDef_cells->f2[b_i];
      }
      b_expl_temp.f1.set_size(1, problemDef_cells->f1.size(1));
      kstr = problemDef_cells->f1.size(1);
      for (b_i = 0; b_i < kstr; b_i++) {
        b_expl_temp.f1[b_i] = problemDef_cells->f1[b_i];
      }
      standardTF_custXY_reflectivityCalculation(
          problemDef, &b_expl_temp, controls, problem, b_reflectivity,
          b_Simulation, b_shifted_data, b_layerSlds, b_sldProfiles, allLayers);
      break;
    }
    reflectivity.set_size(b_reflectivity.size(0));
    b_i = b_reflectivity.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = b_reflectivity[i1].f1.size(0);
      reflectivity[i1].f1.set_size(b_reflectivity[i1].f1.size(0), 2);
      for (i = 0; i < 2; i++) {
        for (i2 = 0; i2 < kstr; i2++) {
          reflectivity[i1].f1[i2 + reflectivity[i1].f1.size(0) * i] =
              b_reflectivity[i1].f1[i2 + b_reflectivity[i1].f1.size(0) * i];
        }
      }
    }
    Simulation.set_size(b_Simulation.size(0));
    b_i = b_Simulation.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = b_Simulation[i1].f1.size(0);
      Simulation[i1].f1.set_size(b_Simulation[i1].f1.size(0), 2);
      for (i = 0; i < 2; i++) {
        for (i2 = 0; i2 < kstr; i2++) {
          Simulation[i1].f1[i2 + Simulation[i1].f1.size(0) * i] =
              b_Simulation[i1].f1[i2 + b_Simulation[i1].f1.size(0) * i];
        }
      }
    }
    shifted_data.set_size(b_shifted_data.size(0));
    b_i = b_shifted_data.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = b_shifted_data[i1].f1.size(1);
      shifted_data[i1].f1.set_size(b_shifted_data[i1].f1.size(0),
                                   b_shifted_data[i1].f1.size(1));
      for (i = 0; i < kstr; i++) {
        c_bool = b_shifted_data[i1].f1.size(0);
        for (i2 = 0; i2 < c_bool; i2++) {
          shifted_data[i1].f1[i2 + shifted_data[i1].f1.size(0) * i] =
              b_shifted_data[i1].f1[i2 + b_shifted_data[i1].f1.size(0) * i];
        }
      }
    }
    layerSlds.set_size(b_layerSlds.size(0));
    b_i = b_layerSlds.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = b_layerSlds[i1].f1.size(0);
      layerSlds[i1].f1.set_size(b_layerSlds[i1].f1.size(0), 3);
      for (i = 0; i < 3; i++) {
        for (i2 = 0; i2 < kstr; i2++) {
          layerSlds[i1].f1[i2 + layerSlds[i1].f1.size(0) * i] =
              b_layerSlds[i1].f1[i2 + b_layerSlds[i1].f1.size(0) * i];
        }
      }
    }
    sldProfiles.set_size(b_sldProfiles.size(0));
    b_i = b_sldProfiles.size(0);
    for (i1 = 0; i1 < b_i; i1++) {
      kstr = b_sldProfiles[i1].f1.size(1);
      sldProfiles[i1].f1.set_size(b_sldProfiles[i1].f1.size(0),
                                  b_sldProfiles[i1].f1.size(1));
      for (i = 0; i < kstr; i++) {
        c_bool = b_sldProfiles[i1].f1.size(0);
        for (i2 = 0; i2 < c_bool; i2++) {
          sldProfiles[i1].f1[i2 + sldProfiles[i1].f1.size(0) * i] =
              b_sldProfiles[i1].f1[i2 + b_sldProfiles[i1].f1.size(0) * i];
        }
      }
    }
    // case 'oilWaterTF'
    // problem =
    // oilWaterTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
    // case 'polarisedTF'
    // problem =
    // polarisedTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
    // case 'domainsTF'
    // problem =
    // domainsTF_reflectivityCalculation(problemDef,problemDef_cells,controls);
  } break;
  }
  // cell1Length = numberOfContrasts;
  b_i = static_cast<int>(problemDef->numberOfContrasts);
  result->f1.set_size(b_i);
  //  cell2Length = 7;
  b_i = static_cast<int>(problemDef->numberOfContrasts);
  result->f2.set_size(b_i);
  //
  //  cell3Length = 7;
  b_i = static_cast<int>(problemDef->numberOfContrasts);
  result->f3.set_size(b_i);
  //
  //  cell4Length = 7;
  b_i = static_cast<int>(problemDef->numberOfContrasts);
  result->f4.set_size(b_i);
  //
  //  cell5Length = 7;
  b_i = static_cast<int>(problemDef->numberOfContrasts);
  result->f5.set_size(b_i);
  //
  //  cell6Length = 7;
  b_i = static_cast<int>(problemDef->numberOfContrasts);
  cell6.set_size(b_i);
  for (i = 0; i < loop_ub_tmp; i++) {
    kstr = reflectivity[i].f1.size(0);
    result->f1[i].f1.set_size(reflectivity[i].f1.size(0), 2);
    c_bool = Simulation[i].f1.size(0);
    result->f2[i].f1.set_size(Simulation[i].f1.size(0), 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < kstr; i1++) {
        result->f1[i].f1[i1 + result->f1[i].f1.size(0) * b_i] =
            reflectivity[i].f1[i1 + reflectivity[i].f1.size(0) * b_i];
      }
      for (i1 = 0; i1 < c_bool; i1++) {
        result->f2[i].f1[i1 + result->f2[i].f1.size(0) * b_i] =
            Simulation[i].f1[i1 + Simulation[i].f1.size(0) * b_i];
      }
    }
    kstr = shifted_data[i].f1.size(0);
    result->f3[i].f1.set_size(shifted_data[i].f1.size(0), 3);
    c_bool = layerSlds[i].f1.size(0);
    result->f4[i].f1.set_size(layerSlds[i].f1.size(0), 3);
    for (b_i = 0; b_i < 3; b_i++) {
      for (i1 = 0; i1 < kstr; i1++) {
        result->f3[i].f1[i1 + result->f3[i].f1.size(0) * b_i] =
            shifted_data[i].f1[i1 + shifted_data[i].f1.size(0) * b_i];
      }
      for (i1 = 0; i1 < c_bool; i1++) {
        result->f4[i].f1[i1 + result->f4[i].f1.size(0) * b_i] =
            layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * b_i];
      }
    }
    kstr = sldProfiles[i].f1.size(0);
    result->f5[i].f1.set_size(sldProfiles[i].f1.size(0), 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < kstr; i1++) {
        result->f5[i].f1[i1 + result->f5[i].f1.size(0) * b_i] =
            sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * b_i];
      }
    }
    cell6[i] = 0;
  }
  result->f6.set_size(cell6.size(0));
  kstr = cell6.size(0);
  for (b_i = 0; b_i < kstr; b_i++) {
    result->f6[b_i] = 0.0;
  }
}

// End of code generation (reflectivity_calculation.cpp)
