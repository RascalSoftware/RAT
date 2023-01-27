//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: standardTF_stanlay_paraPoints.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//

// Include Files
#include "standardTF_stanlay_paraPoints.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "reflectivity_calculation_internal_types.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "standardTF_layers_core.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
//
// Standard Layers calculation paralelised over the inner loop
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
  void standardTF_stanlay_paraPoints(const struct0_T *problemDef, const cell_18 *
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
    static cell_wrap_19 outParameterisedLayers_data[1000];
    ::coder::array<real_T, 2U> resampledLayers;
    ::coder::array<real_T, 2U> sldProfile;
    real_T shifted_dat_data[5000];
    real_T thisContrastLayers_data[5000];
    real_T layerSld_data[3000];
    real_T thisBackground;
    real_T thisNba;
    real_T thisNbs;
    real_T thisQshift;
    real_T thisResol;
    real_T thisSf;
    int32_T layerSld_size[2];
    int32_T outParameterisedLayers_size[2];
    int32_T shifted_dat_size[2];
    int32_T i;

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
    //  Allocate the memory for the output arrays before the main loop
    i = static_cast<int32_T>(problemDef->numberOfContrasts);
    backgs.set_size(i);

    //  end memory allocation.
    //  First we need to allocate the absolute values of the input
    //  parameters to all the layers in the layers list. This only needs
    //  to be done once, and so is done outside the contrasts loop
    allocateParamsToLayers(problemDef->params.data, problemDef_cells->f6.data,
      &problemDef_cells->f6.size[0], outParameterisedLayers_data,
      outParameterisedLayers_size);

    //  Resample params if required
    //  Loop over all the contrasts
    outSsubs.set_size(i);
    sldProfiles.set_size(i);
    reflectivity.set_size(i);
    Simulation.set_size(i);
    shifted_data.set_size(i);
    layerSlds.set_size(i);
    chis.set_size(i);
    qshifts.set_size(i);
    sfs.set_size(i);
    nbas.set_size(i);
    nbss.set_size(i);
    resols.set_size(i);
    allRoughs.set_size(i);
    allLayers.set_size(i);
    for (int32_T b_i{0}; b_i < i; b_i++) {
      int32_T iv[2];
      int32_T b_loop_ub;
      int32_T loop_ub;

      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(problemDef->contrastBacks.data[b_i],
               problemDef->contrastShifts.data[b_i],
               problemDef->contrastScales.data[b_i],
               problemDef->contrastNbas.data[b_i], problemDef->
               contrastNbss.data[b_i], problemDef->contrastRes.data[b_i],
               problemDef->backs.data, problemDef->shifts.data,
               problemDef->sf.data, problemDef->nba.data, problemDef->nbs.data,
               problemDef->res.data, &thisBackground, &thisQshift, &thisSf,
               &thisNba, &thisNbs, &thisResol);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry
      iv[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f5.data[b_i].f1)->size())[0];
      iv[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f5.data[b_i].f1)->size())[1];
      allocateLayersForContrast((const real_T *)((::coder::array<real_T, 2U> *)
        &problemDef_cells->f5.data[b_i].f1)->data(), iv,
        outParameterisedLayers_data, thisContrastLayers_data,
        outParameterisedLayers_size);

      //  For the other parameters, we extract the correct ones from the input
      //  arrays
      //  Substrate roughness is always first parameter for standard layers
      //  Now call the core standardTF_stanlay reflectivity calculation
      //  In this case we are single cored, so we do not parallelise over
      //  points
      //  Call the core layers calculation
      iv[0] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f2.data[b_i].f1)->size())[0];
      iv[1] = (*(int32_T (*)[2])((::coder::array<real_T, 2U> *)
                &problemDef_cells->f2.data[b_i].f1)->size())[1];
      b_standardTF_layers_core(thisContrastLayers_data,
        outParameterisedLayers_size, problemDef->params.data[0],
        problemDef->geometry.data, problemDef->geometry.size, thisNba, thisNbs,
        problemDef->resample.data[b_i], controls->calcSld, thisSf, thisQshift,
        problemDef->dataPresent.data[b_i], (const real_T *)((::coder::array<
        real_T, 2U> *)&problemDef_cells->f2.data[b_i].f1)->data(), iv,
        problemDef_cells->f3.data[b_i].f1, (const real_T *)((::coder::array<
        real_T, 2U> *)&problemDef_cells->f4.data[b_i].f1)->data(),
        problemDef_cells->f1.data[b_i].f1, thisBackground, thisResol,
        problemDef->contrastBacksType.data[b_i], static_cast<real_T>
        (problemDef->params.size[1]), controls->resamPars, sldProfile,
        reflectivity[b_i].f1, Simulation[b_i].f1, shifted_dat_data,
        shifted_dat_size, layerSld_data, layerSld_size, resampledLayers,
        &chis[b_i], &outSsubs[b_i]);

      //  Store returned values for this contrast in the output arrays.
      //  As well as the calculated profiles, we also store a record of
      //  the other values (background, scalefactors etc) for each contrast
      //  for future use.
      loop_ub = sldProfile.size(0);
      sldProfiles[b_i].f1.set_size(sldProfile.size(0), 2);
      for (int32_T i1{0}; i1 < 2; i1++) {
        for (int32_T i2{0}; i2 < loop_ub; i2++) {
          sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] =
            sldProfile[i2 + sldProfile.size(0) * i1];
        }
      }

      loop_ub = shifted_dat_size[1];
      shifted_data[b_i].f1.set_size(shifted_dat_size[0], shifted_dat_size[1]);
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        b_loop_ub = shifted_dat_size[0];
        for (int32_T i2{0}; i2 < b_loop_ub; i2++) {
          shifted_data[b_i].f1[i2 + shifted_data[b_i].f1.size(0) * i1] =
            shifted_dat_data[i2 + shifted_dat_size[0] * i1];
        }
      }

      loop_ub = layerSld_size[0];
      layerSlds[b_i].f1.set_size(layerSld_size[0], 3);
      backgs[b_i] = thisBackground;
      qshifts[b_i] = thisQshift;
      sfs[b_i] = thisSf;
      nbas[b_i] = thisNba;
      nbss[b_i] = thisNbs;
      resols[b_i] = thisResol;
      allRoughs[b_i] = problemDef->params.data[0];
      b_loop_ub = resampledLayers.size(0);
      allLayers[b_i].f1.set_size(resampledLayers.size(0), 3);
      for (int32_T i1{0}; i1 < 3; i1++) {
        for (int32_T i2{0}; i2 < loop_ub; i2++) {
          layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] =
            layerSld_data[i2 + layerSld_size[0] * i1];
        }

        for (int32_T i2{0}; i2 < b_loop_ub; i2++) {
          allLayers[b_i].f1[i2 + allLayers[b_i].f1.size(0) * i1] =
            resampledLayers[i2 + resampledLayers.size(0) * i1];
        }
      }
    }
  }
}

//
// File trailer for standardTF_stanlay_paraPoints.cpp
//
// [EOF]
//
