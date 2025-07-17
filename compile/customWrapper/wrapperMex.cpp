#include <string>
#include <cstring>
#include "mex.h"
#include "library.h"

template<class base> inline mxArray *convertPtr2Mat(base *ptr)
{
    mexLock();
    return mxCreateString(convertPtr2String<base>(ptr).c_str());
}

template<class base> inline void destroyObject(const char* in, size_t size)
{
    delete convertString2HandlePtr<base>(in, size);
    mexUnlock();
}

char* getStringFromMxArray(const mxArray* array, const char* errorMsg)
{
    if ( mxIsChar(array) != 1)
        mexErrMsgTxt(errorMsg);

    /* input must be a row vector */
    if (mxGetM(array) != 1)
        mexErrMsgTxt(errorMsg);

    return mxArrayToString(array);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{	
    // Get the command string
    char cmd[64];
	if (nrhs < 1 || mxGetString(prhs[0], cmd, sizeof(cmd)))
		mexErrMsgTxt("First input should be a command string less than 64 characters long.");
      
    // New
    if (!strcmp("new", cmd)) {
        if (nlhs != 1)
            mexErrMsgTxt("One output expected for New command.");
        if (nrhs != 3)
            mexErrMsgTxt("Two input expected for New command (libName, functionName).");
        char* libName = getStringFromMxArray(prhs[1], "First input should a row vector char array with the full path of the dynamic library");
        char* functionName = getStringFromMxArray(prhs[2], "Second input should a row vector char array with the function name to call in the dynamic library");
        plhs[0] = convertPtr2Mat<CallbackInterface>(new Library(libName, functionName));
        return;
    }
    
     
    // Delete
    if (!strcmp("delete", cmd)) {    
        if (nrhs != 2)
		    mexErrMsgTxt("Second input for delete command should be a class instance handle.");
        size_t size = mxGetNumberOfElements(prhs[1]);
        destroyObject<CallbackInterface>(getStringFromMxArray(prhs[1], "class instance handle should a row vector char array"), size);
        if (nlhs != 0 || nrhs != 2)
            mexWarnMsgTxt("Delete: Unexpected arguments ignored.");
        return;
    }

    mexErrMsgTxt("Command not recognized.");
}
