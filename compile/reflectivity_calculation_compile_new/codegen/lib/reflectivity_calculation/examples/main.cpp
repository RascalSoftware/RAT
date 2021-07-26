//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// main.cpp
//
// Code generation for function 'main'
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include files
#include "main.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_terminate.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Declarations
static void argInit_1x2_real_T(double result[2]);

static void argInit_1x3_cell_wrap_4(cell_wrap_4 result[3]);

static coder::array<cell_wrap_0, 2U> argInit_1xUnbounded_cell_wrap_0();

static coder::array<cell_wrap_1, 2U> argInit_1xUnbounded_cell_wrap_1();

static coder::array<cell_wrap_2, 2U> argInit_1xUnbounded_cell_wrap_2();

static coder::array<cell_wrap_4, 2U> argInit_1xUnbounded_cell_wrap_4();

static coder::array<cell_wrap_5, 2U> argInit_1xUnbounded_cell_wrap_5();

static coder::array<char, 2U> argInit_1xUnbounded_char_T();

static coder::array<double, 2U> argInit_1xUnbounded_real_T();

static void argInit_1xd10_real_T(double result_data[], int result_size[2]);

static coder::array<cell_wrap_3, 1U> argInit_Unboundedx1_cell_wrap_3();

static coder::array<double, 2U> argInit_Unboundedx2_real_T();

static coder::array<double, 2U> argInit_UnboundedxUnbounded_real_T();

static void argInit_cell_6(cell_6 *result);

static cell_wrap_0 argInit_cell_wrap_0();

static cell_wrap_1 argInit_cell_wrap_1();

static cell_wrap_2 argInit_cell_wrap_2();

static void argInit_cell_wrap_3(cell_wrap_3 *result);

static cell_wrap_4 argInit_cell_wrap_4();

static void argInit_cell_wrap_5(cell_wrap_5 *result);

static char argInit_char_T();

static double argInit_real_T();

static void argInit_struct0_T(struct0_T *result);

static void argInit_struct1_T(struct1_T *result);

static void argInit_struct2_T(struct2_T *result);

static void argInit_struct3_T(struct3_T *result);

static void construct(const coder::array<cell_wrap_0, 2U> &f1,
                      const coder::array<cell_wrap_1, 2U> &f2,
                      const coder::array<cell_wrap_0, 2U> &f3,
                      const coder::array<cell_wrap_0, 2U> &f4,
                      const coder::array<cell_wrap_2, 2U> &f5,
                      const coder::array<cell_wrap_3, 1U> &f6,
                      const coder::array<cell_wrap_4, 2U> &f7,
                      const coder::array<cell_wrap_4, 2U> &f8,
                      const coder::array<cell_wrap_4, 2U> &f9,
                      const coder::array<cell_wrap_4, 2U> &f10,
                      const coder::array<cell_wrap_4, 2U> &f11,
                      const coder::array<cell_wrap_4, 2U> &f12,
                      const coder::array<cell_wrap_4, 2U> &f13,
                      const coder::array<cell_wrap_5, 2U> &f14, cell_6 *b);

static void construct(const cell_wrap_4 f1[3], cell_wrap_5 *b);

static void construct(const coder::array<char, 2U> &f1, cell_wrap_4 *b);

static void construct(const coder::array<double, 2U> &params,
                      const coder::array<double, 2U> &backs,
                      const coder::array<double, 2U> &scales,
                      const coder::array<double, 2U> &shifts,
                      const coder::array<double, 2U> &nba,
                      const coder::array<double, 2U> &nbs,
                      const coder::array<double, 2U> &res, struct1_T *b);

static void construct(const coder::array<char, 2U> &para,
                      const coder::array<char, 2U> &proc,
                      const coder::array<char, 2U> &display, double tolX,
                      double tolFun, double maxFunEvals, double maxIter,
                      double populationSize, double F_weight, double F_CR,
                      double VTR, double numGen, double strategy, double Nlive,
                      double nmcmc, const coder::array<double, 2U> &propScale,
                      double nsTolerance, double calcSld, double repeats,
                      double nsimu, double burnin, const struct3_T *checks,
                      struct2_T *b);

