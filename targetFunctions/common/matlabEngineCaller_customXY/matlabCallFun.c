
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"


void matlabCallFun(double params[], int arrayLen, char *funName, char *pathCall, double bulkIn, double bulkOut, double contrast, double *sum, double *ans)
{
	static Engine *ep;
	static double engStatus = 0;
	mxArray *result = NULL;
	mxArray *PARAMS = NULL;
	mxArray *BULKIN = NULL;
	mxArray *BULKOUT = NULL;
	mxArray *CONTRAST = NULL;
	mxArray *lays = NULL;

	double* s;
	double* layers;


	/*Contrast = -1 means start engine only, then return*/
	if(contrast == -1) {
		ep = engOpen("");
				if(ep==0) {
					printf("Connecton to Matlab Engine failed\n");
					return;
				}
				else {
					printf("Starting Matlab Engine\n");
					engStatus == 1;
					return;
				}
	}

    /*Contrast = -2 means close engine only (if open), then return*/
	if(contrast == -2) {
				if(ep==0) {
					printf("No engine open\n");
				}
				else {
					printf("Closing Matlab Engine\n");
					engClose(ep);
					engStatus == 0;
					return;
				}
	}


	/*Automatically start engine if closed to catch non-initialised call*/
	if(engStatus == 0) {
		ep = engOpen("");		
		if(ep==0) {
			printf("Connecton to Matlab Engine failed\n");
			return;
		}
		else {
			printf("Starting Matlab Engine\n");
			/*engEvalString(ep,(char *)pathCall);*/
			/*engEvalString(ep,"cd('/home/arwel/eclipseWorkspace_new/matlabEngine_demo/src')")*/;
			mxArray* MYPATH = mxCreateString(pathCall);
			engPutVariable(ep, "mypath", MYPATH);
			engEvalString(ep,"eval(mypath)");
			mxDestroyArray(MYPATH);
			engStatus = 1;
		}
	}

	PARAMS = mxCreateDoubleMatrix(1,arrayLen,mxREAL);
	memcpy(mxGetPr(PARAMS), params, arrayLen*sizeof(double));
	engPutVariable(ep,"params",PARAMS);

	BULKIN = mxCreateDoubleMatrix(1,1,mxREAL);
	memcpy((void *)mxGetPr(BULKIN), &bulkIn, 1*sizeof(double));
	engPutVariable(ep,"bulk_in",BULKIN);

	BULKOUT = mxCreateDoubleMatrix(1,1,mxREAL);
	memcpy((void *)mxGetPr(BULKOUT), &bulkOut, 1*sizeof(double));
	engPutVariable(ep,"bulk_out",BULKOUT);

	CONTRAST = mxCreateDoubleMatrix(1,1,mxREAL);
	memcpy((void *)mxGetPr(CONTRAST), &contrast, 1*sizeof(double));
	engPutVariable(ep,"contrast",CONTRAST);

	mxArray* MYFUN = mxCreateString(funName);
	engPutVariable(ep, "myfun", MYFUN);
	engEvalString(ep,"eval(myfun)");
	/*engEvalString(ep,"[total,layers] = debugMfile(params,bulk_in,bulk_out,contrast)");*/
	mxDestroyArray(MYFUN);

	result = engGetVariable(ep,"total");
	s = (double *)mxGetData(result);
	memcpy( sum, s, mxGetNumberOfElements(result)*sizeof(double) );

	lays = engGetVariable(ep,"layers");
	layers = (double *)mxGetData(lays);
	memcpy(ans,layers,mxGetNumberOfElements(lays)*sizeof(double) );

	/*engClose(ep)*/;

	mxDestroyArray(PARAMS);
	mxDestroyArray(BULKIN);
	mxDestroyArray(BULKOUT);
	mxDestroyArray(CONTRAST);

};


