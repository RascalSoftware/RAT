/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * callParaMatalbCustlay_types.h
 *
 * Code generation for function 'callParaMatalbCustlay'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T contrastBacks[3];
  real_T contrastBacksType[3];
  char_T TF[10];
  real_T resample[3];
  real_T dataPresent[3];
  real_T numberOfContrasts;
  char_T geometry[16];
  real_T contrastShifts[3];
  real_T contrastScales[3];
  real_T contrastNbas[3];
  real_T contrastNbss[3];
  real_T contrastRes[3];
  real_T backs[3];
  real_T shifts;
  real_T sf;
  real_T nba;
  real_T nbs[3];
  real_T res;
  real_T params[8];
  real_T numberOfLayers;
  char_T modelType[13];
  real_T contrastCustomFiles[3];
  real_T fitpars[15];
  real_T otherpars[3];
  real_T fitconstr[30];
  real_T otherconstr[6];
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T params[16];
  real_T backs[6];
  real_T scales[2];
  real_T shifts[2];
  real_T nba[2];
  real_T nbs[6];
  real_T res[2];
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_struct3_T
#define typedef_struct3_T
typedef struct {
  real_T params_fitYesNo[8];
  real_T backs_fitYesNo[3];
  real_T shifts_fitYesNo;
  real_T scales_fitYesNo;
  real_T nbairs_fitYesNo;
  real_T nbsubs_fitYesNo[3];
  real_T resol_fitYesNo;
} struct3_T;
#endif /* typedef_struct3_T */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
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
  real_T repeats;
  real_T nsimu;
  real_T burnin;
  real_T resamPars[2];
  real_T updateFreq;
  real_T updatePlotFreq;
  struct3_T checks;
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  real_T f1[2];
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#ifndef typedef_cell_1
#define typedef_cell_1
typedef struct {
  real_T f1[438];
  real_T f2[291];
  real_T f3[312];
} cell_1;
#endif /* typedef_cell_1 */

#ifndef typedef_cell_2
#define typedef_cell_2
typedef struct {
  char_T f1[19];
  char_T f2[11];
  char_T f3[15];
  char_T f4[9];
  char_T f5[14];
  char_T f6[17];
  char_T f7[17];
  char_T f8[15];
} cell_2;
#endif /* typedef_cell_2 */

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3
typedef struct {
  char_T f1[13];
} cell_wrap_3;
#endif /* typedef_cell_wrap_3 */

#ifndef typedef_cell_wrap_4
#define typedef_cell_wrap_4
typedef struct {
  char_T f1[10];
} cell_wrap_4;
#endif /* typedef_cell_wrap_4 */

#ifndef typedef_cell_wrap_5
#define typedef_cell_wrap_5
typedef struct {
  char_T f1[7];
} cell_wrap_5;
#endif /* typedef_cell_wrap_5 */

#ifndef typedef_cell_wrap_6
#define typedef_cell_wrap_6
typedef struct {
  char_T f1[16];
} cell_wrap_6;
#endif /* typedef_cell_wrap_6 */

#ifndef typedef_cell_7
#define typedef_cell_7
typedef struct {
  char_T f1[13];
  char_T f2[6];
  char_T f3[62];
} cell_7;
#endif /* typedef_cell_7 */

#ifndef typedef_cell_8
#define typedef_cell_8
typedef struct {
  cell_wrap_0 f1[3];
  cell_1 f2;
  cell_wrap_0 f3[3];
  cell_wrap_0 f4[3];
  real_T f5[3];
  real_T f6[1];
  cell_2 f7;
  cell_wrap_3 f8[3];
  cell_wrap_3 f9[1];
  cell_wrap_4 f10[1];
  cell_wrap_5 f11[1];
  cell_wrap_5 f12[3];
  cell_wrap_6 f13[1];
  cell_7 f14[1];
} cell_8;
#endif /* typedef_cell_8 */

/* End of code generation (callParaMatalbCustlay_types.h) */
