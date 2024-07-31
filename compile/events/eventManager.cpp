#include "eventManager.h"

LIB_EXPORT void sendMessage(const char* msg)
{
    notify(messageEvent(msg));
}

LIB_EXPORT void updateProgress(const char* msg, double percent)
{
    notify(progressEvent(msg, percent));
}

LIB_EXPORT void updatePlot(int nContrast, double* reflect, double* nReflect, double* shiftedData, double* nShiftedData, 
                           double* sldProfiles, double* nSldProfiles, double* layers, double* nLayers,  
                           double* sldProfiles2, double* nSldProfiles2, double* layers2, double* nLayers2, double* subRoughs,
                           double* resample, double* dataPresent, const char* modelType, const char* contrastNames, const double* nContrastNames)
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
    data.sldProfiles2 = sldProfiles2;
    data.nSldProfiles2 = nSldProfiles2;
    data.layers2 = layers2;
    data.nLayers2 = nLayers2;
    data.subRoughs = subRoughs;
    data.resample = resample;
    data.dataPresent = dataPresent;
    data.modelType = modelType;
    data.contrastNames = contrastNames; 
    data.nContrastNames = nContrastNames;
    notify(plotEvent(&data));
}

LIB_EXPORT void notify(const baseEvent& event)
{
	eventManager::get_instance()->notify(event);
}

LIB_EXPORT void addListener(EventTypes type, const std::function<void(const baseEvent&)> fn)
{
    eventManager::get_instance()->addListener(type, fn);
}

LIB_EXPORT void clearListeners()
{
	eventManager::get_instance()->clear();
}

LIB_EXPORT bool hasPlotHandler()
{   
    auto names = eventManager::get_instance()->getEventNames();
	for(unsigned i=0; i < names.size(); i++) {
        if (names[i] == EventTypes::Plot)
            return true;
    }
    return false;
}
