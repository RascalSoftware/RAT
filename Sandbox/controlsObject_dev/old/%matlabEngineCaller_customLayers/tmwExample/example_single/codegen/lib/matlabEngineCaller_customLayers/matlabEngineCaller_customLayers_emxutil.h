/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customLayers_emxutil.h
 *
 * Code generation for function 'matlabEngineCaller_customLayers_emxutil'
 *
 */

#ifndef MATLABENGINECALLER_CUSTOMLAYERS_EMXUTIL_H
#define MATLABENGINECALLER_CUSTOMLAYERS_EMXUTIL_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "matlabEngineCaller_customLayers_types.h"

/* Function Declarations */
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, int
  elementSize);
extern void emxFree_char_T(emxArray_char_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/* End of code generation (matlabEngineCaller_customLayers_emxutil.h) */
