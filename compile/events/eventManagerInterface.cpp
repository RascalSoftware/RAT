#include "mex.h"
#include "EventManager.h"


// Callback function
void myCallback(const baseEvent& event)
{   
    mxArray *prhs[2];
    prhs[0] = mxCreateDoubleScalar((double)event.type);
    if (event.type == MESSAGE) {
        messageEvent* mEvent = (messageEvent*)&event; 
        prhs[1] = mxCreateString(mEvent->msg);
    } else if (event.type == PLOT){
        plotEvent* pEvent = (plotEvent*)&event; 

        mxArray *reflect = mxCreateCellMatrix(pEvent->data->nContrast, 1);

        mwSize dims[2] = {0, 0};
        int offset = 0;
        size_t bytes_to_copy;
        
        for ( int i = 0; i < pEvent->data->nContrast; i++){
            dims[0] = (mwSize)pEvent->data->nReflect[i]/2.0;
            dims[1] = 2; 
            mxArray* temp = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
            bytes_to_copy = dims[0] * dims[1] * mxGetElementSize(temp);
            memcpy(mxGetPr(temp), pEvent->data->reflect + offset, bytes_to_copy);
            mxSetCell(reflect, i, temp);
            offset +=  dims[0] * dims[1];
        }
        
        mxArray *shifted = mxCreateCellMatrix(pEvent->data->nContrast, 1);
        offset = 0;
        for ( int i = 0; i < pEvent->data->nContrast; i++){
            dims[0] = (mwSize)pEvent->data->nShiftedData[i]/3.0;
            dims[1] = 3; 
            mxArray* temp = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
            bytes_to_copy = dims[0] * dims[1] * mxGetElementSize(temp);
            memcpy(mxGetPr(temp), pEvent->data->shiftedData + offset, bytes_to_copy);
            mxSetCell(shifted, i, temp);
            offset +=  dims[0] * dims[1];
        }
        
        mxArray *slds = mxCreateCellMatrix(pEvent->data->nContrast, 1);
        offset = 0;
        for ( int i = 0; i < pEvent->data->nContrast; i++){
            dims[0] = (mwSize)pEvent->data->nSldProfiles[i]/2.0;
            dims[1] = 2; 
            mxArray* temp = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
            bytes_to_copy = dims[0] * dims[1] * mxGetElementSize(temp);
            memcpy(mxGetPr(temp), pEvent->data->sldProfiles + offset, bytes_to_copy);
            mxSetCell(slds, i, temp);
            offset +=  dims[0] * dims[1];
        }

        mxArray *layers = mxCreateCellMatrix(pEvent->data->nContrast, 1);
        offset = 0;
        for ( int i = 0; i < pEvent->data->nContrast; i++){
            dims[0] = (mwSize)pEvent->data->nLayers[i];
            dims[1] = 1; 
            mxArray* temp = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
            bytes_to_copy = dims[0] * dims[1] * mxGetElementSize(temp);
            memcpy(mxGetPr(temp), pEvent->data->layers + offset, bytes_to_copy);
            mxSetCell(layers, i, temp);
            offset +=  dims[0] * dims[1];
        }

        dims[0] = (mwSize)pEvent->data->nContrast;
        dims[1] = 1;
        mxArray* ssubs = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
        memcpy(mxGetPr(ssubs), pEvent->data->ssubs, dims[0] * mxGetElementSize(ssubs));

        mxArray* resample = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
        memcpy(mxGetPr(resample), pEvent->data->resample, dims[0] * mxGetElementSize(resample));

        mxArray* dataPresent = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
        memcpy(mxGetPr(dataPresent), pEvent->data->dataPresent, dims[0] * mxGetElementSize(dataPresent));

        
        const char* field_names[] = {"reflectivity", "shifted_data", "sldProfiles", "allLayers", "ssubs", 
                                     "resample", "dataPresent", "modelType"};
        const mwSize structDims[2] = {1, 1};
        prhs[1] = mxCreateStructArray(2, structDims, 8, field_names);

        mxSetFieldByNumber(prhs[1], 0, 0, reflect);
        mxSetFieldByNumber(prhs[1], 0, 1, shifted);
        mxSetFieldByNumber(prhs[1], 0, 2, slds);
        mxSetFieldByNumber(prhs[1], 0, 3, layers);
        mxSetFieldByNumber(prhs[1], 0, 4, ssubs);
        mxSetFieldByNumber(prhs[1], 0, 5, resample);
        mxSetFieldByNumber(prhs[1], 0, 6, dataPresent);
        mxSetFieldByNumber(prhs[1], 0, 7, mxCreateString(pEvent->data->modelType));
    }
    else
        return;

    mexCallMATLAB(0, NULL, 2, prhs, "eventManager.notify");

    mxDestroyArray(prhs[0]);
    mxDestroyArray(prhs[1]);
}

// MEX Gateway
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    // Get the command string
    char cmd[64];
	if (nrhs < 1 || mxGetString(prhs[0], cmd, sizeof(cmd)))
		mexErrMsgTxt("First input should be a command string less than 64 characters long.");
    
    // clear
    if (!strcmp("clear", cmd)) {
        clearListeners();
        return;
    }  

    int eventType;
    if (nrhs < 2 || !mxIsDouble(prhs[1]) || mxIsComplex(prhs[1]) || mxGetM(prhs[1]) != 1 || mxGetN(prhs[1]) != 1)     
		    mexErrMsgTxt("Second input should be an event type integer.");
    eventType = (int)mxGetScalar(prhs[1]);

    // register
    if (!strcmp("register", cmd)) {
        for ( int type = MESSAGE; type <= PLOT; ++type){
            if (type == eventType){
   	            void (*cbPtr)(const baseEvent&) = myCallback;
                addListener((enum eventTypes)eventType, cbPtr);
                return;
            }
        }
        mexErrMsgTxt("Event type not recognized.");
    }
    
    mexErrMsgTxt("Command not recognized.");
}