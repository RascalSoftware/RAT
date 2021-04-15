//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_gpu_types.h
//
//  Code generation for function 'reflectivity_calculation_gpu_types'
//


#pragma once

// Include files
#include "rtwtypes.h"

// Type Definitions
struct cell_wrap_6
{
  char_T f1[11];
};

struct cell_wrap_5
{
  char_T f1[13];
};

struct cell_wrap_4
{
  char_T f1[15];
};

struct cell_wrap_2
{
  real_T f1[5];
};

struct cell_wrap_1
{
  real_T f1[153];
};

struct cell_wrap_0
{
  real_T f1[2];
};

struct cell_wrap_9
{
  char_T f1[12];
};

struct cell_wrap_7
{
  char_T f1[3];
};

struct struct0_T
{
  real_T contrastBacks[7];
  real_T contrastBacksType[7];
  char_T TF[10];
  real_T resample[7];
  real_T dataPresent[7];
  real_T numberOfContrasts;
  char_T geometry[13];
  real_T contrastShifts[7];
  real_T contrastScales[7];
  real_T contrastNbas[7];
  real_T contrastNbss[7];
  real_T contrastRes[7];
  real_T backs[2];
  real_T shifts;
  real_T sf;
  real_T nba;
  real_T nbs[2];
  real_T res;
  real_T params[10];
  real_T numberOfLayers;
  char_T modelType[6];
  char_T modelFilename;
  char_T path[64];
  char_T modelLanguage[6];
};

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct cell_wrap_17
{
  emxArray_real_T *f1;
};

struct emxArray_cell_wrap_17
{
  cell_wrap_17 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct emxArray_creal_T
{
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct emxArray_int8_T
{
  int8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct cell_wrap_12
{
  emxArray_real_T *f1;
};

struct emxArray_cell_wrap_12
{
  cell_wrap_12 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct cell_3
{
  char_T f1[19];
  char_T f2[11];
  char_T f3[20];
  char_T f4[15];
  char_T f5[22];
  char_T f6[14];
  char_T f7[19];
  char_T f8[14];
  char_T f9[21];
  char_T f10[14];
};

struct cell_8
{
  char_T f1[3];
  char_T f2[4];
};

struct cell_10
{
  cell_wrap_0 f1[7];
  cell_wrap_1 f2[7];
  cell_wrap_0 f3[7];
  cell_wrap_0 f4[7];
  cell_wrap_0 f5[7];
  cell_wrap_2 f6[4];
  cell_3 f7;
  cell_wrap_4 f8[2];
  cell_wrap_5 f9[1];
  cell_wrap_6 f10[1];
  cell_wrap_7 f11[1];
  cell_8 f12;
  cell_wrap_9 f13[1];
};

struct struct3_T
{
  real_T params_fitYesNo[10];
  real_T backs_fitYesNo[2];
  real_T shifts_fitYesNo;
  real_T scales_fitYesNo;
  real_T nbairs_fitYesNo;
  real_T nbsubs_fitYesNo[2];
  real_T resol_fitYesNo;
};

struct struct2_T
{
  char_T para[6];
  char_T proc[9];
  char_T display[4];
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
  struct3_T checks;
};

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct struct1_T
{
  real_T params[20];
  real_T backs[4];
  real_T scales[2];
  real_T shifts[2];
  real_T nba[2];
  real_T nbs[4];
  real_T res[2];
};

struct cell_wrap_11
{
  emxArray_real_T *f1;
};

struct emxArray_cell_wrap_11
{
  cell_wrap_11 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct emxArray_real_T_10000x3
{
  real_T data[30000];
  int32_T size[2];
};

struct cell_wrap_15
{
  emxArray_real_T_10000x3 f1;
};

struct emxArray_cell_wrap_15
{
  cell_wrap_15 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct emxArray_real_T_10000x2
{
  real_T data[20000];
  int32_T size[2];
};

struct cell_wrap_14
{
  emxArray_real_T_10000x2 f1;
};

struct emxArray_cell_wrap_14
{
  cell_wrap_14 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct cell_13
{
  emxArray_cell_wrap_11 *f1;
  emxArray_cell_wrap_11 *f2;
  emxArray_cell_wrap_12 *f3;
  emxArray_cell_wrap_12 *f4;
  emxArray_cell_wrap_11 *f5;
  emxArray_real_T *f6;
};

struct struct5_T
{
  emxArray_real_T *all_chis;
  real_T sum_chi;
};

struct struct4_T
{
  emxArray_real_T *ssubs;
  emxArray_real_T *backgrounds;
  emxArray_real_T *qshifts;
  emxArray_real_T *scalefactors;
  emxArray_real_T *nbairs;
  emxArray_real_T *nbsubs;
  emxArray_real_T *resolutions;
  struct5_T calculations;
  emxArray_real_T *allSubRough;
};

// End of code generation (reflectivity_calculation_gpu_types.h)
