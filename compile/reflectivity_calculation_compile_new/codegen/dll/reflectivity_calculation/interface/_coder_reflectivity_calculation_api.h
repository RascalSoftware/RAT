//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// _coder_reflectivity_calculation_api.h
//
// Code generation for function 'reflectivity_calculation'
//

#ifndef _CODER_REFLECTIVITY_CALCULATION_API_H
#define _CODER_REFLECTIVITY_CALCULATION_API_H

// Include files
#include "reflectivity_calculation_spec.h"
#include "coder_array_mex.h"
#include "coder_bounded_array.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Type Definitions
typedef struct {
  real_T f1[2];
} cell_wrap_0;

typedef struct {
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
  coder::array<real_T, 2U> contrastCustomFiles;
  coder::array<real_T, 2U> fitpars;
  coder::array<real_T, 2U> otherpars;
  coder::array<real_T, 2U> fitconstr;
  coder::array<real_T, 2U> otherconstr;
} struct0_T;

typedef struct {
  coder::array<real_T, 2U> f1;
} cell_wrap_1;

typedef struct {
  coder::array<real_T, 2U> f1;
} cell_wrap_2;

typedef struct {
  coder::bounded_array<real_T, 10U, 2U> f1;
} cell_wrap_3;

typedef struct {
  coder::array<char_T, 2U> f1;
} cell_wrap_4;

typedef struct {
  cell_wrap_4 f1[3];
} cell_wrap_5;

typedef struct {
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
  coder::array<cell_wrap_5, 2U> f14;
} cell_6;

typedef struct {
  coder::array<real_T, 2U> params;
  coder::array<real_T, 2U> backs;
  coder::array<real_T, 2U> scales;
  coder::array<real_T, 2U> shifts;
  coder::array<real_T, 2U> nba;
  coder::array<real_T, 2U> nbs;
  coder::array<real_T, 2U> res;
} struct1_T;

typedef struct {
  coder::array<real_T, 2U> params_fitYesNo;
  coder::array<real_T, 2U> backs_fitYesNo;
  coder::array<real_T, 2U> shifts_fitYesNo;
  coder::array<real_T, 2U> scales_fitYesNo;
  coder::array<real_T, 2U> nbairs_fitYesNo;
  coder::array<real_T, 2U> nbsubs_fitYesNo;
  coder::array<real_T, 2U> resol_fitYesNo;
} struct3_T;

typedef struct {
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
  real_T strategy;
  real_T Nlive;
  real_T nmcmc;
  coder::array<real_T, 2U> propScale;
  real_T nsTolerance;
  real_T calcSld;
  real_T repeats;
  real_T nsimu;
  real_T burnin;
  struct3_T checks;
} struct2_T;

typedef struct {
  coder::array<real_T, 1U> all_chis;
  real_T sum_chi;
} struct5_T;

typedef struct {
  coder::array<real_T, 1U> ssubs;
  coder::array<real_T, 1U> backgrounds;
  coder::array<real_T, 1U> qshifts;
  coder::array<real_T, 1U> scalefactors;
  coder::array<real_T, 1U> nbairs;
  coder::array<real_T, 1U> nbsubs;
  coder::array<real_T, 1U> resolutions;
  struct5_T calculations;
  coder::array<real_T, 1U> allSubRough;
} struct4_T;

typedef struct {
  coder::array<real_T, 2U> f1;
} cell_wrap_7;

typedef struct {
  coder::array<real_T, 2U> f1;
} cell_wrap_8;

typedef struct {
  coder::array<cell_wrap_7, 1U> f1;
  coder::array<cell_wrap_7, 1U> f2;
  coder::array<cell_wrap_8, 1U> f3;
  coder::array<cell_wrap_8, 1U> f4;
  coder::array<cell_wrap_7, 1U> f5;
  coder::array<real_T, 1U> f6;
} cell_9;

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void reflectivity_calculation(struct0_T *problemDef, cell_6 *problemDef_cells,
                              struct1_T *problemDef_limits, struct2_T *controls,
                              struct4_T *problem, cell_9 *result);

void reflectivity_calculation_api(const mxArray *const prhs[4], int32_T nlhs,
                                  const mxArray *plhs[2]);

void reflectivity_calculation_atexit();

void reflectivity_calculation_initialize();

void reflectivity_calculation_terminate();

void reflectivity_calculation_xil_shutdown();

void reflectivity_calculation_xil_terminate();

#endif
// End of code generation (_coder_reflectivity_calculation_api.h)