static void construct(const double f1_data[], const int f1_size[2],
                      cell_wrap_3 *b);

static void construct(const coder::array<double, 2U> &f1, cell_wrap_2 *b);

static void construct(const coder::array<double, 2U> &f1, cell_wrap_1 *b);

static cell_wrap_0 construct(const double f1[2]);

static void construct(
    const coder::array<double, 2U> &contrastBacks,
    const coder::array<double, 2U> &contrastBacksType,
    const coder::array<char, 2U> &TF, const coder::array<double, 2U> &resample,
    const coder::array<double, 2U> &dataPresent, double numberOfContrasts,
    const coder::array<char, 2U> &geometry,
    const coder::array<double, 2U> &contrastShifts,
    const coder::array<double, 2U> &contrastScales,
    const coder::array<double, 2U> &contrastNbas,
    const coder::array<double, 2U> &contrastNbss,
    const coder::array<double, 2U> &contrastRes,
    const coder::array<double, 2U> &backs,
    const coder::array<double, 2U> &shifts, const coder::array<double, 2U> &sf,
    const coder::array<double, 2U> &nba, const coder::array<double, 2U> &nbs,
    const coder::array<double, 2U> &res, const coder::array<double, 2U> &params,
    double numberOfLayers, const coder::array<char, 2U> &modelType,
    const coder::array<double, 2U> &contrastCustomFiles,
    const coder::array<double, 2U> &fitpars,
    const coder::array<double, 2U> &otherpars,
    const coder::array<double, 2U> &fitconstr,
    const coder::array<double, 2U> &otherconstr, struct0_T *b);

static void construct(const coder::array<double, 2U> &params_fitYesNo,
                      const coder::array<double, 2U> &backs_fitYesNo,
                      const coder::array<double, 2U> &shifts_fitYesNo,
                      const coder::array<double, 2U> &scales_fitYesNo,
                      const coder::array<double, 2U> &nbairs_fitYesNo,
                      const coder::array<double, 2U> &nbsubs_fitYesNo,
                      const coder::array<double, 2U> &resol_fitYesNo,
                      struct3_T *b);

static void main_reflectivity_calculation();

// Function Definitions
static void argInit_1x2_real_T(double result[2])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x3_cell_wrap_4(cell_wrap_4 result[3])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 1; idx0++) {
    for (int idx1{0}; idx1 < 3; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1] = argInit_cell_wrap_4();
    }
  }
}

static coder::array<cell_wrap_0, 2U> argInit_1xUnbounded_cell_wrap_0()
{
  coder::array<cell_wrap_0, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 1; idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1] = argInit_cell_wrap_0();
    }
  }
  return result;
}

static coder::array<cell_wrap_1, 2U> argInit_1xUnbounded_cell_wrap_1()
{
  coder::array<cell_wrap_1, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 1; idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1] = argInit_cell_wrap_1();
    }
  }
  return result;
}

static coder::array<cell_wrap_2, 2U> argInit_1xUnbounded_cell_wrap_2()
{
  coder::array<cell_wrap_2, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 1; idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1] = argInit_cell_wrap_2();
    }
  }
  return result;
}

static coder::array<cell_wrap_4, 2U> argInit_1xUnbounded_cell_wrap_4()
{
  coder::array<cell_wrap_4, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 1; idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1] = argInit_cell_wrap_4();
    }
  }
  return result;
}

static coder::array<cell_wrap_5, 2U> argInit_1xUnbounded_cell_wrap_5()
{
  coder::array<cell_wrap_5, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 1; idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      argInit_cell_wrap_5(&result[idx1]);
    }
  }
  return result;
}

static coder::array<char, 2U> argInit_1xUnbounded_char_T()
{
  coder::array<char, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 1; idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1] = argInit_char_T();
    }
  }
  return result;
}

static coder::array<double, 2U> argInit_1xUnbounded_real_T()
{
  coder::array<double, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(1, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 1; idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx1] = argInit_real_T();
    }
  }
  return result;
}

static void argInit_1xd10_real_T(double result_data[], int result_size[2])
{
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result_size[0] = 1;
  result_size[1] = 2;
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_data[idx1] = argInit_real_T();
  }
}

