/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_types.h
 *
 * Code generation for function 'reflectivity_calculation'
 *
 */

#ifndef REFLECTIVITY_CALCULATION_TYPES_H
#define REFLECTIVITY_CALCULATION_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_cell_3
#define typedef_cell_3

typedef struct {
  char f1[19];
  char f2[11];
  char f3[20];
  char f4[15];
  char f5[22];
  char f6[14];
  char f7[19];
  char f8[14];
  char f9[21];
  char f10[14];
} cell_3;

#endif                                 /*typedef_cell_3*/

#ifndef typedef_cell_8
#define typedef_cell_8

typedef struct {
  char f1[3];
  char f2[4];
} cell_8;

#endif                                 /*typedef_cell_8*/

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct {
  double f1[2];
} cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

#ifndef typedef_cell_wrap_1
#define typedef_cell_wrap_1

typedef struct {
  double f1[153];
} cell_wrap_1;

#endif                                 /*typedef_cell_wrap_1*/

#ifndef typedef_cell_wrap_2
#define typedef_cell_wrap_2

typedef struct {
  double f1[5];
} cell_wrap_2;

#endif                                 /*typedef_cell_wrap_2*/

#ifndef typedef_cell_wrap_4
#define typedef_cell_wrap_4

typedef struct {
  char f1[15];
} cell_wrap_4;

#endif                                 /*typedef_cell_wrap_4*/

#ifndef typedef_cell_wrap_5
#define typedef_cell_wrap_5

typedef struct {
  char f1[13];
} cell_wrap_5;

#endif                                 /*typedef_cell_wrap_5*/

#ifndef typedef_cell_wrap_6
#define typedef_cell_wrap_6

typedef struct {
  char f1[11];
} cell_wrap_6;

#endif                                 /*typedef_cell_wrap_6*/

#ifndef typedef_cell_wrap_7
#define typedef_cell_wrap_7

typedef struct {
  char f1[3];
} cell_wrap_7;

#endif                                 /*typedef_cell_wrap_7*/

#ifndef typedef_cell_wrap_9
#define typedef_cell_wrap_9

typedef struct {
  char f1[12];
} cell_wrap_9;

#endif                                 /*typedef_cell_wrap_9*/

#ifndef typedef_cell_10
#define typedef_cell_10

typedef struct {
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
} cell_10;

#endif                                 /*typedef_cell_10*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

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
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_11;

#endif                                 /*typedef_emxArray_cell_wrap_11*/

#ifndef typedef_cell_wrap_12
#define typedef_cell_wrap_12

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_12;

#endif                                 /*typedef_cell_wrap_12*/

#ifndef typedef_emxArray_cell_wrap_12
#define typedef_emxArray_cell_wrap_12

typedef struct {
  cell_wrap_12 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_12;

#endif                                 /*typedef_emxArray_cell_wrap_12*/

#ifndef typedef_cell_13
#define typedef_cell_13

typedef struct {
  emxArray_cell_wrap_11 *f1;
  emxArray_cell_wrap_11 *f2;
  emxArray_cell_wrap_12 *f3;
  emxArray_cell_wrap_12 *f4;
  emxArray_cell_wrap_11 *f5;
  emxArray_real_T *f6;
} cell_13;

#endif                                 /*typedef_cell_13*/

#ifndef typedef_cell_wrap_14
#define typedef_cell_wrap_14

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_14;

#endif                                 /*typedef_cell_wrap_14*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef typedef_emxArray_cell_wrap_14
#define typedef_emxArray_cell_wrap_14

typedef struct {
  cell_wrap_14 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_14;

#endif                                 /*typedef_emxArray_cell_wrap_14*/

#ifndef struct_emxArray_int16_T
#define struct_emxArray_int16_T

struct emxArray_int16_T
{
  short *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int16_T*/

#ifndef typedef_emxArray_int16_T
#define typedef_emxArray_int16_T

typedef struct emxArray_int16_T emxArray_int16_T;

#endif                                 /*typedef_emxArray_int16_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  signed char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int8_T*/

#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T

typedef struct emxArray_int8_T emxArray_int8_T;

#endif                                 /*typedef_emxArray_int8_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  double contrastBacks[7];
  double contrastBacksType[7];
  char TF[10];
  double resample[7];
  double dataPresent[7];
  double numberOfContrasts;
  char geometry[13];
  double contrastShifts[7];
  double contrastScales[7];
  double contrastNbas[7];
  double contrastNbss[7];
  double contrastRes[7];
  double backs[2];
  double shifts;
  double sf;
  double nba;
  double nbs[2];
  double res;
  double params[10];
  double numberOfLayers;
  char modelType[6];
  char path[64];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  double params[20];
  double backs[4];
  double scales[2];
  double shifts[2];
  double nba[2];
  double nbs[4];
  double res[2];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  double params_fitYesNo[10];
  double backs_fitYesNo[2];
  double shifts_fitYesNo;
  double scales_fitYesNo;
  double nbairs_fitYesNo;
  double nbsubs_fitYesNo[2];
  double resol_fitYesNo;
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  char para[6];
  char proc[7];
  char display[4];
  double tolX;
  double tolFun;
  double maxFunEvals;
  double maxIter;
  double populationSize;
  double F_weight;
  double F_CR;
  double VTR;
  double numGen;
  double strategy;
  double Nlive;
  double nmcmc;
  double propScale;
  double nsTolerance;
  struct3_T checks;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct5_T
#define typedef_struct5_T

typedef struct {
  emxArray_real_T *all_chis;
  double sum_chi;
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
#endif

/* End of code generation (reflectivity_calculation_types.h) */
