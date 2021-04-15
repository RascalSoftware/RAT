#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#include "mex.h"



void timestwo(double y[], double x[])
{
  static int engIsOpen;
  Engine *ep;
  mxArray *X = NULL, *Y = NULL;
  
  if (engIsOpen == 0)
	{engIsOpen = 1;
	 ep = engOpen("");
	 printf("\n Matlab Starting ");
  };
  
  X = mxCreateDoubleMatrix(1,1,mxREAL);
  memcpy((void *)mxGetPr(X), (void *)x, sizeof(x)); 
  engPutVariable(ep,"x",X);
  engEvalString(ep, "y = timesThree(x)");
  
}


void mexfunction(int nlhs, mxArray *plhs[], int nrhs,
                 const mxArray *prhs[])
{
  double *x, *y;
  int mrows, ncols;
  
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    mexErrMsgTxt("One input required.");
  } else if (nlhs > 1) {
    mexErrMsgTxt("Too many output arguments");
  }
  
  /* The input must be a noncomplex scalar double.*/
  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);
  if (!mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
      !(mrows == 1 && ncols == 1)) {
    mexErrMsgTxt("Input must be a noncomplex scalar double.");
  }

  /* Create matrix for the return argument. */
  plhs[0] = mxCreateDoubleMatrix(mrows,ncols, mxREAL);
  
  /* Assign pointers to each input and output. */
  x = mxGetPr(prhs[0]);
  y = mxGetPr(plhs[0]);
  
  /* Call the timestwo subroutine. */
  timestwo(y,x);
}
