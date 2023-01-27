//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
// File: reflectivity_calculation_types.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 24-Nov-2022 11:13:31
//
#ifndef REFLECTIVITY_CALCULATION_TYPES_H
#define REFLECTIVITY_CALCULATION_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#define MAX_THREADS                    omp_get_max_threads()

// Type Definitions
namespace RAT
{
  struct cell_wrap_0
  {
    real_T f1[2];
  };

  struct struct0_T
  {
    ::coder::bounded_array<real_T, 1000U, 2U> contrastBacks;
    ::coder::bounded_array<real_T, 1000U, 2U> contrastBacksType;
    ::coder::bounded_array<char_T, 1000U, 2U> TF;
    ::coder::bounded_array<real_T, 1000U, 2U> resample;
    ::coder::bounded_array<real_T, 1000U, 2U> dataPresent;
    real_T numberOfContrasts;
    ::coder::bounded_array<char_T, 1000U, 2U> geometry;
    ::coder::bounded_array<real_T, 1000U, 2U> contrastShifts;
    ::coder::bounded_array<real_T, 1000U, 2U> contrastScales;
    ::coder::bounded_array<real_T, 1000U, 2U> contrastNbas;
    ::coder::bounded_array<real_T, 1000U, 2U> contrastNbss;
    ::coder::bounded_array<real_T, 1000U, 2U> contrastRes;
    ::coder::bounded_array<real_T, 1000U, 2U> backs;
    ::coder::bounded_array<real_T, 1000U, 2U> shifts;
    ::coder::bounded_array<real_T, 1000U, 2U> sf;
    ::coder::bounded_array<real_T, 1000U, 2U> nba;
    ::coder::bounded_array<real_T, 1000U, 2U> nbs;
    ::coder::bounded_array<real_T, 1000U, 2U> res;
    ::coder::bounded_array<real_T, 1000U, 2U> params;
    real_T numberOfLayers;
    ::coder::bounded_array<char_T, 1000U, 2U> modelType;
    ::coder::bounded_array<real_T, 1000U, 2U> contrastCustomFiles;
    ::coder::array<real_T, 2U> fitpars;
    ::coder::array<real_T, 2U> otherpars;
    ::coder::array<real_T, 2U> fitconstr;
    ::coder::array<real_T, 2U> otherconstr;
  };

  struct cell_wrap_1
  {
    ::coder::bounded_array<real_T, 5000U, 2U> f1;
  };

  struct cell_wrap_2
  {
    ::coder::bounded_array<real_T, 2U, 2U> f1;
  };

  struct cell_wrap_3
  {
    ::coder::bounded_array<real_T, 1000U, 2U> f1;
  };

  struct cell_wrap_4
  {
    ::coder::bounded_array<real_T, 10U, 2U> f1;
  };

  struct cell_wrap_5
  {
    ::coder::bounded_array<char_T, 1000U, 2U> f1;
  };

  struct cell_wrap_6
  {
    ::coder::bounded_array<char_T, 1000U, 2U> f1;
  };

  struct cell_wrap_7
  {
    cell_wrap_6 f1[3];
  };

  struct cell_8
  {
    ::coder::bounded_array<cell_wrap_0, 1000U, 2U> f1;
    ::coder::array<cell_wrap_1, 2U> f2;
    ::coder::bounded_array<cell_wrap_0, 1000U, 2U> f3;
    ::coder::bounded_array<cell_wrap_2, 1000U, 2U> f4;
    ::coder::array<cell_wrap_3, 2U> f5;
    ::coder::array<cell_wrap_4, 1U> f6;
    ::coder::array<cell_wrap_5, 2U> f7;
    ::coder::array<cell_wrap_6, 2U> f8;
    ::coder::array<cell_wrap_6, 2U> f9;
    ::coder::array<cell_wrap_6, 2U> f10;
    ::coder::array<cell_wrap_6, 2U> f11;
    ::coder::array<cell_wrap_6, 2U> f12;
    ::coder::array<cell_wrap_6, 2U> f13;
    ::coder::array<cell_wrap_7, 2U> f14;
  };

  struct struct1_T
  {
    ::coder::bounded_array<real_T, 2000U, 2U> params;
    ::coder::bounded_array<real_T, 2000U, 2U> backs;
    ::coder::bounded_array<real_T, 2000U, 2U> scales;
    ::coder::bounded_array<real_T, 2000U, 2U> shifts;
    ::coder::bounded_array<real_T, 2000U, 2U> nba;
    ::coder::bounded_array<real_T, 2000U, 2U> nbs;
    ::coder::bounded_array<real_T, 2000U, 2U> res;
  };

  struct struct3_T
  {
    ::coder::bounded_array<real_T, 1000U, 2U> params_fitYesNo;
    ::coder::bounded_array<real_T, 1000U, 2U> backs_fitYesNo;
    ::coder::bounded_array<real_T, 1000U, 2U> shifts_fitYesNo;
    ::coder::bounded_array<real_T, 1000U, 2U> scales_fitYesNo;
    ::coder::bounded_array<real_T, 1000U, 2U> nbairs_fitYesNo;
    ::coder::bounded_array<real_T, 1000U, 2U> nbsubs_fitYesNo;
    ::coder::bounded_array<real_T, 1000U, 2U> resol_fitYesNo;
  };

  struct struct2_T
  {
    ::coder::bounded_array<char_T, 1000U, 2U> para;
    ::coder::bounded_array<char_T, 1000U, 2U> proc;
    ::coder::bounded_array<char_T, 1000U, 2U> display;
    real_T tolX;
    real_T tolFun;
    real_T maxFunEvals;
    real_T maxIter;
    real_T populationSize;
    real_T F_weight;
    real_T F_CR;
    real_T VTR;
    real_T numGen;
    real_T strategy;
    real_T Nlive;
    real_T nmcmc;
    real_T propScale;
    real_T nsTolerance;
    real_T calcSld;
    real_T repeats;
    real_T nsimu;
    real_T burnin;
    real_T resamPars[2];
    real_T updateFreq;
    real_T updatePlotFreq;
    struct3_T checks;
  };

  struct struct5_T
  {
    ::coder::array<real_T, 1U> all_chis;
    real_T sum_chi;
  };

  struct struct4_T
  {
    ::coder::array<real_T, 1U> ssubs;
    ::coder::array<real_T, 1U> backgrounds;
    ::coder::array<real_T, 1U> qshifts;
    ::coder::array<real_T, 1U> scalefactors;
    ::coder::array<real_T, 1U> nbairs;
    ::coder::array<real_T, 1U> nbsubs;
    ::coder::array<real_T, 1U> resolutions;
    struct5_T calculations;
    ::coder::array<real_T, 1U> allSubRough;
    ::coder::array<real_T, 2U> resample;
  };

  struct cell_wrap_9
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_10
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_11
  {
    ::coder::array<cell_wrap_9, 1U> f1;
    ::coder::array<cell_wrap_9, 1U> f2;
    ::coder::array<cell_wrap_10, 1U> f3;
    ::coder::array<cell_wrap_10, 1U> f4;
    ::coder::array<cell_wrap_9, 1U> f5;
    ::coder::array<cell_wrap_10, 1U> f6;
  };

  struct cell_wrap_14
  {
    ::coder::array<real_T, 2U> f1;
  };
}

#endif

//
// File trailer for reflectivity_calculation_types.h
//
// [EOF]
//
