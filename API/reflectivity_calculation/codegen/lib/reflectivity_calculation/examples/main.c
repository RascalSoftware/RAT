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

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);
static emxArray_cell_wrap_0 *argInit_1xUnbounded_cell_wrap_0(void);
static emxArray_cell_wrap_1 *argInit_1xUnbounded_cell_wrap_1(void);
static emxArray_cell_wrap_3 *argInit_1xUnbounded_cell_wrap_3(void);
static emxArray_char_T *argInit_1xUnbounded_char_T(void);
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static void argInit_1xd5_real_T(double result_data[], int result_size[2]);
static emxArray_cell_wrap_2 *argInit_Unboundedx1_cell_wrap_2(void);
static emxArray_real_T *argInit_Unboundedx2_real_T(void);
static emxArray_real_T *argInit_Unboundedx3_real_T(void);
static void argInit_cell_4(cell_4 *result);
static cell_wrap_0 argInit_cell_wrap_0(void);
static cell_wrap_1 argInit_cell_wrap_1(void);
static cell_wrap_2 argInit_cell_wrap_2(void);
static cell_wrap_3 argInit_cell_wrap_3(void);
static char argInit_char_T(void);
static double argInit_real_T(void);
static void argInit_struct0_T(struct0_T *result);
static struct1_T argInit_struct1_T(void);
static void argInit_struct2_T(struct2_T *result);
static struct3_T argInit_struct3_T(void);
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void);
static void main_reflectivity_calculation(void);

/* Function Definitions */
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

static emxArray_cell_wrap_0 *argInit_1xUnbounded_cell_wrap_0(void)
{
  emxArray_cell_wrap_0 *result;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_cell_wrap_0(1, 2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx1] = argInit_cell_wrap_0();
  }

  return result;
}

static emxArray_cell_wrap_1 *argInit_1xUnbounded_cell_wrap_1(void)
{
  emxArray_cell_wrap_1 *result;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_cell_wrap_1(1, 2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx1] = argInit_cell_wrap_1();
  }

  return result;
}

static emxArray_cell_wrap_3 *argInit_1xUnbounded_cell_wrap_3(void)
{
  emxArray_cell_wrap_3 *result;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_cell_wrap_3(1, 2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx1] = argInit_cell_wrap_3();
  }

  return result;
}

static emxArray_char_T *argInit_1xUnbounded_char_T(void)
{
  emxArray_char_T *result;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_char_T(1, 2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx1] = argInit_char_T();
  }

  return result;
}

static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(1, 2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx1] = argInit_real_T();
  }

  return result;
}

static void argInit_1xd5_real_T(double result_data[], int result_size[2])
{
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result_size[0] = 1;
  result_size[1] = 2;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data[idx1] = argInit_real_T();
  }
}

static emxArray_cell_wrap_2 *argInit_Unboundedx1_cell_wrap_2(void)
{
  emxArray_cell_wrap_2 *result;
  static int iv0[1] = { 2 };

  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_cell_wrap_2(1, iv0);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_cell_wrap_2();
  }

  return result;
}

static emxArray_real_T *argInit_Unboundedx2_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  double d1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    d1 = argInit_real_T();
    result->data[idx0] = d1;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0 + result->size[0]] = d1;
  }

  return result;
}

static emxArray_real_T *argInit_Unboundedx3_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  double d0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 3);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    d0 = argInit_real_T();
    result->data[idx0] = d0;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0 + result->size[0]] = d0;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0 + (result->size[0] << 1)] = argInit_real_T();
  }

  return result;
}

static void argInit_cell_4(cell_4 *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result->f1 = argInit_1xUnbounded_cell_wrap_0();
  result->f2 = argInit_1xUnbounded_cell_wrap_1();
  result->f3 = argInit_1xUnbounded_cell_wrap_0();
  result->f4 = argInit_1xUnbounded_cell_wrap_0();
  result->f5 = argInit_1xUnbounded_cell_wrap_0();
  result->f6 = argInit_Unboundedx1_cell_wrap_2();
  result->f7 = argInit_1xUnbounded_cell_wrap_3();
  result->f8 = argInit_1xUnbounded_cell_wrap_3();
  result->f9 = argInit_1xUnbounded_cell_wrap_3();
  result->f10 = argInit_1xUnbounded_cell_wrap_3();
  result->f11 = argInit_1xUnbounded_cell_wrap_3();
  result->f12 = argInit_1xUnbounded_cell_wrap_3();
  result->f13 = argInit_1xUnbounded_cell_wrap_3();
}

static cell_wrap_0 argInit_cell_wrap_0(void)
{
  cell_wrap_0 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x2_real_T(result.f1);
  return result;
}

static cell_wrap_1 argInit_cell_wrap_1(void)
{
  cell_wrap_1 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.f1 = argInit_Unboundedx3_real_T();
  return result;
}

static cell_wrap_2 argInit_cell_wrap_2(void)
{
  cell_wrap_2 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1xd5_real_T(result.f1.data, result.f1.size);
  return result;
}

