/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_types.h
 *
 * Code generation for function 'reflectivity_calculation_types'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct {
  real_T f1[2];
} cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0

typedef struct {
  cell_wrap_0 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_0;

#endif                                 /*typedef_emxArray_cell_wrap_0*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_cell_wrap_1
#define typedef_cell_wrap_1

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_1;

#endif                                 /*typedef_cell_wrap_1*/

#ifndef typedef_emxArray_cell_wrap_1
#define typedef_emxArray_cell_wrap_1

typedef struct {
  cell_wrap_1 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_1;

#endif                                 /*typedef_emxArray_cell_wrap_1*/

#ifndef typedef_cell_wrap_11
#define typedef_cell_wrap_11

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_11;

#endif                                 /*typedef_cell_wrap_11*/

#ifndef typedef_emxArray_cell_wrap_11
#define typedef_emxArray_cell_wrap_11

typedef struct {
  cell_wrap_11 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_11;

#endif                                 /*typedef_emxArray_cell_wrap_11*/

#ifndef struct_emxArray_real_T_1x5
#define struct_emxArray_real_T_1x5

struct emxArray_real_T_1x5
{
  real_T data[5];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1x5*/

#ifndef typedef_emxArray_real_T_1x5
#define typedef_emxArray_real_T_1x5

typedef struct emxArray_real_T_1x5 emxArray_real_T_1x5;

#endif                                 /*typedef_emxArray_real_T_1x5*/

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3

typedef struct {
  emxArray_real_T_1x5 f1;
} cell_wrap_3;

#endif                                 /*typedef_cell_wrap_3*/

#ifndef typedef_emxArray_cell_wrap_3
#define typedef_emxArray_cell_wrap_3

typedef struct {
  cell_wrap_3 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_3;

#endif                                 /*typedef_emxArray_cell_wrap_3*/

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_char_T*/

#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T

typedef struct emxArray_char_T emxArray_char_T;

#endif                                 /*typedef_emxArray_char_T*/

#ifndef typedef_cell_wrap_4
#define typedef_cell_wrap_4

typedef struct {
  emxArray_char_T *f1;
} cell_wrap_4;

#endif                                 /*typedef_cell_wrap_4*/

#ifndef typedef_emxArray_cell_wrap_4
#define typedef_emxArray_cell_wrap_4

typedef struct {
  cell_wrap_4 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_4;

#endif                                 /*typedef_emxArray_cell_wrap_4*/

#ifndef typedef_cell_13
#define typedef_cell_13

typedef struct {
  emxArray_cell_wrap_0 *f1;
  emxArray_cell_wrap_1 *f2;
  emxArray_cell_wrap_0 *f3;
  emxArray_cell_wrap_0 *f4;
  emxArray_cell_wrap_11 *f5;
  emxArray_cell_wrap_3 *f6;
  emxArray_cell_wrap_4 *f7;
  emxArray_cell_wrap_4 *f8;
  emxArray_cell_wrap_4 *f9;
  emxArray_cell_wrap_4 *f10;
  emxArray_cell_wrap_4 *f11;
  emxArray_cell_wrap_4 *f12;
  emxArray_cell_wrap_4 *f13;
} cell_13;

#endif                                 /*typedef_cell_13*/

#ifndef typedef_cell_wrap_2
#define typedef_cell_wrap_2

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_2;

#endif                                 /*typedef_cell_wrap_2*/

#ifndef typedef_emxArray_cell_wrap_2
#define typedef_emxArray_cell_wrap_2

typedef struct {
  cell_wrap_2 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_2;

#endif                                 /*typedef_emxArray_cell_wrap_2*/

#ifndef typedef_cell_5
#define typedef_cell_5

typedef struct {
  emxArray_cell_wrap_0 *f1;
  emxArray_cell_wrap_1 *f2;
  emxArray_cell_wrap_0 *f3;
  emxArray_cell_wrap_0 *f4;
  emxArray_cell_wrap_2 *f5;
  emxArray_cell_wrap_3 *f6;
  emxArray_cell_wrap_4 *f7;
  emxArray_cell_wrap_4 *f8;
  emxArray_cell_wrap_4 *f9;
  emxArray_cell_wrap_4 *f10;
  emxArray_cell_wrap_4 *f11;
  emxArray_cell_wrap_4 *f12;
  emxArray_cell_wrap_4 *f13;
} cell_5;

#endif                                 /*typedef_cell_5*/

#ifndef typedef_cell_wrap_6
#define typedef_cell_wrap_6

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_6;

#endif                                 /*typedef_cell_wrap_6*/

#ifndef typedef_emxArray_cell_wrap_6
#define typedef_emxArray_cell_wrap_6

typedef struct {
  cell_wrap_6 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_6;

#endif                                 /*typedef_emxArray_cell_wrap_6*/

#ifndef typedef_cell_7
#define typedef_cell_7

typedef struct {
  emxArray_cell_wrap_6 *f1;
  emxArray_cell_wrap_6 *f2;
  emxArray_cell_wrap_1 *f3;
  emxArray_cell_wrap_1 *f4;
  emxArray_cell_wrap_6 *f5;
  emxArray_real_T *f6;
} cell_7;

#endif                                 /*typedef_cell_7*/

#ifndef typedef_cell_wrap_10
#define typedef_cell_wrap_10

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_10;

#endif                                 /*typedef_cell_wrap_10*/

#ifndef typedef_cell_wrap_14
#define typedef_cell_wrap_14

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_14;

#endif                                 /*typedef_cell_wrap_14*/

#ifndef typedef_cell_wrap_15
#define typedef_cell_wrap_15

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_15;

#endif                                 /*typedef_cell_wrap_15*/

#ifndef typedef_cell_wrap_17
#define typedef_cell_wrap_17

typedef struct {
  real_T f1[5];
} cell_wrap_17;

#endif                                 /*typedef_cell_wrap_17*/

#ifndef typedef_cell_wrap_8
#define typedef_cell_wrap_8

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_8;

#endif                                 /*typedef_cell_wrap_8*/

#ifndef typedef_cell_wrap_9
#define typedef_cell_wrap_9

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_9;

#endif                                 /*typedef_cell_wrap_9*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef typedef_emxArray_cell_wrap_10
#define typedef_emxArray_cell_wrap_10

typedef struct {
  cell_wrap_10 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_10;

#endif                                 /*typedef_emxArray_cell_wrap_10*/

#ifndef typedef_emxArray_cell_wrap_14
#define typedef_emxArray_cell_wrap_14

typedef struct {
  cell_wrap_14 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_14;

#endif                                 /*typedef_emxArray_cell_wrap_14*/

#ifndef typedef_emxArray_cell_wrap_15
#define typedef_emxArray_cell_wrap_15

typedef struct {
  cell_wrap_15 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_15;

#endif                                 /*typedef_emxArray_cell_wrap_15*/

#ifndef typedef_emxArray_cell_wrap_17
#define typedef_emxArray_cell_wrap_17

typedef struct {
  cell_wrap_17 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_17;

#endif                                 /*typedef_emxArray_cell_wrap_17*/

#ifndef typedef_emxArray_cell_wrap_8
#define typedef_emxArray_cell_wrap_8

typedef struct {
  cell_wrap_8 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_8;

#endif                                 /*typedef_emxArray_cell_wrap_8*/

#ifndef typedef_emxArray_cell_wrap_9
#define typedef_emxArray_cell_wrap_9

typedef struct {
  cell_wrap_9 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_9;

#endif                                 /*typedef_emxArray_cell_wrap_9*/

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T

struct emxArray_int8_T
{
  int8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int8_T*/

#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T

typedef struct emxArray_int8_T emxArray_int8_T;

#endif                                 /*typedef_emxArray_int8_T*/

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T

struct emxArray_uint32_T
{
  uint32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint32_T*/

#ifndef typedef_emxArray_uint32_T
#define typedef_emxArray_uint32_T

typedef struct emxArray_uint32_T emxArray_uint32_T;

#endif                                 /*typedef_emxArray_uint32_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  emxArray_real_T *params_fitYesNo;
  emxArray_real_T *backs_fitYesNo;
  emxArray_real_T *shifts_fitYesNo;
  emxArray_real_T *scales_fitYesNo;
  emxArray_real_T *nbairs_fitYesNo;
  emxArray_real_T *nbsubs_fitYesNo;
  emxArray_real_T *resol_fitYesNo;
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  emxArray_char_T *para;
  emxArray_char_T *proc;
  emxArray_char_T *display;
  real_T tolX;
  real_T tolFun;
  real_T maxFunEvals;
  real_T maxIter;
  real_T populationSize;
  real_T F_weight;
  real_T F_CR;
  real_T VTR;
  real_T numGen;
  emxArray_real_T *strategy;
  real_T Nlive;
  real_T nmcmc;
  real_T propScale;
  real_T nsTolerance;
  real_T calcSld;
  struct3_T checks;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  emxArray_real_T *params;
  emxArray_real_T *backs;
  emxArray_real_T *scales;
  emxArray_real_T *shifts;
  emxArray_real_T *nba;
  emxArray_real_T *nbs;
  emxArray_real_T *res;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct5_T
#define typedef_struct5_T

typedef struct {
  emxArray_real_T *all_chis;
  real_T sum_chi;
} struct5_T;

#endif                                 /*typedef_struct5_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  emxArray_real_T *ssubs;
  emxArray_real_T *backgrounds;
  emxArray_real_T *qshifts;
  emxArray_real_T *scalefactors;
  emxArray_real_T *nbairs;
  emxArray_real_T *nbsubs;
  emxArray_real_T *resolutions;
  struct5_T calculations;
  emxArray_real_T *allSubRough;
} struct4_T;

#endif                                 /*typedef_struct4_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  emxArray_real_T *contrastBacks;
  emxArray_real_T *contrastBacksType;
  emxArray_char_T *TF;
  emxArray_real_T *resample;
  emxArray_real_T *dataPresent;
  real_T numberOfContrasts;
  emxArray_char_T *geometry;
  emxArray_real_T *contrastShifts;
  emxArray_real_T *contrastScales;
  emxArray_real_T *contrastNbas;
  emxArray_real_T *contrastNbss;
  emxArray_real_T *contrastRes;
  emxArray_real_T *backs;
  emxArray_real_T *shifts;
  emxArray_real_T *sf;
  emxArray_real_T *nba;
  emxArray_real_T *nbs;
  emxArray_real_T *res;
  emxArray_real_T *params;
  real_T numberOfLayers;
  emxArray_char_T *modelType;
  emxArray_char_T *modelFilename;
  emxArray_char_T *path;
  emxArray_char_T *modelLanguage;
  emxArray_real_T *fitpars;
  emxArray_real_T *otherpars;
  emxArray_real_T *fitconstr;
  emxArray_real_T *otherconstr;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* End of code generation (reflectivity_calculation_types.h) */
