#include "mex.h"
#include <cstring>
#include <memory>
#include <functional>
#include "eventManager.h"
#include "dylib.hpp"

std::unique_ptr<dylib> library;

// initialise dynamic library
void initDyLib(void)
{
   if (!library)
   {    
       char filename[18]  = "eventManager";
       library = std::unique_ptr<dylib>(new dylib(getenv("RAT_PATH"), 
                                                  strcat(filename, dylib::extension)));
   }      
}

// Unpack data to cell array with given row and col size
mxArray* unpackDataToCell(int rows, int cols, double* data, double* nData, 
                          double* data2, double* nData2, int dataCol)   
{
    mwSize dims[2] = {0, 0};
    int offset = 0;
    size_t bytes_to_copy;
    mxArray* cellArray = mxCreateCellMatrix(rows, cols);
    for ( int i = 0; i < rows; i++){
        dims[0] = (mwSize)nData[i] / dataCol;
        dims[1] = dataCol; 
        mxArray* temp = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
        bytes_to_copy = dims[0] * dims[1] * mxGetElementSize(temp);
        memcpy(mxGetPr(temp), data + offset, bytes_to_copy);
        mxSetCell(cellArray, i, temp);
        offset +=  dims[0] * dims[1];
    }

    if (data2 != NULL && nData2 != NULL)
    {
        // This is used to unpack the domains data into the second column 
        offset = 0;
        for ( int i = 0; i < rows; i++){
            dims[0] = (mwSize)nData2[i] / dataCol;
            dims[1] = dataCol; 
            mxArray* temp = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
            bytes_to_copy = dims[0] * dims[1] * mxGetElementSize(temp);
            memcpy(mxGetPr(temp), data2 + offset, bytes_to_copy);
            mxSetCell(cellArray, i + rows, temp);
            offset +=  dims[0] * dims[1];
        }
    }

    return cellArray;
}

// Event callback function
void eventCallback(const baseEvent& event)
{   
    mxArray *prhs[2];
    const mwSize structDims[2] = {1, 1};
    prhs[0] = mxCreateDoubleScalar((double)event.type);
    if (event.type == EventTypes::Message) {
        messageEvent* mEvent = (messageEvent*)&event; 
        prhs[1] = mxCreateString(mEvent->msg);
    } else if (event.type == EventTypes::Progress){
        progressEvent* pEvent = (progressEvent*)&event;
        const char* field_names[] = {"message", "percent"};
        prhs[1] = mxCreateStructArray(2, structDims, 2, field_names);
        
        auto array = mxCreateDoubleMatrix(1, 1, mxREAL);
        memcpy(mxGetPr(array), &pEvent->percent, mxGetElementSize(array));
        
        mxSetFieldByNumber(prhs[1], 0, 0, mxCreateString(pEvent->msg));
        mxSetFieldByNumber(prhs[1], 0, 1, array);
    } else if (event.type == EventTypes::Plot){
        plotEvent* pEvent = (plotEvent*)&event; 

        mxArray *reflect = unpackDataToCell(pEvent->data->nContrast, 1, 
                                                   pEvent->data->reflect, pEvent->data->nReflect, NULL, NULL, 2);

        mxArray *shifted = unpackDataToCell(pEvent->data->nContrast, 1, 
                                                   pEvent->data->shiftedData, pEvent->data->nShiftedData, NULL, NULL, 3);
        
        mxArray *slds = unpackDataToCell(pEvent->data->nContrast, (pEvent->data->nSldProfiles2 == NULL) ? 1 : 2,
                                                pEvent->data->sldProfiles, pEvent->data->nSldProfiles, 
                                                pEvent->data->sldProfiles2, pEvent->data->nSldProfiles2, 2);

        mxArray *layers = unpackDataToCell(pEvent->data->nContrast, (pEvent->data->nLayers2 == NULL) ? 1 : 2, 
                                                  pEvent->data->layers, pEvent->data->nLayers, 
                                                  pEvent->data->layers2, pEvent->data->nLayers, 2);

        mwSize dims[2] = {(mwSize)pEvent->data->nContrast, 1};
        mxArray* ssubs = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
        memcpy(mxGetPr(ssubs), pEvent->data->ssubs, dims[0] * mxGetElementSize(ssubs));

        mxArray* resample = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
        memcpy(mxGetPr(resample), pEvent->data->resample, dims[0] * mxGetElementSize(resample));

        mxArray* dataPresent = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
        memcpy(mxGetPr(dataPresent), pEvent->data->dataPresent, dims[0] * mxGetElementSize(dataPresent));

        
        const char* field_names[] = {"reflectivity", "shiftedData", "sldProfiles", "allLayers", "ssubs", 
                                     "resample", "dataPresent", "modelType"};
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
        initDyLib();
        auto clearListeners = library->get_function<void(void)>("clearListeners");
        clearListeners();
        return;
    }  

    int eventType;
    if (nrhs < 2 || !mxIsDouble(prhs[1]) || mxIsComplex(prhs[1]) || mxGetM(prhs[1]) != 1 || mxGetN(prhs[1]) != 1)     
		    mexErrMsgTxt("Second input should be an event type integer.");
    eventType = (int)mxGetScalar(prhs[1]);

    // register
    if (!strcmp("register", cmd)) {
       if (eventType < 0 || eventType > static_cast<int>(EventTypes::Progress)) {
          mexErrMsgTxt("Event type not recognized.");
       }
    
       initDyLib();
       auto addListener = library->get_function<void(EventTypes, std::function<void(const baseEvent&)>)>("addListener");
       addListener(static_cast<EventTypes>(eventType), eventCallback);
       return;    
    }
    
    mexErrMsgTxt("Command not recognized.");
}