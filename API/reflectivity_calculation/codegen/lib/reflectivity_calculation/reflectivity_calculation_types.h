//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
// File: reflectivity_calculation_types.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 11-Jan-2021 16:52:33
//
#ifndef REFLECTIVITY_CALCULATION_TYPES_H
#define REFLECTIVITY_CALCULATION_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#ifdef _MSC_VER

#pragma warning(push)
#pragma warning(disable : 4251)

#endif

// Type Definitions
struct cell_wrap_15
{
  coder::array<double, 2U> f1;
};

struct cell_wrap_0
{
  double f1[2];
};

struct cell_wrap_1
{
  coder::array<double, 2U> f1;
};

struct cell_wrap_11
{
  coder::array<double, 2U> f1;
};

struct emxArray_real_T_1x5
{
  double data[5];
  int size[2];
};

struct cell_wrap_3
{
  emxArray_real_T_1x5 f1;
};

struct cell_wrap_4
{
  coder::array<char, 2U> f1;
};

struct cell_13
{
  coder::array<cell_wrap_0, 2U> f1;
  coder::array<cell_wrap_1, 2U> f2;
  coder::array<cell_wrap_0, 2U> f3;
  coder::array<cell_wrap_0, 2U> f4;
  coder::array<cell_wrap_11, 2U> f5;
  coder::array<cell_wrap_3, 1U> f6;
  coder::array<cell_wrap_4, 2U> f7;
  coder::array<cell_wrap_4, 2U> f8;
  coder::array<cell_wrap_4, 2U> f9;
  coder::array<cell_wrap_4, 2U> f10;
  coder::array<cell_wrap_4, 2U> f11;
  coder::array<cell_wrap_4, 2U> f12;
  coder::array<cell_wrap_4, 2U> f13;
};

struct cell_wrap_9
{
  coder::array<double, 2U> f1;
};

struct cell_wrap_8
{
  coder::array<double, 2U> f1;
};

struct cell_wrap_14
{
  coder::array<double, 2U> f1;
};

struct cell_wrap_16
{
  double f1[5];
};

struct cell_wrap_6
{
  coder::array<double, 2U> f1;
};

struct struct3_T
{
  coder::array<double, 2U> params_fitYesNo;
  coder::array<double, 2U> backs_fitYesNo;
  coder::array<double, 2U> shifts_fitYesNo;
  coder::array<double, 2U> scales_fitYesNo;
  coder::array<double, 2U> nbairs_fitYesNo;
  coder::array<double, 2U> nbsubs_fitYesNo;
  coder::array<double, 2U> resol_fitYesNo;
};

struct struct2_T
{
  coder::array<char, 2U> para;
  coder::array<char, 2U> proc;
  coder::array<char, 2U> display;
  double tolX;
  double tolFun;
  double maxFunEvals;
  double maxIter;
  double populationSize;
  double F_weight;
  double F_CR;
  double VTR;
  double numGen;
  coder::array<double, 2U> strategy;
  double Nlive;
  double nmcmc;
  double propScale;
  double nsTolerance;
  double calcSld;
  struct3_T checks;
};

struct cell_wrap_2
{
  coder::array<double, 2U> f1;
};

struct cell_5
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
  coder::array<cell_wrap_4, 2U> f10;
  coder::array<cell_wrap_4, 2U> f11;
  coder::array<cell_wrap_4, 2U> f12;
  coder::array<cell_wrap_4, 2U> f13;
};

struct struct0_T
{
  coder::array<double, 2U> contrastBacks;
  coder::array<double, 2U> contrastBacksType;
  coder::array<char, 2U> TF;
  coder::array<double, 2U> resample;
  coder::array<double, 2U> dataPresent;
  double numberOfContrasts;
  coder::array<char, 2U> geometry;
  coder::array<double, 2U> contrastShifts;
  coder::array<double, 2U> contrastScales;
  coder::array<double, 2U> contrastNbas;
  coder::array<double, 2U> contrastNbss;
  coder::array<double, 2U> contrastRes;
  coder::array<double, 2U> backs;
  coder::array<double, 2U> shifts;
  coder::array<double, 2U> sf;
  coder::array<double, 2U> nba;
  coder::array<double, 2U> nbs;
  coder::array<double, 2U> res;
  coder::array<double, 2U> params;
  double numberOfLayers;
  coder::array<char, 2U> modelType;
  coder::array<char, 2U> modelFilename;
  coder::array<char, 2U> path;
  coder::array<char, 2U> modelLanguage;
  coder::array<double, 2U> fitpars;
  coder::array<double, 2U> otherpars;
  coder::array<double, 2U> fitconstr;
  coder::array<double, 2U> otherconstr;
};

struct struct5_T
{
  coder::array<double, 1U> all_chis;
  double sum_chi;
};

struct struct4_T
{
  coder::array<double, 1U> ssubs;
  coder::array<double, 1U> backgrounds;
  coder::array<double, 1U> qshifts;
  coder::array<double, 1U> scalefactors;
  coder::array<double, 1U> nbairs;
  coder::array<double, 1U> nbsubs;
  coder::array<double, 1U> resolutions;
  struct5_T calculations;
  coder::array<double, 1U> allSubRough;
};

struct cell_7
{
  coder::array<cell_wrap_6, 1U> f1;
  coder::array<cell_wrap_6, 1U> f2;
  coder::array<cell_wrap_1, 1U> f3;
  coder::array<cell_wrap_1, 1U> f4;
  coder::array<cell_wrap_6, 1U> f5;
  coder::array<double, 1U> f6;
};

struct struct1_T
{
  coder::array<double, 2U> params;
  coder::array<double, 2U> backs;
  coder::array<double, 2U> scales;
  coder::array<double, 2U> shifts;
  coder::array<double, 2U> nba;
  coder::array<double, 2U> nbs;
  coder::array<double, 2U> res;
};

#define MAX_THREADS                    omp_get_max_threads()
#ifdef _MSC_VER

#pragma warning(pop)

#endif
#endif

//
// File trailer for reflectivity_calculation_types.h
//
// [EOF]
//