static coder::array<cell_wrap_3, 1U> argInit_Unboundedx1_cell_wrap_3()
{
  coder::array<cell_wrap_3, 1U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    argInit_cell_wrap_3(&result[idx0]);
  }
  return result;
}

static coder::array<double, 2U> argInit_Unboundedx2_real_T()
{
  coder::array<double, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < 2; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + result.size(0) * idx1] = argInit_real_T();
    }
  }
  return result;
}

static coder::array<double, 2U> argInit_UnboundedxUnbounded_real_T()
{
  coder::array<double, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + result.size(0) * idx1] = argInit_real_T();
    }
  }
  return result;
}

static void argInit_cell_6(cell_6 *result)
{
  coder::array<cell_wrap_0, 2U> r;
  coder::array<cell_wrap_1, 2U> r1;
  coder::array<cell_wrap_2, 2U> r2;
  coder::array<cell_wrap_3, 1U> r3;
  coder::array<cell_wrap_4, 2U> r10;
  coder::array<cell_wrap_4, 2U> r4;
  coder::array<cell_wrap_4, 2U> r5;
  coder::array<cell_wrap_4, 2U> r6;
  coder::array<cell_wrap_4, 2U> r7;
  coder::array<cell_wrap_4, 2U> r8;
  coder::array<cell_wrap_4, 2U> r9;
  coder::array<cell_wrap_5, 2U> r11;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  r = argInit_1xUnbounded_cell_wrap_0();
  r1 = argInit_1xUnbounded_cell_wrap_1();
  r2 = argInit_1xUnbounded_cell_wrap_2();
  r3 = argInit_Unboundedx1_cell_wrap_3();
  r4 = argInit_1xUnbounded_cell_wrap_4();
  r5 = argInit_1xUnbounded_cell_wrap_4();
  r6 = argInit_1xUnbounded_cell_wrap_4();
  r7 = argInit_1xUnbounded_cell_wrap_4();
  r8 = argInit_1xUnbounded_cell_wrap_4();
  r9 = argInit_1xUnbounded_cell_wrap_4();
  r10 = argInit_1xUnbounded_cell_wrap_4();
  r11 = argInit_1xUnbounded_cell_wrap_5();
  construct(r, r1, r, r, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, result);
}

static cell_wrap_0 argInit_cell_wrap_0()
{
  double b_dv[2];
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_1x2_real_T(b_dv);
  return construct(b_dv);
}

static cell_wrap_1 argInit_cell_wrap_1()
{
  coder::array<double, 2U> r;
  cell_wrap_1 result;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  r = argInit_UnboundedxUnbounded_real_T();
  construct(r, &result);
  return result;
}

static cell_wrap_2 argInit_cell_wrap_2()
{
  coder::array<double, 2U> r;
  cell_wrap_2 result;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  r = argInit_1xUnbounded_real_T();
  construct(r, &result);
  return result;
}

static void argInit_cell_wrap_3(cell_wrap_3 *result)
{
  double tmp_data[10];
  int tmp_size[2];
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_1xd10_real_T(tmp_data, tmp_size);
  construct(tmp_data, tmp_size, result);
}

static cell_wrap_4 argInit_cell_wrap_4()
{
  coder::array<char, 2U> r;
  cell_wrap_4 result;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  r = argInit_1xUnbounded_char_T();
  construct(r, &result);
  return result;
}

static void argInit_cell_wrap_5(cell_wrap_5 *result)
{
  cell_wrap_4 rv[3];
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_1x3_cell_wrap_4(rv);
  construct(rv, result);
}

static char argInit_char_T()
{
  return '?';
}

static double argInit_real_T()
{
  return 0.0;
}

static void argInit_struct0_T(struct0_T *result)
{
  coder::array<double, 2U> r;
  coder::array<double, 2U> r2;
  coder::array<char, 2U> r1;
  double result_tmp;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  r = argInit_1xUnbounded_real_T();
  r1 = argInit_1xUnbounded_char_T();
  r2 = argInit_UnboundedxUnbounded_real_T();
  construct(r, r, r1, r, r, result_tmp, r1, r, r, r, r, r, r, r, r, r, r, r, r,
            result_tmp, r1, r, r2, r2, r2, r2, result);
}

