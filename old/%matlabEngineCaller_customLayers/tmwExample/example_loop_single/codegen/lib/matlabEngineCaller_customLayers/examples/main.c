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
#include "matlabEngineCaller_customLayers.h"
#include "main.h"
#include "matlabEngineCaller_customLayers_terminate.h"
#include "matlabEngineCaller_customLayers_emxAPI.h"
#include "matlabEngineCaller_customLayers_initialize.h"

/* Function Declarations */
static void argInit_1x10_char_T(char result[10]);
static void argInit_1x122_char_T(char result[122]);
static void argInit_1x8_real_T(double result[8]);
static char argInit_char_T(void);
static double argInit_real_T(void);
static void c_main_matlabEngineCaller_custo(void);

/* Function Definitions */
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

static void argInit_1x122_char_T(char result[122])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 122; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

static void argInit_1x8_real_T(double result[8])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 8; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static char argInit_char_T(void)
{
  return '?';
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void c_main_matlabEngineCaller_custo(void)
{
  emxArray_real_T *output;
  double dv0[8];
  char cv6[10];
  char cv7[122];
  double sRough_data[1];
  int sRough_size[2];
  emxInitArray_real_T(&output, 2);

  /* Initialize function 'matlabEngineCaller_customLayers' input arguments. */
  /* Initialize function input argument 'params'. */
  /* Initialize function input argument 'funcName'. */
  /* Initialize function input argument 'funcPath'. */
  /* Call the entry-point 'matlabEngineCaller_customLayers'. */
  argInit_1x8_real_T(dv0);
  argInit_1x10_char_T(cv6);
  argInit_1x122_char_T(cv7);
  matlabEngineCaller_customLayers(dv0, argInit_real_T(), cv6, cv7,
    argInit_real_T(), argInit_real_T(), output, sRough_data, sRough_size);
  emxDestroyArray_real_T(output);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  matlabEngineCaller_customLayers_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  c_main_matlabEngineCaller_custo();

  /* Terminate the application.
     You do not need to do this more than one time. */
  matlabEngineCaller_customLayers_terminate();
  return 0;
}

/* End of code generation (main.c) */
