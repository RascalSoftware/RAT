/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * makeSLDProfileXY.c
 *
 * Code generation for function 'makeSLDProfileXY'
 *
 */

/* Include files */
#include "makeSLDProfileXY.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void binary_expand_op(const emlrtStack *sp, emxArray_real_T *SLD,
                      const emxArray_real_T *airBox, const real_T subBox_data[])
{
  const real_T *airBox_data;
  real_T *SLD_data;
  int32_T i;
  int32_T stride_0_1;
  airBox_data = airBox->data;
  i = SLD->size[0] * SLD->size[1];
  SLD->size[0] = 1;
  SLD->size[1] = 101;
  emxEnsureCapacity_real_T(sp, SLD, i, &fi_emlrtRTEI);
  SLD_data = SLD->data;
  stride_0_1 = (airBox->size[1] != 1);
  for (i = 0; i < 101; i++) {
    SLD_data[SLD->size[0] * i] = airBox_data[i * stride_0_1] + subBox_data[i];
  }
}

/* End of code generation (makeSLDProfileXY.c) */
