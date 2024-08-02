#include "eventManagerImpl.hpp"

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
#define LIB_EXPORT __declspec(dllexport)
#else
#define LIB_EXPORT
#endif

LIB_EXPORT void updatePlot(int nContrast, double* reflect, double* nReflect, double* shiftedData, double* nShiftedData, 
                           double* sldProfiles, double* nSldProfiles, double* layers, double* nLayers, 
                           double* sldProfiles2, double* nSldProfiles2, double* layers2, double* nLayers2, double* subRoughs,
                           double* resample, double* dataPresent, const char* modelType, const char* contrastNames, const double* nContrastNames);

LIB_EXPORT void sendMessage(const char* msg);

LIB_EXPORT void updateProgress(const char* msg, double percent);

LIB_EXPORT void notify(const baseEvent& event);

LIB_EXPORT void addListener(EventTypes type, const std::function<void(const baseEvent&)> fn);

LIB_EXPORT void clearListeners();

LIB_EXPORT bool hasPlotHandler();

#ifdef __cplusplus
}
#endif

#endif  // EVENT_MANAGER_H