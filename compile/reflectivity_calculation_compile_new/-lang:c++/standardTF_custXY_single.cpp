//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: standardTF_custXY_single.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "standardTF_custXY_single.h"
#include "applyBackgroundCorrection.h"
#include "backSort.h"
#include "callReflectivity.h"
#include "chiSquared.h"
#include "loopCppCustlayWrapper_CustLaysingle.h"
#include "loopMatalbCustlayWrapper_XYSingle.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_rtwutil.h"
#include "reflectivity_calculation_types.h"
#include "resampleLayers.h"
#include "rt_nonfinite.h"
#include "shiftdata.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
//
// Extract individual cell arrays
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
//                ::coder::array<real_T, 1U> &outSsubs
//                ::coder::array<real_T, 1U> &backgs
//                ::coder::array<real_T, 1U> &qshifts
//                ::coder::array<real_T, 1U> &sfs
//                ::coder::array<real_T, 1U> &nbas
//                ::coder::array<real_T, 1U> &nbss
//                ::coder::array<real_T, 1U> &resols
//                ::coder::array<real_T, 1U> &chis
//                ::coder::array<cell_wrap_9, 1U> &reflectivity
//                ::coder::array<cell_wrap_9, 1U> &Simulation
//                ::coder::array<cell_wrap_14, 1U> &shifted_data
//                ::coder::array<cell_wrap_10, 1U> &layerSlds
//                ::coder::array<cell_wrap_14, 1U> &sldProfiles
//                ::coder::array<cell_wrap_14, 1U> &allLayers
//                ::coder::array<real_T, 1U> &allRoughs
// Return Type  : void
//
namespace RAT
{
  void standardTF_custXY_single(const real_T problemDef_contrastBacks_data[],
    const real_T problemDef_contrastBacksType_data[], const real_T
    problemDef_dataPresent_data[], real_T problemDef_numberOfContrasts, const
    real_T problemDef_contrastShifts_data[], const real_T
    problemDef_contrastScales_data[], const real_T problemDef_contrastNbas_data[],
    const real_T problemDef_contrastNbss_data[], const real_T
    problemDef_contrastRes_data[], const real_T problemDef_backs_data[], const
    real_T problemDef_shifts_data[], const real_T problemDef_sf_data[], const
    real_T problemDef_nba_data[], const real_T problemDef_nbs_data[], const
    real_T problemDef_res_data[], const int32_T problemDef_params_size[2], const
    cell_18 *problemDef_cells, const struct2_T *controls, ::coder::array<real_T,
    1U> &outSsubs, ::coder::array<real_T, 1U> &backgs, ::coder::array<real_T, 1U>
    &qshifts, ::coder::array<real_T, 1U> &sfs, ::coder::array<real_T, 1U> &nbas,
    ::coder::array<real_T, 1U> &nbss, ::coder::array<real_T, 1U> &resols, ::
    coder::array<real_T, 1U> &chis, ::coder::array<cell_wrap_9, 1U>
    &reflectivity, ::coder::array<cell_wrap_9, 1U> &Simulation, ::coder::array<
    cell_wrap_14, 1U> &shifted_data, ::coder::array<cell_wrap_10, 1U> &layerSlds,
    ::coder::array<cell_wrap_14, 1U> &sldProfiles, ::coder::array<cell_wrap_14,
    1U> &allLayers, ::coder::array<real_T, 1U> &allRoughs)
  {
    ::coder::array<cell_wrap_1, 1U> r;
    ::coder::array<cell_wrap_14, 1U> sldProf;
    ::coder::array<real_T, 2U> layerSld;
    ::coder::array<real_T, 2U> reflect;
    real_T shifted_dat_data[5000];
    int32_T problemDef_cells_size[2];
    int32_T b_index;
    int32_T loop_ub_tmp;

    //  Splits up the master input list of all arrays into separate arrays
    //  The min input array 'problemDef_cells' is a master array where
    //  all the cell arrays are grouped together. There are
    //  repeatLayers      - controls repeating of the layers stack
    //  allData           - Array of all the data arrays
    //  dataLimits        - Min max limits in q for the data arrays
    //  simLimits         - Limits in Q for the reflkectivity simulations
    //  Layers details    - Master array of all available layers
    //  contrastLayers    - Which specific combination of arrays are needed for
    //                      each contrast.
    //  Custom files      - Filenames and path for any custom files used
    //  Extract individual parameters from problemDef struct
    // Extract individual parameters from problemDef
    // Pre-Allocation...
    loop_ub_tmp = static_cast<int32_T>(problemDef_numberOfContrasts);
    backgs.set_size(loop_ub_tmp);
    allRoughs.set_size(loop_ub_tmp);
    outSsubs.set_size(loop_ub_tmp);
    sldProf.set_size(loop_ub_tmp);
    sldProfiles.set_size(loop_ub_tmp);
    for (int32_T i{0}; i < loop_ub_tmp; i++) {
      allRoughs[i] = 0.0;
      outSsubs[i] = 0.0;
      sldProf[i].f1.set_size(2, 1);
      sldProf[i].f1[0] = 1.0;
      sldProf[i].f1[1] = 1.0;
      sldProfiles[i].f1.set_size(2, 1);
      sldProfiles[i].f1[0] = 1.0;
      sldProfiles[i].f1[1] = 1.0;
    }

    //  Resampling parameters
    //  Process the custom models. These can either be as a Matlab script, or a
    //  user generated DLL
    if (coder::internal::j_strcmp(problemDef_cells->f14[0].f1[1].f1.data,
         problemDef_cells->f14[0].f1[1].f1.size)) {
      b_index = 0;
    } else if (coder::internal::k_strcmp(problemDef_cells->f14[0].f1[1].f1.data,
                problemDef_cells->f14[0].f1[1].f1.size)) {
      b_index = 1;
    } else {
      b_index = -1;
    }

    switch (b_index) {
     case 0:
      //  Call the Matlab parallel loop to process the custom models.....
      loopMatalbCustlayWrapper_XYSingle(problemDef_numberOfContrasts, sldProf,
        allRoughs);
      break;

     case 1:
      loopCppCustlayWrapper_CustLaysingle(problemDef_numberOfContrasts, r,
        allRoughs);
      cast(r, sldProf);
      break;
    }

    qshifts.set_size(loop_ub_tmp);
    sfs.set_size(loop_ub_tmp);
    nbas.set_size(loop_ub_tmp);
    nbss.set_size(loop_ub_tmp);
    resols.set_size(loop_ub_tmp);
    layerSlds.set_size(loop_ub_tmp);
    allLayers.set_size(loop_ub_tmp);
    shifted_data.set_size(loop_ub_tmp);
    chis.set_size(loop_ub_tmp);
    Simulation.set_size(loop_ub_tmp);
    reflectivity.set_size(loop_ub_tmp);
    for (int32_T i{0}; i < loop_ub_tmp; i++) {
      real_T problemDef_cells_data[5000];
      int32_T shifted_dat_size[2];
      int32_T loop_ub;
      backSort(problemDef_contrastBacks_data[i],
               problemDef_contrastShifts_data[i],
               problemDef_contrastScales_data[i], problemDef_contrastNbas_data[i],
               problemDef_contrastNbss_data[i], problemDef_contrastRes_data[i],
               problemDef_backs_data, problemDef_shifts_data, problemDef_sf_data,
               problemDef_nba_data, problemDef_nbs_data, problemDef_res_data,
               &backgs[i], &qshifts[i], &sfs[i], &nbas[i], &nbss[i], &resols[i]);
      b_index = sldProf[i].f1.size(1);
      sldProfiles[i].f1.set_size(sldProf[i].f1.size(0), sldProf[i].f1.size(1));
      for (int32_T b_i{0}; b_i < b_index; b_i++) {
        loop_ub = sldProf[i].f1.size(0);
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * b_i] = sldProf[i].
            f1[i1 + sldProf[i].f1.size(0) * b_i];
        }
      }

