#ifndef WRAPPER_H
#define WRAPPER_H

#include <iostream>
#include <cstring>
#include <memory>
#include "classHandle.hpp"
#include "dylib.hpp"


class Library: public CallbackInterface
{
    public:
        std::unique_ptr<dylib> library;
        const char* functionName;
    
        Library(const char* libName, const char* functionName){
            this->functionName = strdup(functionName);
            init(libName);
        };
        ~Library(void){};

        Library& operator=(Library* other) noexcept
        {
            if (other) {
                this->library = std::move(other->library);
                this->functionName = other->functionName;
            }
            else {
                this->library = NULL;
                this->functionName = NULL;
            }
            return *this;
        };

        Library& operator=(Library &&other) noexcept
        {
            if (this != &other) {
                this->library = std::move(other.library);
                this->functionName = other.functionName;
            }
            return *this;
        };

        void init(const char* libName)
        {   
           this->library = std::unique_ptr<dylib>(new dylib(libName));
        };

        // Domain overload
        void invoke(double* params,double *bulk_in,double *bulk_out, int contrast, int domainNumber, double *tempOutput,double *roughness,double *nLayers)
        {   
            if (!library)
            {
                std::cerr << "dynamic libray failed to load" << std::endl;
                return;
            }     

            try{
                auto func = library->get_function<void(double*, double*, double*, int, int, double*, double*, double*)>(functionName);
                // pass the arguments to the function
                func(params, bulk_in, bulk_out, contrast, domainNumber, tempOutput, roughness, nLayers);           
            }catch (const dylib::symbol_error &) {
                std::cerr << "failed to get dynamic libray symbol for " << functionName << std::endl;
            }
            
        };
        
        // Non-Domain overload
        void invoke(double* params,double *bulk_in,double *bulk_out, int contrast, double *tempOutput,double *roughness,double *nLayers)
        {   
            if (!library)
            {
                std::cerr << "dynamic libray failed to load" << std::endl;
                return;
            }
            
            try{
                auto func = library->get_function<void(double*, double*, double*, int, double*, double*, double*)>(functionName);
                // pass the arguments to the function
                func(params, bulk_in, bulk_out, contrast, tempOutput, roughness, nLayers);           
            }catch (const dylib::symbol_error &) {
                std::cerr << "failed to get dynamic libray symbol for " << functionName << std::endl;
            }
            
        };
};

#endif

