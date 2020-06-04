/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "resampleLayers_new.h"
#include "repmat.h"
#include "resampleLayers_new_emxutil.h"

/* Function Definitions */
void repmat(const double a[2], double varargin_1, emxArray_real_T *b)
{
  int itilerow;
  int i4;
  itilerow = b->size[0] * b->size[1];
  i4 = (int)varargin_1;
  b->size[0] = i4;
  b->size[1] = 2;
  emxEnsureCapacity_real_T(b, itilerow);
  for (itilerow = 0; itilerow < i4; itilerow++) {
    b->data[itilerow] = a[0];
  }

  for (itilerow = 0; itilerow < i4; itilerow++) {
    b->data[i4 + itilerow] = a[1];
  }
}

/* End of code generation (repmat.c) */
