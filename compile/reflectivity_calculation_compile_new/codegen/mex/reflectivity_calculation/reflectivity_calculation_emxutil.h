/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * reflectivity_calculation_emxutil.h
 *
 * Code generation for function 'reflectivity_calculation_emxutil'
 *
 */

#pragma once

/* Include files */
#include "reflectivity_calculation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void emxCopyMatrix_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 dst[3],
                               const cell_wrap_6 src[3],
                               const emlrtRTEInfo *srcLocation);

void emxCopyStruct_cell_wrap_14(const emlrtStack *sp, cell_wrap_14 *dst,
                                const cell_wrap_14 *src,
                                const emlrtRTEInfo *srcLocation);

void emxCopyStruct_cell_wrap_5(const emlrtStack *sp, cell_wrap_5 *dst,
                               const cell_wrap_5 *src,
                               const emlrtRTEInfo *srcLocation);

void emxCopyStruct_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 *dst,
                               const cell_wrap_6 *src,
                               const emlrtRTEInfo *srcLocation);

void emxCopyStruct_cell_wrap_7(const emlrtStack *sp, cell_wrap_7 *dst,
                               const cell_wrap_7 *src,
                               const emlrtRTEInfo *srcLocation);

void emxCopyStruct_cell_wrap_9(const emlrtStack *sp, cell_wrap_9 *dst,
                               const cell_wrap_9 *src,
                               const emlrtRTEInfo *srcLocation);

void emxCopyStruct_struct5_T(const emlrtStack *sp, struct5_T *dst,
                             const struct5_T *src,
                             const emlrtRTEInfo *srcLocation);

void emxCopy_char_T(const emlrtStack *sp, emxArray_char_T **dst,
                    emxArray_char_T *const *src,
                    const emlrtRTEInfo *srcLocation);

