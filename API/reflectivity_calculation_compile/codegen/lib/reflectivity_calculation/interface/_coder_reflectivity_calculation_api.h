/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_reflectivity_calculation_api.h
 *
 * Code generation for function '_coder_reflectivity_calculation_api'
 *
 */

#ifndef _CODER_REFLECTIVITY_CALCULATION_API_H
#define _CODER_REFLECTIVITY_CALCULATION_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_reflectivity_calculation_api.h"

/* Type Definitions */
#ifndef typedef_cell_3
#define typedef_cell_3

typedef struct {
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
} cell_3;

#endif                                 /*typedef_cell_3*/

#ifndef typedef_cell_8
#define typedef_cell_8

typedef struct {
  char_T f1[3];
  char_T f2[4];
} cell_8;

#endif                                 /*typedef_cell_8*/

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct {
  real_T f1[2];
} cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

#ifndef typedef_cell_wrap_1
#define typedef_cell_wrap_1

typedef struct {
  real_T f1[153];
} cell_wrap_1;

#endif                                 /*typedef_cell_wrap_1*/

#ifndef typedef_cell_wrap_2
#define typedef_cell_wrap_2

typedef struct {
  real_T f1[5];
} cell_wrap_2;

#endif                                 /*typedef_cell_wrap_2*/

#ifndef typedef_cell_wrap_4
#define typedef_cell_wrap_4

typedef struct {
  char_T f1[15];
} cell_wrap_4;

#endif                                 /*typedef_cell_wrap_4*/

#ifndef typedef_cell_wrap_5
#define typedef_cell_wrap_5

typedef struct {
  char_T f1[13];
} cell_wrap_5;

#endif                                 /*typedef_cell_wrap_5*/

#ifndef typedef_cell_wrap_6
#define typedef_cell_wrap_6

typedef struct {
  char_T f1[11];
} cell_wrap_6;

#endif                                 /*typedef_cell_wrap_6*/

#ifndef typedef_cell_wrap_7
#define typedef_cell_wrap_7

typedef struct {
  char_T f1[3];
} cell_wrap_7;

#endif                                 /*typedef_cell_wrap_7*/

#ifndef typedef_cell_wrap_9
#define typedef_cell_wrap_9

typedef struct {
  char_T f1[12];
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
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
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

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
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
  char_T path[64];
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T params[20];
  real_T backs[4];
  real_T scales[2];
  real_T shifts[2];
  real_T nba[2];
  real_T nbs[4];
  real_T res[2];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T params_fitYesNo[10];
  real_T backs_fitYesNo[2];
  real_T shifts_fitYesNo;
  real_T scales_fitYesNo;
  real_T nbairs_fitYesNo;
  real_T nbsubs_fitYesNo[2];
  real_T resol_fitYesNo;
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  char_T para[6];
  char_T proc[7];
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
  struct3_T checks;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

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

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void reflectivity_calculation(struct0_T *problemDef, cell_10
  *problemDef_cells, struct1_T *problemDef_limits, struct2_T *controls,
  struct4_T *problem, cell_13 *result);
extern void reflectivity_calculation_api(const mxArray * const prhs[4], int32_T
  nlhs, const mxArray *plhs[2]);
extern void reflectivity_calculation_atexit(void);
extern void reflectivity_calculation_initialize(void);
extern void reflectivity_calculation_terminate(void);
extern void reflectivity_calculation_xil_shutdown(void);
extern void reflectivity_calculation_xil_terminate(void);

#endif

/* End of code generation (_coder_reflectivity_calculation_api.h) */
