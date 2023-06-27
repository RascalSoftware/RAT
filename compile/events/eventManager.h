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

LIB_EXPORT void updatePlot(int nContrast, double* reflect, int nReflect, double* shiftedData, int nShiftedData, 
                           double* sldProfiles, int nSldProfiles, double* layers, int nLayers, double* ssubs, 
                           double* resample, double* dataPresent, const char* modelType);

LIB_EXPORT void sendMessage(const char* msg);

LIB_EXPORT void notify(const baseEvent& event);

LIB_EXPORT void addListener(enum eventTypes type, const callback fn);

LIB_EXPORT void clearListeners();

#ifdef __cplusplus
}
#endif

#endif  // EVENT_MANAGER_H