static void argInit_struct1_T(struct1_T *result)
{
  coder::array<double, 2U> r;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  r = argInit_Unboundedx2_real_T();
  construct(r, r, r, r, r, r, r, result);
}

static void argInit_struct2_T(struct2_T *result)
{
  coder::array<double, 2U> r1;
  coder::array<char, 2U> r;
  struct3_T r2;
  double result_tmp;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  r = argInit_1xUnbounded_char_T();
  r1 = argInit_1xUnbounded_real_T();
  argInit_struct3_T(&r2);
  construct(r, r, r, result_tmp, result_tmp, result_tmp, result_tmp, result_tmp,
            result_tmp, result_tmp, result_tmp, result_tmp, result_tmp,
            result_tmp, result_tmp, r1, result_tmp, result_tmp, result_tmp,
            result_tmp, result_tmp, &r2, result);
}

static void argInit_struct3_T(struct3_T *result)
{
  coder::array<double, 2U> r;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  r = argInit_1xUnbounded_real_T();
  construct(r, r, r, r, r, r, r, result);
}

static void construct(const cell_wrap_4 f1[3], cell_wrap_5 *b)
{
  b->f1[0] = f1[0];
  b->f1[1] = f1[1];
  b->f1[2] = f1[2];
}

static void construct(const coder::array<cell_wrap_0, 2U> &f1,
                      const coder::array<cell_wrap_1, 2U> &f2,
                      const coder::array<cell_wrap_0, 2U> &f3,
                      const coder::array<cell_wrap_0, 2U> &f4,
                      const coder::array<cell_wrap_2, 2U> &f5,
                      const coder::array<cell_wrap_3, 1U> &f6,
                      const coder::array<cell_wrap_4, 2U> &f7,
                      const coder::array<cell_wrap_4, 2U> &f8,
                      const coder::array<cell_wrap_4, 2U> &f9,
                      const coder::array<cell_wrap_4, 2U> &f10,
                      const coder::array<cell_wrap_4, 2U> &f11,
                      const coder::array<cell_wrap_4, 2U> &f12,
                      const coder::array<cell_wrap_4, 2U> &f13,
                      const coder::array<cell_wrap_5, 2U> &f14, cell_6 *b)
{
  int i;
  int loop_ub;
  b->f1.set_size(1, f1.size(1));
  loop_ub = f1.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f1[i] = f1[i];
  }
  b->f2.set_size(1, f2.size(1));
  loop_ub = f2.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f2[i] = f2[i];
  }
  b->f3.set_size(1, f3.size(1));
  loop_ub = f3.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f3[i] = f3[i];
  }
  b->f4.set_size(1, f4.size(1));
  loop_ub = f4.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f4[i] = f4[i];
  }
  b->f5.set_size(1, f5.size(1));
  loop_ub = f5.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f5[i] = f5[i];
  }
  b->f6.set_size(f6.size(0));
  loop_ub = f6.size(0);
  for (i = 0; i < loop_ub; i++) {
    b->f6[i] = f6[i];
  }
  b->f7.set_size(1, f7.size(1));
  loop_ub = f7.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f7[i] = f7[i];
  }
  b->f8.set_size(1, f8.size(1));
  loop_ub = f8.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f8[i] = f8[i];
  }
  b->f9.set_size(1, f9.size(1));
  loop_ub = f9.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f9[i] = f9[i];
  }
  b->f10.set_size(1, f10.size(1));
  loop_ub = f10.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f10[i] = f10[i];
  }
  b->f11.set_size(1, f11.size(1));
  loop_ub = f11.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f11[i] = f11[i];
  }
  b->f12.set_size(1, f12.size(1));
  loop_ub = f12.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f12[i] = f12[i];
  }
  b->f13.set_size(1, f13.size(1));
  loop_ub = f13.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f13[i] = f13[i];
  }
  b->f14.set_size(1, f14.size(1));
  loop_ub = f14.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->f14[i] = f14[i];
  }
}

static void construct(const coder::array<char, 2U> &f1, cell_wrap_4 *b)
{
  int loop_ub;
  b->f1.set_size(1, f1.size(1));
  loop_ub = f1.size(1);
  for (int i{0}; i < loop_ub; i++) {
    b->f1[i] = f1[i];
  }
}

