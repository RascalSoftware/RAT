//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: standardTF_custXY_reflectivityCalculation.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "standardTF_custXY_reflectivityCalculation.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_custXY_paraContrasts.h"
#include "standardTF_custXY_paraPoints.h"
#include "standardTF_custXY_single.h"
#include "strcmp.h"
#include "sum.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_12, 1U> &r, ::coder::array<
                   cell_wrap_9, 1U> &r1);
  static void cast(const ::coder::array<cell_wrap_35, 1U> &r, ::coder::array<
                   cell_wrap_14, 1U> &r1);
}

// Function Definitions
//
// Arguments    : const ::coder::array<cell_wrap_12, 1U> &r
//                ::coder::array<cell_wrap_9, 1U> &r1
// Return Type  : void
//
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_12, 1U> &r, ::coder::array<
                   cell_wrap_9, 1U> &r1)
  {
    int32_T i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size(0);
      r1[i1].f1.set_size(r[i1].f1.size(0), 2);
      for (int32_T i2{0}; i2 < 2; i2++) {
        for (int32_T i3{0}; i3 < loop_ub; i3++) {
          r1[i1].f1[i3 + r1[i1].f1.size(0) * i2] = r[i1].f1[i3 + r[i1].f1.size(0)
            * i2];
        }
      }
    }
  }

  //
  // Arguments    : const ::coder::array<cell_wrap_35, 1U> &r
  //                ::coder::array<cell_wrap_14, 1U> &r1
  // Return Type  : void
  //
  static void cast(const ::coder::array<cell_wrap_35, 1U> &r, ::coder::array<
                   cell_wrap_14, 1U> &r1)
  {
    int32_T i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.set_size(r[i1].f1.size(0), r[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = r[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1[i3 + r1[i1].f1.size(0) * i2] = r[i1].f1[i3 + r[i1].f1.size(0)
            * i2];
        }
      }
    }
  }

  //
  // Custom XP profile reflectivity calculation for standardTF
  //
  // Arguments    : const real_T problemDef_contrastBacks_data[]
  //                const real_T problemDef_contrastBacksType_data[]
  //                const real_T problemDef_dataPresent_data[]
  //                real_T problemDef_numberOfContrasts
  //                const real_T problemDef_contrastShifts_data[]
  //                const real_T problemDef_contrastScales_data[]
  //                const real_T problemDef_contrastNbas_data[]
  //                const real_T problemDef_contrastNbss_data[]
  //                const real_T problemDef_contrastRes_data[]
  //                const real_T problemDef_backs_data[]
  //                const real_T problemDef_shifts_data[]
  //                const real_T problemDef_sf_data[]
  //                const real_T problemDef_nba_data[]
  //                const real_T problemDef_nbs_data[]
  //                const real_T problemDef_res_data[]
  //                const int32_T problemDef_params_size[2]
  //                const cell_18 *problemDef_cells
  //                const struct2_T *controls
  //                struct4_T *problem
  //                ::coder::array<cell_wrap_9, 1U> &reflectivity
  //                ::coder::array<cell_wrap_9, 1U> &Simulation
  //                ::coder::array<cell_wrap_14, 1U> &shifted_data
  //                ::coder::array<cell_wrap_10, 1U> &layerSlds
  //                ::coder::array<cell_wrap_14, 1U> &sldProfiles
  //                ::coder::array<cell_wrap_14, 1U> &allLayers
  // Return Type  : void
  //
  void standardTF_custXY_reflectivityCalculation(const real_T
    problemDef_contrastBacks_data[], const real_T
    problemDef_contrastBacksType_data[], const real_T
    problemDef_dataPresent_data[], real_T problemDef_numberOfContrasts, const
    real_T problemDef_contrastShifts_data[], const real_T
    problemDef_contrastScales_data[], const real_T problemDef_contrastNbas_data[],
    const real_T problemDef_contrastNbss_data[], const real_T
    problemDef_contrastRes_data[], const real_T problemDef_backs_data[], const
    real_T problemDef_shifts_data[], const real_T problemDef_sf_data[], const
    real_T problemDef_nba_data[], const real_T problemDef_nbs_data[], const
    real_T problemDef_res_data[], const int32_T problemDef_params_size[2], const
    cell_18 *problemDef_cells, const struct2_T *controls, struct4_T *problem, ::
    coder::array<cell_wrap_9, 1U> &reflectivity, ::coder::array<cell_wrap_9, 1U>
    &Simulation, ::coder::array<cell_wrap_14, 1U> &shifted_data, ::coder::array<
    cell_wrap_10, 1U> &layerSlds, ::coder::array<cell_wrap_14, 1U> &sldProfiles,
    ::coder::array<cell_wrap_14, 1U> &allLayers)
  {
    ::coder::array<cell_wrap_12, 1U> r;
    ::coder::array<cell_wrap_12, 1U> r1;
    ::coder::array<cell_wrap_35, 1U> r2;
    int32_T loop_ub_tmp;

    //  This function decides on parallelisation options before calling the
    //  relevant version of the main custom XY calculation. It is more
    //  efficient to have multiple versions of the core calculation, each dealing
    //  with a different scheme for paralellisation. These are:
    //  single    - single threaded teflectivity calculation
    //  points    - parallelise over points in the reflectivity calculation
    //  contrasts - parallelise over contrasts.
    //  Pre-allocation - It's necessary to
    //  pre-allocate the memory for all the arrays
    //  for compilation, so do this in this block.
    loop_ub_tmp = static_cast<int32_T>(problemDef_numberOfContrasts);
    problem->ssubs.set_size(loop_ub_tmp);
    problem->backgrounds.set_size(loop_ub_tmp);
    problem->qshifts.set_size(loop_ub_tmp);
    problem->scalefactors.set_size(loop_ub_tmp);
    problem->nbairs.set_size(loop_ub_tmp);
    problem->nbsubs.set_size(loop_ub_tmp);
    problem->calculations.all_chis.set_size(loop_ub_tmp);
    problem->resolutions.set_size(loop_ub_tmp);
    problem->allSubRough.set_size(loop_ub_tmp);
    reflectivity.set_size(loop_ub_tmp);
    Simulation.set_size(loop_ub_tmp);
    shifted_data.set_size(loop_ub_tmp);
    layerSlds.set_size(loop_ub_tmp);
    sldProfiles.set_size(loop_ub_tmp);
    allLayers.set_size(loop_ub_tmp);
    for (int32_T i{0}; i < loop_ub_tmp; i++) {
      problem->ssubs[i] = 0.0;
      problem->backgrounds[i] = 0.0;
      problem->qshifts[i] = 0.0;
      problem->scalefactors[i] = 0.0;
      problem->nbairs[i] = 0.0;
      problem->nbsubs[i] = 0.0;
      problem->calculations.all_chis[i] = 0.0;
      problem->resolutions[i] = 0.0;
      problem->allSubRough[i] = 0.0;
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
      for (int32_T b_i{0}; b_i < 3; b_i++) {
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
      allLayers[i].f1.set_size(2, 1);
      allLayers[i].f1[0] = 1.0;
      allLayers[i].f1[1] = 1.0;
    }

    if (coder::internal::f_strcmp(controls->para.data, controls->para.size)) {
      loop_ub_tmp = 0;
    } else if (coder::internal::g_strcmp(controls->para.data,
                controls->para.size)) {
      loop_ub_tmp = 1;
    } else if (coder::internal::h_strcmp(controls->para.data,
                controls->para.size)) {
      loop_ub_tmp = 2;
    } else {
      loop_ub_tmp = -1;
    }

    switch (loop_ub_tmp) {
     case 0:
      standardTF_custXY_single(problemDef_contrastBacks_data,
        problemDef_contrastBacksType_data, problemDef_dataPresent_data,
        problemDef_numberOfContrasts, problemDef_contrastShifts_data,
        problemDef_contrastScales_data, problemDef_contrastNbas_data,
        problemDef_contrastNbss_data, problemDef_contrastRes_data,
        problemDef_backs_data, problemDef_shifts_data, problemDef_sf_data,
        problemDef_nba_data, problemDef_nbs_data, problemDef_res_data,
        problemDef_params_size, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
      break;

     case 1:
      standardTF_custXY_paraPoints(problemDef_contrastBacks_data,
        problemDef_contrastBacksType_data, problemDef_dataPresent_data,
        problemDef_numberOfContrasts, problemDef_contrastShifts_data,
        problemDef_contrastScales_data, problemDef_contrastNbas_data,
        problemDef_contrastNbss_data, problemDef_contrastRes_data,
        problemDef_backs_data, problemDef_shifts_data, problemDef_sf_data,
        problemDef_nba_data, problemDef_nbs_data, problemDef_res_data,
        problemDef_params_size, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, reflectivity, Simulation, shifted_data,
        layerSlds, sldProfiles, allLayers, problem->allSubRough);
      break;

     case 2:
      standardTF_custXY_paraContrasts(problemDef_contrastBacks_data,
        problemDef_contrastBacksType_data, problemDef_dataPresent_data,
        problemDef_numberOfContrasts, problemDef_contrastShifts_data,
        problemDef_contrastScales_data, problemDef_contrastNbas_data,
        problemDef_contrastNbss_data, problemDef_contrastRes_data,
        problemDef_backs_data, problemDef_shifts_data, problemDef_sf_data,
        problemDef_nba_data, problemDef_nbs_data, problemDef_res_data,
        problemDef_params_size, problemDef_cells, controls, problem->ssubs,
        problem->backgrounds, problem->qshifts, problem->scalefactors,
        problem->nbairs, problem->nbsubs, problem->resolutions,
        problem->calculations.all_chis, r, r1, shifted_data, layerSlds,
        sldProfiles, r2, problem->allSubRough);
      cast(r, reflectivity);
      cast(r1, Simulation);
      cast(r2, allLayers);
      break;
    }

    problem->calculations.sum_chi = coder::sum(problem->calculations.all_chis);
    problem->resample.set_size(1, problem->allSubRough.size(0));
    loop_ub_tmp = problem->allSubRough.size(0);
    for (int32_T b_i{0}; b_i < loop_ub_tmp; b_i++) {
      problem->resample[b_i] = 1.0;
    }
  }
}

//
// File trailer for standardTF_custXY_reflectivityCalculation.cpp
//
// [EOF]
//
