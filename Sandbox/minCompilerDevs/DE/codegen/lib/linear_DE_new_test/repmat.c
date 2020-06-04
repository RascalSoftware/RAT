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
#include "linear_DE_new_test.h"
#include "repmat.h"

/* Function Definitions */
void repmat(struct_T b_data[], int b_size[1])
{
  int i1;
  b_size[0] = 20;
  for (i1 = 0; i1 < 20; i1++) {
    b_data[i1].I_nc = 0.0;
    b_data[i1].FVr_ca = 0.0;
    b_data[i1].I_no = 0.0;
    b_data[i1].FVr_oa = 0.0;
  }
}

/* End of code generation (repmat.c) */