static void construct(const coder::array<char, 2U> &para,
                      const coder::array<char, 2U> &proc,
                      const coder::array<char, 2U> &display, double tolX,
                      double tolFun, double maxFunEvals, double maxIter,
                      double populationSize, double F_weight, double F_CR,
                      double VTR, double numGen, double strategy, double Nlive,
                      double nmcmc, const coder::array<double, 2U> &propScale,
                      double nsTolerance, double calcSld, double repeats,
                      double nsimu, double burnin, const struct3_T *checks,
                      struct2_T *b)
{
  int i;
  int loop_ub;
  b->para.set_size(1, para.size(1));
  loop_ub = para.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->para[i] = para[i];
  }
  b->proc.set_size(1, proc.size(1));
  loop_ub = proc.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->proc[i] = proc[i];
  }
  b->display.set_size(1, display.size(1));
  loop_ub = display.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->display[i] = display[i];
  }
  b->tolX = tolX;
  b->tolFun = tolFun;
  b->maxFunEvals = maxFunEvals;
  b->maxIter = maxIter;
  b->populationSize = populationSize;
  b->F_weight = F_weight;
  b->F_CR = F_CR;
  b->VTR = VTR;
  b->numGen = numGen;
  b->strategy = strategy;
  b->Nlive = Nlive;
  b->nmcmc = nmcmc;
  b->propScale.set_size(1, propScale.size(1));
  loop_ub = propScale.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->propScale[i] = propScale[i];
  }
  b->nsTolerance = nsTolerance;
  b->calcSld = calcSld;
  b->repeats = repeats;
  b->nsimu = nsimu;
  b->burnin = burnin;
  b->checks = *checks;
}

static void construct(const coder::array<double, 2U> &params,
                      const coder::array<double, 2U> &backs,
                      const coder::array<double, 2U> &scales,
                      const coder::array<double, 2U> &shifts,
                      const coder::array<double, 2U> &nba,
                      const coder::array<double, 2U> &nbs,
                      const coder::array<double, 2U> &res, struct1_T *b)
{
  int i;
  int loop_ub;
  b->params.set_size(params.size(0), 2);
  loop_ub = params.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b->params[i] = params[i];
  }
  b->backs.set_size(backs.size(0), 2);
  loop_ub = backs.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b->backs[i] = backs[i];
  }
  b->scales.set_size(scales.size(0), 2);
  loop_ub = scales.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b->scales[i] = scales[i];
  }
  b->shifts.set_size(shifts.size(0), 2);
  loop_ub = shifts.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b->shifts[i] = shifts[i];
  }
  b->nba.set_size(nba.size(0), 2);
  loop_ub = nba.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b->nba[i] = nba[i];
  }
  b->nbs.set_size(nbs.size(0), 2);
  loop_ub = nbs.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b->nbs[i] = nbs[i];
  }
  b->res.set_size(res.size(0), 2);
  loop_ub = res.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b->res[i] = res[i];
  }
}

static void construct(const coder::array<double, 2U> &f1, cell_wrap_2 *b)
{
  int loop_ub;
  b->f1.set_size(1, f1.size(1));
  loop_ub = f1.size(1);
  for (int i{0}; i < loop_ub; i++) {
    b->f1[i] = f1[i];
  }
}

static void construct(const coder::array<double, 2U> &f1, cell_wrap_1 *b)
{
  int loop_ub;
  b->f1.set_size(f1.size(0), f1.size(1));
  loop_ub = f1.size(0) * f1.size(1);
  for (int i{0}; i < loop_ub; i++) {
    b->f1[i] = f1[i];
  }
}

static cell_wrap_0 construct(const double f1[2])
{
  cell_wrap_0 b;
  b.f1[0] = f1[0];
  b.f1[1] = f1[1];
  return b;
}

