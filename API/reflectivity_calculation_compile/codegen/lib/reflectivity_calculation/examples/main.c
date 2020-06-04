/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
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
/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "main.h"
#include "reflectivity_calculation_terminate.h"
#include "reflectivity_calculation_emxAPI.h"
#include "reflectivity_calculation_initialize.h"
#include <string.h>

/* Function Declarations */
static void argInit_10x2_real_T(double result[20]);
static void argInit_1x10_char_T(char result[10]);
static void argInit_1x10_real_T(double result[10]);
static void argInit_1x11_char_T(char result[11]);
static void argInit_1x12_char_T(char result[12]);
static void argInit_1x13_char_T(char result[13]);
static void argInit_1x14_char_T(char result[14]);
static void argInit_1x15_char_T(char result[15]);
static void argInit_1x19_char_T(char result[19]);
static void argInit_1x1_cell_wrap_5(cell_wrap_5 result[1]);
static void argInit_1x1_cell_wrap_6(cell_wrap_6 result[1]);
static void argInit_1x1_cell_wrap_7(cell_wrap_7 result[1]);
static void argInit_1x1_cell_wrap_9(cell_wrap_9 result[1]);
static void argInit_1x20_char_T(char result[20]);
static void argInit_1x21_char_T(char result[21]);
static void argInit_1x22_char_T(char result[22]);
static void argInit_1x2_cell_wrap_4(cell_wrap_4 result[2]);
static void argInit_1x2_real_T(double result[2]);
static void argInit_1x3_char_T(char result[3]);
static void argInit_1x4_char_T(char result[4]);
static void argInit_1x5_real_T(double result[5]);
static void argInit_1x64_char_T(char result[64]);
static void argInit_1x6_char_T(char result[6]);
static void argInit_1x7_cell_wrap_0(cell_wrap_0 result[7]);
static void argInit_1x7_cell_wrap_1(cell_wrap_1 result[7]);
static void argInit_1x7_char_T(char result[7]);
static void argInit_1x7_real_T(double result[7]);
static void argInit_2x2_real_T(double result[4]);
static void argInit_4x1_cell_wrap_2(cell_wrap_2 result[4]);
static void argInit_51x3_real_T(double result[153]);
static void argInit_cell_10(cell_10 *result);
static void argInit_cell_3(cell_3 *result);
static cell_8 argInit_cell_8(void);
static cell_wrap_0 argInit_cell_wrap_0(void);
static void argInit_cell_wrap_1(cell_wrap_1 *result);
static cell_wrap_2 argInit_cell_wrap_2(void);
static cell_wrap_4 argInit_cell_wrap_4(void);
static cell_wrap_5 argInit_cell_wrap_5(void);
static cell_wrap_6 argInit_cell_wrap_6(void);
static cell_wrap_7 argInit_cell_wrap_7(void);
static cell_wrap_9 argInit_cell_wrap_9(void);
static char argInit_char_T(void);
static double argInit_real_T(void);
static void argInit_struct0_T(struct0_T *result);
static void argInit_struct1_T(struct1_T *result);
static void argInit_struct2_T(struct2_T *result);
static void argInit_struct3_T(struct3_T *result);
static void main_reflectivity_calculation(void);

/* Function Definitions */
static void argInit_10x2_real_T(double result[20])
{
  int idx0;
  double result_tmp;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 10; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 10] = result_tmp;
  }
}

static void argInit_1x10_char_T(char result[10])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 10; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x10_real_T(double result[10])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 10; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x11_char_T(char result[11])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 11; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x12_char_T(char result[12])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 12; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x13_char_T(char result[13])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 13; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x14_char_T(char result[14])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 14; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x15_char_T(char result[15])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 15; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x19_char_T(char result[19])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 19; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x1_cell_wrap_5(cell_wrap_5 result[1])
{
  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[0] = argInit_cell_wrap_5();
}

static void argInit_1x1_cell_wrap_6(cell_wrap_6 result[1])
{
  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[0] = argInit_cell_wrap_6();
}

static void argInit_1x1_cell_wrap_7(cell_wrap_7 result[1])
{
  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[0] = argInit_cell_wrap_7();
}

static void argInit_1x1_cell_wrap_9(cell_wrap_9 result[1])
{
  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[0] = argInit_cell_wrap_9();
}

static void argInit_1x20_char_T(char result[20])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 20; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x21_char_T(char result[21])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 21; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x22_char_T(char result[22])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 22; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x2_cell_wrap_4(cell_wrap_4 result[2])
{
  cell_wrap_4 result_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp = argInit_cell_wrap_4();
  result[0] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = result_tmp;
}

