// calloctave.cc

#include "interpreter.h"
#include "mxarray.h"
#include "parse.h"

extern "C"
int
mexCallOctave (int nargout, mxArray *argout[], int nargin,
               mxArray *argin[], const char *fname)
{

  static octave::interpreter embedded_interpreter;
  if (!embedded_interpreter.initialized())
    embedded_interpreter.execute ();

  octave_value_list args;

  args.resize (nargin);

  for (int i = 0; i < nargin; i++)
    args(i) = mxArray::as_octave_value (argin[i]);

  bool execution_error = false;

  octave_value_list retval;


  retval = octave::feval (fname, args, nargout);

  int num_to_copy = retval.length ();

  if (nargout < retval.length ())
    num_to_copy = nargout;

  for (int i = 0; i < num_to_copy; i++)
    {
      argout[i] = new mxArray (retval(i));
    }

  while (num_to_copy < nargout)
    argout[num_to_copy++] = nullptr;

  return execution_error ? 1 : 0;
}

extern "C"
void 
free_arg_list (int nargs, mxArray* arglist[])
{
    for(int i = 0; i < nargs; i++)
            delete arglist[i];
}
