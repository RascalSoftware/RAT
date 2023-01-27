//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: standardTF_custlay_paraPoints.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "standardTF_custlay_paraPoints.h"
#include "backSort.h"
#include "loopCppCustlayWrapper_CustLaysingle.h"
#include "loopMatalbCustlayWrapper_CustLaysingle.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_rtwutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
//
// Multi threaded version of the custom layers over reflectivity poimnts
//  for standardTF reflectivity calculation.
//  The function extracts the relevant parameters from the input
//  arrays, allocates these on a pre-contrast basis, then calls the 'core'
//  calculation (the core layers standardTf calc is shared between multiple
//  calculation types).
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
  void standardTF_custlay_paraPoints(const struct0_T *problemDef, const cell_18 *
    problemDef_cells, const struct2_T *controls, ::coder::array<real_T, 1U>
    &outSsubs, ::coder::array<real_T, 1U> &backgs, ::coder::array<real_T, 1U>
    &qshifts, ::coder::array<real_T, 1U> &sfs, ::coder::array<real_T, 1U> &nbas,
    ::coder::array<real_T, 1U> &nbss, ::coder::array<real_T, 1U> &resols, ::
    coder::array<real_T, 1U> &chis, ::coder::array<cell_wrap_9, 1U>
    &reflectivity, ::coder::array<cell_wrap_9, 1U> &Simulation, ::coder::array<
    cell_wrap_14, 1U> &shifted_data, ::coder::array<cell_wrap_10, 1U> &layerSlds,
    ::coder::array<cell_wrap_14, 1U> &sldProfiles, ::coder::array<cell_wrap_14,
    1U> &allLayers, ::coder::array<real_T, 1U> &allRoughs)
  {
    ::coder::array<cell_wrap_1, 1U> r;
    ::coder::array<real_T, 2U> resamLayers;
    ::coder::array<real_T, 2U> sldProfile;
    real_T shifted_dat_data[5000];
    real_T thisBackground;
    real_T thisNba;
    real_T thisNbs;
    real_T thisQshift;
    real_T thisResol;
    real_T thisSf;
    int32_T shifted_dat_size[2];
    int32_T b_index;
    int32_T loop_ub_tmp;

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
    //  Pre-Allocation of output arrays...
    //    --- Begin Memory Allocation ---
    loop_ub_tmp = static_cast<int32_T>(problemDef->numberOfContrasts);
    backgs.set_size(loop_ub_tmp);
    allRoughs.set_size(loop_ub_tmp);
    allLayers.set_size(loop_ub_tmp);
    for (int32_T i{0}; i < loop_ub_tmp; i++) {
      allRoughs[i] = 0.0;
      allLayers[i].f1.set_size(2, 1);
      allLayers[i].f1[0] = 1.0;
      allLayers[i].f1[1] = 1.0;
    }

    //    --- End Memory Allocation ---
    //  Depending on custom layer language we change the functions used
    //  so if there are multiple language models we should have a variable that seeks what language model is being used
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
      loopMatalbCustlayWrapper_CustLaysingle(problemDef->numberOfContrasts,
        allLayers, allRoughs);

      //
      break;

     case 1:
      loopCppCustlayWrapper_CustLaysingle(problemDef->numberOfContrasts, r,
        allRoughs);
      cast(r, allLayers);
      break;
    }

    //  Single cored over all contrasts
    outSsubs.set_size(loop_ub_tmp);
    sldProfiles.set_size(loop_ub_tmp);
    reflectivity.set_size(loop_ub_tmp);
    Simulation.set_size(loop_ub_tmp);
    shifted_data.set_size(loop_ub_tmp);
    layerSlds.set_size(loop_ub_tmp);
    chis.set_size(loop_ub_tmp);
    qshifts.set_size(loop_ub_tmp);
    sfs.set_size(loop_ub_tmp);
    nbas.set_size(loop_ub_tmp);
    nbss.set_size(loop_ub_tmp);
    resols.set_size(loop_ub_tmp);
    for (int32_T i{0}; i < loop_ub_tmp; i++) {
      int32_T iv[2];

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

      //  Call the custom layers function to get the layers array...
      //  For the other parameters, we extract the correct ones from the input
      //  arrays
      //  Now call the core standardTF_stanlay reflectivity calculation
      //  In this case we are single cored, so we do not parallelise over
      //  points
      //  Call the reflectivity calculation
      iv[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f2.data[i].f1)->size())[0];
      iv[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f2.data[i].f1)->size())[1];
      b_standardTF_layers_core(allLayers[i].f1, allRoughs[i],
        problemDef->geometry.data, problemDef->geometry.size, thisNba, thisNbs,
        problemDef->resample.data[i], controls->calcSld, thisSf, thisQshift,
        problemDef->dataPresent.data[i], (const real_T *)((::coder::array<real_T,
        2U> *)&problemDef_cells->f2.data[i].f1)->data(), iv,
        problemDef_cells->f3.data[i].f1, (const real_T *)((::coder::array<real_T,
        2U> *)&problemDef_cells->f4.data[i].f1)->data(),
        problemDef_cells->f1.data[i].f1, thisBackground, thisResol,
        problemDef->contrastBacksType.data[i], static_cast<real_T>
        (problemDef->params.size[1]), controls->resamPars, sldProfile,
        reflectivity[i].f1, Simulation[i].f1, shifted_dat_data, shifted_dat_size,
        layerSlds[i].f1, resamLayers, &chis[i], &outSsubs[i]);

      //  Store returned values for this contrast in the output arrays.
      //  As well as the calculated profiles, we also store a record of
      //  the other values (background, scalefactors etc) for each contrast
      //  for future use.
      b_index = sldProfile.size(0);
      sldProfiles[i].f1.set_size(sldProfile.size(0), 2);
      for (int32_T b_i{0}; b_i < 2; b_i++) {
        for (int32_T i1{0}; i1 < b_index; i1++) {
          sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * b_i] =
            sldProfile[i1 + sldProfile.size(0) * b_i];
        }
      }

      b_index = shifted_dat_size[1];
      shifted_data[i].f1.set_size(shifted_dat_size[0], shifted_dat_size[1]);
      for (int32_T b_i{0}; b_i < b_index; b_i++) {
        int32_T loop_ub;
        loop_ub = shifted_dat_size[0];
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          shifted_data[i].f1[i1 + shifted_data[i].f1.size(0) * b_i] =
            shifted_dat_data[i1 + shifted_dat_size[0] * b_i];
        }
      }

      b_index = resamLayers.size(0);
      allLayers[i].f1.set_size(resamLayers.size(0), 3);
      for (int32_T b_i{0}; b_i < 3; b_i++) {
        for (int32_T i1{0}; i1 < b_index; i1++) {
          allLayers[i].f1[i1 + allLayers[i].f1.size(0) * b_i] = resamLayers[i1 +
            resamLayers.size(0) * b_i];
        }
      }

      backgs[i] = thisBackground;
      qshifts[i] = thisQshift;
      sfs[i] = thisSf;
      nbas[i] = thisNba;
      nbss[i] = thisNbs;
      resols[i] = thisResol;
    }
  }
}

//
// File trailer for standardTF_custlay_paraPoints.cpp
//
// [EOF]
//
