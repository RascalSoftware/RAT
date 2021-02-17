//main.c
#include <stdio.h>
#include "calloctave.h"   
int main()
{
    double input_data[] = {0,1,2,3,4,5,6,7,8,9,10};

    const int nargin = 1;
    const int nargout = 1;
    mxArray* rhs[nargin];
    mxArray* lhs[nargout];

    // allocate mex array
    rhs[0] = mxCreateDoubleMatrix( 10, 1, mxREAL);
    double* rhs_ptr = mxGetPr( rhs[0] );

    // copy data from input buffer to mex array
    for (int i = 0 ; i < 10; i++)
        rhs_ptr[i] = input_data[i];

    // call octave function
    mexCallOctave(nargout, lhs, nargin, rhs, "myfunction");

    double* lhs_ptr = mxGetPr( lhs[0] );

    double output_data = *lhs_ptr;

    // show the result
    printf ("result = %f", output_data);

    // free memory

    mxDestroyArray(rhs[0]);
    free_arg_list(nargout, lhs);
}