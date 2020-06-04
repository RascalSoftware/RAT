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
#include "abeles.h"
#include "main.h"
#include "abeles_terminate.h"
#include "abeles_emxAPI.h"
#include "abeles_initialize.h"

/* Function Declarations */
static emxArray_real_T *argInit_1xUnbounded_real_T(void);
static emxArray_creal_T *argInit_Unboundedx3_creal_T(void);
static creal_T argInit_creal_T(void);
static double argInit_real_T(void);
static void main_abeles(void);

/* Function Definitions */
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

static emxArray_creal_T *argInit_Unboundedx3_creal_T(void)
{
  emxArray_creal_T *result;
  int idx0;
  creal_T dc1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_creal_T(2, 3);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    dc1 = argInit_creal_T();
    result->data[idx0] = dc1;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0 + result->size[0]] = dc1;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0 + (result->size[0] << 1)] = argInit_creal_T();
  }

  return result;
}

static creal_T argInit_creal_T(void)
{
  creal_T result;
  double result_tmp;

  /* Set the value of the complex variable.
     Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result.re = result_tmp;
  result.im = result_tmp;
  return result;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void main_abeles(void)
{
  emxArray_real_T *out;
  emxArray_real_T *x;
  emxArray_creal_T *sld;
  creal_T dc0;
  emxInitArray_real_T(&out, 1);

  /* Initialize function 'abeles' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_1xUnbounded_real_T();

  /* Initialize function input argument 'sld'. */
  sld = argInit_Unboundedx3_creal_T();

  /* Initialize function input argument 'nbair'. */
  /* Initialize function input argument 'nbsub'. */
  /* Call the entry-point 'abeles'. */
  dc0 = argInit_creal_T();
  abeles(x, sld, dc0, dc0, argInit_real_T(), argInit_real_T(), argInit_real_T(),
         argInit_real_T(), out);
  emxDestroyArray_real_T(out);
  emxDestroyArray_creal_T(sld);
  emxDestroyArray_real_T(x);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  abeles_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_abeles();

  /* Terminate the application.
     You do not need to do this more than one time. */
  abeles_terminate();
  return 0;
}

/* End of code generation (main.c) */