static void construct(
    const coder::array<double, 2U> &contrastBacks,
    const coder::array<double, 2U> &contrastBacksType,
    const coder::array<char, 2U> &TF, const coder::array<double, 2U> &resample,
    const coder::array<double, 2U> &dataPresent, double numberOfContrasts,
    const coder::array<char, 2U> &geometry,
    const coder::array<double, 2U> &contrastShifts,
    const coder::array<double, 2U> &contrastScales,
    const coder::array<double, 2U> &contrastNbas,
    const coder::array<double, 2U> &contrastNbss,
    const coder::array<double, 2U> &contrastRes,
    const coder::array<double, 2U> &backs,
    const coder::array<double, 2U> &shifts, const coder::array<double, 2U> &sf,
    const coder::array<double, 2U> &nba, const coder::array<double, 2U> &nbs,
    const coder::array<double, 2U> &res, const coder::array<double, 2U> &params,
    double numberOfLayers, const coder::array<char, 2U> &modelType,
    const coder::array<double, 2U> &contrastCustomFiles,
    const coder::array<double, 2U> &fitpars,
    const coder::array<double, 2U> &otherpars,
    const coder::array<double, 2U> &fitconstr,
    const coder::array<double, 2U> &otherconstr, struct0_T *b)
{
  int i;
  int loop_ub;
  b->contrastBacks.set_size(1, contrastBacks.size(1));
  loop_ub = contrastBacks.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->contrastBacks[i] = contrastBacks[i];
  }
  b->contrastBacksType.set_size(1, contrastBacksType.size(1));
  loop_ub = contrastBacksType.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->contrastBacksType[i] = contrastBacksType[i];
  }
  b->TF.set_size(1, TF.size(1));
  loop_ub = TF.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->TF[i] = TF[i];
  }
  b->resample.set_size(1, resample.size(1));
  loop_ub = resample.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->resample[i] = resample[i];
  }
  b->dataPresent.set_size(1, dataPresent.size(1));
  loop_ub = dataPresent.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->dataPresent[i] = dataPresent[i];
  }
  b->numberOfContrasts = numberOfContrasts;
  b->geometry.set_size(1, geometry.size(1));
  loop_ub = geometry.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->geometry[i] = geometry[i];
  }
  b->contrastShifts.set_size(1, contrastShifts.size(1));
  loop_ub = contrastShifts.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->contrastShifts[i] = contrastShifts[i];
  }
  b->contrastScales.set_size(1, contrastScales.size(1));
  loop_ub = contrastScales.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->contrastScales[i] = contrastScales[i];
  }
  b->contrastNbas.set_size(1, contrastNbas.size(1));
  loop_ub = contrastNbas.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->contrastNbas[i] = contrastNbas[i];
  }
  b->contrastNbss.set_size(1, contrastNbss.size(1));
  loop_ub = contrastNbss.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->contrastNbss[i] = contrastNbss[i];
  }
  b->contrastRes.set_size(1, contrastRes.size(1));
  loop_ub = contrastRes.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->contrastRes[i] = contrastRes[i];
  }
  b->backs.set_size(1, backs.size(1));
  loop_ub = backs.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->backs[i] = backs[i];
  }
  b->shifts.set_size(1, shifts.size(1));
  loop_ub = shifts.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->shifts[i] = shifts[i];
  }
  b->sf.set_size(1, sf.size(1));
  loop_ub = sf.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->sf[i] = sf[i];
  }
  b->nba.set_size(1, nba.size(1));
  loop_ub = nba.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->nba[i] = nba[i];
  }
  b->nbs.set_size(1, nbs.size(1));
  loop_ub = nbs.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->nbs[i] = nbs[i];
  }
  b->res.set_size(1, res.size(1));
  loop_ub = res.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->res[i] = res[i];
  }
  b->params.set_size(1, params.size(1));
  loop_ub = params.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->params[i] = params[i];
  }
  b->numberOfLayers = numberOfLayers;
  b->modelType.set_size(1, modelType.size(1));
  loop_ub = modelType.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->modelType[i] = modelType[i];
  }
  b->contrastCustomFiles.set_size(1, contrastCustomFiles.size(1));
  loop_ub = contrastCustomFiles.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->contrastCustomFiles[i] = contrastCustomFiles[i];
  }
  b->fitpars.set_size(fitpars.size(0), fitpars.size(1));
  loop_ub = fitpars.size(0) * fitpars.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->fitpars[i] = fitpars[i];
  }
  b->otherpars.set_size(otherpars.size(0), otherpars.size(1));
  loop_ub = otherpars.size(0) * otherpars.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->otherpars[i] = otherpars[i];
  }
  b->fitconstr.set_size(fitconstr.size(0), fitconstr.size(1));
  loop_ub = fitconstr.size(0) * fitconstr.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->fitconstr[i] = fitconstr[i];
  }
  b->otherconstr.set_size(otherconstr.size(0), otherconstr.size(1));
  loop_ub = otherconstr.size(0) * otherconstr.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->otherconstr[i] = otherconstr[i];
  }
}