      shifted_dat_size[0] = (*(int32_T (*)[2])sldProfiles[i].f1.size())[0];
      shifted_dat_size[1] = (*(int32_T (*)[2])sldProfiles[i].f1.size())[1];
      resampleLayers((const real_T *)sldProfiles[i].f1.data(), shifted_dat_size,
                     controls->resamPars, layerSld);
      layerSlds[i].f1.set_size(layerSld.size(0), 3);
      allLayers[i].f1.set_size(layerSld.size(0), 3);
      b_index = layerSld.size(0);
      for (int32_T b_i{0}; b_i < 3; b_i++) {
        for (int32_T i1{0}; i1 < b_index; i1++) {
          layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * b_i] = layerSld[i1 +
            layerSld.size(0) * b_i];
          allLayers[i].f1[i1 + allLayers[i].f1.size(0) * b_i] = layerSld[i1 +
            layerSld.size(0) * b_i];
        }
      }

      problemDef_cells_size[0] = problemDef_cells->f2.data[i].f1.size(0);
      problemDef_cells_size[1] = problemDef_cells->f2.data[i].f1.size(1);
      b_index = problemDef_cells->f2.data[i].f1.size(1) - 1;
      for (int32_T b_i{0}; b_i <= b_index; b_i++) {
        loop_ub = problemDef_cells->f2.data[i].f1.size(0) - 1;
        for (int32_T i1{0}; i1 <= loop_ub; i1++) {
          problemDef_cells_data[i1 + problemDef_cells_size[0] * b_i] =
            problemDef_cells->f2.data[i].f1[i1 + problemDef_cells->f2.data[i].
            f1.size(0) * b_i];
        }
      }

      shiftdata(sfs[i], qshifts[i], problemDef_dataPresent_data[i],
                problemDef_cells_data, problemDef_cells_size,
                problemDef_cells->f3.data[i].f1, (const real_T *)((::coder::
                  array<real_T, 2U> *)&problemDef_cells->f4.data[i].f1)->data(),
                shifted_dat_data, shifted_dat_size);
      b_index = shifted_dat_size[1];
      shifted_data[i].f1.set_size(shifted_dat_size[0], shifted_dat_size[1]);
      for (int32_T b_i{0}; b_i < b_index; b_i++) {
        loop_ub = shifted_dat_size[0];
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          shifted_data[i].f1[i1 + shifted_data[i].f1.size(0) * b_i] =
            shifted_dat_data[i1 + shifted_dat_size[0] * b_i];
        }
      }

      callReflectivity(nbas[i], nbss[i], (const real_T *)((::coder::array<real_T,
        2U> *)&problemDef_cells->f4.data[i].f1)->data(),
                       problemDef_cells->f1.data[i].f1, shifted_dat_data,
                       shifted_dat_size, layerSld, 0.0, resols[i], reflect,
                       Simulation[i].f1);
      applyBackgroundCorrection(reflect, Simulation[i].f1, shifted_dat_data,
        shifted_dat_size, backgs[i], problemDef_contrastBacksType_data[i]);
      b_index = reflect.size(0);
      reflectivity[i].f1.set_size(reflect.size(0), 2);
      for (int32_T b_i{0}; b_i < 2; b_i++) {
        for (int32_T i1{0}; i1 < b_index; i1++) {
          reflectivity[i].f1[i1 + reflectivity[i].f1.size(0) * b_i] = reflect[i1
            + reflect.size(0) * b_i];
        }
      }

      if (problemDef_dataPresent_data[i] != 0.0) {
        chis[i] = chiSquared(shifted_dat_data, shifted_dat_size, reflect,
                             static_cast<real_T>(problemDef_params_size[1]));
      } else {
        chis[i] = 0.0;
      }
    }
  }
}

//
// File trailer for standardTF_custXY_single.cpp
//
// [EOF]
//
