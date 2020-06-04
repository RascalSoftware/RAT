/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * oneCellTest.c
 *
 * Code generation for function 'oneCellTest'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "oneCellTest.h"
#include "rand.h"
#include "oneCellTest_emxutil.h"

/* Function Definitions */
void oneCellTest(double cell1Length, emxArray_cell_wrap_0 *outResult)
{
  int i0;
  int i;
  double r;
  int loop_ub;
  int i1;
  i0 = outResult->size[0] * outResult->size[1];
  outResult->size[0] = 1;
  outResult->size[1] = (int)cell1Length;
  emxEnsureCapacity_cell_wrap_0(outResult, i0);
  i0 = outResult->size[1];
  for (i = 0; i < i0; i++) {
    r = b_rand();
    r = 1.0 + floor(r * 10.0);
    outResult->data[outResult->size[0] * i].f1.size[0] = (int)r;
    outResult->data[outResult->size[0] * i].f1.size[1] = 3;
    loop_ub = (int)r * 3;
    for (i1 = 0; i1 < loop_ub; i1++) {
      outResult->data[outResult->size[0] * i].f1.data[i1] = 1.0;
    }
  }
}

/* End of code generation (oneCellTest.c) */
