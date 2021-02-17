/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * octaveCaller.c
 *
 * Code generation for function 'octaveCaller'
 *
 */

/* Include files */
#include "octaveCaller.h"
#include "octaveCaller_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void octaveCaller(const emlrtStack *sp)
{
  (void)sp;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);

  /*  Runnink mkoctfile */
  /*  */
  /* g++ -std=gnu++11 -I/usr/include/suitesparse -I/usr/include/octave-5.2.0/octave/.. -I/usr/include/octave-5.2.0/octave  -pthread -fopenmp -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector-strong --param=ssp-buffer-size=4 -grecord-gcc-switches -m64 -mtune=generic -flto=auto -rdynamic  -fPIC -Wl,-z,relro   -o simpleOctave   -L/usr/lib64 -L/usr/lib64/octave/5.2.0 -loctinterp -loctave  */
  covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);

  /* sourceFile2 = 'mexCallOctave.cpp'; */
  /* coder.updateBuildInfo('addLinkObjects',linkFile1,linkPath1,libPriority,libPreCompiled,libLinkOnly); */
  /* coder.updateBuildInfo('addLinkObjects',linkFile2,linkPath1,libPriority,libPreCompiled,libLinkOnly); */
  /* coder.updateBuildInfo('addSourceFiles',sourceFile2); */
  simpleOctave();
}

/* End of code generation (octaveCaller.c) */
