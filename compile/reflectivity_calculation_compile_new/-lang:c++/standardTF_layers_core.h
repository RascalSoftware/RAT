//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: standardTF_layers_core.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef STANDARDTF_LAYERS_CORE_H
#define STANDARDTF_LAYERS_CORE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void b_standardTF_layers_core(const real_T contrastLayers_data[], const
    int32_T contrastLayers_size[2], real_T rough, const char_T geometry_data[],
    const int32_T geometry_size[2], real_T nba, real_T nbs, real_T resample,
    real_T calcSld, real_T sf, real_T qshift, real_T dataPresent, const real_T
    data_data[], const int32_T data_size[2], const real_T dataLimits[2], const
    real_T simLimits_data[], const real_T repeatLayers[2], real_T background,
    real_T resol, real_T backsType, real_T params, const real_T resamPars[2], ::
    coder::array<real_T, 2U> &sldProfile, ::coder::array<real_T, 2U> &reflect, ::
    coder::array<real_T, 2U> &Simul, real_T shifted_dat_data[], int32_T
    shifted_dat_size[2], real_T theseLayers_data[], int32_T theseLayers_size[2],
    ::coder::array<real_T, 2U> &resamLayers, real_T *chiSq, real_T *ssubs);
  void b_standardTF_layers_core(const ::coder::array<real_T, 2U> &contrastLayers,
    real_T rough, const char_T geometry_data[], const int32_T geometry_size[2],
    real_T nba, real_T nbs, real_T resample, real_T calcSld, real_T sf, real_T
    qshift, real_T dataPresent, const real_T data_data[], const int32_T
    data_size[2], const real_T dataLimits[2], const real_T simLimits_data[],
    const real_T repeatLayers[2], real_T background, real_T resol, real_T
    backsType, real_T params, const real_T resamPars[2], ::coder::array<real_T,
    2U> &sldProfile, ::coder::array<real_T, 2U> &reflect, ::coder::array<real_T,
    2U> &Simul, real_T shifted_dat_data[], int32_T shifted_dat_size[2], ::coder::
    array<real_T, 2U> &theseLayers, ::coder::array<real_T, 2U> &resamLayers,
    real_T *chiSq, real_T *ssubs);
  void standardTF_layers_core(const real_T contrastLayers_data[], const int32_T
    contrastLayers_size[2], real_T rough, const char_T geometry_data[], const
    int32_T geometry_size[2], real_T nba, real_T nbs, real_T resample, real_T
    calcSld, real_T sf, real_T qshift, real_T dataPresent, const real_T
    data_data[], const int32_T data_size[2], const real_T dataLimits[2], const
    real_T simLimits_data[], const real_T repeatLayers[2], real_T background,
    real_T resol, real_T backsType, real_T params, const real_T resamPars[2], ::
    coder::array<real_T, 2U> &sldProfile, ::coder::array<real_T, 2U> &reflect, ::
    coder::array<real_T, 2U> &Simul, real_T shifted_dat_data[], int32_T
    shifted_dat_size[2], real_T theseLayers_data[], int32_T theseLayers_size[2],
    ::coder::array<real_T, 2U> &resamLayers, real_T *chiSq, real_T *ssubs);
  void standardTF_layers_core(const ::coder::array<real_T, 2U> &contrastLayers,
    real_T rough, const char_T geometry_data[], const int32_T geometry_size[2],
    real_T nba, real_T nbs, real_T resample, real_T calcSld, real_T sf, real_T
    qshift, real_T dataPresent, const real_T data_data[], const int32_T
    data_size[2], const real_T dataLimits[2], const real_T simLimits_data[],
    const real_T repeatLayers[2], real_T background, real_T resol, real_T
    backsType, real_T params, const real_T resamPars[2], ::coder::array<real_T,
    2U> &sldProfile, ::coder::array<real_T, 2U> &reflect, ::coder::array<real_T,
    2U> &Simul, real_T shifted_dat_data[], int32_T shifted_dat_size[2], ::coder::
    array<real_T, 2U> &theseLayers, ::coder::array<real_T, 2U> &resamLayers,
    real_T *chiSq, real_T *ssubs);
}

#endif

//
// File trailer for standardTF_layers_core.h
//
// [EOF]
//