static void argInit_1x2_real_T(double result[2])
{
  double result_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result[0] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = result_tmp;
}

static void argInit_1x3_char_T(char result[3])
{
  char result_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp = argInit_char_T();
  result[0] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[2] = argInit_char_T();
}

static void argInit_1x4_char_T(char result[4])
{
  char result_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp = argInit_char_T();
  result[0] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[2] = argInit_char_T();

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[3] = argInit_char_T();
}

static void argInit_1x5_real_T(double result[5])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 5; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x64_char_T(char result[64])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 64; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x6_char_T(char result[6])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 6; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x7_cell_wrap_0(cell_wrap_0 result[7])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 7; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_cell_wrap_0();
  }
}

static void argInit_1x7_cell_wrap_1(cell_wrap_1 result[7])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 7; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    argInit_cell_wrap_1(&result[idx1]);
  }
}

static void argInit_1x7_char_T(char result[7])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 7; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x7_real_T(double result[7])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 7; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_2x2_real_T(double result[4])
{
  double result_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result[0] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[2] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = argInit_real_T();

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[3] = argInit_real_T();
}

static void argInit_4x1_cell_wrap_2(cell_wrap_2 result[4])
{
  cell_wrap_2 result_tmp;

  /* Loop over the array to initialize each element. */
  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result_tmp = argInit_cell_wrap_2();
  result[0] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[1] = result_tmp;

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[2] = argInit_cell_wrap_2();

  /* Set the value of the array element.
     Change this value to the value that the application requires. */
  result[3] = argInit_cell_wrap_2();
}

static void argInit_51x3_real_T(double result[153])
{
  int idx0;
  double result_tmp;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 51; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 51] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 102] = argInit_real_T();
  }
}

static void argInit_cell_10(cell_10 *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x7_cell_wrap_0(result->f1);
  argInit_1x7_cell_wrap_1(result->f2);
  argInit_1x7_cell_wrap_0(result->f3);
  argInit_1x7_cell_wrap_0(result->f4);
  argInit_1x7_cell_wrap_0(result->f5);
  argInit_4x1_cell_wrap_2(result->f6);
  argInit_cell_3(&result->f7);
  argInit_1x2_cell_wrap_4(result->f8);
  argInit_1x1_cell_wrap_5(result->f9);
  argInit_1x1_cell_wrap_6(result->f10);
  argInit_1x1_cell_wrap_7(result->f11);
  result->f12 = argInit_cell_8();
  argInit_1x1_cell_wrap_9(result->f13);
}

static void argInit_cell_3(cell_3 *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x19_char_T(result->f1);
  argInit_1x11_char_T(result->f2);
  argInit_1x20_char_T(result->f3);
  argInit_1x15_char_T(result->f4);
  argInit_1x22_char_T(result->f5);
  argInit_1x14_char_T(result->f6);
  argInit_1x19_char_T(result->f7);
  argInit_1x14_char_T(result->f8);
  argInit_1x21_char_T(result->f9);
  argInit_1x14_char_T(result->f10);
}

static cell_8 argInit_cell_8(void)
{
  cell_8 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x3_char_T(result.f1);
  argInit_1x4_char_T(result.f2);
  return result;
}

static cell_wrap_0 argInit_cell_wrap_0(void)
{
  cell_wrap_0 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x2_real_T(result.f1);
  return result;
}

static void argInit_cell_wrap_1(cell_wrap_1 *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_51x3_real_T(result->f1);
}

static cell_wrap_2 argInit_cell_wrap_2(void)
{
  cell_wrap_2 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x5_real_T(result.f1);
  return result;
}

static cell_wrap_4 argInit_cell_wrap_4(void)
{
  cell_wrap_4 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x15_char_T(result.f1);
  return result;
}

static cell_wrap_5 argInit_cell_wrap_5(void)
{
  cell_wrap_5 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x13_char_T(result.f1);
  return result;
}

static cell_wrap_6 argInit_cell_wrap_6(void)
{
  cell_wrap_6 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x11_char_T(result.f1);
  return result;
}

static cell_wrap_7 argInit_cell_wrap_7(void)
{
  cell_wrap_7 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x3_char_T(result.f1);
  return result;
}

static cell_wrap_9 argInit_cell_wrap_9(void)
{
  cell_wrap_9 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x12_char_T(result.f1);
  return result;
}

