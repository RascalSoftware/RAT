//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_types.h
//
//  Code generation for function 'reflectivity_calculation_types'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#ifdef _MSC_VER

#pragma warning(push)
#pragma warning(disable : 4251)

#endif

// Type Definitions
struct cell_wrap_1
{
  coder::array<real_T, 2U> f1;
};

struct struct5_T
{
  coder::array<real_T, 1U> all_chis;
  real_T sum_chi;
};

struct struct4_T
{
  coder::array<real_T, 1U> ssubs;
  coder::array<real_T, 1U> backgrounds;
  coder::array<real_T, 1U> qshifts;
  coder::array<real_T, 1U> scalefactors;
  coder::array<real_T, 1U> nbairs;
  coder::array<real_T, 1U> nbsubs;
  coder::array<real_T, 1U> resolutions;
  struct5_T calculations;
  coder::array<real_T, 1U> allSubRough;
};

struct cell_wrap_0
{
  real_T f1[2];
};

struct emxArray_real_T_1x5
{
  real_T data[5];
  int32_T size[2];
};

struct cell_wrap_3
{
  emxArray_real_T_1x5 f1;
};

struct cell_wrap_19
{
  real_T f1[5];
};

struct cell_wrap_11
{
  coder::array<real_T, 1U> f1;
};

struct cell_wrap_12
{
  coder::array<real_T, 2U> f1;
};

struct cell_wrap_7
{
  coder::array<real_T, 2U> f1;
};

struct struct3_T
{
  coder::array<real_T, 2U> params_fitYesNo;
  coder::array<real_T, 2U> backs_fitYesNo;
  coder::array<real_T, 2U> shifts_fitYesNo;
  coder::array<real_T, 2U> scales_fitYesNo;
  coder::array<real_T, 2U> nbairs_fitYesNo;
  coder::array<real_T, 2U> nbsubs_fitYesNo;
  coder::array<real_T, 2U> resol_fitYesNo;
};

struct struct2_T
{
  coder::array<char_T, 2U> para;
  coder::array<char_T, 2U> proc;
  coder::array<char_T, 2U> display;
  real_T tolX;
  real_T tolFun;
  real_T maxFunEvals;
  real_T maxIter;
  real_T populationSize;
  real_T F_weight;
  real_T F_CR;
  real_T VTR;
  real_T numGen;
  coder::array<real_T, 2U> strategy;
  real_T Nlive;
  real_T nmcmc;
  real_T propScale;
  real_T nsTolerance;
  real_T calcSld;
  real_T repeats;
  real_T nsimu;
  real_T burnin;
  struct3_T checks;
};

struct cell_8
{
  coder::array<cell_wrap_7, 1U> f1;
  coder::array<cell_wrap_7, 1U> f2;
  coder::array<cell_wrap_1, 1U> f3;
  coder::array<cell_wrap_1, 1U> f4;
  coder::array<cell_wrap_7, 1U> f5;
  coder::array<real_T, 1U> f6;
};

struct cell_wrap_2
{
  coder::array<real_T, 2U> f1;
};

struct cell_wrap_4
{
  coder::array<char_T, 2U> f1;
};

struct cell_wrap_5
{
  coder::array<char_T, 2U> f1;
};

struct cell_6
{
  coder::array<cell_wrap_0, 2U> f1;
  coder::array<cell_wrap_1, 2U> f2;
  coder::array<cell_wrap_0, 2U> f3;
  coder::array<cell_wrap_0, 2U> f4;
  coder::array<cell_wrap_2, 2U> f5;
  coder::array<cell_wrap_3, 1U> f6;
  coder::array<cell_wrap_4, 2U> f7;
  coder::array<cell_wrap_4, 2U> f8;
  coder::array<cell_wrap_4, 2U> f9;
  coder::array<cell_wrap_5, 2U> f10;
  coder::array<cell_wrap_4, 2U> f11;
  coder::array<cell_wrap_4, 2U> f12;
  coder::array<cell_wrap_4, 2U> f13;
};

struct struct0_T
{
  coder::array<real_T, 2U> contrastBacks;
  coder::array<real_T, 2U> contrastBacksType;
  coder::array<char_T, 2U> TF;
  coder::array<real_T, 2U> resample;
  coder::array<real_T, 2U> dataPresent;
  real_T numberOfContrasts;
  coder::array<char_T, 2U> geometry;
  coder::array<real_T, 2U> contrastShifts;
  coder::array<real_T, 2U> contrastScales;
  coder::array<real_T, 2U> contrastNbas;
  coder::array<real_T, 2U> contrastNbss;
  coder::array<real_T, 2U> contrastRes;
  coder::array<real_T, 2U> backs;
  coder::array<real_T, 2U> shifts;
  coder::array<real_T, 2U> sf;
  coder::array<real_T, 2U> nba;
  coder::array<real_T, 2U> nbs;
  coder::array<real_T, 2U> res;
  coder::array<real_T, 2U> params;
  real_T numberOfLayers;
  coder::array<char_T, 2U> modelType;
  coder::array<char_T, 2U> modelFilename;
  coder::array<char_T, 2U> path;
  coder::array<char_T, 2U> modelLanguage;
  coder::array<real_T, 2U> fitpars;
  coder::array<real_T, 2U> otherpars;
  coder::array<real_T, 2U> fitconstr;
  coder::array<real_T, 2U> otherconstr;
};

struct cell_15
{
  coder::array<cell_wrap_0, 2U> f1;
  coder::array<cell_wrap_1, 2U> f2;
  coder::array<cell_wrap_0, 2U> f3;
  coder::array<cell_wrap_0, 2U> f4;
  coder::array<cell_wrap_12, 2U> f5;
  coder::array<cell_wrap_3, 1U> f6;
  coder::array<cell_wrap_4, 2U> f7;
  coder::array<cell_wrap_4, 2U> f8;
  coder::array<cell_wrap_4, 2U> f9;
  coder::array<cell_wrap_5, 2U> f10;
  coder::array<cell_wrap_4, 2U> f11;
  coder::array<cell_wrap_4, 2U> f12;
  coder::array<cell_wrap_4, 2U> f13;
};

struct cell_21
{
  coder::array<real_T, 2U> f1;
};

struct struct1_T
{
  coder::array<real_T, 2U> params;
  coder::array<real_T, 2U> backs;
  coder::array<real_T, 2U> scales;
  coder::array<real_T, 2U> shifts;
  coder::array<real_T, 2U> nba;
  coder::array<real_T, 2U> nbs;
  coder::array<real_T, 2U> res;
};

#define MAX_THREADS                    omp_get_max_threads()
#ifdef _MSC_VER

#pragma warning(pop)

#endif

// End of code generation (reflectivity_calculation_types.h)
