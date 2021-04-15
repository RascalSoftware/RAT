/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 * File: _coder_reflectivity_calculation_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 15-Apr-2021 10:46:16
 */

#ifndef _CODER_REFLECTIVITY_CALCULATION_API_H
#define _CODER_REFLECTIVITY_CALCULATION_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

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

#ifndef struct_emxArray_real_T_1x10
#define struct_emxArray_real_T_1x10

struct emxArray_real_T_1x10
{
  real_T data[10];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1x10*/

#ifndef typedef_emxArray_real_T_1x10
#define typedef_emxArray_real_T_1x10

typedef struct emxArray_real_T_1x10 emxArray_real_T_1x10;

#endif                                 /*typedef_emxArray_real_T_1x10*/

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3

typedef struct {
  emxArray_real_T_1x10 f1;
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

#ifndef typedef_cell_wrap_5
#define typedef_cell_wrap_5

typedef struct {
  cell_wrap_4 f1[3];
} cell_wrap_5;

#endif                                 /*typedef_cell_wrap_5*/

#ifndef typedef_emxArray_cell_wrap_5
#define typedef_emxArray_cell_wrap_5

typedef struct {
  cell_wrap_5 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_5;

#endif                                 /*typedef_emxArray_cell_wrap_5*/

#ifndef typedef_cell_6
#define typedef_cell_6

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
  emxArray_cell_wrap_5 *f14;
} cell_6;

#endif                                 /*typedef_cell_6*/

#ifndef typedef_cell_wrap_7
#define typedef_cell_wrap_7

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_7;

#endif                                 /*typedef_cell_wrap_7*/

#ifndef typedef_emxArray_cell_wrap_7
#define typedef_emxArray_cell_wrap_7

typedef struct {
  cell_wrap_7 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_7;

#endif                                 /*typedef_emxArray_cell_wrap_7*/

#ifndef typedef_cell_wrap_8
#define typedef_cell_wrap_8

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_8;

#endif                                 /*typedef_cell_wrap_8*/

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

#ifndef typedef_cell_9
#define typedef_cell_9

typedef struct {
  emxArray_cell_wrap_7 *f1;
  emxArray_cell_wrap_7 *f2;
  emxArray_cell_wrap_8 *f3;
  emxArray_cell_wrap_8 *f4;
  emxArray_cell_wrap_7 *f5;
  emxArray_real_T *f6;
} cell_9;

#endif                                 /*typedef_cell_9*/

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
  real_T repeats;
  real_T nsimu;
  real_T burnin;
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
  emxArray_real_T *contrastCustomFiles;
  emxArray_real_T *fitpars;
  emxArray_real_T *otherpars;
  emxArray_real_T *fitconstr;
  emxArray_real_T *otherconstr;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#define MAX_THREADS                    omp_get_max_threads()

/* Function Declarations */
extern void reflectivity_calculation(struct0_T *problemDef, cell_6
  *problemDef_cells, struct1_T *problemDef_limits, struct2_T *controls,
  struct4_T *problem, cell_9 *result);
extern void reflectivity_calculation_api(const mxArray * const prhs[4], int32_T
  nlhs, const mxArray *plhs[2]);
extern void reflectivity_calculation_atexit(void);
extern void reflectivity_calculation_initialize(void);
extern void reflectivity_calculation_terminate(void);
extern void reflectivity_calculation_xil_shutdown(void);
extern void reflectivity_calculation_xil_terminate(void);

#endif

/*
 * File trailer for _coder_reflectivity_calculation_api.h
 *
 * [EOF]
 */
