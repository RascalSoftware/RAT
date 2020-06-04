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
#include "standard_layers_mod.h"
#include "main.h"
#include "standard_layers_mod_terminate.h"
#include "standard_layers_mod_emxAPI.h"
#include "standard_layers_mod_initialize.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);
static void argInit_1x5_real_T(double result[5]);
static emxArray_cell_wrap_0 *argInit_1xUnbounded_cell_wrap_0(void);
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static cell_wrap_0 argInit_cell_wrap_0(void);
static double argInit_real_T(void);
static void main_standard_layers_mod(void);

/* Function Definitions */
static void argInit_1x2_real_T(double result[2])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
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

static emxArray_cell_wrap_0 *argInit_1xUnbounded_cell_wrap_0(void)
{
  emxArray_cell_wrap_0 *result;
  static int iv1[2] = { 1, 2 };

  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_cell_wrap_0(2, iv1);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[result->size[0] * idx1] = argInit_cell_wrap_0();
  }

  return result;
}

static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  static int iv0[2] = { 1, 2 };

  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(2, iv0);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[result->size[0] * idx1] = argInit_real_T();
  }

  return result;
}

static cell_wrap_0 argInit_cell_wrap_0(void)
{
  cell_wrap_0 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1x5_real_T(result.f1);
  return result;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_standard_layers_mod(void)
{
  emxArray_real_T *params;
  double contrastLayers[2];
  double numberOfLayers;
  emxArray_cell_wrap_0 *layersDetails;
  double layersOutput_data[10];
  int layersOutput_size[2];
  double sRoughOutput;

  /* Initialize function 'standard_layers_mod' input arguments. */
  /* Initialize function input argument 'params'. */
  params = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'contrastLayers'. */
  argInit_1x2_real_T(contrastLayers);
  numberOfLayers = argInit_real_T();

  /* Initialize function input argument 'layersDetails'. */
  layersDetails = argInit_1xUnbounded_cell_wrap_0();

  /* Call the entry-point 'standard_layers_mod'. */
  standard_layers_mod(params, contrastLayers, numberOfLayers, layersDetails,
                      layersOutput_data, layersOutput_size, &sRoughOutput);
  emxDestroyArray_cell_wrap_0(layersDetails);
  emxDestroyArray_real_T(params);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  standard_layers_mod_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_standard_layers_mod();

  /* Terminate the application.
     You do not need to do this more than one time. */
  standard_layers_mod_terminate();
  return 0;
}

/* End of code generation (main.c) */