static void construct(const double f1_data[], const int f1_size[2],
                      cell_wrap_3 *b)
{
  int loop_ub;
  b->f1.size[0] = 1;
  b->f1.size[1] = f1_size[1];
  loop_ub = f1_size[1];
  if (0 <= loop_ub - 1) {
    std::copy(&f1_data[0], &f1_data[loop_ub], &b->f1.data[0]);
  }
}

static void construct(const coder::array<double, 2U> &params_fitYesNo,
                      const coder::array<double, 2U> &backs_fitYesNo,
                      const coder::array<double, 2U> &shifts_fitYesNo,
                      const coder::array<double, 2U> &scales_fitYesNo,
                      const coder::array<double, 2U> &nbairs_fitYesNo,
                      const coder::array<double, 2U> &nbsubs_fitYesNo,
                      const coder::array<double, 2U> &resol_fitYesNo,
                      struct3_T *b)
{
  int i;
  int loop_ub;
  b->params_fitYesNo.set_size(1, params_fitYesNo.size(1));
  loop_ub = params_fitYesNo.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->params_fitYesNo[i] = params_fitYesNo[i];
  }
  b->backs_fitYesNo.set_size(1, backs_fitYesNo.size(1));
  loop_ub = backs_fitYesNo.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->backs_fitYesNo[i] = backs_fitYesNo[i];
  }
  b->shifts_fitYesNo.set_size(1, shifts_fitYesNo.size(1));
  loop_ub = shifts_fitYesNo.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->shifts_fitYesNo[i] = shifts_fitYesNo[i];
  }
  b->scales_fitYesNo.set_size(1, scales_fitYesNo.size(1));
  loop_ub = scales_fitYesNo.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->scales_fitYesNo[i] = scales_fitYesNo[i];
  }
  b->nbairs_fitYesNo.set_size(1, nbairs_fitYesNo.size(1));
  loop_ub = nbairs_fitYesNo.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->nbairs_fitYesNo[i] = nbairs_fitYesNo[i];
  }
  b->nbsubs_fitYesNo.set_size(1, nbsubs_fitYesNo.size(1));
  loop_ub = nbsubs_fitYesNo.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->nbsubs_fitYesNo[i] = nbsubs_fitYesNo[i];
  }
  b->resol_fitYesNo.set_size(1, resol_fitYesNo.size(1));
  loop_ub = resol_fitYesNo.size(1);
  for (i = 0; i < loop_ub; i++) {
    b->resol_fitYesNo[i] = resol_fitYesNo[i];
  }
}

static void main_reflectivity_calculation()
{
  cell_6 problemDef_cells;
  cell_9 result;
  struct0_T problemDef;
  struct1_T problemDef_limits;
  struct2_T controls;
  struct4_T problem;
  // Initialize function 'reflectivity_calculation' input arguments.
  // Initialize function input argument 'problemDef'.
  argInit_struct0_T(&problemDef);
  // Initialize function input argument 'problemDef_cells'.
  argInit_cell_6(&problemDef_cells);
  // Initialize function input argument 'problemDef_limits'.
  argInit_struct1_T(&problemDef_limits);
  // Initialize function input argument 'controls'.
  argInit_struct2_T(&controls);
  // Call the entry-point 'reflectivity_calculation'.
  reflectivity_calculation(&problemDef, &problemDef_cells, &problemDef_limits,
                           &controls, &problem, &result);
}

int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_reflectivity_calculation();
  // Terminate the application.
  // You do not need to do this more than one time.
  reflectivity_calculation_terminate();
  return 0;
}

// End of code generation (main.cpp)