static cell_wrap_3 argInit_cell_wrap_3(void)
{
  cell_wrap_3 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.f1 = argInit_1xUnbounded_char_T();
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
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result->contrastBacks = argInit_1xUnbounded_real_T();
  result->contrastBacksType = argInit_1xUnbounded_real_T();
  result->TF = argInit_1xUnbounded_char_T();
  result->resample = argInit_1xUnbounded_real_T();
  result->dataPresent = argInit_1xUnbounded_real_T();
  result->numberOfContrasts = argInit_real_T();
  result->geometry = argInit_1xUnbounded_char_T();
  result->contrastShifts = argInit_1xUnbounded_real_T();
  result->contrastScales = argInit_1xUnbounded_real_T();
  result->contrastNbas = argInit_1xUnbounded_real_T();
  result->contrastNbss = argInit_1xUnbounded_real_T();
  result->contrastRes = argInit_1xUnbounded_real_T();
  result->backs = argInit_1xUnbounded_real_T();
  result->shifts = argInit_1xUnbounded_real_T();
  result->sf = argInit_1xUnbounded_real_T();
  result->nba = argInit_1xUnbounded_real_T();
  result->nbs = argInit_1xUnbounded_real_T();
  result->res = argInit_1xUnbounded_real_T();
  result->params = argInit_1xUnbounded_real_T();
  result->numberOfLayers = argInit_real_T();
  result->modelType = argInit_1xUnbounded_char_T();
  result->modelFilename = argInit_1xUnbounded_char_T();
  result->path = argInit_1xUnbounded_char_T();
  result->modelLanguage = argInit_1xUnbounded_real_T();
  result->fitpars = c_argInit_UnboundedxUnbounded_r();
  result->otherpars = c_argInit_UnboundedxUnbounded_r();
  result->fitconstr = c_argInit_UnboundedxUnbounded_r();
  result->otherconstr = c_argInit_UnboundedxUnbounded_r();
}

static struct1_T argInit_struct1_T(void)
{
  struct1_T result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.params = argInit_Unboundedx2_real_T();
  result.backs = argInit_Unboundedx2_real_T();
  result.scales = argInit_Unboundedx2_real_T();
  result.shifts = argInit_Unboundedx2_real_T();
  result.nba = argInit_Unboundedx2_real_T();
  result.nbs = argInit_Unboundedx2_real_T();
  result.res = argInit_Unboundedx2_real_T();
  return result;
}

static void argInit_struct2_T(struct2_T *result)
{
  double result_tmp;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result->para = argInit_1xUnbounded_char_T();
  result->proc = argInit_1xUnbounded_char_T();
  result->display = argInit_1xUnbounded_char_T();
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
  result->strategy = argInit_1xUnbounded_real_T();
  result->Nlive = argInit_real_T();
  result->nmcmc = argInit_real_T();
  result->propScale = argInit_real_T();
  result->nsTolerance = argInit_real_T();
  result->checks = argInit_struct3_T();
}

static struct3_T argInit_struct3_T(void)
{
  struct3_T result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.params_fitYesNo = argInit_1xUnbounded_real_T();
  result.backs_fitYesNo = argInit_1xUnbounded_real_T();
  result.shifts_fitYesNo = argInit_1xUnbounded_real_T();
  result.scales_fitYesNo = argInit_1xUnbounded_real_T();
  result.nbairs_fitYesNo = argInit_1xUnbounded_real_T();
  result.nbsubs_fitYesNo = argInit_1xUnbounded_real_T();
  result.resol_fitYesNo = argInit_1xUnbounded_real_T();
  return result;
}

static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

static void main_reflectivity_calculation(void)
{
  struct4_T problem;
  cell_7 result;
  struct0_T problemDef;
  cell_4 problemDef_cells;
  struct1_T problemDef_limits;
  struct2_T controls;
  emxInit_struct4_T(&problem);
  emxInit_cell_7(&result);

  /* Initialize function 'reflectivity_calculation' input arguments. */
  /* Initialize function input argument 'problemDef'. */
  argInit_struct0_T(&problemDef);

  /* Initialize function input argument 'problemDef_cells'. */
  argInit_cell_4(&problemDef_cells);

  /* Initialize function input argument 'problemDef_limits'. */
  problemDef_limits = argInit_struct1_T();

  /* Initialize function input argument 'controls'. */
  argInit_struct2_T(&controls);

  /* Call the entry-point 'reflectivity_calculation'. */
  reflectivity_calculation(&problemDef, &problemDef_cells, &problemDef_limits,
    &controls, &problem, &result);
  emxDestroy_cell_7(result);
  emxDestroy_struct4_T(problem);
  emxDestroy_struct2_T(controls);
  emxDestroy_struct1_T(problemDef_limits);
  emxDestroy_cell_4(problemDef_cells);
  emxDestroy_struct0_T(problemDef);
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
