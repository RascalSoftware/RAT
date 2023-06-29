#include "eventManager.h"

LIB_EXPORT void sendMessage(const char* msg)
{
    notify(messageEvent(msg));
}

LIB_EXPORT void updatePlot(int nContrast, double* reflect, double* nReflect, double* shiftedData, double* nShiftedData, 
                           double* sldProfiles, double* nSldProfiles, double* layers, double* nLayers, double* ssubs, 
                           double* resample, double* dataPresent, const char* modelType)
{
    plotData data;
    data.nContrast = nContrast;
    data.reflect = reflect;
    data.nReflect = nReflect;
    data.shiftedData = shiftedData;
    data.nShiftedData = nShiftedData;
    data.sldProfiles = sldProfiles;
    data.nSldProfiles = nSldProfiles;
    data.layers = layers;
    data.nLayers = nLayers;
    data.ssubs = ssubs;
    data.resample = resample;
    data.dataPresent = dataPresent;
    data.modelType = modelType;
    notify(plotEvent(&data));
}

LIB_EXPORT void notify(const baseEvent& event)
{
	eventManager::get_instance()->notify(event);
}

LIB_EXPORT void addListener(enum eventTypes type, const callback fn)
{
    if (type == MESSAGE)
	    eventManager::get_instance()->addListener(MESSAGE, fn);
    else if (type == PLOT)
        eventManager::get_instance()->addListener(PLOT, fn);
}

LIB_EXPORT void clearListeners()
{
	eventManager::get_instance()->clear();
}
