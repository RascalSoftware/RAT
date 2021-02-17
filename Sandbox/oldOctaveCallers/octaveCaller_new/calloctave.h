// calloctave.h
#pragma once
#include "mex.h"

#if defined  (__cplusplus)
extern "C" {
#endif

int
mexCallOctave (int nargout, mxArray *argout[], int nargin,
               mxArray *argin[], const char *fname);
void 
free_arg_list (int nargs, mxArray* arglist[]);

#if defined  (__cplusplus)
}
#endif