void emxCopy_real_T(const emlrtStack *sp, emxArray_real_T **dst,
                    emxArray_real_T *const *src,
                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
                                 emxArray_boolean_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_0(const emlrtStack *sp,
                                   emxArray_cell_wrap_0 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_1(const emlrtStack *sp,
                                   emxArray_cell_wrap_1 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_10(const emlrtStack *sp,
                                    emxArray_cell_wrap_10 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_12(const emlrtStack *sp,
                                    emxArray_cell_wrap_12 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_13(const emlrtStack *sp,
                                    emxArray_cell_wrap_13 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_14(const emlrtStack *sp,
                                    emxArray_cell_wrap_14 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_17(const emlrtStack *sp,
                                    emxArray_cell_wrap_17 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_2(const emlrtStack *sp,
                                   emxArray_cell_wrap_2 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_27(const emlrtStack *sp,
                                    emxArray_cell_wrap_27 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_28(const emlrtStack *sp,
                                    emxArray_cell_wrap_28 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_29(const emlrtStack *sp,
                                    emxArray_cell_wrap_29 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_3(const emlrtStack *sp,
                                   emxArray_cell_wrap_3 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_4(const emlrtStack *sp,
                                   emxArray_cell_wrap_4 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_5(const emlrtStack *sp,
                                   emxArray_cell_wrap_5 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_6(const emlrtStack *sp,
                                   emxArray_cell_wrap_6 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_7(const emlrtStack *sp,
                                   emxArray_cell_wrap_7 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_9(const emlrtStack *sp,
                                   emxArray_cell_wrap_9 *emxArray,
                                   int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_char_T(const emlrtStack *sp, emxArray_char_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_int8_T(const emlrtStack *sp, emxArray_int8_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_10(const emlrtStack *sp,
                            emxArray_cell_wrap_10 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_12(const emlrtStack *sp,
                            emxArray_cell_wrap_12 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_13(const emlrtStack *sp,
                            emxArray_cell_wrap_13 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_14(const emlrtStack *sp,
                            emxArray_cell_wrap_14 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_2(emxArray_cell_wrap_2 *emxArray, int32_T fromIndex,
                           int32_T toIndex);

void emxExpand_cell_wrap_28(const emlrtStack *sp,
                            emxArray_cell_wrap_28 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_29(const emlrtStack *sp,
                            emxArray_cell_wrap_29 *emxArray, int32_T fromIndex,
                            int32_T toIndex, const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_4(emxArray_cell_wrap_4 *emxArray, int32_T fromIndex,
                           int32_T toIndex);

void emxExpand_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_6(const emlrtStack *sp, emxArray_cell_wrap_6 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_7(const emlrtStack *sp, emxArray_cell_wrap_7 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation);

void emxFreeMatrix_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 pMatrix[3]);

void emxFreeStruct_cell_11(const emlrtStack *sp, cell_11 *pStruct);

void emxFreeStruct_cell_16(const emlrtStack *sp, cell_16 *pStruct);

void emxFreeStruct_cell_19(const emlrtStack *sp, cell_19 *pStruct);

void emxFreeStruct_cell_8(const emlrtStack *sp, cell_8 *pStruct);

void emxFreeStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct);

void emxFreeStruct_cell_wrap_10(const emlrtStack *sp, cell_wrap_10 *pStruct);

void emxFreeStruct_cell_wrap_12(const emlrtStack *sp, cell_wrap_12 *pStruct);

void emxFreeStruct_cell_wrap_13(const emlrtStack *sp, cell_wrap_13 *pStruct);

void emxFreeStruct_cell_wrap_14(const emlrtStack *sp, cell_wrap_14 *pStruct);

void emxFreeStruct_cell_wrap_28(const emlrtStack *sp, cell_wrap_28 *pStruct);

void emxFreeStruct_cell_wrap_29(const emlrtStack *sp, cell_wrap_29 *pStruct);

void emxFreeStruct_cell_wrap_3(const emlrtStack *sp, cell_wrap_3 *pStruct);

void emxFreeStruct_cell_wrap_5(const emlrtStack *sp, cell_wrap_5 *pStruct);

void emxFreeStruct_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 *pStruct);

void emxFreeStruct_cell_wrap_7(const emlrtStack *sp, cell_wrap_7 *pStruct);

void emxFreeStruct_cell_wrap_9(const emlrtStack *sp, cell_wrap_9 *pStruct);

void emxFreeStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct);

void emxFreeStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct);

void emxFreeStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct);

void emxFreeStruct_struct3_T(const emlrtStack *sp, struct3_T *pStruct);

void emxFreeStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct);

void emxFreeStruct_struct5_T(const emlrtStack *sp, struct5_T *pStruct);

void emxFreeStruct_struct_T(const emlrtStack *sp, struct_T *pStruct);

void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray);

void emxFree_cell_wrap_0(const emlrtStack *sp,
                         emxArray_cell_wrap_0 **pEmxArray);

void emxFree_cell_wrap_1(const emlrtStack *sp,
                         emxArray_cell_wrap_1 **pEmxArray);

void emxFree_cell_wrap_10(const emlrtStack *sp,
                          emxArray_cell_wrap_10 **pEmxArray);

void emxFree_cell_wrap_12(const emlrtStack *sp,
                          emxArray_cell_wrap_12 **pEmxArray);

void emxFree_cell_wrap_13(const emlrtStack *sp,
                          emxArray_cell_wrap_13 **pEmxArray);

void emxFree_cell_wrap_14(const emlrtStack *sp,
                          emxArray_cell_wrap_14 **pEmxArray);

void emxFree_cell_wrap_17(const emlrtStack *sp,
                          emxArray_cell_wrap_17 **pEmxArray);

void emxFree_cell_wrap_2(const emlrtStack *sp,
                         emxArray_cell_wrap_2 **pEmxArray);

void emxFree_cell_wrap_27(const emlrtStack *sp,
                          emxArray_cell_wrap_27 **pEmxArray);

void emxFree_cell_wrap_28(const emlrtStack *sp,
                          emxArray_cell_wrap_28 **pEmxArray);

void emxFree_cell_wrap_29(const emlrtStack *sp,
                          emxArray_cell_wrap_29 **pEmxArray);

void emxFree_cell_wrap_3(const emlrtStack *sp,
                         emxArray_cell_wrap_3 **pEmxArray);

void emxFree_cell_wrap_4(const emlrtStack *sp,
                         emxArray_cell_wrap_4 **pEmxArray);

void emxFree_cell_wrap_5(const emlrtStack *sp,
                         emxArray_cell_wrap_5 **pEmxArray);

void emxFree_cell_wrap_6(const emlrtStack *sp,
                         emxArray_cell_wrap_6 **pEmxArray);

void emxFree_cell_wrap_7(const emlrtStack *sp,
                         emxArray_cell_wrap_7 **pEmxArray);

void emxFree_cell_wrap_9(const emlrtStack *sp,
                         emxArray_cell_wrap_9 **pEmxArray);

void emxFree_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray);

void emxFree_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray);

void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray);

void emxFree_int8_T(const emlrtStack *sp, emxArray_int8_T **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxInitMatrix_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 pMatrix[3],
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush);

void emxInitStruct_cell_11(const emlrtStack *sp, cell_11 *pStruct,
                           const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_16(const emlrtStack *sp, cell_16 *pStruct,
                           const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_19(const emlrtStack *sp, cell_19 *pStruct,
                           const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_8(const emlrtStack *sp, cell_8 *pStruct,
                          const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct,
                               const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_10(const emlrtStack *sp, cell_wrap_10 *pStruct,
                                const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_12(const emlrtStack *sp, cell_wrap_12 *pStruct,
                                const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_13(const emlrtStack *sp, cell_wrap_13 *pStruct,
                                const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_14(const emlrtStack *sp, cell_wrap_14 *pStruct,
                                const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_2(cell_wrap_2 *pStruct);

void emxInitStruct_cell_wrap_28(const emlrtStack *sp, cell_wrap_28 *pStruct,
                                const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_29(const emlrtStack *sp, cell_wrap_29 *pStruct,
                                const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_3(const emlrtStack *sp, cell_wrap_3 *pStruct,
                               const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_4(cell_wrap_4 *pStruct);

void emxInitStruct_cell_wrap_5(const emlrtStack *sp, cell_wrap_5 *pStruct,
                               const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_6(const emlrtStack *sp, cell_wrap_6 *pStruct,
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush);

void emxInitStruct_cell_wrap_7(const emlrtStack *sp, cell_wrap_7 *pStruct,
                               const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_9(const emlrtStack *sp, cell_wrap_9 *pStruct,
                               const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct3_T(const emlrtStack *sp, struct3_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct5_T(const emlrtStack *sp, struct5_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct_T(const emlrtStack *sp, struct_T *pStruct,
                            const emlrtRTEInfo *srcLocation);

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_10(const emlrtStack *sp,
                          emxArray_cell_wrap_10 **pEmxArray,
                          const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_12(const emlrtStack *sp,
                          emxArray_cell_wrap_12 **pEmxArray,
                          const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_13(const emlrtStack *sp,
                          emxArray_cell_wrap_13 **pEmxArray,
                          const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_14(const emlrtStack *sp,
                          emxArray_cell_wrap_14 **pEmxArray,
                          int32_T numDimensions,
                          const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_17(const emlrtStack *sp,
                          emxArray_cell_wrap_17 **pEmxArray,
                          const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_2(const emlrtStack *sp, emxArray_cell_wrap_2 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_27(const emlrtStack *sp,
                          emxArray_cell_wrap_27 **pEmxArray,
                          const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_28(const emlrtStack *sp,
                          emxArray_cell_wrap_28 **pEmxArray,
                          const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_29(const emlrtStack *sp,
                          emxArray_cell_wrap_29 **pEmxArray,
                          const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_4(const emlrtStack *sp, emxArray_cell_wrap_4 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_6(const emlrtStack *sp, emxArray_cell_wrap_6 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_7(const emlrtStack *sp, emxArray_cell_wrap_7 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation, boolean_T doPush);

void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void emxInit_int8_T(const emlrtStack *sp, emxArray_int8_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation,
                    boolean_T doPush);

void emxTrim_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 *emxArray,
                         int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_10(const emlrtStack *sp, emxArray_cell_wrap_10 *emxArray,
                          int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_12(const emlrtStack *sp, emxArray_cell_wrap_12 *emxArray,
                          int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_13(const emlrtStack *sp, emxArray_cell_wrap_13 *emxArray,
                          int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_14(const emlrtStack *sp, emxArray_cell_wrap_14 *emxArray,
                          int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_28(const emlrtStack *sp, emxArray_cell_wrap_28 *emxArray,
                          int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_29(const emlrtStack *sp, emxArray_cell_wrap_29 *emxArray,
                          int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_3(const emlrtStack *sp, emxArray_cell_wrap_3 *emxArray,
                         int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_5(const emlrtStack *sp, emxArray_cell_wrap_5 *emxArray,
                         int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_6(const emlrtStack *sp, emxArray_cell_wrap_6 *emxArray,
                         int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_7(const emlrtStack *sp, emxArray_cell_wrap_7 *emxArray,
                         int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_9(const emlrtStack *sp, emxArray_cell_wrap_9 *emxArray,
                         int32_T fromIndex, int32_T toIndex);

/* End of code generation (reflectivity_calculation_emxutil.h) */
