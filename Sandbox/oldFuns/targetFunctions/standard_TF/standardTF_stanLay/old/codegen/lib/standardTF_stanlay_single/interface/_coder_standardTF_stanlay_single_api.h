/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_standardTF_stanlay_single_api.h
 *
 * Code generation for function '_coder_standardTF_stanlay_single_api'
 *
 */

#ifndef _CODER_STANDARDTF_STANLAY_SINGLE_API_H
#define _CODER_STANDARDTF_STANLAY_SINGLE_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_standardTF_stanlay_single_api.h"

/* Type Definitions */
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

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

#ifndef typedef_cell_wrap_1
#define typedef_cell_wrap_1

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_1;

#endif                                 /*typedef_cell_wrap_1*/

#ifndef typedef_cell_wrap_2
#define typedef_cell_wrap_2

typedef struct {
  real_T f1[2];
} cell_wrap_2;

#endif                                 /*typedef_cell_wrap_2*/

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

#ifndef typedef_cell_wrap_4
#define typedef_cell_wrap_4

typedef struct {
  emxArray_real_T *f1;
} cell_wrap_4;

#endif                                 /*typedef_cell_wrap_4*/

#ifndef struct_sgvqTPMhaUJUFDHFGDwCvAB
#define struct_sgvqTPMhaUJUFDHFGDwCvAB

struct sgvqTPMhaUJUFDHFGDwCvAB
{
  emxArray_real_T *f1;
};

#endif                                 /*struct_sgvqTPMhaUJUFDHFGDwCvAB*/

#ifndef typedef_cell_wrap_5
#define typedef_cell_wrap_5

typedef struct sgvqTPMhaUJUFDHFGDwCvAB cell_wrap_5;

#endif                                 /*typedef_cell_wrap_5*/

#ifndef struct_emxArray_cell_wrap_0
#define struct_emxArray_cell_wrap_0

struct emxArray_cell_wrap_0
{
  cell_wrap_0 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_cell_wrap_0*/

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0

typedef struct emxArray_cell_wrap_0 emxArray_cell_wrap_0;

#endif                                 /*typedef_emxArray_cell_wrap_0*/

#ifndef struct_emxArray_cell_wrap_1
#define struct_emxArray_cell_wrap_1

struct emxArray_cell_wrap_1
{
  cell_wrap_1 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_cell_wrap_1*/

#ifndef typedef_emxArray_cell_wrap_1
#define typedef_emxArray_cell_wrap_1

typedef struct emxArray_cell_wrap_1 emxArray_cell_wrap_1;

#endif                                 /*typedef_emxArray_cell_wrap_1*/

#ifndef struct_emxArray_cell_wrap_2
#define struct_emxArray_cell_wrap_2

struct emxArray_cell_wrap_2
{
  cell_wrap_2 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_cell_wrap_2*/

#ifndef typedef_emxArray_cell_wrap_2
#define typedef_emxArray_cell_wrap_2

typedef struct emxArray_cell_wrap_2 emxArray_cell_wrap_2;

#endif                                 /*typedef_emxArray_cell_wrap_2*/

#ifndef struct_emxArray_cell_wrap_3
#define struct_emxArray_cell_wrap_3

struct emxArray_cell_wrap_3
{
  cell_wrap_3 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_cell_wrap_3*/

#ifndef typedef_emxArray_cell_wrap_3
#define typedef_emxArray_cell_wrap_3

typedef struct emxArray_cell_wrap_3 emxArray_cell_wrap_3;

#endif                                 /*typedef_emxArray_cell_wrap_3*/

#ifndef struct_emxArray_cell_wrap_4
#define struct_emxArray_cell_wrap_4

struct emxArray_cell_wrap_4
{
  cell_wrap_4 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_cell_wrap_4*/

#ifndef typedef_emxArray_cell_wrap_4
#define typedef_emxArray_cell_wrap_4

typedef struct emxArray_cell_wrap_4 emxArray_cell_wrap_4;

#endif                                 /*typedef_emxArray_cell_wrap_4*/

#ifndef struct_emxArray_cell_wrap_5
#define struct_emxArray_cell_wrap_5

struct emxArray_cell_wrap_5
{
  cell_wrap_5 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_cell_wrap_5*/

#ifndef typedef_emxArray_cell_wrap_5
#define typedef_emxArray_cell_wrap_5

typedef struct emxArray_cell_wrap_5 emxArray_cell_wrap_5;

#endif                                 /*typedef_emxArray_cell_wrap_5*/

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

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void standardTF_stanlay_single(emxArray_real_T *resam, real_T
  numberOfContrasts, emxArray_char_T *geometry, emxArray_real_T *nbairs,
  emxArray_real_T *nbsubs, emxArray_cell_wrap_0 *repeats, emxArray_real_T
  *cBacks, emxArray_real_T *cShifts, emxArray_real_T *cScales, emxArray_real_T
  *cNbas, emxArray_real_T *cNbss, emxArray_real_T *cRes, emxArray_real_T *backs,
  emxArray_real_T *shifts, emxArray_real_T *sf, emxArray_real_T *nba,
  emxArray_real_T *nbs, emxArray_real_T *res, emxArray_real_T *dataPresent,
  emxArray_cell_wrap_1 *allData, emxArray_cell_wrap_2 *dataLimits,
  emxArray_cell_wrap_2 *simLimits, emxArray_cell_wrap_2 *repeatLayers, real_T
  nParams, emxArray_real_T *params, emxArray_cell_wrap_0 *contrastLayers, real_T
  numberOfLayers, emxArray_cell_wrap_3 *layersDetails, real_T whichType,
  emxArray_real_T *outSsubs, emxArray_real_T *backgs, emxArray_real_T *qshifts,
  emxArray_real_T *sfs, emxArray_real_T *nbas, emxArray_real_T *nbss,
  emxArray_real_T *resols, emxArray_real_T *chis, emxArray_cell_wrap_4
  *reflectivity, emxArray_cell_wrap_4 *Simulation, emxArray_cell_wrap_1
  *shifted_data, emxArray_cell_wrap_1 *layerSlds, emxArray_cell_wrap_4
  *sldProfiles, emxArray_cell_wrap_5 *allLayers, emxArray_real_T *allRoughs);
extern void standardTF_stanlay_single_api(const mxArray *prhs[30], const mxArray
  *plhs[15]);
extern void standardTF_stanlay_single_atexit(void);
extern void standardTF_stanlay_single_initialize(void);
extern void standardTF_stanlay_single_terminate(void);
extern void standardTF_stanlay_single_xil_terminate(void);

#endif

/* End of code generation (_coder_standardTF_stanlay_single_api.h) */
