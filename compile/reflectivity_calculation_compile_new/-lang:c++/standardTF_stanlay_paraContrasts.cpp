//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: standardTF_stanlay_paraContrasts.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "standardTF_stanlay_paraContrasts.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"

// Function Definitions
//
// Standard Layers calculation paralelised over the outer loop
//  This is the main reflectivity calculation of the standard layers
//  calculation type. It extracts the required paramters for the contrasts
//  from the input arrays, then passes the main calculation to
//  'standardLayersCore', which carries out the calculation iteslf.
//  The core calculation is common for both standard and custom layers.
//
// Arguments    : const struct0_T *problemDef
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
  void standardTF_stanlay_paraContrasts(const struct0_T *problemDef, const
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
    static cell_wrap_19 outParameterisedLayers_data[1000];
    ::coder::array<real_T, 2U> Simul;
    ::coder::array<real_T, 2U> reflect;
    ::coder::array<real_T, 2U> resampledLayers;
    ::coder::array<real_T, 2U> sldProfile;
    real_T shifted_dat_data[5000];
    real_T thisContrastLayers_data[5000];
    real_T layerSld_data[3000];
    real_T calcSld;
    real_T thisBackground;
    real_T thisChiSquared;
    real_T thisNba;
    real_T thisNbs;
    real_T thisQshift;
    real_T thisResol;
    real_T thisSf;
    real_T thisSsubs;
    int32_T iv[2];
    int32_T layerSld_size[2];
    int32_T outParameterisedLayers_size[2];
    int32_T shifted_dat_size[2];
    int32_T thisContrastLayers_size[2];
    int32_T b_i;
    int32_T b_loop_ub;
    int32_T c_loop_ub;
    int32_T i1;
    int32_T loop_ub;
    int32_T nParams;
    int32_T ub_loop;

    //  Extract individual cell arrays
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
    nParams = problemDef->params.size[1];
    calcSld = controls->calcSld;

    //  Allocate the memory for the output arrays before the main loop
    backgs.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));

    //  end memory allocation.
    //  First we need to allocate the absolute values of the input
    //  parameters to all the layers in the layers list. This only needs
    //  to be done once, and so is done outside the contrasts loop
    allocateParamsToLayers(problemDef->params.data, problemDef_cells->f6.data,
      &problemDef_cells->f6.size[0], outParameterisedLayers_data,
      outParameterisedLayers_size);

    //  Resample parameters is required
    //  Parallel loop over all the contrasts
    outSsubs.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    sldProfiles.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    reflectivity.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    Simulation.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    shifted_data.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    layerSlds.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    chis.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    qshifts.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    sfs.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    nbas.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    nbss.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    resols.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    allRoughs.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    allLayers.set_size(static_cast<int32_T>(problemDef->numberOfContrasts));
    ub_loop = static_cast<int32_T>(problemDef->numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(sldProfile,reflect,Simul,resampledLayers,thisSsubs,thisChiSquared,layerSld_data,layerSld_size,shifted_dat_data,shifted_dat_size,thisContrastLayers_data,thisContrastLayers_size,thisResol,thisNbs,thisNba,thisSf,thisQshift,thisBackground,iv,loop_ub,b_loop_ub,c_loop_ub,b_i,i1)

    for (int32_T i = 0; i <= ub_loop; i++) {
      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(problemDef->contrastBacks.data[i],
               problemDef->contrastShifts.data[i],
               problemDef->contrastScales.data[i], problemDef->
               contrastNbas.data[i], problemDef->contrastNbss.data[i],
               problemDef->contrastRes.data[i], problemDef->backs.data,
               problemDef->shifts.data, problemDef->sf.data,
               problemDef->nba.data, problemDef->nbs.data, problemDef->res.data,
               &thisBackground, &thisQshift, &thisSf, &thisNba, &thisNbs,
               &thisResol);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry
      iv[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f5.data[i].f1)->size())[0];
      iv[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f5.data[i].f1)->size())[1];
      allocateLayersForContrast((const real_T *)((::coder::array<real_T, 2U> *)
        &problemDef_cells->f5.data[i].f1)->data(), iv,
        outParameterisedLayers_data, thisContrastLayers_data,
        thisContrastLayers_size);

      //  For the other parameters, we extract the correct ones from the input
      //  arrays
      //  Substrate roughness is always first parameter for standard layers
      //  Now call the core standardTF_stanlay reflectivity calculation
      //  In this case we are single cored, so we do not parallelise over
      //  points
      //  Call the core layers calculation
      iv[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f2.data[i].f1)->size())[0];
      iv[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f2.data[i].f1)->size())[1];
      standardTF_layers_core(thisContrastLayers_data, thisContrastLayers_size,
        problemDef->params.data[0], problemDef->geometry.data,
        problemDef->geometry.size, thisNba, thisNbs, problemDef->resample.data[i],
        calcSld, thisSf, thisQshift, problemDef->dataPresent.data[i], (const
        real_T *)((::coder::array<real_T, 2U> *)&problemDef_cells->f2.data[i].f1)
        ->data(), iv, problemDef_cells->f3.data[i].f1, (const real_T *)((::coder::
        array<real_T, 2U> *)&problemDef_cells->f4.data[i].f1)->data(),
        problemDef_cells->f1.data[i].f1, thisBackground, thisResol,
        problemDef->contrastBacksType.data[i], static_cast<real_T>(nParams),
        controls->resamPars, sldProfile, reflect, Simul, shifted_dat_data,
        shifted_dat_size, layerSld_data, layerSld_size, resampledLayers,
        &thisChiSquared, &thisSsubs);

      //  Store returned values for this contrast in the output arrays.
      //  As well as the calculated profiles, we also store a record of
      //  the other values (background, scalefactors etc) for each contrast
      //  for future use.
      outSsubs[i] = thisSsubs;
      loop_ub = sldProfile.size(0);
      sldProfiles[i].f1.set_size(sldProfile.size(0), 2);
      b_loop_ub = reflect.size(0);
      reflectivity[i].f1.set_size(reflect.size(0), 2);
      c_loop_ub = Simul.size(0);
      Simulation[i].f1.set_size(Simul.size(0), 2);
      for (b_i = 0; b_i < 2; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * b_i] =
            sldProfile[i1 + sldProfile.size(0) * b_i];
        }

        for (i1 = 0; i1 < b_loop_ub; i1++) {
          reflectivity[i].f1[i1 + reflectivity[i].f1.size(0) * b_i] = reflect[i1
            + reflect.size(0) * b_i];
        }

        for (i1 = 0; i1 < c_loop_ub; i1++) {
          Simulation[i].f1[i1 + Simulation[i].f1.size(0) * b_i] = Simul[i1 +
            Simul.size(0) * b_i];
        }
      }

      loop_ub = shifted_dat_size[1];
      shifted_data[i].f1.set_size(shifted_dat_size[0], shifted_dat_size[1]);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_loop_ub = shifted_dat_size[0];
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          shifted_data[i].f1[i1 + shifted_data[i].f1.size(0) * b_i] =
            shifted_dat_data[i1 + shifted_dat_size[0] * b_i];
        }
      }

      loop_ub = layerSld_size[0];
      layerSlds[i].f1.set_size(layerSld_size[0], 3);
      chis[i] = thisChiSquared;
      backgs[i] = thisBackground;
      qshifts[i] = thisQshift;
      sfs[i] = thisSf;
      nbas[i] = thisNba;
      nbss[i] = thisNbs;
      resols[i] = thisResol;
      allRoughs[i] = problemDef->params.data[0];
      b_loop_ub = resampledLayers.size(0);
      allLayers[i].f1.set_size(resampledLayers.size(0), 3);
      for (b_i = 0; b_i < 3; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * b_i] = layerSld_data[i1
            + layerSld_size[0] * b_i];
        }

        for (i1 = 0; i1 < b_loop_ub; i1++) {
          allLayers[i].f1[i1 + allLayers[i].f1.size(0) * b_i] =
            resampledLayers[i1 + resampledLayers.size(0) * b_i];
        }
      }
    }
  }
}

//
// File trailer for standardTF_stanlay_paraContrasts.cpp
//
// [EOF]
//
