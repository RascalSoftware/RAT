// A class which uses a function from matlabCallFunc.c to create, call and destroy a matlab engine.
// The class is used to call functions in matlabCallFunc.c which is 1 function

// The class passes data to matlabCallFunc.c and gets the results back.

// include matlabCallFunc.c

extern "C" 
{
    #include "matlabCallFun.c"
}


// Class                                                                  


class cCaller
{
    // Public 

    double params[];
    int arrayLen;
    char *funcName;
    char *pathCall;
    double bulkIn;
    double bulkOut;
    double constrast;
    double *sum;
    double *ans;

    // constructor 
    cCaller()
    {
        this->funcName = funcName;
        this->params = params;
        this->arrayLen = arrayLen;
        this->pathCall = pathCall;
        this->bulkIn = bulkIn;
        this->bulkOut = bulkOut;
        this->constrast = constrast;
        this->sum = sum;
        this->ans = ans;


        // paramsLen is the length of the params array
        // total mem for all params / one param size = paramsLen
        int paramsLen = sizeof(params)/sizeof(params[0]);

    }

    // REMENBER TO ADD FLAGS TO DETECT ENGINES THAT HAVE BEEN CREATED AND DESTROYED and ACTIVE


    // destructor
    ~cCaller()
    {
        // free memory
        free(sum);
        free(ans);

        // Send contrast -1 to matlabCallFunc.c to indicate that the Engine is being closed
        stopEngine();

    }


    // Public methods
    
    // callMatlabFunc
    // Calls the matlab function 
    void callMatlabFunc()
    {   // double matlabCallFun(double params[], int arrayLen, char *funName, char *pathCall, double bulkIn, double bulkOut, double contrast, double *sum, double *ans) is the C function which is called
        // call matlab function

        matlabCallFunc(params, arrayLen,funcName, pathCall, &bulkIn, &bulkOut, &constrast, &sum, &ans);
    }

    void startEngine()
    {
        // start matlab engine
        matlabCallFunc(0,0,'dummy','dummy','matlabroot',0,0,-1,0,0);
    }

    void stopEngine()
    {
        // stop matlab engine
        matlabCallFunc(0,0,'dummy','dummy','matlabroot',0,0,-2,0,0);
    }
    
    int testReach()
    {
        // test reach
        int c = 0;
        c = 1+12;
        return c;
        
        
    }


}

