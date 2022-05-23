/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * customBilayer.h
 *
 * Code generation for function 'customBilayer'
 *
 */

#ifndef CUSTOMBILAYER_H
#define CUSTOMBILAYER_H

/* Include files */
#include "customBilayer_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void customBilayer(const emxArray_real_T *params, double bulk_in,
                          double bulk_out, double contrast, double output[18],
                          double *sub_rough);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (customBilayer.h) */