static char argInit_char_T(void)
{
  return '?';
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void argInit_struct0_T(struct0_T *result)
{
  double result_tmp_tmp[7];
  int i18;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x7_real_T(result_tmp_tmp);
  for (i18 = 0; i18 < 7; i18++) {
    result->contrastBacks[i18] = result_tmp_tmp[i18];
    result->contrastBacksType[i18] = result_tmp_tmp[i18];
  }

  argInit_1x10_char_T(result->TF);
  argInit_1x7_real_T(result->resample);
  argInit_1x7_real_T(result->dataPresent);
  result->numberOfContrasts = argInit_real_T();
  argInit_1x13_char_T(result->geometry);
  argInit_1x7_real_T(result->contrastShifts);
  argInit_1x7_real_T(result->contrastScales);
  argInit_1x7_real_T(result->contrastNbas);
  argInit_1x7_real_T(result->contrastNbss);
  argInit_1x7_real_T(result->contrastRes);
  argInit_1x2_real_T(result->backs);
  result->shifts = argInit_real_T();
  result->sf = argInit_real_T();
  result->nba = argInit_real_T();
  argInit_1x2_real_T(result->nbs);
  result->res = argInit_real_T();
  argInit_1x10_real_T(result->params);
  result->numberOfLayers = argInit_real_T();
  argInit_1x6_char_T(result->modelType);
  argInit_1x64_char_T(result->path);
}

static void argInit_struct1_T(struct1_T *result)
{
  double result_tmp_tmp[2];

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_10x2_real_T(result->params);
  argInit_2x2_real_T(result->backs);
  argInit_1x2_real_T(result_tmp_tmp);
  result->scales[0] = result_tmp_tmp[0];
  result->shifts[0] = result_tmp_tmp[0];
  result->nba[0] = result_tmp_tmp[0];
  result->scales[1] = result_tmp_tmp[1];
  result->shifts[1] = result_tmp_tmp[1];
  result->nba[1] = result_tmp_tmp[1];
  argInit_2x2_real_T(result->nbs);
  argInit_1x2_real_T(result->res);
}

static void argInit_struct2_T(struct2_T *result)
{
  double result_tmp;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x6_char_T(result->para);
  argInit_1x7_char_T(result->proc);
  argInit_1x4_char_T(result->display);
  result_tmp = argInit_real_T();
  result->tolX = result_tmp;
  result->tolFun = result_tmp;
  result->maxFunEvals = argInit_real_T();
  result->maxIter = argInit_real_T();
  result->populationSize = argInit_real_T();
  result->F_weight = argInit_real_T();
  result->F_CR = argInit_real_T();
  result->VTR = argInit_real_T();
  result->numGen = argInit_real_T();
  result->strategy = argInit_real_T();
  result->Nlive = argInit_real_T();
  result->nmcmc = argInit_real_T();
  result->propScale = argInit_real_T();
  result->nsTolerance = argInit_real_T();
  argInit_struct3_T(&result->checks);
}

static void argInit_struct3_T(struct3_T *result)
{
  double result_tmp;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x10_real_T(result->params_fitYesNo);
  argInit_1x2_real_T(result->backs_fitYesNo);
  result_tmp = argInit_real_T();
  result->shifts_fitYesNo = result_tmp;
  result->scales_fitYesNo = result_tmp;
  result->nbairs_fitYesNo = argInit_real_T();
  argInit_1x2_real_T(result->nbsubs_fitYesNo);
  result->resol_fitYesNo = argInit_real_T();
}

static void main_reflectivity_calculation(void)
{
  struct4_T problem;
  cell_13 result;
  struct0_T r1;
  cell_10 r2;
  struct1_T r3;
  struct2_T r4;
  emxInit_struct4_T(&problem);
  emxInit_cell_13(&result);

  /* Initialize function 'reflectivity_calculation' input arguments. */
  /* Initialize function input argument 'problemDef'. */
  /* Initialize function input argument 'problemDef_cells'. */
  /* Initialize function input argument 'problemDef_limits'. */
  /* Initialize function input argument 'controls'. */
  /* Call the entry-point 'reflectivity_calculation'. */
  argInit_struct0_T(&r1);
  argInit_cell_10(&r2);
  argInit_struct1_T(&r3);
  argInit_struct2_T(&r4);
  reflectivity_calculation(&r1, &r2, &r3, &r4, &problem, &result);
  emxDestroy_cell_13(result);
  emxDestroy_struct4_T(problem);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  reflectivity_calculation_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_reflectivity_calculation();

  /* Terminate the application.
     You do not need to do this more than one time. */
  reflectivity_calculation_terminate();
  return 0;
}

/* End of code generation (main.c) */
