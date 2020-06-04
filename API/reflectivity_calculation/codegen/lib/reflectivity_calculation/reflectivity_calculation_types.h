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
#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct {
  double f1[2];
} cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0

typedef struct {
  cell_wrap_0 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_0;

#endif                                 /*typedef_emxArray_cell_wrap_0*/

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
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_1;

#endif                                 /*typedef_emxArray_cell_wrap_1*/

#ifndef struct_emxArray_real_T_1x5
#define struct_emxArray_real_T_1x5

struct emxArray_real_T_1x5
{
  double data[5];
  int size[2];
};

#endif                                 /*struct_emxArray_real_T_1x5*/

#ifndef typedef_emxArray_real_T_1x5
#define typedef_emxArray_real_T_1x5

typedef struct emxArray_real_T_1x5 emxArray_real_T_1x5;

#endif                                 /*typedef_emxArray_real_T_1x5*/

#ifndef typedef_cell_wrap_2
#define typedef_cell_wrap_2

typedef struct {
  emxArray_real_T_1x5 f1;
} cell_wrap_2;

#endif                                 /*typedef_cell_wrap_2*/

#ifndef typedef_emxArray_cell_wrap_2
#define typedef_emxArray_cell_wrap_2

typedef struct {
  cell_wrap_2 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_2;

#endif                                 /*typedef_emxArray_cell_wrap_2*/

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_char_T*/

#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T

typedef struct emxArray_char_T emxArray_char_T;

#endif                                 /*typedef_emxArray_char_T*/

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3

typedef struct {
  emxArray_char_T *f1;
} cell_wrap_3;

#endif                                 /*typedef_cell_wrap_3*/

#ifndef typedef_emxArray_cell_wrap_3
#define typedef_emxArray_cell_wrap_3

typedef struct {
  cell_wrap_3 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_3;

#endif                                 /*typedef_emxArray_cell_wrap_3*/

#ifndef typedef_cell_4
#define typedef_cell_4

typedef struct {
  emxArray_cell_wrap_0 *f1;
  emxArray_cell_wrap_1 *f2;
  emxArray_cell_wrap_0 *f3;
  emxArray_cell_wrap_0 *f4;
  emxArray_cell_wrap_0 *f5;
  emxArray_cell_wrap_2 *f6;
  emxArray_cell_wrap_3 *f7;
  emxArray_cell_wrap_3 *f8;
  emxArray_cell_wrap_3 *f9;
  emxArray_cell_wrap_3 *f10;
  emxArray_cell_wrap_3 *f11;
  emxArray_cell_wrap_3 *f12;
  emxArray_cell_wrap_3 *f13;
} cell_4;

#endif                                 /*typedef_cell_4*/

#ifndef typedef_cell_wrap_5
#define typedef_cell_wrap_5

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_5;

#endif                                 /*typedef_cell_wrap_5*/

#ifndef typedef_emxArray_cell_wrap_5
#define typedef_emxArray_cell_wrap_5

typedef struct {
  cell_wrap_5 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_5;

#endif                                 /*typedef_emxArray_cell_wrap_5*/

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
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_6;

#endif                                 /*typedef_emxArray_cell_wrap_6*/

#ifndef typedef_cell_7
#define typedef_cell_7

typedef struct {
  emxArray_cell_wrap_5 *f1;
  emxArray_cell_wrap_5 *f2;
  emxArray_cell_wrap_6 *f3;
  emxArray_cell_wrap_6 *f4;
  emxArray_cell_wrap_5 *f5;
  emxArray_real_T *f6;
} cell_7;

#endif                                 /*typedef_cell_7*/

#ifndef typedef_cell_wrap_13
#define typedef_cell_wrap_13

typedef struct {
  double f1[5];
} cell_wrap_13;

#endif                                 /*typedef_cell_wrap_13*/

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

#ifndef typedef_emxArray_cell_wrap_13
#define typedef_emxArray_cell_wrap_13

typedef struct {
  cell_wrap_13 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_13;

#endif                                 /*typedef_emxArray_cell_wrap_13*/

#ifndef typedef_emxArray_cell_wrap_8
#define typedef_emxArray_cell_wrap_8

typedef struct {
  cell_wrap_8 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_8;

#endif                                 /*typedef_emxArray_cell_wrap_8*/

#ifndef typedef_emxArray_cell_wrap_9
#define typedef_emxArray_cell_wrap_9

typedef struct {
  cell_wrap_9 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_9;

#endif                                 /*typedef_emxArray_cell_wrap_9*/

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

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T

struct emxArray_uint32_T
{
  unsigned int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint32_T*/

#ifndef typedef_emxArray_uint32_T
#define typedef_emxArray_uint32_T

typedef struct emxArray_uint32_T emxArray_uint32_T;

#endif                                 /*typedef_emxArray_uint32_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  emxArray_real_T *contrastBacks;
  emxArray_real_T *contrastBacksType;
  emxArray_char_T *TF;
  emxArray_real_T *resample;
  emxArray_real_T *dataPresent;
  double numberOfContrasts;
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
  double numberOfLayers;
  emxArray_char_T *modelType;
  emxArray_char_T *modelFilename;
  emxArray_char_T *path;
  emxArray_real_T *modelLanguage;
  emxArray_real_T *fitpars;
  emxArray_real_T *otherpars;
  emxArray_real_T *fitconstr;
  emxArray_real_T *otherconstr;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

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
  double tolX;
  double tolFun;
  double maxFunEvals;
  double maxIter;
  double populationSize;
  double F_weight;
  double F_CR;
  double VTR;
  double numGen;
  emxArray_real_T *strategy;
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
