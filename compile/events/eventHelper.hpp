#ifndef EVENT_HELPER_HPP
#define EVENT_HELPER_HPP

#include <memory>
#include <cstdlib>
#include "dylib.hpp" // dylib.hpp is a header file that contains the dylib class that extracts a function from dll

class eventHelper
{
    public:
        std::unique_ptr<dylib> library;
        bool initialised = false;
    
        eventHelper(void){};
        ~eventHelper(void){};

        eventHelper& operator=(eventHelper* other) noexcept
        {
            if (other) {
                this->library = std::move(other->library);
                this->initialised = other->initialised;
            }
            else {
                this->library = NULL;
                this->initialised = false;
            }
            return *this;
        };

        eventHelper& operator=(eventHelper &&other) noexcept
        {
            if (this != &other) {
                this->library = std::move(other.library);
                this->initialised = other.initialised;
            }
            return *this;
        };

        bool isInitialised(void){ return this->initialised;};

        void init(const char* path)
        {   
            try 
            {
                char filename[18]  = "eventManager";
                this->library = std::unique_ptr<dylib>(new dylib(path, strcat(filename, dylib::extension)));
                this->initialised = true;
            } 
            catch (const dylib::handle_error &) 
            {
                this->initialised = false;
            }   
        };
        
        void sendMessage(const char* msg)
        {                              
            auto sendMessage = library->get_function<void(const char*)>("sendMessage");
            
            // pass the arguments to the function
            return sendMessage(msg);   

        };

        void updateProgress(const char* msg, double percent)
        {                              
            auto updateProgress = library->get_function<void(const char*, double)>("updateProgress");
            return updateProgress(msg, percent);   

        };
        
        bool hasPlotHandler(void)
        {                              
            auto hasPlotHandler = library->get_function<bool(void)>("hasPlotHandler");
            return hasPlotHandler();   
        };

        void updatePlot(int nContrast, double* reflect, double* nReflect, double* shiftedData, double* nShiftedData, 
                        double* sldProfiles, double* nSldProfiles, double* layers, double* nLayers, 
                        double* sldProfiles2, double* nSldProfiles2, double* layers2, double* nLayers2, double* subRoughs,
                        double* resample, double* dataPresent, const char* modelType, const char* contrastNames, const double* nContrastNames)
        {                              
            auto updatePlot = library->get_function<void(int, double*, double*, double*, double*, 
                                                         double*, double*, double*, double*, double*,
                                                         double*, double*, double*, double*,
                                                         double*, double*, const char*, const char*, const double*)>("updatePlot");
            
            return updatePlot(nContrast, reflect, nReflect, shiftedData, nShiftedData, sldProfiles, nSldProfiles, 
                              layers, nLayers, sldProfiles2, nSldProfiles2, layers2, nLayers2, subRoughs, resample, 
                              dataPresent, modelType, contrastNames, nContrastNames);   

        };
};

#endif
